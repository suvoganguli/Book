% setup_MRAC
%
% run this after 
%
% created: 07/01/10
% last revised: 
%


%% baseline control law

% xcdot = Ac * xc + Bcp * xp + Bcr * r
% u     = Bc * xc + Dcp * xp + Dcr * r

% MACH - rate loop

Ac  = zeros(3,3);
Bcp = - Kb_rate * fi_rate * c_rate;
Bcr =   Kb_rate * fi_rate * eye(3);
Cc  =   cbinv_rate * Kb_rate ;
Dcp = - cbinv_rate * ( ca_rate + Kb_rate * c_rate) ;
Dcr =   cbinv_rate * Kb_rate * fc_rate;

%% plant

% xpdot = Ap * xp + Bp * u
%   where
% u     = [Kxc' Kxp']*[xp; xc] + Kr'*r
% Kxc'  = [Cc]
% Kxp   = [Dcp];
% Kr'   = [Dcr];

Ap = Aac_trac ; 
Bp = Bac_trac(:,1:3) ; 

Kxc = Cc';
Kxp = Dcp';
Kx = [Kxc' Kxp']';
Kr = Dcr';


%% augmented dynamics

A = [Ac             Bcp ;
     zeros(12,3)    Ap] ;
B1 = [zeros(3,3); Bp];
B2 = [Bcr; zeros(12,3)];


%% reference model

Am = A + B1 * Kx';
Bm = B2 + B1 * Kr';

Amchk = Am-acl([13:15 1:12],[13:15 1:12]);


