% do_actfail_scenarios

% Select (actuator) failures cases - 10/27/09 (steve/suvo)


disp(' ');
disp('Elevator - Stuck');
disp('================');
disp('1: elev stuck at 0.6 deg at t = 1.0 [TRAC]')
disp('2: elev stuck at 0.6 deg at t = 1.0 [BOTH]')
disp('3: elev stuck at 0.6 deg at t = 1.0 [TRAC], elev stuck at 0.6 deg at t = 1.5 [OBAC]')
disp('4: elev stuck at current pos at t = 3.0 [TRAC]')
disp(' ');
disp('Elevator - Reduced Effectiveness');
disp('================================');
disp('11: elev gain reduced to 0.90 at t = 1.0 [TRAC]')
disp('12: elev gain reduced to 0.80 at t = 1.0 [TRAC]')
disp('13: elev gain reduced to 0.70 at t = 1.0 [TRAC]')
disp('14: elev gain reduced to 0.60 at t = 1.0 [TRAC]')
disp('15: elev gain reduced to 0.50 at t = 1.0 [TRAC]')
disp('16: elev gain reduced to 0.40 at t = 1.0 [TRAC]')
disp('17: elev gain reduced to 0.30 at t = 1.0 [TRAC]')
disp('18: elev gain reduced to 0.20 at t = 1.0 [TRAC]')
disp(' ');
disp('116: elev gain reduced to 0.50 at t = x.y [TRAC]')
disp('117: elev gain reduced to 0.5 at t = 2.5 [BOTH]')
disp('118: elev gain reduced to 0.1 at t = 2.5 [BOTH]')
disp('119: elev gain reduced to 0.1 at t = 2.5 [BOTH], stab use at t = 2.5 [BOTH]')
disp(' ');
disp('Elevator - Reduced Effectiveness; Stabilizer Reconfiguration');
disp('============================================================');
disp('21: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 2.5 [BOTH], stab use at t = 2.5 [BOTH]  ')
disp('22: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 1.5 [BOTH], stab use at t = 1.5 [BOTH]  ')
disp('23: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 1.5 [BOTH], stab use at t = 2.5 [BOTH]  ')
disp('24: stab fixed at t = 1 [BOTH], elev gain reduced to 0.0 at t = 1.5 [BOTH], stab use at t = 2.5 [BOTH]  ')
disp('25: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 2.5 [BOTH], stab not used [BOTH]  ')
disp('26: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 2.1 [TRAC], stab use at t = 3.0 [BOTH]  ')
disp('27: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 2.1 [TRAC], stab use at t = 3.0 [BOTH]  ')
disp('28: stab fixed at t = 1 [BOTH], elev gain reduced to 0.1 at t = 2.5 [TRAC], ... ');
disp('    elev gain reduced to 0.1 at t = 2.8 [OBAC], stab use at t = 2.8 [BOTH]  ')
disp(' ');
disp('Differential Throttle');
disp('=====================');
disp('41: rudder stuck at 0 deg at t=0 sec [BOTH] - use throtdiff')
disp('42: rudder stuck at 0 deg at t=0 sec [BOTH] - dont use throttdiff')
disp(' ');
disp('Reaching Different Flight Condition');
disp('===================================');
disp('51. Fly away from trim, then elev gain reduced to 0.5 at t = 21.0 [TRAC]');
disp(' ');
disp('Nominal Condition');
disp('=================');
disp('0: nominal (no failure, stab fixed at IC) [BOTH]')
disp(' ');


actfail_case = input('Enter actuator failure scenario # : ');

switch (actfail_case)
    
    % --------------------------------------------------    
    case 0
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
        
    % --------------------------------------------------    
    case 1
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1 'elev' 0.6 0.6 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 2
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1 'elev' 0.6 0.6 'both'; };
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 3
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both';
            1 'elev' 0.6 0.6 'trac'; 1.5 'elev' 0.6 0.6 'obac'; };
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 4
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            3 'elev rlim' 0 0 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
        
    % --------------------------------------------------    
    case 11
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.9 0.9 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'}); 
    case 12
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.8 0.8 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'}); 
    case 13
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.7 0.7 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'}); 
    case 14
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.6 0.6 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});         
    case 15
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.5 0.5 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});   
    case 16
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.4 0.4 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});          
    case 17
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.3 0.3 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});          
    case 18
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            1.0 'elevgain' 0.2 0.2 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});          

        
        
        
    case 116
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            3.5 'elevgain' 0.5 0.5 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});           
    case 117
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            2.5 'elevgain' 0.5 0.5 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 118
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            2.5 'elevgain' 0.1 0.1 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 119
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            2.5 'elevgain' 0.1 0.1 'both'; 2.5 'stab rlim' -300 300 'both'}; 
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
        
    % --------------------------------------------------    
    case 21
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            2.5 'elevgain' 0.1 0.1 'both'; 2.5 'stab rlim' -300 300 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 22
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            1.5 'elevgain' 0.1 0.1 'both'; 1.5 'stab rlim' -300 300 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 23
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            1.5 'elevgain' 0.1 0.1 'both'; 2.5 'stab rlim' -300 300 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 24
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            1.5 'elevgain' 0 0 'both'; 2.5 'stab rlim' -300 300 'both'}; 
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 25
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            2.5 'elevgain' 0.1 0.1 'both';};   
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 26
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            2.1 'elevgain' 0.1 0.1 'trac';};        
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 27
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            2.1 'elevgain' 0.1 0.1 'trac'; 2.1 'elevgain' 0.1 0.1 'obac'; ...
            2.1 'stab rlim' -300 300 'both'};    
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
    case 28
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 1 'stab rlim' 0 0 'both'; ...
            2.1 'elevgain' 0.1 0.1 'trac'; 2.5 'elevgain' 0.1 0.1 'obac'; ...
            2.5 'stab rlim' -300 300 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
        
    % --------------------------------------------------    
    case 41
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'rud' 0 0 'both'});        
    case 42
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});
        config.fail_surfs = vertcat(config.fail_surfs,{0 'rud' 0 0 'both'});        
        
    % -------------------------------------------------- 
    case 51
        config.fail_surfs = {0 'elevgain' 1 1 'both'; 0 'stab rlim' 0 0 'both'; ...
            11.0 'elevgain' 1.0 1.0 'trac'};
        config.fail_surfs = vertcat(config.fail_surfs,{0 'throtdiff' 0 0 'both'});  
        
    otherwise
        error('Incorrect fail_case');
end


