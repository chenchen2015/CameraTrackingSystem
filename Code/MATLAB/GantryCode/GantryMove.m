%% Class GantryMove (Base class NavCmd)
% Higher-level functionality for controlling and reading data from the
% SensorPod. Relies on class NavCmd from NavCmd.m. Power to SensorPod 
% (not just the QNX OS) must be ON. 
%
% g = GantryMove('IPADDRESS') constructs a GantryMove object, which is
% linked via IPADDRESS to the SensorPod's QNX OS. 
% g.Connect establishes a proper connection between all communication ports
%
% Example: 
% g = GantryMove('192.168.1.121');
% g.Connect;
% g.goToPos([0.1,0.2,0.2,0]); % go to a position in the tank
% g.GetGanESSnap;                 % read electrosense data at current position
% g.Disconnect;
%
% Chen Chen
% Apr. 13, 2015
%
% Sandra Fang
% June 2016

classdef GantryMove < NavCmd
    %% Public Properties
    properties (Access = public)
        % Initialize fields for which sensors are used (boards), 
        % which is the middle sensor (S4), 
        % and which index it appears at in boards (S4ind)
        boards = [];
        S4 = 0;
        S4ind = 0; 
        
        % Velocity and Acceleration Limit Grid
        % [X, Y, Z, Yaw]
        MaxVelGrid = zeros(1, 4, 'double');
        MaxAccGrid = zeros(1, 4, 'double');
        
        % Position and Velocity Trajectory Data - not used
        % DataPosi;
        % DataVelo;
        
    end
    
    %% Default Constructor - Public Sealed Methods
    methods (Access = public, Sealed = true)
        function GM = GantryMove(varargin)
            % GM = GantryMove(varargin)
            % Default constructor that creates a 
            % GantryMove object. Inherits from NavCmd Class.
            % 
            % g = GantryMove('IPADDRESS'); constructs a GantryMove object, which is
            % linked via IPADDRESS to the SensorPod's QNX OS. 
            % 
            % INPUT: 
            % varargin: input IP address (as a string) here
            % OUTPUT: 
            % GM: GantryMove object; contains properties related to the
            % physical gantry settings
            % 
            % Chen Chen 
            % 2015
            
            GM = GM @ NavCmd(varargin);
            
            % Initialize Local Properties
            GM.MaxVelGrid = [0.2, 0.2, 0.2, pi/3]; % Maximum velocity allowed
                                                   % x and y coords must be same
            GM.MaxAccGrid = [2, 2, .2, 2]; %maximum acceleration allowed
            GM.boards = [1 5]; % Sensor Boards Used (as defined by their node IDs)
            GM.S4 = GM.boards(2); % Board that corresponds to S4 (middle sensing pair)
            GM.S4ind = find(GM.boards == GM.S4);
            
            % Report Status
            disp(['Current IP: ' GM.navBoxIPAddr]);
        end
    end
    
    %% Gantry Move Methods
    methods (Access = public)
        function MiddleESdata = createmap2D(GM)
            % MiddleESdata = createmap2D(GM)
            % Interpolation to create 2D map (plane) of tank ES
            % Generate random data points at a certain z position, fixed yaw
            % interpolate those points to get map of tank ES without object
            % Must start at x=0, y=0, otherwise high chance will cause position
            % errors. 
            %
            % INPUT: 
            % none
            % OUTPUT: 
            % MiddleESdata: Middle sensing pair ES data as interpolation 
            % obj (also saved) also saves time it took to run each segment,
            % gantry pos, ES data at each pos. 
            % Units of ES is in V with gain (gain is not subtracted)
            %
            % Sandra Fang
            % August 3/10/16
            
            flushinput(GM.MNETStrmESDataP2M);
            flushinput(GM.MNETStrmGanMotionDataP2M);
            %Generate 10 nodes (including corner,startpt) within gantry soft limits
            X = 2*GM.GanPosLimit(2,1)*rand(5, 1) - GM.GanPosLimit(2,1);
            Y = 2*GM.GanPosLimit(2,2)*rand(5, 1) - GM.GanPosLimit(2,2);
            XY = [X,Y];
            %force addition of corner pts - place slightly within soft
            %limits
            corners = [-0.70, -0.40;
                       -0.70, 0.40;
                       0.75, -0.40;
                       0.75, 0.40];
            %insert corner positions randomly in node array
            %insertrows is not part of default MATLAB package - download!
            XY = insertrows(XY, corners, floor(19*rand(1,4)+1));
            %force addition of current point as starting point
            currpos = GM.GetGanPosSnap;
            XY = insertrows(XY, [currpos(1),currpos(2)], 0);
            display(XY);
            
            zpos = currpos(3);
            yawpos = currpos(4);
            %position at first node, stop the gantry from moving, wait 3s
            GM.goToPos([XY(1,1),XY(1,2),zpos,yawpos]);
            GM.GetToVel([GM.AxisId_PX, 0, GM.MaxAccGrid(1)],...
                    [GM.AxisId_PY, 0, GM.MaxAccGrid(2)]);
            pause(2);
            
            %go through the points
            POSdata = []; ESdata = []; Tdata = []; 
            for n=1:length(XY)-1
                display(['Take: ', num2str(n), '/', num2str(length(XY)-1)]);
                display(sprintf('(x,y) = (%0.3f,%0.3f) to (%0.3f,%0.3f)', ...
                    XY(n,1), XY(n,2), XY(n+1,1), XY(n+1,2)));
                %For some reason, sometimes this does not go to the desired
                %endpoint. even if it doesn't, we do take ES and POS data
                %correctly (both are sampled in real time). 
                [time, ES, POS] = GM.ExecuteLinearTrajRecord( ...
                    [XY(n,1),XY(n,2),zpos,yawpos], ...
                    [XY(n+1,1),XY(n+1,2),zpos,yawpos]);
                POSdata = [POSdata; POS];
                ESdata = [ESdata; ES];
                Tdata = [Tdata; time];
                %make sure they start at endpoint
                GM.goToPos([XY(n+1,1),XY(n+1,2),zpos,yawpos]); 
                pause(2);
            end
            
            save('mapdata.mat', 'Tdata', 'POSdata', 'ESdata');
            
            %create interpolation
            X = POSdata(:,1);
            Y = POSdata(:,2);
            
            % get interpolation object of Tank Map Data for middle sensing
            % pair
            MiddleESdata = scatteredInterpolant(X,Y,ESdata(:,GM.S4ind));  
            
            save('ESinterp.mat', 'MiddleESdata');
            
            %stop the robot
            GM.GetToVel([GM.AxisId_PX, 0, GM.MaxAccGrid(1)],...
                    [GM.AxisId_PY, 0, GM.MaxAccGrid(2)]);
        end
        
        
        % Go to a position specified by pos
        function varargout = goToPos(GM, pos)
            % goToPos(GM, pos)
            % Goes to a certain position defined by pos at a preset max 
            % speed/acceleration. 
            %
            % INPUT: 
            % pos = [x y z yaw(in radians)], positions are in meters
            % OUTPUT: none
            %
            % Sandra Fang
            % June 19,2015
            
            if any(isnan(pos)) || any(isinf(pos)) || ~isreal(pos)
                disp('Dangerously sending NaN/InF/Imag...');
                GM.CmdOff;
            else
                % GM.AxisId_PX = 0 (x axis)
                % GM.AxisId_PY = 1 (y axis)
                % GM.AxisId_PZ = 2 (z axis)
                % GM.AxisId_RZ = 3 (yaw/rotation)
        
                pos = GM.CheckBound(pos);
                
                %send X and Y coordinates
                GM.GetToPos([GM.AxisId_PX, pos(1), GM.MaxVelGrid(1), GM.MaxAccGrid(1)],...
                    [GM.AxisId_PY, pos(2), GM.MaxVelGrid(2), GM.MaxAccGrid(2)]);
                %send Z and rotational coordinates (note vel, accel are fixed) 
                GM.GetToPos([GM.AxisId_PZ, pos(3), GM.MaxVelGrid(3), GM.MaxAccGrid(3)],...
                    [GM.AxisId_RZ, pos(4), GM.MaxVelGrid(4), GM.MaxAccGrid(4)]);
                
                varargout{1} = pos;
            end
        end
        
        % Set yaw independent of position
        function setYaw(GM, yaw)
            % setYaw(GM, yaw)
            % Set yaw independent of position
            % at a preset max speed/accel
            % INPUT: 
            % yaw (in radians)
            % OUTPUT: none
            %
            % Sandra Fang
            % June 19,2015
            
            if isnan(yaw) || isinf(yaw) || ~isreal(yaw)
                disp('Dangerously sending NaN/InF/Imag...');
                GM.CmdOff;
            else
                % GM.AxisId_PX = 0 (x axis)
                % GM.AxisId_PY = 1 (y axis)
                % GM.AxisId_PZ = 2 (z axis)
                % GM.AxisId_RZ = 3 (yaw/rotation)
        
                %send Z and rotational coordinates (note vel, accel are fixed) 
                GM.GetToPos([GM.AxisId_RZ, yaw, GM.MaxVelGrid(4), GM.MaxAccGrid(4)]);
                
            end
        end
        
        % Go to position specified by pos at a specific speed for each DoF
        function goToPosVarspeed(GM, pos, speed) 
            % goToPosVarspeed(GM, pos, speed)
            % Goes to a certain position defined by pos at a
            % speed/acceleration defined by speed
            %
            % INPUT: 
            % pos = [x y z yaw(in radians)], positions are in meters
            % speed = [x y z yaw] denoting the speed at which this happens 
            % (in m/s and rad/s)
            % OUTPUT: none
            % 
            % Sandra Fang
            % June 19,2015
            
            if any(isnan(pos)) || any(isinf(pos)) || ~isreal(pos)
                disp('Dangerously sending NaN/InF/Imag...');
                GM.CmdOff;
            else
                % GM.AxisId_PX = 0 (x axis)
                % GM.AxisId_PY = 1 (y axis)
                % GM.AxisId_PZ = 2 (z axis)
                % GM.AxisId_RZ = 3 (yaw/rotation)
        
                %send X and Y coordinates
                GM.GetToPos([GM.AxisId_PX, pos(1), speed(1), GM.MaxAccGrid(1)],...
                    [GM.AxisId_PY, pos(2), speed(2), GM.MaxAccGrid(2)]);
                %send Z and rotational coordinates (note vel, accel are fixed) 
                GM.GetToPos([GM.AxisId_PZ, pos(3), speed(3), GM.MaxAccGrid(3)],...
                    [GM.AxisId_RZ, pos(4), speed(4), GM.MaxAccGrid(4)]);
                
            end
        end
        
        
        % Achieve a certain velocity
        function goToVel(GM, vel, accel)
            % goToVel(GM, vel, accel)
            % Get to a certain velocity
            %
            % INPUT: 
            % vel = [x,y,z,yaw] denoting the velocity in m/s
            %       (?) and rad/s
            % accel = [x,y,z,yaw] denoting maximum 
            %       permissible acceleration in m/s^2 (?) and rad/s
            % OUTPUT: none
            % 
            % Sandra Fang
            % Feb 23,2016
            
            nonvalidInput = any(isnan(vel)) || any(isinf(vel)) || ~isreal(vel)...
                || any(isnan(accel)) || any(isinf(accel)) || ~isreal(accel);
            if nonvalidInput
                disp('Dangerously sending NaN/InF/Imag...');
                GM.CmdOff;
            else
                % GM.AxisId_PX = 0 (x axis)
                % GM.AxisId_PY = 1 (y axis)
                % GM.AxisId_PZ = 2 (z axis)
                % GM.AxisId_RZ = 3 (yaw/rotation)
        
                %send X and Y coordinates
                GM.GetToVel([GM.AxisId_PX, vel(1), accel(1)],...
                    [GM.AxisId_PY, vel(2), accel(2)]);
                %send Z and rotational coordinates 
                %GM.GetToVel([GM.AxisId_PZ, vel(3), accel(3)],...
                %    [GM.AxisId_RZ, vel(4), accel(4)]);
                
            end
        end
     
        % Execute a linear trajectory and record ES data
        function [time, ESdata, POSdata]=ExecuteLinearTrajRecord(GM, startpos, endpos, varargin)
            % [time, ESdata, POSdata] = 
            %           ExecuteLinearTrajRecord(GM, startpos, endpos)
            % Records ES data for a trajectory that is linear in the XY plane. 
            % Speed is a constant set to 0.1 of the maximum gantry speed in 
            % each direction.
            % 
            % INPUT: 
            % startpos and endpos: [xpos, ypos, zpos, yaw]; start
            %   positions and end positions of trajectory, respectively. 
            % varargin: a string containing filename you want to save
            %   data as (without extension)
            % OUTPUT: 
            % time: time (sec) array corresponding to when data was taken
            %   since start of trajectory
            % ESdata: electrosense data in V (note that gain
            %   is NOT accounted for - this is Voltage with Gain)
            % POSdata: a matrix of [X,Y] positions (in meters) recorded
            %   at each ES measurement. 
            % Optional: will plot graph of ES data from all available channels
            %   and save it if filename given
            % Note: Must move gantry to start position before running
            %
            % Sandra Fang
            % July 30, 2015
            flushinput(GM.MNETStrmESDataP2M);
            flushinput(GM.MNETStrmGanMotionDataP2M);
            
            delT_list = []; 
            currPOS_list = [];
            currES_list = [];
            
            % executes trajectory at constant velocity (0.1 of MaxVelGrid in X,Y directions)
            dist = sqrt((endpos(1)-startpos(1))^2+(endpos(2)-startpos(2))^2);
            xdist = endpos(1)-startpos(1);
            ydist = endpos(2)-startpos(2);
            theta = atan(ydist/xdist); % not yaw! this is the angle off the 
                                       % x axis defined by tank coordinates
                
            vel = [abs(GM.MaxVelGrid(1)*0.1*cos(theta)),abs(GM.MaxVelGrid(2)*0.1*sin(theta)),0,0]; %velocity in [x,y,z,yaw];
            accel = [0.2,0.2,0,0]; %make gantry change speed with less delay
            Tcompletetrajectory = dist/(GM.MaxVelGrid(1)*0.1); 
                %amount of time it takes to complete trajectory
                %assumes constant velocity at 0.1*MaxVelGridg,
            
            GM.gantryTime = 0;
            currPOS = GM.GetGanPosSnap;
            prevnorm = 10;
            tic;
            %while conditions:
            % give gantry alotted time + 0.1s to complete trajectory
            % also make sure it reaches position - if not, go there 
            % regardless of time.
            
            while (toc<(Tcompletetrajectory+0.1) || norm(currPOS-endpos') < prevnorm) 
                prevnorm = norm(currPOS-endpos');
                GM.GetToPos([GM.AxisId_PX, endpos(1)*toc/Tcompletetrajectory, vel(1), accel(1)],...
                    [GM.AxisId_PY, endpos(2)*toc/Tcompletetrajectory, vel(2), accel(2)]);
                currPOS = GM.GetGanPosSnap;
                currES = GM.GetGanESSnap;
                if (~any(isnan(currES)) && ~any(isnan(currPOS))) %make sure all ES,POS values are not NaN
                    delT_list = [delT_list, toc];
                    currPOS_list = [currPOS_list, currPOS];
                    currES_list = [currES_list, currES];
                end
                pause(0.01); %need delay to prevent checksum errors. 
            end

            %Boards 1,5 working (corresponds to the same rows in
            %GetGanESSnap (as of 11/10/15)
            time = delT_list'; ESdata = (currES_list(GM.boards,:))'; POSdata = currPOS_list';
            if nargin == 4
                save(strcat(varargin{1},'.mat'), 'time', 'ESdata', 'POSdata');
            end
        end
        
        %Excefute multiple linear take trials
        function ExecuteMultipleLinTraj(GM, startpos, endpos, trials, plots)
            % ExecuteMultipleLinTraj(GM, startpos, endpos, trials, plots)
            % Runs function ExecuteLinearTrajRecord(...) for multiple trials. 
            % 
            % INPUT: 
            % startpos and endpos: [xpos, ypos, zpos, yaw] in meters, rad
            % trials: the number of trials to make. One trial consists
            %        of going from startpos to endpos, and then from endpos to
            %        startpos (roundtrip). 
            % plot: 1 = plot, 0 = don't plot
            % OUTPUT: 
            % none to MATLAB. Values saved in files in current directory. 
            %   Units saved are: position: m; 
            % ES: V, gain not subtracted out. (but in plts, gain has 
            %     been subtracted out)                  
            %
            % Sandra Fang
            % Aug 25th, 2015
            
            GM.goToPos(startpos); 
            pause(1);
            for i=1:trials
                display(strcat('trial: ', num2str(i)));
                pause(1); 
                filenamef = strcat('ES', num2str(i),'f'); %f is for forwards
                [~, ESdata, POSdata]= GM.ExecuteLinearTrajRecord(startpos, endpos, filenamef);
                GM.goToPos(endpos); 
                pause(2);
                if (plots)
                %plotting x dir in POSdata - change this manually for now
                    plot(POSdata(:,1)*100, ESdata(:,GM.S4ind)*10); hold on; 
                    title('Object ES Data');
                    xlabel('distance (cm)');
                    ylabel('Voltage (mV)'); %gain has also been subtracted in plot
                    pause(2);
                end
                filenameb = strcat('ES', num2str(i),'b'); %b is for backwards
                [~, ESdata, POSdata] = GM.ExecuteLinearTrajRecord(endpos, startpos, filenameb);
                GM.goToPos(startpos);
                pause(2);
                if (plots)
                    %plotting x dir in POSdata
                    plot(POSdata(:,1)*100, ESdata(:,GM.S4ind)*10); hold on; 
                    title('Object ES Data');
                    xlabel('distance (cm)');
                    ylabel('Voltage (mV)'); %gain has also been subtracted in plot
                    pause(2);
                end
            end
        end
        
        % Update as of June/2016: OUTDATED - may not work properly
        %Rotation trajectory
        function [RADdata,ESdata] = ExecuteRotateTraj(GM, startRad, endRad, varargin)
            % [RADdata,ESdata] = ExecuteRotateTraj(GM, startRad, endRad, varargin)
            % Executes a trajectory of rotation
            % Note: Motion may be choppy
            %
            % INPUT: 
            % startRad: radian to start at
            % endRad: radian to end at 
            % varargin: enter a string here to denote the filename of the
            % data to be saved
            % OUTPUT: 
            % RADdata: radian at each step
            % ESdata: electrosense data at each step (units of V, w/gain)
            %
            % Sandra Fang 
            % 2015
            flushinput(GM.MNETStrmESDataP2M);
            flushinput(GM.MNETStrmGanMotionDataP2M);
            
            delT_list = []; 
            currRAD_list = [];
            currES_list = [];
            
            vel = [0,0,0,0.1*GM.MaxVelGrid(4)]; %
            accel = [0,0,0,0.2]; %make gantry change speed with less delay
            
            GM.gantryTime = 0;
            currRAD = GM.GetGanPosSnap; currRAD = currRAD(4);
            Tcompletetrajectory = (endRad-startRad)/vel(4);
            prevnorm = 10;
            tic;
            %while conditions:
            % give gantry alotted time + 0.1s to complete trajectory
            % also make sure it reaches position - if not, go there 
            % regardless of time.
            
            while (toc<(Tcompletetrajectory+0.1) || norm(currRAD-endRad) < prevnorm) 
                prevnorm = norm(currRAD-endRad);
                GM.GetToPos([GM.AxisId_RZ, endRad*toc/Tcompletetrajectory, vel(4), accel(4)],...
                    [GM.AxisId_PY, 0,0,0]);
                
                currRAD = GM.GetGanPosSnap; currRAD = currRAD(4);
                currES = GM.GetGanESSnap;
                if (~any(isnan(currES)) && ~any(isnan(currRAD))) %make sure all ES,POS values are not NaN
                    delT_list = [delT_list, toc];
                    currRAD_list = [currRAD_list, currRAD];
                    currES_list = [currES_list, currES];
                end
                pause(0.01); %need delay to prevent checksum errors. 
            end
            %Boards 1,5 working (corresponds to the same rows in
            %GetGanESSnap (as of 11/10/15)
            time = delT_list'; ESdata = (currES_list(GM.boards,:))'; RADdata = currRAD_list'; 
            %only get S4 data from ES
            ESdata = ESdata(:,GM.S4ind);
            if nargin == 4
                save(strcat(varargin{1},'.mat'), 'time', 'ESdata', 'RADdata');
            end
        end
        
        % Update as of June/2016: OUTDATED - may not work properly
        % Execute a sinusoidal trajectory
        function ExecuteSinTraj(GM,radius)
            % ExecuteSinTraj(GM,radius)
            % Executes a sinusoidal trajectory
            % Note: Motion may be choppy
            %
            % Sandra Fang 2015
            delT_list = [];
            currx_list = [];
            tic;
            points=0;
            %outer while loop to generate trajectory based on current time
            %toc
            while(toc <= 2*pi)
                toc;
                delT = toc+0.1;
                desired_pos = radius*cos(delT);
                desired_vel = -2*radius*sin(delT);
                desired_acc = -2*radius*cos(delT);
                GM.GetToPos([GM.AxisId_PX, desired_pos, desired_vel, desired_acc]);
                
                atgoal=0;
                %inner while loop for position tracking
                while(atgoal == 0)
                    
                    currx = GM.GetGanPosSnap;
                    delT_list = [delT_list, toc];
                    currx_list = [currx_list; currx(1)];
                    if (currx(1) - desired_pos < 0.01)
                        atgoal = 1;
                        display(currx);
                        delT_list = [delT_list, toc];
                        currx_list = [currx_list; currx(1)];
                        points = points + 1;
                    end
                end 
            end
            display(points);
            toc;
            
            figure(1);
            plot(delT_list, currx_list(:,1));
            legend('x');
            disp('end of traj'); 
            GM.goToPos([0.3,0,-0.2,0]);
        end
        
        % Update as of June/2016: OUTDATED - may not work properly
        function ExecuteCircTraj(GM,radius)
            % ExecuteCircTraj(GM,radius)
            % Execute circular trajectory in plane - hopefully code runs at 10 hz
            % currently only for circles at [0,0], starting at [x,y]=[0.1,0] 
            % 
            % INPUT: 
            % radius: radius of circular trajectory
            % OUTPUT: none
            %
            % Sandra Fang
            % 2015
            
            delT_list = [];
            currx_list = [];
            tic;
            points=0;
            %outer while loop to generate trajectory based on current time
            %toc
            while(toc <= 8*pi)
                delT = toc+0.1;
                desired_pos = [radius*cos(delT/4), radius*sin(delT/4)];
                desired_vel = [-radius*sin(delT/4), radius*cos(delT/4)];
                desired_acc = 2*[-radius*cos(delT/4), -radius*sin(delT/4)];
                GM.GetToPos([GM.AxisId_PX, desired_pos(1), desired_vel(1), desired_acc(1)],...
                    [GM.AxisId_PY, desired_pos(2),desired_vel(2), desired_acc(2)]);
                
                atgoal=0;
                %inner while loop for position tracking
                
                while(atgoal == 0)
                    currx = GM.GetGanPosSnap;
                    delT_list = [delT_list, toc];
                    currx_list = [currx_list; [currx(1), currx(2)]];
                    if (norm(currx - [desired_pos(1),desired_pos(2),currx(3),currx(4)]') < 0.01)
                        atgoal = 1;
                        delT_list = [delT_list, toc];
                        currx_list = [currx_list; [currx(1), currx(2)]];
                        points = points + 1;
                    end
                end 
                
            end

            display(points);
            toc;
            
            figure(1);
            plot(delT_list, currx_list(:,1), delT_list, currx_list(:,2));
            legend('x','y');
            figure(2);
            plot(currx_list(:,1), currx_list(:,2));
            daspect([1 1 1]);
            GM.goToPos([radius,0,-0.2,0]);
        end  
      
        function DemoLinTraj(GM, startpos, endpos)
            % DemoLinTraj(GM, startpos, endpos)
            % Demo for looking at object in tank - move gantry back and forth
            % continuously, plot what you see
            %
            % INPUT: 
            % startpos and endpos: [x,y,z,yaw] in meters, radians
            % OUTPUT: none, but plots points as gantry moves past object
            % 
            % Sandra 
            % 2015
            
            %run demo continuously
            figure(1);
            while(1);
                axis([-40, 40, -30, -20]); hold on;
                xlabel('y axis distance (cm)'); ylabel('mV'); 
                title('Flyby profile');
                plot(-30:30,zeros(61,1),'k--');
                
                flushinput(GM.MNETStrmESDataP2M);
                flushinput(GM.MNETStrmGanMotionDataP2M);

                delT_list = []; 
                currPOS_list = [];
                currES_list = [];

                % executes trajectory at constant velocity (0.1 of MaxVelGrid in X,Y directions)
                dist = sqrt((endpos(1)-startpos(1))^2+(endpos(2)-startpos(2))^2);
                xdist = endpos(1)-startpos(1);
                ydist = endpos(2)-startpos(2);
                theta = atan(ydist/xdist); % not yaw! this is the angle off the 
                                           % x axis defined by tank coordinates

                vel = [abs(GM.MaxVelGrid(1)*0.1*cos(theta)),abs(GM.MaxVelGrid(2)*0.1*sin(theta)),0,0]; %velocity in [x,y,z,yaw];
                accel = [0.2,0.2,0,0]; %make gantry change speed with less delay
                Tcompletetrajectory = dist/(GM.MaxVelGrid(1)*0.1); 
                    %amount of time it takes to complete trajectory
                    %assumes constant velocity at 0.1*MaxVelGridg
                
                %Forwards
                GM.gantryTime = 0;
                currPOS = GM.GetGanPosSnap;
                prevnorm = 10;
                %while conditions:
                % give gantry alotted time + 0.1s to complete trajectory
                % also make sure it reaches position - if not, go there 
                % regardless of time.
                tic;
                while (toc<(Tcompletetrajectory+0.1) || norm(currPOS-endpos') < prevnorm) 
                    prevnorm = norm(currPOS-endpos');
                    GM.GetToPos([GM.AxisId_PX, endpos(1)*toc/Tcompletetrajectory, vel(1), accel(1)],...
                        [GM.AxisId_PY, endpos(2)*toc/Tcompletetrajectory, vel(2), accel(2)]);
                    currPOS = GM.GetGanPosSnap;
                    currES = GM.GetGanESSnap;
                    if (~any(isnan(currES)) && ~any(isnan(currPOS))) %make sure all ES,POS values are not NaN
                        %plot(currPOS(2)*100, currES(1)*10,'.b');
                        plot(currPOS(2)*100, currES(GM.S4)*1000/101,'.r'); %S4 board ID
                    end
                    pause(0.01); %need delay to prevent checksum errors. 
                end
                
                pause(1);
                % Make it go the other way
                startpos(2) = -1*startpos(2);
                endpos(2) = -1*endpos(2);
                clf;
            end

        end
        
        % added by : Ritwik Ummalaneni - only for OR demo
        % Update as of June/2016: OUTDATED - do not use
        function DemoLinTrajOculus(GM, startpos, endpos,t) 
            prev = 0;
            prevPos = [0, 0, 0, 0];
                
                %flushinput(GM.MNETStrmESDataP2M);
                %flushinput(GM.MNETStrmGanMotionDataP2M);

                delT_list = []; 
                currPOS_list = [];
                currES_list = [];

                % executes trajectory at constant velocity (0.1 of MaxVelGrid in X,Y directions)
                dist = sqrt((endpos(1)-startpos(1))^2+(endpos(2)-startpos(2))^2);
                xdist = endpos(1)-startpos(1);
                ydist = endpos(2)-startpos(2);
                theta = atan(ydist/xdist); % not yaw! this is the angle off the 
                                           % x axis defined by tank coordinates

                vel = [abs(GM.MaxVelGrid(1)*0.1*cos(theta)),abs(GM.MaxVelGrid(2)*0.1*sin(theta)),0,0]; %velocity in [x,y,z,yaw];
                accel = [0.2,0.2,0,0]; %make gantry change speed with less delay
                Tcompletetrajectory = dist/(GM.MaxVelGrid(1)*0.1); 
                    %amount of time it takes to complete trajectory
                    %assumes constant velocity at 0.1*MaxVelGridg
                
                %Forwards
                GM.gantryTime = 0;
                currPOS = GM.GetGanPosSnap;
                
                prevnorm = 10;
                %while conditions:
                % give gantry alotted time + 0.1s to complete trajectory
                % also make sure it reaches position - if not, go there 
                % regardless of time.
                tic;
                while (toc<(Tcompletetrajectory+0.1) || norm(currPOS-endpos') < prevnorm) 
                    if t.BytesAvailable
                        data1 = t.read;
                        data1 = char(data1);
                        yawData = strread(data1, '%f', 'delimiter', ';');
                        yaw = yawData(end - 2);
                        X = ['The current yaw is: ', num2str(yaw)];
                        disp(X);
                        prevnorm = norm(currPOS-endpos');
                        GM.GetToPos([0, endpos(1)*toc/Tcompletetrajectory, vel(1), accel(1)],...
                            [1, endpos(2)*toc/Tcompletetrajectory, vel(2), accel(2)]);
                        currPOS = GM.GetGanPosSnap;
                        currPos = currPOS;
                        currES = GM.GetGanESSnap;
                        if (~any(isnan(currES)) && ~any(isnan(currPOS))) %make sure all ES,POS values are not NaN
                            %plot(currPOS(2)*100, currES(1)*10,'.b');
                            prevPos = currPos;
                            es = abs(currES);
                            esN = ((es(5) - ( 0)) / (2)-(0)) * 100;
                            prev = esN;
                            t.write([uint8(num2str(currPos(4)*180/pi)) 44  uint8(num2str(currPos(1)*100)) 44 uint8(num2str(esN)) 44 uint8(num2str(-currPos(2)*100)) 13]);
                        else
                            currPos = prevPos;
                            t.write([uint8(num2str(currPos(4)*180/pi)) 44  uint8(num2str(currPos(1)*100)) 44 uint8(num2str(prev)) 44 uint8(num2str(-currPos(2)*100)) 13]);
                        end
                        %pause(0.01); %need delay to prevent checksum errors.
                    end
                end                
                pause(1);

        end
    end
    
    %% Processing data and plotting methods
    methods (Access = public) 
        function ESnoNoise = removeNoise(GM, POS, ES, dim, varargin)
            % ESnoNoise = removeNoise(GM, POS, ES, dim, varargin)
            % Removes noise from ES data of the currently working channels
            %
            % INPUTS: 
            % varargin:  must be at least size 1 (1 channel). Channels should
            % be listed from smallest channel number to largest
            % dim = dimensions needed for interpolation; can only be 1,2,3
            % POS = the positions corresponding to ES data from gantry
            % ES = ES data from gantry
            % OUTPUT:
            % ESnoNoise: the ES values with noise subtracted
            %
            % Sandra Fang
            % 2015
            
            for n = 1:nargin-4
                ESch = varargin{n}; 
                if dim == 1
                    ESnoNoise(:,n) = ES(:,n) - ESch(POS(:,1));
                elseif dim==2
                    ESnoNoise(:,n) = ES(:,n) - ESch([POS(:,1),POS(:,2)]);
                elseif dim == 3
                    ESnoNoise(:,n) = ES(:,n) - ESch([POS(:,1),POS(:,2), POS(:,3)]);
                else 
                    warning('Not a correct dimension. Can only be 1D,2D, or 3D interpolation');
                    return;
                end
            end
        end
            
        function plotTankMap(GM,X,Y,varargin)
            % plotTankMap(GM,X,Y,varargin)
            % Plot tank map (map of normal ES readings without object in tank)
            % For use with plotting the data saved from createmap2D(GM)
            % 
            % INPUT: 
            % X, Y coordinates saved (in m)
            % varargin: list of data from sensors (S1-S7) to plot
            % OUTPUT: none
            %
            % Sandra Fang
            % August 14, 2015
            
            for n = 4:nargin
                hold on;
                plot3(X,Y,varargin{n-3},'o');
            end
            axis([-0.758, 0.758, -0.412827, 0.412827]); %gantry tank limits
        end
        
        function plotTankMapInterp(GM,varargin)
            % plotTankMapInterp(GM,varargin)
            % Plot tank map (map of normal ES readings without object in tank)
            % as a surface of interpolated points. For use with plotting the
            % interpolated object saved from createmap2D(GM)
            %
            % INPUT: varargin{1}: the ES data from a sensor pair to interpolate. 
            % OUTPUT: none; will plot interpolation
            %
            % Sandra Fang
            % August 14, 2015
            
            [xq,yq] = meshgrid(-0.75:0.01: 0.75, -0.41:0.01:0.41);
            ESq = varargin{1}(xq,yq);
            mesh(xq,yq,ESq);
            xlabel('x');
            ylabel('y');
            zlabel('V (gain not subtracted)');
            axis([-0.758, 0.758, -0.412827, 0.412827]); %gantry tank limits
        end
        
        
        
        function plotES(GM, POSdata, ESdata, varargin)
            % plotES(GM, POSdata, ESdata, varargin)
            % Plot ES data from all channels against 1D position. 
            % 
            % INPUT: 
            % POSdata: the position vectors; must be N x 4 or 1D position vector
            %    if varargin is empty
            % ESdata: the electrosense channel data in Volts; size
            %    N x NumberOfChannels - currently N = 2
            % varargin: can be either 'x', 'y', 'z', 'r' for x,y,z, rotation
            %    If nothing entered, will plot ES against 1D POSdata
            %
            % Sandra Fang 
            % August 12, 2015
            
            if nargin == 3
                plot(POSdata, ESdata(:,1), ...
                    POSdata, ESdata(:,2)); %change this if N =/= 2
                title('Capacitive Object Data');
                legend('board 1', 'board 4'); 
                xlabel('distance (m)');
                ylabel('Voltage (V)');
                return;
            else
                axis = varargin{1};
                a = 0;
                if axis == 'x'
                    a = 1;
                elseif axis == 'y'
                    a = 2;
                elseif axis == 'z'
                    a = 3;
                elseif axis == 'r'
                    a = 4;
                end

                plot( POSdata(:,a), ESdata(:,1), ...
                      POSdata(:,a), ESdata(:,2)); %change this if N =/= 2
                title('Capacitive Object Data');
                legend('Ch4', 'Ch13', 'Ch16'); 
                xlabel('distance (m)');
                ylabel('Voltage (V)');
            end
        end
        
    end %end processing methods
end % END OF FILE