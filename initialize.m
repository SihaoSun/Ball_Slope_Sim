close all;
clear all;

%% parameters
m = 1; %mass of the ball, kg
R = 1; %radius of the slope, m
r = 0.1; %radius of the ball, m
c = 0; %damping, 1/s

g = 9.81;
umax =  9*m; % N
umin = -9*m; % N

sign = 1; 
%% initial conditions

theta0  = 0;
dtheta0 = 0;

x0 = [theta0, dtheta0]';

%% Call animation function
animation_figure_id = 100;
close(figure(animation_figure_id));
figure(animation_figure_id)
set(gcf,'position',[1400,500,450,400])
ax = axes('XLim',[-2,2],'YLim',[-1,3],'ZLim',[-5,5]); 
h_ball = rectangle('position',[-r,-r,2*r,2*r],'Curvature',[1 1]); hold on;

if sign == 1
    h_slope = plot([-R:0.01:R],sqrt(R^2-[-R:0.01:R].^2));
else
    h_slope = plot([-R:0.01:R],-sqrt(R^2-[-R:0.01:R].^2));
end
t_ball = hgtransform('Parent',ax);
t_slope = hgtransform('Parent',ax);
set(h_ball,'Parent',t_ball);
set(h_slope,'Parent',t_slope);


if sign == 1
    set(t_ball,'Matrix',makehgtform('translate',[0 R+r 0]));
else
    set(t_slope,'Matrix',makehgtform('translate',[0 R-r 0]));
end

%% design lqr gains
lqr_des;

%% initialization of RLS
C0 = [0 0 0]';
P0 = 100*eye(3);