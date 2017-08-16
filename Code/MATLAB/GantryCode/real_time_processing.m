%% Initialize Gantry 
g = GantryMove('192.168.1.121');
g.Connect;

%% Prepare sample space and image handle
numberOfPos = 10;         % Number of samples to process
result(numberOfPos).gantryPos = [];
result(numberOfPos).estimatedPos = [];

figure(1);clf;             % Initialize figure 1 with 3 subplots
h1 = subplot(1,3,1);
hIm1 = imshow(rand(2048), 'Parent', h1);hold on;
hLED1 = plot(0,0,'g.','MarkerSize',15);
h2 = subplot(1,3,2);
hIm2 = imshow(rand(2048), 'Parent', h2);hold on;
hLED2 = plot(0,0,'g.','MarkerSize',15);
h3 = subplot(1,3,3);
hIm3 = imshow(rand(2048), 'Parent', h3);hold on;
hLED3 = plot(0,0,'g.','MarkerSize',15);

%% Main loop
for i = 1:numberOfPos
    result(i).gantryPos = g.GetGanPosSnap;       % Capture real gantry position
    Console_FrameGrabber_v1('./Imgs/Unit$-Samp.bmp');       % Capture images from frame grabber
    trackedLED = processImages;
  
    % display images with processing results
    figure(1);
    im1 = double(imread('./Imgs/Unit0-Samp.bmp'));
%     bw1 = im2bw(im1,graythresh(im1));
    hIm1.CData = im1/255;hold on;
    hLED1.XData = trackedLED(1).Centroid(1);
    hLED1.YData = trackedLED(1).Centroid(2);

    im2 = double(imread('./Imgs/Unit1-Samp.bmp'));
%     bw2 = im2bw(im2,graythresh(im2));
    hIm2.CData = im2/255;hold on;
    hLED2.XData = trackedLED(2).Centroid(1);
    hLED2.YData = trackedLED(2).Centroid(2);
    
    subplot(1,3,3);
    im3 = double(imread('./Imgs/Unit2-Samp.bmp'));
%     bw3 = im2bw(im3,graythresh(im3));
    hIm3.CData = im3/255;hold on;
    hLED3.XData = trackedLED(3).Centroid(1);
    hLED3.YData = trackedLED(3).Centroid(2);
    pause(0.05);
    
    % Record estimated positions
    matchedPairs = zeros(3,4);
    matchedPairs(1,:) = cat(2,trackedLED(1).Centroid, trackedLED(2).Centroid);
    matchedPairs(2,:) = cat(2,trackedLED(1).Centroid, trackedLED(3).Centroid);
    matchedPairs(3,:) = cat(2,trackedLED(2).Centroid, trackedLED(3).Centroid);
    
    if length(find(~matchedPairs)) > 4
        result(i).estimatedPos = zeros(1,3);
    elseif ~isempty(find(trackedLED(1).Centroid == 0, 1))
        result(i).estimatedPos = regModelView23(matchedPairs(3,:));
    elseif ~isempty(find(trackedLED(2).Centroid == 0, 1))
        result(i).estimatedPos = regModelView13(matchedPairs(2,:));
    elseif ~isempty(find(trackedLED(3).Centroid == 0, 1))
        result(i).estimatedPos = regModelView12(matchedPairs(2,:));
    else
        result(i).estimatedPos = regModelView123(cat(2,trackedLED(1).Centroid, trackedLED(2).Centroid, trackedLED(3).Centroid));
    end
%     result(i).estimatedPos = regModelView12(matchedPairs(1,:));
%     fprintf('Estimated 3D coordinate from cameara 1 and 2: %d,%d,%d\n', output1(1), output1(2), output1(3));
%     result(i).estimatedPos = regModelView13(matchedPairs(2,:));
%     fprintf('Estimated 3D coordinate from cameara 1 and 3: %d,%d,%d\n', output2(1), output2(2), output2(3));
%     result(i).estimatedPos = regModelView23(matchedPairs(3,:));
%     fprintf('Estimated 3D coordinate from cameara 2 and 3: %d,%d,%d\n', output3(1), output3(2), output3(3));
%     result(i).estimatedPos = regModelView123(cat(2,trackedLED(1).Centroid, trackedLED(2).Centroid, trackedLED(3).Centroid));
end
g.Disconnect;