
% Dryden Gust Model

% turbulence_level = 0 ==> zero turbulence
% turbulence_level = 1 ==> light turbulence
% turbulence_level = 2 ==> moderate turbulence
% turbulence_level = 3 ==> severe turbulence

% user input parameters to modify standard sigma profiles:
%      sigma_factor  ( = 1 for standard turbulence profiles)
%      sigma_offset  ( = 0 for standard turbulence profiles)

% (sigma = sigma_default * sigma_factor + sigma_offset)

turbulence_level = 0 ;
sigma_factor = 1 ;
sigma_offset = 0 ;

Lu = 1750 ; % feet
Lv = 1750 ; % feet
Lw = 1750 ; % feet

ugust_seed = 111 ;
vgust_seed = 222 ;
wgust_seed = 333 ;

tbl_light_h = [ 0 9e3 30e3 ] ;
tbl_light_sigma = [5 5 0 ] ;

tbl_moderate_h = [ 0 11e3 60e3 ] ;
tbl_moderate_sigma = [ 10 10 0 ] ;

tbl_severe_h = [ 0 20e3 80e3 ] ;
tbl_severe_sigma = [ 21 21 3 ] ;

min_sig_gust = 0.5 ; % ft/sec

if( turbulence_level == 1 ) % light
    if( altitude <  tbl_light_h(1) )
        sig_gust = tbl_light_sigma(1) ;
    elseif( altitude < tbl_light_h(end) )
        sig_gust = interp1(tbl_light_h,tbl_light_sigma,altitude) ;
    else
        sig_gust = tbl_light_sigma(end) ;
    end
    sig_gust = max( min_sig_gust , sig_gust ) ;
elseif( turbulence_level == 2 ) % moderate
    if( altitude <  tbl_moderate_h(1) )
        sig_gust = tbl_moderate_sigma(1) ;
    elseif( altitude < tbl_moderate_h(end) )
        sig_gust = interp1(tbl_moderate_h,tbl_moderate_sigma,altitude) ;
    else
        sig_gust = tbl_moderate_sigma(end) ;
    end
    sig_gust = max( min_sig_gust , sig_gust ) ;
elseif( turbulence_level == 3 ) % severe
    if( altitude <  tbl_severe_h(1) )
        sig_gust = tbl_severe_sigma(1) ;
    elseif( altitude < tbl_severe_h(end) )
        sig_gust = interp1(tbl_severe_h,tbl_severe_sigma,altitude) ;
    else
        sig_gust = tbl_severe_sigma(end) ;
    end
    sig_gust = max( min_sig_gust , sig_gust ) ;
else
    sig_gust = 0 ;
end

sig_gust = sigma_offset + sigma_factor * sig_gust ;

sig_ug = sig_gust ;
sig_vg = sig_gust ;
sig_wg = sig_gust ;
