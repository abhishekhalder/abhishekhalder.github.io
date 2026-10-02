close all; clear; clc;

set(groot,'defaultAxesTickLabelInterpreter','latex');
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');

G1 = tf(3, [1 2]); G2 = tf(5, [1 -1]);
G_Series = series(G1,G2);
G_Parallel = parallel(G1,G2);
G_NegFeedback = feedback(G1,G2);

%% plot unit step response in [0,tfinal]
tfinal = 2;
figure(1)
stepplot(G_Series,G_Parallel,G_NegFeedback,tfinal)
set(findall(gcf,'type','line'),'linewidth',2)
xlabel('$t$','fontsize',30,'interpreter','latex');
ylabel('$y_{u}(t)$','fontsize',30,'interpreter','latex');
set(gca,'FontSize',30)
title('Unit step response','fontsize',25)
legend('FontSize',25,'Location','best','Interpreter','latex')
legend boxoff
