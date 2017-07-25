function postprocessData

%% Load Data
load('TrackedLED.mat');

%% Process data
nUnits = length(trackedLED);

% Preallocate Memory
nonZeroIdx = cell(nUnits, 1);

for i = 1:length(trackedLED)
    nonZeroIdx{i} = find(sum(trackedLED(i).Centroid, 2) ~= 0);
end

% Find overlapped available points
perm = [1,2;1,3;2,3];
permIdx = cell(nUnits,1);
trainData(nUnits).in = [];
trainData(nUnits).out = [];
for i = 1:nUnits
    permNonZeroIdx = nonZeroIdx(perm(i,:));
    permIdx{i} = intersect(permNonZeroIdx{1},permNonZeroIdx{2});
    
    % Assemble Training Data
    trainData(i).in = [trackedLED(perm(i,1)).Centroid(permIdx{i},:), ...
        trackedLED(perm(i,2)).Centroid(permIdx{i},:)];
    trainData(i).out = ganPosSampleList(permIdx{i},1:3);
end

save('TrainData', 'trainData');
