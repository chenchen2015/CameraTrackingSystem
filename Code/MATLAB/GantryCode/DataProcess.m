dataPath = 'Z:\Repos\CameraTrackingSystem-GitHub\branches\Sherwin_branch\Code\MATLAB\GantryCode\';
allFiles = dir(fullfile(dataPath, 'DataSet*.mat'));
dataFileName = {allFiles.name};
numOfDataSet = numel(dataFileName);
gantryPos = zeros(numOfDataSet, 3);
MatchPair1 = zeros(numOfDataSet, 2);
MatchPair2 = zeros(numOfDataSet, 2);
MatchPair3 = zeros(numOfDataSet, 2);
for i = 1:numOfDataSet
    load ([dataPath,dataFileName{i}]);
    gantryPos(i,:) = gantryPosition;
    if ~isempty(trackedLED(1).Centroid)
        MatchPair1(i,:) = trackedLED(1).Centroid;
    end
    if ~isempty(trackedLED(2).Centroid)
        MatchPair2(i,:) = trackedLED(2).Centroid;
    end
    if ~isempty(trackedLED(3).Centroid)
        MatchPair3(i,:) = trackedLED(3).Centroid;
    end
end
InputPair = [MatchPair1 MatchPair2 MatchPair3];