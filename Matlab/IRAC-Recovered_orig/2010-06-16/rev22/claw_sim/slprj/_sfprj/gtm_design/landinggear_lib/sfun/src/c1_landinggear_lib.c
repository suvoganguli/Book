/* Include files */

#include "landinggear_lib_sfun.h"
#include "c1_landinggear_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "landinggear_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void initialize_params_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance);
static void enable_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void disable_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void update_debugger_state_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance);
static void set_sim_state_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct *
  chartInstance, const mxArray *c1_st);
static void finalize_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void sf_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void c1_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_eml_error(SFc1_landinggear_libInstanceStruct *chartInstance);
static real_T c1_max(SFc1_landinggear_libInstanceStruct *chartInstance, real_T
                     c1_varargin_1, real_T c1_varargin_2);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[62]);
static void init_dsm_address_info(SFc1_landinggear_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_landinggear_lib = 0U;
}

static void initialize_params_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_d1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'GEAR_SPRING' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_GEAR_SPRING = c1_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'zeta' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_zeta = c1_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_landinggear_lib
  (SFc1_landinggear_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct *
  chartInstance, const mxArray *c1_st)
{
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
}

static void sf_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  uint8_T c1_previousEvent;
  real_T *c1_h;
  real_T *c1_brakec;
  real_T *c1_steerc;
  real_T (*c1_F)[6];
  real_T (*c1_Xeom)[12];
  c1_F = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_h = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_brakec = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_steerc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_Xeom = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 3);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c1_h, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_brakec, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_steerc, 2U);
  for (c1_i0 = 0; c1_i0 < 12; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_Xeom)[c1_i0], 3U);
  }

  for (c1_i1 = 0; c1_i1 < 6; c1_i1 = c1_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_F)[c1_i1], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c1_GEAR_SPRING, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_zeta, 6U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_landinggear_lib(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_landinggear_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_landinggear_lib(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
  real_T c1_h;
  real_T c1_brakec;
  real_T c1_steerc;
  int32_T c1_i2;
  real_T c1_Xeom[12];
  real_T c1_b_GEAR_SPRING;
  real_T c1_b_zeta;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 6.0;
  real_T c1_euler[3];
  real_T c1_pqr[3];
  real_T c1_uvw[3];
  real_T c1_C[3];
  real_T c1_GEAR_DAMPER;
  real_T c1_K[3];
  real_T c1_MAX_BRAKES;
  real_T c1_BRAKE_DAMPER;
  real_T c1_F[6];
  real_T c1_a;
  int32_T c1_i3;
  static real_T c1_dv0[3] = { 1.0, 2.0, 1.0 };

  real_T c1_b;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_x;
  real_T c1_b_b;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_c_b;
  real_T c1_d_a;
  int32_T c1_i4;
  real_T c1_e_a[3];
  int32_T c1_i5;
  real_T c1_d_x[3];
  int32_T c1_i6;
  real_T c1_d_b[3];
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_c_k;
  real_T c1_e_x;
  real_T c1_f_x;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_A[3];
  int32_T c1_i12;
  real_T c1_g_x[3];
  int32_T c1_i13;
  real_T c1_h_x[3];
  int32_T c1_i14;
  real_T c1_i_x[3];
  int32_T c1_i15;
  real_T c1_y[3];
  real_T c1_f_a;
  real_T c1_e_b;
  real_T c1_b_y;
  real_T c1_g_a;
  real_T c1_f_b;
  real_T c1_c_y;
  real_T c1_j_x;
  real_T c1_g_b;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  boolean_T c1_h_b;
  real_T c1_h_a;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_d_y;
  real_T c1_i_b;
  real_T c1_e_y;
  real_T c1_j_b;
  real_T c1_f_y;
  real_T c1_p_x;
  real_T c1_k_b;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  boolean_T c1_l_b;
  real_T c1_i_a;
  real_T c1_j_a;
  real_T c1_k_a;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_g_y;
  real_T c1_m_b;
  real_T c1_h_y;
  real_T c1_n_b;
  real_T c1_i_y;
  real_T c1_dv1[3];
  real_T c1_dv2[3];
  int32_T c1_i16;
  int32_T c1_i17;
  real_T *c1_b_steerc;
  real_T *c1_b_brakec;
  real_T *c1_b_h;
  real_T (*c1_b_F)[6];
  real_T (*c1_b_Xeom)[12];
  c1_b_F = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_h = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_brakec = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_steerc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Xeom = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_h = *c1_b_h;
  c1_brakec = *c1_b_brakec;
  c1_steerc = *c1_b_steerc;
  for (c1_i2 = 0; c1_i2 < 12; c1_i2 = c1_i2 + 1) {
    c1_Xeom[c1_i2] = (*c1_b_Xeom)[c1_i2];
  }

  c1_b_GEAR_SPRING = chartInstance->c1_GEAR_SPRING;
  c1_b_zeta = chartInstance->c1_zeta;
  sf_debug_symbol_scope_push(17U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("euler", &c1_euler, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("pqr", &c1_pqr, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("uvw", &c1_uvw, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("C", &c1_C, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("GEAR_DAMPER", &c1_GEAR_DAMPER, c1_sf_marshall);
  sf_debug_symbol_scope_add("K", &c1_K, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("MAX_BRAKES", &c1_MAX_BRAKES, c1_sf_marshall);
  sf_debug_symbol_scope_add("BRAKE_DAMPER", &c1_BRAKE_DAMPER, c1_sf_marshall);
  sf_debug_symbol_scope_add("F", &c1_F, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("zeta", &c1_b_zeta, c1_sf_marshall);
  sf_debug_symbol_scope_add("GEAR_SPRING", &c1_b_GEAR_SPRING, c1_sf_marshall);
  sf_debug_symbol_scope_add("Xeom", &c1_Xeom, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("steerc", &c1_steerc, c1_sf_marshall);
  sf_debug_symbol_scope_add("brakec", &c1_brakec, c1_sf_marshall);
  sf_debug_symbol_scope_add("h", &c1_h, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c1_BRAKE_DAMPER = 5.0;

  /* lbf sec/ft */
  _SFD_EML_CALL(0,6);
  c1_MAX_BRAKES = 20.0;

  /* lbf */
  _SFD_EML_CALL(0,8);
  c1_a = c1_b_GEAR_SPRING;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    c1_K[c1_i3] = c1_a * c1_dv0[c1_i3];
  }

  /*  lbs*ft/rad; roll, pitch, yaw (Landing Gear Geometry) */
  _SFD_EML_CALL(0,9);
  c1_b = c1_b_zeta;
  c1_b_a = 2.0 * c1_b;
  c1_c_a = c1_b_GEAR_SPRING;
  c1_x = c1_c_a * 50.0;
  c1_b_b = c1_x;
  if (c1_b_b < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_b_x = c1_b_b;
  c1_c_x = c1_b_x;
  c1_c_x = muDoubleScalarSqrt(c1_c_x);
  c1_b_b = c1_c_x;
  c1_GEAR_DAMPER = c1_b_a * c1_b_b;

  /* assume 50 lbs aircraft */
  _SFD_EML_CALL(0,10);
  c1_c_b = c1_b_zeta;
  c1_d_a = 2.0 * c1_c_b;
  for (c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
    c1_e_a[c1_i4] = c1_K[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    c1_d_x[c1_i5] = c1_e_a[c1_i5] * 50.0;
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
    c1_d_b[c1_i6] = c1_d_x[c1_i6];
  }

  for (c1_k = 1.0; c1_k <= 3.0; c1_k = c1_k + 1.0) {
    c1_b_k = c1_k;
    if (c1_d_b[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k",
          c1_b_k), 1, 3, 1, 0) - 1] < 0.0) {
      c1_eml_error(chartInstance);
    }
  }

  for (c1_c_k = 1.0; c1_c_k <= 3.0; c1_c_k = c1_c_k + 1.0) {
    c1_b_k = c1_c_k;
    c1_e_x = c1_d_b[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
      ("k", c1_b_k), 1, 3, 1, 0) - 1];
    c1_f_x = c1_e_x;
    c1_f_x = muDoubleScalarSqrt(c1_f_x);
    c1_d_b[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k",
      c1_b_k), 1, 3, 1, 0) - 1] = c1_f_x;
  }

  for (c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    c1_C[c1_i7] = c1_d_a * c1_d_b[c1_i7];
  }

  /*   assume 50 lbs aircraft */
  _SFD_EML_CALL(0,12);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8 = c1_i8 + 1) {
    c1_uvw[c1_i8] = c1_Xeom[c1_i8];
  }

  _SFD_EML_CALL(0,13);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
    c1_pqr[c1_i9] = c1_Xeom[3 + c1_i9];
  }

  _SFD_EML_CALL(0,14);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10 = c1_i10 + 1) {
    c1_euler[c1_i10] = c1_Xeom[9 + c1_i10];
  }

  /*  Brakes act as damper, with saturation in x, always on in y */
  /*  Z force is spring on relative height, damper on vertical velocity */
  /*  Torques are spring/damper on euler angles, with psi relative to steering reference */
  _SFD_EML_CALL(0,19);
  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    c1_A[c1_i11] = c1_K[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
    c1_g_x[c1_i12] = c1_A[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13 = c1_i13 + 1) {
    c1_h_x[c1_i13] = c1_g_x[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14 = c1_i14 + 1) {
    c1_i_x[c1_i14] = c1_h_x[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15 = c1_i15 + 1) {
    c1_y[c1_i15] = c1_i_x[c1_i15] / 2.0;
  }

  c1_f_a = c1_GEAR_DAMPER;
  c1_e_b = c1_uvw[2];
  c1_b_y = c1_f_a * c1_e_b;
  c1_g_a = c1_b_GEAR_SPRING;
  c1_f_b = c1_h;
  c1_c_y = c1_g_a * c1_f_b;
  c1_j_x = c1_uvw[1];
  c1_g_b = c1_j_x;
  c1_k_x = c1_g_b;
  c1_l_x = c1_k_x;
  c1_m_x = c1_l_x;
  c1_h_b = rtIsNaN(c1_m_x);
  if (c1_h_b) {
    c1_l_x = rtNaN;
  } else if (c1_l_x > 0.0) {
    c1_l_x = 1.0;
  } else if (c1_l_x < 0.0) {
    c1_l_x = -1.0;
  } else {
    c1_l_x = 0.0;
  }

  c1_g_b = c1_l_x;
  c1_h_a = -1.0 * c1_g_b;
  c1_n_x = c1_uvw[1];
  c1_o_x = c1_n_x;
  c1_d_y = muDoubleScalarAbs(c1_o_x);
  c1_i_b = c1_d_y;
  c1_e_y = 5.0 * c1_i_b;
  c1_j_b = c1_max(chartInstance, c1_e_y, 5.0);
  c1_f_y = c1_h_a * c1_j_b;
  c1_p_x = c1_uvw[0];
  c1_k_b = c1_p_x;
  c1_q_x = c1_k_b;
  c1_r_x = c1_q_x;
  c1_s_x = c1_r_x;
  c1_l_b = rtIsNaN(c1_s_x);
  if (c1_l_b) {
    c1_r_x = rtNaN;
  } else if (c1_r_x > 0.0) {
    c1_r_x = 1.0;
  } else if (c1_r_x < 0.0) {
    c1_r_x = -1.0;
  } else {
    c1_r_x = 0.0;
  }

  c1_k_b = c1_r_x;
  c1_i_a = -1.0 * c1_k_b;
  c1_j_a = c1_brakec;
  c1_k_a = c1_j_a * 5.0;
  c1_t_x = c1_uvw[0];
  c1_u_x = c1_t_x;
  c1_g_y = muDoubleScalarAbs(c1_u_x);
  c1_m_b = c1_g_y;
  c1_h_y = c1_k_a * c1_m_b;
  c1_n_b = c1_max(chartInstance, c1_h_y, 5.0);
  c1_i_y = c1_i_a * c1_n_b;
  c1_dv1[0] = 0.0;
  c1_dv1[1] = 0.0;
  c1_dv1[2] = c1_euler[2];
  c1_dv2[0] = 0.0;
  c1_dv2[1] = 0.0;
  c1_dv2[2] = c1_steerc;
  c1_F[0] = c1_i_y;
  c1_F[1] = c1_f_y;
  c1_F[2] = c1_c_y - c1_b_y;
  for (c1_i16 = 0; c1_i16 < 3; c1_i16 = c1_i16 + 1) {
    c1_F[c1_i16 + 3] = ((-c1_K[c1_i16]) * (c1_euler[c1_i16] - c1_dv1[c1_i16]) -
                        c1_C[c1_i16] * c1_pqr[c1_i16]) + c1_y[c1_i16] * c1_dv2[
      c1_i16];
  }

  _SFD_EML_CALL(0,-19);
  sf_debug_symbol_scope_pop();
  for (c1_i17 = 0; c1_i17 < 6; c1_i17 = c1_i17 + 1) {
    (*c1_b_F)[c1_i17] = c1_F[c1_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_eml_error(SFc1_landinggear_libInstanceStruct *chartInstance)
{
  int32_T c1_i18;
  static char_T c1_varargin_1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  int32_T c1_i19;
  static char_T c1_varargin_2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e',
    'r', 'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o',
    'm', 'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r',
    'e', 's', 'u', 'l',
    't', 's', ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',',
    ' ', 'u', 's', 'e',
    ' ', '\'', 's', 'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'x', ')', ')', '\''
    , '.' };

  char_T c1_b_u[77];
  const mxArray *c1_b_y = NULL;
  for (c1_i18 = 0; c1_i18 < 31; c1_i18 = c1_i18 + 1) {
    c1_u[c1_i18] = c1_varargin_1[c1_i18];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c1_i19 = 0; c1_i19 < 77; c1_i19 = c1_i19 + 1) {
    c1_b_u[c1_i19] = c1_varargin_2[c1_i19];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static real_T c1_max(SFc1_landinggear_libInstanceStruct *chartInstance, real_T
                     c1_varargin_1, real_T c1_varargin_2)
{
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_xk;
  real_T c1_yk;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_rx;
  real_T c1_ry;
  real_T c1_d_x;
  boolean_T c1_b;
  real_T c1_extremum;
  c1_x = c1_varargin_1;
  c1_y = c1_varargin_2;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_xk = c1_b_x;
  c1_yk = c1_b_y;
  c1_c_x = c1_xk;
  c1_c_y = c1_yk;
  c1_rx = c1_xk;
  c1_ry = c1_yk;
  if (c1_rx >= c1_ry) {
  } else {
    c1_d_x = c1_ry;
    c1_b = rtIsNaN(c1_d_x);
    if (c1_b) {
    } else {
      c1_extremum = c1_c_y;
      goto label_1;
    }
  }

  c1_extremum = c1_c_x;
 label_1:
  ;
  return c1_extremum;
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *)chartInstanceVoid;
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
  real_T c1_b_u[12];
  const mxArray *c1_b_y = NULL;
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i20 = 0; c1_i20 < 12; c1_i20 = c1_i20 + 1) {
    c1_b_u[c1_i20] = (*((real_T (*)[12])c1_u))[c1_i20];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i21;
  real_T c1_b_u[6];
  const mxArray *c1_b_y = NULL;
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i21 = 0; c1_i21 < 6; c1_i21 = c1_i21 + 1) {
    c1_b_u[c1_i21] = (*((real_T (*)[6])c1_u))[c1_i21];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i22;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i22 = 0; c1_i22 < 3; c1_i22 = c1_i22 + 1) {
    c1_b_u[c1_i22] = (*((real_T (*)[3])c1_u))[c1_i22];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_landinggear_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[62];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i23;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 62));
  for (c1_i23 = 0; c1_i23 < 62; c1_i23 = c1_i23 + 1) {
    c1_r0 = &c1_info[c1_i23];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i23);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i23);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i23
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i23
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[62])
{
  c1_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].name = "strcmp";
  c1_info[0].dominantType = "char";
  c1_info[0].resolved = "[B]strcmp";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[1].name = "isa";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]isa";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c1_info[2].name = "eml_scalar_sign";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c1_info[2].fileLength = 543U;
  c1_info[2].fileTime1 = 1203473212U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[3].name = "eml_scalar_abs";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[3].fileLength = 461U;
  c1_info[3].fileTime1 = 1203473160U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].name = "gt";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]gt";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "size";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]size";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "times";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]times";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "";
  c1_info[7].name = "uminus";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]uminus";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "class";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]class";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[9].name = "eml_error";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[9].fileLength = 315U;
  c1_info[9].fileTime1 = 1213662886U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[10].name = "ge";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]ge";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "";
  c1_info[11].name = "sqrt";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[11].fileLength = 572U;
  c1_info[11].fileTime1 = 1203473246U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].name = "isinteger";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]isinteger";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[13].name = "and";
  c1_info[13].dominantType = "logical";
  c1_info[13].resolved = "[B]and";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[14].name = "double";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]double";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[15].name = "eml_scalexp_size";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c1_info[15].fileLength = 1373U;
  c1_info[15].fileTime1 = 1208205260U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[16].name = "eml_min_or_max";
  c1_info[16].dominantType = "char";
  c1_info[16].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[16].fileLength = 7562U;
  c1_info[16].fileTime1 = 1213662886U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[17].name = "islogical";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[B]islogical";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c1_info[18].name = "minus";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]minus";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[19].name = "true";
  c1_info[19].dominantType = "";
  c1_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[19].fileLength = 237U;
  c1_info[19].fileTime1 = 1192491962U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context = "";
  c1_info[20].name = "mtimes";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[20].fileLength = 2336U;
  c1_info[20].fileTime1 = 1213662890U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[21].name = "eml_warning";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[21].fileLength = 262U;
  c1_info[21].fileTime1 = 1213662888U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[22].name = "not";
  c1_info[22].dominantType = "logical";
  c1_info[22].resolved = "[B]not";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[23].name = "eml_div";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[23].fileLength = 4254U;
  c1_info[23].fileTime1 = 1192491972U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "";
  c1_info[24].name = "mrdivide";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[24].fileLength = 755U;
  c1_info[24].fileTime1 = 1209356082U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c1_info[25].name = "eml_scalexp_compatible";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[25].fileLength = 502U;
  c1_info[25].fileTime1 = 1208205258U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[26].name = "eq";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]eq";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "";
  c1_info[27].name = "max";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[27].fileLength = 308U;
  c1_info[27].fileTime1 = 1192491830U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c1_info[28].name = "cast";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[28].fileLength = 866U;
  c1_info[28].fileTime1 = 1192491844U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[29].name = "eml_alloc";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[29].fileLength = 2627U;
  c1_info[29].fileTime1 = 1213662886U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c1_info[30].name = "plus";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[B]plus";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[31].name = "intmax";
  c1_info[31].dominantType = "char";
  c1_info[31].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[31].fileLength = 1535U;
  c1_info[31].fileTime1 = 1192491928U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "";
  c1_info[32].name = "abs";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[32].fileLength = 538U;
  c1_info[32].fileTime1 = 1203473128U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[33].name = "ne";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]ne";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[34].name = "isempty";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved = "[B]isempty";
  c1_info[34].fileLength = 0U;
  c1_info[34].fileTime1 = 0U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[35].name = "rdivide";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[35].fileLength = 620U;
  c1_info[35].fileTime1 = 1213662890U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[36].name = "eml_index_class";
  c1_info[36].dominantType = "";
  c1_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[36].fileLength = 909U;
  c1_info[36].fileTime1 = 1192491982U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c1_info[37].name = "eml_varargin_to_size";
  c1_info[37].dominantType = "";
  c1_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_varargin_to_size.m";
  c1_info[37].fileLength = 630U;
  c1_info[37].fileTime1 = 1209356044U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[38].name = "le";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]le";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[39].name = "int32";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]int32";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "";
  c1_info[40].name = "sign";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c1_info[40].fileLength = 408U;
  c1_info[40].fileTime1 = 1203473242U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[41].name = "isreal";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[B]isreal";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[42].name = "isnumeric";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[B]isnumeric";
  c1_info[42].fileLength = 0U;
  c1_info[42].fileTime1 = 0U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[43].name = "eml_scalar_sqrt";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[43].fileLength = 664U;
  c1_info[43].fileTime1 = 1209355994U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[44].name = "logical";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved = "[B]logical";
  c1_info[44].fileLength = 0U;
  c1_info[44].fileTime1 = 0U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[45].name = "false";
  c1_info[45].dominantType = "";
  c1_info[45].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[45].fileLength = 238U;
  c1_info[45].fileTime1 = 1192491920U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[46].name = "lt";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved = "[B]lt";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[47].name = "nargout";
  c1_info[47].dominantType = "";
  c1_info[47].resolved = "[B]nargout";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[48].name = "ischar";
  c1_info[48].dominantType = "char";
  c1_info[48].resolved = "[B]ischar";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_varargin_to_size.m";
  c1_info[49].name = "eml_assert_valid_size_arg";
  c1_info[49].dominantType = "";
  c1_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[49].fileLength = 2835U;
  c1_info[49].fileTime1 = 1210895844U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c1_info[50].name = "ones";
  c1_info[50].dominantType = "char";
  c1_info[50].resolved = "[B]ones";
  c1_info[50].fileLength = 0U;
  c1_info[50].fileTime1 = 0U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[51].name = "nan";
  c1_info[51].dominantType = "char";
  c1_info[51].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c1_info[51].fileLength = 474U;
  c1_info[51].fileTime1 = 1192491944U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[52].name = "eml_is_float_class";
  c1_info[52].dominantType = "char";
  c1_info[52].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[52].fileLength = 226U;
  c1_info[52].fileTime1 = 1197875642U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[53].name = "isstruct";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved = "[B]isstruct";
  c1_info[53].fileLength = 0U;
  c1_info[53].fileTime1 = 0U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[54].name = "isscalar";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved = "[B]isscalar";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[55].name = "nargin";
  c1_info[55].dominantType = "";
  c1_info[55].resolved = "[B]nargin";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[56].name = "isfinite";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[56].fileLength = 341U;
  c1_info[56].fileTime1 = 1192491934U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c1_info[57].name = "eml_guarded_nan";
  c1_info[57].dominantType = "char";
  c1_info[57].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[57].fileLength = 485U;
  c1_info[57].fileTime1 = 1192491980U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[58].name = "isvector";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved = "[B]isvector";
  c1_info[58].fileLength = 0U;
  c1_info[58].fileTime1 = 0U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[59].name = "isinf";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[59].fileLength = 472U;
  c1_info[59].fileTime1 = 1192491934U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c1_info[60].name = "zeros";
  c1_info[60].dominantType = "char";
  c1_info[60].resolved = "[B]zeros";
  c1_info[60].fileLength = 0U;
  c1_info[60].fileTime1 = 0U;
  c1_info[60].fileTime2 = 0U;
  c1_info[61].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c1_info[61].name = "isnan";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[61].fileLength = 472U;
  c1_info[61].fileTime1 = 1192491936U;
  c1_info[61].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc1_landinggear_libInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_landinggear_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3502845277U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4272372347U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3555399505U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2493257758U);
}

