function [gm_results,pm_results] = gpm(lp,indx)
% gain and phase margins

tmp = size(lp) ;
n = tmp(1,1) - 1;

not_first = 0 ;

pm_results = [ ] ;
gm_results = [ ] ;

for i = 1:n 
   g = lp(i,1) ;
   w = lp(i,2) ;
   absg= abs(g) ;
   if( absg ~= 0 ) ,
      gain = 20 * log10(abs(g)) ;
      phase = atan2( imag(g), real(g) ) * 180 / pi ;
      im = imag(g) ;
      re = real(g) ;
      if( not_first == 1 ) ,
         if( gain * gain_old <= 0 ) ,
            wc = w_old - ( w - w_old )/   ...
               ( gain - gain_old ) * gain_old ;
            gi = g_old + ( g - g_old )/   ...
               ( w - w_old )*( wc - w_old )  ;
            pm = atan2( -imag(gi) , -real(gi) ) * 180 / pi ;
            pm_results = [ pm_results ; indx wc pm ] ;
         end ;

         if( im * im_old <= 0 & re < 0 ) ,
            wp = w_old - ( w - w_old )/   ...
               ( im - im_old ) * im_old ;
            gi = g_old + ( g - g_old )/   ...
               ( w - w_old )*( wp - w_old )  ;
            gm = 20 * log10(abs(gi)) ;
            gm_results = [ gm_results ; indx wp gm ] ;
        end ;
      
      end ;
   
      not_first = 1 ;
      g_old = g ;
      w_old = w ;
      gain_old = gain ;
      phase_old = phase ;
      im_old = im ;
   end ;   
   
end ;
clear g
% pm_results
% gm_results
