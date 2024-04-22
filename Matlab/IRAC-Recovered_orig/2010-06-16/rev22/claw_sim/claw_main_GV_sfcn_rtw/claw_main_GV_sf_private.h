/*
 * claw_main_GV_sf_private.h
 *
 * Real-Time Workshop code generation for Simulink model "claw_main_GV_sf.mdl".
 *
 * Model Version              : 1.5137
 * Real-Time Workshop version : 6.3  (R14SP3)  26-Jul-2005
 * C source code generated on : Fri May 29 11:09:50 2009
 */
#ifndef _RTW_HEADER_claw_main_GV_sf_private_h_
#define _RTW_HEADER_claw_main_GV_sf_private_h_

#include "rtwtypes.h"

# include "rtlibsrc.h"
#define CALL_EVENT                      (MAX_uint8_T)

#ifndef _RTW_COMMON_DEFINES_
# define _RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr) if(!(ptr)) {\
    ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
    return(S);\
  }

#if !defined(_WIN32)
#define rt_FREE(ptr) if((ptr) != NULL) {\
    free((ptr));\
    (ptr) = NULL;\
  }
#else
/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr) if((ptr) != NULL) {\
    free((void *)(ptr));\
    (ptr) = NULL;\
  }
#endif

#endif                                  /* _RTW_COMMON_DEFINES_ */

/* Used by FromWorkspace Block: <S94>/From Workspace4 */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2) (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v) ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else
/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                  /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                  /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                  /* __RTWTYPES_H__ */

/*
 * Tunable Parameters
 *
 * Note: Tunable parameters with Auto storage class are treated as s-function
 * parameters in the Real-Time Workshop S-Function Target.  The generated 
 * s-function will declare them as parameters and verify correct data 
 * types/sizes are maintained.  The parameters are propagated to nested
 * non-inlined s-functions
 *
 */
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_claw_main_GV_sf)
#define MACH_U_nom_IC(S) _ssGetSFcnParam(S,0)
#define MACH_gain_mat(S) _ssGetSFcnParam(S,1)
#define MACH_mass_IC(S) _ssGetSFcnParam(S,2)
#define MACH_pos_IC(S) _ssGetSFcnParam(S,3)
#define MACH_pqr_Bmat_IC(S) _ssGetSFcnParam(S,4)
#define MACH_pqr_IC(S) _ssGetSFcnParam(S,5)
#define MACH_pqr_u_IC(S) _ssGetSFcnParam(S,6)
#define MACH_quat_IC(S) _ssGetSFcnParam(S,7)
#define MACH_throttle_IC(S) _ssGetSFcnParam(S,8)
#define MACH_vel_Bmat_IC(S) _ssGetSFcnParam(S,9)
#define MACH_vel_IC(S) _ssGetSFcnParam(S,10)
#define MACH_vel_cvdnom_IC(S) _ssGetSFcnParam(S,11)
#define MACH_vel_uold_IC(S) _ssGetSFcnParam(S,12)
#endif                                  /* RTW_GENERATED_SFCN_TUNABLE_PRMS_claw_main_GV_sf */

extern void smn_sfunc_gam_mpass_epsposdef_Outputs_wrapper(const real_T *u0,
 real_T *y0,
 const int_T y_width, const int_T u_width);

real_T aaimcjmobimocbai_genpnorm(real_T *x, real_T p);

real_T kngdjecbopphhlfk_norm(real_T *x);

real_T kfcjnglndbiejecb_mpower(real_T x1, real_T x2);

real_T cbaabiecohlncbaa_atan2(real_T Y, real_T X);

real_T fcjmlfcbmophlngl_sign(real_T X);

real_T ngdbimohgdjmhlfc_max2(real_T x, real_T y);

void lfcblnglfkfkophl_LUSolve(real_T *A, real_T *B, real_T *Y);

real_T claw_main_GV_sf_DotProduct_real(const real_T *pIn1, const real_T *pIn2,
 int32_T nMiddleDim);
extern void table3v5(SimStruct *childS);
extern void table2v5(SimStruct *childS);
extern void table1v5(SimStruct *childS);

#endif                                  /* _RTW_HEADER_claw_main_GV_sf_private_h_ */
