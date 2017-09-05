% mex Console_FrameGrabber_v1.cpp XCLIBW64.lib PXIPLW64.lib CaptureLog.cpp;

%% Initialize Gantry
g = GantryMove('192.168.1.121');
g.Connect;

%% Prepare spatial samples
sampleNum2D = 49;
sampleNumDepth = 3;
nTotalSamples = sampleNum2D * sampleNumDepth;
ganPosSampleList = zeros(nTotalSamples, 4);
%                 X ,   Y  , Depth
GanPosLimit = [-0.70, -0.40, -0.35;...
                0.70,  0.40,  0.00];

% Sample 3D space based on grid samples
xSamples = linspace(GanPosLimit(1,1),GanPosLimit(2,1),sampleNum2D^0.5);
ySamples = linspace(GanPosLimit(1,2),GanPosLimit(2,2),sampleNum2D^0.5);
depthSamples = linspace(GanPosLimit(1,3),GanPosLimit(2,3),sampleNumDepth);
[x,y,z] = meshgrid(xSamples,ySamples,depthSamples);
yy = y(:);
for i = 1:2:(sampleNum2D^0.5)*sampleNumDepth-1
    yy( (i*sampleNum2D^0.5+1):((i+1)*sampleNum2D^0.5) ) = flip(yy( (i*sampleNum2D^0.5+1):((i+1)*sampleNum2D^0.5) ));
end

ganPosSampleList(:,1) = x(:);
ganPosSampleList(:,2) = yy;
ganPosSampleList(:,3) = z(:);

%% Prepare animation
figure(1), clf;
hdl = plot3(x(:),y(:),z(:),'.','MarkerSize',32); hold on; grid on;
hdlF = plot3(0,0,0,'xg','MarkerSize',32); % Finished Samples
hdlC = plot3(0,0,0,'or','MarkerSize',32); % Current target

%% Main Loop
g.goToPos(ganPosSampleList(1,:));
pause(1);

for i = 1:nTotalSamples
    disp('Going to next position...');
    g.goToPos(ganPosSampleList(i,:));
    
    % Update plot
    hdlF.XData = ganPosSampleList(1:(i-1),1);
    hdlF.YData = ganPosSampleList(1:(i-1),2);
    hdlF.ZData = ganPosSampleList(1:(i-1),3);
    hdlC.XData = ganPosSampleList(i,1);
    hdlC.YData = ganPosSampleList(i,2);
    hdlC.ZData = ganPosSampleList(i,3);
    
    pause(4);
    
    if mod(i,25) == 1
        disp('Starting new depth...');
        pause(5);
    end
    
    disp('Capturing image...');
    tic;
    Console_FrameGrabber_v1(sprintf('./Imgs/Unit$-Samp%03d.bmp', i));
    toc;
    pause(0.5);
end

g.Disconnect;

save('./Imgs/session4.mat', 'ganPosSampleList');

% for i = 1:sampleNum
%     trackLEDs(i, gantryPos(i,:));
% end
% 
% DataProcess;
