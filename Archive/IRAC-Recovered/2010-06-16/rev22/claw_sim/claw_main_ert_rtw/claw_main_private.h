/*
 * File: claw_main_private.h
 *
 * Real-Time Workshop code generated for Simulink model claw_main.
 *
 * Model version                        : 1.5330
 * Real-Time Workshop file version      : 7.2  (R2008b)  04-Aug-2008
 * Real-Time Workshop file generated on : Tue Dec 13 11:51:06 2011
 * TLC version                          : 7.2 (Aug  5 2008)
 * C/C++ source code generated on       : Tue Dec 13 11:51:08 2011
 */

#ifndef RTW_HEADER_claw_main_private_h_
#define RTW_HEADER_claw_main_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (MAX_uint8_T)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

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
void BINARYSEARCH_real_T( uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void LookUp_real_T_real_T( real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi);
uint32_T plook_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction, uint32_T *prevIndex);
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction);
real_T intrp2d_lc(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], uint32_T stride);
int32_T plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
  *fraction, int32_T *prevIndex);
real_T intrp1d_lc(uint32_T bpIndex, real_T frac, const real_T table[]);
real_T intrp1d_lx(uint32_T bpIndex, real_T frac, const real_T table[]);
real_T intrp3d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], const uint32_T stride[]);
real_T intrp2d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], uint32_T stride);
uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction);
uint32_T plook_linxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction, uint32_T *prevIndex);
real_T intrp4d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], const uint32_T stride[]);
uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
int32_T binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
uint32_T linsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex);
void claw_main_tiltcam(const real_T rtu_att[3], real_T rty_0[9],
  rtP_tiltcam_claw_main *localP);
void claw_main_ypr(const real_T rtu_att[3], real_T rty_0[9], rtP_ypr_claw_main
                   *localP);
void claw_main_mba(const real_T rtu_att[3], real_T rtu_1, real_T rtu_2, real_T
                   rtu_3, real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                   real_T rtu_8, real_T rtu_9, real_T rty_0[9],
                   rtP_mba_claw_main *localP);
void claw_main_tiltcam_b(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
  real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7, real_T rtu_8, real_T
  rty_0[3], rtP_tiltcam_claw_main_n *localP);
void claw_main_ypr_c(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
                     real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                     real_T rtu_8, real_T rty_0[3], rtP_ypr_claw_main_p *localP);
void claw_main_mba_h(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
                     real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                     real_T rtu_8, real_T rtu_9, real_T rtu_10, real_T rtu_11,
                     real_T rtu_12, real_T rtu_13, real_T rtu_14, real_T rtu_15,
                     real_T rtu_16, real_T rtu_17, real_T rty_0[3],
                     rtP_mba_claw_main_a *localP);
void claw_mai_EmbeddedMATLABFunction(real_T rtu_u,
  rtB_EmbeddedMATLABFunction_claw *localB, rtP_EmbeddedMATLABFunction_claw
  *localP);
void claw_main_fuelcgshiftcg_pos0(real_T rtu_fuel_used,
  rtB_fuelcgshiftcg_pos0_claw_mai *localB, rtP_fuelcgshiftcg_pos0_claw_mai
  *localP);
void SwitchCaseActionSubsystem_Start(real_T rty_0[6],
  rtP_SwitchCaseActionSubsystem_c *localP);
void claw__SwitchCaseActionSubsystem(real_T rtu_alpha, real_T rtu_beta, uint32_T
  rtu_damage_case, real_T rty_0[6], rtDW_SwitchCaseActionSubsystem_ *localDW,
  rtP_SwitchCaseActionSubsystem_c *localP);
void claw_main_ImplementDamageModels(const real_T rtu_0[6], const real_T rtu_1[6],
  const real_T rtu_2[6], const real_T rtu_3[6], const real_T rtu_4[6], const
  real_T rtu_5[6], const real_T rtu_6[6], const real_T rtu_7[6], const real_T
  rtu_8[6], const real_T rtu_9[6], const real_T rtu_10[6], const real_T rtu_11[6],
  const real_T rtu_12[6], const real_T rtu_13[6], const real_T rtu_14[6], const
  real_T rtu_15[6], const real_T rtu_16[6], const real_T rtu_17[6], real_T
  rtu_DamageCase, rtB_ImplementDamageModels_claw_ *localB);
void ForcedOscillationwithDamageIncr(real_T rtu_alpha, uint32_T rtu_DamageCase,
  real_T rtu_TAS, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T
  rty_0[6], rtB_ForcedOscillationwithDamage *localB,
  rtDW_ForcedOscillationwithDamag *localDW, rtP_ForcedOscillationwithDamage
  *localP, uint8_T rtd_WhileIterator_IterationMark[7]);
void claw_main_BlendingFunction(real_T rtu_alpha, real_T rtu_beta, real_T
  rtu_tas, const real_T rtu_pqr[3], real_T rtu_B, real_T rtu_Cbar,
  rtB_BlendingFunction_claw_main *localB);
void claw_RotaryBlendedUnDamagedCase(real_T rtu_alpha, real_T rtu_TAS, real_T
  rtu_beta, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T rty_0[6],
  rtB_RotaryBlendedUnDamagedCase_ *localB, rtDW_RotaryBlendedUnDamagedCase
  *localDW, rtP_RotaryBlendedUnDamagedCase_ *localP, uint8_T
  rtd_WhileIterator_IterationMark[7]);
void claw_main_EngineAlignment(real_T rtu_Tl, real_T rtu_hl, real_T rtu_Tr,
  real_T rtu_hr, rtB_EngineAlignment_claw_main *localB,
  rtP_EngineAlignment_claw_main *localP);
void ForcedOscillationwithDamageIn_o(real_T rtu_alpha, uint32_T rtu_DamageCase,
  real_T rtu_TAS, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T
  rty_0[6], rtB_ForcedOscillationwithDama_d *localB,
  rtDW_ForcedOscillationwithDam_j *localDW, rtP_ForcedOscillationwithDama_l
  *localP);
void cl_RotaryBlendedUnDamagedCase_k(real_T rtu_alpha, real_T rtu_TAS, real_T
  rtu_beta, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T rty_0[6],
  rtB_RotaryBlendedUnDamagedCas_a *localB, rtDW_RotaryBlendedUnDamagedCa_p
  *localDW, rtP_RotaryBlendedUnDamagedCas_m *localP);

#endif                                 /* RTW_HEADER_claw_main_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
