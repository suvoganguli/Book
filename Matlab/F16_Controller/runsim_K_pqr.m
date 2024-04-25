% runsim_K_q.m

% Author: Subhabrata Ganguli

% setup
load F16lin.mat
load trimcond.mat

C_nl = C(8,:);
CB_nl = C_nl*B(:,2);
invCB_nl = inv(CB_nl);
CA_nl = C_nl*A;

C_rate = C([7:9 13],:);

K_rate = 4*ones(4,1);
fc_rate = 1/2*ones(4,1);
fi_rate = 1/4*ones(4,1);
