/* Include files */

#include "GTM_aerolib_sfun.h"
#include "c1_GTM_aerolib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GTM_aerolib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance);
static void initialize_params_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance);
static void enable_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance);
static void disable_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance);
static void update_debugger_state_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c1_GTM_aerolib
  (SFc1_GTM_aerolibInstanceStruct *chartInstance);
static void set_sim_state_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance);
static void sf_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance);
static void c1_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_round(SFc1_GTM_aerolibInstanceStruct *chartInstance, real_T
  c1_x);
static void c1_squeeze(SFc1_GTM_aerolibInstanceStruct *chartInstance, real_T
  c1_a[108], real_T c1_b[108]);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[59]);
static void init_dsm_address_info(SFc1_GTM_aerolibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_GTM_aerolib = 0U;
}

static void initialize_params_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance)
{
  real_T c1_dv0[648];
  int32_T c1_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'SurfGain' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c1_dv0, 0, 0, 0U, 1, 0U, 3, 6, 18, 6);
  for (c1_i0 = 0; c1_i0 < 648; c1_i0 = c1_i0 + 1) {
    chartInstance->c1_SurfGain[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *
  chartInstance)
{
}

static const mxArray *get_sim_state_c1_GTM_aerolib
  (SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct
  *chartInstance)
{
}

static void sf_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  uint8_T c1_previousEvent;
  real_T *c1_DamageCase;
  real_T (*c1_dC6)[6];
  real_T (*c1_SurfVec)[108];
  c1_DamageCase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_SurfVec = (real_T (*)[108])ssGetInputPortSignal(chartInstance->S, 0);
  c1_dC6 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i1 = 0; c1_i1 < 108; c1_i1 = c1_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_SurfVec)[c1_i1], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_DamageCase, 1U);
  for (c1_i2 = 0; c1_i2 < 6; c1_i2 = c1_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_dC6)[c1_i2], 2U);
  }

  for (c1_i3 = 0; c1_i3 < 648; c1_i3 = c1_i3 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_SurfGain[c1_i3], 3U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_GTM_aerolib(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_GTM_aerolibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_GTM_aerolib(SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
  int32_T c1_i4;
  real_T c1_SurfVec[108];
  real_T c1_DamageCase;
  int32_T c1_i5;
  real_T c1_b_SurfGain[648];
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 3.0;
  real_T c1_gain[108];
  real_T c1_Nsurfs;
  uint32_T c1_damagecase;
  real_T c1_dC6[6];
  real_T c1_x;
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_d2;
  uint32_T c1_u0;
  int32_T c1_i6;
  real_T c1_b_x[108];
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_y[108];
  int32_T c1_i7;
  int32_T c1_i8;
  real_T c1_b[108];
  int32_T c1_i9;
  int32_T c1_i10;
  real_T c1_B[108];
  int32_T c1_i11;
  real_T c1_C[6];
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_b_B[108];
  int32_T c1_i14;
  real_T c1_b_C[6];
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_c_B[108];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_hoistedExpr;
  int32_T c1_b_damagecase;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_b_hoistedExpr;
  int32_T c1_c_hoistedExpr;
  static real_T c1_dv1[648] = { 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  real_T c1_dv2[108];
  real_T c1_dv3[108];
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_c_x[108];
  int32_T c1_c_k;
  int32_T c1_d_k;
  real_T c1_b_y[108];
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_b_b[108];
  int32_T c1_i25;
  int32_T c1_i26;
  real_T c1_d_B[108];
  int32_T c1_i27;
  real_T c1_c_C[6];
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_e_B[108];
  int32_T c1_i30;
  real_T c1_d_C[6];
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_f_B[108];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_d_hoistedExpr;
  int32_T c1_i35;
  real_T *c1_b_DamageCase;
  real_T (*c1_b_dC6)[6];
  real_T (*c1_b_SurfVec)[108];
  c1_b_DamageCase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_SurfVec = (real_T (*)[108])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_dC6 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i4 = 0; c1_i4 < 108; c1_i4 = c1_i4 + 1) {
    c1_SurfVec[c1_i4] = (*c1_b_SurfVec)[c1_i4];
  }

  c1_DamageCase = *c1_b_DamageCase;
  for (c1_i5 = 0; c1_i5 < 648; c1_i5 = c1_i5 + 1) {
    c1_b_SurfGain[c1_i5] = chartInstance->c1_SurfGain[c1_i5];
  }

  sf_debug_symbol_scope_push(9U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("gain", &c1_gain, c1_f_sf_marshall);
  sf_debug_symbol_scope_add("Nsurfs", &c1_Nsurfs, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("damagecase", &c1_damagecase, c1_e_sf_marshall);
  sf_debug_symbol_scope_add("dC6", &c1_dC6, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("SurfGain", &c1_b_SurfGain, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("DamageCase", &c1_DamageCase, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("SurfVec", &c1_SurfVec, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,4);
  c1_x = c1_round(chartInstance, c1_DamageCase);
  c1_d0 = c1_x;
  c1_d1 = c1_d0;
  c1_d1 = c1_d1 < 0.0 ? muDoubleScalarCeil(c1_d1 - 0.5) : muDoubleScalarFloor
    (c1_d1 + 0.5);
  c1_d2 = c1_d1;
  if (c1_d2 < 4.294967296E+009) {
    if (c1_d2 >= 0.0) {
      c1_u0 = (uint32_T)c1_d2;
    } else {
      c1_u0 = 0U;
    }
  } else if (c1_d2 >= 4.294967296E+009) {
    c1_u0 = MAX_uint32_T;
  } else {
    c1_u0 = 0U;
  }

  c1_damagecase = c1_u0;
  _SFD_EML_CALL(0,5);
  c1_Nsurfs = 18.0;
  _SFD_EML_CALL(0,6);
  if (CV_EML_IF(0, 0, (real_T)c1_damagecase == 0.0)) {
    _SFD_EML_CALL(0,7);
    for (c1_i6 = 0; c1_i6 < 108; c1_i6 = c1_i6 + 1) {
      c1_b_x[c1_i6] = c1_SurfVec[c1_i6];
    }

    for (c1_k = 1; c1_k < 109; c1_k = c1_k + 1) {
      c1_b_k = c1_k;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)
        c1_b_k), 1, 108, 1, 0) - 1] = c1_b_x[
        _SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("k", (real_T)c1_b_k),
        1, 108, 1, 0) - 1];
    }

    for (c1_i7 = 0; c1_i7 < 6; c1_i7 = c1_i7 + 1) {
      for (c1_i8 = 0; c1_i8 < 18; c1_i8 = c1_i8 + 1) {
        c1_b[c1_i8 + 18 * c1_i7] = c1_y[c1_i7 + 6 * c1_i8];
      }
    }

    for (c1_i9 = 0; c1_i9 < 6; c1_i9 = c1_i9 + 1) {
      c1_dC6[c1_i9] = 0.0;
    }

    for (c1_i10 = 0; c1_i10 < 108; c1_i10 = c1_i10 + 1) {
      c1_B[c1_i10] = c1_b[c1_i10];
    }

    for (c1_i11 = 0; c1_i11 < 6; c1_i11 = c1_i11 + 1) {
      c1_C[c1_i11] = c1_dC6[c1_i11];
    }

    for (c1_i12 = 0; c1_i12 < 6; c1_i12 = c1_i12 + 1) {
      c1_dC6[c1_i12] = c1_C[c1_i12];
    }

    for (c1_i13 = 0; c1_i13 < 108; c1_i13 = c1_i13 + 1) {
      c1_b_B[c1_i13] = c1_B[c1_i13];
    }

    for (c1_i14 = 0; c1_i14 < 6; c1_i14 = c1_i14 + 1) {
      c1_b_C[c1_i14] = c1_dC6[c1_i14];
    }

    for (c1_i15 = 0; c1_i15 < 6; c1_i15 = c1_i15 + 1) {
      c1_dC6[c1_i15] = c1_b_C[c1_i15];
    }

    for (c1_i16 = 0; c1_i16 < 108; c1_i16 = c1_i16 + 1) {
      c1_c_B[c1_i16] = c1_b_B[c1_i16];
    }

    for (c1_i17 = 0; c1_i17 < 6; c1_i17 = c1_i17 + 1) {
      c1_dC6[c1_i17] = 0.0;
      for (c1_i18 = 0; c1_i18 < 18; c1_i18 = c1_i18 + 1) {
        c1_hoistedExpr = c1_i18;
        c1_dC6[c1_i17] = c1_dC6[c1_i17] + c1_c_B[c1_i18 + 18 * c1_i17];
      }
    }
  } else {
    _SFD_EML_CALL(0,9);
    c1_b_damagecase = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("damagecase", (real_T)c1_damagecase), 1, 6, 1, 0) - 1;
    for (c1_i19 = 0; c1_i19 < 6; c1_i19 = c1_i19 + 1) {
      for (c1_i20 = 0; c1_i20 < 18; c1_i20 = c1_i20 + 1) {
        c1_b_hoistedExpr = c1_i20;
        c1_c_hoistedExpr = c1_i19;
        c1_dv2[c1_i20 + 18 * c1_i19] = c1_dv1[(c1_b_damagecase + 6 *
          c1_b_hoistedExpr) + 108 * c1_c_hoistedExpr];
      }
    }

    c1_squeeze(chartInstance, c1_dv2, c1_dv3);
    for (c1_i21 = 0; c1_i21 < 108; c1_i21 = c1_i21 + 1) {
      c1_gain[c1_i21] = c1_dv3[c1_i21];
    }

    _SFD_EML_CALL(0,10);
    for (c1_i22 = 0; c1_i22 < 108; c1_i22 = c1_i22 + 1) {
      c1_c_x[c1_i22] = c1_SurfVec[c1_i22];
    }

    for (c1_c_k = 1; c1_c_k < 109; c1_c_k = c1_c_k + 1) {
      c1_d_k = c1_c_k;
      c1_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)
        c1_d_k), 1, 108, 1, 0) - 1] = c1_c_x[
        _SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("k", (real_T)c1_d_k),
        1, 108, 1, 0) - 1];
    }

    for (c1_i23 = 0; c1_i23 < 6; c1_i23 = c1_i23 + 1) {
      for (c1_i24 = 0; c1_i24 < 18; c1_i24 = c1_i24 + 1) {
        c1_b_b[c1_i24 + 18 * c1_i23] = c1_b_y[c1_i23 + 6 * c1_i24] *
          c1_gain[c1_i24 + 18 * c1_i23];
      }
    }

    for (c1_i25 = 0; c1_i25 < 6; c1_i25 = c1_i25 + 1) {
      c1_dC6[c1_i25] = 0.0;
    }

    for (c1_i26 = 0; c1_i26 < 108; c1_i26 = c1_i26 + 1) {
      c1_d_B[c1_i26] = c1_b_b[c1_i26];
    }

    for (c1_i27 = 0; c1_i27 < 6; c1_i27 = c1_i27 + 1) {
      c1_c_C[c1_i27] = c1_dC6[c1_i27];
    }

    for (c1_i28 = 0; c1_i28 < 6; c1_i28 = c1_i28 + 1) {
      c1_dC6[c1_i28] = c1_c_C[c1_i28];
    }

    for (c1_i29 = 0; c1_i29 < 108; c1_i29 = c1_i29 + 1) {
      c1_e_B[c1_i29] = c1_d_B[c1_i29];
    }

    for (c1_i30 = 0; c1_i30 < 6; c1_i30 = c1_i30 + 1) {
      c1_d_C[c1_i30] = c1_dC6[c1_i30];
    }

    for (c1_i31 = 0; c1_i31 < 6; c1_i31 = c1_i31 + 1) {
      c1_dC6[c1_i31] = c1_d_C[c1_i31];
    }

    for (c1_i32 = 0; c1_i32 < 108; c1_i32 = c1_i32 + 1) {
      c1_f_B[c1_i32] = c1_e_B[c1_i32];
    }

    for (c1_i33 = 0; c1_i33 < 6; c1_i33 = c1_i33 + 1) {
      c1_dC6[c1_i33] = 0.0;
      for (c1_i34 = 0; c1_i34 < 18; c1_i34 = c1_i34 + 1) {
        c1_d_hoistedExpr = c1_i34;
        c1_dC6[c1_i33] = c1_dC6[c1_i33] + c1_f_B[c1_i34 + 18 * c1_i33];
      }
    }
  }

  _SFD_EML_CALL(0,-10);
  sf_debug_symbol_scope_pop();
  for (c1_i35 = 0; c1_i35 < 6; c1_i35 = c1_i35 + 1) {
    (*c1_b_dC6)[c1_i35] = c1_dC6[c1_i35];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_round(SFc1_GTM_aerolibInstanceStruct *chartInstance, real_T
  c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x;
  if (c1_e_x < 0.0) {
    c1_d_x = muDoubleScalarCeil(c1_e_x - 0.5);
  } else {
    c1_d_x = muDoubleScalarFloor(c1_e_x + 0.5);
  }

  return c1_d_x;
}

static void c1_squeeze(SFc1_GTM_aerolibInstanceStruct *chartInstance, real_T
  c1_a[108], real_T c1_b[108])
{
  int32_T c1_i36;
  real_T c1_x[108];
  int32_T c1_k;
  int32_T c1_b_k;
  for (c1_i36 = 0; c1_i36 < 108; c1_i36 = c1_i36 + 1) {
    c1_x[c1_i36] = c1_a[c1_i36];
  }

  for (c1_k = 1; c1_k < 109; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)c1_b_k),
      1, 108, 1, 0) - 1] = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("x", _SFD_INTEGER_CHECK("k", (real_T)c1_b_k), 1, 108, 1, 0) - 1];
  }
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i37;
  real_T c1_b_u[108];
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i37 = 0; c1_i37 < 108; c1_i37 = c1_i37 + 1) {
    c1_b_u[c1_i37] = (*((real_T (*)[108])c1_u))[c1_i37];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 108));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  real_T c1_b_u[648];
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i38 = 0; c1_i38 < 6; c1_i38 = c1_i38 + 1) {
    for (c1_i39 = 0; c1_i39 < 18; c1_i39 = c1_i39 + 1) {
      for (c1_i40 = 0; c1_i40 < 6; c1_i40 = c1_i40 + 1) {
        c1_b_u[(c1_i40 + 6 * c1_i39) + 108 * c1_i38] = (*((real_T (*)[648])c1_u))
          [(c1_i40 + 6 * c1_i39) + 108 * c1_i38];
      }
    }
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 3, 6, 18, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i41;
  real_T c1_b_u[6];
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i41 = 0; c1_i41 < 6; c1_i41 = c1_i41 + 1) {
    c1_b_u[c1_i41] = (*((real_T (*)[6])c1_u))[c1_i41];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  uint32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((uint32_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 7, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_b_u[108];
  const mxArray *c1_b_y = NULL;
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i42 = 0; c1_i42 < 6; c1_i42 = c1_i42 + 1) {
    for (c1_i43 = 0; c1_i43 < 18; c1_i43 = c1_i43 + 1) {
      c1_b_u[c1_i43 + 18 * c1_i42] = (*((real_T (*)[108])c1_u))[c1_i43 + 18 *
        c1_i42];
    }
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 18, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_GTM_aerolib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[59];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i44;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 59));
  for (c1_i44 = 0; c1_i44 < 59; c1_i44 = c1_i44 + 1) {
    c1_r0 = &c1_info[c1_i44];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i44);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i44);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i44);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i44);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i44);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i44
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i44
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[59])
{
  c1_info[0].context = "";
  c1_info[0].name = "squeeze";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c1_info[0].fileLength = 668U;
  c1_info[0].fileTime1 = 1209356018U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[1].name = "isinf";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[1].fileLength = 472U;
  c1_info[1].fileTime1 = 1192491934U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[2].name = "isreal";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[B]isreal";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[3].name = "islogical";
  c1_info[3].dominantType = "logical";
  c1_info[3].resolved = "[B]islogical";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[4].name = "false";
  c1_info[4].dominantType = "";
  c1_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[4].fileLength = 238U;
  c1_info[4].fileTime1 = 1192491920U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[5].name = "eml_index_class";
  c1_info[5].dominantType = "";
  c1_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[5].fileLength = 909U;
  c1_info[5].fileTime1 = 1192491982U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "eml_xgemm";
  c1_info[6].dominantType = "int32";
  c1_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[6].fileLength = 3184U;
  c1_info[6].fileTime1 = 1209356052U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[7].name = "isvector";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isvector";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_to_size";
  c1_info[8].name = "assert";
  c1_info[8].dominantType = "char";
  c1_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[8].fileLength = 2684U;
  c1_info[8].fileTime1 = 1210895856U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[9].name = "size";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]size";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[10].name = "intmax";
  c1_info[10].dominantType = "char";
  c1_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[10].fileLength = 1535U;
  c1_info[10].fileTime1 = 1192491928U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_to_size";
  c1_info[11].name = "le";
  c1_info[11].dominantType = "int32";
  c1_info[11].resolved = "[B]le";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_to_size";
  c1_info[12].name = "eml_index_prod";
  c1_info[12].dominantType = "int32";
  c1_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[12].fileLength = 547U;
  c1_info[12].fileTime1 = 1210895846U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[13].name = "logical";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]logical";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[14].name = "minus";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]minus";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[15].name = "eml_index_minus";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[15].fileLength = 277U;
  c1_info[15].fileTime1 = 1192491984U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_nempty";
  c1_info[16].name = "zeros";
  c1_info[16].dominantType = "char";
  c1_info[16].resolved = "[B]zeros";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[17].name = "eml_index_times";
  c1_info[17].dominantType = "int32";
  c1_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[17].fileLength = 280U;
  c1_info[17].fileTime1 = 1192491988U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[18].name = "not";
  c1_info[18].dominantType = "logical";
  c1_info[18].resolved = "[B]not";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[19].name = "isfloat";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]isfloat";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[20].name = "true";
  c1_info[20].dominantType = "";
  c1_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[20].fileLength = 237U;
  c1_info[20].fileTime1 = 1192491962U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[21].name = "int32";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved = "[B]int32";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "";
  c1_info[22].name = "ctranspose";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]ctranspose";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[23].name = "and";
  c1_info[23].dominantType = "logical";
  c1_info[23].resolved = "[B]and";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[24].name = "eml_scalar_round";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[24].fileLength = 523U;
  c1_info[24].fileTime1 = 1203473208U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context = "";
  c1_info[25].name = "cast";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[25].fileLength = 866U;
  c1_info[25].fileTime1 = 1192491844U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[26].name = "gt";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]gt";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "";
  c1_info[27].name = "eq";
  c1_info[27].dominantType = "uint32";
  c1_info[27].resolved = "[B]eq";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "";
  c1_info[28].name = "round";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[28].fileLength = 331U;
  c1_info[28].fileTime1 = 1203473238U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[29].name = "eml_blas_xgemm";
  c1_info[29].dominantType = "int32";
  c1_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c1_info[29].fileLength = 355U;
  c1_info[29].fileTime1 = 1192492054U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[30].name = "ischar";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved = "[B]ischar";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[31].name = "lt";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]lt";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_to_size";
  c1_info[32].name = "eml_assert_valid_size_arg";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[32].fileLength = 2835U;
  c1_info[32].fileTime1 = 1210895844U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "";
  c1_info[33].name = "transpose";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]transpose";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[34].name = "nargin";
  c1_info[34].dominantType = "";
  c1_info[34].resolved = "[B]nargin";
  c1_info[34].fileLength = 0U;
  c1_info[34].fileTime1 = 0U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[35].name = "ndims";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]ndims";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[36].name = "double";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]double";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[37].name = "strcmp";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved = "[B]strcmp";
  c1_info[37].fileLength = 0U;
  c1_info[37].fileTime1 = 0U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[38].name = "isinteger";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]isinteger";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "";
  c1_info[39].name = "reshape";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[39].fileLength = 2221U;
  c1_info[39].fileTime1 = 1209356014U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[40].name = "eml_alloc";
  c1_info[40].dominantType = "int32";
  c1_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[40].fileLength = 2627U;
  c1_info[40].fileTime1 = 1213662886U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[41].name = "plus";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[B]plus";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m/varargin_nempty";
  c1_info[42].name = "isempty";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[B]isempty";
  c1_info[42].fileLength = 0U;
  c1_info[42].fileTime1 = 0U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[43].name = "ne";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved = "[B]ne";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c1_info[44].name = "eml_refblas_xgemm";
  c1_info[44].dominantType = "int32";
  c1_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[44].fileLength = 5746U;
  c1_info[44].fileTime1 = 1210895858U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[45].name = "isa";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved = "[B]isa";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[46].name = "isstruct";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved = "[B]isstruct";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context = "";
  c1_info[47].name = "ones";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]ones";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[48].name = "eml_index_plus";
  c1_info[48].dominantType = "int32";
  c1_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[48].fileLength = 272U;
  c1_info[48].fileTime1 = 1192491986U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[49].name = "eml_zeros";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zeros.m";
  c1_info[49].fileLength = 1083U;
  c1_info[49].fileTime1 = 1213662888U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[50].name = "uint32";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved = "[B]uint32";
  c1_info[50].fileLength = 0U;
  c1_info[50].fileTime1 = 0U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[51].name = "class";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved = "[B]class";
  c1_info[51].fileLength = 0U;
  c1_info[51].fileTime1 = 0U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[52].name = "mtimes";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[52].fileLength = 2336U;
  c1_info[52].fileTime1 = 1213662890U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[53].name = "isfinite";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[53].fileLength = 341U;
  c1_info[53].fileTime1 = 1192491934U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "";
  c1_info[54].name = "times";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved = "[B]times";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[55].name = "ge";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved = "[B]ge";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[56].name = "isnan";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[56].fileLength = 472U;
  c1_info[56].fileTime1 = 1192491936U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[57].name = "isscalar";
  c1_info[57].dominantType = "logical";
  c1_info[57].resolved = "[B]isscalar";
  c1_info[57].fileLength = 0U;
  c1_info[57].fileTime1 = 0U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[58].name = "isnumeric";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved = "[B]isnumeric";
  c1_info[58].fileLength = 0U;
  c1_info[58].fileTime1 = 0U;
  c1_info[58].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc1_GTM_aerolibInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_GTM_aerolib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2738692555U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(251903528U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3394347981U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3551005169U);
}

