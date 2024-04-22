function [X, YL, SD, M] = SMPLX(FX, N, X, DX, SD, M, Y0, YL)


NV = N + 1;
V = zeros(N, NV);

for I = 1:N
    for J = 1:NV
        V(I, J) = X(I);
    end
    V(I, I+1) = X(I) + DX(I);
end

Y0 = FX(X);
Y = zeros(1, NV);
Y(1) = Y0;

for J = 2:NV
    Y(J) = FX(V(1, J));
end

K = NV;
YH = Y(1);
YL = Y(1);
NH = 1;
NL = 1;

for J = 2:NV
    if Y(J) > YH
        YH = Y(J);
        NH = J;
    elseif Y(J) < YL
        YL = Y(J);
        NL = J;
    end
end

YB = Y(1);

for J = 2:NV
    YB = YB + Y(J);
end

YB = YB / NV;
D = 0.0;

for J = 2:NV
    D = D + (Y(J) - YB)^2;
end

SDA = sqrt(D / NV);

if K >= M || SDA <= SD
    SD = SDA;
    M = K;
    YL = Y(NL);

    for I = 1:N
        X(I) = V(I, NL);
    end

    return;
end

XC = zeros(1, N);

for I = 1:N
    XC(I) = 0.0;

    for J = 1:NV
        if J ~= NH
            XC(I) = XC(I) + V(I, J);
        end
    end

    XC(I) = XC(I) / N;
end

for I = 1:N
    X(I) = XC(I) + XC(I) - V(I, NH);
end

K = K + 1;
YR = FX(X);

if YR < YL
    for I = 1:N
        XX(I) = X(I) + X(I) - XC(I);
    end

    K = K + 1;
    YE = FX(XX);

    if YE < YR
        Y(NH) = YE;

        for I = 1:N
            V(I, NH) = XX(I);
        end
    else
        Y(NH) = YR;

        for I = 1:N
            V(I, NH) = X(I);
        end
    end

    goto 4;
end

for J = 1:NV
    if J ~= NL && J ~= NH && Y(J) > Y2
        Y2 = Y(J);
    end
end

if YR < YH
    Y(NH) = YR;

    for I = 1:N
        V(I, NH) = X(I);
    end

    if YR < Y2
        goto 4;
    end
end

for I = 1:N
    XX(I) = 0.5 * (V(I, NH) + XC(I));
end

K = K + 1;
YC = FX(XX);

if YC < YH
    Y(NH) = YC;

    for I = 1:N
        V(I, NH) = XX(I);
    end
else
    for J = 1:NV
        for I = 1:N
            V(I, J) = 0.5 * (V(I, J) + V(I, NL));
        end

        if J ~= NL
            Y(J) = FX(V(1, J));
        end

        K = K + N;
    end

    goto 4;
end
end


