close all; clear; clc;

syms x; % create the symbolic variable x

%% g1(x)

g1 = x - x^3 - 4*x^2 + 10; % function
Dg1 = diff(g1); % compute derivative analytically

figure(1)
h_g1 = ezplot(g1,[-3,3]); set(h_g1,'color','b','LineWidth',2);
hold on;
h_Dg1 = ezplot(Dg1,[-3,3]); set(h_Dg1,'color','r','LineWidth',2);
title(''); hold on;
l1 = line([-3 3], [-1 -1],'LineWidth',2,'Color','g','LineStyle','--'); hold on;
l2 = line([-3 3], [1 1],'LineWidth',2,'Color','g','LineStyle','--');

set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(gca,'FontSize',16)
set(legend([h_g1, h_Dg1, l1],'g_{1}(x)','g_{1}^{\prime}(x)','\pm 1','FontSize',14),'Location','southwest');

%% g2(x)

g2 = sqrt((10 - 4*x^2)/x); % function
Dg2 = diff(g2); % compute derivative analytically

figure(2)
h_g2 = ezplot(g2,[-3,3]); set(h_g2,'color','b','LineWidth',2);
hold on;
h_Dg2 = ezplot(Dg2,[-3,3]); set(h_Dg2,'color','r','LineWidth',2);
ylim([-20,20])
title(''); hold on;
l1 = line([-3 3], [-1 -1],'LineWidth',2,'Color','g','LineStyle','--'); hold on;
l2 = line([-3 3], [1 1],'LineWidth',2,'Color','g','LineStyle','--');

set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(gca,'FontSize',16)
set(legend([h_g2, h_Dg2, l1],'g_{2}(x)','g_{2}^{\prime}(x)','\pm 1','FontSize',14),'Location','southwest');

%% g3(x)

g3 = 0.5*sqrt(10 - x^3); % function
Dg3 = diff(g3); % compute derivative analytically

figure(3)
h_g3 = ezplot(g3,[-3,3]); set(h_g3,'color','b','LineWidth',2);
ylim([-4,4])
hold on;
h_Dg3 = ezplot(Dg3,[-3,3]); set(h_Dg3,'color','r','LineWidth',2);
ylim([-4,4])
title(''); hold on;
l1 = line([-3 3], [-1 -1],'LineWidth',2,'Color','g','LineStyle','--'); hold on;
l2 = line([-3 3], [1 1],'LineWidth',2,'Color','g','LineStyle','--');

set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(gca,'FontSize',16)
set(legend([h_g3, h_Dg3, l1],'g_{3}(x)','g_{3}^{\prime}(x)','\pm 1','FontSize',14),'Location','southwest');

%% g4(x)

g4 = sqrt(10/(x + 4)); % function
Dg4 = diff(g4); % compute derivative analytically

figure(4)
h_g4 = ezplot(g4,[-3,3]); set(h_g4,'color','b','LineWidth',2);
ylim([-4,4])
hold on;
h_Dg4 = ezplot(Dg4,[-3,3]); set(h_Dg4,'color','r','LineWidth',2);
ylim([-4,4])
title(''); hold on;
l1 = line([-3 3], [-1 -1],'LineWidth',2,'Color','g','LineStyle','--'); hold on;
l2 = line([-3 3], [1 1],'LineWidth',2,'Color','g','LineStyle','--');

set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(gca,'FontSize',16)
set(legend([h_g4, h_Dg4, l1],'g_{4}(x)','g_{4}^{\prime}(x)','\pm 1','FontSize',14),'Location','southwest');

%% g5(x)

g5 = x - ((x^3 + 4*x^2 - 10) / (3*x^2 + 8*x)); % function
Dg5 = diff(g5); % compute derivative analytically

figure(5)
h_g5 = ezplot(g5,[-3,3]); set(h_g5,'color','b','LineWidth',2);
ylim([-4,4])
hold on;
h_Dg5 = ezplot(Dg5,[-3,3]); set(h_Dg5,'color','r','LineWidth',2);
ylim([-4,4])
title(''); hold on;
l1 = line([-3 3], [-1 -1],'LineWidth',2,'Color','g','LineStyle','--'); hold on;
l2 = line([-3 3], [1 1],'LineWidth',2,'Color','g','LineStyle','--');

set(get(gca,'Xlabel'),'string','x','fontsize',20)
set(gca,'FontSize',16)
set(legend([h_g5, h_Dg5, l1],'g_{5}(x)','g_{5}^{\prime}(x)','\pm 1','FontSize',14),'Location','southwest');

