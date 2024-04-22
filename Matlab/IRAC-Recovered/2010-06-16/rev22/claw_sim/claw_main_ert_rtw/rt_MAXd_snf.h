/*
 * File: rt_MAXd_snf.h
 *
 * Real-Time Workshop code generated for Simulink model claw_main.
 *
 * Model version                        : 1.5330
 * Real-Time Workshop file version      : 7.2  (R2008b)  04-Aug-2008
 * Real-Time Workshop file generated on : Tue Dec 13 11:51:06 2011
 * TLC version                          : 7.2 (Aug  5 2008)
 * C/C++ source code generated on       : Tue Dec 13 11:51:08 2011
 */

#ifndef RTW_HEADER_rt_MAXd_snf_h_
#define RTW_HEADER_rt_MAXd_snf_h_
#include "rt_nonfinite.h"
#define rt_MAXd_snf(a, b)              (( ((a) >= (b)) || rtIsNaN(b) ) ? (a) : (b))
#endif                                 /* RTW_HEADER_rt_MAXd_snf_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
