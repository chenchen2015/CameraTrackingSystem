function makeLEDTrackPlot

%% 
load('TrackedLED.mat');
fileNameTplt = './trial4/IR/Unit%1d-Samp%02d.bmp';
sampRange = [45, 62];

figure(1); clf;
h = imshow(rand(2048), 'Border','tight'); hold on;
hD = plot(0,0,'g.','MarkerSize',36);

for i = sampRange(1):sampRange(2)
    for j = 0:2
        im = imread(sprintf(fileNameTplt, j, i));
        h.CData = double(im) / 255;
        hD.XData = trackedLED(j+1).Centroid(i,1);
        hD.YData = trackedLED(j+1).Centroid(i,2);
        pause(0.08);
        print(sprintf('Plot_Unit%1d-Samp%02d.png', j, i),'-dpng');
    end
end