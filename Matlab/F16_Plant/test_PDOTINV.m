
figure(1);
clf

ctr = 1;
for P1 = 0:5:100
    for P3 = 0:5:100

        PDOT_OUT = PDOT_K(P3,P1);
        P1_OUT = PDOTINV_K(P3,PDOT_OUT);

        figure(1);
        hold on
        plot(ctr,P1,'r*',ctr,P1_OUT,'bo')

        if abs(P1 - P1_OUT) > 1
            %keyboard
        end

        if ctr >= 300
            keyboard
        end

        % figure(2); hold on
        % plot(ctr,PDOT_OUT,'r*')
        ctr = ctr + 1;
    end
end
        