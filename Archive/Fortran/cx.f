{\rtf1\ansi\ansicpg1252\cocoartf2758
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 FUNCTION CX(ALPHA,EL) ! x-axis aerodynamic force coeff.\
\
REAL A(-2:9,-2:2)\
DATA A/\
& -.099, -.081, -.081, -.063, -.025, .044, .097,\
&  .113,  .145,  .167,  .174,  .166,\
& -.048, -.038, -.040, -.021,  .016, .083, .127,\
&  .137,  .162,  .177,  .179,  .167,\
& -.022, -.020, -.021, -.004,  .032, .094, .128,\
&  .130,  .154,  .161,  .155,  .138,\
& -.040, -.038, -.039, -.025,  .006, .062, .087,\
&  .085,  .100,  .110,  .104,  .091,\
& -.083, -.073, -.076, -.072, -.046, .012, .024,\
&  .025,  .043,  .053,  .047,  .040/\
\
S= 0.2 * ALPHA\
K= INT(S)\
IF(K .LE. -2) K= -1\
IF(K .GE. 9) K= 8\
DA= S - FLOAT(K)\
L = K + INT( SIGN(1.1,DA) )\
S= EL/12.0\
M= INT(S)\
IF(M .LE. -2) M= -1\
IF(M .GE. 2) M= 1\
DE= S - FLOAT(M)\
N= M + INT( SIGN(1.1,DE) )\
T= A(K,M)\
U= A(K,N)\
V= T + ABS(DA) * (A(L,M) - T)\
W= U + ABS(DA) * (A(L,N) - U)\
\
CX= V + (W-V) * ABS(DE)\
RETURN\
END\
}