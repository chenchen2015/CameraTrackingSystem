function trackedLED = processImages
%% Track IR LEDs and Save Tracked Result

%% File Select
imgPath = './Imgs/';
allFiles = dir(fullfile(imgPath, '*.bmp'));
imgFileName = {allFiles.name};
numOfImgs = length(allFiles);

%% Process Each Image
nUnits = 3;
nSamples = 1;

% Preallocate Memory
trackedLED(nUnits).LEDs = struct;
for i = 1:nUnits
    trackedLED(i).Centroid = zeros(nSamples,2);
end

% Image Plot Handles
figure(2);clf;
im = imread([imgPath,imgFileName{1}]);
seg_im = imquantize(im,multithresh(im,4));
bw = im2bw(im,0.9);
hIm = imshow(seg_im,[]);hold on;
hLED = plot(0,0,'g.','MarkerSize',24);
sortMethod = 'ascend';

% Process all the images
for i = 1:numOfImgs
    A = sscanf(imgFileName{i},'Unit%1d-Samp.bmp');
    unitID = A(1) + 1;
    sampID = 1;
    im = imread([imgPath,imgFileName{i}]);
%     thresh = graythresh(im) + 0.1;
%     thresh = 0.6;
    
    % If no LED is found
%     if thresh < 0.1
%         trackedLED(i).LEDs = [];
%         trackedLED(i).Centroid(sampID,:) = [];
%         trackedLED(i).Area(sampID) = [];
%         hIm.CData = double(im) / 255;
% %         hIm.CData = bw;
%         hLED.Color = 'r';
%         hLED.XData = 5;
%         hLED.YData = 5;
%         pause(0.01);
%         continue;
%     end
    
%     bw = im2bw(im,thresh);
    
    % Do blob detection
    stats = regionprops('table',bw,'Centroid','ConvexArea');
    if ~isempty(stats)
        stats = stats(stats.ConvexArea > 50,:);
    end
    
    % Sort and get the largest 6 blobs
    [~,idx] = sort(stats.ConvexArea,'descend');
    if length(idx) > 6
        stats = stats(idx(1:6),:);
    end
    
    % Kmeans clustering, two clusters
    nBlobs = numel(stats.ConvexArea);
%     if nBlobs > 2
%         trackedLED(unitID).Centroid(sampID,:) = checkClusters(stats.Centroid, sortMethod);
% %         [~, C] = kmeans(stats.Centroid,2);
% %         [~, idx] = sort(C(:,2),'ascend');
% %         trackedLED(unitID).Centroid(sampID,:) = C(idx(1),:);
%     elseif nBlobs >= 1
%         [~, idx] = sort(stats.Centroid(:,2), sortMethod);
%         trackedLED(unitID).Centroid(sampID,:) = stats.Centroid(idx(1),:);
%     else
%         hIm.CData = double(im) / 255;
%         hLED.Color = 'r';
%         hLED.XData = 5;
%         hLED.YData = 5;
%         pause(0.01);
%         continue;
%     end
    
%     stats = stats(stats.Centroid(:,2) > 500 & stats.Centroid(:,2) < 1700 & stats.ConvexArea > 300,:);
    
    
    fprintf('LED tracked - idx #%d, Unit #%d, Samp #%02d, n = %d\n', i, unitID, sampID, numel(stats.ConvexArea));
    if numel(stats.ConvexArea) == 3
%         trackedLED(i).LEDs = stats;
        trackedLED(i).Centroid(sampID,:) = mean(stats.Centroid);
        trackedLED(i).Area(sampID) = mean(stats.ConvexArea);
        
    elseif numel(stats.ConvexArea) > 3
        [~,idx] = sort(stats.Centroid(:,2),'descend');
        
        if norm(diff(stats(idx(1:3),:).Centroid(:,2))) > 10
%             trackedLED(i).LEDs = stats(idx(1),:);
            trackedLED(i).Centroid(sampID,:) = stats(idx(1),:).Centroid;
            trackedLED(i).Area(sampID) = stats(idx(1),:).ConvexArea;
        else
%             trackedLED(i).LEDs = stats(idx(1:3),:);
            trackedLED(i).Centroid(sampID,:) = mean(stats(idx(1:3),:).Centroid);
            trackedLED(i).Area(sampID) = mean(stats(idx(1:3),:).ConvexArea);
        end
    elseif ~isempty(stats)
        [~,idx] = sort(stats.Centroid(:,2),'descend');
%         trackedLED(i).LEDs = stats(idx(1),:);
        trackedLED(i).Centroid(sampID,:) = stats(idx(1),:).Centroid;
        trackedLED(i).Area(sampID) = stats(idx(1),:).ConvexArea;
    elseif isempty(stats)
        trackedLED(i).LEDs = [];
        trackedLED(i).Centroid(sampID) = [];
        trackedLED(i).Area(sampID) = [];
%         isTrackSuccess = 0;
    end
    
    % Update Plot
    hIm.CData = seg_im;
%     hIm.CData = bw;
    hLED.Color = 'g';
    hLED.XData = trackedLED(unitID).Centroid(sampID,1);
    hLED.YData = trackedLED(unitID).Centroid(sampID,2);
%     save('Data1.mat','trackedLED');
end

%% Assemble Output Data Structure
% dataSetStr = 'realTime';
% Comment = strcat('DataSet-', dataSetStr);
% SampleTime = datestr(now,'mm-dd-yyyy');
% 
% % Save Data
% save(SampleTime,'trackedLED','SampleTime');

end

function center = checkClusters(centroid, sortMethod)
[idx2, c2] = kmeans(centroid,3);

[c2_sort, idx] = sort(c2(:,2));
if min(diff(c2_sort)) > 80
    % Detected two shadows
    % Use the middle 
    center = mean(centroid(idx2 == idx(2),:));
else
    [~, c1] = kmeans(centroid,2);
    [~, idx] = sort(c1(:,2), sortMethod);
    center = c1(idx==1,:);
end

end