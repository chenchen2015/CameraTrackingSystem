%ExecuteTrajectory.m: Move according to a set of velocity points
%inputs: vel: velocity
%        gantryTime: start time of communications when you turn on the
%           robot
%output: none for now
function ExecuteTrajectoryArc(pos,vel,gantryTime)
    global AxisId_PX AxisId_PY AxisId_PZ
    
    navCmd_getToPos([AxisId_PX,  pos(1,1), 0.1, 1]);
    navCmd_getToPos([AxisId_PY,  pos(1,2), 0.1, 1]);
    navCmd_getToPos([AxisId_PZ,  pos(1,3), 0.1, 1]);
    
    time = size(vel,1);
    for i=1:time
            navCmd_getToVel([AxisId_PX,  vel(i,1), 0.2]);
            navCmd_getToVel([AxisId_PY,  vel(i,2), 0.2]);
            navCmd_getToVel([AxisId_PZ,  vel(i,3), 0.2]);
            pause(1);
    end
    navCmd_getToVel([AxisId_PX,  0, 0.2]);
    navCmd_getToVel([AxisId_PY,  0, 0.2]);
    navCmd_getToVel([AxisId_PZ,  0, 0.2]);
    
    navCmd_getToPos([AxisId_PX,  pos(end,1), 1]);
    navCmd_getToPos([AxisId_PY,  pos(end,2), 1]);
    navCmd_getToPos([AxisId_PZ,  pos(end,3), 1]);
end