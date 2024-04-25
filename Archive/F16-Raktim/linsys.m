load trim_val.mat

u_ = getinputstruct(report);
x_ = getstatestruct(report);

[phi_tht_psi,p,q,r,u,v,w,Xe,Ye,Ze] = x_.signals.values;
ele = u_.signals.values;

x0 = [phi_tht_psi,p,q,r,u,v,w,Xe,Ye,Ze]';
u0 = ele; % ele

[A,B,C,D] = linmod('F16_trim',x0,u0);

idx_lon = [2 5 7 9 10 12]; % tht q u w Xe Ze
idx_lat = [1 3 4 6 8 11];  % phi psi p r u Ye

Alon = A(idx_lon, idx_lon);
Blon = B(idx_lon);
Clon = eye(6);
Dlon = zeros(6,1);
sys_lon = ss(Alon,Blon,Clon);

Alat = A(idx_lat,idx_lat);
Blat = B(idx_lat);
Clat = eye(6);
sys_lat = ss(Alat,Blat,Clat);

