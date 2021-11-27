% =========================================================================
% Title of Code: Function to compute W between multivariate Gaussians
% Date: 09/19/2013
% Authors: Abhishek Halder, Raktim Bhattacharya
% Laboratory for Uncertainty Quantification (uq.tamu.edu)
% Dept. of Aerospace Engineering, Texas A&M University.
% Code provided under standard GPLv3 license (https://gnu.org/licenses/gpl-3.0.txt)
% =========================================================================

function W = mvnWasserstein(mu1,mu2,Sigma1,Sigma2)

MuDiscrepancy = norm(mu1 - mu2, 2);

TripleProductTerm = (sqrtm(Sigma1))*Sigma2*(sqrtm(Sigma1));

SigmaSquareDiscrepancy = trace(Sigma1) + trace(Sigma2) - 2*trace(sqrtm(TripleProductTerm));

W = sqrt(MuDiscrepancy^2 + SigmaSquareDiscrepancy);