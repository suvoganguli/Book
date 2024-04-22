/* Include files */

#include "models_sfun.h"
#include "c5_models.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "models_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void initialize_params_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void enable_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void disable_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void update_debugger_state_c5_models(SFc5_modelsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_models(SFc5_modelsInstanceStruct
  *chartInstance);
static void set_sim_state_c5_models(SFc5_modelsInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void sf_c5_models(SFc5_modelsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static real_T c5_cosd(SFc5_modelsInstanceStruct *chartInstance, real_T c5_x);
static real_T c5_eml_scalar_mod(SFc5_modelsInstanceStruct *chartInstance, real_T
  c5_x, real_T c5_y);
static real_T c5_sind(SFc5_modelsInstanceStruct *chartInstance, real_T c5_x);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[52]);
static void init_dsm_address_info(SFc5_modelsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_models = 0U;
}

static void initialize_params_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
  real_T c5_dv0[3];
  int32_T c5_i0;
  real_T c5_dv1[3];
  int32_T c5_i1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'engl_ang' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c5_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c5_i0 = 0; c5_i0 < 3; c5_i0 = c5_i0 + 1) {
    chartInstance->c5_engl_ang[c5_i0] = c5_dv0[c5_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'engr_ang' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c5_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1 = c5_i1 + 1) {
    chartInstance->c5_engr_ang[c5_i1] = c5_dv1[c5_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c5_models(SFc5_modelsInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_models(SFc5_modelsInstanceStruct
  *chartInstance)
{
  return NULL;
}

static void set_sim_state_c5_models(SFc5_modelsInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
}

static void sf_c5_models(SFc5_modelsInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  uint8_T c5_previousEvent;
  real_T c5_Tl;
  real_T c5_hl;
  real_T c5_Tr;
  real_T c5_hr;
  int32_T c5_i8;
  real_T c5_b_engl_ang[3];
  int32_T c5_i9;
  real_T c5_b_engr_ang[3];
  real_T c5_nargout = 4.0;
  real_T c5_nargin = 6.0;
  real_T c5_H[3];
  real_T c5_TR[3];
  real_T c5_TL[3];
  real_T c5_T[3];
  real_T c5_a;
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_y;
  real_T c5_c_a;
  real_T c5_b_b;
  real_T c5_b_y;
  real_T c5_d0;
  real_T c5_c_b[3];
  int32_T c5_i10;
  real_T c5_d_a;
  real_T c5_e_a;
  real_T c5_d_b;
  real_T c5_c_y;
  real_T c5_f_a;
  real_T c5_e_b;
  real_T c5_d_y;
  real_T c5_d1;
  real_T c5_f_b[3];
  int32_T c5_i11;
  int32_T c5_i12;
  real_T c5_g_a;
  real_T c5_h_a;
  real_T c5_g_b;
  real_T c5_e_y;
  real_T c5_i_a;
  real_T c5_h_b;
  real_T c5_f_y;
  real_T c5_d2;
  real_T c5_i_b[3];
  int32_T c5_i13;
  real_T c5_g_y[3];
  real_T c5_j_a;
  real_T c5_k_a;
  real_T c5_j_b;
  real_T c5_h_y;
  real_T c5_l_a;
  real_T c5_k_b;
  real_T c5_i_y;
  real_T c5_d3;
  real_T c5_l_b[3];
  int32_T c5_i14;
  real_T c5_j_y[3];
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  real_T *c5_b_Tl;
  real_T *c5_b_hl;
  real_T *c5_b_Tr;
  real_T *c5_b_hr;
  real_T (*c5_b_T)[3];
  real_T (*c5_b_TL)[3];
  real_T (*c5_b_TR)[3];
  real_T (*c5_b_H)[3];
  c5_b_H = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c5_b_TL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_hl = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_T = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_Tl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_hr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_TR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_Tr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2 = c5_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_T)[c5_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_Tl, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_hl, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Tr, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_hr, 4U);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3 = c5_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_TL)[c5_i3], 5U);
  }

  for (c5_i4 = 0; c5_i4 < 3; c5_i4 = c5_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_engl_ang[c5_i4], 6U);
  }

  for (c5_i5 = 0; c5_i5 < 3; c5_i5 = c5_i5 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_engr_ang[c5_i5], 7U);
  }

  for (c5_i6 = 0; c5_i6 < 3; c5_i6 = c5_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_TR)[c5_i6], 8U);
  }

  for (c5_i7 = 0; c5_i7 < 3; c5_i7 = c5_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_H)[c5_i7], 9U);
  }

  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  c5_Tl = *c5_b_Tl;
  c5_hl = *c5_b_hl;
  c5_Tr = *c5_b_Tr;
  c5_hr = *c5_b_hr;
  for (c5_i8 = 0; c5_i8 < 3; c5_i8 = c5_i8 + 1) {
    c5_b_engl_ang[c5_i8] = chartInstance->c5_engl_ang[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 3; c5_i9 = c5_i9 + 1) {
    c5_b_engr_ang[c5_i9] = chartInstance->c5_engr_ang[c5_i9];
  }

  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("nargout", &c5_nargout, c5_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c5_nargin, c5_sf_marshall);
  sf_debug_symbol_scope_add("H", &c5_H, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("TR", &c5_TR, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("TL", &c5_TL, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("T", &c5_T, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("engr_ang", &c5_b_engr_ang, c5_b_sf_marshall);
  sf_debug_symbol_scope_add("engl_ang", &c5_b_engl_ang, c5_b_sf_marshall);
  sf_debug_symbol_scope_add("hr", &c5_hr, c5_sf_marshall);
  sf_debug_symbol_scope_add("Tr", &c5_Tr, c5_sf_marshall);
  sf_debug_symbol_scope_add("hl", &c5_hl, c5_sf_marshall);
  sf_debug_symbol_scope_add("Tl", &c5_Tl, c5_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  Using the engine alignment angles (set in AC_params_T2.m), compute the  */
  /*  off-axis thrust and angular momentum terms. */
  _SFD_EML_CALL(0,8);
  c5_a = c5_Tl;
  c5_b_a = c5_sind(chartInstance, c5_b_engl_ang[1]);
  c5_b = c5_cosd(chartInstance, c5_b_engl_ang[2]);
  c5_y = c5_b_a * c5_b;
  c5_c_a = c5_cosd(chartInstance, c5_b_engl_ang[1]);
  c5_b_b = c5_cosd(chartInstance, c5_b_engl_ang[2]);
  c5_b_y = c5_c_a * c5_b_b;
  c5_d0 = -c5_sind(chartInstance, c5_b_engl_ang[2]);
  c5_c_b[0] = c5_b_y;
  c5_c_b[1] = c5_d0;
  c5_c_b[2] = c5_y;
  for (c5_i10 = 0; c5_i10 < 3; c5_i10 = c5_i10 + 1) {
    c5_TL[c5_i10] = c5_a * c5_c_b[c5_i10];
  }

  _SFD_EML_CALL(0,11);
  c5_d_a = c5_Tr;
  c5_e_a = c5_sind(chartInstance, c5_b_engr_ang[1]);
  c5_d_b = c5_cosd(chartInstance, c5_b_engr_ang[2]);
  c5_c_y = c5_e_a * c5_d_b;
  c5_f_a = c5_cosd(chartInstance, c5_b_engr_ang[1]);
  c5_e_b = c5_cosd(chartInstance, c5_b_engr_ang[2]);
  c5_d_y = c5_f_a * c5_e_b;
  c5_d1 = -c5_sind(chartInstance, c5_b_engr_ang[2]);
  c5_f_b[0] = c5_d_y;
  c5_f_b[1] = c5_d1;
  c5_f_b[2] = c5_c_y;
  for (c5_i11 = 0; c5_i11 < 3; c5_i11 = c5_i11 + 1) {
    c5_TR[c5_i11] = c5_d_a * c5_f_b[c5_i11];
  }

  _SFD_EML_CALL(0,14);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12 = c5_i12 + 1) {
    c5_T[c5_i12] = c5_TL[c5_i12] + c5_TR[c5_i12];
  }

  _SFD_EML_CALL(0,16);
  c5_g_a = c5_hr;
  c5_h_a = c5_sind(chartInstance, c5_b_engr_ang[1]);
  c5_g_b = c5_cosd(chartInstance, c5_b_engr_ang[2]);
  c5_e_y = c5_h_a * c5_g_b;
  c5_i_a = c5_cosd(chartInstance, c5_b_engr_ang[1]);
  c5_h_b = c5_cosd(chartInstance, c5_b_engr_ang[2]);
  c5_f_y = c5_i_a * c5_h_b;
  c5_d2 = -c5_sind(chartInstance, c5_b_engr_ang[2]);
  c5_i_b[0] = c5_f_y;
  c5_i_b[1] = c5_d2;
  c5_i_b[2] = c5_e_y;
  for (c5_i13 = 0; c5_i13 < 3; c5_i13 = c5_i13 + 1) {
    c5_g_y[c5_i13] = c5_g_a * c5_i_b[c5_i13];
  }

  c5_j_a = c5_hl;
  c5_k_a = c5_sind(chartInstance, c5_b_engl_ang[1]);
  c5_j_b = c5_cosd(chartInstance, c5_b_engl_ang[2]);
  c5_h_y = c5_k_a * c5_j_b;
  c5_l_a = c5_cosd(chartInstance, c5_b_engl_ang[1]);
  c5_k_b = c5_cosd(chartInstance, c5_b_engl_ang[2]);
  c5_i_y = c5_l_a * c5_k_b;
  c5_d3 = -c5_sind(chartInstance, c5_b_engl_ang[2]);
  c5_l_b[0] = c5_i_y;
  c5_l_b[1] = c5_d3;
  c5_l_b[2] = c5_h_y;
  for (c5_i14 = 0; c5_i14 < 3; c5_i14 = c5_i14 + 1) {
    c5_j_y[c5_i14] = c5_j_a * c5_l_b[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 3; c5_i15 = c5_i15 + 1) {
    c5_H[c5_i15] = c5_j_y[c5_i15] + c5_g_y[c5_i15];
  }

  _SFD_EML_CALL(0,-16);
  sf_debug_symbol_scope_pop();
  for (c5_i16 = 0; c5_i16 < 3; c5_i16 = c5_i16 + 1) {
    (*c5_b_T)[c5_i16] = c5_T[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 3; c5_i17 = c5_i17 + 1) {
    (*c5_b_TL)[c5_i17] = c5_TL[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 3; c5_i18 = c5_i18 + 1) {
    (*c5_b_TR)[c5_i18] = c5_TR[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 3; c5_i19 = c5_i19 + 1) {
    (*c5_b_H)[c5_i19] = c5_H[c5_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_modelsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static real_T c5_cosd(SFc5_modelsInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_n;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_m;
  real_T c5_h_x;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_d_x = c5_c_x;
  c5_e_x = c5_d_x / 90.0;
  c5_n = c5_e_x;
  c5_f_x = c5_n;
  if (c5_f_x < 0.0) {
    c5_n = muDoubleScalarCeil(c5_f_x - 0.5);
  } else {
    c5_n = muDoubleScalarFloor(c5_f_x + 0.5);
  }

  c5_d_x = c5_d_x - c5_n * 90.0;
  c5_g_x = c5_eml_scalar_mod(chartInstance, c5_n, 4.0);
  c5_m = c5_g_x;
  c5_h_x = c5_m;
  if (c5_h_x < 0.0) {
    c5_m = muDoubleScalarCeil(c5_h_x - 0.5);
  } else {
    c5_m = muDoubleScalarFloor(c5_h_x + 0.5);
  }

  if (c5_m < 2.0) {
    if (c5_m < 1.0) {
      c5_d_x = muDoubleScalarCos(1.7453292519943295E-002 * c5_d_x);
    } else {
      c5_d_x = -muDoubleScalarSin(1.7453292519943295E-002 * c5_d_x);
    }
  } else if (c5_m < 3.0) {
    c5_d_x = -muDoubleScalarCos(1.7453292519943295E-002 * c5_d_x);
  } else {
    c5_d_x = muDoubleScalarSin(1.7453292519943295E-002 * c5_d_x);
  }

  return c5_d_x;
}

static real_T c5_eml_scalar_mod(SFc5_modelsInstanceStruct *chartInstance, real_T
  c5_x, real_T c5_y)
{
  real_T c5_r;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_b;
  real_T c5_b_y;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_c_y;
  real_T c5_l_x;
  real_T c5_m_x;
  if (c5_y == 0.0) {
    c5_b_x = c5_x;
    return c5_b_x;
  } else {
    c5_c_x = c5_y;
    c5_d_x = c5_c_x;
    c5_d_x = muDoubleScalarFloor(c5_d_x);
    if (c5_y == c5_d_x) {
      c5_e_x = c5_x / c5_y;
      c5_f_x = c5_e_x;
      c5_f_x = muDoubleScalarFloor(c5_f_x);
      return c5_x - c5_f_x * c5_y;
    } else {
      c5_r = c5_x / c5_y;
      c5_g_x = c5_r;
      c5_b = muDoubleScalarAbs(c5_g_x);
      c5_b_y = 2.2204460492503131E-016 * c5_b;
      c5_h_x = c5_r;
      c5_i_x = c5_h_x;
      c5_j_x = c5_i_x;
      if (c5_j_x < 0.0) {
        c5_i_x = muDoubleScalarCeil(c5_j_x - 0.5);
      } else {
        c5_i_x = muDoubleScalarFloor(c5_j_x + 0.5);
      }

      c5_k_x = c5_r - c5_i_x;
      c5_c_y = muDoubleScalarAbs(c5_k_x);
      if (c5_c_y <= c5_b_y) {
        return 0.0;
      } else {
        c5_l_x = c5_r;
        c5_m_x = c5_l_x;
        c5_m_x = muDoubleScalarFloor(c5_m_x);
        return (c5_r - c5_m_x) * c5_y;
      }
    }
  }
}

static real_T c5_sind(SFc5_modelsInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_n;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_m;
  real_T c5_h_x;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_d_x = c5_c_x;
  c5_e_x = c5_d_x / 90.0;
  c5_n = c5_e_x;
  c5_f_x = c5_n;
  if (c5_f_x < 0.0) {
    c5_n = muDoubleScalarCeil(c5_f_x - 0.5);
  } else {
    c5_n = muDoubleScalarFloor(c5_f_x + 0.5);
  }

  c5_d_x = c5_d_x - c5_n * 90.0;
  c5_g_x = c5_eml_scalar_mod(chartInstance, c5_n, 4.0);
  c5_m = c5_g_x;
  c5_h_x = c5_m;
  if (c5_h_x < 0.0) {
    c5_m = muDoubleScalarCeil(c5_h_x - 0.5);
  } else {
    c5_m = muDoubleScalarFloor(c5_h_x + 0.5);
  }

  if (c5_m < 2.0) {
    if (c5_m < 1.0) {
      c5_d_x = muDoubleScalarSin(1.7453292519943295E-002 * c5_d_x);
    } else {
      c5_d_x = muDoubleScalarCos(1.7453292519943295E-002 * c5_d_x);
    }
  } else if (c5_m < 3.0) {
    c5_d_x = -muDoubleScalarSin(1.7453292519943295E-002 * c5_d_x);
  } else {
    c5_d_x = -muDoubleScalarCos(1.7453292519943295E-002 * c5_d_x);
  }

  return c5_d_x;
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc5_modelsInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i20;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  SFc5_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc5_modelsInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i20 = 0; c5_i20 < 3; c5_i20 = c5_i20 + 1) {
    c5_b_u[c5_i20] = (*((real_T (*)[3])c5_u))[c5_i20];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i21;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  SFc5_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc5_modelsInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i21 = 0; c5_i21 < 3; c5_i21 = c5_i21 + 1) {
    c5_b_u[c5_i21] = (*((real_T (*)[3])c5_u))[c5_i21];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_models_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[52];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i22;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52));
  for (c5_i22 = 0; c5_i22 < 52; c5_i22 = c5_i22 + 1) {
    c5_r0 = &c5_info[c5_i22];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i22);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i22);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i22);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i22);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i22);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i22
                    );
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i22
                    );
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[52])
{
  c5_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[0].name = "intmax";
  c5_info[0].dominantType = "char";
  c5_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[0].fileLength = 1535U;
  c5_info[0].fileTime1 = 1192491928U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[1].name = "gt";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved = "[B]gt";
  c5_info[1].fileLength = 0U;
  c5_info[1].fileTime1 = 0U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[2].name = "eml_is_float_class";
  c5_info[2].dominantType = "char";
  c5_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[2].fileLength = 226U;
  c5_info[2].fileTime1 = 1197875642U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].name = "class";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]class";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[4].name = "nargin";
  c5_info[4].dominantType = "";
  c5_info[4].resolved = "[B]nargin";
  c5_info[4].fileLength = 0U;
  c5_info[4].fileTime1 = 0U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[5].name = "eml_index_class";
  c5_info[5].dominantType = "";
  c5_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[5].fileLength = 909U;
  c5_info[5].fileTime1 = 1192491982U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[6].name = "isreal";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[B]isreal";
  c5_info[6].fileLength = 0U;
  c5_info[6].fileTime1 = 0U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[7].name = "eq";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[B]eq";
  c5_info[7].fileLength = 0U;
  c5_info[7].fileTime1 = 0U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[8].name = "uminus";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]uminus";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c5_info[9].name = "eml_scalar_sind";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c5_info[9].fileLength = 498U;
  c5_info[9].fileTime1 = 1209355992U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[10].name = "islogical";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved = "[B]islogical";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[11].name = "times";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[B]times";
  c5_info[11].fileLength = 0U;
  c5_info[11].fileTime1 = 0U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[12].name = "not";
  c5_info[12].dominantType = "logical";
  c5_info[12].resolved = "[B]not";
  c5_info[12].fileLength = 0U;
  c5_info[12].fileTime1 = 0U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c5_info[13].name = "lt";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[B]lt";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[14].name = "int32";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved = "[B]int32";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[15].name = "and";
  c5_info[15].dominantType = "logical";
  c5_info[15].resolved = "[B]and";
  c5_info[15].fileLength = 0U;
  c5_info[15].fileTime1 = 0U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c5_info[16].name = "eml_scalar_mod";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[16].fileLength = 1087U;
  c5_info[16].fileTime1 = 1213662882U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c5_info[17].name = "mtimes";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[17].fileLength = 2336U;
  c5_info[17].fileTime1 = 1213662890U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[18].name = "zeros";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved = "[B]zeros";
  c5_info[18].fileLength = 0U;
  c5_info[18].fileTime1 = 0U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "";
  c5_info[19].name = "sind";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c5_info[19].fileLength = 378U;
  c5_info[19].fileTime1 = 1203473244U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[20].name = "eml_scalar_cosd";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c5_info[20].fileLength = 497U;
  c5_info[20].fileTime1 = 1209355988U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c5_info[21].name = "eml_scalar_round";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c5_info[21].fileLength = 523U;
  c5_info[21].fileTime1 = 1203473208U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[22].name = "eml_scalar_abs";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[22].fileLength = 461U;
  c5_info[22].fileTime1 = 1203473160U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[23].name = "ge";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved = "[B]ge";
  c5_info[23].fileLength = 0U;
  c5_info[23].fileTime1 = 0U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c5_info[24].name = "cast";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[24].fileLength = 866U;
  c5_info[24].fileTime1 = 1192491844U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[25].name = "eml_scalar_floor";
  c5_info[25].dominantType = "double";
  c5_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[25].fileLength = 260U;
  c5_info[25].fileTime1 = 1209355990U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[26].name = "isscalar";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved = "[B]isscalar";
  c5_info[26].fileLength = 0U;
  c5_info[26].fileTime1 = 0U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c5_info[27].name = "minus";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved = "[B]minus";
  c5_info[27].fileLength = 0U;
  c5_info[27].fileTime1 = 0U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[28].name = "logical";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved = "[B]logical";
  c5_info[28].fileLength = 0U;
  c5_info[28].fileTime1 = 0U;
  c5_info[28].fileTime2 = 0U;
  c5_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c5_info[29].name = "le";
  c5_info[29].dominantType = "double";
  c5_info[29].resolved = "[B]le";
  c5_info[29].fileLength = 0U;
  c5_info[29].fileTime1 = 0U;
  c5_info[29].fileTime2 = 0U;
  c5_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c5_info[30].name = "isfinite";
  c5_info[30].dominantType = "double";
  c5_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[30].fileLength = 341U;
  c5_info[30].fileTime1 = 1192491934U;
  c5_info[30].fileTime2 = 0U;
  c5_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c5_info[31].name = "false";
  c5_info[31].dominantType = "";
  c5_info[31].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[31].fileLength = 238U;
  c5_info[31].fileTime1 = 1192491920U;
  c5_info[31].fileTime2 = 0U;
  c5_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c5_info[32].name = "ne";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved = "[B]ne";
  c5_info[32].fileLength = 0U;
  c5_info[32].fileTime1 = 0U;
  c5_info[32].fileTime2 = 0U;
  c5_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c5_info[33].name = "true";
  c5_info[33].dominantType = "";
  c5_info[33].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c5_info[33].fileLength = 237U;
  c5_info[33].fileTime1 = 1192491962U;
  c5_info[33].fileTime2 = 0U;
  c5_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[34].name = "isstruct";
  c5_info[34].dominantType = "double";
  c5_info[34].resolved = "[B]isstruct";
  c5_info[34].fileLength = 0U;
  c5_info[34].fileTime1 = 0U;
  c5_info[34].fileTime2 = 0U;
  c5_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[35].name = "strcmp";
  c5_info[35].dominantType = "char";
  c5_info[35].resolved = "[B]strcmp";
  c5_info[35].fileLength = 0U;
  c5_info[35].fileTime1 = 0U;
  c5_info[35].fileTime2 = 0U;
  c5_info[36].context = "";
  c5_info[36].name = "cosd";
  c5_info[36].dominantType = "double";
  c5_info[36].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[36].fileLength = 378U;
  c5_info[36].fileTime1 = 1203473152U;
  c5_info[36].fileTime2 = 0U;
  c5_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[37].name = "isvector";
  c5_info[37].dominantType = "double";
  c5_info[37].resolved = "[B]isvector";
  c5_info[37].fileLength = 0U;
  c5_info[37].fileTime1 = 0U;
  c5_info[37].fileTime2 = 0U;
  c5_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[38].name = "eml_assert_valid_size_arg";
  c5_info[38].dominantType = "double";
  c5_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[38].fileLength = 2835U;
  c5_info[38].fileTime1 = 1210895844U;
  c5_info[38].fileTime2 = 0U;
  c5_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[39].name = "ischar";
  c5_info[39].dominantType = "char";
  c5_info[39].resolved = "[B]ischar";
  c5_info[39].fileLength = 0U;
  c5_info[39].fileTime1 = 0U;
  c5_info[39].fileTime2 = 0U;
  c5_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c5_info[40].name = "isinteger";
  c5_info[40].dominantType = "double";
  c5_info[40].resolved = "[B]isinteger";
  c5_info[40].fileLength = 0U;
  c5_info[40].fileTime1 = 0U;
  c5_info[40].fileTime2 = 0U;
  c5_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[41].name = "isnumeric";
  c5_info[41].dominantType = "double";
  c5_info[41].resolved = "[B]isnumeric";
  c5_info[41].fileLength = 0U;
  c5_info[41].fileTime1 = 0U;
  c5_info[41].fileTime2 = 0U;
  c5_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[42].name = "isnan";
  c5_info[42].dominantType = "double";
  c5_info[42].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[42].fileLength = 472U;
  c5_info[42].fileTime1 = 1192491936U;
  c5_info[42].fileTime2 = 0U;
  c5_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c5_info[43].name = "double";
  c5_info[43].dominantType = "double";
  c5_info[43].resolved = "[B]double";
  c5_info[43].fileLength = 0U;
  c5_info[43].fileTime1 = 0U;
  c5_info[43].fileTime2 = 0U;
  c5_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c5_info[44].name = "isfloat";
  c5_info[44].dominantType = "double";
  c5_info[44].resolved = "[B]isfloat";
  c5_info[44].fileLength = 0U;
  c5_info[44].fileTime1 = 0U;
  c5_info[44].fileTime2 = 0U;
  c5_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c5_info[45].name = "plus";
  c5_info[45].dominantType = "double";
  c5_info[45].resolved = "[B]plus";
  c5_info[45].fileLength = 0U;
  c5_info[45].fileTime1 = 0U;
  c5_info[45].fileTime2 = 0U;
  c5_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[46].name = "size";
  c5_info[46].dominantType = "double";
  c5_info[46].resolved = "[B]size";
  c5_info[46].fileLength = 0U;
  c5_info[46].fileTime1 = 0U;
  c5_info[46].fileTime2 = 0U;
  c5_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[47].name = "eml_alloc";
  c5_info[47].dominantType = "double";
  c5_info[47].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[47].fileLength = 2627U;
  c5_info[47].fileTime1 = 1213662886U;
  c5_info[47].fileTime2 = 0U;
  c5_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[48].name = "isinf";
  c5_info[48].dominantType = "double";
  c5_info[48].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c5_info[48].fileLength = 472U;
  c5_info[48].fileTime1 = 1192491934U;
  c5_info[48].fileTime2 = 0U;
  c5_info[49].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c5_info[49].name = "pi";
  c5_info[49].dominantType = "";
  c5_info[49].resolved = "[B]pi";
  c5_info[49].fileLength = 0U;
  c5_info[49].fileTime1 = 0U;
  c5_info[49].fileTime2 = 0U;
  c5_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[50].name = "eps";
  c5_info[50].dominantType = "char";
  c5_info[50].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[50].fileLength = 1342U;
  c5_info[50].fileTime1 = 1210895846U;
  c5_info[50].fileTime2 = 0U;
  c5_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c5_info[51].name = "isa";
  c5_info[51].dominantType = "double";
  c5_info[51].resolved = "[B]isa";
  c5_info[51].fileLength = 0U;
  c5_info[51].fileTime1 = 0U;
  c5_info[51].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc5_modelsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_models_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1757471492U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(473770061U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4173895986U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3870469670U);
}

