/*
 * File: rtGetInf.c
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
 *      Real-Time Workshop function to intialize non-finite, Inf
 */
#include "rtGetInf.h"
#define NumBitsPerChar                 8

/* Function: rtGetInf ==================================================
 * Abstract:
 *	Initialize rtInf needed by the generated code.
 *	Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32) {
    inf = rtGetInfF();
  } else {
    typedef struct {
      struct {
        uint32_T wordL;
        uint32_T wordH;
      } words;
    } LittleEndianIEEEDouble;

    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000;
    tmpVal.bitVal.words.wordL = 0x00000000;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/* Function: rtGetInfF ==================================================
 * Abstract:
 *	Initialize rtInfF needed by the generated code.
 *	Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;

  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000;
  return infF.wordL.wordLreal;
}

/* Function: rtGetMinusInf ==================================================
 * Abstract:
 *	Initialize rtMinusInf needed by the generated code.
 *	Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32) {
    minf = rtGetMinusInfF();
  } else {
    typedef struct {
      struct {
        uint32_T wordL;
        uint32_T wordH;
      } words;
    } LittleEndianIEEEDouble;

    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000;
    tmpVal.bitVal.words.wordL = 0x00000000;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/* Function: rtGetMinusInfF ==================================================
 * Abstract:
 *	Initialize rtMinusInfF needed by the generated code.
 *	Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;

  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000;
  return minfF.wordL.wordLreal;
}

#undef NumBitsPerChar

/* end rtGetInf.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
