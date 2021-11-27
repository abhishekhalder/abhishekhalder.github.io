close all; clear; clc;

load('Laguerre.dat'); % load the data file

% now plot the Laguerre polynomial
figure(1)
plot(Laguerre(:,1),Laguerre(:,2),'-b','LineWidth',2)
grid on

axis([-2 15 -15 20]) % axis limits

hold on
% plot the x-axis (the line y = 0)
line([-2 15],[0 0], 'LineWidth',2,'Color','r')

% fancy stuff
set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(get(gca,'Ylabel'),'string','L_{5}(x)','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)

%% Now plot the convergence trends for each of the five roots

load('Interval_0_1.dat'); % load the data file for 1st root
load('Interval_1_2.dat'); % load the data file for 2nd root
load('Interval_3_4.dat'); % load the data file for 3rd root
load('Interval_7_8.dat'); % load the data file for 4th root
load('Interval_12_13.dat'); % load the data file for 5th root

% Plot root versus iteration count
figure(2)
plot(Interval_0_1(:,1),'-bo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',10)
hold on
plot(Interval_1_2(:,1),'-go','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','g','MarkerSize',10)
hold on
plot(Interval_3_4(:,1),'-mo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','m','MarkerSize',10)
hold on
plot(Interval_7_8(:,1),'-ro','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',10)
hold on
plot(Interval_12_13(:,1),'-ko','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','k','MarkerSize',10)
axis tight

set(get(gca,'Xlabel'),'string','Iteration Number','fontsize',20)
set(get(gca,'Ylabel'),'string','c','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)
set(legend('root # 1 \in [0,1]','root # 2 \in [1,2]','root # 3 \in [3,4]','root # 4 \in [7,8]','root # 5 \in [12,13]','FontSize',14),'Location','northeast');

% Plot absolute value of the function at root versus the iteration count
figure(3)
plot(abs(Interval_0_1(:,2)),'-bo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',10)
hold on
plot(abs(Interval_1_2(:,2)),'-go','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','g','MarkerSize',10)
hold on
plot(abs(Interval_3_4(:,2)),'-mo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','m','MarkerSize',10)
hold on
plot(abs(Interval_7_8(:,2)),'-ro','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',10)
hold on
plot(abs(Interval_12_13(:,2)),'-ko','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','k','MarkerSize',10)
axis tight

set(get(gca,'Xlabel'),'string','Iteration Number','fontsize',20)
set(get(gca,'Ylabel'),'string','|f(c)|','fontsize',20,'Rotation',0.0)
set(gca,'FontSize',16)
set(legend('root # 1','root # 2','root # 3','root # 4','root # 5','FontSize',14),'Location','northeast');

