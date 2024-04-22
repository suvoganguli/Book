% x = phi tht psi p q r u v w Xe Ye Ze

%function do_trim2()

x0 = [0     % phi   - 1 
      0     % theta - 2
      0     % psi   - 3
      0     % p     - 4
      0     % q     - 5
      0     % r     - 6
      91.44 % u     - 7
      0     % v     - 8
      0     % w     - 9
      0     % Xe    - 10
      0     % Ye    - 11
      -1000]; % Ze  - 12

ix = [1 3 4 6 8];

u0 = [0];   % ele

iu = [];

y0 = [0     % X     - 1
      0     % Y     - 2
      0     % Z     - 3
      91.44 % Xd    - 4
      0     % Yd    - 5
      0     % Zd    - 6
      91.44 % Vt    - 7
      0;    % alpha - 8
      0;    % beta  - 9
      0;    % phi   - 10
      0;    % theta - 11
      0;    % psi   - 12
      0;    % gamma - 13
      0;    % p     - 14
      0;    % q     - 15
      0;    % r     - 16
      0;    % lin acc x - 17
      0;    % lin acc y - 18
      0;    % lin acc z - 19
      0;    % ang acc x - 20
      0;    % ang acc y - 21
      0;    % ang acc z - 22
      91.44/1125.33]; % Mach - 23

iy = [7 9 10 12 14 16 17 18 19 20 21 22];


[x,u,y,dx] = trim('F16_linmod',x0,u0,y0); %,ix,iy,iu)