mxArray *sf_c1_GTM_aerolib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2105698493U);
    pr[1] = (double)(3698935019U);
    pr[2] = (double)(602904887U);
    pr[3] = (double)(816139187U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(108);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(18);
      pr[2] = (double)(6);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_GTM_aerolibMachineNumber_,
           1,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_GTM_aerolibMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_GTM_aerolibMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_GTM_aerolibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 108;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"SurfVec",0,c1_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "DamageCase",0,c1_b_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 6;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"dC6",0,c1_d_sf_marshall);
          }

          {
            unsigned int dimVector[3];
            dimVector[0]= 6;
            dimVector[1]= 18;
            dimVector[2]= 6;
            _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"SurfGain",0,c1_c_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,402);
        _SFD_CV_INIT_EML_IF(0,0,207,225,280,398);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c1_SurfVec)[108];
          real_T *c1_DamageCase;
          real_T (*c1_dC6)[6];
          c1_DamageCase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_SurfVec = (real_T (*)[108])ssGetInputPortSignal(chartInstance->S, 0);
          c1_dC6 = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_SurfVec);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_DamageCase);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_dC6);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c1_SurfGain);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_GTM_aerolibMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c1_GTM_aerolib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*)
    chartInstanceVar);
  initialize_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_GTM_aerolib(void *chartInstanceVar)
{
  enable_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_GTM_aerolib(void *chartInstanceVar)
{
  disable_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_GTM_aerolib(void *chartInstanceVar)
{
  sf_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c1_GTM_aerolib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_GTM_aerolib
    ((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c1_GTM_aerolib(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_GTM_aerolib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_GTM_aerolib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_GTM_aerolib((SFc1_GTM_aerolibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_GTM_aerolib(SimStruct *S)
{
  /* Actual parameters from chart:
     SurfGain
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for SurfGain*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("GTM_aerolib","gtm_design_dbg",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("GTM_aerolib","gtm_design_dbg",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("GTM_aerolib",
      "gtm_design_dbg",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"GTM_aerolib","gtm_design_dbg",1,2);
      sf_mark_chart_reusable_outputs(S,"GTM_aerolib","gtm_design_dbg",1,1);
    }

    sf_set_rtw_dwork_info(S,"GTM_aerolib","gtm_design_dbg",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2539524138U));
  ssSetChecksum1(S,(841892649U));
  ssSetChecksum2(S,(2051375385U));
  ssSetChecksum3(S,(2692774494U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_GTM_aerolib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "GTM_aerolib", "gtm_design_dbg",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_GTM_aerolib(SimStruct *S)
{
  SFc1_GTM_aerolibInstanceStruct *chartInstance;
  chartInstance = (SFc1_GTM_aerolibInstanceStruct *)malloc(sizeof
    (SFc1_GTM_aerolibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_GTM_aerolib;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_GTM_aerolib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_GTM_aerolib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_GTM_aerolib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_GTM_aerolib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_GTM_aerolib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_GTM_aerolib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_GTM_aerolib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_GTM_aerolib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_GTM_aerolib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c1_GTM_aerolib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_GTM_aerolib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_GTM_aerolib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_GTM_aerolib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_GTM_aerolib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
