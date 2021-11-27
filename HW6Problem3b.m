close all; clear; clc;

%% Plot control points

P = [-1 -1; 1 -1; 1 1; -1 1];
Q = [2/3 -2/3; 1 -1/3; 1 1/3; 2/3 2/3];
plot(P(:,1), P(:,2),'bo','MarkerEdgeColor','k','MarkerFaceColor','b')
hold on
plot(Q(:,1), Q(:,2),'ro','MarkerEdgeColor','k','MarkerFaceColor','r')
hold on
axis([-1 1 -1 1])
xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)
hold on

%% Method 1
u = 0:0.01:1;

x = (-1).*u.^2 + u + (2/3).*ones(1,length(u));
y = (-2/3).*u.^3 + u.^2 + u + (-2/3).*ones(1,length(u));
 
plot(x,y,'-g','LineWidth',2)
legend('B-spline control points P_{i}','Bezier control points Q_{i}','curve segment','Location','NorthWest')

%% Method 2

% u = linspace(0,1,100); 
% u2 = u.*u; u3 = u.*u2;
% 
% % B-spline basis functions
% b1 = 1/6*(1 - u).^3; b2 = u3/2 - u2 + 2/3;
% b3 = (-u3 + u2 + u + 1/3)/2; b4 = u3/6;
% 
% x = P(:,1); y = P(:,2);
% 
% % Plot B-spline
% for k = 1:length(P)-3
%     X = b1*x(k) + b2*x(k+1) + b3*x(k+2) + b4*x(k+3);
%     Y = b1*y(k) + b2*y(k+1) + b3*y(k+2) + b4*y(k+3);
%         if mod(k,2)==1, plot(X,Y,'g-','LineWidth',2); else
%         plot(X,Y,'k-'); end
% end