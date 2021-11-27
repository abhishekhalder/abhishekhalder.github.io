close all; clear; clc;

n = [1, 2, 5];

linestyles = cellstr(char('--','-.',':')); % automate line styles
cc = jet(length(n)); % automate line color

xmin = -1; xmax = 1; dx = 0.1; % domain
x = xmin : dx : xmax;

figure(1)
f = exp(x); % true function
plot(x,f,'-ro','LineWidth',2,'MarkerEdgeColor','k','MarkerFaceColor','r')
hold on
xlabel('x','fontsize',20); ylabel('y','fontsize',20); 
set(gca,'FontSize',16)

for j=1:length(n)
    for k=1:n(j)
        for i=1:length(x)
            term(i,k) = (((-1)^k)/(1 + k^2))*(cos(k*x(i)) - k*sin(k*x(i)));
        end
    end

    TermSum = sum(term,2); % vector of length same as x

    preFactor = (exp(pi) - exp(-pi))/pi; % scalar

    fhat = preFactor*(0.5*ones(length(TermSum),1) + TermSum); % least square approximation

    plot(x,fhat,'color',cc(j,:),'LineWidth',2)
    hold on
end
legend('f(x) = e^x','fhat(x), n = 1','fhat(x), n = 2','fhat(x), n = 5','Location','NorthWest')
hold off
