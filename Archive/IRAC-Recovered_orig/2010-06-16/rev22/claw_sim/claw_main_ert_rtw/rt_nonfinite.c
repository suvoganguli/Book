/*
 * File: rt_nonfinite.c
 *
 * Real-Time Workshop code generated for Simulink model claw_main.
 *
 * Model version                        : 1.5330
 * Real-Time Workshop file version      : 7.2  (R2008b)  04-Aug-2008
 * Real-Time Workshop file generated on : Tue Dec 13 11:51:06 2011
 * TLC version                          : 7.2 (Aug  5 2008)
 * C/C++ source code generated on       : Tue Dec 13 11:51:08 2011
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#define NumBitsPerChar                 8

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 *	Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 *	generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Function: rtIsInf ==================================================
 * Abstract:
 *	Test if value is infinite
 */
boolean_T rtIsInf(real_T value)
{
  return ((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 *	Test if single-precision value is infinite
 */
boolean_T rtIsInfF(real32_T value)
{
  return(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 *	Test if value is not a number
 */
boolean_T rtIsNaN(real_T value)
{
  return((value!=value) ? 1U : 0U);
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 *	Test if single-precision value is not a number
 */
boolean_T rtIsNaNF(real32_T value)
{
  return((value!=value) ? 1U : 0U);
}

#undef NumBitsPerChar

/* end rt_nonfinite.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
