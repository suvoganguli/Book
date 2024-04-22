% **************** Honeywell Proprietary ****************************
% This code is considered proprietary to Honeywell. 
% Questions about its availability should be directed
% to either Dale Enns (612-951-7289 or enns_dale@htc.honeywell.com)
% or Dan Bugajski (612-951-7287 or bugajski_dan@htc.honeywell.com)
% **************** Honeywell Proprietary ****************************

%---------------------------------------------------------------

% function smn 

% smn stands for solve m equations for n unknowns
%
% inputs:
%         bin = B matrix
%         rhs = right hand side of equation to be solved
%         ain_min = minimum value allowed for answer
%         ain_max = maximum value allowed for answer
%         wrhs = weighting used to prioritize right hand side
%         aprefin = preferred answer
%         wprefin = weighting associated with preferred answer
%         lam_in = starting value for lagrange multiplier
%         cdim_in = working col dimension of bin
%         rdim_in = working row dimension of bin
% outputs:
%          aout = answer
%          sdat = an array containing diagnostic information
%          lam_out = final value for lagrange multiplier
%
% when it is possible this routine solves bin*aout=rhs 
% subject to constraints ain_min < aout < ain_max, and 
% if n>m wprefin*(aout-aprefin)^2 is minimized
% and when the equations cannot be solved
% it minimizes wrhs*(bin*aout-rhs)^2 
%
% in the event that one of the columns of bin is sufficiently small
% or the ain_min = ain_max the problem is reduced to
% bmat*ans=rhs with constraints ans_min < ans < ans_max
% if n>m wpref*(ans-apref)^2 is minimized
% and when the equations cannot be solved
% it minimizes wrhs*(b*ans-rhs)^2 
%
% it is because of this reduction in the number of unknowns
% that n_spmn >= n_a

%function [a_out,solve_data,lam_out] = smn(bin,rhs,a_min,a_max,w_rhs,a_pref,w_pref,...
%   lam_in,cdim_in,rdim_in)

% [SGP 20021016] modify input to be directly compatible
% with Simulink MATLAB Function block

function out_out = smn_func(in_in)

rdim_in = in_in(1);
cdim_in = in_in(2);

offset = 2;
bin = reshape(in_in(offset+1:offset+rdim_in*cdim_in), rdim_in, cdim_in); offset = offset + rdim_in*cdim_in;
rhs = in_in(offset+1:offset+rdim_in); offset = offset + rdim_in;
a_min = in_in(offset+1:offset+cdim_in); offset = offset + cdim_in;
a_max = in_in(offset+1:offset+cdim_in); offset = offset + cdim_in;
w_rhs = in_in(offset+1:offset+rdim_in); offset = offset + rdim_in;
a_pref = in_in(offset+1:offset+cdim_in); offset = offset + cdim_in;
w_pref = in_in(offset+1:offset+cdim_in); offset = offset + cdim_in;
lam_in = in_in(offset+1);

use_matinv = 0 ;
if( use_matinv == 1 ) 
    %%%%dfe experiment starts

    [u,s,v] = svd(bin) ;
    
    nnn = min(rdim_in,cdim_in) ;
    mins = s(nnn,nnn) ;
    
    if( mins > 1.e-3 )
        if( cdim_in == rdim_in )
            sol = v * inv(s) * u' * rhs ;
        else
            sol = v(1:cdim_in,1:rdim_in) * inv(s(1:rdim_in,1:rdim_in))  * u' * rhs ;
            eqn_error = rhs - bin * sol ;
            jerror = sqrt( eqn_error' * eqn_error ) ;
            if( jerror > 1.e-6 )
                disp('found a large error in pseudo inverse')
                cdim_in
                rdim_in
            end ;
        end ;
        
        for kkk = 1:1:cdim_in
            if( sol(kkk) < a_min(kkk) )
                sol(kkk) = a_min(kkk) ;
            elseif( sol(kkk) > a_max(kkk) )
                sol(kkk) = a_max(kkk) ;
            end ;
        end ;
    else
        sol = 0 * rhs ;
        disp('singular B matrix')
        s
        bin
    end ;
    out_out = [ sol ; 0 ] ;
    return

    %%%% dfe experiment ends
end ;

  eps_bcol = 0.0000001 ;
  eps_alim = 0.0000001 ;
    
  % dan added 7aug02
  global MACH
  w_pref = diag(w_pref) ;

% omit control from solution if 1) entire col. of B (=bin) approx zero
%                            or 2) control_min = control_max
  % find bad cols
  n_spmn = 0 ;
  
  for jj = 1:size(bin,2)
    col_ok = 0 ;
    for ii = 1:size(bin,1)
      if ( abs(bin(ii,jj)) > eps_bcol ) 
        col_ok = 1 ;
      end ; 
    end ;
    if ( col_ok & (a_max(jj) - a_min(jj)) > eps_alim ) 
      n_spmn = n_spmn + 1 ;
      b_spmn(:,n_spmn) = bin(:,jj) ;
      a_min_spmn(n_spmn) = a_min(jj) ;
      a_max_spmn(n_spmn) = a_max(jj) ;
      a_pref_spmn(n_spmn) = a_pref(jj) ;
      vec(n_spmn) = jj ;
    else
      if ( (a_max(jj) - a_min(jj)) > eps_alim ) 
        % col is not ok but limits are ok
        if ( a_pref(jj) < a_min(jj) ) 
          a_out(jj) = a_min(jj) ;
        elseif ( a_pref(jj) < a_max(jj) ) 
          a_out(jj) = a_pref(jj) ;
        else 
          a_out(jj) = a_max(jj) ;
        end , 
      else
        % here col is not ok and limits are inconsistent. i.e. a_min > a_max
        a_out(jj) = 0.5* ( a_min(jj) + a_max(jj)) ;
      end  ;
    end  ;

  end  ;

  if ( n_spmn == 0 ) 
    return ;
  end  ;

