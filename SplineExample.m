close all; clear; clc;

xx = -1:0.4:1;
yy = 1./(1 + 25*xx.^2);

plot(xx,yy,'ko','LineWidth',2,'MarkerFaceColor','k')
xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)
hold on

sp2 = spapi(2,xx,yy); fnplt(sp2,2,'b-'), % linear spline
sp3 = spapi(3,xx,yy); fnplt(sp3,2,'g--'), % quadratic spline
sp4 = spapi(4,xx,yy); fnplt(sp4,2,'r-.'), % cubic spline
legend('data','linear','quadratic','cubic'), hold off