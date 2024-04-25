/*
 * File: claw_main.c
 *
 * Real-Time Workshop code generated for Simulink model claw_main.
 *
 * Model version                        : 1.5330
 * Real-Time Workshop file version      : 7.2  (R2008b)  04-Aug-2008
 * Real-Time Workshop file generated on : Tue Dec 13 11:51:06 2011
 * TLC version                          : 7.2 (Aug  5 2008)
 * C/C++ source code generated on       : Tue Dec 13 11:51:08 2011
 */

#include "claw_main.h"
#include "claw_main_private.h"

/* Exported block signals */
real_T CLAW_Nd_wind;                   /* '<S87>/In1' */
real_T CLAW_Ed_wind;                   /* '<S87>/In2' */
real_T CLAW_Dd_wind;                   /* '<S87>/In3' */
real_T CLAW_p_int;                     /* '<S86>/In1' */
real_T CLAW_q_int;                     /* '<S86>/In2' */
real_T CLAW_r_int;                     /* '<S86>/In3' */
real_T CLAW_e0_int;                    /* '<S86>/In4' */
real_T CLAW_e1_int;                    /* '<S86>/In5' */
real_T CLAW_e2_int;                    /* '<S86>/In6' */
real_T CLAW_e3_int;                    /* '<S86>/In7' */
real_T CLAW_Ndot_int;                  /* '<S86>/In8' */
real_T CLAW_Edot_int;                  /* '<S86>/In9' */
real_T CLAW_hdot_int;                  /* '<S86>/In10' */
real_T CLAW_N_int;                     /* '<S86>/In11' */
real_T CLAW_E_int;                     /* '<S86>/In12' */
real_T CLAW_h_int;                     /* '<S86>/In13' */
real_T CLAW_p_cvdex;                   /* '<S85>/In1' */
real_T CLAW_q_cvdex;                   /* '<S85>/In2' */
real_T CLAW_r_cvdex;                   /* '<S85>/In3' */
real_T CLAW_e0_cvdex;                  /* '<S85>/In4' */
real_T CLAW_e1_cvdex;                  /* '<S85>/In5' */
real_T CLAW_e2_cvdex;                  /* '<S85>/In6' */
real_T CLAW_e3_cvdex;                  /* '<S85>/In7' */
real_T CLAW_Ndot_cvdex;                /* '<S85>/In8' */
real_T CLAW_Edot_cvdex;                /* '<S85>/In9' */
real_T CLAW_hdot_cvdex;                /* '<S85>/In10' */
real_T CLAW_N_cvdex;                   /* '<S85>/In11' */
real_T CLAW_E_cvdex;                   /* '<S85>/In12' */
real_T CLAW_h_cvdex;                   /* '<S85>/In13' */
real_T CLAW_p_cvcmd;                   /* '<S84>/In1' */
real_T CLAW_q_cvcmd;                   /* '<S84>/In2' */
real_T CLAW_r_cvcmd;                   /* '<S84>/In3' */
real_T CLAW_e0_cvcmd;                  /* '<S84>/In4' */
real_T CLAW_e1_cvcmd;                  /* '<S84>/In5' */
real_T CLAW_e2_cvcmd;                  /* '<S84>/In6' */
real_T CLAW_e3_cvcmd;                  /* '<S84>/In7' */
real_T CLAW_Ndot_cvcmd;                /* '<S84>/In8' */
real_T CLAW_Edot_cvcmd;                /* '<S84>/In9' */
real_T CLAW_hdot_cvcmd;                /* '<S84>/In10' */
real_T CLAW_N_cvcmd;                   /* '<S84>/In11' */
real_T CLAW_E_cvcmd;                   /* '<S84>/In12' */
real_T CLAW_h_cvcmd;                   /* '<S84>/In13' */
real_T CLAW_p_cv;                      /* '<S83>/In1' */
real_T CLAW_q_cv;                      /* '<S83>/In2' */
real_T CLAW_r_cv;                      /* '<S83>/In3' */
real_T CLAW_e0_cv;                     /* '<S83>/In4' */
real_T CLAW_e1_cv;                     /* '<S83>/In5' */
real_T CLAW_e2_cv;                     /* '<S83>/In6' */
real_T CLAW_e3_cv;                     /* '<S83>/In7' */
real_T CLAW_Ndot_cv;                   /* '<S83>/In8' */
real_T CLAW_Edot_cv;                   /* '<S83>/In9' */
real_T CLAW_hdot_cv;                   /* '<S83>/In10' */
real_T CLAW_N_cv;                      /* '<S83>/In11' */
real_T CLAW_E_cv;                      /* '<S83>/In12' */
real_T CLAW_h_cv;                      /* '<S83>/In13' */

/* Block signals (auto storage) */
BlockIO_claw_main claw_main_B;

/* Block states (auto storage) */
D_Work_claw_main claw_main_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_claw_main claw_main_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_claw_main claw_main_Y;

/* Real-time model */
RT_MODEL_claw_main claw_main_M_;
RT_MODEL_claw_main *claw_main_M = &claw_main_M_;

/*********************************************************************
 * Lookup Binary Search Utility BINARYSEARCH_real_T
 */
void BINARYSEARCH_real_T( uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1 ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* end macro BINARYSEARCH_real_T
 *********************************************************************/

/*********************************************************************
 * Lookup Utility LookUp_real_T_real_T
 */
void LookUp_real_T_real_T( real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den = den - pUData[iLeft];
      num = u;
      num = num - pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      if (lambda != 0) {
        yLeftCast += lambda * ( yRghtCast - yLeftCast );
      }

      (*pY) = yLeftCast;
    }
  }
}

/* end function LookUp_real_T_real_T
 *********************************************************************/
uint32_T plook_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction, uint32_T *prevIndex)
{
  uint32_T bpIndex;
  uint32_T startIndex;
  real_T bpLeftCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Linear extrapolation'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (u < bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    startIndex = *prevIndex;
    bpIndex = binsearch_u32d_prevIdx(u, bp, startIndex, maxIndex);
    bpLeftCast = bp[bpIndex];
    *fraction = (u - bpLeftCast) / (bp[bpIndex + 1U] - bpLeftCast);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;
  real_T bpLeftCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Linear extrapolation'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (u < bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, (maxIndex + 1U) >> 1U, maxIndex);
    bpLeftCast = bp[bpIndex];
    *fraction = (u - bpLeftCast) / (bp[bpIndex + 1U] - bpLeftCast);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

real_T intrp2d_lc(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], uint32_T stride)
{
  real_T y;
  uint32_T offset_1d;
  real_T yL_0d0;
  real_T yL_0d1;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  offset_1d = bpIndex[1] * stride + bpIndex[0];
  yL_0d0 = table[offset_1d];
  yL_0d0 = (table[offset_1d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_1d = offset_1d + stride;
  yL_0d1 = table[offset_1d];
  y = (((table[offset_1d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) * frac[1]
    + yL_0d0;
  return y;
}

int32_T plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
  *fraction, int32_T *prevIndex)
{
  int32_T bpIndex;
  uint32_T startIndex;
  real_T bpLeftCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Linear extrapolation'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (u < bp[0U]) {
    bpIndex = 0;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    startIndex = (uint32_T)*prevIndex;
    bpIndex = binsearch_s32d_prevIdx(u, bp, startIndex, maxIndex);
    bpLeftCast = bp[(uint32_T)bpIndex];
    *fraction = (u - bpLeftCast) / (bp[(uint32_T)bpIndex + 1U] - bpLeftCast);
  } else {
    bpIndex = (int32_T)(maxIndex - 1U);
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

real_T intrp1d_lc(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T y;
  real_T yL_0d0;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  yL_0d0 = table[bpIndex];
  y = (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
  return y;
}

real_T intrp1d_lx(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T y;
  real_T yL_0d0;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  yL_0d0 = table[bpIndex];
  y = (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
  return y;
}

real_T intrp3d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], const uint32_T stride[])
{
  real_T y;
  real_T yL_2d;
  uint32_T offset_2d;
  real_T yL_0d0;
  uint32_T offset_0d;
  real_T yL_0d1;

  /* Interpolation 3-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  offset_2d = (bpIndex[2] * stride[2] + bpIndex[1] * stride[1]) + bpIndex[0];
  yL_0d0 = table[offset_2d];
  yL_0d0 = (table[offset_2d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_0d = offset_2d + stride[1];
  yL_0d1 = table[offset_0d];
  yL_2d = (((table[offset_0d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) *
    frac[1] + yL_0d0;
  offset_2d = offset_2d + stride[2];
  yL_0d0 = table[offset_2d];
  yL_0d0 = (table[offset_2d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_2d = offset_2d + stride[1];
  yL_0d1 = table[offset_2d];
  y = (((((table[offset_2d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) * frac
        [1] + yL_0d0) - yL_2d) * frac[2] + yL_2d;
  return y;
}

real_T intrp2d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], uint32_T stride)
{
  real_T y;
  uint32_T offset_1d;
  real_T yL_0d0;
  real_T yL_0d1;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  offset_1d = bpIndex[1] * stride + bpIndex[0];
  yL_0d0 = table[offset_1d];
  yL_0d0 = (table[offset_1d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_1d = offset_1d + stride;
  yL_0d1 = table[offset_1d];
  y = (((table[offset_1d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) * frac[1]
    + yL_0d0;
  return y;
}

uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;
  real_T bpLeftCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (u < bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, (maxIndex + 1U) >> 1U, maxIndex);
    bpLeftCast = bp[bpIndex];
    *fraction = (u - bpLeftCast) / (bp[bpIndex + 1U] - bpLeftCast);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0;
  }

  return bpIndex;
}

uint32_T plook_linxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                     *fraction, uint32_T *prevIndex)
{
  uint32_T bpIndex;
  uint32_T startIndex;
  real_T bpLeftCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Process out of range input: 'Linear extrapolation'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (u < bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    startIndex = *prevIndex;
    bpIndex = linsearch_u32d(u, bp, startIndex);
    bpLeftCast = bp[bpIndex];
    *fraction = (u - bpLeftCast) / (bp[bpIndex + 1U] - bpLeftCast);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

real_T intrp4d_lx(const uint32_T bpIndex[], const real_T frac[], const real_T
                  table[], const uint32_T stride[])
{
  real_T y;
  real_T yL_3d;
  uint32_T offset_3d;
  real_T yL_2d;
  real_T yL_0d0;
  uint32_T offset_0d;
  real_T yL_0d1;

  /* Interpolation 4-D
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  offset_3d = ((bpIndex[3] * stride[3] + bpIndex[2] * stride[2]) + bpIndex[1] *
               stride[1]) + bpIndex[0];
  yL_0d0 = table[offset_3d];
  yL_0d0 = (table[offset_3d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_0d = offset_3d + stride[1];
  yL_0d1 = table[offset_0d];
  yL_2d = (((table[offset_0d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) *
    frac[1] + yL_0d0;
  offset_0d = offset_3d + stride[2];
  yL_0d0 = table[offset_0d];
  yL_0d0 = (table[offset_0d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_0d = offset_0d + stride[1];
  yL_0d1 = table[offset_0d];
  yL_3d = (((((table[offset_0d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) *
            frac[1] + yL_0d0) - yL_2d) * frac[2] + yL_2d;
  offset_0d = offset_3d + stride[3];
  yL_0d0 = table[offset_0d];
  yL_0d0 = (table[offset_0d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_3d = offset_0d + stride[1];
  yL_0d1 = table[offset_3d];
  yL_2d = (((table[offset_3d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) *
    frac[1] + yL_0d0;
  offset_0d = offset_0d + stride[2];
  yL_0d0 = table[offset_0d];
  yL_0d0 = (table[offset_0d + 1U] - yL_0d0) * frac[0] + yL_0d0;
  offset_0d = offset_0d + stride[1];
  yL_0d1 = table[offset_0d];
  y = (((((((table[offset_0d + 1U] - yL_0d1) * frac[0] + yL_0d1) - yL_0d0) *
          frac[1] + yL_0d0) - yL_2d) * frac[2] + yL_2d) - yL_3d) * frac[3] +
    yL_3d;
  return y;
}

uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;
  uint32_T found;

  /* Binary Search using Previous Index */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx - 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    } else if (u < bp[bpIdx + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIdx + 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    }
  }

  bpIndex = bpIdx;
  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  bpIndex = iLeft;
  return bpIndex;
}

int32_T binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  int32_T bpIndex;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;
  uint32_T found;

  /* Binary Search using Previous Index */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx - 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    } else if (u < bp[bpIdx + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIdx + 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    }
  }

  bpIndex = (int32_T)bpIdx;
  return bpIndex;
}

uint32_T linsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex)
{
  uint32_T bpIndex;
  uint32_T found;
  uint32_T bpIdx;

  /* Linear Search */
  found = 0U;
  bpIdx = startIndex;
  while (found == 0U) {
    if (u < bp[bpIdx]) {
      bpIdx = bpIdx - 1U;
    } else if (u < bp[bpIdx + 1U]) {
      found = 1U;
    } else {
      bpIdx = bpIdx + 1U;
    }
  }

  bpIndex = bpIdx;
  return bpIndex;
}

/* Output and update for action system:
 *   '<S43>/tiltcam'
 *   '<S628>/tiltcam'
 *   '<S736>/tiltcam'
 *   '<S797>/tiltcam'
 */
void claw_main_tiltcam(const real_T rtu_att[3], real_T rty_0[9],
  rtP_tiltcam_claw_main *localP)
{
  {
    real_T rtb_TrigonometricFunction3_n;
    real_T rtb_TrigonometricFunction1_g;
    real_T rtb_TrigonometricFunction_gc;
    real_T rtb_TrigonometricFunction2_c;
    real_T rtb_TrigonometricFunction4_fc;
    real_T rtb_Product2_hq;
    real_T rtb_TrigonometricFunction5_m;
    real_T rtb_Product9_ap;
    real_T rtb_Product4_nn;
    real_T rtb_Product7_g;
    real_T rtb_TrigonometricFunction3_n_0[9];
    int32_T tmp;
    int32_T tmp_0;
    real_T rtb_Gain_mt_idx;
    real_T rtb_Gain_mt_idx_0;
    real_T rtb_Gain_mt_idx_1;

    /* Gain: '<S53>/Gain' */
    rtb_Gain_mt_idx_1 = localP->Gain_Gain * rtu_att[0];
    rtb_Gain_mt_idx = localP->Gain_Gain * rtu_att[1];
    rtb_Gain_mt_idx_0 = localP->Gain_Gain * rtu_att[2];

    /* Trigonometry: '<S55>/Trigonometric Function3' */
    rtb_TrigonometricFunction3_n = cos(rtb_Gain_mt_idx);

    /* Trigonometry: '<S55>/Trigonometric Function1' */
    rtb_TrigonometricFunction1_g = cos(rtb_Gain_mt_idx_0);

    /* Trigonometry: '<S55>/Trigonometric Function' */
    rtb_TrigonometricFunction_gc = sin(rtb_Gain_mt_idx_0);

    /* Trigonometry: '<S55>/Trigonometric Function2' */
    rtb_TrigonometricFunction2_c = sin(rtb_Gain_mt_idx);

    /* Trigonometry: '<S55>/Trigonometric Function4' */
    rtb_TrigonometricFunction4_fc = sin(rtb_Gain_mt_idx_1);

    /* Product: '<S55>/Product2' */
    rtb_Product2_hq = rtb_TrigonometricFunction4_fc *
      rtb_TrigonometricFunction1_g;

    /* Trigonometry: '<S55>/Trigonometric Function5' */
    rtb_TrigonometricFunction5_m = cos(rtb_Gain_mt_idx_1);

    /* Product: '<S55>/Product9' */
    rtb_Product9_ap = rtb_TrigonometricFunction5_m *
      rtb_TrigonometricFunction_gc;

    /* Product: '<S55>/Product4' */
    rtb_Product4_nn = rtb_TrigonometricFunction4_fc *
      rtb_TrigonometricFunction_gc;

    /* Product: '<S55>/Product7' */
    rtb_Product7_g = rtb_TrigonometricFunction5_m * rtb_TrigonometricFunction1_g;

    /* Reshape: '<S52>/Reshape1' incorporates:
     *  Gain: '<S52>/Gain'
     *  Gain: '<S55>/Gain'
     *  Product: '<S55>/Product'
     *  Product: '<S55>/Product1'
     *  Product: '<S55>/Product10'
     *  Product: '<S55>/Product11'
     *  Product: '<S55>/Product3'
     *  Product: '<S55>/Product5'
     *  Product: '<S55>/Product6'
     *  Product: '<S55>/Product8'
     *  Reshape: '<S52>/Reshape'
     *  Sum: '<S55>/Sum'
     *  Sum: '<S55>/Sum1'
     *  Sum: '<S55>/Sum2'
     *  Sum: '<S55>/Sum3'
     */
    rtb_TrigonometricFunction3_n_0[0] = rtb_TrigonometricFunction3_n *
      rtb_TrigonometricFunction1_g;
    rtb_TrigonometricFunction3_n_0[1] = rtb_TrigonometricFunction3_n *
      rtb_TrigonometricFunction_gc;
    rtb_TrigonometricFunction3_n_0[2] = localP->Gain_Gain_f *
      rtb_TrigonometricFunction2_c;
    rtb_TrigonometricFunction3_n_0[3] = rtb_TrigonometricFunction2_c *
      rtb_Product2_hq - rtb_Product9_ap;
    rtb_TrigonometricFunction3_n_0[4] = rtb_TrigonometricFunction2_c *
      rtb_Product4_nn + rtb_Product7_g;
    rtb_TrigonometricFunction3_n_0[5] = rtb_TrigonometricFunction3_n *
      rtb_TrigonometricFunction4_fc;
    rtb_TrigonometricFunction3_n_0[6] = rtb_TrigonometricFunction2_c *
      rtb_Product7_g + rtb_Product4_nn;
    rtb_TrigonometricFunction3_n_0[7] = rtb_TrigonometricFunction2_c *
      rtb_Product9_ap - rtb_Product2_hq;
    rtb_TrigonometricFunction3_n_0[8] = rtb_TrigonometricFunction3_n *
      rtb_TrigonometricFunction5_m;
    for (tmp = 0; tmp < 3; tmp++) {
      for (tmp_0 = 0; tmp_0 < 3; tmp_0++) {
        rty_0[tmp + 3 * tmp_0] = 0.0;
        rty_0[tmp + 3 * tmp_0] = rty_0[3 * tmp_0 + tmp] +
          rtb_TrigonometricFunction3_n_0[3 * tmp_0] * localP->Gain_Gain_n[tmp];
        rty_0[tmp + 3 * tmp_0] = rtb_TrigonometricFunction3_n_0[3 * tmp_0 + 1] *
          localP->Gain_Gain_n[tmp + 3] + rty_0[3 * tmp_0 + tmp];
        rty_0[tmp + 3 * tmp_0] = rtb_TrigonometricFunction3_n_0[3 * tmp_0 + 2] *
          localP->Gain_Gain_n[tmp + 6] + rty_0[3 * tmp_0 + tmp];
      }
    }
  }
}

/* Output and update for action system:
 *   '<S43>/ypr'
 *   '<S628>/ypr'
 *   '<S736>/ypr'
 *   '<S797>/ypr'
 */
void claw_main_ypr(const real_T rtu_att[3], real_T rty_0[9], rtP_ypr_claw_main
                   *localP)
{
  {
    real_T rtb_TrigonometricFunction3_h;
    real_T rtb_TrigonometricFunction5_a;
    real_T rtb_TrigonometricFunction2_l;
    real_T rtb_TrigonometricFunction_f;
    real_T rtb_Product9_di;
    real_T rtb_TrigonometricFunction4_oi;
    real_T rtb_TrigonometricFunction1_l;
    real_T rtb_Product2_ki;
    real_T rtb_Product7_hf;
    real_T rtb_Product4_ef;
    real_T rtb_TrigonometricFunction3_h_0[9];
    int32_T tmp;
    int32_T tmp_0;
    real_T rtb_Gain_bt_idx;
    real_T rtb_Gain_bt_idx_0;
    real_T rtb_Gain_bt_idx_1;

    /* Gain: '<S57>/Gain' */
    rtb_Gain_bt_idx_1 = localP->Gain_Gain * rtu_att[0];
    rtb_Gain_bt_idx = localP->Gain_Gain * rtu_att[1];
    rtb_Gain_bt_idx_0 = localP->Gain_Gain * rtu_att[2];

    /* Trigonometry: '<S59>/Trigonometric Function3' */
    rtb_TrigonometricFunction3_h = cos(rtb_Gain_bt_idx);

    /* Trigonometry: '<S59>/Trigonometric Function5' */
    rtb_TrigonometricFunction5_a = cos(rtb_Gain_bt_idx_0);

    /* Trigonometry: '<S59>/Trigonometric Function2' */
    rtb_TrigonometricFunction2_l = sin(rtb_Gain_bt_idx);

    /* Trigonometry: '<S59>/Trigonometric Function' */
    rtb_TrigonometricFunction_f = sin(rtb_Gain_bt_idx_1);

    /* Product: '<S59>/Product9' */
    rtb_Product9_di = rtb_TrigonometricFunction5_a * rtb_TrigonometricFunction_f;

    /* Trigonometry: '<S59>/Trigonometric Function4' */
    rtb_TrigonometricFunction4_oi = sin(rtb_Gain_bt_idx_0);

    /* Trigonometry: '<S59>/Trigonometric Function1' */
    rtb_TrigonometricFunction1_l = cos(rtb_Gain_bt_idx_1);

    /* Product: '<S59>/Product2' */
    rtb_Product2_ki = rtb_TrigonometricFunction4_oi *
      rtb_TrigonometricFunction1_l;

    /* Product: '<S59>/Product7' */
    rtb_Product7_hf = rtb_TrigonometricFunction5_a *
      rtb_TrigonometricFunction1_l;

    /* Product: '<S59>/Product4' */
    rtb_Product4_ef = rtb_TrigonometricFunction4_oi *
      rtb_TrigonometricFunction_f;

    /* Reshape: '<S56>/Reshape1' incorporates:
     *  Gain: '<S56>/Gain'
     *  Gain: '<S59>/Gain'
     *  Product: '<S59>/Product'
     *  Product: '<S59>/Product1'
     *  Product: '<S59>/Product10'
     *  Product: '<S59>/Product11'
     *  Product: '<S59>/Product3'
     *  Product: '<S59>/Product5'
     *  Product: '<S59>/Product6'
     *  Product: '<S59>/Product8'
     *  Reshape: '<S56>/Reshape'
     *  Sum: '<S59>/Sum'
     *  Sum: '<S59>/Sum1'
     *  Sum: '<S59>/Sum2'
     *  Sum: '<S59>/Sum3'
     */
    rtb_TrigonometricFunction3_h_0[0] = rtb_TrigonometricFunction3_h *
      rtb_TrigonometricFunction5_a;
    rtb_TrigonometricFunction3_h_0[1] = rtb_TrigonometricFunction2_l *
      rtb_Product9_di - rtb_Product2_ki;
    rtb_TrigonometricFunction3_h_0[2] = rtb_TrigonometricFunction2_l *
      rtb_Product7_hf + rtb_Product4_ef;
    rtb_TrigonometricFunction3_h_0[3] = rtb_TrigonometricFunction3_h *
      rtb_TrigonometricFunction4_oi;
    rtb_TrigonometricFunction3_h_0[4] = rtb_TrigonometricFunction2_l *
      rtb_Product4_ef + rtb_Product7_hf;
    rtb_TrigonometricFunction3_h_0[5] = rtb_TrigonometricFunction2_l *
      rtb_Product2_ki - rtb_Product9_di;
    rtb_TrigonometricFunction3_h_0[6] = localP->Gain_Gain_k *
      rtb_TrigonometricFunction2_l;
    rtb_TrigonometricFunction3_h_0[7] = rtb_TrigonometricFunction3_h *
      rtb_TrigonometricFunction_f;
    rtb_TrigonometricFunction3_h_0[8] = rtb_TrigonometricFunction3_h *
      rtb_TrigonometricFunction1_l;
    for (tmp = 0; tmp < 3; tmp++) {
      for (tmp_0 = 0; tmp_0 < 3; tmp_0++) {
        rty_0[tmp + 3 * tmp_0] = 0.0;
        rty_0[tmp + 3 * tmp_0] = rty_0[3 * tmp_0 + tmp] +
          rtb_TrigonometricFunction3_h_0[3 * tmp_0] * localP->Gain_Gain_l[tmp];
        rty_0[tmp + 3 * tmp_0] = rtb_TrigonometricFunction3_h_0[3 * tmp_0 + 1] *
          localP->Gain_Gain_l[tmp + 3] + rty_0[3 * tmp_0 + tmp];
        rty_0[tmp + 3 * tmp_0] = rtb_TrigonometricFunction3_h_0[3 * tmp_0 + 2] *
          localP->Gain_Gain_l[tmp + 6] + rty_0[3 * tmp_0 + tmp];
      }
    }
  }
}

/* Output and update for action system:
 *   '<S43>/mba'
 *   '<S628>/mba'
 *   '<S736>/mba'
 *   '<S797>/mba'
 */
void claw_main_mba(const real_T rtu_att[3], real_T rtu_1, real_T rtu_2, real_T
                   rtu_3, real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                   real_T rtu_8, real_T rtu_9, real_T rty_0[9],
                   rtP_mba_claw_main *localP)
{
  {
    real_T rtb_TrigonometricFunction3_kq;
    real_T rtb_TrigonometricFunction1_k;
    real_T rtb_TrigonometricFunction2_at;
    real_T rtb_TrigonometricFunction_e;
    real_T rtb_TrigonometricFunction5_g;
    real_T rtb_Product7_i;
    real_T rtb_TrigonometricFunction4_n;
    real_T rtb_Product4_o5;
    real_T rtb_Product9_m;
    real_T rtb_Product2_kl;
    real_T rtb_TrigonometricFunction3_kq_0[9];
    real_T tmp[9];
    int32_T tmp_0;
    int32_T tmp_1;
    real_T rtb_Gain_ch_idx;
    real_T rtb_Gain_ch_idx_0;
    real_T rtb_Gain_ch_idx_1;

    /* Gain: '<S49>/Gain' incorporates:
     *  Gain: '<S48>/Gain1'
     */
    rtb_Gain_ch_idx_1 = localP->Gain1_Gain[0] * rtu_att[0] * localP->Gain_Gain;
    rtb_Gain_ch_idx_0 = localP->Gain1_Gain[1] * rtu_att[1] * localP->Gain_Gain;
    rtb_Gain_ch_idx = localP->Gain1_Gain[2] * rtu_att[2] * localP->Gain_Gain;

    /* Trigonometry: '<S51>/Trigonometric Function3' */
    rtb_TrigonometricFunction3_kq = cos(rtb_Gain_ch_idx);

    /* Trigonometry: '<S51>/Trigonometric Function1' */
    rtb_TrigonometricFunction1_k = cos(rtb_Gain_ch_idx_0);

    /* Trigonometry: '<S51>/Trigonometric Function2' */
    rtb_TrigonometricFunction2_at = sin(rtb_Gain_ch_idx);

    /* Trigonometry: '<S51>/Trigonometric Function' */
    rtb_TrigonometricFunction_e = sin(rtb_Gain_ch_idx_0);

    /* Trigonometry: '<S51>/Trigonometric Function5' */
    rtb_TrigonometricFunction5_g = cos(rtb_Gain_ch_idx_1);

    /* Product: '<S51>/Product7' */
    rtb_Product7_i = rtb_TrigonometricFunction5_g * rtb_TrigonometricFunction1_k;

    /* Trigonometry: '<S51>/Trigonometric Function4' */
    rtb_TrigonometricFunction4_n = sin(rtb_Gain_ch_idx_1);

    /* Product: '<S51>/Product4' */
    rtb_Product4_o5 = rtb_TrigonometricFunction4_n * rtb_TrigonometricFunction_e;

    /* Product: '<S51>/Product9' */
    rtb_Product9_m = rtb_TrigonometricFunction5_g * rtb_TrigonometricFunction_e;

    /* Product: '<S51>/Product2' */
    rtb_Product2_kl = rtb_TrigonometricFunction4_n *
      rtb_TrigonometricFunction1_k;

    /* Reshape: '<S48>/Reshape3' incorporates:
     *  Gain: '<S51>/Gain'
     *  Product: '<S48>/Product'
     *  Product: '<S51>/Product'
     *  Product: '<S51>/Product1'
     *  Product: '<S51>/Product10'
     *  Product: '<S51>/Product11'
     *  Product: '<S51>/Product3'
     *  Product: '<S51>/Product5'
     *  Product: '<S51>/Product6'
     *  Product: '<S51>/Product8'
     *  Reshape: '<S48>/Reshape1'
     *  Reshape: '<S48>/Reshape2'
     *  Sum: '<S51>/Sum'
     *  Sum: '<S51>/Sum1'
     *  Sum: '<S51>/Sum2'
     *  Sum: '<S51>/Sum3'
     */
    rtb_TrigonometricFunction3_kq_0[0] = rtb_TrigonometricFunction3_kq *
      rtb_TrigonometricFunction1_k;
    rtb_TrigonometricFunction3_kq_0[1] = localP->Gain_Gain_j *
      rtb_TrigonometricFunction2_at;
    rtb_TrigonometricFunction3_kq_0[2] = rtb_TrigonometricFunction3_kq *
      rtb_TrigonometricFunction_e;
    rtb_TrigonometricFunction3_kq_0[3] = rtb_TrigonometricFunction2_at *
      rtb_Product7_i + rtb_Product4_o5;
    rtb_TrigonometricFunction3_kq_0[4] = rtb_TrigonometricFunction3_kq *
      rtb_TrigonometricFunction5_g;
    rtb_TrigonometricFunction3_kq_0[5] = rtb_TrigonometricFunction2_at *
      rtb_Product9_m - rtb_Product2_kl;
    rtb_TrigonometricFunction3_kq_0[6] = rtb_TrigonometricFunction2_at *
      rtb_Product2_kl - rtb_Product9_m;
    rtb_TrigonometricFunction3_kq_0[7] = rtb_TrigonometricFunction3_kq *
      rtb_TrigonometricFunction4_n;
    rtb_TrigonometricFunction3_kq_0[8] = rtb_TrigonometricFunction2_at *
      rtb_Product4_o5 + rtb_Product7_i;
    tmp[0] = rtu_1;
    tmp[1] = rtu_2;
    tmp[2] = rtu_3;
    tmp[3] = rtu_4;
    tmp[4] = rtu_5;
    tmp[5] = rtu_6;
    tmp[6] = rtu_7;
    tmp[7] = rtu_8;
    tmp[8] = rtu_9;
    for (tmp_0 = 0; tmp_0 < 3; tmp_0++) {
      for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
        rty_0[tmp_0 + 3 * tmp_1] = 0.0;
        rty_0[tmp_0 + 3 * tmp_1] = rty_0[3 * tmp_1 + tmp_0] + tmp[3 * tmp_1] *
          rtb_TrigonometricFunction3_kq_0[tmp_0];
        rty_0[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 1] *
          rtb_TrigonometricFunction3_kq_0[tmp_0 + 3] + rty_0[3 * tmp_1 + tmp_0];
        rty_0[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 2] *
          rtb_TrigonometricFunction3_kq_0[tmp_0 + 6] + rty_0[3 * tmp_1 + tmp_0];
      }
    }
  }
}

/* Output and update for action system:
 *   '<S61>/tiltcam'
 *   '<S103>/tiltcam'
 *   '<S769>/tiltcam'
 *   '<S817>/tiltcam'
 */
void claw_main_tiltcam_b(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
  real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7, real_T rtu_8, real_T
  rty_0[3], rtP_tiltcam_claw_main_n *localP)
{
  {
    real_T rtb_Gain_n4[9];
    real_T tmp[9];
    int32_T tmp_0;
    int32_T tmp_1;

    /* Gain: '<S70>/Gain' incorporates:
     *  Reshape: '<S70>/Reshape'
     */
    tmp[0] = rtu_0;
    tmp[1] = rtu_1;
    tmp[2] = rtu_2;
    tmp[3] = rtu_3;
    tmp[4] = rtu_4;
    tmp[5] = rtu_5;
    tmp[6] = rtu_6;
    tmp[7] = rtu_7;
    tmp[8] = rtu_8;
    for (tmp_0 = 0; tmp_0 < 3; tmp_0++) {
      for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
        rtb_Gain_n4[tmp_0 + 3 * tmp_1] = 0.0;
        rtb_Gain_n4[tmp_0 + 3 * tmp_1] = rtb_Gain_n4[3 * tmp_1 + tmp_0] + tmp[3 *
          tmp_1] * localP->Gain_Gain[tmp_0];
        rtb_Gain_n4[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 1] * localP->
          Gain_Gain[tmp_0 + 3] + rtb_Gain_n4[3 * tmp_1 + tmp_0];
        rtb_Gain_n4[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 2] * localP->
          Gain_Gain[tmp_0 + 6] + rtb_Gain_n4[3 * tmp_1 + tmp_0];
      }
    }

    /* Gain: '<S71>/Gain' incorporates:
     *  Gain: '<S72>/Gain'
     *  Math: '<S72>/Math Function1'
     *  Reshape: '<S70>/Reshape1'
     *  Trigonometry: '<S72>/Trigonometric Function1'
     *  Trigonometry: '<S72>/Trigonometric Function2'
     *  Trigonometry: '<S72>/Trigonometric Function3'
     */
    rty_0[0] = localP->Gain_Gain_f * rt_atan2_snf(rtb_Gain_n4[5], rtb_Gain_n4[8]);
    rty_0[1] = rt_atan2_snf(localP->Gain_Gain_h * rtb_Gain_n4[2], rt_hypot_snf
      (rtb_Gain_n4[8], rtb_Gain_n4[5])) * localP->Gain_Gain_f;
    rty_0[2] = localP->Gain_Gain_f * rt_atan2_snf(rtb_Gain_n4[1], rtb_Gain_n4[0]);
  }
}

/* Output and update for action system:
 *   '<S61>/ypr'
 *   '<S103>/ypr'
 *   '<S769>/ypr'
 *   '<S817>/ypr'
 */
void claw_main_ypr_c(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
                     real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                     real_T rtu_8, real_T rty_0[3], rtP_ypr_claw_main_p *localP)
{
  {
    real_T rtb_Gain_mz[9];
    real_T tmp[9];
    int32_T tmp_0;
    int32_T tmp_1;

    /* Gain: '<S74>/Gain' incorporates:
     *  Reshape: '<S74>/Reshape'
     */
    tmp[0] = rtu_0;
    tmp[1] = rtu_1;
    tmp[2] = rtu_2;
    tmp[3] = rtu_3;
    tmp[4] = rtu_4;
    tmp[5] = rtu_5;
    tmp[6] = rtu_6;
    tmp[7] = rtu_7;
    tmp[8] = rtu_8;
    for (tmp_0 = 0; tmp_0 < 3; tmp_0++) {
      for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
        rtb_Gain_mz[tmp_0 + 3 * tmp_1] = 0.0;
        rtb_Gain_mz[tmp_0 + 3 * tmp_1] = rtb_Gain_mz[3 * tmp_1 + tmp_0] + tmp[3 *
          tmp_1] * localP->Gain_Gain[tmp_0];
        rtb_Gain_mz[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 1] * localP->
          Gain_Gain[tmp_0 + 3] + rtb_Gain_mz[3 * tmp_1 + tmp_0];
        rtb_Gain_mz[tmp_0 + 3 * tmp_1] = tmp[3 * tmp_1 + 2] * localP->
          Gain_Gain[tmp_0 + 6] + rtb_Gain_mz[3 * tmp_1 + tmp_0];
      }
    }

    /* Gain: '<S75>/Gain' incorporates:
     *  Gain: '<S76>/Gain'
     *  Math: '<S76>/Math Function1'
     *  Reshape: '<S74>/Reshape1'
     *  Trigonometry: '<S76>/Trigonometric Function1'
     *  Trigonometry: '<S76>/Trigonometric Function2'
     *  Trigonometry: '<S76>/Trigonometric Function3'
     */
    rty_0[0] = localP->Gain_Gain_b * rt_atan2_snf(rtb_Gain_mz[7], rtb_Gain_mz[8]);
    rty_0[1] = rt_atan2_snf(localP->Gain_Gain_k * rtb_Gain_mz[6], rt_hypot_snf
      (rtb_Gain_mz[0], rtb_Gain_mz[3])) * localP->Gain_Gain_b;
    rty_0[2] = localP->Gain_Gain_b * rt_atan2_snf(rtb_Gain_mz[3], rtb_Gain_mz[0]);
  }
}

/* Output and update for action system:
 *   '<S61>/mba'
 *   '<S103>/mba'
 *   '<S769>/mba'
 *   '<S817>/mba'
 */
void claw_main_mba_h(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T rtu_3,
                     real_T rtu_4, real_T rtu_5, real_T rtu_6, real_T rtu_7,
                     real_T rtu_8, real_T rtu_9, real_T rtu_10, real_T rtu_11,
                     real_T rtu_12, real_T rtu_13, real_T rtu_14, real_T rtu_15,
                     real_T rtu_16, real_T rtu_17, real_T rty_0[3],
                     rtP_mba_claw_main_a *localP)
{
  {
    real_T rtb_Product_hz1[9];
    real_T tmp[9];
    real_T tmp_0[9];
    int32_T tmp_1;
    int32_T tmp_2;

    /* Product: '<S66>/Product' incorporates:
     *  Math: '<S66>/Math Function'
     *  Reshape: '<S66>/Reshape2'
     *  Reshape: '<S66>/Reshape3'
     */
    tmp[0] = rtu_0;
    tmp[1] = rtu_1;
    tmp[2] = rtu_2;
    tmp[3] = rtu_3;
    tmp[4] = rtu_4;
    tmp[5] = rtu_5;
    tmp[6] = rtu_6;
    tmp[7] = rtu_7;
    tmp[8] = rtu_8;
    tmp_0[0] = rtu_9;
    tmp_0[1] = rtu_10;
    tmp_0[2] = rtu_11;
    tmp_0[3] = rtu_12;
    tmp_0[4] = rtu_13;
    tmp_0[5] = rtu_14;
    tmp_0[6] = rtu_15;
    tmp_0[7] = rtu_16;
    tmp_0[8] = rtu_17;
    for (tmp_1 = 0; tmp_1 < 3; tmp_1++) {
      for (tmp_2 = 0; tmp_2 < 3; tmp_2++) {
        rtb_Product_hz1[tmp_1 + 3 * tmp_2] = 0.0;
        rtb_Product_hz1[tmp_1 + 3 * tmp_2] = rtb_Product_hz1[3 * tmp_2 + tmp_1]
          + tmp[tmp_1] * tmp_0[tmp_2];
        rtb_Product_hz1[tmp_1 + 3 * tmp_2] = rtb_Product_hz1[3 * tmp_2 + tmp_1]
          + tmp[tmp_1 + 3] * tmp_0[tmp_2 + 3];
        rtb_Product_hz1[tmp_1 + 3 * tmp_2] = rtb_Product_hz1[3 * tmp_2 + tmp_1]
          + tmp[tmp_1 + 6] * tmp_0[tmp_2 + 6];
      }
    }

    /* Gain: '<S66>/Gain1' incorporates:
     *  Gain: '<S67>/Gain'
     *  Gain: '<S68>/Gain'
     *  Math: '<S68>/Math Function1'
     *  Reshape: '<S66>/Reshape1'
     *  Trigonometry: '<S68>/Trigonometric Function1'
     *  Trigonometry: '<S68>/Trigonometric Function2'
     *  Trigonometry: '<S68>/Trigonometric Function3'
     */
    rty_0[0] = localP->Gain_Gain_e * rt_atan2_snf(rtb_Product_hz1[7],
      rtb_Product_hz1[4]) * localP->Gain1_Gain[0];
    rty_0[1] = localP->Gain_Gain_e * rt_atan2_snf(rtb_Product_hz1[2],
      rtb_Product_hz1[0]) * localP->Gain1_Gain[1];
    rty_0[2] = rt_atan2_snf(localP->Gain_Gain * rtb_Product_hz1[1], rt_hypot_snf
                            (rtb_Product_hz1[4], rtb_Product_hz1[7])) *
      localP->Gain_Gain_e * localP->Gain1_Gain[2];
  }
}

/* Output and update for atomic system:
 *   '<S227>/Embedded MATLAB Function'
 *   '<S228>/Embedded MATLAB Function'
 *   '<S229>/Embedded MATLAB Function'
 *   '<S355>/Embedded MATLAB Function'
 *   '<S356>/Embedded MATLAB Function'
 *   '<S357>/Embedded MATLAB Function'
 *   '<S453>/Embedded MATLAB Function'
 *   '<S454>/Embedded MATLAB Function'
 *   '<S455>/Embedded MATLAB Function'
 *   '<S561>/Embedded MATLAB Function'
 *   ...
 */
void claw_mai_EmbeddedMATLABFunction(real_T rtu_u,
  rtB_EmbeddedMATLABFunction_claw *localB, rtP_EmbeddedMATLABFunction_claw
  *localP)
{
  /* Embedded MATLAB: '<S227>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'Polyval/Embedded MATLAB Function': '<S230>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /* '<S230>:1:6' */
  localB->y = localP->SFunction_p1[0] * rt_pow_snf(rtu_u, 2.0);
  localB->y = localP->SFunction_p1[1] * rt_pow_snf(rtu_u, 1.0) + localB->y;
  localB->y = localP->SFunction_p1[2] * rt_pow_snf(rtu_u, 0.0) + localB->y;
}

/* Output and update for atomic system:
 *   '<S221>/fuel cg shift, cg_pos0'
 *   '<S349>/fuel cg shift, cg_pos0'
 *   '<S447>/fuel cg shift, cg_pos0'
 *   '<S555>/fuel cg shift, cg_pos0'
 *   '<S663>/fuel cg shift, cg_pos0'
 */
void claw_main_fuelcgshiftcg_pos0(real_T rtu_fuel_used,
  rtB_fuelcgshiftcg_pos0_claw_mai *localB, rtP_fuelcgshiftcg_pos0_claw_mai
  *localP)
{
  {
    real_T eml_varargin;
    real_T eml_extremum;

    /* Embedded MATLAB: '<S221>/fuel cg shift, cg_pos0' */
    /* Embedded MATLAB Function 'gtm-aero/A/C parameters/Inertia/Mass/CG Shift/fuel cg shift, cg_pos0': '<S226>:1' */
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    /* '<S226>:1:5' */
    eml_varargin = rtu_fuel_used - localP->SFunction_p4;
    if ((0.0 >= eml_varargin) || rtIsNaN(eml_varargin)) {
      eml_varargin = 0.0;
    }

    if ((!(localP->SFunction_p1 <= rtu_fuel_used)) && (!rtIsNaN(rtu_fuel_used)))
    {
      eml_extremum = rtu_fuel_used;
    } else {
      eml_extremum = localP->SFunction_p1;
    }

    localB->y[0] = (localP->SFunction_p6 * localP->SFunction_p3[0] -
                    eml_extremum * localP->SFunction_p2[0]) - eml_varargin *
      localP->SFunction_p5[0];
    localB->y[1] = (localP->SFunction_p6 * localP->SFunction_p3[1] -
                    eml_extremum * localP->SFunction_p2[1]) - eml_varargin *
      localP->SFunction_p5[1];
    localB->y[2] = (localP->SFunction_p6 * localP->SFunction_p3[2] -
                    eml_extremum * localP->SFunction_p2[2]) - eml_varargin *
      localP->SFunction_p5[2];
  }
}

/* Start for action system:
 *   '<S238>/Switch Case Action Subsystem'
 *   '<S366>/Switch Case Action Subsystem'
 *   '<S464>/Switch Case Action Subsystem'
 *   '<S572>/Switch Case Action Subsystem'
 *   '<S680>/Switch Case Action Subsystem'
 */
void SwitchCaseActionSubsystem_Start(real_T rty_0[6],
  rtP_SwitchCaseActionSubsystem_c *localP)
{
  {
    int32_T i;

    /* VirtualOutportStart for Outport: '<S239>/dC6_dam' */
    for (i = 0; i < 6; i++) {
      rty_0[i] = localP->dC6_dam_Y0[i];
    }
  }
}

/* Output and update for action system:
 *   '<S238>/Switch Case Action Subsystem'
 *   '<S366>/Switch Case Action Subsystem'
 *   '<S464>/Switch Case Action Subsystem'
 *   '<S572>/Switch Case Action Subsystem'
 *   '<S680>/Switch Case Action Subsystem'
 */
void claw__SwitchCaseActionSubsystem(real_T rtu_alpha, real_T rtu_beta, uint32_T
  rtu_damage_case, real_T rty_0[6], rtDW_SwitchCaseActionSubsystem_ *localDW,
  rtP_SwitchCaseActionSubsystem_c *localP)
{
  {
    real_T rtb_AlphaLookup_o2_p;
    real_T fractionTmp_0d;
    real_T frac[2];
    real_T rtb_BetaLookup_o2;
    uint32_T rtb_AlphaLookup_o1_o;
    uint32_T bpIndex[4];
    uint32_T rtb_BetaLookup_o1;
    uint32_T rtb_Subtract;
    uint32_T indexTmp_2d;
    int32_T idx;

    /* PreLookup: '<S239>/AlphaLookup' */
    rtb_AlphaLookup_o1_o = plook_binxp(rtu_alpha,
      &localP->AlphaLookup_BreakpointsData[0], 17U, &rtb_AlphaLookup_o2_p,
      &localDW->AlphaLookup_DWORK1);

    /* PreLookup: '<S239>/BetaLookup' */
    rtb_BetaLookup_o1 = plook_binx(rtu_beta, &localP->
      BetaLookup_BreakpointsData[0], 12U, &rtb_BetaLookup_o2);

    /* Sum: '<S239>/Subtract' incorporates:
     *  Constant: '<S239>/Constant'
     */
    rtb_Subtract = rtu_damage_case - localP->Constant_Value;

    /* Interpolation_n-D: '<S239>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S239>/Constant4'
     */
    fractionTmp_0d = rtb_AlphaLookup_o2_p;
    if (fractionTmp_0d < 0.0) {
      fractionTmp_0d = 0.0;
    } else {
      if (fractionTmp_0d > 1.0) {
        fractionTmp_0d = 1.0;
      }
    }

    frac[0] = fractionTmp_0d;
    fractionTmp_0d = rtb_BetaLookup_o2;
    if (fractionTmp_0d < 0.0) {
      fractionTmp_0d = 0.0;
    } else {
      if (fractionTmp_0d > 1.0) {
        fractionTmp_0d = 1.0;
      }
    }

    frac[1] = fractionTmp_0d;
    bpIndex[0] = rtb_AlphaLookup_o1_o;
    bpIndex[1] = rtb_BetaLookup_o1;
    indexTmp_2d = rtb_Subtract;
    if (rtb_Subtract > 5U) {
      indexTmp_2d = 5U;
    }

    bpIndex[2] = indexTmp_2d;
    for (idx = 0; idx < 6; idx++) {
      indexTmp_2d = localP->Constant4_Value[idx];
      if (localP->Constant4_Value[idx] > 5U) {
        indexTmp_2d = 5U;
      }

      bpIndex[3] = indexTmp_2d;
      indexTmp_2d = 1404U * bpIndex[3U] + 234U * bpIndex[2U];
      rty_0[idx] = intrp2d_lc(&bpIndex[0U], &frac[0U],
        &localP->InterpolationUsingPrelookup_Tab[indexTmp_2d], 18U);
    }
  }
}

/* Output and update for atomic system:
 *   '<S246>/Implement Damage Models'
 *   '<S374>/Implement Damage Models'
 *   '<S472>/Implement Damage Models'
 *   '<S580>/Implement Damage Models'
 *   '<S688>/Implement Damage Models'
 */
void claw_main_ImplementDamageModels(const real_T rtu_0[6], const real_T rtu_1[6],
  const real_T rtu_2[6], const real_T rtu_3[6], const real_T rtu_4[6], const
  real_T rtu_5[6], const real_T rtu_6[6], const real_T rtu_7[6], const real_T
  rtu_8[6], const real_T rtu_9[6], const real_T rtu_10[6], const real_T rtu_11[6],
  const real_T rtu_12[6], const real_T rtu_13[6], const real_T rtu_14[6], const
  real_T rtu_15[6], const real_T rtu_16[6], const real_T rtu_17[6], real_T
  rtu_DamageCase, rtB_ImplementDamageModels_claw_ *localB)
{
  {
    int8_T eml_gain[108];
    real_T eml_y[108];
    int8_T eml_a[108];
    real_T eml_x;
    real_T rtb_TmpHiddenBufferAtSFunctionI[108];
    int32_T i;
    int32_T hoistedExpr;
    int32_T hoistedExpr_0;
    real_T eml_y_0[108];
    uint32_T tmp;
    static int8_T tmp_0[648] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
      1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
      0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
      1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0,
      0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
      0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1 };

    /* SignalConversion: '<S259>/TmpHiddenBufferAt SFunction Inport1' */
    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i] = rtu_0[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 6] = rtu_1[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 12] = rtu_2[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 18] = rtu_3[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 24] = rtu_4[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 30] = rtu_5[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 36] = rtu_6[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 42] = rtu_7[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 48] = rtu_8[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 54] = rtu_9[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 60] = rtu_10[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 66] = rtu_11[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 72] = rtu_12[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 78] = rtu_13[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 84] = rtu_14[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 90] = rtu_15[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 96] = rtu_16[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtSFunctionI[i + 102] = rtu_17[i];
    }

    /* Embedded MATLAB: '<S246>/Implement Damage Models' */
    /* Embedded MATLAB Function 'Control Surfaces/Implement Damage Models/Implement Damage Models': '<S259>:1' */
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    /* '<S259>:1:4' */
    if (rtu_DamageCase < 0.0) {
      eml_x = ceil(rtu_DamageCase - 0.5);
    } else {
      eml_x = floor(rtu_DamageCase + 0.5);
    }

    eml_x = eml_x < 0.0 ? ceil(eml_x - 0.5) : floor(eml_x + 0.5);
    if (eml_x < 4.294967296E+009) {
      if (eml_x >= 0.0) {
        tmp = (uint32_T)eml_x;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint32_T;
    }

    if (tmp == 0U) {
      /* '<S259>:1:6' */
      /* '<S259>:1:7' */
      memcpy((void *)&eml_y[0], (void *)&rtb_TmpHiddenBufferAtSFunctionI[0],
             108U * (uint32_T)((char_T *)&rtb_TmpHiddenBufferAtSFunctionI[1U] -
              (char_T *)&rtb_TmpHiddenBufferAtSFunctionI[0U]));
      for (i = 0; i < 6; i++) {
        localB->dC6[i] = 0.0;
        for (hoistedExpr_0 = 0; hoistedExpr_0 < 18; hoistedExpr_0++) {
          localB->dC6[i] = eml_y[6 * hoistedExpr_0 + i] + localB->dC6[i];
        }
      }
    } else {
      /* '<S259>:1:9' */
      i = (int32_T)tmp - 1;
      for (hoistedExpr_0 = 0; hoistedExpr_0 < 6; hoistedExpr_0++) {
        for (hoistedExpr = 0; hoistedExpr < 18; hoistedExpr++) {
          eml_a[hoistedExpr + 18 * hoistedExpr_0] = tmp_0[(6 * hoistedExpr + i)
            + 108 * hoistedExpr_0];
        }
      }

      /* '<S259>:1:10' */
      for (i = 0; i < 108; i++) {
        eml_gain[i] = eml_a[i];
        eml_y[i] = rtb_TmpHiddenBufferAtSFunctionI[i];
      }

      for (i = 0; i < 6; i++) {
        for (hoistedExpr_0 = 0; hoistedExpr_0 < 18; hoistedExpr_0++) {
          eml_y_0[hoistedExpr_0 + 18 * i] = eml_y[6 * hoistedExpr_0 + i] *
            (real_T)eml_gain[18 * i + hoistedExpr_0];
        }
      }

      for (i = 0; i < 6; i++) {
        localB->dC6[i] = 0.0;
        for (hoistedExpr_0 = 0; hoistedExpr_0 < 18; hoistedExpr_0++) {
          localB->dC6[i] = eml_y_0[18 * i + hoistedExpr_0] + localB->dC6[i];
        }
      }
    }
  }
}

/* Output and update for action system:
 *   '<S236>/Forced Oscillation with Damage Increments'
 *   '<S570>/Forced Oscillation with Damage Increments'
 */
void ForcedOscillationwithDamageIncr(real_T rtu_alpha, uint32_T rtu_DamageCase,
  real_T rtu_TAS, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T
  rty_0[6], rtB_ForcedOscillationwithDamage *localB,
  rtDW_ForcedOscillationwithDamag *localDW, rtP_ForcedOscillationwithDamage
  *localP, uint8_T rtd_WhileIterator_IterationMark[7])
{
  {
    int32_T scalarPrevIndex;
    uint32_T locIndex;
    int32_T scalarIndex;
    real_T scalarFraction;
    int32_T indexTmp_0d;
    uint32_T rtb_Subtract2;
    int32_T scalarPrevIndex_0;
    real_T scalarFraction_0;
    real_T rtb_Gain_ow;
    int32_T scalarPrevIndex_1;
    real_T scalarFraction_1;
    real_T frac[2];
    uint32_T bpIndex[3];
    uint32_T idx;
    real_T rtb_p[6];
    real_T rtb_Product2_fh[6];
    uint32_T rtb_Subtract1;
    int32_T scalarPrevIndex_2;
    real_T scalarFraction_2;
    int32_T scalarPrevIndex_3;
    real_T scalarFraction_3;
    real_T frac_0[2];
    uint32_T bpIndex_0[3];
    real_T rtb_q[6];
    real_T rtb_Product1_ie[6];
    uint32_T rtb_Subtract_j;
    int32_T scalarPrevIndex_4;
    real_T scalarFraction_4;
    int32_T scalarPrevIndex_5;
    real_T scalarFraction_5;
    real_T frac_1[2];
    uint32_T bpIndex_1[3];
    real_T rtb_r[6];
    real_T rtb_Product3_l[6];
    int32_T scalarPrevIndex_6;
    real_T scalarFraction_6;
    uint32_T rtb_Subtract_n;
    real_T rtb_PreLookupIndexSearch2_idx;
    int32_T bpIndex_idx;
    real_T rtb_PreLookupIndexSearch_idx;
    real_T rtb_roll_idx;
    real_T rtb_roll_idx_0;

    /* S-Function (sfun_idxsearch): '<S273>/PreLookup Index Search' */
    scalarPrevIndex = localDW->PreLookupIndexSearch_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData[0], 17U, &scalarFraction,
      &scalarPrevIndex);
    rtb_PreLookupIndexSearch_idx = scalarFraction;

    /* Sum: '<S273>/Subtract2' incorporates:
     *  Constant: '<S273>/Constant5'
     */
    rtb_Subtract2 = rtu_DamageCase - localP->Constant5_Value_k;

    /* S-Function (sfun_kflookupnd): '<S273>/p' incorporates:
     *  Constant: '<S273>/Constant3'
     */
    rtb_roll_idx = rtb_PreLookupIndexSearch_idx;
    if (rtb_PreLookupIndexSearch_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract2 > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract2;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant3_Value[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant3_Value[locIndex];
      }

      rtb_p[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_idx,
        &localP->p_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search4' */
    scalarPrevIndex_0 = localDW->PreLookupIndexSearch4_MODE;
    indexTmp_0d = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch4_bpData[0], 23U, &scalarFraction_0,
      &scalarPrevIndex_0);
    rtb_roll_idx = scalarFraction_0;

    /* Gain: '<S275>/Gain' incorporates:
     *  Saturate: '<S275>/Saturation1'
     */
    rtb_Gain_ow = localP->Gain_Gain * rt_SATURATE(rtu_TAS,
      localP->Saturation1_LowerSat, localP->Saturation1_UpperSat);

    /* Product: '<S275>/Product3' */
    localB->Product3[0] = rtu_pqr[0] * rtu_4 / rtb_Gain_ow;
    localB->Product3[1] = rtu_pqr[1] * rtu_5 / rtb_Gain_ow;
    localB->Product3[2] = rtu_pqr[2] * rtu_4 / rtb_Gain_ow;

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search2' */
    scalarPrevIndex_1 = localDW->PreLookupIndexSearch2_MODE;
    bpIndex_idx = plook_s32dd_binxp(localB->Product3[0],
      &localP->PreLookupIndexSearch2_bpData[0], 14U, &scalarFraction_1,
      &scalarPrevIndex_1);
    rtb_PreLookupIndexSearch2_idx = scalarFraction_1;

    /* S-Function (sfun_kflookupnd): '<S274>/roll' incorporates:
     *  Constant: '<S274>/Constant2'
     */
    if (rtb_roll_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_roll_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac[0] = rtb_roll_idx;
    rtb_roll_idx = rtb_PreLookupIndexSearch2_idx;
    if (rtb_PreLookupIndexSearch2_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac[1] = rtb_roll_idx;
    if (indexTmp_0d > 22) {
      rtb_roll_idx = 22.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex[0] = (uint32_T)rtb_roll_idx;
    if (bpIndex_idx > 13) {
      rtb_roll_idx = 13.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex[1] = (uint32_T)rtb_roll_idx;
    if (localP->Constant2_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[0];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_PreLookupIndexSearch2_idx = intrp2d_lc(&bpIndex[0U], &frac[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[1];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_roll_idx = intrp2d_lc(&bpIndex[0U], &frac[0U], &localP->
      roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[2];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_roll_idx_0 = intrp2d_lc(&bpIndex[0U], &frac[0U], &localP->
      roll_tableData[locIndex], 24U);

    /* Assignment: '<S274>/Assignment to  Lateral' incorporates:
     *  Constant: '<S274>/Constant4'
     */
    if (rtd_WhileIterator_IterationMark[1] < 2) {
      rtd_WhileIterator_IterationMark[1] = 2U;
      for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
        localB->AssignmenttoLateral[bpIndex_idx] = localP->
          Constant4_Value[bpIndex_idx];
      }
    }

    localB->AssignmenttoLateral[1] = rtb_PreLookupIndexSearch2_idx;
    localB->AssignmenttoLateral[3] = rtb_roll_idx;
    localB->AssignmenttoLateral[5] = rtb_roll_idx_0;

    /* Product: '<S270>/Product2' */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_Product2_fh[bpIndex_idx] = rtb_p[bpIndex_idx] *
        localB->AssignmenttoLateral[bpIndex_idx];
    }

    /* Sum: '<S273>/Subtract1' incorporates:
     *  Constant: '<S273>/Constant4'
     */
    rtb_Subtract1 = rtu_DamageCase - localP->Constant4_Value_c;

    /* S-Function (sfun_kflookupnd): '<S273>/q' incorporates:
     *  Constant: '<S273>/Constant2'
     */
    rtb_roll_idx = rtb_PreLookupIndexSearch_idx;
    if (rtb_PreLookupIndexSearch_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract1 > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract1;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant2_Value_c[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant2_Value_c[locIndex];
      }

      rtb_q[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_idx,
        &localP->q_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search' */
    scalarPrevIndex_2 = localDW->PreLookupIndexSearch_MODE_m;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_g[0], 23U, &scalarFraction_2,
      &scalarPrevIndex_2);
    rtb_roll_idx = scalarFraction_2;

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search3' */
    scalarPrevIndex_3 = localDW->PreLookupIndexSearch3_MODE;
    indexTmp_0d = plook_s32dd_binxp(localB->Product3[1],
      &localP->PreLookupIndexSearch3_bpData[0], 14U, &scalarFraction_3,
      &scalarPrevIndex_3);
    rtb_PreLookupIndexSearch2_idx = scalarFraction_3;

    /* S-Function (sfun_kflookupnd): '<S274>/pitch' incorporates:
     *  Constant: '<S274>/Constant1'
     */
    if (rtb_roll_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_roll_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac_0[0] = rtb_roll_idx;
    rtb_roll_idx = rtb_PreLookupIndexSearch2_idx;
    if (rtb_PreLookupIndexSearch2_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac_0[1] = rtb_roll_idx;
    if (bpIndex_idx > 22) {
      rtb_roll_idx = 22.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex_0[0] = (uint32_T)rtb_roll_idx;
    if (indexTmp_0d > 13) {
      rtb_roll_idx = 13.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex_0[1] = (uint32_T)rtb_roll_idx;
    if (localP->Constant1_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[0];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch2_idx = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[1];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_roll_idx = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[2];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_roll_idx_0 = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);

    /* Assignment: '<S274>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S274>/Constant'
     */
    if (rtd_WhileIterator_IterationMark[3] < 2) {
      rtd_WhileIterator_IterationMark[3] = 2U;
      for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
        localB->AssignmenttoLongitudinal[bpIndex_idx] = localP->
          Constant_Value[bpIndex_idx];
      }
    }

    localB->AssignmenttoLongitudinal[0] = rtb_PreLookupIndexSearch2_idx;
    localB->AssignmenttoLongitudinal[2] = rtb_roll_idx;
    localB->AssignmenttoLongitudinal[4] = rtb_roll_idx_0;

    /* Product: '<S270>/Product1' */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_Product1_ie[bpIndex_idx] = rtb_q[bpIndex_idx] *
        localB->AssignmenttoLongitudinal[bpIndex_idx];
    }

    /* Sum: '<S273>/Subtract' incorporates:
     *  Constant: '<S273>/Constant'
     */
    rtb_Subtract_j = rtu_DamageCase - localP->Constant_Value_k;

    /* S-Function (sfun_kflookupnd): '<S273>/r' incorporates:
     *  Constant: '<S273>/Constant1'
     */
    rtb_roll_idx = rtb_PreLookupIndexSearch_idx;
    if (rtb_PreLookupIndexSearch_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract_j > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract_j;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant1_Value_h[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant1_Value_h[locIndex];
      }

      rtb_r[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_idx,
        &localP->r_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search5' */
    scalarPrevIndex_4 = localDW->PreLookupIndexSearch5_MODE;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch5_bpData[0], 24U, &scalarFraction_4,
      &scalarPrevIndex_4);
    rtb_roll_idx = scalarFraction_4;

    /* S-Function (sfun_idxsearch): '<S274>/PreLookup Index Search1' */
    scalarPrevIndex_5 = localDW->PreLookupIndexSearch1_MODE;
    indexTmp_0d = plook_s32dd_binxp(localB->Product3[2],
      &localP->PreLookupIndexSearch1_bpData[0], 14U, &scalarFraction_5,
      &scalarPrevIndex_5);
    rtb_PreLookupIndexSearch2_idx = scalarFraction_5;

    /* S-Function (sfun_kflookupnd): '<S274>/yaw' incorporates:
     *  Constant: '<S274>/Constant3'
     */
    if (rtb_roll_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_roll_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac_1[0] = rtb_roll_idx;
    rtb_roll_idx = rtb_PreLookupIndexSearch2_idx;
    if (rtb_PreLookupIndexSearch2_idx < 0.0) {
      rtb_roll_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_idx > 1.0) {
        rtb_roll_idx = 1.0;
      }
    }

    frac_1[1] = rtb_roll_idx;
    if (bpIndex_idx > 23) {
      rtb_roll_idx = 23.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex_1[0] = (uint32_T)rtb_roll_idx;
    if (indexTmp_0d > 13) {
      rtb_roll_idx = 13.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex_1[1] = (uint32_T)rtb_roll_idx;
    if (localP->Constant3_Value_n[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_n[0];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch2_idx = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value_n[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_n[1];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_roll_idx = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value_n[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_n[2];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_roll_idx_0 = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);

    /* Assignment: '<S274>/Assignment to  Lateral1' incorporates:
     *  Constant: '<S274>/Constant5'
     */
    if (rtd_WhileIterator_IterationMark[2] < 2) {
      rtd_WhileIterator_IterationMark[2] = 2U;
      for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
        localB->AssignmenttoLateral1[bpIndex_idx] = localP->
          Constant5_Value[bpIndex_idx];
      }
    }

    localB->AssignmenttoLateral1[1] = rtb_PreLookupIndexSearch2_idx;
    localB->AssignmenttoLateral1[3] = rtb_roll_idx;
    localB->AssignmenttoLateral1[5] = rtb_roll_idx_0;

    /* Product: '<S270>/Product3' */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_Product3_l[bpIndex_idx] = rtb_r[bpIndex_idx] *
        localB->AssignmenttoLateral1[bpIndex_idx];
    }

    /* S-Function (sfun_idxsearch): '<S272>/PreLookup Index Search' */
    scalarPrevIndex_6 = localDW->PreLookupIndexSearch_MODE_b;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_m[0], 23U, &scalarFraction_6,
      &scalarPrevIndex_6);
    rtb_PreLookupIndexSearch2_idx = scalarFraction_6;

    /* Sum: '<S272>/Subtract' incorporates:
     *  Constant: '<S272>/Constant'
     *  DataTypeConversion: '<S272>/Data Type Conversion'
     */
    rtb_Subtract_n = rtu_DamageCase - localP->Constant_Value_j;

    /* S-Function (sfun_kflookupnd): '<S272>/CY derivative increment due to rates' incorporates:
     *  Constant: '<S272>/Constant1'
     */
    if (bpIndex_idx > 22) {
      rtb_roll_idx = 22.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_idx = 0.0;
    }

    bpIndex_idx = (int32_T)rtb_roll_idx;
    if (rtb_Subtract_n > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract_n;
    }

    indexTmp_0d = (int32_T)locIndex;
    if (localP->Constant1_Value_n[0] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_n[0];
    }

    rtb_roll_idx = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);
    if (localP->Constant1_Value_n[1] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_n[1];
    }

    rtb_roll_idx_0 = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);
    if (localP->Constant1_Value_n[2] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_n[2];
    }

    rtb_PreLookupIndexSearch2_idx = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);

    /* Assignment: '<S270>/Assignment to  CY' incorporates:
     *  Constant: '<S270>/Constant4'
     *  Product: '<S272>/Product'
     */
    if (rtd_WhileIterator_IterationMark[0] < 2) {
      rtd_WhileIterator_IterationMark[0] = 2U;
      for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
        localB->AssignmenttoCY[bpIndex_idx] = localP->
          Constant4_Value_g[bpIndex_idx];
      }
    }

    localB->AssignmenttoCY[1] = (rtb_roll_idx * localB->Product3[0] +
      rtb_roll_idx_0 * localB->Product3[1]) + rtb_PreLookupIndexSearch2_idx *
      localB->Product3[2];

    /* Sum: '<S270>/Add1' incorporates:
     *  Sum: '<S270>/Add'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rty_0[bpIndex_idx] = ((rtb_Product2_fh[bpIndex_idx] +
        rtb_Product1_ie[bpIndex_idx]) + rtb_Product3_l[bpIndex_idx]) +
        localB->AssignmenttoCY[bpIndex_idx];
    }
  }
}

/* Output and update for atomic system:
 *   '<S271>/Blending Function'
 *   '<S399>/Blending Function'
 *   '<S497>/Blending Function'
 *   '<S605>/Blending Function'
 *   '<S713>/Blending Function'
 */
void claw_main_BlendingFunction(real_T rtu_alpha, real_T rtu_beta, real_T
  rtu_tas, const real_T rtu_pqr[3], real_T rtu_B, real_T rtu_Cbar,
  rtB_BlendingFunction_claw_main *localB)
{
  {
    real_T eml_alpha;
    real_T eml_beta;
    int32_T eml_whichcase;
    real_T eml_r_osc;

    /* Embedded MATLAB: '<S271>/Blending Function' */
    /* Embedded MATLAB Function 'gtm-aero/Aero_GTM_T2/Dynamic Derviatives/Rotary Blended  UnDamaged Case/Blending Function': '<S276>:1' */
    /*  Hybrid Kalviste blending method for use in embedded block in Simulink. */
    /*  */
    /*  Austin Murch */
    /*  Austin.M.Murch@nasa.gov */
    /*  Dimension vector outputs. */
    /* '<S276>:1:8' */
    localB->pqr_osc[0] = 0.0;
    localB->pqr_osc[1] = 0.0;
    localB->pqr_osc[2] = 0.0;

    /*  Constants */
    /*  Setup variables */
    /* '<S276>:1:16' */
    /* '<S276>:1:17' */
    /* '<S276>:1:18' */
    /* '<S276>:1:20' */
    eml_alpha = rtu_alpha * 1.7453292519943295E-002;

    /* '<S276>:1:21' */
    eml_beta = rtu_beta * 1.7453292519943295E-002;

    /* '<S276>:1:22' */
    localB->omega = 0.0;

    /* ----Hybrid Kalviste Method----% */
    /* '<S276>:1:25' */
    eml_whichcase = 0;

    /* Test for case 1: p_osc = 0 */
    if ((!(cos(eml_alpha) * cos(eml_beta) == 0.0)) && (!(rtu_pqr[0] == 0.0))) {
      /* '<S276>:1:31' */
      localB->omega = rtu_pqr[0] / (cos(eml_alpha) * cos(eml_beta));

      /* '<S276>:1:32' */
      eml_r_osc = rtu_pqr[2] - localB->omega * sin(eml_alpha) * cos(eml_beta);
      if ((!(fabs(eml_r_osc) > fabs(rtu_pqr[2]))) && (!(eml_r_osc * rtu_pqr[2] <
            0.0))) {
        /* '<S276>:1:36' */
        eml_whichcase = 1;
      } else {
        /* '<S276>:1:34' */
        /* '<S276>:1:33' */
      }
    } else {
      /* '<S276>:1:29' */
      /* '<S276>:1:28' */
    }

    /* Test for case 2: r_osc = 0 */
    if ((!(sin(eml_alpha) * cos(eml_beta) == 0.0)) && (!(rtu_pqr[2] == 0.0))) {
      /* '<S276>:1:44' */
      localB->omega = rtu_pqr[2] / (sin(eml_alpha) * cos(eml_beta));

      /* '<S276>:1:45' */
      eml_r_osc = rtu_pqr[0] - localB->omega * cos(eml_alpha) * cos(eml_beta);
      if ((!(fabs(eml_r_osc) > fabs(rtu_pqr[0]))) && (!(eml_r_osc * rtu_pqr[0] <
            0.0))) {
        /* '<S276>:1:49' */
        eml_whichcase = 2;
      } else {
        /* '<S276>:1:47' */
        /* '<S276>:1:46' */
      }
    } else {
      /* '<S276>:1:42' */
      /* '<S276>:1:41' */
    }

    /* Test for case 3: Omega = 0 */
    if (eml_whichcase == 0) {
      /* '<S276>:1:54' */
      /* '<S276>:1:55' */
      eml_whichcase = 3;
    }

    /* '<S276>:1:60' */
    switch (eml_whichcase) {
     case 1:
      /* '<S276>:1:62' */
      localB->omega = rtu_pqr[0] / (cos(eml_alpha) * cos(eml_beta));

      /* '<S276>:1:63' */
      localB->pqr_osc[0] = 0.0;

      /* '<S276>:1:64' */
      localB->pqr_osc[1] = rtu_pqr[1] - localB->omega * sin(eml_beta);

      /* '<S276>:1:65' */
      localB->pqr_osc[2] = rtu_pqr[2] - localB->omega * sin(eml_alpha) * cos
        (eml_beta);
      break;

     case 2:
      /* '<S276>:1:68' */
      localB->omega = rtu_pqr[2] / (sin(eml_alpha) * cos(eml_beta));

      /* '<S276>:1:69' */
      localB->pqr_osc[0] = rtu_pqr[0] - localB->omega * cos(eml_alpha) * cos
        (eml_beta);

      /* '<S276>:1:70' */
      localB->pqr_osc[1] = rtu_pqr[1] - localB->omega * sin(eml_beta);

      /* '<S276>:1:71' */
      localB->pqr_osc[2] = 0.0;
      break;

     case 3:
      /* '<S276>:1:74' */
      localB->pqr_osc[0] = rtu_pqr[0];

      /* '<S276>:1:75' */
      localB->pqr_osc[1] = rtu_pqr[1];

      /* '<S276>:1:76' */
      localB->pqr_osc[2] = rtu_pqr[2];

      /* '<S276>:1:77' */
      localB->omega = 0.0;
      break;
    }

    /* -----------------------------------------------% End Hybrid Kalviste */
    /*  Scale values for table lookup */
    /* '<S276>:1:83' */
    eml_r_osc = rtu_B / (2.0 * rtu_tas * 1.689);

    /* '<S276>:1:84' */
    /* '<S276>:1:85' */
    localB->omega = localB->omega * eml_r_osc;

    /* '<S276>:1:86' */
    localB->pqr_osc[0] = localB->pqr_osc[0] * eml_r_osc;
    localB->pqr_osc[1] = rtu_Cbar / (2.0 * rtu_tas * 1.689) * localB->pqr_osc[1];
    localB->pqr_osc[2] = localB->pqr_osc[2] * eml_r_osc;
  }
}

/* Output and update for action system:
 *   '<S236>/Rotary Blended  UnDamaged Case'
 *   '<S570>/Rotary Blended  UnDamaged Case'
 */
void claw_RotaryBlendedUnDamagedCase(real_T rtu_alpha, real_T rtu_TAS, real_T
  rtu_beta, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T rty_0[6],
  rtB_RotaryBlendedUnDamagedCase_ *localB, rtDW_RotaryBlendedUnDamagedCase
  *localDW, rtP_RotaryBlendedUnDamagedCase_ *localP, uint8_T
  rtd_WhileIterator_IterationMark[7])
{
  /* local block i/o variables */
  real_T rtb_Saturation1_i;

  {
    int32_T scalarPrevIndex;
    uint32_T locIndex;
    int32_T scalarIndex;
    real_T scalarFraction;
    int32_T scalarPrevIndex_0;
    int32_T scalarIndex_0;
    real_T scalarFraction_0;
    int32_T scalarPrevIndex_1;
    int32_T scalarIndex_1;
    real_T scalarFraction_1;
    real_T frac[3];
    uint32_T bpIndex[4];
    int32_T scalarPrevIndex_2;
    real_T scalarFraction_2;
    int32_T scalarPrevIndex_3;
    real_T scalarFraction_3;
    real_T frac_0[2];
    uint32_T bpIndex_0[3];
    int32_T scalarPrevIndex_4;
    real_T scalarFraction_4;
    int32_T scalarPrevIndex_5;
    real_T scalarFraction_5;
    real_T frac_1[2];
    uint32_T bpIndex_1[3];
    int32_T scalarPrevIndex_6;
    real_T scalarFraction_6;
    int32_T scalarPrevIndex_7;
    real_T scalarFraction_7;
    real_T frac_2[2];
    uint32_T bpIndex_2[3];
    real_T rtb_TableLookup_j[6];
    real_T rtb_PreLookupIndexSearch1_j_idx;
    real_T rtb_PreLookupIndexSearch2_h_idx;
    real_T rtb_PreLookupIndexSearch_p_idx;

    /* S-Function (sfun_idxsearch): '<S278>/PreLookup Index Search' */
    scalarPrevIndex = localDW->PreLookupIndexSearch_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData[0], 23U, &scalarFraction,
      &scalarPrevIndex);
    rtb_PreLookupIndexSearch_p_idx = scalarFraction;

    /* Saturate: '<S271>/Saturation1' */
    rtb_Saturation1_i = rt_SATURATE(rtu_TAS, localP->Saturation1_LowerSat,
      localP->Saturation1_UpperSat);
    claw_main_BlendingFunction(rtu_alpha, rtu_beta, rtb_Saturation1_i, rtu_pqr,
      rtu_4, rtu_5, &localB->sf_BlendingFunction);

    /* Saturate: '<S271>/Saturation' */
    localB->Saturation = rt_SATURATE(localB->sf_BlendingFunction.omega,
      localP->Saturation_LowerSat, localP->Saturation_UpperSat);

    /* S-Function (sfun_idxsearch): '<S278>/PreLookup Index Search2' */
    scalarPrevIndex_0 = localDW->PreLookupIndexSearch2_MODE;
    scalarIndex_0 = plook_s32dd_binxp(localB->Saturation,
      &localP->PreLookupIndexSearch2_bpData[0], 8U, &scalarFraction_0,
      &scalarPrevIndex_0);
    rtb_PreLookupIndexSearch2_h_idx = scalarFraction_0;

    /* S-Function (sfun_idxsearch): '<S278>/PreLookup Index Search1' */
    scalarPrevIndex_1 = localDW->PreLookupIndexSearch1_MODE;
    scalarIndex_1 = plook_s32dd_binxp(rtu_beta,
      &localP->PreLookupIndexSearch1_bpData[0], 20U, &scalarFraction_1,
      &scalarPrevIndex_1);
    rtb_PreLookupIndexSearch1_j_idx = scalarFraction_1;

    /* S-Function (sfun_kflookupnd): '<S278>/TableLookup' incorporates:
     *  Constant: '<S278>/Constant1'
     */
    frac[0] = rtb_PreLookupIndexSearch_p_idx;
    frac[1] = rtb_PreLookupIndexSearch2_h_idx;
    frac[2] = rtb_PreLookupIndexSearch1_j_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_p_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex[0] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (scalarIndex_0 > 7) {
      rtb_PreLookupIndexSearch_p_idx = 7.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex[1] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (scalarIndex_1 > 19) {
      rtb_PreLookupIndexSearch_p_idx = 19.0;
    } else if (scalarIndex_1 >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex_1;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex[2] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      if (localP->Constant1_Value[scalarIndex] > 5U) {
        locIndex = 5U;
      } else {
        locIndex = localP->Constant1_Value[scalarIndex];
      }

      bpIndex[3] = locIndex;
      locIndex = 4536U * bpIndex[3U];
      rtb_TableLookup_j[(uint32_T)scalarIndex] = intrp3d_lx(&bpIndex[0U], &frac
        [0U], &localP->TableLookup_tableData[locIndex],
        &localP->TableLookup_dimSizes[0]);
    }

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search4' */
    scalarPrevIndex_2 = localDW->PreLookupIndexSearch4_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch4_bpData[0], 23U, &scalarFraction_2,
      &scalarPrevIndex_2);
    rtb_PreLookupIndexSearch_p_idx = scalarFraction_2;

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search2' */
    scalarPrevIndex_3 = localDW->PreLookupIndexSearch2_MODE_i;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[0],
      &localP->PreLookupIndexSearch2_bpData_f[0], 14U, &scalarFraction_3,
      &scalarPrevIndex_3);
    rtb_PreLookupIndexSearch2_h_idx = scalarFraction_3;

    /* S-Function (sfun_kflookupnd): '<S277>/roll' incorporates:
     *  Constant: '<S277>/Constant2'
     */
    frac_0[0] = rtb_PreLookupIndexSearch_p_idx;
    frac_0[1] = rtb_PreLookupIndexSearch2_h_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_p_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_0[0] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_p_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_0[1] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (localP->Constant2_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[0];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch_p_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[1];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch2_h_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[2];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch1_j_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);

    /* Assignment: '<S277>/Assignment to  Lateral' incorporates:
     *  Constant: '<S277>/Constant4'
     */
    if (rtd_WhileIterator_IterationMark[4] < 2) {
      rtd_WhileIterator_IterationMark[4] = 2U;
      for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
        localB->AssignmenttoLateral[scalarIndex] = localP->
          Constant4_Value[scalarIndex];
      }
    }

    localB->AssignmenttoLateral[1] = rtb_PreLookupIndexSearch_p_idx;
    localB->AssignmenttoLateral[3] = rtb_PreLookupIndexSearch2_h_idx;
    localB->AssignmenttoLateral[5] = rtb_PreLookupIndexSearch1_j_idx;

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search' */
    scalarPrevIndex_4 = localDW->PreLookupIndexSearch_MODE_j;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_c[0], 23U, &scalarFraction_4,
      &scalarPrevIndex_4);
    rtb_PreLookupIndexSearch_p_idx = scalarFraction_4;

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search3' */
    scalarPrevIndex_5 = localDW->PreLookupIndexSearch3_MODE;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[1],
      &localP->PreLookupIndexSearch3_bpData[0], 14U, &scalarFraction_5,
      &scalarPrevIndex_5);
    rtb_PreLookupIndexSearch2_h_idx = scalarFraction_5;

    /* S-Function (sfun_kflookupnd): '<S277>/pitch' incorporates:
     *  Constant: '<S277>/Constant1'
     */
    frac_1[0] = rtb_PreLookupIndexSearch_p_idx;
    frac_1[1] = rtb_PreLookupIndexSearch2_h_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_p_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_1[0] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_p_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_1[1] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (localP->Constant1_Value_k[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_k[0];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch_p_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value_k[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_k[1];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch2_h_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value_k[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_k[2];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch1_j_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);

    /* Assignment: '<S277>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S277>/Constant'
     */
    if (rtd_WhileIterator_IterationMark[6] < 2) {
      rtd_WhileIterator_IterationMark[6] = 2U;
      for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
        localB->AssignmenttoLongitudinal[scalarIndex] = localP->
          Constant_Value[scalarIndex];
      }
    }

    localB->AssignmenttoLongitudinal[0] = rtb_PreLookupIndexSearch_p_idx;
    localB->AssignmenttoLongitudinal[2] = rtb_PreLookupIndexSearch2_h_idx;
    localB->AssignmenttoLongitudinal[4] = rtb_PreLookupIndexSearch1_j_idx;

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search5' */
    scalarPrevIndex_6 = localDW->PreLookupIndexSearch5_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch5_bpData[0], 24U, &scalarFraction_6,
      &scalarPrevIndex_6);
    rtb_PreLookupIndexSearch_p_idx = scalarFraction_6;

    /* S-Function (sfun_idxsearch): '<S277>/PreLookup Index Search1' */
    scalarPrevIndex_7 = localDW->PreLookupIndexSearch1_MODE_k;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[2],
      &localP->PreLookupIndexSearch1_bpData_c[0], 14U, &scalarFraction_7,
      &scalarPrevIndex_7);
    rtb_PreLookupIndexSearch2_h_idx = scalarFraction_7;

    /* S-Function (sfun_kflookupnd): '<S277>/yaw' incorporates:
     *  Constant: '<S277>/Constant3'
     */
    frac_2[0] = rtb_PreLookupIndexSearch_p_idx;
    frac_2[1] = rtb_PreLookupIndexSearch2_h_idx;
    if (scalarIndex > 23) {
      rtb_PreLookupIndexSearch_p_idx = 23.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_2[0] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_p_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_p_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_p_idx = 0.0;
    }

    bpIndex_2[1] = (uint32_T)rtb_PreLookupIndexSearch_p_idx;
    if (localP->Constant3_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[0];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch_p_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[1];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch2_h_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[2];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch1_j_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);

    /* Assignment: '<S277>/Assignment to  Lateral1' incorporates:
     *  Constant: '<S277>/Constant5'
     */
    if (rtd_WhileIterator_IterationMark[5] < 2) {
      rtd_WhileIterator_IterationMark[5] = 2U;
      for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
        localB->AssignmenttoLateral1[scalarIndex] = localP->
          Constant5_Value[scalarIndex];
      }
    }

    localB->AssignmenttoLateral1[1] = rtb_PreLookupIndexSearch_p_idx;
    localB->AssignmenttoLateral1[3] = rtb_PreLookupIndexSearch2_h_idx;
    localB->AssignmenttoLateral1[5] = rtb_PreLookupIndexSearch1_j_idx;

    /* Sum: '<S271>/Add' */
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      rty_0[scalarIndex] = ((rtb_TableLookup_j[scalarIndex] +
        localB->AssignmenttoLateral[scalarIndex]) +
                            localB->AssignmenttoLongitudinal[scalarIndex]) +
        localB->AssignmenttoLateral1[scalarIndex];
    }
  }
}

/* Forward declaration for local functions */
static real_T claw_main_cosd(real_T eml_x);
static real_T claw_main_sind(real_T eml_x);

/* Function for Embedded MATLAB: '<S218>/Engine Alignment' */
static real_T claw_main_cosd(real_T eml_x)
{
  real_T eml_b_x;
  real_T eml_c_x;
  eml_c_x = eml_x / 90.0;
  if (eml_c_x < 0.0) {
    eml_c_x = ceil(eml_c_x - 0.5);
  } else {
    eml_c_x = floor(eml_c_x + 0.5);
  }

  eml_b_x = eml_x - eml_c_x * 90.0;
  eml_c_x -= floor(eml_c_x / 4.0) * 4.0;
  if (eml_c_x < 0.0) {
    eml_c_x = ceil(eml_c_x - 0.5);
  } else {
    eml_c_x = floor(eml_c_x + 0.5);
  }

  if (eml_c_x < 2.0) {
    if (eml_c_x < 1.0) {
      return cos(1.7453292519943295E-002 * eml_b_x);
    } else {
      return -sin(1.7453292519943295E-002 * eml_b_x);
    }
  } else if (eml_c_x < 3.0) {
    return -cos(1.7453292519943295E-002 * eml_b_x);
  } else {
    return sin(1.7453292519943295E-002 * eml_b_x);
  }
}

/* Function for Embedded MATLAB: '<S218>/Engine Alignment' */
static real_T claw_main_sind(real_T eml_x)
{
  real_T eml_b_x;
  real_T eml_c_x;
  eml_c_x = eml_x / 90.0;
  if (eml_c_x < 0.0) {
    eml_c_x = ceil(eml_c_x - 0.5);
  } else {
    eml_c_x = floor(eml_c_x + 0.5);
  }

  eml_b_x = eml_x - eml_c_x * 90.0;
  eml_c_x -= floor(eml_c_x / 4.0) * 4.0;
  if (eml_c_x < 0.0) {
    eml_c_x = ceil(eml_c_x - 0.5);
  } else {
    eml_c_x = floor(eml_c_x + 0.5);
  }

  if (eml_c_x < 2.0) {
    if (eml_c_x < 1.0) {
      return sin(1.7453292519943295E-002 * eml_b_x);
    } else {
      return cos(1.7453292519943295E-002 * eml_b_x);
    }
  } else if (eml_c_x < 3.0) {
    return -sin(1.7453292519943295E-002 * eml_b_x);
  } else {
    return -cos(1.7453292519943295E-002 * eml_b_x);
  }
}

/* Output and update for atomic system:
 *   '<S218>/Engine Alignment'
 *   '<S346>/Engine Alignment'
 *   '<S444>/Engine Alignment'
 *   '<S552>/Engine Alignment'
 *   '<S660>/Engine Alignment'
 */
void claw_main_EngineAlignment(real_T rtu_Tl, real_T rtu_hl, real_T rtu_Tr,
  real_T rtu_hr, rtB_EngineAlignment_claw_main *localB,
  rtP_EngineAlignment_claw_main *localP)
{
  /* Embedded MATLAB: '<S218>/Engine Alignment' */
  /* Embedded MATLAB Function 'GTM_T2_MACH/Engine Alignment': '<S281>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  Using the engine alignment angles (set in AC_params_T2.m), compute the  */
  /*  off-axis thrust and angular momentum terms. */
  /* '<S281>:1:8' */
  /* '<S281>:1:11' */
  /* '<S281>:1:14' */
  /* '<S281>:1:16' */
  localB->TL[0] = claw_main_cosd(localP->SFunction_p1[1]) * claw_main_cosd
    (localP->SFunction_p1[2]) * rtu_Tl;
  localB->TR[0] = claw_main_cosd(localP->SFunction_p2[1]) * claw_main_cosd
    (localP->SFunction_p2[2]) * rtu_Tr;
  localB->T[0] = localB->TL[0] + localB->TR[0];
  localB->H[0] = claw_main_cosd(localP->SFunction_p1[1]) * claw_main_cosd
    (localP->SFunction_p1[2]) * rtu_hl + claw_main_cosd(localP->SFunction_p2[1])
    * claw_main_cosd(localP->SFunction_p2[2]) * rtu_hr;
  localB->TL[1] = rtu_Tl * claw_main_sind(localP->SFunction_p1[2]);
  localB->TR[1] = rtu_Tr * claw_main_sind(localP->SFunction_p2[2]);
  localB->T[1] = localB->TL[1] + localB->TR[1];
  localB->H[1] = rtu_hl * claw_main_sind(localP->SFunction_p1[2]) + rtu_hr *
    claw_main_sind(localP->SFunction_p2[2]);
  localB->TL[2] = (-claw_main_sind(localP->SFunction_p1[1])) * claw_main_cosd
    (localP->SFunction_p1[2]) * rtu_Tl;
  localB->TR[2] = (-claw_main_sind(localP->SFunction_p2[1])) * claw_main_cosd
    (localP->SFunction_p2[2]) * rtu_Tr;
  localB->T[2] = localB->TL[2] + localB->TR[2];
  localB->H[2] = (-claw_main_sind(localP->SFunction_p1[1])) * claw_main_cosd
    (localP->SFunction_p1[2]) * rtu_hl + (-claw_main_sind(localP->SFunction_p2[1]))
    * claw_main_cosd(localP->SFunction_p2[2]) * rtu_hr;
}

/* Output and update for action system:
 *   '<S364>/Forced Oscillation with Damage Increments'
 *   '<S462>/Forced Oscillation with Damage Increments'
 *   '<S678>/Forced Oscillation with Damage Increments'
 */
void ForcedOscillationwithDamageIn_o(real_T rtu_alpha, uint32_T rtu_DamageCase,
  real_T rtu_TAS, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T
  rty_0[6], rtB_ForcedOscillationwithDama_d *localB,
  rtDW_ForcedOscillationwithDam_j *localDW, rtP_ForcedOscillationwithDama_l
  *localP)
{
  {
    int32_T scalarPrevIndex;
    uint32_T locIndex;
    int32_T scalarIndex;
    real_T scalarFraction;
    int32_T indexTmp_0d;
    uint32_T rtb_Subtract2_o;
    int32_T scalarPrevIndex_0;
    real_T scalarFraction_0;
    real_T rtb_Gain_py;
    int32_T scalarPrevIndex_1;
    real_T scalarFraction_1;
    real_T frac[2];
    uint32_T bpIndex[3];
    uint32_T idx;
    real_T rtb_AssignmenttoLateral_i[6];
    real_T rtb_p_g[6];
    uint32_T rtb_Subtract1_p;
    int32_T scalarPrevIndex_2;
    real_T scalarFraction_2;
    int32_T scalarPrevIndex_3;
    real_T scalarFraction_3;
    real_T frac_0[2];
    uint32_T bpIndex_0[3];
    real_T rtb_AssignmenttoLongitudinal_n0[6];
    real_T rtb_q_b[6];
    uint32_T rtb_Subtract_nk;
    int32_T scalarPrevIndex_4;
    real_T scalarFraction_4;
    int32_T scalarPrevIndex_5;
    real_T scalarFraction_5;
    real_T frac_1[2];
    uint32_T bpIndex_1[3];
    real_T rtb_AssignmenttoLateral1[6];
    real_T rtb_r_j[6];
    int32_T scalarPrevIndex_6;
    real_T scalarFraction_6;
    uint32_T rtb_Subtract_g;
    real_T rtb_AssignmenttoCY[6];
    real_T rtb_PreLookupIndexSearch2_f_idx;
    int32_T bpIndex_idx;
    real_T rtb_PreLookupIndexSearch_n_idx;
    real_T rtb_roll_l_idx;
    real_T rtb_roll_l_idx_0;

    /* S-Function (sfun_idxsearch): '<S401>/PreLookup Index Search' */
    scalarPrevIndex = localDW->PreLookupIndexSearch_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData[0], 17U, &scalarFraction,
      &scalarPrevIndex);
    rtb_PreLookupIndexSearch_n_idx = scalarFraction;

    /* Sum: '<S401>/Subtract2' incorporates:
     *  Constant: '<S401>/Constant5'
     */
    rtb_Subtract2_o = rtu_DamageCase - localP->Constant5_Value_n;

    /* S-Function (sfun_kflookupnd): '<S401>/p' incorporates:
     *  Constant: '<S401>/Constant3'
     */
    rtb_roll_l_idx = rtb_PreLookupIndexSearch_n_idx;
    if (rtb_PreLookupIndexSearch_n_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_n_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract2_o > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract2_o;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant3_Value[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant3_Value[locIndex];
      }

      rtb_p_g[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_l_idx,
        &localP->p_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search4' */
    scalarPrevIndex_0 = localDW->PreLookupIndexSearch4_MODE;
    indexTmp_0d = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch4_bpData[0], 23U, &scalarFraction_0,
      &scalarPrevIndex_0);
    rtb_roll_l_idx = scalarFraction_0;

    /* Gain: '<S403>/Gain' incorporates:
     *  Saturate: '<S403>/Saturation1'
     */
    rtb_Gain_py = localP->Gain_Gain * rt_SATURATE(rtu_TAS,
      localP->Saturation1_LowerSat, localP->Saturation1_UpperSat);

    /* Product: '<S403>/Product3' */
    localB->Product3[0] = rtu_pqr[0] * rtu_4 / rtb_Gain_py;
    localB->Product3[1] = rtu_pqr[1] * rtu_5 / rtb_Gain_py;
    localB->Product3[2] = rtu_pqr[2] * rtu_4 / rtb_Gain_py;

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search2' */
    scalarPrevIndex_1 = localDW->PreLookupIndexSearch2_MODE;
    bpIndex_idx = plook_s32dd_binxp(localB->Product3[0],
      &localP->PreLookupIndexSearch2_bpData[0], 14U, &scalarFraction_1,
      &scalarPrevIndex_1);
    rtb_PreLookupIndexSearch2_f_idx = scalarFraction_1;

    /* S-Function (sfun_kflookupnd): '<S402>/roll' incorporates:
     *  Constant: '<S402>/Constant2'
     */
    if (rtb_roll_l_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_roll_l_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac[0] = rtb_roll_l_idx;
    rtb_roll_l_idx = rtb_PreLookupIndexSearch2_f_idx;
    if (rtb_PreLookupIndexSearch2_f_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_f_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac[1] = rtb_roll_l_idx;
    if (indexTmp_0d > 22) {
      rtb_roll_l_idx = 22.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_l_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex[0] = (uint32_T)rtb_roll_l_idx;
    if (bpIndex_idx > 13) {
      rtb_roll_l_idx = 13.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_l_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex[1] = (uint32_T)rtb_roll_l_idx;
    if (localP->Constant2_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[0];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_PreLookupIndexSearch2_f_idx = intrp2d_lc(&bpIndex[0U], &frac[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[1];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_roll_l_idx = intrp2d_lc(&bpIndex[0U], &frac[0U], &localP->
      roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[2];
    }

    bpIndex[2] = locIndex;
    locIndex = 360U * bpIndex[2U];
    rtb_roll_l_idx_0 = intrp2d_lc(&bpIndex[0U], &frac[0U],
      &localP->roll_tableData[locIndex], 24U);

    /* Assignment: '<S402>/Assignment to  Lateral' incorporates:
     *  Constant: '<S402>/Constant4'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_AssignmenttoLateral_i[bpIndex_idx] = localP->
        Constant4_Value[bpIndex_idx];
    }

    rtb_AssignmenttoLateral_i[1] = rtb_PreLookupIndexSearch2_f_idx;
    rtb_AssignmenttoLateral_i[3] = rtb_roll_l_idx;
    rtb_AssignmenttoLateral_i[5] = rtb_roll_l_idx_0;

    /* Sum: '<S401>/Subtract1' incorporates:
     *  Constant: '<S401>/Constant4'
     */
    rtb_Subtract1_p = rtu_DamageCase - localP->Constant4_Value_p;

    /* S-Function (sfun_kflookupnd): '<S401>/q' incorporates:
     *  Constant: '<S401>/Constant2'
     */
    rtb_roll_l_idx = rtb_PreLookupIndexSearch_n_idx;
    if (rtb_PreLookupIndexSearch_n_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_n_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract1_p > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract1_p;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant2_Value_h[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant2_Value_h[locIndex];
      }

      rtb_q_b[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_l_idx,
        &localP->q_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search' */
    scalarPrevIndex_2 = localDW->PreLookupIndexSearch_MODE_p;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_m[0], 23U, &scalarFraction_2,
      &scalarPrevIndex_2);
    rtb_roll_l_idx = scalarFraction_2;

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search3' */
    scalarPrevIndex_3 = localDW->PreLookupIndexSearch3_MODE;
    indexTmp_0d = plook_s32dd_binxp(localB->Product3[1],
      &localP->PreLookupIndexSearch3_bpData[0], 14U, &scalarFraction_3,
      &scalarPrevIndex_3);
    rtb_PreLookupIndexSearch2_f_idx = scalarFraction_3;

    /* S-Function (sfun_kflookupnd): '<S402>/pitch' incorporates:
     *  Constant: '<S402>/Constant1'
     */
    if (rtb_roll_l_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_roll_l_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac_0[0] = rtb_roll_l_idx;
    rtb_roll_l_idx = rtb_PreLookupIndexSearch2_f_idx;
    if (rtb_PreLookupIndexSearch2_f_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_f_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac_0[1] = rtb_roll_l_idx;
    if (bpIndex_idx > 22) {
      rtb_roll_l_idx = 22.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_l_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex_0[0] = (uint32_T)rtb_roll_l_idx;
    if (indexTmp_0d > 13) {
      rtb_roll_l_idx = 13.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_l_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex_0[1] = (uint32_T)rtb_roll_l_idx;
    if (localP->Constant1_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[0];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch2_f_idx = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[1];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_roll_l_idx = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value[2];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_roll_l_idx_0 = intrp2d_lc(&bpIndex_0[0U], &frac_0[0U],
      &localP->pitch_tableData[locIndex], 24U);

    /* Assignment: '<S402>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S402>/Constant'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_AssignmenttoLongitudinal_n0[bpIndex_idx] = localP->
        Constant_Value[bpIndex_idx];
    }

    rtb_AssignmenttoLongitudinal_n0[0] = rtb_PreLookupIndexSearch2_f_idx;
    rtb_AssignmenttoLongitudinal_n0[2] = rtb_roll_l_idx;
    rtb_AssignmenttoLongitudinal_n0[4] = rtb_roll_l_idx_0;

    /* Sum: '<S401>/Subtract' incorporates:
     *  Constant: '<S401>/Constant'
     */
    rtb_Subtract_nk = rtu_DamageCase - localP->Constant_Value_m;

    /* S-Function (sfun_kflookupnd): '<S401>/r' incorporates:
     *  Constant: '<S401>/Constant1'
     */
    rtb_roll_l_idx = rtb_PreLookupIndexSearch_n_idx;
    if (rtb_PreLookupIndexSearch_n_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch_n_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    if (scalarIndex > 16) {
      indexTmp_0d = 16;
    } else if (scalarIndex >= 0) {
      indexTmp_0d = scalarIndex;
    } else {
      indexTmp_0d = 0;
    }

    if (rtb_Subtract_nk > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract_nk;
    }

    bpIndex_idx = (int32_T)locIndex;
    for (locIndex = 0U; locIndex < 6U; locIndex++) {
      if (localP->Constant1_Value_g[locIndex] > 5U) {
        idx = 5U;
      } else {
        idx = localP->Constant1_Value_g[locIndex];
      }

      rtb_r_j[locIndex] = intrp1d_lc((uint32_T)indexTmp_0d, rtb_roll_l_idx,
        &localP->r_tableData[108U * idx + 18 * bpIndex_idx]);
    }

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search5' */
    scalarPrevIndex_4 = localDW->PreLookupIndexSearch5_MODE;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch5_bpData[0], 24U, &scalarFraction_4,
      &scalarPrevIndex_4);
    rtb_roll_l_idx = scalarFraction_4;

    /* S-Function (sfun_idxsearch): '<S402>/PreLookup Index Search1' */
    scalarPrevIndex_5 = localDW->PreLookupIndexSearch1_MODE;
    indexTmp_0d = plook_s32dd_binxp(localB->Product3[2],
      &localP->PreLookupIndexSearch1_bpData[0], 14U, &scalarFraction_5,
      &scalarPrevIndex_5);
    rtb_PreLookupIndexSearch2_f_idx = scalarFraction_5;

    /* S-Function (sfun_kflookupnd): '<S402>/yaw' incorporates:
     *  Constant: '<S402>/Constant3'
     */
    if (rtb_roll_l_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_roll_l_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac_1[0] = rtb_roll_l_idx;
    rtb_roll_l_idx = rtb_PreLookupIndexSearch2_f_idx;
    if (rtb_PreLookupIndexSearch2_f_idx < 0.0) {
      rtb_roll_l_idx = 0.0;
    } else {
      if (rtb_PreLookupIndexSearch2_f_idx > 1.0) {
        rtb_roll_l_idx = 1.0;
      }
    }

    frac_1[1] = rtb_roll_l_idx;
    if (bpIndex_idx > 23) {
      rtb_roll_l_idx = 23.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_l_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex_1[0] = (uint32_T)rtb_roll_l_idx;
    if (indexTmp_0d > 13) {
      rtb_roll_l_idx = 13.0;
    } else if (indexTmp_0d >= 0) {
      rtb_roll_l_idx = (real_T)indexTmp_0d;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex_1[1] = (uint32_T)rtb_roll_l_idx;
    if (localP->Constant3_Value_h[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_h[0];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch2_f_idx = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value_h[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_h[1];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_roll_l_idx = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value_h[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value_h[2];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 375U * bpIndex_1[2U];
    rtb_roll_l_idx_0 = intrp2d_lc(&bpIndex_1[0U], &frac_1[0U],
      &localP->yaw_tableData[locIndex], 25U);

    /* Assignment: '<S402>/Assignment to  Lateral1' incorporates:
     *  Constant: '<S402>/Constant5'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_AssignmenttoLateral1[bpIndex_idx] = localP->
        Constant5_Value[bpIndex_idx];
    }

    rtb_AssignmenttoLateral1[1] = rtb_PreLookupIndexSearch2_f_idx;
    rtb_AssignmenttoLateral1[3] = rtb_roll_l_idx;
    rtb_AssignmenttoLateral1[5] = rtb_roll_l_idx_0;

    /* S-Function (sfun_idxsearch): '<S400>/PreLookup Index Search' */
    scalarPrevIndex_6 = localDW->PreLookupIndexSearch_MODE_c;
    bpIndex_idx = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_k[0], 23U, &scalarFraction_6,
      &scalarPrevIndex_6);
    rtb_PreLookupIndexSearch2_f_idx = scalarFraction_6;

    /* Sum: '<S400>/Subtract' incorporates:
     *  Constant: '<S400>/Constant'
     *  DataTypeConversion: '<S400>/Data Type Conversion'
     */
    rtb_Subtract_g = rtu_DamageCase - localP->Constant_Value_e;

    /* S-Function (sfun_kflookupnd): '<S400>/CY derivative increment due to rates' incorporates:
     *  Constant: '<S400>/Constant1'
     */
    if (bpIndex_idx > 22) {
      rtb_roll_l_idx = 22.0;
    } else if (bpIndex_idx >= 0) {
      rtb_roll_l_idx = (real_T)bpIndex_idx;
    } else {
      rtb_roll_l_idx = 0.0;
    }

    bpIndex_idx = (int32_T)rtb_roll_l_idx;
    if (rtb_Subtract_g > 5U) {
      locIndex = 5U;
    } else {
      locIndex = rtb_Subtract_g;
    }

    indexTmp_0d = (int32_T)locIndex;
    if (localP->Constant1_Value_k[0] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_k[0];
    }

    rtb_roll_l_idx = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_f_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);
    if (localP->Constant1_Value_k[1] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_k[1];
    }

    rtb_roll_l_idx_0 = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_f_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);
    if (localP->Constant1_Value_k[2] > 2U) {
      idx = 2U;
    } else {
      idx = localP->Constant1_Value_k[2];
    }

    rtb_PreLookupIndexSearch2_f_idx = intrp1d_lx((uint32_T)bpIndex_idx,
      rtb_PreLookupIndexSearch2_f_idx, &localP->CYderivativeincrementduetorates
      [144U * idx + 24 * indexTmp_0d]);

    /* Assignment: '<S398>/Assignment to  CY' incorporates:
     *  Constant: '<S398>/Constant4'
     *  Product: '<S400>/Product'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rtb_AssignmenttoCY[bpIndex_idx] = localP->Constant4_Value_l[bpIndex_idx];
    }

    rtb_AssignmenttoCY[1] = (rtb_roll_l_idx * localB->Product3[0] +
      rtb_roll_l_idx_0 * localB->Product3[1]) + rtb_PreLookupIndexSearch2_f_idx *
      localB->Product3[2];

    /* Sum: '<S398>/Add1' incorporates:
     *  Product: '<S398>/Product1'
     *  Product: '<S398>/Product2'
     *  Product: '<S398>/Product3'
     *  Sum: '<S398>/Add'
     */
    for (bpIndex_idx = 0; bpIndex_idx < 6; bpIndex_idx++) {
      rty_0[bpIndex_idx] = ((rtb_p_g[bpIndex_idx] *
        rtb_AssignmenttoLateral_i[bpIndex_idx] + rtb_q_b[bpIndex_idx] *
        rtb_AssignmenttoLongitudinal_n0[bpIndex_idx]) + rtb_r_j[bpIndex_idx] *
                            rtb_AssignmenttoLateral1[bpIndex_idx]) +
        rtb_AssignmenttoCY[bpIndex_idx];
    }
  }
}

/* Output and update for action system:
 *   '<S364>/Rotary Blended  UnDamaged Case'
 *   '<S462>/Rotary Blended  UnDamaged Case'
 *   '<S678>/Rotary Blended  UnDamaged Case'
 */
void cl_RotaryBlendedUnDamagedCase_k(real_T rtu_alpha, real_T rtu_TAS, real_T
  rtu_beta, const real_T rtu_pqr[3], real_T rtu_4, real_T rtu_5, real_T rty_0[6],
  rtB_RotaryBlendedUnDamagedCas_a *localB, rtDW_RotaryBlendedUnDamagedCa_p
  *localDW, rtP_RotaryBlendedUnDamagedCas_m *localP)
{
  /* local block i/o variables */
  real_T rtb_Saturation1_f;

  {
    int32_T scalarPrevIndex;
    uint32_T locIndex;
    int32_T scalarIndex;
    real_T scalarFraction;
    int32_T scalarPrevIndex_0;
    int32_T scalarIndex_0;
    real_T scalarFraction_0;
    int32_T scalarPrevIndex_1;
    int32_T scalarIndex_1;
    real_T scalarFraction_1;
    real_T frac[3];
    uint32_T bpIndex[4];
    int32_T scalarPrevIndex_2;
    real_T scalarFraction_2;
    int32_T scalarPrevIndex_3;
    real_T scalarFraction_3;
    real_T frac_0[2];
    uint32_T bpIndex_0[3];
    real_T rtb_AssignmenttoLateral_n[6];
    int32_T scalarPrevIndex_4;
    real_T scalarFraction_4;
    int32_T scalarPrevIndex_5;
    real_T scalarFraction_5;
    real_T frac_1[2];
    uint32_T bpIndex_1[3];
    real_T rtb_AssignmenttoLongitudinal_lk[6];
    int32_T scalarPrevIndex_6;
    real_T scalarFraction_6;
    int32_T scalarPrevIndex_7;
    real_T scalarFraction_7;
    real_T frac_2[2];
    uint32_T bpIndex_2[3];
    real_T rtb_AssignmenttoLateral1_n[6];
    real_T rtb_TableLookup_d[6];
    real_T rtb_PreLookupIndexSearch1_l_idx;
    real_T rtb_PreLookupIndexSearch2_e_idx;
    real_T rtb_PreLookupIndexSearch_mk_idx;

    /* S-Function (sfun_idxsearch): '<S406>/PreLookup Index Search' */
    scalarPrevIndex = localDW->PreLookupIndexSearch_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData[0], 23U, &scalarFraction,
      &scalarPrevIndex);
    rtb_PreLookupIndexSearch_mk_idx = scalarFraction;

    /* Saturate: '<S399>/Saturation1' */
    rtb_Saturation1_f = rt_SATURATE(rtu_TAS, localP->Saturation1_LowerSat,
      localP->Saturation1_UpperSat);
    claw_main_BlendingFunction(rtu_alpha, rtu_beta, rtb_Saturation1_f, rtu_pqr,
      rtu_4, rtu_5, &localB->sf_BlendingFunction);

    /* Saturate: '<S399>/Saturation' */
    localB->Saturation = rt_SATURATE(localB->sf_BlendingFunction.omega,
      localP->Saturation_LowerSat, localP->Saturation_UpperSat);

    /* S-Function (sfun_idxsearch): '<S406>/PreLookup Index Search2' */
    scalarPrevIndex_0 = localDW->PreLookupIndexSearch2_MODE;
    scalarIndex_0 = plook_s32dd_binxp(localB->Saturation,
      &localP->PreLookupIndexSearch2_bpData[0], 8U, &scalarFraction_0,
      &scalarPrevIndex_0);
    rtb_PreLookupIndexSearch2_e_idx = scalarFraction_0;

    /* S-Function (sfun_idxsearch): '<S406>/PreLookup Index Search1' */
    scalarPrevIndex_1 = localDW->PreLookupIndexSearch1_MODE;
    scalarIndex_1 = plook_s32dd_binxp(rtu_beta,
      &localP->PreLookupIndexSearch1_bpData[0], 20U, &scalarFraction_1,
      &scalarPrevIndex_1);
    rtb_PreLookupIndexSearch1_l_idx = scalarFraction_1;

    /* S-Function (sfun_kflookupnd): '<S406>/TableLookup' incorporates:
     *  Constant: '<S406>/Constant1'
     */
    frac[0] = rtb_PreLookupIndexSearch_mk_idx;
    frac[1] = rtb_PreLookupIndexSearch2_e_idx;
    frac[2] = rtb_PreLookupIndexSearch1_l_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_mk_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex[0] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (scalarIndex_0 > 7) {
      rtb_PreLookupIndexSearch_mk_idx = 7.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex[1] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (scalarIndex_1 > 19) {
      rtb_PreLookupIndexSearch_mk_idx = 19.0;
    } else if (scalarIndex_1 >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex_1;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex[2] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      if (localP->Constant1_Value[scalarIndex] > 5U) {
        locIndex = 5U;
      } else {
        locIndex = localP->Constant1_Value[scalarIndex];
      }

      bpIndex[3] = locIndex;
      locIndex = 4536U * bpIndex[3U];
      rtb_TableLookup_d[(uint32_T)scalarIndex] = intrp3d_lx(&bpIndex[0U], &frac
        [0U], &localP->TableLookup_tableData[locIndex],
        &localP->TableLookup_dimSizes[0]);
    }

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search4' */
    scalarPrevIndex_2 = localDW->PreLookupIndexSearch4_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch4_bpData[0], 23U, &scalarFraction_2,
      &scalarPrevIndex_2);
    rtb_PreLookupIndexSearch_mk_idx = scalarFraction_2;

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search2' */
    scalarPrevIndex_3 = localDW->PreLookupIndexSearch2_MODE_m;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[0],
      &localP->PreLookupIndexSearch2_bpData_a[0], 14U, &scalarFraction_3,
      &scalarPrevIndex_3);
    rtb_PreLookupIndexSearch2_e_idx = scalarFraction_3;

    /* S-Function (sfun_kflookupnd): '<S405>/roll' incorporates:
     *  Constant: '<S405>/Constant2'
     */
    frac_0[0] = rtb_PreLookupIndexSearch_mk_idx;
    frac_0[1] = rtb_PreLookupIndexSearch2_e_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_mk_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_0[0] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_mk_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_0[1] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (localP->Constant2_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[0];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch_mk_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[1];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch2_e_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);
    if (localP->Constant2_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant2_Value[2];
    }

    bpIndex_0[2] = locIndex;
    locIndex = 360U * bpIndex_0[2U];
    rtb_PreLookupIndexSearch1_l_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &localP->roll_tableData[locIndex], 24U);

    /* Assignment: '<S405>/Assignment to  Lateral' incorporates:
     *  Constant: '<S405>/Constant4'
     */
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      rtb_AssignmenttoLateral_n[scalarIndex] = localP->
        Constant4_Value[scalarIndex];
    }

    rtb_AssignmenttoLateral_n[1] = rtb_PreLookupIndexSearch_mk_idx;
    rtb_AssignmenttoLateral_n[3] = rtb_PreLookupIndexSearch2_e_idx;
    rtb_AssignmenttoLateral_n[5] = rtb_PreLookupIndexSearch1_l_idx;

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search' */
    scalarPrevIndex_4 = localDW->PreLookupIndexSearch_MODE_i;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch_bpData_i[0], 23U, &scalarFraction_4,
      &scalarPrevIndex_4);
    rtb_PreLookupIndexSearch_mk_idx = scalarFraction_4;

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search3' */
    scalarPrevIndex_5 = localDW->PreLookupIndexSearch3_MODE;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[1],
      &localP->PreLookupIndexSearch3_bpData[0], 14U, &scalarFraction_5,
      &scalarPrevIndex_5);
    rtb_PreLookupIndexSearch2_e_idx = scalarFraction_5;

    /* S-Function (sfun_kflookupnd): '<S405>/pitch' incorporates:
     *  Constant: '<S405>/Constant1'
     */
    frac_1[0] = rtb_PreLookupIndexSearch_mk_idx;
    frac_1[1] = rtb_PreLookupIndexSearch2_e_idx;
    if (scalarIndex > 22) {
      rtb_PreLookupIndexSearch_mk_idx = 22.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_1[0] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_mk_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_1[1] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (localP->Constant1_Value_h[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_h[0];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch_mk_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value_h[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_h[1];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch2_e_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);
    if (localP->Constant1_Value_h[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant1_Value_h[2];
    }

    bpIndex_1[2] = locIndex;
    locIndex = 360U * bpIndex_1[2U];
    rtb_PreLookupIndexSearch1_l_idx = intrp2d_lx(&bpIndex_1[0U], &frac_1[0U],
      &localP->pitch_tableData[locIndex], 24U);

    /* Assignment: '<S405>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S405>/Constant'
     */
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      rtb_AssignmenttoLongitudinal_lk[scalarIndex] = localP->
        Constant_Value[scalarIndex];
    }

    rtb_AssignmenttoLongitudinal_lk[0] = rtb_PreLookupIndexSearch_mk_idx;
    rtb_AssignmenttoLongitudinal_lk[2] = rtb_PreLookupIndexSearch2_e_idx;
    rtb_AssignmenttoLongitudinal_lk[4] = rtb_PreLookupIndexSearch1_l_idx;

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search5' */
    scalarPrevIndex_6 = localDW->PreLookupIndexSearch5_MODE;
    scalarIndex = plook_s32dd_binxp(rtu_alpha,
      &localP->PreLookupIndexSearch5_bpData[0], 24U, &scalarFraction_6,
      &scalarPrevIndex_6);
    rtb_PreLookupIndexSearch_mk_idx = scalarFraction_6;

    /* S-Function (sfun_idxsearch): '<S405>/PreLookup Index Search1' */
    scalarPrevIndex_7 = localDW->PreLookupIndexSearch1_MODE_m;
    scalarIndex_0 = plook_s32dd_binxp(localB->sf_BlendingFunction.pqr_osc[2],
      &localP->PreLookupIndexSearch1_bpData_p[0], 14U, &scalarFraction_7,
      &scalarPrevIndex_7);
    rtb_PreLookupIndexSearch2_e_idx = scalarFraction_7;

    /* S-Function (sfun_kflookupnd): '<S405>/yaw' incorporates:
     *  Constant: '<S405>/Constant3'
     */
    frac_2[0] = rtb_PreLookupIndexSearch_mk_idx;
    frac_2[1] = rtb_PreLookupIndexSearch2_e_idx;
    if (scalarIndex > 23) {
      rtb_PreLookupIndexSearch_mk_idx = 23.0;
    } else if (scalarIndex >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_2[0] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (scalarIndex_0 > 13) {
      rtb_PreLookupIndexSearch_mk_idx = 13.0;
    } else if (scalarIndex_0 >= 0) {
      rtb_PreLookupIndexSearch_mk_idx = (real_T)scalarIndex_0;
    } else {
      rtb_PreLookupIndexSearch_mk_idx = 0.0;
    }

    bpIndex_2[1] = (uint32_T)rtb_PreLookupIndexSearch_mk_idx;
    if (localP->Constant3_Value[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[0];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch_mk_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[1];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch2_e_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);
    if (localP->Constant3_Value[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = localP->Constant3_Value[2];
    }

    bpIndex_2[2] = locIndex;
    locIndex = 375U * bpIndex_2[2U];
    rtb_PreLookupIndexSearch1_l_idx = intrp2d_lx(&bpIndex_2[0U], &frac_2[0U],
      &localP->yaw_tableData[locIndex], 25U);

    /* Assignment: '<S405>/Assignment to  Lateral1' incorporates:
     *  Constant: '<S405>/Constant5'
     */
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      rtb_AssignmenttoLateral1_n[scalarIndex] = localP->
        Constant5_Value[scalarIndex];
    }

    rtb_AssignmenttoLateral1_n[1] = rtb_PreLookupIndexSearch_mk_idx;
    rtb_AssignmenttoLateral1_n[3] = rtb_PreLookupIndexSearch2_e_idx;
    rtb_AssignmenttoLateral1_n[5] = rtb_PreLookupIndexSearch1_l_idx;

    /* Sum: '<S399>/Add' */
    for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
      rty_0[scalarIndex] = ((rtb_TableLookup_d[scalarIndex] +
        rtb_AssignmenttoLateral_n[scalarIndex]) +
                            rtb_AssignmenttoLongitudinal_lk[scalarIndex]) +
        rtb_AssignmenttoLateral1_n[scalarIndex];
    }
  }
}

/* Forward declaration for local functions */
static real_T claw_main_get_ellipsoid_scaling(const real_T eml_dir[3], const
  real_T eml_ellipsoid[9]);

/* Function for Embedded MATLAB: '<S197>/Bang Bang' */
static real_T claw_main_get_ellipsoid_scaling(const real_T eml_dir[3], const
  real_T eml_ellipsoid[9])
{
  real_T eml_x;
  real_T eml_a[3];
  real_T eml_b[3];
  int32_T tmp;

  /* '<S309>:1:149' */
  for (tmp = 0; tmp < 3; tmp++) {
    eml_a[tmp] = eml_dir[tmp];
    eml_b[tmp] = 0.0;
    eml_b[tmp] += eml_ellipsoid[tmp] * eml_dir[0];
    eml_b[tmp] += eml_ellipsoid[tmp + 3] * eml_dir[1];
    eml_b[tmp] += eml_ellipsoid[tmp + 6] * eml_dir[2];
  }

  eml_x = sqrt((eml_a[0] * eml_b[0] + eml_a[1] * eml_b[1]) + eml_a[2] * eml_b[2]);
  if (!(eml_x >= 1.0E-012)) {
    eml_x = 1.0E-012;
  }

  return 1.0 / eml_x;
}

/* Model step function */
void claw_main_step(void)
{
  /* local block i/o variables */
  real_T rtb_sensors[36];
  real_T rtb_Gain1_o[4];
  real_T rtb_abs_cos_b;
  real_T rtb_Gain_i[6];
  real_T rtb_abs_cos_theta;
  real_T rtb_abs_vel_rw;
  real_T rtb_abs_cos_beta;
  real_T rtb_Product11;
  real_T rtb_abs_cos_gamma_rw;
  real_T rtb_Switch_k;
  real_T rtb_Product_b;
  real_T rtb_qbar;
  real_T rtb_att_type_availability[6];
  real_T rtb_MinMax4;
  real_T rtb_Product10;
  real_T rtb_Gain_p;
  real_T rtb_Sum3;
  real_T rtb_Sum2_l;
  real_T rtb_Product5;
  real_T rtb_Sum1_p;
  real_T rtb_Sum_m;
  real_T rtb_Product_h;
  real_T rtb_FromWorkspace4[3];
  real_T rtb_FromWorkspace1[3];
  real_T rtb_FromWorkspace2[3];
  real_T rtb_Reshape_n[52];
  real_T rtb_Gain1_e[4];
  real_T rtb_Gain_jg[6];
  real_T rtb_Gain1_jg[4];
  real_T rtb_Gain_po[6];
  real_T rtb_FromWorkspace4_b[3];
  real_T rtb_orderatts_k[3];
  real_T rtb_Assignment2[13];
  real_T rtb_LeftRollSpoilerSchedule;
  real_T rtb_RightRollSpoilerSchedule;
  real_T rtb_u20_p;
  real_T rtb_P;
  real_T rtb_RPMref_2_FuelFlow;
  real_T rtb_FuelPumpVoltage;
  real_T rtb_LengON[6];
  real_T rtb_RPMref_2_FuelFlow_m;
  real_T rtb_FuelPumpVoltage_g;
  real_T rtb_RengON[6];
  real_T rtb_FromWorkspace;
  real_T rtb_Product_m[6];
  real_T rtb_Product_dv[6];
  real_T rtb_NegateLateral[6];
  real_T rtb_InterpolationUsingPrelook_n[6];
  real_T rtb_Product_iy[6];
  real_T rtb_Product_p[6];
  real_T rtb_Product_io[6];
  real_T rtb_Product_ho[6];
  real_T rtb_AssignmenttoLongitudinal[6];
  real_T rtb_Gain_i5[6];
  real_T rtb_Gain_cz[6];
  real_T rtb_Gain_jm[6];
  real_T rtb_Gain_d[6];
  real_T rtb_Gain_id[6];
  real_T rtb_Gain1_d[6];
  real_T rtb_Gain2_e[6];
  real_T rtb_Gain3_c[6];
  real_T rtb_AssignmenttoLongitudinal_h[6];
  real_T rtb_tas;
  real_T rtb_sos;
  real_T rtb_Rslant;
  real_T rtb_r_cg[3];
  real_T rtb_inertia[9];
  real_T rtb_inertia_inv[9];
  real_T rtb_Isp;
  real_T rtb_FromWorkspace1_o[3];
  real_T rtb_Gain1_h[4];
  real_T rtb_Gain_kgg[6];
  real_T rtb_orderatts_b[3];
  real_T rtb_LeftRollSpoilerSchedule_g;
  real_T rtb_RightRollSpoilerSchedule_g;
  real_T rtb_RPMref_2_FuelFlow_i;
  real_T rtb_FuelPumpVoltage_i;
  real_T rtb_LengON_k[6];
  real_T rtb_RPMref_2_FuelFlow_n;
  real_T rtb_FuelPumpVoltage_m;
  real_T rtb_RengON_j[6];
  real_T rtb_FromWorkspace_g;
  real_T rtb_Product_h5[6];
  real_T rtb_Product_mq[6];
  real_T rtb_NegateLateral_n[6];
  real_T rtb_InterpolationUsingPrelook_j[6];
  real_T rtb_Product_n5[6];
  real_T rtb_Product_f[6];
  real_T rtb_Product_lk[6];
  real_T rtb_Product_d0[6];
  real_T rtb_AssignmenttoLongitudinal_l[6];
  real_T rtb_Gain_l0[6];
  real_T rtb_Gain_oz[6];
  real_T rtb_Gain_ha[6];
  real_T rtb_Gain_hp[6];
  real_T rtb_Gain_ill[6];
  real_T rtb_Gain1_cz[6];
  real_T rtb_Gain2_iw[6];
  real_T rtb_Gain3_e[6];
  real_T rtb_AssignmenttoLongitudinal_j[6];
  real_T rtb_tas_o;
  real_T rtb_Relay;
  real_T rtb_FromWorkspace_j;
  real_T rtb_beta_360;
  real_T rtb_accels_cg[3];
  real_T rtb_Gain_i1;
  real_T rtb_Reshape1_gm[6];
  real_T rtb_S;
  real_T rtb_tratio;
  real_T rtb_Constant1;
  real_T rtb_sec_per_min;
  real_T rtb_Mach;
  real_T rtb_Rslant_d;
  real_T rtb_LeftRollSpoilerSchedule_d;
  real_T rtb_RightRollSpoilerSchedule_k;
  real_T rtb_RPMref_2_FuelFlow_e;
  real_T rtb_FuelPumpVoltage_p;
  real_T rtb_LengON_j[6];
  real_T rtb_RPMref_2_FuelFlow_j;
  real_T rtb_FuelPumpVoltage_k;
  real_T rtb_RengON_m[6];
  real_T rtb_FromWorkspace_c;
  real_T rtb_Product_pp[6];
  real_T rtb_Product_oq[6];
  real_T rtb_NegateLateral_o[6];
  real_T rtb_InterpolationUsingPreloo_km[6];
  real_T rtb_Product_py[6];
  real_T rtb_Product_jg[6];
  real_T rtb_Product_dg[6];
  real_T rtb_Product_al[6];
  real_T rtb_AssignmenttoLongitudinal_ju[6];
  real_T rtb_Gain_eps[6];
  real_T rtb_Gain_ggw[6];
  real_T rtb_Gain_jt[6];
  real_T rtb_Gain_pb[6];
  real_T rtb_Gain_jo[6];
  real_T rtb_Gain1_p4[6];
  real_T rtb_Gain2_b[6];
  real_T rtb_Gain3_dl[6];
  real_T rtb_AssignmenttoLongitudinal_ek[6];
  real_T rtb_tas_d;
  real_T rtb_NEhdot_p[3];
  real_T rtb_pqrdot_m[3];
  real_T rtb_Gain4_kx[4];
  real_T rtb_Gain_g5u;
  real_T rtb_Reshape1_i3[6];
  real_T rtb_S_o;
  real_T rtb_tratio_h;
  real_T rtb_Constant1_j;
  real_T rtb_sec_per_min_c;
  real_T rtb_Mach_k;
  real_T rtb_accels_cg_h[3];
  real_T rtb_NEhdot_j[3];
  real_T rtb_pqrdot_a[3];
  real_T rtb_Gain4_a[4];
  real_T rtb_Gain_ng;
  real_T rtb_Reshape1_hn[6];
  real_T rtb_S_b;
  real_T rtb_tratio_g;
  real_T rtb_Constant1_m;
  real_T rtb_sec_per_min_n;
  real_T rtb_Mach_g;
  real_T rtb_Rslant_o;
  real_T rtb_orderatts_j[3];
  real_T rtb_orderatts_e[3];
  real_T rtb_Assignment2_b[13];
  real_T rtb_LeftRollSpoilerSchedule_p;
  real_T rtb_RightRollSpoilerSchedule_m;
  real_T rtb_RPMref_2_FuelFlow_g;
  real_T rtb_FuelPumpVoltage_o;
  real_T rtb_LengON_o[6];
  real_T rtb_RPMref_2_FuelFlow_g1;
  real_T rtb_FuelPumpVoltage_d;
  real_T rtb_RengON_d[6];
  real_T rtb_FromWorkspace_o;
  real_T rtb_Product_hs[6];
  real_T rtb_Product_b2[6];
  real_T rtb_NegateLateral_d[6];
  real_T rtb_InterpolationUsingPreloo_nc[6];
  real_T rtb_Product_ij[6];
  real_T rtb_Product_nh[6];
  real_T rtb_Product_eb[6];
  real_T rtb_Product_nz[6];
  real_T rtb_AssignmenttoLongitudinal_n[6];
  real_T rtb_Gain_f4[6];
  real_T rtb_Gain_kl[6];
  real_T rtb_Gain_fa[6];
  real_T rtb_Gain_oi[6];
  real_T rtb_Gain_nr[6];
  real_T rtb_Gain1_ic[6];
  real_T rtb_Gain2_eg[6];
  real_T rtb_Gain3_jm[6];
  real_T rtb_AssignmenttoLongitudinal_d[6];
  real_T rtb_tas_b;
  real_T rtb_accels_cg_c[3];
  real_T rtb_NEhdot_f[3];
  real_T rtb_pqrdot_g[3];
  real_T rtb_Gain4_am[4];
  real_T rtb_Gain_mq;
  real_T rtb_Reshape1_l[6];
  real_T rtb_S_c;
  real_T rtb_tratio_n;
  real_T rtb_Constant1_o;
  real_T rtb_sec_per_min_h;
  real_T rtb_Mach_n;
  real_T rtb_minerr;
  real_T rtb_scale;
  real_T rtb_LeftRollSpoilerSchedule_n;
  real_T rtb_RightRollSpoilerSchedule_i;
  real_T rtb_RPMref_2_FuelFlow_n1;
  real_T rtb_FuelPumpVoltage_h;
  real_T rtb_LengON_i[6];
  real_T rtb_RPMref_2_FuelFlow_f;
  real_T rtb_FuelPumpVoltage_a;
  real_T rtb_RengON_o[6];
  real_T rtb_FromWorkspace_f;
  real_T rtb_Product_pz[6];
  real_T rtb_Product_o3[6];
  real_T rtb_NegateLateral_bi[6];
  real_T rtb_InterpolationUsingPreloo_pu[6];
  real_T rtb_Product_go[6];
  real_T rtb_Product_j5[6];
  real_T rtb_Product_lm[6];
  real_T rtb_Product_m0[6];
  real_T rtb_AssignmenttoLongitudinal_kv[6];
  real_T rtb_Gain_ex[6];
  real_T rtb_Gain_o1[6];
  real_T rtb_Gain_oa[6];
  real_T rtb_Gain_nw[6];
  real_T rtb_Gain_ez[6];
  real_T rtb_Gain1_os[6];
  real_T rtb_Gain2_dt[6];
  real_T rtb_Gain3_o2[6];
  real_T rtb_AssignmenttoLongitudinal_b[6];
  real_T rtb_tas_bc;
  real_T rtb_accels_cg_k[3];
  real_T rtb_NEhdot_i[3];
  real_T rtb_uvwdot_d[3];
  real_T rtb_Gain4_j[4];
  real_T rtb_Gain_pr;
  real_T rtb_Reshape1_nw[6];
  real_T rtb_S_a;
  real_T rtb_tratio_f;
  real_T rtb_Constant1_f;
  real_T rtb_sec_per_min_o;
  real_T rtb_Mach_h;
  uint32_T rtb_DataTypeConversion_d;
  uint32_T rtb_DataTypeConversion_c;
  uint32_T rtb_DataTypeConversion_e;
  uint32_T rtb_DataTypeConversion_p;
  uint32_T rtb_DataTypeConversion_o;
  uint32_T rtb_DataTypeConversion_g;
  uint32_T rtb_DataTypeConversion_k;
  uint32_T rtb_DataTypeConversion_h;
  uint32_T rtb_DataTypeConversion_dh;
  uint32_T rtb_DataTypeConversion_j;

  /* local scratch DWork variables */
  real_T Product_DWORK1[9];
  real_T Product_DWORK3[9];
  int32_T Product_DWORK2[3];

  {
    real_T eml_p[2];
    real_T eml_A[4];
    boolean_T eml_b;
    real_T rtb_MultiportSwitch1_d[10];
    real_T rtb_control_input[114];
    real_T rtb_xdot_nom[13];
    real_T rtb_MultiportSwitch_oq[18];
    real_T rtb_Sum2_ht[3];
    real_T rtb_NEh_e[3];
    real_T rtb_w_est[3];
    real_T rtb_NED_wind_ex[3];
    real_T rtb_Sum2[3];
    real_T rtb_DiscreteTimeIntegrator[3];
    real_T rtb_accels_cg_b[3];
    real_T rtb_att_type;
    int32_T rtb_enable_bb;
    int32_T yOffset;
    int32_T uDimIdx;
    real_T rtb_UnitDelay1_j;
    int32_T rtb_LogicalOperator4_h;
    int32_T rtb_LogicalOperator2;
    real_T rtb_Assignment1[6];
    real_T rtb_Saturation1;
    real_T rtb_e1e2;
    real_T rtb_e3e1;
    real_T rtb_e2e3;
    real_T rtb_e0e3;
    real_T rtb_e0e2;
    real_T rtb_e0e1;
    real_T rtb_Saturation;
    boolean_T rtb_Compare_la;
    real_T rtb_uvw[3];
    real_T rtb_Gain1_n[4];
    real_T rtb_e1e2_k;
    real_T rtb_e3e1_k;
    real_T rtb_e2e3_k;
    real_T rtb_e0e3_g;
    real_T rtb_e0e2_e;
    real_T rtb_e0e1_k;
    real_T rtb_Product[3];
    real_T rtb_Sum1_c[3];
    real_T min[3];
    real_T min_0[3];
    real_T rtb_Sum2_m[3];
    real_T max[3];
    real_T rtb_MathFunction_l;
    real_T rtb_MathFunction1;
    real_T max_0;
    real_T rtb_TrigonometricFunction1;
    real_T rtb_Rground;
    real_T rtb_elevation;
    real_T rtb_TrigonometricFunction3;
    real_T rtb_TrigonometricFunction1_n;
    real_T rtb_u20;
    boolean_T rtb_LogicalOperator_o;
    real_T max_1;
    real_T rtb_argmax1[6];
    real_T rtb_MultiportSwitch1_l;
    uint8_T rtb_FixPtRelationalOperator_h;
    real_T rtb_TrigonometricFunction_o;
    real_T rtb_TrigonometricFunction2;
    real_T rtb_azimuth;
    real_T rtb_TrigonometricFunction4;
    real_T rtb_Product2;
    real_T rtb_TrigonometricFunction5;
    real_T rtb_Product9;
    real_T rtb_Product4;
    real_T rtb_Product7;
    int32_T yOffset_0;
    int32_T rtb_LogicalOperator4_i;
    boolean_T rtb_Compare_m;
    boolean_T rtb_LogicalOperator_p;
    real_T rtb_Switch1;
    real_T rtb_Sum3_e;
    real_T max_2;
    uint32_T locIndex;
    uint32_T scalarIndex;
    real_T scalarFraction;
    boolean_T rtb_Compare_df;
    real_T scalarFraction_0;
    int32_T rtb_LogicalOperator;
    real_T rtb_u_old[10];
    real_T rtb_MultiportSwitch[10];
    real_T rtb_fuel;
    real_T rtb_Assignment1_n[10];
    real_T min_1[10];
    real_T rtb_Sum2_b[10];
    real_T max_3[10];
    real_T rtb_Sum1_l[10];
    real_T min_2[10];
    real_T rtb_MultiportSwitch1_i[10];
    real_T rtb_Assignment[10];
    real_T rtb_Sum1_b[10];
    real_T rtb_MultiportSwitch2_d;
    real_T rtb_MatrixConcatenation[12];
    real_T rtb_Product_e;
    real_T rtb_Switch_n;
    real_T min_3;
    boolean_T rtb_LogicalOperator1_f;
    real_T rtb_MatrixConcatenation_j[12];
    real_T rtb_e1e2_n;
    real_T rtb_e3e1_d;
    real_T rtb_e2e3_h;
    real_T rtb_e0e3_b;
    real_T rtb_e0e2_d;
    real_T rtb_e0e1_j;
    real_T rtb_UnitDelay_n[5];
    real_T rtb_Sum2_m5;
    real_T max_4;
    real_T rtb_Sum1_d;
    real_T min_4;
    real_T rtb_Rground_i;
    real_T rtb_elevation_d;
    real_T rtb_TrigonometricFunction3_k;
    real_T rtb_azimuth_k;
    real_T rtb_TrigonometricFunction5_o;
    real_T rtb_TrigonometricFunction2_a;
    real_T rtb_TrigonometricFunction_p;
    real_T rtb_Product9_a;
    real_T rtb_TrigonometricFunction4_h;
    real_T rtb_TrigonometricFunction1_e;
    real_T rtb_Product2_j;
    real_T rtb_Product7_m;
    real_T rtb_Product4_f;
    real_T rtb_e1e2_j;
    real_T rtb_e3e1_c;
    real_T rtb_e2e3_d;
    real_T rtb_e0e3_go;
    real_T rtb_e0e2_a;
    real_T rtb_e0e1_k5;
    real_T rtb_Rground_f;
    real_T rtb_zeropqr[13];
    real_T rtb_TmpHiddenBufferAtorderattsI[3];
    real_T rtb_Gain_l[16];
    real_T rtb_TmpHiddenBufferAtselectbest[4];
    real_T rtb_selectbestdiag;
    real_T rtb_MathFunction_eu;
    real_T rtb_TmpHiddenBufferAtAssignment[7];
    real_T rtb_Gain1_oy[4];
    real_T rtb_e1e2_i;
    real_T rtb_e3e1_e;
    real_T rtb_e2e3_e;
    real_T rtb_e0e3_n;
    real_T rtb_e0e2_k;
    real_T rtb_e0e1_m;
    real_T rtb_dL_Ail;
    real_T rtb_dR_Ail;
    real_T rtb_MultiportSwitch1_h2[10];
    real_T rtb_usethrotestimatefrommeasure[10];
    real_T rtb_zeroRCSinputs[10];
    real_T min_5;
    real_T rtb_Assignment_a[10];
    real_T rtb_zeroratesurfs[10];
    real_T rtb_Assignment1_l[10];
    real_T rtb_Sum3_k;
    real_T rtb_ELLOBC;
    real_T rtb_ELLIBC;
    real_T rtb_ELROBC;
    real_T rtb_ELRIBC;
    real_T rtb_Sum_l;
    real_T rtb_AILLC;
    real_T rtb_AILRC;
    real_T rtb_Sum2_on;
    real_T rtb_RUDUPC;
    real_T rtb_RUDLOC;
    real_T rtb_SPLLIBC;
    real_T rtb_SPLLOBC;
    real_T rtb_Sum4_d;
    real_T rtb_GEARC;
    real_T rtb_pratio;
    real_T rtb_RPMref_2_Thrust;
    real_T rtb_Throttle_2_RPMref;
    real_T rtb_UnScale_Ref_RPM;
    real_T rtb_angularmomentum;
    real_T rtb_RPMref_2_Thrust_b;
    real_T rtb_Throttle_2_RPMref_o;
    real_T rtb_UnScale_Ref_RPM_o;
    real_T rtb_angularmomentum_g;
    real_T rtb_gwest;
    real_T rtb_Product_jx[3];
    real_T rtb_MathFunction_fc;
    real_T rtb_AlphaLookup_o2;
    real_T frac[2];
    real_T rtb_AlphaLookup1_o2;
    uint32_T rtb_AlphaLookup_o1;
    uint32_T bpIndex[3];
    uint32_T rtb_AlphaLookup1_o1;
    real_T frac_0[2];
    uint32_T bpIndex_0[3];
    real_T rtb_Switch_e;
    real_T rtb_Prelookup_o2;
    real_T frac_1[3];
    real_T rtb_Prelookup1_o2;
    real_T rtb_Prelookup2_o2;
    uint32_T rtb_Prelookup_o1;
    uint32_T bpIndex_1[4];
    uint32_T rtb_Prelookup1_o1;
    uint32_T rtb_Prelookup2_o1;
    real_T rtb_Assignmenttolateral[6];
    real_T rtb_InterpolationUsingPrelook_m[6];
    real_T rtb_Switch_ei;
    real_T rtb_Prelookup_o2_k;
    real_T frac_2[3];
    real_T rtb_Prelookup1_o2_m;
    real_T rtb_Prelookup2_o2_a;
    uint32_T rtb_Prelookup_o1_c;
    uint32_T bpIndex_2[4];
    uint32_T rtb_Prelookup1_o1_m;
    uint32_T rtb_Prelookup2_o1_f;
    real_T rtb_Assignmenttolateral_k[6];
    real_T rtb_InterpolationUsingPrelook_a[6];
    real_T rtb_Prelookup1_o2_h;
    real_T frac_3[3];
    real_T rtb_Prelookup2_o2_m;
    real_T rtb_Prelookup3_o2;
    uint32_T rtb_Prelookup1_o1_j;
    uint32_T bpIndex_3[4];
    uint32_T rtb_Prelookup2_o1_p;
    uint32_T rtb_Prelookup3_o1;
    real_T rtb_InterpolationUsingPreloo_hb[6];
    real_T frac_4[3];
    real_T rtb_Prelookup4_o2;
    real_T rtb_Prelookup5_o2;
    uint32_T bpIndex_4[4];
    uint32_T rtb_Prelookup4_o1;
    uint32_T rtb_Prelookup5_o1;
    real_T rtb_Prelookup1_o2_n;
    real_T frac_5[3];
    real_T rtb_Prelookup2_o2_h;
    real_T rtb_Prelookup3_o2_o;
    uint32_T rtb_Prelookup1_o1_e;
    uint32_T bpIndex_5[4];
    uint32_T rtb_Prelookup2_o1_l;
    uint32_T rtb_Prelookup3_o1_i;
    real_T rtb_InterpolationUsingPrelook_f[6];
    real_T rtb_Prelookup1_o2_b;
    real_T frac_6[3];
    real_T rtb_Prelookup2_o2_aw;
    real_T rtb_Prelookup3_o2_a;
    uint32_T rtb_Prelookup1_o1_g;
    uint32_T bpIndex_6[4];
    uint32_T rtb_Prelookup2_o1_e;
    uint32_T rtb_Prelookup3_o1_e;
    real_T rtb_InterpolationUsingPrelook_l[6];
    real_T frac_7[3];
    real_T rtb_Prelookup4_o2_f;
    real_T rtb_Prelookup5_o2_b;
    uint32_T bpIndex_7[4];
    uint32_T rtb_Prelookup4_o1_e;
    uint32_T rtb_Prelookup5_o1_a;
    real_T rtb_InterpolationUsingPrelook_e[6];
    real_T frac_8[3];
    real_T rtb_Prelookup4_o2_h;
    real_T rtb_Prelookup5_o2_m;
    uint32_T bpIndex_8[4];
    uint32_T rtb_Prelookup4_o1_d;
    uint32_T rtb_Prelookup5_o1_h;
    real_T rtb_InterpolationUsingPreloo_ah[6];
    real_T rtb_Prelookup1_o2_c;
    real_T frac_9[4];
    real_T rtb_Prelookup2_o2_hn;
    real_T rtb_Prelookup3_o2_oe;
    real_T rtb_Prelookup4_o2_ha;
    uint32_T rtb_Prelookup1_o1_l;
    uint32_T bpIndex_9[5];
    uint32_T rtb_Prelookup2_o1_n;
    uint32_T rtb_Prelookup3_o1_k;
    uint32_T rtb_Prelookup4_o1_j;
    real_T frac_a[4];
    real_T rtb_Prelookup4_o2_c;
    uint32_T bpIndex_a[5];
    uint32_T rtb_Prelookup4_o1_ev;
    real_T rtb_AssignmenttoLongitudinal_a[6];
    real_T frac_b[4];
    real_T rtb_Prelookup4_o2_k;
    uint32_T bpIndex_b[5];
    uint32_T rtb_Prelookup4_o1_d4;
    real_T rtb_AssignmenttoLongitudinal_e[6];
    real_T frac_c[4];
    real_T rtb_Prelookup4_o2_hx;
    uint32_T bpIndex_c[5];
    uint32_T rtb_Prelookup4_o1_h;
    real_T rtb_AssignmenttoLongitudinal_e0[6];
    real_T frac_d[4];
    real_T rtb_Prelookup4_o2_m;
    uint32_T bpIndex_d[5];
    uint32_T rtb_Prelookup4_o1_h0;
    real_T rtb_AssignmenttoLongitudinal_m[6];
    int32_T scalarPrevIndex;
    int32_T scalarIndex_0;
    real_T scalarFraction_1;
    real_T rtb_Reshape_c[6];
    real_T rtb_MathFunction1_k;
    real_T max_5;
    real_T rtb_qbar_p;
    real_T rtb_Gain2_n[6];
    real_T rtb_Gain_jqu;
    real_T rtb_Divide1_l;
    real_T rtb_Gain_kg;
    real_T rtb_Divide1_e;
    real_T rtb_Gain1_kw;
    real_T scalarFraction_2;
    real_T rtb_Sum1_g;
    real_T rtb_throt_to_ff;
    real_T rtb_Gain6;
    real_T rtb_Assignment1_nx[10];
    real_T rtb_e1e2_e;
    real_T rtb_e3e1_a;
    real_T rtb_e2e3_g;
    real_T rtb_e0e3_j;
    real_T rtb_e0e2_i;
    real_T rtb_e0e1_k0;
    real_T rtb_TmpHiddenBufferAtorderatt_g[3];
    real_T rtb_switchattcmd[3];
    real_T rtb_Product_bh[3];
    real_T rtb_switchthrotcmd;
    real_T rtb_MultiportSwitch2_i;
    real_T rtb_dL_Ail_m;
    real_T rtb_dR_Ail_p;
    real_T rtb_Sum3_fp;
    real_T rtb_ELLOBC_g;
    real_T rtb_ELLIBC_o;
    real_T rtb_ELROBC_g;
    real_T rtb_ELRIBC_o;
    real_T rtb_Sum_fu;
    real_T rtb_AILLC_a;
    real_T rtb_AILRC_d;
    real_T rtb_Sum2_kr;
    real_T rtb_RUDUPC_e;
    real_T rtb_RUDLOC_l;
    real_T rtb_SPLLIBC_k;
    real_T rtb_SPLLOBC_l;
    real_T rtb_Sum4_n;
    real_T rtb_GEARC_l;
    real_T rtb_pratio_m;
    real_T rtb_RPMref_2_Thrust_k;
    real_T rtb_Throttle_2_RPMref_n;
    real_T rtb_UnScale_Ref_RPM_f;
    real_T rtb_angularmomentum_f;
    real_T rtb_RPMref_2_Thrust_l;
    real_T rtb_Throttle_2_RPMref_l;
    real_T rtb_UnScale_Ref_RPM_e;
    real_T rtb_angularmomentum_e;
    real_T rtb_gwest_i;
    real_T rtb_Product_a[3];
    real_T rtb_AlphaLookup_o2_m;
    real_T frac_e[2];
    real_T rtb_AlphaLookup1_o2_o;
    uint32_T rtb_AlphaLookup_o1_g;
    uint32_T bpIndex_e[3];
    uint32_T rtb_AlphaLookup1_o1_j;
    real_T frac_f[2];
    uint32_T bpIndex_f[3];
    real_T rtb_Switch_ky;
    real_T rtb_Prelookup_o2_e;
    real_T frac_g[3];
    real_T rtb_Prelookup1_o2_hd;
    real_T rtb_Prelookup2_o2_i;
    uint32_T rtb_Prelookup_o1_b;
    uint32_T bpIndex_g[4];
    uint32_T rtb_Prelookup1_o1_i;
    uint32_T rtb_Prelookup2_o1_o;
    real_T rtb_Assignmenttolateral_i[6];
    real_T rtb_InterpolationUsingPreloo_nw[6];
    real_T rtb_Switch_c;
    real_T rtb_Prelookup_o2_g;
    real_T frac_h[3];
    real_T rtb_Prelookup1_o2_l;
    real_T rtb_Prelookup2_o2_j;
    uint32_T rtb_Prelookup_o1_be;
    uint32_T bpIndex_h[4];
    uint32_T rtb_Prelookup1_o1_n;
    uint32_T rtb_Prelookup2_o1_j;
    real_T rtb_Assignmenttolateral_a[6];
    real_T rtb_InterpolationUsingPreloo_a0[6];
    real_T rtb_Prelookup1_o2_i;
    real_T frac_i[3];
    real_T rtb_Prelookup2_o2_l;
    real_T rtb_Prelookup3_o2_f;
    uint32_T rtb_Prelookup1_o1_h;
    uint32_T bpIndex_i[4];
    uint32_T rtb_Prelookup2_o1_po;
    uint32_T rtb_Prelookup3_o1_g;
    real_T rtb_InterpolationUsingPreloo_hj[6];
    real_T frac_j[3];
    real_T rtb_Prelookup4_o2_j;
    real_T rtb_Prelookup5_o2_b2;
    uint32_T bpIndex_j[4];
    uint32_T rtb_Prelookup4_o1_l;
    uint32_T rtb_Prelookup5_o1_o;
    real_T rtb_Prelookup1_o2_cb;
    real_T frac_k[3];
    real_T rtb_Prelookup2_o2_o;
    real_T rtb_Prelookup3_o2_k;
    uint32_T rtb_Prelookup1_o1_jh;
    uint32_T bpIndex_k[4];
    uint32_T rtb_Prelookup2_o1_ne;
    uint32_T rtb_Prelookup3_o1_f;
    real_T rtb_InterpolationUsingPreloo_ex[6];
    real_T rtb_Prelookup1_o2_o;
    real_T frac_l[3];
    real_T rtb_Prelookup2_o2_is;
    real_T rtb_Prelookup3_o2_n;
    uint32_T rtb_Prelookup1_o1_d;
    uint32_T bpIndex_l[4];
    uint32_T rtb_Prelookup2_o1_fc;
    uint32_T rtb_Prelookup3_o1_gn;
    real_T rtb_InterpolationUsingPrelook_k[6];
    real_T frac_m[3];
    real_T rtb_Prelookup4_o2_fh;
    real_T rtb_Prelookup5_o2_d;
    uint32_T bpIndex_m[4];
    uint32_T rtb_Prelookup4_o1_a;
    uint32_T rtb_Prelookup5_o1_at;
    real_T rtb_InterpolationUsingPrelook_d[6];
    real_T frac_n[3];
    real_T rtb_Prelookup4_o2_i;
    real_T rtb_Prelookup5_o2_e;
    uint32_T bpIndex_n[4];
    uint32_T rtb_Prelookup4_o1_b;
    uint32_T rtb_Prelookup5_o1_n;
    real_T rtb_InterpolationUsingPreloo_b4[6];
    real_T rtb_Prelookup1_o2_e;
    real_T frac_o[4];
    real_T rtb_Prelookup2_o2_p;
    real_T rtb_Prelookup3_o2_d;
    real_T rtb_Prelookup4_o2_o;
    uint32_T rtb_Prelookup1_o1_gm;
    uint32_T bpIndex_o[5];
    uint32_T rtb_Prelookup2_o1_m;
    uint32_T rtb_Prelookup3_o1_kp;
    uint32_T rtb_Prelookup4_o1_i;
    real_T frac_p[4];
    real_T rtb_Prelookup4_o2_iq;
    uint32_T bpIndex_p[5];
    uint32_T rtb_Prelookup4_o1_p;
    real_T rtb_AssignmenttoLongitudinal_c[6];
    real_T frac_q[4];
    real_T rtb_Prelookup4_o2_kp;
    uint32_T bpIndex_q[5];
    uint32_T rtb_Prelookup4_o1_it;
    real_T rtb_AssignmenttoLongitudinal_k[6];
    real_T frac_r[4];
    real_T rtb_Prelookup4_o2_hz;
    uint32_T bpIndex_r[5];
    uint32_T rtb_Prelookup4_o1_jp;
    real_T rtb_AssignmenttoLongitudinal_hb[6];
    real_T frac_s[4];
    real_T rtb_Prelookup4_o2_n;
    uint32_T bpIndex_s[5];
    uint32_T rtb_Prelookup4_o1_m;
    real_T rtb_AssignmenttoLongitudinal_p[6];
    int32_T scalarPrevIndex_0;
    real_T scalarFraction_3;
    real_T rtb_Reshape_o[6];
    real_T rtb_Gain2_oj[6];
    real_T rtb_Product2_e4[3];
    real_T rtb_pqrdot[3];
    real_T rtb_MatrixConcatenation_i[12];
    real_T rtb_TmpHiddenBufferAtAssignme_a[9];
    int32_T rtb_LogicalOperator_g;
    real_T max_6[9];
    real_T max_7[9];
    real_T min_6[6];
    real_T rtb_MultiportSwitch1_ik[9];
    real_T rtb_Assignment_b[9];
    real_T rtb_UnitDelay2_o[9];
    real_T rtb_Sum2_fu[9];
    real_T rtb_TmpHiddenBufferAtAssignme_j[9];
    real_T rtb_MultiportSwitch2_o[9];
    real_T rtb_Assignment1_d5[9];
    real_T rtb_Sum1_f[9];
    real_T rtb_Assignment_f[10];
    real_T rtb_Sum2_d3[8];
    real_T max_8[8];
    real_T rtb_Sum1_eb[8];
    real_T min_7[8];
    real_T rtb_Gain1_b1[4];
    real_T rtb_e1e2_c;
    real_T rtb_e3e1_j;
    real_T rtb_e2e3_f;
    real_T rtb_e0e3_h;
    real_T rtb_e0e2_da;
    real_T rtb_e0e1_o;
    real_T rtb_MultiportSwitch2_j[10];
    real_T rtb_Assignment1_d[10];
    real_T rtb_MultiportSwitch_cn[10];
    real_T rtb_Gain1_a1;
    real_T rtb_Sum_hl[6];
    real_T rtb_SwitchControl;
    real_T rtb_Gain1_dd[4];
    real_T rtb_e1e2_k5;
    real_T rtb_e3e1_ak;
    real_T rtb_e2e3_eh;
    real_T rtb_e0e3_l;
    real_T rtb_e0e2_l;
    real_T rtb_e0e1_mp;
    real_T rtb_Product_o[3];
    real_T rtb_dL_Ail_j;
    real_T rtb_dR_Ail_c;
    real_T rtb_Sum3_i;
    real_T rtb_ELLOBC_k;
    real_T rtb_ELLIBC_m;
    real_T rtb_ELROBC_gd;
    real_T rtb_ELRIBC_m;
    real_T rtb_Sum_fy;
    real_T rtb_AILLC_j;
    real_T rtb_AILRC_m;
    real_T rtb_Sum2_p0;
    real_T rtb_RUDUPC_f;
    real_T rtb_RUDLOC_c;
    real_T rtb_SPLLIBC_i;
    real_T rtb_SPLLOBC_i;
    real_T rtb_Sum4_kd;
    real_T rtb_GEARC_e;
    real_T rtb_pratio_a;
    real_T rtb_RPMref_2_Thrust_n;
    real_T rtb_Throttle_2_RPMref_c;
    real_T rtb_UnScale_Ref_RPM_fb;
    real_T rtb_angularmomentum_a;
    real_T rtb_RPMref_2_Thrust_ny;
    real_T rtb_Throttle_2_RPMref_cj;
    real_T rtb_UnScale_Ref_RPM_k;
    real_T rtb_angularmomentum_aj;
    real_T rtb_gwest_ia;
    real_T rtb_Product_ih[3];
    real_T rtb_uvw_rw_at[3];
    real_T rtb_MathFunction_nk;
    real_T rtb_AlphaLookup_o2_j;
    real_T frac_t[2];
    real_T rtb_AlphaLookup1_o2_c;
    uint32_T rtb_AlphaLookup_o1_h;
    uint32_T bpIndex_t[3];
    uint32_T rtb_AlphaLookup1_o1_n;
    real_T frac_u[2];
    uint32_T bpIndex_u[3];
    real_T rtb_Switch_i;
    real_T rtb_Prelookup_o2_gl;
    real_T frac_v[3];
    real_T rtb_Prelookup1_o2_d;
    real_T rtb_Prelookup2_o2_h1;
    uint32_T rtb_Prelookup_o1_cp;
    uint32_T bpIndex_v[4];
    uint32_T rtb_Prelookup1_o1_f;
    uint32_T rtb_Prelookup2_o1_ml;
    real_T rtb_Assignmenttolateral_l[6];
    real_T rtb_InterpolationUsingPreloo_cv[6];
    real_T rtb_Switch_c5;
    real_T rtb_Prelookup_o2_o;
    real_T frac_w[3];
    real_T rtb_Prelookup1_o2_a;
    real_T rtb_Prelookup2_o2_e;
    uint32_T rtb_Prelookup_o1_a;
    uint32_T bpIndex_w[4];
    uint32_T rtb_Prelookup1_o1_c;
    uint32_T rtb_Prelookup2_o1_j2;
    real_T rtb_Assignmenttolateral_lz[6];
    real_T rtb_InterpolationUsingPreloo_dx[6];
    real_T rtb_Prelookup1_o2_iq;
    real_T frac_x[3];
    real_T rtb_Prelookup2_o2_f;
    real_T rtb_Prelookup3_o2_c;
    uint32_T rtb_Prelookup1_o1_k;
    uint32_T bpIndex_x[4];
    uint32_T rtb_Prelookup2_o1_nh;
    uint32_T rtb_Prelookup3_o1_n;
    real_T rtb_InterpolationUsingPrelook_p[6];
    real_T frac_y[3];
    real_T rtb_Prelookup4_o2_g;
    real_T rtb_Prelookup5_o2_n;
    uint32_T bpIndex_y[4];
    uint32_T rtb_Prelookup4_o1_dz;
    uint32_T rtb_Prelookup5_o1_d;
    real_T rtb_Prelookup1_o2_cf;
    real_T frac_z[3];
    real_T rtb_Prelookup2_o2_c;
    real_T rtb_Prelookup3_o2_j;
    uint32_T rtb_Prelookup1_o1_gv;
    uint32_T bpIndex_z[4];
    uint32_T rtb_Prelookup2_o1_od;
    uint32_T rtb_Prelookup3_o1_ny;
    real_T rtb_InterpolationUsingPreloo_bk[6];
    real_T rtb_Prelookup1_o2_lm;
    real_T frac_10[3];
    real_T rtb_Prelookup2_o2_b;
    real_T rtb_Prelookup3_o2_p;
    uint32_T rtb_Prelookup1_o1_b;
    uint32_T bpIndex_10[4];
    uint32_T rtb_Prelookup2_o1_i;
    uint32_T rtb_Prelookup3_o1_a;
    real_T rtb_InterpolationUsingPreloo_gc[6];
    real_T frac_11[3];
    real_T rtb_Prelookup4_o2_c3;
    real_T rtb_Prelookup5_o2_i;
    uint32_T bpIndex_11[4];
    uint32_T rtb_Prelookup4_o1_ee;
    uint32_T rtb_Prelookup5_o1_dv;
    real_T rtb_InterpolationUsingPreloo_h3[6];
    real_T frac_12[3];
    real_T rtb_Prelookup4_o2_hf;
    real_T rtb_Prelookup5_o2_p;
    uint32_T bpIndex_12[4];
    uint32_T rtb_Prelookup4_o1_lh;
    uint32_T rtb_Prelookup5_o1_g;
    real_T rtb_InterpolationUsingPreloo_j3[6];
    real_T rtb_Prelookup1_o2_cz;
    real_T frac_13[4];
    real_T rtb_Prelookup2_o2_au;
    real_T rtb_Prelookup3_o2_b;
    real_T rtb_Prelookup4_o2_l;
    uint32_T rtb_Prelookup1_o1_d0;
    uint32_T bpIndex_13[5];
    uint32_T rtb_Prelookup2_o1_h;
    uint32_T rtb_Prelookup3_o1_p;
    uint32_T rtb_Prelookup4_o1_jk;
    real_T frac_14[4];
    real_T rtb_Prelookup4_o2_g2;
    uint32_T bpIndex_14[5];
    uint32_T rtb_Prelookup4_o1_j3;
    real_T rtb_AssignmenttoLongitudinal_g[6];
    real_T frac_15[4];
    real_T rtb_Prelookup4_o2_cc;
    uint32_T bpIndex_15[5];
    uint32_T rtb_Prelookup4_o1_p2;
    real_T rtb_AssignmenttoLongitudinal_lr[6];
    real_T frac_16[4];
    real_T rtb_Prelookup4_o2_b;
    uint32_T bpIndex_16[5];
    uint32_T rtb_Prelookup4_o1_p2x;
    real_T rtb_AssignmenttoLongitudinal_a2[6];
    real_T frac_17[4];
    real_T rtb_Prelookup4_o2_e;
    uint32_T bpIndex_17[5];
    uint32_T rtb_Prelookup4_o1_n;
    real_T rtb_AssignmenttoLongitudinal_mh[6];
    int32_T scalarPrevIndex_1;
    real_T scalarFraction_4;
    real_T rtb_Reshape_no[6];
    real_T rtb_MathFunction1_j;
    real_T rtb_qbar_a;
    real_T rtb_Gain2_oi[6];
    real_T rtb_Sum_hv[6];
    real_T rtb_Product2_f[3];
    real_T rtb_MatrixConcatenation_d[12];
    real_T rtb_SwitchControl_h;
    real_T rtb_Sum_mp[6];
    real_T rtb_Product2_kx[3];
    real_T rtb_MatrixConcatenation_m[12];
    real_T rtb_SwitchControl_p;
    real_T rtb_Gain_c3[16];
    real_T rtb_TmpHiddenBufferAtselectbe_g[4];
    real_T rtb_selectbestdiag_o;
    real_T rtb_MathFunction_ie;
    real_T rtb_Switch1_o;
    int32_T rtb_use_bb;
    real_T rtb_timer;
    real_T rtb_MathFunction_n1;
    real_T rtb_Switch_ec;
    boolean_T rtb_Compare_ff;
    boolean_T rtb_Compare_ov;
    boolean_T rtb_Compare_e4;
    real_T rtb_AssignmenttoLateral[6];
    real_T rtb_Switch_j[6];
    real_T rtb_InterpolationUsingPrelookup[6];
    real_T rtb_Add[6];
    real_T rtb_columncounter;
    real_T rtb_MultiportSwitch_p;
    real_T rtb_d[3];
    real_T rtb_TmpHiddenBufferAtSelector1I[3];
    real_T rtb_Sum1_e5[3];
    real_T rtb_Selector4;
    real_T rtb_TmpHiddenBufferAtorderatt_k[3];
    real_T rtb_Gain_om3[16];
    real_T rtb_TmpHiddenBufferAtselectb_gg[4];
    real_T rtb_selectbestdiag_h;
    real_T rtb_MathFunction_cq;
    real_T rtb_TmpHiddenBufferAtAssignme_b[7];
    real_T rtb_Gain1_pd[4];
    real_T rtb_e1e2_if;
    real_T rtb_e3e1_i;
    real_T rtb_e2e3_n;
    real_T rtb_e0e3_k;
    real_T rtb_e0e2_g;
    real_T rtb_e0e1_kt;
    real_T rtb_dL_Ail_e;
    real_T rtb_dR_Ail_k;
    real_T rtb_Sum3_n;
    real_T rtb_ELLOBC_e;
    real_T rtb_ELLIBC_o3;
    real_T rtb_ELROBC_o;
    real_T rtb_ELRIBC_p;
    real_T rtb_Sum_ht;
    real_T rtb_AILLC_f;
    real_T rtb_AILRC_l;
    real_T rtb_Sum2_ds;
    real_T rtb_RUDUPC_h;
    real_T rtb_RUDLOC_h;
    real_T rtb_SPLLIBC_g;
    real_T rtb_SPLLOBC_c;
    real_T rtb_Sum4_a;
    real_T rtb_GEARC_m;
    real_T rtb_pratio_g;
    real_T rtb_RPMref_2_Thrust_c;
    real_T rtb_Throttle_2_RPMref_p;
    real_T rtb_UnScale_Ref_RPM_e2;
    real_T rtb_angularmomentum_l;
    real_T rtb_RPMref_2_Thrust_e;
    real_T rtb_Throttle_2_RPMref_m;
    real_T rtb_UnScale_Ref_RPM_ej;
    real_T rtb_angularmomentum_b;
    real_T rtb_gwest_c;
    real_T rtb_Product_dr[3];
    real_T rtb_MathFunction_k;
    real_T rtb_AlphaLookup_o2_e;
    real_T frac_18[2];
    real_T rtb_AlphaLookup1_o2_d;
    uint32_T rtb_AlphaLookup_o1_gx;
    uint32_T bpIndex_18[3];
    uint32_T rtb_AlphaLookup1_o1_a;
    real_T frac_19[2];
    uint32_T bpIndex_19[3];
    real_T rtb_Switch_nn;
    real_T rtb_Prelookup_o2_d;
    real_T frac_1a[3];
    real_T rtb_Prelookup1_o2_c1;
    real_T rtb_Prelookup2_o2_lu;
    uint32_T rtb_Prelookup_o1_e;
    uint32_T bpIndex_1a[4];
    uint32_T rtb_Prelookup1_o1_a;
    uint32_T rtb_Prelookup2_o1_b;
    real_T rtb_Assignmenttolateral_b[6];
    real_T rtb_InterpolationUsingPreloo_mo[6];
    real_T rtb_Switch_kl;
    real_T rtb_Prelookup_o2_dh;
    real_T frac_1b[3];
    real_T rtb_Prelookup1_o2_j;
    real_T rtb_Prelookup2_o2_k;
    uint32_T rtb_Prelookup_o1_o;
    uint32_T bpIndex_1b[4];
    uint32_T rtb_Prelookup1_o1_jc;
    uint32_T rtb_Prelookup2_o1_k;
    real_T rtb_Assignmenttolateral_d[6];
    real_T rtb_InterpolationUsingPreloo_ll[6];
    real_T rtb_Prelookup1_o2_h0;
    real_T frac_1c[3];
    real_T rtb_Prelookup2_o2_ld;
    real_T rtb_Prelookup3_o2_nz;
    uint32_T rtb_Prelookup1_o1_dk;
    uint32_T bpIndex_1c[4];
    uint32_T rtb_Prelookup2_o1_pr;
    uint32_T rtb_Prelookup3_o1_l;
    real_T rtb_InterpolationUsingPrelook_i[6];
    real_T frac_1d[3];
    real_T rtb_Prelookup4_o2_a;
    real_T rtb_Prelookup5_o2_mk;
    uint32_T bpIndex_1d[4];
    uint32_T rtb_Prelookup4_o1_g;
    uint32_T rtb_Prelookup5_o1_m;
    real_T rtb_Prelookup1_o2_o2;
    real_T frac_1e[3];
    real_T rtb_Prelookup2_o2_ms;
    real_T rtb_Prelookup3_o2_e;
    uint32_T rtb_Prelookup1_o1_ib;
    uint32_T bpIndex_1e[4];
    uint32_T rtb_Prelookup2_o1_kj;
    uint32_T rtb_Prelookup3_o1_ib;
    real_T rtb_InterpolationUsingPreloo_ev[6];
    real_T rtb_Prelookup1_o2_hj;
    real_T frac_1f[3];
    real_T rtb_Prelookup2_o2_kg;
    real_T rtb_Prelookup3_o2_ec;
    uint32_T rtb_Prelookup1_o1_j5;
    uint32_T bpIndex_1f[4];
    uint32_T rtb_Prelookup2_o1_mq;
    uint32_T rtb_Prelookup3_o1_fn;
    real_T rtb_InterpolationUsingPreloo_cp[6];
    real_T frac_1g[3];
    real_T rtb_Prelookup4_o2_na;
    real_T rtb_Prelookup5_o2_o;
    uint32_T bpIndex_1g[4];
    uint32_T rtb_Prelookup4_o1_c;
    uint32_T rtb_Prelookup5_o1_f;
    real_T rtb_InterpolationUsingPreloo_fg[6];
    real_T frac_1h[3];
    real_T rtb_Prelookup4_o2_b3;
    real_T rtb_Prelookup5_o2_il;
    uint32_T bpIndex_1h[4];
    uint32_T rtb_Prelookup4_o1_k;
    uint32_T rtb_Prelookup5_o1_l;
    real_T rtb_InterpolationUsingPreloo_jn[6];
    real_T rtb_Prelookup1_o2_n0;
    real_T frac_1i[4];
    real_T rtb_Prelookup2_o2_mr;
    real_T rtb_Prelookup3_o2_m;
    real_T rtb_Prelookup4_o2_la;
    uint32_T rtb_Prelookup1_o1_if;
    uint32_T bpIndex_1i[5];
    uint32_T rtb_Prelookup2_o1_pm;
    uint32_T rtb_Prelookup3_o1_lh;
    uint32_T rtb_Prelookup4_o1_no;
    real_T frac_1j[4];
    real_T rtb_Prelookup4_o2_mb;
    uint32_T bpIndex_1j[5];
    uint32_T rtb_Prelookup4_o1_pa;
    real_T rtb_AssignmenttoLongitudinal_ja[6];
    real_T frac_1k[4];
    real_T rtb_Prelookup4_o2_mo;
    uint32_T bpIndex_1k[5];
    uint32_T rtb_Prelookup4_o1_b3;
    real_T rtb_AssignmenttoLongitudinal_i[6];
    real_T frac_1l[4];
    real_T rtb_Prelookup4_o2_cz;
    uint32_T bpIndex_1l[5];
    uint32_T rtb_Prelookup4_o1_pd;
    real_T rtb_AssignmenttoLongitudinal_jm[6];
    real_T frac_1m[4];
    real_T rtb_Prelookup4_o2_bb;
    uint32_T bpIndex_1m[5];
    uint32_T rtb_Prelookup4_o1_di;
    real_T rtb_AssignmenttoLongitudinal_o[6];
    int32_T scalarPrevIndex_2;
    real_T scalarFraction_5;
    real_T rtb_Reshape_iq[6];
    real_T rtb_MathFunction1_if;
    real_T rtb_qbar_m;
    real_T rtb_Gain2_ij[6];
    real_T rtb_Sum_ap[6];
    real_T rtb_Product2_o[3];
    real_T rtb_MatrixConcatenation_n[12];
    real_T rtb_SwitchControl_k;
    real_T rtb_Switch_ej;
    real_T rtb_Gain_bz;
    real_T rtb_Divide1_k;
    real_T rtb_Divide_e;
    real_T rtb_Gain_he4;
    real_T rtb_Divide1_n3;
    real_T rtb_Divide_d;
    real_T rtb_AssignmenttoLateral_ox[6];
    real_T rtb_Switch_ju[6];
    real_T rtb_InterpolationUsingPreloo_fo[6];
    real_T rtb_Add_a[6];
    real_T rtb_dL_Ail_n;
    real_T rtb_dR_Ail_f;
    real_T rtb_columncounter_i;
    real_T rtb_MultiportSwitch_kx;
    real_T rtb_d_h[9];
    real_T rtb_Switch_jl[9];
    real_T rtb_Sum3_gy;
    real_T rtb_ELLOBC_n;
    real_T rtb_ELLIBC_mo;
    real_T rtb_ELROBC_gf;
    real_T rtb_ELRIBC_b;
    real_T rtb_Sum_i4;
    real_T rtb_AILLC_o;
    real_T rtb_AILRC_b;
    real_T rtb_Sum2_gxu;
    real_T rtb_RUDUPC_a;
    real_T rtb_RUDLOC_hv;
    real_T rtb_SPLLIBC_b;
    real_T rtb_SPLLOBC_d;
    real_T rtb_Sum4_g4;
    real_T rtb_GEARC_f;
    real_T rtb_pratio_c;
    real_T rtb_RPMref_2_Thrust_a;
    real_T rtb_Throttle_2_RPMref_pa;
    real_T rtb_UnScale_Ref_RPM_ee;
    real_T rtb_angularmomentum_h;
    real_T rtb_RPMref_2_Thrust_m;
    real_T rtb_Throttle_2_RPMref_i;
    real_T rtb_UnScale_Ref_RPM_h;
    real_T rtb_angularmomentum_c;
    real_T rtb_gwest_o;
    real_T rtb_Product_ia[3];
    real_T rtb_Gain1_bp[4];
    real_T rtb_e1e2_a;
    real_T rtb_e3e1_b;
    real_T rtb_e2e3_d2;
    real_T rtb_e0e3_d;
    real_T rtb_e0e2_f;
    real_T rtb_e0e1_b;
    real_T rtb_MathFunction_n1u;
    real_T rtb_AlphaLookup_o2_a;
    real_T frac_1n[2];
    real_T rtb_AlphaLookup1_o2_o3;
    uint32_T rtb_AlphaLookup_o1_b;
    uint32_T bpIndex_1n[3];
    uint32_T rtb_AlphaLookup1_o1_k;
    real_T frac_1o[2];
    uint32_T bpIndex_1o[3];
    real_T rtb_Switch_ln;
    real_T rtb_Prelookup_o2_p;
    real_T frac_1p[3];
    real_T rtb_Prelookup1_o2_g;
    real_T rtb_Prelookup2_o2_kn;
    uint32_T rtb_Prelookup_o1_bs;
    uint32_T bpIndex_1p[4];
    uint32_T rtb_Prelookup1_o1_ah;
    uint32_T rtb_Prelookup2_o1_g;
    real_T rtb_Assignmenttolateral_o[6];
    real_T rtb_InterpolationUsingPreloo_nk[6];
    real_T rtb_Switch_bz;
    real_T rtb_Prelookup_o2_ef;
    real_T frac_1q[3];
    real_T rtb_Prelookup1_o2_dq;
    real_T rtb_Prelookup2_o2_bj;
    uint32_T rtb_Prelookup_o1_h;
    uint32_T bpIndex_1q[4];
    uint32_T rtb_Prelookup1_o1_bl;
    uint32_T rtb_Prelookup2_o1_hb;
    real_T rtb_Assignmenttolateral_n[6];
    real_T rtb_InterpolationUsingPreloo_ds[6];
    real_T rtb_Prelookup1_o2_bo;
    real_T frac_1r[3];
    real_T rtb_Prelookup2_o2_ll;
    real_T rtb_Prelookup3_o2_ki;
    uint32_T rtb_Prelookup1_o1_lj;
    uint32_T bpIndex_1r[4];
    uint32_T rtb_Prelookup2_o1_eq;
    uint32_T rtb_Prelookup3_o1_e0;
    real_T rtb_InterpolationUsingPreloo_j1[6];
    real_T frac_1s[3];
    real_T rtb_Prelookup4_o2_l5;
    real_T rtb_Prelookup5_o2_a;
    uint32_T bpIndex_1s[4];
    uint32_T rtb_Prelookup4_o1_kq;
    uint32_T rtb_Prelookup5_o1_e;
    real_T rtb_Prelookup1_o2_d3;
    real_T frac_1t[3];
    real_T rtb_Prelookup2_o2_ir;
    real_T rtb_Prelookup3_o2_pb;
    uint32_T rtb_Prelookup1_o1_nx;
    uint32_T bpIndex_1t[4];
    uint32_T rtb_Prelookup2_o1_gu;
    uint32_T rtb_Prelookup3_o1_gf;
    real_T rtb_InterpolationUsingPrelo_fie[6];
    real_T rtb_Prelookup1_o2_j4;
    real_T frac_1u[3];
    real_T rtb_Prelookup2_o2_bz;
    real_T rtb_Prelookup3_o2_h;
    uint32_T rtb_Prelookup1_o1_ke;
    uint32_T bpIndex_1u[4];
    uint32_T rtb_Prelookup2_o1_ok;
    uint32_T rtb_Prelookup3_o1_h;
    real_T rtb_InterpolationUsingPrelo_mic[6];
    real_T frac_1v[3];
    real_T rtb_Prelookup4_o2_e3;
    real_T rtb_Prelookup5_o2_bn;
    uint32_T bpIndex_1v[4];
    uint32_T rtb_Prelookup4_o1_d5;
    uint32_T rtb_Prelookup5_o1_hq;
    real_T rtb_InterpolationUsingPreloo_jx[6];
    real_T frac_1w[3];
    real_T rtb_Prelookup4_o2_gw;
    real_T rtb_Prelookup5_o2_g;
    uint32_T bpIndex_1w[4];
    uint32_T rtb_Prelookup4_o1_np;
    uint32_T rtb_Prelookup5_o1_mx;
    real_T rtb_InterpolationUsingPreloo_o1[6];
    real_T rtb_Prelookup1_o2_p;
    real_T frac_1x[4];
    real_T rtb_Prelookup2_o2_ey;
    real_T rtb_Prelookup3_o2_i;
    real_T rtb_Prelookup4_o2_fx;
    uint32_T rtb_Prelookup1_o1_dq;
    uint32_T bpIndex_1x[5];
    uint32_T rtb_Prelookup2_o1_nhy;
    uint32_T rtb_Prelookup3_o1_ig;
    uint32_T rtb_Prelookup4_o1_ao;
    real_T frac_1y[4];
    real_T rtb_Prelookup4_o2_mk;
    uint32_T bpIndex_1y[5];
    uint32_T rtb_Prelookup4_o1_o;
    real_T rtb_AssignmenttoLongitudinal_f[6];
    real_T frac_1z[4];
    real_T rtb_Prelookup4_o2_i4;
    uint32_T bpIndex_1z[5];
    uint32_T rtb_Prelookup4_o1_ah;
    real_T rtb_AssignmenttoLongitudinal_m1[6];
    real_T frac_20[4];
    real_T rtb_Prelookup4_o2_kc;
    uint32_T bpIndex_20[5];
    uint32_T rtb_Prelookup4_o1_gu;
    real_T rtb_AssignmenttoLongitudinal_hl[6];
    real_T frac_21[4];
    real_T rtb_Prelookup4_o2_oj;
    uint32_T bpIndex_21[5];
    uint32_T rtb_Prelookup4_o1_f;
    real_T rtb_AssignmenttoLongitudinal_h5[6];
    int32_T scalarPrevIndex_3;
    real_T scalarFraction_6;
    real_T rtb_Reshape_h3[6];
    real_T rtb_MathFunction1_f;
    real_T rtb_qbar_b;
    real_T rtb_Gain2_dg[6];
    real_T rtb_Product2_aq[3];
    real_T rtb_Sum1_ku[9];
    real_T rtb_Selector4_m;
    real_T rtb_Sum_aw[6];
    real_T rtb_MatrixConcatenation_ik[12];
    real_T rtb_SwitchControl_i;
    real_T rtb_Switch1_o2;
    real_T rtb_Sum4_j[8];
    real_T rtb_Assignment1_m[10];
    real_T rtb_TmpHiddenBufferAtAssignme_m[10];
    real_T rtb_Switch_h[6];
    real_T rtb_AssignmenttoLateral_m[6];
    real_T rtb_Switch_be[6];
    real_T rtb_InterpolationUsingPrelook_o[6];
    real_T rtb_Add_c[6];
    real_T rtb_Switch_p[6];
    real_T rtb_Switch_f5[6];
    real_T rtb_AssignmenttoLateral_o[6];
    real_T rtb_Switch_ce[6];
    real_T rtb_InterpolationUsingPreloo_gx[6];
    real_T rtb_Add_g[6];
    real_T rtb_Switch_ke[6];
    real_T rtb_Rground_k;
    real_T rtb_elevation_g;
    real_T rtb_TrigonometricFunction3_a;
    real_T rtb_azimuth_b;
    real_T rtb_TrigonometricFunction5_os;
    real_T rtb_TrigonometricFunction2_k;
    real_T rtb_TrigonometricFunction_av;
    real_T rtb_Product9_n;
    real_T rtb_TrigonometricFunction4_f;
    real_T rtb_TrigonometricFunction1_ch;
    real_T rtb_Product2_ajh;
    real_T rtb_Product7_hd;
    real_T rtb_Product4_fk;
    real_T rtb_AssignmenttoLateral_of[6];
    real_T rtb_Switch_cu[6];
    real_T rtb_InterpolationUsingPreloo_bx[6];
    real_T rtb_Add_mz[6];
    real_T rtb_Switch_o[6];
    real_T rtb_debug_output[12];
    real_T rtb_rcs_cmd;
    real_T rtb_TmpHiddenBufferAtAssignme_f[7];
    real_T rtb_Sum2_jn;
    real_T rtb_Sum1_k5;
    real_T rtb_Sum2_dsp;
    real_T rtb_Product_c3[3];
    real_T rtb_Gain_j4[16];
    real_T rtb_TmpHiddenBufferAtselectbe_c[4];
    real_T rtb_selectbestdiag_e;
    real_T rtb_MathFunction_nq;
    real_T rtb_TrigonometricFunction1_a;
    real_T rtb_elevation_k;
    real_T rtb_TrigonometricFunction3_iq;
    real_T rtb_TrigonometricFunction_a;
    real_T rtb_TrigonometricFunction2_h;
    real_T rtb_azimuth_c;
    real_T rtb_TrigonometricFunction4_o;
    real_T rtb_Product2_bm;
    real_T rtb_TrigonometricFunction5_l;
    real_T rtb_Product9_d;
    real_T rtb_Product4_aq;
    real_T rtb_Product7_h;
    real_T rtb_Sum4_i;
    real_T rtb_Sum5_i4;
    real_T rtb_InterpolationnDusingPreLo_b;
    real_T rtb_Selector_f[18];
    real_T rtb_Assignment_k[27];
    real_T rtb_solve_dat[18];
    real_T rtb_Assignment_m[9];
    real_T rtb_Selector[17];
    real_T rtb_dircos[9];
    real_T rtb_Reshape_gr[9];
    real_T rtb_Gain_h[12];
    real_T rtb_selectgainset[52];
    real_T rtb_Gain_e[9];
    real_T rtb_wght_cv[9];
    real_T rtb_dircos_b[9];
    real_T rtb_Bmat_smn[24];
    real_T rtb_Gain4_i[12];
    real_T rtb_Product_hz[9];
    real_T rtb_Gain_om[9];
    real_T rtb_Gain_ah[9];
    real_T rtb_Reshape1_i[176];
    real_T rtb_Valuendx_o[6];
    real_T rtb_dircos_g[9];
    real_T rtb_Valuendx_b[6];
    real_T rtb_Valuendx_k[6];
    real_T rtb_Reshape1_gq[66];
    real_T rtb_SwitchControl_c[9];
    real_T rtb_Memory1_m[9];
    real_T rtb_dircos_m[9];
    real_T rtb_Valuendx_pi[6];
    real_T rtb_Memory1_e[27];
    real_T rtb_Selector5_a[9];
    real_T rtb_dircos_h[9];
    real_T rtb_Valuendx_p4[6];
    real_T tmp[18];
    real_T tmp_0[18];
    real_T tmp_1[18];
    real_T tmp_2[18];
    real_T tmp_3[18];
    real_T tmp_4[18];
    int32_T i;
    real_T tmp_5[3];
    real_T tmp_6[3];
    real_T tmp_7[3];
    real_T rtb_dircos_0[3];
    real_T rtb_MatrixConcatenation_j_0[4];
    real_T rtb_Gain_e_0[3];
    real_T tmp_8[16];
    real_T rtb_dircos_b_0[3];
    real_T rtb_Gain2_n_0[6];
    real_T rtb_Gain1_oy_0[9];
    real_T rtb_Sum4_j_0[9];
    real_T rtb_MultiportSwitch_cn_0[9];
    real_T rtb_dircos_b_1[3];
    real_T rtb_Gain1_idx;
    real_T rtb_Add2_idx;
    real_T eml_a_idx;
    real_T rtb_cvddes_idx;
    real_T rtb_Sum5_d_idx;
    real_T rtb_X_idx_idx;
    real_T rtb_eow_idx_idx;
    real_T rtb_Gain_g_idx;
    real_T rtb_Gain_g_idx_0;
    real_T rtb_Gain_g_idx_1;
    real_T rtb_Gain_g_idx_2;
    real_T rtb_Gain_g_idx_3;
    real_T rtb_Gain_g_idx_4;
    real_T rtb_Sum_ow_idx;
    real_T rtb_Sum_ow_idx_0;
    real_T rtb_Sum_ow_idx_1;
    real_T rtb_Sum_ow_idx_2;
    real_T rtb_Sum_kw_idx;
    real_T rtb_NE_idx;
    real_T rtb_delta_LLh_idx;
    real_T rtb_NE_idx_0;
    real_T rtb_delta_LLh_idx_0;
    real_T rtb_Gain1_idx_0;
    real_T rtb_Switch2_idx;
    real_T rtb_delta_LLh_idx_1;
    real_T rtb_Switch_idx;
    real_T rtb_Switch_idx_0;
    real_T rtb_Switch_idx_1;
    real_T rtb_Switch_idx_2;
    real_T rtb_Gain_idx;
    real_T rtb_Gain_idx_0;
    real_T rtb_Gain_idx_1;
    real_T rtb_uvw_rw_idx;
    real_T rtb_uvw_rw_idx_0;
    real_T rtb_uvw_rw_idx_1;
    real_T rtb_Sum_h_idx;
    int32_T rtb_LogicalOperator3_idx;
    int32_T rtb_LogicalOperator3_idx_0;
    int32_T rtb_LogicalOperator3_idx_1;
    real_T rtb_Switch_f_idx;
    real_T rtb_Gain1_cg_idx;
    real_T rtb_Switch_d_idx;
    real_T rtb_MultiportSwitch_o_idx;
    real_T rtb_Product5_m_idx;
    real_T rtb_Sum4_c_idx;
    real_T rtb_UnitDelay_nf_idx;
    real_T rtb_MultiportSwitch_o_idx_0;
    real_T rtb_Switch_m_idx;
    real_T rtb_orderatts_i_idx;
    real_T rtb_Gain1_lr_idx;
    real_T rtb_MultiportSwitch_n_idx;
    real_T rtb_Product5_b_idx;
    real_T rtb_Sum_f3_idx;
    real_T rtb_Gain_kp_idx;
    real_T rtb_Sum4_e_idx;
    real_T rtb_MultiportSwitch_k_idx;
    real_T rtb_MultiportSwitch_k_idx_0;
    real_T rtb_MultiportSwitch_k_idx_1;
    real_T rtb_MultiportSwitch_n_idx_0;
    real_T rtb_MultiportSwitch_n_idx_1;
    real_T rtb_MultiportSwitch_o_idx_1;
    real_T rtb_MultiportSwitch_o_idx_2;
    real_T rtb_Sum5_b_idx;
    real_T rtb_Sum5_b_idx_0;
    real_T rtb_Sum5_b_idx_1;
    real_T rtb_Sum4_li_idx;
    real_T rtb_Sum4_li_idx_0;
    real_T rtb_Sum4_li_idx_1;
    real_T rtb_Sum4_li_idx_2;
    real_T rtb_Sum5_p_idx;
    real_T rtb_Sum5_p_idx_0;
    real_T rtb_MultiportSwitch_k_idx_2;
    real_T rtb_integration1_idx;
    real_T rtb_Switch3_idx;
    real_T rtb_Switch3_idx_0;
    real_T rtb_Switch3_idx_1;
    real_T rtb_integration1_idx_0;
    real_T rtb_integration1_idx_1;
    real_T rtb_Gain1_idx_1;
    real_T rtb_NEh_idx;
    real_T rtb_NEh_idx_0;
    real_T rtb_NEh_idx_1;
    real_T rtb_MultiportSwitch2_idx;
    real_T rtb_MultiportSwitch2_idx_0;
    real_T rtb_MultiportSwitch2_idx_1;
    real_T rtb_MultiportSwitch2_idx_2;
    real_T rtb_MultiportSwitch1_idx;
    real_T rtb_MultiportSwitch1_idx_0;
    real_T rtb_MultiportSwitch1_idx_1;
    real_T rtb_attcmdintegration_idx;
    real_T rtb_Switch_f_idx_0;
    real_T rtb_Switch_f_idx_1;
    real_T rtb_InterpolationnDusingPreLo_0;
    real_T rtb_InterpolationnDusingPreLo_1;
    real_T rtb_InterpolationnDusingPreLo_2;
    int32_T rtb_LogicalOperator_n_idx;
    int32_T rtb_LogicalOperator_n_idx_0;
    int32_T rtb_LogicalOperator_n_idx_1;
    int32_T rtb_LogicalOperator_n_idx_2;
    real_T rtb_Gain4_idx;
    real_T rtb_Product2_a_idx;
    real_T rtb_Gain4_idx_0;
    real_T rtb_Product2_a_idx_0;
    real_T rtb_Gain4_idx_1;
    real_T rtb_Product2_a_idx_1;
    real_T rtb_Gain4_idx_2;
    real_T rtb_Product2_a_idx_2;
    real_T rtb_orderatts_a_idx;
    real_T rtb_orderatts_a_idx_0;
    real_T rtb_orderatts_a_idx_1;
    real_T rtb_Switch_d_idx_0;
    real_T rtb_Switch_d_idx_1;
    real_T rtb_orderatts_i_idx_0;
    real_T rtb_orderatts_i_idx_1;
    real_T rtb_UnitDelay_nf_idx_0;
    real_T rtb_InterpolationnDusingPreLo_3;
    real_T rtb_InterpolationnDusingPreLo_4;
    real_T rtb_InterpolationnDusingPreLo_5;
    real_T rtb_MathFunction_h_idx;
    real_T rtb_Product5_m_idx_0;
    real_T rtb_MathFunction_h_idx_0;
    real_T rtb_Product5_m_idx_1;
    real_T rtb_MathFunction_h_idx_1;
    real_T rtb_Sum4_c_idx_0;
    real_T rtb_Sum4_c_idx_1;
    real_T rtb_Switch_m_idx_0;
    real_T rtb_Switch_m_idx_1;
    real_T rtb_Product1_b_idx;
    real_T rtb_Product1_b_idx_0;
    real_T rtb_Product1_b_idx_1;
    real_T rtb_Add2_idx_0;
    real_T rtb_Add2_idx_1;
    real_T rtb_Gain_kp_idx_0;
    real_T rtb_Gain_kp_idx_1;
    real_T rtb_Selector1_idx;
    real_T rtb_Selector1_idx_0;
    real_T rtb_Selector2_idx;
    real_T rtb_Selector2_idx_0;
    real_T rtb_Assignment_pi_idx;
    real_T rtb_Assignment_l_idx;
    real_T rtb_Product5_b_idx_0;
    real_T rtb_Product5_b_idx_1;
    real_T rtb_MathFunction_pa_idx;
    real_T rtb_Sum_f3_idx_0;
    real_T rtb_Sum_f3_idx_1;
    real_T rtb_Sum4_e_idx_0;
    real_T rtb_Sum4_e_idx_1;
    real_T rtb_Sum1_e_idx;
    real_T rtb_MathFunction_lo_idx;
    real_T rtb_Product5_f_idx;
    real_T rtb_Sum1_e_idx_0;
    real_T rtb_MathFunction_lo_idx_0;
    real_T rtb_Product5_f_idx_0;
    real_T rtb_Sum1_e_idx_1;
    real_T rtb_MathFunction_lo_idx_1;
    real_T rtb_Product5_f_idx_1;
    real_T rtb_Sum1_e_idx_2;
    real_T rtb_MathFunction_lo_idx_2;
    real_T rtb_Product5_f_idx_2;
    real_T rtb_Sum4_l_idx;
    real_T rtb_Sum4_l_idx_0;
    real_T rtb_Sum4_l_idx_1;
    real_T rtb_Sum4_l_idx_2;
    real_T rtb_MultiportSwitch_c_idx;
    real_T rtb_MultiportSwitch_c_idx_0;
    real_T rtb_Product_j3_idx;
    real_T rtb_Product_j3_idx_0;
    real_T rtb_Product_j3_idx_1;
    real_T rtb_Product_j3_idx_2;
    real_T rtb_Product5_hf_idx;
    real_T rtb_Product5_hf_idx_0;
    real_T rtb_Product5_hf_idx_1;
    real_T rtb_Sum4_k_idx;
    real_T rtb_Sum4_k_idx_0;
    real_T rtb_Sum4_k_idx_1;
    real_T rtb_cvddes_idx_0;
    real_T rtb_dir_idx;
    real_T rtb_cvddes_idx_1;
    real_T rtb_dir_idx_0;
    real_T rtb_Sum5_d_idx_0;
    real_T rtb_Sum5_d_idx_1;
    boolean_T rtb_Compare_bh_idx;
    boolean_T rtb_Compare_bh_idx_0;
    boolean_T rtb_Compare_bh_idx_1;
    boolean_T rtb_Compare_ow_idx;
    boolean_T rtb_Compare_j_idx;
    boolean_T rtb_Compare_ow_idx_0;
    static int8_T tmp_9[2] = { 0, 1 };

    static int8_T tmp_a[7] = { 9, 10, 11, 12, 3, 4, 5 };

    static int8_T tmp_b[9] = { 0, 1, 2, 3, 4, 5, 7, 8, 9 };

    static int8_T tmp_c[10] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 6 };

    /* Outputs for atomic SubSystem: '<Root>/claw_main' incorporates:
     *  Gain: '<S650>/Matrix Gain'
     *  Math: '<S176>/Math Function'
     *  Math: '<S184>/Math Function'
     *  Math: '<S650>/Math Function'
     *  MinMax: '<S180>/MinMax'
     *  MinMax: '<S180>/MinMax1'
     *  MinMax: '<S89>/MinMax'
     *  Product: '<S650>/Product1'
     *  Product: '<S92>/Product1'
     *  Update for DiscreteIntegrator: '<S92>/att cmd integration'
     */

    /* Inport: '<S1>/sensors' incorporates:
     *  Inport: '<Root>/LOS_rate'
     *  Inport: '<Root>/NED_dot'
     *  Inport: '<Root>/NED_wind'
     *  Inport: '<Root>/Rground'
     *  Inport: '<Root>/Rslant'
     *  Inport: '<Root>/accels_cg'
     *  Inport: '<Root>/azimuth'
     *  Inport: '<Root>/e'
     *  Inport: '<Root>/elevation'
     *  Inport: '<Root>/latlonh'
     *  Inport: '<Root>/nav_ok'
     *  Inport: '<Root>/pqr'
     *  Inport: '<Root>/u_meas'
     */
    rtb_sensors[0] = claw_main_U.pqr[0];
    rtb_sensors[1] = claw_main_U.pqr[1];
    rtb_sensors[2] = claw_main_U.pqr[2];
    rtb_sensors[3] = claw_main_U.NED_dot[0];
    rtb_sensors[4] = claw_main_U.NED_dot[1];
    rtb_sensors[5] = claw_main_U.NED_dot[2];
    rtb_sensors[6] = claw_main_U.latlonh[0];
    rtb_sensors[7] = claw_main_U.latlonh[1];
    rtb_sensors[8] = claw_main_U.latlonh[2];
    rtb_sensors[9] = claw_main_U.e[0];
    rtb_sensors[10] = claw_main_U.e[1];
    rtb_sensors[11] = claw_main_U.e[2];
    rtb_sensors[12] = claw_main_U.e[3];
    rtb_sensors[13] = claw_main_U.accels_cg[0];
    rtb_sensors[14] = claw_main_U.accels_cg[1];
    rtb_sensors[15] = claw_main_U.accels_cg[2];
    rtb_sensors[16] = claw_main_U.nav_ok;
    memcpy((void *)&rtb_sensors[17], (void *)(&claw_main_U.u_meas[0]), 10U *
           (uint32_T)((char_T *)(&claw_main_U.u_meas[1]) - (char_T *)
                      (&claw_main_U.u_meas[0])));
    rtb_sensors[27] = claw_main_U.NED_wind[0];
    rtb_sensors[28] = claw_main_U.NED_wind[1];
    rtb_sensors[29] = claw_main_U.NED_wind[2];
    rtb_sensors[30] = claw_main_U.LOS_rate[0];
    rtb_sensors[31] = claw_main_U.LOS_rate[1];
    rtb_sensors[32] = claw_main_U.azimuth;
    rtb_sensors[33] = claw_main_U.elevation;
    rtb_sensors[34] = claw_main_U.Rground;
    rtb_sensors[35] = claw_main_U.Rslant;

    /* Switch: '<S426>/Switch' incorporates:
     *  Gain: '<S426>/Gain'
     *  S-Function (sfix_dot): '<S426>/Dot Product'
     *  UnitDelay: '<S332>/Unit Delay1'
     */
    rtb_delta_LLh_idx = ((rtb_sensors[9] * claw_main_DWork.UnitDelay1_DSTATE[0]
                          + rtb_sensors[10] * claw_main_DWork.UnitDelay1_DSTATE
                          [1]) + rtb_sensors[11] *
                         claw_main_DWork.UnitDelay1_DSTATE[2]) + rtb_sensors[12]
      * claw_main_DWork.UnitDelay1_DSTATE[3];
    if (rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_o3) {
      rtb_Switch_idx = rtb_sensors[9];
    } else {
      rtb_Switch_idx = claw_main_P.Gain_Gain_p * rtb_sensors[9];
    }

    if (rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_o3) {
      rtb_Switch_idx_0 = rtb_sensors[10];
    } else {
      rtb_Switch_idx_0 = claw_main_P.Gain_Gain_p * rtb_sensors[10];
    }

    if (rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_o3) {
      rtb_Switch_idx_1 = rtb_sensors[11];
    } else {
      rtb_Switch_idx_1 = claw_main_P.Gain_Gain_p * rtb_sensors[11];
    }

    if (rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_o3) {
      rtb_Switch_idx_2 = rtb_sensors[12];
    } else {
      rtb_Switch_idx_2 = claw_main_P.Gain_Gain_p * rtb_sensors[12];
    }

    /* Gain: '<S332>/Gain' */
    rtb_Gain_idx = claw_main_P.Gain_Gain_ls[0] * rtb_sensors[3];
    rtb_Gain_idx_0 = claw_main_P.Gain_Gain_ls[1] * rtb_sensors[4];
    rtb_Gain_idx_1 = claw_main_P.Gain_Gain_ls[2] * rtb_sensors[5];

    /* Inport: '<S1>/control_input' incorporates:
     *  Inport: '<Root>/CLAW_mode'
     *  Inport: '<Root>/Isp_sl'
     *  Inport: '<Root>/Isp_vacuum'
     *  Inport: '<Root>/accel_submode'
     *  Inport: '<Root>/att_rate_cmd_sw'
     *  Inport: '<Root>/att_type'
     *  Inport: '<Root>/cam_rate_cmd_sw'
     *  Inport: '<Root>/command'
     *  Inport: '<Root>/enable_bb_sw'
     *  Inport: '<Root>/enable_homing_sw'
     *  Inport: '<Root>/engaged_sw'
     *  Inport: '<Root>/full_surf_cmd'
     *  Inport: '<Root>/full_surf_cmd_sw'
     *  Inport: '<Root>/full_surf_llim'
     *  Inport: '<Root>/full_surf_lock'
     *  Inport: '<Root>/full_surf_lrlim'
     *  Inport: '<Root>/full_surf_pref'
     *  Inport: '<Root>/full_surf_pref_select'
     *  Inport: '<Root>/full_surf_pref_wght'
     *  Inport: '<Root>/full_surf_ulim'
     *  Inport: '<Root>/full_surf_urlim'
     *  Inport: '<Root>/gain_set_sw'
     *  Inport: '<Root>/int_reset_sw'
     *  Inport: '<Root>/llh_input_sw'
     *  Inport: '<Root>/nav_enable_sw'
     *  Inport: '<Root>/pre_takeoff_sw'
     *  Inport: '<Root>/reset_pos_sw'
     *  Inport: '<Root>/throt_to_ff'
     *  Inport: '<Root>/use_held_aero_obac_sw'
     *  Inport: '<Root>/wind_est_sw'
     */
    rtb_control_input[0] = claw_main_U.command[0];
    rtb_control_input[1] = claw_main_U.command[1];
    rtb_control_input[2] = claw_main_U.command[2];
    rtb_control_input[3] = claw_main_U.command[3];
    memcpy((void *)&rtb_control_input[4], (void *)(&claw_main_U.full_surf_cmd[0]),
           10U * (uint32_T)((char_T *)(&claw_main_U.full_surf_cmd[1]) - (char_T *)
            (&claw_main_U.full_surf_cmd[0])));
    memcpy((void *)&rtb_control_input[14], (void *)(&claw_main_U.full_surf_ulim
            [0]), 10U * (uint32_T)((char_T *)(&claw_main_U.full_surf_ulim[1]) -
            (char_T *)(&claw_main_U.full_surf_ulim[0])));
    memcpy((void *)&rtb_control_input[24], (void *)(&claw_main_U.full_surf_llim
            [0]), 10U * (uint32_T)((char_T *)(&claw_main_U.full_surf_llim[1]) -
            (char_T *)(&claw_main_U.full_surf_llim[0])));
    memcpy((void *)&rtb_control_input[34], (void *)
           (&claw_main_U.full_surf_urlim[0]), 10U * (uint32_T)((char_T *)
            (&claw_main_U.full_surf_urlim[1]) - (char_T *)
            (&claw_main_U.full_surf_urlim[0])));
    memcpy((void *)&rtb_control_input[44], (void *)
           (&claw_main_U.full_surf_lrlim[0]), 10U * (uint32_T)((char_T *)
            (&claw_main_U.full_surf_lrlim[1]) - (char_T *)
            (&claw_main_U.full_surf_lrlim[0])));
    memcpy((void *)&rtb_control_input[54], (void *)(&claw_main_U.full_surf_lock
            [0]), 10U * (uint32_T)((char_T *)(&claw_main_U.full_surf_lock[1]) -
            (char_T *)(&claw_main_U.full_surf_lock[0])));
    memcpy((void *)&rtb_control_input[64], (void *)
           (&claw_main_U.full_surf_pref_select[0]), 10U * (uint32_T)((char_T *)(
             &claw_main_U.full_surf_pref_select[1]) - (char_T *)
            (&claw_main_U.full_surf_pref_select[0])));
    memcpy((void *)&rtb_control_input[74], (void *)(&claw_main_U.full_surf_pref
            [0]), 10U * (uint32_T)((char_T *)(&claw_main_U.full_surf_pref[1]) -
            (char_T *)(&claw_main_U.full_surf_pref[0])));
    memcpy((void *)&rtb_control_input[84], (void *)
           (&claw_main_U.full_surf_pref_wght[0]), 10U * (uint32_T)((char_T *)
            (&claw_main_U.full_surf_pref_wght[1]) - (char_T *)
            (&claw_main_U.full_surf_pref_wght[0])));
    rtb_control_input[94] = claw_main_U.CLAW_mode;
    rtb_control_input[95] = claw_main_U.engaged_sw;
    rtb_control_input[96] = claw_main_U.accel_submode;
    rtb_control_input[97] = claw_main_U.pre_takeoff_sw;
    rtb_control_input[98] = claw_main_U.reset_pos_sw;
    rtb_control_input[99] = claw_main_U.wind_est_sw;
    rtb_control_input[100] = claw_main_U.llh_input_sw;
    rtb_control_input[101] = claw_main_U.int_reset_sw;
    rtb_control_input[102] = claw_main_U.att_type;
    rtb_control_input[103] = claw_main_U.cam_rate_cmd_sw;
    rtb_control_input[104] = claw_main_U.full_surf_cmd_sw;
    rtb_control_input[105] = claw_main_U.enable_homing_sw;
    rtb_control_input[106] = claw_main_U.att_rate_cmd_sw;
    rtb_control_input[107] = claw_main_U.nav_enable_sw;
    rtb_control_input[108] = claw_main_U.enable_bb_sw;
    rtb_control_input[109] = claw_main_U.gain_set_sw;
    rtb_control_input[110] = claw_main_U.use_held_aero_obac_sw;
    rtb_control_input[111] = claw_main_U.Isp_sl;
    rtb_control_input[112] = claw_main_U.Isp_vacuum;
    rtb_control_input[113] = claw_main_U.throt_to_ff;

    /* Switch: '<S427>/Switch3' incorporates:
     *  Logic: '<S9>/Logical Operator'
     *  UnitDelay: '<S427>/Unit Delay1'
     */
    if ((rtb_control_input[107] != 0.0) && (rtb_sensors[16] != 0.0)) {
      rtb_Switch3_idx = claw_main_DWork.UnitDelay1_DSTATE_m[0];
      rtb_Switch3_idx_0 = claw_main_DWork.UnitDelay1_DSTATE_m[1];
      rtb_Switch3_idx_1 = claw_main_DWork.UnitDelay1_DSTATE_m[2];
    } else {
      rtb_Switch3_idx = rtb_sensors[6];
      rtb_Switch3_idx_0 = rtb_sensors[7];
      rtb_Switch3_idx_1 = rtb_sensors[8];
    }

    /* Product: '<S422>/Product' incorporates:
     *  Constant: '<S422>/Constant'
     *  Gain: '<S422>/Gain1'
     *  Trigonometry: '<S422>/Trigonometric Function'
     */

    /* Gain: '<S332>/Gain1' */
    rtb_Gain1_idx = claw_main_P.Gain1_Gain_jv[0] * rtb_Switch3_idx;

    /* Sum: '<S422>/Sum' */
    rtb_delta_LLh_idx = rtb_sensors[6] - rtb_Gain1_idx;

    /* DiscreteIntegrator: '<S425>/integration1' */
    rtb_integration1_idx_0 = claw_main_DWork.integration1_DSTATE[0];
    rtb_Gain1_idx_0 = rtb_Gain1_idx;

    /* Gain: '<S332>/Gain1' */
    rtb_Gain1_idx = claw_main_P.Gain1_Gain_jv[1] * rtb_Switch3_idx_0;

    /* Sum: '<S422>/Sum' */
    rtb_delta_LLh_idx_0 = rtb_sensors[7] - rtb_Gain1_idx;

    /* DiscreteIntegrator: '<S425>/integration1' */
    rtb_integration1_idx_1 = claw_main_DWork.integration1_DSTATE[1];
    rtb_Gain1_idx_1 = rtb_Gain1_idx;

    /* Gain: '<S332>/Gain1' */
    rtb_Gain1_idx = claw_main_P.Gain1_Gain_jv[2] * rtb_Switch3_idx_1;

    /* Sum: '<S422>/Sum' */
    rtb_delta_LLh_idx_1 = rtb_sensors[8] - rtb_Gain1_idx;

    /* DiscreteIntegrator: '<S425>/integration1' */
    rtb_integration1_idx = claw_main_DWork.integration1_DSTATE[2];
    rtb_NE_idx = rtb_delta_LLh_idx * claw_main_P.Constant_Value_gn;
    rtb_NE_idx_0 = claw_main_P.Gain1_Gain_n5 * cos(rtb_Gain1_idx_0) *
      rtb_delta_LLh_idx_0;

    /* Switch: '<S332>/Switch2' incorporates:
     *  Constant: '<S332>/use_nav'
     */
    if (claw_main_P.use_nav_Value >= claw_main_P.Switch2_Threshold) {
      rtb_delta_LLh_idx = rtb_NE_idx;
      rtb_delta_LLh_idx_0 = rtb_NE_idx_0;
      rtb_Switch2_idx = rtb_delta_LLh_idx_1;
    } else {
      rtb_delta_LLh_idx = claw_main_DWork.integration1_DSTATE[0];
      rtb_delta_LLh_idx_0 = claw_main_DWork.integration1_DSTATE[1];
      rtb_Switch2_idx = claw_main_DWork.integration1_DSTATE[2];
    }

    /* Switch: '<S332>/Switch1' incorporates:
     *  UnitDelay: '<S332>/Unit Delay'
     */
    if (rtb_control_input[98] >= claw_main_P.Switch1_Threshold_p) {
      rtb_NEh_idx = rtb_delta_LLh_idx;
      rtb_NEh_idx_0 = rtb_delta_LLh_idx_0;
      rtb_NEh_idx_1 = rtb_Switch2_idx;
    } else {
      rtb_NEh_idx = claw_main_DWork.UnitDelay_DSTATE[0];
      rtb_NEh_idx_0 = claw_main_DWork.UnitDelay_DSTATE[1];
      rtb_NEh_idx_1 = claw_main_DWork.UnitDelay_DSTATE[2];
    }

    /* Sum: '<S332>/Sum' */
    rtb_NEh_e[0] = rtb_delta_LLh_idx - rtb_NEh_idx;
    rtb_NEh_e[1] = rtb_delta_LLh_idx_0 - rtb_NEh_idx_0;
    rtb_NEh_e[2] = rtb_Switch2_idx - rtb_NEh_idx_1;

    /* Outputs for atomic SubSystem: '<S78>/Subsystem' */

    /* Inport: '<S83>/In1' */
    CLAW_p_cv = rtb_sensors[0];

    /* Inport: '<S83>/In2' */
    CLAW_q_cv = rtb_sensors[1];

    /* Inport: '<S83>/In3' */
    CLAW_r_cv = rtb_sensors[2];

    /* Inport: '<S83>/In4' */
    CLAW_e0_cv = rtb_Switch_idx;

    /* Inport: '<S83>/In5' */
    CLAW_e1_cv = rtb_Switch_idx_0;

    /* Inport: '<S83>/In6' */
    CLAW_e2_cv = rtb_Switch_idx_1;

    /* Inport: '<S83>/In7' */
    CLAW_e3_cv = rtb_Switch_idx_2;

    /* Inport: '<S83>/In8' */
    CLAW_Ndot_cv = rtb_Gain_idx;

    /* Inport: '<S83>/In9' */
    CLAW_Edot_cv = rtb_Gain_idx_0;

    /* Inport: '<S83>/In10' */
    CLAW_hdot_cv = rtb_Gain_idx_1;

    /* Inport: '<S83>/In11' */
    CLAW_N_cv = rtb_NEh_e[0];

    /* Inport: '<S83>/In12' */
    CLAW_E_cv = rtb_NEh_e[1];

    /* Inport: '<S83>/In13' */
    CLAW_h_cv = rtb_NEh_e[2];

    /* end of Outputs for SubSystem: '<S78>/Subsystem' */

    /* Selector: '<S97>/Selector' incorporates:
     *  Constant: '<S97>/Constant'
     */
    yOffset = 0;
    i = 17 * (int32_T)rtb_control_input[94];
    for (yOffset_0 = 0; yOffset_0 < 17; yOffset_0++) {
      rtb_Selector[yOffset] = claw_main_P.Constant_Value_b4[i + yOffset_0];
      yOffset++;
    }

    /* UnitDelay: '<S199>/Unit Delay1' */
    rtb_UnitDelay1_j = claw_main_DWork.UnitDelay1_DSTATE_d;

    /* MultiPortSwitch: '<S95>/Multiport Switch2' incorporates:
     *  Assignment: '<S95>/Assignment'
     *  Constant: '<S128>/Constant'
     *  Constant: '<S129>/Constant'
     *  Gain: '<S129>/Gain1'
     *  Logic: '<S95>/Logical Operator4'
     *  Product: '<S129>/Product'
     *  RelationalOperator: '<S128>/Compare'
     *  SignalConversion: '<S95>/TmpHiddenBufferAtAssignmentInport2'
     *  Sum: '<S129>/Sum'
     *  Trigonometry: '<S129>/Trigonometric Function'
     */
    if (((rtb_control_input[94] == claw_main_P.Constant_Value_m1k) &&
         (rtb_control_input[100] != 0.0)) == 0) {
      rtb_MultiportSwitch2_idx = rtb_control_input[0];
      rtb_MultiportSwitch2_idx_0 = rtb_control_input[1];
      rtb_MultiportSwitch2_idx_1 = rtb_control_input[2];
      rtb_MultiportSwitch2_idx_2 = rtb_control_input[3];
    } else {
      rtb_MultiportSwitch2_idx = (rtb_control_input[0] - rtb_Gain1_idx_0) *
        claw_main_P.Constant_Value_j;
      rtb_MultiportSwitch2_idx_0 = (rtb_control_input[1] - rtb_Gain1_idx_1) *
        (claw_main_P.Gain1_Gain * cos(rtb_Gain1_idx_0));
      rtb_MultiportSwitch2_idx_1 = rtb_control_input[2];
      rtb_MultiportSwitch2_idx_2 = rtb_control_input[3] - rtb_Gain1_idx;
    }

    /* Logic: '<S92>/Logical Operator4' incorporates:
     *  Constant: '<S100>/Constant'
     *  RelationalOperator: '<S100>/Compare'
     */
    rtb_LogicalOperator4_h = ((rtb_control_input[94] ==
      claw_main_P.Constant_Value_mp) && (rtb_control_input[106] != 0.0));

    /* Logic: '<S92>/Logical Operator2' incorporates:
     *  Constant: '<S101>/Constant'
     *  Logic: '<S92>/Logical Operator1'
     *  RelationalOperator: '<S101>/Compare'
     */
    rtb_LogicalOperator2 = ((((rtb_control_input[106] != 0.0) ||
      (rtb_control_input[103] != 0.0)) != 0) && (rtb_control_input[94] >=
      claw_main_P.Constant_Value_cp));

    /* Assignment: '<S146>/Assignment1' incorporates:
     *  Constant: '<S146>/Constant1'
     *  Constant: '<S90>/priority_weighting'
     *  Selector: '<S146>/Selector'
     *  Sum: '<S146>/Sum1'
     *  UnitDelay: '<S146>/Unit Delay'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignment1[i] = claw_main_P.priority_weighting_Value[i];
    }

    rtb_Assignment1[(int32_T)claw_main_DWork.UnitDelay_DSTATE_j] =
      claw_main_P.priority_weighting_Value[(int32_T)
      claw_main_DWork.UnitDelay_DSTATE_j] + claw_main_P.Constant1_Value_d5;

    /* Gain: '<S424>/Gain1' incorporates:
     *  Math: '<S424>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
    rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
    rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_o[i] = 0.0;
      rtb_Gain1_o[i] += claw_main_P.Gain1_Gain_ac[i] * rtb_delta_LLh_idx;
      rtb_Gain1_o[i] += claw_main_P.Gain1_Gain_ac[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_o[i] += claw_main_P.Gain1_Gain_ac[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_o[i] += claw_main_P.Gain1_Gain_ac[i + 12] * rtb_Gain1_idx_0;
    }

    /* Saturate: '<S147>/Saturation1' */
    rtb_Saturation1 = rt_SATURATE(rtb_Gain1_o[1],
      claw_main_P.Saturation1_LowerSat_c, claw_main_P.Saturation1_UpperSat_b);

    /* Fcn: '<S147>/abs_cos_b' */
    if ((rtb_Saturation1 < 0.0) && (2.0 > floor(2.0))) {
      max_1 = -rt_pow_snf(-rtb_Saturation1, 2.0);
    } else {
      max_1 = rt_pow_snf(rtb_Saturation1, 2.0);
    }

    max_1 = 1.0 - max_1;
    if (max_1 < 0.0) {
      rtb_abs_cos_b = -sqrt(-max_1);
    } else {
      rtb_abs_cos_b = sqrt(max_1);
    }

    /* Product: '<S424>/e1*e2' */
    rtb_e1e2 = rtb_Switch_idx_0 * rtb_Switch_idx_1;

    /* Product: '<S424>/e3*e1' */
    rtb_e3e1 = rtb_Switch_idx_2 * rtb_Switch_idx_0;

    /* Product: '<S424>/e2*e3' */
    rtb_e2e3 = rtb_Switch_idx_1 * rtb_Switch_idx_2;

    /* Product: '<S424>/e0*e3' */
    rtb_e0e3 = rtb_Switch_idx * rtb_Switch_idx_2;

    /* Product: '<S424>/e0*e2' */
    rtb_e0e2 = rtb_Switch_idx * rtb_Switch_idx_1;

    /* Product: '<S424>/e0*e1' */
    rtb_e0e1 = rtb_Switch_idx * rtb_Switch_idx_0;

    /* Gain: '<S424>/Gain' incorporates:
     *  Sum: '<S424>/Sum'
     *  Sum: '<S424>/Sum1'
     */
    rtb_Gain_i[0] = (rtb_e1e2 + rtb_e0e3) * claw_main_P.Gain_Gain_de;
    rtb_Gain_i[1] = (rtb_e3e1 + rtb_e0e2) * claw_main_P.Gain_Gain_de;
    rtb_Gain_i[2] = (rtb_e2e3 + rtb_e0e1) * claw_main_P.Gain_Gain_de;
    rtb_Gain_i[3] = (rtb_e1e2 - rtb_e0e3) * claw_main_P.Gain_Gain_de;
    rtb_Gain_i[4] = (rtb_e3e1 - rtb_e0e2) * claw_main_P.Gain_Gain_de;
    rtb_Gain_i[5] = (rtb_e2e3 - rtb_e0e1) * claw_main_P.Gain_Gain_de;

    /* Saturate: '<S147>/Saturation' */
    rtb_Saturation = rt_SATURATE(rtb_Gain_i[4],
      claw_main_P.Saturation_LowerSat_e, claw_main_P.Saturation_UpperSat_e);

    /* Fcn: '<S147>/abs_cos_theta' */
    if ((rtb_Saturation < 0.0) && (2.0 > floor(2.0))) {
      max_1 = -rt_pow_snf(-rtb_Saturation, 2.0);
    } else {
      max_1 = rt_pow_snf(rtb_Saturation, 2.0);
    }

    max_1 = 1.0 - max_1;
    if (max_1 < 0.0) {
      rtb_abs_cos_theta = -sqrt(-max_1);
    } else {
      rtb_abs_cos_theta = sqrt(max_1);
    }

    /* RelationalOperator: '<S153>/Compare' incorporates:
     *  Constant: '<S153>/Constant'
     */
    rtb_Compare_la = (rtb_abs_cos_theta >= claw_main_P.Constant_Value_bd);

    /* Product: '<S332>/Product' incorporates:
     *  Reshape: '<S332>/Reshape'
     */
    rtb_Gain1_oy_0[0] = rtb_Gain1_o[1];
    rtb_Gain1_oy_0[1] = rtb_Gain_i[3];
    rtb_Gain1_oy_0[2] = rtb_Gain_i[1];
    rtb_Gain1_oy_0[3] = rtb_Gain_i[0];
    rtb_Gain1_oy_0[4] = rtb_Gain1_o[2];
    rtb_Gain1_oy_0[5] = rtb_Gain_i[5];
    rtb_Gain1_oy_0[6] = rtb_Gain_i[4];
    rtb_Gain1_oy_0[7] = rtb_Gain_i[2];
    rtb_Gain1_oy_0[8] = rtb_Gain1_o[3];
    for (i = 0; i < 3; i++) {
      rtb_uvw[i] = 0.0;
      rtb_uvw[i] += rtb_Gain1_oy_0[i] * rtb_sensors[3];
      rtb_uvw[i] += rtb_Gain1_oy_0[i + 3] * rtb_sensors[4];
      rtb_uvw[i] += rtb_Gain1_oy_0[i + 6] * rtb_sensors[5];
    }

    /* Gain: '<S335>/Gain1' incorporates:
     *  Math: '<S335>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
    rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
    rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_n[i] = 0.0;
      rtb_Gain1_n[i] += claw_main_P.Gain1_Gain_hj[i] * rtb_delta_LLh_idx;
      rtb_Gain1_n[i] += claw_main_P.Gain1_Gain_hj[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_n[i] += claw_main_P.Gain1_Gain_hj[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_n[i] += claw_main_P.Gain1_Gain_hj[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S335>/e1*e2' */
    rtb_e1e2_k = rtb_Switch_idx_0 * rtb_Switch_idx_1;

    /* Product: '<S335>/e3*e1' */
    rtb_e3e1_k = rtb_Switch_idx_2 * rtb_Switch_idx_0;

    /* Product: '<S335>/e2*e3' */
    rtb_e2e3_k = rtb_Switch_idx_1 * rtb_Switch_idx_2;

    /* Product: '<S335>/e0*e3' */
    rtb_e0e3_g = rtb_Switch_idx * rtb_Switch_idx_2;

    /* Product: '<S335>/e0*e2' */
    rtb_e0e2_e = rtb_Switch_idx * rtb_Switch_idx_1;

    /* Product: '<S335>/e0*e1' */
    rtb_e0e1_k = rtb_Switch_idx * rtb_Switch_idx_0;

    /* Reshape: '<S334>/Reshape' incorporates:
     *  Gain: '<S335>/Gain'
     *  Sum: '<S335>/Sum'
     *  Sum: '<S335>/Sum1'
     */
    rtb_dircos[0] = rtb_Gain1_n[1];
    rtb_dircos[1] = (rtb_e1e2_k - rtb_e0e3_g) * claw_main_P.Gain_Gain_db;
    rtb_dircos[2] = (rtb_e3e1_k + rtb_e0e2_e) * claw_main_P.Gain_Gain_db;
    rtb_dircos[3] = (rtb_e1e2_k + rtb_e0e3_g) * claw_main_P.Gain_Gain_db;
    rtb_dircos[4] = rtb_Gain1_n[2];
    rtb_dircos[5] = (rtb_e2e3_k - rtb_e0e1_k) * claw_main_P.Gain_Gain_db;
    rtb_dircos[6] = (rtb_e3e1_k - rtb_e0e2_e) * claw_main_P.Gain_Gain_db;
    rtb_dircos[7] = (rtb_e2e3_k + rtb_e0e1_k) * claw_main_P.Gain_Gain_db;
    rtb_dircos[8] = rtb_Gain1_n[3];

    /* Reshape: '<S431>/Reshape' */
    rtb_Reshape_gr[0] = rtb_Gain1_o[1];
    rtb_Reshape_gr[1] = rtb_Gain_i[3];
    rtb_Reshape_gr[2] = rtb_Gain_i[1];
    rtb_Reshape_gr[3] = rtb_Gain_i[0];
    rtb_Reshape_gr[4] = rtb_Gain1_o[2];
    rtb_Reshape_gr[5] = rtb_Gain_i[5];
    rtb_Reshape_gr[6] = rtb_Gain_i[4];
    rtb_Reshape_gr[7] = rtb_Gain_i[2];
    rtb_Reshape_gr[8] = rtb_Gain1_o[3];

    /* DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator[0] =
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0];

    /* Sum: '<S431>/Sum2' */
    rtb_Sum2[0] = claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0] - rtb_uvw[0];

    /* DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator[1] =
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1];

    /* Sum: '<S431>/Sum2' */
    rtb_Sum2[1] = claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1] - rtb_uvw[1];

    /* DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator[2] =
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2];

    /* Sum: '<S431>/Sum2' */
    rtb_Sum2[2] = claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2] - rtb_uvw[2];
    for (i = 0; i < 3; i++) {
      /* Product: '<S431>/Product' incorporates:
       *  Math: '<S431>/Math Function'
       */
      rtb_Product[i] = 0.0;
      rtb_Product[i] += rtb_Reshape_gr[3 * i] * rtb_Sum2[0];
      rtb_Product[i] += rtb_Reshape_gr[3 * i + 1] * rtb_Sum2[1];
      rtb_Product[i] += rtb_Reshape_gr[3 * i + 2] * rtb_Sum2[2];

      /* Sum: '<S521>/Sum1' incorporates:
       *  Constant: '<S520>/Constant2'
       *  Gain: '<S521>/Gain'
       *  UnitDelay: '<S520>/Unit Delay'
       */
      rtb_Sum1_c[i] = claw_main_P.Gain_Gain_n2 * claw_main_P.Constant2_Value_b[i]
        + claw_main_DWork.UnitDelay_DSTATE_j3[i];

      /* MinMax: '<S521>/MinMax3' incorporates:
       *  Constant: '<S520>/Constant1'
       */
      min[i] = rt_MINd_snf(rtb_Sum1_c[i], claw_main_P.Constant1_Value_g[i]);

      /* MinMax: '<S521>/MinMax2' incorporates:
       *  Constant: '<S520>/Constant'
       */
      min[i] = rt_MAXd_snf(min[i], claw_main_P.Constant_Value_p5[i]);

      /* MinMax: '<S520>/MinMax1' */
      min_0[i] = rt_MINd_snf(rtb_Product[i], min[i]);

      /* Sum: '<S521>/Sum2' incorporates:
       *  Constant: '<S520>/Constant3'
       *  Gain: '<S521>/Gain1'
       *  UnitDelay: '<S520>/Unit Delay'
       */
      rtb_Sum2_m[i] = claw_main_P.Gain1_Gain_hi *
        claw_main_P.Constant3_Value_ab[i] +
        claw_main_DWork.UnitDelay_DSTATE_j3[i];

      /* MinMax: '<S521>/MinMax1' incorporates:
       *  Constant: '<S520>/Constant'
       */
      min[i] = rt_MAXd_snf(rtb_Sum2_m[i], claw_main_P.Constant_Value_p5[i]);

      /* MinMax: '<S521>/MinMax' incorporates:
       *  Constant: '<S520>/Constant1'
       */
      min[i] = rt_MINd_snf(min[i], claw_main_P.Constant1_Value_g[i]);

      /* MinMax: '<S520>/MinMax' */
      max[i] = rt_MAXd_snf(min_0[i], min[i]);

      /* Product: '<S431>/Product2' incorporates:
       *  DataTypeConversion: '<S431>/Data Type Conversion'
       */
      rtb_w_est[i] = rtb_control_input[99] * max[i];
    }

    /* MultiPortSwitch: '<S333>/Multiport Switch1' incorporates:
     *  Constant: '<S333>/use_wind_est'
     */
    if ((int32_T)claw_main_P.use_wind_est_Value == 0) {
      rtb_MultiportSwitch1_idx = rtb_sensors[27];
      rtb_MultiportSwitch1_idx_0 = rtb_sensors[28];
      rtb_MultiportSwitch1_idx_1 = rtb_sensors[29];
    } else {
      rtb_MultiportSwitch1_idx = rtb_w_est[0];
      rtb_MultiportSwitch1_idx_0 = rtb_w_est[1];
      rtb_MultiportSwitch1_idx_1 = rtb_w_est[2];
    }

    /* Sum: '<S334>/Sum1' incorporates:
     *  Product: '<S334>/Product'
     */
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_dircos[i] * rtb_MultiportSwitch1_idx;
      rtb_dircos_0[i] += rtb_dircos[i + 3] * rtb_MultiportSwitch1_idx_0;
      rtb_dircos_0[i] += rtb_dircos[i + 6] * rtb_MultiportSwitch1_idx_1;
    }

    /* Math: '<S421>/Math Function' */
    rtb_uvw_rw_idx = rtb_uvw[0] + rtb_dircos_0[0];

    /* Sum: '<S317>/Sum' incorporates:
     *  Gain: '<S314>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_k1[0] * rtb_Gain_idx +
      rtb_MultiportSwitch1_idx;
    rtb_uvw_rw_idx_1 = rtb_uvw[1] + rtb_dircos_0[1];

    /* Sum: '<S317>/Sum' incorporates:
     *  Gain: '<S314>/Gain'
     */
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_k1[1] * rtb_Gain_idx_0 +
      rtb_MultiportSwitch1_idx_0;
    rtb_uvw_rw_idx_0 = rtb_uvw[2] + rtb_dircos_0[2];

    /* Sum: '<S317>/Sum' incorporates:
     *  Gain: '<S314>/Gain'
     */
    rtb_Sum_h_idx = claw_main_P.Gain_Gain_k1[2] * rtb_Gain_idx_1 +
      rtb_MultiportSwitch1_idx_1;
    rtb_MathFunction_l = rt_hypot_snf(rtb_uvw_rw_idx, rtb_uvw_rw_idx_0);

    /* Math: '<S421>/Math Function1' */
    rtb_MathFunction1 = rt_hypot_snf(rtb_MathFunction_l, rtb_uvw_rw_idx_1);

    /* MinMax: '<S348>/MinMax' incorporates:
     *  Constant: '<S348>/Constant'
     */
    max_0 = rt_MAXd_snf(claw_main_P.Constant_Value_gl, rtb_MathFunction1);

    /* Abs: '<S147>/abs_vel_rw' */
    rtb_abs_vel_rw = fabs(max_0);

    /* Trigonometry: '<S421>/Trigonometric Function1' */
    rtb_TrigonometricFunction1 = rt_atan2_snf(rtb_uvw_rw_idx_1,
      rtb_MathFunction_l);

    /* Abs: '<S147>/abs_cos_beta' incorporates:
     *  Trigonometry: '<S147>/Trigonometric Function'
     */
    rtb_abs_cos_beta = fabs(cos(rtb_TrigonometricFunction1));

    /* Math: '<S325>/Math Function' */
    rtb_Rground = rt_hypot_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* Trigonometry: '<S325>/Trigonometric Function1' incorporates:
     *  Gain: '<S325>/Gain'
     */
    rtb_elevation = rt_atan2_snf(claw_main_P.Gain_Gain_pm * rtb_Sum_h_idx,
      rtb_Rground);

    /* Trigonometry: '<S326>/Trigonometric Function3' */
    rtb_TrigonometricFunction3 = cos(rtb_elevation);

    /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
     *  Constant: '<S325>/Constant'
     */
    rtb_TrigonometricFunction1_n = cos(claw_main_P.Constant_Value_d5);

    /* Product: '<S326>/Product11' */
    rtb_Product11 = rtb_TrigonometricFunction3 * rtb_TrigonometricFunction1_n;

    /* Abs: '<S147>/abs_cos_gamma_rw' */
    rtb_abs_cos_gamma_rw = fabs(rtb_Product11);

    /* Switch: '<S313>/Switch' incorporates:
     *  Memory: '<S313>/Memory'
     *  Memory: '<S313>/Memory1'
     *  Product: '<S313>/Product'
     */
    if (rtb_control_input[110] * claw_main_DWork.Memory_PreviousInput != 0.0) {
      rtb_Switch_k = claw_main_DWork.Memory1_PreviousInput;
    } else {
      rtb_Switch_k = rtb_sensors[8];
    }

    /* Switch: '<S319>/u2>=0' incorporates:
     *  Constant: '<S319>/Constant2'
     *  Constant: '<S321>/Constant1'
     *  Constant: '<S321>/Constant2'
     *  Constant: '<S321>/Constant4'
     *  Constant: '<S321>/alt_prt'
     *  Math: '<S321>/Math Function'
     *  Product: '<S321>/Product2'
     *  Product: '<S321>/Product3'
     *  Product: '<S321>/Product4'
     *  Sum: '<S319>/Sum'
     *  Sum: '<S321>/Sum3'
     */
    if (claw_main_P.Constant2_Value_c0 - rtb_Switch_k >=
        claw_main_P.u20_Threshold) {
      /* Sum: '<S322>/Sum2' incorporates:
       *  Constant: '<S322>/Constant'
       *  Constant: '<S322>/Constant1'
       *  Constant: '<S322>/Constant4'
       *  Product: '<S322>/Product1'
       */
      rtb_Sum2_jn = 1.0 / claw_main_P.Constant_Value_ex /
        claw_main_P.Constant1_Value_b3 - claw_main_P.Constant4_Value_d;

      /* Sum: '<S322>/Sum1' incorporates:
       *  Constant: '<S322>/Constant'
       *  Constant: '<S322>/Constant2'
       *  Constant: '<S322>/Constant3'
       *  Product: '<S322>/Product'
       */
      rtb_Sum1_k5 = claw_main_P.Constant3_Value_a - rtb_Switch_k /
        claw_main_P.Constant2_Value_d * claw_main_P.Constant_Value_ex;

      /* Math: '<S322>/Math Function' */
      if ((rtb_Sum1_k5 < 0.0) && (rtb_Sum2_jn > floor(rtb_Sum2_jn))) {
        rtb_MathFunction_n1 = -rt_pow_snf(-rtb_Sum1_k5, rtb_Sum2_jn);
      } else {
        rtb_MathFunction_n1 = rt_pow_snf(rtb_Sum1_k5, rtb_Sum2_jn);
      }

      rtb_u20 = rtb_MathFunction_n1;
    } else {
      /* Sum: '<S321>/Sum2' incorporates:
       *  Constant: '<S321>/Constant'
       *  Constant: '<S321>/Constant2'
       *  Constant: '<S321>/Constant4'
       *  Product: '<S321>/Product1'
       */
      rtb_Sum2_dsp = claw_main_P.Constant2_Value_i -
        claw_main_P.Constant4_Value_oa * claw_main_P.Constant_Value_lz;
      rtb_u20 = 1.0 / exp((rtb_Switch_k - claw_main_P.Constant4_Value_oa) /
                          claw_main_P.Constant1_Value_d / rtb_Sum2_dsp) * (1.0 /
        rtb_Sum2_dsp * claw_main_P.Constant2_Value_i) *
        claw_main_P.alt_prt_Value;
    }

    /* Product: '<S319>/Product' incorporates:
     *  Constant: '<S319>/Constant1'
     */
    rtb_Product_b = rtb_u20 * claw_main_P.Constant1_Value_kr;

    /* Fcn: '<S348>/wind_qbar' */
    if ((max_0 < 0.0) && (2.0 > floor(2.0))) {
      max_1 = -rt_pow_snf(-max_0, 2.0);
    } else {
      max_1 = rt_pow_snf(max_0, 2.0);
    }

    /* Product: '<S348>/Product1' */
    rtb_qbar = 0.5 * max_1 * rtb_Product_b;

    /* Logic: '<S148>/Logical Operator' incorporates:
     *  Constant: '<S150>/Constant'
     *  Constant: '<S151>/Constant'
     *  Constant: '<S152>/Constant'
     *  Constant: '<S155>/Constant'
     *  RelationalOperator: '<S150>/Compare'
     *  RelationalOperator: '<S151>/Compare'
     *  RelationalOperator: '<S152>/Compare'
     *  RelationalOperator: '<S155>/Compare'
     */
    rtb_LogicalOperator_o = ((rtb_abs_vel_rw >= claw_main_P.Constant_Value_kg) &&
                             (rtb_abs_cos_beta >= claw_main_P.Constant_Value_bq)
      && (rtb_abs_cos_gamma_rw >= claw_main_P.Constant_Value_fa) && (rtb_qbar >=
      claw_main_P.Constant_Value_b0));

    /* Product: '<S90>/Product' incorporates:
     *  Constant: '<S148>/Constant'
     *  Constant: '<S154>/Constant'
     *  RelationalOperator: '<S154>/Compare'
     */
    rtb_att_type_availability[0] = claw_main_P.Constant_Value_nme ?
      rtb_Assignment1[0] : 0.0;
    rtb_att_type_availability[1] = rtb_abs_cos_b >=
      claw_main_P.Constant_Value_ig ? rtb_Assignment1[1] : 0.0;
    rtb_att_type_availability[2] = rtb_Compare_la ? rtb_Assignment1[2] : 0.0;
    rtb_att_type_availability[3] = rtb_Compare_la ? rtb_Assignment1[3] : 0.0;
    rtb_att_type_availability[4] = rtb_LogicalOperator_o ? rtb_Assignment1[4] :
      0.0;
    rtb_att_type_availability[5] = rtb_LogicalOperator_o ? rtb_Assignment1[5] :
      0.0;

    /* MinMax: '<S149>/MinMax3' */
    max_1 = rtb_att_type_availability[0];
    for (yOffset_0 = 0; yOffset_0 < 5; yOffset_0++) {
      max_1 = rt_MAXd_snf(max_1, rtb_att_type_availability[yOffset_0 + 1]);
    }

    /* Switch: '<S149>/argmax1' incorporates:
     *  Constant: '<S149>/Constant4'
     *  Constant: '<S149>/Constant5'
     *  Sum: '<S149>/Sum2'
     */
    for (i = 0; i < 6; i++) {
      if (rtb_att_type_availability[i] - max_1 >=
          claw_main_P.argmax1_Threshold_o) {
        rtb_argmax1[i] = claw_main_P.Constant4_Value_a[i];
      } else {
        rtb_argmax1[i] = claw_main_P.Constant5_Value_fr;
      }
    }

    /* MinMax: '<S149>/MinMax4' */
    max_1 = rtb_argmax1[0];
    for (yOffset_0 = 0; yOffset_0 < 5; yOffset_0++) {
      max_1 = rt_MINd_snf(max_1, rtb_argmax1[yOffset_0 + 1]);
    }

    rtb_MinMax4 = max_1;

    /* MultiPortSwitch: '<S90>/Multiport Switch1' incorporates:
     *  Constant: '<S90>/Constant5'
     */
    if ((int32_T)claw_main_P.Constant5_Value_n == 0) {
      rtb_MultiportSwitch1_l = rtb_control_input[102];
    } else {
      rtb_MultiportSwitch1_l = rtb_MinMax4;
    }

    /* Gain: '<S314>/Gain1' */
    rtb_att_type = claw_main_P.Gain1_Gain_gl * rtb_MultiportSwitch1_l;

    /* RelationalOperator: '<S104>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S104>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_h = (rtb_att_type !=
      claw_main_DWork.DelayInput1_DSTATE_c);

    /* Logic: '<S102>/Logical Operator3' incorporates:
     *  Logic: '<S102>/Logical Operator2'
     *  RelationalOperator: '<S105>/FixPt Relational Operator'
     *  UnitDelay: '<S102>/Unit Delay'
     *  UnitDelay: '<S105>/Delay Input1'
     */
    rtb_LogicalOperator3_idx = (((((real_T)rtb_LogicalOperator4_h >
      claw_main_DWork.DelayInput1_DSTATE[0]) != 0) ||
      (rtb_FixPtRelationalOperator_h != 0)) != 0) ^
      (claw_main_DWork.UnitDelay_DSTATE_p[0] != 0.0);
    rtb_LogicalOperator3_idx_0 = (((((real_T)rtb_LogicalOperator4_h >
      claw_main_DWork.DelayInput1_DSTATE[1]) != 0) ||
      (rtb_FixPtRelationalOperator_h != 0)) != 0) ^
      (claw_main_DWork.UnitDelay_DSTATE_p[1] != 0.0);
    rtb_LogicalOperator3_idx_1 = (((((real_T)rtb_LogicalOperator2 >
      claw_main_DWork.DelayInput1_DSTATE[2]) != 0) ||
      (rtb_FixPtRelationalOperator_h != 0)) != 0) ^
      (claw_main_DWork.UnitDelay_DSTATE_p[2] != 0.0);

    /* Gain: '<S92>/Gain1' */
    rtb_Gain1_idx_0 = claw_main_P.Gain1_Gain_er[0] * (real_T)
      rtb_LogicalOperator3_idx;
    rtb_Gain1_idx_1 = claw_main_P.Gain1_Gain_er[1] * (real_T)
      rtb_LogicalOperator3_idx_0;
    rtb_Gain1_idx = claw_main_P.Gain1_Gain_er[2] * (real_T)
      rtb_LogicalOperator3_idx_1;

    /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
     *  Constant: '<S325>/Constant'
     */
    rtb_TrigonometricFunction_o = sin(claw_main_P.Constant_Value_d5);

    /* Product: '<S326>/Product10' */
    rtb_Product10 = rtb_TrigonometricFunction3 * rtb_TrigonometricFunction_o;

    /* Trigonometry: '<S326>/Trigonometric Function2' */
    rtb_TrigonometricFunction2 = sin(rtb_elevation);

    /* Gain: '<S326>/Gain' */
    rtb_Gain_p = claw_main_P.Gain_Gain_lb * rtb_TrigonometricFunction2;

    /* Trigonometry: '<S325>/Trigonometric Function' */
    rtb_azimuth = rt_atan2_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* Trigonometry: '<S326>/Trigonometric Function4' */
    rtb_TrigonometricFunction4 = sin(rtb_azimuth);

    /* Product: '<S326>/Product2' */
    rtb_Product2 = rtb_TrigonometricFunction4 * rtb_TrigonometricFunction1_n;

    /* Trigonometry: '<S326>/Trigonometric Function5' */
    rtb_TrigonometricFunction5 = cos(rtb_azimuth);

    /* Product: '<S326>/Product9' */
    rtb_Product9 = rtb_TrigonometricFunction5 * rtb_TrigonometricFunction_o;

    /* Sum: '<S326>/Sum3' incorporates:
     *  Product: '<S326>/Product8'
     */
    rtb_Sum3 = rtb_TrigonometricFunction2 * rtb_Product2 - rtb_Product9;

    /* Product: '<S326>/Product4' */
    rtb_Product4 = rtb_TrigonometricFunction4 * rtb_TrigonometricFunction_o;

    /* Product: '<S326>/Product7' */
    rtb_Product7 = rtb_TrigonometricFunction5 * rtb_TrigonometricFunction1_n;

    /* Sum: '<S326>/Sum2' incorporates:
     *  Product: '<S326>/Product6'
     */
    rtb_Sum2_l = rtb_TrigonometricFunction2 * rtb_Product4 + rtb_Product7;

    /* Product: '<S326>/Product5' */
    rtb_Product5 = rtb_TrigonometricFunction3 * rtb_TrigonometricFunction4;

    /* Sum: '<S326>/Sum1' incorporates:
     *  Product: '<S326>/Product3'
     */
    rtb_Sum1_p = rtb_TrigonometricFunction2 * rtb_Product7 + rtb_Product4;

    /* Sum: '<S326>/Sum' incorporates:
     *  Product: '<S326>/Product1'
     */
    rtb_Sum_m = rtb_TrigonometricFunction2 * rtb_Product9 - rtb_Product2;

    /* Product: '<S326>/Product' */
    rtb_Product_h = rtb_TrigonometricFunction3 * rtb_TrigonometricFunction5;

    /* SwitchCase: '<S103>/Switch Case' incorporates:
     *  ActionPort: '<S106>/Action Port'
     *  ActionPort: '<S107>/Action Port'
     *  ActionPort: '<S108>/Action Port'
     *  SubSystem: '<S103>/mba'
     *  SubSystem: '<S103>/tiltcam'
     *  SubSystem: '<S103>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam_b(rtb_Gain1_o[1], rtb_Gain_i[3], rtb_Gain_i[1],
                          rtb_Gain_i[0], rtb_Gain1_o[2], rtb_Gain_i[5],
                          rtb_Gain_i[4], rtb_Gain_i[2], rtb_Gain1_o[3],
                          claw_main_B.Merge, (rtP_tiltcam_claw_main_n *)
                          &claw_main_P.tiltcam);
      break;

     case 2:
     case 3:
      claw_main_ypr_c(rtb_Gain1_o[1], rtb_Gain_i[3], rtb_Gain_i[1], rtb_Gain_i[0],
                      rtb_Gain1_o[2], rtb_Gain_i[5], rtb_Gain_i[4], rtb_Gain_i[2],
                      rtb_Gain1_o[3], claw_main_B.Merge, (rtP_ypr_claw_main_p *)
                      &claw_main_P.ypr);
      break;

     case 4:
     case 5:
      claw_main_mba_h(rtb_Gain1_o[1], rtb_Gain_i[3], rtb_Gain_i[1], rtb_Gain_i[0],
                      rtb_Gain1_o[2], rtb_Gain_i[5], rtb_Gain_i[4], rtb_Gain_i[2],
                      rtb_Gain1_o[3], rtb_Product_h, rtb_Sum_m, rtb_Sum1_p,
                      rtb_Product5, rtb_Sum2_l, rtb_Sum3, rtb_Gain_p,
                      rtb_Product10, rtb_Product11, claw_main_B.Merge,
                      (rtP_mba_claw_main_a *) &claw_main_P.mba);
      break;
    }

    /* Selector: '<S103>/order atts' incorporates:
     *  Constant: '<S103>/Constant'
     *  Selector: '<S103>/Selector'
     */
    rtb_delta_LLh_idx = claw_main_B.Merge[(int32_T)
      claw_main_P.Constant_Value_nu[(int32_T)rtb_att_type - 1] - 1];
    rtb_delta_LLh_idx_0 = claw_main_B.Merge[(int32_T)
      claw_main_P.Constant_Value_nu[(int32_T)rtb_att_type + 4] - 1];
    rtb_Switch2_idx = claw_main_B.Merge[(int32_T)claw_main_P.Constant_Value_nu
      [(int32_T)rtb_att_type + 9] - 1];

    /* DiscreteIntegrator: '<S92>/att cmd integration' */
    if (claw_main_DWork.attcmdintegration_IC_LOADING) {
      claw_main_DWork.attcmdintegration_IC_LOADING = 0U;
      claw_main_DWork.attcmdintegration_DSTATE[0] = rtb_delta_LLh_idx;
      rtb_delta_LLh_idx = claw_main_DWork.attcmdintegration_DSTATE[0];
      claw_main_DWork.attcmdintegration_DSTATE[1] = rtb_delta_LLh_idx_0;
      rtb_delta_LLh_idx_0 = claw_main_DWork.attcmdintegration_DSTATE[1];
      claw_main_DWork.attcmdintegration_DSTATE[2] = rtb_Switch2_idx;
      rtb_attcmdintegration_idx = claw_main_DWork.attcmdintegration_DSTATE[2];
    } else {
      if (((rtb_Gain1_idx_0 > 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[0] <= 0)) ||
          ((rtb_Gain1_idx_0 <= 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[0] == 1))) {
        claw_main_DWork.attcmdintegration_DSTATE[0] = rtb_delta_LLh_idx;
        rtb_delta_LLh_idx = claw_main_DWork.attcmdintegration_DSTATE[0];
      } else {
        rtb_delta_LLh_idx = claw_main_DWork.attcmdintegration_DSTATE[0];
      }

      if (((rtb_Gain1_idx_1 > 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[1] <= 0)) ||
          ((rtb_Gain1_idx_1 <= 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[1] == 1))) {
        claw_main_DWork.attcmdintegration_DSTATE[1] = rtb_delta_LLh_idx_0;
        rtb_delta_LLh_idx_0 = claw_main_DWork.attcmdintegration_DSTATE[1];
      } else {
        rtb_delta_LLh_idx_0 = claw_main_DWork.attcmdintegration_DSTATE[1];
      }

      if (((rtb_Gain1_idx > 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[2] <= 0)) ||
          ((rtb_Gain1_idx <= 0.0) &&
           (claw_main_DWork.attcmdintegration_PrevResetStat[2] == 1))) {
        claw_main_DWork.attcmdintegration_DSTATE[2] = rtb_Switch2_idx;
        rtb_attcmdintegration_idx = claw_main_DWork.attcmdintegration_DSTATE[2];
      } else {
        rtb_attcmdintegration_idx = claw_main_DWork.attcmdintegration_DSTATE[2];
      }
    }

    /* MultiPortSwitch: '<S92>/Multiport Switch1' */
    min[0] = (real_T)rtb_LogicalOperator4_h;
    min[1] = (real_T)rtb_LogicalOperator4_h;
    min[2] = (real_T)rtb_LogicalOperator2;
    if (rtb_Gain1_idx_0 > 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[0] = 1;
    } else if (rtb_Gain1_idx_0 < 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[0] = -1;
    } else {
      claw_main_DWork.attcmdintegration_PrevResetStat[0] = 0;
    }

    if (min[0] == 0.0) {
      rtb_delta_LLh_idx = rtb_MultiportSwitch2_idx;
    }

    if (rtb_Gain1_idx_1 > 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[1] = 1;
    } else if (rtb_Gain1_idx_1 < 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[1] = -1;
    } else {
      claw_main_DWork.attcmdintegration_PrevResetStat[1] = 0;
    }

    if (min[1] == 0.0) {
      rtb_delta_LLh_idx_0 = rtb_MultiportSwitch2_idx_0;
    }

    if (rtb_Gain1_idx > 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[2] = 1;
    } else if (rtb_Gain1_idx < 0.0) {
      claw_main_DWork.attcmdintegration_PrevResetStat[2] = -1;
    } else {
      claw_main_DWork.attcmdintegration_PrevResetStat[2] = 0;
    }

    if (min[2] == 0.0) {
      rtb_attcmdintegration_idx = rtb_MultiportSwitch2_idx_1;
    }

    /* Logic: '<S93>/Logical Operator4' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S93>/Constant4'
     *  RelationalOperator: '<S121>/Compare'
     */
    rtb_LogicalOperator4_i = ((rtb_control_input[94] ==
      claw_main_P.Constant_Value_no) && (claw_main_P.Constant4_Value_k != 0.0));

    /* FromWorkspace: '<S93>/From Workspace4' */
    {
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace4_PWORK.DataPtr;
      rtb_FromWorkspace4[0] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace4[1] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace4[2] = pDataValues[0];
      pDataValues += 1;
    }

    /* FromWorkspace: '<S93>/From Workspace1' */
    {
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace1_PWORK.DataPtr;
      rtb_FromWorkspace1[0] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace1[1] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace1[2] = pDataValues[0];
      pDataValues += 1;
    }

    /* FromWorkspace: '<S93>/From Workspace2' */
    {
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace2_PWORK.DataPtr;
      rtb_FromWorkspace2[0] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace2[1] = pDataValues[0];
      pDataValues += 1;
      rtb_FromWorkspace2[2] = pDataValues[0];
      pDataValues += 1;
    }

    /* MultiPortSwitch: '<S93>/Multiport Switch1' */
    if (rtb_LogicalOperator4_i != 0) {
      /* MultiPortSwitch: '<S93>/Multiport Switch2' */
      switch ((int32_T)rtb_MultiportSwitch1_l) {
       case 1:
        rtb_delta_LLh_idx = rtb_FromWorkspace4[0];
        rtb_delta_LLh_idx_0 = rtb_FromWorkspace4[1];
        rtb_attcmdintegration_idx = rtb_FromWorkspace4[2];
        break;

       case 2:
        rtb_delta_LLh_idx = rtb_FromWorkspace1[0];
        rtb_delta_LLh_idx_0 = rtb_FromWorkspace1[1];
        rtb_attcmdintegration_idx = rtb_FromWorkspace1[2];
        break;

       case 3:
        rtb_delta_LLh_idx = rtb_FromWorkspace1[2];
        rtb_delta_LLh_idx_0 = rtb_FromWorkspace1[1];
        rtb_attcmdintegration_idx = rtb_FromWorkspace1[0];
        break;

       case 4:
        rtb_delta_LLh_idx = rtb_FromWorkspace2[0];
        rtb_delta_LLh_idx_0 = rtb_FromWorkspace2[1];
        rtb_attcmdintegration_idx = rtb_FromWorkspace2[2];
        break;

       default:
        rtb_delta_LLh_idx = rtb_FromWorkspace2[2];
        rtb_delta_LLh_idx_0 = rtb_FromWorkspace2[1];
        rtb_attcmdintegration_idx = rtb_FromWorkspace2[0];
        break;
      }
    }

    /* RelationalOperator: '<S131>/Compare' incorporates:
     *  Constant: '<S131>/Constant'
     */
    rtb_Compare_m = (rtb_control_input[94] == claw_main_P.Constant_Value_hw);

    /* Logic: '<S96>/Logical Operator' incorporates:
     *  Constant: '<S130>/Constant'
     *  RelationalOperator: '<S130>/Compare'
     *  UnitDelay: '<S96>/Unit Delay1'
     */
    rtb_LogicalOperator_p = ((claw_main_DWork.UnitDelay1_DSTATE_m1 <=
      claw_main_P.Constant_Value_dl) && rtb_Compare_m);

    /* Switch: '<S96>/Switch' incorporates:
     *  Assignment: '<S92>/set att cmd'
     *  Assignment: '<S93>/set att cmd'
     *  Sum: '<S96>/Sum'
     *  UnitDelay: '<S96>/Unit Delay'
     */
    if (rtb_LogicalOperator_p) {
      rtb_Switch_f_idx_0 = rtb_Gain_idx - rtb_delta_LLh_idx;
      rtb_Switch_f_idx_1 = rtb_Gain_idx_0 - rtb_delta_LLh_idx_0;
      rtb_Switch_f_idx = rtb_Gain_idx_1 - rtb_MultiportSwitch2_idx_2;
    } else {
      rtb_Switch_f_idx_0 = claw_main_DWork.UnitDelay_DSTATE_jm[0];
      rtb_Switch_f_idx_1 = claw_main_DWork.UnitDelay_DSTATE_jm[1];
      rtb_Switch_f_idx = claw_main_DWork.UnitDelay_DSTATE_jm[2];
    }

    /* Switch: '<S96>/Switch1' incorporates:
     *  Constant: '<S96>/Constant1'
     *  Product: '<S96>/Product1'
     *  UnitDelay: '<S96>/Unit Delay2'
     */
    if (rtb_LogicalOperator_p) {
      rtb_Switch1 = claw_main_P.Constant1_Value_p;
    } else {
      rtb_Switch1 = rtb_Compare_m ? claw_main_DWork.UnitDelay2_DSTATE : 0.0;
    }

    /* Sum: '<S96>/Sum3' incorporates:
     *  Constant: '<S96>/Constant'
     */
    rtb_Sum3_e = rtb_Switch1 - claw_main_P.Constant_Value_pw;

    /* MinMax: '<S96>/MinMax' incorporates:
     *  Constant: '<S96>/Constant2'
     */
    max_2 = rt_MAXd_snf(claw_main_P.Constant2_Value_n4, rtb_Sum3_e);

    /* Sum: '<S98>/Sum1' incorporates:
     *  Constant: '<S98>/Constant'
     *  Product: '<S98>/Product2'
     *  S-Function (sfix_dot): '<S98>/Dot Product'
     */
    claw_main_B.eow = ((rtb_uvw[0] * rtb_uvw[0] + rtb_uvw[1] * rtb_uvw[1]) +
                       rtb_uvw[2] * rtb_uvw[2]) / claw_main_P.Constant_Value_b4r
      + rtb_NEh_e[2];

    /* S-Function (sfun_idxsearch): '<S98>/PreLookup Index Search' */
    scalarIndex = plook_binx(claw_main_B.eow,
      &claw_main_P.PreLookupIndexSearch_bpData[0], 1U, &scalarFraction);
    rtb_eow_idx_idx = scalarFraction;

    /* RelationalOperator: '<S133>/Compare' incorporates:
     *  Constant: '<S133>/Constant'
     */
    rtb_Compare_df = (claw_main_B.eow >= claw_main_P.Constant_Value_kj);

    /* Sum: '<S98>/Sum3' incorporates:
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant2'
     *  Constant: '<S98>/Constant3'
     *  Constant: '<S98>/Constant4'
     *  Product: '<S98>/Product1'
     *  Product: '<S98>/Product3'
     *  Sum: '<S98>/Sum2'
     *  Sum: '<S98>/Sum4'
     */
    claw_main_B.X = (rtb_NEh_e[0] - claw_main_P.Constant3_Value_dq) *
      claw_main_P.Constant2_Value_a + (rtb_NEh_e[1] -
      claw_main_P.Constant4_Value_ar) * claw_main_P.Constant1_Value_at;

    /* S-Function (sfun_idxsearch): '<S98>/PreLookup Index Search1' */
    scalarIndex = plook_binc(claw_main_B.X,
      &claw_main_P.PreLookupIndexSearch1_bpData_h[0], 1U, &scalarFraction_0);
    rtb_X_idx_idx = scalarFraction_0;

    /* Logic: '<S99>/Logical Operator' incorporates:
     *  Constant: '<S134>/Constant'
     *  Constant: '<S99>/Constant4'
     *  RelationalOperator: '<S134>/Compare'
     */
    rtb_LogicalOperator = ((claw_main_P.Constant4_Value_i != 0.0) &&
      (rtb_control_input[94] == claw_main_P.Constant_Value_gw));

    /* Switch: '<S99>/Switch2' incorporates:
     *  Assignment: '<S92>/set att cmd'
     *  Assignment: '<S93>/set att cmd'
     *  Product: '<S96>/Product'
     *  Sum: '<S96>/Sum2'
     */
    if ((real_T)rtb_LogicalOperator >= claw_main_P.Switch2_Threshold_l) {
      /* Switch: '<S99>/Switch1' */
      if (rtb_Compare_df) {
        /* S-Function (sfun_kflookupnd): '<S135>/Interpolation (n-D) using PreLookup' incorporates:
         *  Constant: '<S135>/Constant1'
         */
        if (claw_main_P.Constant1_Value_io[0] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_io[0] >= 0) {
          yOffset = claw_main_P.Constant1_Value_io[0];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_0 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_t[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_io[1] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_io[1] >= 0) {
          yOffset = claw_main_P.Constant1_Value_io[1];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_1 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_t[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_io[2] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_io[2] >= 0) {
          yOffset = claw_main_P.Constant1_Value_io[2];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_2 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_t[yOffset << 1U]);
      } else {
        /* Sum: '<S136>/Sum4' incorporates:
         *  Constant: '<S136>/Constant3'
         *  Constant: '<S136>/Constant4'
         *  Product: '<S136>/Product4'
         */
        rtb_Sum4_i = claw_main_P.Constant4_Value_j * claw_main_B.X +
          claw_main_P.Constant3_Value_e;

        /* Sum: '<S136>/Sum5' incorporates:
         *  Constant: '<S136>/Constant1'
         *  Constant: '<S136>/Constant5'
         *  Product: '<S136>/Product3'
         */
        rtb_Sum5_i4 = claw_main_P.Constant5_Value_i * claw_main_B.X +
          claw_main_P.Constant1_Value_o;

        /* S-Function (sfun_kflookupnd): '<S136>/Interpolation (n-D) using PreLookup for h' */
        rtb_InterpolationnDusingPreLo_b = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLooku_m4[0]);
        rtb_InterpolationnDusingPreLo_0 = rtb_Sum4_i;
        rtb_InterpolationnDusingPreLo_1 = rtb_Sum5_i4;
        rtb_InterpolationnDusingPreLo_2 = rtb_InterpolationnDusingPreLo_b;
      }
    } else {
      rtb_InterpolationnDusingPreLo_0 = rtb_Switch_f_idx_0 * max_2 +
        rtb_delta_LLh_idx;
      rtb_InterpolationnDusingPreLo_1 = rtb_Switch_f_idx_1 * max_2 +
        rtb_delta_LLh_idx_0;
      rtb_InterpolationnDusingPreLo_2 = rtb_Switch_f_idx * max_2 +
        rtb_MultiportSwitch2_idx_2;
    }

    /* DiscreteIntegrator: '<S8>/mass' */
    claw_main_B.mass = claw_main_DWork.mass_DSTATE;

    /* Sum: '<S318>/Sum4' incorporates:
     *  Constant: '<S318>/Constant1'
     */
    rtb_fuel = claw_main_B.mass - claw_main_P.Constant1_Value_no;

    /* Product: '<S143>/Product' incorporates:
     *  Constant: '<S143>/Constant'
     *  Logic: '<S143>/Logical Operator'
     *  RelationalOperator: '<S145>/Compare'
     */
    for (i = 0; i < 10; i++) {
      /* UnitDelay: '<S1>/Unit Delay' */
      rtb_u_old[i] = claw_main_DWork.UnitDelay_DSTATE_je[i];

      /* Sum: '<S138>/Sum1' incorporates:
       *  Gain: '<S138>/Gain'
       */
      rtb_Sum1_l[i] = rtb_control_input[i + 34] * claw_main_P.Gain_Gain_pc +
        claw_main_DWork.UnitDelay_DSTATE_je[i];

      /* MultiPortSwitch: '<S137>/Multiport Switch' */
      switch ((int32_T)rtb_control_input[54 + i]) {
       case 0:
        rtb_MultiportSwitch[i] = rtb_control_input[14 + i];
        break;

       case 1:
        rtb_MultiportSwitch[i] = rtb_control_input[4 + i];
        break;

       default:
        rtb_MultiportSwitch[i] = rtb_sensors[17 + i];
        break;
      }

      rtb_Assignment1_n[i] = rtb_MultiportSwitch[i];
    }

    /* Assignment: '<S141>/Assignment1' */
    rtb_Assignment1_n[6] = !((rtb_fuel <= 0.0) && (claw_main_P.Constant_Value_pv
      != 0.0)) ? rtb_MultiportSwitch[6] : 0.0;

    /* Product: '<S142>/Product' incorporates:
     *  Constant: '<S142>/Constant'
     *  Logic: '<S142>/Logical Operator'
     *  RelationalOperator: '<S144>/Compare'
     */
    for (i = 0; i < 10; i++) {
      /* MinMax: '<S139>/MinMax2' incorporates:
       *  Constant: '<S139>/Constant3'
       */
      min_1[i] = rt_MINd_snf(claw_main_P.Constant3_Value_g[i],
        rtb_Assignment1_n[i]);

      /* Sum: '<S139>/Sum2' incorporates:
       *  Gain: '<S139>/Gain1'
       */
      rtb_Sum2_b[i] = rtb_control_input[i + 44] * claw_main_P.Gain1_Gain_j5 +
        claw_main_DWork.UnitDelay_DSTATE_je[i];

      /* MinMax: '<S139>/MinMax3' */
      max_3[i] = rt_MAXd_snf(min_1[i], rtb_Sum2_b[i]);

      /* MinMax: '<S138>/MinMax3' */
      min_2[i] = rt_MINd_snf(rtb_Sum1_l[i], max_3[i]);

      /* Sum: '<S139>/Sum1' incorporates:
       *  Gain: '<S139>/Gain'
       */
      rtb_Sum1_b[i] = rtb_control_input[i + 34] * claw_main_P.Gain_Gain_ft +
        claw_main_DWork.UnitDelay_DSTATE_je[i];

      /* MultiPortSwitch: '<S137>/Multiport Switch1' */
      switch ((int32_T)rtb_control_input[54 + i]) {
       case 0:
        rtb_MultiportSwitch1_i[i] = rtb_control_input[24 + i];
        break;

       case 1:
        rtb_MultiportSwitch1_i[i] = rtb_control_input[4 + i];
        break;

       default:
        rtb_MultiportSwitch1_i[i] = rtb_sensors[17 + i];
        break;
      }

      rtb_Assignment[i] = rtb_MultiportSwitch1_i[i];
    }

    /* Assignment: '<S141>/Assignment' */
    rtb_Assignment[6] = !((rtb_fuel <= 0.0) && (claw_main_P.Constant_Value_fn !=
      0.0)) ? rtb_MultiportSwitch1_i[6] : 0.0;
    for (i = 0; i < 10; i++) {
      /* MinMax: '<S139>/MinMax1' incorporates:
       *  Constant: '<S139>/Constant1'
       */
      rtb_delta_LLh_idx = rt_MAXd_snf(claw_main_P.Constant1_Value_f5[i],
        rtb_Assignment[i]);

      /* MinMax: '<S139>/MinMax4' */
      rtb_delta_LLh_idx = rt_MINd_snf(rtb_Sum1_b[i], rtb_delta_LLh_idx);

      /* MinMax: '<S138>/MinMax2' */
      rtb_Switch2_idx = rt_MAXd_snf(min_2[i], rtb_delta_LLh_idx);

      /* Sum: '<S138>/Sum2' incorporates:
       *  Gain: '<S138>/Gain1'
       */
      rtb_delta_LLh_idx_0 = rtb_control_input[i + 44] *
        claw_main_P.Gain1_Gain_he + claw_main_DWork.UnitDelay_DSTATE_je[i];

      /* MinMax: '<S138>/MinMax1' */
      rtb_delta_LLh_idx = rt_MAXd_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

      /* MinMax: '<S138>/MinMax' */
      rtb_delta_LLh_idx = rt_MINd_snf(rtb_delta_LLh_idx, max_3[i]);

      /* MinMax: '<S89>/MinMax2' */
      rtb_delta_LLh_idx = rt_MAXd_snf(rtb_delta_LLh_idx, rtb_control_input[i + 4]);
      min_1[i] = rt_MINd_snf(rtb_Switch2_idx, rtb_delta_LLh_idx);
    }

    /* MultiPortSwitch: '<S310>/Multiport Switch2' incorporates:
     *  Assignment: '<S99>/set pos cmd'
     *  Gain: '<S310>/Gain1'
     */
    if ((int32_T)rtb_control_input[104] == 0) {
      rtb_MultiportSwitch2_d = claw_main_P.Gain1_Gain_n *
        rtb_InterpolationnDusingPreLo_2;
    } else {
      rtb_MultiportSwitch2_d = min_1[6];
    }

    /* Logic: '<S91>/Logical Operator4' incorporates:
     *  Constant: '<S158>/Constant'
     *  Constant: '<S91>/Constant'
     *  Constant: '<S91>/Constant1'
     *  Logic: '<S158>/Logical Operator'
     *  Logic: '<S91>/Logical Operator1'
     *  Logic: '<S91>/Logical Operator5'
     *  Product: '<S158>/Product'
     *  RelationalOperator: '<S172>/Compare'
     */
    rtb_enable_bb = ((rtb_control_input[108] != 0.0) && (((!((!((rtb_fuel <= 0.0)
      && (claw_main_P.Constant_Value_mn != 0.0)) ?
      claw_main_P.Constant_Value_pkn : 0.0) != 0.0) != 0) ||
      (claw_main_P.Constant1_Value_h != 0.0)) != 0));

    /* Reshape: '<S37>/Reshape' incorporates:
     *  Gain: '<S37>/Gain1'
     */
    rtb_MatrixConcatenation[0] = claw_main_P.Gain1_Gain_m4[0] * rtb_Switch_idx_0;
    rtb_MatrixConcatenation[1] = claw_main_P.Gain1_Gain_m4[1] * rtb_Switch_idx;
    rtb_MatrixConcatenation[2] = claw_main_P.Gain1_Gain_m4[2] * rtb_Switch_idx_2;
    rtb_MatrixConcatenation[3] = claw_main_P.Gain1_Gain_m4[3] * rtb_Switch_idx_1;

    /* Reshape: '<S37>/Reshape1' incorporates:
     *  Gain: '<S37>/Gain2'
     */
    rtb_MatrixConcatenation[4] = claw_main_P.Gain2_Gain_k4[0] * rtb_Switch_idx_1;
    rtb_MatrixConcatenation[5] = claw_main_P.Gain2_Gain_k4[1] * rtb_Switch_idx_2;
    rtb_MatrixConcatenation[6] = claw_main_P.Gain2_Gain_k4[2] * rtb_Switch_idx;
    rtb_MatrixConcatenation[7] = claw_main_P.Gain2_Gain_k4[3] * rtb_Switch_idx_0;

    /* Reshape: '<S37>/Reshape2' incorporates:
     *  Gain: '<S37>/Gain3'
     */
    rtb_MatrixConcatenation[8] = claw_main_P.Gain3_Gain_e[0] * rtb_Switch_idx_2;
    rtb_MatrixConcatenation[9] = claw_main_P.Gain3_Gain_e[1] * rtb_Switch_idx_1;
    rtb_MatrixConcatenation[10] = claw_main_P.Gain3_Gain_e[2] * rtb_Switch_idx_0;
    rtb_MatrixConcatenation[11] = claw_main_P.Gain3_Gain_e[3] * rtb_Switch_idx;

    /* Gain: '<S34>/Gain' incorporates:
     *  Math: '<S34>/Math Function'
     */
    for (i = 0; i < 4; i++) {
      rtb_Gain_h[3 * i] = claw_main_P.Gain_Gain_ku * rtb_MatrixConcatenation[i];
      rtb_Gain_h[1 + 3 * i] = rtb_MatrixConcatenation[i + 4] *
        claw_main_P.Gain_Gain_ku;
      rtb_Gain_h[2 + 3 * i] = rtb_MatrixConcatenation[i + 8] *
        claw_main_P.Gain_Gain_ku;
    }

    /* Switch: '<S159>/Switch' */
    if (rtb_control_input[109] >= claw_main_P.Switch_Threshold_m) {
      rtb_Switch_n = rtb_control_input[109];
    } else {
      rtb_Switch_n = (real_T)rtb_enable_bb;
    }

    /* Product: '<S159>/Product' */
    rtb_Product_e = claw_main_B.Width2 / claw_main_B.Width1;

    /* MinMax: '<S159>/MinMax' */
    min_3 = rt_MINd_snf(rtb_Switch_n, rtb_Product_e);

    /* Selector: '<S159>/select gain set' incorporates:
     *  Constant: '<S159>/Constant2'
     */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 52; uDimIdx++) {
      rtb_selectgainset[yOffset] = claw_main_P.Constant2_Value_ac[uDimIdx +
        (int32_T)min_3];
      yOffset++;
    }

    /* Reshape: '<S159>/Reshape' */
    memcpy((void *)&rtb_Reshape_n[0], (void *)&rtb_selectgainset[0], 52U *
           (uint32_T)((char_T *)&rtb_selectgainset[1U] - (char_T *)
                      &rtb_selectgainset[0U]));

    /* Logic: '<S157>/Logical Operator1' incorporates:
     *  Constant: '<S157>/Constant'
     *  Constant: '<S171>/Constant'
     *  Logic: '<S157>/Logical Operator2'
     *  Logic: '<S157>/Logical Operator3'
     *  RelationalOperator: '<S171>/Compare'
     */
    rtb_LogicalOperator1_f = ((!(claw_main_P.Constant_Value_hx != 0.0)) ||
      ((claw_main_P.Constant_Value_hx != 0.0) && (rtb_MultiportSwitch1_l >=
      claw_main_P.Constant_Value_fl)));

    /* Logic: '<S157>/Logical Operator' */
    rtb_LogicalOperator_n_idx = ((rtb_Reshape_n[8] != 0.0) &&
      rtb_LogicalOperator1_f);
    rtb_LogicalOperator_n_idx_0 = ((rtb_Reshape_n[9] != 0.0) &&
      rtb_LogicalOperator1_f);
    rtb_LogicalOperator_n_idx_1 = ((rtb_Reshape_n[10] != 0.0) &&
      rtb_LogicalOperator1_f);
    rtb_LogicalOperator_n_idx_2 = ((rtb_Reshape_n[11] != 0.0) &&
      rtb_LogicalOperator1_f);

    /* Reshape: '<S127>/Reshape' incorporates:
     *  Gain: '<S127>/Gain1'
     */
    rtb_MatrixConcatenation_j[0] = claw_main_P.Gain1_Gain_fl[0] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_j[1] = claw_main_P.Gain1_Gain_fl[1] * rtb_Switch_idx;
    rtb_MatrixConcatenation_j[2] = claw_main_P.Gain1_Gain_fl[2] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_j[3] = claw_main_P.Gain1_Gain_fl[3] *
      rtb_Switch_idx_1;

    /* Reshape: '<S127>/Reshape1' incorporates:
     *  Gain: '<S127>/Gain2'
     */
    rtb_MatrixConcatenation_j[4] = claw_main_P.Gain2_Gain_a1[0] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_j[5] = claw_main_P.Gain2_Gain_a1[1] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_j[6] = claw_main_P.Gain2_Gain_a1[2] * rtb_Switch_idx;
    rtb_MatrixConcatenation_j[7] = claw_main_P.Gain2_Gain_a1[3] *
      rtb_Switch_idx_0;

    /* Reshape: '<S127>/Reshape2' incorporates:
     *  Gain: '<S127>/Gain3'
     */
    rtb_MatrixConcatenation_j[8] = claw_main_P.Gain3_Gain_l[0] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_j[9] = claw_main_P.Gain3_Gain_l[1] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_j[10] = claw_main_P.Gain3_Gain_l[2] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_j[11] = claw_main_P.Gain3_Gain_l[3] * rtb_Switch_idx;

    /* S-Function (sfix_dot): '<S122>/Dot Product' */
    rtb_delta_LLh_idx = (rtb_uvw[0] * rtb_uvw[0] + rtb_uvw[1] * rtb_uvw[1]) +
      rtb_uvw[2] * rtb_uvw[2];

    /* Sum: '<S122>/Sum2' incorporates:
     *  Gain: '<S122>/Gain'
     */
    rtb_Switch2_idx = claw_main_P.Gain_Gain_bq * rtb_Gain_i[4] + rtb_sensors[13];
    rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_bq * rtb_Gain_i[2] + rtb_sensors[14];
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_bq * rtb_Gain1_o[3] +
      rtb_sensors[15];

    /* Gain: '<S126>/Gain4' incorporates:
     *  Constant: '<S122>/protect for   divide by zero'
     *  MinMax: '<S122>/MinMax1'
     *  Product: '<S122>/Product1'
     *  Product: '<S125>/Product'
     *  Product: '<S125>/Product1'
     *  Product: '<S126>/Product'
     *  Sum: '<S125>/Sum'
     */
    rtb_delta_LLh_idx = 1.0 / rt_MAXd_snf(rtb_delta_LLh_idx,
      claw_main_P.protectfordividebyzero_Value);
    rtb_Gain1_idx_1 = (rtb_uvw[1] * rtb_delta_LLh_idx_0 - rtb_uvw[2] *
                       rtb_Gain1_idx_0) * rtb_delta_LLh_idx;
    rtb_delta_LLh_idx_0 = (rtb_uvw[2] * rtb_Switch2_idx - rtb_uvw[0] *
      rtb_delta_LLh_idx_0) * rtb_delta_LLh_idx;
    rtb_delta_LLh_idx *= rtb_uvw[0] * rtb_Gain1_idx_0 - rtb_uvw[1] *
      rtb_Switch2_idx;
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_j[i] *
        rtb_Gain1_idx_1;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_j[i + 4] *
        rtb_delta_LLh_idx_0;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_j[i + 8] *
        rtb_delta_LLh_idx;
    }

    rtb_Gain4_idx = claw_main_P.Gain4_Gain_o * rtb_MatrixConcatenation_j_0[0];

    /* Product: '<S18>/Product2' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Product2_a_idx = claw_main_P.Constant_Value_nj * (real_T)
      rtb_LogicalOperator_n_idx;
    rtb_Gain4_idx_0 = claw_main_P.Gain4_Gain_o * rtb_MatrixConcatenation_j_0[1];

    /* Product: '<S18>/Product2' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Product2_a_idx_0 = claw_main_P.Constant_Value_nj * (real_T)
      rtb_LogicalOperator_n_idx_0;
    rtb_Gain4_idx_1 = claw_main_P.Gain4_Gain_o * rtb_MatrixConcatenation_j_0[2];

    /* Product: '<S18>/Product2' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Product2_a_idx_1 = claw_main_P.Constant_Value_nj * (real_T)
      rtb_LogicalOperator_n_idx_1;
    rtb_Gain4_idx_2 = claw_main_P.Gain4_Gain_o * rtb_MatrixConcatenation_j_0[3];

    /* Product: '<S18>/Product2' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Product2_a_idx_2 = claw_main_P.Constant_Value_nj * (real_T)
      rtb_LogicalOperator_n_idx_2;

    /* Gain: '<S62>/Gain1' incorporates:
     *  Math: '<S62>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
    rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
    rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_e[i] = 0.0;
      rtb_Gain1_e[i] += claw_main_P.Gain1_Gain_k[i] * rtb_delta_LLh_idx;
      rtb_Gain1_e[i] += claw_main_P.Gain1_Gain_k[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_e[i] += claw_main_P.Gain1_Gain_k[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_e[i] += claw_main_P.Gain1_Gain_k[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S62>/e1*e2' */
    rtb_e1e2_n = rtb_Switch_idx_0 * rtb_Switch_idx_1;

    /* Product: '<S62>/e3*e1' */
    rtb_e3e1_d = rtb_Switch_idx_2 * rtb_Switch_idx_0;

    /* Product: '<S62>/e2*e3' */
    rtb_e2e3_h = rtb_Switch_idx_1 * rtb_Switch_idx_2;

    /* Product: '<S62>/e0*e3' */
    rtb_e0e3_b = rtb_Switch_idx * rtb_Switch_idx_2;

    /* Product: '<S62>/e0*e2' */
    rtb_e0e2_d = rtb_Switch_idx * rtb_Switch_idx_1;

    /* Product: '<S62>/e0*e1' */
    rtb_e0e1_j = rtb_Switch_idx * rtb_Switch_idx_0;

    /* Gain: '<S62>/Gain' incorporates:
     *  Sum: '<S62>/Sum'
     *  Sum: '<S62>/Sum1'
     */
    rtb_Gain_jg[0] = (rtb_e1e2_n + rtb_e0e3_b) * claw_main_P.Gain_Gain_li;
    rtb_Gain_jg[1] = (rtb_e3e1_d + rtb_e0e2_d) * claw_main_P.Gain_Gain_li;
    rtb_Gain_jg[2] = (rtb_e2e3_h + rtb_e0e1_j) * claw_main_P.Gain_Gain_li;
    rtb_Gain_jg[3] = (rtb_e1e2_n - rtb_e0e3_b) * claw_main_P.Gain_Gain_li;
    rtb_Gain_jg[4] = (rtb_e3e1_d - rtb_e0e2_d) * claw_main_P.Gain_Gain_li;
    rtb_Gain_jg[5] = (rtb_e2e3_h - rtb_e0e1_j) * claw_main_P.Gain_Gain_li;

    /* SwitchCase: '<S61>/Switch Case' incorporates:
     *  ActionPort: '<S63>/Action Port'
     *  ActionPort: '<S64>/Action Port'
     *  ActionPort: '<S65>/Action Port'
     *  SubSystem: '<S61>/mba'
     *  SubSystem: '<S61>/tiltcam'
     *  SubSystem: '<S61>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam_b(rtb_Gain1_e[1], rtb_Gain_jg[3], rtb_Gain_jg[1],
                          rtb_Gain_jg[0], rtb_Gain1_e[2], rtb_Gain_jg[5],
                          rtb_Gain_jg[4], rtb_Gain_jg[2], rtb_Gain1_e[3],
                          claw_main_B.Merge_c, (rtP_tiltcam_claw_main_n *)
                          &claw_main_P.tiltcam_b);
      break;

     case 2:
     case 3:
      claw_main_ypr_c(rtb_Gain1_e[1], rtb_Gain_jg[3], rtb_Gain_jg[1],
                      rtb_Gain_jg[0], rtb_Gain1_e[2], rtb_Gain_jg[5],
                      rtb_Gain_jg[4], rtb_Gain_jg[2], rtb_Gain1_e[3],
                      claw_main_B.Merge_c, (rtP_ypr_claw_main_p *)
                      &claw_main_P.ypr_c);
      break;

     case 4:
     case 5:
      claw_main_mba_h(rtb_Gain1_e[1], rtb_Gain_jg[3], rtb_Gain_jg[1],
                      rtb_Gain_jg[0], rtb_Gain1_e[2], rtb_Gain_jg[5],
                      rtb_Gain_jg[4], rtb_Gain_jg[2], rtb_Gain1_e[3],
                      rtb_Product_h, rtb_Sum_m, rtb_Sum1_p, rtb_Product5,
                      rtb_Sum2_l, rtb_Sum3, rtb_Gain_p, rtb_Product10,
                      rtb_Product11, claw_main_B.Merge_c, (rtP_mba_claw_main_a *)
                      &claw_main_P.mba_h);
      break;
    }

    /* Selector: '<S61>/order atts' incorporates:
     *  Constant: '<S61>/Constant'
     *  Selector: '<S61>/Selector'
     */
    rtb_orderatts_a_idx = claw_main_B.Merge_c[(int32_T)
      claw_main_P.Constant_Value_ej[(int32_T)rtb_att_type - 1] - 1];
    rtb_orderatts_a_idx_0 = claw_main_B.Merge_c[(int32_T)
      claw_main_P.Constant_Value_ej[(int32_T)rtb_att_type + 4] - 1];
    rtb_orderatts_a_idx_1 = claw_main_B.Merge_c[(int32_T)
      claw_main_P.Constant_Value_ej[(int32_T)rtb_att_type + 9] - 1];

    /* MinMax: '<S795>/MinMax2' incorporates:
     *  Constant: '<S795>/Constant3'
     */
    max_1 = rt_MINd_snf(claw_main_P.Constant3_Value_jz, rtb_Assignment1_n[6]);

    /* UnitDelay: '<S10>/Unit Delay' */
    for (i = 0; i < 5; i++) {
      rtb_UnitDelay_n[i] = claw_main_DWork.UnitDelay_DSTATE_h[i];
    }

    /* Sum: '<S795>/Sum2' incorporates:
     *  Gain: '<S795>/Gain1'
     */
    rtb_Sum2_m5 = claw_main_P.Gain1_Gain_l * rtb_control_input[50] +
      claw_main_DWork.UnitDelay_DSTATE_h[4];

    /* MinMax: '<S795>/MinMax3' */
    max_4 = rt_MAXd_snf(max_1, rtb_Sum2_m5);

    /* Sum: '<S795>/Sum1' incorporates:
     *  Gain: '<S795>/Gain'
     */
    rtb_Sum1_d = claw_main_P.Gain_Gain_cm * rtb_control_input[40] +
      claw_main_DWork.UnitDelay_DSTATE_h[4];

    /* MinMax: '<S795>/MinMax1' incorporates:
     *  Constant: '<S795>/Constant1'
     */
    max_1 = rt_MAXd_snf(claw_main_P.Constant1_Value_dm, rtb_Assignment[6]);

    /* MinMax: '<S795>/MinMax4' */
    min_4 = rt_MINd_snf(rtb_Sum1_d, max_1);

    /* Gain: '<S423>/Gain1' */
    rtb_delta_LLh_idx = claw_main_P.Gain1_Gain_hb[0] * rtb_Gain_idx;
    rtb_delta_LLh_idx_0 = claw_main_P.Gain1_Gain_hb[1] * rtb_Gain_idx_0;
    rtb_Gain1_cg_idx = claw_main_P.Gain1_Gain_hb[2] * rtb_Gain_idx_1;

    /* Math: '<S428>/Math Function' */
    rtb_Rground_i = rt_hypot_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* Trigonometry: '<S428>/Trigonometric Function1' incorporates:
     *  Gain: '<S428>/Gain'
     */
    rtb_elevation_d = rt_atan2_snf(claw_main_P.Gain_Gain_cn * rtb_Gain1_cg_idx,
      rtb_Rground_i);

    /* Trigonometry: '<S429>/Trigonometric Function3' */
    rtb_TrigonometricFunction3_k = cos(rtb_elevation_d);

    /* Trigonometry: '<S428>/Trigonometric Function' */
    rtb_azimuth_k = rt_atan2_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* Trigonometry: '<S429>/Trigonometric Function5' */
    rtb_TrigonometricFunction5_o = cos(rtb_azimuth_k);

    /* Trigonometry: '<S429>/Trigonometric Function2' */
    rtb_TrigonometricFunction2_a = sin(rtb_elevation_d);

    /* Trigonometry: '<S429>/Trigonometric Function' incorporates:
     *  Constant: '<S428>/Constant'
     */
    rtb_TrigonometricFunction_p = sin(claw_main_P.Constant_Value_bsy);

    /* Product: '<S429>/Product9' */
    rtb_Product9_a = rtb_TrigonometricFunction5_o * rtb_TrigonometricFunction_p;

    /* Trigonometry: '<S429>/Trigonometric Function4' */
    rtb_TrigonometricFunction4_h = sin(rtb_azimuth_k);

    /* Trigonometry: '<S429>/Trigonometric Function1' incorporates:
     *  Constant: '<S428>/Constant'
     */
    rtb_TrigonometricFunction1_e = cos(claw_main_P.Constant_Value_bsy);

    /* Product: '<S429>/Product2' */
    rtb_Product2_j = rtb_TrigonometricFunction4_h * rtb_TrigonometricFunction1_e;

    /* Product: '<S429>/Product7' */
    rtb_Product7_m = rtb_TrigonometricFunction5_o * rtb_TrigonometricFunction1_e;

    /* Product: '<S429>/Product4' */
    rtb_Product4_f = rtb_TrigonometricFunction4_h * rtb_TrigonometricFunction_p;

    /* Gain: '<S423>/Gain' incorporates:
     *  Gain: '<S429>/Gain'
     *  Product: '<S429>/Product'
     *  Product: '<S429>/Product1'
     *  Product: '<S429>/Product10'
     *  Product: '<S429>/Product11'
     *  Product: '<S429>/Product3'
     *  Product: '<S429>/Product5'
     *  Product: '<S429>/Product6'
     *  Product: '<S429>/Product8'
     *  Reshape: '<S423>/Reshape'
     *  Sum: '<S429>/Sum'
     *  Sum: '<S429>/Sum1'
     *  Sum: '<S429>/Sum2'
     *  Sum: '<S429>/Sum3'
     */
    rtb_Gain_e[0] = rtb_TrigonometricFunction3_k * rtb_TrigonometricFunction5_o *
      claw_main_P.Gain_Gain_kl[0];
    rtb_Gain_e[1] = (rtb_TrigonometricFunction2_a * rtb_Product9_a -
                     rtb_Product2_j) * claw_main_P.Gain_Gain_kl[1];
    rtb_Gain_e[2] = (rtb_TrigonometricFunction2_a * rtb_Product7_m +
                     rtb_Product4_f) * claw_main_P.Gain_Gain_kl[2];
    rtb_Gain_e[3] = rtb_TrigonometricFunction3_k * rtb_TrigonometricFunction4_h *
      claw_main_P.Gain_Gain_kl[3];
    rtb_Gain_e[4] = (rtb_TrigonometricFunction2_a * rtb_Product4_f +
                     rtb_Product7_m) * claw_main_P.Gain_Gain_kl[4];
    rtb_Gain_e[5] = (rtb_TrigonometricFunction2_a * rtb_Product2_j -
                     rtb_Product9_a) * claw_main_P.Gain_Gain_kl[5];
    rtb_Gain_e[6] = claw_main_P.Gain_Gain_hm * rtb_TrigonometricFunction2_a *
      claw_main_P.Gain_Gain_kl[6];
    rtb_Gain_e[7] = rtb_TrigonometricFunction3_k * rtb_TrigonometricFunction_p *
      claw_main_P.Gain_Gain_kl[7];
    rtb_Gain_e[8] = rtb_TrigonometricFunction3_k * rtb_TrigonometricFunction1_e *
      claw_main_P.Gain_Gain_kl[8];

    /* Switch: '<S156>/Switch1' incorporates:
     *  Constant: '<S156>/Constant2'
     */
    if (rtb_control_input[94] >= claw_main_P.Switch1_Threshold_nl) {
      /* Switch: '<S156>/Switch' incorporates:
       *  Constant: '<S156>/Constant1'
       */
      if (rtb_control_input[105] >= claw_main_P.Switch_Threshold_c) {
        rtb_Switch_ec = claw_main_P.Constant1_Value_c;
      } else {
        rtb_Switch_ec = rtb_control_input[96];
      }

      rtb_Switch1_o = rtb_Switch_ec;
    } else {
      rtb_Switch1_o = claw_main_P.Constant2_Value_n;
    }

    /* SwitchCase: '<S156>/Switch Case' incorporates:
     *  ActionPort: '<S165>/Action Port'
     *  ActionPort: '<S166>/Action Port'
     *  ActionPort: '<S167>/Action Port'
     *  SubSystem: '<S156>/NED_dd//vchigam_dot'
     *  SubSystem: '<S156>/homing'
     *  SubSystem: '<S156>/normal vel desdyn'
     */
    switch ((int32_T)rtb_Switch1_o) {
     case 1:
     case 2:
      /* Gain: '<S165>/Gain' */
      claw_main_B.Merge2[0] = claw_main_P.Gain_Gain_i4[0] * rtb_Switch1_o;
      claw_main_B.Merge2[1] = claw_main_P.Gain_Gain_i4[1] * rtb_Switch1_o;
      claw_main_B.Merge2[2] = claw_main_P.Gain_Gain_i4[2] * rtb_Switch1_o;

      /* SignalConversion: '<S165>/Signal Conversion' incorporates:
       *  Assignment: '<S99>/set pos cmd'
       */
      claw_main_B.Merge1[0] = rtb_InterpolationnDusingPreLo_0;
      claw_main_B.Merge1[1] = rtb_InterpolationnDusingPreLo_1;
      claw_main_B.Merge1[2] = rtb_InterpolationnDusingPreLo_2;
      break;

     case 3:
      /* RelationalOperator: '<S168>/Compare' incorporates:
       *  Constant: '<S168>/Constant'
       */
      rtb_Compare_ff = (rtb_sensors[35] <= claw_main_P.Constant_Value_m);

      /* RelationalOperator: '<S169>/Compare' incorporates:
       *  Constant: '<S169>/Constant'
       */
      rtb_Compare_ov = (rtb_sensors[35] <= claw_main_P.Constant_Value_d);

      /* RelationalOperator: '<S170>/Compare' incorporates:
       *  Constant: '<S170>/Constant'
       */
      rtb_Compare_e4 = (rtb_sensors[35] >= claw_main_P.Constant_Value_df);

      /* Constant: '<S166>/Constant2' */
      claw_main_B.Merge1[0] = claw_main_P.Constant2_Value_f;

      /* Gain: '<S166>/Gain' incorporates:
       *  DataTypeConversion: '<S166>/Data Type Conversion'
       */
      claw_main_B.Merge2[0] = claw_main_P.Gain_Gain_c4 * (real_T)rtb_Compare_ov;
      claw_main_B.Merge2[1] = claw_main_P.Gain_Gain_c4 * (real_T)rtb_Compare_ov;
      claw_main_B.Merge2[2] = claw_main_P.Gain_Gain_c4 * (real_T)rtb_Compare_ff;

      /* Gain: '<S166>/azimuth_d//elevation_d gain' incorporates:
       *  Logic: '<S166>/Logical Operator2'
       *  Product: '<S166>/Product3'
       */
      claw_main_B.Merge1[1] = (rtb_Compare_ov && rtb_Compare_e4 ? rtb_sensors[30]
        : 0.0) * claw_main_P.azimuth_delevation_dgain_Gain[0];
      claw_main_B.Merge1[2] = (rtb_Compare_ff && rtb_Compare_e4 ? rtb_sensors[31]
        : 0.0) * claw_main_P.azimuth_delevation_dgain_Gain[1];
      break;

     default:
      /* Constant: '<S167>/Constant2' */
      claw_main_B.Merge2[0] = claw_main_P.Constant2_Value_p[0];

      /* Constant: '<S167>/Constant1' */
      claw_main_B.Merge1[0] = claw_main_P.Constant1_Value_px[0];

      /* Constant: '<S167>/Constant2' */
      claw_main_B.Merge2[1] = claw_main_P.Constant2_Value_p[1];

      /* Constant: '<S167>/Constant1' */
      claw_main_B.Merge1[1] = claw_main_P.Constant1_Value_px[1];

      /* Constant: '<S167>/Constant2' */
      claw_main_B.Merge2[2] = claw_main_P.Constant2_Value_p[2];

      /* Constant: '<S167>/Constant1' */
      claw_main_B.Merge1[2] = claw_main_P.Constant1_Value_px[2];
      break;
    }

    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S132>/command current vel'
     *  Reshape: '<S97>/Reshape'
     */
    if (claw_main_B.Merge2[0] >= claw_main_P.Switch_Threshold_d) {
      rtb_Switch_d_idx_0 = claw_main_P.commandcurrentvel_Value;
    } else {
      rtb_Switch_d_idx_0 = rtb_Selector[9];
    }

    if (claw_main_B.Merge2[1] >= claw_main_P.Switch_Threshold_d) {
      rtb_Switch_d_idx_1 = claw_main_P.commandcurrentvel_Value;
    } else {
      rtb_Switch_d_idx_1 = rtb_Selector[10];
    }

    if (claw_main_B.Merge2[2] >= claw_main_P.Switch_Threshold_d) {
      rtb_Switch_d_idx = claw_main_P.commandcurrentvel_Value;
    } else {
      rtb_Switch_d_idx = rtb_Selector[12];
    }

    /* Gain: '<S818>/Gain1' incorporates:
     *  Math: '<S818>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
    rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
    rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_jg[i] = 0.0;
      rtb_Gain1_jg[i] += claw_main_P.Gain1_Gain_ni[i] * rtb_delta_LLh_idx;
      rtb_Gain1_jg[i] += claw_main_P.Gain1_Gain_ni[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_jg[i] += claw_main_P.Gain1_Gain_ni[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_jg[i] += claw_main_P.Gain1_Gain_ni[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S818>/e1*e2' */
    rtb_e1e2_j = rtb_Switch_idx_0 * rtb_Switch_idx_1;

    /* Product: '<S818>/e3*e1' */
    rtb_e3e1_c = rtb_Switch_idx_2 * rtb_Switch_idx_0;

    /* Product: '<S818>/e2*e3' */
    rtb_e2e3_d = rtb_Switch_idx_1 * rtb_Switch_idx_2;

    /* Product: '<S818>/e0*e3' */
    rtb_e0e3_go = rtb_Switch_idx * rtb_Switch_idx_2;

    /* Product: '<S818>/e0*e2' */
    rtb_e0e2_a = rtb_Switch_idx * rtb_Switch_idx_1;

    /* Product: '<S818>/e0*e1' */
    rtb_e0e1_k5 = rtb_Switch_idx * rtb_Switch_idx_0;

    /* Gain: '<S818>/Gain' incorporates:
     *  Sum: '<S818>/Sum'
     *  Sum: '<S818>/Sum1'
     */
    rtb_Gain_po[0] = (rtb_e1e2_j + rtb_e0e3_go) * claw_main_P.Gain_Gain_m0;
    rtb_Gain_po[1] = (rtb_e3e1_c + rtb_e0e2_a) * claw_main_P.Gain_Gain_m0;
    rtb_Gain_po[2] = (rtb_e2e3_d + rtb_e0e1_k5) * claw_main_P.Gain_Gain_m0;
    rtb_Gain_po[3] = (rtb_e1e2_j - rtb_e0e3_go) * claw_main_P.Gain_Gain_m0;
    rtb_Gain_po[4] = (rtb_e3e1_c - rtb_e0e2_a) * claw_main_P.Gain_Gain_m0;
    rtb_Gain_po[5] = (rtb_e2e3_d - rtb_e0e1_k5) * claw_main_P.Gain_Gain_m0;

    /* SwitchCase: '<S817>/Switch Case' incorporates:
     *  ActionPort: '<S819>/Action Port'
     *  ActionPort: '<S820>/Action Port'
     *  ActionPort: '<S821>/Action Port'
     *  SubSystem: '<S817>/mba'
     *  SubSystem: '<S817>/tiltcam'
     *  SubSystem: '<S817>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam_b(rtb_Gain1_jg[1], rtb_Gain_po[3], rtb_Gain_po[1],
                          rtb_Gain_po[0], rtb_Gain1_jg[2], rtb_Gain_po[5],
                          rtb_Gain_po[4], rtb_Gain_po[2], rtb_Gain1_jg[3],
                          claw_main_B.Merge_i, (rtP_tiltcam_claw_main_n *)
                          &claw_main_P.tiltcam_l);
      break;

     case 2:
     case 3:
      claw_main_ypr_c(rtb_Gain1_jg[1], rtb_Gain_po[3], rtb_Gain_po[1],
                      rtb_Gain_po[0], rtb_Gain1_jg[2], rtb_Gain_po[5],
                      rtb_Gain_po[4], rtb_Gain_po[2], rtb_Gain1_jg[3],
                      claw_main_B.Merge_i, (rtP_ypr_claw_main_p *)
                      &claw_main_P.ypr_e);
      break;

     case 4:
     case 5:
      claw_main_mba_h(rtb_Gain1_jg[1], rtb_Gain_po[3], rtb_Gain_po[1],
                      rtb_Gain_po[0], rtb_Gain1_jg[2], rtb_Gain_po[5],
                      rtb_Gain_po[4], rtb_Gain_po[2], rtb_Gain1_jg[3],
                      rtb_Product_h, rtb_Sum_m, rtb_Sum1_p, rtb_Product5,
                      rtb_Sum2_l, rtb_Sum3, rtb_Gain_p, rtb_Product10,
                      rtb_Product11, claw_main_B.Merge_i, (rtP_mba_claw_main_a *)
                      &claw_main_P.mba_m);
      break;
    }

    /* Selector: '<S817>/order atts' incorporates:
     *  Constant: '<S817>/Constant'
     *  Selector: '<S817>/Selector'
     */
    rtb_orderatts_i_idx_0 = claw_main_B.Merge_i[(int32_T)
      claw_main_P.Constant_Value_br[(int32_T)rtb_att_type - 1] - 1];
    rtb_orderatts_i_idx_1 = claw_main_B.Merge_i[(int32_T)
      claw_main_P.Constant_Value_br[(int32_T)rtb_att_type + 4] - 1];
    rtb_orderatts_i_idx = claw_main_B.Merge_i[(int32_T)
      claw_main_P.Constant_Value_br[(int32_T)rtb_att_type + 9] - 1];

    /* UnitDelay: '<S188>/Unit Delay' */
    rtb_MultiportSwitch2_idx_2 = claw_main_DWork.UnitDelay_DSTATE_g[0];
    rtb_UnitDelay_nf_idx_0 = claw_main_DWork.UnitDelay_DSTATE_g[1];
    rtb_UnitDelay_nf_idx = claw_main_DWork.UnitDelay_DSTATE_g[2];

    /* FromWorkspace: '<S94>/From Workspace4' */
    {
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace4_PWORK_g.DataPtr;
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace4_PWORK_g.TimePtr;
      int_T currTimeIndex = claw_main_DWork.FromWorkspace4_IWORK_e.PrevIndex;
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      if (t >= pTimeValues[1]) {
        rtb_FromWorkspace4_b[0] = pDataValues[1];
        pDataValues += 2;
        rtb_FromWorkspace4_b[1] = pDataValues[1];
        pDataValues += 2;
        rtb_FromWorkspace4_b[2] = pDataValues[1];
        pDataValues += 2;
      } else {
        /* get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[1]) {
          currTimeIndex = 0;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        claw_main_DWork.FromWorkspace4_IWORK_e.PrevIndex = currTimeIndex;

        /* post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              rtb_FromWorkspace4_b[0] = pDataValues[currTimeIndex];
              pDataValues += 2;
              rtb_FromWorkspace4_b[1] = pDataValues[currTimeIndex];
              pDataValues += 2;
              rtb_FromWorkspace4_b[2] = pDataValues[currTimeIndex];
              pDataValues += 2;
            } else {
              rtb_FromWorkspace4_b[0] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
              rtb_FromWorkspace4_b[1] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
              rtb_FromWorkspace4_b[2] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex= currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace4_b[0] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace4_b[1] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace4_b[2] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
          }
        }
      }
    }

    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S94>/Constant'
     */
    if (claw_main_P.Constant_Value_ki >= claw_main_P.Switch_Threshold_gx) {
      /* Switch: '<S94>/Switch2' */
      if (rtb_Compare_df) {
        /* S-Function (sfun_kflookupnd): '<S123>/Interpolation (n-D) using PreLookup for vel' incorporates:
         *  Constant: '<S123>/Constant1'
         */
        if (claw_main_P.Constant1_Value_gz[0] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_gz[0] >= 0) {
          yOffset = claw_main_P.Constant1_Value_gz[0];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_3 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_f[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_gz[1] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_gz[1] >= 0) {
          yOffset = claw_main_P.Constant1_Value_gz[1];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_4 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_f[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_gz[2] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_gz[2] >= 0) {
          yOffset = claw_main_P.Constant1_Value_gz[2];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_5 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_f[yOffset << 1U]);
      } else {
        /* S-Function (sfun_kflookupnd): '<S124>/Interpolation (n-D) using PreLookup for vel' incorporates:
         *  Constant: '<S124>/Constant1'
         */
        if (claw_main_P.Constant1_Value_jh[0] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_jh[0] >= 0) {
          yOffset = claw_main_P.Constant1_Value_jh[0];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_3 = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_m[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_jh[1] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_jh[1] >= 0) {
          yOffset = claw_main_P.Constant1_Value_jh[1];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_4 = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_m[yOffset << 1U]);
        if (claw_main_P.Constant1_Value_jh[2] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant1_Value_jh[2] >= 0) {
          yOffset = claw_main_P.Constant1_Value_jh[2];
        } else {
          yOffset = 0;
        }

        rtb_InterpolationnDusingPreLo_5 = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_m[yOffset << 1U]);
      }
    } else {
      rtb_InterpolationnDusingPreLo_3 = rtb_FromWorkspace4_b[0];
      rtb_InterpolationnDusingPreLo_4 = rtb_FromWorkspace4_b[1];
      rtb_InterpolationnDusingPreLo_5 = rtb_FromWorkspace4_b[2];
    }

    /* Switch: '<S132>/Switch1' incorporates:
     *  Constant: '<S132>/command current pos'
     *  Reshape: '<S97>/Reshape'
     */
    if (claw_main_B.Merge2[0] >= claw_main_P.Switch1_Threshold_he) {
      rtb_delta_LLh_idx = claw_main_P.commandcurrentpos_Value;
    } else {
      rtb_delta_LLh_idx = rtb_Selector[13];
    }

    if (claw_main_B.Merge2[1] >= claw_main_P.Switch1_Threshold_he) {
      rtb_delta_LLh_idx_0 = claw_main_P.commandcurrentpos_Value;
    } else {
      rtb_delta_LLh_idx_0 = rtb_Selector[14];
    }

    if (claw_main_B.Merge2[2] >= claw_main_P.Switch1_Threshold_he) {
      rtb_Switch2_idx = claw_main_P.commandcurrentpos_Value;
    } else {
      rtb_Switch2_idx = rtb_Selector[16];
    }

    /* MultiPortSwitch: '<S189>/Multiport Switch' incorporates:
     *  Assignment: '<S132>/Assignment1'
     *  Assignment: '<S93>/set att cmd'
     *  Assignment: '<S99>/set pos cmd'
     *  Reshape: '<S97>/Reshape'
     */
    switch ((int32_T)rtb_delta_LLh_idx) {
     case 0:
      rtb_MultiportSwitch_o_idx_1 = rtb_NEh_e[0];
      break;

     case 1:
      rtb_MultiportSwitch_o_idx_1 = rtb_InterpolationnDusingPreLo_0;
      break;

     default:
      rtb_MultiportSwitch_o_idx_1 = 0.0;
      break;
    }

    switch ((int32_T)rtb_delta_LLh_idx_0) {
     case 0:
      rtb_MultiportSwitch_o_idx_2 = rtb_NEh_e[1];
      break;

     case 1:
      rtb_MultiportSwitch_o_idx_2 = rtb_InterpolationnDusingPreLo_1;
      break;

     default:
      rtb_MultiportSwitch_o_idx_2 = 0.0;
      break;
    }

    switch ((int32_T)rtb_Selector[15]) {
     case 0:
      rtb_MultiportSwitch_o_idx_0 = 0.0;
      break;

     case 1:
      rtb_MultiportSwitch_o_idx_0 = rtb_attcmdintegration_idx;
      break;

     default:
      rtb_MultiportSwitch_o_idx_0 = 0.0;
      break;
    }

    switch ((int32_T)rtb_Switch2_idx) {
     case 0:
      rtb_MultiportSwitch_o_idx = rtb_NEh_e[2];
      break;

     case 1:
      rtb_MultiportSwitch_o_idx = rtb_InterpolationnDusingPreLo_2;
      break;

     default:
      rtb_MultiportSwitch_o_idx = 0.0;
      break;
    }

    min[0] = rtb_Reshape_n[25];
    if (min[0] < 0.0) {
      rtb_MathFunction_h_idx = -sqrt(-min[0]);
    } else {
      rtb_MathFunction_h_idx = sqrt(min[0]);
    }

    /* Sum: '<S176>/Sum' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_fae -
      claw_main_P.Gain_Gain_k3 * rtb_Reshape_n[25];

    /* Math: '<S176>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain1'
     *  Sum: '<S176>/Sum1'
     */
    if (!(rtb_Reshape_n[25] >= claw_main_P.Switch_Threshold_j5)) {
      rtb_MathFunction_h_idx = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_fae) * claw_main_P.Gain1_Gain_c;
    }

    /* Switch: '<S176>/Switch1' incorporates:
     *  Constant: '<S176>/Constant3'
     */
    if (rtb_Reshape_n[22] >= claw_main_P.Switch1_Threshold_k) {
      rtb_Gain1_idx = claw_main_P.Constant3_Value_oq;
    } else {
      rtb_Gain1_idx = rtb_MathFunction_h_idx;
    }

    /* Product: '<S190>/Product5' */
    rtb_Product5_m_idx_0 = rtb_Gain1_idx * rtb_Reshape_n[19];
    min[1] = rtb_Reshape_n[26];
    if (min[1] < 0.0) {
      rtb_MathFunction_h_idx_0 = -sqrt(-min[1]);
    } else {
      rtb_MathFunction_h_idx_0 = sqrt(min[1]);
    }

    /* Sum: '<S176>/Sum' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_fae -
      claw_main_P.Gain_Gain_k3 * rtb_Reshape_n[26];

    /* Math: '<S176>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain1'
     *  Sum: '<S176>/Sum1'
     */
    if (!(rtb_Reshape_n[26] >= claw_main_P.Switch_Threshold_j5)) {
      rtb_MathFunction_h_idx_0 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_fae) * claw_main_P.Gain1_Gain_c;
    }

    /* Switch: '<S176>/Switch1' incorporates:
     *  Constant: '<S176>/Constant3'
     */
    if (rtb_Reshape_n[23] >= claw_main_P.Switch1_Threshold_k) {
      rtb_Gain1_idx_1 = claw_main_P.Constant3_Value_oq;
    } else {
      rtb_Gain1_idx_1 = rtb_MathFunction_h_idx_0;
    }

    /* Product: '<S190>/Product5' */
    rtb_Product5_m_idx_1 = rtb_Gain1_idx_1 * rtb_Reshape_n[20];
    min[2] = rtb_Reshape_n[27];
    if (min[2] < 0.0) {
      rtb_MathFunction_h_idx_1 = -sqrt(-min[2]);
    } else {
      rtb_MathFunction_h_idx_1 = sqrt(min[2]);
    }

    /* Sum: '<S176>/Sum' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_fae -
      claw_main_P.Gain_Gain_k3 * rtb_Reshape_n[27];

    /* Math: '<S176>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S176>/Constant'
     *  Gain: '<S176>/Gain1'
     *  Sum: '<S176>/Sum1'
     */
    if (!(rtb_Reshape_n[27] >= claw_main_P.Switch_Threshold_j5)) {
      rtb_MathFunction_h_idx_1 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_fae) * claw_main_P.Gain1_Gain_c;
    }

    /* Switch: '<S176>/Switch1' incorporates:
     *  Constant: '<S176>/Constant3'
     */
    if (rtb_Reshape_n[24] >= claw_main_P.Switch1_Threshold_k) {
      rtb_Gain1_idx_0 = claw_main_P.Constant3_Value_oq;
    } else {
      rtb_Gain1_idx_0 = rtb_MathFunction_h_idx_1;
    }

    /* Product: '<S190>/Product5' */
    rtb_Product5_m_idx = rtb_Gain1_idx_0 * rtb_Reshape_n[21];

    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S161>/Constant3'
     *  Constant: '<S161>/Constant6'
     *  Constant: '<S176>/Constant2'
     *  Constant: '<S176>/Constant4'
     *  Product: '<S176>/Divide2'
     *  Product: '<S176>/Divide3'
     *  Sum: '<S176>/Sum2'
     *  Sum: '<S176>/Sum3'
     */
    if (rtb_Reshape_n[22] >= claw_main_P.Switch2_Threshold_n) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_m;
    } else {
      rtb_delta_LLh_idx = (claw_main_P.Constant2_Value_ih - rtb_Gain1_idx) *
        claw_main_P.Constant6_Value_o[0] + 1.0 / rtb_Reshape_n[19] *
        claw_main_P.Constant3_Value_ba[0];
    }

    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S161>/Constant3'
     *  Constant: '<S161>/Constant6'
     *  Constant: '<S176>/Constant2'
     *  Constant: '<S176>/Constant4'
     *  Product: '<S176>/Divide2'
     *  Product: '<S176>/Divide3'
     *  Sum: '<S176>/Sum2'
     *  Sum: '<S176>/Sum3'
     */
    if (rtb_Reshape_n[23] >= claw_main_P.Switch2_Threshold_n) {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_m;
    } else {
      rtb_delta_LLh_idx_0 = (claw_main_P.Constant2_Value_ih - rtb_Gain1_idx_1) *
        claw_main_P.Constant6_Value_o[1] + 1.0 / rtb_Reshape_n[20] *
        claw_main_P.Constant3_Value_ba[1];
    }

    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S161>/Constant3'
     *  Constant: '<S161>/Constant6'
     *  Constant: '<S176>/Constant2'
     *  Constant: '<S176>/Constant4'
     *  Product: '<S176>/Divide2'
     *  Product: '<S176>/Divide3'
     *  Sum: '<S176>/Sum2'
     *  Sum: '<S176>/Sum3'
     */
    if (rtb_Reshape_n[24] >= claw_main_P.Switch2_Threshold_n) {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_m;
    } else {
      rtb_Switch2_idx = (claw_main_P.Constant2_Value_ih - rtb_Gain1_idx_0) *
        claw_main_P.Constant6_Value_o[2] + 1.0 / rtb_Reshape_n[21] *
        claw_main_P.Constant3_Value_ba[2];
    }

    /* DiscreteIntegrator: '<S186>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S190>/Gain'
     *  Product: '<S186>/Product4'
     *  Product: '<S190>/Product1'
     *  Product: '<S190>/Product2'
     *  Product: '<S190>/Product3'
     *  RelationalOperator: '<S191>/Compare'
     *  RelationalOperator: '<S192>/Compare'
     *  Sum: '<S186>/Sum1'
     *  Sum: '<S186>/Sum3'
     *  Sum: '<S190>/Sum'
     *  Sum: '<S190>/Sum1'
     *  Sum: '<S190>/Sum2'
     *  Sum: '<S190>/Sum6'
     *  UnitDelay: '<S186>/Unit Delay2'
     *  UnitDelay: '<S190>/Unit Delay'
     */
    if (claw_main_DWork.DiscreteTimeIntegrator_IC_LOADI) {
      claw_main_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2];
    } else if ((rtb_control_input[101] > 0.0) &&
               (claw_main_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2];
    } else {
      claw_main_B.DiscreteTimeIntegrator[0] =
        (((((claw_main_DWork.UnitDelay_DSTATE_e[0] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_e[0] - rtb_Product5_m_idx_0) *
             rtb_MultiportSwitch_o_idx_1 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_e[3] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] - rtb_NEh_e[0])
             * (claw_main_DWork.UnitDelay_DSTATE_e[3] - rtb_Reshape_n[19]) : 0.0))
           / rtb_Reshape_n[19] * claw_main_P.Gain_Gain_d5 - (rtb_Reshape_n[25] ==
            0.0 ? rtb_Reshape_n[19] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] : 0.0)) +
          rtb_Reshape_n[25] * rtb_Reshape_n[19] * (rtb_MultiportSwitch_o_idx_1 -
           rtb_NEh_e[0])) + claw_main_DWork.UnitDelay2_DSTATE_a[0]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_o +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0];
      claw_main_B.DiscreteTimeIntegrator[1] =
        (((((claw_main_DWork.UnitDelay_DSTATE_e[1] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_e[1] - rtb_Product5_m_idx_1) *
             rtb_MultiportSwitch_o_idx_2 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_e[4] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] - rtb_NEh_e[1])
             * (claw_main_DWork.UnitDelay_DSTATE_e[4] - rtb_Reshape_n[20]) : 0.0))
           / rtb_Reshape_n[20] * claw_main_P.Gain_Gain_d5 - (rtb_Reshape_n[26] ==
            0.0 ? rtb_Reshape_n[20] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] : 0.0)) +
          rtb_Reshape_n[26] * rtb_Reshape_n[20] * (rtb_MultiportSwitch_o_idx_2 -
           rtb_NEh_e[1])) + claw_main_DWork.UnitDelay2_DSTATE_a[1]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_o +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1];
      claw_main_B.DiscreteTimeIntegrator[2] =
        (((((claw_main_DWork.UnitDelay_DSTATE_e[2] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_e[2] - rtb_Product5_m_idx) *
             rtb_MultiportSwitch_o_idx : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_e[5] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] - rtb_NEh_e[2])
             * (claw_main_DWork.UnitDelay_DSTATE_e[5] - rtb_Reshape_n[21]) : 0.0))
           / rtb_Reshape_n[21] * claw_main_P.Gain_Gain_d5 - (rtb_Reshape_n[27] ==
            0.0 ? rtb_Reshape_n[21] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] : 0.0)) +
          rtb_Reshape_n[27] * rtb_Reshape_n[21] * (rtb_MultiportSwitch_o_idx -
           rtb_NEh_e[2])) + claw_main_DWork.UnitDelay2_DSTATE_a[2]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_o +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2];
    }

    if (rtb_control_input[101] > 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (rtb_control_input[101] < 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRese = -1;
    } else {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRese = 0;
    }

    /* Sum: '<S186>/Sum4' incorporates:
     *  Product: '<S186>/Product2'
     *  Product: '<S186>/Product5'
     *  Product: '<S186>/Product6'
     *  Sum: '<S186>/Sum2'
     *  Sum: '<S186>/Sum5'
     */
    rtb_Sum4_c_idx_0 = ((rtb_MultiportSwitch_o_idx_1 * rtb_Gain1_idx -
                         rtb_NEh_e[0]) + claw_main_B.DiscreteTimeIntegrator[0]) *
      rtb_Reshape_n[19] + rtb_Reshape_n[22] * rtb_InterpolationnDusingPreLo_3;
    rtb_Sum4_c_idx_1 = ((rtb_MultiportSwitch_o_idx_2 * rtb_Gain1_idx_1 -
                         rtb_NEh_e[1]) + claw_main_B.DiscreteTimeIntegrator[1]) *
      rtb_Reshape_n[20] + rtb_Reshape_n[23] * rtb_InterpolationnDusingPreLo_4;
    rtb_Sum4_c_idx = ((rtb_MultiportSwitch_o_idx * rtb_Gain1_idx_0 - rtb_NEh_e[2])
                      + claw_main_B.DiscreteTimeIntegrator[2]) * rtb_Reshape_n
      [21] + rtb_Reshape_n[24] * rtb_InterpolationnDusingPreLo_5;

    /* Switch: '<S188>/Switch' incorporates:
     *  Constant: '<S188>/Constant'
     *  Math: '<S188>/Math Function'
     *  Product: '<S188>/Product1'
     *  Saturate: '<S188>/Saturation'
     *  Saturate: '<S188>/Saturation1'
     *  Sum: '<S188>/Sum1'
     */
    if (claw_main_P.Constant_Value_gwi >= claw_main_P.Switch_Threshold_nr) {
      /* Switch: '<S188>/Switch1' incorporates:
       *  Assignment: '<S132>/Assignment'
       *  Constant: '<S193>/Constant'
       *  RelationalOperator: '<S193>/Compare'
       *  Reshape: '<S97>/Reshape'
       */
      if (rtb_Switch_d_idx_0 < claw_main_P.Constant_Value_o) {
        rtb_InterpolationnDusingPreLo_3 = rtb_MultiportSwitch2_idx_2;
      }

      if (rtb_Switch_d_idx_1 < claw_main_P.Constant_Value_o) {
        rtb_InterpolationnDusingPreLo_4 = rtb_UnitDelay_nf_idx_0;
      }

      if (rtb_Switch_d_idx < claw_main_P.Constant_Value_o) {
        rtb_InterpolationnDusingPreLo_5 = rtb_UnitDelay_nf_idx;
      }

      /* Product: '<S188>/Product' incorporates:
       *  Sum: '<S188>/Sum'
       */
      rtb_delta_LLh_idx = rtb_Sum4_c_idx_0 - rtb_InterpolationnDusingPreLo_3;
      rtb_delta_LLh_idx_0 = rtb_Sum4_c_idx_1 - rtb_InterpolationnDusingPreLo_4;
      rtb_Switch2_idx = rtb_Sum4_c_idx - rtb_InterpolationnDusingPreLo_5;
      for (i = 0; i < 3; i++) {
        rtb_Product_c3[i] = 0.0;
        rtb_Product_c3[i] += rtb_Gain_e[i] * rtb_delta_LLh_idx;
        rtb_Product_c3[i] += rtb_Gain_e[i + 3] * rtb_delta_LLh_idx_0;
        rtb_Product_c3[i] += rtb_Gain_e[i + 6] * rtb_Switch2_idx;
      }

      rtb_delta_LLh_idx = rt_SATURATE(rtb_Product_c3[0],
        claw_main_P.Saturation1_LowerSat[0], claw_main_P.Saturation1_UpperSat[0]);
      rtb_delta_LLh_idx_0 = rt_SATURATE(rtb_Product_c3[1],
        claw_main_P.Saturation1_LowerSat[1], claw_main_P.Saturation1_UpperSat[1]);
      rtb_Switch2_idx = rt_SATURATE(rtb_Product_c3[2],
        claw_main_P.Saturation1_LowerSat[2], claw_main_P.Saturation1_UpperSat[2]);
      for (i = 0; i < 3; i++) {
        rtb_Gain_e_0[i] = 0.0;
        rtb_Gain_e_0[i] += rtb_Gain_e[3 * i] * rtb_delta_LLh_idx;
        rtb_Gain_e_0[i] += rtb_Gain_e[3 * i + 1] * rtb_delta_LLh_idx_0;
        rtb_Gain_e_0[i] += rtb_Gain_e[3 * i + 2] * rtb_Switch2_idx;
      }

      rtb_Switch_m_idx_0 = rtb_InterpolationnDusingPreLo_3 + rtb_Gain_e_0[0];
      rtb_Switch_m_idx_1 = rtb_InterpolationnDusingPreLo_4 + rtb_Gain_e_0[1];
      rtb_Switch_m_idx = rtb_InterpolationnDusingPreLo_5 + rtb_Gain_e_0[2];
    } else {
      rtb_Switch_m_idx_0 = rt_SATURATE(rtb_Sum4_c_idx_0,
        claw_main_P.Saturation_LowerSat[0], claw_main_P.Saturation_UpperSat[0]);
      rtb_Switch_m_idx_1 = rt_SATURATE(rtb_Sum4_c_idx_1,
        claw_main_P.Saturation_LowerSat[1], claw_main_P.Saturation_UpperSat[1]);
      rtb_Switch_m_idx = rt_SATURATE(rtb_Sum4_c_idx,
        claw_main_P.Saturation_LowerSat[2], claw_main_P.Saturation_UpperSat[2]);
    }

    /* MultiPortSwitch: '<S529>/Multiport Switch' incorporates:
     *  Assignment: '<S132>/Assignment'
     *  Assignment: '<S93>/set att cmd'
     *  Assignment: '<S99>/set pos cmd'
     */
    switch ((int32_T)rtb_Switch_d_idx_0) {
     case 0:
      rtb_MultiportSwitch_n_idx_0 = rtb_Gain_idx;
      break;

     case 1:
      rtb_MultiportSwitch_n_idx_0 = rtb_InterpolationnDusingPreLo_0;
      break;

     default:
      rtb_MultiportSwitch_n_idx_0 = rtb_Switch_m_idx_0;
      break;
    }

    switch ((int32_T)rtb_Switch_d_idx_1) {
     case 0:
      rtb_MultiportSwitch_n_idx_1 = rtb_Gain_idx_0;
      break;

     case 1:
      rtb_MultiportSwitch_n_idx_1 = rtb_InterpolationnDusingPreLo_1;
      break;

     default:
      rtb_MultiportSwitch_n_idx_1 = rtb_Switch_m_idx_1;
      break;
    }

    switch ((int32_T)rtb_Selector[11]) {
     case 0:
      rtb_MultiportSwitch_o_idx_0 = rtb_orderatts_i_idx;
      break;

     case 1:
      rtb_MultiportSwitch_o_idx_0 = rtb_attcmdintegration_idx;
      break;
    }

    switch ((int32_T)rtb_Switch_d_idx) {
     case 0:
      rtb_MultiportSwitch_n_idx = rtb_Gain_idx_1;
      break;

     case 1:
      rtb_MultiportSwitch_n_idx = rtb_InterpolationnDusingPreLo_2;
      break;

     default:
      rtb_MultiportSwitch_n_idx = rtb_Switch_m_idx;
      break;
    }

    /* Gain: '<S789>/Gain1' */
    rtb_delta_LLh_idx = claw_main_P.Gain1_Gain_ht[0] *
      rtb_MultiportSwitch_n_idx_0;
    rtb_delta_LLh_idx_0 = claw_main_P.Gain1_Gain_ht[1] *
      rtb_MultiportSwitch_n_idx_1;
    rtb_Gain1_lr_idx = claw_main_P.Gain1_Gain_ht[2] * rtb_MultiportSwitch_n_idx;

    /* Math: '<S793>/Math Function' */
    rtb_Rground_f = rt_hypot_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* MultiPortSwitch: '<S530>/Multiport Switch2' incorporates:
     *  Constant: '<S530>/Constant1'
     *  Gain: '<S530>/Gain2'
     *  RelationalOperator: '<S530>/Relational Operator'
     */
    if ((max_4 == min_4) == 0) {
      memcpy((void *)&rtb_wght_cv[0], (void *)(&claw_main_P.Constant1_Value_n[0]),
             9U * (uint32_T)((char_T *)(&claw_main_P.Constant1_Value_n[1]) -
              (char_T *)(&claw_main_P.Constant1_Value_n[0])));
    } else {
      /* Switch: '<S786>/SwitchControl' incorporates:
       *  Constant: '<S786>/Constant'
       *  Gain: '<S789>/Gain'
       *  Gain: '<S794>/Gain'
       *  Product: '<S794>/Product'
       *  Product: '<S794>/Product1'
       *  Product: '<S794>/Product10'
       *  Product: '<S794>/Product11'
       *  Product: '<S794>/Product3'
       *  Product: '<S794>/Product5'
       *  Product: '<S794>/Product6'
       *  Product: '<S794>/Product8'
       *  Reshape: '<S789>/Reshape'
       *  Sum: '<S794>/Sum'
       *  Sum: '<S794>/Sum1'
       *  Sum: '<S794>/Sum2'
       *  Sum: '<S794>/Sum3'
       */
      if (claw_main_P.Constant_Value_hu > claw_main_P.SwitchControl_Threshold_i)
      {
        memcpy((void *)&rtb_SwitchControl_c[0], (void *)&rtb_Gain_e[0], 9U *
               (uint32_T)((char_T *)&rtb_Gain_e[1U] - (char_T *)&rtb_Gain_e[0U]));
      } else {
        /* Trigonometry: '<S794>/Trigonometric Function1' incorporates:
         *  Constant: '<S793>/Constant'
         */
        rtb_TrigonometricFunction1_a = cos(claw_main_P.Constant_Value_pk);

        /* Trigonometry: '<S793>/Trigonometric Function1' incorporates:
         *  Gain: '<S793>/Gain'
         */
        rtb_elevation_k = rt_atan2_snf(claw_main_P.Gain_Gain_dh *
          rtb_Gain1_lr_idx, rtb_Rground_f);

        /* Trigonometry: '<S794>/Trigonometric Function3' */
        rtb_TrigonometricFunction3_iq = cos(rtb_elevation_k);

        /* Trigonometry: '<S794>/Trigonometric Function' incorporates:
         *  Constant: '<S793>/Constant'
         */
        rtb_TrigonometricFunction_a = sin(claw_main_P.Constant_Value_pk);

        /* Trigonometry: '<S794>/Trigonometric Function2' */
        rtb_TrigonometricFunction2_h = sin(rtb_elevation_k);

        /* Trigonometry: '<S793>/Trigonometric Function' */
        rtb_azimuth_c = rt_atan2_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

        /* Trigonometry: '<S794>/Trigonometric Function4' */
        rtb_TrigonometricFunction4_o = sin(rtb_azimuth_c);

        /* Product: '<S794>/Product2' */
        rtb_Product2_bm = rtb_TrigonometricFunction4_o *
          rtb_TrigonometricFunction1_a;

        /* Trigonometry: '<S794>/Trigonometric Function5' */
        rtb_TrigonometricFunction5_l = cos(rtb_azimuth_c);

        /* Product: '<S794>/Product9' */
        rtb_Product9_d = rtb_TrigonometricFunction5_l *
          rtb_TrigonometricFunction_a;

        /* Product: '<S794>/Product4' */
        rtb_Product4_aq = rtb_TrigonometricFunction4_o *
          rtb_TrigonometricFunction_a;

        /* Product: '<S794>/Product7' */
        rtb_Product7_h = rtb_TrigonometricFunction5_l *
          rtb_TrigonometricFunction1_a;
        rtb_SwitchControl_c[0] = rtb_TrigonometricFunction3_iq *
          rtb_TrigonometricFunction5_l * claw_main_P.Gain_Gain_cb[0];
        rtb_SwitchControl_c[1] = (rtb_TrigonometricFunction2_h * rtb_Product9_d
          - rtb_Product2_bm) * claw_main_P.Gain_Gain_cb[1];
        rtb_SwitchControl_c[2] = (rtb_TrigonometricFunction2_h * rtb_Product7_h
          + rtb_Product4_aq) * claw_main_P.Gain_Gain_cb[2];
        rtb_SwitchControl_c[3] = rtb_TrigonometricFunction3_iq *
          rtb_TrigonometricFunction4_o * claw_main_P.Gain_Gain_cb[3];
        rtb_SwitchControl_c[4] = (rtb_TrigonometricFunction2_h * rtb_Product4_aq
          + rtb_Product7_h) * claw_main_P.Gain_Gain_cb[4];
        rtb_SwitchControl_c[5] = (rtb_TrigonometricFunction2_h * rtb_Product2_bm
          - rtb_Product9_d) * claw_main_P.Gain_Gain_cb[5];
        rtb_SwitchControl_c[6] = claw_main_P.Gain_Gain_o0 *
          rtb_TrigonometricFunction2_h * claw_main_P.Gain_Gain_cb[6];
        rtb_SwitchControl_c[7] = rtb_TrigonometricFunction3_iq *
          rtb_TrigonometricFunction_a * claw_main_P.Gain_Gain_cb[7];
        rtb_SwitchControl_c[8] = rtb_TrigonometricFunction3_iq *
          rtb_TrigonometricFunction1_a * claw_main_P.Gain_Gain_cb[8];
      }

      for (i = 0; i < 9; i++) {
        rtb_wght_cv[i] = claw_main_P.Gain2_Gain_e[i] * rtb_SwitchControl_c[i];
      }
    }

    /* Assignment: '<S522>/zero pqr' incorporates:
     *  Constant: '<S522>/Constant'
     *  SignalConversion: '<S522>/TmpHiddenBufferAtzero pqrInport1'
     */
    rtb_zeropqr[0] = rtb_sensors[0];
    rtb_zeropqr[1] = rtb_sensors[1];
    rtb_zeropqr[2] = rtb_sensors[2];
    rtb_zeropqr[3] = rtb_uvw[0];
    rtb_zeropqr[4] = rtb_uvw[1];
    rtb_zeropqr[5] = rtb_uvw[2];
    rtb_zeropqr[6] = rtb_NEh_e[0];
    rtb_zeropqr[7] = rtb_NEh_e[1];
    rtb_zeropqr[8] = rtb_NEh_e[2];
    rtb_zeropqr[9] = rtb_Switch_idx;
    rtb_zeropqr[10] = rtb_Switch_idx_0;
    rtb_zeropqr[11] = rtb_Switch_idx_1;
    rtb_zeropqr[12] = rtb_Switch_idx_2;
    rtb_zeropqr[0] = claw_main_P.Constant_Value_b1;
    rtb_zeropqr[1] = claw_main_P.Constant_Value_b1;
    rtb_zeropqr[2] = claw_main_P.Constant_Value_b1;

    /* SignalConversion: '<S736>/TmpHiddenBufferAtorder attsInport1' */
    rtb_TmpHiddenBufferAtorderattsI[0] = rtb_orderatts_i_idx_0;
    rtb_TmpHiddenBufferAtorderattsI[1] = rtb_orderatts_i_idx_1;
    rtb_TmpHiddenBufferAtorderattsI[2] = rtb_MultiportSwitch_o_idx_0;

    /* Selector: '<S736>/order atts' incorporates:
     *  Constant: '<S736>/Constant'
     *  Selector: '<S736>/Selector'
     */
    rtb_orderatts_k[0] = rtb_TmpHiddenBufferAtorderattsI[(int32_T)
      claw_main_P.Constant_Value_c4[(int32_T)rtb_att_type - 1] - 1];
    rtb_orderatts_k[1] = rtb_TmpHiddenBufferAtorderattsI[(int32_T)
      claw_main_P.Constant_Value_c4[(int32_T)rtb_att_type + 4] - 1];
    rtb_orderatts_k[2] = rtb_TmpHiddenBufferAtorderattsI[(int32_T)
      claw_main_P.Constant_Value_c4[(int32_T)rtb_att_type + 9] - 1];

    /* SwitchCase: '<S736>/Switch Case' incorporates:
     *  ActionPort: '<S738>/Action Port'
     *  ActionPort: '<S739>/Action Port'
     *  ActionPort: '<S740>/Action Port'
     *  SubSystem: '<S736>/mba'
     *  SubSystem: '<S736>/tiltcam'
     *  SubSystem: '<S736>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam(rtb_orderatts_k, claw_main_B.Merge_b,
                        (rtP_tiltcam_claw_main *) &claw_main_P.tiltcam_p);
      break;

     case 2:
     case 3:
      claw_main_ypr(rtb_orderatts_k, claw_main_B.Merge_b, (rtP_ypr_claw_main *)
                    &claw_main_P.ypr_c5);
      break;

     case 4:
     case 5:
      claw_main_mba(rtb_orderatts_k, rtb_Product_h, rtb_Sum_m, rtb_Sum1_p,
                    rtb_Product5, rtb_Sum2_l, rtb_Sum3, rtb_Gain_p,
                    rtb_Product10, rtb_Product11, claw_main_B.Merge_b,
                    (rtP_mba_claw_main *) &claw_main_P.mba_g);
      break;
    }

    /* Gain: '<S753>/Gain' incorporates:
     *  Constant: '<S753>/Constant'
     *  Gain: '<S753>/Matrix Gain'
     *  Sum: '<S753>/Sum'
     */
    for (i = 0; i < 16; i++) {
      tmp_8[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        tmp_8[i] += claw_main_P.MatrixGain_Gain_b[(yOffset_0 << 4) + i] *
          claw_main_B.Merge_b[yOffset_0];
      }

      rtb_Gain_l[i] = (tmp_8[i] + claw_main_P.Constant_Value_c5[i]) *
        claw_main_P.Gain_Gain_g0;
    }

    /* SignalConversion: '<S753>/TmpHiddenBufferAtselect best diagInport1' */
    rtb_TmpHiddenBufferAtselectbest[0] = rtb_Gain_l[0];
    rtb_TmpHiddenBufferAtselectbest[1] = rtb_Gain_l[5];
    rtb_TmpHiddenBufferAtselectbest[2] = rtb_Gain_l[10];
    rtb_TmpHiddenBufferAtselectbest[3] = rtb_Gain_l[15];

    /* MinMax: '<S753>/MinMax3' */
    max_1 = rt_MAXd_snf(rtb_TmpHiddenBufferAtselectbest[0],
                        rtb_TmpHiddenBufferAtselectbest[1]);
    max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbest[2]);
    max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbest[3]);

    /* Switch: '<S753>/argmax1' incorporates:
     *  Constant: '<S753>/Constant4'
     *  Constant: '<S753>/Constant5'
     *  Sum: '<S753>/Sum2'
     */
    if (rtb_TmpHiddenBufferAtselectbest[0] - max_1 >=
        claw_main_P.argmax1_Threshold_oh) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_e[0];
    } else {
      rtb_delta_LLh_idx = claw_main_P.Constant5_Value_j;
    }

    if (rtb_TmpHiddenBufferAtselectbest[1] - max_1 >=
        claw_main_P.argmax1_Threshold_oh) {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_e[1];
    } else {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant5_Value_j;
    }

    if (rtb_TmpHiddenBufferAtselectbest[2] - max_1 >=
        claw_main_P.argmax1_Threshold_oh) {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_e[2];
    } else {
      rtb_Switch2_idx = claw_main_P.Constant5_Value_j;
    }

    if (rtb_TmpHiddenBufferAtselectbest[3] - max_1 >=
        claw_main_P.argmax1_Threshold_oh) {
      rtb_Gain1_idx_0 = claw_main_P.Constant4_Value_e[3];
    } else {
      rtb_Gain1_idx_0 = claw_main_P.Constant5_Value_j;
    }

    /* MinMax: '<S753>/MinMax4' */
    max_1 = rt_MINd_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);
    max_1 = rt_MINd_snf(max_1, rtb_Switch2_idx);
    max_1 = rt_MINd_snf(max_1, rtb_Gain1_idx_0);

    /* Selector: '<S753>/select best col' incorporates:
     *  Reshape: '<S753>/Reshape1'
     */
    i = ((int32_T)max_1 - 1) << 2;

    /* Selector: '<S753>/select best diag' */
    rtb_selectbestdiag = rtb_TmpHiddenBufferAtselectbest[(int32_T)max_1 - 1];

    /* Math: '<S753>/Math Function' */
    if (rtb_selectbestdiag < 0.0) {
      rtb_MathFunction_eu = -sqrt(-rtb_selectbestdiag);
    } else {
      rtb_MathFunction_eu = sqrt(rtb_selectbestdiag);
    }

    /* Product: '<S753>/Product' */
    rtb_Gain1_idx_0 = rtb_Gain_l[i] / rtb_MathFunction_eu;
    rtb_Gain1_idx_1 = rtb_Gain_l[i + 1] / rtb_MathFunction_eu;
    rtb_Gain1_idx = rtb_Gain_l[i + 2] / rtb_MathFunction_eu;
    rtb_MultiportSwitch2_idx_2 = rtb_Gain_l[i + 3] / rtb_MathFunction_eu;

    /* Switch: '<S737>/Switch' incorporates:
     *  Gain: '<S737>/Gain'
     *  Reshape: '<S753>/Reshape2'
     *  S-Function (sfix_dot): '<S737>/Dot Product'
     */
    rtb_delta_LLh_idx = ((rtb_Gain1_idx_0 * rtb_zeropqr[9] + rtb_Gain1_idx_1 *
                          rtb_zeropqr[10]) + rtb_Gain1_idx * rtb_zeropqr[11]) +
      rtb_MultiportSwitch2_idx_2 * rtb_zeropqr[12];
    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_ok)) {
      rtb_Gain1_idx_0 *= claw_main_P.Gain_Gain_pq;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_ok)) {
      rtb_Gain1_idx_1 *= claw_main_P.Gain_Gain_pq;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_ok)) {
      rtb_Gain1_idx *= claw_main_P.Gain_Gain_pq;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_ok)) {
      rtb_MultiportSwitch2_idx_2 *= claw_main_P.Gain_Gain_pq;
    }

    /* SignalConversion: '<S535>/TmpHiddenBufferAtAssignment2Inport2' incorporates:
     *  Gain: '<S535>/Gain'
     *  Product: '<S535>/Product1'
     *  Reshape: '<S535>/Reshape1'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_cl[0] * rtb_Gain_idx;
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_cl[1] * rtb_Gain_idx_0;
    rtb_Switch2_idx = claw_main_P.Gain_Gain_cl[2] * rtb_Gain_idx_1;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += claw_main_B.Merge_b[i] * rtb_delta_LLh_idx;
      rtb_dircos_0[i] += claw_main_B.Merge_b[i + 3] * rtb_delta_LLh_idx_0;
      rtb_dircos_0[i] += claw_main_B.Merge_b[i + 6] * rtb_Switch2_idx;
    }

    rtb_TmpHiddenBufferAtAssignment[0] = rtb_Gain1_idx_0;
    rtb_TmpHiddenBufferAtAssignment[1] = rtb_Gain1_idx_1;
    rtb_TmpHiddenBufferAtAssignment[2] = rtb_Gain1_idx;
    rtb_TmpHiddenBufferAtAssignment[3] = rtb_MultiportSwitch2_idx_2;
    rtb_TmpHiddenBufferAtAssignment[4] = rtb_dircos_0[0];
    rtb_TmpHiddenBufferAtAssignment[5] = rtb_dircos_0[1];
    rtb_TmpHiddenBufferAtAssignment[6] = rtb_dircos_0[2];

    /* Assignment: '<S535>/Assignment2' */
    memcpy((void *)&rtb_Assignment2[0], (void *)&rtb_zeropqr[0], 13U * (uint32_T)
           ((char_T *)&rtb_zeropqr[1U] - (char_T *)&rtb_zeropqr[0U]));
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 7; uDimIdx++) {
      rtb_Assignment2[(int32_T)tmp_a[uDimIdx]] =
        rtb_TmpHiddenBufferAtAssignment[yOffset];
      yOffset++;
    }

    /* Gain: '<S649>/Gain1' incorporates:
     *  Math: '<S649>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Assignment2[9] * rtb_Assignment2[9];
    rtb_delta_LLh_idx_0 = rtb_Assignment2[10] * rtb_Assignment2[10];
    rtb_Switch2_idx = rtb_Assignment2[11] * rtb_Assignment2[11];
    rtb_Gain1_idx_0 = rtb_Assignment2[12] * rtb_Assignment2[12];
    for (i = 0; i < 4; i++) {
      rtb_Gain1_oy[i] = 0.0;
      rtb_Gain1_oy[i] += claw_main_P.Gain1_Gain_pk[i] * rtb_delta_LLh_idx;
      rtb_Gain1_oy[i] += claw_main_P.Gain1_Gain_pk[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_oy[i] += claw_main_P.Gain1_Gain_pk[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_oy[i] += claw_main_P.Gain1_Gain_pk[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S649>/e1*e2' */
    rtb_e1e2_i = rtb_Assignment2[10] * rtb_Assignment2[11];

    /* Product: '<S649>/e3*e1' */
    rtb_e3e1_e = rtb_Assignment2[12] * rtb_Assignment2[10];

    /* Product: '<S649>/e2*e3' */
    rtb_e2e3_e = rtb_Assignment2[11] * rtb_Assignment2[12];

    /* Product: '<S649>/e0*e3' */
    rtb_e0e3_n = rtb_Assignment2[9] * rtb_Assignment2[12];

    /* Product: '<S649>/e0*e2' */
    rtb_e0e2_k = rtb_Assignment2[9] * rtb_Assignment2[11];

    /* Product: '<S649>/e0*e1' */
    rtb_e0e1_m = rtb_Assignment2[9] * rtb_Assignment2[10];

    /* Gain: '<S649>/Gain' incorporates:
     *  Sum: '<S649>/Sum'
     *  Sum: '<S649>/Sum1'
     */
    rtb_Gain_g_idx = (rtb_e1e2_i + rtb_e0e3_n) * claw_main_P.Gain_Gain_bqn;
    rtb_Gain_g_idx_0 = (rtb_e3e1_e + rtb_e0e2_k) * claw_main_P.Gain_Gain_bqn;
    rtb_Gain_g_idx_1 = (rtb_e2e3_e + rtb_e0e1_m) * claw_main_P.Gain_Gain_bqn;
    rtb_Gain_g_idx_2 = (rtb_e1e2_i - rtb_e0e3_n) * claw_main_P.Gain_Gain_bqn;
    rtb_Gain_g_idx_3 = (rtb_e3e1_e - rtb_e0e2_k) * claw_main_P.Gain_Gain_bqn;
    rtb_Gain_g_idx_4 = (rtb_e2e3_e - rtb_e0e1_m) * claw_main_P.Gain_Gain_bqn;

    /* Reshape: '<S648>/Reshape' */
    rtb_dircos_b[0] = rtb_Gain1_oy[1];
    rtb_dircos_b[1] = rtb_Gain_g_idx_2;
    rtb_dircos_b[2] = rtb_Gain_g_idx_0;
    rtb_dircos_b[3] = rtb_Gain_g_idx;
    rtb_dircos_b[4] = rtb_Gain1_oy[2];
    rtb_dircos_b[5] = rtb_Gain_g_idx_4;
    rtb_dircos_b[6] = rtb_Gain_g_idx_3;
    rtb_dircos_b[7] = rtb_Gain_g_idx_1;
    rtb_dircos_b[8] = rtb_Gain1_oy[3];

    /* Product: '<S648>/Product1' incorporates:
     *  Gain: '<S648>/g'
     *  Selector: '<S648>/dircos(:,3)'
     */
    rtb_Product1_b_idx = claw_main_P.g_Gain_g * rtb_dircos_b[6] *
      claw_main_B.mass;
    rtb_Product1_b_idx_0 = claw_main_P.g_Gain_g * rtb_dircos_b[7] *
      claw_main_B.mass;
    rtb_Product1_b_idx_1 = claw_main_P.g_Gain_g * rtb_dircos_b[8] *
      claw_main_B.mass;

    /* Gain: '<S734>/Gain1' */
    rtb_dL_Ail = claw_main_P.Gain1_Gain_gh * 0.0;

    /* Gain: '<S734>/Gain2' */
    rtb_dR_Ail = claw_main_P.Gain2_Gain_h * 0.0;

    /* MultiPortSwitch: '<S331>/Multiport Switch1' incorporates:
     *  Constant: '<S331>/use_throt_estimate'
     */
    if ((int32_T)claw_main_P.use_throt_estimate_Value == 0) {
      memcpy((void *)&rtb_MultiportSwitch1_h2[0], (void *)&rtb_u_old[0], 10U *
             (uint32_T)((char_T *)&rtb_u_old[1U] - (char_T *)&rtb_u_old[0U]));
    } else {
      /* Assignment: '<S331>/use throt estimate from measurement instead of past throt cmd' */
      memcpy((void *)&rtb_usethrotestimatefrommeasure[0], (void *)&rtb_u_old[0],
             10U * (uint32_T)((char_T *)&rtb_u_old[1U] - (char_T *)&rtb_u_old[0U]));
      rtb_usethrotestimatefrommeasure[6] = rtb_sensors[23];
      memcpy((void *)&rtb_MultiportSwitch1_h2[0], (void *)
             &rtb_usethrotestimatefrommeasure[0], 10U * (uint32_T)((char_T *)
              &rtb_usethrotestimatefrommeasure[1U] - (char_T *)
              &rtb_usethrotestimatefrommeasure[0U]));
    }

    /* Assignment: '<S331>/zero RCS inputs' incorporates:
     *  Constant: '<S331>/Constant'
     */
    memcpy((void *)&rtb_zeroRCSinputs[0], (void *)&rtb_MultiportSwitch1_h2[0],
           10U * (uint32_T)((char_T *)&rtb_MultiportSwitch1_h2[1U] - (char_T *)
            &rtb_MultiportSwitch1_h2[0U]));
    rtb_zeroRCSinputs[9] = claw_main_P.Constant_Value_j0;

    /* MinMax: '<S532>/MinMax1' */
    max_1 = rt_MAXd_snf(rtb_zeroRCSinputs[6], min_4);

    /* MinMax: '<S532>/MinMax' */
    min_5 = rt_MINd_snf(max_1, max_4);

    /* Assignment: '<S532>/Assignment' */
    memcpy((void *)&rtb_Assignment_a[0], (void *)&rtb_zeroRCSinputs[0], 10U *
           (uint32_T)((char_T *)&rtb_zeroRCSinputs[1U] - (char_T *)
                      &rtb_zeroRCSinputs[0U]));
    rtb_Assignment_a[6] = min_5;

    /* Assignment: '<S522>/zero rate surfs' incorporates:
     *  Constant: '<S522>/Constant1'
     */
    memcpy((void *)&rtb_zeroratesurfs[0], (void *)&rtb_Assignment_a[0], 10U *
           (uint32_T)((char_T *)&rtb_Assignment_a[1U] - (char_T *)
                      &rtb_Assignment_a[0U]));
    for (yOffset = 0; yOffset < 9; yOffset++) {
      rtb_zeroratesurfs[(int32_T)tmp_b[yOffset]] =
        claw_main_P.Constant1_Value_dx;
    }

    /* Assignment: '<S535>/Assignment1' */
    memcpy((void *)&rtb_Assignment1_l[0], (void *)&rtb_zeroratesurfs[0], 10U *
           (uint32_T)((char_T *)&rtb_zeroratesurfs[1U] - (char_T *)
                      &rtb_zeroratesurfs[0U]));
    rtb_Assignment1_l[6] = min_5;

    /* Sum: '<S732>/Sum3' incorporates:
     *  Constant: '<S732>/Elevator'
     *  Product: '<S732>/Product'
     */
    rtb_Sum3_k = rtb_Assignment1_l[4] * rtb_Assignment1_l[0] +
      claw_main_P.Elevator_Value_c3;

    /* Gain: '<S732>/Gain6' */
    rtb_ELLOBC = claw_main_P.Gain6_Gain_f * rtb_Sum3_k;

    /* Gain: '<S732>/Gain5' */
    rtb_ELLIBC = claw_main_P.Gain5_Gain_g * rtb_Sum3_k;

    /* Gain: '<S732>/Gain7' */
    rtb_ELROBC = claw_main_P.Gain7_Gain_n * rtb_Sum3_k;

    /* Gain: '<S732>/Gain8' */
    rtb_ELRIBC = claw_main_P.Gain8_Gain_f * rtb_Sum3_k;

    /* Sum: '<S732>/Sum' incorporates:
     *  Constant: '<S732>/Aileron'
     */
    rtb_Sum_l = rtb_Assignment1_l[1] + claw_main_P.Aileron_Value_l;

    /* Gain: '<S732>/Gain1' */
    rtb_AILLC = claw_main_P.Gain1_Gain_dk * rtb_Sum_l;

    /* Gain: '<S732>/Gain2' */
    rtb_AILRC = claw_main_P.Gain2_Gain_k4o * rtb_Sum_l;

    /* Sum: '<S732>/Sum2' incorporates:
     *  Constant: '<S732>/Rudder'
     */
    rtb_Sum2_on = rtb_Assignment1_l[2] + claw_main_P.Rudder_Value_a;

    /* Gain: '<S732>/Gain3' */
    rtb_RUDUPC = claw_main_P.Gain3_Gain_kq * rtb_Sum2_on;

    /* Gain: '<S732>/Gain4' */
    rtb_RUDLOC = claw_main_P.Gain4_Gain_nu * rtb_Sum2_on;

    /* Lookup Block: '<S732>/Left Roll Spoiler Schedule'
     * About '<S732>/Left Roll Spoiler Schedule :'
     * Lookup Block: '<S732>/Left Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_LeftRollSpoilerSchedule),
                         claw_main_P.LeftRollSpoilerSchedule_YData_m,
                         claw_main_P.Constant_Value_fq,
                         claw_main_P.LeftRollSpoilerSchedule_XData_o, 6U);

    /* Gain: '<S732>/Gain12' */
    rtb_SPLLIBC = claw_main_P.Gain12_Gain_l * rtb_LeftRollSpoilerSchedule;

    /* Gain: '<S732>/Gain13' */
    rtb_SPLLOBC = claw_main_P.Gain13_Gain_e * rtb_LeftRollSpoilerSchedule;

    /* Lookup Block: '<S732>/Right Roll Spoiler Schedule'
     * About '<S732>/Right Roll Spoiler Schedule :'
     * Lookup Block: '<S732>/Right Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_RightRollSpoilerSchedule),
                         claw_main_P.RightRollSpoilerSchedule_YDat_e,
                         claw_main_P.Constant_Value_fq,
                         claw_main_P.RightRollSpoilerSchedule_XDat_o, 6U);

    /* Sum: '<S732>/Sum4' incorporates:
     *  Constant: '<S732>/Constant2'
     *  Constant: '<S732>/Flaps'
     */
    rtb_Sum4_d = claw_main_P.Constant2_Value_gb + claw_main_P.Flaps_Value_f;

    /* Gain: '<S732>/Gain20' incorporates:
     *  Constant: '<S732>/Gear'
     */
    rtb_GEARC = claw_main_P.Gain20_Gain_o * claw_main_P.Gear_Value_e;

    /* Sum: '<S731>/Sum' incorporates:
     *  Constant: '<S731>/Gear1'
     *  Constant: '<S732>/Constant3'
     *  Gain: '<S732>/Gain10'
     *  Gain: '<S732>/Gain11'
     *  Gain: '<S732>/Gain14'
     *  Gain: '<S732>/Gain15'
     *  Gain: '<S732>/Gain16'
     *  Gain: '<S732>/Gain17'
     *  Gain: '<S732>/Gain18'
     *  Gain: '<S732>/Gain21'
     *  Gain: '<S732>/Gain22'
     *  Gain: '<S732>/Gain9'
     *  Saturate: '<S731>/Brake'
     *  Saturate: '<S731>/Gear'
     *  SignalConversion: '<S732>/TmpHiddenBufferAtGain22Inport1'
     *  Sum: '<S731>/Sum3'
     */
    rtb_orderatts_i_idx = claw_main_P.Gain14_Gain_h *
      rtb_RightRollSpoilerSchedule;
    rtb_Switch_d_idx_0 = claw_main_P.Gain11_Gain_j *
      rtb_RightRollSpoilerSchedule;
    rtb_Switch_d_idx = claw_main_P.Gain16_Gain_h * rtb_Sum4_d;
    rtb_Sum_ow_idx = claw_main_P.Gain17_Gain_i * rtb_Sum4_d;
    rtb_Sum_ow_idx_0 = claw_main_P.Gain18_Gain_g * rtb_Sum4_d;
    rtb_Sum_ow_idx_1 = claw_main_P.Gain15_Gain_g * rtb_Sum4_d;
    rtb_Switch_d_idx_1 = rtb_Assignment1_l[3] + claw_main_P.Gear1_Value_a;
    rtb_Sum_ow_idx_2 = rt_SATURATE(rtb_GEARC, claw_main_P.Gear_LowerSat_f,
      claw_main_P.Gear_UpperSat_k);
    rtb_delta_LLh_idx = (claw_main_P.Gain22_Gain_b[0] * rtb_Assignment1_l[6] +
                         claw_main_P.Gain22_Gain_b[2] * rtb_Assignment1_l[5]) *
      claw_main_P.Gain9_Gain_d;
    rtb_delta_LLh_idx_0 = (claw_main_P.Gain22_Gain_b[1] * rtb_Assignment1_l[6] +
      claw_main_P.Gain22_Gain_b[3] * rtb_Assignment1_l[5]) *
      claw_main_P.Gain10_Gain_h;

    /* Polyval: '<S729>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref = ((claw_main_P.Throttle_2_RPMref_coefs_a[0] *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_a[1]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_a[2]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_a[3];

    /* Polyval: '<S729>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust = ((claw_main_P.RPMref_2_Thrust_coefs_p0[0] *
      rtb_Throttle_2_RPMref + claw_main_P.RPMref_2_Thrust_coefs_p0[1]) *
      rtb_Throttle_2_RPMref + claw_main_P.RPMref_2_Thrust_coefs_p0[2]) *
      rtb_Throttle_2_RPMref + claw_main_P.RPMref_2_Thrust_coefs_p0[3];

    /* Switch: '<S320>/u2>=0' incorporates:
     *  Constant: '<S320>/Constant2'
     *  Constant: '<S323>/Constant'
     *  Constant: '<S323>/Constant2'
     *  Constant: '<S323>/Constant4'
     *  Constant: '<S324>/Constant5'
     *  Constant: '<S324>/Constant6'
     *  Product: '<S323>/Product1'
     *  Product: '<S324>/Product2'
     *  Sum: '<S320>/Sum'
     *  Sum: '<S323>/Sum2'
     *  Sum: '<S324>/Sum3'
     */
    if (claw_main_P.Constant2_Value_k - rtb_Switch_k >=
        claw_main_P.u20_Threshold_f) {
      rtb_u20_p = claw_main_P.Constant6_Value - rtb_Switch_k *
        claw_main_P.Constant5_Value_h;
    } else {
      rtb_u20_p = claw_main_P.Constant2_Value_h - claw_main_P.Constant4_Value_ne
        * claw_main_P.Constant_Value_dk;
    }

    /* Gain: '<S316>/Gain' incorporates:
     *  Product: '<S316>/Product'
     */
    rtb_P = rtb_Product_b * rtb_u20_p * claw_main_P.Gain_Gain_j2;

    /* Gain: '<S659>/Gain1' */
    rtb_pratio = claw_main_P.Gain1_Gain_cm * rtb_P;

    /* Gain: '<S729>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM = claw_main_P.UnScale_Ref_RPM_Gain_a *
      rtb_Throttle_2_RPMref;

    /* Gain: '<S729>/angular momentum' */
    rtb_angularmomentum = claw_main_P.angularmomentum_Gain_g *
      rtb_UnScale_Ref_RPM;

    /* Polyval: '<S729>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow = claw_main_P.RPMref_2_FuelFlow_coefs_ai[0];
    rtb_RPMref_2_FuelFlow = rtb_RPMref_2_FuelFlow * rtb_Throttle_2_RPMref +
      claw_main_P.RPMref_2_FuelFlow_coefs_ai[1];
    rtb_RPMref_2_FuelFlow = rtb_RPMref_2_FuelFlow * rtb_Throttle_2_RPMref +
      claw_main_P.RPMref_2_FuelFlow_coefs_ai[2];

    /* Lookup Block: '<S729>/Fuel Pump Voltage'
     * About '<S729>/Fuel Pump Voltage :'
     * Lookup Block: '<S729>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage),
                         claw_main_P.FuelPumpVoltage_YData_eo,
                         rtb_RPMref_2_FuelFlow,
                         claw_main_P.FuelPumpVoltage_XData_h, 25U);

    /* Gain: '<S660>/LengON' incorporates:
     *  Polyval: '<S729>/RPMref_2_EGT'
     *  Product: '<S729>/Product2'
     */
    rtb_LengON[0] = rtb_RPMref_2_Thrust * rtb_pratio * claw_main_P.LengON_Gain_m;
    rtb_LengON[1] = claw_main_P.LengON_Gain_m * rtb_UnScale_Ref_RPM;
    rtb_LengON[2] = claw_main_P.LengON_Gain_m * rtb_angularmomentum;
    rtb_LengON[3] = claw_main_P.LengON_Gain_m * rtb_FuelPumpVoltage;
    rtb_LengON[4] = ((((claw_main_P.RPMref_2_EGT_coefs_d[0] *
                        rtb_Throttle_2_RPMref +
                        claw_main_P.RPMref_2_EGT_coefs_d[1]) *
                       rtb_Throttle_2_RPMref + claw_main_P.RPMref_2_EGT_coefs_d
                       [2]) * rtb_Throttle_2_RPMref +
                      claw_main_P.RPMref_2_EGT_coefs_d[3]) *
                     rtb_Throttle_2_RPMref + claw_main_P.RPMref_2_EGT_coefs_d[4])
      * claw_main_P.LengON_Gain_m;
    rtb_LengON[5] = claw_main_P.LengON_Gain_m * rtb_RPMref_2_FuelFlow;

    /* Polyval: '<S730>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref_o = ((claw_main_P.Throttle_2_RPMref_coefs_i[0] *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_i[1]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_i[2]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_i[3];

    /* Polyval: '<S730>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust_b = ((claw_main_P.RPMref_2_Thrust_coefs_bc[0] *
      rtb_Throttle_2_RPMref_o + claw_main_P.RPMref_2_Thrust_coefs_bc[1]) *
      rtb_Throttle_2_RPMref_o + claw_main_P.RPMref_2_Thrust_coefs_bc[2]) *
      rtb_Throttle_2_RPMref_o + claw_main_P.RPMref_2_Thrust_coefs_bc[3];

    /* Gain: '<S730>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM_o = claw_main_P.UnScale_Ref_RPM_Gain_e *
      rtb_Throttle_2_RPMref_o;

    /* Gain: '<S730>/angular momentum' */
    rtb_angularmomentum_g = claw_main_P.angularmomentum_Gain_b *
      rtb_UnScale_Ref_RPM_o;

    /* Polyval: '<S730>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow_m = claw_main_P.RPMref_2_FuelFlow_coefs_c[0];
    rtb_RPMref_2_FuelFlow_m = rtb_RPMref_2_FuelFlow_m * rtb_Throttle_2_RPMref_o
      + claw_main_P.RPMref_2_FuelFlow_coefs_c[1];
    rtb_RPMref_2_FuelFlow_m = rtb_RPMref_2_FuelFlow_m * rtb_Throttle_2_RPMref_o
      + claw_main_P.RPMref_2_FuelFlow_coefs_c[2];

    /* Lookup Block: '<S730>/Fuel Pump Voltage'
     * About '<S730>/Fuel Pump Voltage :'
     * Lookup Block: '<S730>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_g),
                         claw_main_P.FuelPumpVoltage_YData_o,
                         rtb_RPMref_2_FuelFlow_m,
                         claw_main_P.FuelPumpVoltage_XData_mv, 25U);

    /* Gain: '<S660>/RengON' incorporates:
     *  Polyval: '<S730>/RPMref_2_EGT'
     *  Product: '<S730>/Product2'
     */
    rtb_RengON[0] = rtb_RPMref_2_Thrust_b * rtb_pratio *
      claw_main_P.RengON_Gain_i0;
    rtb_RengON[1] = claw_main_P.RengON_Gain_i0 * rtb_UnScale_Ref_RPM_o;
    rtb_RengON[2] = claw_main_P.RengON_Gain_i0 * rtb_angularmomentum_g;
    rtb_RengON[3] = claw_main_P.RengON_Gain_i0 * rtb_FuelPumpVoltage_g;
    rtb_RengON[4] = ((((claw_main_P.RPMref_2_EGT_coefs_b[0] *
                        rtb_Throttle_2_RPMref_o +
                        claw_main_P.RPMref_2_EGT_coefs_b[1]) *
                       rtb_Throttle_2_RPMref_o +
                       claw_main_P.RPMref_2_EGT_coefs_b[2]) *
                      rtb_Throttle_2_RPMref_o +
                      claw_main_P.RPMref_2_EGT_coefs_b[3]) *
                     rtb_Throttle_2_RPMref_o + claw_main_P.RPMref_2_EGT_coefs_b
                     [4]) * claw_main_P.RengON_Gain_i0;
    rtb_RengON[5] = claw_main_P.RengON_Gain_i0 * rtb_RPMref_2_FuelFlow_m;
    claw_main_EngineAlignment(rtb_LengON[0], rtb_LengON[2], rtb_RengON[0],
      rtb_RengON[2], &claw_main_B.sf_EngineAlignment,
      (rtP_EngineAlignment_claw_main *) &claw_main_P.sf_EngineAlignment);

    /* FromWorkspace: '<S664>/From Workspace' */
    {
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK.TimePtr;
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK.DataPtr;
      if (t < pTimeValues[0]) {
        rtb_FromWorkspace = 0.0;
      } else if (t >= pTimeValues[1]) {
        rtb_FromWorkspace = pDataValues[1];
      } else {
        int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        rtb_FromWorkspace = pDataValues[currTimeIndex];
        claw_main_DWork.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
      }
    }

    /* Selector: '<S667>/Value(ndx,:)1' incorporates:
     *  Constant: '<S667>/Gain2'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain2_Value_b[(int32_T)rtb_FromWorkspace];
    rtb_Switch2_idx = claw_main_P.Gain2_Value_b[7 + (int32_T)rtb_FromWorkspace];
    rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain2_Value_b[14 + (int32_T)
      rtb_FromWorkspace];

    /* Sum: '<S663>/Add' incorporates:
     *  Constant: '<S660>/zero2'
     *  Constant: '<S663>/ixxb7'
     *  Constant: '<S667>/Gain1'
     *  Selector: '<S667>/Value(ndx,:)'
     *  Sum: '<S663>/Add3'
     */
    rtb_gwest = (claw_main_P.ixxb7_Value_g - claw_main_P.zero2_Value_j) +
      claw_main_P.Gain1_Value_d[(int32_T)rtb_FromWorkspace];
    claw_main_fuelcgshiftcg_pos0(claw_main_P.zero2_Value_j,
      &claw_main_B.sf_fuelcgshiftcg_pos0, (rtP_fuelcgshiftcg_pos0_claw_mai *)
      &claw_main_P.sf_fuelcgshiftcg_pos0);

    /* Switch: '<S663>/Switch1' incorporates:
     *  Constant: '<S663>/xCG1'
     *  Constant: '<S663>/xCG4'
     */
    if (rtb_Sum_ow_idx_2 >= claw_main_P.Switch1_Threshold_pz) {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG4_Value_f[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG4_Value_f[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG4_Value_f[2];
    } else {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG1_Value_mq[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG1_Value_mq[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG1_Value_mq[2];
    }

    /* Sum: '<S663>/Add2' incorporates:
     *  Product: '<S663>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest * claw_main_B.sf_fuelcgshiftcg_pos0.y[0] +
                    rtb_delta_LLh_idx) + rtb_delta_LLh_idx_0;

    /* Sum: '<S722>/Sum6' incorporates:
     *  Constant: '<S657>/ixxb6'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_c[0] - rtb_Add2_idx;

    /* Gain: '<S728>/Gain' */
    rtb_Gain1_idx = claw_main_P.Gain_Gain_by * rtb_Gain1_idx_1;

    /* Sum: '<S722>/Sum7' incorporates:
     *  Constant: '<S657>/ixxb5'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_m[0] - rtb_Add2_idx;

    /* Gain: '<S727>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_bne *
      rtb_MultiportSwitch2_idx_2;
    rtb_UnitDelay_nf_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_0 = rtb_Add2_idx;
    rtb_InterpolationnDusingPreLo_3 = rtb_Gain1_idx_1;

    /* Sum: '<S663>/Add2' incorporates:
     *  Product: '<S663>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest * claw_main_B.sf_fuelcgshiftcg_pos0.y[1] +
                    rtb_Switch2_idx) + rtb_Gain1_idx_0;

    /* Sum: '<S722>/Sum6' incorporates:
     *  Constant: '<S657>/ixxb6'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_c[1] - rtb_Add2_idx;

    /* Gain: '<S728>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_by * rtb_Gain1_idx_1;

    /* Sum: '<S722>/Sum7' incorporates:
     *  Constant: '<S657>/ixxb5'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_m[1] - rtb_Add2_idx;

    /* Gain: '<S727>/Gain' */
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_bne * rtb_MultiportSwitch2_idx_2;
    rtb_Switch2_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_1 = rtb_Add2_idx;
    rtb_Gain1_idx_0 = rtb_Gain1_idx_1;

    /* Sum: '<S663>/Add2' incorporates:
     *  Product: '<S663>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest * claw_main_B.sf_fuelcgshiftcg_pos0.y[2] +
                    rtb_InterpolationnDusingPreLo_4) +
      rtb_InterpolationnDusingPreLo_5;

    /* Sum: '<S722>/Sum6' incorporates:
     *  Constant: '<S657>/ixxb6'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_c[2] - rtb_Add2_idx;

    /* Sum: '<S722>/Sum7' incorporates:
     *  Constant: '<S657>/ixxb5'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_m[2] - rtb_Add2_idx;

    /* Sum: '<S722>/Sum1' incorporates:
     *  Gain: '<S727>/Gain'
     *  Gain: '<S728>/Gain'
     *  Product: '<S727>/Product'
     *  Product: '<S728>/Product'
     *  Reshape: '<S727>/Reshape'
     *  Reshape: '<S728>/Reshape'
     */
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_by * rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_InterpolationnDusingPreLo_3;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[8] = 0.0;
    rtb_Sum4_j_0[0] = 0.0;
    rtb_Sum4_j_0[1] = rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[2] = rtb_delta_LLh_idx_0;
    rtb_Sum4_j_0[3] = claw_main_P.Gain_Gain_bne * rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[4] = 0.0;
    rtb_Sum4_j_0[5] = rtb_UnitDelay_nf_idx;
    rtb_Sum4_j_0[6] = rtb_Switch2_idx;
    rtb_Sum4_j_0[7] = rtb_UnitDelay_nf_idx_0;
    rtb_Sum4_j_0[8] = 0.0;

    /* Product: '<S721>/Product' incorporates:
     *  Gain: '<S721>/Gain'
     *  Reshape: '<S721>/Reshape'
     */
    rtb_MultiportSwitch_cn_0[0] = 0.0;
    rtb_MultiportSwitch_cn_0[1] = rtb_Assignment2[2];
    rtb_MultiportSwitch_cn_0[2] = claw_main_P.Gain_Gain_bv * rtb_Assignment2[1];
    rtb_MultiportSwitch_cn_0[3] = claw_main_P.Gain_Gain_bv * rtb_Assignment2[2];
    rtb_MultiportSwitch_cn_0[4] = 0.0;
    rtb_MultiportSwitch_cn_0[5] = rtb_Assignment2[0];
    rtb_MultiportSwitch_cn_0[6] = rtb_Assignment2[1];
    rtb_MultiportSwitch_cn_0[7] = claw_main_P.Gain_Gain_bv * rtb_Assignment2[0];
    rtb_MultiportSwitch_cn_0[8] = 0.0;

    /* Sum: '<S648>/Sum1' incorporates:
     *  Product: '<S648>/Product'
     */
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * claw_main_B.sf_EngineAlignment.TL[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] *
        claw_main_B.sf_EngineAlignment.TL[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] *
        claw_main_B.sf_EngineAlignment.TL[2];
      rtb_Gain_e_0[i] = 0.0;
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i] * claw_main_B.sf_EngineAlignment.TR[0];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 3] *
        claw_main_B.sf_EngineAlignment.TR[1];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 6] *
        claw_main_B.sf_EngineAlignment.TR[2];
      rtb_Product_jx[i] = 0.0;
      rtb_Product_jx[i] += rtb_MultiportSwitch_cn_0[i] *
        claw_main_B.sf_EngineAlignment.H[0];
      rtb_Product_jx[i] += rtb_MultiportSwitch_cn_0[i + 3] *
        claw_main_B.sf_EngineAlignment.H[1];
      rtb_Product_jx[i] += rtb_MultiportSwitch_cn_0[i + 6] *
        claw_main_B.sf_EngineAlignment.H[2];
      rtb_dircos_b_0[i] = 0.0;
      rtb_dircos_b_0[i] += rtb_dircos_b[i] * rtb_MultiportSwitch1_idx;
      rtb_dircos_b_0[i] += rtb_dircos_b[i + 3] * rtb_MultiportSwitch1_idx_0;
      rtb_dircos_b_0[i] += rtb_dircos_b[i + 6] * rtb_MultiportSwitch1_idx_1;
    }

    rtb_delta_LLh_idx = rtb_Assignment2[3] + rtb_dircos_b_0[0];
    rtb_Gain1_idx_0 = rtb_Assignment2[4] + rtb_dircos_b_0[1];
    rtb_delta_LLh_idx_0 = rtb_Assignment2[5] + rtb_dircos_b_0[2];

    /* Gain: '<S659>/Gain2' incorporates:
     *  Trigonometry: '<S735>/Trigonometric Function2'
     */
    claw_main_B.alpha = claw_main_P.Gain2_Gain_o1 * rt_atan2_snf
      (rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

    /* PreLookup: '<S675>/AlphaLookup' */
    rtb_AlphaLookup_o1 = plook_linxp(claw_main_B.alpha,
      &claw_main_P.AlphaLookup_BreakpointsData_c[0], 31U, &rtb_AlphaLookup_o2,
      &claw_main_DWork.AlphaLookup_DWORK1);

    /* Math: '<S735>/Math Function' */
    rtb_MathFunction_fc = rt_hypot_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);

    /* Gain: '<S659>/Gain3' incorporates:
     *  Trigonometry: '<S735>/Trigonometric Function1'
     */
    claw_main_B.beta = claw_main_P.Gain3_Gain_a * rt_atan2_snf(rtb_Gain1_idx_0,
      rtb_MathFunction_fc);

    /* PreLookup: '<S675>/AlphaLookup1' */
    rtb_AlphaLookup1_o1 = plook_linxp(claw_main_B.beta,
      &claw_main_P.AlphaLookup1_BreakpointsData_c[0], 26U, &rtb_AlphaLookup1_o2,
      &claw_main_DWork.AlphaLookup1_DWORK1);

    /* Interpolation_n-D: '<S675>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S675>/Constant1'
     */
    max_1 = rtb_AlphaLookup_o2;
    frac[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2;
    frac[1] = max_1;
    bpIndex[0] = rtb_AlphaLookup_o1;
    bpIndex[1] = rtb_AlphaLookup1_o1;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_bp[scalarIndex];
      if (claw_main_P.Constant1_Value_bp[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex[2] = locIndex;
      locIndex = 864U * bpIndex[2U];
      rtb_InterpolationUsingPrelookup[scalarIndex] = intrp2d_lx(&bpIndex[0U],
        &frac[0U], &claw_main_P.InterpolationUsingPrelookup_T_c[locIndex], 32U);
    }

    /* Interpolation_n-D: '<S675>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S675>/Constant2'
     */
    max_1 = rtb_AlphaLookup_o2;
    frac_0[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2;
    frac_0[1] = max_1;
    bpIndex_0[0] = rtb_AlphaLookup_o1;
    bpIndex_0[1] = rtb_AlphaLookup1_o1;
    locIndex = claw_main_P.Constant2_Value_gw[0];
    if (claw_main_P.Constant2_Value_gw[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_0[2] = locIndex;
    locIndex = 864U * bpIndex_0[2U];
    rtb_delta_LLh_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &claw_main_P.InterpolationUsingPrelookup1__h[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_gw[1];
    if (claw_main_P.Constant2_Value_gw[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_0[2] = locIndex;
    locIndex = 864U * bpIndex_0[2U];
    rtb_delta_LLh_idx_0 = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &claw_main_P.InterpolationUsingPrelookup1__h[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_gw[2];
    if (claw_main_P.Constant2_Value_gw[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_0[2] = locIndex;
    locIndex = 864U * bpIndex_0[2U];
    rtb_Switch2_idx = intrp2d_lx(&bpIndex_0[0U], &frac_0[0U],
      &claw_main_P.InterpolationUsingPrelookup1__h[locIndex], 32U);

    /* Switch: '<S675>/Switch' incorporates:
     *  Constant: '<S658>/symmetry_on'
     *  Constant: '<S675>/Constant3'
     */
    if (claw_main_P.symmetry_on_Value_j != 0.0) {
      /* Assignment: '<S675>/Assignment to  Lateral' incorporates:
       *  Constant: '<S675>/Constant'
       */
      for (i = 0; i < 6; i++) {
        rtb_AssignmenttoLateral[i] = claw_main_P.Constant_Value_av[i];
      }

      rtb_AssignmenttoLateral[1] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLateral[3] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLateral[5] = rtb_Switch2_idx;
      for (i = 0; i < 6; i++) {
        rtb_Switch_j[i] = rtb_AssignmenttoLateral[i];
      }
    } else {
      for (i = 0; i < 6; i++) {
        rtb_Switch_j[i] = claw_main_P.Constant3_Value_l[i];
      }
    }

    /* DataTypeConversion: '<S675>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace;
    if ((rtb_FromWorkspace < 4.5035996273704960E+015) && (rtb_FromWorkspace >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace) || rtIsInf(rtb_FromWorkspace)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_d = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S680>/Switch Case' incorporates:
     *  ActionPort: '<S681>/Action Port'
     *  ActionPort: '<S682>/Action Port'
     *  SubSystem: '<S680>/Switch Case Action Subsystem'
     *  SubSystem: '<S680>/Switch Case Action Subsystem2'
     */
    switch (rtb_DataTypeConversion_d) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      claw__SwitchCaseActionSubsystem(claw_main_B.alpha, claw_main_B.beta,
        rtb_DataTypeConversion_d, claw_main_B.Merge_n,
        &claw_main_DWork.SwitchCaseActionSubsystem,
        (rtP_SwitchCaseActionSubsystem_c *)
        &claw_main_P.SwitchCaseActionSubsystem);
      break;

     default:
      /* Constant: '<S682>/Constant4' */
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_n[i] = claw_main_P.Constant4_Value_p[i];
      }
      break;
    }

    /* Sum: '<S675>/Add' */
    for (i = 0; i < 6; i++) {
      rtb_Add[i] = (rtb_InterpolationUsingPrelookup[i] + rtb_Switch_j[i]) +
        claw_main_B.Merge_n[i];
    }

    /* PreLookup: '<S705>/Prelookup' */
    rtb_Prelookup_o1 = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup_BreakpointsData_d[0], 31U, &rtb_Prelookup_o2,
      &claw_main_DWork.Prelookup_DWORK1);

    /* Switch: '<S705>/Switch' incorporates:
     *  Constant: '<S705>/Constant'
     *  Constant: '<S705>/Constant1'
     */
    if (rtb_RUDUPC >= claw_main_P.Switch_Threshold_k) {
      rtb_Switch_e = claw_main_P.Constant_Value_ls;
    } else {
      rtb_Switch_e = claw_main_P.Constant1_Value_bn;
    }

    /* PreLookup: '<S705>/Prelookup1' incorporates:
     *  Product: '<S705>/Product1'
     */
    rtb_Prelookup1_o1 = plook_linxp(claw_main_B.beta * rtb_Switch_e,
      &claw_main_P.Prelookup1_BreakpointsData_d[0], 26U, &rtb_Prelookup1_o2,
      &claw_main_DWork.Prelookup1_DWORK1);

    /* PreLookup: '<S705>/Prelookup2' incorporates:
     *  Abs: '<S705>/Abs'
     *  Gain: '<S705>/Gain'
     */
    rtb_Prelookup2_o1 = plook_linxp(claw_main_P.Gain_Gain_bv4 * fabs(rtb_RUDUPC),
      &claw_main_P.Prelookup2_BreakpointsData_e[0], 3U, &rtb_Prelookup2_o2,
      &claw_main_DWork.Prelookup2_DWORK1);

    /* Interpolation_n-D: '<S705>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S705>/Constant2'
     */
    max_1 = rtb_Prelookup_o2;
    frac_1[0] = max_1;
    max_1 = rtb_Prelookup1_o2;
    frac_1[1] = max_1;
    max_1 = rtb_Prelookup2_o2;
    frac_1[2] = max_1;
    bpIndex_1[0] = rtb_Prelookup_o1;
    bpIndex_1[1] = rtb_Prelookup1_o1;
    bpIndex_1[2] = rtb_Prelookup2_o1;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_aj[scalarIndex];
      if (claw_main_P.Constant2_Value_aj[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_1[3] = locIndex;
      locIndex = 3456U * bpIndex_1[3U];
      rtb_InterpolationUsingPrelook_m[scalarIndex] = intrp3d_lx(&bpIndex_1[0U],
        &frac_1[0U], &claw_main_P.InterpolationUsingPrelookup_T_f[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__k5[0]);
    }

    /* Assignment: '<S705>/Assignment to lateral' incorporates:
     *  Constant: '<S705>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral[i] = claw_main_P.Constant3_Value_ov[i];
    }

    rtb_Assignmenttolateral[1] = rtb_Switch_e;
    rtb_Assignmenttolateral[3] = rtb_Switch_e;
    rtb_Assignmenttolateral[5] = rtb_Switch_e;

    /* Product: '<S702>/Product' incorporates:
     *  Constant: '<S702>/gains'
     *  Product: '<S705>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_m[i] = rtb_InterpolationUsingPrelook_m[i] *
        rtb_Assignmenttolateral[i] * claw_main_P.gains_Value_ev[i];
    }

    /* PreLookup: '<S704>/Prelookup' */
    rtb_Prelookup_o1_c = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup_BreakpointsData_i[0], 31U, &rtb_Prelookup_o2_k,
      &claw_main_DWork.Prelookup_DWORK1_n);

    /* Switch: '<S704>/Switch' incorporates:
     *  Constant: '<S704>/Constant'
     *  Constant: '<S704>/Constant1'
     */
    if (rtb_RUDLOC >= claw_main_P.Switch_Threshold_gu) {
      rtb_Switch_ei = claw_main_P.Constant_Value_ar;
    } else {
      rtb_Switch_ei = claw_main_P.Constant1_Value_pn;
    }

    /* PreLookup: '<S704>/Prelookup1' incorporates:
     *  Product: '<S704>/Product1'
     */
    rtb_Prelookup1_o1_m = plook_linxp(claw_main_B.beta * rtb_Switch_ei,
      &claw_main_P.Prelookup1_BreakpointsData_fo[0], 26U, &rtb_Prelookup1_o2_m,
      &claw_main_DWork.Prelookup1_DWORK1_a);

    /* PreLookup: '<S704>/Prelookup2' incorporates:
     *  Abs: '<S704>/Abs'
     *  Gain: '<S704>/Gain'
     */
    rtb_Prelookup2_o1_f = plook_linxp(claw_main_P.Gain_Gain_dw * fabs(rtb_RUDLOC),
      &claw_main_P.Prelookup2_BreakpointsData_k[0], 3U, &rtb_Prelookup2_o2_a,
      &claw_main_DWork.Prelookup2_DWORK1_b);

    /* Interpolation_n-D: '<S704>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S704>/Constant2'
     */
    max_1 = rtb_Prelookup_o2_k;
    frac_2[0] = max_1;
    max_1 = rtb_Prelookup1_o2_m;
    frac_2[1] = max_1;
    max_1 = rtb_Prelookup2_o2_a;
    frac_2[2] = max_1;
    bpIndex_2[0] = rtb_Prelookup_o1_c;
    bpIndex_2[1] = rtb_Prelookup1_o1_m;
    bpIndex_2[2] = rtb_Prelookup2_o1_f;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_h4[scalarIndex];
      if (claw_main_P.Constant2_Value_h4[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_2[3] = locIndex;
      locIndex = 3456U * bpIndex_2[3U];
      rtb_InterpolationUsingPrelook_a[scalarIndex] = intrp3d_lx(&bpIndex_2[0U],
        &frac_2[0U], &claw_main_P.InterpolationUsingPrelookup__is[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__eh[0]);
    }

    /* Assignment: '<S704>/Assignment to lateral' incorporates:
     *  Constant: '<S704>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral_k[i] = claw_main_P.Constant3_Value_n2[i];
    }

    rtb_Assignmenttolateral_k[1] = rtb_Switch_ei;
    rtb_Assignmenttolateral_k[3] = rtb_Switch_ei;
    rtb_Assignmenttolateral_k[5] = rtb_Switch_ei;

    /* Product: '<S703>/Product' incorporates:
     *  Constant: '<S703>/gains'
     *  Product: '<S704>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_dv[i] = rtb_InterpolationUsingPrelook_a[i] *
        rtb_Assignmenttolateral_k[i] * claw_main_P.gains_Value_h[i];
    }

    /* PreLookup: '<S684>/Prelookup1' */
    rtb_Prelookup1_o1_j = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup1_BreakpointsData_hq[0], 31U, &rtb_Prelookup1_o2_h,
      &claw_main_DWork.Prelookup1_DWORK1_e);

    /* PreLookup: '<S684>/Prelookup2' incorporates:
     *  Gain: '<S684>/Gain2'
     */
    rtb_Prelookup2_o1_p = plook_linxp(claw_main_P.Gain2_Gain_dq *
      claw_main_B.beta, &claw_main_P.Prelookup2_BreakpointsData_pr[0], 26U,
      &rtb_Prelookup2_o2_m, &claw_main_DWork.Prelookup2_DWORK1_n);

    /* PreLookup: '<S684>/Prelookup3' */
    rtb_Prelookup3_o1 = plook_linxp(rtb_dL_Ail + rtb_AILLC,
      &claw_main_P.Prelookup3_BreakpointsData_m[0], 6U, &rtb_Prelookup3_o2,
      &claw_main_DWork.Prelookup3_DWORK1);

    /* Interpolation_n-D: '<S684>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S684>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_h;
    frac_3[0] = max_1;
    max_1 = rtb_Prelookup2_o2_m;
    frac_3[1] = max_1;
    max_1 = rtb_Prelookup3_o2;
    frac_3[2] = max_1;
    bpIndex_3[0] = rtb_Prelookup1_o1_j;
    bpIndex_3[1] = rtb_Prelookup2_o1_p;
    bpIndex_3[2] = rtb_Prelookup3_o1;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_ot[scalarIndex];
      if (claw_main_P.Constant3_Value_ot[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_3[3] = locIndex;
      locIndex = 6048U * bpIndex_3[3U];
      rtb_InterpolationUsingPreloo_hb[scalarIndex] = intrp3d_lx(&bpIndex_3[0U],
        &frac_3[0U], &claw_main_P.InterpolationUsingPrelookup__bj[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__d2[0]);
    }

    /* Gain: '<S684>/Negate Lateral' */
    for (i = 0; i < 6; i++) {
      rtb_NegateLateral[i] = claw_main_P.NegateLateral_Gain_i[i] *
        rtb_InterpolationUsingPreloo_hb[i];
    }

    /* PreLookup: '<S684>/Prelookup4' */
    rtb_Prelookup4_o1 = plook_linxp(claw_main_B.beta,
      &claw_main_P.Prelookup4_BreakpointsData_gy[0], 26U, &rtb_Prelookup4_o2,
      &claw_main_DWork.Prelookup4_DWORK1);

    /* PreLookup: '<S684>/Prelookup5' */
    rtb_Prelookup5_o1 = plook_linxp(rtb_dR_Ail + rtb_AILRC,
      &claw_main_P.Prelookup5_BreakpointsData_n0[0], 6U, &rtb_Prelookup5_o2,
      &claw_main_DWork.Prelookup5_DWORK1);

    /* Interpolation_n-D: '<S684>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S684>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_h;
    frac_4[0] = max_1;
    max_1 = rtb_Prelookup4_o2;
    frac_4[1] = max_1;
    max_1 = rtb_Prelookup5_o2;
    frac_4[2] = max_1;
    bpIndex_4[0] = rtb_Prelookup1_o1_j;
    bpIndex_4[1] = rtb_Prelookup4_o1;
    bpIndex_4[2] = rtb_Prelookup5_o1;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_bq[scalarIndex];
      if (claw_main_P.Constant1_Value_bq[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_4[3] = locIndex;
      locIndex = 6048U * bpIndex_4[3U];
      rtb_InterpolationUsingPrelook_n[scalarIndex] = intrp3d_lx(&bpIndex_4[0U],
        &frac_4[0U], &claw_main_P.InterpolationUsingPrelookup1_nj[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_mc[0]);
    }

    /* PreLookup: '<S710>/Prelookup1' */
    rtb_Prelookup1_o1_e = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup1_BreakpointsData_bh[0], 31U, &rtb_Prelookup1_o2_n,
      &claw_main_DWork.Prelookup1_DWORK1_eg);

    /* PreLookup: '<S710>/Prelookup2' incorporates:
     *  Gain: '<S710>/Gain2'
     */
    rtb_Prelookup2_o1_l = plook_linxp(claw_main_P.Gain2_Gain_km *
      claw_main_B.beta, &claw_main_P.Prelookup2_BreakpointsData_h0[0], 26U,
      &rtb_Prelookup2_o2_h, &claw_main_DWork.Prelookup2_DWORK1_p);

    /* PreLookup: '<S710>/Prelookup3' */
    rtb_Prelookup3_o1_i = plook_linxp(rtb_SPLLIBC,
      &claw_main_P.Prelookup3_BreakpointsData_nm[0], 2U, &rtb_Prelookup3_o2_o,
      &claw_main_DWork.Prelookup3_DWORK1_p);

    /* Interpolation_n-D: '<S710>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S710>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_n;
    frac_5[0] = max_1;
    max_1 = rtb_Prelookup2_o2_h;
    frac_5[1] = max_1;
    max_1 = rtb_Prelookup3_o2_o;
    frac_5[2] = max_1;
    bpIndex_5[0] = rtb_Prelookup1_o1_e;
    bpIndex_5[1] = rtb_Prelookup2_o1_l;
    bpIndex_5[2] = rtb_Prelookup3_o1_i;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_cu[scalarIndex];
      if (claw_main_P.Constant3_Value_cu[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_5[3] = locIndex;
      locIndex = 2592U * bpIndex_5[3U];
      rtb_InterpolationUsingPrelook_f[scalarIndex] = intrp3d_lx(&bpIndex_5[0U],
        &frac_5[0U], &claw_main_P.InterpolationUsingPrelookup__pp[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_l[0]);
    }

    /* Product: '<S707>/Product' incorporates:
     *  Constant: '<S707>/gains'
     *  Gain: '<S710>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_iy[i] = claw_main_P.NegateLateral_Gain_f[i] *
        rtb_InterpolationUsingPrelook_f[i] * claw_main_P.gains_Value_g[i];
    }

    /* PreLookup: '<S711>/Prelookup1' */
    rtb_Prelookup1_o1_g = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup1_BreakpointsData_og[0], 31U, &rtb_Prelookup1_o2_b,
      &claw_main_DWork.Prelookup1_DWORK1_g);

    /* PreLookup: '<S711>/Prelookup2' incorporates:
     *  Gain: '<S711>/Gain2'
     */
    rtb_Prelookup2_o1_e = plook_linxp(claw_main_P.Gain2_Gain_g *
      claw_main_B.beta, &claw_main_P.Prelookup2_BreakpointsData_fk[0], 26U,
      &rtb_Prelookup2_o2_aw, &claw_main_DWork.Prelookup2_DWORK1_f);

    /* PreLookup: '<S711>/Prelookup3' */
    rtb_Prelookup3_o1_e = plook_linxp(rtb_SPLLOBC,
      &claw_main_P.Prelookup3_BreakpointsData_g[0], 2U, &rtb_Prelookup3_o2_a,
      &claw_main_DWork.Prelookup3_DWORK1_j);

    /* Interpolation_n-D: '<S711>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S711>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_b;
    frac_6[0] = max_1;
    max_1 = rtb_Prelookup2_o2_aw;
    frac_6[1] = max_1;
    max_1 = rtb_Prelookup3_o2_a;
    frac_6[2] = max_1;
    bpIndex_6[0] = rtb_Prelookup1_o1_g;
    bpIndex_6[1] = rtb_Prelookup2_o1_e;
    bpIndex_6[2] = rtb_Prelookup3_o1_e;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_i4[scalarIndex];
      if (claw_main_P.Constant3_Value_i4[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_6[3] = locIndex;
      locIndex = 2592U * bpIndex_6[3U];
      rtb_InterpolationUsingPrelook_l[scalarIndex] = intrp3d_lx(&bpIndex_6[0U],
        &frac_6[0U], &claw_main_P.InterpolationUsingPrelookup_T_d[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__hg[0]);
    }

    /* Product: '<S708>/Product' incorporates:
     *  Constant: '<S708>/gains'
     *  Gain: '<S711>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_p[i] = claw_main_P.NegateLateral_Gain_fc[i] *
        rtb_InterpolationUsingPrelook_l[i] * claw_main_P.gains_Value_lm[i];
    }

    /* PreLookup: '<S710>/Prelookup4' */
    rtb_Prelookup4_o1_e = plook_linxp(claw_main_B.beta,
      &claw_main_P.Prelookup4_BreakpointsData_m2[0], 26U, &rtb_Prelookup4_o2_f,
      &claw_main_DWork.Prelookup4_DWORK1_l);

    /* PreLookup: '<S710>/Prelookup5' */
    rtb_Prelookup5_o1_a = plook_linxp(rtb_orderatts_i_idx,
      &claw_main_P.Prelookup5_BreakpointsData_k[0], 2U, &rtb_Prelookup5_o2_b,
      &claw_main_DWork.Prelookup5_DWORK1_l);

    /* Interpolation_n-D: '<S710>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S710>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_n;
    frac_7[0] = max_1;
    max_1 = rtb_Prelookup4_o2_f;
    frac_7[1] = max_1;
    max_1 = rtb_Prelookup5_o2_b;
    frac_7[2] = max_1;
    bpIndex_7[0] = rtb_Prelookup1_o1_e;
    bpIndex_7[1] = rtb_Prelookup4_o1_e;
    bpIndex_7[2] = rtb_Prelookup5_o1_a;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_od[scalarIndex];
      if (claw_main_P.Constant1_Value_od[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_7[3] = locIndex;
      locIndex = 2592U * bpIndex_7[3U];
      rtb_InterpolationUsingPrelook_e[scalarIndex] = intrp3d_lx(&bpIndex_7[0U],
        &frac_7[0U], &claw_main_P.InterpolationUsingPrelookup1__k[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_ej[0]);
    }

    /* Product: '<S706>/Product' incorporates:
     *  Constant: '<S706>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_io[i] = rtb_InterpolationUsingPrelook_e[i] *
        claw_main_P.gains_Value_hn[i];
    }

    /* PreLookup: '<S711>/Prelookup4' */
    rtb_Prelookup4_o1_d = plook_linxp(claw_main_B.beta,
      &claw_main_P.Prelookup4_BreakpointsData_df[0], 26U, &rtb_Prelookup4_o2_h,
      &claw_main_DWork.Prelookup4_DWORK1_f);

    /* PreLookup: '<S711>/Prelookup5' */
    rtb_Prelookup5_o1_h = plook_linxp(rtb_Switch_d_idx_0,
      &claw_main_P.Prelookup5_BreakpointsData_h[0], 2U, &rtb_Prelookup5_o2_m,
      &claw_main_DWork.Prelookup5_DWORK1_m);

    /* Interpolation_n-D: '<S711>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S711>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_b;
    frac_8[0] = max_1;
    max_1 = rtb_Prelookup4_o2_h;
    frac_8[1] = max_1;
    max_1 = rtb_Prelookup5_o2_m;
    frac_8[2] = max_1;
    bpIndex_8[0] = rtb_Prelookup1_o1_g;
    bpIndex_8[1] = rtb_Prelookup4_o1_d;
    bpIndex_8[2] = rtb_Prelookup5_o1_h;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_ju[scalarIndex];
      if (claw_main_P.Constant1_Value_ju[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_8[3] = locIndex;
      locIndex = 2592U * bpIndex_8[3U];
      rtb_InterpolationUsingPreloo_ah[scalarIndex] = intrp3d_lx(&bpIndex_8[0U],
        &frac_8[0U], &claw_main_P.InterpolationUsingPrelookup1__g[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_bn[0]);
    }

    /* Product: '<S709>/Product' incorporates:
     *  Constant: '<S709>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_ho[i] = rtb_InterpolationUsingPreloo_ah[i] *
        claw_main_P.gains_Value_b[i];
    }

    /* PreLookup: '<S685>/Prelookup1' */
    rtb_Prelookup1_o1_l = plook_linxp(claw_main_B.alpha,
      &claw_main_P.Prelookup1_BreakpointsData_c[0], 31U, &rtb_Prelookup1_o2_c,
      &claw_main_DWork.Prelookup1_DWORK1_j);

    /* PreLookup: '<S685>/Prelookup2' */
    rtb_Prelookup2_o1_n = plook_linxp(claw_main_B.beta,
      &claw_main_P.Prelookup2_BreakpointsData_b4[0], 26U, &rtb_Prelookup2_o2_hn,
      &claw_main_DWork.Prelookup2_DWORK1_i);

    /* PreLookup: '<S685>/Prelookup3' */
    rtb_Prelookup3_o1_k = plook_linxp(rtb_Switch_d_idx_1,
      &claw_main_P.Prelookup3_BreakpointsData_e[0], 3U, &rtb_Prelookup3_o2_oe,
      &claw_main_DWork.Prelookup3_DWORK1_k);

    /* PreLookup: '<S696>/Prelookup4' incorporates:
     *  Constant: '<S685>/Constant1'
     */
    rtb_Prelookup4_o1_j = plook_linxp(claw_main_P.Constant1_Value_cr,
      &claw_main_P.Prelookup4_BreakpointsData_e5[0], 5U, &rtb_Prelookup4_o2_ha,
      &claw_main_DWork.Prelookup4_DWORK1_g);

    /* Interpolation_n-D: '<S696>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S696>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_c;
    frac_9[0] = max_1;
    max_1 = rtb_Prelookup2_o2_hn;
    frac_9[1] = max_1;
    max_1 = rtb_Prelookup3_o2_oe;
    frac_9[2] = max_1;
    max_1 = rtb_Prelookup4_o2_ha;
    frac_9[3] = max_1;
    bpIndex_9[0] = rtb_Prelookup1_o1_l;
    bpIndex_9[1] = rtb_Prelookup2_o1_n;
    bpIndex_9[2] = rtb_Prelookup3_o1_k;
    bpIndex_9[3] = rtb_Prelookup4_o1_j;
    locIndex = claw_main_P.Constant2_Value_hu[0];
    if (claw_main_P.Constant2_Value_hu[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_9[4] = locIndex;
    locIndex = 20736U * bpIndex_9[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_9[0U], &frac_9[0U],
      &claw_main_P.InterpolationUsingPrelookup__cd[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__p1[0]);
    locIndex = claw_main_P.Constant2_Value_hu[1];
    if (claw_main_P.Constant2_Value_hu[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_9[4] = locIndex;
    locIndex = 20736U * bpIndex_9[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_9[0U], &frac_9[0U],
      &claw_main_P.InterpolationUsingPrelookup__cd[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__p1[0]);
    locIndex = claw_main_P.Constant2_Value_hu[2];
    if (claw_main_P.Constant2_Value_hu[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_9[4] = locIndex;
    locIndex = 20736U * bpIndex_9[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_9[0U], &frac_9[0U],
      &claw_main_P.InterpolationUsingPrelookup__cd[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__p1[0]);

    /* Assignment: '<S696>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S696>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal[i] = claw_main_P.Constant_Value_lu[i];
    }

    rtb_AssignmenttoLongitudinal[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal[4] = rtb_Switch2_idx;

    /* PreLookup: '<S695>/Prelookup4' */
    rtb_Prelookup4_o1_ev = plook_linxp(rtb_ELLOBC,
      &claw_main_P.Prelookup4_BreakpointsData_k[0], 5U, &rtb_Prelookup4_o2_c,
      &claw_main_DWork.Prelookup4_DWORK1_k);

    /* Interpolation_n-D: '<S695>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S695>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_c;
    frac_a[0] = max_1;
    max_1 = rtb_Prelookup2_o2_hn;
    frac_a[1] = max_1;
    max_1 = rtb_Prelookup3_o2_oe;
    frac_a[2] = max_1;
    max_1 = rtb_Prelookup4_o2_c;
    frac_a[3] = max_1;
    bpIndex_a[0] = rtb_Prelookup1_o1_l;
    bpIndex_a[1] = rtb_Prelookup2_o1_n;
    bpIndex_a[2] = rtb_Prelookup3_o1_k;
    bpIndex_a[3] = rtb_Prelookup4_o1_ev;
    locIndex = claw_main_P.Constant2_Value_gc[0];
    if (claw_main_P.Constant2_Value_gc[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_a[4] = locIndex;
    locIndex = 20736U * bpIndex_a[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_a[0U], &frac_a[0U],
      &claw_main_P.InterpolationUsingPrelookup__pu[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ch[0]);
    locIndex = claw_main_P.Constant2_Value_gc[1];
    if (claw_main_P.Constant2_Value_gc[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_a[4] = locIndex;
    locIndex = 20736U * bpIndex_a[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_a[0U], &frac_a[0U],
      &claw_main_P.InterpolationUsingPrelookup__pu[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ch[0]);
    locIndex = claw_main_P.Constant2_Value_gc[2];
    if (claw_main_P.Constant2_Value_gc[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_a[4] = locIndex;
    locIndex = 20736U * bpIndex_a[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_a[0U], &frac_a[0U],
      &claw_main_P.InterpolationUsingPrelookup__pu[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ch[0]);

    /* Assignment: '<S695>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S695>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_a[i] = claw_main_P.Constant_Value_nh[i];
    }

    rtb_AssignmenttoLongitudinal_a[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_a[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_a[4] = rtb_Switch2_idx;

    /* Gain: '<S692>/Gain' incorporates:
     *  Gain: '<S685>/Gain'
     *  Sum: '<S685>/Add'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_a[i] -
                  rtb_AssignmenttoLongitudinal[i]) * claw_main_P.Gain_Gain_nl;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_i5[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_i5[i] += claw_main_P.Gain_Gain_oi[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S697>/Prelookup4' */
    rtb_Prelookup4_o1_d4 = plook_linxp(rtb_ELLIBC,
      &claw_main_P.Prelookup4_BreakpointsData_eu[0], 5U, &rtb_Prelookup4_o2_k,
      &claw_main_DWork.Prelookup4_DWORK1_m);

    /* Interpolation_n-D: '<S697>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S697>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_c;
    frac_b[0] = max_1;
    max_1 = rtb_Prelookup2_o2_hn;
    frac_b[1] = max_1;
    max_1 = rtb_Prelookup3_o2_oe;
    frac_b[2] = max_1;
    max_1 = rtb_Prelookup4_o2_k;
    frac_b[3] = max_1;
    bpIndex_b[0] = rtb_Prelookup1_o1_l;
    bpIndex_b[1] = rtb_Prelookup2_o1_n;
    bpIndex_b[2] = rtb_Prelookup3_o1_k;
    bpIndex_b[3] = rtb_Prelookup4_o1_d4;
    locIndex = claw_main_P.Constant2_Value_kb[0];
    if (claw_main_P.Constant2_Value_kb[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_b[4] = locIndex;
    locIndex = 20736U * bpIndex_b[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_b[0U], &frac_b[0U],
      &claw_main_P.InterpolationUsingPrelookup_T_e[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__pf[0]);
    locIndex = claw_main_P.Constant2_Value_kb[1];
    if (claw_main_P.Constant2_Value_kb[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_b[4] = locIndex;
    locIndex = 20736U * bpIndex_b[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_b[0U], &frac_b[0U],
      &claw_main_P.InterpolationUsingPrelookup_T_e[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__pf[0]);
    locIndex = claw_main_P.Constant2_Value_kb[2];
    if (claw_main_P.Constant2_Value_kb[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_b[4] = locIndex;
    locIndex = 20736U * bpIndex_b[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_b[0U], &frac_b[0U],
      &claw_main_P.InterpolationUsingPrelookup_T_e[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__pf[0]);

    /* Assignment: '<S697>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S697>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_e[i] = claw_main_P.Constant_Value_hj[i];
    }

    rtb_AssignmenttoLongitudinal_e[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_e[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_e[4] = rtb_Switch2_idx;

    /* Gain: '<S691>/Gain' incorporates:
     *  Gain: '<S685>/Gain1'
     *  Sum: '<S685>/Add1'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_e[i] -
                  rtb_AssignmenttoLongitudinal[i]) * claw_main_P.Gain1_Gain_dr;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_cz[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_cz[i] += claw_main_P.Gain_Gain_no[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S699>/Prelookup4' */
    rtb_Prelookup4_o1_h = plook_linxp(rtb_ELRIBC,
      &claw_main_P.Prelookup4_BreakpointsData_ow[0], 5U, &rtb_Prelookup4_o2_hx,
      &claw_main_DWork.Prelookup4_DWORK1_n);

    /* Interpolation_n-D: '<S699>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S699>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_c;
    frac_c[0] = max_1;
    max_1 = rtb_Prelookup2_o2_hn;
    frac_c[1] = max_1;
    max_1 = rtb_Prelookup3_o2_oe;
    frac_c[2] = max_1;
    max_1 = rtb_Prelookup4_o2_hx;
    frac_c[3] = max_1;
    bpIndex_c[0] = rtb_Prelookup1_o1_l;
    bpIndex_c[1] = rtb_Prelookup2_o1_n;
    bpIndex_c[2] = rtb_Prelookup3_o1_k;
    bpIndex_c[3] = rtb_Prelookup4_o1_h;
    locIndex = claw_main_P.Constant2_Value_my[0];
    if (claw_main_P.Constant2_Value_my[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_c[4] = locIndex;
    locIndex = 20736U * bpIndex_c[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_c[0U], &frac_c[0U],
      &claw_main_P.InterpolationUsingPrelookup__c1[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__je[0]);
    locIndex = claw_main_P.Constant2_Value_my[1];
    if (claw_main_P.Constant2_Value_my[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_c[4] = locIndex;
    locIndex = 20736U * bpIndex_c[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_c[0U], &frac_c[0U],
      &claw_main_P.InterpolationUsingPrelookup__c1[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__je[0]);
    locIndex = claw_main_P.Constant2_Value_my[2];
    if (claw_main_P.Constant2_Value_my[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_c[4] = locIndex;
    locIndex = 20736U * bpIndex_c[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_c[0U], &frac_c[0U],
      &claw_main_P.InterpolationUsingPrelookup__c1[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__je[0]);

    /* Assignment: '<S699>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S699>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_e0[i] = claw_main_P.Constant_Value_la[i];
    }

    rtb_AssignmenttoLongitudinal_e0[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_e0[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_e0[4] = rtb_Switch2_idx;

    /* Gain: '<S693>/Gain' incorporates:
     *  Gain: '<S685>/Gain2'
     *  Sum: '<S685>/Add2'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_e0[i] -
                  rtb_AssignmenttoLongitudinal[i]) * claw_main_P.Gain2_Gain_kz;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_jm[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_jm[i] += claw_main_P.Gain_Gain_md[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S698>/Prelookup4' */
    rtb_Prelookup4_o1_h0 = plook_linxp(rtb_ELROBC,
      &claw_main_P.Prelookup4_BreakpointsData_mn[0], 5U, &rtb_Prelookup4_o2_m,
      &claw_main_DWork.Prelookup4_DWORK1_o);

    /* Interpolation_n-D: '<S698>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S698>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_c;
    frac_d[0] = max_1;
    max_1 = rtb_Prelookup2_o2_hn;
    frac_d[1] = max_1;
    max_1 = rtb_Prelookup3_o2_oe;
    frac_d[2] = max_1;
    max_1 = rtb_Prelookup4_o2_m;
    frac_d[3] = max_1;
    bpIndex_d[0] = rtb_Prelookup1_o1_l;
    bpIndex_d[1] = rtb_Prelookup2_o1_n;
    bpIndex_d[2] = rtb_Prelookup3_o1_k;
    bpIndex_d[3] = rtb_Prelookup4_o1_h0;
    locIndex = claw_main_P.Constant2_Value_bu[0];
    if (claw_main_P.Constant2_Value_bu[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_d[4] = locIndex;
    locIndex = 20736U * bpIndex_d[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_d[0U], &frac_d[0U],
      &claw_main_P.InterpolationUsingPrelookup__pc[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__c5[0]);
    locIndex = claw_main_P.Constant2_Value_bu[1];
    if (claw_main_P.Constant2_Value_bu[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_d[4] = locIndex;
    locIndex = 20736U * bpIndex_d[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_d[0U], &frac_d[0U],
      &claw_main_P.InterpolationUsingPrelookup__pc[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__c5[0]);
    locIndex = claw_main_P.Constant2_Value_bu[2];
    if (claw_main_P.Constant2_Value_bu[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_d[4] = locIndex;
    locIndex = 20736U * bpIndex_d[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_d[0U], &frac_d[0U],
      &claw_main_P.InterpolationUsingPrelookup__pc[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__c5[0]);

    /* Assignment: '<S698>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S698>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_m[i] = claw_main_P.Constant_Value_d3[i];
    }

    rtb_AssignmenttoLongitudinal_m[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_m[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_m[4] = rtb_Switch2_idx;

    /* Gain: '<S694>/Gain' incorporates:
     *  Gain: '<S685>/Gain3'
     *  Sum: '<S685>/Add3'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_m[i] -
                  rtb_AssignmenttoLongitudinal[i]) * claw_main_P.Gain3_Gain_f;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_d[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_d[i] += claw_main_P.Gain_Gain_dn[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }

      /* Gain: '<S686>/Gain' */
      rtb_Gain_id[i] = claw_main_P.Gain_Gain_ftk[i] * rtb_Sum_ow_idx;

      /* Gain: '<S686>/Gain1' */
      rtb_Gain1_d[i] = claw_main_P.Gain1_Gain_ab[i] * rtb_Switch_d_idx;

      /* Gain: '<S686>/Gain2' */
      rtb_Gain2_e[i] = claw_main_P.Gain2_Gain_jt[i] * rtb_Sum_ow_idx_0;

      /* Gain: '<S686>/Gain3' */
      rtb_Gain3_c[i] = claw_main_P.Gain3_Gain_pt[i] * rtb_Sum_ow_idx_1;
    }

    /* S-Function (sfun_idxsearch): '<S687>/PreLookup Index Search1' */
    scalarPrevIndex = claw_main_DWork.PreLookupIndexSearch1_MODE_l;
    scalarIndex_0 = plook_s32dd_binxp(claw_main_B.alpha,
      &claw_main_P.PreLookupIndexSearch1_bpData_d[0], 31U, &scalarFraction_1,
      &scalarPrevIndex);
    rtb_delta_LLh_idx = scalarFraction_1;

    /* S-Function (sfun_kflookupnd): '<S687>/TableLookup' incorporates:
     *  Constant: '<S687>/Constant2'
     *  DataTypeConversion: '<S687>/Data Type Conversion2'
     *  RelationalOperator: '<S700>/Compare'
     */
    if (scalarIndex_0 > 30) {
      max_1 = 30.0;
    } else if (scalarIndex_0 >= 0) {
      max_1 = (real_T)scalarIndex_0;
    } else {
      max_1 = 0.0;
    }

    i = (int32_T)max_1;
    yOffset_0 = (rtb_Sum_ow_idx_2 != 0.0);
    if (claw_main_P.Constant2_Value_bm[0] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = claw_main_P.Constant2_Value_bm[0];
    }

    rtb_delta_LLh_idx_0 = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_k[(locIndex << 6U) + (yOffset_0 << 5)]);
    if (claw_main_P.Constant2_Value_bm[1] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = claw_main_P.Constant2_Value_bm[1];
    }

    rtb_Switch2_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_k[(locIndex << 6U) + (yOffset_0 << 5)]);
    if (claw_main_P.Constant2_Value_bm[2] > 2U) {
      locIndex = 2U;
    } else {
      locIndex = claw_main_P.Constant2_Value_bm[2];
    }

    rtb_delta_LLh_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_k[(locIndex << 6U) + (yOffset_0 << 5)]);

    /* Assignment: '<S687>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S687>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_h[i] = claw_main_P.Constant_Value_cg[i];
    }

    rtb_AssignmenttoLongitudinal_h[0] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_h[2] = rtb_Switch2_idx;
    rtb_AssignmenttoLongitudinal_h[4] = rtb_delta_LLh_idx;
    claw_main_ImplementDamageModels(rtb_Product_m, rtb_Product_dv,
      rtb_NegateLateral, rtb_InterpolationUsingPrelook_n, rtb_Product_iy,
      rtb_Product_p, rtb_Product_io, rtb_Product_ho,
      rtb_AssignmenttoLongitudinal, rtb_Gain_i5, rtb_Gain_cz, rtb_Gain_jm,
      rtb_Gain_d, rtb_Gain_id, rtb_Gain1_d, rtb_Gain2_e, rtb_Gain3_c,
      rtb_AssignmenttoLongitudinal_h, rtb_FromWorkspace,
      &claw_main_B.sf_ImplementDamageModels);

    /* Reshape: '<S688>/Reshape' */
    for (i = 0; i < 6; i++) {
      rtb_Reshape_c[i] = claw_main_B.sf_ImplementDamageModels.dC6[i];
    }

    /* Math: '<S735>/Math Function1' */
    rtb_MathFunction1_k = rt_hypot_snf(rtb_MathFunction_fc, rtb_Gain1_idx_0);

    /* MinMax: '<S662>/MinMax' incorporates:
     *  Constant: '<S662>/Constant'
     */
    max_5 = rt_MAXd_snf(claw_main_P.Constant_Value_n4, rtb_MathFunction1_k);

    /* Gain: '<S659>/Gain5' */
    rtb_tas = claw_main_P.Gain5_Gain_k * max_5;

    /* DataTypeConversion: '<S678>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace;
    if ((rtb_FromWorkspace < 4.5035996273704960E+015) && (rtb_FromWorkspace >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace) || rtIsInf(rtb_FromWorkspace)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_c = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S678>/Switch Case' incorporates:
     *  ActionPort: '<S712>/Action Port'
     *  ActionPort: '<S713>/Action Port'
     *  SubSystem: '<S678>/Forced Oscillation with Damage Increments'
     *  SubSystem: '<S678>/Rotary Blended  UnDamaged Case'
     */
    switch (rtb_DataTypeConversion_c) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      ForcedOscillationwithDamageIn_o(claw_main_B.alpha,
        rtb_DataTypeConversion_c, rtb_tas, rtb_Assignment2,
        claw_main_P.B_Value_m, claw_main_P.Cbar_Value_h, claw_main_B.Merge_bf,
        &claw_main_B.ForcedOscillationwithDamageIn_h,
        &claw_main_DWork.ForcedOscillationwithDamageIn_h,
        (rtP_ForcedOscillationwithDama_l *)
        &claw_main_P.ForcedOscillationwithDamageIn_h);
      break;

     default:
      cl_RotaryBlendedUnDamagedCase_k(claw_main_B.alpha, rtb_tas,
        claw_main_B.beta, rtb_Assignment2, claw_main_P.B_Value_m,
        claw_main_P.Cbar_Value_h, claw_main_B.Merge_bf,
        &claw_main_B.RotaryBlendedUnDamagedCase,
        &claw_main_DWork.RotaryBlendedUnDamagedCase,
        (rtP_RotaryBlendedUnDamagedCas_m *)
        &claw_main_P.RotaryBlendedUnDamagedCase);
      break;
    }

    /* Fcn: '<S662>/wind_qbar' */
    if ((max_5 < 0.0) && (2.0 > floor(2.0))) {
      max_1 = -rt_pow_snf(-max_5, 2.0);
    } else {
      max_1 = rt_pow_snf(max_5, 2.0);
    }

    /* Product: '<S662>/Product1' */
    rtb_qbar_p = 0.5 * max_1 * rtb_Product_b;

    /* Gain: '<S676>/Gain2' incorporates:
     *  Product: '<S676>/Product'
     *  Sum: '<S658>/Sum8'
     */
    for (i = 0; i < 6; i++) {
      rtb_Gain2_n[i] = ((rtb_Add[i] + rtb_Reshape_c[i]) + claw_main_B.Merge_bf[i])
        * rtb_qbar_p * claw_main_P.Gain2_Gain_cm;
    }

    /* Sum: '<S676>/Sum' incorporates:
     *  Constant: '<S657>/xCG1'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_ma[0] - rtb_Add2_idx_0;

    /* Gain: '<S683>/Gain' */
    rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_of * rtb_Switch2_idx;
    rtb_Gain1_idx_1 = rtb_Switch2_idx;

    /* Sum: '<S676>/Sum' incorporates:
     *  Constant: '<S657>/xCG1'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_ma[1] - rtb_Add2_idx_1;

    /* Gain: '<S683>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_of * rtb_Switch2_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch2_idx;

    /* Sum: '<S676>/Sum' incorporates:
     *  Constant: '<S657>/xCG1'
     *  Reshape: '<S663>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_ma[2] - rtb_Add2_idx;

    /* Sum: '<S651>/Sum' incorporates:
     *  Gain: '<S676>/Reference Lengths'
     *  Gain: '<S683>/Gain'
     *  Product: '<S683>/Product'
     *  Reshape: '<S683>/Reshape'
     *  Reshape: '<S683>/Reshape1'
     *  Sum: '<S660>/Sum'
     *  Sum: '<S676>/Sum1'
     */
    min_6[0] = claw_main_B.sf_EngineAlignment.T[0];
    min_6[1] = claw_main_B.sf_EngineAlignment.T[1];
    min_6[2] = claw_main_B.sf_EngineAlignment.T[2];
    min_6[3] = (rtb_dircos_0[0] + rtb_Gain_e_0[0]) + rtb_Product_jx[0];
    min_6[4] = (rtb_dircos_0[1] + rtb_Gain_e_0[1]) + rtb_Product_jx[1];
    min_6[5] = (rtb_dircos_0[2] + rtb_Gain_e_0[2]) + rtb_Product_jx[2];
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_of * rtb_Switch2_idx;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[6] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Gain2_n[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Gain2_n[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Gain2_n[2];
    }

    rtb_Gain2_n_0[0] = rtb_Gain2_n[0];
    rtb_Gain2_n_0[1] = rtb_Gain2_n[1];
    rtb_Gain2_n_0[2] = rtb_Gain2_n[2];
    rtb_Gain2_n_0[3] = claw_main_P.ReferenceLengths_Gain_b[0] * rtb_Gain2_n[3] +
      rtb_dircos_0[0];
    rtb_Gain2_n_0[4] = claw_main_P.ReferenceLengths_Gain_b[1] * rtb_Gain2_n[4] +
      rtb_dircos_0[1];
    rtb_Gain2_n_0[5] = claw_main_P.ReferenceLengths_Gain_b[2] * rtb_Gain2_n[5] +
      rtb_dircos_0[2];
    for (i = 0; i < 6; i++) {
      rtb_Sum_mp[i] = min_6[i] + rtb_Gain2_n_0[i];
    }

    /* Gain: '<S534>/Gain' incorporates:
     *  Math: '<S534>/Math Function'
     *  Product: '<S534>/Product'
     *  Product: '<S650>/Force -> Acceleration'
     *  Product: '<S654>/Product'
     *  Product: '<S654>/Product1'
     *  Reshape: '<S534>/Reshape'
     *  Reshape: '<S648>/Reshape1'
     *  Sum: '<S648>/Sum'
     *  Sum: '<S650>/Sum'
     *  Sum: '<S654>/Sum'
     */
    rtb_Gain1_oy_0[0] = rtb_Gain1_oy[1];
    rtb_Gain1_oy_0[1] = rtb_Gain_g_idx_2;
    rtb_Gain1_oy_0[2] = rtb_Gain_g_idx_0;
    rtb_Gain1_oy_0[3] = rtb_Gain_g_idx;
    rtb_Gain1_oy_0[4] = rtb_Gain1_oy[2];
    rtb_Gain1_oy_0[5] = rtb_Gain_g_idx_4;
    rtb_Gain1_oy_0[6] = rtb_Gain_g_idx_3;
    rtb_Gain1_oy_0[7] = rtb_Gain_g_idx_1;
    rtb_Gain1_oy_0[8] = rtb_Gain1_oy[3];
    rtb_delta_LLh_idx = 1.0 / claw_main_B.mass;
    rtb_Switch2_idx = (rtb_Product1_b_idx + rtb_Sum_mp[0]) * rtb_delta_LLh_idx -
      (rtb_Assignment2[1] * rtb_Assignment2[5] - rtb_Assignment2[2] *
       rtb_Assignment2[4]);
    rtb_delta_LLh_idx_0 = (rtb_Product1_b_idx_0 + rtb_Sum_mp[1]) *
      rtb_delta_LLh_idx - (rtb_Assignment2[2] * rtb_Assignment2[3] -
      rtb_Assignment2[0] * rtb_Assignment2[5]);
    rtb_delta_LLh_idx = (rtb_Product1_b_idx_1 + rtb_Sum_mp[2]) *
      rtb_delta_LLh_idx - (rtb_Assignment2[0] * rtb_Assignment2[4] -
      rtb_Assignment2[1] * rtb_Assignment2[3]);
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i] * rtb_Switch2_idx;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 1] * rtb_delta_LLh_idx_0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 2] * rtb_delta_LLh_idx;
    }

    rtb_Gain_kp_idx_0 = claw_main_P.Gain_Gain_c1[0] * rtb_dircos_0[0];
    rtb_Gain_kp_idx_1 = claw_main_P.Gain_Gain_c1[1] * rtb_dircos_0[1];
    rtb_Gain_kp_idx = claw_main_P.Gain_Gain_c1[2] * rtb_dircos_0[2];

    /* Selector: '<S787>/Selector1' incorporates:
     *  Constant: '<S787>/Constant'
     */
    rtb_Selector1_idx = claw_main_P.Constant_Value_gs[(int32_T)rtb_att_type - 1];
    rtb_Selector1_idx_0 = claw_main_P.Constant_Value_gs[(int32_T)rtb_att_type +
      4];

    /* Selector: '<S787>/Selector2' incorporates:
     *  Constant: '<S787>/Constant7'
     */
    rtb_Selector2_idx = claw_main_P.Constant7_Value[(int32_T)rtb_att_type - 1];
    rtb_Selector2_idx_0 = claw_main_P.Constant7_Value[(int32_T)rtb_att_type + 4];

    /* Gain: '<S792>/Gain' incorporates:
     *  Constant: '<S787>/Constant8'
     */
    rtb_Gain_jqu = claw_main_P.Gain_Gain_l4 * claw_main_P.Constant8_Value;

    /* Product: '<S792>/Divide1' incorporates:
     *  Constant: '<S787>/Constant2'
     *  Selector: '<S792>/q_limit'
     */
    rtb_Divide1_l = rtb_Gain_jqu / claw_main_P.Constant2_Value_bk[1];

    /* Assignment: '<S792>/Assignment' incorporates:
     *  Constant: '<S787>/Constant2'
     */
    rtb_Assignment_pi_idx = claw_main_P.Constant2_Value_bk[0];
    rtb_Assignment_l_idx = claw_main_P.Constant1_Value_cn[0];

    /* Gain: '<S791>/Gain' incorporates:
     *  Constant: '<S787>/Constant3'
     */
    rtb_Gain_kg = claw_main_P.Gain_Gain_oa * claw_main_P.Constant3_Value_gn;

    /* Product: '<S791>/Divide1' incorporates:
     *  Constant: '<S787>/Constant1'
     *  Selector: '<S791>/q_limit'
     */
    rtb_Divide1_e = rtb_Gain_kg / claw_main_P.Constant1_Value_cn[1];

    /* Gain: '<S316>/Gain1' */
    rtb_Gain1_kw = claw_main_P.Gain1_Gain_nx * rtb_u20_p;

    /* Math: '<S316>/Math Function' */
    if (rtb_Gain1_kw < 0.0) {
      rtb_sos = -sqrt(-rtb_Gain1_kw);
    } else {
      rtb_sos = sqrt(rtb_Gain1_kw);
    }

    /* Math: '<S325>/Math Function1' */
    rtb_Rslant = rt_hypot_snf(rtb_Rground, rtb_Sum_h_idx);

    /* S-Function (sfun_idxsearch): '<S318>/PreLookup Index Search' */
    scalarIndex = plook_binc(claw_main_B.mass,
      &claw_main_P.PreLookupIndexSearch_bpData_b[0], 1U, &scalarFraction_2);
    rtb_delta_LLh_idx = scalarFraction_2;

    /* Sum: '<S318>/Sum1' incorporates:
     *  Constant: '<S318>/Constant'
     */
    rtb_Sum1_g = claw_main_P.Constant_Value_fy - rtb_delta_LLh_idx;

    /* Sum: '<S318>/Sum2' incorporates:
     *  Gain: '<S318>/Gain1'
     *  Gain: '<S318>/Gain2'
     */
    rtb_r_cg[0] = claw_main_P.Gain1_Gain_o4[0] * rtb_delta_LLh_idx +
      claw_main_P.Gain2_Gain_g0[0] * rtb_Sum1_g;
    rtb_r_cg[1] = claw_main_P.Gain1_Gain_o4[1] * rtb_delta_LLh_idx +
      claw_main_P.Gain2_Gain_g0[1] * rtb_Sum1_g;
    rtb_r_cg[2] = claw_main_P.Gain1_Gain_o4[2] * rtb_delta_LLh_idx +
      claw_main_P.Gain2_Gain_g0[2] * rtb_Sum1_g;

    /* Sum: '<S318>/Sum3' incorporates:
     *  Gain: '<S318>/Gain3'
     *  Gain: '<S318>/Gain4'
     */
    for (i = 0; i < 9; i++) {
      rtb_inertia[i] = claw_main_P.Gain3_Gain_n[i] * rtb_delta_LLh_idx +
        claw_main_P.Gain4_Gain_a[i] * rtb_Sum1_g;
    }

    {
      static const int_T dims[3] = { 3, 3, 3 };

      rt_MatDivRR_Dbl(rtb_inertia_inv, rtb_inertia,
                      &claw_main_DWork.Product_DWORK4[0], (real_T*)
                      &Product_DWORK1[0],
                      &Product_DWORK2[0], (real_T*)&Product_DWORK3[0],
                      &dims[0]);
    }

    /* Gain: '<S318>/Gain5' */
    rtb_throt_to_ff = claw_main_P.Gain5_Gain_l * rtb_control_input[113];

    /* Gain: '<S318>/Gain6' */
    rtb_Gain6 = claw_main_P.Gain6_Gain_c * rtb_P;

    /* Sum: '<S318>/Sum6' incorporates:
     *  Constant: '<S318>/Constant2'
     *  Product: '<S318>/Product1'
     *  Product: '<S318>/Product2'
     *  Sum: '<S318>/Sum5'
     */
    rtb_Isp = (claw_main_P.Constant2_Value_iw - rtb_Gain6) * rtb_control_input
      [112] + rtb_control_input[111] * rtb_Gain6;

    /* Outputs for iterator SubSystem: '<S522>/B matrix comp' incorporates:
     *  Constant: '<S533>/Constant2'
     *  WhileIterator: '<S533>/While Iterator'
     */
    memcpy((void *)&rtb_Assignment2_b[0], (void *)&rtb_Assignment2[0], 13U *
           (uint32_T)((char_T *)&rtb_Assignment2[1U] - (char_T *)
                      &rtb_Assignment2[0U]));
    memcpy((void *)&rtb_Assignment1_nx[0], (void *)&rtb_Assignment1_l[0], 10U *
           (uint32_T)((char_T *)&rtb_Assignment1_l[1U] - (char_T *)
                      &rtb_Assignment1_l[0U]));
    scalarIndex_0 = 1;
    for (i = 0; i < 7; i++) {
      claw_main_DWork.WhileIterator_IterationMarker[i] = 1U;
    }

    do {
      /* Sum: '<S533>/Sum' incorporates:
       *  Constant: '<S533>/Constant'
       *  Memory: '<S533>/Memory'
       */
      rtb_columncounter = claw_main_DWork.Memory_PreviousInput_g +
        claw_main_P.Constant_Value_k2;

      /* MultiPortSwitch: '<S533>/Multiport Switch' incorporates:
       *  Constant: '<S533>/Constant2'
       */
      if ((int32_T)claw_main_P.Constant2_Value_c == 0) {
        rtb_MultiportSwitch_p = rtb_columncounter;
      } else {
        rtb_MultiportSwitch_p = (real_T)scalarIndex_0;
      }

      /* Selector: '<S646>/Selector5' incorporates:
       *  Constant: '<S538>/Constant2'
       */
      i = ((int32_T)rtb_MultiportSwitch_p - 1) * 3;
      rtb_delta_LLh_idx = claw_main_P.Constant2_Value_ii[i + 1];
      rtb_delta_LLh_idx_0 = claw_main_P.Constant2_Value_ii[i + 2];

      /* Sum: '<S646>/Sum3' incorporates:
       *  Reshape: '<S646>/Reshape'
       */
      rtb_d[0] = rtb_orderatts_i_idx_0 + claw_main_P.Constant2_Value_ii[i];
      rtb_TmpHiddenBufferAtSelector1I[0] = rtb_Selector1_idx;
      rtb_d[1] = rtb_orderatts_i_idx_1 + rtb_delta_LLh_idx;
      rtb_TmpHiddenBufferAtSelector1I[1] = rtb_Selector1_idx_0;
      rtb_d[2] = min_5 + rtb_delta_LLh_idx_0;

      /* SignalConversion: '<S646>/TmpHiddenBufferAtSelector1Inport1' incorporates:
       *  Reshape: '<S787>/Reshape1'
       */
      rtb_TmpHiddenBufferAtSelector1I[2] = max_4;

      /* Switch: '<S646>/Switch' incorporates:
       *  RelationalOperator: '<S646>/Relational Operator'
       *  Reshape: '<S646>/Reshape'
       *  Selector: '<S646>/Selector'
       *  Selector: '<S646>/Selector1'
       *  Sum: '<S646>/Sum2'
       */
      if ((real_T)(rtb_d[(int32_T)rtb_MultiportSwitch_p - 1] <=
                   rtb_TmpHiddenBufferAtSelector1I[(int32_T)
                   rtb_MultiportSwitch_p - 1]) >= claw_main_P.Switch_Threshold_h)
      {
        rtb_Switch2_idx = rtb_d[0];
        rtb_delta_LLh_idx = rtb_d[1];
        rtb_UnitDelay_nf_idx_0 = rtb_d[2];
      } else {
        rtb_Switch2_idx = rtb_orderatts_i_idx_0 -
          claw_main_P.Constant2_Value_ii[i];
        rtb_delta_LLh_idx = rtb_orderatts_i_idx_1 - rtb_delta_LLh_idx;
        rtb_UnitDelay_nf_idx_0 = min_5 - rtb_delta_LLh_idx_0;
      }

      /* Sum: '<S646>/Sum1' */
      rtb_Sum1_e5[0] = rtb_Switch2_idx - rtb_orderatts_i_idx_0;
      rtb_Sum1_e5[1] = rtb_delta_LLh_idx - rtb_orderatts_i_idx_1;
      rtb_Sum1_e5[2] = rtb_UnitDelay_nf_idx_0 - min_5;

      /* Selector: '<S646>/Selector4' */
      rtb_Selector4 = rtb_Sum1_e5[(int32_T)rtb_MultiportSwitch_p - 1];

      /* Assertion: '<S533>/Assertion' */
      utAssert(rtb_Selector4 != 0.0);

      /* Memory: '<S533>/Memory1' */
      memcpy((void *)&rtb_Memory1_m[0], (void *)
             (&claw_main_DWork.Memory1_PreviousInput_k[0]), 9U * (uint32_T)
             ((char_T *)(&claw_main_DWork.Memory1_PreviousInput_k[1]) - (char_T *)
              (&claw_main_DWork.Memory1_PreviousInput_k[0])));

      /* SignalConversion: '<S628>/TmpHiddenBufferAtorder attsInport1' */
      rtb_TmpHiddenBufferAtorderatt_k[0] = rtb_Switch2_idx;
      rtb_TmpHiddenBufferAtorderatt_k[1] = rtb_delta_LLh_idx;
      rtb_TmpHiddenBufferAtorderatt_k[2] = rtb_MultiportSwitch_o_idx_0;

      /* Selector: '<S628>/order atts' incorporates:
       *  Constant: '<S628>/Constant'
       *  Selector: '<S628>/Selector'
       */
      rtb_orderatts_e[0] = rtb_TmpHiddenBufferAtorderatt_k[(int32_T)
        claw_main_P.Constant_Value_be[(int32_T)rtb_att_type - 1] - 1];
      rtb_orderatts_e[1] = rtb_TmpHiddenBufferAtorderatt_k[(int32_T)
        claw_main_P.Constant_Value_be[(int32_T)rtb_att_type + 4] - 1];
      rtb_orderatts_e[2] = rtb_TmpHiddenBufferAtorderatt_k[(int32_T)
        claw_main_P.Constant_Value_be[(int32_T)rtb_att_type + 9] - 1];

      /* SwitchCase: '<S628>/Switch Case' incorporates:
       *  ActionPort: '<S630>/Action Port'
       *  ActionPort: '<S631>/Action Port'
       *  ActionPort: '<S632>/Action Port'
       *  SubSystem: '<S628>/mba'
       *  SubSystem: '<S628>/tiltcam'
       *  SubSystem: '<S628>/ypr'
       */
      switch ((int32_T)rtb_att_type) {
       case 1:
        claw_main_tiltcam(rtb_orderatts_e, claw_main_B.Merge_f4,
                          (rtP_tiltcam_claw_main *) &claw_main_P.tiltcam_j);
        break;

       case 2:
       case 3:
        claw_main_ypr(rtb_orderatts_e, claw_main_B.Merge_f4, (rtP_ypr_claw_main *)
                      &claw_main_P.ypr_k);
        break;

       case 4:
       case 5:
        claw_main_mba(rtb_orderatts_e, rtb_Product_h, rtb_Sum_m, rtb_Sum1_p,
                      rtb_Product5, rtb_Sum2_l, rtb_Sum3, rtb_Gain_p,
                      rtb_Product10, rtb_Product11, claw_main_B.Merge_f4,
                      (rtP_mba_claw_main *) &claw_main_P.mba_n);
        break;
      }

      /* Gain: '<S645>/Gain' incorporates:
       *  Constant: '<S645>/Constant'
       *  Gain: '<S645>/Matrix Gain'
       *  Sum: '<S645>/Sum'
       */
      for (i = 0; i < 16; i++) {
        tmp_8[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
          tmp_8[i] += claw_main_P.MatrixGain_Gain_p[(yOffset_0 << 4) + i] *
            claw_main_B.Merge_f4[yOffset_0];
        }

        rtb_Gain_om3[i] = (tmp_8[i] + claw_main_P.Constant_Value_d0[i]) *
          claw_main_P.Gain_Gain_ik;
      }

      /* SignalConversion: '<S645>/TmpHiddenBufferAtselect best diagInport1' */
      rtb_TmpHiddenBufferAtselectb_gg[0] = rtb_Gain_om3[0];
      rtb_TmpHiddenBufferAtselectb_gg[1] = rtb_Gain_om3[5];
      rtb_TmpHiddenBufferAtselectb_gg[2] = rtb_Gain_om3[10];
      rtb_TmpHiddenBufferAtselectb_gg[3] = rtb_Gain_om3[15];

      /* MinMax: '<S645>/MinMax3' */
      max_1 = rt_MAXd_snf(rtb_TmpHiddenBufferAtselectb_gg[0],
                          rtb_TmpHiddenBufferAtselectb_gg[1]);
      max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectb_gg[2]);
      max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectb_gg[3]);

      /* Switch: '<S645>/argmax1' incorporates:
       *  Constant: '<S645>/Constant4'
       *  Constant: '<S645>/Constant5'
       *  Sum: '<S645>/Sum2'
       */
      if (rtb_TmpHiddenBufferAtselectb_gg[0] - max_1 >=
          claw_main_P.argmax1_Threshold_f) {
        rtb_delta_LLh_idx = claw_main_P.Constant4_Value_b[0];
      } else {
        rtb_delta_LLh_idx = claw_main_P.Constant5_Value_f;
      }

      if (rtb_TmpHiddenBufferAtselectb_gg[1] - max_1 >=
          claw_main_P.argmax1_Threshold_f) {
        rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_b[1];
      } else {
        rtb_delta_LLh_idx_0 = claw_main_P.Constant5_Value_f;
      }

      if (rtb_TmpHiddenBufferAtselectb_gg[2] - max_1 >=
          claw_main_P.argmax1_Threshold_f) {
        rtb_Switch2_idx = claw_main_P.Constant4_Value_b[2];
      } else {
        rtb_Switch2_idx = claw_main_P.Constant5_Value_f;
      }

      if (rtb_TmpHiddenBufferAtselectb_gg[3] - max_1 >=
          claw_main_P.argmax1_Threshold_f) {
        rtb_Gain1_idx_0 = claw_main_P.Constant4_Value_b[3];
      } else {
        rtb_Gain1_idx_0 = claw_main_P.Constant5_Value_f;
      }

      /* MinMax: '<S645>/MinMax4' */
      max_1 = rt_MINd_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);
      max_1 = rt_MINd_snf(max_1, rtb_Switch2_idx);
      max_1 = rt_MINd_snf(max_1, rtb_Gain1_idx_0);

      /* Selector: '<S645>/select best col' incorporates:
       *  Reshape: '<S645>/Reshape1'
       */
      i = ((int32_T)max_1 - 1) << 2;

      /* Selector: '<S645>/select best diag' */
      rtb_selectbestdiag_h = rtb_TmpHiddenBufferAtselectb_gg[(int32_T)max_1 - 1];

      /* Math: '<S645>/Math Function' */
      if (rtb_selectbestdiag_h < 0.0) {
        rtb_MathFunction_cq = -sqrt(-rtb_selectbestdiag_h);
      } else {
        rtb_MathFunction_cq = sqrt(rtb_selectbestdiag_h);
      }

      /* Product: '<S645>/Product' */
      rtb_Gain1_idx_0 = rtb_Gain_om3[i] / rtb_MathFunction_cq;
      rtb_Gain1_idx_1 = rtb_Gain_om3[i + 1] / rtb_MathFunction_cq;
      rtb_Gain1_idx = rtb_Gain_om3[i + 2] / rtb_MathFunction_cq;
      rtb_MultiportSwitch2_idx_2 = rtb_Gain_om3[i + 3] / rtb_MathFunction_cq;

      /* Switch: '<S629>/Switch' incorporates:
       *  Gain: '<S629>/Gain'
       *  Reshape: '<S645>/Reshape2'
       *  S-Function (sfix_dot): '<S629>/Dot Product'
       */
      rtb_delta_LLh_idx = ((rtb_Gain1_idx_0 * rtb_Assignment2[9] +
                            rtb_Gain1_idx_1 * rtb_Assignment2[10]) +
                           rtb_Gain1_idx * rtb_Assignment2[11]) +
        rtb_MultiportSwitch2_idx_2 * rtb_Assignment2[12];
      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_j)) {
        rtb_Gain1_idx_0 *= claw_main_P.Gain_Gain_n;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_j)) {
        rtb_Gain1_idx_1 *= claw_main_P.Gain_Gain_n;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_j)) {
        rtb_Gain1_idx *= claw_main_P.Gain_Gain_n;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_j)) {
        rtb_MultiportSwitch2_idx_2 *= claw_main_P.Gain_Gain_n;
      }

      /* SignalConversion: '<S537>/TmpHiddenBufferAtAssignment2Inport2' incorporates:
       *  Gain: '<S537>/Gain'
       *  Product: '<S537>/Product1'
       *  Reshape: '<S537>/Reshape1'
       */
      rtb_delta_LLh_idx = claw_main_P.Gain_Gain_n0[0] * rtb_Gain_idx;
      rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_n0[1] * rtb_Gain_idx_0;
      rtb_Switch2_idx = claw_main_P.Gain_Gain_n0[2] * rtb_Gain_idx_1;
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += claw_main_B.Merge_f4[i] * rtb_delta_LLh_idx;
        rtb_dircos_0[i] += claw_main_B.Merge_f4[i + 3] * rtb_delta_LLh_idx_0;
        rtb_dircos_0[i] += claw_main_B.Merge_f4[i + 6] * rtb_Switch2_idx;
      }

      rtb_TmpHiddenBufferAtAssignme_b[0] = rtb_Gain1_idx_0;
      rtb_TmpHiddenBufferAtAssignme_b[1] = rtb_Gain1_idx_1;
      rtb_TmpHiddenBufferAtAssignme_b[2] = rtb_Gain1_idx;
      rtb_TmpHiddenBufferAtAssignme_b[3] = rtb_MultiportSwitch2_idx_2;
      rtb_TmpHiddenBufferAtAssignme_b[4] = rtb_dircos_0[0];
      rtb_TmpHiddenBufferAtAssignme_b[5] = rtb_dircos_0[1];
      rtb_TmpHiddenBufferAtAssignme_b[6] = rtb_dircos_0[2];

      /* Assignment: '<S537>/Assignment2' */
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 7; uDimIdx++) {
        rtb_Assignment2_b[(int32_T)tmp_a[uDimIdx]] =
          rtb_TmpHiddenBufferAtAssignme_b[yOffset];
        yOffset++;
      }

      /* Gain: '<S541>/Gain1' incorporates:
       *  Math: '<S541>/Math Function'
       */
      rtb_delta_LLh_idx = rtb_Assignment2_b[9] * rtb_Assignment2_b[9];
      rtb_delta_LLh_idx_0 = rtb_Assignment2_b[10] * rtb_Assignment2_b[10];
      rtb_Switch2_idx = rtb_Assignment2_b[11] * rtb_Assignment2_b[11];
      rtb_Gain1_idx_0 = rtb_Assignment2_b[12] * rtb_Assignment2_b[12];
      for (i = 0; i < 4; i++) {
        rtb_Gain1_pd[i] = 0.0;
        rtb_Gain1_pd[i] += claw_main_P.Gain1_Gain_p4[i] * rtb_delta_LLh_idx;
        rtb_Gain1_pd[i] += claw_main_P.Gain1_Gain_p4[i + 4] *
          rtb_delta_LLh_idx_0;
        rtb_Gain1_pd[i] += claw_main_P.Gain1_Gain_p4[i + 8] * rtb_Switch2_idx;
        rtb_Gain1_pd[i] += claw_main_P.Gain1_Gain_p4[i + 12] * rtb_Gain1_idx_0;
      }

      /* Product: '<S541>/e1*e2' */
      rtb_e1e2_if = rtb_Assignment2_b[10] * rtb_Assignment2_b[11];

      /* Product: '<S541>/e3*e1' */
      rtb_e3e1_i = rtb_Assignment2_b[12] * rtb_Assignment2_b[10];

      /* Product: '<S541>/e2*e3' */
      rtb_e2e3_n = rtb_Assignment2_b[11] * rtb_Assignment2_b[12];

      /* Product: '<S541>/e0*e3' */
      rtb_e0e3_k = rtb_Assignment2_b[9] * rtb_Assignment2_b[12];

      /* Product: '<S541>/e0*e2' */
      rtb_e0e2_g = rtb_Assignment2_b[9] * rtb_Assignment2_b[11];

      /* Product: '<S541>/e0*e1' */
      rtb_e0e1_kt = rtb_Assignment2_b[9] * rtb_Assignment2_b[10];

      /* Gain: '<S541>/Gain' incorporates:
       *  Sum: '<S541>/Sum'
       *  Sum: '<S541>/Sum1'
       */
      rtb_Gain_g_idx = (rtb_e1e2_if + rtb_e0e3_k) * claw_main_P.Gain_Gain_ct;
      rtb_Gain_g_idx_0 = (rtb_e3e1_i + rtb_e0e2_g) * claw_main_P.Gain_Gain_ct;
      rtb_Gain_g_idx_1 = (rtb_e2e3_n + rtb_e0e1_kt) * claw_main_P.Gain_Gain_ct;
      rtb_Gain_g_idx_2 = (rtb_e1e2_if - rtb_e0e3_k) * claw_main_P.Gain_Gain_ct;
      rtb_Gain_g_idx_3 = (rtb_e3e1_i - rtb_e0e2_g) * claw_main_P.Gain_Gain_ct;
      rtb_Gain_g_idx_4 = (rtb_e2e3_n - rtb_e0e1_kt) * claw_main_P.Gain_Gain_ct;

      /* Reshape: '<S540>/Reshape' */
      rtb_dircos_m[0] = rtb_Gain1_pd[1];
      rtb_dircos_m[1] = rtb_Gain_g_idx_2;
      rtb_dircos_m[2] = rtb_Gain_g_idx_0;
      rtb_dircos_m[3] = rtb_Gain_g_idx;
      rtb_dircos_m[4] = rtb_Gain1_pd[2];
      rtb_dircos_m[5] = rtb_Gain_g_idx_4;
      rtb_dircos_m[6] = rtb_Gain_g_idx_3;
      rtb_dircos_m[7] = rtb_Gain_g_idx_1;
      rtb_dircos_m[8] = rtb_Gain1_pd[3];

      /* Product: '<S540>/Product1' incorporates:
       *  Gain: '<S540>/g'
       *  Selector: '<S540>/dircos(:,3)'
       */
      rtb_Product1_b_idx = claw_main_P.g_Gain_i * rtb_dircos_m[6] *
        claw_main_B.mass;
      rtb_Product1_b_idx_0 = claw_main_P.g_Gain_i * rtb_dircos_m[7] *
        claw_main_B.mass;
      rtb_Product1_b_idx_1 = claw_main_P.g_Gain_i * rtb_dircos_m[8] *
        claw_main_B.mass;

      /* Gain: '<S626>/Gain1' */
      rtb_dL_Ail_e = claw_main_P.Gain1_Gain_b * 0.0;

      /* Gain: '<S626>/Gain2' */
      rtb_dR_Ail_k = claw_main_P.Gain2_Gain_fj * 0.0;

      /* Assignment: '<S537>/Assignment1' */
      rtb_Assignment1_nx[6] = rtb_UnitDelay_nf_idx_0;

      /* Sum: '<S624>/Sum3' incorporates:
       *  Constant: '<S624>/Elevator'
       *  Product: '<S624>/Product'
       */
      rtb_Sum3_n = rtb_Assignment1_nx[4] * rtb_Assignment1_nx[0] +
        claw_main_P.Elevator_Value_c;

      /* Gain: '<S624>/Gain6' */
      rtb_ELLOBC_e = claw_main_P.Gain6_Gain_p * rtb_Sum3_n;

      /* Gain: '<S624>/Gain5' */
      rtb_ELLIBC_o3 = claw_main_P.Gain5_Gain_h * rtb_Sum3_n;

      /* Gain: '<S624>/Gain7' */
      rtb_ELROBC_o = claw_main_P.Gain7_Gain_c * rtb_Sum3_n;

      /* Gain: '<S624>/Gain8' */
      rtb_ELRIBC_p = claw_main_P.Gain8_Gain_o * rtb_Sum3_n;

      /* Sum: '<S624>/Sum' incorporates:
       *  Constant: '<S624>/Aileron'
       */
      rtb_Sum_ht = rtb_Assignment1_nx[1] + claw_main_P.Aileron_Value_h;

      /* Gain: '<S624>/Gain1' */
      rtb_AILLC_f = claw_main_P.Gain1_Gain_h * rtb_Sum_ht;

      /* Gain: '<S624>/Gain2' */
      rtb_AILRC_l = claw_main_P.Gain2_Gain_d * rtb_Sum_ht;

      /* Sum: '<S624>/Sum2' incorporates:
       *  Constant: '<S624>/Rudder'
       */
      rtb_Sum2_ds = rtb_Assignment1_nx[2] + claw_main_P.Rudder_Value_i;

      /* Gain: '<S624>/Gain3' */
      rtb_RUDUPC_h = claw_main_P.Gain3_Gain_d * rtb_Sum2_ds;

      /* Gain: '<S624>/Gain4' */
      rtb_RUDLOC_h = claw_main_P.Gain4_Gain_g * rtb_Sum2_ds;

      /* Lookup Block: '<S624>/Left Roll Spoiler Schedule'
       * About '<S624>/Left Roll Spoiler Schedule :'
       * Lookup Block: '<S624>/Left Roll Spoiler Schedule'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_LeftRollSpoilerSchedule_p),
                           claw_main_P.LeftRollSpoilerSchedule_YData_a,
                           claw_main_P.Constant_Value_id,
                           claw_main_P.LeftRollSpoilerSchedule_XData_g, 6U);

      /* Gain: '<S624>/Gain12' */
      rtb_SPLLIBC_g = claw_main_P.Gain12_Gain_i * rtb_LeftRollSpoilerSchedule_p;

      /* Gain: '<S624>/Gain13' */
      rtb_SPLLOBC_c = claw_main_P.Gain13_Gain_c * rtb_LeftRollSpoilerSchedule_p;

      /* Lookup Block: '<S624>/Right Roll Spoiler Schedule'
       * About '<S624>/Right Roll Spoiler Schedule :'
       * Lookup Block: '<S624>/Right Roll Spoiler Schedule'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_RightRollSpoilerSchedule_m),
                           claw_main_P.RightRollSpoilerSchedule_YDat_o,
                           claw_main_P.Constant_Value_id,
                           claw_main_P.RightRollSpoilerSchedule_XDat_c, 6U);

      /* Sum: '<S624>/Sum4' incorporates:
       *  Constant: '<S624>/Constant2'
       *  Constant: '<S624>/Flaps'
       */
      rtb_Sum4_a = claw_main_P.Constant2_Value_nb + claw_main_P.Flaps_Value_g;

      /* Gain: '<S624>/Gain20' incorporates:
       *  Constant: '<S624>/Gear'
       */
      rtb_GEARC_m = claw_main_P.Gain20_Gain_f * claw_main_P.Gear_Value_d;

      /* Sum: '<S623>/Sum' incorporates:
       *  Constant: '<S623>/Gear1'
       *  Constant: '<S624>/Constant3'
       *  Gain: '<S624>/Gain10'
       *  Gain: '<S624>/Gain11'
       *  Gain: '<S624>/Gain14'
       *  Gain: '<S624>/Gain15'
       *  Gain: '<S624>/Gain16'
       *  Gain: '<S624>/Gain17'
       *  Gain: '<S624>/Gain18'
       *  Gain: '<S624>/Gain21'
       *  Gain: '<S624>/Gain22'
       *  Gain: '<S624>/Gain9'
       *  Saturate: '<S623>/Brake'
       *  Saturate: '<S623>/Gear'
       *  SignalConversion: '<S624>/TmpHiddenBufferAtGain22Inport1'
       *  Sum: '<S623>/Sum3'
       */
      rtb_orderatts_i_idx = claw_main_P.Gain14_Gain_d *
        rtb_RightRollSpoilerSchedule_m;
      rtb_Switch_d_idx_0 = claw_main_P.Gain11_Gain_p *
        rtb_RightRollSpoilerSchedule_m;
      rtb_Switch_d_idx = claw_main_P.Gain16_Gain_f * rtb_Sum4_a;
      rtb_Sum_ow_idx = claw_main_P.Gain17_Gain_m * rtb_Sum4_a;
      rtb_Sum_ow_idx_0 = claw_main_P.Gain18_Gain_j * rtb_Sum4_a;
      rtb_Sum_ow_idx_1 = claw_main_P.Gain15_Gain_p * rtb_Sum4_a;
      rtb_Switch_d_idx_1 = rtb_Assignment1_nx[3] + claw_main_P.Gear1_Value_p;
      rtb_Sum_h_idx = rt_SATURATE(rtb_GEARC_m, claw_main_P.Gear_LowerSat_k,
        claw_main_P.Gear_UpperSat_b);
      rtb_delta_LLh_idx = (claw_main_P.Gain22_Gain_p[0] * rtb_Assignment1_nx[6]
                           + claw_main_P.Gain22_Gain_p[2] * rtb_Assignment1_nx[5])
        * claw_main_P.Gain9_Gain_l;
      rtb_delta_LLh_idx_0 = (claw_main_P.Gain22_Gain_p[1] * rtb_Assignment1_nx[6]
        + claw_main_P.Gain22_Gain_p[3] * rtb_Assignment1_nx[5]) *
        claw_main_P.Gain10_Gain_o;

      /* Polyval: '<S621>/Throttle_2_RPMref' */
      rtb_Throttle_2_RPMref_p = ((claw_main_P.Throttle_2_RPMref_coefs_k[0] *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_k[1]) *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_k[2]) *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_k[3];

      /* Polyval: '<S621>/RPMref_2_Thrust' */
      rtb_RPMref_2_Thrust_c = ((claw_main_P.RPMref_2_Thrust_coefs_p[0] *
        rtb_Throttle_2_RPMref_p + claw_main_P.RPMref_2_Thrust_coefs_p[1]) *
        rtb_Throttle_2_RPMref_p + claw_main_P.RPMref_2_Thrust_coefs_p[2]) *
        rtb_Throttle_2_RPMref_p + claw_main_P.RPMref_2_Thrust_coefs_p[3];

      /* Gain: '<S551>/Gain1' */
      rtb_pratio_g = claw_main_P.Gain1_Gain_m * rtb_P;

      /* Gain: '<S621>/UnScale_Ref_RPM' */
      rtb_UnScale_Ref_RPM_e2 = claw_main_P.UnScale_Ref_RPM_Gain_c *
        rtb_Throttle_2_RPMref_p;

      /* Gain: '<S621>/angular momentum' */
      rtb_angularmomentum_l = claw_main_P.angularmomentum_Gain_c *
        rtb_UnScale_Ref_RPM_e2;

      /* Polyval: '<S621>/RPMref_2_FuelFlow' */
      rtb_RPMref_2_FuelFlow_g = claw_main_P.RPMref_2_FuelFlow_coefs_n[0];
      rtb_RPMref_2_FuelFlow_g = rtb_RPMref_2_FuelFlow_g *
        rtb_Throttle_2_RPMref_p + claw_main_P.RPMref_2_FuelFlow_coefs_n[1];
      rtb_RPMref_2_FuelFlow_g = rtb_RPMref_2_FuelFlow_g *
        rtb_Throttle_2_RPMref_p + claw_main_P.RPMref_2_FuelFlow_coefs_n[2];

      /* Lookup Block: '<S621>/Fuel Pump Voltage'
       * About '<S621>/Fuel Pump Voltage :'
       * Lookup Block: '<S621>/Fuel Pump Voltage'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_o),
                           claw_main_P.FuelPumpVoltage_YData_k,
                           rtb_RPMref_2_FuelFlow_g,
                           claw_main_P.FuelPumpVoltage_XData_c, 25U);

      /* Gain: '<S552>/LengON' incorporates:
       *  Polyval: '<S621>/RPMref_2_EGT'
       *  Product: '<S621>/Product2'
       */
      rtb_LengON_o[0] = rtb_RPMref_2_Thrust_c * rtb_pratio_g *
        claw_main_P.LengON_Gain_i;
      rtb_LengON_o[1] = claw_main_P.LengON_Gain_i * rtb_UnScale_Ref_RPM_e2;
      rtb_LengON_o[2] = claw_main_P.LengON_Gain_i * rtb_angularmomentum_l;
      rtb_LengON_o[3] = claw_main_P.LengON_Gain_i * rtb_FuelPumpVoltage_o;
      rtb_LengON_o[4] = ((((claw_main_P.RPMref_2_EGT_coefs_o[0] *
                            rtb_Throttle_2_RPMref_p +
                            claw_main_P.RPMref_2_EGT_coefs_o[1]) *
                           rtb_Throttle_2_RPMref_p +
                           claw_main_P.RPMref_2_EGT_coefs_o[2]) *
                          rtb_Throttle_2_RPMref_p +
                          claw_main_P.RPMref_2_EGT_coefs_o[3]) *
                         rtb_Throttle_2_RPMref_p +
                         claw_main_P.RPMref_2_EGT_coefs_o[4]) *
        claw_main_P.LengON_Gain_i;
      rtb_LengON_o[5] = claw_main_P.LengON_Gain_i * rtb_RPMref_2_FuelFlow_g;

      /* Polyval: '<S622>/Throttle_2_RPMref' */
      rtb_Throttle_2_RPMref_m = ((claw_main_P.Throttle_2_RPMref_coefs_b[0] *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_b[1]) *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_b[2]) *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_b[3];

      /* Polyval: '<S622>/RPMref_2_Thrust' */
      rtb_RPMref_2_Thrust_e = ((claw_main_P.RPMref_2_Thrust_coefs_o[0] *
        rtb_Throttle_2_RPMref_m + claw_main_P.RPMref_2_Thrust_coefs_o[1]) *
        rtb_Throttle_2_RPMref_m + claw_main_P.RPMref_2_Thrust_coefs_o[2]) *
        rtb_Throttle_2_RPMref_m + claw_main_P.RPMref_2_Thrust_coefs_o[3];

      /* Gain: '<S622>/UnScale_Ref_RPM' */
      rtb_UnScale_Ref_RPM_ej = claw_main_P.UnScale_Ref_RPM_Gain_k *
        rtb_Throttle_2_RPMref_m;

      /* Gain: '<S622>/angular momentum' */
      rtb_angularmomentum_b = claw_main_P.angularmomentum_Gain_j *
        rtb_UnScale_Ref_RPM_ej;

      /* Polyval: '<S622>/RPMref_2_FuelFlow' */
      rtb_RPMref_2_FuelFlow_g1 = claw_main_P.RPMref_2_FuelFlow_coefs_a[0];
      rtb_RPMref_2_FuelFlow_g1 = rtb_RPMref_2_FuelFlow_g1 *
        rtb_Throttle_2_RPMref_m + claw_main_P.RPMref_2_FuelFlow_coefs_a[1];
      rtb_RPMref_2_FuelFlow_g1 = rtb_RPMref_2_FuelFlow_g1 *
        rtb_Throttle_2_RPMref_m + claw_main_P.RPMref_2_FuelFlow_coefs_a[2];

      /* Lookup Block: '<S622>/Fuel Pump Voltage'
       * About '<S622>/Fuel Pump Voltage :'
       * Lookup Block: '<S622>/Fuel Pump Voltage'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_d),
                           claw_main_P.FuelPumpVoltage_YData_e,
                           rtb_RPMref_2_FuelFlow_g1,
                           claw_main_P.FuelPumpVoltage_XData_a, 25U);

      /* Gain: '<S552>/RengON' incorporates:
       *  Polyval: '<S622>/RPMref_2_EGT'
       *  Product: '<S622>/Product2'
       */
      rtb_RengON_d[0] = rtb_RPMref_2_Thrust_e * rtb_pratio_g *
        claw_main_P.RengON_Gain_i;
      rtb_RengON_d[1] = claw_main_P.RengON_Gain_i * rtb_UnScale_Ref_RPM_ej;
      rtb_RengON_d[2] = claw_main_P.RengON_Gain_i * rtb_angularmomentum_b;
      rtb_RengON_d[3] = claw_main_P.RengON_Gain_i * rtb_FuelPumpVoltage_d;
      rtb_RengON_d[4] = ((((claw_main_P.RPMref_2_EGT_coefs_e[0] *
                            rtb_Throttle_2_RPMref_m +
                            claw_main_P.RPMref_2_EGT_coefs_e[1]) *
                           rtb_Throttle_2_RPMref_m +
                           claw_main_P.RPMref_2_EGT_coefs_e[2]) *
                          rtb_Throttle_2_RPMref_m +
                          claw_main_P.RPMref_2_EGT_coefs_e[3]) *
                         rtb_Throttle_2_RPMref_m +
                         claw_main_P.RPMref_2_EGT_coefs_e[4]) *
        claw_main_P.RengON_Gain_i;
      rtb_RengON_d[5] = claw_main_P.RengON_Gain_i * rtb_RPMref_2_FuelFlow_g1;
      claw_main_EngineAlignment(rtb_LengON_o[0], rtb_LengON_o[2], rtb_RengON_d[0],
        rtb_RengON_d[2], &claw_main_B.sf_EngineAlignment_g,
        (rtP_EngineAlignment_claw_main *) &claw_main_P.sf_EngineAlignment_g);

      /* FromWorkspace: '<S556>/From Workspace' */
      {
        real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
        real_T *pTimeValues = (real_T *)
          claw_main_DWork.FromWorkspace_PWORK_i.TimePtr;
        real_T *pDataValues = (real_T *)
          claw_main_DWork.FromWorkspace_PWORK_i.DataPtr;
        if (t < pTimeValues[0]) {
          rtb_FromWorkspace_o = 0.0;
        } else if (t >= pTimeValues[1]) {
          rtb_FromWorkspace_o = pDataValues[1];
        } else {
          int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK_n.PrevIndex;
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }

          rtb_FromWorkspace_o = pDataValues[currTimeIndex];
          claw_main_DWork.FromWorkspace_IWORK_n.PrevIndex = currTimeIndex;
        }
      }

      /* Selector: '<S559>/Value(ndx,:)1' incorporates:
       *  Constant: '<S559>/Gain2'
       */
      rtb_delta_LLh_idx = claw_main_P.Gain2_Value_j[(int32_T)rtb_FromWorkspace_o];
      rtb_Switch2_idx = claw_main_P.Gain2_Value_j[7 + (int32_T)
        rtb_FromWorkspace_o];
      rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain2_Value_j[14 + (int32_T)
        rtb_FromWorkspace_o];

      /* Sum: '<S555>/Add' incorporates:
       *  Constant: '<S552>/zero2'
       *  Constant: '<S555>/ixxb7'
       *  Constant: '<S559>/Gain1'
       *  Selector: '<S559>/Value(ndx,:)'
       *  Sum: '<S555>/Add3'
       */
      rtb_gwest_c = (claw_main_P.ixxb7_Value_j - claw_main_P.zero2_Value_c) +
        claw_main_P.Gain1_Value_e[(int32_T)rtb_FromWorkspace_o];
      claw_main_fuelcgshiftcg_pos0(claw_main_P.zero2_Value_c,
        &claw_main_B.sf_fuelcgshiftcg_pos0_i, (rtP_fuelcgshiftcg_pos0_claw_mai *)
        &claw_main_P.sf_fuelcgshiftcg_pos0_i);

      /* Switch: '<S555>/Switch1' incorporates:
       *  Constant: '<S555>/xCG1'
       *  Constant: '<S555>/xCG4'
       */
      if (rtb_Sum_h_idx >= claw_main_P.Switch1_Threshold_n) {
        rtb_delta_LLh_idx_0 = claw_main_P.xCG4_Value_h[0];
        rtb_Gain1_idx_0 = claw_main_P.xCG4_Value_h[1];
        rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG4_Value_h[2];
      } else {
        rtb_delta_LLh_idx_0 = claw_main_P.xCG1_Value_h[0];
        rtb_Gain1_idx_0 = claw_main_P.xCG1_Value_h[1];
        rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG1_Value_h[2];
      }

      /* Sum: '<S555>/Add2' incorporates:
       *  Product: '<S555>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_c * claw_main_B.sf_fuelcgshiftcg_pos0_i.y
                      [0] + rtb_delta_LLh_idx) + rtb_delta_LLh_idx_0;

      /* Sum: '<S614>/Sum6' incorporates:
       *  Constant: '<S549>/ixxb6'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_m[0] - rtb_Add2_idx;

      /* Gain: '<S620>/Gain' */
      rtb_Gain1_idx = claw_main_P.Gain_Gain_pb * rtb_Gain1_idx_1;

      /* Sum: '<S614>/Sum7' incorporates:
       *  Constant: '<S549>/ixxb5'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_l[0] - rtb_Add2_idx;

      /* Gain: '<S619>/Gain' */
      rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_cr *
        rtb_MultiportSwitch2_idx_2;
      rtb_UnitDelay_nf_idx = rtb_MultiportSwitch2_idx_2;
      rtb_Add2_idx_0 = rtb_Add2_idx;
      rtb_InterpolationnDusingPreLo_3 = rtb_Gain1_idx_1;

      /* Sum: '<S555>/Add2' incorporates:
       *  Product: '<S555>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_c * claw_main_B.sf_fuelcgshiftcg_pos0_i.y
                      [1] + rtb_Switch2_idx) + rtb_Gain1_idx_0;

      /* Sum: '<S614>/Sum6' incorporates:
       *  Constant: '<S549>/ixxb6'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_m[1] - rtb_Add2_idx;

      /* Gain: '<S620>/Gain' */
      rtb_delta_LLh_idx = claw_main_P.Gain_Gain_pb * rtb_Gain1_idx_1;

      /* Sum: '<S614>/Sum7' incorporates:
       *  Constant: '<S549>/ixxb5'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_l[1] - rtb_Add2_idx;

      /* Gain: '<S619>/Gain' */
      rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_cr *
        rtb_MultiportSwitch2_idx_2;
      rtb_Switch2_idx = rtb_MultiportSwitch2_idx_2;
      rtb_Add2_idx_1 = rtb_Add2_idx;
      rtb_Gain1_idx_0 = rtb_Gain1_idx_1;

      /* Sum: '<S555>/Add2' incorporates:
       *  Product: '<S555>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_c * claw_main_B.sf_fuelcgshiftcg_pos0_i.y
                      [2] + rtb_InterpolationnDusingPreLo_4) +
        rtb_InterpolationnDusingPreLo_5;

      /* Sum: '<S614>/Sum6' incorporates:
       *  Constant: '<S549>/ixxb6'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_m[2] - rtb_Add2_idx;

      /* Sum: '<S614>/Sum7' incorporates:
       *  Constant: '<S549>/ixxb5'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_l[2] - rtb_Add2_idx;

      /* Sum: '<S614>/Sum1' incorporates:
       *  Gain: '<S619>/Gain'
       *  Gain: '<S620>/Gain'
       *  Product: '<S619>/Product'
       *  Product: '<S620>/Product'
       *  Reshape: '<S619>/Reshape'
       *  Reshape: '<S620>/Reshape'
       */
      rtb_Gain1_oy_0[0] = 0.0;
      rtb_Gain1_oy_0[1] = rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
      rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_pb * rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[4] = 0.0;
      rtb_Gain1_oy_0[5] = rtb_InterpolationnDusingPreLo_3;
      rtb_Gain1_oy_0[6] = rtb_Gain1_idx_0;
      rtb_Gain1_oy_0[7] = rtb_Gain1_idx;
      rtb_Gain1_oy_0[8] = 0.0;
      rtb_Sum4_j_0[0] = 0.0;
      rtb_Sum4_j_0[1] = rtb_MultiportSwitch2_idx_2;
      rtb_Sum4_j_0[2] = rtb_delta_LLh_idx_0;
      rtb_Sum4_j_0[3] = claw_main_P.Gain_Gain_cr * rtb_MultiportSwitch2_idx_2;
      rtb_Sum4_j_0[4] = 0.0;
      rtb_Sum4_j_0[5] = rtb_UnitDelay_nf_idx;
      rtb_Sum4_j_0[6] = rtb_Switch2_idx;
      rtb_Sum4_j_0[7] = rtb_UnitDelay_nf_idx_0;
      rtb_Sum4_j_0[8] = 0.0;

      /* Product: '<S613>/Product' incorporates:
       *  Gain: '<S613>/Gain'
       *  Reshape: '<S613>/Reshape'
       */
      rtb_MultiportSwitch_cn_0[0] = 0.0;
      rtb_MultiportSwitch_cn_0[1] = rtb_Assignment2_b[2];
      rtb_MultiportSwitch_cn_0[2] = claw_main_P.Gain_Gain_du *
        rtb_Assignment2_b[1];
      rtb_MultiportSwitch_cn_0[3] = claw_main_P.Gain_Gain_du *
        rtb_Assignment2_b[2];
      rtb_MultiportSwitch_cn_0[4] = 0.0;
      rtb_MultiportSwitch_cn_0[5] = rtb_Assignment2_b[0];
      rtb_MultiportSwitch_cn_0[6] = rtb_Assignment2_b[1];
      rtb_MultiportSwitch_cn_0[7] = claw_main_P.Gain_Gain_du *
        rtb_Assignment2_b[0];
      rtb_MultiportSwitch_cn_0[8] = 0.0;

      /* Sum: '<S540>/Sum1' incorporates:
       *  Product: '<S540>/Product'
       */
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i] *
          claw_main_B.sf_EngineAlignment_g.TL[0];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] *
          claw_main_B.sf_EngineAlignment_g.TL[1];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] *
          claw_main_B.sf_EngineAlignment_g.TL[2];
        rtb_Gain_e_0[i] = 0.0;
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i] *
          claw_main_B.sf_EngineAlignment_g.TR[0];
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 3] *
          claw_main_B.sf_EngineAlignment_g.TR[1];
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 6] *
          claw_main_B.sf_EngineAlignment_g.TR[2];
        rtb_Product_dr[i] = 0.0;
        rtb_Product_dr[i] += rtb_MultiportSwitch_cn_0[i] *
          claw_main_B.sf_EngineAlignment_g.H[0];
        rtb_Product_dr[i] += rtb_MultiportSwitch_cn_0[i + 3] *
          claw_main_B.sf_EngineAlignment_g.H[1];
        rtb_Product_dr[i] += rtb_MultiportSwitch_cn_0[i + 6] *
          claw_main_B.sf_EngineAlignment_g.H[2];
        rtb_dircos_b_0[i] = 0.0;
        rtb_dircos_b_0[i] += rtb_dircos_m[i] * rtb_MultiportSwitch1_idx;
        rtb_dircos_b_0[i] += rtb_dircos_m[i + 3] * rtb_MultiportSwitch1_idx_0;
        rtb_dircos_b_0[i] += rtb_dircos_m[i + 6] * rtb_MultiportSwitch1_idx_1;
      }

      rtb_delta_LLh_idx = rtb_Assignment2_b[3] + rtb_dircos_b_0[0];
      rtb_Gain1_idx_0 = rtb_Assignment2_b[4] + rtb_dircos_b_0[1];
      rtb_delta_LLh_idx_0 = rtb_Assignment2_b[5] + rtb_dircos_b_0[2];

      /* Gain: '<S551>/Gain2' incorporates:
       *  Trigonometry: '<S627>/Trigonometric Function2'
       */
      claw_main_B.alpha_c = claw_main_P.Gain2_Gain_ma * rt_atan2_snf
        (rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

      /* PreLookup: '<S567>/AlphaLookup' */
      rtb_AlphaLookup_o1_gx = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.AlphaLookup_BreakpointsData_m[0], 31U,
        &rtb_AlphaLookup_o2_e, &claw_main_DWork.AlphaLookup_DWORK1_n);

      /* Math: '<S627>/Math Function' */
      rtb_MathFunction_k = rt_hypot_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);

      /* Gain: '<S551>/Gain3' incorporates:
       *  Trigonometry: '<S627>/Trigonometric Function1'
       */
      claw_main_B.beta_n = claw_main_P.Gain3_Gain_i * rt_atan2_snf
        (rtb_Gain1_idx_0, rtb_MathFunction_k);

      /* PreLookup: '<S567>/AlphaLookup1' */
      rtb_AlphaLookup1_o1_a = plook_linxp(claw_main_B.beta_n,
        &claw_main_P.AlphaLookup1_BreakpointsData_h[0], 26U,
        &rtb_AlphaLookup1_o2_d, &claw_main_DWork.AlphaLookup1_DWORK1_g);

      /* Interpolation_n-D: '<S567>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S567>/Constant1'
       */
      max_1 = rtb_AlphaLookup_o2_e;
      frac_18[0] = max_1;
      max_1 = rtb_AlphaLookup1_o2_d;
      frac_18[1] = max_1;
      bpIndex_18[0] = rtb_AlphaLookup_o1_gx;
      bpIndex_18[1] = rtb_AlphaLookup1_o1_a;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_keb[scalarIndex];
        if (claw_main_P.Constant1_Value_keb[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_18[2] = locIndex;
        locIndex = 864U * bpIndex_18[2U];
        rtb_InterpolationUsingPreloo_gx[scalarIndex] = intrp2d_lx(&bpIndex_18[0U],
          &frac_18[0U], &claw_main_P.InterpolationUsingPrelookup_T_g[locIndex],
          32U);
      }

      /* Interpolation_n-D: '<S567>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S567>/Constant2'
       */
      max_1 = rtb_AlphaLookup_o2_e;
      frac_19[0] = max_1;
      max_1 = rtb_AlphaLookup1_o2_d;
      frac_19[1] = max_1;
      bpIndex_19[0] = rtb_AlphaLookup_o1_gx;
      bpIndex_19[1] = rtb_AlphaLookup1_o1_a;
      locIndex = claw_main_P.Constant2_Value_ki[0];
      if (claw_main_P.Constant2_Value_ki[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_19[2] = locIndex;
      locIndex = 864U * bpIndex_19[2U];
      rtb_delta_LLh_idx = intrp2d_lx(&bpIndex_19[0U], &frac_19[0U],
        &claw_main_P.InterpolationUsingPrelookup1__d[locIndex], 32U);
      locIndex = claw_main_P.Constant2_Value_ki[1];
      if (claw_main_P.Constant2_Value_ki[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_19[2] = locIndex;
      locIndex = 864U * bpIndex_19[2U];
      rtb_delta_LLh_idx_0 = intrp2d_lx(&bpIndex_19[0U], &frac_19[0U],
        &claw_main_P.InterpolationUsingPrelookup1__d[locIndex], 32U);
      locIndex = claw_main_P.Constant2_Value_ki[2];
      if (claw_main_P.Constant2_Value_ki[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_19[2] = locIndex;
      locIndex = 864U * bpIndex_19[2U];
      rtb_Switch2_idx = intrp2d_lx(&bpIndex_19[0U], &frac_19[0U],
        &claw_main_P.InterpolationUsingPrelookup1__d[locIndex], 32U);

      /* Switch: '<S567>/Switch' incorporates:
       *  Constant: '<S550>/symmetry_on'
       *  Constant: '<S567>/Constant3'
       */
      if (claw_main_P.symmetry_on_Value_o != 0.0) {
        /* Assignment: '<S567>/Assignment to  Lateral' incorporates:
         *  Constant: '<S567>/Constant'
         */
        if (scalarIndex_0 == 1) {
          for (i = 0; i < 6; i++) {
            rtb_AssignmenttoLateral_o[i] = claw_main_P.Constant_Value_bl[i];
          }
        }

        rtb_AssignmenttoLateral_o[1] = rtb_delta_LLh_idx;
        rtb_AssignmenttoLateral_o[3] = rtb_delta_LLh_idx_0;
        rtb_AssignmenttoLateral_o[5] = rtb_Switch2_idx;
        for (i = 0; i < 6; i++) {
          rtb_Switch_ce[i] = rtb_AssignmenttoLateral_o[i];
        }
      } else {
        for (i = 0; i < 6; i++) {
          rtb_Switch_ce[i] = claw_main_P.Constant3_Value_di[i];
        }
      }

      /* DataTypeConversion: '<S567>/Data Type Conversion' */
      rtb_delta_LLh_idx = rtb_FromWorkspace_o;
      if ((rtb_FromWorkspace_o < 4.5035996273704960E+015) &&
          (rtb_FromWorkspace_o > -4.5035996273704960E+015)) {
        rtb_delta_LLh_idx = floor(rtb_FromWorkspace_o + 0.5);
      }

      if (rtIsNaN(rtb_FromWorkspace_o) || rtIsInf(rtb_FromWorkspace_o)) {
        rtb_delta_LLh_idx = 0.0;
      } else {
        rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
      }

      rtb_DataTypeConversion_k = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
        (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

      /* SwitchCase: '<S572>/Switch Case' incorporates:
       *  ActionPort: '<S573>/Action Port'
       *  ActionPort: '<S574>/Action Port'
       *  SubSystem: '<S572>/Switch Case Action Subsystem'
       *  SubSystem: '<S572>/Switch Case Action Subsystem2'
       */
      switch (rtb_DataTypeConversion_k) {
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
       case 6:
        claw__SwitchCaseActionSubsystem(claw_main_B.alpha_c, claw_main_B.beta_n,
          rtb_DataTypeConversion_k, claw_main_B.Merge_l,
          &claw_main_DWork.SwitchCaseActionSubsystem_c,
          (rtP_SwitchCaseActionSubsystem_c *)
          &claw_main_P.SwitchCaseActionSubsystem_c);
        break;

       default:
        /* Constant: '<S574>/Constant4' */
        for (i = 0; i < 6; i++) {
          claw_main_B.Merge_l[i] = claw_main_P.Constant4_Value_cm[i];
        }
        break;
      }

      /* Sum: '<S567>/Add' */
      for (i = 0; i < 6; i++) {
        rtb_Add_g[i] = (rtb_InterpolationUsingPreloo_gx[i] + rtb_Switch_ce[i]) +
          claw_main_B.Merge_l[i];
      }

      /* PreLookup: '<S597>/Prelookup' */
      rtb_Prelookup_o1_e = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup_BreakpointsData_l[0], 31U, &rtb_Prelookup_o2_d,
        &claw_main_DWork.Prelookup_DWORK1_n1);

      /* Switch: '<S597>/Switch' incorporates:
       *  Constant: '<S597>/Constant'
       *  Constant: '<S597>/Constant1'
       */
      if (rtb_RUDUPC_h >= claw_main_P.Switch_Threshold_nu) {
        rtb_Switch_nn = claw_main_P.Constant_Value_jg;
      } else {
        rtb_Switch_nn = claw_main_P.Constant1_Value_m;
      }

      /* PreLookup: '<S597>/Prelookup1' incorporates:
       *  Product: '<S597>/Product1'
       */
      rtb_Prelookup1_o1_a = plook_linxp(claw_main_B.beta_n * rtb_Switch_nn,
        &claw_main_P.Prelookup1_BreakpointsData_h[0], 26U, &rtb_Prelookup1_o2_c1,
        &claw_main_DWork.Prelookup1_DWORK1_k);

      /* PreLookup: '<S597>/Prelookup2' incorporates:
       *  Abs: '<S597>/Abs'
       *  Gain: '<S597>/Gain'
       */
      rtb_Prelookup2_o1_b = plook_linxp(claw_main_P.Gain_Gain_p5 * fabs
        (rtb_RUDUPC_h), &claw_main_P.Prelookup2_BreakpointsData_p[0], 3U,
        &rtb_Prelookup2_o2_lu, &claw_main_DWork.Prelookup2_DWORK1_dh);

      /* Interpolation_n-D: '<S597>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S597>/Constant2'
       */
      max_1 = rtb_Prelookup_o2_d;
      frac_1a[0] = max_1;
      max_1 = rtb_Prelookup1_o2_c1;
      frac_1a[1] = max_1;
      max_1 = rtb_Prelookup2_o2_lu;
      frac_1a[2] = max_1;
      bpIndex_1a[0] = rtb_Prelookup_o1_e;
      bpIndex_1a[1] = rtb_Prelookup1_o1_a;
      bpIndex_1a[2] = rtb_Prelookup2_o1_b;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant2_Value_in[scalarIndex];
        if (claw_main_P.Constant2_Value_in[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1a[3] = locIndex;
        locIndex = 3456U * bpIndex_1a[3U];
        rtb_InterpolationUsingPreloo_mo[scalarIndex] = intrp3d_lx(&bpIndex_1a[0U],
          &frac_1a[0U], &claw_main_P.InterpolationUsingPrelookup__gc[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_h[0]);
      }

      /* Assignment: '<S597>/Assignment to lateral' incorporates:
       *  Constant: '<S597>/Constant3'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_Assignmenttolateral_b[i] = claw_main_P.Constant3_Value_at[i];
        }
      }

      rtb_Assignmenttolateral_b[1] = rtb_Switch_nn;
      rtb_Assignmenttolateral_b[3] = rtb_Switch_nn;
      rtb_Assignmenttolateral_b[5] = rtb_Switch_nn;

      /* Product: '<S594>/Product' incorporates:
       *  Constant: '<S594>/gains'
       *  Product: '<S597>/Product2'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_hs[i] = rtb_InterpolationUsingPreloo_mo[i] *
          rtb_Assignmenttolateral_b[i] * claw_main_P.gains_Value_o[i];
      }

      /* PreLookup: '<S596>/Prelookup' */
      rtb_Prelookup_o1_o = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup_BreakpointsData_e[0], 31U, &rtb_Prelookup_o2_dh,
        &claw_main_DWork.Prelookup_DWORK1_i);

      /* Switch: '<S596>/Switch' incorporates:
       *  Constant: '<S596>/Constant'
       *  Constant: '<S596>/Constant1'
       */
      if (rtb_RUDLOC_h >= claw_main_P.Switch_Threshold_g1) {
        rtb_Switch_kl = claw_main_P.Constant_Value_bs;
      } else {
        rtb_Switch_kl = claw_main_P.Constant1_Value_j0;
      }

      /* PreLookup: '<S596>/Prelookup1' incorporates:
       *  Product: '<S596>/Product1'
       */
      rtb_Prelookup1_o1_jc = plook_linxp(claw_main_B.beta_n * rtb_Switch_kl,
        &claw_main_P.Prelookup1_BreakpointsData_ij[0], 26U, &rtb_Prelookup1_o2_j,
        &claw_main_DWork.Prelookup1_DWORK1_m);

      /* PreLookup: '<S596>/Prelookup2' incorporates:
       *  Abs: '<S596>/Abs'
       *  Gain: '<S596>/Gain'
       */
      rtb_Prelookup2_o1_k = plook_linxp(claw_main_P.Gain_Gain_bu * fabs
        (rtb_RUDLOC_h), &claw_main_P.Prelookup2_BreakpointsData_d[0], 3U,
        &rtb_Prelookup2_o2_k, &claw_main_DWork.Prelookup2_DWORK1_o);

      /* Interpolation_n-D: '<S596>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S596>/Constant2'
       */
      max_1 = rtb_Prelookup_o2_dh;
      frac_1b[0] = max_1;
      max_1 = rtb_Prelookup1_o2_j;
      frac_1b[1] = max_1;
      max_1 = rtb_Prelookup2_o2_k;
      frac_1b[2] = max_1;
      bpIndex_1b[0] = rtb_Prelookup_o1_o;
      bpIndex_1b[1] = rtb_Prelookup1_o1_jc;
      bpIndex_1b[2] = rtb_Prelookup2_o1_k;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant2_Value_mh[scalarIndex];
        if (claw_main_P.Constant2_Value_mh[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1b[3] = locIndex;
        locIndex = 3456U * bpIndex_1b[3U];
        rtb_InterpolationUsingPreloo_ll[scalarIndex] = intrp3d_lx(&bpIndex_1b[0U],
          &frac_1b[0U], &claw_main_P.InterpolationUsingPrelookup_T_h[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_e[0]);
      }

      /* Assignment: '<S596>/Assignment to lateral' incorporates:
       *  Constant: '<S596>/Constant3'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_Assignmenttolateral_d[i] = claw_main_P.Constant3_Value_jk[i];
        }
      }

      rtb_Assignmenttolateral_d[1] = rtb_Switch_kl;
      rtb_Assignmenttolateral_d[3] = rtb_Switch_kl;
      rtb_Assignmenttolateral_d[5] = rtb_Switch_kl;

      /* Product: '<S595>/Product' incorporates:
       *  Constant: '<S595>/gains'
       *  Product: '<S596>/Product2'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_b2[i] = rtb_InterpolationUsingPreloo_ll[i] *
          rtb_Assignmenttolateral_d[i] * claw_main_P.gains_Value_c[i];
      }

      /* PreLookup: '<S576>/Prelookup1' */
      rtb_Prelookup1_o1_dk = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup1_BreakpointsData_j[0], 31U, &rtb_Prelookup1_o2_h0,
        &claw_main_DWork.Prelookup1_DWORK1_lj);

      /* PreLookup: '<S576>/Prelookup2' incorporates:
       *  Gain: '<S576>/Gain2'
       */
      rtb_Prelookup2_o1_pr = plook_linxp(claw_main_P.Gain2_Gain_o *
        claw_main_B.beta_n, &claw_main_P.Prelookup2_BreakpointsData_pe[0], 26U,
        &rtb_Prelookup2_o2_ld, &claw_main_DWork.Prelookup2_DWORK1_pa);

      /* PreLookup: '<S576>/Prelookup3' */
      rtb_Prelookup3_o1_l = plook_linxp(rtb_dL_Ail_e + rtb_AILLC_f,
        &claw_main_P.Prelookup3_BreakpointsData_k[0], 6U, &rtb_Prelookup3_o2_nz,
        &claw_main_DWork.Prelookup3_DWORK1_c);

      /* Interpolation_n-D: '<S576>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S576>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_h0;
      frac_1c[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ld;
      frac_1c[1] = max_1;
      max_1 = rtb_Prelookup3_o2_nz;
      frac_1c[2] = max_1;
      bpIndex_1c[0] = rtb_Prelookup1_o1_dk;
      bpIndex_1c[1] = rtb_Prelookup2_o1_pr;
      bpIndex_1c[2] = rtb_Prelookup3_o1_l;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_mf[scalarIndex];
        if (claw_main_P.Constant3_Value_mf[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1c[3] = locIndex;
        locIndex = 6048U * bpIndex_1c[3U];
        rtb_InterpolationUsingPrelook_i[scalarIndex] = intrp3d_lx(&bpIndex_1c[0U],
          &frac_1c[0U], &claw_main_P.InterpolationUsingPrelookup__jl[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_p[0]);
      }

      /* Gain: '<S576>/Negate Lateral' */
      for (i = 0; i < 6; i++) {
        rtb_NegateLateral_d[i] = claw_main_P.NegateLateral_Gain_e[i] *
          rtb_InterpolationUsingPrelook_i[i];
      }

      /* PreLookup: '<S576>/Prelookup4' */
      rtb_Prelookup4_o1_g = plook_linxp(claw_main_B.beta_n,
        &claw_main_P.Prelookup4_BreakpointsData_o[0], 26U, &rtb_Prelookup4_o2_a,
        &claw_main_DWork.Prelookup4_DWORK1_bm);

      /* PreLookup: '<S576>/Prelookup5' */
      rtb_Prelookup5_o1_m = plook_linxp(rtb_dR_Ail_k + rtb_AILRC_l,
        &claw_main_P.Prelookup5_BreakpointsData_b[0], 6U, &rtb_Prelookup5_o2_mk,
        &claw_main_DWork.Prelookup5_DWORK1_b);

      /* Interpolation_n-D: '<S576>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S576>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_h0;
      frac_1d[0] = max_1;
      max_1 = rtb_Prelookup4_o2_a;
      frac_1d[1] = max_1;
      max_1 = rtb_Prelookup5_o2_mk;
      frac_1d[2] = max_1;
      bpIndex_1d[0] = rtb_Prelookup1_o1_dk;
      bpIndex_1d[1] = rtb_Prelookup4_o1_g;
      bpIndex_1d[2] = rtb_Prelookup5_o1_m;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_oc[scalarIndex];
        if (claw_main_P.Constant1_Value_oc[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1d[3] = locIndex;
        locIndex = 6048U * bpIndex_1d[3U];
        rtb_InterpolationUsingPreloo_nc[scalarIndex] = intrp3d_lx(&bpIndex_1d[0U],
          &frac_1d[0U], &claw_main_P.InterpolationUsingPrelookup1__o[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1__p[0]);
      }

      /* PreLookup: '<S602>/Prelookup1' */
      rtb_Prelookup1_o1_ib = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup1_BreakpointsData_ip[0], 31U,
        &rtb_Prelookup1_o2_o2, &claw_main_DWork.Prelookup1_DWORK1_i);

      /* PreLookup: '<S602>/Prelookup2' incorporates:
       *  Gain: '<S602>/Gain2'
       */
      rtb_Prelookup2_o1_kj = plook_linxp(claw_main_P.Gain2_Gain_ae *
        claw_main_B.beta_n, &claw_main_P.Prelookup2_BreakpointsData_n[0], 26U,
        &rtb_Prelookup2_o2_ms, &claw_main_DWork.Prelookup2_DWORK1_l);

      /* PreLookup: '<S602>/Prelookup3' */
      rtb_Prelookup3_o1_ib = plook_linxp(rtb_SPLLIBC_g,
        &claw_main_P.Prelookup3_BreakpointsData_a[0], 2U, &rtb_Prelookup3_o2_e,
        &claw_main_DWork.Prelookup3_DWORK1_n5);

      /* Interpolation_n-D: '<S602>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S602>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_o2;
      frac_1e[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ms;
      frac_1e[1] = max_1;
      max_1 = rtb_Prelookup3_o2_e;
      frac_1e[2] = max_1;
      bpIndex_1e[0] = rtb_Prelookup1_o1_ib;
      bpIndex_1e[1] = rtb_Prelookup2_o1_kj;
      bpIndex_1e[2] = rtb_Prelookup3_o1_ib;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_i[scalarIndex];
        if (claw_main_P.Constant3_Value_i[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1e[3] = locIndex;
        locIndex = 2592U * bpIndex_1e[3U];
        rtb_InterpolationUsingPreloo_ev[scalarIndex] = intrp3d_lx(&bpIndex_1e[0U],
          &frac_1e[0U], &claw_main_P.InterpolationUsingPrelookup__ia[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_d[0]);
      }

      /* Product: '<S599>/Product' incorporates:
       *  Constant: '<S599>/gains'
       *  Gain: '<S602>/Negate Lateral'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_ij[i] = claw_main_P.NegateLateral_Gain_o[i] *
          rtb_InterpolationUsingPreloo_ev[i] * claw_main_P.gains_Value_l[i];
      }

      /* PreLookup: '<S603>/Prelookup1' */
      rtb_Prelookup1_o1_j5 = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup1_BreakpointsData_e[0], 31U, &rtb_Prelookup1_o2_hj,
        &claw_main_DWork.Prelookup1_DWORK1_cy);

      /* PreLookup: '<S603>/Prelookup2' incorporates:
       *  Gain: '<S603>/Gain2'
       */
      rtb_Prelookup2_o1_mq = plook_linxp(claw_main_P.Gain2_Gain_k2 *
        claw_main_B.beta_n, &claw_main_P.Prelookup2_BreakpointsData_bt[0], 26U,
        &rtb_Prelookup2_o2_kg, &claw_main_DWork.Prelookup2_DWORK1_j3);

      /* PreLookup: '<S603>/Prelookup3' */
      rtb_Prelookup3_o1_fn = plook_linxp(rtb_SPLLOBC_c,
        &claw_main_P.Prelookup3_BreakpointsData_ab[0], 2U, &rtb_Prelookup3_o2_ec,
        &claw_main_DWork.Prelookup3_DWORK1_dm);

      /* Interpolation_n-D: '<S603>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S603>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_hj;
      frac_1f[0] = max_1;
      max_1 = rtb_Prelookup2_o2_kg;
      frac_1f[1] = max_1;
      max_1 = rtb_Prelookup3_o2_ec;
      frac_1f[2] = max_1;
      bpIndex_1f[0] = rtb_Prelookup1_o1_j5;
      bpIndex_1f[1] = rtb_Prelookup2_o1_mq;
      bpIndex_1f[2] = rtb_Prelookup3_o1_fn;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_g4[scalarIndex];
        if (claw_main_P.Constant3_Value_g4[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1f[3] = locIndex;
        locIndex = 2592U * bpIndex_1f[3U];
        rtb_InterpolationUsingPreloo_cp[scalarIndex] = intrp3d_lx(&bpIndex_1f[0U],
          &frac_1f[0U], &claw_main_P.InterpolationUsingPrelookup_T_m[locIndex],
          &claw_main_P.InterpolationUsingPrelookup__am[0]);
      }

      /* Product: '<S600>/Product' incorporates:
       *  Constant: '<S600>/gains'
       *  Gain: '<S603>/Negate Lateral'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_nh[i] = claw_main_P.NegateLateral_Gain_n[i] *
          rtb_InterpolationUsingPreloo_cp[i] * claw_main_P.gains_Value_j[i];
      }

      /* PreLookup: '<S602>/Prelookup4' */
      rtb_Prelookup4_o1_c = plook_linxp(claw_main_B.beta_n,
        &claw_main_P.Prelookup4_BreakpointsData_ld[0], 26U,
        &rtb_Prelookup4_o2_na, &claw_main_DWork.Prelookup4_DWORK1_ol);

      /* PreLookup: '<S602>/Prelookup5' */
      rtb_Prelookup5_o1_f = plook_linxp(rtb_orderatts_i_idx,
        &claw_main_P.Prelookup5_BreakpointsData_j[0], 2U, &rtb_Prelookup5_o2_o,
        &claw_main_DWork.Prelookup5_DWORK1_g);

      /* Interpolation_n-D: '<S602>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S602>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_o2;
      frac_1g[0] = max_1;
      max_1 = rtb_Prelookup4_o2_na;
      frac_1g[1] = max_1;
      max_1 = rtb_Prelookup5_o2_o;
      frac_1g[2] = max_1;
      bpIndex_1g[0] = rtb_Prelookup1_o1_ib;
      bpIndex_1g[1] = rtb_Prelookup4_o1_c;
      bpIndex_1g[2] = rtb_Prelookup5_o1_f;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_ac[scalarIndex];
        if (claw_main_P.Constant1_Value_ac[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1g[3] = locIndex;
        locIndex = 2592U * bpIndex_1g[3U];
        rtb_InterpolationUsingPreloo_fg[scalarIndex] = intrp3d_lx(&bpIndex_1g[0U],
          &frac_1g[0U], &claw_main_P.InterpolationUsingPrelookup1_oy[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1_ef[0]);
      }

      /* Product: '<S598>/Product' incorporates:
       *  Constant: '<S598>/gains'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_eb[i] = rtb_InterpolationUsingPreloo_fg[i] *
          claw_main_P.gains_Value_cf[i];
      }

      /* PreLookup: '<S603>/Prelookup4' */
      rtb_Prelookup4_o1_k = plook_linxp(claw_main_B.beta_n,
        &claw_main_P.Prelookup4_BreakpointsData_ne[0], 26U,
        &rtb_Prelookup4_o2_b3, &claw_main_DWork.Prelookup4_DWORK1_mz);

      /* PreLookup: '<S603>/Prelookup5' */
      rtb_Prelookup5_o1_l = plook_linxp(rtb_Switch_d_idx_0,
        &claw_main_P.Prelookup5_BreakpointsData_n[0], 2U, &rtb_Prelookup5_o2_il,
        &claw_main_DWork.Prelookup5_DWORK1_ay);

      /* Interpolation_n-D: '<S603>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S603>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_hj;
      frac_1h[0] = max_1;
      max_1 = rtb_Prelookup4_o2_b3;
      frac_1h[1] = max_1;
      max_1 = rtb_Prelookup5_o2_il;
      frac_1h[2] = max_1;
      bpIndex_1h[0] = rtb_Prelookup1_o1_j5;
      bpIndex_1h[1] = rtb_Prelookup4_o1_k;
      bpIndex_1h[2] = rtb_Prelookup5_o1_l;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_cx[scalarIndex];
        if (claw_main_P.Constant1_Value_cx[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1h[3] = locIndex;
        locIndex = 2592U * bpIndex_1h[3U];
        rtb_InterpolationUsingPreloo_jn[scalarIndex] = intrp3d_lx(&bpIndex_1h[0U],
          &frac_1h[0U], &claw_main_P.InterpolationUsingPrelookup1__n[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1_bd[0]);
      }

      /* Product: '<S601>/Product' incorporates:
       *  Constant: '<S601>/gains'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_nz[i] = rtb_InterpolationUsingPreloo_jn[i] *
          claw_main_P.gains_Value_cfo[i];
      }

      /* PreLookup: '<S577>/Prelookup1' */
      rtb_Prelookup1_o1_if = plook_linxp(claw_main_B.alpha_c,
        &claw_main_P.Prelookup1_BreakpointsData_o[0], 31U, &rtb_Prelookup1_o2_n0,
        &claw_main_DWork.Prelookup1_DWORK1_pa);

      /* PreLookup: '<S577>/Prelookup2' */
      rtb_Prelookup2_o1_pm = plook_linxp(claw_main_B.beta_n,
        &claw_main_P.Prelookup2_BreakpointsData_jq[0], 26U,
        &rtb_Prelookup2_o2_mr, &claw_main_DWork.Prelookup2_DWORK1_fo);

      /* PreLookup: '<S577>/Prelookup3' */
      rtb_Prelookup3_o1_lh = plook_linxp(rtb_Switch_d_idx_1,
        &claw_main_P.Prelookup3_BreakpointsData_l[0], 3U, &rtb_Prelookup3_o2_m,
        &claw_main_DWork.Prelookup3_DWORK1_o);

      /* PreLookup: '<S588>/Prelookup4' incorporates:
       *  Constant: '<S577>/Constant1'
       */
      rtb_Prelookup4_o1_no = plook_linxp(claw_main_P.Constant1_Value_l,
        &claw_main_P.Prelookup4_BreakpointsData_db[0], 5U, &rtb_Prelookup4_o2_la,
        &claw_main_DWork.Prelookup4_DWORK1_c);

      /* Interpolation_n-D: '<S588>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S588>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_n0;
      frac_1i[0] = max_1;
      max_1 = rtb_Prelookup2_o2_mr;
      frac_1i[1] = max_1;
      max_1 = rtb_Prelookup3_o2_m;
      frac_1i[2] = max_1;
      max_1 = rtb_Prelookup4_o2_la;
      frac_1i[3] = max_1;
      bpIndex_1i[0] = rtb_Prelookup1_o1_if;
      bpIndex_1i[1] = rtb_Prelookup2_o1_pm;
      bpIndex_1i[2] = rtb_Prelookup3_o1_lh;
      bpIndex_1i[3] = rtb_Prelookup4_o1_no;
      locIndex = claw_main_P.Constant2_Value_bb[0];
      if (claw_main_P.Constant2_Value_bb[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1i[4] = locIndex;
      locIndex = 20736U * bpIndex_1i[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1i[0U], &frac_1i[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_o[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ni[0]);
      locIndex = claw_main_P.Constant2_Value_bb[1];
      if (claw_main_P.Constant2_Value_bb[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1i[4] = locIndex;
      locIndex = 20736U * bpIndex_1i[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1i[0U], &frac_1i[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_o[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ni[0]);
      locIndex = claw_main_P.Constant2_Value_bb[2];
      if (claw_main_P.Constant2_Value_bb[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1i[4] = locIndex;
      locIndex = 20736U * bpIndex_1i[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1i[0U], &frac_1i[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_o[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ni[0]);

      /* Assignment: '<S588>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S588>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_n[i] = claw_main_P.Constant_Value_co[i];
        }
      }

      rtb_AssignmenttoLongitudinal_n[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_n[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_n[4] = rtb_Switch2_idx;

      /* PreLookup: '<S587>/Prelookup4' */
      rtb_Prelookup4_o1_pa = plook_linxp(rtb_ELLOBC_e,
        &claw_main_P.Prelookup4_BreakpointsData_e[0], 5U, &rtb_Prelookup4_o2_mb,
        &claw_main_DWork.Prelookup4_DWORK1_gc);

      /* Interpolation_n-D: '<S587>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S587>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_n0;
      frac_1j[0] = max_1;
      max_1 = rtb_Prelookup2_o2_mr;
      frac_1j[1] = max_1;
      max_1 = rtb_Prelookup3_o2_m;
      frac_1j[2] = max_1;
      max_1 = rtb_Prelookup4_o2_mb;
      frac_1j[3] = max_1;
      bpIndex_1j[0] = rtb_Prelookup1_o1_if;
      bpIndex_1j[1] = rtb_Prelookup2_o1_pm;
      bpIndex_1j[2] = rtb_Prelookup3_o1_lh;
      bpIndex_1j[3] = rtb_Prelookup4_o1_pa;
      locIndex = claw_main_P.Constant2_Value_gf[0];
      if (claw_main_P.Constant2_Value_gf[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1j[4] = locIndex;
      locIndex = 20736U * bpIndex_1j[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1j[0U], &frac_1j[0U],
        &claw_main_P.InterpolationUsingPrelookup__mi[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__cz[0]);
      locIndex = claw_main_P.Constant2_Value_gf[1];
      if (claw_main_P.Constant2_Value_gf[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1j[4] = locIndex;
      locIndex = 20736U * bpIndex_1j[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1j[0U], &frac_1j[0U],
        &claw_main_P.InterpolationUsingPrelookup__mi[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__cz[0]);
      locIndex = claw_main_P.Constant2_Value_gf[2];
      if (claw_main_P.Constant2_Value_gf[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1j[4] = locIndex;
      locIndex = 20736U * bpIndex_1j[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1j[0U], &frac_1j[0U],
        &claw_main_P.InterpolationUsingPrelookup__mi[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__cz[0]);

      /* Assignment: '<S587>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S587>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_ja[i] = claw_main_P.Constant_Value_h2[i];
        }
      }

      rtb_AssignmenttoLongitudinal_ja[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_ja[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_ja[4] = rtb_Switch2_idx;

      /* Gain: '<S584>/Gain' incorporates:
       *  Gain: '<S577>/Gain'
       *  Sum: '<S577>/Add'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_ja[i] -
                    rtb_AssignmenttoLongitudinal_n[i]) *
          claw_main_P.Gain_Gain_nv;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_f4[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_f4[i] += claw_main_P.Gain_Gain_ks[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S589>/Prelookup4' */
      rtb_Prelookup4_o1_b3 = plook_linxp(rtb_ELLIBC_o3,
        &claw_main_P.Prelookup4_BreakpointsData_az[0], 5U, &rtb_Prelookup4_o2_mo,
        &claw_main_DWork.Prelookup4_DWORK1_cg);

      /* Interpolation_n-D: '<S589>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S589>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_n0;
      frac_1k[0] = max_1;
      max_1 = rtb_Prelookup2_o2_mr;
      frac_1k[1] = max_1;
      max_1 = rtb_Prelookup3_o2_m;
      frac_1k[2] = max_1;
      max_1 = rtb_Prelookup4_o2_mo;
      frac_1k[3] = max_1;
      bpIndex_1k[0] = rtb_Prelookup1_o1_if;
      bpIndex_1k[1] = rtb_Prelookup2_o1_pm;
      bpIndex_1k[2] = rtb_Prelookup3_o1_lh;
      bpIndex_1k[3] = rtb_Prelookup4_o1_b3;
      locIndex = claw_main_P.Constant2_Value_pi[0];
      if (claw_main_P.Constant2_Value_pi[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1k[4] = locIndex;
      locIndex = 20736U * bpIndex_1k[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1k[0U], &frac_1k[0U],
        &claw_main_P.InterpolationUsingPrelookup__bk[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__nq[0]);
      locIndex = claw_main_P.Constant2_Value_pi[1];
      if (claw_main_P.Constant2_Value_pi[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1k[4] = locIndex;
      locIndex = 20736U * bpIndex_1k[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1k[0U], &frac_1k[0U],
        &claw_main_P.InterpolationUsingPrelookup__bk[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__nq[0]);
      locIndex = claw_main_P.Constant2_Value_pi[2];
      if (claw_main_P.Constant2_Value_pi[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1k[4] = locIndex;
      locIndex = 20736U * bpIndex_1k[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1k[0U], &frac_1k[0U],
        &claw_main_P.InterpolationUsingPrelookup__bk[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__nq[0]);

      /* Assignment: '<S589>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S589>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_i[i] = claw_main_P.Constant_Value_g[i];
        }
      }

      rtb_AssignmenttoLongitudinal_i[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_i[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_i[4] = rtb_Switch2_idx;

      /* Gain: '<S583>/Gain' incorporates:
       *  Gain: '<S577>/Gain1'
       *  Sum: '<S577>/Add1'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_i[i] -
                    rtb_AssignmenttoLongitudinal_n[i]) *
          claw_main_P.Gain1_Gain_j;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_kl[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_kl[i] += claw_main_P.Gain_Gain_i4f[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S591>/Prelookup4' */
      rtb_Prelookup4_o1_pd = plook_linxp(rtb_ELRIBC_p,
        &claw_main_P.Prelookup4_BreakpointsData_nf[0], 5U, &rtb_Prelookup4_o2_cz,
        &claw_main_DWork.Prelookup4_DWORK1_l3);

      /* Interpolation_n-D: '<S591>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S591>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_n0;
      frac_1l[0] = max_1;
      max_1 = rtb_Prelookup2_o2_mr;
      frac_1l[1] = max_1;
      max_1 = rtb_Prelookup3_o2_m;
      frac_1l[2] = max_1;
      max_1 = rtb_Prelookup4_o2_cz;
      frac_1l[3] = max_1;
      bpIndex_1l[0] = rtb_Prelookup1_o1_if;
      bpIndex_1l[1] = rtb_Prelookup2_o1_pm;
      bpIndex_1l[2] = rtb_Prelookup3_o1_lh;
      bpIndex_1l[3] = rtb_Prelookup4_o1_pd;
      locIndex = claw_main_P.Constant2_Value_gp[0];
      if (claw_main_P.Constant2_Value_gp[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1l[4] = locIndex;
      locIndex = 20736U * bpIndex_1l[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1l[0U], &frac_1l[0U],
        &claw_main_P.InterpolationUsingPrelookup__bq[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ba[0]);
      locIndex = claw_main_P.Constant2_Value_gp[1];
      if (claw_main_P.Constant2_Value_gp[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1l[4] = locIndex;
      locIndex = 20736U * bpIndex_1l[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1l[0U], &frac_1l[0U],
        &claw_main_P.InterpolationUsingPrelookup__bq[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ba[0]);
      locIndex = claw_main_P.Constant2_Value_gp[2];
      if (claw_main_P.Constant2_Value_gp[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1l[4] = locIndex;
      locIndex = 20736U * bpIndex_1l[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1l[0U], &frac_1l[0U],
        &claw_main_P.InterpolationUsingPrelookup__bq[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ba[0]);

      /* Assignment: '<S591>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S591>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_jm[i] = claw_main_P.Constant_Value_gc[i];
        }
      }

      rtb_AssignmenttoLongitudinal_jm[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_jm[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_jm[4] = rtb_Switch2_idx;

      /* Gain: '<S585>/Gain' incorporates:
       *  Gain: '<S577>/Gain2'
       *  Sum: '<S577>/Add2'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_jm[i] -
                    rtb_AssignmenttoLongitudinal_n[i]) *
          claw_main_P.Gain2_Gain_k3;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_fa[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_fa[i] += claw_main_P.Gain_Gain_f[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S590>/Prelookup4' */
      rtb_Prelookup4_o1_di = plook_linxp(rtb_ELROBC_o,
        &claw_main_P.Prelookup4_BreakpointsData_j[0], 5U, &rtb_Prelookup4_o2_bb,
        &claw_main_DWork.Prelookup4_DWORK1_h);

      /* Interpolation_n-D: '<S590>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S590>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_n0;
      frac_1m[0] = max_1;
      max_1 = rtb_Prelookup2_o2_mr;
      frac_1m[1] = max_1;
      max_1 = rtb_Prelookup3_o2_m;
      frac_1m[2] = max_1;
      max_1 = rtb_Prelookup4_o2_bb;
      frac_1m[3] = max_1;
      bpIndex_1m[0] = rtb_Prelookup1_o1_if;
      bpIndex_1m[1] = rtb_Prelookup2_o1_pm;
      bpIndex_1m[2] = rtb_Prelookup3_o1_lh;
      bpIndex_1m[3] = rtb_Prelookup4_o1_di;
      locIndex = claw_main_P.Constant2_Value_mh1[0];
      if (claw_main_P.Constant2_Value_mh1[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1m[4] = locIndex;
      locIndex = 20736U * bpIndex_1m[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1m[0U], &frac_1m[0U],
        &claw_main_P.InterpolationUsingPrelookup__jv[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__at[0]);
      locIndex = claw_main_P.Constant2_Value_mh1[1];
      if (claw_main_P.Constant2_Value_mh1[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1m[4] = locIndex;
      locIndex = 20736U * bpIndex_1m[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1m[0U], &frac_1m[0U],
        &claw_main_P.InterpolationUsingPrelookup__jv[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__at[0]);
      locIndex = claw_main_P.Constant2_Value_mh1[2];
      if (claw_main_P.Constant2_Value_mh1[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1m[4] = locIndex;
      locIndex = 20736U * bpIndex_1m[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1m[0U], &frac_1m[0U],
        &claw_main_P.InterpolationUsingPrelookup__jv[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__at[0]);

      /* Assignment: '<S590>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S590>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_o[i] = claw_main_P.Constant_Value_pz[i];
        }
      }

      rtb_AssignmenttoLongitudinal_o[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_o[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_o[4] = rtb_Switch2_idx;

      /* Gain: '<S586>/Gain' incorporates:
       *  Gain: '<S577>/Gain3'
       *  Sum: '<S577>/Add3'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_o[i] -
                    rtb_AssignmenttoLongitudinal_n[i]) *
          claw_main_P.Gain3_Gain_g;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_oi[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_oi[i] += claw_main_P.Gain_Gain_lj[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }

        /* Gain: '<S578>/Gain' */
        rtb_Gain_nr[i] = claw_main_P.Gain_Gain_bj[i] * rtb_Sum_ow_idx;

        /* Gain: '<S578>/Gain1' */
        rtb_Gain1_ic[i] = claw_main_P.Gain1_Gain_dn[i] * rtb_Switch_d_idx;

        /* Gain: '<S578>/Gain2' */
        rtb_Gain2_eg[i] = claw_main_P.Gain2_Gain_j[i] * rtb_Sum_ow_idx_0;

        /* Gain: '<S578>/Gain3' */
        rtb_Gain3_jm[i] = claw_main_P.Gain3_Gain_o3[i] * rtb_Sum_ow_idx_1;
      }

      /* S-Function (sfun_idxsearch): '<S579>/PreLookup Index Search1' */
      scalarPrevIndex_2 = claw_main_DWork.PreLookupIndexSearch1_MODE_f;
      i = plook_s32dd_binxp(claw_main_B.alpha_c,
                            &claw_main_P.PreLookupIndexSearch1_bpData_b[0], 31U,
                            &scalarFraction_5, &scalarPrevIndex_2);
      rtb_delta_LLh_idx = scalarFraction_5;

      /* S-Function (sfun_kflookupnd): '<S579>/TableLookup' incorporates:
       *  Constant: '<S579>/Constant2'
       *  DataTypeConversion: '<S579>/Data Type Conversion2'
       *  RelationalOperator: '<S592>/Compare'
       */
      if (i > 30) {
        max_1 = 30.0;
      } else if (i >= 0) {
        max_1 = (real_T)i;
      } else {
        max_1 = 0.0;
      }

      i = (int32_T)max_1;
      yOffset_0 = (rtb_Sum_h_idx != 0.0);
      if (claw_main_P.Constant2_Value_ob[0] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_ob[0];
      }

      rtb_delta_LLh_idx_0 = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData_f[(scalarIndex << 6U) + (yOffset_0 <<
        5)]);
      if (claw_main_P.Constant2_Value_ob[1] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_ob[1];
      }

      rtb_Switch2_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData_f[(scalarIndex << 6U) + (yOffset_0 <<
        5)]);
      if (claw_main_P.Constant2_Value_ob[2] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_ob[2];
      }

      rtb_delta_LLh_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData_f[(scalarIndex << 6U) + (yOffset_0 <<
        5)]);

      /* Assignment: '<S579>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S579>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_d[i] = claw_main_P.Constant_Value_fx[i];
        }
      }

      rtb_AssignmenttoLongitudinal_d[0] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_d[2] = rtb_Switch2_idx;
      rtb_AssignmenttoLongitudinal_d[4] = rtb_delta_LLh_idx;
      claw_main_ImplementDamageModels(rtb_Product_hs, rtb_Product_b2,
        rtb_NegateLateral_d, rtb_InterpolationUsingPreloo_nc, rtb_Product_ij,
        rtb_Product_nh, rtb_Product_eb, rtb_Product_nz,
        rtb_AssignmenttoLongitudinal_n, rtb_Gain_f4, rtb_Gain_kl, rtb_Gain_fa,
        rtb_Gain_oi, rtb_Gain_nr, rtb_Gain1_ic, rtb_Gain2_eg, rtb_Gain3_jm,
        rtb_AssignmenttoLongitudinal_d, rtb_FromWorkspace_o,
        &claw_main_B.sf_ImplementDamageModels_lh);

      /* Reshape: '<S580>/Reshape' */
      for (i = 0; i < 6; i++) {
        rtb_Reshape_iq[i] = claw_main_B.sf_ImplementDamageModels_lh.dC6[i];
      }

      /* Math: '<S627>/Math Function1' */
      rtb_MathFunction1_if = rt_hypot_snf(rtb_MathFunction_k, rtb_Gain1_idx_0);

      /* MinMax: '<S554>/MinMax' incorporates:
       *  Constant: '<S554>/Constant'
       */
      max_1 = rt_MAXd_snf(claw_main_P.Constant_Value_lj, rtb_MathFunction1_if);

      /* Gain: '<S551>/Gain5' */
      rtb_tas_b = claw_main_P.Gain5_Gain_e * max_1;

      /* DataTypeConversion: '<S570>/Data Type Conversion' */
      rtb_delta_LLh_idx = rtb_FromWorkspace_o;
      if ((rtb_FromWorkspace_o < 4.5035996273704960E+015) &&
          (rtb_FromWorkspace_o > -4.5035996273704960E+015)) {
        rtb_delta_LLh_idx = floor(rtb_FromWorkspace_o + 0.5);
      }

      if (rtIsNaN(rtb_FromWorkspace_o) || rtIsInf(rtb_FromWorkspace_o)) {
        rtb_delta_LLh_idx = 0.0;
      } else {
        rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
      }

      rtb_DataTypeConversion_h = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
        (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

      /* SwitchCase: '<S570>/Switch Case' incorporates:
       *  ActionPort: '<S604>/Action Port'
       *  ActionPort: '<S605>/Action Port'
       *  SubSystem: '<S570>/Forced Oscillation with Damage Increments'
       *  SubSystem: '<S570>/Rotary Blended  UnDamaged Case'
       */
      switch (rtb_DataTypeConversion_h) {
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
       case 6:
        ForcedOscillationwithDamageIncr(claw_main_B.alpha_c,
          rtb_DataTypeConversion_h, rtb_tas_b, rtb_Assignment2_b,
          claw_main_P.B_Value_k, claw_main_P.Cbar_Value_i, claw_main_B.Merge_di,
          &claw_main_B.ForcedOscillationwithDamageIn_l,
          &claw_main_DWork.ForcedOscillationwithDamageIn_l,
          (rtP_ForcedOscillationwithDamage *)
          &claw_main_P.ForcedOscillationwithDamageIn_l,
          &claw_main_DWork.WhileIterator_IterationMarker[0]);
        break;

       default:
        claw_RotaryBlendedUnDamagedCase(claw_main_B.alpha_c, rtb_tas_b,
          claw_main_B.beta_n, rtb_Assignment2_b, claw_main_P.B_Value_k,
          claw_main_P.Cbar_Value_i, claw_main_B.Merge_di,
          &claw_main_B.RotaryBlendedUnDamagedCase_f,
          &claw_main_DWork.RotaryBlendedUnDamagedCase_f,
          (rtP_RotaryBlendedUnDamagedCase_ *)
          &claw_main_P.RotaryBlendedUnDamagedCase_f,
          &claw_main_DWork.WhileIterator_IterationMarker[0]);
        break;
      }

      /* Fcn: '<S554>/wind_qbar' */
      if ((max_1 < 0.0) && (2.0 > floor(2.0))) {
        rtb_MultiportSwitch2_idx_2 = -rt_pow_snf(-max_1, 2.0);
      } else {
        rtb_MultiportSwitch2_idx_2 = rt_pow_snf(max_1, 2.0);
      }

      /* Product: '<S554>/Product1' */
      rtb_qbar_m = 0.5 * rtb_MultiportSwitch2_idx_2 * rtb_Product_b;

      /* Gain: '<S568>/Gain2' incorporates:
       *  Product: '<S568>/Product'
       *  Sum: '<S550>/Sum8'
       */
      for (i = 0; i < 6; i++) {
        rtb_Gain2_ij[i] = ((rtb_Add_g[i] + rtb_Reshape_iq[i]) +
                           claw_main_B.Merge_di[i]) * rtb_qbar_m *
          claw_main_P.Gain2_Gain_b;
      }

      /* Sum: '<S568>/Sum' incorporates:
       *  Constant: '<S549>/xCG1'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_k[0] - rtb_Add2_idx_0;

      /* Gain: '<S575>/Gain' */
      rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_o5 * rtb_Switch2_idx;
      rtb_Gain1_idx_1 = rtb_Switch2_idx;

      /* Sum: '<S568>/Sum' incorporates:
       *  Constant: '<S549>/xCG1'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_k[1] - rtb_Add2_idx_1;

      /* Gain: '<S575>/Gain' */
      rtb_delta_LLh_idx = claw_main_P.Gain_Gain_o5 * rtb_Switch2_idx;
      rtb_delta_LLh_idx_0 = rtb_Switch2_idx;

      /* Sum: '<S568>/Sum' incorporates:
       *  Constant: '<S549>/xCG1'
       *  Reshape: '<S555>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_k[2] - rtb_Add2_idx;

      /* Sum: '<S543>/Sum' incorporates:
       *  Gain: '<S568>/Reference Lengths'
       *  Gain: '<S575>/Gain'
       *  Product: '<S575>/Product'
       *  Reshape: '<S575>/Reshape'
       *  Reshape: '<S575>/Reshape1'
       *  Sum: '<S552>/Sum'
       *  Sum: '<S568>/Sum1'
       */
      min_6[0] = claw_main_B.sf_EngineAlignment_g.T[0];
      min_6[1] = claw_main_B.sf_EngineAlignment_g.T[1];
      min_6[2] = claw_main_B.sf_EngineAlignment_g.T[2];
      min_6[3] = (rtb_dircos_0[0] + rtb_Gain_e_0[0]) + rtb_Product_dr[0];
      min_6[4] = (rtb_dircos_0[1] + rtb_Gain_e_0[1]) + rtb_Product_dr[1];
      min_6[5] = (rtb_dircos_0[2] + rtb_Gain_e_0[2]) + rtb_Product_dr[2];
      rtb_Gain1_oy_0[0] = 0.0;
      rtb_Gain1_oy_0[1] = rtb_Switch2_idx;
      rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
      rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_o5 * rtb_Switch2_idx;
      rtb_Gain1_oy_0[4] = 0.0;
      rtb_Gain1_oy_0[5] = rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[6] = rtb_delta_LLh_idx_0;
      rtb_Gain1_oy_0[7] = rtb_Gain1_idx_0;
      rtb_Gain1_oy_0[8] = 0.0;
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Gain2_ij[0];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Gain2_ij[1];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Gain2_ij[2];
      }

      rtb_Gain2_n_0[0] = rtb_Gain2_ij[0];
      rtb_Gain2_n_0[1] = rtb_Gain2_ij[1];
      rtb_Gain2_n_0[2] = rtb_Gain2_ij[2];
      rtb_Gain2_n_0[3] = claw_main_P.ReferenceLengths_Gain_j[0] * rtb_Gain2_ij[3]
        + rtb_dircos_0[0];
      rtb_Gain2_n_0[4] = claw_main_P.ReferenceLengths_Gain_j[1] * rtb_Gain2_ij[4]
        + rtb_dircos_0[1];
      rtb_Gain2_n_0[5] = claw_main_P.ReferenceLengths_Gain_j[2] * rtb_Gain2_ij[5]
        + rtb_dircos_0[2];
      for (i = 0; i < 6; i++) {
        rtb_Sum_ap[i] = min_6[i] + rtb_Gain2_n_0[i];
      }

      /* Product: '<S533>/Product' incorporates:
       *  Gain: '<S536>/Gain'
       *  Math: '<S536>/Math Function'
       *  Product: '<S536>/Product'
       *  Product: '<S542>/Force -> Acceleration'
       *  Product: '<S546>/Product'
       *  Product: '<S546>/Product1'
       *  Reshape: '<S536>/Reshape'
       *  Reshape: '<S540>/Reshape1'
       *  Sum: '<S533>/Sum1'
       *  Sum: '<S540>/Sum'
       *  Sum: '<S542>/Sum'
       *  Sum: '<S546>/Sum'
       */
      rtb_Gain1_oy_0[0] = rtb_Gain1_pd[1];
      rtb_Gain1_oy_0[1] = rtb_Gain_g_idx_2;
      rtb_Gain1_oy_0[2] = rtb_Gain_g_idx_0;
      rtb_Gain1_oy_0[3] = rtb_Gain_g_idx;
      rtb_Gain1_oy_0[4] = rtb_Gain1_pd[2];
      rtb_Gain1_oy_0[5] = rtb_Gain_g_idx_4;
      rtb_Gain1_oy_0[6] = rtb_Gain_g_idx_3;
      rtb_Gain1_oy_0[7] = rtb_Gain_g_idx_1;
      rtb_Gain1_oy_0[8] = rtb_Gain1_pd[3];
      rtb_delta_LLh_idx = 1.0 / claw_main_B.mass;
      rtb_Switch2_idx = (rtb_Product1_b_idx + rtb_Sum_ap[0]) * rtb_delta_LLh_idx
        - (rtb_Assignment2_b[1] * rtb_Assignment2_b[5] - rtb_Assignment2_b[2] *
           rtb_Assignment2_b[4]);
      rtb_delta_LLh_idx_0 = (rtb_Product1_b_idx_0 + rtb_Sum_ap[1]) *
        rtb_delta_LLh_idx - (rtb_Assignment2_b[2] * rtb_Assignment2_b[3] -
        rtb_Assignment2_b[0] * rtb_Assignment2_b[5]);
      rtb_delta_LLh_idx = (rtb_Product1_b_idx_1 + rtb_Sum_ap[2]) *
        rtb_delta_LLh_idx - (rtb_Assignment2_b[0] * rtb_Assignment2_b[4] -
        rtb_Assignment2_b[1] * rtb_Assignment2_b[3]);
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i] * rtb_Switch2_idx;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 1] * rtb_delta_LLh_idx_0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 2] * rtb_delta_LLh_idx;
      }

      /* Assignment: '<S533>/Assignment' incorporates:
       *  Reshape: '<S533>/Reshape'
       */
      if (scalarIndex_0 == 1) {
        memcpy((void *)&rtb_Assignment_m[0], (void *)&rtb_Memory1_m[0], 9U *
               (uint32_T)((char_T *)&rtb_Memory1_m[1U] - (char_T *)
                          &rtb_Memory1_m[0U]));
      }

      i = ((int32_T)rtb_MultiportSwitch_p - 1) * 3;
      rtb_Assignment_m[i] = (claw_main_P.Gain_Gain_mj[0] * rtb_dircos_0[0] -
        rtb_Gain_kp_idx_0) / rtb_Selector4;
      rtb_Assignment_m[i + 1] = (claw_main_P.Gain_Gain_mj[1] * rtb_dircos_0[1] -
        rtb_Gain_kp_idx_1) / rtb_Selector4;
      rtb_Assignment_m[i + 2] = (claw_main_P.Gain_Gain_mj[2] * rtb_dircos_0[2] -
        rtb_Gain_kp_idx) / rtb_Selector4;

      /* Switch: '<S533>/Switch' incorporates:
       *  Constant: '<S533>/Constant1'
       */
      if (rtb_columncounter >= claw_main_P.Switch_Threshold_ou) {
        rtb_Switch_ej = claw_main_P.Constant1_Value_f;
      } else {
        rtb_Switch_ej = rtb_columncounter;
      }

      /* Product: '<S540>/Product2' */
      rtb_accels_cg_c[0] = rtb_Sum_ap[0] / claw_main_B.mass;
      rtb_accels_cg_c[1] = rtb_Sum_ap[1] / claw_main_B.mass;
      rtb_accels_cg_c[2] = rtb_Sum_ap[2] / claw_main_B.mass;
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_dircos_m[3 * i] * rtb_Assignment2_b[3];
        rtb_dircos_0[i] += rtb_dircos_m[3 * i + 1] * rtb_Assignment2_b[4];
        rtb_dircos_0[i] += rtb_dircos_m[3 * i + 2] * rtb_Assignment2_b[5];
        rtb_NEhdot_f[i] = claw_main_P.MatrixGain_Gain_l[i] * rtb_dircos_0[i];

        /* Product: '<S542>/Product2' */
        rtb_Product2_o[i] = 0.0;
        rtb_Product2_o[i] += rtb_inertia[i] * rtb_Assignment2_b[0];
        rtb_Product2_o[i] += rtb_inertia[i + 3] * rtb_Assignment2_b[1];
        rtb_Product2_o[i] += rtb_inertia[i + 6] * rtb_Assignment2_b[2];
      }

      /* Product: '<S542>/Product3' incorporates:
       *  Product: '<S545>/Product'
       *  Product: '<S545>/Product1'
       *  Product: '<S547>/Product'
       *  Product: '<S547>/Product1'
       *  Sum: '<S542>/Sum1'
       *  Sum: '<S545>/Sum'
       *  Sum: '<S547>/Sum'
       */
      rtb_delta_LLh_idx = (rtb_Sum_ap[3] - (rtb_Assignment2_b[1] * 0.0 -
        rtb_Assignment2_b[2] * 0.0)) - (rtb_Assignment2_b[1] * rtb_Product2_o[2]
        - rtb_Assignment2_b[2] * rtb_Product2_o[1]);
      rtb_delta_LLh_idx_0 = (rtb_Sum_ap[4] - (rtb_Assignment2_b[2] * 0.0 -
        rtb_Assignment2_b[0] * 0.0)) - (rtb_Assignment2_b[2] * rtb_Product2_o[0]
        - rtb_Assignment2_b[0] * rtb_Product2_o[2]);
      rtb_Switch2_idx = (rtb_Sum_ap[5] - (rtb_Assignment2_b[0] * 0.0 -
        rtb_Assignment2_b[1] * 0.0)) - (rtb_Assignment2_b[0] * rtb_Product2_o[1]
        - rtb_Assignment2_b[1] * rtb_Product2_o[0]);
      for (i = 0; i < 3; i++) {
        rtb_pqrdot_g[i] = 0.0;
        rtb_pqrdot_g[i] += rtb_inertia_inv[i] * rtb_delta_LLh_idx;
        rtb_pqrdot_g[i] += rtb_inertia_inv[i + 3] * rtb_delta_LLh_idx_0;
        rtb_pqrdot_g[i] += rtb_inertia_inv[i + 6] * rtb_Switch2_idx;
      }

      /* Reshape: '<S548>/Reshape' incorporates:
       *  Gain: '<S548>/Gain1'
       */
      rtb_MatrixConcatenation_n[0] = claw_main_P.Gain1_Gain_bf[0] *
        rtb_Assignment2_b[10];
      rtb_MatrixConcatenation_n[1] = claw_main_P.Gain1_Gain_bf[1] *
        rtb_Assignment2_b[9];
      rtb_MatrixConcatenation_n[2] = claw_main_P.Gain1_Gain_bf[2] *
        rtb_Assignment2_b[12];
      rtb_MatrixConcatenation_n[3] = claw_main_P.Gain1_Gain_bf[3] *
        rtb_Assignment2_b[11];

      /* Reshape: '<S548>/Reshape1' incorporates:
       *  Gain: '<S548>/Gain2'
       */
      rtb_MatrixConcatenation_n[4] = claw_main_P.Gain2_Gain_dd[0] *
        rtb_Assignment2_b[11];
      rtb_MatrixConcatenation_n[5] = claw_main_P.Gain2_Gain_dd[1] *
        rtb_Assignment2_b[12];
      rtb_MatrixConcatenation_n[6] = claw_main_P.Gain2_Gain_dd[2] *
        rtb_Assignment2_b[9];
      rtb_MatrixConcatenation_n[7] = claw_main_P.Gain2_Gain_dd[3] *
        rtb_Assignment2_b[10];

      /* Reshape: '<S548>/Reshape2' incorporates:
       *  Gain: '<S548>/Gain3'
       */
      rtb_MatrixConcatenation_n[8] = claw_main_P.Gain3_Gain_p[0] *
        rtb_Assignment2_b[12];
      rtb_MatrixConcatenation_n[9] = claw_main_P.Gain3_Gain_p[1] *
        rtb_Assignment2_b[11];
      rtb_MatrixConcatenation_n[10] = claw_main_P.Gain3_Gain_p[2] *
        rtb_Assignment2_b[10];
      rtb_MatrixConcatenation_n[11] = claw_main_P.Gain3_Gain_p[3] *
        rtb_Assignment2_b[9];

      /* Gain: '<S544>/Gain4' incorporates:
       *  Product: '<S544>/Product'
       */
      for (i = 0; i < 4; i++) {
        rtb_MatrixConcatenation_j_0[i] = 0.0;
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_n[i] *
          rtb_Assignment2_b[0];
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_n[i + 4] *
          rtb_Assignment2_b[1];
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_n[i + 8] *
          rtb_Assignment2_b[2];
      }

      rtb_Gain4_am[0] = claw_main_P.Gain4_Gain_n * rtb_MatrixConcatenation_j_0[0];
      rtb_Gain4_am[1] = claw_main_P.Gain4_Gain_n * rtb_MatrixConcatenation_j_0[1];
      rtb_Gain4_am[2] = claw_main_P.Gain4_Gain_n * rtb_MatrixConcatenation_j_0[2];
      rtb_Gain4_am[3] = claw_main_P.Gain4_Gain_n * rtb_MatrixConcatenation_j_0[3];

      /* Selector: '<S557>/Value(ndx,:)' incorporates:
       *  Constant: '<S557>/Gain1'
       */
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
        rtb_Valuendx_pi[yOffset] = claw_main_P.Gain1_Value_n[7 * uDimIdx +
          (int32_T)rtb_FromWorkspace_o];
        yOffset++;
      }

      /* Switch: '<S555>/Switch' incorporates:
       *  Constant: '<S555>/xCG3'
       *  Constant: '<S555>/xCG5'
       */
      for (i = 0; i < 6; i++) {
        if (rtb_Sum_h_idx >= claw_main_P.Switch_Threshold_b) {
          rtb_Switch_ke[i] = claw_main_P.xCG3_Value_k[i];
        } else {
          rtb_Switch_ke[i] = claw_main_P.xCG5_Value_f[i];
        }
      }

      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_c,
        &claw_main_B.sf_EmbeddedMATLABFunction_p,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_p);
      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_c,
        &claw_main_B.sf_EmbeddedMATLABFunction_f5,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_f5);
      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_c,
        &claw_main_B.sf_EmbeddedMATLABFunction_dz,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_dz);

      /* Gain: '<S555>/Gain' */
      rtb_Gain_mq = claw_main_P.Gain_Gain_gb * rtb_gwest_c;

      /* Reshape: '<S555>/Reshape1' incorporates:
       *  Constant: '<S555>/ixxb3'
       *  Constant: '<S558>/xCG6'
       *  Sum: '<S555>/Add1'
       */
      rtb_Reshape1_l[0] = ((rtb_Switch_ke[0] +
                            claw_main_B.sf_EmbeddedMATLABFunction_p.y) +
                           rtb_Valuendx_pi[0]) + claw_main_P.ixxb3_Value_p[0];
      rtb_Reshape1_l[1] = ((rtb_Switch_ke[1] +
                            claw_main_B.sf_EmbeddedMATLABFunction_f5.y) +
                           rtb_Valuendx_pi[1]) + claw_main_P.ixxb3_Value_p[1];
      rtb_Reshape1_l[2] = ((rtb_Switch_ke[2] +
                            claw_main_B.sf_EmbeddedMATLABFunction_dz.y) +
                           rtb_Valuendx_pi[2]) + claw_main_P.ixxb3_Value_p[2];
      rtb_Reshape1_l[3] = ((rtb_Switch_ke[3] + claw_main_P.xCG6_Value_i[0]) +
                           rtb_Valuendx_pi[3]) + claw_main_P.ixxb3_Value_p[3];
      rtb_Reshape1_l[4] = ((rtb_Switch_ke[4] + claw_main_P.xCG6_Value_i[1]) +
                           rtb_Valuendx_pi[4]) + claw_main_P.ixxb3_Value_p[4];
      rtb_Reshape1_l[5] = ((rtb_Switch_ke[5] + claw_main_P.xCG6_Value_i[2]) +
                           rtb_Valuendx_pi[5]) + claw_main_P.ixxb3_Value_p[5];

      /* Constant: '<S549>/S' */
      rtb_S_c = claw_main_P.S_Value_k;

      /* Gain: '<S551>/Gain' */
      rtb_tratio_n = claw_main_P.Gain_Gain_j * rtb_u20_p;

      /* Constant: '<S552>/Constant1' */
      rtb_Constant1_o = claw_main_P.Constant1_Value_m3;

      /* Switch: '<S618>/SwitchControl' incorporates:
       *  Constant: '<S552>/zero1'
       *  Constant: '<S618>/Constant'
       *  Sum: '<S552>/Add'
       */
      if (claw_main_P.Constant_Value_jg3 > claw_main_P.SwitchControl_Threshold_k)
      {
        rtb_SwitchControl_k = rtb_LengON_o[5] + rtb_RengON_d[5];
      } else {
        rtb_SwitchControl_k = claw_main_P.zero1_Value_e;
      }

      /* Gain: '<S552>/sec_per_min' */
      rtb_sec_per_min_h = claw_main_P.sec_per_min_Gain_l * rtb_SwitchControl_k;

      /* Product: '<S554>/Product2' */
      rtb_Mach_n = max_1 / rtb_sos;

      /* Update for Memory: '<S533>/Memory' */
      claw_main_DWork.Memory_PreviousInput_g = rtb_Switch_ej;

      /* Update for Memory: '<S533>/Memory1' */
      memcpy((void *)(&claw_main_DWork.Memory1_PreviousInput_k[0]), (void *)
             &rtb_Assignment_m[0], 9U * (uint32_T)((char_T *)&rtb_Assignment_m
              [1U] - (char_T *)&rtb_Assignment_m[0U]));
      scalarIndex_0++;
    } while ((claw_main_P.Constant2_Value_c != 0.0) && (scalarIndex_0 <= 3));

    /* end of Outputs for SubSystem: '<S522>/B matrix comp' */

    /* Outputs for atomic SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* MinMax: '<S526>/MinMax' */
    max_1 = rt_MAXd_snf(claw_main_B.Merge2[0], claw_main_B.Merge2[1]);
    max_1 = rt_MAXd_snf(max_1, claw_main_B.Merge2[2]);

    /* SwitchCase: '<S526>/Switch Case' incorporates:
     *  ActionPort: '<S763>/Action Port'
     *  ActionPort: '<S764>/Action Port'
     *  SubSystem: '<S526>/NED_dd cmd'
     *  SubSystem: '<S526>/vchigam_dot cmd'
     */
    switch ((int32_T)max_1) {
     case 1:
      /* Inport: '<S763>/NEH_dd_cmd_in' */
      claw_main_B.Merge_cz[0] = claw_main_B.Merge1[0];
      claw_main_B.Merge_cz[1] = claw_main_B.Merge1[1];
      claw_main_B.Merge_cz[2] = claw_main_B.Merge1[2];
      break;

     case 2:
      /* Gain: '<S764>/convert to NED_d' */
      rtb_delta_LLh_idx = claw_main_P.converttoNED_d_Gain[0] * rtb_Gain_idx;
      rtb_delta_LLh_idx_0 = claw_main_P.converttoNED_d_Gain[1] * rtb_Gain_idx_0;
      rtb_Switch2_idx = claw_main_P.converttoNED_d_Gain[2] * rtb_Gain_idx_1;

      /* Math: '<S766>/Math Function' */
      rtb_Rground_k = rt_hypot_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

      /* Trigonometry: '<S766>/Trigonometric Function1' incorporates:
       *  Gain: '<S766>/Gain'
       */
      rtb_elevation_g = rt_atan2_snf(claw_main_P.Gain_Gain_lt * rtb_Switch2_idx,
        rtb_Rground_k);

      /* Trigonometry: '<S767>/Trigonometric Function3' */
      rtb_TrigonometricFunction3_a = cos(rtb_elevation_g);

      /* Trigonometry: '<S766>/Trigonometric Function' */
      rtb_azimuth_b = rt_atan2_snf(rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

      /* Trigonometry: '<S767>/Trigonometric Function5' */
      rtb_TrigonometricFunction5_os = cos(rtb_azimuth_b);

      /* Trigonometry: '<S767>/Trigonometric Function2' */
      rtb_TrigonometricFunction2_k = sin(rtb_elevation_g);

      /* Trigonometry: '<S767>/Trigonometric Function' incorporates:
       *  Constant: '<S766>/Constant'
       */
      rtb_TrigonometricFunction_av = sin(claw_main_P.Constant_Value_dr);

      /* Product: '<S767>/Product9' */
      rtb_Product9_n = rtb_TrigonometricFunction5_os *
        rtb_TrigonometricFunction_av;

      /* Trigonometry: '<S767>/Trigonometric Function4' */
      rtb_TrigonometricFunction4_f = sin(rtb_azimuth_b);

      /* Trigonometry: '<S767>/Trigonometric Function1' incorporates:
       *  Constant: '<S766>/Constant'
       */
      rtb_TrigonometricFunction1_ch = cos(claw_main_P.Constant_Value_dr);

      /* Product: '<S767>/Product2' */
      rtb_Product2_ajh = rtb_TrigonometricFunction4_f *
        rtb_TrigonometricFunction1_ch;

      /* Product: '<S767>/Product7' */
      rtb_Product7_hd = rtb_TrigonometricFunction5_os *
        rtb_TrigonometricFunction1_ch;

      /* Product: '<S767>/Product4' */
      rtb_Product4_fk = rtb_TrigonometricFunction4_f *
        rtb_TrigonometricFunction_av;

      /* Gain: '<S764>/convert to NEh_dd' incorporates:
       *  Gain: '<S765>/Gain1'
       *  Gain: '<S767>/Gain'
       *  Math: '<S764>/Math Function'
       *  Math: '<S766>/Math Function1'
       *  Product: '<S764>/Product2'
       *  Product: '<S765>/Product3'
       *  Product: '<S767>/Product'
       *  Product: '<S767>/Product1'
       *  Product: '<S767>/Product10'
       *  Product: '<S767>/Product11'
       *  Product: '<S767>/Product3'
       *  Product: '<S767>/Product5'
       *  Product: '<S767>/Product6'
       *  Product: '<S767>/Product8'
       *  Reshape: '<S764>/Reshape1'
       *  SignalConversion: '<S764>/TmpHiddenBufferAtProduct2Inport2'
       *  Sum: '<S767>/Sum'
       *  Sum: '<S767>/Sum1'
       *  Sum: '<S767>/Sum2'
       *  Sum: '<S767>/Sum3'
       */
      rtb_Gain1_oy_0[0] = rtb_TrigonometricFunction3_a *
        rtb_TrigonometricFunction5_os;
      rtb_Gain1_oy_0[1] = rtb_TrigonometricFunction2_k * rtb_Product9_n -
        rtb_Product2_ajh;
      rtb_Gain1_oy_0[2] = rtb_TrigonometricFunction2_k * rtb_Product7_hd +
        rtb_Product4_fk;
      rtb_Gain1_oy_0[3] = rtb_TrigonometricFunction3_a *
        rtb_TrigonometricFunction4_f;
      rtb_Gain1_oy_0[4] = rtb_TrigonometricFunction2_k * rtb_Product4_fk +
        rtb_Product7_hd;
      rtb_Gain1_oy_0[5] = rtb_TrigonometricFunction2_k * rtb_Product2_ajh -
        rtb_Product9_n;
      rtb_Gain1_oy_0[6] = claw_main_P.Gain_Gain_bn *
        rtb_TrigonometricFunction2_k;
      rtb_Gain1_oy_0[7] = rtb_TrigonometricFunction3_a *
        rtb_TrigonometricFunction_av;
      rtb_Gain1_oy_0[8] = rtb_TrigonometricFunction3_a *
        rtb_TrigonometricFunction1_ch;
      rtb_delta_LLh_idx_0 = claw_main_P.Gain1_Gain_a[0] * rtb_Rground_k *
        claw_main_B.Merge1[1];
      rtb_delta_LLh_idx = claw_main_P.Gain1_Gain_a[1] * rt_hypot_snf
        (rtb_Rground_k, rtb_Switch2_idx) * claw_main_B.Merge1[2];
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i] * claw_main_B.Merge1[0];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 1] * rtb_delta_LLh_idx_0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[3 * i + 2] * rtb_delta_LLh_idx;
      }

      claw_main_B.Merge_cz[0] = claw_main_P.converttoNEh_dd_Gain[0] *
        rtb_dircos_0[0];
      claw_main_B.Merge_cz[1] = claw_main_P.converttoNEh_dd_Gain[1] *
        rtb_dircos_0[1];
      claw_main_B.Merge_cz[2] = claw_main_P.converttoNEh_dd_Gain[2] *
        rtb_dircos_0[2];
      break;
    }

    /* end of Outputs for SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* FromWorkspace: '<S94>/From Workspace1' */
    {
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace1_PWORK_i.DataPtr;
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace1_PWORK_i.TimePtr;
      int_T currTimeIndex = claw_main_DWork.FromWorkspace1_IWORK_f.PrevIndex;
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      if (t >= pTimeValues[1]) {
        rtb_FromWorkspace1_o[0] = pDataValues[1];
        pDataValues += 2;
        rtb_FromWorkspace1_o[1] = pDataValues[1];
        pDataValues += 2;
        rtb_FromWorkspace1_o[2] = pDataValues[1];
        pDataValues += 2;
      } else {
        /* get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[1]) {
          currTimeIndex = 0;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        claw_main_DWork.FromWorkspace1_IWORK_f.PrevIndex = currTimeIndex;

        /* post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              rtb_FromWorkspace1_o[0] = pDataValues[currTimeIndex];
              pDataValues += 2;
              rtb_FromWorkspace1_o[1] = pDataValues[currTimeIndex];
              pDataValues += 2;
              rtb_FromWorkspace1_o[2] = pDataValues[currTimeIndex];
              pDataValues += 2;
            } else {
              rtb_FromWorkspace1_o[0] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
              rtb_FromWorkspace1_o[1] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
              rtb_FromWorkspace1_o[2] = pDataValues[currTimeIndex + 1];
              pDataValues += 2;
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex= currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace1_o[0] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace1_o[1] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace1_o[2] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
          }
        }
      }
    }

    /* Switch: '<S94>/Switch1' incorporates:
     *  Constant: '<S94>/Constant'
     */
    if (claw_main_P.Constant_Value_ki >= claw_main_P.Switch1_Threshold_n4) {
      /* Switch: '<S94>/Switch3' */
      if (rtb_Compare_df) {
        /* S-Function (sfun_kflookupnd): '<S123>/Interpolation (n-D) using PreLookup for acc' incorporates:
         *  Constant: '<S123>/Constant2'
         */
        if (claw_main_P.Constant2_Value_bzj[0] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_bzj[0] >= 0) {
          yOffset = claw_main_P.Constant2_Value_bzj[0];
        } else {
          yOffset = 0;
        }

        rtb_MultiportSwitch2_idx_2 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_h[yOffset << 1U]);
        if (claw_main_P.Constant2_Value_bzj[1] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_bzj[1] >= 0) {
          yOffset = claw_main_P.Constant2_Value_bzj[1];
        } else {
          yOffset = 0;
        }

        rtb_UnitDelay_nf_idx = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_h[yOffset << 1U]);
        if (claw_main_P.Constant2_Value_bzj[2] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_bzj[2] >= 0) {
          yOffset = claw_main_P.Constant2_Value_bzj[2];
        } else {
          yOffset = 0;
        }

        rtb_UnitDelay_nf_idx_0 = intrp1d_lx(0U, rtb_eow_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookup_h[yOffset << 1U]);
      } else {
        /* S-Function (sfun_kflookupnd): '<S124>/Interpolation (n-D) using PreLookup for acc' incorporates:
         *  Constant: '<S124>/Constant2'
         */
        if (claw_main_P.Constant2_Value_lt[0] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_lt[0] >= 0) {
          yOffset = claw_main_P.Constant2_Value_lt[0];
        } else {
          yOffset = 0;
        }

        rtb_MultiportSwitch2_idx_2 = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookupfo[yOffset << 1U]);
        if (claw_main_P.Constant2_Value_lt[1] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_lt[1] >= 0) {
          yOffset = claw_main_P.Constant2_Value_lt[1];
        } else {
          yOffset = 0;
        }

        rtb_UnitDelay_nf_idx = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookupfo[yOffset << 1U]);
        if (claw_main_P.Constant2_Value_lt[2] > 2) {
          yOffset = 2;
        } else if (claw_main_P.Constant2_Value_lt[2] >= 0) {
          yOffset = claw_main_P.Constant2_Value_lt[2];
        } else {
          yOffset = 0;
        }

        rtb_UnitDelay_nf_idx_0 = intrp1d_lx(0U, rtb_X_idx_idx,
          &claw_main_P.InterpolationnDusingPreLookupfo[yOffset << 1U]);
      }
    } else {
      rtb_MultiportSwitch2_idx_2 = rtb_FromWorkspace1_o[0];
      rtb_UnitDelay_nf_idx = rtb_FromWorkspace1_o[1];
      rtb_UnitDelay_nf_idx_0 = rtb_FromWorkspace1_o[2];
    }

    min[0] = rtb_Reshape_n[49];
    if (min[0] < 0.0) {
      rtb_eow_idx_idx = -sqrt(-min[0]);
    } else {
      rtb_eow_idx_idx = sqrt(min[0]);
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_hxr -
      claw_main_P.Gain_Gain_jc * rtb_Reshape_n[49];

    /* Math: '<S184>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain1'
     *  Sum: '<S184>/Sum1'
     */
    if (!(rtb_Reshape_n[49] >= claw_main_P.Switch_Threshold_ll)) {
      rtb_eow_idx_idx = (rtb_delta_LLh_idx + claw_main_P.Constant_Value_hxr) *
        claw_main_P.Gain1_Gain_dx;
    }

    /* Switch: '<S184>/Switch1' incorporates:
     *  Constant: '<S184>/Constant3'
     */
    if (rtb_Reshape_n[46] >= claw_main_P.Switch1_Threshold_b) {
      rtb_Gain1_idx_1 = claw_main_P.Constant3_Value_m;
    } else {
      rtb_Gain1_idx_1 = rtb_eow_idx_idx;
    }

    /* Product: '<S754>/Product5' */
    rtb_Product5_b_idx_0 = rtb_Gain1_idx_1 * rtb_Reshape_n[43];
    min[1] = rtb_Reshape_n[50];
    if (min[1] < 0.0) {
      rtb_X_idx_idx = -sqrt(-min[1]);
    } else {
      rtb_X_idx_idx = sqrt(min[1]);
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_hxr -
      claw_main_P.Gain_Gain_jc * rtb_Reshape_n[50];

    /* Math: '<S184>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain1'
     *  Sum: '<S184>/Sum1'
     */
    if (!(rtb_Reshape_n[50] >= claw_main_P.Switch_Threshold_ll)) {
      rtb_X_idx_idx = (rtb_delta_LLh_idx + claw_main_P.Constant_Value_hxr) *
        claw_main_P.Gain1_Gain_dx;
    }

    /* Switch: '<S184>/Switch1' incorporates:
     *  Constant: '<S184>/Constant3'
     */
    if (rtb_Reshape_n[47] >= claw_main_P.Switch1_Threshold_b) {
      rtb_Gain1_idx = claw_main_P.Constant3_Value_m;
    } else {
      rtb_Gain1_idx = rtb_X_idx_idx;
    }

    /* Product: '<S754>/Product5' */
    rtb_Product5_b_idx_1 = rtb_Gain1_idx * rtb_Reshape_n[44];
    min[2] = rtb_Reshape_n[51];
    if (min[2] < 0.0) {
      rtb_MathFunction_pa_idx = -sqrt(-min[2]);
    } else {
      rtb_MathFunction_pa_idx = sqrt(min[2]);
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_hxr -
      claw_main_P.Gain_Gain_jc * rtb_Reshape_n[51];

    /* Math: '<S184>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Gain1'
     *  Sum: '<S184>/Sum1'
     */
    if (!(rtb_Reshape_n[51] >= claw_main_P.Switch_Threshold_ll)) {
      rtb_MathFunction_pa_idx = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_hxr) * claw_main_P.Gain1_Gain_dx;
    }

    /* Switch: '<S184>/Switch1' incorporates:
     *  Constant: '<S184>/Constant3'
     */
    if (rtb_Reshape_n[48] >= claw_main_P.Switch1_Threshold_b) {
      rtb_Gain1_idx_0 = claw_main_P.Constant3_Value_m;
    } else {
      rtb_Gain1_idx_0 = rtb_MathFunction_pa_idx;
    }

    /* Product: '<S754>/Product5' */
    rtb_Product5_b_idx = rtb_Gain1_idx_0 * rtb_Reshape_n[45];

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S164>/Constant6'
     *  Constant: '<S184>/Constant2'
     *  Constant: '<S184>/Constant4'
     *  Product: '<S184>/Divide2'
     *  Product: '<S184>/Divide3'
     *  Sum: '<S184>/Sum2'
     *  Sum: '<S184>/Sum3'
     */
    if (rtb_Reshape_n[46] >= claw_main_P.Switch2_Threshold_h) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_me;
    } else {
      rtb_delta_LLh_idx = (claw_main_P.Constant2_Value_bz - rtb_Gain1_idx_1) *
        claw_main_P.Constant6_Value_i[0] + 1.0 / rtb_Reshape_n[43] *
        claw_main_P.Constant1_Value_fb[0];
    }

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S164>/Constant6'
     *  Constant: '<S184>/Constant2'
     *  Constant: '<S184>/Constant4'
     *  Product: '<S184>/Divide2'
     *  Product: '<S184>/Divide3'
     *  Sum: '<S184>/Sum2'
     *  Sum: '<S184>/Sum3'
     */
    if (rtb_Reshape_n[47] >= claw_main_P.Switch2_Threshold_h) {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_me;
    } else {
      rtb_delta_LLh_idx_0 = (claw_main_P.Constant2_Value_bz - rtb_Gain1_idx) *
        claw_main_P.Constant6_Value_i[1] + 1.0 / rtb_Reshape_n[44] *
        claw_main_P.Constant1_Value_fb[1];
    }

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S164>/Constant6'
     *  Constant: '<S184>/Constant2'
     *  Constant: '<S184>/Constant4'
     *  Product: '<S184>/Divide2'
     *  Product: '<S184>/Divide3'
     *  Sum: '<S184>/Sum2'
     *  Sum: '<S184>/Sum3'
     */
    if (rtb_Reshape_n[48] >= claw_main_P.Switch2_Threshold_h) {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_me;
    } else {
      rtb_Switch2_idx = (claw_main_P.Constant2_Value_bz - rtb_Gain1_idx_0) *
        claw_main_P.Constant6_Value_i[2] + 1.0 / rtb_Reshape_n[45] *
        claw_main_P.Constant1_Value_fb[2];
    }

    /* DiscreteIntegrator: '<S523>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S754>/Gain'
     *  Product: '<S523>/Product4'
     *  Product: '<S754>/Product1'
     *  Product: '<S754>/Product2'
     *  Product: '<S754>/Product3'
     *  RelationalOperator: '<S755>/Compare'
     *  RelationalOperator: '<S756>/Compare'
     *  Sum: '<S523>/Sum1'
     *  Sum: '<S523>/Sum3'
     *  Sum: '<S754>/Sum'
     *  Sum: '<S754>/Sum1'
     *  Sum: '<S754>/Sum2'
     *  Sum: '<S754>/Sum6'
     *  UnitDelay: '<S523>/Unit Delay2'
     *  UnitDelay: '<S754>/Unit Delay'
     */
    if (claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_c) {
      claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_c = 0U;
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_o[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_o[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_o[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2];
    } else if ((rtb_control_input[101] > 0.0) &&
               (claw_main_DWork.DiscreteTimeIntegrator_PrevRe_n <= 0)) {
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_o[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_o[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_o[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2];
    } else {
      claw_main_B.DiscreteTimeIntegrator_o[0] =
        (((((claw_main_DWork.UnitDelay_DSTATE_a[0] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_a[0] - rtb_Product5_b_idx_0) *
             rtb_MultiportSwitch_n_idx_0 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_a[3] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] - rtb_Gain_idx)
             * (claw_main_DWork.UnitDelay_DSTATE_a[3] - rtb_Reshape_n[43]) : 0.0))
           / rtb_Reshape_n[43] * claw_main_P.Gain_Gain_kb - (rtb_Reshape_n[49] ==
            0.0 ? rtb_Reshape_n[43] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] : 0.0)) +
          rtb_Reshape_n[49] * rtb_Reshape_n[43] * (rtb_MultiportSwitch_n_idx_0 -
           rtb_Gain_idx)) + claw_main_DWork.UnitDelay2_DSTATE_d[0]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_n +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0];
      claw_main_B.DiscreteTimeIntegrator_o[1] =
        (((((claw_main_DWork.UnitDelay_DSTATE_a[1] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_a[1] - rtb_Product5_b_idx_1) *
             rtb_MultiportSwitch_n_idx_1 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_a[4] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] -
              rtb_Gain_idx_0) * (claw_main_DWork.UnitDelay_DSTATE_a[4] -
              rtb_Reshape_n[44]) : 0.0)) / rtb_Reshape_n[44] *
           claw_main_P.Gain_Gain_kb - (rtb_Reshape_n[50] == 0.0 ? rtb_Reshape_n
            [44] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] : 0.0)) +
          rtb_Reshape_n[50] * rtb_Reshape_n[44] * (rtb_MultiportSwitch_n_idx_1 -
           rtb_Gain_idx_0)) + claw_main_DWork.UnitDelay2_DSTATE_d[1]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_n +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1];
      claw_main_B.DiscreteTimeIntegrator_o[2] =
        (((((claw_main_DWork.UnitDelay_DSTATE_a[2] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_a[2] - rtb_Product5_b_idx) *
             rtb_MultiportSwitch_n_idx : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_a[5] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] -
              rtb_Gain_idx_1) * (claw_main_DWork.UnitDelay_DSTATE_a[5] -
              rtb_Reshape_n[45]) : 0.0)) / rtb_Reshape_n[45] *
           claw_main_P.Gain_Gain_kb - (rtb_Reshape_n[51] == 0.0 ? rtb_Reshape_n
            [45] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] : 0.0)) +
          rtb_Reshape_n[51] * rtb_Reshape_n[45] * (rtb_MultiportSwitch_n_idx -
           rtb_Gain_idx_1)) + claw_main_DWork.UnitDelay2_DSTATE_d[2]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_n +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2];
    }

    if (rtb_control_input[101] > 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_n = 1;
    } else if (rtb_control_input[101] < 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_n = -1;
    } else {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_n = 0;
    }

    /* Sum: '<S757>/Sum' incorporates:
     *  Product: '<S523>/Product2'
     *  Product: '<S523>/Product5'
     *  Product: '<S523>/Product6'
     *  Sum: '<S523>/Sum2'
     *  Sum: '<S523>/Sum4'
     *  Sum: '<S523>/Sum5'
     *  Switch: '<S10>/Switch'
     */
    if (claw_main_B.Merge2[0] >= claw_main_P.Switch_Threshold_mh) {
      rtb_delta_LLh_idx = claw_main_B.Merge_cz[0];
    } else {
      rtb_delta_LLh_idx = ((rtb_MultiportSwitch_n_idx_0 * rtb_Gain1_idx_1 -
                            rtb_Gain_idx) +
                           claw_main_B.DiscreteTimeIntegrator_o[0]) *
        rtb_Reshape_n[43] + rtb_Reshape_n[46] * rtb_MultiportSwitch2_idx_2;
    }

    rtb_Sum_f3_idx_0 = rtb_delta_LLh_idx - rtb_Gain_kp_idx_0;
    if (claw_main_B.Merge2[1] >= claw_main_P.Switch_Threshold_mh) {
      rtb_delta_LLh_idx = claw_main_B.Merge_cz[1];
    } else {
      rtb_delta_LLh_idx = ((rtb_MultiportSwitch_n_idx_1 * rtb_Gain1_idx -
                            rtb_Gain_idx_0) +
                           claw_main_B.DiscreteTimeIntegrator_o[1]) *
        rtb_Reshape_n[44] + rtb_Reshape_n[47] * rtb_UnitDelay_nf_idx;
    }

    rtb_Sum_f3_idx_1 = rtb_delta_LLh_idx - rtb_Gain_kp_idx_1;
    if (claw_main_B.Merge2[2] >= claw_main_P.Switch_Threshold_mh) {
      rtb_delta_LLh_idx = claw_main_B.Merge_cz[2];
    } else {
      rtb_delta_LLh_idx = ((rtb_MultiportSwitch_n_idx * rtb_Gain1_idx_0 -
                            rtb_Gain_idx_1) +
                           claw_main_B.DiscreteTimeIntegrator_o[2]) *
        rtb_Reshape_n[45] + rtb_Reshape_n[48] * rtb_UnitDelay_nf_idx_0;
    }

    rtb_Sum_f3_idx = rtb_delta_LLh_idx - rtb_Gain_kp_idx;

    /* Gain: '<S770>/Gain1' incorporates:
     *  Math: '<S770>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_UnitDelay_n[0] * rtb_UnitDelay_n[0];
    rtb_delta_LLh_idx_0 = rtb_UnitDelay_n[1] * rtb_UnitDelay_n[1];
    rtb_Switch2_idx = rtb_UnitDelay_n[2] * rtb_UnitDelay_n[2];
    rtb_Gain1_idx_0 = rtb_UnitDelay_n[3] * rtb_UnitDelay_n[3];
    for (i = 0; i < 4; i++) {
      rtb_Gain1_h[i] = 0.0;
      rtb_Gain1_h[i] += claw_main_P.Gain1_Gain_al[i] * rtb_delta_LLh_idx;
      rtb_Gain1_h[i] += claw_main_P.Gain1_Gain_al[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_h[i] += claw_main_P.Gain1_Gain_al[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_h[i] += claw_main_P.Gain1_Gain_al[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S770>/e1*e2' */
    rtb_e1e2_e = rtb_UnitDelay_n[1] * rtb_UnitDelay_n[2];

    /* Product: '<S770>/e3*e1' */
    rtb_e3e1_a = rtb_UnitDelay_n[3] * rtb_UnitDelay_n[1];

    /* Product: '<S770>/e2*e3' */
    rtb_e2e3_g = rtb_UnitDelay_n[2] * rtb_UnitDelay_n[3];

    /* Product: '<S770>/e0*e3' */
    rtb_e0e3_j = rtb_UnitDelay_n[0] * rtb_UnitDelay_n[3];

    /* Product: '<S770>/e0*e2' */
    rtb_e0e2_i = rtb_UnitDelay_n[0] * rtb_UnitDelay_n[2];

    /* Product: '<S770>/e0*e1' */
    rtb_e0e1_k0 = rtb_UnitDelay_n[0] * rtb_UnitDelay_n[1];

    /* Gain: '<S770>/Gain' incorporates:
     *  Sum: '<S770>/Sum'
     *  Sum: '<S770>/Sum1'
     */
    rtb_Gain_kgg[0] = (rtb_e1e2_e + rtb_e0e3_j) * claw_main_P.Gain_Gain_lv;
    rtb_Gain_kgg[1] = (rtb_e3e1_a + rtb_e0e2_i) * claw_main_P.Gain_Gain_lv;
    rtb_Gain_kgg[2] = (rtb_e2e3_g + rtb_e0e1_k0) * claw_main_P.Gain_Gain_lv;
    rtb_Gain_kgg[3] = (rtb_e1e2_e - rtb_e0e3_j) * claw_main_P.Gain_Gain_lv;
    rtb_Gain_kgg[4] = (rtb_e3e1_a - rtb_e0e2_i) * claw_main_P.Gain_Gain_lv;
    rtb_Gain_kgg[5] = (rtb_e2e3_g - rtb_e0e1_k0) * claw_main_P.Gain_Gain_lv;

    /* SwitchCase: '<S769>/Switch Case' incorporates:
     *  ActionPort: '<S771>/Action Port'
     *  ActionPort: '<S772>/Action Port'
     *  ActionPort: '<S773>/Action Port'
     *  SubSystem: '<S769>/mba'
     *  SubSystem: '<S769>/tiltcam'
     *  SubSystem: '<S769>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam_b(rtb_Gain1_h[1], rtb_Gain_kgg[3], rtb_Gain_kgg[1],
                          rtb_Gain_kgg[0], rtb_Gain1_h[2], rtb_Gain_kgg[5],
                          rtb_Gain_kgg[4], rtb_Gain_kgg[2], rtb_Gain1_h[3],
                          claw_main_B.Merge_d, (rtP_tiltcam_claw_main_n *)
                          &claw_main_P.tiltcam_px);
      break;

     case 2:
     case 3:
      claw_main_ypr_c(rtb_Gain1_h[1], rtb_Gain_kgg[3], rtb_Gain_kgg[1],
                      rtb_Gain_kgg[0], rtb_Gain1_h[2], rtb_Gain_kgg[5],
                      rtb_Gain_kgg[4], rtb_Gain_kgg[2], rtb_Gain1_h[3],
                      claw_main_B.Merge_d, (rtP_ypr_claw_main_p *)
                      &claw_main_P.ypr_i);
      break;

     case 4:
     case 5:
      claw_main_mba_h(rtb_Gain1_h[1], rtb_Gain_kgg[3], rtb_Gain_kgg[1],
                      rtb_Gain_kgg[0], rtb_Gain1_h[2], rtb_Gain_kgg[5],
                      rtb_Gain_kgg[4], rtb_Gain_kgg[2], rtb_Gain1_h[3],
                      rtb_Product_h, rtb_Sum_m, rtb_Sum1_p, rtb_Product5,
                      rtb_Sum2_l, rtb_Sum3, rtb_Gain_p, rtb_Product10,
                      rtb_Product11, claw_main_B.Merge_d, (rtP_mba_claw_main_a *)
                      &claw_main_P.mba_e);
      break;
    }

    /* Selector: '<S769>/order atts' incorporates:
     *  Constant: '<S769>/Constant'
     *  Selector: '<S769>/Selector'
     */
    rtb_delta_LLh_idx_0 = claw_main_B.Merge_d[(int32_T)
      claw_main_P.Constant_Value_n0[(int32_T)rtb_att_type - 1] - 1];
    rtb_Gain1_idx_1 = claw_main_B.Merge_d[(int32_T)
      claw_main_P.Constant_Value_n0[(int32_T)rtb_att_type + 4] - 1];

    /* Sum: '<S760>/Sum2' incorporates:
     *  Gain: '<S760>/Gain1'
     *  MinMax: '<S791>/limit1'
     *  Product: '<S791>/Divide'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain1_Gain_jc * rtb_Assignment_l_idx +
      rtb_delta_LLh_idx_0;
    rtb_Gain1_idx_0 = rtb_Gain_kg / rt_MAXd_snf(rtb_Divide1_e, rtb_uvw[0]) *
      claw_main_P.Gain1_Gain_jc + rtb_Gain1_idx_1;
    rtb_Gain1_idx = claw_main_P.Gain1_Gain_jc * rtb_control_input[50] +
      rtb_UnitDelay_n[4];

    /* MinMax: '<S760>/MinMax1' incorporates:
     *  MinMax: '<S792>/limit1'
     *  Product: '<S792>/Divide'
     *  Reshape: '<S787>/Reshape3'
     */
    min[0] = rt_MAXd_snf(rtb_delta_LLh_idx, rtb_Selector2_idx);
    rtb_Switch2_idx = claw_main_P.Gain_Gain_dbq * rtb_Assignment_pi_idx +
      rtb_delta_LLh_idx_0;
    min[1] = rt_MAXd_snf(rtb_Gain1_idx_0, rtb_Selector2_idx_0);
    rtb_delta_LLh_idx_0 = rtb_Gain_jqu / rt_MAXd_snf(rtb_Divide1_l, rtb_uvw[0]) *
      claw_main_P.Gain_Gain_dbq + rtb_Gain1_idx_1;
    min[2] = rt_MAXd_snf(rtb_Gain1_idx, min_4);

    /* Sum: '<S760>/Sum1' incorporates:
     *  Gain: '<S760>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_dbq * rtb_control_input[40] +
      rtb_UnitDelay_n[4];

    /* MinMax: '<S760>/MinMax3' incorporates:
     *  Reshape: '<S787>/Reshape1'
     */
    min_0[0] = rt_MINd_snf(rtb_Switch2_idx, rtb_Selector1_idx);
    min_0[1] = rt_MINd_snf(rtb_delta_LLh_idx_0, rtb_Selector1_idx_0);
    min_0[2] = rt_MINd_snf(rtb_delta_LLh_idx, max_4);

    /* SignalConversion: '<S761>/TmpHiddenBufferAtS-FunctionInport1' incorporates:
     *  Constant: '<S530>/Constant3'
     *  Constant: '<S530>/Constant4'
     *  Constant: '<S761>/ncolumns'
     *  Constant: '<S761>/nrows'
     *  Constant: '<S762>/Constant'
     *  Memory: '<S757>/Memory'
     *  MinMax: '<S760>/MinMax'
     *  MinMax: '<S760>/MinMax2'
     *  Product: '<S762>/Product1'
     *  Product: '<S762>/Product2'
     *  Reshape: '<S787>/Reshape1'
     *  Reshape: '<S787>/Reshape3'
     *  Sum: '<S757>/Sum1'
     *  Sum: '<S757>/Sum2'
     *  Sum: '<S757>/Sum3'
     */
    for (i = 0; i < 3; i++) {
      for (yOffset_0 = 0; yOffset_0 < 3; yOffset_0++) {
        rtb_Gain1_oy_0[i + 3 * yOffset_0] = 0.0;
        rtb_Gain1_oy_0[i + 3 * yOffset_0] = rtb_Gain1_oy_0[3 * yOffset_0 + i] +
          rtb_Assignment_m[3 * yOffset_0] * rtb_wght_cv[i];
        rtb_Gain1_oy_0[i + 3 * yOffset_0] = rtb_Assignment_m[3 * yOffset_0 + 1] *
          rtb_wght_cv[i + 3] + rtb_Gain1_oy_0[3 * yOffset_0 + i];
        rtb_Gain1_oy_0[i + 3 * yOffset_0] = rtb_Assignment_m[3 * yOffset_0 + 2] *
          rtb_wght_cv[i + 6] + rtb_Gain1_oy_0[3 * yOffset_0 + i];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_wght_cv[i] * rtb_Sum_f3_idx_0;
      rtb_dircos_0[i] += rtb_wght_cv[i + 3] * rtb_Sum_f3_idx_1;
      rtb_dircos_0[i] += rtb_wght_cv[i + 6] * rtb_Sum_f3_idx;
    }

    claw_main_B.TmpHiddenBufferAtSFunctionInpor[0] = claw_main_P.nrows_Value;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[1] = claw_main_P.ncolumns_Value;
    memcpy((void *)(&claw_main_B.TmpHiddenBufferAtSFunctionInpor[2]), (void *)
           &rtb_Gain1_oy_0[0], 9U * (uint32_T)((char_T *)&rtb_Gain1_oy_0[1U] -
            (char_T *)&rtb_Gain1_oy_0[0U]));
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[11] = rtb_dircos_0[0];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[12] = rtb_dircos_0[1];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[13] = rtb_dircos_0[2];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[14] = rt_MINd_snf(min[0],
      rtb_Selector1_idx) - rtb_orderatts_i_idx_0;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[15] = rt_MINd_snf(min[1],
      rtb_Selector1_idx_0) - rtb_orderatts_i_idx_1;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[16] = rt_MINd_snf(min[2], max_4)
      - min_5;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[17] = rt_MAXd_snf(min_0[0],
      rtb_Selector2_idx) - rtb_orderatts_i_idx_0;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[18] = rt_MAXd_snf(min_0[1],
      rtb_Selector2_idx_0) - rtb_orderatts_i_idx_1;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[19] = rt_MAXd_snf(min_0[2],
      min_4) - min_5;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[20] =
      claw_main_P.Constant_Value_o4[0];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[21] =
      claw_main_P.Constant_Value_o4[1];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[22] =
      claw_main_P.Constant_Value_o4[2];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[23] =
      claw_main_P.Constant3_Value_b2[0] - rtb_orderatts_i_idx_0;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[24] =
      claw_main_P.Constant3_Value_b2[1] - rtb_orderatts_i_idx_1;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[25] =
      claw_main_P.Constant3_Value_b2[2] - min_5;
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[26] =
      claw_main_P.Constant4_Value_if[0];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[27] =
      claw_main_P.Constant4_Value_if[1];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[28] =
      claw_main_P.Constant4_Value_if[2];
    claw_main_B.TmpHiddenBufferAtSFunctionInpor[29] =
      claw_main_DWork.Memory_PreviousInput_d;

    /* S-Function "smn_sfunc_gam_mpass_epsposdef_wrapper" Block: <S761>/S-Function */
    smn_sfunc_gam_mpass_epsposdef_Outputs_wrapper
      (claw_main_B.TmpHiddenBufferAtSFunctionInpor, claw_main_B.SFunction , 461,
       30);

    /* Sum: '<S757>/Sum4' */
    rtb_Sum4_e_idx_0 = claw_main_B.SFunction[0] + rtb_orderatts_i_idx_0;
    rtb_Sum4_e_idx_1 = claw_main_B.SFunction[1] + rtb_orderatts_i_idx_1;
    rtb_Sum4_e_idx = claw_main_B.SFunction[2] + min_5;

    /* SignalConversion: '<S797>/TmpHiddenBufferAtorder attsInport1' */
    rtb_TmpHiddenBufferAtorderatt_g[0] = rtb_Sum4_e_idx_0;
    rtb_TmpHiddenBufferAtorderatt_g[1] = rtb_Sum4_e_idx_1;
    rtb_TmpHiddenBufferAtorderatt_g[2] = rtb_MultiportSwitch_o_idx_0;

    /* MultiPortSwitch: '<S19>/switch att cmd' incorporates:
     *  Assignment: '<S93>/set att cmd'
     *  Assignment: '<S99>/set pos cmd'
     *  Reshape: '<S97>/Reshape'
     */
    switch ((int32_T)rtb_Selector[5]) {
     case 0:
      rtb_switchattcmd[0] = rtb_orderatts_a_idx;
      break;

     case 1:
      rtb_switchattcmd[0] = rtb_InterpolationnDusingPreLo_0;
      break;

     default:
      rtb_switchattcmd[0] = rtb_TmpHiddenBufferAtorderatt_g[0];
      break;
    }

    switch ((int32_T)rtb_Selector[6]) {
     case 0:
      rtb_switchattcmd[1] = rtb_orderatts_a_idx_0;
      break;

     case 1:
      rtb_switchattcmd[1] = rtb_InterpolationnDusingPreLo_1;
      break;

     default:
      rtb_switchattcmd[1] = rtb_TmpHiddenBufferAtorderatt_g[1];
      break;
    }

    switch ((int32_T)rtb_Selector[7]) {
     case 0:
      rtb_switchattcmd[2] = rtb_orderatts_a_idx_1;
      break;

     case 1:
      rtb_switchattcmd[2] = rtb_attcmdintegration_idx;
      break;

     default:
      rtb_switchattcmd[2] = rtb_TmpHiddenBufferAtorderatt_g[2];
      break;
    }

    /* Selector: '<S43>/order atts' incorporates:
     *  Constant: '<S43>/Constant'
     *  Selector: '<S43>/Selector'
     */
    rtb_orderatts_b[0] = rtb_switchattcmd[(int32_T)
      claw_main_P.Constant_Value_j0p[(int32_T)rtb_att_type - 1] - 1];
    rtb_orderatts_b[1] = rtb_switchattcmd[(int32_T)
      claw_main_P.Constant_Value_j0p[(int32_T)rtb_att_type + 4] - 1];
    rtb_orderatts_b[2] = rtb_switchattcmd[(int32_T)
      claw_main_P.Constant_Value_j0p[(int32_T)rtb_att_type + 9] - 1];

    /* SwitchCase: '<S43>/Switch Case' incorporates:
     *  ActionPort: '<S45>/Action Port'
     *  ActionPort: '<S46>/Action Port'
     *  ActionPort: '<S47>/Action Port'
     *  SubSystem: '<S43>/mba'
     *  SubSystem: '<S43>/tiltcam'
     *  SubSystem: '<S43>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam(rtb_orderatts_b, claw_main_B.Merge_db,
                        (rtP_tiltcam_claw_main *) &claw_main_P.tiltcam_bw);
      break;

     case 2:
     case 3:
      claw_main_ypr(rtb_orderatts_b, claw_main_B.Merge_db, (rtP_ypr_claw_main *)
                    &claw_main_P.ypr_eg);
      break;

     case 4:
     case 5:
      claw_main_mba(rtb_orderatts_b, rtb_Product_h, rtb_Sum_m, rtb_Sum1_p,
                    rtb_Product5, rtb_Sum2_l, rtb_Sum3, rtb_Gain_p,
                    rtb_Product10, rtb_Product11, claw_main_B.Merge_db,
                    (rtP_mba_claw_main *) &claw_main_P.mba_mj);
      break;
    }

    /* Switch: '<S19>/Switch' incorporates:
     *  RelationalOperator: '<S39>/Compare'
     *  Reshape: '<S97>/Reshape'
     */
    if (rtb_Selector[4] == 0.0) {
      rtb_Product_j3_idx = rtb_Switch_idx;
      rtb_Product_j3_idx_0 = rtb_Switch_idx_0;
      rtb_Product_j3_idx_1 = rtb_Switch_idx_1;
      rtb_Product_j3_idx_2 = rtb_Switch_idx_2;
    } else {
      /* Gain: '<S60>/Gain' incorporates:
       *  Constant: '<S60>/Constant'
       *  Gain: '<S60>/Matrix Gain'
       *  Sum: '<S60>/Sum'
       */
      for (i = 0; i < 16; i++) {
        tmp_8[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
          tmp_8[i] += claw_main_P.MatrixGain_Gain[(yOffset_0 << 4) + i] *
            claw_main_B.Merge_db[yOffset_0];
        }

        rtb_Gain_j4[i] = (tmp_8[i] + claw_main_P.Constant_Value[i]) *
          claw_main_P.Gain_Gain_i3;
      }

      /* SignalConversion: '<S60>/TmpHiddenBufferAtselect best diagInport1' */
      rtb_TmpHiddenBufferAtselectbe_c[0] = rtb_Gain_j4[0];
      rtb_TmpHiddenBufferAtselectbe_c[1] = rtb_Gain_j4[5];
      rtb_TmpHiddenBufferAtselectbe_c[2] = rtb_Gain_j4[10];
      rtb_TmpHiddenBufferAtselectbe_c[3] = rtb_Gain_j4[15];

      /* MinMax: '<S60>/MinMax3' */
      max_1 = rt_MAXd_snf(rtb_TmpHiddenBufferAtselectbe_c[0],
                          rtb_TmpHiddenBufferAtselectbe_c[1]);
      max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbe_c[2]);
      max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbe_c[3]);

      /* Switch: '<S60>/argmax1' incorporates:
       *  Constant: '<S60>/Constant4'
       *  Constant: '<S60>/Constant5'
       *  Sum: '<S60>/Sum2'
       */
      if (rtb_TmpHiddenBufferAtselectbe_c[0] - max_1 >=
          claw_main_P.argmax1_Threshold) {
        rtb_delta_LLh_idx = claw_main_P.Constant4_Value_n[0];
      } else {
        rtb_delta_LLh_idx = claw_main_P.Constant5_Value;
      }

      if (rtb_TmpHiddenBufferAtselectbe_c[1] - max_1 >=
          claw_main_P.argmax1_Threshold) {
        rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_n[1];
      } else {
        rtb_delta_LLh_idx_0 = claw_main_P.Constant5_Value;
      }

      if (rtb_TmpHiddenBufferAtselectbe_c[2] - max_1 >=
          claw_main_P.argmax1_Threshold) {
        rtb_Switch2_idx = claw_main_P.Constant4_Value_n[2];
      } else {
        rtb_Switch2_idx = claw_main_P.Constant5_Value;
      }

      if (rtb_TmpHiddenBufferAtselectbe_c[3] - max_1 >=
          claw_main_P.argmax1_Threshold) {
        rtb_Gain1_idx_0 = claw_main_P.Constant4_Value_n[3];
      } else {
        rtb_Gain1_idx_0 = claw_main_P.Constant5_Value;
      }

      /* MinMax: '<S60>/MinMax4' */
      max_1 = rt_MINd_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);
      max_1 = rt_MINd_snf(max_1, rtb_Switch2_idx);
      max_1 = rt_MINd_snf(max_1, rtb_Gain1_idx_0);

      /* Selector: '<S60>/select best diag' */
      rtb_selectbestdiag_e = rtb_TmpHiddenBufferAtselectbe_c[(int32_T)max_1 - 1];

      /* Math: '<S60>/Math Function' */
      if (rtb_selectbestdiag_e < 0.0) {
        rtb_MathFunction_nq = -sqrt(-rtb_selectbestdiag_e);
      } else {
        rtb_MathFunction_nq = sqrt(rtb_selectbestdiag_e);
      }

      /* Selector: '<S60>/select best col' incorporates:
       *  Reshape: '<S60>/Reshape1'
       */
      i = ((int32_T)max_1 - 1) << 2;

      /* Product: '<S60>/Product' */
      rtb_Product_j3_idx = rtb_Gain_j4[i] / rtb_MathFunction_nq;
      rtb_Product_j3_idx_0 = rtb_Gain_j4[i + 1] / rtb_MathFunction_nq;
      rtb_Product_j3_idx_1 = rtb_Gain_j4[i + 2] / rtb_MathFunction_nq;
      rtb_Product_j3_idx_2 = rtb_Gain_j4[i + 3] / rtb_MathFunction_nq;

      /* Switch: '<S44>/Switch' incorporates:
       *  Gain: '<S44>/Gain'
       *  Reshape: '<S60>/Reshape2'
       *  S-Function (sfix_dot): '<S44>/Dot Product'
       */
      rtb_delta_LLh_idx = ((rtb_Product_j3_idx * rtb_Switch_idx +
                            rtb_Product_j3_idx_0 * rtb_Switch_idx_0) +
                           rtb_Product_j3_idx_1 * rtb_Switch_idx_1) +
        rtb_Product_j3_idx_2 * rtb_Switch_idx_2;
      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold)) {
        rtb_Product_j3_idx *= claw_main_P.Gain_Gain_i;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold)) {
        rtb_Product_j3_idx_0 *= claw_main_P.Gain_Gain_i;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold)) {
        rtb_Product_j3_idx_1 *= claw_main_P.Gain_Gain_i;
      }

      if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold)) {
        rtb_Product_j3_idx_2 *= claw_main_P.Gain_Gain_i;
      }
    }

    /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
     *  RelationalOperator: '<S38>/Compare'
     */
    if (claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_m) {
      claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_m = 0U;
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0] = rtb_Product_j3_idx;
      rtb_UnitDelay_nf_idx = claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1] = rtb_Product_j3_idx_0;
      rtb_InterpolationnDusingPreLo_3 =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2] = rtb_Product_j3_idx_1;
      rtb_InterpolationnDusingPreLo_4 =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3] = rtb_Product_j3_idx_2;
      rtb_InterpolationnDusingPreLo_5 =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3];
    } else {
      if (rtb_Product2_a_idx == 0.0) {
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0] = rtb_Product_j3_idx;
        rtb_UnitDelay_nf_idx = claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0];
      } else {
        rtb_UnitDelay_nf_idx = claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0];
      }

      if (rtb_Product2_a_idx_0 == 0.0) {
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1] =
          rtb_Product_j3_idx_0;
        rtb_InterpolationnDusingPreLo_3 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1];
      } else {
        rtb_InterpolationnDusingPreLo_3 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1];
      }

      if (rtb_Product2_a_idx_1 == 0.0) {
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2] =
          rtb_Product_j3_idx_1;
        rtb_InterpolationnDusingPreLo_4 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2];
      } else {
        rtb_InterpolationnDusingPreLo_4 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2];
      }

      if (rtb_Product2_a_idx_2 == 0.0) {
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3] =
          rtb_Product_j3_idx_2;
        rtb_InterpolationnDusingPreLo_5 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3];
      } else {
        rtb_InterpolationnDusingPreLo_5 =
          claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3];
      }
    }

    /* Product: '<S21>/Product2' incorporates:
     *  Math: '<S174>/Math Function'
     *  RelationalOperator: '<S22>/Compare'
     *  Sum: '<S21>/Sum2'
     *  Sum: '<S21>/Sum6'
     *  UnitDelay: '<S21>/Unit Delay'
     */

    /* Sum: '<S18>/Sum1' incorporates:
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Sum'
     */
    rtb_Sum1_e_idx = rtb_Product2_a_idx * rtb_Reshape_n[4] * (rtb_Product_j3_idx
      - rtb_UnitDelay_nf_idx) + rtb_Gain4_idx * (real_T)
      rtb_LogicalOperator_n_idx;
    if (rtb_Reshape_n[12] < 0.0) {
      rtb_MathFunction_lo_idx = -sqrt(-rtb_Reshape_n[12]);
    } else {
      rtb_MathFunction_lo_idx = sqrt(rtb_Reshape_n[12]);
    }

    /* Sum: '<S174>/Sum' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_d0n -
      claw_main_P.Gain_Gain_a5 * rtb_Reshape_n[12];

    /* Math: '<S174>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain1'
     *  Sum: '<S174>/Sum1'
     */
    if (!(rtb_Reshape_n[12] >= claw_main_P.Switch_Threshold_cq)) {
      rtb_MathFunction_lo_idx = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_d0n) * claw_main_P.Gain1_Gain_eg;
    }

    /* Switch: '<S174>/Switch1' incorporates:
     *  Constant: '<S174>/Constant3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx >= claw_main_P.Switch1_Threshold_kb) {
      rtb_UnitDelay_nf_idx_0 = claw_main_P.Constant3_Value_ac;
    } else {
      rtb_UnitDelay_nf_idx_0 = rtb_MathFunction_lo_idx;
    }

    /* Product: '<S21>/Product5' */
    rtb_Product5_f_idx = rtb_UnitDelay_nf_idx_0 * rtb_Reshape_n[4];

    /* Sum: '<S18>/Sum1' incorporates:
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Sum'
     */
    rtb_Sum1_e_idx_0 = rtb_Product2_a_idx_0 * rtb_Reshape_n[5] *
      (rtb_Product_j3_idx_0 - rtb_InterpolationnDusingPreLo_3) + rtb_Gain4_idx_0
      * (real_T)rtb_LogicalOperator_n_idx_0;
    if (rtb_Reshape_n[13] < 0.0) {
      rtb_MathFunction_lo_idx_0 = -sqrt(-rtb_Reshape_n[13]);
    } else {
      rtb_MathFunction_lo_idx_0 = sqrt(rtb_Reshape_n[13]);
    }

    /* Sum: '<S174>/Sum' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_d0n -
      claw_main_P.Gain_Gain_a5 * rtb_Reshape_n[13];

    /* Math: '<S174>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain1'
     *  Sum: '<S174>/Sum1'
     */
    if (!(rtb_Reshape_n[13] >= claw_main_P.Switch_Threshold_cq)) {
      rtb_MathFunction_lo_idx_0 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_d0n) * claw_main_P.Gain1_Gain_eg;
    }

    /* Switch: '<S174>/Switch1' incorporates:
     *  Constant: '<S174>/Constant3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_0 >= claw_main_P.Switch1_Threshold_kb)
    {
      rtb_MultiportSwitch2_idx_2 = claw_main_P.Constant3_Value_ac;
    } else {
      rtb_MultiportSwitch2_idx_2 = rtb_MathFunction_lo_idx_0;
    }

    /* Product: '<S21>/Product5' */
    rtb_Product5_f_idx_0 = rtb_MultiportSwitch2_idx_2 * rtb_Reshape_n[5];

    /* Sum: '<S18>/Sum1' incorporates:
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Sum'
     */
    rtb_Sum1_e_idx_1 = rtb_Product2_a_idx_1 * rtb_Reshape_n[6] *
      (rtb_Product_j3_idx_1 - rtb_InterpolationnDusingPreLo_4) + rtb_Gain4_idx_1
      * (real_T)rtb_LogicalOperator_n_idx_1;
    if (rtb_Reshape_n[14] < 0.0) {
      rtb_MathFunction_lo_idx_1 = -sqrt(-rtb_Reshape_n[14]);
    } else {
      rtb_MathFunction_lo_idx_1 = sqrt(rtb_Reshape_n[14]);
    }

    /* Sum: '<S174>/Sum' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_d0n -
      claw_main_P.Gain_Gain_a5 * rtb_Reshape_n[14];

    /* Math: '<S174>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain1'
     *  Sum: '<S174>/Sum1'
     */
    if (!(rtb_Reshape_n[14] >= claw_main_P.Switch_Threshold_cq)) {
      rtb_MathFunction_lo_idx_1 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_d0n) * claw_main_P.Gain1_Gain_eg;
    }

    /* Switch: '<S174>/Switch1' incorporates:
     *  Constant: '<S174>/Constant3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_1 >= claw_main_P.Switch1_Threshold_kb)
    {
      rtb_Gain1_idx = claw_main_P.Constant3_Value_ac;
    } else {
      rtb_Gain1_idx = rtb_MathFunction_lo_idx_1;
    }

    /* Product: '<S21>/Product5' */
    rtb_Product5_f_idx_1 = rtb_Gain1_idx * rtb_Reshape_n[6];

    /* Sum: '<S18>/Sum1' incorporates:
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Sum'
     */
    rtb_Sum1_e_idx_2 = rtb_Product2_a_idx_2 * rtb_Reshape_n[7] *
      (rtb_Product_j3_idx_2 - rtb_InterpolationnDusingPreLo_5) + rtb_Gain4_idx_2
      * (real_T)rtb_LogicalOperator_n_idx_2;
    if (rtb_Reshape_n[15] < 0.0) {
      rtb_MathFunction_lo_idx_2 = -sqrt(-rtb_Reshape_n[15]);
    } else {
      rtb_MathFunction_lo_idx_2 = sqrt(rtb_Reshape_n[15]);
    }

    /* Sum: '<S174>/Sum' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_d0n -
      claw_main_P.Gain_Gain_a5 * rtb_Reshape_n[15];

    /* Math: '<S174>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  Gain: '<S174>/Gain1'
     *  Sum: '<S174>/Sum1'
     */
    if (!(rtb_Reshape_n[15] >= claw_main_P.Switch_Threshold_cq)) {
      rtb_MathFunction_lo_idx_2 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_d0n) * claw_main_P.Gain1_Gain_eg;
    }

    /* Switch: '<S174>/Switch1' incorporates:
     *  Constant: '<S174>/Constant3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_2 >= claw_main_P.Switch1_Threshold_kb)
    {
      rtb_Gain1_idx_1 = claw_main_P.Constant3_Value_ac;
    } else {
      rtb_Gain1_idx_1 = rtb_MathFunction_lo_idx_2;
    }

    /* Product: '<S21>/Product5' */
    rtb_Product5_f_idx_2 = rtb_Gain1_idx_1 * rtb_Reshape_n[7];

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant4'
     *  Product: '<S174>/Divide2'
     *  Product: '<S174>/Divide3'
     *  Sum: '<S174>/Sum2'
     *  Sum: '<S174>/Sum3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx >= claw_main_P.Switch2_Threshold_i) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_cc;
    } else {
      rtb_delta_LLh_idx = (claw_main_P.Constant2_Value_b0 -
                           rtb_UnitDelay_nf_idx_0) *
        claw_main_P.Constant6_Value_i0[0] + 1.0 / rtb_Reshape_n[4] *
        claw_main_P.Constant1_Value_np[0];
    }

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant4'
     *  Product: '<S174>/Divide2'
     *  Product: '<S174>/Divide3'
     *  Sum: '<S174>/Sum2'
     *  Sum: '<S174>/Sum3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_0 >= claw_main_P.Switch2_Threshold_i)
    {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_cc;
    } else {
      rtb_delta_LLh_idx_0 = (claw_main_P.Constant2_Value_b0 -
        rtb_MultiportSwitch2_idx_2) * claw_main_P.Constant6_Value_i0[1] + 1.0 /
        rtb_Reshape_n[5] * claw_main_P.Constant1_Value_np[1];
    }

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant4'
     *  Product: '<S174>/Divide2'
     *  Product: '<S174>/Divide3'
     *  Sum: '<S174>/Sum2'
     *  Sum: '<S174>/Sum3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_1 >= claw_main_P.Switch2_Threshold_i)
    {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_cc;
    } else {
      rtb_Switch2_idx = (claw_main_P.Constant2_Value_b0 - rtb_Gain1_idx) *
        claw_main_P.Constant6_Value_i0[2] + 1.0 / rtb_Reshape_n[6] *
        claw_main_P.Constant1_Value_np[2];
    }

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant6'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant4'
     *  Product: '<S174>/Divide2'
     *  Product: '<S174>/Divide3'
     *  Sum: '<S174>/Sum2'
     *  Sum: '<S174>/Sum3'
     */
    if ((real_T)rtb_LogicalOperator_n_idx_2 >= claw_main_P.Switch2_Threshold_i)
    {
      rtb_Gain1_idx_0 = claw_main_P.Constant4_Value_cc;
    } else {
      rtb_Gain1_idx_0 = (claw_main_P.Constant2_Value_b0 - rtb_Gain1_idx_1) *
        claw_main_P.Constant6_Value_i0[3] + 1.0 / rtb_Reshape_n[7] *
        claw_main_P.Constant1_Value_np[3];
    }

    /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S21>/Gain'
     *  Product: '<S20>/Product4'
     *  Product: '<S21>/Product1'
     *  Product: '<S21>/Product3'
     *  RelationalOperator: '<S23>/Compare'
     *  Sum: '<S20>/Sum1'
     *  Sum: '<S20>/Sum3'
     *  Sum: '<S21>/Sum'
     *  Sum: '<S21>/Sum1'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    if (claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_e) {
      claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_e = 0U;
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_p[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_p[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_p[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] = rtb_Gain1_idx_0;
      claw_main_B.DiscreteTimeIntegrator_p[3] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3];
    } else if ((rtb_control_input[101] > 0.0) &&
               (claw_main_DWork.DiscreteTimeIntegrator_PrevRe_a <= 0)) {
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_p[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_p[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_p[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2];
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] = rtb_Gain1_idx_0;
      claw_main_B.DiscreteTimeIntegrator_p[3] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3];
    } else {
      claw_main_B.DiscreteTimeIntegrator_p[0] =
        (((((claw_main_DWork.UnitDelay_DSTATE_b[0] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_b[0] - rtb_Product5_f_idx) *
             rtb_UnitDelay_nf_idx : 0.0) + (claw_main_DWork.UnitDelay_DSTATE_b[4]
             > 0.0 ? (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] -
                      rtb_Switch_idx) * (claw_main_DWork.UnitDelay_DSTATE_b[4] -
              rtb_Reshape_n[4]) : 0.0)) / rtb_Reshape_n[4] *
           claw_main_P.Gain_Gain_do - (rtb_Reshape_n[12] == 0.0 ? rtb_Reshape_n
            [4] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] : 0.0)) +
          rtb_Reshape_n[12] * rtb_Reshape_n[4] * (rtb_UnitDelay_nf_idx -
           rtb_Switch_idx)) + claw_main_DWork.UnitDelay2_DSTATE_e[0]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_j +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0];
      claw_main_B.DiscreteTimeIntegrator_p[1] =
        (((((claw_main_DWork.UnitDelay_DSTATE_b[1] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_b[1] - rtb_Product5_f_idx_0) *
             rtb_InterpolationnDusingPreLo_3 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_b[5] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] -
              rtb_Switch_idx_0) * (claw_main_DWork.UnitDelay_DSTATE_b[5] -
              rtb_Reshape_n[5]) : 0.0)) / rtb_Reshape_n[5] *
           claw_main_P.Gain_Gain_do - (rtb_Reshape_n[13] == 0.0 ? rtb_Reshape_n
            [5] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] : 0.0)) +
          rtb_Reshape_n[13] * rtb_Reshape_n[5] *
          (rtb_InterpolationnDusingPreLo_3 - rtb_Switch_idx_0)) +
         claw_main_DWork.UnitDelay2_DSTATE_e[1]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_j +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1];
      claw_main_B.DiscreteTimeIntegrator_p[2] =
        (((((claw_main_DWork.UnitDelay_DSTATE_b[2] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_b[2] - rtb_Product5_f_idx_1) *
             rtb_InterpolationnDusingPreLo_4 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_b[6] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] -
              rtb_Switch_idx_1) * (claw_main_DWork.UnitDelay_DSTATE_b[6] -
              rtb_Reshape_n[6]) : 0.0)) / rtb_Reshape_n[6] *
           claw_main_P.Gain_Gain_do - (rtb_Reshape_n[14] == 0.0 ? rtb_Reshape_n
            [6] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] : 0.0)) +
          rtb_Reshape_n[14] * rtb_Reshape_n[6] *
          (rtb_InterpolationnDusingPreLo_4 - rtb_Switch_idx_1)) +
         claw_main_DWork.UnitDelay2_DSTATE_e[2]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_j +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2];
      claw_main_B.DiscreteTimeIntegrator_p[3] =
        (((((claw_main_DWork.UnitDelay_DSTATE_b[3] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_b[3] - rtb_Product5_f_idx_2) *
             rtb_InterpolationnDusingPreLo_5 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_b[7] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] -
              rtb_Switch_idx_2) * (claw_main_DWork.UnitDelay_DSTATE_b[7] -
              rtb_Reshape_n[7]) : 0.0)) / rtb_Reshape_n[7] *
           claw_main_P.Gain_Gain_do - (rtb_Reshape_n[15] == 0.0 ? rtb_Reshape_n
            [7] * claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] : 0.0)) +
          rtb_Reshape_n[15] * rtb_Reshape_n[7] *
          (rtb_InterpolationnDusingPreLo_5 - rtb_Switch_idx_2)) +
         claw_main_DWork.UnitDelay2_DSTATE_e[3]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_j +
        claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3];
    }

    if (rtb_control_input[101] > 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_a = 1;
    } else if (rtb_control_input[101] < 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_a = -1;
    } else {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_a = 0;
    }

    /* Sum: '<S20>/Sum4' incorporates:
     *  Product: '<S20>/Product2'
     *  Product: '<S20>/Product5'
     *  Product: '<S20>/Product6'
     *  Sum: '<S20>/Sum2'
     *  Sum: '<S20>/Sum5'
     */
    rtb_Sum4_l_idx = ((rtb_UnitDelay_nf_idx * rtb_UnitDelay_nf_idx_0 -
                       rtb_Switch_idx) + claw_main_B.DiscreteTimeIntegrator_p[0])
      * rtb_Reshape_n[4] + (real_T)rtb_LogicalOperator_n_idx * rtb_Sum1_e_idx;
    rtb_Sum4_l_idx_0 = ((rtb_InterpolationnDusingPreLo_3 *
                         rtb_MultiportSwitch2_idx_2 - rtb_Switch_idx_0) +
                        claw_main_B.DiscreteTimeIntegrator_p[1]) *
      rtb_Reshape_n[5] + (real_T)rtb_LogicalOperator_n_idx_0 * rtb_Sum1_e_idx_0;
    rtb_Sum4_l_idx_1 = ((rtb_InterpolationnDusingPreLo_4 * rtb_Gain1_idx -
                         rtb_Switch_idx_1) +
                        claw_main_B.DiscreteTimeIntegrator_p[2]) *
      rtb_Reshape_n[6] + (real_T)rtb_LogicalOperator_n_idx_1 * rtb_Sum1_e_idx_1;
    rtb_Sum4_l_idx_2 = ((rtb_InterpolationnDusingPreLo_5 * rtb_Gain1_idx_1 -
                         rtb_Switch_idx_2) +
                        claw_main_B.DiscreteTimeIntegrator_p[3]) *
      rtb_Reshape_n[7] + (real_T)rtb_LogicalOperator_n_idx_2 * rtb_Sum1_e_idx_2;

    /* Product: '<S34>/Product' */
    for (i = 0; i < 3; i++) {
      rtb_Product_bh[i] = 0.0;
      rtb_Product_bh[i] += rtb_Gain_h[i] * rtb_Sum4_l_idx;
      rtb_Product_bh[i] += rtb_Gain_h[i + 3] * rtb_Sum4_l_idx_0;
      rtb_Product_bh[i] += rtb_Gain_h[i + 6] * rtb_Sum4_l_idx_1;
      rtb_Product_bh[i] += rtb_Gain_h[i + 9] * rtb_Sum4_l_idx_2;
    }

    /* MultiPortSwitch: '<S33>/Multiport Switch' incorporates:
     *  Assignment: '<S36>/Assignment'
     *  Logic: '<S91>/Logical Operator'
     *  MinMax: '<S33>/Enforce upper limit'
     */
    if (!(rtb_enable_bb != 0) == 0) {
      rtb_Assignment_pi_idx = rtb_Product_bh[0];
      rtb_MultiportSwitch_c_idx = rtb_Product_bh[1];
      rtb_MultiportSwitch_c_idx_0 = rtb_Product_bh[2];
    } else {
      /* Gain: '<S36>/Gain' incorporates:
       *  Constant: '<S33>/Constant1'
       */
      rtb_Gain_bz = claw_main_P.Gain_Gain * claw_main_P.Constant1_Value;

      /* Product: '<S36>/Divide1' incorporates:
       *  Constant: '<S33>/Constant3'
       *  Selector: '<S36>/q_limit'
       */
      rtb_Divide1_k = rtb_Gain_bz / claw_main_P.Constant3_Value[1];

      /* Product: '<S36>/Divide' incorporates:
       *  MinMax: '<S36>/limit1'
       */
      rtb_Divide_e = rtb_Gain_bz / rt_MAXd_snf(rtb_Divide1_k, rtb_uvw[0]);

      /* Gain: '<S35>/Gain' incorporates:
       *  Constant: '<S33>/Constant4'
       */
      rtb_Gain_he4 = claw_main_P.Gain_Gain_c * claw_main_P.Constant4_Value;

      /* Product: '<S35>/Divide1' incorporates:
       *  Constant: '<S33>/Constant2'
       *  Selector: '<S35>/q_limit'
       */
      rtb_Divide1_n3 = rtb_Gain_he4 / claw_main_P.Constant2_Value[1];

      /* Product: '<S35>/Divide' incorporates:
       *  MinMax: '<S35>/limit1'
       */
      rtb_Divide_d = rtb_Gain_he4 / rt_MAXd_snf(rtb_Divide1_n3, rtb_uvw[0]);

      /* MinMax: '<S33>/Enforce lower limit' incorporates:
       *  Assignment: '<S36>/Assignment'
       *  Constant: '<S33>/Constant3'
       */
      rtb_delta_LLh_idx = rt_MAXd_snf(rtb_Product_bh[0],
        claw_main_P.Constant2_Value[0]);
      rtb_Assignment_pi_idx = rt_MINd_snf(rtb_delta_LLh_idx,
        claw_main_P.Constant3_Value[0]);
      min[0] = rtb_delta_LLh_idx;

      /* MinMax: '<S33>/Enforce lower limit' incorporates:
       *  Assignment: '<S35>/Assignment'
       *  Constant: '<S33>/Constant2'
       */
      rtb_delta_LLh_idx = rt_MAXd_snf(rtb_Product_bh[1], rtb_Divide_d);
      rtb_MultiportSwitch_c_idx = rt_MINd_snf(rtb_delta_LLh_idx, rtb_Divide_e);
      min[1] = rtb_delta_LLh_idx;

      /* MinMax: '<S33>/Enforce lower limit' incorporates:
       *  Assignment: '<S36>/Assignment'
       */
      rtb_delta_LLh_idx = rt_MAXd_snf(rtb_Product_bh[2],
        claw_main_P.Constant2_Value[2]);
      rtb_MultiportSwitch_c_idx_0 = rt_MINd_snf(rtb_delta_LLh_idx,
        claw_main_P.Constant3_Value[2]);
      min[2] = rtb_delta_LLh_idx;
    }

    /* MultiPortSwitch: '<S19>/switch throt cmd' incorporates:
     *  Reshape: '<S97>/Reshape'
     *  UnitDelay: '<S19>/Unit Delay2'
     */
    switch ((int32_T)rtb_Selector[8]) {
     case 0:
      rtb_switchthrotcmd = claw_main_DWork.UnitDelay2_DSTATE_m;
      break;

     case 1:
      /* MultiPortSwitch: '<S42>/Multiport Switch2' incorporates:
       *  Assignment: '<S99>/set pos cmd'
       *  Gain: '<S42>/Gain'
       */
      if ((int32_T)rtb_control_input[104] == 0) {
        rtb_MultiportSwitch2_i = claw_main_P.Gain_Gain_h *
          rtb_InterpolationnDusingPreLo_2;
      } else {
        rtb_MultiportSwitch2_i = min_1[6];
      }

      rtb_switchthrotcmd = rtb_MultiportSwitch2_i;
      break;

     default:
      rtb_switchthrotcmd = rtb_Sum4_e_idx;
      break;
    }

    /* MultiPortSwitch: '<S199>/Multiport Switch' incorporates:
     *  Assignment: '<S93>/set att cmd'
     *  Assignment: '<S99>/set pos cmd'
     *  Reshape: '<S97>/Reshape'
     */
    switch ((int32_T)rtb_Selector[0]) {
     case 0:
      rtb_MultiportSwitch_k_idx = rtb_sensors[0];
      break;

     case 1:
      rtb_MultiportSwitch_k_idx = rtb_InterpolationnDusingPreLo_0;
      break;

     default:
      rtb_MultiportSwitch_k_idx = rtb_Assignment_pi_idx;
      break;
    }

    switch ((int32_T)rtb_Selector[1]) {
     case 0:
      rtb_MultiportSwitch_k_idx_0 = rtb_sensors[1];
      break;

     case 1:
      rtb_MultiportSwitch_k_idx_0 = rtb_InterpolationnDusingPreLo_1;
      break;

     default:
      rtb_MultiportSwitch_k_idx_0 = rtb_MultiportSwitch_c_idx;
      break;
    }

    switch ((int32_T)rtb_Selector[2]) {
     case 0:
      rtb_MultiportSwitch_k_idx_1 = rtb_sensors[2];
      break;

     case 1:
      rtb_MultiportSwitch_k_idx_1 = rtb_attcmdintegration_idx;
      break;

     default:
      rtb_MultiportSwitch_k_idx_1 = rtb_MultiportSwitch_c_idx_0;
      break;
    }

    switch ((int32_T)rtb_Selector[3]) {
     case 0:
      rtb_MultiportSwitch_k_idx_2 = rtb_UnitDelay1_j;
      break;

     case 1:
      rtb_MultiportSwitch_k_idx_2 = rtb_MultiportSwitch2_d;
      break;

     default:
      rtb_MultiportSwitch_k_idx_2 = rtb_switchthrotcmd;
      break;
    }

    /* Outputs for atomic SubSystem: '<S79>/Subsystem' */

    /* Inport: '<S84>/In1' */
    CLAW_p_cvcmd = rtb_MultiportSwitch_k_idx;

    /* Inport: '<S84>/In2' */
    CLAW_q_cvcmd = rtb_MultiportSwitch_k_idx_0;

    /* Inport: '<S84>/In3' */
    CLAW_r_cvcmd = rtb_MultiportSwitch_k_idx_1;

    /* Inport: '<S84>/In4' */
    CLAW_e0_cvcmd = rtb_Product_j3_idx;

    /* Inport: '<S84>/In5' */
    CLAW_e1_cvcmd = rtb_Product_j3_idx_0;

    /* Inport: '<S84>/In6' */
    CLAW_e2_cvcmd = rtb_Product_j3_idx_1;

    /* Inport: '<S84>/In7' */
    CLAW_e3_cvcmd = rtb_Product_j3_idx_2;

    /* Inport: '<S84>/In8' */
    CLAW_Ndot_cvcmd = rtb_MultiportSwitch_n_idx_0;

    /* Inport: '<S84>/In9' */
    CLAW_Edot_cvcmd = rtb_MultiportSwitch_n_idx_1;

    /* Inport: '<S84>/In10' */
    CLAW_hdot_cvcmd = rtb_MultiportSwitch_n_idx;

    /* Inport: '<S84>/In11' */
    CLAW_N_cvcmd = rtb_MultiportSwitch_o_idx_1;

    /* Inport: '<S84>/In12' */
    CLAW_E_cvcmd = rtb_MultiportSwitch_o_idx_2;

    /* Inport: '<S84>/In13' */
    CLAW_h_cvcmd = rtb_MultiportSwitch_o_idx;

    /* end of Outputs for SubSystem: '<S79>/Subsystem' */

    /* Gain: '<S420>/Gain1' */
    rtb_dL_Ail_m = claw_main_P.Gain1_Gain_ns * 0.0;

    /* Gain: '<S420>/Gain2' */
    rtb_dR_Ail_p = claw_main_P.Gain2_Gain_hm * 0.0;

    /* Sum: '<S418>/Sum3' incorporates:
     *  Constant: '<S418>/Elevator'
     *  Product: '<S418>/Product'
     */
    rtb_Sum3_fp = rtb_zeroRCSinputs[4] * rtb_zeroRCSinputs[0] +
      claw_main_P.Elevator_Value_a;

    /* Gain: '<S418>/Gain6' */
    rtb_ELLOBC_g = claw_main_P.Gain6_Gain_h * rtb_Sum3_fp;

    /* Gain: '<S418>/Gain5' */
    rtb_ELLIBC_o = claw_main_P.Gain5_Gain_b * rtb_Sum3_fp;

    /* Gain: '<S418>/Gain7' */
    rtb_ELROBC_g = claw_main_P.Gain7_Gain_d * rtb_Sum3_fp;

    /* Gain: '<S418>/Gain8' */
    rtb_ELRIBC_o = claw_main_P.Gain8_Gain_j * rtb_Sum3_fp;

    /* Sum: '<S418>/Sum' incorporates:
     *  Constant: '<S418>/Aileron'
     */
    rtb_Sum_fu = rtb_zeroRCSinputs[1] + claw_main_P.Aileron_Value_k;

    /* Gain: '<S418>/Gain1' */
    rtb_AILLC_a = claw_main_P.Gain1_Gain_dkt * rtb_Sum_fu;

    /* Gain: '<S418>/Gain2' */
    rtb_AILRC_d = claw_main_P.Gain2_Gain_nw * rtb_Sum_fu;

    /* Sum: '<S418>/Sum2' incorporates:
     *  Constant: '<S418>/Rudder'
     */
    rtb_Sum2_kr = rtb_zeroRCSinputs[2] + claw_main_P.Rudder_Value_b;

    /* Gain: '<S418>/Gain3' */
    rtb_RUDUPC_e = claw_main_P.Gain3_Gain_i4 * rtb_Sum2_kr;

    /* Gain: '<S418>/Gain4' */
    rtb_RUDLOC_l = claw_main_P.Gain4_Gain_e * rtb_Sum2_kr;

    /* Lookup Block: '<S418>/Left Roll Spoiler Schedule'
     * About '<S418>/Left Roll Spoiler Schedule :'
     * Lookup Block: '<S418>/Left Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_LeftRollSpoilerSchedule_g),
                         claw_main_P.LeftRollSpoilerSchedule_YData_h,
                         claw_main_P.Constant_Value_pu,
                         claw_main_P.LeftRollSpoilerSchedule_XData_n, 6U);

    /* Gain: '<S418>/Gain12' */
    rtb_SPLLIBC_k = claw_main_P.Gain12_Gain_h * rtb_LeftRollSpoilerSchedule_g;

    /* Gain: '<S418>/Gain13' */
    rtb_SPLLOBC_l = claw_main_P.Gain13_Gain_h * rtb_LeftRollSpoilerSchedule_g;

    /* Lookup Block: '<S418>/Right Roll Spoiler Schedule'
     * About '<S418>/Right Roll Spoiler Schedule :'
     * Lookup Block: '<S418>/Right Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_RightRollSpoilerSchedule_g),
                         claw_main_P.RightRollSpoilerSchedule_YDat_a,
                         claw_main_P.Constant_Value_pu,
                         claw_main_P.RightRollSpoilerSchedule_XDat_b, 6U);

    /* Sum: '<S418>/Sum4' incorporates:
     *  Constant: '<S418>/Constant2'
     *  Constant: '<S418>/Flaps'
     */
    rtb_Sum4_n = claw_main_P.Constant2_Value_c3 + claw_main_P.Flaps_Value_e;

    /* Gain: '<S418>/Gain20' incorporates:
     *  Constant: '<S418>/Gear'
     */
    rtb_GEARC_l = claw_main_P.Gain20_Gain_ow * claw_main_P.Gear_Value_a;

    /* Sum: '<S417>/Sum' incorporates:
     *  Constant: '<S417>/Gear1'
     *  Constant: '<S418>/Constant3'
     *  Gain: '<S418>/Gain10'
     *  Gain: '<S418>/Gain11'
     *  Gain: '<S418>/Gain14'
     *  Gain: '<S418>/Gain15'
     *  Gain: '<S418>/Gain16'
     *  Gain: '<S418>/Gain17'
     *  Gain: '<S418>/Gain18'
     *  Gain: '<S418>/Gain21'
     *  Gain: '<S418>/Gain22'
     *  Gain: '<S418>/Gain9'
     *  Saturate: '<S417>/Brake'
     *  Saturate: '<S417>/Gear'
     *  SignalConversion: '<S418>/TmpHiddenBufferAtGain22Inport1'
     *  Sum: '<S417>/Sum3'
     */
    rtb_orderatts_i_idx = claw_main_P.Gain14_Gain_i *
      rtb_RightRollSpoilerSchedule_g;
    rtb_Switch_d_idx_0 = claw_main_P.Gain11_Gain_o *
      rtb_RightRollSpoilerSchedule_g;
    rtb_Switch_d_idx = claw_main_P.Gain16_Gain_i * rtb_Sum4_n;
    rtb_Sum_ow_idx = claw_main_P.Gain17_Gain_b * rtb_Sum4_n;
    rtb_Sum_ow_idx_0 = claw_main_P.Gain18_Gain_f * rtb_Sum4_n;
    rtb_Sum_ow_idx_1 = claw_main_P.Gain15_Gain_c * rtb_Sum4_n;
    rtb_Switch_d_idx_1 = rtb_zeroRCSinputs[3] + claw_main_P.Gear1_Value_g;
    rtb_Sum_kw_idx = rt_SATURATE(rtb_GEARC_l, claw_main_P.Gear_LowerSat_m,
      claw_main_P.Gear_UpperSat_n);
    rtb_delta_LLh_idx = (claw_main_P.Gain22_Gain_i[0] * rtb_zeroRCSinputs[6] +
                         claw_main_P.Gain22_Gain_i[2] * rtb_zeroRCSinputs[5]) *
      claw_main_P.Gain9_Gain_lp;
    rtb_delta_LLh_idx_0 = (claw_main_P.Gain22_Gain_i[1] * rtb_zeroRCSinputs[6] +
      claw_main_P.Gain22_Gain_i[3] * rtb_zeroRCSinputs[5]) *
      claw_main_P.Gain10_Gain_c;

    /* Polyval: '<S415>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref_n = ((claw_main_P.Throttle_2_RPMref_coefs_i3[0] *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_i3[1]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_i3[2]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_i3[3];

    /* Polyval: '<S415>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust_k = ((claw_main_P.RPMref_2_Thrust_coefs_i[0] *
      rtb_Throttle_2_RPMref_n + claw_main_P.RPMref_2_Thrust_coefs_i[1]) *
      rtb_Throttle_2_RPMref_n + claw_main_P.RPMref_2_Thrust_coefs_i[2]) *
      rtb_Throttle_2_RPMref_n + claw_main_P.RPMref_2_Thrust_coefs_i[3];

    /* Gain: '<S345>/Gain1' */
    rtb_pratio_m = claw_main_P.Gain1_Gain_cg * rtb_P;

    /* Gain: '<S415>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM_f = claw_main_P.UnScale_Ref_RPM_Gain_p *
      rtb_Throttle_2_RPMref_n;

    /* Gain: '<S415>/angular momentum' */
    rtb_angularmomentum_f = claw_main_P.angularmomentum_Gain_l *
      rtb_UnScale_Ref_RPM_f;

    /* Polyval: '<S415>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow_i = claw_main_P.RPMref_2_FuelFlow_coefs_h[0];
    rtb_RPMref_2_FuelFlow_i = rtb_RPMref_2_FuelFlow_i * rtb_Throttle_2_RPMref_n
      + claw_main_P.RPMref_2_FuelFlow_coefs_h[1];
    rtb_RPMref_2_FuelFlow_i = rtb_RPMref_2_FuelFlow_i * rtb_Throttle_2_RPMref_n
      + claw_main_P.RPMref_2_FuelFlow_coefs_h[2];

    /* Lookup Block: '<S415>/Fuel Pump Voltage'
     * About '<S415>/Fuel Pump Voltage :'
     * Lookup Block: '<S415>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_i),
                         claw_main_P.FuelPumpVoltage_YData_f,
                         rtb_RPMref_2_FuelFlow_i,
                         claw_main_P.FuelPumpVoltage_XData_b, 25U);

    /* Gain: '<S346>/LengON' incorporates:
     *  Polyval: '<S415>/RPMref_2_EGT'
     *  Product: '<S415>/Product2'
     */
    rtb_LengON_k[0] = rtb_RPMref_2_Thrust_k * rtb_pratio_m *
      claw_main_P.LengON_Gain_h;
    rtb_LengON_k[1] = claw_main_P.LengON_Gain_h * rtb_UnScale_Ref_RPM_f;
    rtb_LengON_k[2] = claw_main_P.LengON_Gain_h * rtb_angularmomentum_f;
    rtb_LengON_k[3] = claw_main_P.LengON_Gain_h * rtb_FuelPumpVoltage_i;
    rtb_LengON_k[4] = ((((claw_main_P.RPMref_2_EGT_coefs_om[0] *
                          rtb_Throttle_2_RPMref_n +
                          claw_main_P.RPMref_2_EGT_coefs_om[1]) *
                         rtb_Throttle_2_RPMref_n +
                         claw_main_P.RPMref_2_EGT_coefs_om[2]) *
                        rtb_Throttle_2_RPMref_n +
                        claw_main_P.RPMref_2_EGT_coefs_om[3]) *
                       rtb_Throttle_2_RPMref_n +
                       claw_main_P.RPMref_2_EGT_coefs_om[4]) *
      claw_main_P.LengON_Gain_h;
    rtb_LengON_k[5] = claw_main_P.LengON_Gain_h * rtb_RPMref_2_FuelFlow_i;

    /* Polyval: '<S416>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref_l = ((claw_main_P.Throttle_2_RPMref_coefs_n[0] *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_n[1]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_n[2]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_n[3];

    /* Polyval: '<S416>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust_l = ((claw_main_P.RPMref_2_Thrust_coefs_m[0] *
      rtb_Throttle_2_RPMref_l + claw_main_P.RPMref_2_Thrust_coefs_m[1]) *
      rtb_Throttle_2_RPMref_l + claw_main_P.RPMref_2_Thrust_coefs_m[2]) *
      rtb_Throttle_2_RPMref_l + claw_main_P.RPMref_2_Thrust_coefs_m[3];

    /* Gain: '<S416>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM_e = claw_main_P.UnScale_Ref_RPM_Gain_em *
      rtb_Throttle_2_RPMref_l;

    /* Gain: '<S416>/angular momentum' */
    rtb_angularmomentum_e = claw_main_P.angularmomentum_Gain_n *
      rtb_UnScale_Ref_RPM_e;

    /* Polyval: '<S416>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow_n = claw_main_P.RPMref_2_FuelFlow_coefs_o[0];
    rtb_RPMref_2_FuelFlow_n = rtb_RPMref_2_FuelFlow_n * rtb_Throttle_2_RPMref_l
      + claw_main_P.RPMref_2_FuelFlow_coefs_o[1];
    rtb_RPMref_2_FuelFlow_n = rtb_RPMref_2_FuelFlow_n * rtb_Throttle_2_RPMref_l
      + claw_main_P.RPMref_2_FuelFlow_coefs_o[2];

    /* Lookup Block: '<S416>/Fuel Pump Voltage'
     * About '<S416>/Fuel Pump Voltage :'
     * Lookup Block: '<S416>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_m),
                         claw_main_P.FuelPumpVoltage_YData_a,
                         rtb_RPMref_2_FuelFlow_n,
                         claw_main_P.FuelPumpVoltage_XData_j, 25U);

    /* Gain: '<S346>/RengON' incorporates:
     *  Polyval: '<S416>/RPMref_2_EGT'
     *  Product: '<S416>/Product2'
     */
    rtb_RengON_j[0] = rtb_RPMref_2_Thrust_l * rtb_pratio_m *
      claw_main_P.RengON_Gain_l;
    rtb_RengON_j[1] = claw_main_P.RengON_Gain_l * rtb_UnScale_Ref_RPM_e;
    rtb_RengON_j[2] = claw_main_P.RengON_Gain_l * rtb_angularmomentum_e;
    rtb_RengON_j[3] = claw_main_P.RengON_Gain_l * rtb_FuelPumpVoltage_m;
    rtb_RengON_j[4] = ((((claw_main_P.RPMref_2_EGT_coefs_i[0] *
                          rtb_Throttle_2_RPMref_l +
                          claw_main_P.RPMref_2_EGT_coefs_i[1]) *
                         rtb_Throttle_2_RPMref_l +
                         claw_main_P.RPMref_2_EGT_coefs_i[2]) *
                        rtb_Throttle_2_RPMref_l +
                        claw_main_P.RPMref_2_EGT_coefs_i[3]) *
                       rtb_Throttle_2_RPMref_l +
                       claw_main_P.RPMref_2_EGT_coefs_i[4]) *
      claw_main_P.RengON_Gain_l;
    rtb_RengON_j[5] = claw_main_P.RengON_Gain_l * rtb_RPMref_2_FuelFlow_n;
    claw_main_EngineAlignment(rtb_LengON_k[0], rtb_LengON_k[2], rtb_RengON_j[0],
      rtb_RengON_j[2], &claw_main_B.sf_EngineAlignment_c,
      (rtP_EngineAlignment_claw_main *) &claw_main_P.sf_EngineAlignment_c);

    /* FromWorkspace: '<S350>/From Workspace' */
    {
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_p.TimePtr;
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_p.DataPtr;
      if (t < pTimeValues[0]) {
        rtb_FromWorkspace_g = 0.0;
      } else if (t >= pTimeValues[1]) {
        rtb_FromWorkspace_g = pDataValues[1];
      } else {
        int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK_i.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        rtb_FromWorkspace_g = pDataValues[currTimeIndex];
        claw_main_DWork.FromWorkspace_IWORK_i.PrevIndex = currTimeIndex;
      }
    }

    /* Selector: '<S353>/Value(ndx,:)1' incorporates:
     *  Constant: '<S353>/Gain2'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain2_Value_j4[(int32_T)rtb_FromWorkspace_g];
    rtb_Switch2_idx = claw_main_P.Gain2_Value_j4[7 + (int32_T)
      rtb_FromWorkspace_g];
    rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain2_Value_j4[14 + (int32_T)
      rtb_FromWorkspace_g];

    /* Sum: '<S349>/Add' incorporates:
     *  Constant: '<S346>/zero2'
     *  Constant: '<S349>/ixxb7'
     *  Constant: '<S353>/Gain1'
     *  Selector: '<S353>/Value(ndx,:)'
     *  Sum: '<S349>/Add3'
     */
    rtb_gwest_i = (claw_main_P.ixxb7_Value_i - claw_main_P.zero2_Value_b) +
      claw_main_P.Gain1_Value_nx[(int32_T)rtb_FromWorkspace_g];
    claw_main_fuelcgshiftcg_pos0(claw_main_P.zero2_Value_b,
      &claw_main_B.sf_fuelcgshiftcg_pos0_o, (rtP_fuelcgshiftcg_pos0_claw_mai *)
      &claw_main_P.sf_fuelcgshiftcg_pos0_o);

    /* Switch: '<S349>/Switch1' incorporates:
     *  Constant: '<S349>/xCG1'
     *  Constant: '<S349>/xCG4'
     */
    if (rtb_Sum_kw_idx >= claw_main_P.Switch1_Threshold_c) {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG4_Value_n[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG4_Value_n[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG4_Value_n[2];
    } else {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG1_Value_m[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG1_Value_m[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG1_Value_m[2];
    }

    /* Sum: '<S349>/Add2' incorporates:
     *  Product: '<S349>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_i * claw_main_B.sf_fuelcgshiftcg_pos0_o.y[0]
                    + rtb_delta_LLh_idx) + rtb_delta_LLh_idx_0;

    /* Sum: '<S408>/Sum6' incorporates:
     *  Constant: '<S343>/ixxb6'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_b[0] - rtb_Add2_idx;

    /* Gain: '<S414>/Gain' */
    rtb_Gain1_idx = claw_main_P.Gain_Gain_k3m * rtb_Gain1_idx_1;

    /* Sum: '<S408>/Sum7' incorporates:
     *  Constant: '<S343>/ixxb5'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_e[0] - rtb_Add2_idx;

    /* Gain: '<S413>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_be *
      rtb_MultiportSwitch2_idx_2;
    rtb_UnitDelay_nf_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_0 = rtb_Add2_idx;
    rtb_InterpolationnDusingPreLo_3 = rtb_Gain1_idx_1;

    /* Sum: '<S349>/Add2' incorporates:
     *  Product: '<S349>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_i * claw_main_B.sf_fuelcgshiftcg_pos0_o.y[1]
                    + rtb_Switch2_idx) + rtb_Gain1_idx_0;

    /* Sum: '<S408>/Sum6' incorporates:
     *  Constant: '<S343>/ixxb6'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_b[1] - rtb_Add2_idx;

    /* Gain: '<S414>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_k3m * rtb_Gain1_idx_1;

    /* Sum: '<S408>/Sum7' incorporates:
     *  Constant: '<S343>/ixxb5'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_e[1] - rtb_Add2_idx;

    /* Gain: '<S413>/Gain' */
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_be * rtb_MultiportSwitch2_idx_2;
    rtb_Switch2_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_1 = rtb_Add2_idx;
    rtb_Gain1_idx_0 = rtb_Gain1_idx_1;

    /* Sum: '<S349>/Add2' incorporates:
     *  Product: '<S349>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_i * claw_main_B.sf_fuelcgshiftcg_pos0_o.y[2]
                    + rtb_InterpolationnDusingPreLo_4) +
      rtb_InterpolationnDusingPreLo_5;

    /* Sum: '<S408>/Sum6' incorporates:
     *  Constant: '<S343>/ixxb6'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_b[2] - rtb_Add2_idx;

    /* Sum: '<S408>/Sum7' incorporates:
     *  Constant: '<S343>/ixxb5'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_e[2] - rtb_Add2_idx;

    /* Sum: '<S408>/Sum1' incorporates:
     *  Gain: '<S413>/Gain'
     *  Gain: '<S414>/Gain'
     *  Product: '<S413>/Product'
     *  Product: '<S414>/Product'
     *  Reshape: '<S413>/Reshape'
     *  Reshape: '<S414>/Reshape'
     */
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_k3m * rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_InterpolationnDusingPreLo_3;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[8] = 0.0;
    rtb_Sum4_j_0[0] = 0.0;
    rtb_Sum4_j_0[1] = rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[2] = rtb_delta_LLh_idx_0;
    rtb_Sum4_j_0[3] = claw_main_P.Gain_Gain_be * rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[4] = 0.0;
    rtb_Sum4_j_0[5] = rtb_UnitDelay_nf_idx;
    rtb_Sum4_j_0[6] = rtb_Switch2_idx;
    rtb_Sum4_j_0[7] = rtb_UnitDelay_nf_idx_0;
    rtb_Sum4_j_0[8] = 0.0;

    /* Product: '<S407>/Product' incorporates:
     *  Gain: '<S407>/Gain'
     *  Reshape: '<S407>/Reshape'
     */
    rtb_MultiportSwitch_cn_0[0] = 0.0;
    rtb_MultiportSwitch_cn_0[1] = rtb_sensors[2];
    rtb_MultiportSwitch_cn_0[2] = claw_main_P.Gain_Gain_o2 * rtb_sensors[1];
    rtb_MultiportSwitch_cn_0[3] = claw_main_P.Gain_Gain_o2 * rtb_sensors[2];
    rtb_MultiportSwitch_cn_0[4] = 0.0;
    rtb_MultiportSwitch_cn_0[5] = rtb_sensors[0];
    rtb_MultiportSwitch_cn_0[6] = rtb_sensors[1];
    rtb_MultiportSwitch_cn_0[7] = claw_main_P.Gain_Gain_o2 * rtb_sensors[0];
    rtb_MultiportSwitch_cn_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] *
        claw_main_B.sf_EngineAlignment_c.TL[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] *
        claw_main_B.sf_EngineAlignment_c.TL[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] *
        claw_main_B.sf_EngineAlignment_c.TL[2];
      rtb_Gain_e_0[i] = 0.0;
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i] * claw_main_B.sf_EngineAlignment_c.TR[0];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 3] *
        claw_main_B.sf_EngineAlignment_c.TR[1];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 6] *
        claw_main_B.sf_EngineAlignment_c.TR[2];
      rtb_Product_a[i] = 0.0;
      rtb_Product_a[i] += rtb_MultiportSwitch_cn_0[i] *
        claw_main_B.sf_EngineAlignment_c.H[0];
      rtb_Product_a[i] += rtb_MultiportSwitch_cn_0[i + 3] *
        claw_main_B.sf_EngineAlignment_c.H[1];
      rtb_Product_a[i] += rtb_MultiportSwitch_cn_0[i + 6] *
        claw_main_B.sf_EngineAlignment_c.H[2];
    }

    /* Gain: '<S345>/Gain2' incorporates:
     *  Trigonometry: '<S421>/Trigonometric Function2'
     */
    claw_main_B.alpha_k = claw_main_P.Gain2_Gain_fh * rt_atan2_snf
      (rtb_uvw_rw_idx_0, rtb_uvw_rw_idx);

    /* PreLookup: '<S361>/AlphaLookup' */
    rtb_AlphaLookup_o1_g = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.AlphaLookup_BreakpointsData_i[0], 31U, &rtb_AlphaLookup_o2_m,
      &claw_main_DWork.AlphaLookup_DWORK1_g);

    /* Gain: '<S345>/Gain3' */
    claw_main_B.beta_h = claw_main_P.Gain3_Gain_h * rtb_TrigonometricFunction1;

    /* PreLookup: '<S361>/AlphaLookup1' */
    rtb_AlphaLookup1_o1_j = plook_linxp(claw_main_B.beta_h,
      &claw_main_P.AlphaLookup1_BreakpointsData_m[0], 26U,
      &rtb_AlphaLookup1_o2_o, &claw_main_DWork.AlphaLookup1_DWORK1_m);

    /* Interpolation_n-D: '<S361>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S361>/Constant1'
     */
    max_1 = rtb_AlphaLookup_o2_m;
    frac_e[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2_o;
    frac_e[1] = max_1;
    bpIndex_e[0] = rtb_AlphaLookup_o1_g;
    bpIndex_e[1] = rtb_AlphaLookup1_o1_j;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_c3[scalarIndex];
      if (claw_main_P.Constant1_Value_c3[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_e[2] = locIndex;
      locIndex = 864U * bpIndex_e[2U];
      rtb_InterpolationUsingPreloo_fo[scalarIndex] = intrp2d_lx(&bpIndex_e[0U],
        &frac_e[0U], &claw_main_P.InterpolationUsingPrelookup__cf[locIndex], 32U);
    }

    /* Interpolation_n-D: '<S361>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S361>/Constant2'
     */
    max_1 = rtb_AlphaLookup_o2_m;
    frac_f[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2_o;
    frac_f[1] = max_1;
    bpIndex_f[0] = rtb_AlphaLookup_o1_g;
    bpIndex_f[1] = rtb_AlphaLookup1_o1_j;
    locIndex = claw_main_P.Constant2_Value_m2[0];
    if (claw_main_P.Constant2_Value_m2[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_f[2] = locIndex;
    locIndex = 864U * bpIndex_f[2U];
    rtb_delta_LLh_idx = intrp2d_lx(&bpIndex_f[0U], &frac_f[0U],
      &claw_main_P.InterpolationUsingPrelookup1_gv[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_m2[1];
    if (claw_main_P.Constant2_Value_m2[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_f[2] = locIndex;
    locIndex = 864U * bpIndex_f[2U];
    rtb_delta_LLh_idx_0 = intrp2d_lx(&bpIndex_f[0U], &frac_f[0U],
      &claw_main_P.InterpolationUsingPrelookup1_gv[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_m2[2];
    if (claw_main_P.Constant2_Value_m2[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_f[2] = locIndex;
    locIndex = 864U * bpIndex_f[2U];
    rtb_Switch2_idx = intrp2d_lx(&bpIndex_f[0U], &frac_f[0U],
      &claw_main_P.InterpolationUsingPrelookup1_gv[locIndex], 32U);

    /* Switch: '<S361>/Switch' incorporates:
     *  Constant: '<S344>/symmetry_on'
     *  Constant: '<S361>/Constant3'
     */
    if (claw_main_P.symmetry_on_Value_m != 0.0) {
      /* Assignment: '<S361>/Assignment to  Lateral' incorporates:
       *  Constant: '<S361>/Constant'
       */
      for (i = 0; i < 6; i++) {
        rtb_AssignmenttoLateral_ox[i] = claw_main_P.Constant_Value_i[i];
      }

      rtb_AssignmenttoLateral_ox[1] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLateral_ox[3] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLateral_ox[5] = rtb_Switch2_idx;
      for (i = 0; i < 6; i++) {
        rtb_Switch_ju[i] = rtb_AssignmenttoLateral_ox[i];
      }
    } else {
      for (i = 0; i < 6; i++) {
        rtb_Switch_ju[i] = claw_main_P.Constant3_Value_d[i];
      }
    }

    /* DataTypeConversion: '<S361>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace_g;
    if ((rtb_FromWorkspace_g < 4.5035996273704960E+015) && (rtb_FromWorkspace_g >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace_g + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace_g) || rtIsInf(rtb_FromWorkspace_g)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_e = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S366>/Switch Case' incorporates:
     *  ActionPort: '<S367>/Action Port'
     *  ActionPort: '<S368>/Action Port'
     *  SubSystem: '<S366>/Switch Case Action Subsystem'
     *  SubSystem: '<S366>/Switch Case Action Subsystem2'
     */
    switch (rtb_DataTypeConversion_e) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      claw__SwitchCaseActionSubsystem(claw_main_B.alpha_k, claw_main_B.beta_h,
        rtb_DataTypeConversion_e, claw_main_B.Merge_f,
        &claw_main_DWork.SwitchCaseActionSubsystem_o,
        (rtP_SwitchCaseActionSubsystem_c *)
        &claw_main_P.SwitchCaseActionSubsystem_o);
      break;

     default:
      /* Constant: '<S368>/Constant4' */
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_f[i] = claw_main_P.Constant4_Value_jw[i];
      }
      break;
    }

    /* Sum: '<S361>/Add' */
    for (i = 0; i < 6; i++) {
      rtb_Add_a[i] = (rtb_InterpolationUsingPreloo_fo[i] + rtb_Switch_ju[i]) +
        claw_main_B.Merge_f[i];
    }

    /* PreLookup: '<S391>/Prelookup' */
    rtb_Prelookup_o1_b = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup_BreakpointsData_gp[0], 31U, &rtb_Prelookup_o2_e,
      &claw_main_DWork.Prelookup_DWORK1_d);

    /* Switch: '<S391>/Switch' incorporates:
     *  Constant: '<S391>/Constant'
     *  Constant: '<S391>/Constant1'
     */
    if (rtb_RUDUPC_e >= claw_main_P.Switch_Threshold_cw) {
      rtb_Switch_ky = claw_main_P.Constant_Value_pc;
    } else {
      rtb_Switch_ky = claw_main_P.Constant1_Value_ku;
    }

    /* PreLookup: '<S391>/Prelookup1' incorporates:
     *  Product: '<S391>/Product1'
     */
    rtb_Prelookup1_o1_i = plook_linxp(claw_main_B.beta_h * rtb_Switch_ky,
      &claw_main_P.Prelookup1_BreakpointsData_ex[0], 26U, &rtb_Prelookup1_o2_hd,
      &claw_main_DWork.Prelookup1_DWORK1_d);

    /* PreLookup: '<S391>/Prelookup2' incorporates:
     *  Abs: '<S391>/Abs'
     *  Gain: '<S391>/Gain'
     */
    rtb_Prelookup2_o1_o = plook_linxp(claw_main_P.Gain_Gain_i41 * fabs
      (rtb_RUDUPC_e), &claw_main_P.Prelookup2_BreakpointsData_ek[0], 3U,
      &rtb_Prelookup2_o2_i, &claw_main_DWork.Prelookup2_DWORK1_c);

    /* Interpolation_n-D: '<S391>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S391>/Constant2'
     */
    max_1 = rtb_Prelookup_o2_e;
    frac_g[0] = max_1;
    max_1 = rtb_Prelookup1_o2_hd;
    frac_g[1] = max_1;
    max_1 = rtb_Prelookup2_o2_i;
    frac_g[2] = max_1;
    bpIndex_g[0] = rtb_Prelookup_o1_b;
    bpIndex_g[1] = rtb_Prelookup1_o1_i;
    bpIndex_g[2] = rtb_Prelookup2_o1_o;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_at[scalarIndex];
      if (claw_main_P.Constant2_Value_at[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_g[3] = locIndex;
      locIndex = 3456U * bpIndex_g[3U];
      rtb_InterpolationUsingPreloo_nw[scalarIndex] = intrp3d_lx(&bpIndex_g[0U],
        &frac_g[0U], &claw_main_P.InterpolationUsingPrelookup__cs[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_g[0]);
    }

    /* Assignment: '<S391>/Assignment to lateral' incorporates:
     *  Constant: '<S391>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral_i[i] = claw_main_P.Constant3_Value_kw[i];
    }

    rtb_Assignmenttolateral_i[1] = rtb_Switch_ky;
    rtb_Assignmenttolateral_i[3] = rtb_Switch_ky;
    rtb_Assignmenttolateral_i[5] = rtb_Switch_ky;

    /* Product: '<S388>/Product' incorporates:
     *  Constant: '<S388>/gains'
     *  Product: '<S391>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_h5[i] = rtb_InterpolationUsingPreloo_nw[i] *
        rtb_Assignmenttolateral_i[i] * claw_main_P.gains_Value_pk[i];
    }

    /* PreLookup: '<S390>/Prelookup' */
    rtb_Prelookup_o1_be = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup_BreakpointsData_k[0], 31U, &rtb_Prelookup_o2_g,
      &claw_main_DWork.Prelookup_DWORK1_p);

    /* Switch: '<S390>/Switch' incorporates:
     *  Constant: '<S390>/Constant'
     *  Constant: '<S390>/Constant1'
     */
    if (rtb_RUDLOC_l >= claw_main_P.Switch_Threshold_nt) {
      rtb_Switch_c = claw_main_P.Constant_Value_exg;
    } else {
      rtb_Switch_c = claw_main_P.Constant1_Value_ao;
    }

    /* PreLookup: '<S390>/Prelookup1' incorporates:
     *  Product: '<S390>/Product1'
     */
    rtb_Prelookup1_o1_n = plook_linxp(claw_main_B.beta_h * rtb_Switch_c,
      &claw_main_P.Prelookup1_BreakpointsData_oy[0], 26U, &rtb_Prelookup1_o2_l,
      &claw_main_DWork.Prelookup1_DWORK1_al);

    /* PreLookup: '<S390>/Prelookup2' incorporates:
     *  Abs: '<S390>/Abs'
     *  Gain: '<S390>/Gain'
     */
    rtb_Prelookup2_o1_j = plook_linxp(claw_main_P.Gain_Gain_fe * fabs
      (rtb_RUDLOC_l), &claw_main_P.Prelookup2_BreakpointsData_m[0], 3U,
      &rtb_Prelookup2_o2_j, &claw_main_DWork.Prelookup2_DWORK1_d);

    /* Interpolation_n-D: '<S390>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S390>/Constant2'
     */
    max_1 = rtb_Prelookup_o2_g;
    frac_h[0] = max_1;
    max_1 = rtb_Prelookup1_o2_l;
    frac_h[1] = max_1;
    max_1 = rtb_Prelookup2_o2_j;
    frac_h[2] = max_1;
    bpIndex_h[0] = rtb_Prelookup_o1_be;
    bpIndex_h[1] = rtb_Prelookup1_o1_n;
    bpIndex_h[2] = rtb_Prelookup2_o1_j;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_ao[scalarIndex];
      if (claw_main_P.Constant2_Value_ao[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_h[3] = locIndex;
      locIndex = 3456U * bpIndex_h[3U];
      rtb_InterpolationUsingPreloo_a0[scalarIndex] = intrp3d_lx(&bpIndex_h[0U],
        &frac_h[0U], &claw_main_P.InterpolationUsingPrelookup__o3[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__cp[0]);
    }

    /* Assignment: '<S390>/Assignment to lateral' incorporates:
     *  Constant: '<S390>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral_a[i] = claw_main_P.Constant3_Value_ep[i];
    }

    rtb_Assignmenttolateral_a[1] = rtb_Switch_c;
    rtb_Assignmenttolateral_a[3] = rtb_Switch_c;
    rtb_Assignmenttolateral_a[5] = rtb_Switch_c;

    /* Product: '<S389>/Product' incorporates:
     *  Constant: '<S389>/gains'
     *  Product: '<S390>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_mq[i] = rtb_InterpolationUsingPreloo_a0[i] *
        rtb_Assignmenttolateral_a[i] * claw_main_P.gains_Value_i0[i];
    }

    /* PreLookup: '<S370>/Prelookup1' */
    rtb_Prelookup1_o1_h = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup1_BreakpointsData_m[0], 31U, &rtb_Prelookup1_o2_i,
      &claw_main_DWork.Prelookup1_DWORK1_n);

    /* PreLookup: '<S370>/Prelookup2' incorporates:
     *  Gain: '<S370>/Gain2'
     */
    rtb_Prelookup2_o1_po = plook_linxp(claw_main_P.Gain2_Gain_bf *
      claw_main_B.beta_h, &claw_main_P.Prelookup2_BreakpointsData_dg[0], 26U,
      &rtb_Prelookup2_o2_l, &claw_main_DWork.Prelookup2_DWORK1_j);

    /* PreLookup: '<S370>/Prelookup3' */
    rtb_Prelookup3_o1_g = plook_linxp(rtb_dL_Ail_m + rtb_AILLC_a,
      &claw_main_P.Prelookup3_BreakpointsData_mc[0], 6U, &rtb_Prelookup3_o2_f,
      &claw_main_DWork.Prelookup3_DWORK1_d);

    /* Interpolation_n-D: '<S370>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S370>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_i;
    frac_i[0] = max_1;
    max_1 = rtb_Prelookup2_o2_l;
    frac_i[1] = max_1;
    max_1 = rtb_Prelookup3_o2_f;
    frac_i[2] = max_1;
    bpIndex_i[0] = rtb_Prelookup1_o1_h;
    bpIndex_i[1] = rtb_Prelookup2_o1_po;
    bpIndex_i[2] = rtb_Prelookup3_o1_g;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_ck[scalarIndex];
      if (claw_main_P.Constant3_Value_ck[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_i[3] = locIndex;
      locIndex = 6048U * bpIndex_i[3U];
      rtb_InterpolationUsingPreloo_hj[scalarIndex] = intrp3d_lx(&bpIndex_i[0U],
        &frac_i[0U], &claw_main_P.InterpolationUsingPrelookup__gi[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__b4[0]);
    }

    /* Gain: '<S370>/Negate Lateral' */
    for (i = 0; i < 6; i++) {
      rtb_NegateLateral_n[i] = claw_main_P.NegateLateral_Gain_p[i] *
        rtb_InterpolationUsingPreloo_hj[i];
    }

    /* PreLookup: '<S370>/Prelookup4' */
    rtb_Prelookup4_o1_l = plook_linxp(claw_main_B.beta_h,
      &claw_main_P.Prelookup4_BreakpointsData_mk[0], 26U, &rtb_Prelookup4_o2_j,
      &claw_main_DWork.Prelookup4_DWORK1_f5);

    /* PreLookup: '<S370>/Prelookup5' */
    rtb_Prelookup5_o1_o = plook_linxp(rtb_dR_Ail_p + rtb_AILRC_d,
      &claw_main_P.Prelookup5_BreakpointsData_ky[0], 6U, &rtb_Prelookup5_o2_b2,
      &claw_main_DWork.Prelookup5_DWORK1_o);

    /* Interpolation_n-D: '<S370>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S370>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_i;
    frac_j[0] = max_1;
    max_1 = rtb_Prelookup4_o2_j;
    frac_j[1] = max_1;
    max_1 = rtb_Prelookup5_o2_b2;
    frac_j[2] = max_1;
    bpIndex_j[0] = rtb_Prelookup1_o1_h;
    bpIndex_j[1] = rtb_Prelookup4_o1_l;
    bpIndex_j[2] = rtb_Prelookup5_o1_o;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_fp[scalarIndex];
      if (claw_main_P.Constant1_Value_fp[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_j[3] = locIndex;
      locIndex = 6048U * bpIndex_j[3U];
      rtb_InterpolationUsingPrelook_j[scalarIndex] = intrp3d_lx(&bpIndex_j[0U],
        &frac_j[0U], &claw_main_P.InterpolationUsingPrelookup1__b[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_ec[0]);
    }

    /* PreLookup: '<S396>/Prelookup1' */
    rtb_Prelookup1_o1_jh = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup1_BreakpointsData_m0[0], 31U, &rtb_Prelookup1_o2_cb,
      &claw_main_DWork.Prelookup1_DWORK1_p);

    /* PreLookup: '<S396>/Prelookup2' incorporates:
     *  Gain: '<S396>/Gain2'
     */
    rtb_Prelookup2_o1_ne = plook_linxp(claw_main_P.Gain2_Gain_lx *
      claw_main_B.beta_h, &claw_main_P.Prelookup2_BreakpointsData_bk[0], 26U,
      &rtb_Prelookup2_o2_o, &claw_main_DWork.Prelookup2_DWORK1_m);

    /* PreLookup: '<S396>/Prelookup3' */
    rtb_Prelookup3_o1_f = plook_linxp(rtb_SPLLIBC_k,
      &claw_main_P.Prelookup3_BreakpointsData_kd[0], 2U, &rtb_Prelookup3_o2_k,
      &claw_main_DWork.Prelookup3_DWORK1_a);

    /* Interpolation_n-D: '<S396>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S396>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_cb;
    frac_k[0] = max_1;
    max_1 = rtb_Prelookup2_o2_o;
    frac_k[1] = max_1;
    max_1 = rtb_Prelookup3_o2_k;
    frac_k[2] = max_1;
    bpIndex_k[0] = rtb_Prelookup1_o1_jh;
    bpIndex_k[1] = rtb_Prelookup2_o1_ne;
    bpIndex_k[2] = rtb_Prelookup3_o1_f;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_ke[scalarIndex];
      if (claw_main_P.Constant3_Value_ke[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_k[3] = locIndex;
      locIndex = 2592U * bpIndex_k[3U];
      rtb_InterpolationUsingPreloo_ex[scalarIndex] = intrp3d_lx(&bpIndex_k[0U],
        &frac_k[0U], &claw_main_P.InterpolationUsingPrelookup__eg[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__eu[0]);
    }

    /* Product: '<S393>/Product' incorporates:
     *  Constant: '<S393>/gains'
     *  Gain: '<S396>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_n5[i] = claw_main_P.NegateLateral_Gain_h[i] *
        rtb_InterpolationUsingPreloo_ex[i] * claw_main_P.gains_Value_ey[i];
    }

    /* PreLookup: '<S397>/Prelookup1' */
    rtb_Prelookup1_o1_d = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup1_BreakpointsData_n[0], 31U, &rtb_Prelookup1_o2_o,
      &claw_main_DWork.Prelookup1_DWORK1_nz);

    /* PreLookup: '<S397>/Prelookup2' incorporates:
     *  Gain: '<S397>/Gain2'
     */
    rtb_Prelookup2_o1_fc = plook_linxp(claw_main_P.Gain2_Gain_ci *
      claw_main_B.beta_h, &claw_main_P.Prelookup2_BreakpointsData_g[0], 26U,
      &rtb_Prelookup2_o2_is, &claw_main_DWork.Prelookup2_DWORK1_cx);

    /* PreLookup: '<S397>/Prelookup3' */
    rtb_Prelookup3_o1_gn = plook_linxp(rtb_SPLLOBC_l,
      &claw_main_P.Prelookup3_BreakpointsData_c[0], 2U, &rtb_Prelookup3_o2_n,
      &claw_main_DWork.Prelookup3_DWORK1_n);

    /* Interpolation_n-D: '<S397>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S397>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_o;
    frac_l[0] = max_1;
    max_1 = rtb_Prelookup2_o2_is;
    frac_l[1] = max_1;
    max_1 = rtb_Prelookup3_o2_n;
    frac_l[2] = max_1;
    bpIndex_l[0] = rtb_Prelookup1_o1_d;
    bpIndex_l[1] = rtb_Prelookup2_o1_fc;
    bpIndex_l[2] = rtb_Prelookup3_o1_gn;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_h[scalarIndex];
      if (claw_main_P.Constant3_Value_h[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_l[3] = locIndex;
      locIndex = 2592U * bpIndex_l[3U];
      rtb_InterpolationUsingPrelook_k[scalarIndex] = intrp3d_lx(&bpIndex_l[0U],
        &frac_l[0U], &claw_main_P.InterpolationUsingPrelookup__d1[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__hb[0]);
    }

    /* Product: '<S394>/Product' incorporates:
     *  Constant: '<S394>/gains'
     *  Gain: '<S397>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_f[i] = claw_main_P.NegateLateral_Gain_lc[i] *
        rtb_InterpolationUsingPrelook_k[i] * claw_main_P.gains_Value_n[i];
    }

    /* PreLookup: '<S396>/Prelookup4' */
    rtb_Prelookup4_o1_a = plook_linxp(claw_main_B.beta_h,
      &claw_main_P.Prelookup4_BreakpointsData_my[0], 26U, &rtb_Prelookup4_o2_fh,
      &claw_main_DWork.Prelookup4_DWORK1_kl);

    /* PreLookup: '<S396>/Prelookup5' */
    rtb_Prelookup5_o1_at = plook_linxp(rtb_orderatts_i_idx,
      &claw_main_P.Prelookup5_BreakpointsData_g3[0], 2U, &rtb_Prelookup5_o2_d,
      &claw_main_DWork.Prelookup5_DWORK1_lf);

    /* Interpolation_n-D: '<S396>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S396>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_cb;
    frac_m[0] = max_1;
    max_1 = rtb_Prelookup4_o2_fh;
    frac_m[1] = max_1;
    max_1 = rtb_Prelookup5_o2_d;
    frac_m[2] = max_1;
    bpIndex_m[0] = rtb_Prelookup1_o1_jh;
    bpIndex_m[1] = rtb_Prelookup4_o1_a;
    bpIndex_m[2] = rtb_Prelookup5_o1_at;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_av[scalarIndex];
      if (claw_main_P.Constant1_Value_av[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_m[3] = locIndex;
      locIndex = 2592U * bpIndex_m[3U];
      rtb_InterpolationUsingPrelook_d[scalarIndex] = intrp3d_lx(&bpIndex_m[0U],
        &frac_m[0U], &claw_main_P.InterpolationUsingPrelookup1_hx[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_ee[0]);
    }

    /* Product: '<S392>/Product' incorporates:
     *  Constant: '<S392>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_lk[i] = rtb_InterpolationUsingPrelook_d[i] *
        claw_main_P.gains_Value_go[i];
    }

    /* PreLookup: '<S397>/Prelookup4' */
    rtb_Prelookup4_o1_b = plook_linxp(claw_main_B.beta_h,
      &claw_main_P.Prelookup4_BreakpointsData_kc[0], 26U, &rtb_Prelookup4_o2_i,
      &claw_main_DWork.Prelookup4_DWORK1_i);

    /* PreLookup: '<S397>/Prelookup5' */
    rtb_Prelookup5_o1_n = plook_linxp(rtb_Switch_d_idx_0,
      &claw_main_P.Prelookup5_BreakpointsData_gr[0], 2U, &rtb_Prelookup5_o2_e,
      &claw_main_DWork.Prelookup5_DWORK1_lk);

    /* Interpolation_n-D: '<S397>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S397>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_o;
    frac_n[0] = max_1;
    max_1 = rtb_Prelookup4_o2_i;
    frac_n[1] = max_1;
    max_1 = rtb_Prelookup5_o2_e;
    frac_n[2] = max_1;
    bpIndex_n[0] = rtb_Prelookup1_o1_d;
    bpIndex_n[1] = rtb_Prelookup4_o1_b;
    bpIndex_n[2] = rtb_Prelookup5_o1_n;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_cv[scalarIndex];
      if (claw_main_P.Constant1_Value_cv[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_n[3] = locIndex;
      locIndex = 2592U * bpIndex_n[3U];
      rtb_InterpolationUsingPreloo_b4[scalarIndex] = intrp3d_lx(&bpIndex_n[0U],
        &frac_n[0U], &claw_main_P.InterpolationUsingPrelookup1__c[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_be[0]);
    }

    /* Product: '<S395>/Product' incorporates:
     *  Constant: '<S395>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_d0[i] = rtb_InterpolationUsingPreloo_b4[i] *
        claw_main_P.gains_Value_nq[i];
    }

    /* PreLookup: '<S371>/Prelookup1' */
    rtb_Prelookup1_o1_gm = plook_linxp(claw_main_B.alpha_k,
      &claw_main_P.Prelookup1_BreakpointsData_eq[0], 31U, &rtb_Prelookup1_o2_e,
      &claw_main_DWork.Prelookup1_DWORK1_d1);

    /* PreLookup: '<S371>/Prelookup2' */
    rtb_Prelookup2_o1_m = plook_linxp(claw_main_B.beta_h,
      &claw_main_P.Prelookup2_BreakpointsData_m1[0], 26U, &rtb_Prelookup2_o2_p,
      &claw_main_DWork.Prelookup2_DWORK1_id);

    /* PreLookup: '<S371>/Prelookup3' */
    rtb_Prelookup3_o1_kp = plook_linxp(rtb_Switch_d_idx_1,
      &claw_main_P.Prelookup3_BreakpointsData_f[0], 3U, &rtb_Prelookup3_o2_d,
      &claw_main_DWork.Prelookup3_DWORK1_b);

    /* PreLookup: '<S382>/Prelookup4' incorporates:
     *  Constant: '<S371>/Constant1'
     */
    rtb_Prelookup4_o1_i = plook_linxp(claw_main_P.Constant1_Value_i2,
      &claw_main_P.Prelookup4_BreakpointsData_c[0], 5U, &rtb_Prelookup4_o2_o,
      &claw_main_DWork.Prelookup4_DWORK1_i5);

    /* Interpolation_n-D: '<S382>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S382>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_e;
    frac_o[0] = max_1;
    max_1 = rtb_Prelookup2_o2_p;
    frac_o[1] = max_1;
    max_1 = rtb_Prelookup3_o2_d;
    frac_o[2] = max_1;
    max_1 = rtb_Prelookup4_o2_o;
    frac_o[3] = max_1;
    bpIndex_o[0] = rtb_Prelookup1_o1_gm;
    bpIndex_o[1] = rtb_Prelookup2_o1_m;
    bpIndex_o[2] = rtb_Prelookup3_o1_kp;
    bpIndex_o[3] = rtb_Prelookup4_o1_i;
    locIndex = claw_main_P.Constant2_Value_e2[0];
    if (claw_main_P.Constant2_Value_e2[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_o[4] = locIndex;
    locIndex = 20736U * bpIndex_o[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_o[0U], &frac_o[0U],
      &claw_main_P.InterpolationUsingPrelookup__ht[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_d_f[0]);
    locIndex = claw_main_P.Constant2_Value_e2[1];
    if (claw_main_P.Constant2_Value_e2[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_o[4] = locIndex;
    locIndex = 20736U * bpIndex_o[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_o[0U], &frac_o[0U],
      &claw_main_P.InterpolationUsingPrelookup__ht[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_d_f[0]);
    locIndex = claw_main_P.Constant2_Value_e2[2];
    if (claw_main_P.Constant2_Value_e2[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_o[4] = locIndex;
    locIndex = 20736U * bpIndex_o[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_o[0U], &frac_o[0U],
      &claw_main_P.InterpolationUsingPrelookup__ht[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_d_f[0]);

    /* Assignment: '<S382>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S382>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_l[i] = claw_main_P.Constant_Value_pe[i];
    }

    rtb_AssignmenttoLongitudinal_l[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_l[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_l[4] = rtb_Switch2_idx;

    /* PreLookup: '<S381>/Prelookup4' */
    rtb_Prelookup4_o1_p = plook_linxp(rtb_ELLOBC_g,
      &claw_main_P.Prelookup4_BreakpointsData_h[0], 5U, &rtb_Prelookup4_o2_iq,
      &claw_main_DWork.Prelookup4_DWORK1_b);

    /* Interpolation_n-D: '<S381>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S381>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_e;
    frac_p[0] = max_1;
    max_1 = rtb_Prelookup2_o2_p;
    frac_p[1] = max_1;
    max_1 = rtb_Prelookup3_o2_d;
    frac_p[2] = max_1;
    max_1 = rtb_Prelookup4_o2_iq;
    frac_p[3] = max_1;
    bpIndex_p[0] = rtb_Prelookup1_o1_gm;
    bpIndex_p[1] = rtb_Prelookup2_o1_m;
    bpIndex_p[2] = rtb_Prelookup3_o1_kp;
    bpIndex_p[3] = rtb_Prelookup4_o1_p;
    locIndex = claw_main_P.Constant2_Value_cj[0];
    if (claw_main_P.Constant2_Value_cj[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_p[4] = locIndex;
    locIndex = 20736U * bpIndex_p[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_p[0U], &frac_p[0U],
      &claw_main_P.InterpolationUsingPrelookup__fk[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__gk[0]);
    locIndex = claw_main_P.Constant2_Value_cj[1];
    if (claw_main_P.Constant2_Value_cj[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_p[4] = locIndex;
    locIndex = 20736U * bpIndex_p[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_p[0U], &frac_p[0U],
      &claw_main_P.InterpolationUsingPrelookup__fk[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__gk[0]);
    locIndex = claw_main_P.Constant2_Value_cj[2];
    if (claw_main_P.Constant2_Value_cj[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_p[4] = locIndex;
    locIndex = 20736U * bpIndex_p[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_p[0U], &frac_p[0U],
      &claw_main_P.InterpolationUsingPrelookup__fk[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__gk[0]);

    /* Assignment: '<S381>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S381>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_c[i] = claw_main_P.Constant_Value_ap[i];
    }

    rtb_AssignmenttoLongitudinal_c[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_c[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_c[4] = rtb_Switch2_idx;

    /* Gain: '<S378>/Gain' incorporates:
     *  Gain: '<S371>/Gain'
     *  Sum: '<S371>/Add'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_c[i] -
                  rtb_AssignmenttoLongitudinal_l[i]) * claw_main_P.Gain_Gain_bz;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_l0[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_l0[i] += claw_main_P.Gain_Gain_d3[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S383>/Prelookup4' */
    rtb_Prelookup4_o1_it = plook_linxp(rtb_ELLIBC_o,
      &claw_main_P.Prelookup4_BreakpointsData_b[0], 5U, &rtb_Prelookup4_o2_kp,
      &claw_main_DWork.Prelookup4_DWORK1_a);

    /* Interpolation_n-D: '<S383>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S383>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_e;
    frac_q[0] = max_1;
    max_1 = rtb_Prelookup2_o2_p;
    frac_q[1] = max_1;
    max_1 = rtb_Prelookup3_o2_d;
    frac_q[2] = max_1;
    max_1 = rtb_Prelookup4_o2_kp;
    frac_q[3] = max_1;
    bpIndex_q[0] = rtb_Prelookup1_o1_gm;
    bpIndex_q[1] = rtb_Prelookup2_o1_m;
    bpIndex_q[2] = rtb_Prelookup3_o1_kp;
    bpIndex_q[3] = rtb_Prelookup4_o1_it;
    locIndex = claw_main_P.Constant2_Value_cez[0];
    if (claw_main_P.Constant2_Value_cez[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_q[4] = locIndex;
    locIndex = 20736U * bpIndex_q[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_q[0U], &frac_q[0U],
      &claw_main_P.InterpolationUsingPrelookup__it[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__mz[0]);
    locIndex = claw_main_P.Constant2_Value_cez[1];
    if (claw_main_P.Constant2_Value_cez[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_q[4] = locIndex;
    locIndex = 20736U * bpIndex_q[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_q[0U], &frac_q[0U],
      &claw_main_P.InterpolationUsingPrelookup__it[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__mz[0]);
    locIndex = claw_main_P.Constant2_Value_cez[2];
    if (claw_main_P.Constant2_Value_cez[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_q[4] = locIndex;
    locIndex = 20736U * bpIndex_q[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_q[0U], &frac_q[0U],
      &claw_main_P.InterpolationUsingPrelookup__it[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__mz[0]);

    /* Assignment: '<S383>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S383>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_k[i] = claw_main_P.Constant_Value_fu[i];
    }

    rtb_AssignmenttoLongitudinal_k[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_k[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_k[4] = rtb_Switch2_idx;

    /* Gain: '<S377>/Gain' incorporates:
     *  Gain: '<S371>/Gain1'
     *  Sum: '<S371>/Add1'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_k[i] -
                  rtb_AssignmenttoLongitudinal_l[i]) * claw_main_P.Gain1_Gain_dt;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_oz[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_oz[i] += claw_main_P.Gain_Gain_bh[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S385>/Prelookup4' */
    rtb_Prelookup4_o1_jp = plook_linxp(rtb_ELRIBC_o,
      &claw_main_P.Prelookup4_BreakpointsData_bg[0], 5U, &rtb_Prelookup4_o2_hz,
      &claw_main_DWork.Prelookup4_DWORK1_ga);

    /* Interpolation_n-D: '<S385>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S385>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_e;
    frac_r[0] = max_1;
    max_1 = rtb_Prelookup2_o2_p;
    frac_r[1] = max_1;
    max_1 = rtb_Prelookup3_o2_d;
    frac_r[2] = max_1;
    max_1 = rtb_Prelookup4_o2_hz;
    frac_r[3] = max_1;
    bpIndex_r[0] = rtb_Prelookup1_o1_gm;
    bpIndex_r[1] = rtb_Prelookup2_o1_m;
    bpIndex_r[2] = rtb_Prelookup3_o1_kp;
    bpIndex_r[3] = rtb_Prelookup4_o1_jp;
    locIndex = claw_main_P.Constant2_Value_gh[0];
    if (claw_main_P.Constant2_Value_gh[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_r[4] = locIndex;
    locIndex = 20736U * bpIndex_r[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_r[0U], &frac_r[0U],
      &claw_main_P.InterpolationUsingPrelookup__eq[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ik[0]);
    locIndex = claw_main_P.Constant2_Value_gh[1];
    if (claw_main_P.Constant2_Value_gh[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_r[4] = locIndex;
    locIndex = 20736U * bpIndex_r[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_r[0U], &frac_r[0U],
      &claw_main_P.InterpolationUsingPrelookup__eq[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ik[0]);
    locIndex = claw_main_P.Constant2_Value_gh[2];
    if (claw_main_P.Constant2_Value_gh[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_r[4] = locIndex;
    locIndex = 20736U * bpIndex_r[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_r[0U], &frac_r[0U],
      &claw_main_P.InterpolationUsingPrelookup__eq[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ik[0]);

    /* Assignment: '<S385>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S385>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_hb[i] = claw_main_P.Constant_Value_ny[i];
    }

    rtb_AssignmenttoLongitudinal_hb[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_hb[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_hb[4] = rtb_Switch2_idx;

    /* Gain: '<S379>/Gain' incorporates:
     *  Gain: '<S371>/Gain2'
     *  Sum: '<S371>/Add2'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_hb[i] -
                  rtb_AssignmenttoLongitudinal_l[i]) * claw_main_P.Gain2_Gain_do;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_ha[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_ha[i] += claw_main_P.Gain_Gain_oh[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S384>/Prelookup4' */
    rtb_Prelookup4_o1_m = plook_linxp(rtb_ELROBC_g,
      &claw_main_P.Prelookup4_BreakpointsData_j4[0], 5U, &rtb_Prelookup4_o2_n,
      &claw_main_DWork.Prelookup4_DWORK1_kf);

    /* Interpolation_n-D: '<S384>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S384>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_e;
    frac_s[0] = max_1;
    max_1 = rtb_Prelookup2_o2_p;
    frac_s[1] = max_1;
    max_1 = rtb_Prelookup3_o2_d;
    frac_s[2] = max_1;
    max_1 = rtb_Prelookup4_o2_n;
    frac_s[3] = max_1;
    bpIndex_s[0] = rtb_Prelookup1_o1_gm;
    bpIndex_s[1] = rtb_Prelookup2_o1_m;
    bpIndex_s[2] = rtb_Prelookup3_o1_kp;
    bpIndex_s[3] = rtb_Prelookup4_o1_m;
    locIndex = claw_main_P.Constant2_Value_nm[0];
    if (claw_main_P.Constant2_Value_nm[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_s[4] = locIndex;
    locIndex = 20736U * bpIndex_s[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_s[0U], &frac_s[0U],
      &claw_main_P.InterpolationUsingPrelookup_a2x[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kp[0]);
    locIndex = claw_main_P.Constant2_Value_nm[1];
    if (claw_main_P.Constant2_Value_nm[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_s[4] = locIndex;
    locIndex = 20736U * bpIndex_s[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_s[0U], &frac_s[0U],
      &claw_main_P.InterpolationUsingPrelookup_a2x[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kp[0]);
    locIndex = claw_main_P.Constant2_Value_nm[2];
    if (claw_main_P.Constant2_Value_nm[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_s[4] = locIndex;
    locIndex = 20736U * bpIndex_s[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_s[0U], &frac_s[0U],
      &claw_main_P.InterpolationUsingPrelookup_a2x[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kp[0]);

    /* Assignment: '<S384>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S384>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_p[i] = claw_main_P.Constant_Value_cz[i];
    }

    rtb_AssignmenttoLongitudinal_p[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_p[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_p[4] = rtb_Switch2_idx;

    /* Gain: '<S380>/Gain' incorporates:
     *  Gain: '<S371>/Gain3'
     *  Sum: '<S371>/Add3'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_p[i] -
                  rtb_AssignmenttoLongitudinal_l[i]) * claw_main_P.Gain3_Gain_ps;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_hp[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_hp[i] += claw_main_P.Gain_Gain_dk[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }

      /* Gain: '<S372>/Gain' */
      rtb_Gain_ill[i] = claw_main_P.Gain_Gain_a1[i] * rtb_Sum_ow_idx;

      /* Gain: '<S372>/Gain1' */
      rtb_Gain1_cz[i] = claw_main_P.Gain1_Gain_lc[i] * rtb_Switch_d_idx;

      /* Gain: '<S372>/Gain2' */
      rtb_Gain2_iw[i] = claw_main_P.Gain2_Gain_ev[i] * rtb_Sum_ow_idx_0;

      /* Gain: '<S372>/Gain3' */
      rtb_Gain3_e[i] = claw_main_P.Gain3_Gain_nb[i] * rtb_Sum_ow_idx_1;
    }

    /* S-Function (sfun_idxsearch): '<S373>/PreLookup Index Search1' */
    scalarPrevIndex_0 = claw_main_DWork.PreLookupIndexSearch1_MODE_g;
    i = plook_s32dd_binxp(claw_main_B.alpha_k,
                          &claw_main_P.PreLookupIndexSearch1_bpData_f[0], 31U,
                          &scalarFraction_3, &scalarPrevIndex_0);
    rtb_delta_LLh_idx = scalarFraction_3;

    /* S-Function (sfun_kflookupnd): '<S373>/TableLookup' incorporates:
     *  Constant: '<S373>/Constant2'
     *  DataTypeConversion: '<S373>/Data Type Conversion2'
     *  RelationalOperator: '<S386>/Compare'
     */
    if (i > 30) {
      max_1 = 30.0;
    } else if (i >= 0) {
      max_1 = (real_T)i;
    } else {
      max_1 = 0.0;
    }

    i = (int32_T)max_1;
    yOffset_0 = (rtb_Sum_kw_idx != 0.0);
    if (claw_main_P.Constant2_Value_ez[0] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_ez[0];
    }

    rtb_delta_LLh_idx_0 = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_n[(scalarIndex << 6U) + (yOffset_0 << 5)]);
    if (claw_main_P.Constant2_Value_ez[1] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_ez[1];
    }

    rtb_Switch2_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_n[(scalarIndex << 6U) + (yOffset_0 << 5)]);
    if (claw_main_P.Constant2_Value_ez[2] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_ez[2];
    }

    rtb_delta_LLh_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_n[(scalarIndex << 6U) + (yOffset_0 << 5)]);

    /* Assignment: '<S373>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S373>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_j[i] = claw_main_P.Constant_Value_lsc[i];
    }

    rtb_AssignmenttoLongitudinal_j[0] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_j[2] = rtb_Switch2_idx;
    rtb_AssignmenttoLongitudinal_j[4] = rtb_delta_LLh_idx;
    claw_main_ImplementDamageModels(rtb_Product_h5, rtb_Product_mq,
      rtb_NegateLateral_n, rtb_InterpolationUsingPrelook_j, rtb_Product_n5,
      rtb_Product_f, rtb_Product_lk, rtb_Product_d0,
      rtb_AssignmenttoLongitudinal_l, rtb_Gain_l0, rtb_Gain_oz, rtb_Gain_ha,
      rtb_Gain_hp, rtb_Gain_ill, rtb_Gain1_cz, rtb_Gain2_iw, rtb_Gain3_e,
      rtb_AssignmenttoLongitudinal_j, rtb_FromWorkspace_g,
      &claw_main_B.sf_ImplementDamageModels_l);

    /* Reshape: '<S374>/Reshape' */
    for (i = 0; i < 6; i++) {
      rtb_Reshape_o[i] = claw_main_B.sf_ImplementDamageModels_l.dC6[i];
    }

    /* Gain: '<S345>/Gain5' */
    rtb_tas_o = claw_main_P.Gain5_Gain_n * max_0;

    /* DataTypeConversion: '<S364>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace_g;
    if ((rtb_FromWorkspace_g < 4.5035996273704960E+015) && (rtb_FromWorkspace_g >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace_g + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace_g) || rtIsInf(rtb_FromWorkspace_g)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_p = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S364>/Switch Case' incorporates:
     *  ActionPort: '<S398>/Action Port'
     *  ActionPort: '<S399>/Action Port'
     *  SubSystem: '<S364>/Forced Oscillation with Damage Increments'
     *  SubSystem: '<S364>/Rotary Blended  UnDamaged Case'
     */
    switch (rtb_DataTypeConversion_p) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      ForcedOscillationwithDamageIn_o(claw_main_B.alpha_k,
        rtb_DataTypeConversion_p, rtb_tas_o, rtb_sensors, claw_main_P.B_Value_o,
        claw_main_P.Cbar_Value_k, claw_main_B.Merge_nz,
        &claw_main_B.ForcedOscillationwithDamageI_oa,
        &claw_main_DWork.ForcedOscillationwithDamageI_oa,
        (rtP_ForcedOscillationwithDama_l *)
        &claw_main_P.ForcedOscillationwithDamageI_oa);
      break;

     default:
      cl_RotaryBlendedUnDamagedCase_k(claw_main_B.alpha_k, rtb_tas_o,
        claw_main_B.beta_h, rtb_sensors, claw_main_P.B_Value_o,
        claw_main_P.Cbar_Value_k, claw_main_B.Merge_nz,
        &claw_main_B.RotaryBlendedUnDamagedCase_k,
        &claw_main_DWork.RotaryBlendedUnDamagedCase_k,
        (rtP_RotaryBlendedUnDamagedCas_m *)
        &claw_main_P.RotaryBlendedUnDamagedCase_k);
      break;
    }

    /* Gain: '<S362>/Gain2' incorporates:
     *  Product: '<S362>/Product'
     *  Sum: '<S344>/Sum8'
     */
    for (i = 0; i < 6; i++) {
      rtb_Gain2_oj[i] = ((rtb_Add_a[i] + rtb_Reshape_o[i]) +
                         claw_main_B.Merge_nz[i]) * rtb_qbar *
        claw_main_P.Gain2_Gain_lg;
    }

    /* Sum: '<S362>/Sum' incorporates:
     *  Constant: '<S343>/xCG1'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_e[0] - rtb_Add2_idx_0;

    /* Gain: '<S369>/Gain' */
    rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_ef * rtb_Switch2_idx;
    rtb_Gain1_idx_1 = rtb_Switch2_idx;

    /* Sum: '<S362>/Sum' incorporates:
     *  Constant: '<S343>/xCG1'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_e[1] - rtb_Add2_idx_1;

    /* Gain: '<S369>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_ef * rtb_Switch2_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch2_idx;

    /* Sum: '<S362>/Sum' incorporates:
     *  Constant: '<S343>/xCG1'
     *  Reshape: '<S349>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_e[2] - rtb_Add2_idx;

    /* Sum: '<S337>/Sum' incorporates:
     *  Gain: '<S362>/Reference Lengths'
     *  Gain: '<S369>/Gain'
     *  Product: '<S369>/Product'
     *  Reshape: '<S369>/Reshape'
     *  Reshape: '<S369>/Reshape1'
     *  Sum: '<S346>/Sum'
     *  Sum: '<S362>/Sum1'
     */
    min_6[0] = claw_main_B.sf_EngineAlignment_c.T[0];
    min_6[1] = claw_main_B.sf_EngineAlignment_c.T[1];
    min_6[2] = claw_main_B.sf_EngineAlignment_c.T[2];
    min_6[3] = (rtb_dircos_0[0] + rtb_Gain_e_0[0]) + rtb_Product_a[0];
    min_6[4] = (rtb_dircos_0[1] + rtb_Gain_e_0[1]) + rtb_Product_a[1];
    min_6[5] = (rtb_dircos_0[2] + rtb_Gain_e_0[2]) + rtb_Product_a[2];
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_ef * rtb_Switch2_idx;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[6] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Gain2_oj[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Gain2_oj[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Gain2_oj[2];
    }

    rtb_Gain2_n_0[0] = rtb_Gain2_oj[0];
    rtb_Gain2_n_0[1] = rtb_Gain2_oj[1];
    rtb_Gain2_n_0[2] = rtb_Gain2_oj[2];
    rtb_Gain2_n_0[3] = claw_main_P.ReferenceLengths_Gain_jz[0] * rtb_Gain2_oj[3]
      + rtb_dircos_0[0];
    rtb_Gain2_n_0[4] = claw_main_P.ReferenceLengths_Gain_jz[1] * rtb_Gain2_oj[4]
      + rtb_dircos_0[1];
    rtb_Gain2_n_0[5] = claw_main_P.ReferenceLengths_Gain_jz[2] * rtb_Gain2_oj[5]
      + rtb_dircos_0[2];
    for (i = 0; i < 6; i++) {
      rtb_Sum_hl[i] = min_6[i] + rtb_Gain2_n_0[i];
    }

    /* Product: '<S336>/Product2' */
    for (i = 0; i < 3; i++) {
      rtb_Product2_e4[i] = 0.0;
      rtb_Product2_e4[i] += rtb_inertia[i] * rtb_sensors[0];
      rtb_Product2_e4[i] += rtb_inertia[i + 3] * rtb_sensors[1];
      rtb_Product2_e4[i] += rtb_inertia[i + 6] * rtb_sensors[2];
    }

    /* Product: '<S336>/Product3' incorporates:
     *  Product: '<S339>/Product'
     *  Product: '<S339>/Product1'
     *  Product: '<S341>/Product'
     *  Product: '<S341>/Product1'
     *  Sum: '<S336>/Sum1'
     *  Sum: '<S339>/Sum'
     *  Sum: '<S341>/Sum'
     */
    rtb_delta_LLh_idx = (rtb_Sum_hl[3] - (rtb_sensors[1] * 0.0 - rtb_sensors[2] *
      0.0)) - (rtb_sensors[1] * rtb_Product2_e4[2] - rtb_sensors[2] *
               rtb_Product2_e4[1]);
    rtb_delta_LLh_idx_0 = (rtb_Sum_hl[4] - (rtb_sensors[2] * 0.0 - rtb_sensors[0]
      * 0.0)) - (rtb_sensors[2] * rtb_Product2_e4[0] - rtb_sensors[0] *
                 rtb_Product2_e4[2]);
    rtb_Switch2_idx = (rtb_Sum_hl[5] - (rtb_sensors[0] * 0.0 - rtb_sensors[1] *
      0.0)) - (rtb_sensors[0] * rtb_Product2_e4[1] - rtb_sensors[1] *
               rtb_Product2_e4[0]);

    /* Sum: '<S336>/Sum' incorporates:
     *  Gain: '<S334>/g'
     *  Product: '<S334>/Product1'
     *  Product: '<S336>/Force -> Acceleration'
     *  Product: '<S340>/Product'
     *  Product: '<S340>/Product1'
     *  Selector: '<S334>/dircos(:,3)'
     *  Sum: '<S334>/Sum'
     *  Sum: '<S340>/Sum'
     */
    rtb_Product1_b_idx_1 = (claw_main_P.g_Gain_m * rtb_dircos[6] *
      claw_main_B.mass + rtb_Sum_hl[0]) * (1.0 / claw_main_B.mass) -
      (rtb_sensors[1] * rtb_uvw[2] - rtb_sensors[2] * rtb_uvw[1]);
    rtb_Sum_h_idx = (claw_main_P.g_Gain_m * rtb_dircos[7] * claw_main_B.mass +
                     rtb_Sum_hl[1]) * (1.0 / claw_main_B.mass) - (rtb_sensors[2]
      * rtb_uvw[0] - rtb_sensors[0] * rtb_uvw[2]);
    rtb_Assignment_l_idx = (claw_main_P.g_Gain_m * rtb_dircos[8] *
      claw_main_B.mass + rtb_Sum_hl[2]) * (1.0 / claw_main_B.mass) -
      (rtb_sensors[0] * rtb_uvw[1] - rtb_sensors[1] * rtb_uvw[0]);

    /* Gain: '<S336>/Matrix Gain' incorporates:
     *  Math: '<S336>/Math Function'
     *  Product: '<S336>/Product1'
     */
    for (i = 0; i < 3; i++) {
      rtb_pqrdot[i] = 0.0;
      rtb_pqrdot[i] += rtb_inertia_inv[i] * rtb_delta_LLh_idx;
      rtb_pqrdot[i] += rtb_inertia_inv[i + 3] * rtb_delta_LLh_idx_0;
      rtb_pqrdot[i] += rtb_inertia_inv[i + 6] * rtb_Switch2_idx;
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_dircos[3 * i] * rtb_uvw[0];
      rtb_dircos_0[i] += rtb_dircos[3 * i + 1] * rtb_uvw[1];
      rtb_dircos_0[i] += rtb_dircos[3 * i + 2] * rtb_uvw[2];
    }

    rtb_Gain_g_idx_0 = claw_main_P.MatrixGain_Gain_l1[0] * rtb_dircos_0[0];
    rtb_Gain_g_idx_1 = claw_main_P.MatrixGain_Gain_l1[1] * rtb_dircos_0[1];
    rtb_Gain_g_idx_2 = claw_main_P.MatrixGain_Gain_l1[2] * rtb_dircos_0[2];

    /* Reshape: '<S342>/Reshape' incorporates:
     *  Gain: '<S342>/Gain1'
     */
    rtb_MatrixConcatenation_i[0] = claw_main_P.Gain1_Gain_ef[0] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_i[1] = claw_main_P.Gain1_Gain_ef[1] * rtb_Switch_idx;
    rtb_MatrixConcatenation_i[2] = claw_main_P.Gain1_Gain_ef[2] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_i[3] = claw_main_P.Gain1_Gain_ef[3] *
      rtb_Switch_idx_1;

    /* Reshape: '<S342>/Reshape1' incorporates:
     *  Gain: '<S342>/Gain2'
     */
    rtb_MatrixConcatenation_i[4] = claw_main_P.Gain2_Gain_o5[0] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_i[5] = claw_main_P.Gain2_Gain_o5[1] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_i[6] = claw_main_P.Gain2_Gain_o5[2] * rtb_Switch_idx;
    rtb_MatrixConcatenation_i[7] = claw_main_P.Gain2_Gain_o5[3] *
      rtb_Switch_idx_0;

    /* Reshape: '<S342>/Reshape2' incorporates:
     *  Gain: '<S342>/Gain3'
     */
    rtb_MatrixConcatenation_i[8] = claw_main_P.Gain3_Gain_az[0] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_i[9] = claw_main_P.Gain3_Gain_az[1] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_i[10] = claw_main_P.Gain3_Gain_az[2] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_i[11] = claw_main_P.Gain3_Gain_az[3] *
      rtb_Switch_idx;

    /* Gain: '<S338>/Gain4' incorporates:
     *  Product: '<S338>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_i[i] *
        rtb_sensors[0];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_i[i + 4] *
        rtb_sensors[1];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_i[i + 8] *
        rtb_sensors[2];
    }

    rtb_Gain_g_idx_3 = claw_main_P.Gain4_Gain_a1 * rtb_MatrixConcatenation_j_0[0];
    rtb_Gain_g_idx_4 = claw_main_P.Gain4_Gain_a1 * rtb_MatrixConcatenation_j_0[1];
    rtb_Product1_b_idx = claw_main_P.Gain4_Gain_a1 *
      rtb_MatrixConcatenation_j_0[2];
    rtb_Product1_b_idx_0 = claw_main_P.Gain4_Gain_a1 *
      rtb_MatrixConcatenation_j_0[3];

    /* Relay: '<S163>/Relay'
     *
     * Regarding '<S163>/Relay':
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * On  Points Value parameter uses the same data type and scaling as Input0
     * Off Points Value parameter uses the same data type and scaling as Input0
     * On  Output Value parameter uses the same data type and scaling as Output0
     * Off Output Value parameter uses the same data type and scaling as Output0
     */
    {
      if (rtb_qbar >= claw_main_P.Relay_OnVal ) {
        claw_main_DWork.Relay_Mode = TRUE;
      } else if (rtb_qbar <= claw_main_P.Relay_OffVal ) {
        claw_main_DWork.Relay_Mode = FALSE;
      }

      rtb_Relay = claw_main_DWork.Relay_Mode ? claw_main_P.Relay_YOn :
        claw_main_P.Relay_YOff;
    }

    /* SignalConversion: '<S180>/TmpHiddenBufferAtAssignmentInport1' */
    for (i = 0; i < 6; i++) {
      rtb_TmpHiddenBufferAtAssignme_a[i] = rtb_Assignment1_n[i];
    }

    rtb_TmpHiddenBufferAtAssignme_a[6] = rtb_Assignment1_n[7];
    rtb_TmpHiddenBufferAtAssignme_a[7] = rtb_Assignment1_n[8];
    rtb_TmpHiddenBufferAtAssignme_a[8] = rtb_Assignment1_n[9];

    /* FromWorkspace: '<S182>/From Workspace' */
    {
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_d.TimePtr;
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_d.DataPtr;
      if (t < pTimeValues[0]) {
        rtb_FromWorkspace_j = 0.0;
      } else if (t >= pTimeValues[0]) {
        rtb_FromWorkspace_j = pDataValues[0];
      } else {
        int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK_i1.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        rtb_FromWorkspace_j = pDataValues[currTimeIndex];
        claw_main_DWork.FromWorkspace_IWORK_i1.PrevIndex = currTimeIndex;
      }
    }

    /* Logic: '<S182>/Logical Operator' incorporates:
     *  Logic: '<S182>/Logical Operator1'
     */
    rtb_LogicalOperator_g = ((rtb_FromWorkspace_j != 0.0) && (!(rtb_Relay != 0.0)
      != 0));

    /* MinMax: '<S182>/MinMax' */
    for (i = 0; i < 9; i++) {
      max_6[i] = (real_T)rtb_LogicalOperator_g;
    }

    for (i = 0; i < 6; i++) {
      max_7[i] = rt_MAXd_snf(max_6[i], rtb_control_input[i + 64]);
    }

    max_7[6] = rt_MAXd_snf(max_6[6], rtb_control_input[71]);
    max_7[7] = rt_MAXd_snf(max_6[7], rtb_control_input[72]);
    max_7[8] = rt_MAXd_snf(max_6[8], rtb_control_input[73]);

    /* MultiPortSwitch: '<S182>/Multiport Switch' incorporates:
     *  Constant: '<S182>/Constant2'
     */
    memcpy((void *)&tmp[0], (void *)&max_7[0], 9U * (uint32_T)((char_T *)&max_7
            [1U] - (char_T *)&max_7[0U]));
    memcpy((void *)&tmp[9], (void *)&max_7[0], 9U * (uint32_T)((char_T *)&max_7
            [1U] - (char_T *)&max_7[0U]));
    for (i = 0; i < 6; i++) {
      tmp_0[i] = rtb_control_input[i + 74];
    }

    memcpy((void *)&tmp_0[6], (void *)&rtb_control_input[81], 9U * (uint32_T)
           ((char_T *)&rtb_control_input[1U] - (char_T *)&rtb_control_input[0U]));
    tmp_0[15] = rtb_control_input[91];
    tmp_0[16] = rtb_control_input[92];
    tmp_0[17] = rtb_control_input[93];
    for (i = 0; i < 6; i++) {
      tmp_1[i] = rtb_control_input[i + 74];
    }

    memcpy((void *)&tmp_1[6], (void *)&rtb_control_input[81], 9U * (uint32_T)
           ((char_T *)&rtb_control_input[1U] - (char_T *)&rtb_control_input[0U]));
    tmp_1[15] = rtb_control_input[91];
    tmp_1[16] = rtb_control_input[92];
    tmp_1[17] = rtb_control_input[93];
    for (i = 0; i < 6; i++) {
      tmp_2[i] = rtb_control_input[i + 74];
    }

    memcpy((void *)&tmp_2[6], (void *)&rtb_control_input[81], 9U * (uint32_T)
           ((char_T *)&rtb_control_input[1U] - (char_T *)&rtb_control_input[0U]));
    tmp_2[15] = rtb_control_input[91];
    tmp_2[16] = rtb_control_input[92];
    tmp_2[17] = rtb_control_input[93];
    for (i = 0; i < 6; i++) {
      tmp_3[i] = min_1[i];
    }

    tmp_3[6] = min_1[7];
    tmp_3[7] = min_1[8];
    tmp_3[8] = min_1[9];
    memcpy((void *)&tmp_3[9], (void *)(&claw_main_P.Constant2_Value_pg[0]), 9U *
           (uint32_T)((char_T *)(&claw_main_P.Constant2_Value_pg[1]) - (char_T *)
                      (&claw_main_P.Constant2_Value_pg[0])));
    for (i = 0; i < 6; i++) {
      tmp_4[i] = rtb_control_input[i + 74];
    }

    memcpy((void *)&tmp_4[6], (void *)&rtb_control_input[81], 9U * (uint32_T)
           ((char_T *)&rtb_control_input[1U] - (char_T *)&rtb_control_input[0U]));
    tmp_4[15] = rtb_control_input[91];
    tmp_4[16] = rtb_control_input[92];
    tmp_4[17] = rtb_control_input[93];
    for (yOffset_0 = 0; yOffset_0 < 18; yOffset_0++) {
      switch ((int32_T)tmp[yOffset_0]) {
       case 0:
        rtb_MultiportSwitch_oq[yOffset_0] = tmp_1[yOffset_0];
        break;

       case 1:
        rtb_MultiportSwitch_oq[yOffset_0] = tmp_2[yOffset_0];
        break;

       case 2:
        rtb_MultiportSwitch_oq[yOffset_0] = tmp_3[yOffset_0];
        break;

       case 3:
        rtb_MultiportSwitch_oq[yOffset_0] = tmp_4[yOffset_0];
        break;

       default:
        rtb_MultiportSwitch_oq[yOffset_0] = tmp_0[yOffset_0];
        break;
      }
    }

    for (i = 0; i < 6; i++) {
      rtb_delta_LLh_idx = rt_MINd_snf(rtb_Assignment1_n[i],
        rtb_MultiportSwitch_oq[i]);
      min_6[i] = rt_MAXd_snf(rtb_delta_LLh_idx, rtb_Assignment[i]);
    }

    /* MultiPortSwitch: '<S180>/Multiport Switch1' */
    if ((int32_T)rtb_Relay == 0) {
      memcpy((void *)&rtb_MultiportSwitch1_ik[0], (void *)
             &rtb_TmpHiddenBufferAtAssignme_a[0], 9U * (uint32_T)((char_T *)
              &rtb_TmpHiddenBufferAtAssignme_a[1U] - (char_T *)
              &rtb_TmpHiddenBufferAtAssignme_a[0U]));
    } else {
      /* Assignment: '<S180>/Assignment' */
      memcpy((void *)&rtb_Assignment_b[0], (void *)
             &rtb_TmpHiddenBufferAtAssignme_a[0], 9U * (uint32_T)((char_T *)
              &rtb_TmpHiddenBufferAtAssignme_a[1U] - (char_T *)
              &rtb_TmpHiddenBufferAtAssignme_a[0U]));
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
        rtb_Assignment_b[uDimIdx] = min_6[yOffset];
        yOffset++;
      }

      memcpy((void *)&rtb_MultiportSwitch1_ik[0], (void *)&rtb_Assignment_b[0],
             9U * (uint32_T)((char_T *)&rtb_Assignment_b[1U] - (char_T *)
              &rtb_Assignment_b[0U]));
    }

    for (i = 0; i < 9; i++) {
      /* MinMax: '<S311>/MinMax2' incorporates:
       *  Constant: '<S311>/Constant3'
       */
      max_6[i] = rt_MINd_snf(claw_main_P.Constant3_Value_gw[i],
        rtb_MultiportSwitch1_ik[i]);

      /* UnitDelay: '<S6>/Unit Delay2' */
      rtb_UnitDelay2_o[i] = claw_main_DWork.UnitDelay2_DSTATE_i[i];
    }

    /* Sum: '<S311>/Sum2' incorporates:
     *  Gain: '<S311>/Gain1'
     */
    for (i = 0; i < 6; i++) {
      rtb_Sum2_fu[i] = rtb_control_input[i + 44] * claw_main_P.Gain1_Gain_am +
        claw_main_DWork.UnitDelay2_DSTATE_i[i];
    }

    rtb_Sum2_fu[6] = claw_main_P.Gain1_Gain_am * rtb_control_input[51] +
      claw_main_DWork.UnitDelay2_DSTATE_i[6];
    rtb_Sum2_fu[7] = claw_main_P.Gain1_Gain_am * rtb_control_input[52] +
      claw_main_DWork.UnitDelay2_DSTATE_i[7];
    rtb_Sum2_fu[8] = claw_main_P.Gain1_Gain_am * rtb_control_input[53] +
      claw_main_DWork.UnitDelay2_DSTATE_i[8];

    /* MinMax: '<S311>/MinMax3' */
    for (i = 0; i < 9; i++) {
      max_7[i] = rt_MAXd_snf(max_6[i], rtb_Sum2_fu[i]);
    }

    /* Sum: '<S311>/Sum1' incorporates:
     *  Gain: '<S311>/Gain'
     */
    for (i = 0; i < 6; i++) {
      rtb_Sum1_f[i] = rtb_control_input[i + 34] * claw_main_P.Gain_Gain_fa +
        claw_main_DWork.UnitDelay2_DSTATE_i[i];
      rtb_TmpHiddenBufferAtAssignme_j[i] = rtb_Assignment[i];
    }

    rtb_Sum1_f[6] = claw_main_P.Gain_Gain_fa * rtb_control_input[41] +
      claw_main_DWork.UnitDelay2_DSTATE_i[6];
    rtb_Sum1_f[7] = claw_main_P.Gain_Gain_fa * rtb_control_input[42] +
      claw_main_DWork.UnitDelay2_DSTATE_i[7];
    rtb_Sum1_f[8] = claw_main_P.Gain_Gain_fa * rtb_control_input[43] +
      claw_main_DWork.UnitDelay2_DSTATE_i[8];

    /* SignalConversion: '<S180>/TmpHiddenBufferAtAssignment1Inport1' */
    rtb_TmpHiddenBufferAtAssignme_j[6] = rtb_Assignment[7];
    rtb_TmpHiddenBufferAtAssignme_j[7] = rtb_Assignment[8];
    rtb_TmpHiddenBufferAtAssignme_j[8] = rtb_Assignment[9];

    /* MultiPortSwitch: '<S180>/Multiport Switch2' */
    if ((int32_T)rtb_Relay == 0) {
      memcpy((void *)&rtb_MultiportSwitch2_o[0], (void *)
             &rtb_TmpHiddenBufferAtAssignme_j[0], 9U * (uint32_T)((char_T *)
              &rtb_TmpHiddenBufferAtAssignme_j[1U] - (char_T *)
              &rtb_TmpHiddenBufferAtAssignme_j[0U]));
    } else {
      /* Assignment: '<S180>/Assignment1' */
      memcpy((void *)&rtb_Assignment1_d5[0], (void *)
             &rtb_TmpHiddenBufferAtAssignme_j[0], 9U * (uint32_T)((char_T *)
              &rtb_TmpHiddenBufferAtAssignme_j[1U] - (char_T *)
              &rtb_TmpHiddenBufferAtAssignme_j[0U]));
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
        rtb_Assignment1_d5[uDimIdx] = min_6[yOffset];
        yOffset++;
      }

      memcpy((void *)&rtb_MultiportSwitch2_o[0], (void *)&rtb_Assignment1_d5[0],
             9U * (uint32_T)((char_T *)&rtb_Assignment1_d5[1U] - (char_T *)
              &rtb_Assignment1_d5[0U]));
    }

    for (i = 0; i < 9; i++) {
      /* MinMax: '<S311>/MinMax1' incorporates:
       *  Constant: '<S311>/Constant1'
       */
      rtb_delta_LLh_idx = rt_MAXd_snf(claw_main_P.Constant1_Value_hp[i],
        rtb_MultiportSwitch2_o[i]);

      /* MinMax: '<S311>/MinMax4' */
      rtb_delta_LLh_idx = rt_MINd_snf(rtb_Sum1_f[i], rtb_delta_LLh_idx);
      max_6[i] = rtb_delta_LLh_idx;
    }

    /* Outputs for iterator SubSystem: '<S6>/B matrix comp' incorporates:
     *  Constant: '<S194>/Constant4'
     *  WhileIterator: '<S194>/While Iterator'
     */
    memcpy((void *)&rtb_Assignment_f[0], (void *)&rtb_zeroRCSinputs[0], 10U *
           (uint32_T)((char_T *)&rtb_zeroRCSinputs[1U] - (char_T *)
                      &rtb_zeroRCSinputs[0U]));
    scalarIndex_0 = 1;
    for (i = 0; i < 7; i++) {
      claw_main_DWork.WhileIterator_IterationMarker_n[i] = 1U;
    }

    do {
      /* Memory: '<S194>/Memory1' */
      memcpy((void *)&rtb_Memory1_e[0], (void *)
             (&claw_main_DWork.Memory1_PreviousInput_g[0]), 27U * (uint32_T)
             ((char_T *)(&claw_main_DWork.Memory1_PreviousInput_g[1]) - (char_T *)
              (&claw_main_DWork.Memory1_PreviousInput_g[0])));

      /* Gain: '<S292>/Gain1' */
      rtb_dL_Ail_n = claw_main_P.Gain1_Gain_o * 0.0;

      /* Gain: '<S292>/Gain2' */
      rtb_dR_Ail_f = claw_main_P.Gain2_Gain * 0.0;

      /* Sum: '<S194>/Sum2' incorporates:
       *  Constant: '<S194>/Constant2'
       *  Memory: '<S194>/Memory2'
       */
      rtb_columncounter_i = claw_main_DWork.Memory2_PreviousInput +
        claw_main_P.Constant2_Value_g;

      /* MultiPortSwitch: '<S194>/Multiport Switch' incorporates:
       *  Constant: '<S194>/Constant4'
       */
      if ((int32_T)claw_main_P.Constant4_Value_c == 0) {
        rtb_MultiportSwitch_kx = rtb_columncounter_i;
      } else {
        rtb_MultiportSwitch_kx = (real_T)scalarIndex_0;
      }

      /* Selector: '<S294>/Selector5' incorporates:
       *  Constant: '<S205>/Constant2'
       */
      yOffset = 0;
      i = ((int32_T)rtb_MultiportSwitch_kx - 1) * 9;
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        rtb_Selector5_a[yOffset] = claw_main_P.Constant2_Value_j[i + yOffset_0];
        yOffset++;
      }

      /* Sum: '<S294>/Sum3' incorporates:
       *  Reshape: '<S294>/Reshape'
       */
      for (i = 0; i < 6; i++) {
        rtb_d_h[i] = rtb_zeroRCSinputs[i] + rtb_Selector5_a[i];
      }

      rtb_d_h[6] = rtb_zeroRCSinputs[7] + rtb_Selector5_a[6];
      rtb_d_h[7] = rtb_zeroRCSinputs[8] + rtb_Selector5_a[7];
      rtb_d_h[8] = rtb_zeroRCSinputs[9] + rtb_Selector5_a[8];

      /* Switch: '<S294>/Switch' incorporates:
       *  RelationalOperator: '<S294>/Relational Operator'
       *  Reshape: '<S294>/Reshape'
       *  Selector: '<S294>/Selector'
       *  Selector: '<S294>/Selector1'
       *  Sum: '<S294>/Sum2'
       */
      if ((real_T)(rtb_d_h[(int32_T)rtb_MultiportSwitch_kx - 1] <= max_7
                   [(int32_T)rtb_MultiportSwitch_kx - 1]) >=
          claw_main_P.Switch_Threshold_g) {
        memcpy((void *)&rtb_Switch_jl[0], (void *)&rtb_d_h[0], 9U * (uint32_T)
               ((char_T *)&rtb_d_h[1U] - (char_T *)&rtb_d_h[0U]));
      } else {
        for (i = 0; i < 6; i++) {
          rtb_Switch_jl[i] = rtb_zeroRCSinputs[i] - rtb_Selector5_a[i];
        }

        rtb_Switch_jl[6] = rtb_zeroRCSinputs[7] - rtb_Selector5_a[6];
        rtb_Switch_jl[7] = rtb_zeroRCSinputs[8] - rtb_Selector5_a[7];
        rtb_Switch_jl[8] = rtb_zeroRCSinputs[9] - rtb_Selector5_a[8];
      }

      /* Assignment: '<S204>/Assignment' */
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 9; uDimIdx++) {
        rtb_Assignment_f[(int32_T)tmp_b[uDimIdx]] = rtb_Switch_jl[yOffset];
        yOffset++;
      }

      /* Sum: '<S290>/Sum3' incorporates:
       *  Constant: '<S290>/Elevator'
       *  Product: '<S290>/Product'
       */
      rtb_Sum3_gy = rtb_Assignment_f[4] * rtb_Assignment_f[0] +
        claw_main_P.Elevator_Value;

      /* Gain: '<S290>/Gain6' */
      rtb_ELLOBC_n = claw_main_P.Gain6_Gain * rtb_Sum3_gy;

      /* Gain: '<S290>/Gain5' */
      rtb_ELLIBC_mo = claw_main_P.Gain5_Gain * rtb_Sum3_gy;

      /* Gain: '<S290>/Gain7' */
      rtb_ELROBC_gf = claw_main_P.Gain7_Gain * rtb_Sum3_gy;

      /* Gain: '<S290>/Gain8' */
      rtb_ELRIBC_b = claw_main_P.Gain8_Gain * rtb_Sum3_gy;

      /* Sum: '<S290>/Sum' incorporates:
       *  Constant: '<S290>/Aileron'
       */
      rtb_Sum_i4 = rtb_Assignment_f[1] + claw_main_P.Aileron_Value;

      /* Gain: '<S290>/Gain1' */
      rtb_AILLC_o = claw_main_P.Gain1_Gain_e * rtb_Sum_i4;

      /* Gain: '<S290>/Gain2' */
      rtb_AILRC_b = claw_main_P.Gain2_Gain_l * rtb_Sum_i4;

      /* Sum: '<S290>/Sum2' incorporates:
       *  Constant: '<S290>/Rudder'
       */
      rtb_Sum2_gxu = rtb_Assignment_f[2] + claw_main_P.Rudder_Value;

      /* Gain: '<S290>/Gain3' */
      rtb_RUDUPC_a = claw_main_P.Gain3_Gain * rtb_Sum2_gxu;

      /* Gain: '<S290>/Gain4' */
      rtb_RUDLOC_hv = claw_main_P.Gain4_Gain * rtb_Sum2_gxu;

      /* Lookup Block: '<S290>/Left Roll Spoiler Schedule'
       * About '<S290>/Left Roll Spoiler Schedule :'
       * Lookup Block: '<S290>/Left Roll Spoiler Schedule'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_LeftRollSpoilerSchedule_n),
                           claw_main_P.LeftRollSpoilerSchedule_YData,
                           claw_main_P.Constant_Value_dm,
                           claw_main_P.LeftRollSpoilerSchedule_XData, 6U);

      /* Gain: '<S290>/Gain12' */
      rtb_SPLLIBC_b = claw_main_P.Gain12_Gain * rtb_LeftRollSpoilerSchedule_n;

      /* Gain: '<S290>/Gain13' */
      rtb_SPLLOBC_d = claw_main_P.Gain13_Gain * rtb_LeftRollSpoilerSchedule_n;

      /* Lookup Block: '<S290>/Right Roll Spoiler Schedule'
       * About '<S290>/Right Roll Spoiler Schedule :'
       * Lookup Block: '<S290>/Right Roll Spoiler Schedule'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_RightRollSpoilerSchedule_i),
                           claw_main_P.RightRollSpoilerSchedule_YData,
                           claw_main_P.Constant_Value_dm,
                           claw_main_P.RightRollSpoilerSchedule_XData, 6U);

      /* Sum: '<S290>/Sum4' incorporates:
       *  Constant: '<S290>/Constant2'
       *  Constant: '<S290>/Flaps'
       */
      rtb_Sum4_g4 = claw_main_P.Constant2_Value_e + claw_main_P.Flaps_Value;

      /* Gain: '<S290>/Gain20' incorporates:
       *  Constant: '<S290>/Gear'
       */
      rtb_GEARC_f = claw_main_P.Gain20_Gain * claw_main_P.Gear_Value;

      /* Sum: '<S289>/Sum' incorporates:
       *  Constant: '<S289>/Gear1'
       *  Constant: '<S290>/Constant3'
       *  Gain: '<S290>/Gain10'
       *  Gain: '<S290>/Gain11'
       *  Gain: '<S290>/Gain14'
       *  Gain: '<S290>/Gain15'
       *  Gain: '<S290>/Gain16'
       *  Gain: '<S290>/Gain17'
       *  Gain: '<S290>/Gain18'
       *  Gain: '<S290>/Gain21'
       *  Gain: '<S290>/Gain22'
       *  Gain: '<S290>/Gain9'
       *  Saturate: '<S289>/Brake'
       *  Saturate: '<S289>/Gear'
       *  SignalConversion: '<S290>/TmpHiddenBufferAtGain22Inport1'
       *  Sum: '<S289>/Sum3'
       */
      rtb_orderatts_i_idx = claw_main_P.Gain14_Gain *
        rtb_RightRollSpoilerSchedule_i;
      rtb_Switch_d_idx_0 = claw_main_P.Gain11_Gain *
        rtb_RightRollSpoilerSchedule_i;
      rtb_Switch_d_idx = claw_main_P.Gain16_Gain * rtb_Sum4_g4;
      rtb_Sum_ow_idx = claw_main_P.Gain17_Gain * rtb_Sum4_g4;
      rtb_Sum_ow_idx_0 = claw_main_P.Gain18_Gain * rtb_Sum4_g4;
      rtb_Sum_ow_idx_1 = claw_main_P.Gain15_Gain * rtb_Sum4_g4;
      rtb_Switch_d_idx_1 = rtb_Assignment_f[3] + claw_main_P.Gear1_Value;
      rtb_Gain_g_idx = rt_SATURATE(rtb_GEARC_f, claw_main_P.Gear_LowerSat,
        claw_main_P.Gear_UpperSat);
      rtb_delta_LLh_idx = (claw_main_P.Gain22_Gain[0] * rtb_Assignment_f[6] +
                           claw_main_P.Gain22_Gain[2] * rtb_Assignment_f[5]) *
        claw_main_P.Gain9_Gain;
      rtb_delta_LLh_idx_0 = (claw_main_P.Gain22_Gain[1] * rtb_Assignment_f[6] +
        claw_main_P.Gain22_Gain[3] * rtb_Assignment_f[5]) *
        claw_main_P.Gain10_Gain;

      /* Polyval: '<S287>/Throttle_2_RPMref' */
      rtb_Throttle_2_RPMref_pa = ((claw_main_P.Throttle_2_RPMref_coefs[0] *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs[1]) *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs[2]) *
        rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs[3];

      /* Polyval: '<S287>/RPMref_2_Thrust' */
      rtb_RPMref_2_Thrust_a = ((claw_main_P.RPMref_2_Thrust_coefs[0] *
        rtb_Throttle_2_RPMref_pa + claw_main_P.RPMref_2_Thrust_coefs[1]) *
        rtb_Throttle_2_RPMref_pa + claw_main_P.RPMref_2_Thrust_coefs[2]) *
        rtb_Throttle_2_RPMref_pa + claw_main_P.RPMref_2_Thrust_coefs[3];

      /* Gain: '<S217>/Gain1' */
      rtb_pratio_c = claw_main_P.Gain1_Gain_p * rtb_P;

      /* Gain: '<S287>/UnScale_Ref_RPM' */
      rtb_UnScale_Ref_RPM_ee = claw_main_P.UnScale_Ref_RPM_Gain *
        rtb_Throttle_2_RPMref_pa;

      /* Gain: '<S287>/angular momentum' */
      rtb_angularmomentum_h = claw_main_P.angularmomentum_Gain *
        rtb_UnScale_Ref_RPM_ee;

      /* Polyval: '<S287>/RPMref_2_FuelFlow' */
      rtb_RPMref_2_FuelFlow_n1 = claw_main_P.RPMref_2_FuelFlow_coefs[0];
      rtb_RPMref_2_FuelFlow_n1 = rtb_RPMref_2_FuelFlow_n1 *
        rtb_Throttle_2_RPMref_pa + claw_main_P.RPMref_2_FuelFlow_coefs[1];
      rtb_RPMref_2_FuelFlow_n1 = rtb_RPMref_2_FuelFlow_n1 *
        rtb_Throttle_2_RPMref_pa + claw_main_P.RPMref_2_FuelFlow_coefs[2];

      /* Lookup Block: '<S287>/Fuel Pump Voltage'
       * About '<S287>/Fuel Pump Voltage :'
       * Lookup Block: '<S287>/Fuel Pump Voltage'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_h),
                           claw_main_P.FuelPumpVoltage_YData,
                           rtb_RPMref_2_FuelFlow_n1,
                           claw_main_P.FuelPumpVoltage_XData, 25U);

      /* Gain: '<S218>/LengON' incorporates:
       *  Polyval: '<S287>/RPMref_2_EGT'
       *  Product: '<S287>/Product2'
       */
      rtb_LengON_i[0] = rtb_RPMref_2_Thrust_a * rtb_pratio_c *
        claw_main_P.LengON_Gain;
      rtb_LengON_i[1] = claw_main_P.LengON_Gain * rtb_UnScale_Ref_RPM_ee;
      rtb_LengON_i[2] = claw_main_P.LengON_Gain * rtb_angularmomentum_h;
      rtb_LengON_i[3] = claw_main_P.LengON_Gain * rtb_FuelPumpVoltage_h;
      rtb_LengON_i[4] = ((((claw_main_P.RPMref_2_EGT_coefs[0] *
                            rtb_Throttle_2_RPMref_pa +
                            claw_main_P.RPMref_2_EGT_coefs[1]) *
                           rtb_Throttle_2_RPMref_pa +
                           claw_main_P.RPMref_2_EGT_coefs[2]) *
                          rtb_Throttle_2_RPMref_pa +
                          claw_main_P.RPMref_2_EGT_coefs[3]) *
                         rtb_Throttle_2_RPMref_pa +
                         claw_main_P.RPMref_2_EGT_coefs[4]) *
        claw_main_P.LengON_Gain;
      rtb_LengON_i[5] = claw_main_P.LengON_Gain * rtb_RPMref_2_FuelFlow_n1;

      /* Polyval: '<S288>/Throttle_2_RPMref' */
      rtb_Throttle_2_RPMref_i = ((claw_main_P.Throttle_2_RPMref_coefs_f[0] *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_f[1]) *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_f[2]) *
        rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_f[3];

      /* Polyval: '<S288>/RPMref_2_Thrust' */
      rtb_RPMref_2_Thrust_m = ((claw_main_P.RPMref_2_Thrust_coefs_b[0] *
        rtb_Throttle_2_RPMref_i + claw_main_P.RPMref_2_Thrust_coefs_b[1]) *
        rtb_Throttle_2_RPMref_i + claw_main_P.RPMref_2_Thrust_coefs_b[2]) *
        rtb_Throttle_2_RPMref_i + claw_main_P.RPMref_2_Thrust_coefs_b[3];

      /* Gain: '<S288>/UnScale_Ref_RPM' */
      rtb_UnScale_Ref_RPM_h = claw_main_P.UnScale_Ref_RPM_Gain_m *
        rtb_Throttle_2_RPMref_i;

      /* Gain: '<S288>/angular momentum' */
      rtb_angularmomentum_c = claw_main_P.angularmomentum_Gain_a *
        rtb_UnScale_Ref_RPM_h;

      /* Polyval: '<S288>/RPMref_2_FuelFlow' */
      rtb_RPMref_2_FuelFlow_f = claw_main_P.RPMref_2_FuelFlow_coefs_k[0];
      rtb_RPMref_2_FuelFlow_f = rtb_RPMref_2_FuelFlow_f *
        rtb_Throttle_2_RPMref_i + claw_main_P.RPMref_2_FuelFlow_coefs_k[1];
      rtb_RPMref_2_FuelFlow_f = rtb_RPMref_2_FuelFlow_f *
        rtb_Throttle_2_RPMref_i + claw_main_P.RPMref_2_FuelFlow_coefs_k[2];

      /* Lookup Block: '<S288>/Fuel Pump Voltage'
       * About '<S288>/Fuel Pump Voltage :'
       * Lookup Block: '<S288>/Fuel Pump Voltage'
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0


       */
      LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_a),
                           claw_main_P.FuelPumpVoltage_YData_n,
                           rtb_RPMref_2_FuelFlow_f,
                           claw_main_P.FuelPumpVoltage_XData_m, 25U);

      /* Gain: '<S218>/RengON' incorporates:
       *  Polyval: '<S288>/RPMref_2_EGT'
       *  Product: '<S288>/Product2'
       */
      rtb_RengON_o[0] = rtb_RPMref_2_Thrust_m * rtb_pratio_c *
        claw_main_P.RengON_Gain;
      rtb_RengON_o[1] = claw_main_P.RengON_Gain * rtb_UnScale_Ref_RPM_h;
      rtb_RengON_o[2] = claw_main_P.RengON_Gain * rtb_angularmomentum_c;
      rtb_RengON_o[3] = claw_main_P.RengON_Gain * rtb_FuelPumpVoltage_a;
      rtb_RengON_o[4] = ((((claw_main_P.RPMref_2_EGT_coefs_p[0] *
                            rtb_Throttle_2_RPMref_i +
                            claw_main_P.RPMref_2_EGT_coefs_p[1]) *
                           rtb_Throttle_2_RPMref_i +
                           claw_main_P.RPMref_2_EGT_coefs_p[2]) *
                          rtb_Throttle_2_RPMref_i +
                          claw_main_P.RPMref_2_EGT_coefs_p[3]) *
                         rtb_Throttle_2_RPMref_i +
                         claw_main_P.RPMref_2_EGT_coefs_p[4]) *
        claw_main_P.RengON_Gain;
      rtb_RengON_o[5] = claw_main_P.RengON_Gain * rtb_RPMref_2_FuelFlow_f;
      claw_main_EngineAlignment(rtb_LengON_i[0], rtb_LengON_i[2], rtb_RengON_o[0],
        rtb_RengON_o[2], &claw_main_B.sf_EngineAlignment_b,
        (rtP_EngineAlignment_claw_main *) &claw_main_P.sf_EngineAlignment_b);

      /* FromWorkspace: '<S222>/From Workspace' */
      {
        real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
        real_T *pTimeValues = (real_T *)
          claw_main_DWork.FromWorkspace_PWORK_g.TimePtr;
        real_T *pDataValues = (real_T *)
          claw_main_DWork.FromWorkspace_PWORK_g.DataPtr;
        if (t < pTimeValues[0]) {
          rtb_FromWorkspace_f = 0.0;
        } else if (t >= pTimeValues[1]) {
          rtb_FromWorkspace_f = pDataValues[1];
        } else {
          int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK_m.PrevIndex;
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }

          rtb_FromWorkspace_f = pDataValues[currTimeIndex];
          claw_main_DWork.FromWorkspace_IWORK_m.PrevIndex = currTimeIndex;
        }
      }

      /* Selector: '<S225>/Value(ndx,:)1' incorporates:
       *  Constant: '<S225>/Gain2'
       */
      rtb_delta_LLh_idx = claw_main_P.Gain2_Value[(int32_T)rtb_FromWorkspace_f];
      rtb_Switch2_idx = claw_main_P.Gain2_Value[7 + (int32_T)rtb_FromWorkspace_f];
      rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain2_Value[14 + (int32_T)
        rtb_FromWorkspace_f];

      /* Sum: '<S221>/Add' incorporates:
       *  Constant: '<S218>/zero2'
       *  Constant: '<S221>/ixxb7'
       *  Constant: '<S225>/Gain1'
       *  Selector: '<S225>/Value(ndx,:)'
       *  Sum: '<S221>/Add3'
       */
      rtb_gwest_o = (claw_main_P.ixxb7_Value - claw_main_P.zero2_Value) +
        claw_main_P.Gain1_Value[(int32_T)rtb_FromWorkspace_f];
      claw_main_fuelcgshiftcg_pos0(claw_main_P.zero2_Value,
        &claw_main_B.sf_fuelcgshiftcg_pos0_a, (rtP_fuelcgshiftcg_pos0_claw_mai *)
        &claw_main_P.sf_fuelcgshiftcg_pos0_a);

      /* Switch: '<S221>/Switch1' incorporates:
       *  Constant: '<S221>/xCG1'
       *  Constant: '<S221>/xCG4'
       */
      if (rtb_Gain_g_idx >= claw_main_P.Switch1_Threshold) {
        rtb_delta_LLh_idx_0 = claw_main_P.xCG4_Value[0];
        rtb_Gain1_idx_0 = claw_main_P.xCG4_Value[1];
        rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG4_Value[2];
      } else {
        rtb_delta_LLh_idx_0 = claw_main_P.xCG1_Value[0];
        rtb_Gain1_idx_0 = claw_main_P.xCG1_Value[1];
        rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG1_Value[2];
      }

      /* Sum: '<S221>/Add2' incorporates:
       *  Product: '<S221>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_o * claw_main_B.sf_fuelcgshiftcg_pos0_a.y
                      [0] + rtb_delta_LLh_idx) + rtb_delta_LLh_idx_0;

      /* Sum: '<S280>/Sum6' incorporates:
       *  Constant: '<S215>/ixxb6'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value[0] - rtb_Add2_idx;

      /* Gain: '<S286>/Gain' */
      rtb_Gain1_idx = claw_main_P.Gain_Gain_o * rtb_Gain1_idx_1;

      /* Sum: '<S280>/Sum7' incorporates:
       *  Constant: '<S215>/ixxb5'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value[0] - rtb_Add2_idx;

      /* Gain: '<S285>/Gain' */
      rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_g *
        rtb_MultiportSwitch2_idx_2;
      rtb_UnitDelay_nf_idx = rtb_MultiportSwitch2_idx_2;
      rtb_Add2_idx_0 = rtb_Add2_idx;
      rtb_InterpolationnDusingPreLo_3 = rtb_Gain1_idx_1;

      /* Sum: '<S221>/Add2' incorporates:
       *  Product: '<S221>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_o * claw_main_B.sf_fuelcgshiftcg_pos0_a.y
                      [1] + rtb_Switch2_idx) + rtb_Gain1_idx_0;

      /* Sum: '<S280>/Sum6' incorporates:
       *  Constant: '<S215>/ixxb6'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value[1] - rtb_Add2_idx;

      /* Gain: '<S286>/Gain' */
      rtb_delta_LLh_idx = claw_main_P.Gain_Gain_o * rtb_Gain1_idx_1;

      /* Sum: '<S280>/Sum7' incorporates:
       *  Constant: '<S215>/ixxb5'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value[1] - rtb_Add2_idx;

      /* Gain: '<S285>/Gain' */
      rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_g * rtb_MultiportSwitch2_idx_2;
      rtb_Switch2_idx = rtb_MultiportSwitch2_idx_2;
      rtb_Add2_idx_1 = rtb_Add2_idx;
      rtb_Gain1_idx_0 = rtb_Gain1_idx_1;

      /* Sum: '<S221>/Add2' incorporates:
       *  Product: '<S221>/Divide1'
       */
      rtb_Add2_idx = (1.0 / rtb_gwest_o * claw_main_B.sf_fuelcgshiftcg_pos0_a.y
                      [2] + rtb_InterpolationnDusingPreLo_4) +
        rtb_InterpolationnDusingPreLo_5;

      /* Sum: '<S280>/Sum6' incorporates:
       *  Constant: '<S215>/ixxb6'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value[2] - rtb_Add2_idx;

      /* Sum: '<S280>/Sum7' incorporates:
       *  Constant: '<S215>/ixxb5'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value[2] - rtb_Add2_idx;

      /* Sum: '<S280>/Sum1' incorporates:
       *  Gain: '<S285>/Gain'
       *  Gain: '<S286>/Gain'
       *  Product: '<S285>/Product'
       *  Product: '<S286>/Product'
       *  Reshape: '<S285>/Reshape'
       *  Reshape: '<S286>/Reshape'
       */
      rtb_Gain1_oy_0[0] = 0.0;
      rtb_Gain1_oy_0[1] = rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
      rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_o * rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[4] = 0.0;
      rtb_Gain1_oy_0[5] = rtb_InterpolationnDusingPreLo_3;
      rtb_Gain1_oy_0[6] = rtb_Gain1_idx_0;
      rtb_Gain1_oy_0[7] = rtb_Gain1_idx;
      rtb_Gain1_oy_0[8] = 0.0;
      rtb_Sum4_j_0[0] = 0.0;
      rtb_Sum4_j_0[1] = rtb_MultiportSwitch2_idx_2;
      rtb_Sum4_j_0[2] = rtb_delta_LLh_idx_0;
      rtb_Sum4_j_0[3] = claw_main_P.Gain_Gain_g * rtb_MultiportSwitch2_idx_2;
      rtb_Sum4_j_0[4] = 0.0;
      rtb_Sum4_j_0[5] = rtb_UnitDelay_nf_idx;
      rtb_Sum4_j_0[6] = rtb_Switch2_idx;
      rtb_Sum4_j_0[7] = rtb_UnitDelay_nf_idx_0;
      rtb_Sum4_j_0[8] = 0.0;

      /* Product: '<S279>/Product' incorporates:
       *  Gain: '<S279>/Gain'
       *  Reshape: '<S279>/Reshape'
       */
      rtb_MultiportSwitch_cn_0[0] = 0.0;
      rtb_MultiportSwitch_cn_0[1] = rtb_sensors[2];
      rtb_MultiportSwitch_cn_0[2] = claw_main_P.Gain_Gain_ge * rtb_sensors[1];
      rtb_MultiportSwitch_cn_0[3] = claw_main_P.Gain_Gain_ge * rtb_sensors[2];
      rtb_MultiportSwitch_cn_0[4] = 0.0;
      rtb_MultiportSwitch_cn_0[5] = rtb_sensors[0];
      rtb_MultiportSwitch_cn_0[6] = rtb_sensors[1];
      rtb_MultiportSwitch_cn_0[7] = claw_main_P.Gain_Gain_ge * rtb_sensors[0];
      rtb_MultiportSwitch_cn_0[8] = 0.0;
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i] *
          claw_main_B.sf_EngineAlignment_b.TL[0];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] *
          claw_main_B.sf_EngineAlignment_b.TL[1];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] *
          claw_main_B.sf_EngineAlignment_b.TL[2];
        rtb_Gain_e_0[i] = 0.0;
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i] *
          claw_main_B.sf_EngineAlignment_b.TR[0];
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 3] *
          claw_main_B.sf_EngineAlignment_b.TR[1];
        rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 6] *
          claw_main_B.sf_EngineAlignment_b.TR[2];
        rtb_Product_ia[i] = 0.0;
        rtb_Product_ia[i] += rtb_MultiportSwitch_cn_0[i] *
          claw_main_B.sf_EngineAlignment_b.H[0];
        rtb_Product_ia[i] += rtb_MultiportSwitch_cn_0[i + 3] *
          claw_main_B.sf_EngineAlignment_b.H[1];
        rtb_Product_ia[i] += rtb_MultiportSwitch_cn_0[i + 6] *
          claw_main_B.sf_EngineAlignment_b.H[2];
      }

      /* Gain: '<S207>/Gain1' incorporates:
       *  Math: '<S207>/Math Function'
       */
      rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
      rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
      rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
      rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
      for (i = 0; i < 4; i++) {
        rtb_Gain1_bp[i] = 0.0;
        rtb_Gain1_bp[i] += claw_main_P.Gain1_Gain_f[i] * rtb_delta_LLh_idx;
        rtb_Gain1_bp[i] += claw_main_P.Gain1_Gain_f[i + 4] * rtb_delta_LLh_idx_0;
        rtb_Gain1_bp[i] += claw_main_P.Gain1_Gain_f[i + 8] * rtb_Switch2_idx;
        rtb_Gain1_bp[i] += claw_main_P.Gain1_Gain_f[i + 12] * rtb_Gain1_idx_0;
      }

      /* Product: '<S207>/e1*e2' */
      rtb_e1e2_a = rtb_Switch_idx_0 * rtb_Switch_idx_1;

      /* Product: '<S207>/e3*e1' */
      rtb_e3e1_b = rtb_Switch_idx_2 * rtb_Switch_idx_0;

      /* Product: '<S207>/e2*e3' */
      rtb_e2e3_d2 = rtb_Switch_idx_1 * rtb_Switch_idx_2;

      /* Product: '<S207>/e0*e3' */
      rtb_e0e3_d = rtb_Switch_idx * rtb_Switch_idx_2;

      /* Product: '<S207>/e0*e2' */
      rtb_e0e2_f = rtb_Switch_idx * rtb_Switch_idx_1;

      /* Product: '<S207>/e0*e1' */
      rtb_e0e1_b = rtb_Switch_idx * rtb_Switch_idx_0;

      /* Reshape: '<S206>/Reshape' incorporates:
       *  Gain: '<S207>/Gain'
       *  Sum: '<S207>/Sum'
       *  Sum: '<S207>/Sum1'
       */
      rtb_dircos_h[0] = rtb_Gain1_bp[1];
      rtb_dircos_h[1] = (rtb_e1e2_a - rtb_e0e3_d) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[2] = (rtb_e3e1_b + rtb_e0e2_f) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[3] = (rtb_e1e2_a + rtb_e0e3_d) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[4] = rtb_Gain1_bp[2];
      rtb_dircos_h[5] = (rtb_e2e3_d2 - rtb_e0e1_b) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[6] = (rtb_e3e1_b - rtb_e0e2_f) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[7] = (rtb_e2e3_d2 + rtb_e0e1_b) * claw_main_P.Gain_Gain_b;
      rtb_dircos_h[8] = rtb_Gain1_bp[3];

      /* Sum: '<S206>/Sum1' incorporates:
       *  Product: '<S206>/Product'
       */
      for (i = 0; i < 3; i++) {
        rtb_dircos_b_0[i] = 0.0;
        rtb_dircos_b_0[i] += rtb_dircos_h[i] * rtb_MultiportSwitch1_idx;
        rtb_dircos_b_0[i] += rtb_dircos_h[i + 3] * rtb_MultiportSwitch1_idx_0;
        rtb_dircos_b_0[i] += rtb_dircos_h[i + 6] * rtb_MultiportSwitch1_idx_1;
      }

      rtb_delta_LLh_idx = rtb_uvw[0] + rtb_dircos_b_0[0];
      rtb_Gain1_idx_0 = rtb_uvw[1] + rtb_dircos_b_0[1];
      rtb_delta_LLh_idx_0 = rtb_uvw[2] + rtb_dircos_b_0[2];

      /* Gain: '<S217>/Gain2' incorporates:
       *  Trigonometry: '<S293>/Trigonometric Function2'
       */
      claw_main_B.alpha_f = claw_main_P.Gain2_Gain_n * rt_atan2_snf
        (rtb_delta_LLh_idx_0, rtb_delta_LLh_idx);

      /* PreLookup: '<S233>/AlphaLookup' */
      rtb_AlphaLookup_o1_b = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.AlphaLookup_BreakpointsData[0], 31U, &rtb_AlphaLookup_o2_a,
        &claw_main_DWork.AlphaLookup_DWORK1_j);

      /* Math: '<S293>/Math Function' */
      rtb_MathFunction_n1u = rt_hypot_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);

      /* Gain: '<S217>/Gain3' incorporates:
       *  Trigonometry: '<S293>/Trigonometric Function1'
       */
      claw_main_B.beta_e = claw_main_P.Gain3_Gain_o * rt_atan2_snf
        (rtb_Gain1_idx_0, rtb_MathFunction_n1u);

      /* PreLookup: '<S233>/AlphaLookup1' */
      rtb_AlphaLookup1_o1_k = plook_linxp(claw_main_B.beta_e,
        &claw_main_P.AlphaLookup1_BreakpointsData[0], 26U,
        &rtb_AlphaLookup1_o2_o3, &claw_main_DWork.AlphaLookup1_DWORK1_a);

      /* Interpolation_n-D: '<S233>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S233>/Constant1'
       */
      max_1 = rtb_AlphaLookup_o2_a;
      frac_1n[0] = max_1;
      max_1 = rtb_AlphaLookup1_o2_o3;
      frac_1n[1] = max_1;
      bpIndex_1n[0] = rtb_AlphaLookup_o1_b;
      bpIndex_1n[1] = rtb_AlphaLookup1_o1_k;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_ax[scalarIndex];
        if (claw_main_P.Constant1_Value_ax[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1n[2] = locIndex;
        locIndex = 864U * bpIndex_1n[2U];
        rtb_InterpolationUsingPreloo_bx[scalarIndex] = intrp2d_lx(&bpIndex_1n[0U],
          &frac_1n[0U], &claw_main_P.InterpolationUsingPrelookup_Tab[locIndex],
          32U);
      }

      /* Interpolation_n-D: '<S233>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S233>/Constant2'
       */
      max_1 = rtb_AlphaLookup_o2_a;
      frac_1o[0] = max_1;
      max_1 = rtb_AlphaLookup1_o2_o3;
      frac_1o[1] = max_1;
      bpIndex_1o[0] = rtb_AlphaLookup_o1_b;
      bpIndex_1o[1] = rtb_AlphaLookup1_o1_k;
      locIndex = claw_main_P.Constant2_Value_kh[0];
      if (claw_main_P.Constant2_Value_kh[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1o[2] = locIndex;
      locIndex = 864U * bpIndex_1o[2U];
      rtb_delta_LLh_idx = intrp2d_lx(&bpIndex_1o[0U], &frac_1o[0U],
        &claw_main_P.InterpolationUsingPrelookup1_Ta[locIndex], 32U);
      locIndex = claw_main_P.Constant2_Value_kh[1];
      if (claw_main_P.Constant2_Value_kh[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1o[2] = locIndex;
      locIndex = 864U * bpIndex_1o[2U];
      rtb_delta_LLh_idx_0 = intrp2d_lx(&bpIndex_1o[0U], &frac_1o[0U],
        &claw_main_P.InterpolationUsingPrelookup1_Ta[locIndex], 32U);
      locIndex = claw_main_P.Constant2_Value_kh[2];
      if (claw_main_P.Constant2_Value_kh[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1o[2] = locIndex;
      locIndex = 864U * bpIndex_1o[2U];
      rtb_Switch2_idx = intrp2d_lx(&bpIndex_1o[0U], &frac_1o[0U],
        &claw_main_P.InterpolationUsingPrelookup1_Ta[locIndex], 32U);

      /* Switch: '<S233>/Switch' incorporates:
       *  Constant: '<S216>/symmetry_on'
       *  Constant: '<S233>/Constant3'
       */
      if (claw_main_P.symmetry_on_Value != 0.0) {
        /* Assignment: '<S233>/Assignment to  Lateral' incorporates:
         *  Constant: '<S233>/Constant'
         */
        if (scalarIndex_0 == 1) {
          for (i = 0; i < 6; i++) {
            rtb_AssignmenttoLateral_of[i] = claw_main_P.Constant_Value_p[i];
          }
        }

        rtb_AssignmenttoLateral_of[1] = rtb_delta_LLh_idx;
        rtb_AssignmenttoLateral_of[3] = rtb_delta_LLh_idx_0;
        rtb_AssignmenttoLateral_of[5] = rtb_Switch2_idx;
        for (i = 0; i < 6; i++) {
          rtb_Switch_cu[i] = rtb_AssignmenttoLateral_of[i];
        }
      } else {
        for (i = 0; i < 6; i++) {
          rtb_Switch_cu[i] = claw_main_P.Constant3_Value_n[i];
        }
      }

      /* DataTypeConversion: '<S233>/Data Type Conversion' */
      rtb_delta_LLh_idx = rtb_FromWorkspace_f;
      if ((rtb_FromWorkspace_f < 4.5035996273704960E+015) &&
          (rtb_FromWorkspace_f > -4.5035996273704960E+015)) {
        rtb_delta_LLh_idx = floor(rtb_FromWorkspace_f + 0.5);
      }

      if (rtIsNaN(rtb_FromWorkspace_f) || rtIsInf(rtb_FromWorkspace_f)) {
        rtb_delta_LLh_idx = 0.0;
      } else {
        rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
      }

      rtb_DataTypeConversion_dh = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
        (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

      /* SwitchCase: '<S238>/Switch Case' incorporates:
       *  ActionPort: '<S239>/Action Port'
       *  ActionPort: '<S240>/Action Port'
       *  SubSystem: '<S238>/Switch Case Action Subsystem'
       *  SubSystem: '<S238>/Switch Case Action Subsystem2'
       */
      switch (rtb_DataTypeConversion_dh) {
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
       case 6:
        claw__SwitchCaseActionSubsystem(claw_main_B.alpha_f, claw_main_B.beta_e,
          rtb_DataTypeConversion_dh, claw_main_B.Merge_ie,
          &claw_main_DWork.SwitchCaseActionSubsystem_a,
          (rtP_SwitchCaseActionSubsystem_c *)
          &claw_main_P.SwitchCaseActionSubsystem_a);
        break;

       default:
        /* Constant: '<S240>/Constant4' */
        for (i = 0; i < 6; i++) {
          claw_main_B.Merge_ie[i] = claw_main_P.Constant4_Value_o[i];
        }
        break;
      }

      /* Sum: '<S233>/Add' */
      for (i = 0; i < 6; i++) {
        rtb_Add_mz[i] = (rtb_InterpolationUsingPreloo_bx[i] + rtb_Switch_cu[i])
          + claw_main_B.Merge_ie[i];
      }

      /* PreLookup: '<S263>/Prelookup' */
      rtb_Prelookup_o1_bs = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup_BreakpointsData[0], 31U, &rtb_Prelookup_o2_p,
        &claw_main_DWork.Prelookup_DWORK1_fy);

      /* Switch: '<S263>/Switch' incorporates:
       *  Constant: '<S263>/Constant'
       *  Constant: '<S263>/Constant1'
       */
      if (rtb_RUDUPC_a >= claw_main_P.Switch_Threshold_o) {
        rtb_Switch_ln = claw_main_P.Constant_Value_e2;
      } else {
        rtb_Switch_ln = claw_main_P.Constant1_Value_cw;
      }

      /* PreLookup: '<S263>/Prelookup1' incorporates:
       *  Product: '<S263>/Product1'
       */
      rtb_Prelookup1_o1_ah = plook_linxp(claw_main_B.beta_e * rtb_Switch_ln,
        &claw_main_P.Prelookup1_BreakpointsData[0], 26U, &rtb_Prelookup1_o2_g,
        &claw_main_DWork.Prelookup1_DWORK1_p5);

      /* PreLookup: '<S263>/Prelookup2' incorporates:
       *  Abs: '<S263>/Abs'
       *  Gain: '<S263>/Gain'
       */
      rtb_Prelookup2_o1_g = plook_linxp(claw_main_P.Gain_Gain_iw * fabs
        (rtb_RUDUPC_a), &claw_main_P.Prelookup2_BreakpointsData[0], 3U,
        &rtb_Prelookup2_o2_kn, &claw_main_DWork.Prelookup2_DWORK1_fz);

      /* Interpolation_n-D: '<S263>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S263>/Constant2'
       */
      max_1 = rtb_Prelookup_o2_p;
      frac_1p[0] = max_1;
      max_1 = rtb_Prelookup1_o2_g;
      frac_1p[1] = max_1;
      max_1 = rtb_Prelookup2_o2_kn;
      frac_1p[2] = max_1;
      bpIndex_1p[0] = rtb_Prelookup_o1_bs;
      bpIndex_1p[1] = rtb_Prelookup1_o1_ah;
      bpIndex_1p[2] = rtb_Prelookup2_o1_g;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant2_Value_ha[scalarIndex];
        if (claw_main_P.Constant2_Value_ha[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1p[3] = locIndex;
        locIndex = 3456U * bpIndex_1p[3U];
        rtb_InterpolationUsingPreloo_nk[scalarIndex] = intrp3d_lx(&bpIndex_1p[0U],
          &frac_1p[0U], &claw_main_P.InterpolationUsingPrelookup_T_p[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_dim[0]);
      }

      /* Assignment: '<S263>/Assignment to lateral' incorporates:
       *  Constant: '<S263>/Constant3'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_Assignmenttolateral_o[i] = claw_main_P.Constant3_Value_b[i];
        }
      }

      rtb_Assignmenttolateral_o[1] = rtb_Switch_ln;
      rtb_Assignmenttolateral_o[3] = rtb_Switch_ln;
      rtb_Assignmenttolateral_o[5] = rtb_Switch_ln;

      /* Product: '<S260>/Product' incorporates:
       *  Constant: '<S260>/gains'
       *  Product: '<S263>/Product2'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_pz[i] = rtb_InterpolationUsingPreloo_nk[i] *
          rtb_Assignmenttolateral_o[i] * claw_main_P.gains_Value[i];
      }

      /* PreLookup: '<S262>/Prelookup' */
      rtb_Prelookup_o1_h = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup_BreakpointsData_g[0], 31U, &rtb_Prelookup_o2_ef,
        &claw_main_DWork.Prelookup_DWORK1_p1);

      /* Switch: '<S262>/Switch' incorporates:
       *  Constant: '<S262>/Constant'
       *  Constant: '<S262>/Constant1'
       */
      if (rtb_RUDLOC_hv >= claw_main_P.Switch_Threshold_n) {
        rtb_Switch_bz = claw_main_P.Constant_Value_e;
      } else {
        rtb_Switch_bz = claw_main_P.Constant1_Value_b;
      }

      /* PreLookup: '<S262>/Prelookup1' incorporates:
       *  Product: '<S262>/Product1'
       */
      rtb_Prelookup1_o1_bl = plook_linxp(claw_main_B.beta_e * rtb_Switch_bz,
        &claw_main_P.Prelookup1_BreakpointsData_a[0], 26U, &rtb_Prelookup1_o2_dq,
        &claw_main_DWork.Prelookup1_DWORK1_bw);

      /* PreLookup: '<S262>/Prelookup2' incorporates:
       *  Abs: '<S262>/Abs'
       *  Gain: '<S262>/Gain'
       */
      rtb_Prelookup2_o1_hb = plook_linxp(claw_main_P.Gain_Gain_k * fabs
        (rtb_RUDLOC_hv), &claw_main_P.Prelookup2_BreakpointsData_h[0], 3U,
        &rtb_Prelookup2_o2_bj, &claw_main_DWork.Prelookup2_DWORK1_en);

      /* Interpolation_n-D: '<S262>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S262>/Constant2'
       */
      max_1 = rtb_Prelookup_o2_ef;
      frac_1q[0] = max_1;
      max_1 = rtb_Prelookup1_o2_dq;
      frac_1q[1] = max_1;
      max_1 = rtb_Prelookup2_o2_bj;
      frac_1q[2] = max_1;
      bpIndex_1q[0] = rtb_Prelookup_o1_h;
      bpIndex_1q[1] = rtb_Prelookup1_o1_bl;
      bpIndex_1q[2] = rtb_Prelookup2_o1_hb;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant2_Value_ke[scalarIndex];
        if (claw_main_P.Constant2_Value_ke[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1q[3] = locIndex;
        locIndex = 3456U * bpIndex_1q[3U];
        rtb_InterpolationUsingPreloo_ds[scalarIndex] = intrp3d_lx(&bpIndex_1q[0U],
          &frac_1q[0U], &claw_main_P.InterpolationUsingPrelookup_T_j[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_c[0]);
      }

      /* Assignment: '<S262>/Assignment to lateral' incorporates:
       *  Constant: '<S262>/Constant3'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_Assignmenttolateral_n[i] = claw_main_P.Constant3_Value_o[i];
        }
      }

      rtb_Assignmenttolateral_n[1] = rtb_Switch_bz;
      rtb_Assignmenttolateral_n[3] = rtb_Switch_bz;
      rtb_Assignmenttolateral_n[5] = rtb_Switch_bz;

      /* Product: '<S261>/Product' incorporates:
       *  Constant: '<S261>/gains'
       *  Product: '<S262>/Product2'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_o3[i] = rtb_InterpolationUsingPreloo_ds[i] *
          rtb_Assignmenttolateral_n[i] * claw_main_P.gains_Value_f[i];
      }

      /* PreLookup: '<S242>/Prelookup1' */
      rtb_Prelookup1_o1_lj = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup1_BreakpointsData_b[0], 31U, &rtb_Prelookup1_o2_bo,
        &claw_main_DWork.Prelookup1_DWORK1_jw);

      /* PreLookup: '<S242>/Prelookup2' incorporates:
       *  Gain: '<S242>/Gain2'
       */
      rtb_Prelookup2_o1_eq = plook_linxp(claw_main_P.Gain2_Gain_m *
        claw_main_B.beta_e, &claw_main_P.Prelookup2_BreakpointsData_j[0], 26U,
        &rtb_Prelookup2_o2_ll, &claw_main_DWork.Prelookup2_DWORK1_g);

      /* PreLookup: '<S242>/Prelookup3' */
      rtb_Prelookup3_o1_e0 = plook_linxp(rtb_dL_Ail_n + rtb_AILLC_o,
        &claw_main_P.Prelookup3_BreakpointsData[0], 6U, &rtb_Prelookup3_o2_ki,
        &claw_main_DWork.Prelookup3_DWORK1_ce);

      /* Interpolation_n-D: '<S242>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S242>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_bo;
      frac_1r[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ll;
      frac_1r[1] = max_1;
      max_1 = rtb_Prelookup3_o2_ki;
      frac_1r[2] = max_1;
      bpIndex_1r[0] = rtb_Prelookup1_o1_lj;
      bpIndex_1r[1] = rtb_Prelookup2_o1_eq;
      bpIndex_1r[2] = rtb_Prelookup3_o1_e0;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_kx[scalarIndex];
        if (claw_main_P.Constant3_Value_kx[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1r[3] = locIndex;
        locIndex = 6048U * bpIndex_1r[3U];
        rtb_InterpolationUsingPreloo_j1[scalarIndex] = intrp3d_lx(&bpIndex_1r[0U],
          &frac_1r[0U], &claw_main_P.InterpolationUsingPrelookup_T_a[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_k[0]);
      }

      /* Gain: '<S242>/Negate Lateral' */
      for (i = 0; i < 6; i++) {
        rtb_NegateLateral_bi[i] = claw_main_P.NegateLateral_Gain[i] *
          rtb_InterpolationUsingPreloo_j1[i];
      }

      /* PreLookup: '<S242>/Prelookup4' */
      rtb_Prelookup4_o1_kq = plook_linxp(claw_main_B.beta_e,
        &claw_main_P.Prelookup4_BreakpointsData[0], 26U, &rtb_Prelookup4_o2_l5,
        &claw_main_DWork.Prelookup4_DWORK1_a2);

      /* PreLookup: '<S242>/Prelookup5' */
      rtb_Prelookup5_o1_e = plook_linxp(rtb_dR_Ail_f + rtb_AILRC_b,
        &claw_main_P.Prelookup5_BreakpointsData[0], 6U, &rtb_Prelookup5_o2_a,
        &claw_main_DWork.Prelookup5_DWORK1_a2);

      /* Interpolation_n-D: '<S242>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S242>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_bo;
      frac_1s[0] = max_1;
      max_1 = rtb_Prelookup4_o2_l5;
      frac_1s[1] = max_1;
      max_1 = rtb_Prelookup5_o2_a;
      frac_1s[2] = max_1;
      bpIndex_1s[0] = rtb_Prelookup1_o1_lj;
      bpIndex_1s[1] = rtb_Prelookup4_o1_kq;
      bpIndex_1s[2] = rtb_Prelookup5_o1_e;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_adm[scalarIndex];
        if (claw_main_P.Constant1_Value_adm[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1s[3] = locIndex;
        locIndex = 6048U * bpIndex_1s[3U];
        rtb_InterpolationUsingPreloo_pu[scalarIndex] = intrp3d_lx(&bpIndex_1s[0U],
          &frac_1s[0U], &claw_main_P.InterpolationUsingPrelookup1__l[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1_di[0]);
      }

      /* PreLookup: '<S268>/Prelookup1' */
      rtb_Prelookup1_o1_nx = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup1_BreakpointsData_f[0], 31U, &rtb_Prelookup1_o2_d3,
        &claw_main_DWork.Prelookup1_DWORK1_bb);

      /* PreLookup: '<S268>/Prelookup2' incorporates:
       *  Gain: '<S268>/Gain2'
       */
      rtb_Prelookup2_o1_gu = plook_linxp(claw_main_P.Gain2_Gain_f *
        claw_main_B.beta_e, &claw_main_P.Prelookup2_BreakpointsData_f[0], 26U,
        &rtb_Prelookup2_o2_ir, &claw_main_DWork.Prelookup2_DWORK1_mr);

      /* PreLookup: '<S268>/Prelookup3' */
      rtb_Prelookup3_o1_gf = plook_linxp(rtb_SPLLIBC_b,
        &claw_main_P.Prelookup3_BreakpointsData_d[0], 2U, &rtb_Prelookup3_o2_pb,
        &claw_main_DWork.Prelookup3_DWORK1_g);

      /* Interpolation_n-D: '<S268>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S268>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_d3;
      frac_1t[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ir;
      frac_1t[1] = max_1;
      max_1 = rtb_Prelookup3_o2_pb;
      frac_1t[2] = max_1;
      bpIndex_1t[0] = rtb_Prelookup1_o1_nx;
      bpIndex_1t[1] = rtb_Prelookup2_o1_gu;
      bpIndex_1t[2] = rtb_Prelookup3_o1_gf;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_dt[scalarIndex];
        if (claw_main_P.Constant3_Value_dt[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1t[3] = locIndex;
        locIndex = 2592U * bpIndex_1t[3U];
        rtb_InterpolationUsingPrelo_fie[scalarIndex] = intrp3d_lx(&bpIndex_1t[0U],
          &frac_1t[0U], &claw_main_P.InterpolationUsingPrelookup__ai[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_n[0]);
      }

      /* Product: '<S265>/Product' incorporates:
       *  Constant: '<S265>/gains'
       *  Gain: '<S268>/Negate Lateral'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_go[i] = claw_main_P.NegateLateral_Gain_d[i] *
          rtb_InterpolationUsingPrelo_fie[i] * claw_main_P.gains_Value_i[i];
      }

      /* PreLookup: '<S269>/Prelookup1' */
      rtb_Prelookup1_o1_ke = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup1_BreakpointsData_i[0], 31U, &rtb_Prelookup1_o2_j4,
        &claw_main_DWork.Prelookup1_DWORK1_o);

      /* PreLookup: '<S269>/Prelookup2' incorporates:
       *  Gain: '<S269>/Gain2'
       */
      rtb_Prelookup2_o1_ok = plook_linxp(claw_main_P.Gain2_Gain_fn *
        claw_main_B.beta_e, &claw_main_P.Prelookup2_BreakpointsData_b[0], 26U,
        &rtb_Prelookup2_o2_bz, &claw_main_DWork.Prelookup2_DWORK1_ch);

      /* PreLookup: '<S269>/Prelookup3' */
      rtb_Prelookup3_o1_h = plook_linxp(rtb_SPLLOBC_d,
        &claw_main_P.Prelookup3_BreakpointsData_p[0], 2U, &rtb_Prelookup3_o2_h,
        &claw_main_DWork.Prelookup3_DWORK1_kw);

      /* Interpolation_n-D: '<S269>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S269>/Constant3'
       */
      max_1 = rtb_Prelookup1_o2_j4;
      frac_1u[0] = max_1;
      max_1 = rtb_Prelookup2_o2_bz;
      frac_1u[1] = max_1;
      max_1 = rtb_Prelookup3_o2_h;
      frac_1u[2] = max_1;
      bpIndex_1u[0] = rtb_Prelookup1_o1_ke;
      bpIndex_1u[1] = rtb_Prelookup2_o1_ok;
      bpIndex_1u[2] = rtb_Prelookup3_o1_h;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant3_Value_d1[scalarIndex];
        if (claw_main_P.Constant3_Value_d1[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1u[3] = locIndex;
        locIndex = 2592U * bpIndex_1u[3U];
        rtb_InterpolationUsingPrelo_mic[scalarIndex] = intrp3d_lx(&bpIndex_1u[0U],
          &frac_1u[0U], &claw_main_P.InterpolationUsingPrelookup__af[locIndex],
          &claw_main_P.InterpolationUsingPrelookup_d_i[0]);
      }

      /* Product: '<S266>/Product' incorporates:
       *  Constant: '<S266>/gains'
       *  Gain: '<S269>/Negate Lateral'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_j5[i] = claw_main_P.NegateLateral_Gain_l[i] *
          rtb_InterpolationUsingPrelo_mic[i] * claw_main_P.gains_Value_e[i];
      }

      /* PreLookup: '<S268>/Prelookup4' */
      rtb_Prelookup4_o1_d5 = plook_linxp(claw_main_B.beta_e,
        &claw_main_P.Prelookup4_BreakpointsData_l[0], 26U, &rtb_Prelookup4_o2_e3,
        &claw_main_DWork.Prelookup4_DWORK1_e);

      /* PreLookup: '<S268>/Prelookup5' */
      rtb_Prelookup5_o1_hq = plook_linxp(rtb_orderatts_i_idx,
        &claw_main_P.Prelookup5_BreakpointsData_g[0], 2U, &rtb_Prelookup5_o2_bn,
        &claw_main_DWork.Prelookup5_DWORK1_fq);

      /* Interpolation_n-D: '<S268>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S268>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_d3;
      frac_1v[0] = max_1;
      max_1 = rtb_Prelookup4_o2_e3;
      frac_1v[1] = max_1;
      max_1 = rtb_Prelookup5_o2_bn;
      frac_1v[2] = max_1;
      bpIndex_1v[0] = rtb_Prelookup1_o1_nx;
      bpIndex_1v[1] = rtb_Prelookup4_o1_d5;
      bpIndex_1v[2] = rtb_Prelookup5_o1_hq;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_ng[scalarIndex];
        if (claw_main_P.Constant1_Value_ng[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1v[3] = locIndex;
        locIndex = 2592U * bpIndex_1v[3U];
        rtb_InterpolationUsingPreloo_jx[scalarIndex] = intrp3d_lx(&bpIndex_1v[0U],
          &frac_1v[0U], &claw_main_P.InterpolationUsingPrelookup1__e[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1_nq[0]);
      }

      /* Product: '<S264>/Product' incorporates:
       *  Constant: '<S264>/gains'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_lm[i] = rtb_InterpolationUsingPreloo_jx[i] *
          claw_main_P.gains_Value_ig[i];
      }

      /* PreLookup: '<S269>/Prelookup4' */
      rtb_Prelookup4_o1_np = plook_linxp(claw_main_B.beta_e,
        &claw_main_P.Prelookup4_BreakpointsData_m[0], 26U, &rtb_Prelookup4_o2_gw,
        &claw_main_DWork.Prelookup4_DWORK1_ct);

      /* PreLookup: '<S269>/Prelookup5' */
      rtb_Prelookup5_o1_mx = plook_linxp(rtb_Switch_d_idx_0,
        &claw_main_P.Prelookup5_BreakpointsData_f[0], 2U, &rtb_Prelookup5_o2_g,
        &claw_main_DWork.Prelookup5_DWORK1_h);

      /* Interpolation_n-D: '<S269>/Interpolation Using Prelookup1' incorporates:
       *  Constant: '<S269>/Constant1'
       */
      max_1 = rtb_Prelookup1_o2_j4;
      frac_1w[0] = max_1;
      max_1 = rtb_Prelookup4_o2_gw;
      frac_1w[1] = max_1;
      max_1 = rtb_Prelookup5_o2_g;
      frac_1w[2] = max_1;
      bpIndex_1w[0] = rtb_Prelookup1_o1_ke;
      bpIndex_1w[1] = rtb_Prelookup4_o1_np;
      bpIndex_1w[2] = rtb_Prelookup5_o1_mx;
      for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
        locIndex = claw_main_P.Constant1_Value_oj[scalarIndex];
        if (claw_main_P.Constant1_Value_oj[scalarIndex] > 5U) {
          locIndex = 5U;
        }

        bpIndex_1w[3] = locIndex;
        locIndex = 2592U * bpIndex_1w[3U];
        rtb_InterpolationUsingPreloo_o1[scalarIndex] = intrp3d_lx(&bpIndex_1w[0U],
          &frac_1w[0U], &claw_main_P.InterpolationUsingPrelookup1__i[locIndex],
          &claw_main_P.InterpolationUsingPrelookup1_ff[0]);
      }

      /* Product: '<S267>/Product' incorporates:
       *  Constant: '<S267>/gains'
       */
      for (i = 0; i < 6; i++) {
        rtb_Product_m0[i] = rtb_InterpolationUsingPreloo_o1[i] *
          claw_main_P.gains_Value_p[i];
      }

      /* PreLookup: '<S243>/Prelookup1' */
      rtb_Prelookup1_o1_dq = plook_linxp(claw_main_B.alpha_f,
        &claw_main_P.Prelookup1_BreakpointsData_g[0], 31U, &rtb_Prelookup1_o2_p,
        &claw_main_DWork.Prelookup1_DWORK1_iz);

      /* PreLookup: '<S243>/Prelookup2' */
      rtb_Prelookup2_o1_nhy = plook_linxp(claw_main_B.beta_e,
        &claw_main_P.Prelookup2_BreakpointsData_o[0], 26U, &rtb_Prelookup2_o2_ey,
        &claw_main_DWork.Prelookup2_DWORK1_h);

      /* PreLookup: '<S243>/Prelookup3' */
      rtb_Prelookup3_o1_ig = plook_linxp(rtb_Switch_d_idx_1,
        &claw_main_P.Prelookup3_BreakpointsData_n[0], 3U, &rtb_Prelookup3_o2_i,
        &claw_main_DWork.Prelookup3_DWORK1_h);

      /* PreLookup: '<S254>/Prelookup4' incorporates:
       *  Constant: '<S243>/Constant1'
       */
      rtb_Prelookup4_o1_ao = plook_linxp(claw_main_P.Constant1_Value_j,
        &claw_main_P.Prelookup4_BreakpointsData_g[0], 5U, &rtb_Prelookup4_o2_fx,
        &claw_main_DWork.Prelookup4_DWORK1_kn);

      /* Interpolation_n-D: '<S254>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S254>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_p;
      frac_1x[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ey;
      frac_1x[1] = max_1;
      max_1 = rtb_Prelookup3_o2_i;
      frac_1x[2] = max_1;
      max_1 = rtb_Prelookup4_o2_fx;
      frac_1x[3] = max_1;
      bpIndex_1x[0] = rtb_Prelookup1_o1_dq;
      bpIndex_1x[1] = rtb_Prelookup2_o1_nhy;
      bpIndex_1x[2] = rtb_Prelookup3_o1_ig;
      bpIndex_1x[3] = rtb_Prelookup4_o1_ao;
      locIndex = claw_main_P.Constant2_Value_o[0];
      if (claw_main_P.Constant2_Value_o[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1x[4] = locIndex;
      locIndex = 20736U * bpIndex_1x[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1x[0U], &frac_1x[0U],
        &claw_main_P.InterpolationUsingPrelookup__a2[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_j[0]);
      locIndex = claw_main_P.Constant2_Value_o[1];
      if (claw_main_P.Constant2_Value_o[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1x[4] = locIndex;
      locIndex = 20736U * bpIndex_1x[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1x[0U], &frac_1x[0U],
        &claw_main_P.InterpolationUsingPrelookup__a2[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_j[0]);
      locIndex = claw_main_P.Constant2_Value_o[2];
      if (claw_main_P.Constant2_Value_o[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1x[4] = locIndex;
      locIndex = 20736U * bpIndex_1x[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1x[0U], &frac_1x[0U],
        &claw_main_P.InterpolationUsingPrelookup__a2[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_j[0]);

      /* Assignment: '<S254>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S254>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_kv[i] = claw_main_P.Constant_Value_f[i];
        }
      }

      rtb_AssignmenttoLongitudinal_kv[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_kv[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_kv[4] = rtb_Switch2_idx;

      /* PreLookup: '<S253>/Prelookup4' */
      rtb_Prelookup4_o1_o = plook_linxp(rtb_ELLOBC_n,
        &claw_main_P.Prelookup4_BreakpointsData_d[0], 5U, &rtb_Prelookup4_o2_mk,
        &claw_main_DWork.Prelookup4_DWORK1_cy);

      /* Interpolation_n-D: '<S253>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S253>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_p;
      frac_1y[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ey;
      frac_1y[1] = max_1;
      max_1 = rtb_Prelookup3_o2_i;
      frac_1y[2] = max_1;
      max_1 = rtb_Prelookup4_o2_mk;
      frac_1y[3] = max_1;
      bpIndex_1y[0] = rtb_Prelookup1_o1_dq;
      bpIndex_1y[1] = rtb_Prelookup2_o1_nhy;
      bpIndex_1y[2] = rtb_Prelookup3_o1_ig;
      bpIndex_1y[3] = rtb_Prelookup4_o1_o;
      locIndex = claw_main_P.Constant2_Value_m[0];
      if (claw_main_P.Constant2_Value_m[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1y[4] = locIndex;
      locIndex = 20736U * bpIndex_1y[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1y[0U], &frac_1y[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_i[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_a[0]);
      locIndex = claw_main_P.Constant2_Value_m[1];
      if (claw_main_P.Constant2_Value_m[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1y[4] = locIndex;
      locIndex = 20736U * bpIndex_1y[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1y[0U], &frac_1y[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_i[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_a[0]);
      locIndex = claw_main_P.Constant2_Value_m[2];
      if (claw_main_P.Constant2_Value_m[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1y[4] = locIndex;
      locIndex = 20736U * bpIndex_1y[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1y[0U], &frac_1y[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_i[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_a[0]);

      /* Assignment: '<S253>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S253>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_f[i] = claw_main_P.Constant_Value_l[i];
        }
      }

      rtb_AssignmenttoLongitudinal_f[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_f[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_f[4] = rtb_Switch2_idx;

      /* Gain: '<S250>/Gain' incorporates:
       *  Gain: '<S243>/Gain'
       *  Sum: '<S243>/Add'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_f[i] -
                    rtb_AssignmenttoLongitudinal_kv[i]) *
          claw_main_P.Gain_Gain_l;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_ex[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_ex[i] += claw_main_P.Gain_Gain_bs[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S255>/Prelookup4' */
      rtb_Prelookup4_o1_ah = plook_linxp(rtb_ELLIBC_mo,
        &claw_main_P.Prelookup4_BreakpointsData_a[0], 5U, &rtb_Prelookup4_o2_i4,
        &claw_main_DWork.Prelookup4_DWORK1_hb);

      /* Interpolation_n-D: '<S255>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S255>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_p;
      frac_1z[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ey;
      frac_1z[1] = max_1;
      max_1 = rtb_Prelookup3_o2_i;
      frac_1z[2] = max_1;
      max_1 = rtb_Prelookup4_o2_i4;
      frac_1z[3] = max_1;
      bpIndex_1z[0] = rtb_Prelookup1_o1_dq;
      bpIndex_1z[1] = rtb_Prelookup2_o1_nhy;
      bpIndex_1z[2] = rtb_Prelookup3_o1_ig;
      bpIndex_1z[3] = rtb_Prelookup4_o1_ah;
      locIndex = claw_main_P.Constant2_Value_nr[0];
      if (claw_main_P.Constant2_Value_nr[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1z[4] = locIndex;
      locIndex = 20736U * bpIndex_1z[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_1z[0U], &frac_1z[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_b[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_b[0]);
      locIndex = claw_main_P.Constant2_Value_nr[1];
      if (claw_main_P.Constant2_Value_nr[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1z[4] = locIndex;
      locIndex = 20736U * bpIndex_1z[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_1z[0U], &frac_1z[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_b[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_b[0]);
      locIndex = claw_main_P.Constant2_Value_nr[2];
      if (claw_main_P.Constant2_Value_nr[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_1z[4] = locIndex;
      locIndex = 20736U * bpIndex_1z[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_1z[0U], &frac_1z[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_b[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_b[0]);

      /* Assignment: '<S255>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S255>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_m1[i] = claw_main_P.Constant_Value_c[i];
        }
      }

      rtb_AssignmenttoLongitudinal_m1[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_m1[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_m1[4] = rtb_Switch2_idx;

      /* Gain: '<S249>/Gain' incorporates:
       *  Gain: '<S243>/Gain1'
       *  Sum: '<S243>/Add1'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_m1[i] -
                    rtb_AssignmenttoLongitudinal_kv[i]) *
          claw_main_P.Gain1_Gain_o0;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_o1[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_o1[i] += claw_main_P.Gain_Gain_m[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S257>/Prelookup4' */
      rtb_Prelookup4_o1_gu = plook_linxp(rtb_ELRIBC_b,
        &claw_main_P.Prelookup4_BreakpointsData_n[0], 5U, &rtb_Prelookup4_o2_kc,
        &claw_main_DWork.Prelookup4_DWORK1_a4);

      /* Interpolation_n-D: '<S257>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S257>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_p;
      frac_20[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ey;
      frac_20[1] = max_1;
      max_1 = rtb_Prelookup3_o2_i;
      frac_20[2] = max_1;
      max_1 = rtb_Prelookup4_o2_kc;
      frac_20[3] = max_1;
      bpIndex_20[0] = rtb_Prelookup1_o1_dq;
      bpIndex_20[1] = rtb_Prelookup2_o1_nhy;
      bpIndex_20[2] = rtb_Prelookup3_o1_ig;
      bpIndex_20[3] = rtb_Prelookup4_o1_gu;
      locIndex = claw_main_P.Constant2_Value_pc[0];
      if (claw_main_P.Constant2_Value_pc[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_20[4] = locIndex;
      locIndex = 20736U * bpIndex_20[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_20[0U], &frac_20[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_k[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ao[0]);
      locIndex = claw_main_P.Constant2_Value_pc[1];
      if (claw_main_P.Constant2_Value_pc[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_20[4] = locIndex;
      locIndex = 20736U * bpIndex_20[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_20[0U], &frac_20[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_k[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ao[0]);
      locIndex = claw_main_P.Constant2_Value_pc[2];
      if (claw_main_P.Constant2_Value_pc[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_20[4] = locIndex;
      locIndex = 20736U * bpIndex_20[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_20[0U], &frac_20[0U],
        &claw_main_P.InterpolationUsingPrelookup_T_k[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ao[0]);

      /* Assignment: '<S257>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S257>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_hl[i] = claw_main_P.Constant_Value_cx[i];
        }
      }

      rtb_AssignmenttoLongitudinal_hl[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_hl[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_hl[4] = rtb_Switch2_idx;

      /* Gain: '<S251>/Gain' incorporates:
       *  Gain: '<S243>/Gain2'
       *  Sum: '<S243>/Add2'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_hl[i] -
                    rtb_AssignmenttoLongitudinal_kv[i]) *
          claw_main_P.Gain2_Gain_k;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_oa[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_oa[i] += claw_main_P.Gain_Gain_kt[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }
      }

      /* PreLookup: '<S256>/Prelookup4' */
      rtb_Prelookup4_o1_f = plook_linxp(rtb_ELROBC_gf,
        &claw_main_P.Prelookup4_BreakpointsData_gx[0], 5U, &rtb_Prelookup4_o2_oj,
        &claw_main_DWork.Prelookup4_DWORK1_du);

      /* Interpolation_n-D: '<S256>/Interpolation Using Prelookup' incorporates:
       *  Constant: '<S256>/Constant2'
       */
      max_1 = rtb_Prelookup1_o2_p;
      frac_21[0] = max_1;
      max_1 = rtb_Prelookup2_o2_ey;
      frac_21[1] = max_1;
      max_1 = rtb_Prelookup3_o2_i;
      frac_21[2] = max_1;
      max_1 = rtb_Prelookup4_o2_oj;
      frac_21[3] = max_1;
      bpIndex_21[0] = rtb_Prelookup1_o1_dq;
      bpIndex_21[1] = rtb_Prelookup2_o1_nhy;
      bpIndex_21[2] = rtb_Prelookup3_o1_ig;
      bpIndex_21[3] = rtb_Prelookup4_o1_f;
      locIndex = claw_main_P.Constant2_Value_ar[0];
      if (claw_main_P.Constant2_Value_ar[0] > 2U) {
        locIndex = 2U;
      }

      bpIndex_21[4] = locIndex;
      locIndex = 20736U * bpIndex_21[4U];
      rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_21[0U], &frac_21[0U],
        &claw_main_P.InterpolationUsingPrelookup__jc[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_m[0]);
      locIndex = claw_main_P.Constant2_Value_ar[1];
      if (claw_main_P.Constant2_Value_ar[1] > 2U) {
        locIndex = 2U;
      }

      bpIndex_21[4] = locIndex;
      locIndex = 20736U * bpIndex_21[4U];
      rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_21[0U], &frac_21[0U],
        &claw_main_P.InterpolationUsingPrelookup__jc[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_m[0]);
      locIndex = claw_main_P.Constant2_Value_ar[2];
      if (claw_main_P.Constant2_Value_ar[2] > 2U) {
        locIndex = 2U;
      }

      bpIndex_21[4] = locIndex;
      locIndex = 20736U * bpIndex_21[4U];
      rtb_Switch2_idx = intrp4d_lx(&bpIndex_21[0U], &frac_21[0U],
        &claw_main_P.InterpolationUsingPrelookup__jc[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_d_m[0]);

      /* Assignment: '<S256>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S256>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_h5[i] = claw_main_P.Constant_Value_ps[i];
        }
      }

      rtb_AssignmenttoLongitudinal_h5[0] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLongitudinal_h5[2] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_h5[4] = rtb_Switch2_idx;

      /* Gain: '<S252>/Gain' incorporates:
       *  Gain: '<S243>/Gain3'
       *  Sum: '<S243>/Add3'
       */
      for (i = 0; i < 6; i++) {
        min_6[i] = (rtb_AssignmenttoLongitudinal_h5[i] -
                    rtb_AssignmenttoLongitudinal_kv[i]) *
          claw_main_P.Gain3_Gain_k;
      }

      for (i = 0; i < 6; i++) {
        rtb_Gain_nw[i] = 0.0;
        for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
          rtb_Gain_nw[i] += claw_main_P.Gain_Gain_d[6 * yOffset_0 + i] *
            min_6[yOffset_0];
        }

        /* Gain: '<S244>/Gain' */
        rtb_Gain_ez[i] = claw_main_P.Gain_Gain_hf[i] * rtb_Sum_ow_idx;

        /* Gain: '<S244>/Gain1' */
        rtb_Gain1_os[i] = claw_main_P.Gain1_Gain_pw[i] * rtb_Switch_d_idx;

        /* Gain: '<S244>/Gain2' */
        rtb_Gain2_dt[i] = claw_main_P.Gain2_Gain_mb[i] * rtb_Sum_ow_idx_0;

        /* Gain: '<S244>/Gain3' */
        rtb_Gain3_o2[i] = claw_main_P.Gain3_Gain_b[i] * rtb_Sum_ow_idx_1;
      }

      /* S-Function (sfun_idxsearch): '<S245>/PreLookup Index Search1' */
      scalarPrevIndex_3 = claw_main_DWork.PreLookupIndexSearch1_MODE_n;
      i = plook_s32dd_binxp(claw_main_B.alpha_f,
                            &claw_main_P.PreLookupIndexSearch1_bpData[0], 31U,
                            &scalarFraction_6, &scalarPrevIndex_3);
      rtb_delta_LLh_idx = scalarFraction_6;

      /* S-Function (sfun_kflookupnd): '<S245>/TableLookup' incorporates:
       *  Constant: '<S245>/Constant2'
       *  DataTypeConversion: '<S245>/Data Type Conversion2'
       *  RelationalOperator: '<S258>/Compare'
       */
      if (i > 30) {
        max_1 = 30.0;
      } else if (i >= 0) {
        max_1 = (real_T)i;
      } else {
        max_1 = 0.0;
      }

      i = (int32_T)max_1;
      yOffset_0 = (rtb_Gain_g_idx != 0.0);
      if (claw_main_P.Constant2_Value_do[0] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_do[0];
      }

      rtb_delta_LLh_idx_0 = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData[(scalarIndex << 6U) + (yOffset_0 << 5)]);
      if (claw_main_P.Constant2_Value_do[1] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_do[1];
      }

      rtb_Switch2_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData[(scalarIndex << 6U) + (yOffset_0 << 5)]);
      if (claw_main_P.Constant2_Value_do[2] > 2U) {
        scalarIndex = 2U;
      } else {
        scalarIndex = claw_main_P.Constant2_Value_do[2];
      }

      rtb_delta_LLh_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
        &claw_main_P.TableLookup_tableData[(scalarIndex << 6U) + (yOffset_0 << 5)]);

      /* Assignment: '<S245>/Assignment to  Longitudinal' incorporates:
       *  Constant: '<S245>/Constant'
       */
      if (scalarIndex_0 == 1) {
        for (i = 0; i < 6; i++) {
          rtb_AssignmenttoLongitudinal_b[i] = claw_main_P.Constant_Value_n[i];
        }
      }

      rtb_AssignmenttoLongitudinal_b[0] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLongitudinal_b[2] = rtb_Switch2_idx;
      rtb_AssignmenttoLongitudinal_b[4] = rtb_delta_LLh_idx;
      claw_main_ImplementDamageModels(rtb_Product_pz, rtb_Product_o3,
        rtb_NegateLateral_bi, rtb_InterpolationUsingPreloo_pu, rtb_Product_go,
        rtb_Product_j5, rtb_Product_lm, rtb_Product_m0,
        rtb_AssignmenttoLongitudinal_kv, rtb_Gain_ex, rtb_Gain_o1, rtb_Gain_oa,
        rtb_Gain_nw, rtb_Gain_ez, rtb_Gain1_os, rtb_Gain2_dt, rtb_Gain3_o2,
        rtb_AssignmenttoLongitudinal_b, rtb_FromWorkspace_f,
        &claw_main_B.sf_ImplementDamageModels_j);

      /* Reshape: '<S246>/Reshape' */
      for (i = 0; i < 6; i++) {
        rtb_Reshape_h3[i] = claw_main_B.sf_ImplementDamageModels_j.dC6[i];
      }

      /* Math: '<S293>/Math Function1' */
      rtb_MathFunction1_f = rt_hypot_snf(rtb_MathFunction_n1u, rtb_Gain1_idx_0);

      /* MinMax: '<S220>/MinMax' incorporates:
       *  Constant: '<S220>/Constant'
       */
      max_1 = rt_MAXd_snf(claw_main_P.Constant_Value_db, rtb_MathFunction1_f);

      /* Gain: '<S217>/Gain5' */
      rtb_tas_bc = claw_main_P.Gain5_Gain_o * max_1;

      /* DataTypeConversion: '<S236>/Data Type Conversion' */
      rtb_delta_LLh_idx = rtb_FromWorkspace_f;
      if ((rtb_FromWorkspace_f < 4.5035996273704960E+015) &&
          (rtb_FromWorkspace_f > -4.5035996273704960E+015)) {
        rtb_delta_LLh_idx = floor(rtb_FromWorkspace_f + 0.5);
      }

      if (rtIsNaN(rtb_FromWorkspace_f) || rtIsInf(rtb_FromWorkspace_f)) {
        rtb_delta_LLh_idx = 0.0;
      } else {
        rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
      }

      rtb_DataTypeConversion_j = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
        (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

      /* SwitchCase: '<S236>/Switch Case' incorporates:
       *  ActionPort: '<S270>/Action Port'
       *  ActionPort: '<S271>/Action Port'
       *  SubSystem: '<S236>/Forced Oscillation with Damage Increments'
       *  SubSystem: '<S236>/Rotary Blended  UnDamaged Case'
       */
      switch (rtb_DataTypeConversion_j) {
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
       case 6:
        ForcedOscillationwithDamageIncr(claw_main_B.alpha_f,
          rtb_DataTypeConversion_j, rtb_tas_bc, rtb_sensors, claw_main_P.B_Value,
          claw_main_P.Cbar_Value, claw_main_B.Merge_k,
          &claw_main_B.ForcedOscillationwithDamageIn_b,
          &claw_main_DWork.ForcedOscillationwithDamageIn_b,
          (rtP_ForcedOscillationwithDamage *)
          &claw_main_P.ForcedOscillationwithDamageIn_b,
          &claw_main_DWork.WhileIterator_IterationMarker_n[0]);
        break;

       default:
        claw_RotaryBlendedUnDamagedCase(claw_main_B.alpha_f, rtb_tas_bc,
          claw_main_B.beta_e, rtb_sensors, claw_main_P.B_Value,
          claw_main_P.Cbar_Value, claw_main_B.Merge_k,
          &claw_main_B.RotaryBlendedUnDamagedCase_ka,
          &claw_main_DWork.RotaryBlendedUnDamagedCase_ka,
          (rtP_RotaryBlendedUnDamagedCase_ *)
          &claw_main_P.RotaryBlendedUnDamagedCase_ka,
          &claw_main_DWork.WhileIterator_IterationMarker_n[0]);
        break;
      }

      /* Fcn: '<S220>/wind_qbar' */
      if ((max_1 < 0.0) && (2.0 > floor(2.0))) {
        rtb_MultiportSwitch2_idx_2 = -rt_pow_snf(-max_1, 2.0);
      } else {
        rtb_MultiportSwitch2_idx_2 = rt_pow_snf(max_1, 2.0);
      }

      /* Product: '<S220>/Product1' */
      rtb_qbar_b = 0.5 * rtb_MultiportSwitch2_idx_2 * rtb_Product_b;

      /* Gain: '<S234>/Gain2' incorporates:
       *  Product: '<S234>/Product'
       *  Sum: '<S216>/Sum8'
       */
      for (i = 0; i < 6; i++) {
        rtb_Gain2_dg[i] = ((rtb_Add_mz[i] + rtb_Reshape_h3[i]) +
                           claw_main_B.Merge_k[i]) * rtb_qbar_b *
          claw_main_P.Gain2_Gain_c;
      }

      /* Sum: '<S234>/Sum' incorporates:
       *  Constant: '<S215>/xCG1'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_b[0] - rtb_Add2_idx_0;

      /* Gain: '<S241>/Gain' */
      rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_a * rtb_Switch2_idx;
      rtb_Gain1_idx_1 = rtb_Switch2_idx;

      /* Sum: '<S234>/Sum' incorporates:
       *  Constant: '<S215>/xCG1'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_b[1] - rtb_Add2_idx_1;

      /* Gain: '<S241>/Gain' */
      rtb_delta_LLh_idx = claw_main_P.Gain_Gain_a * rtb_Switch2_idx;
      rtb_delta_LLh_idx_0 = rtb_Switch2_idx;

      /* Sum: '<S234>/Sum' incorporates:
       *  Constant: '<S215>/xCG1'
       *  Reshape: '<S221>/Reshape'
       */
      rtb_Switch2_idx = claw_main_P.xCG1_Value_b[2] - rtb_Add2_idx;

      /* Sum: '<S209>/Sum' incorporates:
       *  Gain: '<S234>/Reference Lengths'
       *  Gain: '<S241>/Gain'
       *  Product: '<S241>/Product'
       *  Reshape: '<S241>/Reshape'
       *  Reshape: '<S241>/Reshape1'
       *  Sum: '<S218>/Sum'
       *  Sum: '<S234>/Sum1'
       */
      min_6[0] = claw_main_B.sf_EngineAlignment_b.T[0];
      min_6[1] = claw_main_B.sf_EngineAlignment_b.T[1];
      min_6[2] = claw_main_B.sf_EngineAlignment_b.T[2];
      min_6[3] = (rtb_dircos_0[0] + rtb_Gain_e_0[0]) + rtb_Product_ia[0];
      min_6[4] = (rtb_dircos_0[1] + rtb_Gain_e_0[1]) + rtb_Product_ia[1];
      min_6[5] = (rtb_dircos_0[2] + rtb_Gain_e_0[2]) + rtb_Product_ia[2];
      rtb_Gain1_oy_0[0] = 0.0;
      rtb_Gain1_oy_0[1] = rtb_Switch2_idx;
      rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
      rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_a * rtb_Switch2_idx;
      rtb_Gain1_oy_0[4] = 0.0;
      rtb_Gain1_oy_0[5] = rtb_Gain1_idx_1;
      rtb_Gain1_oy_0[6] = rtb_delta_LLh_idx_0;
      rtb_Gain1_oy_0[7] = rtb_Gain1_idx_0;
      rtb_Gain1_oy_0[8] = 0.0;
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Gain2_dg[0];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Gain2_dg[1];
        rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Gain2_dg[2];
      }

      rtb_Gain2_n_0[0] = rtb_Gain2_dg[0];
      rtb_Gain2_n_0[1] = rtb_Gain2_dg[1];
      rtb_Gain2_n_0[2] = rtb_Gain2_dg[2];
      rtb_Gain2_n_0[3] = claw_main_P.ReferenceLengths_Gain[0] * rtb_Gain2_dg[3]
        + rtb_dircos_0[0];
      rtb_Gain2_n_0[4] = claw_main_P.ReferenceLengths_Gain[1] * rtb_Gain2_dg[4]
        + rtb_dircos_0[1];
      rtb_Gain2_n_0[5] = claw_main_P.ReferenceLengths_Gain[2] * rtb_Gain2_dg[5]
        + rtb_dircos_0[2];
      for (i = 0; i < 6; i++) {
        rtb_Sum_aw[i] = min_6[i] + rtb_Gain2_n_0[i];
      }

      /* Inport: '<S194>/xdot_nom' */
      for (i = 0; i < 3; i++) {
        /* Product: '<S208>/Product2' */
        rtb_Product2_aq[i] = 0.0;
        rtb_Product2_aq[i] += rtb_inertia[i] * rtb_sensors[0];
        rtb_Product2_aq[i] += rtb_inertia[i + 3] * rtb_sensors[1];
        rtb_Product2_aq[i] += rtb_inertia[i + 6] * rtb_sensors[2];
        rtb_xdot_nom[i] = rtb_pqrdot[i];
      }

      rtb_xdot_nom[3] = rtb_Product1_b_idx_1;
      rtb_xdot_nom[4] = rtb_Sum_h_idx;
      rtb_xdot_nom[5] = rtb_Assignment_l_idx;
      rtb_xdot_nom[6] = rtb_Gain_g_idx_0;
      rtb_xdot_nom[7] = rtb_Gain_g_idx_1;
      rtb_xdot_nom[8] = rtb_Gain_g_idx_2;
      rtb_xdot_nom[9] = rtb_Gain_g_idx_3;
      rtb_xdot_nom[10] = rtb_Gain_g_idx_4;
      rtb_xdot_nom[11] = rtb_Product1_b_idx;
      rtb_xdot_nom[12] = rtb_Product1_b_idx_0;

      /* Sum: '<S294>/Sum1' */
      for (i = 0; i < 6; i++) {
        rtb_Sum1_ku[i] = rtb_Switch_jl[i] - rtb_zeroRCSinputs[i];
      }

      rtb_Sum1_ku[6] = rtb_Switch_jl[6] - rtb_zeroRCSinputs[7];
      rtb_Sum1_ku[7] = rtb_Switch_jl[7] - rtb_zeroRCSinputs[8];
      rtb_Sum1_ku[8] = rtb_Switch_jl[8] - rtb_zeroRCSinputs[9];

      /* Selector: '<S294>/Selector4' */
      rtb_Selector4_m = rtb_Sum1_ku[(int32_T)rtb_MultiportSwitch_kx - 1];

      /* Product: '<S194>/Product' incorporates:
       *  Product: '<S208>/Product3'
       *  Product: '<S211>/Product'
       *  Product: '<S211>/Product1'
       *  Product: '<S213>/Product'
       *  Product: '<S213>/Product1'
       *  Sum: '<S194>/Sum1'
       *  Sum: '<S208>/Sum1'
       *  Sum: '<S211>/Sum'
       *  Sum: '<S213>/Sum'
       */
      rtb_delta_LLh_idx = (rtb_Sum_aw[3] - (rtb_sensors[1] * 0.0 - rtb_sensors[2]
        * 0.0)) - (rtb_sensors[1] * rtb_Product2_aq[2] - rtb_sensors[2] *
                   rtb_Product2_aq[1]);
      rtb_delta_LLh_idx_0 = (rtb_Sum_aw[4] - (rtb_sensors[2] * 0.0 -
        rtb_sensors[0] * 0.0)) - (rtb_sensors[2] * rtb_Product2_aq[0] -
        rtb_sensors[0] * rtb_Product2_aq[2]);
      rtb_Switch2_idx = (rtb_Sum_aw[5] - (rtb_sensors[0] * 0.0 - rtb_sensors[1] *
        0.0)) - (rtb_sensors[0] * rtb_Product2_aq[1] - rtb_sensors[1] *
                 rtb_Product2_aq[0]);
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_inertia_inv[i] * rtb_delta_LLh_idx;
        rtb_dircos_0[i] += rtb_inertia_inv[i + 3] * rtb_delta_LLh_idx_0;
        rtb_dircos_0[i] += rtb_inertia_inv[i + 6] * rtb_Switch2_idx;
      }

      /* Assignment: '<S194>/Assignment' incorporates:
       *  Reshape: '<S194>/Reshape'
       */
      if (scalarIndex_0 == 1) {
        memcpy((void *)&rtb_Assignment_k[0], (void *)&rtb_Memory1_e[0], 27U *
               (uint32_T)((char_T *)&rtb_Memory1_e[1U] - (char_T *)
                          &rtb_Memory1_e[0U]));
      }

      i = ((int32_T)rtb_MultiportSwitch_kx - 1) * 3;
      rtb_Assignment_k[i] = (rtb_dircos_0[0] - rtb_xdot_nom[0]) /
        rtb_Selector4_m;
      rtb_Assignment_k[i + 1] = (rtb_dircos_0[1] - rtb_xdot_nom[1]) /
        rtb_Selector4_m;
      rtb_Assignment_k[i + 2] = (rtb_dircos_0[2] - rtb_xdot_nom[2]) /
        rtb_Selector4_m;

      /* Switch: '<S194>/Switch1' incorporates:
       *  Constant: '<S194>/Constant3'
       */
      if (rtb_columncounter_i >= claw_main_P.Switch1_Threshold_h) {
        rtb_Switch1_o2 = claw_main_P.Constant3_Value_k;
      } else {
        rtb_Switch1_o2 = rtb_columncounter_i;
      }

      /* Product: '<S206>/Product2' */
      rtb_accels_cg_k[0] = rtb_Sum_aw[0] / claw_main_B.mass;
      rtb_accels_cg_k[1] = rtb_Sum_aw[1] / claw_main_B.mass;
      rtb_accels_cg_k[2] = rtb_Sum_aw[2] / claw_main_B.mass;

      /* Gain: '<S208>/Matrix Gain' incorporates:
       *  Math: '<S208>/Math Function'
       *  Product: '<S208>/Product1'
       */
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_dircos_h[3 * i] * rtb_uvw[0];
        rtb_dircos_0[i] += rtb_dircos_h[3 * i + 1] * rtb_uvw[1];
        rtb_dircos_0[i] += rtb_dircos_h[3 * i + 2] * rtb_uvw[2];
      }

      rtb_NEhdot_i[0] = claw_main_P.MatrixGain_Gain_h[0] * rtb_dircos_0[0];
      rtb_NEhdot_i[1] = claw_main_P.MatrixGain_Gain_h[1] * rtb_dircos_0[1];
      rtb_NEhdot_i[2] = claw_main_P.MatrixGain_Gain_h[2] * rtb_dircos_0[2];

      /* Sum: '<S208>/Sum' incorporates:
       *  Gain: '<S206>/g'
       *  Product: '<S206>/Product1'
       *  Product: '<S208>/Force -> Acceleration'
       *  Product: '<S212>/Product'
       *  Product: '<S212>/Product1'
       *  Selector: '<S206>/dircos(:,3)'
       *  Sum: '<S206>/Sum'
       *  Sum: '<S212>/Sum'
       */
      rtb_uvwdot_d[0] = (claw_main_P.g_Gain * rtb_dircos_h[6] * claw_main_B.mass
                         + rtb_Sum_aw[0]) * (1.0 / claw_main_B.mass) -
        (rtb_sensors[1] * rtb_uvw[2] - rtb_sensors[2] * rtb_uvw[1]);
      rtb_uvwdot_d[1] = (claw_main_P.g_Gain * rtb_dircos_h[7] * claw_main_B.mass
                         + rtb_Sum_aw[1]) * (1.0 / claw_main_B.mass) -
        (rtb_sensors[2] * rtb_uvw[0] - rtb_sensors[0] * rtb_uvw[2]);
      rtb_uvwdot_d[2] = (claw_main_P.g_Gain * rtb_dircos_h[8] * claw_main_B.mass
                         + rtb_Sum_aw[2]) * (1.0 / claw_main_B.mass) -
        (rtb_sensors[0] * rtb_uvw[1] - rtb_sensors[1] * rtb_uvw[0]);

      /* Reshape: '<S214>/Reshape' incorporates:
       *  Gain: '<S214>/Gain1'
       */
      rtb_MatrixConcatenation_ik[0] = claw_main_P.Gain1_Gain_d[0] *
        rtb_Switch_idx_0;
      rtb_MatrixConcatenation_ik[1] = claw_main_P.Gain1_Gain_d[1] *
        rtb_Switch_idx;
      rtb_MatrixConcatenation_ik[2] = claw_main_P.Gain1_Gain_d[2] *
        rtb_Switch_idx_2;
      rtb_MatrixConcatenation_ik[3] = claw_main_P.Gain1_Gain_d[3] *
        rtb_Switch_idx_1;

      /* Reshape: '<S214>/Reshape1' incorporates:
       *  Gain: '<S214>/Gain2'
       */
      rtb_MatrixConcatenation_ik[4] = claw_main_P.Gain2_Gain_a[0] *
        rtb_Switch_idx_1;
      rtb_MatrixConcatenation_ik[5] = claw_main_P.Gain2_Gain_a[1] *
        rtb_Switch_idx_2;
      rtb_MatrixConcatenation_ik[6] = claw_main_P.Gain2_Gain_a[2] *
        rtb_Switch_idx;
      rtb_MatrixConcatenation_ik[7] = claw_main_P.Gain2_Gain_a[3] *
        rtb_Switch_idx_0;

      /* Reshape: '<S214>/Reshape2' incorporates:
       *  Gain: '<S214>/Gain3'
       */
      rtb_MatrixConcatenation_ik[8] = claw_main_P.Gain3_Gain_j[0] *
        rtb_Switch_idx_2;
      rtb_MatrixConcatenation_ik[9] = claw_main_P.Gain3_Gain_j[1] *
        rtb_Switch_idx_1;
      rtb_MatrixConcatenation_ik[10] = claw_main_P.Gain3_Gain_j[2] *
        rtb_Switch_idx_0;
      rtb_MatrixConcatenation_ik[11] = claw_main_P.Gain3_Gain_j[3] *
        rtb_Switch_idx;

      /* Gain: '<S210>/Gain4' incorporates:
       *  Product: '<S210>/Product'
       */
      for (i = 0; i < 4; i++) {
        rtb_MatrixConcatenation_j_0[i] = 0.0;
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_ik[i] *
          rtb_sensors[0];
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_ik[i + 4] *
          rtb_sensors[1];
        rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_ik[i + 8] *
          rtb_sensors[2];
      }

      rtb_Gain4_j[0] = claw_main_P.Gain4_Gain_b * rtb_MatrixConcatenation_j_0[0];
      rtb_Gain4_j[1] = claw_main_P.Gain4_Gain_b * rtb_MatrixConcatenation_j_0[1];
      rtb_Gain4_j[2] = claw_main_P.Gain4_Gain_b * rtb_MatrixConcatenation_j_0[2];
      rtb_Gain4_j[3] = claw_main_P.Gain4_Gain_b * rtb_MatrixConcatenation_j_0[3];

      /* Selector: '<S223>/Value(ndx,:)' incorporates:
       *  Constant: '<S223>/Gain1'
       */
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
        rtb_Valuendx_p4[yOffset] = claw_main_P.Gain1_Value_o[7 * uDimIdx +
          (int32_T)rtb_FromWorkspace_f];
        yOffset++;
      }

      /* Switch: '<S221>/Switch' incorporates:
       *  Constant: '<S221>/xCG3'
       *  Constant: '<S221>/xCG5'
       */
      for (i = 0; i < 6; i++) {
        if (rtb_Gain_g_idx >= claw_main_P.Switch_Threshold_l) {
          rtb_Switch_o[i] = claw_main_P.xCG3_Value[i];
        } else {
          rtb_Switch_o[i] = claw_main_P.xCG5_Value[i];
        }
      }

      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value,
        &claw_main_B.sf_EmbeddedMATLABFunction_c,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_c);
      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value,
        &claw_main_B.sf_EmbeddedMATLABFunction_b,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_b);
      claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value,
        &claw_main_B.sf_EmbeddedMATLABFunction_d,
        (rtP_EmbeddedMATLABFunction_claw *)
        &claw_main_P.sf_EmbeddedMATLABFunction_d);

      /* Gain: '<S221>/Gain' */
      rtb_Gain_pr = claw_main_P.Gain_Gain_mg * rtb_gwest_o;

      /* Reshape: '<S221>/Reshape1' incorporates:
       *  Constant: '<S221>/ixxb3'
       *  Constant: '<S224>/xCG6'
       *  Sum: '<S221>/Add1'
       */
      rtb_Reshape1_nw[0] = ((rtb_Switch_o[0] +
        claw_main_B.sf_EmbeddedMATLABFunction_c.y) + rtb_Valuendx_p4[0]) +
        claw_main_P.ixxb3_Value[0];
      rtb_Reshape1_nw[1] = ((rtb_Switch_o[1] +
        claw_main_B.sf_EmbeddedMATLABFunction_b.y) + rtb_Valuendx_p4[1]) +
        claw_main_P.ixxb3_Value[1];
      rtb_Reshape1_nw[2] = ((rtb_Switch_o[2] +
        claw_main_B.sf_EmbeddedMATLABFunction_d.y) + rtb_Valuendx_p4[2]) +
        claw_main_P.ixxb3_Value[2];
      rtb_Reshape1_nw[3] = ((rtb_Switch_o[3] + claw_main_P.xCG6_Value[0]) +
                            rtb_Valuendx_p4[3]) + claw_main_P.ixxb3_Value[3];
      rtb_Reshape1_nw[4] = ((rtb_Switch_o[4] + claw_main_P.xCG6_Value[1]) +
                            rtb_Valuendx_p4[4]) + claw_main_P.ixxb3_Value[4];
      rtb_Reshape1_nw[5] = ((rtb_Switch_o[5] + claw_main_P.xCG6_Value[2]) +
                            rtb_Valuendx_p4[5]) + claw_main_P.ixxb3_Value[5];

      /* Constant: '<S215>/S' */
      rtb_S_a = claw_main_P.S_Value;

      /* Gain: '<S217>/Gain' */
      rtb_tratio_f = claw_main_P.Gain_Gain_km * rtb_u20_p;

      /* Constant: '<S218>/Constant1' */
      rtb_Constant1_f = claw_main_P.Constant1_Value_k;

      /* Switch: '<S284>/SwitchControl' incorporates:
       *  Constant: '<S218>/zero1'
       *  Constant: '<S284>/Constant'
       *  Sum: '<S218>/Add'
       */
      if (claw_main_P.Constant_Value_br4 > claw_main_P.SwitchControl_Threshold)
      {
        rtb_SwitchControl_i = rtb_LengON_i[5] + rtb_RengON_o[5];
      } else {
        rtb_SwitchControl_i = claw_main_P.zero1_Value;
      }

      /* Gain: '<S218>/sec_per_min' */
      rtb_sec_per_min_o = claw_main_P.sec_per_min_Gain * rtb_SwitchControl_i;

      /* Product: '<S220>/Product2' */
      rtb_Mach_h = max_1 / rtb_sos;

      /* Update for Memory: '<S194>/Memory1' */
      memcpy((void *)(&claw_main_DWork.Memory1_PreviousInput_g[0]), (void *)
             &rtb_Assignment_k[0], 27U * (uint32_T)((char_T *)&rtb_Assignment_k
              [1U] - (char_T *)&rtb_Assignment_k[0U]));

      /* Update for Memory: '<S194>/Memory2' */
      claw_main_DWork.Memory2_PreviousInput = rtb_Switch1_o2;
      scalarIndex_0++;
    } while ((claw_main_P.Constant4_Value_c != 0.0) && (scalarIndex_0 <= 9));

    /* end of Outputs for SubSystem: '<S6>/B matrix comp' */

    /* Selector: '<S196>/Bmat_smn' */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 8; uDimIdx++) {
      i = 3 * uDimIdx;
      rtb_Bmat_smn[yOffset] = rtb_Assignment_k[i];
      yOffset++;
      rtb_Bmat_smn[yOffset] = rtb_Assignment_k[i + 1];
      yOffset++;
      rtb_Bmat_smn[yOffset] = rtb_Assignment_k[i + 2];
      yOffset++;
    }

    /* Product: '<S295>/Product2' incorporates:
     *  Math: '<S178>/Math Function'
     *  RelationalOperator: '<S296>/Compare'
     *  Sum: '<S295>/Sum2'
     *  Sum: '<S295>/Sum6'
     *  UnitDelay: '<S295>/Unit Delay'
     */
    min[0] = rtb_Reshape_n[37];
    if (min[0] < 0.0) {
      rtb_InterpolationnDusingPreLo_5 = -sqrt(-min[0]);
    } else {
      rtb_InterpolationnDusingPreLo_5 = sqrt(min[0]);
    }

    /* Sum: '<S178>/Sum' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_is - claw_main_P.Gain_Gain_mq
      * rtb_Reshape_n[37];

    /* Math: '<S178>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain1'
     *  Sum: '<S178>/Sum1'
     */
    if (!(rtb_Reshape_n[37] >= claw_main_P.Switch_Threshold_kx)) {
      rtb_InterpolationnDusingPreLo_5 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_is) * claw_main_P.Gain1_Gain_n1;
    }

    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/Constant3'
     */
    if (rtb_Reshape_n[34] >= claw_main_P.Switch1_Threshold_i) {
      rtb_Gain1_idx = claw_main_P.Constant3_Value_nc;
    } else {
      rtb_Gain1_idx = rtb_InterpolationnDusingPreLo_5;
    }

    /* Product: '<S295>/Product5' */
    rtb_Product5_hf_idx = rtb_Gain1_idx * rtb_Reshape_n[31];
    min[1] = rtb_Reshape_n[38];
    if (min[1] < 0.0) {
      rtb_InterpolationnDusingPreLo_4 = -sqrt(-min[1]);
    } else {
      rtb_InterpolationnDusingPreLo_4 = sqrt(min[1]);
    }

    /* Sum: '<S178>/Sum' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_is - claw_main_P.Gain_Gain_mq
      * rtb_Reshape_n[38];

    /* Math: '<S178>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain1'
     *  Sum: '<S178>/Sum1'
     */
    if (!(rtb_Reshape_n[38] >= claw_main_P.Switch_Threshold_kx)) {
      rtb_InterpolationnDusingPreLo_4 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_is) * claw_main_P.Gain1_Gain_n1;
    }

    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/Constant3'
     */
    if (rtb_Reshape_n[35] >= claw_main_P.Switch1_Threshold_i) {
      rtb_Gain1_idx_1 = claw_main_P.Constant3_Value_nc;
    } else {
      rtb_Gain1_idx_1 = rtb_InterpolationnDusingPreLo_4;
    }

    /* Product: '<S295>/Product5' */
    rtb_Product5_hf_idx_0 = rtb_Gain1_idx_1 * rtb_Reshape_n[32];
    min[2] = rtb_Reshape_n[39];
    if (min[2] < 0.0) {
      rtb_InterpolationnDusingPreLo_3 = -sqrt(-min[2]);
    } else {
      rtb_InterpolationnDusingPreLo_3 = sqrt(min[2]);
    }

    /* Sum: '<S178>/Sum' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain'
     */
    rtb_delta_LLh_idx = claw_main_P.Constant_Value_is - claw_main_P.Gain_Gain_mq
      * rtb_Reshape_n[39];

    /* Math: '<S178>/Math Function1' */
    if (rtb_delta_LLh_idx < 0.0) {
      rtb_delta_LLh_idx = -sqrt(-rtb_delta_LLh_idx);
    } else {
      rtb_delta_LLh_idx = sqrt(rtb_delta_LLh_idx);
    }

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Gain: '<S178>/Gain1'
     *  Sum: '<S178>/Sum1'
     */
    if (!(rtb_Reshape_n[39] >= claw_main_P.Switch_Threshold_kx)) {
      rtb_InterpolationnDusingPreLo_3 = (rtb_delta_LLh_idx +
        claw_main_P.Constant_Value_is) * claw_main_P.Gain1_Gain_n1;
    }

    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/Constant3'
     */
    if (rtb_Reshape_n[36] >= claw_main_P.Switch1_Threshold_i) {
      rtb_Gain1_idx_0 = claw_main_P.Constant3_Value_nc;
    } else {
      rtb_Gain1_idx_0 = rtb_InterpolationnDusingPreLo_3;
    }

    /* Product: '<S295>/Product5' */
    rtb_Product5_hf_idx_1 = rtb_Gain1_idx_0 * rtb_Reshape_n[33];

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Constant: '<S162>/Constant6'
     *  Constant: '<S178>/Constant2'
     *  Constant: '<S178>/Constant4'
     *  Product: '<S178>/Divide2'
     *  Product: '<S178>/Divide3'
     *  Sum: '<S178>/Sum2'
     *  Sum: '<S178>/Sum3'
     */
    if (rtb_Reshape_n[34] >= claw_main_P.Switch2_Threshold_b) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_k4;
    } else {
      rtb_delta_LLh_idx = (claw_main_P.Constant2_Value_cn - rtb_Gain1_idx) *
        claw_main_P.Constant6_Value_d[0] + 1.0 / rtb_Reshape_n[31] *
        claw_main_P.Constant1_Value_ov[0];
    }

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Constant: '<S162>/Constant6'
     *  Constant: '<S178>/Constant2'
     *  Constant: '<S178>/Constant4'
     *  Product: '<S178>/Divide2'
     *  Product: '<S178>/Divide3'
     *  Sum: '<S178>/Sum2'
     *  Sum: '<S178>/Sum3'
     */
    if (rtb_Reshape_n[35] >= claw_main_P.Switch2_Threshold_b) {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_k4;
    } else {
      rtb_delta_LLh_idx_0 = (claw_main_P.Constant2_Value_cn - rtb_Gain1_idx_1) *
        claw_main_P.Constant6_Value_d[1] + 1.0 / rtb_Reshape_n[32] *
        claw_main_P.Constant1_Value_ov[1];
    }

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S162>/Constant1'
     *  Constant: '<S162>/Constant6'
     *  Constant: '<S178>/Constant2'
     *  Constant: '<S178>/Constant4'
     *  Product: '<S178>/Divide2'
     *  Product: '<S178>/Divide3'
     *  Sum: '<S178>/Sum2'
     *  Sum: '<S178>/Sum3'
     */
    if (rtb_Reshape_n[36] >= claw_main_P.Switch2_Threshold_b) {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_k4;
    } else {
      rtb_Switch2_idx = (claw_main_P.Constant2_Value_cn - rtb_Gain1_idx_0) *
        claw_main_P.Constant6_Value_d[2] + 1.0 / rtb_Reshape_n[33] *
        claw_main_P.Constant1_Value_ov[2];
    }

    /* DiscreteIntegrator: '<S195>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S295>/Gain'
     *  Product: '<S195>/Product4'
     *  Product: '<S295>/Product1'
     *  Product: '<S295>/Product3'
     *  RelationalOperator: '<S297>/Compare'
     *  Sum: '<S195>/Sum1'
     *  Sum: '<S195>/Sum3'
     *  Sum: '<S295>/Sum'
     *  Sum: '<S295>/Sum1'
     *  UnitDelay: '<S195>/Unit Delay2'
     */
    if (claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_o) {
      claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_o = 0U;
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_j[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_j[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_j[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2];
    } else if ((rtb_control_input[101] > 0.0) &&
               (claw_main_DWork.DiscreteTimeIntegrator_PrevRe_b <= 0)) {
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] = rtb_delta_LLh_idx;
      claw_main_B.DiscreteTimeIntegrator_j[0] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0];
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] = rtb_delta_LLh_idx_0;
      claw_main_B.DiscreteTimeIntegrator_j[1] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1];
      claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] = rtb_Switch2_idx;
      claw_main_B.DiscreteTimeIntegrator_j[2] =
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2];
    } else {
      claw_main_B.DiscreteTimeIntegrator_j[0] =
        (((((claw_main_DWork.UnitDelay_DSTATE_pq[0] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_pq[0] - rtb_Product5_hf_idx) *
             rtb_MultiportSwitch_k_idx : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_pq[3] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] - rtb_sensors[0])
             * (claw_main_DWork.UnitDelay_DSTATE_pq[3] - rtb_Reshape_n[31]) :
             0.0)) / rtb_Reshape_n[31] * claw_main_P.Gain_Gain_k0 -
           (rtb_Reshape_n[37] == 0.0 ? rtb_Reshape_n[31] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] : 0.0)) +
          rtb_Reshape_n[37] * rtb_Reshape_n[31] * (rtb_MultiportSwitch_k_idx -
           rtb_sensors[0])) + claw_main_DWork.UnitDelay2_DSTATE_eb[0]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_a +
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0];
      claw_main_B.DiscreteTimeIntegrator_j[1] =
        (((((claw_main_DWork.UnitDelay_DSTATE_pq[1] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_pq[1] - rtb_Product5_hf_idx_0) *
             rtb_MultiportSwitch_k_idx_0 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_pq[4] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] - rtb_sensors[1])
             * (claw_main_DWork.UnitDelay_DSTATE_pq[4] - rtb_Reshape_n[32]) :
             0.0)) / rtb_Reshape_n[32] * claw_main_P.Gain_Gain_k0 -
           (rtb_Reshape_n[38] == 0.0 ? rtb_Reshape_n[32] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] : 0.0)) +
          rtb_Reshape_n[38] * rtb_Reshape_n[32] * (rtb_MultiportSwitch_k_idx_0 -
           rtb_sensors[1])) + claw_main_DWork.UnitDelay2_DSTATE_eb[1]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_a +
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1];
      claw_main_B.DiscreteTimeIntegrator_j[2] =
        (((((claw_main_DWork.UnitDelay_DSTATE_pq[2] > 0.0 ?
             (claw_main_DWork.UnitDelay_DSTATE_pq[2] - rtb_Product5_hf_idx_1) *
             rtb_MultiportSwitch_k_idx_1 : 0.0) +
            (claw_main_DWork.UnitDelay_DSTATE_pq[5] > 0.0 ?
             (claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] - rtb_sensors[2])
             * (claw_main_DWork.UnitDelay_DSTATE_pq[5] - rtb_Reshape_n[33]) :
             0.0)) / rtb_Reshape_n[33] * claw_main_P.Gain_Gain_k0 -
           (rtb_Reshape_n[39] == 0.0 ? rtb_Reshape_n[33] *
            claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] : 0.0)) +
          rtb_Reshape_n[39] * rtb_Reshape_n[33] * (rtb_MultiportSwitch_k_idx_1 -
           rtb_sensors[2])) + claw_main_DWork.UnitDelay2_DSTATE_eb[2]) *
        claw_main_P.DiscreteTimeIntegrator_gainva_a +
        claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2];
    }

    if (rtb_control_input[101] > 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_b = 1;
    } else if (rtb_control_input[101] < 0.0) {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_b = -1;
    } else {
      claw_main_DWork.DiscreteTimeIntegrator_PrevRe_b = 0;
    }

    /* Sum: '<S195>/Sum4' incorporates:
     *  Constant: '<S94>/Constant1'
     *  Product: '<S195>/Product2'
     *  Product: '<S195>/Product5'
     *  Product: '<S195>/Product6'
     *  Sum: '<S195>/Sum2'
     *  Sum: '<S195>/Sum5'
     */
    rtb_Sum4_k_idx = ((rtb_MultiportSwitch_k_idx * rtb_Gain1_idx - rtb_sensors[0])
                      + claw_main_B.DiscreteTimeIntegrator_j[0]) *
      rtb_Reshape_n[31] + rtb_Reshape_n[34] * claw_main_P.Constant1_Value_fg[0];
    rtb_Sum4_k_idx_0 = ((rtb_MultiportSwitch_k_idx_0 * rtb_Gain1_idx_1 -
                         rtb_sensors[1]) + claw_main_B.DiscreteTimeIntegrator_j
                        [1]) * rtb_Reshape_n[32] + rtb_Reshape_n[35] *
      claw_main_P.Constant1_Value_fg[1];
    rtb_Sum4_k_idx_1 = ((rtb_MultiportSwitch_k_idx_1 * rtb_Gain1_idx_0 -
                         rtb_sensors[2]) + claw_main_B.DiscreteTimeIntegrator_j
                        [2]) * rtb_Reshape_n[33] + rtb_Reshape_n[36] *
      claw_main_P.Constant1_Value_fg[2];

    /* Embedded MATLAB: '<S197>/Bang Bang' incorporates:
     *  Constant: '<S197>/Constant1'
     *  Constant: '<S197>/Constant2'
     *  UnitDelay: '<S197>/Unit Delay'
     *  UnitDelay: '<S197>/Unit Delay1'
     *  UnitDelay: '<S197>/Unit Delay2'
     */
    /* Embedded MATLAB Function 'claw_main/rate_loops/bangbang/Bang Bang': '<S309>:1' */
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    /* '<S309>:1:5' */
    /* '<S309>:1:6' */
    /* '<S309>:1:7' */
    /* '<S309>:1:8' */
    /* '<S309>:1:9' */
    /* '<S309>:1:10' */
    for (i = 0; i < 6; i++) {
      min_6[i] = claw_main_P.Constant1_Value_hm[i + 5];
    }

    /* '<S309>:1:12' */
    for (i = 0; i < 12; i++) {
      rtb_debug_output[i] = 0.0;
    }

    /* '<S309>:1:13' */
    /* '<S309>:1:14' */
    rtb_use_bb = 0;

    /* '<S309>:1:15' */
    rtb_cvddes_idx_0 = rtb_Sum4_k_idx;
    rtb_dir_idx = 0.0;
    rtb_cvddes_idx_1 = rtb_Sum4_k_idx_0;
    rtb_dir_idx_0 = 0.0;
    rtb_cvddes_idx = rtb_Sum4_k_idx_1;
    eml_a_idx = 0.0;

    /* '<S309>:1:16' */
    rtb_timer = claw_main_DWork.UnitDelay1_DSTATE_e;
    if (rtb_enable_bb != 0) {
      /* '<S309>:1:22' */
      rtb_Switch2_idx = -rtb_Switch_idx_0;
      rtb_Gain1_idx_0 = -rtb_Switch_idx_1;
      rtb_Gain1_idx_1 = -rtb_Switch_idx_2;

      /* '<S309>:1:131' */
      /* '<S309>:1:132' */
      /* '<S309>:1:133' */
      /* '<S309>:1:134' */
      /* '<S309>:1:136' */
      /* '<S309>:1:137' */
      /* '<S309>:1:138' */
      /* '<S309>:1:139' */
      /* '<S309>:1:141' */
      /* '<S309>:1:142' */
      /* '<S309>:1:143' */
      /* '<S309>:1:144' */
      /* '<S309>:1:146' */
      rtb_delta_LLh_idx = rtb_Switch2_idx;
      rtb_delta_LLh_idx_0 = rtb_Gain1_idx_0;
      rtb_Gain1_idx = ((rtb_Switch_idx * rtb_Product_j3_idx - rtb_Switch2_idx *
                        rtb_Product_j3_idx_0) - rtb_Gain1_idx_0 *
                       rtb_Product_j3_idx_1) - rtb_Gain1_idx_1 *
        rtb_Product_j3_idx_2;
      rtb_Switch2_idx = ((rtb_Switch_idx * rtb_Product_j3_idx_0 +
                          rtb_Switch2_idx * rtb_Product_j3_idx) +
                         rtb_Gain1_idx_0 * rtb_Product_j3_idx_2) -
        rtb_Gain1_idx_1 * rtb_Product_j3_idx_1;
      rtb_Gain1_idx_0 = ((rtb_Switch_idx * rtb_Product_j3_idx_1 -
                          rtb_delta_LLh_idx * rtb_Product_j3_idx_2) +
                         rtb_Gain1_idx_0 * rtb_Product_j3_idx) + rtb_Gain1_idx_1
        * rtb_Product_j3_idx_0;
      rtb_Gain1_idx_1 = ((rtb_Switch_idx * rtb_Product_j3_idx_2 +
                          rtb_delta_LLh_idx * rtb_Product_j3_idx_1) -
                         rtb_delta_LLh_idx_0 * rtb_Product_j3_idx_0) +
        rtb_Gain1_idx_1 * rtb_Product_j3_idx;

      /*  default is to use dir_old if we were in bangbang last cycle, */
      /*  and the timer has not expired */
      /* '<S309>:1:26' */
      max_1 = claw_main_DWork.UnitDelay2_DSTATE_an;
      if (claw_main_DWork.UnitDelay2_DSTATE_an != 0.0) {
        /* '<S309>:1:27' */
        /* '<S309>:1:28' */
        rtb_timer = claw_main_DWork.UnitDelay1_DSTATE_e +
          claw_main_P.Constant1_Value_hm[0];
        if (rtb_timer > claw_main_P.Constant1_Value_hm[1]) {
          /* '<S309>:1:29' */
          /*  if timer expires, don't use dir_old */
          /* '<S309>:1:31' */
          max_1 = 0.0;
        }
      }

      /*  compute att using current transformation quat */
      /* '<S309>:1:36' */
      /* '<S309>:1:37' */
      /* '<S309>:1:38' */
      /* '<S309>:1:214' */
      min[0] = rtb_Switch2_idx;
      min[1] = rtb_Gain1_idx_0;
      min[2] = rtb_Gain1_idx_1;
      rtb_MultiportSwitch2_idx_2 = rt_atan2_snf(sqrt((rt_pow_snf(min[0], 2.0) +
        rt_pow_snf(min[1], 2.0)) + rt_pow_snf(min[2], 2.0)), rtb_Gain1_idx) *
        -2.0;

      /* '<S309>:1:39' */
      rtb_Gain1_idx_1 = rt_atan2_snf((claw_main_DWork.UnitDelay_DSTATE_bb[0] *
        min[0] + claw_main_DWork.UnitDelay_DSTATE_bb[1] * min[1]) +
        claw_main_DWork.UnitDelay_DSTATE_bb[2] * min[2], rtb_Gain1_idx) * -2.0;

      /*  choose arbitrary att (and dir) sign to be the same as that computed using */
      /*  dir_old.  This is equivalent to making dir_old'*trans_dir positive. */
      if (rtb_MultiportSwitch2_idx_2 * rtb_Gain1_idx_1 < 0.0) {
        /* '<S309>:1:43' */
        /* '<S309>:1:44' */
        rtb_MultiportSwitch2_idx_2 = -rtb_MultiportSwitch2_idx_2;

        /* '<S309>:1:45' */
        min[0] = -min[0];
        min[1] = -min[1];
        min[2] = -min[2];
      }

      /*  if we intended to use dir_old, but the angle computed using */
      /*  dir_old is significantly different than that derived using the current */
      /*  transformation, we will use current dir. */
      /*  NOTE: the angle test below works only because att has been adjusted */
      /*  to have the same sign as att_old, and both result from atan2  */
      if (max_1 != 0.0) {
        /* '<S309>:1:53' */
        if (fabs(rtb_MultiportSwitch2_idx_2 - rtb_Gain1_idx_1) >
            claw_main_P.Constant1_Value_hm[4]) {
          /* '<S309>:1:54' */
          /* '<S309>:1:55' */
          max_1 = 0.0;
        } else {
          /* '<S309>:1:57' */
          rtb_dir_idx = claw_main_DWork.UnitDelay_DSTATE_bb[0];
          rtb_dir_idx_0 = claw_main_DWork.UnitDelay_DSTATE_bb[1];
          eml_a_idx = claw_main_DWork.UnitDelay_DSTATE_bb[2];

          /* '<S309>:1:58' */
          rtb_MultiportSwitch2_idx_2 = rtb_Gain1_idx_1;
        }
      }

      /*  check condition to enter (or stay in) bangbang */
      if (fabs(rtb_MultiportSwitch2_idx_2) > claw_main_P.Constant1_Value_hm[2])
      {
        /* '<S309>:1:63' */
        /* '<S309>:1:64' */
        rtb_use_bb = 1;
        if (!(max_1 != 0.0)) {
          /* '<S309>:1:66' */
          /* '<S309>:1:67' */
          /* '<S309>:1:214' */
          min_5 = sqrt((rt_pow_snf(min[0], 2.0) + rt_pow_snf(min[1], 2.0)) +
                       rt_pow_snf(min[2], 2.0));
          rtb_dir_idx = min[0] / min_5;
          rtb_dir_idx_0 = min[1] / min_5;
          eml_a_idx = min[2] / min_5;

          /* '<S309>:1:68' */
          rtb_timer = 0.0;
        }
      } else {
        min_0[0] = fabs(rtb_sensors[0]);
        min_0[1] = fabs(rtb_sensors[1]);
        min_0[2] = fabs(rtb_sensors[2]);
        min_5 = min_0[0];
        if ((!rtIsNaN(min_0[1])) && (rtIsNaN(min_0[0]) || (min_0[1] > min_0[0])))
        {
          min_5 = min_0[1];
        }

        if ((!rtIsNaN(min_0[2])) && (rtIsNaN(min_5) || (min_0[2] > min_5))) {
          min_5 = min_0[2];
        }

        if (min_5 > claw_main_P.Constant1_Value_hm[3]) {
          /* '<S309>:1:71' */
          /* '<S309>:1:72' */
          rtb_use_bb = 1;

          /*  if small attitude error, set dir based on rates */
          if (!(max_1 != 0.0)) {
            /* '<S309>:1:75' */
            /* '<S309>:1:76' */
            /* '<S309>:1:214' */
            min_5 = sqrt((rt_pow_snf(rtb_sensors[0], 2.0) + rt_pow_snf
                          (rtb_sensors[1], 2.0)) + rt_pow_snf(rtb_sensors[2],
              2.0));

            /* '<S309>:1:77' */
            eml_a_idx = rtb_sensors[0] / min_5;
            rtb_delta_LLh_idx = eml_a_idx;
            rtb_dir_idx = eml_a_idx;
            eml_a_idx = rtb_sensors[1] / min_5;
            rtb_delta_LLh_idx_0 = eml_a_idx;
            rtb_dir_idx_0 = eml_a_idx;
            eml_a_idx = rtb_sensors[2] / min_5;
            rtb_MultiportSwitch2_idx_2 = rt_atan2_snf((rtb_delta_LLh_idx * min[0]
              + rtb_delta_LLh_idx_0 * min[1]) + eml_a_idx * min[2],
              rtb_Gain1_idx) * -2.0;

            /* '<S309>:1:78' */
            rtb_timer = 0.0;
          }
        } else {
          /*  even though not used, pass dir_old through for in case of ~use_bb */
          /* '<S309>:1:82' */
          rtb_dir_idx = claw_main_DWork.UnitDelay_DSTATE_bb[0];
          rtb_dir_idx_0 = claw_main_DWork.UnitDelay_DSTATE_bb[1];
          eml_a_idx = claw_main_DWork.UnitDelay_DSTATE_bb[2];

          /* '<S309>:1:83' */
          rtb_MultiportSwitch2_idx_2 = rtb_Gain1_idx_1;
        }
      }

      /*  Note: cvddes has been set to a default value of cvddes_lin */
      if (rtb_use_bb != 0) {
        /* '<S309>:1:88' */
        /* '<S309>:1:89' */
        rtb_Gain1_idx_0 = (rtb_sensors[0] * rtb_dir_idx + rtb_sensors[1] *
                           rtb_dir_idx_0) + rtb_sensors[2] * eml_a_idx;

        /* '<S309>:1:90' */
        for (i = 0; i < 3; i++) {
          rtb_dircos_0[i] = 0.0;
          rtb_dircos_0[i] += rtb_inertia[i] * rtb_dir_idx;
          rtb_dircos_0[i] += rtb_inertia[i + 3] * rtb_dir_idx_0;
          rtb_dircos_0[i] += rtb_inertia[i + 6] * eml_a_idx;
        }

        tmp_7[0] = rtb_dircos_0[0];
        tmp_7[1] = rtb_dircos_0[1];
        tmp_7[2] = rtb_dircos_0[2];
        min_5 = claw_main_get_ellipsoid_scaling(tmp_7,
          &claw_main_P.Constant2_Value_l[0]);

        /* '<S309>:1:91' */
        /* '<S309>:1:92' */
        min_6[0] = min_5;

        /* '<S309>:1:93' */
        min_6[1] = -min_5;

        /* '<S309>:1:94' */
        /*  the linear control law is */
        /*  accel = ww^2 * ( att_cmd - att ) - 2 * zeta * ww * rate */
        /* '<S309>:1:156' */
        /* '<S309>:1:157' */
        /* '<S309>:1:158' */
        /* '<S309>:1:159' */
        /* '<S309>:1:160' */
        /* '<S309>:1:161' */
        /*  make switch curves conservative */
        /* '<S309>:1:166' */
        /* '<S309>:1:167' */
        /*  replace ellipse with parallelogram */
        /*  outside = ( ww^2 * att^2 + 2 * zeta * ww * att * rate + rate^2 ) / ( ( 1 - zeta^2 ) * amax^2 / ww^2 ) ; */
        /* '<S309>:1:171' */
        /* '<S309>:1:172' */
        /* '<S309>:1:173' */
        /* '<S309>:1:174' */
        /* '<S309>:1:175' */
        eml_p[0] = (1.0 + min_6[3]) + 4.0 * rt_pow_snf(min_6[3], 2.0);
        eml_p[1] = -0.5 - 2.0 * min_6[3];

        /* '<S309>:1:176' */
        rtb_delta_LLh_idx = 1.0 - 4.0 * rt_pow_snf(min_6[3], 2.0);
        rtb_delta_LLh_idx_0 = 2.0 * min_6[3];

        /* '<S309>:1:178' */
        eml_A[0] = rtb_delta_LLh_idx + eml_p[0];
        eml_A[1] = rtb_delta_LLh_idx_0 + eml_p[1];
        eml_A[2] = rtb_delta_LLh_idx - eml_p[0];
        eml_A[3] = rtb_delta_LLh_idx_0 - eml_p[1];
        eml_p[0] = rtb_MultiportSwitch2_idx_2 * min_6[2];
        eml_p[1] = rtb_Gain1_idx_0;
        if (fabs(eml_A[1]) > fabs(eml_A[0])) {
          yOffset = 2;
          uDimIdx = 1;
        } else {
          yOffset = 1;
          uDimIdx = 2;
        }

        min_5 = eml_A[uDimIdx - 1] / eml_A[yOffset - 1];
        rtb_delta_LLh_idx_0 = (eml_p[uDimIdx - 1] - eml_p[yOffset - 1] * min_5) /
          (eml_A[uDimIdx + 1] - eml_A[yOffset + 1] * min_5);
        rtb_delta_LLh_idx = (eml_p[yOffset - 1] - eml_A[yOffset + 1] *
                             rtb_delta_LLh_idx_0) / eml_A[yOffset - 1];
        eml_p[0] = fabs(rtb_delta_LLh_idx);
        eml_p[1] = fabs(rtb_delta_LLh_idx_0);
        min_5 = eml_p[0];
        if ((!rtIsNaN(eml_p[1])) && (rtIsNaN(eml_p[0]) || (eml_p[1] > eml_p[0])))
        {
          min_5 = eml_p[1];
        }

        max_1 = 2.0 * min_6[2] / min_6[0] * min_5;

        /* '<S309>:1:179' */
        rtb_delta_LLh_idx = 0.0;
        if (!(max_1 <= 1.0)) {
          if (rtb_Gain1_idx_0 > 0.0) {
            /* '<S309>:1:185' */
            if (0.5 * rt_pow_snf(rtb_Gain1_idx_0, 2.0) - min_6[1] *
                rtb_MultiportSwitch2_idx_2 < 0.0) {
              /* '<S309>:1:186' */
              if (rtb_Gain1_idx_0 < min_6[4]) {
                /* '<S309>:1:187' */
                /* '<S309>:1:188' */
                rtb_delta_LLh_idx = min_6[0];
              } else if (rtb_Gain1_idx_0 < min_6[5]) {
                /* '<S309>:1:189' */
                /* '<S309>:1:190' */
                rtb_delta_LLh_idx = 0.0;
              } else {
                /* '<S309>:1:192' */
                rtb_delta_LLh_idx = min_6[1];
              }
            } else {
              /* '<S309>:1:195' */
              rtb_delta_LLh_idx = min_6[1];
            }
          } else if (0.5 * rt_pow_snf(rtb_Gain1_idx_0, 2.0) - min_6[0] *
                     rtb_MultiportSwitch2_idx_2 < 0.0) {
            /* '<S309>:1:198' */
            if (rtb_Gain1_idx_0 > -min_6[4]) {
              /* '<S309>:1:199' */
              /* '<S309>:1:200' */
              rtb_delta_LLh_idx = min_6[1];
            } else if (rtb_Gain1_idx_0 > -min_6[5]) {
              /* '<S309>:1:201' */
              /* '<S309>:1:202' */
              rtb_delta_LLh_idx = 0.0;
            } else {
              /* '<S309>:1:204' */
              rtb_delta_LLh_idx = min_6[0];
            }
          } else {
            /* '<S309>:1:207' */
            rtb_delta_LLh_idx = min_6[0];
          }
        } else {
          /* '<S309>:1:181' */
        }

        if (max_1 <= 1.0) {
          /* '<S309>:1:96' */
          /*  use default cvddes (cvddes_lin) */
          /* '<S309>:1:98' */
          rtb_use_bb = 0;
        } else {
          /*  eliminate component of linear command in direction dir */
          /* '<S309>:1:101' */
          min_5 = (rtb_dir_idx * rtb_Sum4_k_idx + rtb_dir_idx_0 *
                   rtb_Sum4_k_idx_0) + eml_a_idx * rtb_Sum4_k_idx_1;
          rtb_cvddes_idx_0 = rtb_Sum4_k_idx - min_5 * rtb_dir_idx;
          rtb_cvddes_idx_1 = rtb_Sum4_k_idx_0 - min_5 * rtb_dir_idx_0;
          rtb_cvddes_idx = rtb_Sum4_k_idx_1 - min_5 * eml_a_idx;
        }
      } else {
        /*  use default cvddes (cvddes_lin) */
        /* '<S309>:1:105' */
        rtb_Gain1_idx_0 = 0.0;

        /* '<S309>:1:106' */
        max_1 = 0.0;

        /* '<S309>:1:107' */
        rtb_delta_LLh_idx = 0.0;
      }

      /*  saturate command at ellipsoid */
      /* '<S309>:1:111' */
      for (i = 0; i < 3; i++) {
        rtb_dircos_0[i] = 0.0;
        rtb_dircos_0[i] += rtb_inertia[i] * rtb_cvddes_idx_0;
        rtb_dircos_0[i] += rtb_inertia[i + 3] * rtb_cvddes_idx_1;
        rtb_dircos_0[i] += rtb_inertia[i + 6] * rtb_cvddes_idx;
      }

      tmp_6[0] = rtb_dircos_0[0];
      tmp_6[1] = rtb_dircos_0[1];
      tmp_6[2] = rtb_dircos_0[2];
      min_5 = claw_main_get_ellipsoid_scaling(tmp_6,
        &claw_main_P.Constant2_Value_l[0]);
      if (!(min_5 <= 1.0)) {
        min_5 = 1.0;
      }

      /*  add component from bangbang */
      /* '<S309>:1:114' */
      /* '<S309>:1:115' */
      rtb_delta_LLh_idx_0 = rtb_cvddes_idx_0 * min_5;
      rtb_Switch2_idx = rtb_delta_LLh_idx * rtb_dir_idx;
      rtb_cvddes_idx_0 = rtb_delta_LLh_idx_0 + rtb_Switch2_idx;
      min[0] = rtb_delta_LLh_idx_0;
      min_0[0] = rtb_Switch2_idx;
      rtb_delta_LLh_idx_0 = rtb_cvddes_idx_1 * min_5;
      rtb_Switch2_idx = rtb_delta_LLh_idx * rtb_dir_idx_0;
      rtb_cvddes_idx_1 = rtb_delta_LLh_idx_0 + rtb_Switch2_idx;
      min[1] = rtb_delta_LLh_idx_0;
      min_0[1] = rtb_Switch2_idx;
      rtb_delta_LLh_idx_0 = rtb_cvddes_idx * min_5;
      rtb_Switch2_idx = rtb_delta_LLh_idx * eml_a_idx;
      rtb_cvddes_idx = rtb_delta_LLh_idx_0 + rtb_Switch2_idx;
      min[2] = rtb_delta_LLh_idx_0;
      min_0[2] = rtb_Switch2_idx;

      /* '<S309>:1:117' */
      /* '<S309>:1:118' */
      for (i = 0; i < 3; i++) {
        rtb_Gain_e_0[i] = 0.0;
        rtb_Gain_e_0[i] += rtb_inertia[i] * rtb_cvddes_idx_0;
        rtb_Gain_e_0[i] += rtb_inertia[i + 3] * rtb_cvddes_idx_1;
        rtb_Gain_e_0[i] += rtb_inertia[i + 6] * rtb_cvddes_idx;
      }

      tmp_5[0] = rtb_Gain_e_0[0];
      tmp_5[1] = rtb_Gain_e_0[1];
      tmp_5[2] = rtb_Gain_e_0[2];
      rtb_debug_output[0] = rtb_MultiportSwitch2_idx_2;
      rtb_debug_output[1] = rtb_Gain1_idx_1;
      rtb_debug_output[2] = rtb_Gain1_idx_0;
      rtb_debug_output[3] = max_1;
      rtb_debug_output[4] = rtb_delta_LLh_idx;
      rtb_debug_output[5] = 1.0 / claw_main_get_ellipsoid_scaling(tmp_5,
        &claw_main_P.Constant2_Value_l[0]);
      rtb_debug_output[6] = min_0[0];
      rtb_debug_output[7] = min_0[1];
      rtb_debug_output[8] = min_0[2];
      rtb_debug_output[9] = min[0];
      rtb_debug_output[10] = min[1];
      rtb_debug_output[11] = min[2];
      if (!(rtb_use_bb != 0)) {
        /* '<S309>:1:120' */
        /*  if not using bangbang reset the timer, and set dir to zero */
        /* '<S309>:1:123' */
        rtb_timer = 0.0;

        /*  dir used for cvd_des blending is now zeroed outside of this block, */
        /*  so that dir can be retained through a temporary ~use_bb condition */
        /*      dir = 0*dir ; */
      }
    } else {
      /* '<S309>:1:18' */
    }

    /* Sum: '<S303>/Sum' */
    rtb_delta_LLh_idx = rtb_cvddes_idx_0 - rtb_xdot_nom[0];
    rtb_delta_LLh_idx_0 = rtb_cvddes_idx_1 - rtb_xdot_nom[1];
    rtb_Switch2_idx = rtb_cvddes_idx - rtb_xdot_nom[2];

    /* Sum: '<S306>/Sum2' incorporates:
     *  Gain: '<S306>/Gain1'
     */
    for (i = 0; i < 6; i++) {
      rtb_Sum2_d3[i] = rtb_control_input[i + 44] * claw_main_P.Gain1_Gain_i +
        rtb_UnitDelay2_o[i];
    }

    rtb_Sum2_d3[6] = claw_main_P.Gain1_Gain_i * rtb_control_input[51] +
      rtb_UnitDelay2_o[6];
    rtb_Sum2_d3[7] = claw_main_P.Gain1_Gain_i * rtb_control_input[52] +
      rtb_UnitDelay2_o[7];

    /* MinMax: '<S306>/MinMax1' */
    for (i = 0; i < 8; i++) {
      max_8[i] = rt_MAXd_snf(rtb_Sum2_d3[i], max_6[i]);
    }

    /* Sum: '<S306>/Sum1' incorporates:
     *  Gain: '<S306>/Gain'
     */
    for (i = 0; i < 6; i++) {
      rtb_Sum1_eb[i] = rtb_control_input[i + 34] * claw_main_P.Gain_Gain_lf +
        rtb_UnitDelay2_o[i];
    }

    rtb_Sum1_eb[6] = claw_main_P.Gain_Gain_lf * rtb_control_input[41] +
      rtb_UnitDelay2_o[6];
    rtb_Sum1_eb[7] = claw_main_P.Gain_Gain_lf * rtb_control_input[42] +
      rtb_UnitDelay2_o[7];

    /* MinMax: '<S306>/MinMax3' */
    for (i = 0; i < 8; i++) {
      min_7[i] = rt_MINd_snf(rtb_Sum1_eb[i], max_7[i]);
    }

    /* SignalConversion: '<S307>/TmpHiddenBufferAtS-FunctionInport1' incorporates:
     *  Constant: '<S163>/Constant5'
     *  Constant: '<S307>/ncolumns'
     *  Constant: '<S307>/nrows'
     *  Memory: '<S303>/Memory'
     *  MinMax: '<S306>/MinMax'
     *  MinMax: '<S306>/MinMax2'
     *  Reshape: '<S307>/Reshape'
     *  Sum: '<S303>/Sum1'
     *  Sum: '<S303>/Sum2'
     *  Sum: '<S303>/Sum3'
     */
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[0] = claw_main_P.nrows_Value_o;
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[1] =
      claw_main_P.ncolumns_Value_b;
    memcpy((void *)(&claw_main_B.TmpHiddenBufferAtSFunctionInp_k[2]), (void *)
           &rtb_Bmat_smn[0], 24U * (uint32_T)((char_T *)&rtb_Bmat_smn[1U] -
            (char_T *)&rtb_Bmat_smn[0U]));
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[26] = rtb_delta_LLh_idx;
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[27] = rtb_delta_LLh_idx_0;
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[28] = rtb_Switch2_idx;
    for (i = 0; i < 6; i++) {
      claw_main_B.TmpHiddenBufferAtSFunctionInp_k[i + 29] = rt_MINd_snf(max_8[i],
        max_7[i]) - rtb_zeroRCSinputs[i];
    }

    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[35] = rt_MINd_snf(max_8[6],
      max_7[6]) - rtb_zeroRCSinputs[7];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[36] = rt_MINd_snf(max_8[7],
      max_7[7]) - rtb_zeroRCSinputs[8];
    for (i = 0; i < 6; i++) {
      claw_main_B.TmpHiddenBufferAtSFunctionInp_k[i + 37] = rt_MAXd_snf(min_7[i],
        max_6[i]) - rtb_zeroRCSinputs[i];
    }

    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[43] = rt_MAXd_snf(min_7[6],
      max_6[6]) - rtb_zeroRCSinputs[7];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[44] = rt_MAXd_snf(min_7[7],
      max_6[7]) - rtb_zeroRCSinputs[8];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[45] =
      claw_main_P.Constant5_Value_o[0];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[46] =
      claw_main_P.Constant5_Value_o[1];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[47] =
      claw_main_P.Constant5_Value_o[2];
    for (i = 0; i < 6; i++) {
      claw_main_B.TmpHiddenBufferAtSFunctionInp_k[i + 48] =
        rtb_MultiportSwitch_oq[i] - rtb_zeroRCSinputs[i];
    }

    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[54] = rtb_MultiportSwitch_oq[6]
      - rtb_zeroRCSinputs[7];
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[55] = rtb_MultiportSwitch_oq[7]
      - rtb_zeroRCSinputs[8];
    memcpy((void *)(&claw_main_B.TmpHiddenBufferAtSFunctionInp_k[56]), (void *)
           &rtb_MultiportSwitch_oq[9], (uint32_T)((char_T *)
            &rtb_MultiportSwitch_oq[1U] - (char_T *)&rtb_MultiportSwitch_oq[0U])
           << 3U);
    claw_main_B.TmpHiddenBufferAtSFunctionInp_k[64] =
      claw_main_DWork.Memory_PreviousInput_j;

    /* S-Function "smn_sfunc_gam_mpass_epsposdef_wrapper" Block: <S307>/S-Function */
    smn_sfunc_gam_mpass_epsposdef_Outputs_wrapper
      (claw_main_B.TmpHiddenBufferAtSFunctionInp_k, claw_main_B.SFunction_g ,
       461, 65);

    /* Sum: '<S303>/Sum5' incorporates:
     *  Product: '<S303>/Product'
     */
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 8; yOffset_0++) {
        rtb_dircos_0[i] += rtb_Bmat_smn[3 * yOffset_0 + i] *
          claw_main_B.SFunction_g[yOffset_0];
      }
    }

    /* Embedded MATLAB: '<S298>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S298>/Constant'
     *  Constant: '<S298>/Constant1'
     *  Constant: '<S298>/Constant2'
     *  Selector: '<S196>/Bmat_rcs'
     */
    /* Embedded MATLAB Function 'claw_main/rate_loops/allocation/RCS allocation/Embedded MATLAB Function': '<S302>:1' */
    /* '<S302>:1:4' */
    rtb_scale = 1.0;

    /* '<S302>:1:26' */
    rtb_rcs_cmd = max_6[8];

    /* '<S302>:1:27' */
    /* '<S302>:1:28' */
    /* '<S302>:1:89' */
    rtb_Sum5_d_idx = rtb_dircos_0[0] - rtb_delta_LLh_idx;

    /* Gain: '<S196>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_l0 * rtb_Sum5_d_idx;
    rtb_UnitDelay_nf_idx = rtb_Assignment_k[24] * max_6[8];
    rtb_delta_LLh_idx = (rtb_UnitDelay_nf_idx - rtb_UnitDelay_nf_idx_0) *
      claw_main_P.Constant_Value_k5[0];
    min_0[0] = rt_pow_snf(rtb_delta_LLh_idx, 2.0);
    min[0] = rtb_delta_LLh_idx;
    rtb_Gain1_idx_0 = rtb_UnitDelay_nf_idx;
    rtb_Gain1_idx_1 = rtb_UnitDelay_nf_idx_0;
    rtb_Sum5_d_idx_0 = rtb_Sum5_d_idx;
    rtb_Sum5_d_idx = rtb_dircos_0[1] - rtb_delta_LLh_idx_0;

    /* Gain: '<S196>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_l0 * rtb_Sum5_d_idx;
    rtb_UnitDelay_nf_idx = rtb_Assignment_k[25] * max_6[8];
    rtb_delta_LLh_idx = (rtb_UnitDelay_nf_idx - rtb_UnitDelay_nf_idx_0) *
      claw_main_P.Constant_Value_k5[1];
    min_0[1] = rt_pow_snf(rtb_delta_LLh_idx, 2.0);
    min[1] = rtb_delta_LLh_idx;
    rtb_Gain1_idx = rtb_UnitDelay_nf_idx;
    rtb_MultiportSwitch2_idx_2 = rtb_UnitDelay_nf_idx_0;
    rtb_Sum5_d_idx_1 = rtb_Sum5_d_idx;
    rtb_Sum5_d_idx = rtb_dircos_0[2] - rtb_Switch2_idx;

    /* Gain: '<S196>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_l0 * rtb_Sum5_d_idx;
    rtb_UnitDelay_nf_idx = rtb_Assignment_k[26] * max_6[8];
    rtb_delta_LLh_idx = (rtb_UnitDelay_nf_idx - rtb_UnitDelay_nf_idx_0) *
      claw_main_P.Constant_Value_k5[2];
    min_0[2] = rt_pow_snf(rtb_delta_LLh_idx, 2.0);
    min[2] = rtb_delta_LLh_idx;
    rtb_minerr = sqrt((min_0[0] + min_0[1]) + min_0[2]);
    if (!(rtb_minerr <= claw_main_P.Constant2_Value_ce)) {
      /* '<S302>:1:34' */
      for (i = 0; i < 9; i++) {
        rtb_Gain1_oy_0[i] = 0.0;
      }

      rtb_Gain1_oy_0[0] = claw_main_P.Constant_Value_k5[0];
      rtb_Gain1_oy_0[4] = claw_main_P.Constant_Value_k5[1];
      rtb_Gain1_oy_0[8] = claw_main_P.Constant_Value_k5[2];

      /* '<S302>:1:35' */
      /* '<S302>:1:41' */
      /* '<S302>:1:42' */
      /* '<S302>:1:43' */
      /* '<S302>:1:44' */
      /* '<S302>:1:45' */
      /* '<S302>:1:46' */
      rtb_delta_LLh_idx = max_7[8] < 0.0 ? ceil(max_7[8] - 0.5) : floor(max_7[8]
        + 0.5);
      if (rtb_delta_LLh_idx < 4.294967296E+009) {
        if (rtb_delta_LLh_idx >= 0.0) {
          scalarIndex = (uint32_T)rtb_delta_LLh_idx;
        } else {
          scalarIndex = 0U;
        }
      } else {
        scalarIndex = MAX_uint32_T;
      }

      rtb_delta_LLh_idx = max_6[8] < 0.0 ? ceil(max_6[8] - 0.5) : floor(max_6[8]
        + 0.5);
      if (rtb_delta_LLh_idx < 4.294967296E+009) {
        if (rtb_delta_LLh_idx >= 0.0) {
          locIndex = (uint32_T)rtb_delta_LLh_idx;
        } else {
          locIndex = 0U;
        }
      } else {
        locIndex = MAX_uint32_T;
      }

      max_1 = (real_T)(((locIndex | 1U) & scalarIndex) == 1U) *
        claw_main_P.Constant1_Value_fo;
      if ((!(max_1 == 0.0)) && (!rtIsNaN(max_1))) {
        eml_b = false;
      } else {
        eml_b = true;
      }

      if ((!eml_b) && (max_1 != 0.0)) {
        /* '<S302>:1:59' */
        for (i = 0; i < 3; i++) {
          rtb_dircos_0[i] = 0.0;
          rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Assignment_k[24];
          rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Assignment_k[25];
          rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Assignment_k[26];
        }

        /*  optional scaling */
        /* '<S302>:1:77' */
        /* '<S302>:1:78' */
        /* '<S302>:1:89' */
        rtb_delta_LLh_idx = rtb_dircos_0[0] - claw_main_P.Constant_Value_k5[0] *
          rtb_Gain1_idx_1;
        rtb_delta_LLh_idx_0 = rt_pow_snf(rtb_delta_LLh_idx, 2.0);
        min[0] = rtb_dircos_0[0];
        rtb_delta_LLh_idx = rtb_dircos_0[1] - claw_main_P.Constant_Value_k5[1] *
          rtb_MultiportSwitch2_idx_2;
        rtb_Switch2_idx = rt_pow_snf(rtb_delta_LLh_idx, 2.0);
        min[1] = rtb_dircos_0[1];
        rtb_delta_LLh_idx = rtb_dircos_0[2] - claw_main_P.Constant_Value_k5[2] *
          rtb_UnitDelay_nf_idx_0;
        min[2] = rtb_dircos_0[2];
        max_1 = sqrt((rtb_delta_LLh_idx_0 + rtb_Switch2_idx) + rt_pow_snf
                     (rtb_delta_LLh_idx, 2.0));
        if (max_1 < rtb_minerr) {
          /* '<S302>:1:79' */
          /* '<S302>:1:80' */
          rtb_scale = 1.0;

          /* '<S302>:1:81' */
          rtb_rcs_cmd = 1.0;

          /* '<S302>:1:82' */
          rtb_minerr = max_1;

          /* '<S302>:1:83' */
          rtb_Gain1_idx_0 = min[0] / claw_main_P.Constant_Value_k5[0];
          rtb_Gain1_idx = min[1] / claw_main_P.Constant_Value_k5[1];
          rtb_UnitDelay_nf_idx = min[2] / claw_main_P.Constant_Value_k5[2];
        }
      } else {
        /* '<S302>:1:54' */
        /* '<S302>:1:48' */
      }
    } else {
      /* '<S302>:1:30' */
    }

    /* Sum: '<S298>/Sum5' */
    rtb_Sum5_b_idx = rtb_Gain1_idx_0 - rtb_Gain1_idx_1;
    rtb_Sum5_b_idx_0 = rtb_Gain1_idx - rtb_MultiportSwitch2_idx_2;
    rtb_Sum5_b_idx_1 = rtb_UnitDelay_nf_idx - rtb_UnitDelay_nf_idx_0;

    /* Gain: '<S16>/Gain4' */
    for (i = 0; i < 12; i++) {
      rtb_Gain4_i[i] = claw_main_P.Gain4_Gain_bs * rtb_MatrixConcatenation[i];
    }

    /* S-Function (sfix_dot): '<S16>/Dot Product' */
    rtb_delta_LLh_idx = ((rtb_Switch_idx * rtb_Sum4_l_idx + rtb_Switch_idx_0 *
                          rtb_Sum4_l_idx_0) + rtb_Switch_idx_1 *
                         rtb_Sum4_l_idx_1) + rtb_Switch_idx_2 * rtb_Sum4_l_idx_2;

    /* Sum: '<S16>/Sum4' incorporates:
     *  Product: '<S16>/Product4'
     *  Product: '<S16>/Product5'
     */
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i] * rtb_Assignment_pi_idx;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i + 4] *
        rtb_MultiportSwitch_c_idx;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i + 8] *
        rtb_MultiportSwitch_c_idx_0;
    }

    rtb_Sum4_li_idx = (rtb_Switch_idx * rtb_delta_LLh_idx +
                       rtb_MatrixConcatenation_j_0[0]) - rtb_Sum4_l_idx;
    rtb_Sum4_li_idx_0 = (rtb_Switch_idx_0 * rtb_delta_LLh_idx +
                         rtb_MatrixConcatenation_j_0[1]) - rtb_Sum4_l_idx_0;
    rtb_Sum4_li_idx_1 = (rtb_Switch_idx_1 * rtb_delta_LLh_idx +
                         rtb_MatrixConcatenation_j_0[2]) - rtb_Sum4_l_idx_1;
    rtb_Sum4_li_idx_2 = (rtb_Switch_idx_2 * rtb_delta_LLh_idx +
                         rtb_MatrixConcatenation_j_0[3]) - rtb_Sum4_l_idx_2;

    /* Sum: '<S757>/Sum5' incorporates:
     *  Product: '<S757>/Product'
     */
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Assignment_m[i] * claw_main_B.SFunction[0];
      rtb_dircos_0[i] += rtb_Assignment_m[i + 3] * claw_main_B.SFunction[1];
      rtb_dircos_0[i] += rtb_Assignment_m[i + 6] * claw_main_B.SFunction[2];
    }

    rtb_Sum5_p_idx = rtb_dircos_0[0] - rtb_Sum_f3_idx_0;

    /* Sum: '<S188>/Sum2' */
    rtb_Sum2_ht[0] = rtb_Switch_m_idx_0 - rtb_Sum4_c_idx_0;
    rtb_Sum5_p_idx_0 = rtb_dircos_0[1] - rtb_Sum_f3_idx_1;

    /* Sum: '<S188>/Sum2' */
    rtb_Sum2_ht[1] = rtb_Switch_m_idx_1 - rtb_Sum4_c_idx_1;
    rtb_Sum4_c_idx_0 = rtb_dircos_0[2] - rtb_Sum_f3_idx;

    /* Sum: '<S188>/Sum2' */
    rtb_Sum2_ht[2] = rtb_Switch_m_idx - rtb_Sum4_c_idx;

    /* Outputs for atomic SubSystem: '<S80>/Subsystem' */

    /* Inport: '<S85>/In1' */
    CLAW_p_cvdex = rtb_Sum5_b_idx;

    /* Inport: '<S85>/In2' */
    CLAW_q_cvdex = rtb_Sum5_b_idx_0;

    /* Inport: '<S85>/In3' */
    CLAW_r_cvdex = rtb_Sum5_b_idx_1;

    /* Inport: '<S85>/In4' */
    CLAW_e0_cvdex = rtb_Sum4_li_idx;

    /* Inport: '<S85>/In5' */
    CLAW_e1_cvdex = rtb_Sum4_li_idx_0;

    /* Inport: '<S85>/In6' */
    CLAW_e2_cvdex = rtb_Sum4_li_idx_1;

    /* Inport: '<S85>/In7' */
    CLAW_e3_cvdex = rtb_Sum4_li_idx_2;

    /* Inport: '<S85>/In8' */
    CLAW_Ndot_cvdex = rtb_Sum5_p_idx;

    /* Inport: '<S85>/In9' */
    CLAW_Edot_cvdex = rtb_Sum5_p_idx_0;

    /* Inport: '<S85>/In10' */
    CLAW_hdot_cvdex = rtb_Sum4_c_idx_0;

    /* Inport: '<S85>/In11' */
    CLAW_N_cvdex = rtb_Sum2_ht[0];

    /* Inport: '<S85>/In12' */
    CLAW_E_cvdex = rtb_Sum2_ht[1];

    /* Inport: '<S85>/In13' */
    CLAW_h_cvdex = rtb_Sum2_ht[2];

    /* end of Outputs for SubSystem: '<S80>/Subsystem' */

    /* Outputs for atomic SubSystem: '<S81>/Subsystem' */

    /* Inport: '<S86>/In1' */
    CLAW_p_int = claw_main_B.DiscreteTimeIntegrator_j[0];

    /* Inport: '<S86>/In2' */
    CLAW_q_int = claw_main_B.DiscreteTimeIntegrator_j[1];

    /* Inport: '<S86>/In3' */
    CLAW_r_int = claw_main_B.DiscreteTimeIntegrator_j[2];

    /* Inport: '<S86>/In4' */
    CLAW_e0_int = claw_main_B.DiscreteTimeIntegrator_p[0];

    /* Inport: '<S86>/In5' */
    CLAW_e1_int = claw_main_B.DiscreteTimeIntegrator_p[1];

    /* Inport: '<S86>/In6' */
    CLAW_e2_int = claw_main_B.DiscreteTimeIntegrator_p[2];

    /* Inport: '<S86>/In7' */
    CLAW_e3_int = claw_main_B.DiscreteTimeIntegrator_p[3];

    /* Inport: '<S86>/In8' */
    CLAW_Ndot_int = claw_main_B.DiscreteTimeIntegrator_o[0];

    /* Inport: '<S86>/In9' */
    CLAW_Edot_int = claw_main_B.DiscreteTimeIntegrator_o[1];

    /* Inport: '<S86>/In10' */
    CLAW_hdot_int = claw_main_B.DiscreteTimeIntegrator_o[2];

    /* Inport: '<S86>/In11' */
    CLAW_N_int = claw_main_B.DiscreteTimeIntegrator[0];

    /* Inport: '<S86>/In12' */
    CLAW_E_int = claw_main_B.DiscreteTimeIntegrator[1];

    /* Inport: '<S86>/In13' */
    CLAW_h_int = claw_main_B.DiscreteTimeIntegrator[2];

    /* end of Outputs for SubSystem: '<S81>/Subsystem' */

    /* Outputs for atomic SubSystem: '<S82>/Subsystem' */

    /* Inport: '<S87>/In1' */
    CLAW_Nd_wind = rtb_w_est[0];

    /* Inport: '<S87>/In2' */
    CLAW_Ed_wind = rtb_w_est[1];

    /* Inport: '<S87>/In3' */
    CLAW_Dd_wind = rtb_w_est[2];

    /* end of Outputs for SubSystem: '<S82>/Subsystem' */

    /* S-Function (sfix_dot): '<S11>/Dot Product2' incorporates:
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    rtb_Gain1_idx_0 = ((rtb_Switch_idx * claw_main_DWork.UnitDelay1_DSTATE_h[0]
                        + rtb_Switch_idx_0 *
                        claw_main_DWork.UnitDelay1_DSTATE_h[1]) +
                       rtb_Switch_idx_1 * claw_main_DWork.UnitDelay1_DSTATE_h[2])
      + rtb_Switch_idx_2 * claw_main_DWork.UnitDelay1_DSTATE_h[3];

    /* RelationalOperator: '<S175>/Compare' */
    eml_b = (rtb_Reshape_n[12] > 0.0);

    /* Product: '<S20>/Product1' incorporates:
     *  Product: '<S174>/Divide1'
     */
    rtb_uvw_rw_idx_0 = (eml_b ? rtb_Reshape_n[0] : 0.0) * rtb_Sum4_li_idx;
    rtb_Compare_bh_idx = eml_b;

    /* RelationalOperator: '<S175>/Compare' */
    eml_b = (rtb_Reshape_n[13] > 0.0);

    /* Product: '<S20>/Product1' incorporates:
     *  Product: '<S174>/Divide1'
     */
    rtb_MultiportSwitch1_idx = (eml_b ? rtb_Reshape_n[1] : 0.0) *
      rtb_Sum4_li_idx_0;
    rtb_Compare_bh_idx_0 = eml_b;

    /* RelationalOperator: '<S175>/Compare' */
    eml_b = (rtb_Reshape_n[14] > 0.0);

    /* Product: '<S20>/Product1' incorporates:
     *  Product: '<S174>/Divide1'
     */
    rtb_MultiportSwitch1_idx_0 = (eml_b ? rtb_Reshape_n[2] : 0.0) *
      rtb_Sum4_li_idx_1;
    rtb_Compare_bh_idx_1 = eml_b;

    /* RelationalOperator: '<S175>/Compare' */
    eml_b = (rtb_Reshape_n[15] > 0.0);

    /* Product: '<S20>/Product1' incorporates:
     *  Product: '<S174>/Divide1'
     */
    rtb_MultiportSwitch1_idx_1 = (eml_b ? rtb_Reshape_n[3] : 0.0) *
      rtb_Sum4_li_idx_2;

    /* Product: '<S20>/Product3' incorporates:
     *  Constant: '<S174>/Constant1'
     *  Gain: '<S11>/fe'
     *  Product: '<S11>/Product2'
     *  Product: '<S12>/Product'
     *  Product: '<S174>/Divide'
     *  Sum: '<S11>/Sum'
     *  Sum: '<S12>/Sum1'
     */
    rtb_Switch2_idx = rtb_MultiportSwitch_k_idx - rtb_Assignment_pi_idx;
    rtb_delta_LLh_idx_0 = rtb_MultiportSwitch_k_idx_0 -
      rtb_MultiportSwitch_c_idx;
    rtb_delta_LLh_idx = rtb_MultiportSwitch_k_idx_1 -
      rtb_MultiportSwitch_c_idx_0;
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i] * rtb_Switch2_idx;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i + 4] * rtb_delta_LLh_idx_0;
      rtb_MatrixConcatenation_j_0[i] += rtb_Gain4_i[i + 8] * rtb_delta_LLh_idx;
    }

    rtb_Product2_a_idx_2 = (rtb_Compare_bh_idx ? 1.0 / rtb_Reshape_n[4] /
      rtb_MathFunction_lo_idx * claw_main_P.Constant1_Value_ad : 0.0) *
      (rtb_MatrixConcatenation_j_0[0] - rtb_Switch_idx * rtb_Gain1_idx_0 *
       claw_main_P.fe_Gain);
    rtb_Gain4_idx_2 = (rtb_Compare_bh_idx_0 ? 1.0 / rtb_Reshape_n[5] /
                       rtb_MathFunction_lo_idx_0 *
                       claw_main_P.Constant1_Value_ad : 0.0) *
      (rtb_MatrixConcatenation_j_0[1] - rtb_Switch_idx_0 * rtb_Gain1_idx_0 *
       claw_main_P.fe_Gain);
    rtb_Product2_a_idx_1 = (rtb_Compare_bh_idx_1 ? 1.0 / rtb_Reshape_n[6] /
      rtb_MathFunction_lo_idx_1 * claw_main_P.Constant1_Value_ad : 0.0) *
      (rtb_MatrixConcatenation_j_0[2] - rtb_Switch_idx_1 * rtb_Gain1_idx_0 *
       claw_main_P.fe_Gain);
    rtb_Gain4_idx_1 = (eml_b ? 1.0 / rtb_Reshape_n[7] /
                       rtb_MathFunction_lo_idx_2 *
                       claw_main_P.Constant1_Value_ad : 0.0) *
      (rtb_MatrixConcatenation_j_0[3] - rtb_Switch_idx_2 * rtb_Gain1_idx_0 *
       claw_main_P.fe_Gain);

    /* Gain: '<S17>/Gain1' incorporates:
     *  Math: '<S17>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Product_j3_idx * rtb_Product_j3_idx;
    rtb_delta_LLh_idx_0 = rtb_Product_j3_idx_0 * rtb_Product_j3_idx_0;
    rtb_Switch2_idx = rtb_Product_j3_idx_1 * rtb_Product_j3_idx_1;
    rtb_Gain1_idx_0 = rtb_Product_j3_idx_2 * rtb_Product_j3_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_b1[i] = 0.0;
      rtb_Gain1_b1[i] += claw_main_P.Gain1_Gain_cgd[i] * rtb_delta_LLh_idx;
      rtb_Gain1_b1[i] += claw_main_P.Gain1_Gain_cgd[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_b1[i] += claw_main_P.Gain1_Gain_cgd[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_b1[i] += claw_main_P.Gain1_Gain_cgd[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S17>/e1*e2' */
    rtb_e1e2_c = rtb_Product_j3_idx_0 * rtb_Product_j3_idx_1;

    /* Product: '<S17>/e3*e1' */
    rtb_e3e1_j = rtb_Product_j3_idx_2 * rtb_Product_j3_idx_0;

    /* Product: '<S17>/e2*e3' */
    rtb_e2e3_f = rtb_Product_j3_idx_1 * rtb_Product_j3_idx_2;

    /* Product: '<S17>/e0*e3' */
    rtb_e0e3_h = rtb_Product_j3_idx * rtb_Product_j3_idx_2;

    /* Product: '<S17>/e0*e2' */
    rtb_e0e2_da = rtb_Product_j3_idx * rtb_Product_j3_idx_1;

    /* Product: '<S17>/e0*e1' */
    rtb_e0e1_o = rtb_Product_j3_idx * rtb_Product_j3_idx_0;

    /* Gain: '<S17>/Gain' incorporates:
     *  Sum: '<S17>/Sum'
     *  Sum: '<S17>/Sum1'
     */
    rtb_delta_LLh_idx = (rtb_e1e2_c + rtb_e0e3_h) * claw_main_P.Gain_Gain_b5;
    rtb_delta_LLh_idx_0 = (rtb_e3e1_j + rtb_e0e2_da) * claw_main_P.Gain_Gain_b5;
    rtb_Switch2_idx = (rtb_e2e3_f + rtb_e0e1_o) * claw_main_P.Gain_Gain_b5;
    rtb_Gain1_idx_0 = (rtb_e1e2_c - rtb_e0e3_h) * claw_main_P.Gain_Gain_b5;
    rtb_Gain1_idx_1 = (rtb_e3e1_j - rtb_e0e2_da) * claw_main_P.Gain_Gain_b5;
    rtb_Gain1_idx = (rtb_e2e3_f - rtb_e0e1_o) * claw_main_P.Gain_Gain_b5;

    /* Product: '<S13>/Product' incorporates:
     *  Math: '<S13>/Math Function'
     *  Reshape: '<S13>/Reshape2'
     *  Reshape: '<S13>/Reshape3'
     */
    rtb_Gain1_oy_0[0] = rtb_Gain1_b1[1];
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[3] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[4] = rtb_Gain1_b1[2];
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[7] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[8] = rtb_Gain1_b1[3];
    rtb_Sum4_j_0[0] = rtb_Product_h;
    rtb_Sum4_j_0[1] = rtb_Sum_m;
    rtb_Sum4_j_0[2] = rtb_Sum1_p;
    rtb_Sum4_j_0[3] = rtb_Product5;
    rtb_Sum4_j_0[4] = rtb_Sum2_l;
    rtb_Sum4_j_0[5] = rtb_Sum3;
    rtb_Sum4_j_0[6] = rtb_Gain_p;
    rtb_Sum4_j_0[7] = rtb_Product10;
    rtb_Sum4_j_0[8] = rtb_Product11;
    for (i = 0; i < 3; i++) {
      for (yOffset_0 = 0; yOffset_0 < 3; yOffset_0++) {
        rtb_Product_hz[i + 3 * yOffset_0] = 0.0;
        rtb_Product_hz[i + 3 * yOffset_0] = rtb_Product_hz[3 * yOffset_0 + i] +
          rtb_Gain1_oy_0[i] * rtb_Sum4_j_0[yOffset_0];
        rtb_Product_hz[i + 3 * yOffset_0] = rtb_Product_hz[3 * yOffset_0 + i] +
          rtb_Gain1_oy_0[i + 3] * rtb_Sum4_j_0[yOffset_0 + 3];
        rtb_Product_hz[i + 3 * yOffset_0] = rtb_Product_hz[3 * yOffset_0 + i] +
          rtb_Gain1_oy_0[i + 6] * rtb_Sum4_j_0[yOffset_0 + 6];
      }
    }

    /* Gain: '<S13>/Gain1' incorporates:
     *  Gain: '<S24>/Gain'
     *  Gain: '<S25>/Gain'
     *  Math: '<S25>/Math Function1'
     *  Reshape: '<S13>/Reshape1'
     *  Trigonometry: '<S25>/Trigonometric Function1'
     *  Trigonometry: '<S25>/Trigonometric Function2'
     *  Trigonometry: '<S25>/Trigonometric Function3'
     */
    rtb_Sum_f3_idx_1 = claw_main_P.Gain_Gain_k5 * rt_atan2_snf(rtb_Product_hz[7],
      rtb_Product_hz[4]) * claw_main_P.Gain1_Gain_ky[0];
    rtb_Gain4_idx = claw_main_P.Gain_Gain_k5 * rt_atan2_snf(rtb_Product_hz[2],
      rtb_Product_hz[0]) * claw_main_P.Gain1_Gain_ky[1];
    rtb_Product2_a_idx = rt_atan2_snf(claw_main_P.Gain_Gain_mz * rtb_Product_hz
      [1], rt_hypot_snf(rtb_Product_hz[4], rtb_Product_hz[7])) *
      claw_main_P.Gain_Gain_k5 * claw_main_P.Gain1_Gain_ky[2];

    /* Gain: '<S14>/Gain' incorporates:
     *  Reshape: '<S14>/Reshape'
     */
    rtb_Gain1_oy_0[0] = rtb_Gain1_b1[1];
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[3] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[4] = rtb_Gain1_b1[2];
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[7] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[8] = rtb_Gain1_b1[3];
    for (i = 0; i < 3; i++) {
      for (yOffset_0 = 0; yOffset_0 < 3; yOffset_0++) {
        rtb_Gain_om[i + 3 * yOffset_0] = 0.0;
        rtb_Gain_om[i + 3 * yOffset_0] = rtb_Gain_om[3 * yOffset_0 + i] +
          rtb_Gain1_oy_0[3 * yOffset_0] * claw_main_P.Gain_Gain_on[i];
        rtb_Gain_om[i + 3 * yOffset_0] = rtb_Gain1_oy_0[3 * yOffset_0 + 1] *
          claw_main_P.Gain_Gain_on[i + 3] + rtb_Gain_om[3 * yOffset_0 + i];
        rtb_Gain_om[i + 3 * yOffset_0] = rtb_Gain1_oy_0[3 * yOffset_0 + 2] *
          claw_main_P.Gain_Gain_on[i + 6] + rtb_Gain_om[3 * yOffset_0 + i];
      }
    }

    /* Gain: '<S27>/Gain' incorporates:
     *  Gain: '<S28>/Gain'
     *  Math: '<S28>/Math Function1'
     *  Reshape: '<S14>/Reshape1'
     *  Trigonometry: '<S28>/Trigonometric Function1'
     *  Trigonometry: '<S28>/Trigonometric Function2'
     *  Trigonometry: '<S28>/Trigonometric Function3'
     */
    rtb_Sum_f3_idx_0 = claw_main_P.Gain_Gain_fb * rt_atan2_snf(rtb_Gain_om[5],
      rtb_Gain_om[8]);
    rtb_Gain4_idx_0 = rt_atan2_snf(claw_main_P.Gain_Gain_d5i * rtb_Gain_om[2],
      rt_hypot_snf(rtb_Gain_om[8], rtb_Gain_om[5])) * claw_main_P.Gain_Gain_fb;
    rtb_Product2_a_idx_0 = claw_main_P.Gain_Gain_fb * rt_atan2_snf(rtb_Gain_om[1],
      rtb_Gain_om[0]);

    /* Gain: '<S15>/Gain' incorporates:
     *  Reshape: '<S15>/Reshape'
     */
    rtb_Gain1_oy_0[0] = rtb_Gain1_b1[1];
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[3] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[4] = rtb_Gain1_b1[2];
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[7] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[8] = rtb_Gain1_b1[3];
    for (i = 0; i < 3; i++) {
      for (yOffset_0 = 0; yOffset_0 < 3; yOffset_0++) {
        rtb_Gain_ah[i + 3 * yOffset_0] = 0.0;
        rtb_Gain_ah[i + 3 * yOffset_0] = rtb_Gain_ah[3 * yOffset_0 + i] +
          rtb_Gain1_oy_0[3 * yOffset_0] * claw_main_P.Gain_Gain_ff[i];
        rtb_Gain_ah[i + 3 * yOffset_0] = rtb_Gain1_oy_0[3 * yOffset_0 + 1] *
          claw_main_P.Gain_Gain_ff[i + 3] + rtb_Gain_ah[3 * yOffset_0 + i];
        rtb_Gain_ah[i + 3 * yOffset_0] = rtb_Gain1_oy_0[3 * yOffset_0 + 2] *
          claw_main_P.Gain_Gain_ff[i + 6] + rtb_Gain_ah[3 * yOffset_0 + i];
      }
    }

    /* Gain: '<S30>/Gain' incorporates:
     *  Gain: '<S31>/Gain'
     *  Math: '<S31>/Math Function1'
     *  Reshape: '<S15>/Reshape1'
     *  Trigonometry: '<S31>/Trigonometric Function1'
     *  Trigonometry: '<S31>/Trigonometric Function2'
     *  Trigonometry: '<S31>/Trigonometric Function3'
     */
    rtb_orderatts_a_idx_0 = claw_main_P.Gain_Gain_ck * rt_atan2_snf(rtb_Gain_ah
      [7], rtb_Gain_ah[8]);
    rtb_orderatts_a_idx_1 = rt_atan2_snf(claw_main_P.Gain_Gain_dt * rtb_Gain_ah
      [6], rt_hypot_snf(rtb_Gain_ah[0], rtb_Gain_ah[3])) *
      claw_main_P.Gain_Gain_ck;
    rtb_Sum_f3_idx = claw_main_P.Gain_Gain_ck * rt_atan2_snf(rtb_Gain_ah[3],
      rtb_Gain_ah[0]);

    /* RelationalOperator: '<S177>/Compare' */
    eml_b = (rtb_Reshape_n[25] > 0.0);

    /* RelationalOperator: '<S179>/Compare' */
    rtb_Compare_bh_idx = (rtb_Reshape_n[37] > 0.0);

    /* RelationalOperator: '<S185>/Compare' */
    rtb_Compare_bh_idx_0 = (rtb_Reshape_n[49] > 0.0);

    /* Product: '<S184>/Divide' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    min_5 = rtb_Compare_bh_idx_0 ? 1.0 / rtb_Reshape_n[43] / rtb_eow_idx_idx *
      claw_main_P.Constant1_Value_gt : 0.0;

    /* Product: '<S184>/Divide1' */
    rtb_orderatts_a_idx = rtb_Compare_bh_idx_0 ? rtb_Reshape_n[40] : 0.0;

    /* Product: '<S186>/Product1' incorporates:
     *  Product: '<S176>/Divide1'
     */
    rtb_orderatts_i_idx_0 = (eml_b ? rtb_Reshape_n[16] : 0.0) * rtb_Sum2_ht[0];
    rtb_Compare_bh_idx_1 = eml_b;

    /* RelationalOperator: '<S177>/Compare' */
    eml_b = (rtb_Reshape_n[26] > 0.0);

    /* RelationalOperator: '<S179>/Compare' */
    rtb_Compare_ow_idx = (rtb_Reshape_n[38] > 0.0);

    /* RelationalOperator: '<S185>/Compare' */
    rtb_Compare_bh_idx_0 = (rtb_Reshape_n[50] > 0.0);

    /* Product: '<S184>/Divide' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    rtb_MathFunction_lo_idx_0 = rtb_Compare_bh_idx_0 ? 1.0 / rtb_Reshape_n[44] /
      rtb_X_idx_idx * claw_main_P.Constant1_Value_gt : 0.0;

    /* Product: '<S184>/Divide1' */
    rtb_MathFunction_lo_idx = rtb_Compare_bh_idx_0 ? rtb_Reshape_n[41] : 0.0;

    /* Product: '<S186>/Product1' incorporates:
     *  Product: '<S176>/Divide1'
     */
    rtb_MathFunction_lo_idx_1 = (eml_b ? rtb_Reshape_n[17] : 0.0) * rtb_Sum2_ht
      [1];
    rtb_Compare_j_idx = eml_b;

    /* RelationalOperator: '<S177>/Compare' */
    eml_b = (rtb_Reshape_n[27] > 0.0);

    /* RelationalOperator: '<S179>/Compare' */
    rtb_Compare_ow_idx_0 = (rtb_Reshape_n[39] > 0.0);

    /* RelationalOperator: '<S185>/Compare' */
    rtb_Compare_bh_idx_0 = (rtb_Reshape_n[51] > 0.0);

    /* Product: '<S184>/Divide' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    rtb_orderatts_i_idx_1 = rtb_Compare_bh_idx_0 ? 1.0 / rtb_Reshape_n[45] /
      rtb_MathFunction_pa_idx * claw_main_P.Constant1_Value_gt : 0.0;

    /* Product: '<S184>/Divide1' */
    rtb_MultiportSwitch_o_idx_0 = rtb_Compare_bh_idx_0 ? rtb_Reshape_n[42] : 0.0;

    /* Product: '<S186>/Product1' incorporates:
     *  Product: '<S176>/Divide1'
     */
    rtb_MathFunction_lo_idx_2 = (eml_b ? rtb_Reshape_n[18] : 0.0) * rtb_Sum2_ht
      [2];

    /* Product: '<S186>/Product3' incorporates:
     *  Constant: '<S176>/Constant1'
     *  Product: '<S176>/Divide'
     *  Sum: '<S187>/Sum1'
     */
    rtb_X_idx_idx = (rtb_Compare_bh_idx_1 ? 1.0 / rtb_Reshape_n[19] /
                     rtb_MathFunction_h_idx * claw_main_P.Constant1_Value_f0 :
                     0.0) * (rtb_MultiportSwitch_n_idx_0 - rtb_Switch_m_idx_0);
    rtb_Assignment_pi_idx = (rtb_Compare_j_idx ? 1.0 / rtb_Reshape_n[20] /
      rtb_MathFunction_h_idx_0 * claw_main_P.Constant1_Value_f0 : 0.0) *
      (rtb_MultiportSwitch_n_idx_1 - rtb_Switch_m_idx_1);
    rtb_Assignment_l_idx = (eml_b ? 1.0 / rtb_Reshape_n[21] /
      rtb_MathFunction_h_idx_1 * claw_main_P.Constant1_Value_f0 : 0.0) *
      (rtb_MultiportSwitch_n_idx - rtb_Switch_m_idx);

    /* Sum: '<S303>/Sum4' */
    for (i = 0; i < 6; i++) {
      rtb_Sum4_j[i] = claw_main_B.SFunction_g[i] + rtb_zeroRCSinputs[i];
    }

    rtb_Sum4_j[6] = claw_main_B.SFunction_g[6] + rtb_zeroRCSinputs[7];
    rtb_Sum4_j[7] = claw_main_B.SFunction_g[7] + rtb_zeroRCSinputs[8];

    /* Product: '<S195>/Product1' incorporates:
     *  Product: '<S178>/Divide1'
     */
    rtb_MultiportSwitch_c_idx = (rtb_Compare_bh_idx ? rtb_Reshape_n[28] : 0.0) *
      rtb_Sum5_b_idx;
    rtb_MultiportSwitch_c_idx_0 = (rtb_Compare_ow_idx ? rtb_Reshape_n[29] : 0.0)
      * rtb_Sum5_b_idx_0;
    rtb_eow_idx_idx = (rtb_Compare_ow_idx_0 ? rtb_Reshape_n[30] : 0.0) *
      rtb_Sum5_b_idx_1;

    /* MultiPortSwitch: '<S7>/Multiport Switch1' */
    if ((int32_T)rtb_control_input[95] == 0) {
      /* MultiPortSwitch: '<S7>/Multiport Switch2' */
      if ((int32_T)rtb_control_input[104] == 0) {
        /* SignalConversion: '<S312>/TmpHiddenBufferAtAssignment1Inport2' incorporates:
         *  Assignment: '<S93>/set att cmd'
         *  Assignment: '<S99>/set pos cmd'
         *  Gain: '<S312>/Gain'
         *  Gain: '<S312>/Gain1'
         */
        for (i = 0; i < 6; i++) {
          min_6[i] = 0.0;
          min_6[i] += claw_main_P.Gain_Gain_e[i] *
            rtb_InterpolationnDusingPreLo_0;
          min_6[i] += claw_main_P.Gain_Gain_e[i + 6] *
            rtb_InterpolationnDusingPreLo_1;
          min_6[i] += claw_main_P.Gain_Gain_e[i + 12] *
            rtb_attcmdintegration_idx;
          rtb_TmpHiddenBufferAtAssignme_f[i] = min_6[i];
        }

        rtb_TmpHiddenBufferAtAssignme_f[6] = claw_main_P.Gain1_Gain_g *
          rtb_InterpolationnDusingPreLo_2;

        /* Assignment: '<S312>/Assignment1' incorporates:
         *  Constant: '<S312>/Constant'
         */
        memcpy((void *)&rtb_Assignment1_m[0], (void *)
               (&claw_main_P.Constant_Value_b[0]), 10U * (uint32_T)((char_T *)
                (&claw_main_P.Constant_Value_b[1]) - (char_T *)
                (&claw_main_P.Constant_Value_b[0])));
        yOffset = 0;
        for (uDimIdx = 0; uDimIdx < 7; uDimIdx++) {
          rtb_Assignment1_m[uDimIdx] = rtb_TmpHiddenBufferAtAssignme_f[yOffset];
          yOffset++;
        }

        memcpy((void *)&rtb_MultiportSwitch2_j[0], (void *)&rtb_Assignment1_m[0],
               10U * (uint32_T)((char_T *)&rtb_Assignment1_m[1U] - (char_T *)
                &rtb_Assignment1_m[0U]));
      } else {
        memcpy((void *)&rtb_MultiportSwitch2_j[0], (void *)&min_1[0], 10U *
               (uint32_T)((char_T *)&min_1[1U] - (char_T *)&min_1[0U]));
      }

      memcpy((void *)&rtb_MultiportSwitch1_d[0], (void *)
             &rtb_MultiportSwitch2_j[0], 10U * (uint32_T)((char_T *)
              &rtb_MultiportSwitch2_j[1U] - (char_T *)&rtb_MultiportSwitch2_j[0U]));
    } else {
      /* SignalConversion: '<S6>/TmpHiddenBufferAtAssignment1Inport2' */
      memcpy((void *)&rtb_TmpHiddenBufferAtAssignme_m[0], (void *)&rtb_Sum4_j[0],
             (uint32_T)((char_T *)&rtb_Sum4_j[1U] - (char_T *)&rtb_Sum4_j[0U]) <<
             3U);
      rtb_TmpHiddenBufferAtAssignme_m[8] = rtb_rcs_cmd;
      rtb_TmpHiddenBufferAtAssignme_m[9] = rtb_MultiportSwitch_k_idx_2;

      /* Assignment: '<S6>/Assignment1' incorporates:
       *  Constant: '<S6>/Constant'
       */
      memcpy((void *)&rtb_Assignment1_d[0], (void *)
             (&claw_main_P.Constant_Value_h[0]), 10U * (uint32_T)((char_T *)
              (&claw_main_P.Constant_Value_h[1]) - (char_T *)
              (&claw_main_P.Constant_Value_h[0])));
      yOffset = 0;
      for (uDimIdx = 0; uDimIdx < 10; uDimIdx++) {
        rtb_Assignment1_d[(int32_T)tmp_c[uDimIdx]] =
          rtb_TmpHiddenBufferAtAssignme_m[yOffset];
        yOffset++;
      }

      memcpy((void *)&rtb_MultiportSwitch1_d[0], (void *)&rtb_Assignment1_d[0],
             10U * (uint32_T)((char_T *)&rtb_Assignment1_d[1U] - (char_T *)
              &rtb_Assignment1_d[0U]));
    }

    /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    if ((int32_T)rtb_control_input[97] == 0) {
      memcpy((void *)&rtb_MultiportSwitch_cn[0], (void *)
             &rtb_MultiportSwitch1_d[0], 10U * (uint32_T)((char_T *)
              &rtb_MultiportSwitch1_d[1U] - (char_T *)&rtb_MultiportSwitch1_d[0U]));
    } else {
      memcpy((void *)&rtb_MultiportSwitch_cn[0], (void *)
             (&claw_main_P.Constant1_Value_a[0]), 10U * (uint32_T)((char_T *)
              (&claw_main_P.Constant1_Value_a[1]) - (char_T *)
              (&claw_main_P.Constant1_Value_a[0])));
    }

    /* Product: '<S195>/Product3' incorporates:
     *  Constant: '<S178>/Constant1'
     *  Product: '<S178>/Divide'
     *  Product: '<S198>/Product'
     *  Sum: '<S198>/Sum1'
     */
    for (i = 0; i < 6; i++) {
      rtb_Gain1_oy_0[i] = rtb_MultiportSwitch_cn[i];
    }

    rtb_Gain1_oy_0[6] = rtb_MultiportSwitch_cn[7];
    rtb_Gain1_oy_0[7] = rtb_MultiportSwitch_cn[8];
    rtb_Gain1_oy_0[8] = rtb_MultiportSwitch_cn[9];
    memcpy((void *)&rtb_Sum4_j_0[0], (void *)&rtb_Sum4_j[0], (uint32_T)((char_T *)
            &rtb_Sum4_j[1U] - (char_T *)&rtb_Sum4_j[0U]) << 3U);
    rtb_Sum4_j_0[8] = rtb_rcs_cmd;
    for (i = 0; i < 9; i++) {
      rtb_MultiportSwitch_cn_0[i] = rtb_Gain1_oy_0[i] - rtb_Sum4_j_0[i];
    }

    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        rtb_dircos_0[i] += rtb_Assignment_k[3 * yOffset_0 + i] *
          rtb_MultiportSwitch_cn_0[yOffset_0];
      }
    }

    rtb_Sum_h_idx = (rtb_Compare_bh_idx ? 1.0 / rtb_Reshape_n[31] /
                     rtb_InterpolationnDusingPreLo_5 *
                     claw_main_P.Constant1_Value_dt : 0.0) * rtb_dircos_0[0];
    rtb_Product1_b_idx_1 = (rtb_Compare_ow_idx ? 1.0 / rtb_Reshape_n[32] /
      rtb_InterpolationnDusingPreLo_4 * claw_main_P.Constant1_Value_dt : 0.0) *
      rtb_dircos_0[1];
    rtb_Product1_b_idx_0 = (rtb_Compare_ow_idx_0 ? 1.0 / rtb_Reshape_n[33] /
      rtb_InterpolationnDusingPreLo_3 * claw_main_P.Constant1_Value_dt : 0.0) *
      rtb_dircos_0[2];

    /* Reshape: '<S307>/Reshape1' */
    memcpy((void *)&rtb_Reshape1_i[0], (void *)(&claw_main_B.SFunction_g[9]),
           176U * (uint32_T)((char_T *)(&claw_main_B.SFunction_g[1]) - (char_T *)
            (&claw_main_B.SFunction_g[0])));

    /* Selector: '<S196>/Selector' */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 2; uDimIdx++) {
      i = 22 * tmp_9[uDimIdx];
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        rtb_Selector_f[yOffset] = rtb_Reshape1_i[i + yOffset_0];
        yOffset++;
      }
    }

    /* Gain: '<S8>/Gain1' incorporates:
     *  Constant: '<S327>/Constant'
     *  Gain: '<S318>/Gain'
     *  Logic: '<S327>/Logical Operator'
     *  Product: '<S327>/Product'
     *  Product: '<S328>/Product'
     *  RelationalOperator: '<S329>/Compare'
     */
    rtb_Gain1_a1 = (!((rtb_fuel <= 0.0) && (claw_main_P.Constant_Value_gg != 0.0))
                    ? rtb_zeroRCSinputs[6] : 0.0) * rtb_throt_to_ff *
      claw_main_P.Gain_Gain_ly * claw_main_P.Gain1_Gain_e0;

    /* Fcn: '<S9>/beta_360' */
    rtb_beta_360 = rt_atan2_snf(rtb_uvw_rw_idx_1, rtb_uvw_rw_idx);

    /* Product: '<S334>/Product2' */
    rtb_accels_cg[0] = rtb_Sum_hl[0] / claw_main_B.mass;
    rtb_accels_cg[1] = rtb_Sum_hl[1] / claw_main_B.mass;
    rtb_accels_cg[2] = rtb_Sum_hl[2] / claw_main_B.mass;

    /* Selector: '<S351>/Value(ndx,:)' incorporates:
     *  Constant: '<S351>/Gain1'
     */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
      rtb_Valuendx_o[yOffset] = claw_main_P.Gain1_Value_a[7 * uDimIdx + (int32_T)
        rtb_FromWorkspace_g];
      yOffset++;
    }

    /* Switch: '<S349>/Switch' incorporates:
     *  Constant: '<S349>/xCG3'
     *  Constant: '<S349>/xCG5'
     */
    for (i = 0; i < 6; i++) {
      if (rtb_Sum_kw_idx >= claw_main_P.Switch_Threshold_ki) {
        rtb_Switch_h[i] = claw_main_P.xCG3_Value_l[i];
      } else {
        rtb_Switch_h[i] = claw_main_P.xCG5_Value_e[i];
      }
    }

    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_b,
      &claw_main_B.sf_EmbeddedMATLABFunction_n, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_n);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_b,
      &claw_main_B.sf_EmbeddedMATLABFunction_e, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_e);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_b,
      &claw_main_B.sf_EmbeddedMATLABFunction_e4,
      (rtP_EmbeddedMATLABFunction_claw *)
      &claw_main_P.sf_EmbeddedMATLABFunction_e4);

    /* Gain: '<S349>/Gain' */
    rtb_Gain_i1 = claw_main_P.Gain_Gain_nw * rtb_gwest_i;

    /* Reshape: '<S349>/Reshape1' incorporates:
     *  Constant: '<S349>/ixxb3'
     *  Constant: '<S352>/xCG6'
     *  Sum: '<S349>/Add1'
     */
    rtb_Reshape1_gm[0] = ((rtb_Switch_h[0] +
      claw_main_B.sf_EmbeddedMATLABFunction_n.y) + rtb_Valuendx_o[0]) +
      claw_main_P.ixxb3_Value_i[0];
    rtb_Reshape1_gm[1] = ((rtb_Switch_h[1] +
      claw_main_B.sf_EmbeddedMATLABFunction_e.y) + rtb_Valuendx_o[1]) +
      claw_main_P.ixxb3_Value_i[1];
    rtb_Reshape1_gm[2] = ((rtb_Switch_h[2] +
      claw_main_B.sf_EmbeddedMATLABFunction_e4.y) + rtb_Valuendx_o[2]) +
      claw_main_P.ixxb3_Value_i[2];
    rtb_Reshape1_gm[3] = ((rtb_Switch_h[3] + claw_main_P.xCG6_Value_c[0]) +
                          rtb_Valuendx_o[3]) + claw_main_P.ixxb3_Value_i[3];
    rtb_Reshape1_gm[4] = ((rtb_Switch_h[4] + claw_main_P.xCG6_Value_c[1]) +
                          rtb_Valuendx_o[4]) + claw_main_P.ixxb3_Value_i[4];
    rtb_Reshape1_gm[5] = ((rtb_Switch_h[5] + claw_main_P.xCG6_Value_c[2]) +
                          rtb_Valuendx_o[5]) + claw_main_P.ixxb3_Value_i[5];

    /* Constant: '<S343>/S' */
    rtb_S = claw_main_P.S_Value_o;

    /* Gain: '<S345>/Gain' */
    rtb_tratio = claw_main_P.Gain_Gain_mt * rtb_u20_p;

    /* Constant: '<S346>/Constant1' */
    rtb_Constant1 = claw_main_P.Constant1_Value_e;

    /* Switch: '<S412>/SwitchControl' incorporates:
     *  Constant: '<S346>/zero1'
     *  Constant: '<S412>/Constant'
     *  Sum: '<S346>/Add'
     */
    if (claw_main_P.Constant_Value_gwb > claw_main_P.SwitchControl_Threshold_c)
    {
      rtb_SwitchControl = rtb_LengON_k[5] + rtb_RengON_j[5];
    } else {
      rtb_SwitchControl = claw_main_P.zero1_Value_p;
    }

    /* Gain: '<S346>/sec_per_min' */
    rtb_sec_per_min = claw_main_P.sec_per_min_Gain_lf * rtb_SwitchControl;

    /* Product: '<S348>/Product2' */
    rtb_Mach = max_0 / rtb_sos;

    /* Math: '<S428>/Math Function1' */
    rtb_Rslant_d = rt_hypot_snf(rtb_Rground_i, rtb_Gain1_cg_idx);

    /* Gain: '<S425>/Gain1' incorporates:
     *  Sum: '<S425>/Sum1'
     */
    rtb_Product1_b_idx = (rtb_NE_idx - rtb_integration1_idx_0) *
      claw_main_P.Gain1_Gain_nsc;
    rtb_Gain_g_idx_4 = (rtb_NE_idx_0 - rtb_integration1_idx_1) *
      claw_main_P.Gain1_Gain_nsc;
    rtb_Gain_g_idx_3 = (rtb_delta_LLh_idx_1 - rtb_integration1_idx) *
      claw_main_P.Gain1_Gain_nsc;

    /* Gain: '<S433>/Gain1' incorporates:
     *  Math: '<S433>/Math Function'
     */
    rtb_delta_LLh_idx = rtb_Switch_idx * rtb_Switch_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch_idx_0 * rtb_Switch_idx_0;
    rtb_Switch2_idx = rtb_Switch_idx_1 * rtb_Switch_idx_1;
    rtb_Gain1_idx_0 = rtb_Switch_idx_2 * rtb_Switch_idx_2;
    for (i = 0; i < 4; i++) {
      rtb_Gain1_dd[i] = 0.0;
      rtb_Gain1_dd[i] += claw_main_P.Gain1_Gain_jp[i] * rtb_delta_LLh_idx;
      rtb_Gain1_dd[i] += claw_main_P.Gain1_Gain_jp[i + 4] * rtb_delta_LLh_idx_0;
      rtb_Gain1_dd[i] += claw_main_P.Gain1_Gain_jp[i + 8] * rtb_Switch2_idx;
      rtb_Gain1_dd[i] += claw_main_P.Gain1_Gain_jp[i + 12] * rtb_Gain1_idx_0;
    }

    /* Product: '<S433>/e1*e2' */
    rtb_e1e2_k5 = rtb_Switch_idx_0 * rtb_Switch_idx_1;

    /* Product: '<S433>/e3*e1' */
    rtb_e3e1_ak = rtb_Switch_idx_2 * rtb_Switch_idx_0;

    /* Product: '<S433>/e2*e3' */
    rtb_e2e3_eh = rtb_Switch_idx_1 * rtb_Switch_idx_2;

    /* Product: '<S433>/e0*e3' */
    rtb_e0e3_l = rtb_Switch_idx * rtb_Switch_idx_2;

    /* Product: '<S433>/e0*e2' */
    rtb_e0e2_l = rtb_Switch_idx * rtb_Switch_idx_1;

    /* Product: '<S433>/e0*e1' */
    rtb_e0e1_mp = rtb_Switch_idx * rtb_Switch_idx_0;

    /* Reshape: '<S432>/Reshape' incorporates:
     *  Gain: '<S433>/Gain'
     *  Sum: '<S433>/Sum'
     *  Sum: '<S433>/Sum1'
     */
    rtb_dircos_g[0] = rtb_Gain1_dd[1];
    rtb_dircos_g[1] = (rtb_e1e2_k5 - rtb_e0e3_l) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[2] = (rtb_e3e1_ak + rtb_e0e2_l) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[3] = (rtb_e1e2_k5 + rtb_e0e3_l) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[4] = rtb_Gain1_dd[2];
    rtb_dircos_g[5] = (rtb_e2e3_eh - rtb_e0e1_mp) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[6] = (rtb_e3e1_ak - rtb_e0e2_l) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[7] = (rtb_e2e3_eh + rtb_e0e1_mp) * claw_main_P.Gain_Gain_ps;
    rtb_dircos_g[8] = rtb_Gain1_dd[3];

    /* Product: '<S432>/Product' incorporates:
     *  UnitDelay: '<S333>/Unit Delay'
     */
    for (i = 0; i < 3; i++) {
      rtb_Product_o[i] = 0.0;
      rtb_Product_o[i] += rtb_dircos_g[i] * claw_main_DWork.UnitDelay_DSTATE_d[0];
      rtb_Product_o[i] += rtb_dircos_g[i + 3] *
        claw_main_DWork.UnitDelay_DSTATE_d[1];
      rtb_Product_o[i] += rtb_dircos_g[i + 6] *
        claw_main_DWork.UnitDelay_DSTATE_d[2];
    }

    /* Product: '<S432>/Product1' incorporates:
     *  Gain: '<S432>/g'
     *  Selector: '<S432>/dircos(:,3)'
     */
    rtb_Gain_g_idx = claw_main_P.g_Gain_mv * rtb_dircos_g[6] * claw_main_B.mass;
    rtb_Gain_g_idx_0 = claw_main_P.g_Gain_mv * rtb_dircos_g[7] *
      claw_main_B.mass;
    rtb_Gain_g_idx_1 = claw_main_P.g_Gain_mv * rtb_dircos_g[8] *
      claw_main_B.mass;

    /* Gain: '<S518>/Gain1' */
    rtb_dL_Ail_j = claw_main_P.Gain1_Gain_e2 * 0.0;

    /* Gain: '<S518>/Gain2' */
    rtb_dR_Ail_c = claw_main_P.Gain2_Gain_bp * 0.0;

    /* Sum: '<S516>/Sum3' incorporates:
     *  Constant: '<S516>/Elevator'
     *  Product: '<S516>/Product'
     */
    rtb_Sum3_i = rtb_zeroRCSinputs[4] * rtb_zeroRCSinputs[0] +
      claw_main_P.Elevator_Value_o;

    /* Gain: '<S516>/Gain6' */
    rtb_ELLOBC_k = claw_main_P.Gain6_Gain_pl * rtb_Sum3_i;

    /* Gain: '<S516>/Gain5' */
    rtb_ELLIBC_m = claw_main_P.Gain5_Gain_nu * rtb_Sum3_i;

    /* Gain: '<S516>/Gain7' */
    rtb_ELROBC_gd = claw_main_P.Gain7_Gain_o * rtb_Sum3_i;

    /* Gain: '<S516>/Gain8' */
    rtb_ELRIBC_m = claw_main_P.Gain8_Gain_os * rtb_Sum3_i;

    /* Sum: '<S516>/Sum' incorporates:
     *  Constant: '<S516>/Aileron'
     */
    rtb_Sum_fy = rtb_zeroRCSinputs[1] + claw_main_P.Aileron_Value_j;

    /* Gain: '<S516>/Gain1' */
    rtb_AILLC_j = claw_main_P.Gain1_Gain_i4 * rtb_Sum_fy;

    /* Gain: '<S516>/Gain2' */
    rtb_AILRC_m = claw_main_P.Gain2_Gain_kj * rtb_Sum_fy;

    /* Sum: '<S516>/Sum2' incorporates:
     *  Constant: '<S516>/Rudder'
     */
    rtb_Sum2_p0 = rtb_zeroRCSinputs[2] + claw_main_P.Rudder_Value_n;

    /* Gain: '<S516>/Gain3' */
    rtb_RUDUPC_f = claw_main_P.Gain3_Gain_go * rtb_Sum2_p0;

    /* Gain: '<S516>/Gain4' */
    rtb_RUDLOC_c = claw_main_P.Gain4_Gain_l * rtb_Sum2_p0;

    /* Lookup Block: '<S516>/Left Roll Spoiler Schedule'
     * About '<S516>/Left Roll Spoiler Schedule :'
     * Lookup Block: '<S516>/Left Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_LeftRollSpoilerSchedule_d),
                         claw_main_P.LeftRollSpoilerSchedule_YData_g,
                         claw_main_P.Constant_Value_m3,
                         claw_main_P.LeftRollSpoilerSchedule_XData_a, 6U);

    /* Gain: '<S516>/Gain12' */
    rtb_SPLLIBC_i = claw_main_P.Gain12_Gain_hy * rtb_LeftRollSpoilerSchedule_d;

    /* Gain: '<S516>/Gain13' */
    rtb_SPLLOBC_i = claw_main_P.Gain13_Gain_m * rtb_LeftRollSpoilerSchedule_d;

    /* Lookup Block: '<S516>/Right Roll Spoiler Schedule'
     * About '<S516>/Right Roll Spoiler Schedule :'
     * Lookup Block: '<S516>/Right Roll Spoiler Schedule'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_RightRollSpoilerSchedule_k),
                         claw_main_P.RightRollSpoilerSchedule_YDat_k,
                         claw_main_P.Constant_Value_m3,
                         claw_main_P.RightRollSpoilerSchedule_XDat_k, 6U);

    /* Sum: '<S516>/Sum4' incorporates:
     *  Constant: '<S516>/Constant2'
     *  Constant: '<S516>/Flaps'
     */
    rtb_Sum4_kd = claw_main_P.Constant2_Value_n0 + claw_main_P.Flaps_Value_a;

    /* Gain: '<S516>/Gain20' incorporates:
     *  Constant: '<S516>/Gear'
     */
    rtb_GEARC_e = claw_main_P.Gain20_Gain_d * claw_main_P.Gear_Value_i;

    /* Sum: '<S515>/Sum' incorporates:
     *  Constant: '<S515>/Gear1'
     *  Constant: '<S516>/Constant3'
     *  Gain: '<S516>/Gain10'
     *  Gain: '<S516>/Gain11'
     *  Gain: '<S516>/Gain14'
     *  Gain: '<S516>/Gain15'
     *  Gain: '<S516>/Gain16'
     *  Gain: '<S516>/Gain17'
     *  Gain: '<S516>/Gain18'
     *  Gain: '<S516>/Gain21'
     *  Gain: '<S516>/Gain22'
     *  Gain: '<S516>/Gain9'
     *  Saturate: '<S515>/Brake'
     *  Saturate: '<S515>/Gear'
     *  SignalConversion: '<S418>/TmpHiddenBufferAtGain22Inport1'
     *  Sum: '<S515>/Sum3'
     */
    rtb_orderatts_i_idx = claw_main_P.Gain14_Gain_g *
      rtb_RightRollSpoilerSchedule_k;
    rtb_Switch_d_idx_0 = claw_main_P.Gain11_Gain_m *
      rtb_RightRollSpoilerSchedule_k;
    rtb_Switch_d_idx = claw_main_P.Gain16_Gain_m * rtb_Sum4_kd;
    rtb_Sum_ow_idx = claw_main_P.Gain17_Gain_j * rtb_Sum4_kd;
    rtb_Sum_ow_idx_0 = claw_main_P.Gain18_Gain_l * rtb_Sum4_kd;
    rtb_Sum_ow_idx_1 = claw_main_P.Gain15_Gain_h * rtb_Sum4_kd;
    rtb_Switch_d_idx_1 = rtb_zeroRCSinputs[3] + claw_main_P.Gear1_Value_k;
    rtb_Gain_g_idx_2 = rt_SATURATE(rtb_GEARC_e, claw_main_P.Gear_LowerSat_p,
      claw_main_P.Gear_UpperSat_d);
    rtb_delta_LLh_idx = (claw_main_P.Gain22_Gain_o[0] * rtb_zeroRCSinputs[6] +
                         claw_main_P.Gain22_Gain_o[2] * rtb_zeroRCSinputs[5]) *
      claw_main_P.Gain9_Gain_m;
    rtb_delta_LLh_idx_0 = (claw_main_P.Gain22_Gain_o[1] * rtb_zeroRCSinputs[6] +
      claw_main_P.Gain22_Gain_o[3] * rtb_zeroRCSinputs[5]) *
      claw_main_P.Gain10_Gain_f;

    /* Polyval: '<S513>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref_c = ((claw_main_P.Throttle_2_RPMref_coefs_e[0] *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_e[1]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_e[2]) *
      rtb_delta_LLh_idx + claw_main_P.Throttle_2_RPMref_coefs_e[3];

    /* Polyval: '<S513>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust_n = ((claw_main_P.RPMref_2_Thrust_coefs_m0[0] *
      rtb_Throttle_2_RPMref_c + claw_main_P.RPMref_2_Thrust_coefs_m0[1]) *
      rtb_Throttle_2_RPMref_c + claw_main_P.RPMref_2_Thrust_coefs_m0[2]) *
      rtb_Throttle_2_RPMref_c + claw_main_P.RPMref_2_Thrust_coefs_m0[3];

    /* Gain: '<S443>/Gain1' */
    rtb_pratio_a = claw_main_P.Gain1_Gain_n5m * rtb_P;

    /* Gain: '<S513>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM_fb = claw_main_P.UnScale_Ref_RPM_Gain_pv *
      rtb_Throttle_2_RPMref_c;

    /* Gain: '<S513>/angular momentum' */
    rtb_angularmomentum_a = claw_main_P.angularmomentum_Gain_p *
      rtb_UnScale_Ref_RPM_fb;

    /* Polyval: '<S513>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow_e = claw_main_P.RPMref_2_FuelFlow_coefs_c0[0];
    rtb_RPMref_2_FuelFlow_e = rtb_RPMref_2_FuelFlow_e * rtb_Throttle_2_RPMref_c
      + claw_main_P.RPMref_2_FuelFlow_coefs_c0[1];
    rtb_RPMref_2_FuelFlow_e = rtb_RPMref_2_FuelFlow_e * rtb_Throttle_2_RPMref_c
      + claw_main_P.RPMref_2_FuelFlow_coefs_c0[2];

    /* Lookup Block: '<S513>/Fuel Pump Voltage'
     * About '<S513>/Fuel Pump Voltage :'
     * Lookup Block: '<S513>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_p),
                         claw_main_P.FuelPumpVoltage_YData_i,
                         rtb_RPMref_2_FuelFlow_e,
                         claw_main_P.FuelPumpVoltage_XData_bp, 25U);

    /* Gain: '<S444>/LengON' incorporates:
     *  Polyval: '<S513>/RPMref_2_EGT'
     *  Product: '<S513>/Product2'
     */
    rtb_LengON_j[0] = rtb_RPMref_2_Thrust_n * rtb_pratio_a *
      claw_main_P.LengON_Gain_n;
    rtb_LengON_j[1] = claw_main_P.LengON_Gain_n * rtb_UnScale_Ref_RPM_fb;
    rtb_LengON_j[2] = claw_main_P.LengON_Gain_n * rtb_angularmomentum_a;
    rtb_LengON_j[3] = claw_main_P.LengON_Gain_n * rtb_FuelPumpVoltage_p;
    rtb_LengON_j[4] = ((((claw_main_P.RPMref_2_EGT_coefs_dm[0] *
                          rtb_Throttle_2_RPMref_c +
                          claw_main_P.RPMref_2_EGT_coefs_dm[1]) *
                         rtb_Throttle_2_RPMref_c +
                         claw_main_P.RPMref_2_EGT_coefs_dm[2]) *
                        rtb_Throttle_2_RPMref_c +
                        claw_main_P.RPMref_2_EGT_coefs_dm[3]) *
                       rtb_Throttle_2_RPMref_c +
                       claw_main_P.RPMref_2_EGT_coefs_dm[4]) *
      claw_main_P.LengON_Gain_n;
    rtb_LengON_j[5] = claw_main_P.LengON_Gain_n * rtb_RPMref_2_FuelFlow_e;

    /* Polyval: '<S514>/Throttle_2_RPMref' */
    rtb_Throttle_2_RPMref_cj = ((claw_main_P.Throttle_2_RPMref_coefs_l[0] *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_l[1]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_l[2]) *
      rtb_delta_LLh_idx_0 + claw_main_P.Throttle_2_RPMref_coefs_l[3];

    /* Polyval: '<S514>/RPMref_2_Thrust' */
    rtb_RPMref_2_Thrust_ny = ((claw_main_P.RPMref_2_Thrust_coefs_oe[0] *
      rtb_Throttle_2_RPMref_cj + claw_main_P.RPMref_2_Thrust_coefs_oe[1]) *
      rtb_Throttle_2_RPMref_cj + claw_main_P.RPMref_2_Thrust_coefs_oe[2]) *
      rtb_Throttle_2_RPMref_cj + claw_main_P.RPMref_2_Thrust_coefs_oe[3];

    /* Gain: '<S514>/UnScale_Ref_RPM' */
    rtb_UnScale_Ref_RPM_k = claw_main_P.UnScale_Ref_RPM_Gain_mx *
      rtb_Throttle_2_RPMref_cj;

    /* Gain: '<S514>/angular momentum' */
    rtb_angularmomentum_aj = claw_main_P.angularmomentum_Gain_py *
      rtb_UnScale_Ref_RPM_k;

    /* Polyval: '<S514>/RPMref_2_FuelFlow' */
    rtb_RPMref_2_FuelFlow_j = claw_main_P.RPMref_2_FuelFlow_coefs_p[0];
    rtb_RPMref_2_FuelFlow_j = rtb_RPMref_2_FuelFlow_j * rtb_Throttle_2_RPMref_cj
      + claw_main_P.RPMref_2_FuelFlow_coefs_p[1];
    rtb_RPMref_2_FuelFlow_j = rtb_RPMref_2_FuelFlow_j * rtb_Throttle_2_RPMref_cj
      + claw_main_P.RPMref_2_FuelFlow_coefs_p[2];

    /* Lookup Block: '<S514>/Fuel Pump Voltage'
     * About '<S514>/Fuel Pump Voltage :'
     * Lookup Block: '<S514>/Fuel Pump Voltage'
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0


     */
    LookUp_real_T_real_T( &(rtb_FuelPumpVoltage_k),
                         claw_main_P.FuelPumpVoltage_YData_j,
                         rtb_RPMref_2_FuelFlow_j,
                         claw_main_P.FuelPumpVoltage_XData_cx, 25U);

    /* Gain: '<S444>/RengON' incorporates:
     *  Polyval: '<S514>/RPMref_2_EGT'
     *  Product: '<S514>/Product2'
     */
    rtb_RengON_m[0] = rtb_RPMref_2_Thrust_ny * rtb_pratio_a *
      claw_main_P.RengON_Gain_f;
    rtb_RengON_m[1] = claw_main_P.RengON_Gain_f * rtb_UnScale_Ref_RPM_k;
    rtb_RengON_m[2] = claw_main_P.RengON_Gain_f * rtb_angularmomentum_aj;
    rtb_RengON_m[3] = claw_main_P.RengON_Gain_f * rtb_FuelPumpVoltage_k;
    rtb_RengON_m[4] = ((((claw_main_P.RPMref_2_EGT_coefs_o4[0] *
                          rtb_Throttle_2_RPMref_cj +
                          claw_main_P.RPMref_2_EGT_coefs_o4[1]) *
                         rtb_Throttle_2_RPMref_cj +
                         claw_main_P.RPMref_2_EGT_coefs_o4[2]) *
                        rtb_Throttle_2_RPMref_cj +
                        claw_main_P.RPMref_2_EGT_coefs_o4[3]) *
                       rtb_Throttle_2_RPMref_cj +
                       claw_main_P.RPMref_2_EGT_coefs_o4[4]) *
      claw_main_P.RengON_Gain_f;
    rtb_RengON_m[5] = claw_main_P.RengON_Gain_f * rtb_RPMref_2_FuelFlow_j;
    claw_main_EngineAlignment(rtb_LengON_j[0], rtb_LengON_j[2], rtb_RengON_m[0],
      rtb_RengON_m[2], &claw_main_B.sf_EngineAlignment_d,
      (rtP_EngineAlignment_claw_main *) &claw_main_P.sf_EngineAlignment_d);

    /* FromWorkspace: '<S448>/From Workspace' */
    {
      real_T t = ((claw_main_M->Timing.clockTick0) * 0.01);
      real_T *pTimeValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_h.TimePtr;
      real_T *pDataValues = (real_T *)
        claw_main_DWork.FromWorkspace_PWORK_h.DataPtr;
      if (t < pTimeValues[0]) {
        rtb_FromWorkspace_c = 0.0;
      } else if (t >= pTimeValues[1]) {
        rtb_FromWorkspace_c = pDataValues[1];
      } else {
        int_T currTimeIndex = claw_main_DWork.FromWorkspace_IWORK_c.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        rtb_FromWorkspace_c = pDataValues[currTimeIndex];
        claw_main_DWork.FromWorkspace_IWORK_c.PrevIndex = currTimeIndex;
      }
    }

    /* Selector: '<S451>/Value(ndx,:)1' incorporates:
     *  Constant: '<S451>/Gain2'
     */
    rtb_delta_LLh_idx = claw_main_P.Gain2_Value_bz[(int32_T)rtb_FromWorkspace_c];
    rtb_Switch2_idx = claw_main_P.Gain2_Value_bz[7 + (int32_T)
      rtb_FromWorkspace_c];
    rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain2_Value_bz[14 + (int32_T)
      rtb_FromWorkspace_c];

    /* Sum: '<S447>/Add' incorporates:
     *  Constant: '<S444>/zero2'
     *  Constant: '<S447>/ixxb7'
     *  Constant: '<S451>/Gain1'
     *  Selector: '<S451>/Value(ndx,:)'
     *  Sum: '<S447>/Add3'
     */
    rtb_gwest_ia = (claw_main_P.ixxb7_Value_a - claw_main_P.zero2_Value_o) +
      claw_main_P.Gain1_Value_c[(int32_T)rtb_FromWorkspace_c];
    claw_main_fuelcgshiftcg_pos0(claw_main_P.zero2_Value_o,
      &claw_main_B.sf_fuelcgshiftcg_pos0_l, (rtP_fuelcgshiftcg_pos0_claw_mai *)
      &claw_main_P.sf_fuelcgshiftcg_pos0_l);

    /* Switch: '<S447>/Switch1' incorporates:
     *  Constant: '<S447>/xCG1'
     *  Constant: '<S447>/xCG4'
     */
    if (rtb_Gain_g_idx_2 >= claw_main_P.Switch1_Threshold_cn) {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG4_Value_l[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG4_Value_l[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG4_Value_l[2];
    } else {
      rtb_delta_LLh_idx_0 = claw_main_P.xCG1_Value_p[0];
      rtb_Gain1_idx_0 = claw_main_P.xCG1_Value_p[1];
      rtb_InterpolationnDusingPreLo_5 = claw_main_P.xCG1_Value_p[2];
    }

    /* Sum: '<S447>/Add2' incorporates:
     *  Product: '<S447>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_ia * claw_main_B.sf_fuelcgshiftcg_pos0_l.y[0]
                    + rtb_delta_LLh_idx) + rtb_delta_LLh_idx_0;

    /* Sum: '<S506>/Sum6' incorporates:
     *  Constant: '<S441>/ixxb6'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_n[0] - rtb_Add2_idx;

    /* Gain: '<S512>/Gain' */
    rtb_Gain1_idx = claw_main_P.Gain_Gain_mqu * rtb_Gain1_idx_1;

    /* Sum: '<S506>/Sum7' incorporates:
     *  Constant: '<S441>/ixxb5'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_n[0] - rtb_Add2_idx;

    /* Gain: '<S511>/Gain' */
    rtb_UnitDelay_nf_idx_0 = claw_main_P.Gain_Gain_i4r *
      rtb_MultiportSwitch2_idx_2;
    rtb_UnitDelay_nf_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_0 = rtb_Add2_idx;
    rtb_InterpolationnDusingPreLo_3 = rtb_Gain1_idx_1;

    /* Sum: '<S447>/Add2' incorporates:
     *  Product: '<S447>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_ia * claw_main_B.sf_fuelcgshiftcg_pos0_l.y[1]
                    + rtb_Switch2_idx) + rtb_Gain1_idx_0;

    /* Sum: '<S506>/Sum6' incorporates:
     *  Constant: '<S441>/ixxb6'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_n[1] - rtb_Add2_idx;

    /* Gain: '<S512>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_mqu * rtb_Gain1_idx_1;

    /* Sum: '<S506>/Sum7' incorporates:
     *  Constant: '<S441>/ixxb5'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_n[1] - rtb_Add2_idx;

    /* Gain: '<S511>/Gain' */
    rtb_delta_LLh_idx_0 = claw_main_P.Gain_Gain_i4r * rtb_MultiportSwitch2_idx_2;
    rtb_Switch2_idx = rtb_MultiportSwitch2_idx_2;
    rtb_Add2_idx_1 = rtb_Add2_idx;
    rtb_Gain1_idx_0 = rtb_Gain1_idx_1;

    /* Sum: '<S447>/Add2' incorporates:
     *  Product: '<S447>/Divide1'
     */
    rtb_Add2_idx = (1.0 / rtb_gwest_ia * claw_main_B.sf_fuelcgshiftcg_pos0_l.y[2]
                    + rtb_InterpolationnDusingPreLo_4) +
      rtb_InterpolationnDusingPreLo_5;

    /* Sum: '<S506>/Sum6' incorporates:
     *  Constant: '<S441>/ixxb6'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Gain1_idx_1 = claw_main_P.ixxb6_Value_n[2] - rtb_Add2_idx;

    /* Sum: '<S506>/Sum7' incorporates:
     *  Constant: '<S441>/ixxb5'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_MultiportSwitch2_idx_2 = claw_main_P.ixxb5_Value_n[2] - rtb_Add2_idx;

    /* Sum: '<S506>/Sum1' incorporates:
     *  Gain: '<S511>/Gain'
     *  Gain: '<S512>/Gain'
     *  Product: '<S511>/Product'
     *  Product: '<S512>/Product'
     *  Reshape: '<S511>/Reshape'
     *  Reshape: '<S512>/Reshape'
     */
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_mqu * rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_InterpolationnDusingPreLo_3;
    rtb_Gain1_oy_0[6] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx;
    rtb_Gain1_oy_0[8] = 0.0;
    rtb_Sum4_j_0[0] = 0.0;
    rtb_Sum4_j_0[1] = rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[2] = rtb_delta_LLh_idx_0;
    rtb_Sum4_j_0[3] = claw_main_P.Gain_Gain_i4r * rtb_MultiportSwitch2_idx_2;
    rtb_Sum4_j_0[4] = 0.0;
    rtb_Sum4_j_0[5] = rtb_UnitDelay_nf_idx;
    rtb_Sum4_j_0[6] = rtb_Switch2_idx;
    rtb_Sum4_j_0[7] = rtb_UnitDelay_nf_idx_0;
    rtb_Sum4_j_0[8] = 0.0;

    /* Product: '<S505>/Product' incorporates:
     *  Gain: '<S505>/Gain'
     *  Reshape: '<S505>/Reshape'
     */
    rtb_MultiportSwitch_cn_0[0] = 0.0;
    rtb_MultiportSwitch_cn_0[1] = rtb_sensors[2];
    rtb_MultiportSwitch_cn_0[2] = claw_main_P.Gain_Gain_gef * rtb_sensors[1];
    rtb_MultiportSwitch_cn_0[3] = claw_main_P.Gain_Gain_gef * rtb_sensors[2];
    rtb_MultiportSwitch_cn_0[4] = 0.0;
    rtb_MultiportSwitch_cn_0[5] = rtb_sensors[0];
    rtb_MultiportSwitch_cn_0[6] = rtb_sensors[1];
    rtb_MultiportSwitch_cn_0[7] = claw_main_P.Gain_Gain_gef * rtb_sensors[0];
    rtb_MultiportSwitch_cn_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] *
        claw_main_B.sf_EngineAlignment_d.TL[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] *
        claw_main_B.sf_EngineAlignment_d.TL[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] *
        claw_main_B.sf_EngineAlignment_d.TL[2];
      rtb_Gain_e_0[i] = 0.0;
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i] * claw_main_B.sf_EngineAlignment_d.TR[0];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 3] *
        claw_main_B.sf_EngineAlignment_d.TR[1];
      rtb_Gain_e_0[i] += rtb_Sum4_j_0[i + 6] *
        claw_main_B.sf_EngineAlignment_d.TR[2];
      rtb_Product_ih[i] = 0.0;
      rtb_Product_ih[i] += rtb_MultiportSwitch_cn_0[i] *
        claw_main_B.sf_EngineAlignment_d.H[0];
      rtb_Product_ih[i] += rtb_MultiportSwitch_cn_0[i + 3] *
        claw_main_B.sf_EngineAlignment_d.H[1];
      rtb_Product_ih[i] += rtb_MultiportSwitch_cn_0[i + 6] *
        claw_main_B.sf_EngineAlignment_d.H[2];

      /* Sum: '<S432>/Sum1' */
      rtb_uvw_rw_at[i] = rtb_uvw[i] + rtb_Product_o[i];
    }

    /* Gain: '<S443>/Gain2' incorporates:
     *  Trigonometry: '<S519>/Trigonometric Function2'
     */
    claw_main_B.alpha_l = claw_main_P.Gain2_Gain_p * rt_atan2_snf(rtb_uvw_rw_at
      [2], rtb_uvw_rw_at[0]);

    /* PreLookup: '<S459>/AlphaLookup' */
    rtb_AlphaLookup_o1_h = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.AlphaLookup_BreakpointsData_p[0], 31U, &rtb_AlphaLookup_o2_j,
      &claw_main_DWork.AlphaLookup_DWORK1_h);

    /* Math: '<S519>/Math Function' */
    rtb_MathFunction_nk = rt_hypot_snf(rtb_uvw_rw_at[0], rtb_uvw_rw_at[2]);

    /* Gain: '<S443>/Gain3' incorporates:
     *  Trigonometry: '<S519>/Trigonometric Function1'
     */
    claw_main_B.beta_d = claw_main_P.Gain3_Gain_bh * rt_atan2_snf(rtb_uvw_rw_at
      [1], rtb_MathFunction_nk);

    /* PreLookup: '<S459>/AlphaLookup1' */
    rtb_AlphaLookup1_o1_n = plook_linxp(claw_main_B.beta_d,
      &claw_main_P.AlphaLookup1_BreakpointsData_e[0], 26U,
      &rtb_AlphaLookup1_o2_c, &claw_main_DWork.AlphaLookup1_DWORK1_h);

    /* Interpolation_n-D: '<S459>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S459>/Constant1'
     */
    max_1 = rtb_AlphaLookup_o2_j;
    frac_t[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2_c;
    frac_t[1] = max_1;
    bpIndex_t[0] = rtb_AlphaLookup_o1_h;
    bpIndex_t[1] = rtb_AlphaLookup1_o1_n;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_ff[scalarIndex];
      if (claw_main_P.Constant1_Value_ff[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_t[2] = locIndex;
      locIndex = 864U * bpIndex_t[2U];
      rtb_InterpolationUsingPrelook_o[scalarIndex] = intrp2d_lx(&bpIndex_t[0U],
        &frac_t[0U], &claw_main_P.InterpolationUsingPrelookup_T_l[locIndex], 32U);
    }

    /* Interpolation_n-D: '<S459>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S459>/Constant2'
     */
    max_1 = rtb_AlphaLookup_o2_j;
    frac_u[0] = max_1;
    max_1 = rtb_AlphaLookup1_o2_c;
    frac_u[1] = max_1;
    bpIndex_u[0] = rtb_AlphaLookup_o1_h;
    bpIndex_u[1] = rtb_AlphaLookup1_o1_n;
    locIndex = claw_main_P.Constant2_Value_pe[0];
    if (claw_main_P.Constant2_Value_pe[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_u[2] = locIndex;
    locIndex = 864U * bpIndex_u[2U];
    rtb_delta_LLh_idx = intrp2d_lx(&bpIndex_u[0U], &frac_u[0U],
      &claw_main_P.InterpolationUsingPrelookup1__m[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_pe[1];
    if (claw_main_P.Constant2_Value_pe[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_u[2] = locIndex;
    locIndex = 864U * bpIndex_u[2U];
    rtb_delta_LLh_idx_0 = intrp2d_lx(&bpIndex_u[0U], &frac_u[0U],
      &claw_main_P.InterpolationUsingPrelookup1__m[locIndex], 32U);
    locIndex = claw_main_P.Constant2_Value_pe[2];
    if (claw_main_P.Constant2_Value_pe[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_u[2] = locIndex;
    locIndex = 864U * bpIndex_u[2U];
    rtb_Switch2_idx = intrp2d_lx(&bpIndex_u[0U], &frac_u[0U],
      &claw_main_P.InterpolationUsingPrelookup1__m[locIndex], 32U);

    /* Switch: '<S459>/Switch' incorporates:
     *  Constant: '<S442>/symmetry_on'
     *  Constant: '<S459>/Constant3'
     */
    if (claw_main_P.symmetry_on_Value_k != 0.0) {
      /* Assignment: '<S459>/Assignment to  Lateral' incorporates:
       *  Constant: '<S459>/Constant'
       */
      for (i = 0; i < 6; i++) {
        rtb_AssignmenttoLateral_m[i] = claw_main_P.Constant_Value_a[i];
      }

      rtb_AssignmenttoLateral_m[1] = rtb_delta_LLh_idx;
      rtb_AssignmenttoLateral_m[3] = rtb_delta_LLh_idx_0;
      rtb_AssignmenttoLateral_m[5] = rtb_Switch2_idx;
      for (i = 0; i < 6; i++) {
        rtb_Switch_be[i] = rtb_AssignmenttoLateral_m[i];
      }
    } else {
      for (i = 0; i < 6; i++) {
        rtb_Switch_be[i] = claw_main_P.Constant3_Value_c[i];
      }
    }

    /* DataTypeConversion: '<S459>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace_c;
    if ((rtb_FromWorkspace_c < 4.5035996273704960E+015) && (rtb_FromWorkspace_c >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace_c + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace_c) || rtIsInf(rtb_FromWorkspace_c)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_o = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S464>/Switch Case' incorporates:
     *  ActionPort: '<S465>/Action Port'
     *  ActionPort: '<S466>/Action Port'
     *  SubSystem: '<S464>/Switch Case Action Subsystem'
     *  SubSystem: '<S464>/Switch Case Action Subsystem2'
     */
    switch (rtb_DataTypeConversion_o) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      claw__SwitchCaseActionSubsystem(claw_main_B.alpha_l, claw_main_B.beta_d,
        rtb_DataTypeConversion_o, claw_main_B.Merge_da,
        &claw_main_DWork.SwitchCaseActionSubsystem_ot,
        (rtP_SwitchCaseActionSubsystem_c *)
        &claw_main_P.SwitchCaseActionSubsystem_ot);
      break;

     default:
      /* Constant: '<S466>/Constant4' */
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_da[i] = claw_main_P.Constant4_Value_cp[i];
      }
      break;
    }

    /* Sum: '<S459>/Add' */
    for (i = 0; i < 6; i++) {
      rtb_Add_c[i] = (rtb_InterpolationUsingPrelook_o[i] + rtb_Switch_be[i]) +
        claw_main_B.Merge_da[i];
    }

    /* PreLookup: '<S489>/Prelookup' */
    rtb_Prelookup_o1_cp = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup_BreakpointsData_o[0], 31U, &rtb_Prelookup_o2_gl,
      &claw_main_DWork.Prelookup_DWORK1_f);

    /* Switch: '<S489>/Switch' incorporates:
     *  Constant: '<S489>/Constant'
     *  Constant: '<S489>/Constant1'
     */
    if (rtb_RUDUPC_f >= claw_main_P.Switch_Threshold_hz) {
      rtb_Switch_i = claw_main_P.Constant_Value_k;
    } else {
      rtb_Switch_i = claw_main_P.Constant1_Value_kq;
    }

    /* PreLookup: '<S489>/Prelookup1' incorporates:
     *  Product: '<S489>/Product1'
     */
    rtb_Prelookup1_o1_f = plook_linxp(claw_main_B.beta_d * rtb_Switch_i,
      &claw_main_P.Prelookup1_BreakpointsData_e2[0], 26U, &rtb_Prelookup1_o2_d,
      &claw_main_DWork.Prelookup1_DWORK1_b);

    /* PreLookup: '<S489>/Prelookup2' incorporates:
     *  Abs: '<S489>/Abs'
     *  Gain: '<S489>/Gain'
     */
    rtb_Prelookup2_o1_ml = plook_linxp(claw_main_P.Gain_Gain_jm * fabs
      (rtb_RUDUPC_f), &claw_main_P.Prelookup2_BreakpointsData_gp[0], 3U,
      &rtb_Prelookup2_o2_h1, &claw_main_DWork.Prelookup2_DWORK1_fn);

    /* Interpolation_n-D: '<S489>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S489>/Constant2'
     */
    max_1 = rtb_Prelookup_o2_gl;
    frac_v[0] = max_1;
    max_1 = rtb_Prelookup1_o2_d;
    frac_v[1] = max_1;
    max_1 = rtb_Prelookup2_o2_h1;
    frac_v[2] = max_1;
    bpIndex_v[0] = rtb_Prelookup_o1_cp;
    bpIndex_v[1] = rtb_Prelookup1_o1_f;
    bpIndex_v[2] = rtb_Prelookup2_o1_ml;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_hp[scalarIndex];
      if (claw_main_P.Constant2_Value_hp[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_v[3] = locIndex;
      locIndex = 3456U * bpIndex_v[3U];
      rtb_InterpolationUsingPreloo_cv[scalarIndex] = intrp3d_lx(&bpIndex_v[0U],
        &frac_v[0U], &claw_main_P.InterpolationUsingPrelookup__o5[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__ny[0]);
    }

    /* Assignment: '<S489>/Assignment to lateral' incorporates:
     *  Constant: '<S489>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral_l[i] = claw_main_P.Constant3_Value_ml[i];
    }

    rtb_Assignmenttolateral_l[1] = rtb_Switch_i;
    rtb_Assignmenttolateral_l[3] = rtb_Switch_i;
    rtb_Assignmenttolateral_l[5] = rtb_Switch_i;

    /* Product: '<S486>/Product' incorporates:
     *  Constant: '<S486>/gains'
     *  Product: '<S489>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_pp[i] = rtb_InterpolationUsingPreloo_cv[i] *
        rtb_Assignmenttolateral_l[i] * claw_main_P.gains_Value_ei[i];
    }

    /* PreLookup: '<S488>/Prelookup' */
    rtb_Prelookup_o1_a = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup_BreakpointsData_c[0], 31U, &rtb_Prelookup_o2_o,
      &claw_main_DWork.Prelookup_DWORK1_px);

    /* Switch: '<S488>/Switch' incorporates:
     *  Constant: '<S488>/Constant'
     *  Constant: '<S488>/Constant1'
     */
    if (rtb_RUDLOC_c >= claw_main_P.Switch_Threshold_bx) {
      rtb_Switch_c5 = claw_main_P.Constant_Value_m1;
    } else {
      rtb_Switch_c5 = claw_main_P.Constant1_Value_i;
    }

    /* PreLookup: '<S488>/Prelookup1' incorporates:
     *  Product: '<S488>/Product1'
     */
    rtb_Prelookup1_o1_c = plook_linxp(claw_main_B.beta_d * rtb_Switch_c5,
      &claw_main_P.Prelookup1_BreakpointsData_o3[0], 26U, &rtb_Prelookup1_o2_a,
      &claw_main_DWork.Prelookup1_DWORK1_ge);

    /* PreLookup: '<S488>/Prelookup2' incorporates:
     *  Abs: '<S488>/Abs'
     *  Gain: '<S488>/Gain'
     */
    rtb_Prelookup2_o1_j2 = plook_linxp(claw_main_P.Gain_Gain_cz * fabs
      (rtb_RUDLOC_c), &claw_main_P.Prelookup2_BreakpointsData_mn[0], 3U,
      &rtb_Prelookup2_o2_e, &claw_main_DWork.Prelookup2_DWORK1_a);

    /* Interpolation_n-D: '<S488>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S488>/Constant2'
     */
    max_1 = rtb_Prelookup_o2_o;
    frac_w[0] = max_1;
    max_1 = rtb_Prelookup1_o2_a;
    frac_w[1] = max_1;
    max_1 = rtb_Prelookup2_o2_e;
    frac_w[2] = max_1;
    bpIndex_w[0] = rtb_Prelookup_o1_a;
    bpIndex_w[1] = rtb_Prelookup1_o1_c;
    bpIndex_w[2] = rtb_Prelookup2_o1_j2;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant2_Value_dp[scalarIndex];
      if (claw_main_P.Constant2_Value_dp[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_w[3] = locIndex;
      locIndex = 3456U * bpIndex_w[3U];
      rtb_InterpolationUsingPreloo_dx[scalarIndex] = intrp3d_lx(&bpIndex_w[0U],
        &frac_w[0U], &claw_main_P.InterpolationUsingPrelookup__d3[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__fl[0]);
    }

    /* Assignment: '<S488>/Assignment to lateral' incorporates:
     *  Constant: '<S488>/Constant3'
     */
    for (i = 0; i < 6; i++) {
      rtb_Assignmenttolateral_lz[i] = claw_main_P.Constant3_Value_ec[i];
    }

    rtb_Assignmenttolateral_lz[1] = rtb_Switch_c5;
    rtb_Assignmenttolateral_lz[3] = rtb_Switch_c5;
    rtb_Assignmenttolateral_lz[5] = rtb_Switch_c5;

    /* Product: '<S487>/Product' incorporates:
     *  Constant: '<S487>/gains'
     *  Product: '<S488>/Product2'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_oq[i] = rtb_InterpolationUsingPreloo_dx[i] *
        rtb_Assignmenttolateral_lz[i] * claw_main_P.gains_Value_es[i];
    }

    /* PreLookup: '<S468>/Prelookup1' */
    rtb_Prelookup1_o1_k = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup1_BreakpointsData_ao[0], 31U, &rtb_Prelookup1_o2_iq,
      &claw_main_DWork.Prelookup1_DWORK1_g2);

    /* PreLookup: '<S468>/Prelookup2' incorporates:
     *  Gain: '<S468>/Gain2'
     */
    rtb_Prelookup2_o1_nh = plook_linxp(claw_main_P.Gain2_Gain_cd *
      claw_main_B.beta_d, &claw_main_P.Prelookup2_BreakpointsData_l[0], 26U,
      &rtb_Prelookup2_o2_f, &claw_main_DWork.Prelookup2_DWORK1_b1);

    /* PreLookup: '<S468>/Prelookup3' */
    rtb_Prelookup3_o1_n = plook_linxp(rtb_dL_Ail_j + rtb_AILLC_j,
      &claw_main_P.Prelookup3_BreakpointsData_l3[0], 6U, &rtb_Prelookup3_o2_c,
      &claw_main_DWork.Prelookup3_DWORK1_f);

    /* Interpolation_n-D: '<S468>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S468>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_iq;
    frac_x[0] = max_1;
    max_1 = rtb_Prelookup2_o2_f;
    frac_x[1] = max_1;
    max_1 = rtb_Prelookup3_o2_c;
    frac_x[2] = max_1;
    bpIndex_x[0] = rtb_Prelookup1_o1_k;
    bpIndex_x[1] = rtb_Prelookup2_o1_nh;
    bpIndex_x[2] = rtb_Prelookup3_o1_n;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_ei[scalarIndex];
      if (claw_main_P.Constant3_Value_ei[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_x[3] = locIndex;
      locIndex = 6048U * bpIndex_x[3U];
      rtb_InterpolationUsingPrelook_p[scalarIndex] = intrp3d_lx(&bpIndex_x[0U],
        &frac_x[0U], &claw_main_P.InterpolationUsingPrelookup__ee[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__h2[0]);
    }

    /* Gain: '<S468>/Negate Lateral' */
    for (i = 0; i < 6; i++) {
      rtb_NegateLateral_o[i] = claw_main_P.NegateLateral_Gain_fe[i] *
        rtb_InterpolationUsingPrelook_p[i];
    }

    /* PreLookup: '<S468>/Prelookup4' */
    rtb_Prelookup4_o1_dz = plook_linxp(claw_main_B.beta_d,
      &claw_main_P.Prelookup4_BreakpointsData_n2[0], 26U, &rtb_Prelookup4_o2_g,
      &claw_main_DWork.Prelookup4_DWORK1_p);

    /* PreLookup: '<S468>/Prelookup5' */
    rtb_Prelookup5_o1_d = plook_linxp(rtb_dR_Ail_c + rtb_AILRC_m,
      &claw_main_P.Prelookup5_BreakpointsData_kk[0], 6U, &rtb_Prelookup5_o2_n,
      &claw_main_DWork.Prelookup5_DWORK1_i);

    /* Interpolation_n-D: '<S468>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S468>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_iq;
    frac_y[0] = max_1;
    max_1 = rtb_Prelookup4_o2_g;
    frac_y[1] = max_1;
    max_1 = rtb_Prelookup5_o2_n;
    frac_y[2] = max_1;
    bpIndex_y[0] = rtb_Prelookup1_o1_k;
    bpIndex_y[1] = rtb_Prelookup4_o1_dz;
    bpIndex_y[2] = rtb_Prelookup5_o1_d;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_dh[scalarIndex];
      if (claw_main_P.Constant1_Value_dh[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_y[3] = locIndex;
      locIndex = 6048U * bpIndex_y[3U];
      rtb_InterpolationUsingPreloo_km[scalarIndex] = intrp3d_lx(&bpIndex_y[0U],
        &frac_y[0U], &claw_main_P.InterpolationUsingPrelookup1_hr[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_o5[0]);
    }

    /* PreLookup: '<S494>/Prelookup1' */
    rtb_Prelookup1_o1_gv = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup1_BreakpointsData_at[0], 31U, &rtb_Prelookup1_o2_cf,
      &claw_main_DWork.Prelookup1_DWORK1_c);

    /* PreLookup: '<S494>/Prelookup2' incorporates:
     *  Gain: '<S494>/Gain2'
     */
    rtb_Prelookup2_o1_od = plook_linxp(claw_main_P.Gain2_Gain_kk *
      claw_main_B.beta_d, &claw_main_P.Prelookup2_BreakpointsData_nc[0], 26U,
      &rtb_Prelookup2_o2_c, &claw_main_DWork.Prelookup2_DWORK1_e);

    /* PreLookup: '<S494>/Prelookup3' */
    rtb_Prelookup3_o1_ny = plook_linxp(rtb_SPLLIBC_i,
      &claw_main_P.Prelookup3_BreakpointsData_dv[0], 2U, &rtb_Prelookup3_o2_j,
      &claw_main_DWork.Prelookup3_DWORK1_m);

    /* Interpolation_n-D: '<S494>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S494>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_cf;
    frac_z[0] = max_1;
    max_1 = rtb_Prelookup2_o2_c;
    frac_z[1] = max_1;
    max_1 = rtb_Prelookup3_o2_j;
    frac_z[2] = max_1;
    bpIndex_z[0] = rtb_Prelookup1_o1_gv;
    bpIndex_z[1] = rtb_Prelookup2_o1_od;
    bpIndex_z[2] = rtb_Prelookup3_o1_ny;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_at2[scalarIndex];
      if (claw_main_P.Constant3_Value_at2[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_z[3] = locIndex;
      locIndex = 2592U * bpIndex_z[3U];
      rtb_InterpolationUsingPreloo_bk[scalarIndex] = intrp3d_lx(&bpIndex_z[0U],
        &frac_z[0U], &claw_main_P.InterpolationUsingPrelookup__cm[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_fkm[0]);
    }

    /* Product: '<S491>/Product' incorporates:
     *  Constant: '<S491>/gains'
     *  Gain: '<S494>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_py[i] = claw_main_P.NegateLateral_Gain_a[i] *
        rtb_InterpolationUsingPreloo_bk[i] * claw_main_P.gains_Value_c2[i];
    }

    /* PreLookup: '<S495>/Prelookup1' */
    rtb_Prelookup1_o1_b = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup1_BreakpointsData_eh[0], 31U, &rtb_Prelookup1_o2_lm,
      &claw_main_DWork.Prelookup1_DWORK1_l);

    /* PreLookup: '<S495>/Prelookup2' incorporates:
     *  Gain: '<S495>/Gain2'
     */
    rtb_Prelookup2_o1_i = plook_linxp(claw_main_P.Gain2_Gain_ob *
      claw_main_B.beta_d, &claw_main_P.Prelookup2_BreakpointsData_p2[0], 26U,
      &rtb_Prelookup2_o2_b, &claw_main_DWork.Prelookup2_DWORK1_c3);

    /* PreLookup: '<S495>/Prelookup3' */
    rtb_Prelookup3_o1_a = plook_linxp(rtb_SPLLOBC_i,
      &claw_main_P.Prelookup3_BreakpointsData_i[0], 2U, &rtb_Prelookup3_o2_p,
      &claw_main_DWork.Prelookup3_DWORK1_dz);

    /* Interpolation_n-D: '<S495>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S495>/Constant3'
     */
    max_1 = rtb_Prelookup1_o2_lm;
    frac_10[0] = max_1;
    max_1 = rtb_Prelookup2_o2_b;
    frac_10[1] = max_1;
    max_1 = rtb_Prelookup3_o2_p;
    frac_10[2] = max_1;
    bpIndex_10[0] = rtb_Prelookup1_o1_b;
    bpIndex_10[1] = rtb_Prelookup2_o1_i;
    bpIndex_10[2] = rtb_Prelookup3_o1_a;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant3_Value_nl[scalarIndex];
      if (claw_main_P.Constant3_Value_nl[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_10[3] = locIndex;
      locIndex = 2592U * bpIndex_10[3U];
      rtb_InterpolationUsingPreloo_gc[scalarIndex] = intrp3d_lx(&bpIndex_10[0U],
        &frac_10[0U], &claw_main_P.InterpolationUsingPrelookup__pz[locIndex],
        &claw_main_P.InterpolationUsingPrelookup__me[0]);
    }

    /* Product: '<S492>/Product' incorporates:
     *  Constant: '<S492>/gains'
     *  Gain: '<S495>/Negate Lateral'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_jg[i] = claw_main_P.NegateLateral_Gain_nk[i] *
        rtb_InterpolationUsingPreloo_gc[i] * claw_main_P.gains_Value_bs[i];
    }

    /* PreLookup: '<S494>/Prelookup4' */
    rtb_Prelookup4_o1_ee = plook_linxp(claw_main_B.beta_d,
      &claw_main_P.Prelookup4_BreakpointsData_ls[0], 26U, &rtb_Prelookup4_o2_c3,
      &claw_main_DWork.Prelookup4_DWORK1_d);

    /* PreLookup: '<S494>/Prelookup5' */
    rtb_Prelookup5_o1_dv = plook_linxp(rtb_orderatts_i_idx,
      &claw_main_P.Prelookup5_BreakpointsData_ft[0], 2U, &rtb_Prelookup5_o2_i,
      &claw_main_DWork.Prelookup5_DWORK1_f);

    /* Interpolation_n-D: '<S494>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S494>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_cf;
    frac_11[0] = max_1;
    max_1 = rtb_Prelookup4_o2_c3;
    frac_11[1] = max_1;
    max_1 = rtb_Prelookup5_o2_i;
    frac_11[2] = max_1;
    bpIndex_11[0] = rtb_Prelookup1_o1_gv;
    bpIndex_11[1] = rtb_Prelookup4_o1_ee;
    bpIndex_11[2] = rtb_Prelookup5_o1_dv;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_ou[scalarIndex];
      if (claw_main_P.Constant1_Value_ou[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_11[3] = locIndex;
      locIndex = 2592U * bpIndex_11[3U];
      rtb_InterpolationUsingPreloo_h3[scalarIndex] = intrp3d_lx(&bpIndex_11[0U],
        &frac_11[0U], &claw_main_P.InterpolationUsingPrelookup1_hh[locIndex],
        &claw_main_P.InterpolationUsingPrelookup_njd[0]);
    }

    /* Product: '<S490>/Product' incorporates:
     *  Constant: '<S490>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_dg[i] = rtb_InterpolationUsingPreloo_h3[i] *
        claw_main_P.gains_Value_iv[i];
    }

    /* PreLookup: '<S495>/Prelookup4' */
    rtb_Prelookup4_o1_lh = plook_linxp(claw_main_B.beta_d,
      &claw_main_P.Prelookup4_BreakpointsData_m3[0], 26U, &rtb_Prelookup4_o2_hf,
      &claw_main_DWork.Prelookup4_DWORK1_lt);

    /* PreLookup: '<S495>/Prelookup5' */
    rtb_Prelookup5_o1_g = plook_linxp(rtb_Switch_d_idx_0,
      &claw_main_P.Prelookup5_BreakpointsData_ju[0], 2U, &rtb_Prelookup5_o2_p,
      &claw_main_DWork.Prelookup5_DWORK1_a);

    /* Interpolation_n-D: '<S495>/Interpolation Using Prelookup1' incorporates:
     *  Constant: '<S495>/Constant1'
     */
    max_1 = rtb_Prelookup1_o2_lm;
    frac_12[0] = max_1;
    max_1 = rtb_Prelookup4_o2_hf;
    frac_12[1] = max_1;
    max_1 = rtb_Prelookup5_o2_p;
    frac_12[2] = max_1;
    bpIndex_12[0] = rtb_Prelookup1_o1_b;
    bpIndex_12[1] = rtb_Prelookup4_o1_lh;
    bpIndex_12[2] = rtb_Prelookup5_o1_g;
    for (scalarIndex = 0U; scalarIndex < 6U; scalarIndex++) {
      locIndex = claw_main_P.Constant1_Value_kt[scalarIndex];
      if (claw_main_P.Constant1_Value_kt[scalarIndex] > 5U) {
        locIndex = 5U;
      }

      bpIndex_12[3] = locIndex;
      locIndex = 2592U * bpIndex_12[3U];
      rtb_InterpolationUsingPreloo_j3[scalarIndex] = intrp3d_lx(&bpIndex_12[0U],
        &frac_12[0U], &claw_main_P.InterpolationUsingPrelookup1__f[locIndex],
        &claw_main_P.InterpolationUsingPrelookup1_gs[0]);
    }

    /* Product: '<S493>/Product' incorporates:
     *  Constant: '<S493>/gains'
     */
    for (i = 0; i < 6; i++) {
      rtb_Product_al[i] = rtb_InterpolationUsingPreloo_j3[i] *
        claw_main_P.gains_Value_o4[i];
    }

    /* PreLookup: '<S469>/Prelookup1' */
    rtb_Prelookup1_o1_d0 = plook_linxp(claw_main_B.alpha_l,
      &claw_main_P.Prelookup1_BreakpointsData_ck[0], 31U, &rtb_Prelookup1_o2_cz,
      &claw_main_DWork.Prelookup1_DWORK1_nc);

    /* PreLookup: '<S469>/Prelookup2' */
    rtb_Prelookup2_o1_h = plook_linxp(claw_main_B.beta_d,
      &claw_main_P.Prelookup2_BreakpointsData_g3[0], 26U, &rtb_Prelookup2_o2_au,
      &claw_main_DWork.Prelookup2_DWORK1_p5);

    /* PreLookup: '<S469>/Prelookup3' */
    rtb_Prelookup3_o1_p = plook_linxp(rtb_Switch_d_idx_1,
      &claw_main_P.Prelookup3_BreakpointsData_aa[0], 3U, &rtb_Prelookup3_o2_b,
      &claw_main_DWork.Prelookup3_DWORK1_l);

    /* PreLookup: '<S480>/Prelookup4' incorporates:
     *  Constant: '<S469>/Constant1'
     */
    rtb_Prelookup4_o1_jk = plook_linxp(claw_main_P.Constant1_Value_kl,
      &claw_main_P.Prelookup4_BreakpointsData_ao[0], 5U, &rtb_Prelookup4_o2_l,
      &claw_main_DWork.Prelookup4_DWORK1_pj);

    /* Interpolation_n-D: '<S480>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S480>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_cz;
    frac_13[0] = max_1;
    max_1 = rtb_Prelookup2_o2_au;
    frac_13[1] = max_1;
    max_1 = rtb_Prelookup3_o2_b;
    frac_13[2] = max_1;
    max_1 = rtb_Prelookup4_o2_l;
    frac_13[3] = max_1;
    bpIndex_13[0] = rtb_Prelookup1_o1_d0;
    bpIndex_13[1] = rtb_Prelookup2_o1_h;
    bpIndex_13[2] = rtb_Prelookup3_o1_p;
    bpIndex_13[3] = rtb_Prelookup4_o1_jk;
    locIndex = claw_main_P.Constant2_Value_ir[0];
    if (claw_main_P.Constant2_Value_ir[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_13[4] = locIndex;
    locIndex = 20736U * bpIndex_13[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_13[0U], &frac_13[0U],
      &claw_main_P.InterpolationUsingPrelookup__cj[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_ch0[0]);
    locIndex = claw_main_P.Constant2_Value_ir[1];
    if (claw_main_P.Constant2_Value_ir[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_13[4] = locIndex;
    locIndex = 20736U * bpIndex_13[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_13[0U], &frac_13[0U],
      &claw_main_P.InterpolationUsingPrelookup__cj[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_ch0[0]);
    locIndex = claw_main_P.Constant2_Value_ir[2];
    if (claw_main_P.Constant2_Value_ir[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_13[4] = locIndex;
    locIndex = 20736U * bpIndex_13[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_13[0U], &frac_13[0U],
      &claw_main_P.InterpolationUsingPrelookup__cj[locIndex],
      &claw_main_P.InterpolationUsingPrelookup_ch0[0]);

    /* Assignment: '<S480>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S480>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_ju[i] = claw_main_P.Constant_Value_ec[i];
    }

    rtb_AssignmenttoLongitudinal_ju[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_ju[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_ju[4] = rtb_Switch2_idx;

    /* PreLookup: '<S479>/Prelookup4' */
    rtb_Prelookup4_o1_j3 = plook_linxp(rtb_ELLOBC_k,
      &claw_main_P.Prelookup4_BreakpointsData_no[0], 5U, &rtb_Prelookup4_o2_g2,
      &claw_main_DWork.Prelookup4_DWORK1_af);

    /* Interpolation_n-D: '<S479>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S479>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_cz;
    frac_14[0] = max_1;
    max_1 = rtb_Prelookup2_o2_au;
    frac_14[1] = max_1;
    max_1 = rtb_Prelookup3_o2_b;
    frac_14[2] = max_1;
    max_1 = rtb_Prelookup4_o2_g2;
    frac_14[3] = max_1;
    bpIndex_14[0] = rtb_Prelookup1_o1_d0;
    bpIndex_14[1] = rtb_Prelookup2_o1_h;
    bpIndex_14[2] = rtb_Prelookup3_o1_p;
    bpIndex_14[3] = rtb_Prelookup4_o1_j3;
    locIndex = claw_main_P.Constant2_Value_bh[0];
    if (claw_main_P.Constant2_Value_bh[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_14[4] = locIndex;
    locIndex = 20736U * bpIndex_14[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_14[0U], &frac_14[0U],
      &claw_main_P.InterpolationUsingPrelookup__ho[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ii[0]);
    locIndex = claw_main_P.Constant2_Value_bh[1];
    if (claw_main_P.Constant2_Value_bh[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_14[4] = locIndex;
    locIndex = 20736U * bpIndex_14[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_14[0U], &frac_14[0U],
      &claw_main_P.InterpolationUsingPrelookup__ho[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ii[0]);
    locIndex = claw_main_P.Constant2_Value_bh[2];
    if (claw_main_P.Constant2_Value_bh[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_14[4] = locIndex;
    locIndex = 20736U * bpIndex_14[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_14[0U], &frac_14[0U],
      &claw_main_P.InterpolationUsingPrelookup__ho[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ii[0]);

    /* Assignment: '<S479>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S479>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_g[i] = claw_main_P.Constant_Value_g3[i];
    }

    rtb_AssignmenttoLongitudinal_g[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_g[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_g[4] = rtb_Switch2_idx;

    /* Gain: '<S476>/Gain' incorporates:
     *  Gain: '<S469>/Gain'
     *  Sum: '<S469>/Add'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_g[i] -
                  rtb_AssignmenttoLongitudinal_ju[i]) * claw_main_P.Gain_Gain_m3;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_eps[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_eps[i] += claw_main_P.Gain_Gain_px[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S481>/Prelookup4' */
    rtb_Prelookup4_o1_p2 = plook_linxp(rtb_ELLIBC_m,
      &claw_main_P.Prelookup4_BreakpointsData_ldo[0], 5U, &rtb_Prelookup4_o2_cc,
      &claw_main_DWork.Prelookup4_DWORK1_kz);

    /* Interpolation_n-D: '<S481>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S481>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_cz;
    frac_15[0] = max_1;
    max_1 = rtb_Prelookup2_o2_au;
    frac_15[1] = max_1;
    max_1 = rtb_Prelookup3_o2_b;
    frac_15[2] = max_1;
    max_1 = rtb_Prelookup4_o2_cc;
    frac_15[3] = max_1;
    bpIndex_15[0] = rtb_Prelookup1_o1_d0;
    bpIndex_15[1] = rtb_Prelookup2_o1_h;
    bpIndex_15[2] = rtb_Prelookup3_o1_p;
    bpIndex_15[3] = rtb_Prelookup4_o1_p2;
    locIndex = claw_main_P.Constant2_Value_ex[0];
    if (claw_main_P.Constant2_Value_ex[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_15[4] = locIndex;
    locIndex = 20736U * bpIndex_15[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_15[0U], &frac_15[0U],
      &claw_main_P.InterpolationUsingPrelookup__gn[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__cr[0]);
    locIndex = claw_main_P.Constant2_Value_ex[1];
    if (claw_main_P.Constant2_Value_ex[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_15[4] = locIndex;
    locIndex = 20736U * bpIndex_15[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_15[0U], &frac_15[0U],
      &claw_main_P.InterpolationUsingPrelookup__gn[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__cr[0]);
    locIndex = claw_main_P.Constant2_Value_ex[2];
    if (claw_main_P.Constant2_Value_ex[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_15[4] = locIndex;
    locIndex = 20736U * bpIndex_15[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_15[0U], &frac_15[0U],
      &claw_main_P.InterpolationUsingPrelookup__gn[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__cr[0]);

    /* Assignment: '<S481>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S481>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_lr[i] = claw_main_P.Constant_Value_j2[i];
    }

    rtb_AssignmenttoLongitudinal_lr[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_lr[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_lr[4] = rtb_Switch2_idx;

    /* Gain: '<S475>/Gain' incorporates:
     *  Gain: '<S469>/Gain1'
     *  Sum: '<S469>/Add1'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_lr[i] -
                  rtb_AssignmenttoLongitudinal_ju[i]) *
        claw_main_P.Gain1_Gain_bt;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_ggw[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_ggw[i] += claw_main_P.Gain_Gain_h5[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S483>/Prelookup4' */
    rtb_Prelookup4_o1_p2x = plook_linxp(rtb_ELRIBC_m,
      &claw_main_P.Prelookup4_BreakpointsData_lw[0], 5U, &rtb_Prelookup4_o2_b,
      &claw_main_DWork.Prelookup4_DWORK1_mx);

    /* Interpolation_n-D: '<S483>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S483>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_cz;
    frac_16[0] = max_1;
    max_1 = rtb_Prelookup2_o2_au;
    frac_16[1] = max_1;
    max_1 = rtb_Prelookup3_o2_b;
    frac_16[2] = max_1;
    max_1 = rtb_Prelookup4_o2_b;
    frac_16[3] = max_1;
    bpIndex_16[0] = rtb_Prelookup1_o1_d0;
    bpIndex_16[1] = rtb_Prelookup2_o1_h;
    bpIndex_16[2] = rtb_Prelookup3_o1_p;
    bpIndex_16[3] = rtb_Prelookup4_o1_p2x;
    locIndex = claw_main_P.Constant2_Value_gz[0];
    if (claw_main_P.Constant2_Value_gz[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_16[4] = locIndex;
    locIndex = 20736U * bpIndex_16[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_16[0U], &frac_16[0U],
      &claw_main_P.InterpolationUsingPrelookup__dp[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kf[0]);
    locIndex = claw_main_P.Constant2_Value_gz[1];
    if (claw_main_P.Constant2_Value_gz[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_16[4] = locIndex;
    locIndex = 20736U * bpIndex_16[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_16[0U], &frac_16[0U],
      &claw_main_P.InterpolationUsingPrelookup__dp[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kf[0]);
    locIndex = claw_main_P.Constant2_Value_gz[2];
    if (claw_main_P.Constant2_Value_gz[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_16[4] = locIndex;
    locIndex = 20736U * bpIndex_16[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_16[0U], &frac_16[0U],
      &claw_main_P.InterpolationUsingPrelookup__dp[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__kf[0]);

    /* Assignment: '<S483>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S483>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_a2[i] = claw_main_P.Constant_Value_ba[i];
    }

    rtb_AssignmenttoLongitudinal_a2[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_a2[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_a2[4] = rtb_Switch2_idx;

    /* Gain: '<S477>/Gain' incorporates:
     *  Gain: '<S469>/Gain2'
     *  Sum: '<S469>/Add2'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_a2[i] -
                  rtb_AssignmenttoLongitudinal_ju[i]) *
        claw_main_P.Gain2_Gain_d4;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_jt[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_jt[i] += claw_main_P.Gain_Gain_lo[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }
    }

    /* PreLookup: '<S482>/Prelookup4' */
    rtb_Prelookup4_o1_n = plook_linxp(rtb_ELROBC_gd,
      &claw_main_P.Prelookup4_BreakpointsData_i[0], 5U, &rtb_Prelookup4_o2_e,
      &claw_main_DWork.Prelookup4_DWORK1_nm);

    /* Interpolation_n-D: '<S482>/Interpolation Using Prelookup' incorporates:
     *  Constant: '<S482>/Constant2'
     */
    max_1 = rtb_Prelookup1_o2_cz;
    frac_17[0] = max_1;
    max_1 = rtb_Prelookup2_o2_au;
    frac_17[1] = max_1;
    max_1 = rtb_Prelookup3_o2_b;
    frac_17[2] = max_1;
    max_1 = rtb_Prelookup4_o2_e;
    frac_17[3] = max_1;
    bpIndex_17[0] = rtb_Prelookup1_o1_d0;
    bpIndex_17[1] = rtb_Prelookup2_o1_h;
    bpIndex_17[2] = rtb_Prelookup3_o1_p;
    bpIndex_17[3] = rtb_Prelookup4_o1_n;
    locIndex = claw_main_P.Constant2_Value_dl[0];
    if (claw_main_P.Constant2_Value_dl[0] > 2U) {
      locIndex = 2U;
    }

    bpIndex_17[4] = locIndex;
    locIndex = 20736U * bpIndex_17[4U];
    rtb_delta_LLh_idx = intrp4d_lx(&bpIndex_17[0U], &frac_17[0U],
      &claw_main_P.InterpolationUsingPrelookup__jx[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ac[0]);
    locIndex = claw_main_P.Constant2_Value_dl[1];
    if (claw_main_P.Constant2_Value_dl[1] > 2U) {
      locIndex = 2U;
    }

    bpIndex_17[4] = locIndex;
    locIndex = 20736U * bpIndex_17[4U];
    rtb_delta_LLh_idx_0 = intrp4d_lx(&bpIndex_17[0U], &frac_17[0U],
      &claw_main_P.InterpolationUsingPrelookup__jx[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ac[0]);
    locIndex = claw_main_P.Constant2_Value_dl[2];
    if (claw_main_P.Constant2_Value_dl[2] > 2U) {
      locIndex = 2U;
    }

    bpIndex_17[4] = locIndex;
    locIndex = 20736U * bpIndex_17[4U];
    rtb_Switch2_idx = intrp4d_lx(&bpIndex_17[0U], &frac_17[0U],
      &claw_main_P.InterpolationUsingPrelookup__jx[locIndex],
      &claw_main_P.InterpolationUsingPrelookup__ac[0]);

    /* Assignment: '<S482>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S482>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_mh[i] = claw_main_P.Constant_Value_hc[i];
    }

    rtb_AssignmenttoLongitudinal_mh[0] = rtb_delta_LLh_idx;
    rtb_AssignmenttoLongitudinal_mh[2] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_mh[4] = rtb_Switch2_idx;

    /* Gain: '<S478>/Gain' incorporates:
     *  Gain: '<S469>/Gain3'
     *  Sum: '<S469>/Add3'
     */
    for (i = 0; i < 6; i++) {
      min_6[i] = (rtb_AssignmenttoLongitudinal_mh[i] -
                  rtb_AssignmenttoLongitudinal_ju[i]) *
        claw_main_P.Gain3_Gain_dy;
    }

    for (i = 0; i < 6; i++) {
      rtb_Gain_pb[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 6; yOffset_0++) {
        rtb_Gain_pb[i] += claw_main_P.Gain_Gain_gj[6 * yOffset_0 + i] *
          min_6[yOffset_0];
      }

      /* Gain: '<S470>/Gain' */
      rtb_Gain_jo[i] = claw_main_P.Gain_Gain_cw[i] * rtb_Sum_ow_idx;

      /* Gain: '<S470>/Gain1' */
      rtb_Gain1_p4[i] = claw_main_P.Gain1_Gain_bn[i] * rtb_Switch_d_idx;

      /* Gain: '<S470>/Gain2' */
      rtb_Gain2_b[i] = claw_main_P.Gain2_Gain_jn[i] * rtb_Sum_ow_idx_0;

      /* Gain: '<S470>/Gain3' */
      rtb_Gain3_dl[i] = claw_main_P.Gain3_Gain_ia[i] * rtb_Sum_ow_idx_1;
    }

    /* S-Function (sfun_idxsearch): '<S471>/PreLookup Index Search1' */
    scalarPrevIndex_1 = claw_main_DWork.PreLookupIndexSearch1_MODE_g2;
    i = plook_s32dd_binxp(claw_main_B.alpha_l,
                          &claw_main_P.PreLookupIndexSearch1_bpData_p[0], 31U,
                          &scalarFraction_4, &scalarPrevIndex_1);
    rtb_delta_LLh_idx = scalarFraction_4;

    /* S-Function (sfun_kflookupnd): '<S471>/TableLookup' incorporates:
     *  Constant: '<S471>/Constant2'
     *  DataTypeConversion: '<S471>/Data Type Conversion2'
     *  RelationalOperator: '<S484>/Compare'
     */
    if (i > 30) {
      max_1 = 30.0;
    } else if (i >= 0) {
      max_1 = (real_T)i;
    } else {
      max_1 = 0.0;
    }

    i = (int32_T)max_1;
    yOffset_0 = (rtb_Gain_g_idx_2 != 0.0);
    if (claw_main_P.Constant2_Value_gi[0] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_gi[0];
    }

    rtb_delta_LLh_idx_0 = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_kz[(scalarIndex << 6U) + (yOffset_0 <<
      5)]);
    if (claw_main_P.Constant2_Value_gi[1] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_gi[1];
    }

    rtb_Switch2_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_kz[(scalarIndex << 6U) + (yOffset_0 <<
      5)]);
    if (claw_main_P.Constant2_Value_gi[2] > 2U) {
      scalarIndex = 2U;
    } else {
      scalarIndex = claw_main_P.Constant2_Value_gi[2];
    }

    rtb_delta_LLh_idx = intrp1d_lx((uint32_T)i, rtb_delta_LLh_idx,
      &claw_main_P.TableLookup_tableData_kz[(scalarIndex << 6U) + (yOffset_0 <<
      5)]);

    /* Assignment: '<S471>/Assignment to  Longitudinal' incorporates:
     *  Constant: '<S471>/Constant'
     */
    for (i = 0; i < 6; i++) {
      rtb_AssignmenttoLongitudinal_ek[i] = claw_main_P.Constant_Value_nn[i];
    }

    rtb_AssignmenttoLongitudinal_ek[0] = rtb_delta_LLh_idx_0;
    rtb_AssignmenttoLongitudinal_ek[2] = rtb_Switch2_idx;
    rtb_AssignmenttoLongitudinal_ek[4] = rtb_delta_LLh_idx;
    claw_main_ImplementDamageModels(rtb_Product_pp, rtb_Product_oq,
      rtb_NegateLateral_o, rtb_InterpolationUsingPreloo_km, rtb_Product_py,
      rtb_Product_jg, rtb_Product_dg, rtb_Product_al,
      rtb_AssignmenttoLongitudinal_ju, rtb_Gain_eps, rtb_Gain_ggw, rtb_Gain_jt,
      rtb_Gain_pb, rtb_Gain_jo, rtb_Gain1_p4, rtb_Gain2_b, rtb_Gain3_dl,
      rtb_AssignmenttoLongitudinal_ek, rtb_FromWorkspace_c,
      &claw_main_B.sf_ImplementDamageModels_g);

    /* Reshape: '<S472>/Reshape' */
    for (i = 0; i < 6; i++) {
      rtb_Reshape_no[i] = claw_main_B.sf_ImplementDamageModels_g.dC6[i];
    }

    /* Math: '<S519>/Math Function1' */
    rtb_MathFunction1_j = rt_hypot_snf(rtb_MathFunction_nk, rtb_uvw_rw_at[1]);

    /* MinMax: '<S446>/MinMax' incorporates:
     *  Constant: '<S446>/Constant'
     */
    max_1 = rt_MAXd_snf(claw_main_P.Constant_Value_o0, rtb_MathFunction1_j);

    /* Gain: '<S443>/Gain5' */
    rtb_tas_d = claw_main_P.Gain5_Gain_oe * max_1;

    /* DataTypeConversion: '<S462>/Data Type Conversion' */
    rtb_delta_LLh_idx = rtb_FromWorkspace_c;
    if ((rtb_FromWorkspace_c < 4.5035996273704960E+015) && (rtb_FromWorkspace_c >
         -4.5035996273704960E+015)) {
      rtb_delta_LLh_idx = floor(rtb_FromWorkspace_c + 0.5);
    }

    if (rtIsNaN(rtb_FromWorkspace_c) || rtIsInf(rtb_FromWorkspace_c)) {
      rtb_delta_LLh_idx = 0.0;
    } else {
      rtb_delta_LLh_idx = fmod(rtb_delta_LLh_idx, 4.294967296E+009);
    }

    rtb_DataTypeConversion_g = rtb_delta_LLh_idx < 0.0 ? -((uint32_T)
      (-rtb_delta_LLh_idx)) : (uint32_T)rtb_delta_LLh_idx;

    /* SwitchCase: '<S462>/Switch Case' incorporates:
     *  ActionPort: '<S496>/Action Port'
     *  ActionPort: '<S497>/Action Port'
     *  SubSystem: '<S462>/Forced Oscillation with Damage Increments'
     *  SubSystem: '<S462>/Rotary Blended  UnDamaged Case'
     */
    switch (rtb_DataTypeConversion_g) {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      ForcedOscillationwithDamageIn_o(claw_main_B.alpha_l,
        rtb_DataTypeConversion_g, rtb_tas_d, rtb_sensors, claw_main_P.B_Value_b,
        claw_main_P.Cbar_Value_d, claw_main_B.Merge_fl,
        &claw_main_B.ForcedOscillationwithDamageIn_i,
        &claw_main_DWork.ForcedOscillationwithDamageIn_i,
        (rtP_ForcedOscillationwithDama_l *)
        &claw_main_P.ForcedOscillationwithDamageIn_i);
      break;

     default:
      cl_RotaryBlendedUnDamagedCase_k(claw_main_B.alpha_l, rtb_tas_d,
        claw_main_B.beta_d, rtb_sensors, claw_main_P.B_Value_b,
        claw_main_P.Cbar_Value_d, claw_main_B.Merge_fl,
        &claw_main_B.RotaryBlendedUnDamagedCase_c,
        &claw_main_DWork.RotaryBlendedUnDamagedCase_c,
        (rtP_RotaryBlendedUnDamagedCas_m *)
        &claw_main_P.RotaryBlendedUnDamagedCase_c);
      break;
    }

    /* Fcn: '<S446>/wind_qbar' */
    if ((max_1 < 0.0) && (2.0 > floor(2.0))) {
      rtb_MultiportSwitch2_idx_2 = -rt_pow_snf(-max_1, 2.0);
    } else {
      rtb_MultiportSwitch2_idx_2 = rt_pow_snf(max_1, 2.0);
    }

    /* Product: '<S446>/Product1' */
    rtb_qbar_a = 0.5 * rtb_MultiportSwitch2_idx_2 * rtb_Product_b;

    /* Gain: '<S460>/Gain2' incorporates:
     *  Product: '<S460>/Product'
     *  Sum: '<S442>/Sum8'
     */
    for (i = 0; i < 6; i++) {
      rtb_Gain2_oi[i] = ((rtb_Add_c[i] + rtb_Reshape_no[i]) +
                         claw_main_B.Merge_fl[i]) * rtb_qbar_a *
        claw_main_P.Gain2_Gain_pb;
    }

    /* Sum: '<S460>/Sum' incorporates:
     *  Constant: '<S441>/xCG1'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_a[0] - rtb_Add2_idx_0;

    /* Gain: '<S467>/Gain' */
    rtb_Gain1_idx_0 = claw_main_P.Gain_Gain_bk * rtb_Switch2_idx;
    rtb_Gain1_idx_1 = rtb_Switch2_idx;

    /* Sum: '<S460>/Sum' incorporates:
     *  Constant: '<S441>/xCG1'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_a[1] - rtb_Add2_idx_1;

    /* Gain: '<S467>/Gain' */
    rtb_delta_LLh_idx = claw_main_P.Gain_Gain_bk * rtb_Switch2_idx;
    rtb_delta_LLh_idx_0 = rtb_Switch2_idx;

    /* Sum: '<S460>/Sum' incorporates:
     *  Constant: '<S441>/xCG1'
     *  Reshape: '<S447>/Reshape'
     */
    rtb_Switch2_idx = claw_main_P.xCG1_Value_a[2] - rtb_Add2_idx;

    /* Sum: '<S435>/Sum' incorporates:
     *  Gain: '<S460>/Reference Lengths'
     *  Gain: '<S467>/Gain'
     *  Product: '<S467>/Product'
     *  Reshape: '<S467>/Reshape'
     *  Reshape: '<S467>/Reshape1'
     *  Sum: '<S444>/Sum'
     *  Sum: '<S460>/Sum1'
     */
    min_6[0] = claw_main_B.sf_EngineAlignment_d.T[0];
    min_6[1] = claw_main_B.sf_EngineAlignment_d.T[1];
    min_6[2] = claw_main_B.sf_EngineAlignment_d.T[2];
    min_6[3] = (rtb_dircos_0[0] + rtb_Gain_e_0[0]) + rtb_Product_ih[0];
    min_6[4] = (rtb_dircos_0[1] + rtb_Gain_e_0[1]) + rtb_Product_ih[1];
    min_6[5] = (rtb_dircos_0[2] + rtb_Gain_e_0[2]) + rtb_Product_ih[2];
    rtb_Gain1_oy_0[0] = 0.0;
    rtb_Gain1_oy_0[1] = rtb_Switch2_idx;
    rtb_Gain1_oy_0[2] = rtb_delta_LLh_idx;
    rtb_Gain1_oy_0[3] = claw_main_P.Gain_Gain_bk * rtb_Switch2_idx;
    rtb_Gain1_oy_0[4] = 0.0;
    rtb_Gain1_oy_0[5] = rtb_Gain1_idx_1;
    rtb_Gain1_oy_0[6] = rtb_delta_LLh_idx_0;
    rtb_Gain1_oy_0[7] = rtb_Gain1_idx_0;
    rtb_Gain1_oy_0[8] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i] * rtb_Gain2_oi[0];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 3] * rtb_Gain2_oi[1];
      rtb_dircos_0[i] += rtb_Gain1_oy_0[i + 6] * rtb_Gain2_oi[2];
    }

    rtb_Gain2_n_0[0] = rtb_Gain2_oi[0];
    rtb_Gain2_n_0[1] = rtb_Gain2_oi[1];
    rtb_Gain2_n_0[2] = rtb_Gain2_oi[2];
    rtb_Gain2_n_0[3] = claw_main_P.ReferenceLengths_Gain_n[0] * rtb_Gain2_oi[3]
      + rtb_dircos_0[0];
    rtb_Gain2_n_0[4] = claw_main_P.ReferenceLengths_Gain_n[1] * rtb_Gain2_oi[4]
      + rtb_dircos_0[1];
    rtb_Gain2_n_0[5] = claw_main_P.ReferenceLengths_Gain_n[2] * rtb_Gain2_oi[5]
      + rtb_dircos_0[2];
    for (i = 0; i < 6; i++) {
      rtb_Sum_hv[i] = min_6[i] + rtb_Gain2_n_0[i];
    }

    /* Product: '<S432>/Product2' */
    rtb_accels_cg_b[0] = rtb_Sum_hv[0] / claw_main_B.mass;

    /* Product: '<S434>/Force -> Acceleration' incorporates:
     *  Reshape: '<S432>/Reshape1'
     *  Sum: '<S432>/Sum'
     */
    rtb_Gain1_idx_0 = 1.0 / claw_main_B.mass * (rtb_Gain_g_idx + rtb_Sum_hv[0]);

    /* Product: '<S432>/Product2' */
    rtb_accels_cg_b[1] = rtb_Sum_hv[1] / claw_main_B.mass;

    /* Product: '<S434>/Force -> Acceleration' incorporates:
     *  Reshape: '<S432>/Reshape1'
     *  Sum: '<S432>/Sum'
     */
    rtb_Gain1_idx_1 = 1.0 / claw_main_B.mass * (rtb_Gain_g_idx_0 + rtb_Sum_hv[1]);

    /* Product: '<S432>/Product2' */
    rtb_accels_cg_b[2] = rtb_Sum_hv[2] / claw_main_B.mass;

    /* Product: '<S434>/Force -> Acceleration' incorporates:
     *  Reshape: '<S432>/Reshape1'
     *  Sum: '<S432>/Sum'
     */
    rtb_Gain1_idx = 1.0 / claw_main_B.mass * (rtb_Gain_g_idx_1 + rtb_Sum_hv[2]);
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_dircos_g[3 * i] * rtb_uvw[0];
      rtb_dircos_0[i] += rtb_dircos_g[3 * i + 1] * rtb_uvw[1];
      rtb_dircos_0[i] += rtb_dircos_g[3 * i + 2] * rtb_uvw[2];
      rtb_NEhdot_p[i] = claw_main_P.MatrixGain_Gain_hs[i] * rtb_dircos_0[i];

      /* Product: '<S434>/Product2' */
      rtb_Product2_f[i] = 0.0;
      rtb_Product2_f[i] += rtb_inertia[i] * rtb_sensors[0];
      rtb_Product2_f[i] += rtb_inertia[i + 3] * rtb_sensors[1];
      rtb_Product2_f[i] += rtb_inertia[i + 6] * rtb_sensors[2];
    }

    /* Product: '<S434>/Product3' incorporates:
     *  Product: '<S437>/Product'
     *  Product: '<S437>/Product1'
     *  Product: '<S439>/Product'
     *  Product: '<S439>/Product1'
     *  Sum: '<S434>/Sum1'
     *  Sum: '<S437>/Sum'
     *  Sum: '<S439>/Sum'
     */
    rtb_delta_LLh_idx = (rtb_Sum_hv[3] - (rtb_sensors[1] * 0.0 - rtb_sensors[2] *
      0.0)) - (rtb_sensors[1] * rtb_Product2_f[2] - rtb_sensors[2] *
               rtb_Product2_f[1]);
    rtb_delta_LLh_idx_0 = (rtb_Sum_hv[4] - (rtb_sensors[2] * 0.0 - rtb_sensors[0]
      * 0.0)) - (rtb_sensors[2] * rtb_Product2_f[0] - rtb_sensors[0] *
                 rtb_Product2_f[2]);
    rtb_Switch2_idx = (rtb_Sum_hv[5] - (rtb_sensors[0] * 0.0 - rtb_sensors[1] *
      0.0)) - (rtb_sensors[0] * rtb_Product2_f[1] - rtb_sensors[1] *
               rtb_Product2_f[0]);
    for (i = 0; i < 3; i++) {
      rtb_pqrdot_m[i] = 0.0;
      rtb_pqrdot_m[i] += rtb_inertia_inv[i] * rtb_delta_LLh_idx;
      rtb_pqrdot_m[i] += rtb_inertia_inv[i + 3] * rtb_delta_LLh_idx_0;
      rtb_pqrdot_m[i] += rtb_inertia_inv[i + 6] * rtb_Switch2_idx;
    }

    /* Sum: '<S438>/Sum' incorporates:
     *  Product: '<S438>/Product'
     *  Product: '<S438>/Product1'
     */
    rtb_delta_LLh_idx = rtb_sensors[1] * rtb_uvw[2] - rtb_sensors[2] * rtb_uvw[1];
    rtb_delta_LLh_idx_0 = rtb_sensors[2] * rtb_uvw[0] - rtb_sensors[0] *
      rtb_uvw[2];
    rtb_Switch2_idx = rtb_sensors[0] * rtb_uvw[1] - rtb_sensors[1] * rtb_uvw[0];

    /* Reshape: '<S440>/Reshape' incorporates:
     *  Gain: '<S440>/Gain1'
     */
    rtb_MatrixConcatenation_d[0] = claw_main_P.Gain1_Gain_og[0] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_d[1] = claw_main_P.Gain1_Gain_og[1] * rtb_Switch_idx;
    rtb_MatrixConcatenation_d[2] = claw_main_P.Gain1_Gain_og[2] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_d[3] = claw_main_P.Gain1_Gain_og[3] *
      rtb_Switch_idx_1;

    /* Reshape: '<S440>/Reshape1' incorporates:
     *  Gain: '<S440>/Gain2'
     */
    rtb_MatrixConcatenation_d[4] = claw_main_P.Gain2_Gain_fd[0] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_d[5] = claw_main_P.Gain2_Gain_fd[1] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_d[6] = claw_main_P.Gain2_Gain_fd[2] * rtb_Switch_idx;
    rtb_MatrixConcatenation_d[7] = claw_main_P.Gain2_Gain_fd[3] *
      rtb_Switch_idx_0;

    /* Reshape: '<S440>/Reshape2' incorporates:
     *  Gain: '<S440>/Gain3'
     */
    rtb_MatrixConcatenation_d[8] = claw_main_P.Gain3_Gain_kw[0] *
      rtb_Switch_idx_2;
    rtb_MatrixConcatenation_d[9] = claw_main_P.Gain3_Gain_kw[1] *
      rtb_Switch_idx_1;
    rtb_MatrixConcatenation_d[10] = claw_main_P.Gain3_Gain_kw[2] *
      rtb_Switch_idx_0;
    rtb_MatrixConcatenation_d[11] = claw_main_P.Gain3_Gain_kw[3] *
      rtb_Switch_idx;

    /* Gain: '<S436>/Gain4' incorporates:
     *  Product: '<S436>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_d[i] *
        rtb_sensors[0];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_d[i + 4] *
        rtb_sensors[1];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_d[i + 8] *
        rtb_sensors[2];
    }

    rtb_Gain4_kx[0] = claw_main_P.Gain4_Gain_ll * rtb_MatrixConcatenation_j_0[0];
    rtb_Gain4_kx[1] = claw_main_P.Gain4_Gain_ll * rtb_MatrixConcatenation_j_0[1];
    rtb_Gain4_kx[2] = claw_main_P.Gain4_Gain_ll * rtb_MatrixConcatenation_j_0[2];
    rtb_Gain4_kx[3] = claw_main_P.Gain4_Gain_ll * rtb_MatrixConcatenation_j_0[3];

    /* Selector: '<S449>/Value(ndx,:)' incorporates:
     *  Constant: '<S449>/Gain1'
     */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
      rtb_Valuendx_b[yOffset] = claw_main_P.Gain1_Value_i[7 * uDimIdx + (int32_T)
        rtb_FromWorkspace_c];
      yOffset++;
    }

    /* Switch: '<S447>/Switch' incorporates:
     *  Constant: '<S447>/xCG3'
     *  Constant: '<S447>/xCG5'
     */
    for (i = 0; i < 6; i++) {
      if (rtb_Gain_g_idx_2 >= claw_main_P.Switch_Threshold_mc) {
        rtb_Switch_p[i] = claw_main_P.xCG3_Value_m[i];
      } else {
        rtb_Switch_p[i] = claw_main_P.xCG5_Value_g[i];
      }
    }

    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_o,
      &claw_main_B.sf_EmbeddedMATLABFunction_o, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_o);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_o,
      &claw_main_B.sf_EmbeddedMATLABFunction_l, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_l);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_o,
      &claw_main_B.sf_EmbeddedMATLABFunction_m, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_m);

    /* Gain: '<S447>/Gain' */
    rtb_Gain_g5u = claw_main_P.Gain_Gain_jr * rtb_gwest_ia;

    /* Reshape: '<S447>/Reshape1' incorporates:
     *  Constant: '<S447>/ixxb3'
     *  Constant: '<S450>/xCG6'
     *  Sum: '<S447>/Add1'
     */
    rtb_Reshape1_i3[0] = ((rtb_Switch_p[0] +
      claw_main_B.sf_EmbeddedMATLABFunction_o.y) + rtb_Valuendx_b[0]) +
      claw_main_P.ixxb3_Value_h[0];
    rtb_Reshape1_i3[1] = ((rtb_Switch_p[1] +
      claw_main_B.sf_EmbeddedMATLABFunction_l.y) + rtb_Valuendx_b[1]) +
      claw_main_P.ixxb3_Value_h[1];
    rtb_Reshape1_i3[2] = ((rtb_Switch_p[2] +
      claw_main_B.sf_EmbeddedMATLABFunction_m.y) + rtb_Valuendx_b[2]) +
      claw_main_P.ixxb3_Value_h[2];
    rtb_Reshape1_i3[3] = ((rtb_Switch_p[3] + claw_main_P.xCG6_Value_n[0]) +
                          rtb_Valuendx_b[3]) + claw_main_P.ixxb3_Value_h[3];
    rtb_Reshape1_i3[4] = ((rtb_Switch_p[4] + claw_main_P.xCG6_Value_n[1]) +
                          rtb_Valuendx_b[4]) + claw_main_P.ixxb3_Value_h[4];
    rtb_Reshape1_i3[5] = ((rtb_Switch_p[5] + claw_main_P.xCG6_Value_n[2]) +
                          rtb_Valuendx_b[5]) + claw_main_P.ixxb3_Value_h[5];

    /* Constant: '<S441>/S' */
    rtb_S_o = claw_main_P.S_Value_e;

    /* Gain: '<S443>/Gain' */
    rtb_tratio_h = claw_main_P.Gain_Gain_bqf * rtb_u20_p;

    /* Constant: '<S444>/Constant1' */
    rtb_Constant1_j = claw_main_P.Constant1_Value_dn;

    /* Switch: '<S510>/SwitchControl' incorporates:
     *  Constant: '<S444>/zero1'
     *  Constant: '<S510>/Constant'
     *  Sum: '<S444>/Add'
     */
    if (claw_main_P.Constant_Value_nm > claw_main_P.SwitchControl_Threshold_a) {
      rtb_SwitchControl_h = rtb_LengON_j[5] + rtb_RengON_m[5];
    } else {
      rtb_SwitchControl_h = claw_main_P.zero1_Value_g;
    }

    /* Gain: '<S444>/sec_per_min' */
    rtb_sec_per_min_c = claw_main_P.sec_per_min_Gain_d * rtb_SwitchControl_h;

    /* Product: '<S446>/Product2' */
    rtb_Mach_k = max_1 / rtb_sos;

    /* Sum: '<S431>/Sum3' */
    rtb_NED_wind_ex[0] = rtb_w_est[0] - rtb_Product[0];
    rtb_NED_wind_ex[1] = rtb_w_est[1] - rtb_Product[1];
    rtb_NED_wind_ex[2] = rtb_w_est[2] - rtb_Product[2];
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Reshape_gr[i] * rtb_NED_wind_ex[0];
      rtb_dircos_0[i] += rtb_Reshape_gr[i + 3] * rtb_NED_wind_ex[1];
      rtb_dircos_0[i] += rtb_Reshape_gr[i + 6] * rtb_NED_wind_ex[2];
      rtb_dircos_b_1[i] = 0.0;
      rtb_dircos_b_1[i] += rtb_dircos_b[3 * i] * rtb_Assignment2[3];
      rtb_dircos_b_1[i] += rtb_dircos_b[3 * i + 1] * rtb_Assignment2[4];
      rtb_dircos_b_1[i] += rtb_dircos_b[3 * i + 2] * rtb_Assignment2[5];
      rtb_NEhdot_j[i] = claw_main_P.MatrixGain_Gain_n[i] * rtb_dircos_b_1[i];

      /* Product: '<S650>/Product2' */
      rtb_Product2_kx[i] = 0.0;
      rtb_Product2_kx[i] += rtb_inertia[i] * rtb_Assignment2[0];
      rtb_Product2_kx[i] += rtb_inertia[i + 3] * rtb_Assignment2[1];
      rtb_Product2_kx[i] += rtb_inertia[i + 6] * rtb_Assignment2[2];
    }

    rtb_orderatts_i_idx = claw_main_P.Gain1_Gain_d2[0] * rtb_dircos_0[0];

    /* Sum: '<S431>/Sum4' incorporates:
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     *  Gain: '<S431>/Gain'
     *  Product: '<S431>/Product3'
     *  Sum: '<S431>/Sum'
     *  Sum: '<S431>/Sum1'
     *  Sum: '<S434>/Sum'
     *  UnitDelay: '<S431>/Unit Delay1'
     */
    rtb_InterpolationnDusingPreLo_3 = ((rtb_sensors[13] - rtb_accels_cg_b[0]) *
      claw_main_P.Gain_Gain_oy[0] + (rtb_Gain1_idx_0 - rtb_delta_LLh_idx)) *
      rtb_control_input[99] + claw_main_DWork.UnitDelay1_DSTATE_e0[0];

    /* Product: '<S648>/Product2' */
    rtb_accels_cg_h[0] = rtb_Sum_mp[0] / claw_main_B.mass;
    rtb_InterpolationnDusingPreLo_5 = claw_main_P.Gain1_Gain_d2[1] *
      rtb_dircos_0[1];

    /* Sum: '<S431>/Sum4' incorporates:
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     *  Gain: '<S431>/Gain'
     *  Product: '<S431>/Product3'
     *  Sum: '<S431>/Sum'
     *  Sum: '<S431>/Sum1'
     *  Sum: '<S434>/Sum'
     *  UnitDelay: '<S431>/Unit Delay1'
     */
    rtb_UnitDelay_nf_idx = ((rtb_sensors[14] - rtb_accels_cg_b[1]) *
      claw_main_P.Gain_Gain_oy[1] + (rtb_Gain1_idx_1 - rtb_delta_LLh_idx_0)) *
      rtb_control_input[99] + claw_main_DWork.UnitDelay1_DSTATE_e0[1];

    /* Product: '<S648>/Product2' */
    rtb_accels_cg_h[1] = rtb_Sum_mp[1] / claw_main_B.mass;
    rtb_InterpolationnDusingPreLo_4 = claw_main_P.Gain1_Gain_d2[2] *
      rtb_dircos_0[2];

    /* Sum: '<S431>/Sum4' incorporates:
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     *  Gain: '<S431>/Gain'
     *  Product: '<S431>/Product3'
     *  Sum: '<S431>/Sum'
     *  Sum: '<S431>/Sum1'
     *  Sum: '<S434>/Sum'
     *  UnitDelay: '<S431>/Unit Delay1'
     */
    rtb_UnitDelay_nf_idx_0 = ((rtb_sensors[15] - rtb_accels_cg_b[2]) *
      claw_main_P.Gain_Gain_oy[2] + (rtb_Gain1_idx - rtb_Switch2_idx)) *
      rtb_control_input[99] + claw_main_DWork.UnitDelay1_DSTATE_e0[2];

    /* Product: '<S648>/Product2' */
    rtb_accels_cg_h[2] = rtb_Sum_mp[2] / claw_main_B.mass;

    /* Product: '<S650>/Product3' incorporates:
     *  Product: '<S653>/Product'
     *  Product: '<S653>/Product1'
     *  Product: '<S655>/Product'
     *  Product: '<S655>/Product1'
     *  Sum: '<S650>/Sum1'
     *  Sum: '<S653>/Sum'
     *  Sum: '<S655>/Sum'
     */
    rtb_delta_LLh_idx = (rtb_Sum_mp[3] - (rtb_Assignment2[1] * 0.0 -
      rtb_Assignment2[2] * 0.0)) - (rtb_Assignment2[1] * rtb_Product2_kx[2] -
      rtb_Assignment2[2] * rtb_Product2_kx[1]);
    rtb_delta_LLh_idx_0 = (rtb_Sum_mp[4] - (rtb_Assignment2[2] * 0.0 -
      rtb_Assignment2[0] * 0.0)) - (rtb_Assignment2[2] * rtb_Product2_kx[0] -
      rtb_Assignment2[0] * rtb_Product2_kx[2]);
    rtb_Switch2_idx = (rtb_Sum_mp[5] - (rtb_Assignment2[0] * 0.0 -
      rtb_Assignment2[1] * 0.0)) - (rtb_Assignment2[0] * rtb_Product2_kx[1] -
      rtb_Assignment2[1] * rtb_Product2_kx[0]);
    for (i = 0; i < 3; i++) {
      rtb_pqrdot_a[i] = 0.0;
      rtb_pqrdot_a[i] += rtb_inertia_inv[i] * rtb_delta_LLh_idx;
      rtb_pqrdot_a[i] += rtb_inertia_inv[i + 3] * rtb_delta_LLh_idx_0;
      rtb_pqrdot_a[i] += rtb_inertia_inv[i + 6] * rtb_Switch2_idx;
    }

    /* Reshape: '<S656>/Reshape' incorporates:
     *  Gain: '<S656>/Gain1'
     */
    rtb_MatrixConcatenation_m[0] = claw_main_P.Gain1_Gain_ao[0] *
      rtb_Assignment2[10];
    rtb_MatrixConcatenation_m[1] = claw_main_P.Gain1_Gain_ao[1] *
      rtb_Assignment2[9];
    rtb_MatrixConcatenation_m[2] = claw_main_P.Gain1_Gain_ao[2] *
      rtb_Assignment2[12];
    rtb_MatrixConcatenation_m[3] = claw_main_P.Gain1_Gain_ao[3] *
      rtb_Assignment2[11];

    /* Reshape: '<S656>/Reshape1' incorporates:
     *  Gain: '<S656>/Gain2'
     */
    rtb_MatrixConcatenation_m[4] = claw_main_P.Gain2_Gain_jd[0] *
      rtb_Assignment2[11];
    rtb_MatrixConcatenation_m[5] = claw_main_P.Gain2_Gain_jd[1] *
      rtb_Assignment2[12];
    rtb_MatrixConcatenation_m[6] = claw_main_P.Gain2_Gain_jd[2] *
      rtb_Assignment2[9];
    rtb_MatrixConcatenation_m[7] = claw_main_P.Gain2_Gain_jd[3] *
      rtb_Assignment2[10];

    /* Reshape: '<S656>/Reshape2' incorporates:
     *  Gain: '<S656>/Gain3'
     */
    rtb_MatrixConcatenation_m[8] = claw_main_P.Gain3_Gain_gx[0] *
      rtb_Assignment2[12];
    rtb_MatrixConcatenation_m[9] = claw_main_P.Gain3_Gain_gx[1] *
      rtb_Assignment2[11];
    rtb_MatrixConcatenation_m[10] = claw_main_P.Gain3_Gain_gx[2] *
      rtb_Assignment2[10];
    rtb_MatrixConcatenation_m[11] = claw_main_P.Gain3_Gain_gx[3] *
      rtb_Assignment2[9];

    /* Gain: '<S652>/Gain4' incorporates:
     *  Product: '<S652>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_MatrixConcatenation_j_0[i] = 0.0;
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_m[i] *
        rtb_Assignment2[0];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_m[i + 4] *
        rtb_Assignment2[1];
      rtb_MatrixConcatenation_j_0[i] += rtb_MatrixConcatenation_m[i + 8] *
        rtb_Assignment2[2];
    }

    rtb_Gain4_a[0] = claw_main_P.Gain4_Gain_a5 * rtb_MatrixConcatenation_j_0[0];
    rtb_Gain4_a[1] = claw_main_P.Gain4_Gain_a5 * rtb_MatrixConcatenation_j_0[1];
    rtb_Gain4_a[2] = claw_main_P.Gain4_Gain_a5 * rtb_MatrixConcatenation_j_0[2];
    rtb_Gain4_a[3] = claw_main_P.Gain4_Gain_a5 * rtb_MatrixConcatenation_j_0[3];

    /* Selector: '<S665>/Value(ndx,:)' incorporates:
     *  Constant: '<S665>/Gain1'
     */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 6; uDimIdx++) {
      rtb_Valuendx_k[yOffset] = claw_main_P.Gain1_Value_g[7 * uDimIdx + (int32_T)
        rtb_FromWorkspace];
      yOffset++;
    }

    /* Switch: '<S663>/Switch' incorporates:
     *  Constant: '<S663>/xCG3'
     *  Constant: '<S663>/xCG5'
     */
    for (i = 0; i < 6; i++) {
      if (rtb_Sum_ow_idx_2 >= claw_main_P.Switch_Threshold_go) {
        rtb_Switch_f5[i] = claw_main_P.xCG3_Value_d[i];
      } else {
        rtb_Switch_f5[i] = claw_main_P.xCG5_Value_p[i];
      }
    }

    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_j,
      &claw_main_B.sf_EmbeddedMATLABFunction_k, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_k);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_j,
      &claw_main_B.sf_EmbeddedMATLABFunction_i, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_i);
    claw_mai_EmbeddedMATLABFunction(claw_main_P.zero2_Value_j,
      &claw_main_B.sf_EmbeddedMATLABFunction_f, (rtP_EmbeddedMATLABFunction_claw
      *) &claw_main_P.sf_EmbeddedMATLABFunction_f);

    /* Gain: '<S663>/Gain' */
    rtb_Gain_ng = claw_main_P.Gain_Gain_el * rtb_gwest;

    /* Reshape: '<S663>/Reshape1' incorporates:
     *  Constant: '<S663>/ixxb3'
     *  Constant: '<S666>/xCG6'
     *  Sum: '<S663>/Add1'
     */
    rtb_Reshape1_hn[0] = ((rtb_Switch_f5[0] +
      claw_main_B.sf_EmbeddedMATLABFunction_k.y) + rtb_Valuendx_k[0]) +
      claw_main_P.ixxb3_Value_b[0];
    rtb_Reshape1_hn[1] = ((rtb_Switch_f5[1] +
      claw_main_B.sf_EmbeddedMATLABFunction_i.y) + rtb_Valuendx_k[1]) +
      claw_main_P.ixxb3_Value_b[1];
    rtb_Reshape1_hn[2] = ((rtb_Switch_f5[2] +
      claw_main_B.sf_EmbeddedMATLABFunction_f.y) + rtb_Valuendx_k[2]) +
      claw_main_P.ixxb3_Value_b[2];
    rtb_Reshape1_hn[3] = ((rtb_Switch_f5[3] + claw_main_P.xCG6_Value_cu[0]) +
                          rtb_Valuendx_k[3]) + claw_main_P.ixxb3_Value_b[3];
    rtb_Reshape1_hn[4] = ((rtb_Switch_f5[4] + claw_main_P.xCG6_Value_cu[1]) +
                          rtb_Valuendx_k[4]) + claw_main_P.ixxb3_Value_b[4];
    rtb_Reshape1_hn[5] = ((rtb_Switch_f5[5] + claw_main_P.xCG6_Value_cu[2]) +
                          rtb_Valuendx_k[5]) + claw_main_P.ixxb3_Value_b[5];

    /* Constant: '<S657>/S' */
    rtb_S_b = claw_main_P.S_Value_h;

    /* Gain: '<S659>/Gain' */
    rtb_tratio_g = claw_main_P.Gain_Gain_kf * rtb_u20_p;

    /* Constant: '<S660>/Constant1' */
    rtb_Constant1_m = claw_main_P.Constant1_Value_ke;

    /* Switch: '<S726>/SwitchControl' incorporates:
     *  Constant: '<S660>/zero1'
     *  Constant: '<S726>/Constant'
     *  Sum: '<S660>/Add'
     */
    if (claw_main_P.Constant_Value_bp > claw_main_P.SwitchControl_Threshold_cm)
    {
      rtb_SwitchControl_p = rtb_LengON[5] + rtb_RengON[5];
    } else {
      rtb_SwitchControl_p = claw_main_P.zero1_Value_l;
    }

    /* Gain: '<S660>/sec_per_min' */
    rtb_sec_per_min_n = claw_main_P.sec_per_min_Gain_h * rtb_SwitchControl_p;

    /* Product: '<S662>/Product2' */
    rtb_Mach_g = max_5 / rtb_sos;

    /* Reshape: '<S761>/Reshape1' */
    memcpy((void *)&rtb_Reshape1_gq[0], (void *)(&claw_main_B.SFunction[4]), 66U
           * (uint32_T)((char_T *)(&claw_main_B.SFunction[1]) - (char_T *)
                        (&claw_main_B.SFunction[0])));

    /* Selector: '<S10>/Selector' */
    yOffset = 0;
    for (uDimIdx = 0; uDimIdx < 2; uDimIdx++) {
      i = 22 * tmp_9[uDimIdx];
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        rtb_solve_dat[yOffset] = rtb_Reshape1_gq[i + yOffset_0];
        yOffset++;
      }
    }

    /* Math: '<S793>/Math Function1' */
    rtb_Rslant_o = rt_hypot_snf(rtb_Rground_f, rtb_Gain1_lr_idx);

    /* Selector: '<S797>/order atts' incorporates:
     *  Constant: '<S797>/Constant'
     *  Selector: '<S797>/Selector'
     */
    rtb_orderatts_j[0] = rtb_TmpHiddenBufferAtorderatt_g[(int32_T)
      claw_main_P.Constant_Value_kgk[(int32_T)rtb_att_type - 1] - 1];
    rtb_orderatts_j[1] = rtb_TmpHiddenBufferAtorderatt_g[(int32_T)
      claw_main_P.Constant_Value_kgk[(int32_T)rtb_att_type + 4] - 1];
    rtb_orderatts_j[2] = rtb_TmpHiddenBufferAtorderatt_g[(int32_T)
      claw_main_P.Constant_Value_kgk[(int32_T)rtb_att_type + 9] - 1];

    /* SwitchCase: '<S797>/Switch Case' incorporates:
     *  ActionPort: '<S799>/Action Port'
     *  ActionPort: '<S800>/Action Port'
     *  ActionPort: '<S801>/Action Port'
     *  SubSystem: '<S797>/mba'
     *  SubSystem: '<S797>/tiltcam'
     *  SubSystem: '<S797>/ypr'
     */
    switch ((int32_T)rtb_att_type) {
     case 1:
      claw_main_tiltcam(rtb_orderatts_j, claw_main_B.Merge_g,
                        (rtP_tiltcam_claw_main *) &claw_main_P.tiltcam_g);
      break;

     case 2:
     case 3:
      claw_main_ypr(rtb_orderatts_j, claw_main_B.Merge_g, (rtP_ypr_claw_main *)
                    &claw_main_P.ypr_n);
      break;

     case 4:
     case 5:
      claw_main_mba(rtb_orderatts_j, rtb_Product_h, rtb_Sum_m, rtb_Sum1_p,
                    rtb_Product5, rtb_Sum2_l, rtb_Sum3, rtb_Gain_p,
                    rtb_Product10, rtb_Product11, claw_main_B.Merge_g,
                    (rtP_mba_claw_main *) &claw_main_P.mba_j);
      break;
    }

    /* Gain: '<S815>/Gain' incorporates:
     *  Constant: '<S815>/Constant'
     *  Gain: '<S815>/Matrix Gain'
     *  Sum: '<S815>/Sum'
     */
    for (i = 0; i < 16; i++) {
      tmp_8[i] = 0.0;
      for (yOffset_0 = 0; yOffset_0 < 9; yOffset_0++) {
        tmp_8[i] += claw_main_P.MatrixGain_Gain_hw[(yOffset_0 << 4) + i] *
          claw_main_B.Merge_g[yOffset_0];
      }

      rtb_Gain_c3[i] = (tmp_8[i] + claw_main_P.Constant_Value_b42[i]) *
        claw_main_P.Gain_Gain_ko;
    }

    /* SignalConversion: '<S815>/TmpHiddenBufferAtselect best diagInport1' */
    rtb_TmpHiddenBufferAtselectbe_g[0] = rtb_Gain_c3[0];
    rtb_TmpHiddenBufferAtselectbe_g[1] = rtb_Gain_c3[5];
    rtb_TmpHiddenBufferAtselectbe_g[2] = rtb_Gain_c3[10];
    rtb_TmpHiddenBufferAtselectbe_g[3] = rtb_Gain_c3[15];

    /* MinMax: '<S815>/MinMax3' */
    max_1 = rt_MAXd_snf(rtb_TmpHiddenBufferAtselectbe_g[0],
                        rtb_TmpHiddenBufferAtselectbe_g[1]);
    max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbe_g[2]);
    max_1 = rt_MAXd_snf(max_1, rtb_TmpHiddenBufferAtselectbe_g[3]);

    /* Switch: '<S815>/argmax1' incorporates:
     *  Constant: '<S815>/Constant4'
     *  Constant: '<S815>/Constant5'
     *  Sum: '<S815>/Sum2'
     */
    if (rtb_TmpHiddenBufferAtselectbe_g[0] - max_1 >=
        claw_main_P.argmax1_Threshold_b) {
      rtb_delta_LLh_idx = claw_main_P.Constant4_Value_mr[0];
    } else {
      rtb_delta_LLh_idx = claw_main_P.Constant5_Value_m;
    }

    if (rtb_TmpHiddenBufferAtselectbe_g[1] - max_1 >=
        claw_main_P.argmax1_Threshold_b) {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant4_Value_mr[1];
    } else {
      rtb_delta_LLh_idx_0 = claw_main_P.Constant5_Value_m;
    }

    if (rtb_TmpHiddenBufferAtselectbe_g[2] - max_1 >=
        claw_main_P.argmax1_Threshold_b) {
      rtb_Switch2_idx = claw_main_P.Constant4_Value_mr[2];
    } else {
      rtb_Switch2_idx = claw_main_P.Constant5_Value_m;
    }

    if (rtb_TmpHiddenBufferAtselectbe_g[3] - max_1 >=
        claw_main_P.argmax1_Threshold_b) {
      rtb_Gain1_idx_0 = claw_main_P.Constant4_Value_mr[3];
    } else {
      rtb_Gain1_idx_0 = claw_main_P.Constant5_Value_m;
    }

    /* MinMax: '<S815>/MinMax4' */
    max_1 = rt_MINd_snf(rtb_delta_LLh_idx, rtb_delta_LLh_idx_0);
    max_1 = rt_MINd_snf(max_1, rtb_Switch2_idx);
    max_1 = rt_MINd_snf(max_1, rtb_Gain1_idx_0);

    /* Selector: '<S815>/select best diag' */
    rtb_selectbestdiag_o = rtb_TmpHiddenBufferAtselectbe_g[(int32_T)max_1 - 1];

    /* Math: '<S815>/Math Function' */
    if (rtb_selectbestdiag_o < 0.0) {
      rtb_MathFunction_ie = -sqrt(-rtb_selectbestdiag_o);
    } else {
      rtb_MathFunction_ie = sqrt(rtb_selectbestdiag_o);
    }

    /* Selector: '<S815>/select best col' incorporates:
     *  Reshape: '<S815>/Reshape1'
     */
    i = ((int32_T)max_1 - 1) << 2;

    /* Product: '<S815>/Product' */
    rtb_Gain1_idx_0 = rtb_Gain_c3[i] / rtb_MathFunction_ie;
    rtb_Gain1_idx_1 = rtb_Gain_c3[i + 1] / rtb_MathFunction_ie;
    rtb_Gain1_idx = rtb_Gain_c3[i + 2] / rtb_MathFunction_ie;
    rtb_MultiportSwitch2_idx_2 = rtb_Gain_c3[i + 3] / rtb_MathFunction_ie;

    /* Switch: '<S814>/Switch' incorporates:
     *  Gain: '<S814>/Gain'
     *  Reshape: '<S815>/Reshape2'
     *  S-Function (sfix_dot): '<S814>/Dot Product'
     *  UnitDelay: '<S798>/Unit Delay'
     */
    rtb_delta_LLh_idx = ((rtb_Gain1_idx_0 * claw_main_DWork.UnitDelay_DSTATE_m[0]
                          + rtb_Gain1_idx_1 *
                          claw_main_DWork.UnitDelay_DSTATE_m[1]) + rtb_Gain1_idx
                         * claw_main_DWork.UnitDelay_DSTATE_m[2]) +
      rtb_MultiportSwitch2_idx_2 * claw_main_DWork.UnitDelay_DSTATE_m[3];
    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_e)) {
      rtb_Gain1_idx_0 *= claw_main_P.Gain_Gain_fi;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_e)) {
      rtb_Gain1_idx_1 *= claw_main_P.Gain_Gain_fi;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_e)) {
      rtb_Gain1_idx *= claw_main_P.Gain_Gain_fi;
    }

    if (!(rtb_delta_LLh_idx >= claw_main_P.Switch_Threshold_e)) {
      rtb_MultiportSwitch2_idx_2 *= claw_main_P.Gain_Gain_fi;
    }

    /* Update for UnitDelay: '<S332>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE[0] = rtb_Switch_idx;
    claw_main_DWork.UnitDelay1_DSTATE[1] = rtb_Switch_idx_0;
    claw_main_DWork.UnitDelay1_DSTATE[2] = rtb_Switch_idx_1;
    claw_main_DWork.UnitDelay1_DSTATE[3] = rtb_Switch_idx_2;

    /* Update for UnitDelay: '<S199>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_d = rtb_MultiportSwitch_cn[6];

    /* Update for UnitDelay: '<S105>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE[0] = (real_T)rtb_LogicalOperator4_h;
    claw_main_DWork.DelayInput1_DSTATE[1] = (real_T)rtb_LogicalOperator4_h;
    claw_main_DWork.DelayInput1_DSTATE[2] = (real_T)rtb_LogicalOperator2;

    /* Update for UnitDelay: '<S146>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j = rtb_MinMax4;

    /* Update for Memory: '<S313>/Memory1' */
    claw_main_DWork.Memory1_PreviousInput = rtb_Switch_k;

    /* Update for Memory: '<S313>/Memory' incorporates:
     *  Constant: '<S313>/Constant'
     */
    claw_main_DWork.Memory_PreviousInput = claw_main_P.Constant_Value_ejl;

    /* Update for UnitDelay: '<S104>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE_c = rtb_att_type;

    /* Update for UnitDelay: '<S96>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m1 = rtb_control_input[94];

    /* Update for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[0] = rtb_Switch3_idx;

    /* Update for DiscreteIntegrator: '<S425>/integration1' incorporates:
     *  Sum: '<S425>/Sum2'
     */
    claw_main_DWork.integration1_DSTATE[0] = (rtb_Gain_idx + rtb_Product1_b_idx)
      * claw_main_P.integration1_gainval + claw_main_DWork.integration1_DSTATE[0];

    /* Update for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[0] = rtb_NEh_idx;

    /* Update for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      claw_main_P.DiscreteTimeIntegrator_gainval *
      rtb_InterpolationnDusingPreLo_3 +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0];

    /* Update for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[0] = max[0];

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[0] = (real_T)rtb_LogicalOperator3_idx;
    claw_main_DWork.attcmdintegration_DSTATE[0] = rtb_MultiportSwitch2_idx *
      (real_T)rtb_LogicalOperator4_h * claw_main_P.attcmdintegration_gainval +
      claw_main_DWork.attcmdintegration_DSTATE[0];

    /* Update for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[0] = rtb_Switch_f_idx_0;

    /* Update for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[1] = rtb_Switch3_idx_0;

    /* Update for DiscreteIntegrator: '<S425>/integration1' incorporates:
     *  Sum: '<S425>/Sum2'
     */
    claw_main_DWork.integration1_DSTATE[1] = (rtb_Gain_idx_0 + rtb_Gain_g_idx_4)
      * claw_main_P.integration1_gainval + claw_main_DWork.integration1_DSTATE[1];

    /* Update for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[1] = rtb_NEh_idx_0;

    /* Update for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      claw_main_P.DiscreteTimeIntegrator_gainval * rtb_UnitDelay_nf_idx +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1];

    /* Update for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[1] = max[1];

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[1] = (real_T)rtb_LogicalOperator3_idx_0;
    claw_main_DWork.attcmdintegration_DSTATE[1] = rtb_MultiportSwitch2_idx_0 *
      (real_T)rtb_LogicalOperator4_h * claw_main_P.attcmdintegration_gainval +
      claw_main_DWork.attcmdintegration_DSTATE[1];

    /* Update for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[1] = rtb_Switch_f_idx_1;

    /* Update for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[2] = rtb_Switch3_idx_1;

    /* Update for DiscreteIntegrator: '<S425>/integration1' incorporates:
     *  Sum: '<S425>/Sum2'
     */
    claw_main_DWork.integration1_DSTATE[2] = (rtb_Gain_idx_1 + rtb_Gain_g_idx_3)
      * claw_main_P.integration1_gainval + claw_main_DWork.integration1_DSTATE[2];

    /* Update for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[2] = rtb_NEh_idx_1;

    /* Update for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2] =
      claw_main_P.DiscreteTimeIntegrator_gainval * rtb_UnitDelay_nf_idx_0 +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2];

    /* Update for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[2] = max[2];

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[2] = (real_T)rtb_LogicalOperator3_idx_1;
    claw_main_DWork.attcmdintegration_DSTATE[2] = rtb_MultiportSwitch2_idx_1 *
      (real_T)rtb_LogicalOperator2 * claw_main_P.attcmdintegration_gainval +
      claw_main_DWork.attcmdintegration_DSTATE[2];

    /* Update for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[2] = rtb_Switch_f_idx;

    /* Update for UnitDelay: '<S96>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE = max_2;

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    memcpy((void *)(&claw_main_DWork.UnitDelay_DSTATE_je[0]), (void *)
           &rtb_MultiportSwitch1_d[0], 10U * (uint32_T)((char_T *)
            &rtb_MultiportSwitch1_d[1U] - (char_T *)&rtb_MultiportSwitch1_d[0U]));

    /* Update for DiscreteIntegrator: '<S8>/mass' */
    claw_main_DWork.mass_DSTATE = claw_main_P.mass_gainval * rtb_Gain1_a1 +
      claw_main_DWork.mass_DSTATE;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_h[0] = rtb_Gain1_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_h[1] = rtb_Gain1_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_h[2] = rtb_Gain1_idx;
    claw_main_DWork.UnitDelay_DSTATE_h[3] = rtb_MultiportSwitch2_idx_2;
    claw_main_DWork.UnitDelay_DSTATE_h[4] = rtb_Sum4_e_idx;

    /* Update for UnitDelay: '<S188>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_g[0] = rtb_MultiportSwitch_n_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_g[1] = rtb_MultiportSwitch_n_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_g[2] = rtb_MultiportSwitch_n_idx;

    /* Update for UnitDelay: '<S190>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_e[0] = rtb_Product5_m_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_e[1] = rtb_Product5_m_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_e[2] = rtb_Product5_m_idx;

    /* Update for UnitDelay: '<S754>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_e[3] = rtb_Reshape_n[19];

    /* Update for UnitDelay: '<S186>/Unit Delay2' incorporates:
     *  Sum: '<S186>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_a[0] = rtb_orderatts_i_idx_0 +
      rtb_X_idx_idx;

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] =
      claw_main_B.DiscreteTimeIntegrator[0];
    claw_main_DWork.UnitDelay_DSTATE_a[0] = rtb_Product5_b_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_e[4] = rtb_Reshape_n[20];

    /* Update for UnitDelay: '<S186>/Unit Delay2' incorporates:
     *  Sum: '<S186>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_a[1] = rtb_MathFunction_lo_idx_1 +
      rtb_Assignment_pi_idx;

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] =
      claw_main_B.DiscreteTimeIntegrator[1];
    claw_main_DWork.UnitDelay_DSTATE_a[1] = rtb_Product5_b_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_e[5] = rtb_Reshape_n[21];

    /* Update for UnitDelay: '<S186>/Unit Delay2' incorporates:
     *  Sum: '<S186>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_a[2] = rtb_MathFunction_lo_idx_2 +
      rtb_Assignment_l_idx;

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] =
      claw_main_B.DiscreteTimeIntegrator[2];
    claw_main_DWork.UnitDelay_DSTATE_a[2] = rtb_Product5_b_idx;
    claw_main_DWork.UnitDelay_DSTATE_a[3] = rtb_Reshape_n[43];
    claw_main_DWork.UnitDelay_DSTATE_a[4] = rtb_Reshape_n[44];
    claw_main_DWork.UnitDelay_DSTATE_a[5] = rtb_Reshape_n[45];

    /* Update for UnitDelay: '<S523>/Unit Delay2' incorporates:
     *  Product: '<S523>/Product1'
     *  Product: '<S523>/Product3'
     *  Product: '<S524>/Product'
     *  Sum: '<S523>/Sum7'
     *  Sum: '<S524>/Sum1'
     */
    rtb_Switch2_idx = rtb_switchattcmd[0] - rtb_Sum4_e_idx_0;
    rtb_delta_LLh_idx_0 = rtb_switchattcmd[1] - rtb_Sum4_e_idx_1;
    rtb_delta_LLh_idx = rtb_switchthrotcmd - rtb_Sum4_e_idx;
    for (i = 0; i < 3; i++) {
      rtb_dircos_0[i] = 0.0;
      rtb_dircos_0[i] += rtb_Assignment_m[i] * rtb_Switch2_idx;
      rtb_dircos_0[i] += rtb_Assignment_m[i + 3] * rtb_delta_LLh_idx_0;
      rtb_dircos_0[i] += rtb_Assignment_m[i + 6] * rtb_delta_LLh_idx;
    }

    claw_main_DWork.UnitDelay2_DSTATE_d[0] = rtb_orderatts_a_idx *
      rtb_Sum5_p_idx + min_5 * rtb_dircos_0[0];

    /* Update for DiscreteIntegrator: '<S523>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] =
      claw_main_B.DiscreteTimeIntegrator_o[0];
    claw_main_DWork.UnitDelay2_DSTATE_d[1] = rtb_MathFunction_lo_idx *
      rtb_Sum5_p_idx_0 + rtb_MathFunction_lo_idx_0 * rtb_dircos_0[1];

    /* Update for DiscreteIntegrator: '<S523>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] =
      claw_main_B.DiscreteTimeIntegrator_o[1];
    claw_main_DWork.UnitDelay2_DSTATE_d[2] = rtb_MultiportSwitch_o_idx_0 *
      rtb_Sum4_c_idx_0 + rtb_orderatts_i_idx_1 * rtb_dircos_0[2];

    /* Update for DiscreteIntegrator: '<S523>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] =
      claw_main_B.DiscreteTimeIntegrator_o[2];

    /* Update for Memory: '<S757>/Memory' */
    claw_main_DWork.Memory_PreviousInput_d = claw_main_B.SFunction[3];

    /* Update for UnitDelay: '<S21>/Unit Delay' */

    /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0] =
      claw_main_P.DiscreteTimeIntegrator_gainva_f * rtb_Sum1_e_idx +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0];
    claw_main_DWork.UnitDelay_DSTATE_b[0] = rtb_Product5_f_idx;

    /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1] =
      claw_main_P.DiscreteTimeIntegrator_gainva_f * rtb_Sum1_e_idx_0 +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1];
    claw_main_DWork.UnitDelay_DSTATE_b[1] = rtb_Product5_f_idx_0;

    /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2] =
      claw_main_P.DiscreteTimeIntegrator_gainva_f * rtb_Sum1_e_idx_1 +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2];
    claw_main_DWork.UnitDelay_DSTATE_b[2] = rtb_Product5_f_idx_1;

    /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3] =
      claw_main_P.DiscreteTimeIntegrator_gainva_f * rtb_Sum1_e_idx_2 +
      claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3];
    claw_main_DWork.UnitDelay_DSTATE_b[3] = rtb_Product5_f_idx_2;
    claw_main_DWork.UnitDelay_DSTATE_b[4] = rtb_Reshape_n[4];

    /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
     *  Sum: '<S20>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_e[0] = rtb_uvw_rw_idx_0 +
      rtb_Product2_a_idx_2;

    /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] =
      claw_main_B.DiscreteTimeIntegrator_p[0];
    claw_main_DWork.UnitDelay_DSTATE_b[5] = rtb_Reshape_n[5];

    /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
     *  Sum: '<S20>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_e[1] = rtb_MultiportSwitch1_idx +
      rtb_Gain4_idx_2;

    /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] =
      claw_main_B.DiscreteTimeIntegrator_p[1];
    claw_main_DWork.UnitDelay_DSTATE_b[6] = rtb_Reshape_n[6];

    /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
     *  Sum: '<S20>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_e[2] = rtb_MultiportSwitch1_idx_0 +
      rtb_Product2_a_idx_1;

    /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] =
      claw_main_B.DiscreteTimeIntegrator_p[2];
    claw_main_DWork.UnitDelay_DSTATE_b[7] = rtb_Reshape_n[7];

    /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
     *  Sum: '<S20>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_e[3] = rtb_MultiportSwitch1_idx_1 +
      rtb_Gain4_idx_1;

    /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] =
      claw_main_B.DiscreteTimeIntegrator_p[3];

    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_m = rtb_MultiportSwitch_k_idx_2;

    /* Update for UnitDelay: '<S6>/Unit Delay2' */
    memcpy((void *)(&claw_main_DWork.UnitDelay2_DSTATE_i[0]), (void *)
           &rtb_Sum4_j[0], (uint32_T)((char_T *)&rtb_Sum4_j[1U] - (char_T *)
            &rtb_Sum4_j[0U]) << 3U);
    claw_main_DWork.UnitDelay2_DSTATE_i[8] = rtb_rcs_cmd;

    /* Update for UnitDelay: '<S295>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_pq[0] = rtb_Product5_hf_idx;
    claw_main_DWork.UnitDelay_DSTATE_pq[1] = rtb_Product5_hf_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_pq[2] = rtb_Product5_hf_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_pq[3] = rtb_Reshape_n[31];

    /* Update for UnitDelay: '<S195>/Unit Delay2' incorporates:
     *  Sum: '<S195>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_eb[0] = rtb_MultiportSwitch_c_idx +
      rtb_Sum_h_idx;

    /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] =
      claw_main_B.DiscreteTimeIntegrator_j[0];

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[0] = rtb_dir_idx;
    claw_main_DWork.UnitDelay_DSTATE_pq[4] = rtb_Reshape_n[32];

    /* Update for UnitDelay: '<S195>/Unit Delay2' incorporates:
     *  Sum: '<S195>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_eb[1] = rtb_MultiportSwitch_c_idx_0 +
      rtb_Product1_b_idx_1;

    /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] =
      claw_main_B.DiscreteTimeIntegrator_j[1];

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[1] = rtb_dir_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_pq[5] = rtb_Reshape_n[33];

    /* Update for UnitDelay: '<S195>/Unit Delay2' incorporates:
     *  Sum: '<S195>/Sum7'
     */
    claw_main_DWork.UnitDelay2_DSTATE_eb[2] = rtb_eow_idx_idx +
      rtb_Product1_b_idx_0;

    /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] =
      claw_main_B.DiscreteTimeIntegrator_j[2];

    /* Update for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[2] = eml_a_idx;

    /* Update for UnitDelay: '<S197>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_an = (real_T)rtb_use_bb;

    /* Update for UnitDelay: '<S197>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e = rtb_timer;

    /* Update for Memory: '<S303>/Memory' */
    claw_main_DWork.Memory_PreviousInput_j = claw_main_B.SFunction_g[8];

    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_h[0] = rtb_Sum4_l_idx;
    claw_main_DWork.UnitDelay1_DSTATE_h[1] = rtb_Sum4_l_idx_0;
    claw_main_DWork.UnitDelay1_DSTATE_h[2] = rtb_Sum4_l_idx_1;
    claw_main_DWork.UnitDelay1_DSTATE_h[3] = rtb_Sum4_l_idx_2;

    /* Update for UnitDelay: '<S99>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_f = (real_T)rtb_LogicalOperator;

    /* Update for UnitDelay: '<S333>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_d[0] = rtb_w_est[0];

    /* Update for UnitDelay: '<S431>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e0[0] = rtb_orderatts_i_idx;

    /* Update for UnitDelay: '<S333>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_d[1] = rtb_w_est[1];

    /* Update for UnitDelay: '<S431>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e0[1] = rtb_InterpolationnDusingPreLo_5;

    /* Update for UnitDelay: '<S333>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_d[2] = rtb_w_est[2];

    /* Update for UnitDelay: '<S431>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e0[2] = rtb_InterpolationnDusingPreLo_4;

    /* Update for UnitDelay: '<S798>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_m[0] = rtb_Gain1_idx_0;
    claw_main_DWork.UnitDelay_DSTATE_m[1] = rtb_Gain1_idx_1;
    claw_main_DWork.UnitDelay_DSTATE_m[2] = rtb_Gain1_idx;
    claw_main_DWork.UnitDelay_DSTATE_m[3] = rtb_MultiportSwitch2_idx_2;

    /* end of Outputs for SubSystem: '<Root>/claw_main' */

    /* Outport: '<Root>/commandb' */
    claw_main_Y.commandb[0] = rtb_control_input[0];
    claw_main_Y.commandb[1] = rtb_control_input[1];
    claw_main_Y.commandb[2] = rtb_control_input[2];
    claw_main_Y.commandb[3] = rtb_control_input[3];
    for (i = 0; i < 10; i++) {
      /* Outport: '<Root>/u_out' */
      claw_main_Y.u_out[i] = rtb_MultiportSwitch1_d[i];

      /* Outport: '<Root>/full_surf_cmdb' */
      claw_main_Y.full_surf_cmdb[i] = rtb_control_input[i + 4];

      /* Outport: '<Root>/full_surf_ulimb' */
      claw_main_Y.full_surf_ulimb[i] = rtb_control_input[i + 14];

      /* Outport: '<Root>/full_surf_llimb' */
      claw_main_Y.full_surf_llimb[i] = rtb_control_input[i + 24];

      /* Outport: '<Root>/full_surf_urlimb' */
      claw_main_Y.full_surf_urlimb[i] = rtb_control_input[i + 34];

      /* Outport: '<Root>/full_surf_lrlimb' */
      claw_main_Y.full_surf_lrlimb[i] = rtb_control_input[i + 44];

      /* Outport: '<Root>/full_surf_lockb' */
      claw_main_Y.full_surf_lockb[i] = rtb_control_input[i + 54];

      /* Outport: '<Root>/full_surf_pref_selectb' */
      claw_main_Y.full_surf_pref_selectb[i] = rtb_control_input[i + 64];

      /* Outport: '<Root>/full_surf_prefb' */
      claw_main_Y.full_surf_prefb[i] = rtb_control_input[i + 74];

      /* Outport: '<Root>/full_surf_pref_wghtb' */
      claw_main_Y.full_surf_pref_wghtb[i] = rtb_control_input[i + 84];
    }

    /* Outport: '<Root>/CLAW_modeb' */
    claw_main_Y.CLAW_modeb = rtb_control_input[94];

    /* Outport: '<Root>/engaged_swb' */
    claw_main_Y.engaged_swb = rtb_control_input[95];

    /* Outport: '<Root>/accel_submodeb' */
    claw_main_Y.accel_submodeb = rtb_control_input[96];

    /* Outport: '<Root>/pre_takeoff_swb' */
    claw_main_Y.pre_takeoff_swb = rtb_control_input[97];

    /* Outport: '<Root>/reset_pos_swb' */
    claw_main_Y.reset_pos_swb = rtb_control_input[98];

    /* Outport: '<Root>/wind_est_swb' */
    claw_main_Y.wind_est_swb = rtb_control_input[99];

    /* Outport: '<Root>/llh_input_swb' */
    claw_main_Y.llh_input_swb = rtb_control_input[100];

    /* Outport: '<Root>/int_reset_swb' */
    claw_main_Y.int_reset_swb = rtb_control_input[101];

    /* Outport: '<Root>/att_typeb' */
    claw_main_Y.att_typeb = rtb_control_input[102];

    /* Outport: '<Root>/cam_rate_cmd_swb' */
    claw_main_Y.cam_rate_cmd_swb = rtb_control_input[103];

    /* Outport: '<Root>/full_surf_cmd_swb' */
    claw_main_Y.full_surf_cmd_swb = rtb_control_input[104];

    /* Outport: '<Root>/enable_homing_swb' */
    claw_main_Y.enable_homing_swb = rtb_control_input[105];

    /* Outport: '<Root>/att_rate_cmd_swb' */
    claw_main_Y.att_rate_cmd_swb = rtb_control_input[106];

    /* Outport: '<Root>/nav_enable_swb' */
    claw_main_Y.nav_enable_swb = rtb_control_input[107];

    /* Outport: '<Root>/enable_bb_swb' */
    claw_main_Y.enable_bb_swb = rtb_control_input[108];

    /* Outport: '<Root>/gain_set_swb' */
    claw_main_Y.gain_set_swb = rtb_control_input[109];

    /* Outport: '<Root>/use_held_aero_obac_swb' */
    claw_main_Y.use_held_aero_obac_swb = rtb_control_input[110];

    /* Outport: '<Root>/Isp_slb' */
    claw_main_Y.Isp_slb = rtb_control_input[111];

    /* Outport: '<Root>/Isp_vacuumb' */
    claw_main_Y.Isp_vacuumb = rtb_control_input[112];

    /* Outport: '<Root>/throt_to_ffb' */
    claw_main_Y.throt_to_ffb = rtb_control_input[113];

    /* Outport: '<Root>/cvdex_smn' */
    claw_main_Y.cvdex_smn[0] = rtb_Sum5_d_idx_0;
    claw_main_Y.cvdex_smn[1] = rtb_Sum5_d_idx_1;
    claw_main_Y.cvdex_smn[2] = rtb_Sum5_d_idx;

    /* Outport: '<Root>/lambda' */
    claw_main_Y.lambda = claw_main_B.SFunction_g[8];

    /* Outport: '<Root>/solve_dat' */
    memcpy((void *)(&claw_main_Y.solve_dat[0]), (void *)&rtb_Selector_f[0], 18U *
           (uint32_T)((char_T *)&rtb_Selector_f[1U] - (char_T *)&rtb_Selector_f
                      [0U]));

    /* Outport: '<Root>/cvdex' */
    claw_main_Y.cvdex[0] = rtb_Sum5_b_idx;

    /* Outport: '<Root>/cvc' */
    claw_main_Y.cvc[0] = rtb_MultiportSwitch_k_idx;

    /* Outport: '<Root>/integ' */
    claw_main_Y.integ[0] = claw_main_B.DiscreteTimeIntegrator_j[0];

    /* Outport: '<Root>/cv' */
    claw_main_Y.cv[0] = rtb_sensors[0];

    /* Outport: '<Root>/cvdnom' */
    claw_main_Y.cvdnom[0] = rtb_xdot_nom[0];

    /* Outport: '<Root>/cvdex' */
    claw_main_Y.cvdex[1] = rtb_Sum5_b_idx_0;

    /* Outport: '<Root>/cvc' */
    claw_main_Y.cvc[1] = rtb_MultiportSwitch_k_idx_0;

    /* Outport: '<Root>/integ' */
    claw_main_Y.integ[1] = claw_main_B.DiscreteTimeIntegrator_j[1];

    /* Outport: '<Root>/cv' */
    claw_main_Y.cv[1] = rtb_sensors[1];

    /* Outport: '<Root>/cvdnom' */
    claw_main_Y.cvdnom[1] = rtb_xdot_nom[1];

    /* Outport: '<Root>/cvdex' */
    claw_main_Y.cvdex[2] = rtb_Sum5_b_idx_1;

    /* Outport: '<Root>/cvc' */
    claw_main_Y.cvc[2] = rtb_MultiportSwitch_k_idx_1;

    /* Outport: '<Root>/integ' */
    claw_main_Y.integ[2] = claw_main_B.DiscreteTimeIntegrator_j[2];

    /* Outport: '<Root>/cv' */
    claw_main_Y.cv[2] = rtb_sensors[2];

    /* Outport: '<Root>/cvdnom' */
    claw_main_Y.cvdnom[2] = rtb_xdot_nom[2];

    /* Outport: '<Root>/Bmat' */
    memcpy((void *)(&claw_main_Y.Bmat[0]), (void *)&rtb_Assignment_k[0], 27U *
           (uint32_T)((char_T *)&rtb_Assignment_k[1U] - (char_T *)
                      &rtb_Assignment_k[0U]));
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/u_ulim' */
      claw_main_Y.u_ulim[i] = max_7[i];

      /* Outport: '<Root>/u_llim' */
      claw_main_Y.u_llim[i] = max_6[i];

      /* Outport: '<Root>/u_pref' */
      claw_main_Y.u_pref[i] = rtb_MultiportSwitch_oq[i];
    }

    /* Outport: '<Root>/bb_debug' */
    memcpy((void *)(&claw_main_Y.bb_debug[0]), (void *)&rtb_debug_output[0], 12U
           * (uint32_T)((char_T *)&rtb_debug_output[1U] - (char_T *)
                        &rtb_debug_output[0U]));
    claw_main_Y.bb_debug[12] = rtb_cvddes_idx_0;
    claw_main_Y.bb_debug[13] = rtb_cvddes_idx_1;
    claw_main_Y.bb_debug[14] = rtb_cvddes_idx;
    claw_main_Y.bb_debug[15] = rtb_dir_idx;
    claw_main_Y.bb_debug[16] = rtb_dir_idx_0;
    claw_main_Y.bb_debug[17] = eml_a_idx;
    claw_main_Y.bb_debug[18] = (real_T)rtb_use_bb;
    claw_main_Y.bb_debug[19] = rtb_timer;
    claw_main_Y.bb_debug[20] = rtb_Sum4_k_idx;
    claw_main_Y.bb_debug[21] = rtb_Sum4_k_idx_0;
    claw_main_Y.bb_debug[22] = rtb_Sum4_k_idx_1;

    /* Outport: '<Root>/cvdexb' */
    claw_main_Y.cvdexb[0] = rtb_Sum4_li_idx;

    /* Outport: '<Root>/integb' */
    claw_main_Y.integb[0] = claw_main_B.DiscreteTimeIntegrator_p[0];

    /* Outport: '<Root>/cvcb' */
    claw_main_Y.cvcb[0] = rtb_Product_j3_idx;

    /* Outport: '<Root>/cvb' */
    claw_main_Y.cvb[0] = rtb_Switch_idx;

    /* Outport: '<Root>/cvdexb' */
    claw_main_Y.cvdexb[1] = rtb_Sum4_li_idx_0;

    /* Outport: '<Root>/integb' */
    claw_main_Y.integb[1] = claw_main_B.DiscreteTimeIntegrator_p[1];

    /* Outport: '<Root>/cvcb' */
    claw_main_Y.cvcb[1] = rtb_Product_j3_idx_0;

    /* Outport: '<Root>/cvb' */
    claw_main_Y.cvb[1] = rtb_Switch_idx_0;

    /* Outport: '<Root>/cvdexb' */
    claw_main_Y.cvdexb[2] = rtb_Sum4_li_idx_1;

    /* Outport: '<Root>/integb' */
    claw_main_Y.integb[2] = claw_main_B.DiscreteTimeIntegrator_p[2];

    /* Outport: '<Root>/cvcb' */
    claw_main_Y.cvcb[2] = rtb_Product_j3_idx_1;

    /* Outport: '<Root>/cvb' */
    claw_main_Y.cvb[2] = rtb_Switch_idx_1;

    /* Outport: '<Root>/cvdexb' */
    claw_main_Y.cvdexb[3] = rtb_Sum4_li_idx_2;

    /* Outport: '<Root>/integb' */
    claw_main_Y.integb[3] = claw_main_B.DiscreteTimeIntegrator_p[3];

    /* Outport: '<Root>/cvcb' */
    claw_main_Y.cvcb[3] = rtb_Product_j3_idx_2;

    /* Outport: '<Root>/cvb' */
    claw_main_Y.cvb[3] = rtb_Switch_idx_2;

    /* Outport: '<Root>/tiltcam_cmds' */
    claw_main_Y.tiltcam_cmds[0] = rtb_Sum_f3_idx_0;

    /* Outport: '<Root>/rpy_cmds' */
    claw_main_Y.rpy_cmds[0] = rtb_orderatts_a_idx_0;

    /* Outport: '<Root>/mab_cmds' */
    claw_main_Y.mab_cmds[0] = rtb_Sum_f3_idx_1;

    /* Outport: '<Root>/cvdexa' */
    claw_main_Y.cvdexa[0] = rtb_Sum5_p_idx;

    /* Outport: '<Root>/tiltcam_cmds' */
    claw_main_Y.tiltcam_cmds[1] = rtb_Gain4_idx_0;

    /* Outport: '<Root>/rpy_cmds' */
    claw_main_Y.rpy_cmds[1] = rtb_orderatts_a_idx_1;

    /* Outport: '<Root>/mab_cmds' */
    claw_main_Y.mab_cmds[1] = rtb_Gain4_idx;

    /* Outport: '<Root>/cvdexa' */
    claw_main_Y.cvdexa[1] = rtb_Sum5_p_idx_0;

    /* Outport: '<Root>/tiltcam_cmds' */
    claw_main_Y.tiltcam_cmds[2] = rtb_Product2_a_idx_0;

    /* Outport: '<Root>/rpy_cmds' */
    claw_main_Y.rpy_cmds[2] = rtb_Sum_f3_idx;

    /* Outport: '<Root>/mab_cmds' */
    claw_main_Y.mab_cmds[2] = rtb_Product2_a_idx;

    /* Outport: '<Root>/cvdexa' */
    claw_main_Y.cvdexa[2] = rtb_Sum4_c_idx_0;

    /* Outport: '<Root>/lambdab' */
    claw_main_Y.lambdab = claw_main_B.SFunction[3];

    /* Outport: '<Root>/solve_datb' */
    memcpy((void *)(&claw_main_Y.solve_datb[0]), (void *)&rtb_solve_dat[0], 18U *
           (uint32_T)((char_T *)&rtb_solve_dat[1U] - (char_T *)&rtb_solve_dat[0U]));

    /* Outport: '<Root>/intega' */
    claw_main_Y.intega[0] = claw_main_B.DiscreteTimeIntegrator_o[0];
    claw_main_Y.intega[1] = claw_main_B.DiscreteTimeIntegrator_o[1];
    claw_main_Y.intega[2] = claw_main_B.DiscreteTimeIntegrator_o[2];

    /* Outport: '<Root>/cvca' */
    claw_main_Y.cvca[0] = rtb_MultiportSwitch_n_idx_0;
    claw_main_Y.cvca[1] = rtb_MultiportSwitch_n_idx_1;
    claw_main_Y.cvca[2] = rtb_MultiportSwitch_n_idx;

    /* Outport: '<Root>/cva' */
    claw_main_Y.cva[0] = rtb_Gain_idx;

    /* Outport: '<Root>/cvdnomb' */
    claw_main_Y.cvdnomb[0] = rtb_Gain_kp_idx_0;

    /* Outport: '<Root>/cva' */
    claw_main_Y.cva[1] = rtb_Gain_idx_0;

    /* Outport: '<Root>/cvdnomb' */
    claw_main_Y.cvdnomb[1] = rtb_Gain_kp_idx_1;

    /* Outport: '<Root>/cva' */
    claw_main_Y.cva[2] = rtb_Gain_idx_1;

    /* Outport: '<Root>/cvdnomb' */
    claw_main_Y.cvdnomb[2] = rtb_Gain_kp_idx;

    /* Outport: '<Root>/Bmatb' */
    memcpy((void *)(&claw_main_Y.Bmatb[0]), (void *)&rtb_Assignment_m[0], 9U *
           (uint32_T)((char_T *)&rtb_Assignment_m[1U] - (char_T *)
                      &rtb_Assignment_m[0U]));

    /* Outport: '<Root>/Bmat_fltpath' incorporates:
     *  Product: '<S10>/Product1'
     */
    for (i = 0; i < 3; i++) {
      for (yOffset_0 = 0; yOffset_0 < 3; yOffset_0++) {
        claw_main_Y.Bmat_fltpath[i + 3 * yOffset_0] = 0.0;
        claw_main_Y.Bmat_fltpath[i + 3 * yOffset_0] = claw_main_Y.Bmat_fltpath[3
          * yOffset_0 + i] + rtb_Assignment_m[3 * yOffset_0] * rtb_Gain_e[i];
        claw_main_Y.Bmat_fltpath[i + 3 * yOffset_0] = rtb_Assignment_m[3 *
          yOffset_0 + 1] * rtb_Gain_e[i + 3] + claw_main_Y.Bmat_fltpath[3 *
          yOffset_0 + i];
        claw_main_Y.Bmat_fltpath[i + 3 * yOffset_0] = rtb_Assignment_m[3 *
          yOffset_0 + 2] * rtb_Gain_e[i + 6] + claw_main_Y.Bmat_fltpath[3 *
          yOffset_0 + i];
      }
    }

    /* Outport: '<Root>/u_ulimb' incorporates:
     *  Reshape: '<S787>/Reshape1'
     */
    claw_main_Y.u_ulimb[0] = rtb_Selector1_idx;
    claw_main_Y.u_llimb[0] = rtb_Selector2_idx;
    claw_main_Y.u_ulimb[1] = rtb_Selector1_idx_0;
    claw_main_Y.u_llimb[1] = rtb_Selector2_idx_0;
    claw_main_Y.u_ulimb[2] = max_4;

    /* Outport: '<Root>/u_llimb' incorporates:
     *  Reshape: '<S787>/Reshape3'
     */
    claw_main_Y.u_llimb[2] = min_4;

    /* Outport: '<Root>/cvcc' */
    claw_main_Y.cvcc[0] = rtb_MultiportSwitch_o_idx_1;
    claw_main_Y.cvcc[1] = rtb_MultiportSwitch_o_idx_2;
    claw_main_Y.cvcc[2] = rtb_MultiportSwitch_o_idx;
    for (i = 0; i < 3; i++) {
      /* Outport: '<Root>/cvdex_fltpath' incorporates:
       *  Product: '<S10>/Product'
       */
      claw_main_Y.cvdex_fltpath[i] = 0.0;
      claw_main_Y.cvdex_fltpath[i] = rtb_Gain_e[i] * rtb_Sum5_p_idx +
        claw_main_Y.cvdex_fltpath[i];
      claw_main_Y.cvdex_fltpath[i] = rtb_Gain_e[i + 3] * rtb_Sum5_p_idx_0 +
        claw_main_Y.cvdex_fltpath[i];
      claw_main_Y.cvdex_fltpath[i] = rtb_Gain_e[i + 6] * rtb_Sum4_c_idx_0 +
        claw_main_Y.cvdex_fltpath[i];

      /* Outport: '<Root>/cvdexc' */
      claw_main_Y.cvdexc[i] = rtb_Sum2_ht[i];

      /* Outport: '<Root>/integc' */
      claw_main_Y.integc[i] = claw_main_B.DiscreteTimeIntegrator[i];

      /* Outport: '<Root>/cvd' */
      claw_main_Y.cvd[i] = rtb_NEh_e[i];

      /* Outport: '<Root>/cvdex_fltpathb' incorporates:
       *  Product: '<S5>/Product'
       */
      claw_main_Y.cvdex_fltpathb[i] = 0.0;
      claw_main_Y.cvdex_fltpathb[i] = rtb_Gain_e[i] * rtb_Sum2_ht[0] +
        claw_main_Y.cvdex_fltpathb[i];
      claw_main_Y.cvdex_fltpathb[i] = rtb_Gain_e[i + 3] * rtb_Sum2_ht[1] +
        claw_main_Y.cvdex_fltpathb[i];
      claw_main_Y.cvdex_fltpathb[i] = rtb_Gain_e[i + 6] * rtb_Sum2_ht[2] +
        claw_main_Y.cvdex_fltpathb[i];

      /* Outport: '<Root>/w_est' */
      claw_main_Y.w_est[i] = rtb_w_est[i];

      /* Outport: '<Root>/NED_wind_ex' */
      claw_main_Y.NED_wind_ex[i] = rtb_NED_wind_ex[i];

      /* Outport: '<Root>/uvw_wind' */
      claw_main_Y.uvw_wind[i] = rtb_Sum2[i];

      /* Outport: '<Root>/uvw_rw_est' */
      claw_main_Y.uvw_rw_est[i] = rtb_DiscreteTimeIntegrator[i];

      /* Outport: '<Root>/accels' */
      claw_main_Y.accels[i] = rtb_accels_cg_b[i];
    }

    /* Outport: '<Root>/att_typea' */
    claw_main_Y.att_typea = rtb_att_type;

    /* Outport: '<Root>/mass' */
    claw_main_Y.mass = claw_main_B.mass;

    /* Outport: '<Root>/enable_bb' */
    claw_main_Y.enable_bb = (real_T)rtb_enable_bb;

    /* Outport: '<Root>/gain_set' */
    claw_main_Y.gain_set = min_3;
  }

  /* Update absolute time for base rate */
  claw_main_M->Timing.clockTick0++;
}

/* Model initialize function */
void claw_main_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)claw_main_M,0,
                sizeof(RT_MODEL_claw_main));
  rtmSetFirstInitCond(claw_main_M, 1);

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_B.Merge_b[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_n[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_bf[i] = 0.0;
    }

    for (i = 0; i < 30; i++) {
      claw_main_B.TmpHiddenBufferAtSFunctionInpor[i] = 0.0;
    }

    for (i = 0; i < 461; i++) {
      claw_main_B.SFunction[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      claw_main_B.Merge_db[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_f[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_nz[i] = 0.0;
    }

    for (i = 0; i < 65; i++) {
      claw_main_B.TmpHiddenBufferAtSFunctionInp_k[i] = 0.0;
    }

    for (i = 0; i < 461; i++) {
      claw_main_B.SFunction_g[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_da[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_fl[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      claw_main_B.Merge_g[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      claw_main_B.Merge_f4[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_l[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_di[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_ie[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_k[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.sf_ImplementDamageModels.dC6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_f.AssignmenttoLateral[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_f.AssignmenttoLongitudinal[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_f.AssignmenttoLateral1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_l.AssignmenttoLateral[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_l.AssignmenttoLongitudinal[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_l.AssignmenttoLateral1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_l.AssignmenttoCY[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.sf_ImplementDamageModels_lh.dC6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.sf_ImplementDamageModels_g.dC6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.sf_ImplementDamageModels_l.dC6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_ka.AssignmenttoLateral[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_ka.AssignmenttoLongitudinal[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.RotaryBlendedUnDamagedCase_ka.AssignmenttoLateral1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_b.AssignmenttoLateral[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_b.AssignmenttoLongitudinal[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_b.AssignmenttoLateral1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.ForcedOscillationwithDamageIn_b.AssignmenttoCY[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      claw_main_B.sf_ImplementDamageModels_j.dC6[i] = 0.0;
    }

    claw_main_B.Merge[0] = 0.0;
    claw_main_B.Merge[1] = 0.0;
    claw_main_B.Merge[2] = 0.0;
    claw_main_B.eow = 0.0;
    claw_main_B.X = 0.0;
    claw_main_B.mass = 0.0;
    claw_main_B.Width2 = 0.0;
    claw_main_B.Width1 = 0.0;
    claw_main_B.Merge_c[0] = 0.0;
    claw_main_B.Merge_c[1] = 0.0;
    claw_main_B.Merge_c[2] = 0.0;
    claw_main_B.Merge2[0] = 0.0;
    claw_main_B.Merge2[1] = 0.0;
    claw_main_B.Merge2[2] = 0.0;
    claw_main_B.Merge_i[0] = 0.0;
    claw_main_B.Merge_i[1] = 0.0;
    claw_main_B.Merge_i[2] = 0.0;
    claw_main_B.DiscreteTimeIntegrator[0] = 0.0;
    claw_main_B.DiscreteTimeIntegrator[1] = 0.0;
    claw_main_B.DiscreteTimeIntegrator[2] = 0.0;
    claw_main_B.alpha = 0.0;
    claw_main_B.beta = 0.0;
    claw_main_B.Merge1[0] = 0.0;
    claw_main_B.Merge1[1] = 0.0;
    claw_main_B.Merge1[2] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_o[0] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_o[1] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_o[2] = 0.0;
    claw_main_B.Merge_d[0] = 0.0;
    claw_main_B.Merge_d[1] = 0.0;
    claw_main_B.Merge_d[2] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_p[0] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_p[1] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_p[2] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_p[3] = 0.0;
    claw_main_B.alpha_k = 0.0;
    claw_main_B.beta_h = 0.0;
    claw_main_B.DiscreteTimeIntegrator_j[0] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_j[1] = 0.0;
    claw_main_B.DiscreteTimeIntegrator_j[2] = 0.0;
    claw_main_B.alpha_l = 0.0;
    claw_main_B.beta_d = 0.0;
    claw_main_B.Merge_cz[0] = 0.0;
    claw_main_B.Merge_cz[1] = 0.0;
    claw_main_B.Merge_cz[2] = 0.0;
    claw_main_B.alpha_c = 0.0;
    claw_main_B.beta_n = 0.0;
    claw_main_B.alpha_f = 0.0;
    claw_main_B.beta_e = 0.0;
    claw_main_B.sf_EngineAlignment.T[0] = 0.0;
    claw_main_B.sf_EngineAlignment.T[1] = 0.0;
    claw_main_B.sf_EngineAlignment.T[2] = 0.0;
    claw_main_B.sf_EngineAlignment.TL[0] = 0.0;
    claw_main_B.sf_EngineAlignment.TL[1] = 0.0;
    claw_main_B.sf_EngineAlignment.TL[2] = 0.0;
    claw_main_B.sf_EngineAlignment.TR[0] = 0.0;
    claw_main_B.sf_EngineAlignment.TR[1] = 0.0;
    claw_main_B.sf_EngineAlignment.TR[2] = 0.0;
    claw_main_B.sf_EngineAlignment.H[0] = 0.0;
    claw_main_B.sf_EngineAlignment.H[1] = 0.0;
    claw_main_B.sf_EngineAlignment.H[2] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase.Saturation = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase.sf_BlendingFunction.omega = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase.sf_BlendingFunction.pqr_osc[0] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase.sf_BlendingFunction.pqr_osc[1] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase.sf_BlendingFunction.pqr_osc[2] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_h.Product3[0] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_h.Product3[1] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_h.Product3[2] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0.y[0] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0.y[1] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0.y[2] = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_f.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_i.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_k.y = 0.0;
    claw_main_B.sf_EngineAlignment_g.T[0] = 0.0;
    claw_main_B.sf_EngineAlignment_g.T[1] = 0.0;
    claw_main_B.sf_EngineAlignment_g.T[2] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TL[0] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TL[1] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TL[2] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TR[0] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TR[1] = 0.0;
    claw_main_B.sf_EngineAlignment_g.TR[2] = 0.0;
    claw_main_B.sf_EngineAlignment_g.H[0] = 0.0;
    claw_main_B.sf_EngineAlignment_g.H[1] = 0.0;
    claw_main_B.sf_EngineAlignment_g.H[2] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_f.Saturation = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_f.sf_BlendingFunction.omega = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_f.sf_BlendingFunction.pqr_osc[0] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_f.sf_BlendingFunction.pqr_osc[1] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_f.sf_BlendingFunction.pqr_osc[2] =
      0.0;
    claw_main_B.ForcedOscillationwithDamageIn_l.Product3[0] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_l.Product3[1] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_l.Product3[2] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_i.y[0] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_i.y[1] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_i.y[2] = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_dz.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_f5.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_p.y = 0.0;
    claw_main_B.sf_EngineAlignment_d.T[0] = 0.0;
    claw_main_B.sf_EngineAlignment_d.T[1] = 0.0;
    claw_main_B.sf_EngineAlignment_d.T[2] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TL[0] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TL[1] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TL[2] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TR[0] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TR[1] = 0.0;
    claw_main_B.sf_EngineAlignment_d.TR[2] = 0.0;
    claw_main_B.sf_EngineAlignment_d.H[0] = 0.0;
    claw_main_B.sf_EngineAlignment_d.H[1] = 0.0;
    claw_main_B.sf_EngineAlignment_d.H[2] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_c.Saturation = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_c.sf_BlendingFunction.omega = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_c.sf_BlendingFunction.pqr_osc[0] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_c.sf_BlendingFunction.pqr_osc[1] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_c.sf_BlendingFunction.pqr_osc[2] =
      0.0;
    claw_main_B.ForcedOscillationwithDamageIn_i.Product3[0] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_i.Product3[1] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_i.Product3[2] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_l.y[0] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_l.y[1] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_l.y[2] = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_m.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_l.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_o.y = 0.0;
    claw_main_B.sf_EngineAlignment_c.T[0] = 0.0;
    claw_main_B.sf_EngineAlignment_c.T[1] = 0.0;
    claw_main_B.sf_EngineAlignment_c.T[2] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TL[0] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TL[1] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TL[2] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TR[0] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TR[1] = 0.0;
    claw_main_B.sf_EngineAlignment_c.TR[2] = 0.0;
    claw_main_B.sf_EngineAlignment_c.H[0] = 0.0;
    claw_main_B.sf_EngineAlignment_c.H[1] = 0.0;
    claw_main_B.sf_EngineAlignment_c.H[2] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_k.Saturation = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_k.sf_BlendingFunction.omega = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_k.sf_BlendingFunction.pqr_osc[0] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_k.sf_BlendingFunction.pqr_osc[1] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_k.sf_BlendingFunction.pqr_osc[2] =
      0.0;
    claw_main_B.ForcedOscillationwithDamageI_oa.Product3[0] = 0.0;
    claw_main_B.ForcedOscillationwithDamageI_oa.Product3[1] = 0.0;
    claw_main_B.ForcedOscillationwithDamageI_oa.Product3[2] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_o.y[0] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_o.y[1] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_o.y[2] = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_e4.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_e.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_n.y = 0.0;
    claw_main_B.sf_EngineAlignment_b.T[0] = 0.0;
    claw_main_B.sf_EngineAlignment_b.T[1] = 0.0;
    claw_main_B.sf_EngineAlignment_b.T[2] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TL[0] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TL[1] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TL[2] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TR[0] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TR[1] = 0.0;
    claw_main_B.sf_EngineAlignment_b.TR[2] = 0.0;
    claw_main_B.sf_EngineAlignment_b.H[0] = 0.0;
    claw_main_B.sf_EngineAlignment_b.H[1] = 0.0;
    claw_main_B.sf_EngineAlignment_b.H[2] = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_ka.Saturation = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_ka.sf_BlendingFunction.omega = 0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_ka.sf_BlendingFunction.pqr_osc[0] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_ka.sf_BlendingFunction.pqr_osc[1] =
      0.0;
    claw_main_B.RotaryBlendedUnDamagedCase_ka.sf_BlendingFunction.pqr_osc[2] =
      0.0;
    claw_main_B.ForcedOscillationwithDamageIn_b.Product3[0] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_b.Product3[1] = 0.0;
    claw_main_B.ForcedOscillationwithDamageIn_b.Product3[2] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_a.y[0] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_a.y[1] = 0.0;
    claw_main_B.sf_fuelcgshiftcg_pos0_a.y[2] = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_d.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_b.y = 0.0;
    claw_main_B.sf_EmbeddedMATLABFunction_c.y = 0.0;
  }

  /* exported global signals */
  CLAW_Nd_wind = 0.0;
  CLAW_Ed_wind = 0.0;
  CLAW_Dd_wind = 0.0;
  CLAW_p_int = 0.0;
  CLAW_q_int = 0.0;
  CLAW_r_int = 0.0;
  CLAW_e0_int = 0.0;
  CLAW_e1_int = 0.0;
  CLAW_e2_int = 0.0;
  CLAW_e3_int = 0.0;
  CLAW_Ndot_int = 0.0;
  CLAW_Edot_int = 0.0;
  CLAW_hdot_int = 0.0;
  CLAW_N_int = 0.0;
  CLAW_E_int = 0.0;
  CLAW_h_int = 0.0;
  CLAW_p_cvdex = 0.0;
  CLAW_q_cvdex = 0.0;
  CLAW_r_cvdex = 0.0;
  CLAW_e0_cvdex = 0.0;
  CLAW_e1_cvdex = 0.0;
  CLAW_e2_cvdex = 0.0;
  CLAW_e3_cvdex = 0.0;
  CLAW_Ndot_cvdex = 0.0;
  CLAW_Edot_cvdex = 0.0;
  CLAW_hdot_cvdex = 0.0;
  CLAW_N_cvdex = 0.0;
  CLAW_E_cvdex = 0.0;
  CLAW_h_cvdex = 0.0;
  CLAW_p_cvcmd = 0.0;
  CLAW_q_cvcmd = 0.0;
  CLAW_r_cvcmd = 0.0;
  CLAW_e0_cvcmd = 0.0;
  CLAW_e1_cvcmd = 0.0;
  CLAW_e2_cvcmd = 0.0;
  CLAW_e3_cvcmd = 0.0;
  CLAW_Ndot_cvcmd = 0.0;
  CLAW_Edot_cvcmd = 0.0;
  CLAW_hdot_cvcmd = 0.0;
  CLAW_N_cvcmd = 0.0;
  CLAW_E_cvcmd = 0.0;
  CLAW_h_cvcmd = 0.0;
  CLAW_p_cv = 0.0;
  CLAW_q_cv = 0.0;
  CLAW_r_cv = 0.0;
  CLAW_e0_cv = 0.0;
  CLAW_e1_cv = 0.0;
  CLAW_e2_cv = 0.0;
  CLAW_e3_cv = 0.0;
  CLAW_Ndot_cv = 0.0;
  CLAW_Edot_cv = 0.0;
  CLAW_hdot_cv = 0.0;
  CLAW_N_cv = 0.0;
  CLAW_E_cv = 0.0;
  CLAW_h_cv = 0.0;

  /* states (dwork) */
  (void) memset((void *)&claw_main_DWork, 0,
                sizeof(D_Work_claw_main));
  claw_main_DWork.UnitDelay1_DSTATE[0] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE[1] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE[3] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_m[0] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_m[1] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_m[2] = 0.0;
  claw_main_DWork.integration1_DSTATE[0] = 0.0;
  claw_main_DWork.integration1_DSTATE[1] = 0.0;
  claw_main_DWork.integration1_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_d = 0.0;
  claw_main_DWork.DelayInput1_DSTATE[0] = 0.0;
  claw_main_DWork.DelayInput1_DSTATE[1] = 0.0;
  claw_main_DWork.DelayInput1_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_j = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_j3[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_j3[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_j3[2] = 0.0;
  claw_main_DWork.DelayInput1_DSTATE_c = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_p[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_p[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_p[2] = 0.0;
  claw_main_DWork.attcmdintegration_DSTATE[0] = 0.0;
  claw_main_DWork.attcmdintegration_DSTATE[1] = 0.0;
  claw_main_DWork.attcmdintegration_DSTATE[2] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_m1 = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_jm[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_jm[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_jm[2] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_DWork.UnitDelay_DSTATE_je[i] = 0.0;
    }
  }

  claw_main_DWork.mass_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      claw_main_DWork.UnitDelay_DSTATE_h[i] = 0.0;
    }
  }

  claw_main_DWork.UnitDelay_DSTATE_g[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_g[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_g[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_e[i] = 0.0;
    }
  }

  claw_main_DWork.UnitDelay2_DSTATE_a[0] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_a[1] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_a[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_a[i] = 0.0;
    }
  }

  claw_main_DWork.UnitDelay2_DSTATE_d[0] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_d[1] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_d[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_m[3] = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      claw_main_DWork.UnitDelay_DSTATE_b[i] = 0.0;
    }
  }

  claw_main_DWork.UnitDelay2_DSTATE_e[0] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_e[1] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_e[2] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_e[3] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_m = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_DWork.UnitDelay2_DSTATE_i[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_pq[i] = 0.0;
    }
  }

  claw_main_DWork.UnitDelay2_DSTATE_eb[0] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_eb[1] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_eb[2] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] = 0.0;
  claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_bb[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_bb[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_bb[2] = 0.0;
  claw_main_DWork.UnitDelay2_DSTATE_an = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_e = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_h[0] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_h[1] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_h[2] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_h[3] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_f = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_d[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_d[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_d[2] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_e0[0] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_e0[1] = 0.0;
  claw_main_DWork.UnitDelay1_DSTATE_e0[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_m[0] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_m[1] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_m[2] = 0.0;
  claw_main_DWork.UnitDelay_DSTATE_m[3] = 0.0;
  claw_main_DWork.Memory1_PreviousInput = 0.0;
  claw_main_DWork.Memory_PreviousInput = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_DWork.Product_DWORK4[i] = 0.0;
    }
  }

  claw_main_DWork.Memory_PreviousInput_d = 0.0;
  claw_main_DWork.Memory_PreviousInput_j = 0.0;
  claw_main_DWork.Memory_PreviousInput_g = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_DWork.Memory1_PreviousInput_k[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 27; i++) {
      claw_main_DWork.Memory1_PreviousInput_g[i] = 0.0;
    }
  }

  claw_main_DWork.Memory2_PreviousInput = 0.0;

  /* external inputs */
  claw_main_U.command[0] = 0.0;
  claw_main_U.command[1] = 0.0;
  claw_main_U.command[2] = 0.0;
  claw_main_U.command[3] = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_cmd[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_ulim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_llim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_urlim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_lrlim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_lock[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_pref_select[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_pref[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.full_surf_pref_wght[i] = 0.0;
    }
  }

  claw_main_U.CLAW_mode = 0.0;
  claw_main_U.engaged_sw = 0.0;
  claw_main_U.accel_submode = 0.0;
  claw_main_U.pre_takeoff_sw = 0.0;
  claw_main_U.reset_pos_sw = 0.0;
  claw_main_U.wind_est_sw = 0.0;
  claw_main_U.llh_input_sw = 0.0;
  claw_main_U.int_reset_sw = 0.0;
  claw_main_U.att_type = 0.0;
  claw_main_U.cam_rate_cmd_sw = 0.0;
  claw_main_U.full_surf_cmd_sw = 0.0;
  claw_main_U.enable_homing_sw = 0.0;
  claw_main_U.att_rate_cmd_sw = 0.0;
  claw_main_U.nav_enable_sw = 0.0;
  claw_main_U.enable_bb_sw = 0.0;
  claw_main_U.gain_set_sw = 0.0;
  claw_main_U.use_held_aero_obac_sw = 0.0;
  claw_main_U.Isp_sl = 0.0;
  claw_main_U.Isp_vacuum = 0.0;
  claw_main_U.throt_to_ff = 0.0;
  claw_main_U.pqr[0] = 0.0;
  claw_main_U.pqr[1] = 0.0;
  claw_main_U.pqr[2] = 0.0;
  claw_main_U.NED_dot[0] = 0.0;
  claw_main_U.NED_dot[1] = 0.0;
  claw_main_U.NED_dot[2] = 0.0;
  claw_main_U.latlonh[0] = 0.0;
  claw_main_U.latlonh[1] = 0.0;
  claw_main_U.latlonh[2] = 0.0;
  claw_main_U.e[0] = 0.0;
  claw_main_U.e[1] = 0.0;
  claw_main_U.e[2] = 0.0;
  claw_main_U.e[3] = 0.0;
  claw_main_U.accels_cg[0] = 0.0;
  claw_main_U.accels_cg[1] = 0.0;
  claw_main_U.accels_cg[2] = 0.0;
  claw_main_U.nav_ok = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_U.u_meas[i] = 0.0;
    }
  }

  claw_main_U.NED_wind[0] = 0.0;
  claw_main_U.NED_wind[1] = 0.0;
  claw_main_U.NED_wind[2] = 0.0;
  claw_main_U.LOS_rate[0] = 0.0;
  claw_main_U.LOS_rate[1] = 0.0;
  claw_main_U.azimuth = 0.0;
  claw_main_U.elevation = 0.0;
  claw_main_U.Rground = 0.0;
  claw_main_U.Rslant = 0.0;

  /* external outputs */
  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.u_out[i] = 0.0;
    }
  }

  claw_main_Y.commandb[0] = 0.0;
  claw_main_Y.commandb[1] = 0.0;
  claw_main_Y.commandb[2] = 0.0;
  claw_main_Y.commandb[3] = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_cmdb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_ulimb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_llimb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_urlimb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_lrlimb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_lockb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_pref_selectb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_prefb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      claw_main_Y.full_surf_pref_wghtb[i] = 0.0;
    }
  }

  claw_main_Y.CLAW_modeb = 0.0;
  claw_main_Y.engaged_swb = 0.0;
  claw_main_Y.accel_submodeb = 0.0;
  claw_main_Y.pre_takeoff_swb = 0.0;
  claw_main_Y.reset_pos_swb = 0.0;
  claw_main_Y.wind_est_swb = 0.0;
  claw_main_Y.llh_input_swb = 0.0;
  claw_main_Y.int_reset_swb = 0.0;
  claw_main_Y.att_typeb = 0.0;
  claw_main_Y.cam_rate_cmd_swb = 0.0;
  claw_main_Y.full_surf_cmd_swb = 0.0;
  claw_main_Y.enable_homing_swb = 0.0;
  claw_main_Y.att_rate_cmd_swb = 0.0;
  claw_main_Y.nav_enable_swb = 0.0;
  claw_main_Y.enable_bb_swb = 0.0;
  claw_main_Y.gain_set_swb = 0.0;
  claw_main_Y.use_held_aero_obac_swb = 0.0;
  claw_main_Y.Isp_slb = 0.0;
  claw_main_Y.Isp_vacuumb = 0.0;
  claw_main_Y.throt_to_ffb = 0.0;
  claw_main_Y.cvdex_smn[0] = 0.0;
  claw_main_Y.cvdex_smn[1] = 0.0;
  claw_main_Y.cvdex_smn[2] = 0.0;
  claw_main_Y.lambda = 0.0;

  {
    int_T i;
    for (i = 0; i < 18; i++) {
      claw_main_Y.solve_dat[i] = 0.0;
    }
  }

  claw_main_Y.cvdex[0] = 0.0;
  claw_main_Y.cvdex[1] = 0.0;
  claw_main_Y.cvdex[2] = 0.0;
  claw_main_Y.cvc[0] = 0.0;
  claw_main_Y.cvc[1] = 0.0;
  claw_main_Y.cvc[2] = 0.0;
  claw_main_Y.integ[0] = 0.0;
  claw_main_Y.integ[1] = 0.0;
  claw_main_Y.integ[2] = 0.0;
  claw_main_Y.cv[0] = 0.0;
  claw_main_Y.cv[1] = 0.0;
  claw_main_Y.cv[2] = 0.0;
  claw_main_Y.cvdnom[0] = 0.0;
  claw_main_Y.cvdnom[1] = 0.0;
  claw_main_Y.cvdnom[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 27; i++) {
      claw_main_Y.Bmat[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_Y.u_ulim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_Y.u_llim[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_Y.u_pref[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 23; i++) {
      claw_main_Y.bb_debug[i] = 0.0;
    }
  }

  claw_main_Y.cvdexb[0] = 0.0;
  claw_main_Y.cvdexb[1] = 0.0;
  claw_main_Y.cvdexb[2] = 0.0;
  claw_main_Y.cvdexb[3] = 0.0;
  claw_main_Y.integb[0] = 0.0;
  claw_main_Y.integb[1] = 0.0;
  claw_main_Y.integb[2] = 0.0;
  claw_main_Y.integb[3] = 0.0;
  claw_main_Y.cvcb[0] = 0.0;
  claw_main_Y.cvcb[1] = 0.0;
  claw_main_Y.cvcb[2] = 0.0;
  claw_main_Y.cvcb[3] = 0.0;
  claw_main_Y.cvb[0] = 0.0;
  claw_main_Y.cvb[1] = 0.0;
  claw_main_Y.cvb[2] = 0.0;
  claw_main_Y.cvb[3] = 0.0;
  claw_main_Y.tiltcam_cmds[0] = 0.0;
  claw_main_Y.tiltcam_cmds[1] = 0.0;
  claw_main_Y.tiltcam_cmds[2] = 0.0;
  claw_main_Y.rpy_cmds[0] = 0.0;
  claw_main_Y.rpy_cmds[1] = 0.0;
  claw_main_Y.rpy_cmds[2] = 0.0;
  claw_main_Y.mab_cmds[0] = 0.0;
  claw_main_Y.mab_cmds[1] = 0.0;
  claw_main_Y.mab_cmds[2] = 0.0;
  claw_main_Y.cvdexa[0] = 0.0;
  claw_main_Y.cvdexa[1] = 0.0;
  claw_main_Y.cvdexa[2] = 0.0;
  claw_main_Y.lambdab = 0.0;

  {
    int_T i;
    for (i = 0; i < 18; i++) {
      claw_main_Y.solve_datb[i] = 0.0;
    }
  }

  claw_main_Y.intega[0] = 0.0;
  claw_main_Y.intega[1] = 0.0;
  claw_main_Y.intega[2] = 0.0;
  claw_main_Y.cvca[0] = 0.0;
  claw_main_Y.cvca[1] = 0.0;
  claw_main_Y.cvca[2] = 0.0;
  claw_main_Y.cva[0] = 0.0;
  claw_main_Y.cva[1] = 0.0;
  claw_main_Y.cva[2] = 0.0;
  claw_main_Y.cvdnomb[0] = 0.0;
  claw_main_Y.cvdnomb[1] = 0.0;
  claw_main_Y.cvdnomb[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_Y.Bmatb[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      claw_main_Y.Bmat_fltpath[i] = 0.0;
    }
  }

  claw_main_Y.u_ulimb[0] = 0.0;
  claw_main_Y.u_ulimb[1] = 0.0;
  claw_main_Y.u_ulimb[2] = 0.0;
  claw_main_Y.u_llimb[0] = 0.0;
  claw_main_Y.u_llimb[1] = 0.0;
  claw_main_Y.u_llimb[2] = 0.0;
  claw_main_Y.cvdex_fltpath[0] = 0.0;
  claw_main_Y.cvdex_fltpath[1] = 0.0;
  claw_main_Y.cvdex_fltpath[2] = 0.0;
  claw_main_Y.cvdexc[0] = 0.0;
  claw_main_Y.cvdexc[1] = 0.0;
  claw_main_Y.cvdexc[2] = 0.0;
  claw_main_Y.integc[0] = 0.0;
  claw_main_Y.integc[1] = 0.0;
  claw_main_Y.integc[2] = 0.0;
  claw_main_Y.cvcc[0] = 0.0;
  claw_main_Y.cvcc[1] = 0.0;
  claw_main_Y.cvcc[2] = 0.0;
  claw_main_Y.cvd[0] = 0.0;
  claw_main_Y.cvd[1] = 0.0;
  claw_main_Y.cvd[2] = 0.0;
  claw_main_Y.cvdex_fltpathb[0] = 0.0;
  claw_main_Y.cvdex_fltpathb[1] = 0.0;
  claw_main_Y.cvdex_fltpathb[2] = 0.0;
  claw_main_Y.w_est[0] = 0.0;
  claw_main_Y.w_est[1] = 0.0;
  claw_main_Y.w_est[2] = 0.0;
  claw_main_Y.NED_wind_ex[0] = 0.0;
  claw_main_Y.NED_wind_ex[1] = 0.0;
  claw_main_Y.NED_wind_ex[2] = 0.0;
  claw_main_Y.uvw_wind[0] = 0.0;
  claw_main_Y.uvw_wind[1] = 0.0;
  claw_main_Y.uvw_wind[2] = 0.0;
  claw_main_Y.uvw_rw_est[0] = 0.0;
  claw_main_Y.uvw_rw_est[1] = 0.0;
  claw_main_Y.uvw_rw_est[2] = 0.0;
  claw_main_Y.accels[0] = 0.0;
  claw_main_Y.accels[1] = 0.0;
  claw_main_Y.accels[2] = 0.0;
  claw_main_Y.att_typea = 0.0;
  claw_main_Y.mass = 0.0;
  claw_main_Y.enable_bb = 0.0;
  claw_main_Y.gain_set = 0.0;

  {
    int32_T i;

    /* Start for atomic SubSystem: '<Root>/claw_main' */

    /* FromWorkspace Block: '<S93>/From Workspace4' */
    {
      static real_T pTimeValues[] = { 0.0 } ;

      static real_T pDataValues[] = { 1.4856322965068893E+000,
        -1.7096591153906164E-006, 1.5708840510726072E+000 } ;

      claw_main_DWork.FromWorkspace4_PWORK.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace4_PWORK.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace4_IWORK.PrevIndex = 0;
    }

    /* FromWorkspace Block: '<S93>/From Workspace1' */
    {
      static real_T pTimeValues[] = { 0.0 } ;

      static real_T pDataValues[] = { 1.5707946109169855E+000,
        8.5164030287882581E-002, -8.7870232206913105E-005 } ;

      claw_main_DWork.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace1_IWORK.PrevIndex = 0;
    }

    /* FromWorkspace Block: '<S93>/From Workspace2' */
    {
      static real_T pTimeValues[] = { 0.0 } ;

      static real_T pDataValues[] = { -1.6364738164137613E+000,
        -1.5513097860508127E+000, -1.5707085858589882E+000 } ;

      claw_main_DWork.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace2_IWORK.PrevIndex = 0;
    }

    /* Width Block: '<S159>/Width2' */
    claw_main_B.Width2 = (real_T)52;

    /* Width Block: '<S159>/Width1' */
    claw_main_B.Width1 = (real_T)52;

    /* Start for ifaction SubSystem: '<S156>/homing' */

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd_sw' */
    claw_main_B.Merge2[0] = claw_main_P.accel_cmd_sw_Y0[0];

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd' */
    claw_main_B.Merge1[0] = claw_main_P.accel_cmd_Y0[0];

    /* VirtualOutportStart for Outport: '<S166>/accel_cmd_sw' */
    claw_main_B.Merge2[0] = claw_main_P.accel_cmd_sw_Y0_d[0];

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd_sw' */
    claw_main_B.Merge2[1] = claw_main_P.accel_cmd_sw_Y0[1];

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd' */
    claw_main_B.Merge1[1] = claw_main_P.accel_cmd_Y0[1];

    /* VirtualOutportStart for Outport: '<S166>/accel_cmd_sw' */
    claw_main_B.Merge2[1] = claw_main_P.accel_cmd_sw_Y0_d[1];

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd_sw' */
    claw_main_B.Merge2[2] = claw_main_P.accel_cmd_sw_Y0[2];

    /* VirtualOutportStart for Outport: '<S165>/accel_cmd' */
    claw_main_B.Merge1[2] = claw_main_P.accel_cmd_Y0[2];

    /* VirtualOutportStart for Outport: '<S166>/accel_cmd_sw' */
    claw_main_B.Merge2[2] = claw_main_P.accel_cmd_sw_Y0_d[2];

    /* VirtualOutportStart for Outport: '<S166>/accel_cmd' */
    claw_main_B.Merge1[0] = claw_main_P.accel_cmd_Y0_k[0];
    claw_main_B.Merge1[1] = claw_main_P.accel_cmd_Y0_k[1];
    claw_main_B.Merge1[2] = claw_main_P.accel_cmd_Y0_k[2];

    /* end of Start for SubSystem: '<S156>/homing' */

    /* Start for ifaction SubSystem: '<S156>/normal vel desdyn' */

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd_sw' */
    claw_main_B.Merge2[0] = claw_main_P.accel_cmd_sw_Y0_n[0];

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd' */
    claw_main_B.Merge1[0] = claw_main_P.accel_cmd_Y0_f[0];

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd_sw' */
    claw_main_B.Merge2[1] = claw_main_P.accel_cmd_sw_Y0_n[1];

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd' */
    claw_main_B.Merge1[1] = claw_main_P.accel_cmd_Y0_f[1];

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd_sw' */
    claw_main_B.Merge2[2] = claw_main_P.accel_cmd_sw_Y0_n[2];

    /* VirtualOutportStart for Outport: '<S167>/accel_cmd' */
    claw_main_B.Merge1[2] = claw_main_P.accel_cmd_Y0_f[2];

    /* end of Start for SubSystem: '<S156>/normal vel desdyn' */

    /* FromWorkspace Block: '<S94>/From Workspace4' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace4_PWORK_g.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace4_PWORK_g.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace4_IWORK_e.PrevIndex = 0;
    }

    /* FromWorkspace Block: '<S664>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK.PrevIndex = 0;
    }

    /* Start for ifaction SubSystem: '<S680>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Start(claw_main_B.Merge_n,
      (rtP_SwitchCaseActionSubsystem_c *) &claw_main_P.SwitchCaseActionSubsystem);

    /* end of Start for SubSystem: '<S680>/Switch Case Action Subsystem' */

    /* Start for ifaction SubSystem: '<S680>/Switch Case Action Subsystem2' */

    /* VirtualOutportStart for Outport: '<S682>/Zeros' */
    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_n[i] = claw_main_P.Zeros_Y0_l[i];
    }

    /* end of Start for SubSystem: '<S680>/Switch Case Action Subsystem2' */

    /* Create Identify Matrix for Block: '<S318>/Product' */
    {
      int_T i;
      real_T *dWork = &claw_main_DWork.Product_DWORK4[0];
      for (i = 0; i < 9; i++) {
        *dWork++ = 0.0;
      }

      dWork = &claw_main_DWork.Product_DWORK4[0];
      while (dWork < &claw_main_DWork.Product_DWORK4[0]+9) {
        *dWork = 1;
        dWork += 4;
      }
    }

    /* Start for iterator SubSystem: '<S522>/B matrix comp' */

    /* FromWorkspace Block: '<S556>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace_PWORK_i.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK_i.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK_n.PrevIndex = 0;
    }

    /* Start for ifaction SubSystem: '<S572>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Start(claw_main_B.Merge_l,
      (rtP_SwitchCaseActionSubsystem_c *)
      &claw_main_P.SwitchCaseActionSubsystem_c);

    /* end of Start for SubSystem: '<S572>/Switch Case Action Subsystem' */

    /* Start for ifaction SubSystem: '<S572>/Switch Case Action Subsystem2' */

    /* VirtualOutportStart for Outport: '<S574>/Zeros' */
    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_l[i] = claw_main_P.Zeros_Y0_bc[i];
    }

    /* end of Start for SubSystem: '<S572>/Switch Case Action Subsystem2' */

    /* InitializeConditions for Memory: '<S533>/Memory' */
    claw_main_DWork.Memory_PreviousInput_g = claw_main_P.Memory_X0;

    /* InitializeConditions for Memory: '<S533>/Memory1' */
    memcpy((void *)(&claw_main_DWork.Memory1_PreviousInput_k[0]), (void *)
           (&claw_main_P.Memory1_X0_c[0]), 9U * (uint32_T)((char_T *)
            (&claw_main_P.Memory1_X0_c[1]) - (char_T *)
            (&claw_main_P.Memory1_X0_c[0])));

    /* InitializeConditions for Merge: '<S572>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_l[i] = claw_main_P.Merge_InitialOutput_h[i];
      }
    }

    /* InitializeConditions for Merge: '<S570>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_di[i] = claw_main_P.Merge_InitialOutput_p[i];
      }
    }

    /* end of Start for SubSystem: '<S522>/B matrix comp' */

    /* Start for atomic SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* Start for ifaction SubSystem: '<S526>/NED_dd cmd' */

    /* VirtualOutportStart for Outport: '<S763>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[0] = claw_main_P.NEh_dd_cmd_Y0[0];

    /* end of Start for SubSystem: '<S526>/NED_dd cmd' */

    /* Start for ifaction SubSystem: '<S526>/vchigam_dot cmd' */

    /* VirtualOutportStart for Outport: '<S764>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[0] = claw_main_P.NEh_dd_cmd_Y0_k[0];

    /* end of Start for SubSystem: '<S526>/vchigam_dot cmd' */

    /* Start for ifaction SubSystem: '<S526>/NED_dd cmd' */

    /* VirtualOutportStart for Outport: '<S763>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[1] = claw_main_P.NEh_dd_cmd_Y0[1];

    /* end of Start for SubSystem: '<S526>/NED_dd cmd' */

    /* Start for ifaction SubSystem: '<S526>/vchigam_dot cmd' */

    /* VirtualOutportStart for Outport: '<S764>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[1] = claw_main_P.NEh_dd_cmd_Y0_k[1];

    /* end of Start for SubSystem: '<S526>/vchigam_dot cmd' */

    /* Start for ifaction SubSystem: '<S526>/NED_dd cmd' */

    /* VirtualOutportStart for Outport: '<S763>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[2] = claw_main_P.NEh_dd_cmd_Y0[2];

    /* end of Start for SubSystem: '<S526>/NED_dd cmd' */

    /* Start for ifaction SubSystem: '<S526>/vchigam_dot cmd' */

    /* VirtualOutportStart for Outport: '<S764>/NEh_dd_cmd' */
    claw_main_B.Merge_cz[2] = claw_main_P.NEh_dd_cmd_Y0_k[2];

    /* end of Start for SubSystem: '<S526>/vchigam_dot cmd' */

    /* end of Start for SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* FromWorkspace Block: '<S94>/From Workspace1' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace1_PWORK_i.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace1_PWORK_i.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace1_IWORK_f.PrevIndex = 0;
    }

    /* FromWorkspace Block: '<S350>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace_PWORK_p.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK_p.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK_i.PrevIndex = 0;
    }

    /* Start for ifaction SubSystem: '<S366>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Start(claw_main_B.Merge_f,
      (rtP_SwitchCaseActionSubsystem_c *)
      &claw_main_P.SwitchCaseActionSubsystem_o);

    /* end of Start for SubSystem: '<S366>/Switch Case Action Subsystem' */

    /* Start for ifaction SubSystem: '<S366>/Switch Case Action Subsystem2' */

    /* VirtualOutportStart for Outport: '<S368>/Zeros' */
    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_f[i] = claw_main_P.Zeros_Y0_b[i];
    }

    /* end of Start for SubSystem: '<S366>/Switch Case Action Subsystem2' */

    /* FromWorkspace Block: '<S182>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0 } ;

      static real_T pDataValues[] = { 0.0 };

      claw_main_DWork.FromWorkspace_PWORK_d.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK_d.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK_i1.PrevIndex = 0;
    }

    /* Start for iterator SubSystem: '<S6>/B matrix comp' */

    /* FromWorkspace Block: '<S222>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace_PWORK_g.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK_g.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK_m.PrevIndex = 0;
    }

    /* Start for ifaction SubSystem: '<S238>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Start(claw_main_B.Merge_ie,
      (rtP_SwitchCaseActionSubsystem_c *)
      &claw_main_P.SwitchCaseActionSubsystem_a);

    /* end of Start for SubSystem: '<S238>/Switch Case Action Subsystem' */

    /* Start for ifaction SubSystem: '<S238>/Switch Case Action Subsystem2' */

    /* VirtualOutportStart for Outport: '<S240>/Zeros' */
    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_ie[i] = claw_main_P.Zeros_Y0[i];
    }

    /* end of Start for SubSystem: '<S238>/Switch Case Action Subsystem2' */

    /* InitializeConditions for Memory: '<S194>/Memory1' */
    memcpy((void *)(&claw_main_DWork.Memory1_PreviousInput_g[0]), (void *)
           (&claw_main_P.Memory1_X0[0]), 27U * (uint32_T)((char_T *)
            (&claw_main_P.Memory1_X0[1]) - (char_T *)(&claw_main_P.Memory1_X0[0])));

    /* InitializeConditions for Memory: '<S194>/Memory2' */
    claw_main_DWork.Memory2_PreviousInput = claw_main_P.Memory2_X0;

    /* InitializeConditions for Merge: '<S238>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_ie[i] = claw_main_P.Merge_InitialOutput[i];
      }
    }

    /* InitializeConditions for Merge: '<S236>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_k[i] = claw_main_P.Merge_InitialOutput_n[i];
      }
    }

    /* end of Start for SubSystem: '<S6>/B matrix comp' */

    /* FromWorkspace Block: '<S448>/From Workspace' */
    {
      static real_T pTimeValues[] = { 0.0, 0.0 } ;

      static real_T pDataValues[] = { 0.0, 0.0 } ;

      claw_main_DWork.FromWorkspace_PWORK_h.TimePtr = (void *) pTimeValues;
      claw_main_DWork.FromWorkspace_PWORK_h.DataPtr = (void *) pDataValues;
      claw_main_DWork.FromWorkspace_IWORK_c.PrevIndex = 0;
    }

    /* Start for ifaction SubSystem: '<S464>/Switch Case Action Subsystem' */
    SwitchCaseActionSubsystem_Start(claw_main_B.Merge_da,
      (rtP_SwitchCaseActionSubsystem_c *)
      &claw_main_P.SwitchCaseActionSubsystem_ot);

    /* end of Start for SubSystem: '<S464>/Switch Case Action Subsystem' */

    /* Start for ifaction SubSystem: '<S464>/Switch Case Action Subsystem2' */

    /* VirtualOutportStart for Outport: '<S466>/Zeros' */
    for (i = 0; i < 6; i++) {
      claw_main_B.Merge_da[i] = claw_main_P.Zeros_Y0_c[i];
    }

    /* end of Start for SubSystem: '<S464>/Switch Case Action Subsystem2' */

    /* end of Start for SubSystem: '<Root>/claw_main' */
  }

  {
    int32_T i;

    /* InitializeConditions for atomic SubSystem: '<Root>/claw_main' */

    /* InitializeConditions for UnitDelay: '<S332>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE[0] = claw_main_P.UnitDelay1_X0[0];
    claw_main_DWork.UnitDelay1_DSTATE[1] = claw_main_P.UnitDelay1_X0[1];
    claw_main_DWork.UnitDelay1_DSTATE[2] = claw_main_P.UnitDelay1_X0[2];
    claw_main_DWork.UnitDelay1_DSTATE[3] = claw_main_P.UnitDelay1_X0[3];

    /* InitializeConditions for UnitDelay: '<S199>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_d = claw_main_P.UnitDelay1_X0_e;

    /* InitializeConditions for UnitDelay: '<S146>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j = claw_main_P.UnitDelay_X0_g;

    /* InitializeConditions for Memory: '<S313>/Memory1' */
    claw_main_DWork.Memory1_PreviousInput = claw_main_P.Memory1_X0_d;

    /* InitializeConditions for Memory: '<S313>/Memory' */
    claw_main_DWork.Memory_PreviousInput = claw_main_P.Memory_X0_i;

    /* InitializeConditions for UnitDelay: '<S104>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE_c = claw_main_P.DelayInput1_X0_d;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/att cmd integration' */
    claw_main_DWork.attcmdintegration_IC_LOADING = 1U;

    /* InitializeConditions for UnitDelay: '<S96>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m1 = claw_main_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[0] = claw_main_P.UnitDelay1_X0_f;

    /* InitializeConditions for DiscreteIntegrator: '<S425>/integration1' */
    claw_main_DWork.integration1_DSTATE[0] = claw_main_P.integration1_IC;

    /* InitializeConditions for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[0] = claw_main_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S105>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE[0] = claw_main_P.DelayInput1_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      claw_main_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[0] = claw_main_P.UnitDelay_X0_a;

    /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[0] = claw_main_P.UnitDelay_X0_b;
    claw_main_DWork.attcmdintegration_PrevResetStat[0] = 2;

    /* InitializeConditions for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[0] = claw_main_P.UnitDelay_X0_bu;

    /* InitializeConditions for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[1] = claw_main_P.UnitDelay1_X0_f;

    /* InitializeConditions for DiscreteIntegrator: '<S425>/integration1' */
    claw_main_DWork.integration1_DSTATE[1] = claw_main_P.integration1_IC;

    /* InitializeConditions for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[1] = claw_main_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S105>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE[1] = claw_main_P.DelayInput1_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      claw_main_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[1] = claw_main_P.UnitDelay_X0_a;

    /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[1] = claw_main_P.UnitDelay_X0_b;
    claw_main_DWork.attcmdintegration_PrevResetStat[1] = 2;

    /* InitializeConditions for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[1] = claw_main_P.UnitDelay_X0_bu;

    /* InitializeConditions for UnitDelay: '<S427>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_m[2] = claw_main_P.UnitDelay1_X0_f;

    /* InitializeConditions for DiscreteIntegrator: '<S425>/integration1' */
    claw_main_DWork.integration1_DSTATE[2] = claw_main_P.integration1_IC;

    /* InitializeConditions for UnitDelay: '<S332>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE[2] = claw_main_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S105>/Delay Input1' */
    claw_main_DWork.DelayInput1_DSTATE[2] = claw_main_P.DelayInput1_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S431>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE[2] =
      claw_main_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S520>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_j3[2] = claw_main_P.UnitDelay_X0_a;

    /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_p[2] = claw_main_P.UnitDelay_X0_b;
    claw_main_DWork.attcmdintegration_PrevResetStat[2] = 2;

    /* InitializeConditions for UnitDelay: '<S96>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_jm[2] = claw_main_P.UnitDelay_X0_bu;

    /* InitializeConditions for UnitDelay: '<S96>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE = claw_main_P.UnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
    memcpy((void *)(&claw_main_DWork.UnitDelay_DSTATE_je[0]), (void *)
           (&claw_main_P.UnitDelay_X0_c[0]), 10U * (uint32_T)((char_T *)
            (&claw_main_P.UnitDelay_X0_c[1]) - (char_T *)
            (&claw_main_P.UnitDelay_X0_c[0])));

    /* InitializeConditions for DiscreteIntegrator: '<S8>/mass' */
    claw_main_DWork.mass_DSTATE = claw_main_P.mass_IC;

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
    for (i = 0; i < 5; i++) {
      claw_main_DWork.UnitDelay_DSTATE_h[i] = claw_main_P.UnitDelay_X0_p[i];
    }

    /* InitializeConditions for Merge: '<S156>/Merge2' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      claw_main_B.Merge2[0] = claw_main_P.Merge2_InitialOutput[0];
      claw_main_B.Merge2[1] = claw_main_P.Merge2_InitialOutput[1];
      claw_main_B.Merge2[2] = claw_main_P.Merge2_InitialOutput[2];
    }

    /* InitializeConditions for UnitDelay: '<S188>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_g[0] = claw_main_P.UnitDelay_X0_k[0];
    claw_main_DWork.UnitDelay_DSTATE_g[1] = claw_main_P.UnitDelay_X0_k[1];
    claw_main_DWork.UnitDelay_DSTATE_g[2] = claw_main_P.UnitDelay_X0_k[2];

    /* InitializeConditions for UnitDelay: '<S190>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_e[i] = claw_main_P.UnitDelay_X0_l;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;

    /* InitializeConditions for UnitDelay: '<S186>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_a[0] = claw_main_P.UnitDelay2_X0_b;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[0] = 0.0;

    /* InitializeConditions for UnitDelay: '<S186>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_a[1] = claw_main_P.UnitDelay2_X0_b;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S186>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_a[2] = claw_main_P.UnitDelay2_X0_b;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_d[2] = 0.0;
    claw_main_DWork.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for Merge: '<S680>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_n[i] = claw_main_P.Merge_InitialOutput_m[i];
      }
    }

    /* InitializeConditions for Merge: '<S678>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_bf[i] = claw_main_P.Merge_InitialOutput_hl[i];
      }
    }

    /* InitializeConditions for Merge: '<S156>/Merge1' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      claw_main_B.Merge1[0] = claw_main_P.Merge1_InitialOutput[0];
      claw_main_B.Merge1[1] = claw_main_P.Merge1_InitialOutput[1];
      claw_main_B.Merge1[2] = claw_main_P.Merge1_InitialOutput[2];
    }

    /* InitializeConditions for atomic SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* InitializeConditions for Merge: '<S526>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      claw_main_B.Merge_cz[0] = claw_main_P.Merge_InitialOutput_b[0];
      claw_main_B.Merge_cz[1] = claw_main_P.Merge_InitialOutput_b[1];
      claw_main_B.Merge_cz[2] = claw_main_P.Merge_InitialOutput_b[2];
    }

    /* end of InitializeConditions for SubSystem: '<S10>/convert accel_cmd to NED_dd_cmd' */

    /* InitializeConditions for UnitDelay: '<S754>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_a[i] = claw_main_P.UnitDelay_X0_o;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S523>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_c = 1U;

    /* InitializeConditions for UnitDelay: '<S523>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_d[0] = claw_main_P.UnitDelay2_X0_o;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[0] = 0.0;

    /* InitializeConditions for UnitDelay: '<S523>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_d[1] = claw_main_P.UnitDelay2_X0_o;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S523>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_d[2] = claw_main_P.UnitDelay2_X0_o;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_o[2] = 0.0;
    claw_main_DWork.DiscreteTimeIntegrator_PrevRe_n = 2;

    /* InitializeConditions for Memory: '<S757>/Memory' */
    claw_main_DWork.Memory_PreviousInput_d = claw_main_P.Memory_X0_a;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_m = 1U;

    /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
    for (i = 0; i < 8; i++) {
      claw_main_DWork.UnitDelay_DSTATE_b[i] = claw_main_P.UnitDelay_X0_ox;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_e = 1U;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_e[0] = claw_main_P.UnitDelay2_X0_e;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[0] = 0.0;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_e[1] = claw_main_P.UnitDelay2_X0_e;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_e[2] = claw_main_P.UnitDelay2_X0_e;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[2] = 0.0;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_e[3] = claw_main_P.UnitDelay2_X0_e;
    claw_main_DWork.DiscreteTimeIntegrator_DSTATE_p[3] = 0.0;
    claw_main_DWork.DiscreteTimeIntegrator_PrevRe_a = 2;

    /* InitializeConditions for UnitDelay: '<S19>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_m = claw_main_P.UnitDelay2_X0_c;

    /* InitializeConditions for Merge: '<S366>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_f[i] = claw_main_P.Merge_InitialOutput_b0[i];
      }
    }

    /* InitializeConditions for Merge: '<S364>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_nz[i] = claw_main_P.Merge_InitialOutput_g[i];
      }
    }

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
    memcpy((void *)(&claw_main_DWork.UnitDelay2_DSTATE_i[0]), (void *)
           (&claw_main_P.UnitDelay2_X0_a[0]), 9U * (uint32_T)((char_T *)
            (&claw_main_P.UnitDelay2_X0_a[1]) - (char_T *)
            (&claw_main_P.UnitDelay2_X0_a[0])));

    /* InitializeConditions for UnitDelay: '<S295>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      claw_main_DWork.UnitDelay_DSTATE_pq[i] = claw_main_P.UnitDelay_X0_m;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    claw_main_DWork.DiscreteTimeIntegrator_IC_LOA_o = 1U;
    claw_main_DWork.DiscreteTimeIntegrator_PrevRe_b = 2;

    /* InitializeConditions for UnitDelay: '<S195>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_eb[0] = claw_main_P.UnitDelay2_X0_e0;
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[0] = 0.0;

    /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[0] = claw_main_P.UnitDelay_X0_pl[0];

    /* InitializeConditions for UnitDelay: '<S195>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_eb[1] = claw_main_P.UnitDelay2_X0_e0;
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[1] = claw_main_P.UnitDelay_X0_pl[1];

    /* InitializeConditions for UnitDelay: '<S195>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_eb[2] = claw_main_P.UnitDelay2_X0_e0;
    claw_main_DWork.DiscreteTimeIntegrator_DSTAT_pd[2] = 0.0;

    /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_bb[2] = claw_main_P.UnitDelay_X0_pl[2];

    /* InitializeConditions for UnitDelay: '<S197>/Unit Delay2' */
    claw_main_DWork.UnitDelay2_DSTATE_an = claw_main_P.UnitDelay2_X0_f;

    /* InitializeConditions for UnitDelay: '<S197>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e = claw_main_P.UnitDelay1_X0_o;

    /* InitializeConditions for Memory: '<S303>/Memory' */
    claw_main_DWork.Memory_PreviousInput_j = claw_main_P.Memory_X0_o;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_h[0] = claw_main_P.UnitDelay1_X0_m;
    claw_main_DWork.UnitDelay1_DSTATE_h[1] = claw_main_P.UnitDelay1_X0_m;
    claw_main_DWork.UnitDelay1_DSTATE_h[2] = claw_main_P.UnitDelay1_X0_m;
    claw_main_DWork.UnitDelay1_DSTATE_h[3] = claw_main_P.UnitDelay1_X0_m;

    /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_f = claw_main_P.UnitDelay_X0_oz;

    /* InitializeConditions for UnitDelay: '<S333>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_d[0] = claw_main_P.UnitDelay_X0_br[0];
    claw_main_DWork.UnitDelay_DSTATE_d[1] = claw_main_P.UnitDelay_X0_br[1];
    claw_main_DWork.UnitDelay_DSTATE_d[2] = claw_main_P.UnitDelay_X0_br[2];

    /* InitializeConditions for Merge: '<S464>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_da[i] = claw_main_P.Merge_InitialOutput_k[i];
      }
    }

    /* InitializeConditions for Merge: '<S462>/Merge' */
    if (rtmIsFirstInitCond(claw_main_M)) {
      for (i = 0; i < 6; i++) {
        claw_main_B.Merge_fl[i] = claw_main_P.Merge_InitialOutput_pm[i];
      }
    }

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay1' */
    claw_main_DWork.UnitDelay1_DSTATE_e0[0] = claw_main_P.UnitDelay1_X0_i[0];
    claw_main_DWork.UnitDelay1_DSTATE_e0[1] = claw_main_P.UnitDelay1_X0_i[1];
    claw_main_DWork.UnitDelay1_DSTATE_e0[2] = claw_main_P.UnitDelay1_X0_i[2];

    /* InitializeConditions for UnitDelay: '<S798>/Unit Delay' */
    claw_main_DWork.UnitDelay_DSTATE_m[0] = claw_main_P.UnitDelay_X0_e[0];
    claw_main_DWork.UnitDelay_DSTATE_m[1] = claw_main_P.UnitDelay_X0_e[1];
    claw_main_DWork.UnitDelay_DSTATE_m[2] = claw_main_P.UnitDelay_X0_e[2];
    claw_main_DWork.UnitDelay_DSTATE_m[3] = claw_main_P.UnitDelay_X0_e[3];

    /* end of InitializeConditions for SubSystem: '<Root>/claw_main' */
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(claw_main_M)) {
    rtmSetFirstInitCond(claw_main_M, 0);
  }
}

/* Model terminate function */
void claw_main_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
