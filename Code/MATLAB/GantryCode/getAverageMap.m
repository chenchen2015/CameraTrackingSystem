%%takes a tank map file name, and then an array of the filenames of the
%%data gathered from the takes
%to run: getAverageMap('.\testdata\tank.mat', namearray);

function [averagemap] = getAverageMap(tankmapFile, takesFileArray)
    mapTank = importdata(tankmapFile); 
    averagemap = zeros(size(mapTank.map));
    numTakes = size(takesFileArray,1);
    for i=1:numTakes
        datastructure = importdata(takesFileArray(i,:));
        averagemap = averagemap + datastructure.map - mapTank.map;
    end
    averagemap = averagemap/numTakes;
end

