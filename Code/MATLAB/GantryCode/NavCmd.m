%% Class NavCmd
% Contains lower-level functionality for SensorPod.
% Contains all the handlers and variables (global and local) from the
% nav command scripts. 
%
% For use with GantryMove.m.
%
% Code mainly adapted from Kinea.
% 
% Chen Chen
% Apr. 13, 2015
%
% Sandra Fang
% June 2016

% Will inherit bulltin methods from Handle class
classdef NavCmd < handle
    %% Public Constant Addresses and Variables
    properties (Access = public, Transient = true, Constant = true)
        % !!Important!!
        % For Limiting gantry position and motion
        %   Position Limit:
        %                  X(m)  ,     Y(m)  ,     Z(m)
        GanPosLimit = [-0.758054, -0.412827, -0.394389;...
                        0.758054,  0.412827,  0.394389];
    end
    
    %% Protected Constant Addresses and Variables
    properties (Access = protected, Transient = true, Constant = true)
        % Gantry control message type from MatlabNetRead.h:
        GanCntrlMsg_TEST = 1001;
        GanCntrlMsg_ON = 1002;
        GanCntrlMsg_OFF = 1003;
        GanCntrlMsg_PSERVOSLOW = 1004;
        GanCntrlMsg_STOPALL = 1005;
        GanCntrlMsg_VELCMD = 1006;
        GanCntrlMsg_GETTOVEL = 1007;
        GanCntrlMsg_GETTOPOS = 1008;
        GanCntrlMsg_PSERVOFAST = 1009;
        GanCntrlMsg_TOGGLEGANMOTIONDATASTREAM = 1010;
        GanCntrlMsg_TOGGLEESDATASTREAM = 1011;
        GanCntrlMsg_SETESPODMUXES = 1012;
        GanCntrlMsg_CANREINIT = 1013;
        GanCntrlMsg_REQUESTAXISLIMIT = 1014;
        GanCntrlMsg_SETESPODFREQPHASE = 1015;
        
        % Streaming message types from MatlabWriteStream.h:
        NOTHING_TO_SEND = 0;
        ganMotionData_POS = -2001;
        ganMotionData_VEL = -2002;
        ganMotionData_ACC = -2003;
        ganMotionData_VCMD = -2004;
        ganMotionData_XPOS = -2005;
        ganMotionData_YPOS = -2006;
        ganMotionData_ZPOS = -2007;
        ganMotionData_TPOS = -2008;
        sensorPodData_ES = -3001;
        
        % Information from Gantry control box from MatlabNetWrite.h
        P2MMSG_MUXSTATEID = -4001;
        P2MMSG_AXISLIMIT = -4002;
        P2MMSG_TRIGFREQPHASE = -4003;
        
        % Size of packets -- Matlab to PC104 -- from MatlabNetRead.h: 
        GANCNTRLMSG_DATALEN = 10;
        GANCNTRLMSG_TOTLEN = 13;
        CAN2PODMSG_DATALEN = 8;
        CAN2PODMSG_TOTLEN = 12;
        
        % Size of packtes -- PC104 to Matlab -- from MatlabNetWrite.h:
        EXECUTEDCONFIRM_TOTLEN = 3;
        GANTRYDATA_DATALEN = 4;
        GANTRYDATA_TOTLEN = 8;
        GANTRYMOTIONDATA_TOTLEN = 6;
        ESDATA_DATALEN = 21;
        ESDATA_TOTLEN = 24;
        TEXTMSG_DATALEN = 256;
        TEXTMSG_TOTLEN = 256;

        % MUX Channels
        E_UP_DIFF = 0;
        E_UP_L_BUF = 1;
        E_MID_L_BUF = 2;
        E_BOT_BUF = 3;
        E_MID_DIFF = 4;
        E_UP_R_BUF = 5;
        E_MID_R_BUF = 6;
        E_BOT_DIFF = 7;
        
        % Axis and node identifier from GantryController.h:
        AxisId_PX = 0;
        AxisId_PY = 1;
        AxisId_PZ = 2;
        AxisId_RZ = 3;
        NODE_1=0;
        NODE_2=1;
        NODE_3=2;
        NODE_4=3;
        NODE_5=4;
        NODE_6=5;
        NODE_7=6;
        
        % port numbers -- from NavGantry.h:
        GANCNTRLMSG_PORT_M2P = 3101;
        GANDATA_PORT_P2M = 3102;
        MSGEXECONF_PORT_P2M = 3103;
        GANDATASTRM_PORT_P2M = 3104;
        CAN2POD_PORT_M2P = 3105;
        ESDATASTRM_PORT_P2M = 3106;
        TEXTMSG_PORT_P2M = 3107;
        %defNavBoxIPAddr = '10.0.203.231';
        defNavBoxIPAddr = '192.168.1.121';
        
        % Constants for Communication
        maxFreadLoops = 200;
        nBytesInDouble = 8;
    end
       
    %% Protected Tcp-Ip Handlers
    properties (Access = protected, Transient = true)
        % Direction : Send
        % MATLAB to PC104 (gantry)
        MNETGanCntrlMsgM2P;
        MNETCan2PodM2P;
        
        % Direction : Receive
        % PC104 (gantry) to MATLAB
        MNETMsgExeConfP2M;
        MNETStrmGanMotionDataP2M; % Done! - CC
        MNETStrmESDataP2M;
        MNETTextMsgP2M;
        MNETGanDataP2M;
    end
  
    %% Public Variables
    properties (Access = public, Transient = true)
        % packet serial number:
        serialNM2P = 0;
        
        % Gantry Time
        gantryTime = 0;   
        
        % Nav IP address
        navBoxIPAddr;    
        
        % Switch for Gantry Motion Data Filter
        GanMotionDataFilterSW = 0; 
        
    end
    
    %% Public State flag variables
    properties (Access = public, Transient = true)
        IsConnected = false;
    end
    
    %% Protected Variables
    properties (Access = protected, Transient = true)
        GetMotionDone = false;            
    end
    
    %% Private Constants
    properties (Access = private, Transient = true)
        % For filtering gantry motion data
        GanMotionBufferSize = 5;
    end
    
    %% Private Variables
    properties (Access = private, Transient = true)
        GanMotionBuffer;
        GanMotionBufferInd = 1;
    end
    
    %% Default Constructor and Destructor - Public Sealed Methods
    methods (Access = public, Sealed = true)
        % Default Constructor Overload
        function NC = NavCmd(varargin)
            % NavCmd(varargin)
            % Default constructor. Handles paths and
            % initializations of low-level properties. 
            %
            % Chen 2015
            
            % Initialize path
            addpath('../mat2PC104Functions');
            addpath('../callbackFunctions');
            addpath('../TrajectorySetup');
            addpath('../RunTime');
            addpath('../sf');
            addpath('../Chen');
            
            % Handle input
            if ~nargin
                NC.navBoxIPAddr = NC.defNavBoxIPAddr;
            elseif nargin == 1
                NC.navBoxIPAddr = varargin{1}{1};
            else
                if ~mod(nargin,2)
                    % Wrong number of input
                    error('Error in constructor input: Wrong number of input, expecting inputs in pairs');
                end
                for i = 1:2:nargin
                    switch varargin{i}
                        case 'IP'
                            NC.navBoxIPAddr = varargin{i+1};
                    end
                end
            end
            if length(NC.navBoxIPAddr) < length('0.0.0.0')
                NC.navBoxIPAddr = NC.defNavBoxIPAddr;
            end
            
            % Initialize Local Variables
            NC.GanMotionBuffer = zeros(4, NC.GanMotionBufferSize * 2);
            
            % Initialize Communication
            InitComm(NC);
        end
    end
    
    methods (Access = public)
        % Default Destructor Overload
        function delete(NC)
            % delete(NC)
            % Default destructor
            %
            % Chen 2015
            if NC.IsConnected
                Disconnect(NC);
            end
        end
    end
    
    %% Communication Methods
    methods (Access = protected, Sealed = true)
            
        function packetNumberM2P = setESPodMuxes(NC, sensorNodeIndex, muxNumber, channelNumber)
        % packetNumberM2P = setESPodMuxes(sensorNodeIndex, muxNumber, channelNumber)
        % Set the output channel for the electrosense multiplexers in the Sensor Pod
        %
        % INPUT:
        % sensorNodeIndex:  Sensor Node Index: 0-6 (for seven node boards)
        % muxNumber:  Which MUX to control: 0-2
        % channelNumber: Choose output channel of MUX: 0-7
        % OUTPUT: 
        % packetNumberM2P: packet serial number -- Matlab to PC104
        % 
        % Adapted from Kinea by Sandra Fang, 10/6/2015
        
            NC.serialNM2P = NC.serialNM2P + 1;
            packetNumberM2P = NC.serialNM2P;
            MType = NC.GanCntrlMsg_SETESPODMUXES;
            MCheck = MType + NC.GANCNTRLMSG_DATALEN + packetNumberM2P;

            data = [sensorNodeIndex, muxNumber, channelNumber];

            if any(isnan(data)) || any(isinf(data)) || ~isreal(data)
                disp('Dangerously sending NaN/InF/Imag...');
                navCmd_off();
                return
            end

            if (any(data<0))
                error('Indices cannot be negative')
            end
            if sensorNodeIndex > 6
                error('sensorNodeIndex cannot be greater than 6')
            end
            if muxNumber > 2
                error('muxNumber cannot be greater than 2')
            end
            if channelNumber > 7
                error('channelNumber cannot be greater than 7')
            end

            data = [data, 0*ones(1, NC.GANCNTRLMSG_DATALEN-length(data) )];
            packet = [MType, data, packetNumberM2P, MCheck];
            fwrite(NC.MNETGanCntrlMsgM2P, packet, 'double');
        end
        
        function InitComm(NC)
            % InitComm(NC)
            % Initialize low-level TCP/IP communications and ports
            %
            % Adapted from Kinea. 
            
            % Initialize Connection
            NC.MNETGanDataP2M = tcpip(NC.navBoxIPAddr, NC.GANDATA_PORT_P2M);
            NC.MNETGanCntrlMsgM2P = tcpip(NC.navBoxIPAddr, NC.GANCNTRLMSG_PORT_M2P); %'remote host', remote port
            NC.MNETCan2PodM2P = tcpip(NC.navBoxIPAddr, NC.CAN2POD_PORT_M2P);
            NC.MNETMsgExeConfP2M = tcpip(NC.navBoxIPAddr, NC.MSGEXECONF_PORT_P2M);
            NC.MNETStrmGanMotionDataP2M = tcpip(NC.navBoxIPAddr, NC.GANDATASTRM_PORT_P2M);
            NC.MNETStrmESDataP2M = tcpip(NC.navBoxIPAddr, NC.ESDATASTRM_PORT_P2M);
            NC.MNETTextMsgP2M = tcpip(NC.navBoxIPAddr, NC.TEXTMSG_PORT_P2M);
            
            % Set ByteOrder
            % x86 is littleEndian, matlab defaults to bigEndian for some reason
            set(NC.MNETGanDataP2M,'ByteOrder','littleEndian');
            set(NC.MNETGanCntrlMsgM2P,'ByteOrder','littleEndian');
            set(NC.MNETCan2PodM2P,'ByteOrder','littleEndian');
            set(NC.MNETMsgExeConfP2M,'ByteOrder','littleEndian');
            set(NC.MNETStrmGanMotionDataP2M,'ByteOrder','littleEndian');
            set(NC.MNETStrmESDataP2M,'ByteOrder','littleEndian');
            set(NC.MNETTextMsgP2M,'ByteOrder','littleEndian');

            % Input Buffer Size
            % make the input buffer larger, default is 512 bytes
            set(NC.MNETGanDataP2M,'InputBufferSize',256*4095);
            set(NC.MNETMsgExeConfP2M,'InputBufferSize',256*4095);
            set(NC.MNETCan2PodM2P,'InputBufferSize',256*4095);
            set(NC.MNETGanCntrlMsgM2P,'OutputBufferSize',256*4095);
            set(NC.MNETStrmGanMotionDataP2M,'InputBufferSize',256*4095);
            set(NC.MNETStrmESDataP2M,'InputBufferSize',256*4095);
            set(NC.MNETTextMsgP2M,'InputBufferSize',256*4095);
            
            % Time Out
            % fail sooner due to lack of connection
            set(NC.MNETGanDataP2M,'Timeout',2);
            set(NC.MNETMsgExeConfP2M,'Timeout',2);
            set(NC.MNETCan2PodM2P,'Timeout',2);
            set(NC.MNETGanCntrlMsgM2P,'Timeout',2);
            set(NC.MNETStrmGanMotionDataP2M,'Timeout',2);
            set(NC.MNETStrmESDataP2M,'Timeout',2);
            set(NC.MNETTextMsgP2M,'Timeout',2);
        end
        
    end
    
    methods (Access = public, Sealed = true)
        % Set Freq/TrigPhase
        function packetNumberM2P = setESPodFreqPhase(NC, excFreq, trigPhase)
            % packetNumberM2P = navCmd_setESPodFreqPhase(excFreq, trigPhase)
            % Set the excitation frequency and trigger phase shift in the Sensor Pod
            %
            % INPUTS:
            % excFreq: excitation frequency in Hz
            % trigPhase: phase shift of demodulation trigger in degrees
            % OUTPUT: 
            % packetNumberM2P: packet serial number -- Matlab to PC104
            %
            % Adapted from Kinea.

            NC.serialNM2P = NC.serialNM2P + 1;
            packetNumberM2P = NC.serialNM2P;
            MType = NC.GanCntrlMsg_SETESPODFREQPHASE;
            MCheck = MType + NC.GANCNTRLMSG_DATALEN + packetNumberM2P;

            data = [excFreq, trigPhase];

            data = [data, 0*ones(1, NC.GANCNTRLMSG_DATALEN-length(data) )];

            if any(isnan(data)) || any(isinf(data)) || ~isreal(data)
                disp('Dangerously sending NaN/InF/Imag...');
                NC.Disconnect;
                return
            end

            packet = [MType, data, packetNumberM2P, MCheck];
            fwrite(NC.MNETGanCntrlMsgM2P, packet, 'double');
        end
        
        
        function Connect(NC)
            % Connect(NC)
            % Connect (open) all ports
            %
            % Chen 2015
            
            % Check connection status
            if NC.IsConnected
                warning('Nav already connected. ');
                return;
            end
            
            % Try to connect
            try
                fopen(NC.MNETGanDataP2M);
            catch err
                NC.IsConnected = false;
                warning(['failed to connect: ' err.message]);
            end
            fopen(NC.MNETGanCntrlMsgM2P);
            fopen(NC.MNETCan2PodM2P); 
            fopen(NC.MNETMsgExeConfP2M);
            fopen(NC.MNETStrmGanMotionDataP2M);
            fopen(NC.MNETStrmESDataP2M);
            fopen(NC.MNETTextMsgP2M);
            
            NC.IsConnected = true;
            fprintf('Successfully connected to Nav host (%s)\n',NC.navBoxIPAddr);
            
            % Set Muxes
            for n=1:7,
                requestedMuxStates(1,n) = NC.E_UP_L_BUF; % equ to writing 1
                requestedMuxStates(2,n) = NC.E_UP_DIFF; % upper differential
                requestedMuxStates(3,n) = NC.E_UP_R_BUF;
            end
            
            nodeIDs = 0:6;
            muxIDs = 0:2;
            for n=1:7,
                for m=1:3,
                    NC.setESPodMuxes(nodeIDs(n), muxIDs(m), requestedMuxStates(m,n));
                end
            end
            fprintf('Muxes set\n');
            NC.setESPodFreqPhase(40000,0);
            fprintf('Pod Freq at 40000, 0 deg out of phase\n');
            
        end
        
        function Disconnect(NC)
            % Disconnect(NC)
            % Disonnect all ports
            %
            % Chen 2015
            
            % Check connection status
            if ~NC.IsConnected
                warning('Nav already disconnected. ');
                return;
            else
                fclose(NC.MNETGanDataP2M);
                fclose(NC.MNETGanCntrlMsgM2P);
                fclose(NC.MNETCan2PodM2P);
                fclose(NC.MNETMsgExeConfP2M);
                fclose(NC.MNETStrmGanMotionDataP2M);
                fclose(NC.MNETStrmESDataP2M);
                fclose(NC.MNETTextMsgP2M);
            end
            
            NC.IsConnected = false;
            fprintf('Successfully disconnected to Nav host (%s)\n',NC.navBoxIPAddr);
        end
        
        function CheckConnection(NC)
            % CheckConnection(NC)
            % Check if connection to gantry has been established
            %
            % Chen 2015
            
            if ~NC.IsConnected
                error(['Please Connect to the gantry first! ' ...
                    'Run the Connect method']);
            else
                return;
            end
        end
        
    end
    
    %% Gantry Data Read Methods
    methods (Access = public, Sealed = true)
   
        function GanPosData = GetGanPosSnap(NC)
            % GanPosData = GetGanPosSnap(NC)
            % Get Gantry Position - Snapshot version, will only sample and 
            % return the position once
            %
            % Hint: Each full package of motion data contains
            %       1 package of ganMotionData_POS and
            %       1 package of ganMotionData_VEL
            %       the length of each package is GANTRYMOTIONDATA_TOTLEN
            %       The gantry will send these two packages of data in
            %       an alternating manner NONSTOP at 10Hz. (This also
            %       explains why in minMotionDataLen, I set it to
            %       packagesPerData * NC.GANTRYMOTIONDATA_TOTLEN, you need 
            %       to read both two packages. )
            %       Note: need to flush buffer to correctly update readings
            %       Also seems like sampling for two samples is safer
            %       (produces less errors) than sampling one reading after
            %       flushing buffer. 
            %
            % 
            % INPUT: None
            % OUTPUT: 
            % 4x2 matrix; 1st column is positions; second is
            % velocities. Descending by row, they are for the x, y, z, yaw
            % axes, where x,y,z are in meters, yaw is in radians. 
            %
            % Chen Chen, edited by Sandra Fang
            % Aug 27, 2015
            
            CheckConnection(NC);
            samplesNeeded = 2; %need 2 in case one gets cut off
            packagesPerData = 2; % ganMotionData_POS and ganMotionData_VEL
            minMotionDataLen = packagesPerData * NC.GANTRYMOTIONDATA_TOTLEN; %2x6
            packageSize = minMotionDataLen * samplesNeeded;

            % Start Reading Ganty Data and make
            % space for at least two iterations of data packets
            flushinput(NC.MNETStrmGanMotionDataP2M);
            rawdata = fread(NC.MNETStrmGanMotionDataP2M, ...
                packageSize, 'double');
            index = find(rawdata == NC.ganMotionData_POS); % prevent bad data
                                                           % from being written by 
                                                           % looking specifically for -2001
            % If index is empty matrix, skip the data since it has not been
            % sampled correctly. otherwise, reformat the data
            if isempty(index)
                warning('Wrong type of gantry-motion data packet. Skipping data.');
                GanPosData = NaN(4,1);
                return;
            end
            data = rawdata(index:index+11);
            thisData = reshape(data,NC.GANTRYMOTIONDATA_TOTLEN,packagesPerData);

            % Read and Update Gantry Time
            thisGantryTime = thisData(2,:);
            NC.gantryTime = max([NC.gantryTime, thisGantryTime]);

            % Read Gantry Motion Data for position
            GanMotionData = thisData(3:6,:);
            GanPosData = GanMotionData(:,1);
        end
        
        function GanPosTrackDemo(NC)
            % GanPosTrackDemo(NC)
            % Visualize Gantry Position
            %
            % Chen Chen
            % Apr. 15, 2015
            
            CheckConnection(NC);
            
            clf;
            figure(1);
           
            h = plot3(0,0,0,'.');...
                grid on;rotate3d on;
            h.MarkerSize = 80;
            axis([-0.8,0.8,-0.8,0.8,-0.5,0.5]) %[xmin, xmax, ymin, ymax, zmin, zmax]
            
            while true
                GanPosData = NC.GetGanPosSnap;
                h.XData = GanPosData(1);
                h.YData = GanPosData(2);
                h.ZData = GanPosData(3);
                title(num2str(GanPosData));
                refreshdata;
                pause(0.1); %gantry response at 10Hz
            end
        end
        
        function GanESData = GetGanESSnap(NC)
            % GanESData = GetGanESSnap(NC)
            % Get electrosense data snapshot. ES data measured in Volts
            %
            % INPUT: 
            % none
            % OUTPUT: 
            % Outputs 7 ES channels of differential data in Volts
            % (with gain)
            %
            % Note: data outputs 24 columns in the format of:
            % gantry time
            % 5
            % 21 columns corresp to: left electrode reading
            %                        differential reading
            %                        right reading
            % Checksum (sum of first 3 cols)
            %
            % Sandra Fang
            % Oct 6, 2015
            CheckConnection(NC);
            
            % Start Reading Ganty Data
            flushinput(NC.MNETStrmESDataP2M);
            data = fread(NC.MNETStrmESDataP2M, NC.ESDATA_TOTLEN, ...
                'double'); %originally from Rx_Tx
            
            %checksum
            if (data(end, :) ~= (data(1,:)+data(2,:)+data(3,:)) )
                warning('Electrosense data stream check-sum error. Skipping data.');
                GanESData = NaN(5,1);
            else
                GanESData = data([4, 7, 10, 13, 16, 19, 22],:);
                %Note that out of these 5 channels, only 4 16 work as of
                %11/11/15 (Corresp. to boards 1,5, and sensing electrodes 3,4)
                % that is, board 5 controls the middle sensing pair
            end
        end
        
        function GetGanESCont(NC,length)
            % GetGanESCont(NC,length)
            % Get electrosense data continuously. ES data measured in Volts
            %
            % INPUT: 
            % length: number of data points to sample
            % OUTPUT: 
            % None, but plots the data
            %
            % Sandra Fang
            % 2015
            i=1;
            while(i<length)
                flushinput(NC.MNETStrmESDataP2M);
                flushinput(NC.MNETStrmGanMotionDataP2M);
                
                figure(1); hold on;
                axis([1 length -2, 2]);
                GanESData = NC.GetGanESSnap;
                if (~any(isnan(GanESData)))
                    plot(i, GanESData(1),'r.');
                    %plot(i, GanESData(2),'g.');
                    %plot(i, GanESData(3),'c.');
                    %plot(i, GanESData(4),'y.');
                    plot(i, GanESData(5),'b.'); 
                    %plot(i, GanESData(6),'m.'); 
                    %plot(i, GanESData(7),'k.');
                end
                i=i+1;
                
                pause(0.01);
            end
        end
        
        function boundaries = getSoftAxisLimits(NC)
            % boundaries = getSoftAxisLimits(NC)
            % Request axis soft position limits
            % 
            % OUTPUT: 
            % values displayed in a 2x3 matrix:
            % xmin ymin zmin (in meters)
            % xmax ymax zmax (in meters)
            %
            % Sandra Fang
            % July 29, 2015 
            boundaries = NC.GanPosLimit;
        end

        %% - Test functions
        function GanCtrlData = GetGanCtrl(NC)
            %
            % Sandra Fang
            % June 18, 2015
           
            % Direction : Receive
            % PC104 to MATLAB
            % Not complete
            NC.MNETTextMsgP2M;
            NC.MNETGanDataP2M;
        
            while(NC.MNETGanDataP2M.BytesAvailable >= 8*NC.GANTRYDATA_TOTLEN),
                [data, ~, ~] = fread(NC.MNETGanDataP2M,NC.GANTRYDATA_TOTLEN,'double');
                msgType = data(1);
                nData = NC.GANTRYDATA_DATALEN;
                msgData = data(2:(1+nData));
                msgSN = data(2+nData);
                timeStamp = data(3+nData);
                check = data(4+nData);
                if (check ~= (msgType+nData+msgSN))
                    warning('Gantry control box data packet check-sum error.');
                    warning('Flushing data from port MNETGanDataP2M.');
                    flushinput(NC.MNETGanDataP2M);
                    break;
                end
            end
        end 
    end
    
    %% Low Level Move Methods
    methods (Access = protected, Sealed = true)
        function [boundedPos, boundaryFlag] = CheckBound(NC, targetPos)
            % Check if target input violate the software boundary limit
            % and if so, limit the axis value
            if length(targetPos) ~= 4
                % Check Invalid Input
                boundaryFlag = NaN(1,4);
                return;
            else
                gantryPos = targetPos(1:3);
                theta = targetPos(4);
                boundaryFlag = gantryPos > NC.GanPosLimit(1,:) & ...
                    gantryPos < NC.GanPosLimit(2,:);
                
                boundaryLower = gantryPos < NC.GanPosLimit(1,:);
                boundaryUpper = gantryPos > NC.GanPosLimit(2,:);
                
                gantryPos(boundaryLower) = NC.GanPosLimit(1,boundaryLower);
                gantryPos(boundaryUpper) = NC.GanPosLimit(2,boundaryUpper);
                
                boundedPos = [gantryPos,theta];
            end
        end
        
        function packetNumberM2P = GetToPos(NC, axis1Cmd, axis2Cmd)
            % packetNumberM2P = GetToPos(axis1Cmd, axis2Cmd)
            % Control axis to desired position limiting both velocity 
            % and acceleration; can control up to two axes per call.
            %
            % INPUT: for each axisCmd:
            % axisCmd = [axis_id, desired_pos, max_vel, max_acc]
            % OUTPUT:
            % packetNumberM2P: packet serial number -- Matlab to PC104
            % 
            % One or two axes can be commanded per call
            %
            % int GetToPos::SetNewXDesired(double newXDesired, double maxVelocity,double acceleration)
            %
            % Adapted from Kinea
            
            NC.serialNM2P = NC.serialNM2P + 1;
            packetNumberM2P = NC.serialNM2P;
            MType = NC.GanCntrlMsg_GETTOPOS; %=1008
            MCheck = MType + NC.GANCNTRLMSG_DATALEN + packetNumberM2P;
            doit1 = 1;
            doit2 = 1;
            
            %sending one axis command
            if length(axis1Cmd)~=4
                warning('Improper size of 1st input array.  Command not sent.')
                doit1 = 0;
                axis1Cmd = [0,0,0,0];
            end
            if nargin==2
                data = [doit1, axis1Cmd,0,0,0,0,0];
            %sending 2 axis commands    
            elseif nargin==3
                if length(axis2Cmd)~=4
                    warning('Improper size of 2st input array. Command not sent.')
                    doit2 = 0;
                    axis2Cmd = [0,0,0,0];
                end
                data = [doit1, axis1Cmd, doit2, axis2Cmd];
            %if we try to send other than 1 or 2 axis inputs
            else
                warning('Improper number of inputs.  Commands not sent');
                data = 0;
            end
            data = [data, 0*ones(1, NC.GANCNTRLMSG_DATALEN-length(data) )];
            
            if any(isnan(data)) || any(isinf(data)) || ~isreal(data)
                disp('Dangerously sending NaN/InF/Imag...');
                NC.CmdOff;
                return
            end
            
            packet = [MType, data, packetNumberM2P, MCheck]; 
            fwrite(NC.MNETGanCntrlMsgM2P, packet, 'double');
        end
        
        function packetNumberM2P = GetToVel(NC, axis1Cmd, axis2Cmd)
            % packetNumberM2P = GetToVel(axis1Cmd, axis2Cmd)
            % Control axis to desired velocity limiting acceleration
            %
            % INPUT:
            % axisCmd = [axis_id, desired_vel, max_acc] (units of m, s, radians)
            % One or two axes can be commanded per call
            % OUTPUT:
            % packetNumberM2P: packet serial number -- Matlab to PC104
            % 
            % packetNumberM2P = navCmd_getToVel(ax1YesNo, ax1ID, ax1desVel, ax1maxAcc, ax2YesNo, ax2ID, ax2desVel, ax2maxAcc)
            %
            % Adapted from Kinea
            
            NC.serialNM2P = NC.serialNM2P + 1;
            packetNumberM2P = NC.serialNM2P;
            MType = NC.GanCntrlMsg_GETTOVEL;
            MCheck = MType + NC.GANCNTRLMSG_DATALEN + packetNumberM2P;
            % Multiple checks
            
            
            doit1 = 1;
            doit2 = 1;
            if length(axis1Cmd)~=3
                warning('Improper size of 1st input array.  Command not sent.')
