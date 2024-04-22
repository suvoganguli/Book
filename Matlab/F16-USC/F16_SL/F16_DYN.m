function XD = F16_DYN(X,U,XCG)
% f16 dynamics

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

%% Parameters

AXX = 9496.0;
AYY = 55814.0;
AZZ = 63100.0;
AXZ =   982.0;

AXZS = AXZ^2;
XPQ  = AXZ * (AXX - AYY + AZZ);
GAM = AXX * AZZ - AXZ^2;

XQR = AZZ * (AZZ - AYY) + AXZS;
ZPQ =(AXX-AYY) * AXX + AXZS;
YPR = AZZ - AXX;

WEIGHT = 20493.0;
GD = 32.174;
MASS = WEIGHT/GD;
MASS = 636.942675159236;

S = 300;
B = 30;
CBAR = 11.32;
XCGR = 0.35;
HX = 160;
RTOD = 180/pi;

%% Assign State and Control Variables

VT = X(1); 
ALPHA = X(2)*RTOD; 
BETA = X(3)*RTOD;
PHI = X(4); 
THETA = X(5); 
PSI = X(6);
P = X(7); 
Q = X(8); 
R = X(9); 
ALT = X(12); 
POW = X(13);

THTL = U(1);
EL = U(2);
AIL = U(3);
RDR = U(4);

XD = zeros(13,1);

%% Air data computer and engine model

[TFAC, T, RHO, AMACH, QBAR, PS ] = ADC (VT, ALT);
CPOW = TGEAR(THTL);

XD(13) = PDOT(POW,CPOW);     
T = THRUST(POW,ALT,AMACH);

%% Look-up tables and component buildup

CXT = CX (ALPHA,EL);
CYT = CY (BETA,AIL,RDR);
CZT = CZ (ALPHA,BETA,EL);
      
DAIL= AIL/20.0; DRDR= RDR/30.0;

DLDA_OUT = DLDA(ALPHA,BETA);
DLDR_OUT = DLDR(ALPHA,BETA);
DNDA_OUT = DNDA(ALPHA,BETA);
DNDR_OUT = DNDR(ALPHA,BETA);

CLT = CL(ALPHA,BETA) + DLDA_OUT*DAIL + DLDR_OUT*DRDR;
CMT = CM(ALPHA,EL);
CNT = CN(ALPHA,BETA) + DNDA_OUT*DAIL ...
    + DNDR_OUT*DRDR;

%% Add damping derivatives

TVT = 0.5/VT; 
B2V = B*TVT; 
CQ = CBAR*Q*TVT;

D = DAMP(ALPHA);

CXT = CXT + CQ * D(1);
CYT = CYT + B2V * ( D(2)*R + D(3)*P );
CZT = CZT + CQ * D(4);
CLT = CLT + B2V * ( D(5)*R + D(6)*P );
CMT = CMT + CQ * D(7) + CZT * (XCGR-XCG);
CNT = CNT + B2V*(D(8)*R + D(9)*P) - CYT*(XCGR-XCG) * CBAR/B;

%% Get ready for state equations

CBTA  = cos(X(3)); 
U     = VT*cos(X(2))*CBTA;
V     = VT * sin(X(3)); 
W     = VT*sin(X(2))*CBTA;
STH   = sin(THETA); 
CTH   = cos(THETA);   
SPH   = sin(PHI);
CPH   = cos(PHI); 
SPSI  = sin(PSI);    
CPSI  = cos(PSI);
QS    = QBAR * S; 
QSB   = QS * B;        
RMQS  = QS/MASS;
GCTH  = GD * CTH; 
QSPH  = Q * SPH;
AY    = RMQS*CYT; 
AZ    = RMQS * CZT;

%% Force Equations

UDOT   = R*V - Q*W - GD*STH + (QS * CXT + T)/MASS;
VDOT   = P*W - R*U + GCTH * SPH + AY;
WDOT   = Q*U - P*V + GCTH * CPH + AZ;
    
DUM   = (U*U + W*W);
XD(1) = (U*UDOT + V*VDOT + W*WDOT)/VT;
XD(2) = (U*WDOT - W*UDOT) / DUM;
XD(3) = (VT*VDOT- V*XD(1)) * CBTA / DUM;

%% Kinematics

XD(4) = P + (STH/CTH)*(QSPH + R*CPH);
XD(5) = Q*CPH - R*SPH;
XD(6) = (QSPH + R*CPH)/CTH;

%% Moments

ROLL  = QSB*CLT;
PITCH = QS *CBAR*CMT;
YAW   = QSB*CNT;
PQ    = P*Q;
QR    = P*R;
QHX   = Q*HX;
XD(7) = ( XPQ*PQ - XQR*QR + AZZ*ROLL + AXZ*(YAW + QHX) )/GAM;
XD(8) = ( YPR*P*R - AXZ*(P^2 - R^2) + PITCH - R*HX )/AYY;
XD(9) = ( ZPQ*PQ - XPQ*QR + AXZ*ROLL + AXX*(YAW + QHX) )/GAM;

%% Navigation

T1 = SPH * CPSI; 
T2 = CPH * STH; 
T3 = SPH * SPSI;
S1 = CTH * CPSI; 
S2 = CTH * SPSI; 
S3 = T1 * STH - CPH * SPSI;
S4 = T3 * STH + CPH * CPSI; 
S5 = SPH * CTH; 
S6 = T2 * CPSI + T3;
S7 = T2 * SPSI - T1; 
S8 = CPH * CTH;

XD(10)  = U * S1 + V * S3 + W * S6;   %   North speed
XD(11)  = U * S2 + V * S4 + W * S7;   %   East speed
XD(12)  = U * STH -V * S5 - W * S8;   %   Vertical speed

end