% set up preference weighting for controls that are tro be considered
    for ii = 1:n_spmn
      for jj = 1:n_spmn 
        w_pref_spmn(ii,jj) = w_pref(vec(ii),vec(jj)) ;
      end  ;
    end  ;

% call to spmn
  [a_spmn,solve_data,lam_out] = spmn(b_spmn , ...
                                     rhs , ...
                                     a_min_spmn , ...
                                     a_max_spmn , ...
			             w_rhs , ...
                                     a_pref_spmn , ...
                                     w_pref_spmn , ...
			             lam_in , ...
				     n_spmn , ...
				     rdim_in) ;

% put values of a_spmn into appropriate locations of a_out
  for ii = 1:n_spmn 
    a_out(vec(ii)) = a_spmn(ii) ;
  end  ;
  out_out = [a_out lam_out] ;
  
%---------------------------------------------------------------

% function spmn is

% spmn stands for solve m equations for n unknowns with 
% protection for constraints 
%
% inputs:
%         bmat = B matrix
%         rhs = right hand side of equation to be solved
%         ans_min = minimum value allowed for answer
%         ans_max = maximum value allowed for answer
%         wrhs = weighting used to prioritize right hand side
%         apref = preferred answer
%         wpref = weighting associated with preferred answer
%         lam_in = starting value for lagrange multiplier
%         cdim_in = number of cols of bmat
%         rdim_in = number of rows of bmat
% outputs:
%          ans = answer
%          sdat = an array containing diagnostic information
%          lam_out = starting value for lagrange multiplier
%
% when it is possible this routine solves b*ans=rhs 
% subject to constraints ans_min < aout < ans_max, and 
% if n>m wpref*(ans-apref)^2 is minimized
% and when the equations cannot be solved
% it minimizes wrhs*(b*ans-rhs)^2 
%
% the underlying routine treats the constraints with ellipes (ellipsoids)
% instead of rectangles (polytopes) where the rectangle is inside the
% elipse, usually the answer has to be clipped to satisfy the rectangular
% constraints. In this case, another pass is made to solve for the
% variables that were not clipped
%
% q is an array that defines the elipse 0.5 * ans^T * q * ans = 1
% and q is derived from the rectangular minimum and maximum limits
%
% the unknown is redefined such that the limits are symmetric
% about the origin, so a center is computed, subtracted off;
% the equations are solved, and then the center is added back on again
function  [a_out,solve_data,lam_out] = spmn(bin,rhs,a_min,a_max,w_rhs,a_pref,w_pref, ...
    lam_in,cdim_in,rdim_in)

% dan added 7aug02
  global MACH
  
%initialize
  eps_brow = 0.0000001 ;
  a_out = zeros(cdim_in,1) ;
  num_a_avail = cdim_in ;
  a_avail = zeros(cdim_in,1) ;
  tmp_a_avail = a_avail ;
  num_a_notavail = 0 ;
  a_notavail = zeros(cdim_in,1) ;
  iter = zeros(cdim_in,1) ;
  itot = 0 ;
  single_pass = 0 ;
  ellipse_outside = 1 ;

% set diagnostic array elements
  solve_data = zeros(22,cdim_in) ;

% main loop over all controls
% will do all controls if needed
% will exit this loop if none are on limits

  for passes = 1:cdim_in 

    num_passes = passes ;

    if ( passes == 1 ) 
      for ii = 1:num_a_avail 
	a_avail(ii) = ii ;
      end  ;
    end ;

    for ii = 1:num_a_avail 
      s_vec(ii) = ii ;

      a_index = a_avail(ii) ;
    % find Q for ellipse and center the problem
      s_center(ii) = 0.5*(a_min(a_index) + a_max(a_index)) ;
      if( ellipse_outside ) 
	% use ellipse that is outside of the rectangle
        q_semn(ii) = 8.0/(num_a_avail* ...
                             (a_max(a_index) - a_min(a_index))* ...
                             (a_max(a_index) - a_min(a_index))) ;
      else
	% use the ellipse that is inside the rectangle
        q_semn(ii) = 8.0/((a_max(a_index) - a_min(a_index))* ...
                               (a_max(a_index) - a_min(a_index))) ;
      end ;
      upref_semn(ii) = a_pref(a_index) - s_center(ii) ;
      % grab the appropriate available portion of the preference weighting
      for jj = 1:num_a_avail 
        wpref_semn(ii,jj) = w_pref(a_avail(ii),a_avail(jj)) ;
      end  ;
    % select appropriate available columns of B
      b_semn(:, ii ) = bin(:, a_index ) ;
    end  ;