mxArray *sf_c5_models_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(677209183U);
    pr[1] = (double)(51255210U);
    pr[2] = (double)(1102054563U);
    pr[3] = (double)(2243857262U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc5_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc5_modelsInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_modelsMachineNumber_,
          5,
          1,
          1,
          10,
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
          init_script_number_translation(_modelsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_modelsMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_modelsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"T",0,c5_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Tl",0,
                              c5_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"hl",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Tr",0,
                              NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"hr",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"TL",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"engl_ang",0,c5_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(7,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"engr_ang",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"TR",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"H",0,NULL);
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,821);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c5_T)[3];
          real_T *c5_Tl;
          real_T *c5_hl;
          real_T *c5_Tr;
          real_T *c5_hr;
          real_T (*c5_TL)[3];
          real_T (*c5_TR)[3];
          real_T (*c5_H)[3];
          c5_H = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
          c5_TL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c5_hl = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_T = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_Tl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_hr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_TR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c5_Tr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_T);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_Tl);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_hl);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_Tr);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_hr);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_TL);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c5_engl_ang);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c5_engr_ang);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_TR);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_H);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_modelsMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c5_models(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_modelsInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
  initialize_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_models(void *chartInstanceVar)
{
  enable_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_models(void *chartInstanceVar)
{
  disable_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_models(void *chartInstanceVar)
{
  sf_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c5_models(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c5_models((SFc5_modelsInstanceStruct*)
    chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c5_models(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar,
    sf_mex_dup(st));
}

static void sf_opaque_terminate_c5_models(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_modelsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_models((SFc5_modelsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_models(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_models((SFc5_modelsInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_models(SimStruct *S)
{
  /* Actual parameters from chart:
     engl_ang engr_ang
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for engl_ang*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for engr_ang*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("models","main_sim_claw_main_sf",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("models","main_sim_claw_main_sf",5,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("models",
      "main_sim_claw_main_sf",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"models","main_sim_claw_main_sf",5,4);
      sf_mark_chart_reusable_outputs(S,"models","main_sim_claw_main_sf",5,4);
    }

    sf_set_rtw_dwork_info(S,"models","main_sim_claw_main_sf",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3665161058U));
  ssSetChecksum1(S,(3686559358U));
  ssSetChecksum2(S,(3763387404U));
  ssSetChecksum3(S,(2324388479U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_models(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "models", "main_sim_claw_main_sf",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_models(SimStruct *S)
{
  SFc5_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc5_modelsInstanceStruct *)malloc(sizeof
    (SFc5_modelsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_models;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_models;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_models;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_models;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_models;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_models;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_models;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_models;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_models;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_models;
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

void c5_models_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_models(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_models(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_models(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_models_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
