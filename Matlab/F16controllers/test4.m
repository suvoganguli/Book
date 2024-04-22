
figure(2); clf

i = 1;
for CM = -0.1:0.0001:0.1
    ALPHA = 2;
    %for ALPHA = 0:0.1:3
        figure(2);
        EL_OUT = CMINV(CM,ALPHA);
        plot(i, EL_OUT,'b*');
        hold on

        i = i+1;
        figure(2);

        if EL_OUT == 0
            %keyboard
        end

    %end
end

