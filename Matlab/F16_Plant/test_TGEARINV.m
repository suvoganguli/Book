% test3.m

figure(1); clf
i = 0;
for THTL = 0:0.01:1
    TGEAR_OUT = TGEAR(THTL);
    THTL_OUT = TGEARINV(TGEAR_OUT);

    if abs(THTL_OUT - THTL) < 0.1
        plot(i,THTL,'b*',i,THTL_OUT,'ro');
        hold on
    end
    i = i+1;

end

