% save linearized plant after runnign dfemklin

t_end = t(end);
filename = input('Enter filename: ','s');
eval(['save ' filename '.mat a b c d tt tt1 time_linmod t_end']);
    
% fc01_V0912_dcx.mat a b c d tt tt1