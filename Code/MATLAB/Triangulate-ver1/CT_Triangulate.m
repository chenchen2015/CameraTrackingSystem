function [points3d, reprojectionErrors] = CT_Triangulate()
%% Load Data
load('./Data/StereoCameraCalibration-2.mat');
load('./Data/TestImg-2.mat');

%% Calculate Camera Matrix
cameraMatrix1 = cameraMatrix(stereoParams.CameraParameters1, eye(3), [0 0 0]);
cameraMatrix2 = cameraMatrix(stereoParams.CameraParameters2, ...
    stereoParams.RotationOfCamera2, stereoParams.TranslationOfCamera2);

cameraMatrices = cat(3, cameraMatrix1, cameraMatrix2);

%%
points = cat(3, matchedPt1, matchedPt2);
if isa(points, 'double')
    points2d = points;
else
    points2d = single(points);
end

%% Main Loop
numPoints = size(points2d, 1);
points3d = zeros(numPoints, 3, 'like', points2d);
reprojectionErrors = zeros(numPoints, 1, 'like', points2d);

for i = 1:numPoints
    [points3d(i, :), errors] = ...
        triangulateOnePoint(cameraMatrices, squeeze(points2d(i, :, :))');
    reprojectionErrors(i) = mean(hypot(errors(:, 1), errors(:, 2)));
end

%%
function [point3d, reprojectionErrors] = ...
    triangulateOnePoint(cameraMatrices, matchingPoints)

% do the triangulation
numViews = size(cameraMatrices, 3);
A = zeros(numViews * 2, 4);
for i = 1:numViews
    P = cameraMatrices(:,:,i)';
    A(2*i - 1, :) = matchingPoints(i, 1) * P(3,:) - P(1,:);
    A(2*i    , :) = matchingPoints(i, 2) * P(3,:) - P(2,:);
end

[~,~,V] = svd(A);
X = V(:, end);
X = X/X(end);

point3d = X(1:3)';

reprojectedPoints = zeros(size(matchingPoints), 'like', matchingPoints);
for i = 1:numViews
    reprojectedPoints(i, :) = projectPoints(point3d, cameraMatrices(:, :, i));
end
reprojectionErrors = reprojectedPoints - matchingPoints;


%--------------------------------------------------------------------------
function points2d = projectPoints(points3d, P)
points3dHomog = [points3d, ones(size(points3d, 1), 1, 'like', points3d)];
points2dHomog = points3dHomog * P;
points2d = bsxfun(@rdivide, points2dHomog(:, 1:2), points2dHomog(:, 3));
