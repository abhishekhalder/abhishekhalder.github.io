close all; clear; clc;

% Load data file
load('Newton.dat');

%% Compute convergence parameters
% Order of convergence (alpha)
alpha = (Newton(end,end) - Newton(end-1,end))/(Newton(end-1,end) - Newton(end-2,end));
% Asymptotic error constant (lambda)
lambda = Newton(end,end-1)/((Newton(end-1,end-1))^alpha);