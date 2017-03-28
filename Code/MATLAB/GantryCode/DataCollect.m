g = GantryMove('192.168.1.121');
g.Connect;
%g.goToPos([-0.7,-0.4,0.2,0]);
%pause(10);
x = -0.7;
y = -0.4;
for i = 1:5
    x = x + 0.3;
    y = y + 0.15;
    g.goToPos([x,y,-0.2,0]);
    pause(5);
end
g.Disconnect;