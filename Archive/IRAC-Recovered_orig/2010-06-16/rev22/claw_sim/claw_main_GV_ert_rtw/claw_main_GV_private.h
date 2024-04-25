/*
 * File: claw_main_GV_private.h
 *
 * Real-Time Workshop code generated for Simulink model claw_main_GV.
 *
 * Model version                        : 1.5149
 * Real-Time Workshop file version      : 6.3  (R14SP3)  26-Jul-2005
 * Real-Time Workshop file generated on : Mon Jun 29 11:29:25 2009
 * TLC version                          : 6.3 (Aug  5 2005)
 * C source code generated on           : Mon Jun 29 11:29:47 2009
 */

#ifndef _RTW_HEADER_claw_main_GV_private_h_
#define _RTW_HEADER_claw_main_GV_private_h_

#include "rtwtypes.h"

# include "rtlibsrc.h"
#define CALL_EVENT                      (MAX_uint8_T)
/* Private macros used by the generated code to access rtModel */

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm) claw_main_GV_M->Timing.t[0] == (rtmGetTStart((rtm)))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm) ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val) ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: <S93>/From Workspace4 */
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

real_T DotProduct_real(const real_T *pIn1, const real_T *pIn2, int32_T
 nMiddleDim);
extern void table3v5(SimStruct *rts);
extern void table2v5(SimStruct *rts);
extern void table1v5(SimStruct *rts);

#endif                                  /* _RTW_HEADER_claw_main_GV_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
