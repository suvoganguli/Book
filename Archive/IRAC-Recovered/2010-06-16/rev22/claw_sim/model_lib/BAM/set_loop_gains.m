
switch(gain_set)

    case 0

        % pqr loop [ p q r ]
        pqr_kbnom = 10 ;
        pqr_fi = [ 0.25 0.25 0.25 ] ;
        pqr_ff = 0 ;
        pqr_kaw = 2 ;

        % att loop [ e0 e1 e2 e3 ]
        att_kbnom = 2 ;
        att_fi = 0.25 ;
        att_ff = 0 ;
        att_kaw = 2 ;

        % vel loop [ Nd Ed hd ]
        vel_kbnom = 1;
        vel_fi = 0.25 ;
        vel_ff = 0 ;
        vel_kaw = 2 ;

        % pos loop [ N E h ]
        pos_kbnom = 0.2 ;
        pos_fi = 0.25 ;
        pos_ff = 0 ;
        pos_kaw = 2 ;
end
