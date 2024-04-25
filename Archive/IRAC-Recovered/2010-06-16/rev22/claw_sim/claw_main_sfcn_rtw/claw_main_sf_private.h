/*
 * claw_main_sf_private.h
 *
 * Real-Time Workshop code generation for Simulink model "claw_main_sf.mdl".
 *
 * Model Version              : 1.5449
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Dec 13 11:25:43 2011
 */
#ifndef RTW_HEADER_claw_main_sf_private_h_
#define RTW_HEADER_claw_main_sf_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (MAX_uint8_T)
#ifndef RTW_COMMON_DEFINES_
# define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 return(S);\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif                                 /* RTW_COMMON_DEFINES_ */

/* Used by FromWorkspace Block: '<S222>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
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
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void smn_sfunc_gam_mpass_epsposdef_Outputs_wrapper(const real_T *u0,
  real_T *y0,
  const int_T y_width, const int_T u_width);
void claw_main_sf_BINARYSEARCH_real_T( uint32_T *piLeft, uint32_T *piRght,
  real_T u, const real_T *pData, uint32_T iHi);
void claw_main_sf_LookUp_real_T_real_T( real_T *pY, const real_T *pYData, real_T
  u, const real_T *pUData, uint32_T iHi);
uint32_T claw_main_plook_binx(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
uint32_T claw_main_plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
uint32_T claw_main_plook_linxp(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex);
real_T claw_main_intrp2d_lx(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], uint32_T stride);
real_T claw_main_intrp3d_lx(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride[]);
real_T claw_main_intrp4d_lx(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride[]);
int32_T claw_main_plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T
  maxIndex, real_T *fraction, int32_T *prevIndex);
real_T claw_main_intrp1d_lx(uint32_T bpIndex, real_T frac, const real_T table[]);
uint32_T claw_main_plook_binxp(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, uint32_T *prevIndex);
real_T claw_main_intrp2d_lc(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], uint32_T stride);
real_T claw_main_intrp1d_lc(uint32_T bpIndex, real_T frac, const real_T table[]);
uint32_T claw_main_binsearch_u32d(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
uint32_T claw_main_linsearch_u32d(real_T u, const real_T bp[], uint32_T
  startIndex);
int32_T claw_main_binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
uint32_T claw_main_binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);

#endif                                 /* RTW_HEADER_claw_main_sf_private_h_ */
