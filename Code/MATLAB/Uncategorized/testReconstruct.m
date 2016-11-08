%%
clear all;

I1 = imread('center.bmp');
I2 = imread('center1.bmp');

figure;
imshowpair(I1, I2, 'montage');
title('Original Images');

%%
% Detect feature points
imagePoints1 = detectMinEigenFeatures(I1, 'MinQuality', 0.1);

% Visualize detected points
figure
imshow(I1, 'InitialMagnification', 50);
title('150 Strongest Corners from the First Image');
hold on
plot(selectStrongest(imagePoints1, 150));

% Create the point tracker
tracker = vision.PointTracker('MaxBidirectionalError', 5, 'NumPyramidLevels', 10);
tracker.MaxIterations = 2000;

% Initialize the point tracker
imagePoints1 = imagePoints1.Location;
initialize(tracker, imagePoints1, I1);

% Track the points
[imagePoints2, validIdx] = step(tracker, I2);
matchedPoints1 = imagePoints1(validIdx, :);
matchedPoints2 = imagePoints2(validIdx, :);

% Visualize correspondences
figure
showMatchedFeatures(I1, I2, matchedPoints1, matchedPoints2);
title('Tracked Features');