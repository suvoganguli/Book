function [EL_OUT,sol] = CMINV(CM_OUT,ALPHA)

A = [.205   .168   .186   .196   .213   .251   .245   .238   .252   .231   .198   .192;
     .081   .077   .107   .110   .110   .141   .127   .119   .133   .108   .081   .093;
    -.046  -.020  -.009  -.005  -.006   .010   .006  -.001   .014   .000  -.013   .032;
    -.174  -.145  -.121  -.127  -.129  -.102  -.097  -.113  -.087  -.084  -.069  -.006;
    -.259  -.202  -.184  -.193  -.199  -.150  -.160  -.167  -.104  -.076  -.041  -.005]';

EL_OUT = -25;
i = 0;
sol = 0;
%figure(2); clf
for EL = -25:0.0002:25
    S = 0.2 * ALPHA;
    K = fix(S);
    if (K <= -2)
        K = -1;
    end
    if(K >= 9)
        K = 8;
    end

    DA = S - double(K);
    L = K + fix( sign(DA) * 1.1 );
    S = EL/12.0;
    M = fix(S);

    if(M <= -2)
        M = -1;
    end
    if(M >= 2)
        M = 1;
    end
    DE = S - double(M);
    N = M + fix( sign(DE) * 1.1 );

    IDX_SHIFT_ALPHA = 3; % Fortran to Matlab
    IDX_SHIFT_EL = 3; % Fortran to Matlab

    T = A(K + IDX_SHIFT_ALPHA, M + IDX_SHIFT_EL);
    U = A(K + IDX_SHIFT_ALPHA, N + IDX_SHIFT_EL);
    V = T + abs(DA) * (A(L + IDX_SHIFT_ALPHA, M + IDX_SHIFT_EL) - T);
    W = U + abs(DA) * (A(L + IDX_SHIFT_ALPHA, N + IDX_SHIFT_EL) - U);

    CM_CALC = V + (W-V) * abs(DE);

    if mod(EL, 5) == 0
        %figure(2);
        %plot(i, CM_CALC, 'b*', i, CM_OUT, 'ro');
        %hold on
    end
    i = i+1;

    if (abs(CM_CALC - CM_OUT) < 1e-6)
        EL_OUT = EL;
        sol = 1;
        return
    end

end