mxArray *sf_c1_landinggear_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2636266207U);
    pr[1] = (double)(2155714851U);
    pr[2] = (double)(4035120724U);
    pr[3] = (double)(3704945386U);
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
      pr[0] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_landinggear_libMachineNumber_,
           1,
           1,
           1,
           7,
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
          init_script_number_translation(_landinggear_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_landinggear_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_landinggear_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"h",0,
                              c1_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"brakec",
                              0,NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"steerc",
                              0,NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 12;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Xeom",0,c1_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"F",0,c1_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "GEAR_SPRING",0,NULL);
          _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"zeta",0,
                              NULL);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,921);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c1_h;
          real_T *c1_brakec;
          real_T *c1_steerc;
          real_T (*c1_Xeom)[12];
          real_T (*c1_F)[6];
          c1_F = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_h = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_brakec = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_steerc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_Xeom = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 3);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_h);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_brakec);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_steerc);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Xeom);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_F);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_GEAR_SPRING);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_zeta);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_landinggear_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c1_landinggear_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar);
  initialize_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_landinggear_lib(void *chartInstanceVar)
{
  enable_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_landinggear_lib(void *chartInstanceVar)
{
  disable_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_landinggear_lib(void *chartInstanceVar)
{
  sf_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c1_landinggear_lib(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_landinggear_lib
    ((SFc1_landinggear_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c1_landinggear_lib(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_landinggear_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_landinggear_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_landinggear_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_landinggear_lib((SFc1_landinggear_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_landinggear_lib(SimStruct *S)
{
  /* Actual parameters from chart:
     GEAR_SPRING zeta
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for GEAR_SPRING*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for zeta*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("landinggear_lib","gtm_design",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("landinggear_lib","gtm_design",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("landinggear_lib",
      "gtm_design",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"landinggear_lib","gtm_design",1,4);
      sf_mark_chart_reusable_outputs(S,"landinggear_lib","gtm_design",1,1);
    }

    sf_set_rtw_dwork_info(S,"landinggear_lib","gtm_design",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1829771339U));
  ssSetChecksum1(S,(303802767U));
  ssSetChecksum2(S,(2414741345U));
  ssSetChecksum3(S,(526310433U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_landinggear_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "landinggear_lib", "gtm_design",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_landinggear_lib(SimStruct *S)
{
  SFc1_landinggear_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_landinggear_libInstanceStruct *)malloc(sizeof
    (SFc1_landinggear_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_landinggear_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_landinggear_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_landinggear_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_landinggear_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_landinggear_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_landinggear_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_landinggear_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_landinggear_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_landinggear_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_landinggear_lib;
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

void c1_landinggear_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_landinggear_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_landinggear_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_landinggear_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_landinggear_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
