%{
gantry motion test for figuring out sampling rate of GetGanPosSnap
tic;
g.goToPos([0.5,0.0,-0.2,0.0]);
timer1 = toc;
atgoal = 0;
counts = 0;
while(atgoal == 0)
    currx = g.GetGanPosSnap;
    counts=counts+1;
    display(currx);
    if (norm(currx - [0.5,0,-0.2,0]') < 0.001)
        atgoal = 1; 
        display(currx);
        display(counts);
    end
end
toc;
g.goToPos([0.0,0.0,-0.2,0.0]);
atgoal=0;
while(atgoal == 0)
    currx = g.GetGanPosSnap;
    if (norm(currx - [0.0,0.0,-0.2,0.0]') < 0.001)
        atgoal = 1; 
        display(currx);
    end
end
%}

t=0:2*pi/40:2*pi;
e1 = exp(t*j);
plot(real(e1),imag(e1),'ro','MarkerFaceColor',[1 0 0]); axis([-1.2 1.2 -1.2 1.2]);daspect([1 1 1]);