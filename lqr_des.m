theta0 = 0;

A = [0 1; g*cos(theta0),0]; B = [0; 1];

QQ = diag([1,1]); RR = [0.1];

k_lqr = lqr(A,B,QQ,RR);