function trackedLED = processImages
%% Track IR LEDs and Save Tracked Result

%% File Select
imgPath = './Imgs/';
IRFiles = dir(fullfile(imgPath, '*.bmp'));
% NoIRFiles = dir(fullfile(imgPath, '*_NoIR.bmp'));
IRFileName = {IRFiles.name};
% NoIRFileName = {NoIRFiles.name};
numOfImgs = length(IRFiles);

%% Process Each Image
nUnits = 3;
nSamples = ceil(numOfImgs / nUnits);

% Preallocate Memory
trackedLED(nUnits).LEDs = struct;
for i = 1:nUnits
    trackedLED(i).Centroid = zeros(nSamples,2);
end

% Image Plot Handles
figure(2);clf;
hIm = imshow(rand(2048));hold on;
hLED = plot(0,0,'g.','MarkerSize',24);
sortMethod = 'ascend';

% Process all the images
for i = 1:numOfImgs
% for i = 1100:1200
    A = sscanf(IRFileName{i},'Unit%1d-Samp%03d.bmp');
    unitID = A(1) + 1;
    sampID = A(2);
    im_IR = imread([imgPath,IRFileName{i}]);
%     im_NoIR = imread([imgPath,NoIRFileName{i}]);
%     seg_im = imquantize(im_NoIR,multithresh(im_NoIR,4));
    bw = im2bw(im_IR, 0.99);
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
    
    
    
    % Do blob detection
    stats = regionprops('table',bw,'Centroid','ConvexArea');
%     if ~isempty(stats)
%         stats = stats(stats.ConvexArea > 25,:);
%     end
    
%     % Sort and get the largest 6 blobs
%     [~,idx] = sort(stats.ConvexArea,'descend');
%     if length(idx) > 15
%         stats = stats(idx(1:15),:);
%     end
    
    % Kmeans clustering, two clusters
    nBlobs = numel(stats.ConvexArea);
    if nBlobs > 2
        trackedLED(unitID).Centroid(sampID,:) = checkThreeClusters(stats.Centroid, sortMethod);
%         [~, C] = kmeans(stats.Centroid,2);
%         [~, idx] = sort(C(:,2),'ascend');
%         trackedLED(unitID).Centroid(sampID,:) = C(idx(1),:);
    elseif nBlobs == 2
        trackedLED(unitID).Centroid(sampID,:) = checkTwoClusters(stats.Centroid);
    elseif nBlobs == 1
%         [~, idx] = sort(stats.Centroid(:,2), sortMethod);
        trackedLED(unitID).Centroid(sampID,:) = stats.Centroid(1,:);
    else
        trackedLED(unitID).LEDs = [];
        trackedLED(unitID).Centroid(sampID,:) = zeros(1,2);
        hIm.CData = double(im_IR) / 255;
        hLED.Color = 'r';
        hLED.XData = 5;
        hLED.YData = 5;
        pause(0.05);
        continue;
    end
    
%     stats = stats(stats.Centroid(:,2) > 500 & stats.Centroid(:,2) < 1700 & stats.ConvexArea > 300,:);
    
    
    fprintf('LED tracked - idx #%d, Unit #%d, Samp #%02d, n = %d\n', i, unitID, sampID, numel(stats.ConvexArea));
%     if numel(stats.ConvexArea) == 3
% %         trackedLED(i).LEDs = stats;
%         trackedLED(i).Centroid(sampID,:) = mean(stats.Centroid);
%         trackedLED(i).Area(sampID) = mean(stats.ConvexArea);
%         
%     elseif numel(stats.ConvexArea) > 3
%         [~,idx] = sort(stats.Centroid(:,2),'descend');
%         
%         if norm(diff(stats(idx(1:3),:).Centroid(:,2))) > 10
% %             trackedLED(i).LEDs = stats(idx(1),:);
%             trackedLED(i).Centroid(sampID,:) = stats(idx(1),:).Centroid;
%             trackedLED(i).Area(sampID) = stats(idx(1),:).ConvexArea;
%         else
% %             trackedLED(i).LEDs = stats(idx(1:3),:);
%             trackedLED(i).Centroid(sampID,:) = mean(stats(idx(1:3),:).Centroid);
%             trackedLED(i).Area(sampID) = mean(stats(idx(1:3),:).ConvexArea);
%         end
%     elseif ~isempty(stats)
%         [~,idx] = sort(stats.Centroid(:,2),'descend');
% %         trackedLED(i).LEDs = stats(idx(1),:);
%         trackedLED(i).Centroid(sampID,:) = stats(idx(1),:).Centroid;
%         trackedLED(i).Area(sampID) = stats(idx(1),:).ConvexArea;
%     elseif isempty(stats)
%         trackedLED(i).LEDs = [];
%         trackedLED(i).Centroid(sampID) = [];
%         trackedLED(i).Area(sampID) = [];
% %         isTrackSuccess = 0;
%     end
    
    % Update Plot
    hIm.CData = double(im_IR) / 255;
%     hIm.CData = double(im_NoIR) / 255;
%     hIm.CData = bw;
    hLED.Color = 'g';
    hLED.XData = trackedLED(unitID).Centroid(sampID,1);
    hLED.YData = trackedLED(unitID).Centroid(sampID,2);

    pause(0.05);
%     save('Data1.mat','trackedLED');
end

%% Assemble Output Data Structure
dataSetStr = 'realTime';
Comment = strcat('DataSet-', dataSetStr);
SampleTime = datestr(now,'mm-dd-yyyy');

% Save Data
save(SampleTime,'trackedLED','SampleTime');

end

function center = checkThreeClusters(centroid, sortMethod)
[idx2, c2] = kmeans(centroid,3);

[c2_sort, idx] = sort(c2(:,2));
if max(diff(c2_sort)) < 20 || min(diff(c2_sort)) > 80
    % Detected two shadows
    % Use the middle 
    center = mean(centroid(idx2 == idx(2),:),1);
else
    [idx1, c1] = kmeans(centroid,2);
    
    c = [1024,1024];
    dist = [];
    dist(1) = norm(c1(1,:) - c);
    dist(2) = norm(c1(2,:) - c);
    [~, idx] = min(dist);
    center = mean(centroid(idx1 == idx,:),1);
%     % Detected one shadow
%     % Choose the upper one
%     [~, idx] = sort(c1(:,2), sortMethod);
%     center = c1(idx==1,:);
end
end

function center = checkTwoClusters(centroid)

    [idx1, c1] = kmeans(centroid,2);
    
    c = [1024,1024];
    dist = [];
    dist(1) = norm(c1(1,:) - c);
    dist(2) = norm(c1(2,:) - c);
    [~, idx] = min(dist);
    center = mean(centroid(idx1 == idx,:),1);
end