% modify rhs for those controls on a limit
    rhs_semn = rhs ;
    if ( num_a_notavail ~= 0 ) 
      for ii = 1:rdim_in 
        for jj = 1:num_a_notavail 
          na_index = a_notavail(jj) ;
          rhs_semn(ii) = rhs_semn(ii) ...
		       - bin(ii,na_index)*a_out(na_index) ;
	end  ;
      end  ;
    end ;

% modify rhs for the centered controls
    for ii = 1:rdim_in 
      for jj = 1:num_a_avail 
        rhs_semn(ii) = rhs_semn(ii) - b_semn(ii,jj)*s_center(jj) ;
      end  ;
    end  ;

% remove small rows of B and corresponding rhs, wrhs, rdim
    rdim_semn = 0 ;
    for ii = 1:rdim_in 
      row_ok = 0 ;
      for jj = 1:num_a_avail 
        if( abs( b_semn (ii,jj) ) > eps_brow ) 
          row_ok = 1 ;
        end ;
      end  ;
      if( row_ok ) 
        rdim_semn = rdim_semn + 1 ;
        rhs_semn ( rdim_semn ) = rhs_semn ( ii ) ;
        wrhs_semn ( rdim_semn ) = w_rhs ( ii ) ;
        for jj = 1:num_a_avail 
          b_semn( rdim_semn , jj ) = b_semn ( ii , jj ) ;
        end  ;
      end ;
    end  , 

    if ( rdim_semn == 0 )
        return
    end ,  

% call to semn
    [u,sdat_semn,lam_out,iter_semn] = semn(b_semn , ...
                                         rhs_semn , ...
                                         wrhs_semn , ...
					 upref_semn , ...
                                         wpref_semn , ...
					 q_semn , ...
                                         lam_in , ...
					 num_a_avail , ...
					 rdim_semn ) ;
  
    iter(passes) = iter_semn ;
    for ii = 1:num_a_avail 
      a_out(a_avail(ii)) = s_center(ii) + u(ii) ;
    end  ;

    itot = itot + iter_semn ;
    solve_data(2,passes) = real(itot) ;
    for ii = 1:4 
      solve_data(ii+2,passes) = sdat_semn(ii) ;
    end ;
    solve_data(7,passes) = real(num_a_notavail) ;
    solve_data(8,passes) = real(num_passes) ;
    solve_data(9,passes) = real(iter_semn) ;

% loop through available controls
% determine which controls are limited, and limit them appropriately
    tmp_num_a_avail = 0 ;
    hit_a_limit = 0 ;

    for jj = 1:num_a_avail 

      if ( a_out(a_avail(jj)) < a_min(a_avail(jj)) ) 
	a_out(a_avail(jj)) = a_min(a_avail(jj)) ;
	num_a_notavail = num_a_notavail + 1 ;
	a_notavail(num_a_notavail) = a_avail(jj) ;
        hit_a_limit = 1 ;
      elseif ( a_out(a_avail(jj)) > a_max(a_avail(jj)) ) 
	a_out(a_avail(jj)) = a_max(a_avail(jj)) ;
	num_a_notavail = num_a_notavail + 1 ;
	a_notavail(num_a_notavail) = a_avail(jj) ;
        hit_a_limit = 1 ;
      else
	tmp_num_a_avail = tmp_num_a_avail + 1 ;
	tmp_a_avail(tmp_num_a_avail) = a_avail(jj) ;
      end ;

    end  ;

    num_a_avail = tmp_num_a_avail ;
    for ii = 1:num_a_avail 
      a_avail(ii) = tmp_a_avail(ii) ;
    end ;

% if there are still some unlimited controls and the last solution
% required limiting, re-solve with new set of available controls.
% otherwise, done.

    if ( single_pass )
        return
    end;

    if ( ~hit_a_limit | tmp_num_a_avail == 0 )
        return
    end;

  end  ;
  % subtract 1 so iter = 0 means only 1 matrix inverse
  solve_data(1,1) = real(itot) - 1. ;
  solve_data(1,2) = real(num_passes) ;


%---------------------------------------------------------------

% function semn is

% semn stands for solve m equations for n unknowns with 
% an elipse representation of the constraints 
%
% inputs:
%         b = B matrix
%         d = right hand side of equation to be solved
%         w = weighting used to prioritize right hand side
%         ap = preferred answer
%         wp = weighting associated with preferred answer
%         q = elipse size
%         lam_in = starting value for lagrange multiplier
%         cdim_in = number cols of b
% outputs: u = answer
%          sdat = an array containing diagnostic information
%          lam_out = final value for lagrange multiplier
%          iter = number of iterations needed
%
% when it is possible this routine solves b*u_=d 
% subject to constraint 0.5* u^T * q * u <= 1.0, and 
% if n>m wp*(u-ap)^2 is minimized
% and when the equations cannot be solved
% it minimizes w*(b*u-d)^2 

function [u,sdat,lam_out,iter_tot] = semn(bin,rhs,w_rhs,a_pref,w_pref,q_ellipse,lam_in,cdim_in,rdim_in)

