% arcConstVel.m - Jan 2015. Sandra Fang
% Creates a set of waypoints so that robot moves in a circular arc in 
% a constant ANGULAR velocity. 
%
% INPUT: center: center point of [x,y] circle that gantry is traveling around
%        radius: the radius of the circular trajectory
%        rot: total RADIANS traveled of circle. 
%        time: total amount of time (in s) it takes to complete this motion
%        interval: interval in degrees (time  between two successive pts.)
%
% OUTPUT: pos: position vector in (x,y,rotation (rad))
%         vel: velocity in m/s given in (x, y, yaw (rad/s))

function [pos, vel] = arcConstVel(center, radius, rot, time, interval)
    pos = [];
    vel = [];
    
    %time interval is like a resolution: 
    %the smaller the interval, the more points are used to make the arc.
    time_interval = 0:interval:time;
    omega = rot/time;
    
    theta = omega*time_interval;
    rps = omega*ones(size(time_interval,2),1); %radians per second
   
    x = radius*cos(theta)+center(1);
    dx = -radius*sin(theta);
    y = radius*sin(theta)+center(2);
    dy = radius*cos(theta);
    
    pos = [x',y',theta'];
    vel = [dx', dy', zeros(length(dx),1)];
end