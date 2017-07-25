% circ_trajrecord - Jan 2015. Sandra Fang
% Travel in a circular trajectory around an object assumed
% to be at a fixed point (x,y) in a radius r. 
%
% Yang:
% Aug 26th 2014, add rot as input so that the numpts can be Y
% Jun 16th 2014, travel smoothly from A to B while recording data, able to
% select single (no coming back) or dual recording mode (return to start)
% 
% INPUT: center: center of circle (x,y) that will be circled.  
%        radius: radius of circle
%        trials: number of takes
%        numpts: interpolation range (along x-axis when rot = 0) 
%        rot: rotation angle in deg (initial rotation) range from 0 to 2pi
%
% OUTPUT: diff is a 3D matrix with last dimension as take trials
%       1 and 2 denotes the map, gantry data, and es data taken on pass 1
%       (forward) and pass 2 ("backwards").
%       sizedata is the size of the output data arrays
% 
function [pos vel] = circ_trajrecord(center, radius, rot, time, interval)
    global gridVel gridAcc pc104MsgI ganMotionData_POS MNETStrmESDataP2M MNETStrmGanMotionDataP2M
    gridVel = [0.025, 0.025, 0.025, 1*pi/3];
    gridAcc = 10*gridVel;
    pc104MsgI = 0;
    
    % plan trajectory
    zpos = -20/100; %hardcoded 
    
    clear pos vel gandata esdata gdata edata
    time = 30;
    interval = 0.01; 
    [pos vel] = arcConstVel(center, radius, rot, interval);

    % prepare for data acquisition
    navCmd_toggleGanMotionDataStream(ganMotionData_POS);
    flushinput(MNETStrmESDataP2M)
    flushinput(MNETStrmGanMotionDataP2M)
    pause(0.1);
    waitForCmdConfirm(navCmd_on());
    gantryTime = 0;
    [gantryTime, ~, ~] = gotopos(0,[radius,0,pi/2,zpos]);
    pause(5);
    STime = gantryTime; 
    ESDataOff = []; 
    while gantryTime-STime <1
        [gantryTime, ~, ESData] =  Rx_Tx(gantryTime);
        ESDataOff = [ESDataOff; ESData];
    end
    [gantryTime, gandata, esdata, sizedata] = ExecuteTrajectory(pos,vel,GoToStart([pos(1,:) zpos],gantryTime));
    [gdata edata] = aligndata(gandata, esdata);

    %{
    if abs(rot) > 45
        [A, I] = unique(gdata(:,3),'last');
        gdata = gdata(sort(I),:); edata = edata(sort(I),:); 
        %gdata1 = gdata1((I),:); edata1 = edata1((I),:); 
        % interpolate now
        diff1(:,:,i) = interp1(gdata(:,3), edata(:,[4:3:22])*1000/101,numpts); % should be length of numpts
    else
        [A, I] = unique(gdata(:,2),'last');
        gdata = gdata(sort(I),:); edata = edata(sort(I),:); 
        %gdata1 = gdata1((I),:); edata1 = edata1((I),:); 
        % interpolate now
        diff1(:,:,i) = interp1(gdata(:,2), edata(:,[4:3:22])*1000/101,numpts); % should be length of numpts
    end
    %}
   
% ####### where MODE comes in
     %{
        gotopos(gantryTime,[pos(end,:) zpos]); % make it stop and prepare for return
        if mode == 0 % not coming back only when one shot and mode = 0;
            len2 = 0;
            diff2 = 0;
            map2 = 0; % no information whatsoever
        elseif mode == 1 % coming back
            pause(0.5); % let the robot take a break
            clear pos vel gandata esdata gdata edata A I
            points = points(end:-1:1,:);
            [pos, vel] = arcConstVel(center, radius, rot, time, interval);
            navCmd_toggleGanMotionDataStream(ganMotionData_POS);
            flushinput(MNETStrmESDataP2M)
            flushinput(MNETStrmGanMotionDataP2M)
            pause(0.1);
            waitForCmdConfirm(navCmd_on());
            gantryTime = 0;
            spos = [points(1,:) zpos];
            gantryTime = GoToZero(gantryTime,spos);
            STime = gantryTime; 
            ESDataOff = [];
            while gantryTime-STime <1
                [gantryTime, ~, ESData] =  Rx_Tx(gantryTime);
                ESDataOff = [ESDataOff; ESData];
            end
            [gantryTime gandata esdata rawmap] = ExecuteTrajectory(pos,vel,GoToStart([pos(1,:) zpos],gantryTime));
            [gdata2 edata2] = aligndata(gandata, esdata);

            if abs(rot) > 45
                [A I] = unique(gdata2(:,3),'last');
                gdata2 = gdata2(sort(I),:); edata2 = edata2(sort(I),:); 
                %gdata2 = gdata2((I),:); edata2 = edata2((I),:); 
                diff2(:,:,i) = interp1(gdata2(end:-1:1,3), edata2(end:-1:1,[4:3:22])*1000/101, numpts); % should be length of numpts
            else
                [A I] = unique(gdata2(:,2),'last');
                gdata2 = gdata2(sort(I),:); edata2 = edata2(sort(I),:); 
                %gdata2 = gdata2((I),:); edata2 = edata2((I),:); 
                diff2(:,:,i) = interp1(gdata2(end:-1:1,2), edata2(end:-1:1,[4:3:22])*1000/101, numpts); % should be length of numpts
            end
            gotopos(gantryTime,[pos(end,:) zpos]); % make it stop
        end % end MODE
      %}               
    diff1 = mean(diff1,3); diff2 = mean(diff2,3); % mean the data
    pos = pos(end:-1:1,:);% reverse the neg trials
    map = smoothm(diff1(:,[1 3 4:6]),50); 
            
end
