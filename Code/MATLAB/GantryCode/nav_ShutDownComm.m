%% Function nav_ShutDownComm
% Shuts down all the tcp-ip communication
% Apr. 9, 2015
% Chen Chen

function nav_ShutDownComm(~)
global MNETCan2PodM2P MNETGanCntrlMsgM2P MNETGanDataP2M MNETMsgExeConfP2M
global MNETStrmESDataP2M MNETStrmGanMotionDataP2M MNETTextMsgP2M

fclose(MNETCan2PodM2P);
fclose(MNETGanCntrlMsgM2P);
fclose(MNETGanDataP2M);
fclose(MNETMsgExeConfP2M);
fclose(MNETStrmESDataP2M);
fclose(MNETStrmGanMotionDataP2M);
fclose(MNETTextMsgP2M);

delete MNETCan2PodM2P MNETGanCntrlMsgM2P MNETGanDataP2M MNETMsgExeConfP2M
delete MNETStrmESDataP2M MNETStrmGanMotionDataP2M MNETTextMsgP2M