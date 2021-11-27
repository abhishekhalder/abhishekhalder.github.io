clear all; close all; clc;
% Run this file after running the C++ code in Homework4Problem3c.cpp
load Hilbert2.dat;
load Hilbert4.dat;
load Hilbert8.dat;
load Hilbert16.dat;
load Hilbert32.dat;

% Create a cell of Hilbert matrices
Hilbert = {Hilbert2, Hilbert4, Hilbert8, Hilbert16, Hilbert32};

%% Method 1 (without inversion)
for i = 1:numel(Hilbert)
    ProdMatrix = (Hilbert{1,i})*(Hilbert{1,i})';
    k2_method1(i) = sqrt((max(abs(eig(ProdMatrix))))/(min(abs(eig(ProdMatrix)))));
    dim(i) = 2^i;
end
figure(1)
plot(dim, k2_method1,'-bo','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','b','MarkerSize',10)
hold on;

%% Method 2 (with inversion)
for i = 1:numel(Hilbert)
    k2_method2(i) = norm(Hilbert{1,i},2)*norm(inv(Hilbert{1,i}),2);
end
plot(dim, k2_method2,'-ro','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','r','MarkerSize',10)

xlabel('Dimension of Hilbert matrix H'); ylabel('\kappa_{2}(H)')
legend('Method 1','Method 2','Location','NorthWest')

%% Method 3 with analytical computation (for comparison purpose only)
for i = 1:numel(Hilbert)
    k2_analytical(i) = norm(hilb(2^i),2)*norm(invhilb(2^i),2);
end
figure(2)
plot(dim, k2_analytical,'-go','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','g','MarkerSize',10)
% Clearly, both methods 1 and 2 underpredict the value of condition number
% This is due to the round-off errors in our C++ code, using inv(), and
% eig() for an ill-conditioned matrix

xlabel('Dimension of Hilbert matrix H'); ylabel('\kappa_{2}(H)')
legend('Analytical','Location','NorthWest')

