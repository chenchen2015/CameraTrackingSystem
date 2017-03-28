% createConVel
% Creates a set of waypoints so that robot moves with constant velocity in
% a straight path from A to B. Multiple points ABC can be defined if we
% define time at pt. A, B, C. 
% points = matrix of starting points and end points
% ugh why would you ever not comment this code :( 
function [pos vel] = waypointsConstVel(points, time)
    interval = 0.01;
    pos = [];
    vel = [];
    if size(time,1)==size(points,1)

        for i = 1:size(time,1)-1

            velH(i,:) = (points(i+1,:) - points(i,:))/(time(i+1)-time(i));

            tvec = time(i):interval:time(i+1);

            velHold = repmat(velH(i,:)*.01,[length(tvec), 1]);
            if i == 1

                vel = velHold;
            else
                vel = [vel(1:end-1,:); velHold];
            end

        end

        pos = cumsum(vel)+repmat(points(1,:),[length(vel) 1]);
    else
        error('Time and Point Vector do not match')
end