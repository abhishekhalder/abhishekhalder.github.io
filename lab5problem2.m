close all; clear; clc;

x = -5:0.1:4;
y = 2*(sin(x)./x);

% now plot the function
figure(1)
plot(x,y,'-b','LineWidth',2)
grid on
axis tight
hold on
% plot the x-axis (the line y = 0)
line([-5 4],[0 0], 'LineWidth',2,'Color','r')
hold on
stem(-2.2,2*(sin(-2.2)/(-2.2)),'LineWidth',2,'Color','r','MarkerFaceColor','r','MarkerEdgeColor','k')
hold on
stem(2,2*(sin(2)/2),'LineWidth',2,'Color','r','MarkerFaceColor','r','MarkerEdgeColor','k')

% fancy stuff
set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(get(gca,'Ylabel'),'string','f(x)','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)


%% Now plot the convergence trend

load('problem2plot.dat'); % load the data file

figure(2)
plot(problem2plot(:,1),'-b','LineWidth',2)
set(get(gca,'Xlabel'),'string','Iteration number','fontsize',20)
set(get(gca,'Ylabel'),'string','c','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)
axis tight

figure(3)
plot(abs(problem2plot(:,2)),'--b','LineWidth',2)
set(get(gca,'Xlabel'),'string','Iteration number','fontsize',20)
set(get(gca,'Ylabel'),'string','|f(c)|','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)
axis tight
