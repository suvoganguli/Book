
figure(1); clf
i = 0;
for TGEAR_IN = 0:1:6000
    [THTL_OUT, sol] = TGEARINV(TGEAR_IN);

    figure(1);
    plot(i,THTL_OUT,'b*');
    hold on
    i = i+1;
end