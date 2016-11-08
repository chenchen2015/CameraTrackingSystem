function epipolarGeometry()
%% Load Image and Estimate Foundamental Matrix
%
% Chen Chen
% 8.2.2016

IMG_PATH = '../Data/Test3/';
%% Load Session Data
load('Test3-test1-MatchedPts');

%% Compute Fundamental Matrix
% [F,inliersIndex,status] = estimateFundamentalMatrix(matchPt1',matchPt2',...
%     'Method','Norm8Point','NumTrials', 4000,'InlierPercentage',99);
[F,inliersIndex,status] = estimateFundamentalMatrix(matchPt1',matchPt2',...
    'Method','MSAC','NumTrials', 100000,'DistanceThreshold',0.1);

%% Compute Camera Matrix
[orientation,location] = cameraPose(F,cameraParams,matchPt1',matchPt2');
rotationMatrix = orientation';
translationVector = -location * rotationMatrix;

camMatrix = cameraMatrix(cameraParams,rotationMatrix,translationVector);

%%
worldPoints = triangulate(matchedPoints1,matchedPoints2,zeros(4,3),camMatrix);

% 
% %% Read Images
% I1 = CapturedImgPair(1).Im1;
% I2 = CapturedImgPair(1).Im2;
% 
% points1 = detectMSERFeatures(CapturedImgPair(1).Im1);
% points2 = detectMSERFeatures(CapturedImgPair(1).Im2);
% 
% [features1,valid_points1] = extractFeatures(I1,points1);
% [features2,valid_points2] = extractFeatures(I2,points2);
% 
% indexPairs = matchFeatures(features1,features2);
% 
% matchedPoints1 = valid_points1(indexPairs(:,1),:);
% matchedPoints2 = valid_points2(indexPairs(:,2),:);
% 
% figure; showMatchedFeatures(I1,I2,matchedPoints1,matchedPoints2);

end