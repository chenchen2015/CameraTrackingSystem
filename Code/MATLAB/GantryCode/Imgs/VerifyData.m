load('../Data1.mat');
I = imread('./Unit0-Samp.bmp');
imshow(I);
hold on;
hImg = imshow(I);
hPlot = plot(100,100,'g.','MarkerSize',30);
for i = 0:2
    I = sprintf('./Unit%1d-Samp.bmp',i);
    hImg.CData = imread(I);
    hPlot.XData = trackedLED(i+1).Centroid(1);
    hPlot.YData = trackedLED(i+1).Centroid(2);
    pause;
    %waitfor(gcf,'CurrentCharacter');
    %curChar=uint8(get(gcf,'CurrentCharacter'));
end

