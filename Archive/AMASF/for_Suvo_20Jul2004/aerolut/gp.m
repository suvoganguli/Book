clear all

M_step = 0.1; % nd
M_vec = 0.25:M_step:0.75;
alpha_step = 2; % deg
alpha_vec = -10:alpha_step:10;
beta_step = 2; % deg
beta_vec = -10:beta_step:10;
splr_step = 2; % deg
splr_vec = 0:splr_step:10;

nM = length(M_vec);
nalpha = length(alpha_vec);
nbeta = length(beta_vec);
nsplr = length(splr_vec);

var = ones(1,nalpha*nbeta*nsplr^2);
M_in = [];
for i = 1:nM
    M_in = [M_in (M_vec(1)+(i-1)*M_step)*var];
end

var = ones(1,nbeta*nsplr^2);
alpha_in = [];
for i = 1:nalpha
    alpha_in = [alpha_in (alpha_vec(1)+(i-1)*alpha_step)*var];
end
alpha_in = repmat(alpha_in,1,nM);

var = ones(1,nsplr^2);
beta_in = [];
for i = 1:nbeta
    beta_in = [beta_in (beta_vec(1)+(i-1)*beta_step)*var];
end
beta_in = repmat(beta_in,1,nM*nalpha);

var = ones(1,nsplr);
splr_left_in = [];
for i = 1:nsplr
    splr_left_in = [splr_left_in (splr_vec(1)+(i-1)*splr_step)*var];
end
splr_left_in = repmat(splr_left_in,1,nM*nalpha*nbeta);

splr_right_in = repmat(splr_vec,1,nM*nalpha*nbeta*nsplr);

t_in = 0.02*[0:nM*nalpha*nbeta*nsplr^2-1];

tM_in = [t_in' M_in'];
talpha_in = [t_in' alpha_in'];
tbeta_in = [t_in' beta_in'];
tsplr_left_in = [t_in' splr_left_in'];
tsplr_right_in = [t_in' splr_right_in'];


StatesInp(7) = 5000; % ft
QBAR = 150; % psf?
EAS = 210; % kts
cs = 1100; % ft/s
b = 124.524;  % ft
Cbar = 16.64; % ft
CG = 0.25; % nd
RunwayAlt = 9; % ?
weight = 185000; % lb

S = 1951; % ft^2

sim('aeroplt');


for i = 1:nM
    for j = 1:nalpha
        for k = 1:nbeta
            for l = 1:nsplr
                var = (i-1)*nalpha*nbeta*nsplr^2+(j-1)*nbeta*nsplr^2+(k-1)*nsplr^2+(l-1)*nsplr;
                CX_mat(:,l,k,j,i) = force_coeffs(var+1:var+nsplr,1);
                CY_mat(:,l,k,j,i) = force_coeffs(var+1:var+nsplr,2);
                CZ_mat(:,l,k,j,i) = force_coeffs(var+1:var+nsplr,3);
                CL_mat(:,l,k,j,i) = moment_coeffs(var+1:var+nsplr,1);
                CM_mat(:,l,k,j,i) = moment_coeffs(var+1:var+nsplr,2);
                CN_mat(:,l,k,j,i) = moment_coeffs(var+1:var+nsplr,3);
            end
        end
    end
end

save gp M_vec alpha_vec beta_vec splr_vec CX_mat CY_mat CZ_mat CL_mat CM_mat CN_mat
