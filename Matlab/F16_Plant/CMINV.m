function [EL_OUT] = CMINV(CM_IN,ALPHA)

A = [.205   .168   .186   .196   .213   .251   .245   .238   .252   .231   .198   .192;
     .081   .077   .107   .110   .110   .141   .127   .119   .133   .108   .081   .093;
    -.046  -.020  -.009  -.005  -.006   .010   .006  -.001   .014   .000  -.013   .032;
    -.174  -.145  -.121  -.127  -.129  -.102  -.097  -.113  -.087  -.084  -.069  -.006;
    -.259  -.202  -.184  -.193  -.199  -.150  -.160  -.167  -.104  -.076  -.041  -.005]';

i = 1;

EL_VEC = -25:0.002:25;
n = length(EL_VEC);
err = inf*ones(n,1);

for EL = EL_VEC
    CM_CALC = CM(ALPHA, EL);
    err(i) = abs(CM_CALC - CM_IN);

    i = i+1;
end

[~,idx] = min(err);
EL_OUT = EL_VEC(idx);