% dan added 7aug02
  global MACH
   
  % 4 June 1996
  % try_unl0p = T = unlim, 0 preference 2nd matrix inv 
  % bisect_ok = T = can use bisection iterative solution

  iter_bi = 0 ;
  iter_hi = 0 ;
  iter_unlwp = 0 ;
  iter_unl0p = 0 ;
  iter_unlnp = 0 ;
  iter_wpplusnp = 0 ;

  try_unl0p = 1 ;
  bisect_ok = 1 ;
  eps_posdef = 0.0000003 ;
    
  if ( cdim_in >= rdim_in) 

    % get unlimited solution for weighted preferences
    [u,fail_unlwp] = get_unlwp(bin,rhs,a_pref,w_pref,...
                                    cdim_in,rdim_in,eps_posdef) ;
    iter_unlwp = iter_unlwp + 1 ;

    if ( fail_unlwp ) 
      [u] = get_wpplusnp(bin,rhs,a_pref,w_pref,w_rhs,cdim_in,rdim_in) ;
      iter_wpplusnp = iter_wpplusnp + 1 ;
    end ;

    u_unlwp = u ;

    % compute gamma
    mygamma = 0.0 ;
    for ii = 1:cdim_in 
      mygamma = mygamma + u(ii)*q_ellipse(ii)*u(ii) ;
    end  ;
    mygamma = 0.5*mygamma ;

    if ( mygamma > 1.0 & try_unl0p ) 

      % linear solution did not work.
      % if no weighted pref soln, see if a linear soln exists
      % for a_pref=0.

      % get unlimited solution for preferred soln = 0, using
      % ellipse weighting
      [u_o,fail_unl0p] = get_unl0p(bin,rhs,q_ellipse,...
                                    cdim_in,rdim_in,eps_posdef) ;

      iter_unl0p = iter_unl0p + 1 ;

      % if bin is approx singular (fail_unl0p = true), then
      % use wpplusnp soln
      if ( fail_unl0p ) 
        u_o = get_wpplusnp(bin,rhs,zeros(length(a_pref),1),...
                           diag(q_ellipse),w_rhs,cdim_in,rdim_in) ;

        iter_wpplusnp = iter_wpplusnp + 1 ;
      end ;

      % compute gamma
      gamma_o = 0.0 ;
      for ii = 1:cdim_in 
        gamma_o = gamma_o + u_o(ii)*q_ellipse(ii)*u_o(ii) ;
      end  ;
      gamma_o = 0.5*gamma_o ;

      % don't try halving if there is no linear soln for a_pref=0.
      if ( gamma_o > 1.0 ) 
        if( bisect_ok ) 
          if( fail_unl0p | fail_unlwp ) 
	    bisect_needed = 0 ;
          else
	    bisect_needed = 1 ;
          end ;
	else
	  bisect_needed = 0 ;
        end ;
        halving_needed = 0 ;
      else
        bisect_needed = 0 ;
        halving_needed = 1 ;
      end ;

      % if halving makes sense, do it
      if ( halving_needed ) 
        aa = 0. ;
        bb = 0. ;
        cc = -1.;
	for ii = 1:cdim_in 
	  aa = aa + 0.5 * ( u_unlwp(ii)*q_ellipse(ii)*u_unlwp(ii)...
               -2.*u_unlwp(ii)*q_ellipse(ii)*u_o(ii)...
               + u_o(ii)*q_ellipse(ii)*u_o(ii)) ;
	  bb = bb + ( u_unlwp(ii)*q_ellipse(ii)*u_o(ii)...
               - u_o(ii)*q_ellipse(ii)*u_o(ii)) ;
	  cc = cc + 0.5*u_o(ii)*q_ellipse(ii)*u_o(ii) ;
	end ;

	f1f = ( - bb + sqrt( bb * bb - 4. * aa * cc ))/(2. * aa ) ;
	f2f = ( - bb - sqrt( bb * bb - 4. * aa * cc ))/(2. * aa ) ;

        if( f1f >= 0. & f1f <= 1. ) 
          f = f1f ;
        elseif ( f2f >= 0. & f2f <= 1. ) 
          f = f2f ;
        else
          f = 0. ;
        end;

	for ii = 1:cdim_in 
	  u(ii) = f * u_unlwp(ii) + ( 1. - f ) * u_o(ii) ;
	end ;

            % compute gamma
        mygamma = 0.0 ;
        for ii = 1:cdim_in 
          mygamma = mygamma + u(ii)*q_ellipse(ii)*u(ii) ;
        end  ;
        mygamma = 0.5*mygamma ;

      end;

    else

      % linear solution worked
      bisect_needed = 0 ;

    end ;

  else  % else for row_dim >= col_dim test

    [u,fail_unlnp] = get_unlnp(bin,rhs,w_rhs,...
                               cdim_in,rdim_in,eps_posdef) ;

    iter_unlnp = iter_unlnp + 1 ;

% should try non-zero preference and zero preference in this case
% but now only trying zero preference
    if ( fail_unlnp ) 
      u = get_wpplusnp(bin,rhs,zeros(length(a_pref),1),...
                         diag(q_ellipse),w_rhs,cdim_in,rdim_in) ;

      iter_wpplusnp = iter_wpplusnp + 1 ;
    end ;

