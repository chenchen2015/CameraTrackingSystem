function trackLEDs(dataSetNumber, gantryPosition)
%% Track IR LEDs and Save Tracked Result

%% File Select
imgPath = 'Z:\Repos\CameraTrackingSystem-GitHub\branches\Sherwin_branch\Code\MATLAB\GantryCode\Imgs\';
allFiles = dir(fullfile(imgPath, '*.bmp'));
imgFileName = {allFiles.name};

%% Process Each Image
numOfImgs = 3;

% Preallocate Memory
trackedLED(numOfImgs).LEDs = struct;
trackedLED(numOfImgs).Centroid = [];

% Image Plot Handles
figure(dataSetNumber);clf;
im = imread([imgPath,imgFileName{dataSetNumber}]);
bw = im2bw(im,graythresh(im));
hIm = imshow(bw);hold on;
hLED = plot(0,0,'g.','MarkerSize',24);

for i = 1:numOfImgs
    start = (dataSetNumber-1)*3;
    im = imread([imgPath,imgFileName{i+start}]);
    thresh = graythresh(im);
    if thresh < 0.1
        trackedLED(i).LEDs = [];
        trackedLED(i).Centroid = [];
        trackedLED(i).Area = [];
        continue
    end
    bw = im2bw(im,thresh);
    
    % Do blob detection
    stats = regionprops('table',bw,'Centroid','ConvexArea');
    
    stats = stats(stats.Centroid(:,2) > 500 & stats.Centroid(:,2) < 1700 & stats.ConvexArea > 500,:);
    
    if numel(stats.ConvexArea) == 3
        trackedLED(i).LEDs = stats;
        trackedLED(i).Centroid = mean(stats.Centroid);
        trackedLED(i).Area = mean(stats.ConvexArea);
        
        fprintf('LED tracked - norm diff = %.2f\n',...
            norm(diff(trackedLED(i).LEDs.Centroid(:,2))));
    elseif numel(stats.ConvexArea) > 3
        [~,idx] = sort(stats.Centroid(:,2),'descend');
        
        if norm(diff(stats(idx(1:3),:).Centroid(:,2))) > 10
            trackedLED(i).LEDs = stats(idx(1),:);
            trackedLED(i).Centroid = stats(idx(1),:).Centroid;
            trackedLED(i).Area = stats(idx(1),:).ConvexArea;
            fprintf('LED tracked\n');
        else
            trackedLED(i).LEDs = stats(idx(1:3),:);
            trackedLED(i).Centroid = mean(stats(idx(1:3),:).Centroid);
            trackedLED(i).Area = mean(stats(idx(1:3),:).ConvexArea);
            
            fprintf('LED tracked - norm diff = %.2f\n',norm(diff(trackedLED(i).LEDs.Centroid(:,2))));
        end
        
    elseif ~isempty(stats)
        [~,idx] = sort(stats.Centroid(:,2),'descend');
        trackedLED(i).LEDs = stats(idx(1),:);
        trackedLED(i).Centroid = stats(idx(1),:).Centroid;
        trackedLED(i).Area = stats(idx(1),:).ConvexArea;
    elseif isempty(stats)
        trackedLED(i).LEDs = [];
        trackedLED(i).Centroid = [];
        trackedLED(i).Area = [];
    end
    
    % Update Plot
    hIm.CData = bw;
    hLED.XData = trackedLED(i).LEDs.Centroid(:,1);
    hLED.YData = trackedLED(i).LEDs.Centroid(:,2);
    %%pause;
end

%% Assemble Output Data Structure
dataSetStr = num2str(dataSetNumber);
Comment = strcat('DataSet', dataSetStr);
SampleTime = datestr(now,'mm-dd-yyyy');

% Save Data
save(Comment,'trackedLED','gantryPosition','SampleTime');

end