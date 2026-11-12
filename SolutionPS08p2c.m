close all; clear; clc;
set(groot,'defaultAxesTickLabelInterpreter','latex');
set(groot,'defaulttextinterpreter','latex');
set(groot,'defaultLegendInterpreter','latex');
s = tf('s');
sys = (0.1*s + 0.01)/((s+1)*(0.1*s + 1));
figure(1)
[mag,phase,wout] = bode(sys);
mag=squeeze(mag);
phase = squeeze(phase);
subplot(2,1,1)
semilogx(wout,20*log10(mag),'-b')
grid on
xlabel('$\omega$ [rad/s]','fontsize',30,'interpreter','latex');
ylabel('$M(\omega)$ [dB]','fontsize',30,'interpreter','latex');
set(gca,'FontSize',30)
subplot(2,1,2)
semilogx(wout,phase,'-b')
hold on
axis tight
grid on
xlabel('$\omega$ [rad/s]','fontsize',30,'interpreter','latex');
ylabel('$\phi(\omega)$ [degree]','fontsize',30,'interpreter','latex');
set(findall(gcf,'type','line'),'linewidth',2)
set(gca,'FontSize',30)

%% check magnitude and phase at 2 rad/s in Prob. 2(a)
% magnitude without 20*log10
MagnitudeAt2 = interp1(wout,mag,2,"pchip") 
% phase in rad
PhaseAt2 = (pi/180)*(interp1(wout,phase,2,"pchip"))
% plot the input and output
figure(2)
t=0:0.01:4*pi;
% input
u = sin(2*t);
% output from Bode plot
y = MagnitudeAt2*sin(2*t + PhaseAt2);
plot(t,u,'-k',t,y,'--k')
axis tight
grid on
xlabel('$t$ [s]','fontsize',30,'interpreter','latex');
set(findall(gcf,'type','line'),'linewidth',2)
legend('$u(t)$', '$y(t)$', 'fontsize',30,'interpreter','latex','Box','off')
set(gca,'FontSize',30)