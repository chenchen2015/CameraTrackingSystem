function [pos vel] = traj(center, radius, rot)
    clear pos vel
    x = radius*cos(rot*pi/180)+center(1);
    y = radius*sin(rot*pi/180)+center(2);
    
    stapos = [x y rot];
    endpos = [radius*cos(rot*pi/180)+center(1), ...
        radius*sin((360+rot)*pi/180)+center(2), ...
        rot+360];
    points(:,1) = [stapos(1) endpos(1)]/100';
    points(:,2) = [stapos(2) endpos(2)]/100';
    points(:,3) = [stapos(3) endpos(3)]*pi/180';
        
    time = [0; 5];
    [pos vel] = setUpTrajectory(points,time, 2);
end