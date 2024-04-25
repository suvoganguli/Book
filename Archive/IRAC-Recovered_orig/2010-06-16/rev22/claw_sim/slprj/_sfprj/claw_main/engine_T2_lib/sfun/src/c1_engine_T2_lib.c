/* Include files */

#include "engine_T2_lib_sfun.h"
#include "c1_engine_T2_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "engine_T2_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance);
static void initialize_params_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct *
  chartInstance);
static void enable_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance);
static void disable_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance);
static void update_debugger_state_c1_engine_T2_lib
  (SFc1_engine_T2_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_engine_T2_lib
  (SFc1_engine_T2_libInstanceStruct *chartInstance);
static void set_sim_state_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance);
static void sf_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_cosd(SFc1_engine_T2_libInstanceStruct *chartInstance, real_T
                      c1_x);
static real_T c1_eml_scalar_mod(SFc1_engine_T2_libInstanceStruct *chartInstance,
  real_T c1_x, real_T c1_y);
static real_T c1_sind(SFc1_engine_T2_libInstanceStruct *chartInstance, real_T
                      c1_x);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[52]);
static void init_dsm_address_info(SFc1_engine_T2_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_engine_T2_lib = 0U;
}

static void initialize_params_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct *
  chartInstance)
{
  real_T c1_dv0[3];
  int32_T c1_i0;
  real_T c1_dv1[3];
  int32_T c1_i1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'engl_ang' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c1_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0 = c1_i0 + 1) {
    chartInstance->c1_engl_ang[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'engr_ang' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c1_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
    chartInstance->c1_engr_ang[c1_i1] = c1_dv1[c1_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c1_engine_T2_lib
  (SFc1_engine_T2_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_engine_T2_lib
  (SFc1_engine_T2_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct
  *chartInstance)
{
}

static void sf_c1_engine_T2_lib(SFc1_engine_T2_libInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  uint8_T c1_previousEvent;
  real_T c1_Tl;
  real_T c1_hl;
  real_T c1_Tr;
  real_T c1_hr;
  int32_T c1_i8;
  real_T c1_b_engl_ang[3];
  int32_T c1_i9;
  real_T c1_b_engr_ang[3];
  real_T c1_nargout = 4.0;
  real_T c1_nargin = 6.0;
  real_T c1_H[3];
  real_T c1_TR[3];
  real_T c1_TL[3];
  real_T c1_T[3];
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_c_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_d0;
  real_T c1_c_b[3];
  int32_T c1_i10;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_d_b;
  real_T c1_c_y;
  real_T c1_f_a;
  real_T c1_e_b;
  real_T c1_d_y;
  real_T c1_d1;
  real_T c1_f_b[3];
  int32_T c1_i11;
  int32_T c1_i12;
  real_T c1_g_a;
  real_T c1_h_a;
  real_T c1_g_b;
  real_T c1_e_y;
  real_T c1_i_a;
  real_T c1_h_b;
  real_T c1_f_y;
  real_T c1_d2;
  real_T c1_i_b[3];
  int32_T c1_i13;
  real_T c1_g_y[3];
  real_T c1_j_a;
  real_T c1_k_a;
  real_T c1_j_b;
  real_T c1_h_y;
  real_T c1_l_a;
  real_T c1_k_b;
  real_T c1_i_y;
  real_T c1_d3;
  real_T c1_l_b[3];
  int32_T c1_i14;
  real_T c1_j_y[3];
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T *c1_b_Tl;
  real_T *c1_b_hl;
  real_T *c1_b_Tr;
  real_T *c1_b_hr;
  real_T (*c1_b_T)[3];
  real_T (*c1_b_TL)[3];
  real_T (*c1_b_TR)[3];
  real_T (*c1_b_H)[3];
  c1_b_T = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Tl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_Tr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_TL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_hl = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_hr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_TR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_H = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_T)[c1_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_Tl, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_hl, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Tr, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_hr, 4U);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_TL)[c1_i3], 5U);
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_engl_ang[c1_i4], 6U);
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_engr_ang[c1_i5], 7U);
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_TR)[c1_i6], 8U);
  }

  for (c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i7], 9U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_Tl = *c1_b_Tl;
  c1_hl = *c1_b_hl;
  c1_Tr = *c1_b_Tr;
  c1_hr = *c1_b_hr;
  for (c1_i8 = 0; c1_i8 < 3; c1_i8 = c1_i8 + 1) {
    c1_b_engl_ang[c1_i8] = chartInstance->c1_engl_ang[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
    c1_b_engr_ang[c1_i9] = chartInstance->c1_engr_ang[c1_i9];
  }

  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("H", &c1_H, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("TR", &c1_TR, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("TL", &c1_TL, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("T", &c1_T, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("engr_ang", &c1_b_engr_ang, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("engl_ang", &c1_b_engl_ang, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("hr", &c1_hr, c1_sf_marshall);
  sf_debug_symbol_scope_add("Tr", &c1_Tr, c1_sf_marshall);
  sf_debug_symbol_scope_add("hl", &c1_hl, c1_sf_marshall);
  sf_debug_symbol_scope_add("Tl", &c1_Tl, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  Using the engine alignment angles (set in AC_params_T2.m), compute the  */
  /*  off-axis thrust and angular momentum terms. */
  _SFD_EML_CALL(0,8);
  c1_a = c1_Tl;
  c1_b_a = -c1_sind(chartInstance, c1_b_engl_ang[1]);
  c1_b = c1_cosd(chartInstance, c1_b_engl_ang[2]);
  c1_y = c1_b_a * c1_b;
  c1_c_a = c1_cosd(chartInstance, c1_b_engl_ang[1]);
  c1_b_b = c1_cosd(chartInstance, c1_b_engl_ang[2]);
  c1_b_y = c1_c_a * c1_b_b;
  c1_d0 = c1_sind(chartInstance, c1_b_engl_ang[2]);
  c1_c_b[0] = c1_b_y;
  c1_c_b[1] = c1_d0;
  c1_c_b[2] = c1_y;
  for (c1_i10 = 0; c1_i10 < 3; c1_i10 = c1_i10 + 1) {
    c1_TL[c1_i10] = c1_a * c1_c_b[c1_i10];
  }

  _SFD_EML_CALL(0,11);
  c1_d_a = c1_Tr;
  c1_e_a = -c1_sind(chartInstance, c1_b_engr_ang[1]);
  c1_d_b = c1_cosd(chartInstance, c1_b_engr_ang[2]);
  c1_c_y = c1_e_a * c1_d_b;
  c1_f_a = c1_cosd(chartInstance, c1_b_engr_ang[1]);
  c1_e_b = c1_cosd(chartInstance, c1_b_engr_ang[2]);
  c1_d_y = c1_f_a * c1_e_b;
  c1_d1 = c1_sind(chartInstance, c1_b_engr_ang[2]);
  c1_f_b[0] = c1_d_y;
  c1_f_b[1] = c1_d1;
  c1_f_b[2] = c1_c_y;
  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    c1_TR[c1_i11] = c1_d_a * c1_f_b[c1_i11];
  }

  _SFD_EML_CALL(0,14);
  for (c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
    c1_T[c1_i12] = c1_TL[c1_i12] + c1_TR[c1_i12];
  }

  _SFD_EML_CALL(0,16);
  c1_g_a = c1_hr;
  c1_h_a = -c1_sind(chartInstance, c1_b_engr_ang[1]);
  c1_g_b = c1_cosd(chartInstance, c1_b_engr_ang[2]);
  c1_e_y = c1_h_a * c1_g_b;
  c1_i_a = c1_cosd(chartInstance, c1_b_engr_ang[1]);
  c1_h_b = c1_cosd(chartInstance, c1_b_engr_ang[2]);
  c1_f_y = c1_i_a * c1_h_b;
  c1_d2 = c1_sind(chartInstance, c1_b_engr_ang[2]);
  c1_i_b[0] = c1_f_y;
  c1_i_b[1] = c1_d2;
  c1_i_b[2] = c1_e_y;
  for (c1_i13 = 0; c1_i13 < 3; c1_i13 = c1_i13 + 1) {
    c1_g_y[c1_i13] = c1_g_a * c1_i_b[c1_i13];
  }

  c1_j_a = c1_hl;
  c1_k_a = -c1_sind(chartInstance, c1_b_engl_ang[1]);
  c1_j_b = c1_cosd(chartInstance, c1_b_engl_ang[2]);
  c1_h_y = c1_k_a * c1_j_b;
  c1_l_a = c1_cosd(chartInstance, c1_b_engl_ang[1]);
  c1_k_b = c1_cosd(chartInstance, c1_b_engl_ang[2]);
  c1_i_y = c1_l_a * c1_k_b;
  c1_d3 = c1_sind(chartInstance, c1_b_engl_ang[2]);
  c1_l_b[0] = c1_i_y;
  c1_l_b[1] = c1_d3;
  c1_l_b[2] = c1_h_y;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14 = c1_i14 + 1) {
    c1_j_y[c1_i14] = c1_j_a * c1_l_b[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15 = c1_i15 + 1) {
    c1_H[c1_i15] = c1_j_y[c1_i15] + c1_g_y[c1_i15];
  }

  _SFD_EML_CALL(0,-16);
  sf_debug_symbol_scope_pop();
  for (c1_i16 = 0; c1_i16 < 3; c1_i16 = c1_i16 + 1) {
    (*c1_b_T)[c1_i16] = c1_T[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 3; c1_i17 = c1_i17 + 1) {
    (*c1_b_TL)[c1_i17] = c1_TL[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 3; c1_i18 = c1_i18 + 1) {
    (*c1_b_TR)[c1_i18] = c1_TR[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 3; c1_i19 = c1_i19 + 1) {
    (*c1_b_H)[c1_i19] = c1_H[c1_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_engine_T2_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_cosd(SFc1_engine_T2_libInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_n;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_m;
  real_T c1_h_x;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x / 90.0;
  c1_n = c1_e_x;
  c1_f_x = c1_n;
  if (c1_f_x < 0.0) {
    c1_n = muDoubleScalarCeil(c1_f_x - 0.5);
  } else {
    c1_n = muDoubleScalarFloor(c1_f_x + 0.5);
  }

  c1_d_x = c1_d_x - c1_n * 90.0;
  c1_g_x = c1_eml_scalar_mod(chartInstance, c1_n, 4.0);
  c1_m = c1_g_x;
  c1_h_x = c1_m;
  if (c1_h_x < 0.0) {
    c1_m = muDoubleScalarCeil(c1_h_x - 0.5);
  } else {
    c1_m = muDoubleScalarFloor(c1_h_x + 0.5);
  }

  if (c1_m < 2.0) {
    if (c1_m < 1.0) {
      c1_d_x = muDoubleScalarCos(1.7453292519943295E-002 * c1_d_x);
    } else {
      c1_d_x = -muDoubleScalarSin(1.7453292519943295E-002 * c1_d_x);
    }
  } else if (c1_m < 3.0) {
    c1_d_x = -muDoubleScalarCos(1.7453292519943295E-002 * c1_d_x);
  } else {
    c1_d_x = muDoubleScalarSin(1.7453292519943295E-002 * c1_d_x);
  }

  return c1_d_x;
}

static real_T c1_eml_scalar_mod(SFc1_engine_T2_libInstanceStruct *chartInstance,
  real_T c1_x, real_T c1_y)
{
  real_T c1_r;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_c_y;
  real_T c1_l_x;
  real_T c1_m_x;
  if (c1_y == 0.0) {
    c1_b_x = c1_x;
    return c1_b_x;
  } else {
    c1_c_x = c1_y;
    c1_d_x = c1_c_x;
    c1_d_x = muDoubleScalarFloor(c1_d_x);
    if (c1_y == c1_d_x) {
      c1_e_x = c1_x / c1_y;
      c1_f_x = c1_e_x;
      c1_f_x = muDoubleScalarFloor(c1_f_x);
      return c1_x - c1_f_x * c1_y;
    } else {
      c1_r = c1_x / c1_y;
      c1_g_x = c1_r;
      c1_b = muDoubleScalarAbs(c1_g_x);
      c1_b_y = 2.2204460492503131E-016 * c1_b;
      c1_h_x = c1_r;
      c1_i_x = c1_h_x;
      c1_j_x = c1_i_x;
      if (c1_j_x < 0.0) {
        c1_i_x = muDoubleScalarCeil(c1_j_x - 0.5);
      } else {
        c1_i_x = muDoubleScalarFloor(c1_j_x + 0.5);
      }

      c1_k_x = c1_r - c1_i_x;
      c1_c_y = muDoubleScalarAbs(c1_k_x);
      if (c1_c_y <= c1_b_y) {
        return 0.0;
      } else {
        c1_l_x = c1_r;
        c1_m_x = c1_l_x;
        c1_m_x = muDoubleScalarFloor(c1_m_x);
        return (c1_r - c1_m_x) * c1_y;
      }
    }
  }
}

static real_T c1_sind(SFc1_engine_T2_libInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_n;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_m;
  real_T c1_h_x;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x / 90.0;
  c1_n = c1_e_x;
  c1_f_x = c1_n;
  if (c1_f_x < 0.0) {
    c1_n = muDoubleScalarCeil(c1_f_x - 0.5);
  } else {
    c1_n = muDoubleScalarFloor(c1_f_x + 0.5);
  }

  c1_d_x = c1_d_x - c1_n * 90.0;
  c1_g_x = c1_eml_scalar_mod(chartInstance, c1_n, 4.0);
  c1_m = c1_g_x;
  c1_h_x = c1_m;
  if (c1_h_x < 0.0) {
    c1_m = muDoubleScalarCeil(c1_h_x - 0.5);
  } else {
    c1_m = muDoubleScalarFloor(c1_h_x + 0.5);
  }

  if (c1_m < 2.0) {
    if (c1_m < 1.0) {
      c1_d_x = muDoubleScalarSin(1.7453292519943295E-002 * c1_d_x);
    } else {
      c1_d_x = muDoubleScalarCos(1.7453292519943295E-002 * c1_d_x);
    }
  } else if (c1_m < 3.0) {
    c1_d_x = -muDoubleScalarSin(1.7453292519943295E-002 * c1_d_x);
  } else {
    c1_d_x = -muDoubleScalarCos(1.7453292519943295E-002 * c1_d_x);
  }

  return c1_d_x;
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_engine_T2_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_T2_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i20;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_engine_T2_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_T2_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i20 = 0; c1_i20 < 3; c1_i20 = c1_i20 + 1) {
    c1_b_u[c1_i20] = (*((real_T (*)[3])c1_u))[c1_i20];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i21;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_engine_T2_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_T2_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i21 = 0; c1_i21 < 3; c1_i21 = c1_i21 + 1) {
    c1_b_u[c1_i21] = (*((real_T (*)[3])c1_u))[c1_i21];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_engine_T2_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[52];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i22;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52));
  for (c1_i22 = 0; c1_i22 < 52; c1_i22 = c1_i22 + 1) {
    c1_r0 = &c1_info[c1_i22];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i22);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i22
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i22
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[52])
{
  c1_info[0].context = "";
  c1_info[0].name = "cosd";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[0].fileLength = 378U;
  c1_info[0].fileTime1 = 1203473152U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[1].name = "isscalar";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]isscalar";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[2].name = "isvector";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[B]isvector";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c1_info[3].name = "cast";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[3].fileLength = 866U;
  c1_info[3].fileTime1 = 1192491844U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[4].name = "gt";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]gt";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[5].name = "times";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]times";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[6].name = "lt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]lt";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[7].name = "isfloat";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isfloat";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[8].name = "zeros";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]zeros";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[9].name = "eml_index_class";
  c1_info[9].dominantType = "";
  c1_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[9].fileLength = 909U;
  c1_info[9].fileTime1 = 1192491982U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[10].name = "eps";
  c1_info[10].dominantType = "char";
  c1_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[10].fileLength = 1342U;
  c1_info[10].fileTime1 = 1210895846U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[11].name = "not";
  c1_info[11].dominantType = "logical";
  c1_info[11].resolved = "[B]not";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "sind";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c1_info[12].fileLength = 378U;
  c1_info[12].fileTime1 = 1203473244U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[13].name = "ischar";
  c1_info[13].dominantType = "char";
  c1_info[13].resolved = "[B]ischar";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[14].name = "true";
  c1_info[14].dominantType = "";
  c1_info[14].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[14].fileLength = 237U;
  c1_info[14].fileTime1 = 1192491962U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[15].name = "false";
  c1_info[15].dominantType = "";
  c1_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[15].fileLength = 238U;
  c1_info[15].fileTime1 = 1192491920U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[16].name = "isnumeric";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved = "[B]isnumeric";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[17].name = "eml_scalar_floor";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[17].fileLength = 260U;
  c1_info[17].fileTime1 = 1209355990U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[18].name = "eml_scalar_mod";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[18].fileLength = 1087U;
  c1_info[18].fileTime1 = 1213662882U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[19].name = "ne";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]ne";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[20].name = "size";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]size";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[21].name = "int32";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved = "[B]int32";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[22].name = "minus";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]minus";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[23].name = "eml_scalar_abs";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[23].fileLength = 461U;
  c1_info[23].fileTime1 = 1203473160U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[24].name = "isstruct";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[B]isstruct";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[25].name = "pi";
  c1_info[25].dominantType = "";
  c1_info[25].resolved = "[B]pi";
  c1_info[25].fileLength = 0U;
  c1_info[25].fileTime1 = 0U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[26].name = "isinf";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[26].fileLength = 472U;
  c1_info[26].fileTime1 = 1192491934U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[27].name = "mtimes";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[27].fileLength = 2336U;
  c1_info[27].fileTime1 = 1213662890U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[28].name = "isfinite";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[28].fileLength = 341U;
  c1_info[28].fileTime1 = 1192491934U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[29].name = "isnan";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[29].fileLength = 472U;
  c1_info[29].fileTime1 = 1192491936U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[30].name = "double";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[B]double";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[31].name = "logical";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]logical";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[32].name = "eml_is_float_class";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[32].fileLength = 226U;
  c1_info[32].fileTime1 = 1197875642U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c1_info[33].name = "eml_scalar_sind";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c1_info[33].fileLength = 498U;
  c1_info[33].fileTime1 = 1209355992U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[34].name = "eml_scalar_cosd";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[34].fileLength = 497U;
  c1_info[34].fileTime1 = 1209355988U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[35].name = "isinteger";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]isinteger";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[36].name = "eq";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]eq";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[37].name = "and";
  c1_info[37].dominantType = "logical";
  c1_info[37].resolved = "[B]and";
  c1_info[37].fileLength = 0U;
  c1_info[37].fileTime1 = 0U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[38].name = "uminus";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]uminus";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[39].name = "eml_assert_valid_size_arg";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[39].fileLength = 2835U;
  c1_info[39].fileTime1 = 1210895844U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[40].name = "isreal";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[B]isreal";
  c1_info[40].fileLength = 0U;
  c1_info[40].fileTime1 = 0U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[41].name = "nargin";
  c1_info[41].dominantType = "";
  c1_info[41].resolved = "[B]nargin";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c1_info[42].name = "isa";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[B]isa";
  c1_info[42].fileLength = 0U;
  c1_info[42].fileTime1 = 0U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[43].name = "intmax";
  c1_info[43].dominantType = "char";
  c1_info[43].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[43].fileLength = 1535U;
  c1_info[43].fileTime1 = 1192491928U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c1_info[44].name = "eml_alloc";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[44].fileLength = 2627U;
  c1_info[44].fileTime1 = 1213662886U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c1_info[45].name = "plus";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved = "[B]plus";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c1_info[46].name = "eml_scalar_round";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[46].fileLength = 523U;
  c1_info[46].fileTime1 = 1203473208U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[47].name = "le";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]le";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[48].name = "ge";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[B]ge";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[49].name = "strcmp";
  c1_info[49].dominantType = "char";
  c1_info[49].resolved = "[B]strcmp";
  c1_info[49].fileLength = 0U;
  c1_info[49].fileTime1 = 0U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[50].name = "islogical";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved = "[B]islogical";
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
}

static void init_dsm_address_info(SFc1_engine_T2_libInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_engine_T2_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2030712882U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3871199543U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2508920240U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3131655012U);
}

mxArray *sf_c1_engine_T2_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(979475662U);
    pr[1] = (double)(1273935806U);
    pr[2] = (double)(2725494318U);
    pr[3] = (double)(1261522345U);
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
  SFc1_engine_T2_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_T2_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_engine_T2_libMachineNumber_,
           1,
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
          init_script_number_translation(_engine_T2_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_engine_T2_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_engine_T2_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"T",0,c1_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Tl",0,
                              c1_sf_marshall);
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
                                1.0,0,"engl_ang",0,c1_b_sf_marshall);
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
          real_T (*c1_T)[3];
          real_T *c1_Tl;
          real_T *c1_hl;
          real_T *c1_Tr;
          real_T *c1_hr;
          real_T (*c1_TL)[3];
          real_T (*c1_TR)[3];
          real_T (*c1_H)[3];
          c1_T = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Tl = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_Tr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_TL = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_hl = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_hr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_TR = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_H = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_T);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_Tl);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_hl);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Tr);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_hr);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_TL);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_engl_ang);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_engr_ang);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_TR);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_H);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_engine_T2_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c1_engine_T2_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_engine_T2_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*)
    chartInstanceVar);
  initialize_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_engine_T2_lib(void *chartInstanceVar)
{
  enable_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_engine_T2_lib(void *chartInstanceVar)
{
  disable_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_engine_T2_lib(void *chartInstanceVar)
{
  sf_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c1_engine_T2_lib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_engine_T2_lib
    ((SFc1_engine_T2_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c1_engine_T2_lib(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_engine_T2_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_engine_T2_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_engine_T2_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_engine_T2_lib((SFc1_engine_T2_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_engine_T2_lib(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable("engine_T2_lib","claw_main",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("engine_T2_lib","claw_main",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("engine_T2_lib",
      "claw_main",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"engine_T2_lib","claw_main",1,4);
      sf_mark_chart_reusable_outputs(S,"engine_T2_lib","claw_main",1,4);
    }

    sf_set_rtw_dwork_info(S,"engine_T2_lib","claw_main",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3852313416U));
  ssSetChecksum1(S,(2715169969U));
  ssSetChecksum2(S,(11533497U));
  ssSetChecksum3(S,(1618258827U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_engine_T2_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "engine_T2_lib", "claw_main",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_engine_T2_lib(SimStruct *S)
{
  SFc1_engine_T2_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_T2_libInstanceStruct *)malloc(sizeof
    (SFc1_engine_T2_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_engine_T2_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_engine_T2_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_engine_T2_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_engine_T2_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_engine_T2_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_engine_T2_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_engine_T2_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_engine_T2_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_engine_T2_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_engine_T2_lib;
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

void c1_engine_T2_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_engine_T2_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_engine_T2_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_engine_T2_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_engine_T2_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
