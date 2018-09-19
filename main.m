% Ball_Slope_Sim;
% signal = load('signal3211.mat');
load('signalchirp.mat');

set_param('Ball_Slope_Sim','SaveFinalState','on','FinalStateName','myOperPoint','SaveCompleteFinalSimState','on');
theta_eq = 0;
Eigens = timeseries;
eigens_last = timeseries;
for i = 1:1
    
    simOut = sim('Ball_Slope_Sim','StopTime',num2str(10*i));

    signalchirp.Time = signalchirp.Time + 10;
    
    theta_eq = i*20;
    
    set_param('Ball_Slope_Sim','LoadInitialState','on','InitialState','myOperPoint');
    myOperPoint = simOut.get('myOperPoint');
    
    Eigens = append(eigens_last,simOut.get('eigens'));
    
    eigens_last = simOut.get('eigens');
end

set_param('Ball_Slope_Sim','LoadInitialState','off');
set_param('Ball_Slope_Sim','SaveFinalState','off');