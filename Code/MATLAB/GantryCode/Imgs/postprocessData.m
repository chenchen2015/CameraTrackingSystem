function postprocessData

%% Load Data
% load('TrackedLED.mat');
load('session4.mat');
load('../09-05-2017.mat')

%% Process data
nUnits = length(trackedLED);

% Preallocate Memory
nonZeroIdx = cell(nUnits, 1);

for i = 1:length(trackedLED)
    nonZeroIdx{i} = find(sum(trackedLED(i).Centroid, 2) ~= 0);
end

% Find overlapped available points
perm = [1,2,3;1,2,4;1,3,4;2,3,4];
permIdx = cell(nUnits,1);
trainData(nUnits).in = [];
trainData(nUnits).out = [];
for i = 1:nUnits
    permNonZeroIdx = nonZeroIdx(perm(i,:));
    permIdx{i} = intersect(intersect(permNonZeroIdx{1},permNonZeroIdx{2}),permNonZeroIdx{3});
    
    % Assemble Training Data
    trainData(i).in = [trackedLED(perm(i,1)).Centroid(permIdx{i},:), ...
        trackedLED(perm(i,2)).Centroid(permIdx{i},:), trackedLED(perm(i,3)).Centroid(permIdx{i},:)];
    trainData(i).out = ganPosSampleList(permIdx{i},1:3);
end

save('TrainData2', 'trainData');
