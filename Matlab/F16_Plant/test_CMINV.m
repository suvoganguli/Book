
figure(2); clf
i = 1;
EL_VEC = -25:0.5:25;
for EL = EL_VEC
    for ALPHA = 0:0.5:3
        figure(2);
        CM_IN = CM(ALPHA,EL);
        EL_OUT = CMINV(CM_IN,ALPHA);
        plot(i, EL,'b*', i, EL_OUT,'ro');
        hold on

        i = i+1;
    end
end

