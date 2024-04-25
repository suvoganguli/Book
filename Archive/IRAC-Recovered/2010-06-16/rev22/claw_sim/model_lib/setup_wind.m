% Dale's Wind BLock

use_gusts = get_value('use_gusts','onerror',0) ;
use_steady = get_value('use_steady','onerror',0) ;
use_wind_shear = get_value('use_wind_shear','onerror',0) ;
use_wind_dblt = get_value('use_wind_dblt','onerror',0) ;
use_wind_pulse = get_value('use_wind_pulse','onerror',0) ;

wind_start = get_value('wind_start','onerror',0) ; % sec
wind_slope = get_value('wind_slope','onerror',0) ; % ft/sec^2
wind_heading = get_value('wind_heading','onerror',0) ; % rad
wind_steady = get_value('wind_steady','onerror',0) ; % ft/sec
wind_steady_D = get_value('wind_steady_D','onerror',0) ; % ft/sec
wind_sigma = get_value('wind_sigma','onerror',0) ; % ft/sec

wlag1 = get_value('wlag1','onerror',0.2) ; % rad/sec
wlag2 = get_value('wlag1','onerror',0.2) ; % rad/sec
wgain = wind_sigma * sqrt( 2 * wlag1 * wlag2 * ( wlag1 + wlag2 ) ) ;
Nseed = get_value('Nseed','onerror',23341) ;
Eseed = get_value('Nseed','onerror',14332) ;

% parameters used in 'wind shear', 'wind dblt', or 'wind pulse'
wind_pulse_time = 90 ; % sec
wind1 = 16 ; % ft/sec
wind2 = 14 ; % ft/sec
wind3 = 6 ; % ft/sec^2
wind_omega = 1.7 ; % rad/sec
