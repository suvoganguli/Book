clear
ctr = 1;
sol = 0;
figure(1);
clf
P3 = 60;
CPOW = 10;
YDOTDS = 0;

% for P3 = 0:5:100
for P1 = 5:5:100
    PDOT_OUT = PDOT(P3,P1);
    P1_OUT = PDOTINV(P3,PDOT_OUT);

    % if abs(P1 - P1_OUT) > 1
    %     keyboard
    %     disp([P1_OUT P1])
    % end

    for i = -10:0.1:10
        XD = i;
        POW = P3;
        %tmp = PDOT(POW,CPOW);
        CPOW2 = PDOTINV(POW,YDOTDES-XD);

        plot(ctr,CPOW,'b*',ctr,CPOW2,'ro')
        hold on
        if abs(CPOW-CPOW2) < 1e-1
            tmp2 = P1;
            sol = 1;

            if (P1 > 0)
                %disp(P1)
                %keyboard
            end
            %break
        end
    end

    disp(P1)

    if sol == 1 && 0
        subplot(211)
        hold on
        plot(ctr,P1,'b*',ctr,tmp2,'go')
        subplot(212)
        hold on
        THTL = TGEARINV(CPOW);
        plot(ctr,THTL,'b*')
    end
    ctr = ctr + 1;

    if sol == 1
        % break
    end
end
% end