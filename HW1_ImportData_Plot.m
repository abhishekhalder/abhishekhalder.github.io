clear; clc; close all;

% Load the files to MATLAB workspace 
load('Lab2_float.dat');
load('Lab2_double.dat');
load('HW1_float.dat');
load('HW1_double.dat');

% plot the relative error in log-log scale
loglog(Lab2_float(:,1),Lab2_float(:,end),'-bo','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',5)
hold on
loglog(Lab2_double(:,1),Lab2_double(:,end),'--ro','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',5)
hold on
loglog(HW1_float(:,1),HW1_float(:,end),'-gs','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor','g','MarkerSize',5)
hold on
loglog(HW1_double(:,1),HW1_double(:,end),'--ms','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor','m','MarkerSize',5)
grid on

% making the plot look nicer
set(gca,'FontSize',16)
set(get(gca,'Xlabel'),'string','step size (h)','fontsize',20)
set(get(gca,'Ylabel'),'string','relative error','fontsize',20,'Rotation',90.0)
set(legend('Single precision forward difference (Lab 2)','Double precision forward difference (Lab 2)','Single precision central difference (HW 1)','Double precision central difference (HW 1)','FontSize',12),'Location','southeast');
