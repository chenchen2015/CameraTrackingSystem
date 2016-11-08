function trackLEDs()
%% Track IR LEDs and Save Tracked Result

%% File Select
disp('Specify image file pair to read');
[imgFileName,imgPath] = uigetfile({'*.png;*.bmp;*.jpg','Image files'},'Select a image file to read',...
    'MultiSelect','On');

%% Process Each Image
numOfImgs = numel(imgFileName);

% Preallocate Memory
trackedLED(numOfImgs).LEDs = struct;
trackedLED(numOfImgs).Centroid = [];

% Image Plot Handles
figure(1);clf;
im = imread([imgPath,imgFileName{1}]);
bw = im2bw(im,graythresh(im));
hIm = imshow(bw);hold on;
hLED = plot(0,0,'g.','MarkerSize',24);

for i = 1:numOfImgs
    im = imread([imgPath,imgFileName{i}]);
    bw = im2bw(im,graythresh(im));
    
    % Do blob detection
    stats = regionprops('table',bw,'Centroid','ConvexArea');
    
    stats = stats(stats.Centroid(:,2) > 500 & stats.Centroid(:,2) < 1700,:);
    
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
    end
    
    % Update Plot
    hIm.CData = bw;
    hLED.XData = trackedLED(i).LEDs.Centroid(:,1);
    hLED.YData = trackedLED(i).LEDs.Centroid(:,2);
    pause;
end

%% Assemble Output Data Structure
gantryPosition = [-0.52135,0.41379];
Comment = 'test4';
SampleTime = datestr(now,'mm-dd-yyyy');

% Save Data
save('Test-5','trackedLED','gantryPosition','Comment','SampleTime');

end