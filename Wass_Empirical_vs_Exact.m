% =========================================================================
% Title of Code: Accuracy of W computation: empirical versus exact
% Date: 09/19/2013
% Authors: Abhishek Halder, Raktim Bhattacharya
% Laboratory for Uncertainty Quantification (uq.tamu.edu)
% Dept. of Aerospace Engineering, Texas A&M University.
% Code provided under standard GPLv3 license (https://gnu.org/licenses/gpl-3.0.txt)
% =========================================================================

clear; clc; close all;

% First Gaussian
mu0 = [0; 0]; Sigma0 = 9*eye(2);
% Second Gaussian
mu1 = [10;15]; Sigma1 = 25*eye(2);

% Compute exact value of W
W_exact = mvnWasserstein(mu0,mu1,Sigma0,Sigma1);

%% Empirical computation
Nsample = 1000; Ndraw = 100;

Aeq = [kron(ones(1,Nsample),speye(Nsample));
      kron(speye(Nsample),ones(1,Nsample))];

W_empirical = zeros(Ndraw,1); % initialize  
  
for k = 1:Ndraw
    % Sample each distribution
    y0 = mvnrnd(mu0,Sigma0,Nsample); y1 = mvnrnd(mu1,Sigma1,Nsample);
    % Evaluate PDF for each sample set
    rho0 = mvnpdf(y0,mu0',Sigma0); rho1 = mvnpdf(y1,mu1',Sigma1);

%     figure(1)
%     scatter(y0(:,1),y0(:,2),10,rho0)
%     hold on
%     scatter(y1(:,1),y1(:,2),10,rho1)    
%     axis tight

    for i=1:Nsample
        for j=1:Nsample
            C(i,j) = (y0(i,1) - y1(j,1))^2 + (y0(i,2) - y1(j,2))^2; % Euclidean 2-norm
        end
    end
    c = reshape(C,Nsample^2,1); % vectorize the cost for linprog
    clear C; % free some space
   
    % Equality constraints
    beq = [rho0/(sum(rho0)); rho1/(sum(rho1))]; % create the vector beq of size 2*Nsample-by-1; elements are marginal pmf vectors

    % Solve LP to find the empirical Wasserstein distance
    tic;
    [jpmf_opt,J_opt] = linprog(c,[],[],Aeq,beq,sparse(zeros(Nsample^2,1)),Inf(Nsample^2,1));
    toc;
    disp(['Linprog ', num2str(k) ' done']);
    W_empirical(k) = sqrt(J_opt);
end

% Compute the relative error
rel_error = abs((W_exact*ones(Ndraw,1) - W_empirical)/W_exact);

%% Plot stuff

figure(1)
hist(W_empirical)
hold on
line([W_exact W_exact], [0 25],'LineWidth',2,'Color','r')

figure(2)
hist(rel_error)
axis tight