%
    mygamma = 0.0 ;
    for ii = 1:cdim_in 
      mygamma = mygamma + u(ii)*q_ellipse(ii)*u(ii) ;
    end  ;
    mygamma = 0.5*mygamma ;

    if ( mygamma > 1.0 & bisect_ok ) 

      % linear solution did not work.
      if( fail_unlnp ) 
        bisect_needed = 0 ;
      else
        bisect_needed = 1 ;
      end ;

    else

      % linear solution did work.
      bisect_needed = 0 ;

    end ;

  end ;

  gam_out = mygamma;
  lam_out = 0.0;

% do bisection, if necessary
  if ( bisect_needed ) 

    for jj = 1:rdim_in 
      for ii = 1:cdim_in 
        btw(ii,jj) = bin(jj,ii)*w_rhs(jj) ;
      end  ;
    end  ;
    for ii = 1:cdim_in 
      btwd(ii) = 0.0 ;
      for jj = 1:rdim_in 
	btwd(ii) = btwd(ii) + btw(ii,jj)*rhs(jj) ;
      end  ;
    end  ;
    for ii = 1:cdim_in 
      for jj = 1:cdim_in 
	btwb(ii,jj) = 0.0 ;
	for kk = 1:rdim_in 
  	  btwb(ii,jj) = btwb(ii,jj) + btw(ii,kk)*bin(kk,jj) ;
        end  ;
      end  ;
    end  ;

    % get guess for lamba, if needed
    if ( lam_in == 0. ) 
      for ii = 1:cdim_in 
        num(ii) = btwd(ii) ;
        for jj = 1:cdim_in 
          num(ii) = num(ii) - btwb(ii,jj)*u(jj)/sqrt(mygamma) ;
	end  ;
      end  ;
      num_nrm =  0.0 ;
      den_nrm =  0.0 ;
      for ii = 1:cdim_in 
        num_nrm = num_nrm + num(ii)*num(ii) ;
        den_nrm = den_nrm + (q_ellipse(ii)*u(ii))*...
			    (q_ellipse(ii)*u(ii)) ;
      end  ;
      den_nrm = den_nrm/mygamma ;
      lam_bi = sqrt(num_nrm/den_nrm) ;
    else
      lam_bi = lam_in ;
    end ;

  % do bisection
    [u,lam_out,gam_out,iter_bi,iter_hi] = get_lam_bisect(...
	            lam_bi,btwb,btwd,q_ellipse,cdim_in,rdim_in) ;	 
	  
  end ;

  iter_tot = iter_unlwp + iter_unl0p + iter_unlnp + iter_wpplusnp ...
           + iter_bi + iter_hi ;

% diagnostic outputs
  sdat(1) = gam_out ;
  sdat(2) = lam_out ;
  sdat(3) = lam_in ;
  sdat(4) = cdim_in ;

%---------------------------------------------------------------

function [u,lam_out,mygamma,iter_bi,iter_hi] = get_lam_bisect(lam_in,btwb,btwd,q_ellipse,cdim_in,rdim_in)

  iter_hi = 0 ;
  iter_bi = 0 ;

  iter_hi_max = 300 ;
  iter_bi_max = 300 ;
  gam_tol_bi = 0.01 ;
  lam_tol = 0. ;
  lam_lo = 0.0 ;
  lam_hi = lam_in ;
  skip_bi = 0 ;

% this first part tries to find a lambda (lam_hi) which produces
% a gamma less than one. the initial lambda may do this.
% if not, increase lambda until it does.  if gamma never
% get below 1, skip the bisection.

