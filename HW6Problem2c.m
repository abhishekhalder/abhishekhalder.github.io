close all; clear; clc;

% Data
xx = 1:12;
yy = [54.6, 54.4, 67.1, 78.3, 85.3, 88.7, 96.9, 97.6, 84.1, 80.1, 68.8, 61.1];

plot(xx,yy,'ko','LineWidth',2,'MarkerFaceColor','k')
xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)
hold on

% Polynomial interpolation
P = vander(xx')\yy';
xev = linspace(1,12,500)';
yev = polyval(P,xev);
plot(xev,yev,'r--','LineWidth',2)

% Spline interpolation
s1 = spapi(2,xx,yy); fnplt(s1,2,'b-'), % linear spline
s3 = spapi(4,xx,yy); fnplt(s3,2,'g-.'), % cubic spline
legend('data','polynomial','linear spline','cubic spline'), hold off
axis tight