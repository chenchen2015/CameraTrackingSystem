load('TrackedLED.mat');
I = imread('./trial4/NoIR_F2.8/Unit0-Samp01.bmp');
imshow(I);
hold on;
hImg = imshow(I);
hPlot = plot(100,100,'g.','MarkerSize',30);
for i = 0:2
    for j = 1:75
        I = sprintf('./trial4/NoIR_F2.8/Unit%1d-Samp%02d.bmp',i,j);
        hImg.CData = imread(I);
        hPlot.XData = trackedLED(i+1).Centroid(j,1);
        hPlot.YData = trackedLED(i+1).Centroid(j,2);
        pause;
        %waitfor(gcf,'CurrentCharacter');
        %curChar=uint8(get(gcf,'CurrentCharacter'));
    end
end

