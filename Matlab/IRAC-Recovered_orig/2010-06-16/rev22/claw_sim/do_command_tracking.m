% do_command_tracking

switch(gtm_exptno)
    
    case 1
        config.mode = modes.rate ;
        config.tsim_max = 15;     
        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [0    0*pi/180   0*pi/180  0*pi/180  0;
             1    0*pi/180   0*pi/180  0*pi/180  0];   
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 2
        config.mode = modes.rate ;
        config.tsim_max = 10;     
        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [0    0*pi/180   0*pi/180  0*pi/180  0;
            2    0*pi/180   0*pi/180  0*pi/180  0;
            2   5*pi/180   0*pi/180  0*pi/180  0;
            4   5*pi/180   0*pi/180  0*pi/180  0;
            4    0*pi/180   0*pi/180  0*pi/180  0];
        % note: 4th column is throttle command - regenerated
        % after setup_claw

    case 3
        config.mode = modes.rate ;
        config.tsim_max = 15;       
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [ 0    0*pi/180   0*pi/180  0*pi/180  0;                                    
              2    0*pi/180   0*pi/180  0*pi/180  0;
              2    0*pi/180   0*pi/180  0*pi/180  0;
              3    0*pi/180   0*pi/180  0*pi/180  0;        
              3    0*pi/180   0*pi/180  0*pi/180  0;            
             12    0*pi/180   0*pi/180  0*pi/180  0;
             12    0*pi/180  -4*pi/180  0*pi/180  0;
             15    0*pi/180  -4*pi/180  0*pi/180  0;        
             15    0*pi/180   0*pi/180  0*pi/180  0];
               
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
        
    case 30
        config.mode = modes.rate ;
        config.tsim_max = 25;        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [ 0    0*pi/180   0*pi/180  0*pi/180  0;                                    
             15    0*pi/180   0*pi/180  0*pi/180  0;
             15    0*pi/180  -4*pi/180  0*pi/180  0;
             18    0*pi/180  -4*pi/180  0*pi/180  0;        
             18    0*pi/180   0*pi/180  0*pi/180  0];
               
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 31
        config.mode = modes.rate ;
        config.tsim_max = 30;        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [ 0    0*pi/180   0*pi/180  0*pi/180  0;
              2    0*pi/180   0*pi/180  0*pi/180  0;              
              2    0*pi/180   5*pi/180  0*pi/180  0;            
              4    0*pi/180   5*pi/180  0*pi/180  0;              
              4    0*pi/180   0*pi/180  0*pi/180  0;  
              6    0*pi/180   0*pi/180  0*pi/180  0;              
              6    0*pi/180   0*pi/180  0*pi/180  0;            
          10+15    0*pi/180   0*pi/180  0*pi/180  0;
          10+15    0*pi/180  -4*pi/180  0*pi/180  0;
          10+18    0*pi/180  -4*pi/180  0*pi/180  0;        
          10+18    0*pi/180   0*pi/180  0*pi/180  0];       
      
    case 32
        config.mode = modes.rate ;
        config.tsim_max = 26;        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [ 0    0*pi/180   0*pi/180  0*pi/180  0;  
              2    0*pi/180   0*pi/180  0*pi/180  0;  
              2    0*pi/180  -3*pi/180  0*pi/180  0;  
              5    0*pi/180  -3*pi/180  0*pi/180  0;  
              5    0*pi/180   0*pi/180  0*pi/180  0;  
             20    0*pi/180   0*pi/180  0*pi/180  0;
             20    0*pi/180  -4*pi/180  0*pi/180  0;
             23    0*pi/180  -4*pi/180  0*pi/180  0;        
             23    0*pi/180   0*pi/180  0*pi/180  0];      
      
         
    case 33
        config.mode = modes.rate ;
        config.tsim_max = 26;        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [ 0    0*pi/180   0*pi/180  0*pi/180  0;  
              2    0*pi/180   0*pi/180  0*pi/180  0;  
              2   -3*pi/180   0*pi/180  0*pi/180  0;  
              5   -3*pi/180   0*pi/180  0*pi/180  0;  
              5    0*pi/180   0*pi/180  0*pi/180  0;  
             20    0*pi/180   0*pi/180  0*pi/180  0;
             20    0*pi/180  -4*pi/180  0*pi/180  0;
             23    0*pi/180  -4*pi/180  0*pi/180  0;        
             23    0*pi/180   0*pi/180  0*pi/180  0];            
        
    case 4
        config.mode = modes.rate ;
        config.tsim_max = 6;        
        
        config.rate_cmd_select  = 1;
        config.rate_cmd_fw = ...
            [0    0*pi/180   0*pi/180  0*pi/180  0;
            2    0*pi/180   0*pi/180  0*pi/180  0;
            2    0*pi/180   0*pi/180 10*pi/180  0;
            4    0*pi/180   0*pi/180 10*pi/180  0;
            4    0*pi/180   0*pi/180  0*pi/180  0];
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 5
        config.mode = modes.att ;
        config.tsim_max = 10;
        config.rate_cmd_select  = 1;
        
        config.att_cmd_fw = ...
            [0    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  0*pi/180  0];
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 6
        config.mode = modes.att ;
        config.tsim_max = 10;
        
        config.att_cmd_select  = 1;        
        config.att_cmd_fw = ...
            [0    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  0*pi/180  0;
            2   10*pi/180   4.64*pi/180  0*pi/180  0];
       
        
    case 7
        config.mode = modes.att ;
        config.tsim_max = 10;
        
        config.att_cmd_select  = 1;
        config.att_cmd_fw = ...
            [0    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180 (4+4.64)*pi/180  0*pi/180  0];
        
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 8
        config.mode = modes.att ;
        config.tsim_max = 10;
        
        config.att_cmd_select  = 1;        
        config.att_cmd_fw = ...
            [0    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  0*pi/180  0;
            2    0*pi/180   4.64*pi/180  2*pi/180  0];
        
        % note: 4th column is throttle command - regenerated
        % after setup_claw
        
    case 9
        config.mode = modes.vel ;
        config.tsim_max = 20;
        
        config.vel_cmd_select  = 1;
        config.vel_cmd_fw = ...
            [0    0   128.08  0*pi/180  0;
            2    0   128.08  0*pi/180  0;
            2    0   128.08  0*pi/180  0];
        
        
    case 10
        config.mode = modes.vel ;
        config.tsim_max = 10;        
        
        config.vel_cmd_select  = 1;
        config.vel_cmd_fw = ...
            [0    0     128.08  0*pi/180  0;
            2    0     128.08  0*pi/180  0;
            2    0  20+128.08  0*pi/180  0];
        
        
    case 11
        config.mode = modes.vel ;
        config.tsim_max = 10;
        
        config.vel_cmd_select  = 1;
        config.vel_cmd_fw = ...
            [0    0   128.08  0*pi/180  0;
            2    0   128.08  0*pi/180  0;
            2   20   128.08  0*pi/180  0];
        
    case 12
        config.mode = modes.vel ;
        config.tsim_max = 10;        
        
        config.vel_cmd_select  = 1;
        config.vel_cmd_fw = ...
            [0    0   128.08  0*pi/180  0;
            2    0   128.08  0*pi/180  0;
            2    0   128.08  0*pi/180 20];
        
    case 13
        config.mode = modes.pos ;
        config.tsim_max = 10;
        
        config.engage_time = 0.00;  % debugging Ed-cmd discrepancy - 10/21/09
        
        %config.use_NdEdh_pos = 0 ;
        config.pos_cmd_select  = 1;
        config.pos_cmd_fw = ...      
            [0    0           0  0*pi/180   800;
             1    0      128.08  0*pi/180   800;
             2    0    2*128.08  0*pi/180   800;
            10    0   10*128.08  0*pi/180   800];     
         
    case 14
        config.mode = modes.pos ;
        config.tsim_max = 20;
        
        config.engage_time = 0.00;
        
        %config.use_NdEdh_pos = 0 ;
        config.pos_cmd_select  = 1;
        config.pos_cmd_fw = ...
            [0    0           0  0*pi/180   800;
             2    0    2*128.08  0*pi/180   800;
             2    0    2*128.08  0*pi/180   800+20;  
            20    0   20*128.08  0*pi/180   800+20];
        
        disp('Note: Need to check this case ... (Case 14)');
        keyboard
                
    case 18
        config.mode = modes.pos ;
        config.tsim_max = 12;
        
        config.use_NdEdh_pos = 1 ;
        config.pos_cmd_select  = 1;
        config.pos_cmd_fw = ...
            [0    0.0   128.08  0*pi/180  800];
        
    case 19
        config.mode = modes.pos ;
        config.tsim_max = 30;
        
        config.use_NdEdh_pos = 1 ;
        config.pos_cmd_select  = 1;
        config.pos_cmd_fw = ...
            [0    0   128.08  0*pi/180  800;
             2    0   128.08  0*pi/180  800;
             2    0   128.08  0*pi/180  800+20];
        
    case 20
        
        config.mode = modes.pos ;
        
        config.use_NdEdh_pos = 1 ;  % circle in NdEd, hold altitude
        
        do_circle = 1 ;
        if(do_circle && config.mode == modes.pos)
            config.pos_cmd_select = 1 ;
            h0 = 800 ; % trim altitude
            vel = 128 ; % trim velocity
            t0 = config.engage_time ;
            tf = t0 + 50 ;
            t_cmd = [t0:0.1:tf]' ;
            turn_rate = 2*pi/(tf - t0);
            config.tsim_max = tf ;
            config.pos_cmd_fw = [ t_cmd -vel*sin(turn_rate*(t_cmd-t0)) ...
                vel*cos(turn_rate*(t_cmd-t0)) repmat([0 h0],length(t_cmd),1) ] ;
            
            clear vel h0 tf t_cmd turn_rate
        end
        
    otherwise
        error('Incorrent GTM Experiment No.');
        
end  % end switch

%% Setting rate-loop kc term ON/OFF

% switch(config.mode)
%     case modes.rate
%         % this is for special usage with MRAC with rate loops closed
%         set_param('main_sim_adapt_Gref_SP/claw_main/rate_loops/P+I+AW+TRIM Control/Gain','Gain','0');
%     otherwise
%         set_param('main_sim_adapt_Gref_SP/claw_main/rate_loops/P+I+AW+TRIM Control/Gain','Gain','1');
% end



