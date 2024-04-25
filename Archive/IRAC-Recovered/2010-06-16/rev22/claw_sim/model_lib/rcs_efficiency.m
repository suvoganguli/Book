function [rcs_cmd, cvddes_actual, total_norm, component_norm] = rcs_efficiency(vehicle_params, pqr_wght_cv, ulim, llim)

global MACH

r_rcs = vehicle_params.r_rcs;
r_cg = vehicle_params.r_cg_noprop;
Frcs = vehicle_params.Frcs;
inertia = vehicle_params.inertia_noprop;
[neq, nrcs] = size(r_rcs);

if(~exist('llim') || isempty(ulim))
    if(isfield(MACH,'pqr_u_llim'))
        ulim = MACH.pqr_u_ulim(MACH.pqr_u_rcs_idx);
        llim = MACH.pqr_u_llim(MACH.pqr_u_rcs_idx);
    else
        ulim = ones(nrcs,1);
        llim = zeros(nrcs,1);
    end
end
ulim = reshape(ulim,nrcs,1);
llim = reshape(llim,nrcs,1);

if(~exist('pqr_wght_cv') || isempty(pqr_wght_cv))
    pqr_wght_cv = ones(neq,1); % uses unity weighting by default
else
    pqr_wght_cv = reshape(pqr_wght_cv,3,1);
end

Bmat = inertia\cross(r_rcs-repmat(r_cg',1,nrcs),Frcs);
Bmat = diag(pqr_wght_cv)*Bmat;
% Bmat = cross(r_rcs-repmat(r_cg',1,nrcs),Frcs); % fit moment instead

[neq, nrcs] = size(Bmat);
ntrial = 2^nrcs - 1;
rcs_cmd = zeros(nrcs,ntrial);
total_norm = zeros(1,ntrial);
component_norm = zeros(1,ntrial);
cvddes_actual = zeros(neq,ntrial);

for i = 1:ntrial
    rcson = double(bitget(i,1:nrcs))';
    rcson = rcson.*ulim + (1-rcson).*llim;
        
    rcs_cmd(:,i) = rcson;
    cvddes_actual(:,i) = Bmat*rcson;
    total_norm(i) = norm(cvddes_actual(:,i));
    component_norm(i) = sum(sqrt(sum((Bmat.*repmat(rcson',3,1)).^2)));
end
