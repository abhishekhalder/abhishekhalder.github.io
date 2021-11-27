close all; clear; clc;
%% load data files
load 'HW6Problem2cData.dat';
load 'InterpPoly.dat'; 
load 'InterpSplineLinear.dat'; 
load 'InterpSplineCubic.dat';
%% Plot
plot(HW6Problem2cData(:,1), HW6Problem2cData(:,2), 'ko', 'LineWidth', 2, 'MarkerFaceColor', 'k')
hold on
plot(InterpPoly(:,1), InterpPoly(:,2), 'r--', 'LineWidth', 2)
hold on
plot(InterpSplineLinear(:,1), InterpSplineLinear(:,2), 'b-', 'LineWidth', 2)
hold on
plot(InterpSplineCubic(:,1), InterpSplineCubic(:,2), 'g-.', 'LineWidth', 2)

xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)
legend('data','polynomial','linear spline','cubic spline'), hold off
axis tight
