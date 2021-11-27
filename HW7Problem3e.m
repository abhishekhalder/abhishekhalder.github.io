close all; clear; clc;

%% The integrand function plot
xmin = -1; xmax = 1;

x = (xmin:0.001:xmax)';
y = 1./(ones(length(x),1)+x.^2);

plot(x,y,'-b','LineWidth',2)
xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)
hold on

%% Midpoint method plot
rectangle('Position',[-1,1/2,1,(4/5 - 1/2)],'LineWidth',2,'LineStyle','--')
hold on
rectangle('Position',[0,1/2,1,(4/5 - 1/2)],'LineWidth',2,'LineStyle','--')
hold on

%% Trapezoid method plot
nTrapzPoints = 3; 
xx = xmin :(xmax-xmin)/(nTrapzPoints - 1) : xmax;
yy = 1./(ones(1, length(xx))+ xx.^2);
for k=1:1:length(xx)-1
    rx = [xx(k) xx(k) xx(k+1) xx(k+1)];
    ry = [yy(k) min(y) yy(k+1) min(y)];
    k = convhull(rx, ry);
    fill (rx(k), ry(k), 'g','facealpha', 0.3); 
end
plot(xx,yy,'yo','LineWidth',2,'MarkerFaceColor','y')
hold on

%% Simpson's method plot
nParabola_3pt = 1; % 1 parabola for 3 points 
nParabola_5pt = 2; % 2 parabolas for 5 points
h3 = (xmax - xmin)/nParabola_3pt; 
h5 = (xmax - xmin)/nParabola_5pt;
f = '1/(1+z^2)';
% 3 point Simpson's method
for j = 1:1:nParabola_3pt
    L(j) = xmin + h3*(j-1);
    R(j) = L(j) + h3;
    c(j)=(L(j)+R(j))/2;
    
    YL(j) = subs(f,L(j));
    YR(j) = subs(f,R(j));
    Yc(j) = subs(f,c(j));
    
    polyfit([L(j) R(j) c(j)], [YL(j) YR(j) Yc(j)], 2);
    plot(L(j):.0001:R(j), polyval(polyfit([L(j) R(j) c(j)], [YL(j) YR(j) Yc(j)], 2),L(j):.0001:R(j)),'--r','LineWidth',2');
    hold on
end
% 5 point Simpson's method
for j = 1:1:nParabola_5pt
    L(j) = xmin + h5*(j-1);
    R(j) = L(j) + h5;
    c(j)=(L(j)+R(j))/2;
    
    YL(j) = subs(f,L(j));
    YR(j) = subs(f,R(j));
    Yc(j) = subs(f,c(j));
    
    polyfit([L(j) R(j) c(j)], [YL(j) YR(j) Yc(j)], 2);
    plot(L(j):.0001:R(j), polyval(polyfit([L(j) R(j) c(j)], [YL(j) YR(j) Yc(j)], 2),L(j):.0001:R(j)),'--m','LineWidth',2');
    hold on
end
axis tight
