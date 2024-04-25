/*
 * File: rt_atan2_snf.c
 *
 * Real-Time Workshop code generated for Simulink model claw_main.
 *
 * Model version                        : 1.5330
 * Real-Time Workshop file version      : 7.2  (R2008b)  04-Aug-2008
 * Real-Time Workshop file generated on : Tue Dec 13 11:51:06 2011
 * TLC version                          : 7.2 (Aug  5 2008)
 * C/C++ source code generated on       : Tue Dec 13 11:51:08 2011
 */

#include "rt_atan2_snf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <math.h>

/* Function: rt_atan2_snf =======================================================
 * Abstract:
 *   Calls ATAN2, with guards against domain error and non-finites
 */
real_T rt_atan2_snf(real_T a, real_T b)
{
  real_T retValue;
  if (rtIsNaN(a) || rtIsNaN(b)) {
    retValue = (rtNaN);
  } else {
    if (rtIsInf(a) && rtIsInf(b)) {
      if (b > 0.0) {
        b = 1.0;
      } else {
        b = -1.0;
      }

      if (a > 0.0) {
        a = 1.0;
      } else {
        a = -1.0;
      }

      retValue = atan2(a,b);
    } else if (b == 0.0) {
      if (a > 0.0) {
        retValue = (RT_PI)/2.0;
      } else if (a < 0.0) {
        retValue = -(RT_PI)/2.0;
      } else {
        retValue = 0.0;
      }
    } else {
      retValue = atan2(a,b);
    }
  }

  return retValue;
}                                      /* end rt_atan2_snf */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
