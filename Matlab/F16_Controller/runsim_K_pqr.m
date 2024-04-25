% runsim_K_pqr.m

% Author: Subhabrata Ganguli

% setup
load trimcond.mat

C_rate = C([7:9 13],:);

K_rate = 8*ones(4,1);
fc_rate = 1/2*ones(4,1);
fi_rate = 1/4*ones(4,1);

tstep = 0.1;
tdoublet = 3; 

% Step Commands
pc = 0; % deg/s
qc = 1; % deg/s
rc = 0; % deg/s
powc = 0; % percentage