%                 ax1YesNo = 0;
                axis1Cmd = [0,0,0];
            end
            
            if nargin==2
                data = [doit1, axis1Cmd];
            elseif nargin==3
                if length(axis2Cmd)~=3
                    warning('Improper size of 2st input array. Command not sent.')
                    doit2 = 0;
                    axis2Cmd = [0,0,0];
                end
                data = [doit1, axis1Cmd, 0, doit2, axis2Cmd];
            else
                warning('Improper number of inputs.  Commands not sent');
                data = 0;
            end
            
            % data = [ax1YesNo, ax1ID, ax1desVel, ax1maxAcc, 0.0, ax2YesNo, ax2ID, ax2desVel, ax2maxAcc];
            data = [data, 0*ones(1, NC.GANCNTRLMSG_DATALEN-length(data) )];
            
            if any(isnan(data)) || any(isinf(data)) || ~isreal(data)
                disp('Dangerously sending NaN/InF/Imag...');
                NC.CmdOff;
                return
            end
            
            packet = [MType, data, packetNumberM2P, MCheck];
            fwrite(NC.MNETGanCntrlMsgM2P, packet, 'double');
        end
        
        function packetNumberM2P = CmdOff(NC)
            % packetNumberM2P = CmdOff(NC)
            % Turn off Gantry
            %
            % OUTPUT:
            % packetNumberM2P: Returns the message packet number (packet serial number)
            % 
            % Adapted from Kinea
            NC.serialNM2P = NC.serialNM2P + 1;
            packetNumberM2P = NC.serialNM2P;
            MType = NC.GanCntrlMsg_OFF;
            MCheck = MType + NC.GANCNTRLMSG_DATALEN + packetNumberM2P;
            fwrite(NC.MNETGanCntrlMsgM2P,[MType, 1:NC.GANCNTRLMSG_DATALEN, packetNumberM2P, MCheck], 'double');
        end
    end
end