close all; clear; clc;
% housekeeping
set(groot,'defaultAxesTickLabelInterpreter','latex');  
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');

%% actual code starts here
% parameters
m = 1; l = 2; g = 9.81;

% system matrices
A = [0 1; -g/l 0]; B = [0; 1/(m*l^2)];
C = [1 0]; D = 0;
% create state space model
sys = ss(A,B,C,D);

tfinal = 50; 
figure(1)
stepplot(sys,tfinal)
set(findall(gcf,'type','line'),'linewidth',2)
xlabel('$t$ [s]','fontsize',30,'interpreter','latex'); 
ylabel('$y_{u}(t)$','fontsize',30,'interpreter','latex');
set(gca,'FontSize',30)
title('Unit step response','fontsize',25)
%legend('none')
legend boxoff