clear; clc; close all;

% Load the files to MATLAB workspace 
load('Lab2_float.dat');
load('Lab2_double.dat');

% plot the relative error in log-log scale
loglog(Lab2_float(:,1),Lab2_float(:,end),'-bo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','b')
grid on
hold on
loglog(Lab2_double(:,1),Lab2_double(:,end),'--ro','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','r')

% making the plot look nicer
set(gca,'FontSize',16)
set(get(gca,'Xlabel'),'string','step size (log(h))','fontsize',20)
set(get(gca,'Ylabel'),'string','relative error (log(rel error))','fontsize',20,'Rotation',90.0)
set(legend('Single precision','Double precision','FontSize',16),'Location','north');
