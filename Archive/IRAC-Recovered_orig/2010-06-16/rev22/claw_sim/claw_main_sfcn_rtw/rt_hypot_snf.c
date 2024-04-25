/*
 * rt_hypot_snf.c
 *
 * Real-Time Workshop code generation for Simulink model "claw_main_sf.mdl".
 *
 * Model Version              : 1.5449
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Dec 13 11:25:43 2011
 *
 */

#include "rt_hypot_snf.h"
#include <math.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Function: rt_hypot_snf =======================================================
 * Abstract:
 *	hypot(a,b) = sqrt(a^2 + b^2)
 */
real_T rt_hypot_snf(real_T a, real_T b)
{
  real_T t;                            /* scales a & b */
  real_T retValue;
  if (rtIsNaN(a) || rtIsNaN(b)) {
    retValue = (rtNaN);
  } else {
    if (rtIsInf(a) && rtIsInf(b)) {
      retValue = (rtInf);
    } else {
      if (fabs(a) > fabs(b)) {         /* Case 1: a > b ==> t = b / a < 1.0 */
        t = b/a;
        retValue = (fabs(a)*sqrt(1.0 + t*t));
      } else {                         /* Case 2: a <= b ==> t = a / b <= 1.0 */
        if (b == 0.0) {
          retValue = (0.0);
        } else {
          t = a/b;
          retValue = (fabs(b)*sqrt(1.0 + t*t));
        }
      }                                /* one input is inf */
    }                                  /* one input is nan */
  }

  return retValue;
}                                      /* end rt_hypot_snf */
