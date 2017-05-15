%mex Console_FrameGrabber_v1.cpp XCLIBW64.lib PXIPLW64.lib CaptureLog.cpp;
%g = GantryMove('192.168.1.121');
sampleNum = 5;
%gantryPos = zeros(sampleNum,2);
%g.Connect;
%g.goToPos([-0.7,-0.4,-0.2,0]);
%pause(10);
x = -0.7;
y = -0.4;
for i = 1:sampleNum
    x = x + 0.3;
    y = y + 0.15;
    %g.goToPos([x,y,-0.2,0]);
    %pause(20);
    %Console_FrameGrabber_v1();
    gantryPos(i,1) = x;
    gantryPos(i,2) = y;
end
%g.goToPos([-0.7,-0.4,0.2,0]);
%g.Disconnect;
for i = 1:sampleNum
    trackLEDs(i, gantryPos(i,:));
end