%  iter_hi = 0 ;
  another_step = 1 ;

  while another_step 

    % compute gamma
    mati = btwb ;
    for ii = 1:cdim_in 
      mati(ii,ii) = mati(ii,ii) + lam_hi*q_ellipse(ii) ;
    end  ;

    eps_tiny = 1.e-12 ;

    [u,fail] = posdefsol(mati,btwd',cdim_in,1,eps_tiny) ;
%
% no test for fail = true here
%
%    u = gensol(mati,btwd,cdim_in) ;
    gamma_hi = 0.0 ;
    for ii = 1:cdim_in 
      gamma_hi = gamma_hi + u(ii)*q_ellipse(ii)*u(ii) ;
    end  ;
    gamma_hi = 0.5*gamma_hi ;

    % test it
    if ( gamma_hi > 1.0 ) 
      iter_hi = iter_hi + 1 ;
      lam_lo = lam_hi ;
      lam_hi = 2.0*exp(real(iter_hi)/5.0)*lam_hi ;
      if ( iter_hi >= iter_hi_max ) 
	another_step = 0 ;
	mygamma = gamma_hi ;
	lam_out = lam_lo ;
	skip_bi = 1 ;
      end ;
    else
      another_step = 0 ;
    end ;

  end  ;

% this second part bisects the region between lam_lo and
% lam_hi until gamma is appoximately one.

  if ( ~skip_bi ) 
%    iter_bi = 0 ;
    another_step = 1 ;
  
    while another_step 

      iter_bi = iter_bi + 1 ;
      lam_bi = 0.5*(lam_lo + lam_hi) ;

      % compute gamma
      mati = btwb ;
      for ii = 1:cdim_in 
        mati(ii,ii) = mati(ii,ii) + lam_bi*q_ellipse(ii) ;
      end  ;
      [u,fail] = posdefsol(mati,btwd',cdim_in,1,eps_tiny) ;
%
% no test for fail = true here
%
%      u = gensol(mati,btwd,cdim_in) ;
      mygamma = 0.0 ;
      for ii = 1:cdim_in 
        mygamma = mygamma + u(ii)*q_ellipse(ii)*u(ii) ;
      end  ;
      mygamma = 0.5*mygamma ;

      % test it
      if ( mygamma > 1.0 ) 
        lam_lo = lam_bi ;
        gam_lo = mygamma ;
      else
        lam_hi = lam_bi ;
        gam_hi = mygamma ;
      end ;

      % stopping tests
      if ( iter_bi >= iter_bi_max | ...
	   abs(mygamma - 1.0) <= gam_tol_bi   | ...
	   lam_hi - lam_lo < lam_tol   ) 
	   lam_out = lam_bi ;
        another_step = 0 ;
      end ;

    end  ;

  end ;


%---------------------------------------------------------------

function [u,fail] = get_unlwp(bin,rhs,a_pref,w_pref,cdim_in,rdim_in,eps_posdef)

% dan added 7aug02
  global MACH
  
eps_tiny = 1.e-12 ;

  [wibt,fail] = posdefsol(w_pref,bin',cdim_in,rdim_in,eps_tiny) ;
%
% no test for fail = true here
%

  for ii = 1:rdim_in 
    for jj = 1:rdim_in 
      mati(ii,jj) = 0.0 ;
      for kk = 1:cdim_in 
        mati(ii,jj) = mati(ii,jj) + bin(ii,kk)*wibt(kk,jj) ;
      end  ;
    end  ;
  end  ;

  for ii = 1:rdim_in 
    veci(ii) = rhs(ii) ;
    for kk = 1:cdim_in 
      veci(ii) = veci(ii) - bin(ii,kk)*a_pref(kk) ;
    end  ;
  end  ;

  [soli,fail] = posdefsol(mati,veci',rdim_in,1,eps_posdef) ;

  if ( ~fail ) 
    u = a_pref ;
    for ii = 1:cdim_in  
      for kk = 1:rdim_in  
        u(ii) = u(ii) + wibt(ii,kk)*soli(kk) ;
      end  ;
    end  ;
  else
    u = zeros(cdim_in,1) ;
  end ;


%---------------------------------------------------------------

function [u,fail] = get_unl0p(bin,rhs,q,cdim_in,rdim_in,eps_posdef)

% dan added 7aug02
  global MACH
  
  for ii = 1:cdim_in 
    for jj = 1:rdim_in 
      wibt(ii,jj) = bin(jj,ii)/q(ii) ;
    end  ;
  end  ;

  for ii = 1:rdim_in 
    for jj = 1:rdim_in 
      mati(ii,jj) = 0.0 ;
      for kk = 1:cdim_in 
        mati(ii,jj) = mati(ii,jj) + bin(ii,kk)*wibt(kk,jj) ;
      end  ;
    end  ;
  end  ;

  [soli,fail] = posdefsol(mati,rhs,rdim_in,1,eps_posdef) ;

  if ( ~fail ) 
    u = zeros(cdim_in,1) ;
    for ii = 1:cdim_in  
      for kk = 1:rdim_in  
        u(ii) = u(ii) + wibt(ii,kk)*soli(kk) ;
      end  ;
    end  ;
  else
    u = zeros(cdim_in,1) ;
  end ;


%---------------------------------------------------------------

function [u,fail] = get_unlnp(bin,rhs,w_rhs,cdim_in,rdim_in,eps_posdef)

% dan added 7aug02
  global MACH
  
  for ii = 1:cdim_in 
    for kk = 1:rdim_in 
      btw(ii,kk) = bin(kk,ii)*w_rhs(kk) ;
    end  ;
  end  ;

  for ii = 1:cdim_in 
    veci(ii) = 0.0 ;
    for jj = 1:rdim_in 
      veci(ii) = veci(ii) + btw(ii,jj)*rhs(jj) ;
    end  ;
  end  ;

  for ii = 1:cdim_in 
    for jj = 1:cdim_in 
    mati(ii,jj) = 0.0 ;
      for kk = 1:rdim_in 
        mati(ii,jj) = mati(ii,jj) + btw(ii,kk)*bin(kk,jj) ;
      end  ;
    end  ;
  end  ;

  [soli,fail] = posdefsol(mati,veci',cdim_in,1,eps_posdef) ;

  if ( ~fail ) 
    u = soli ;
  else
    u = zeros(cdim_in,1) ;
  end ;


%---------------------------------------------------------------

function [sol,fail_flag] = posdefsol(mat,vec,cdim_in,rdim_in,eps_posdef)

  fail_flag = 0 ;

% factor a pos def mat
  facmat = mat ;
  for jj = 1:cdim_in 

    sum = 0.0 ;
    jmone = jj - 1 ;
    if ( jmone >= 1 ) 
      
      for kk = 1:jmone 
%	t = facmat(kk,jj) - dot(kk-1,facmat(?,kk),facmat(?,jj)) ;
switch kk 
case 1
    t = facmat(kk,jj) ;
case 2
    t = facmat(kk,jj) - facmat(1,kk)*facmat(1,jj) ;
case 3
    t = facmat(kk,jj) - facmat(1,kk)*facmat(1,jj) - facmat(2,kk)*facmat(2,jj) ;
case 4
    t = facmat(kk,jj) - facmat(1,kk)*facmat(1,jj) - facmat(2,kk)*facmat(2,jj) - facmat(3,kk)*facmat(3,jj) ;
case 5
    t = facmat(kk,jj) - facmat(1,kk)*facmat(1,jj) - facmat(2,kk)*facmat(2,jj) - facmat(3,kk)*facmat(3,jj) - facmat(4,kk)*facmat(4,jj) ;
case 6
    t = facmat(kk,jj) - facmat(1,kk)*facmat(1,jj) - facmat(2,kk)*facmat(2,jj) - facmat(3,kk)*facmat(3,jj) - facmat(4,kk)*facmat(4,jj) - facmat(5,kk)*facmat(5,jj) ;
% this should probably be written as the generic case
	end  ;
	recip = 1.0 / facmat(kk,kk) ;
	% t = t/facmat(kk,kk) ;
	t = t * recip ;
	facmat(kk,jj) = t ;
	sum = sum + t*t ;
      end  ;

    end ;
    ddd = facmat(jj,jj) ;
    s = ddd - sum ;
    xxx = eps_posdef * max ( abs( ddd ), sum ) ;
    if ( s <= xxx ) 
      s = xxx ;
      fail_flag = 1 ;
    end ;
    if( fail_flag == 1 ) 
        return ;
    end;
    facmat(jj,jj) = sqrt(s) ;

  end ;
  
  if ( ~fail_flag ) 
      
      % solve the system of equations
      sol = vec ;
      for ll = 1:rdim_in 
          for kk = 1:cdim_in 
              %        tt = dot(kk-1,facmat(?,kk),sol(?,ll)) ;
              switch kk 
              case 1
                  tt = 0.0 ;
              case 2
                  tt = facmat(1,kk)*sol(1,ll) ;
              case 3
                  tt = facmat(1,kk)*sol(1,ll) + facmat(2,kk)*sol(2,ll) ;
              case 4
                  tt = facmat(1,kk)*sol(1,ll) + facmat(2,kk)*sol(2,ll) + facmat(3,kk)*sol(3,ll) ;
              case 5
                  tt = facmat(1,kk)*sol(1,ll) + facmat(2,kk)*sol(2,ll) + facmat(3,kk)*sol(3,ll) + facmat(4,kk)*sol(4,ll) ;
              case 6
                  tt = facmat(1,kk)*sol(1,ll) + facmat(2,kk)*sol(2,ll) + facmat(3,kk)*sol(3,ll) + facmat(4,kk)*sol(4,ll) + facmat(5,kk)*sol(5,ll) ;
              otherwise
                  tt = dot(facmat(:,kk),sol(:,ll)) ;
              end  ;
              sol(kk,ll) = (sol(kk,ll) - tt)/facmat(kk,kk) ;
          end  ;
      end  ;
      
    for ll = 1:rdim_in 
      for kb = 1:cdim_in 
       kbk = cdim_in + 1 - kb ;
        sol(kbk,ll) = sol(kbk,ll)/facmat(kbk,kbk) ;
        ttt = -sol(kbk,ll) ;
%        tmp = axpy(kbk-1,ttt,facmat(?,kbk),sol(?,ll)) ;
%        sol(?,ll) = tmp ;
switch kbk 
case 2
    sol(1,ll) = sol(1,ll) + ttt*facmat(1,kbk) ;
case 3
    sol(1,ll) = sol(1,ll) + ttt*facmat(1,kbk) ;
	   sol(2,ll) = sol(2,ll) + ttt*facmat(2,kbk) ;
case 4
       sol(1,ll) = sol(1,ll) + ttt*facmat(1,kbk) ;
	   sol(2,ll) = sol(2,ll) + ttt*facmat(2,kbk) ;
	   sol(3,ll) = sol(3,ll) + ttt*facmat(3,kbk) ;
case 5
       sol(1,ll) = sol(1,ll) + ttt*facmat(1,kbk) ;
	   sol(2,ll) = sol(2,ll) + ttt*facmat(2,kbk) ;
	   sol(3,ll) = sol(3,ll) + ttt*facmat(3,kbk) ;
	   sol(4,ll) = sol(4,ll) + ttt*facmat(4,kbk) ;
case 6
       sol(1,ll) = sol(1,ll) + ttt*facmat(1,kbk) ;
	   sol(2,ll) = sol(2,ll) + ttt*facmat(2,kbk) ;
	   sol(3,ll) = sol(3,ll) + ttt*facmat(3,kbk) ;
	   sol(4,ll) = sol(4,ll) + ttt*facmat(4,kbk) ;
	   sol(5,ll) = sol(5,ll) + ttt*facmat(5,kbk) ;
	end  ;
      end  ;
    end  ;

  else
    sol = 0.0 * vec ;
  end ;

%---------------------------------------------------------------

function [z] = axpy(n,a,x,y)

% out = ax+y

  if ( n <= 0 ) 
    z = y ;
  else
    z = y ;
    for ii = 1:n 
      z(ii) = z(ii) + a*x(ii) ;
    end  ;
  end ;
%---------------------------------------------------------------

%---------------------------------------------------------------

function [sol] = gensol(mat,vec,cdim_in)

% factor a gen mat
  nm1 = cdim_in - 1 ;
  facmat = mat ;
  if ( nm1 >= 1 ) 

    for kk = 1:nm1 

      kkp1 = kk + 1 ;
      imax = 0 ;
      if ( cdim_in-kk+1 >= 1 ) 
	imax = 1 ;
	if ( cdim_in-kk+1 ~= 1 ) 
	  max = abs(facmat(kk,kk)) ;
	  for iii = 1:cdim_in-kk 
	    if ( abs(facmat(kk+iii,kk)) > max ) 
	      imax = iii + 1 ;
	      max = abs(facmat(kk+iii,kk)) ;
	    end ;
	  end  ;
        end ;
      end ;
      ll = imax + kk - 1 ;
      ipvt(kk) = ll ;

      if ( facmat(ll,kk) ~= 0.0 ) 

	if ( ll ~= kk ) 
	  tt = facmat(ll,kk) ;
	  facmat(ll,kk) = facmat(kk,kk) ;
	  facmat(kk,kk) = tt ;
	end ;

	tt = -1.0/facmat(kk,kk) ;
	if ( cdim_in-kk > 0 ) 
	  for iii = 1:cdim_in-kk 
	    facmat(kk+iii,kk) = tt*facmat(kk+iii,kk) ;
	  end  ;
        end ;

	for jj = kkp1:cdim_in 
	  tt = facmat(ll,jj) ;
	  if ( ll ~= kk ) 
	    facmat(ll,jj) = facmat(kk,jj) ;
	    facmat(kk,jj) = tt ;
	  end ;
	  if ( cdim_in-kk > 0 ) 
	    for iii = 1:cdim_in-kk 
	      facmat(kk+iii,jj) = tt*facmat(kk+iii,kk) ...
	                          +    facmat(kk+iii,jj) ;
	    end  ;
          end ;
	end  ;

      end ;

    end  ;

  end ;
  ipvt(cdim_in) = cdim_in ;


% solve the system of equations
  sol = vec ;
  if ( nm1 >= 1 ) 
    for kk = 1:nm1 
      ll = ipvt(kk) ;
      tt = sol(ll) ;
      if ( ll ~= kk ) 
	sol(ll) = sol(kk) ;
	sol(kk) = tt ;
      end ;
      if ( cdim_in-kk > 0 ) 
        for iii = 1:cdim_in-kk 
          sol(kk+iii) = tt*facmat(kk+iii,kk) ...
                        +    sol(kk+iii) ;
        end  ;
      end ;
    end  ;
  end ;

  for kb = 1:cdim_in 
    kbk = cdim_in + 1 - kb ;
    sol(kbk) = sol(kbk)/facmat(kbk,kbk) ;
    ttt = -sol(kbk) ;
    tmp = axpy(kbk-1,ttt,facmat(:,kbk),sol) ;
    sol = tmp ;
  end  ;

%---------------------------------------------------------------

function [u] = get_wpplusnp(bin,rhs,a_pref,w_pref,w_rhs,cdim_in,rdim_in)

% get_wpplusnp solves the problem
%
%        1      T               1      T
%   min  -(Bu-d) W   (Bu-d)  + k-(u-u ) W (u-u )
%    u   2        rhs           2    p   p    p
%
% solution is:
%
%         T            -1  T
%   u = (B W   B + kW )  (B W   d + kW u )
%           rhs      p       rhs      p p

  k = 0.0000001 ;

  for ii = 1:cdim_in 
    for jj = 1:rdim_in 
      btw(ii,jj) = bin(jj,ii)*w_rhs(jj) ;
    end  ;
  end  ;

  for ii = 1:cdim_in 
    for jj = 1:cdim_in 
    mati(ii,jj) = k*w_pref(ii,jj) ;
      for kk = 1:rdim_in 
        mati(ii,jj) = mati(ii,jj) + btw(ii,kk)*bin(kk,jj) ;
      end  ;
    end  ;
  end  ;

  for ii = 1:cdim_in 
    veci(ii) = 0.0 ;
    for jj = 1:rdim_in 
      veci(ii) = veci(ii) + btw(ii,jj)*rhs(jj) ;
    end  ;
  end  ;

  for ii = 1:cdim_in 
    for kk = 1:cdim_in 
      veci(ii) = veci(ii) + k * w_pref(ii,kk)*a_pref(kk) ;
    end  ;
  end  ;

  eps_tiny = 1.e-12 ;

  [u,fail] = posdefsol(mati,veci',cdim_in,1,eps_tiny) ;
%
% no test for fail = true here
%

%---------------------------------------------------------------

% **************** Honeywell Proprietary ****************************
% This code is considered proprietary to Honeywell. 
% Questions about its availability should be directed
% to either Dale Enns (612-951-7289 or enns_dale@htc.honeywell.com)
% or Dan Bugajski (612-951-7287 or bugajski_dan@htc.honeywell.com)
% **************** Honeywell Proprietary ****************************
