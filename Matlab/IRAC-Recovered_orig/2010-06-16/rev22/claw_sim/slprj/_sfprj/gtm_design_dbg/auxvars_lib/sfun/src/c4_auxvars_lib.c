/* Include files */

#include "auxvars_lib_sfun.h"
#include "c4_auxvars_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "auxvars_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance);
static void initialize_params_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance);
static void enable_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance);
static void disable_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance);
static void update_debugger_state_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c4_auxvars_lib
  (SFc4_auxvars_libInstanceStruct *chartInstance);
static void set_sim_state_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance);
static void sf_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[45]);
static void init_dsm_address_info(SFc4_auxvars_libInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_auxvars_lib = 0U;
}

static void initialize_params_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance)
{
}

static void enable_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *
  chartInstance)
{
}

static const mxArray *get_sim_state_c4_auxvars_lib
  (SFc4_auxvars_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct
  *chartInstance)
{
}

static void sf_c4_auxvars_lib(SFc4_auxvars_libInstanceStruct *chartInstance)
{
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  uint8_T c4_previousEvent;
  int32_T c4_i5;
  real_T c4_omega[3];
  int32_T c4_i6;
  real_T c4_euler[3];
  int32_T c4_i7;
  real_T c4_v[3];
  int32_T c4_i8;
  real_T c4_v_dot[3];
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 4.0;
  real_T c4_theta;
  real_T c4_phi;
  real_T c4_g0;
  real_T c4_n_body[3];
  real_T c4_x;
  real_T c4_a;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_b;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_y;
  real_T c4_g_x;
  real_T c4_b_a;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_b_b;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_b_y;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  int32_T c4_i9;
  real_T c4_c_a[3];
  int32_T c4_i10;
  real_T c4_c_b[3];
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_c_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_d_y;
  real_T c4_c1;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_e_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_f_y;
  real_T c4_c2;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_g_y;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_h_y;
  real_T c4_c3;
  real_T c4_c[3];
  int32_T c4_i11;
  real_T c4_A[3];
  int32_T c4_i12;
  real_T c4_q_x[3];
  int32_T c4_i13;
  real_T c4_r_x[3];
  int32_T c4_i14;
  real_T c4_s_x[3];
  int32_T c4_i15;
  real_T c4_i_y[3];
  real_T c4_t_x[3];
  int32_T c4_i16;
  int32_T c4_i17;
  real_T (*c4_b_n_body)[3];
  real_T (*c4_b_v_dot)[3];
  real_T (*c4_b_v)[3];
  real_T (*c4_b_euler)[3];
  real_T (*c4_b_omega)[3];
  c4_b_n_body = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_v_dot = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_v = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_omega)[c4_i0], 0U);
  }

  for (c4_i1 = 0; c4_i1 < 3; c4_i1 = c4_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_euler)[c4_i1], 1U);
  }

  for (c4_i2 = 0; c4_i2 < 3; c4_i2 = c4_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_v)[c4_i2], 2U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_n_body)[c4_i3], 3U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_v_dot)[c4_i4], 4U);
  }

  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5 = c4_i5 + 1) {
    c4_omega[c4_i5] = (*c4_b_omega)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6 = c4_i6 + 1) {
    c4_euler[c4_i6] = (*c4_b_euler)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7 = c4_i7 + 1) {
    c4_v[c4_i7] = (*c4_b_v)[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8 = c4_i8 + 1) {
    c4_v_dot[c4_i8] = (*c4_b_v_dot)[c4_i8];
  }

  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c4_theta, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("phi", &c4_phi, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("g0", &c4_g0, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("n_body", &c4_n_body, c4_sf_marshall);
  sf_debug_symbol_scope_add("v_dot", &c4_v_dot, c4_sf_marshall);
  sf_debug_symbol_scope_add("v", &c4_v, c4_sf_marshall);
  sf_debug_symbol_scope_add("euler", &c4_euler, c4_sf_marshall);
  sf_debug_symbol_scope_add("omega", &c4_omega, c4_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  Compute body-axis accelerometer measurements.   */
  /*  Inputs: */
  /*        omega: body-axis angular rates, [p q r], in rad/sec */
  /*        euler: Euler angles, [phi theta psi], in rad */
  /*            v: body-axis velocities, [u v w], ft/sec */
  /*        v_dot: body-axis accelerations, [udot vdot wdot], ft/sec^2 */
  /*  */
  /*  Author: Austin Murch (Austin.M.Murch@nasa.gov) */
  /*  Created: 2/19/2008 */
  _SFD_EML_CALL(0,13);
  c4_g0 = 32.174;
  _SFD_EML_CALL(0,14);
  c4_phi = c4_euler[0];
  _SFD_EML_CALL(0,15);
  c4_theta = c4_euler[1];
  _SFD_EML_CALL(0,17);
  c4_x = c4_theta;
  c4_a = c4_x;
  c4_b_x = c4_a;
  c4_c_x = c4_b_x;
  c4_c_x = muDoubleScalarCos(c4_c_x);
  c4_a = c4_c_x;
  c4_d_x = c4_phi;
  c4_b = c4_d_x;
  c4_e_x = c4_b;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarCos(c4_f_x);
  c4_b = c4_f_x;
  c4_y = c4_a * c4_b;
  c4_g_x = c4_theta;
  c4_b_a = c4_g_x;
  c4_h_x = c4_b_a;
  c4_i_x = c4_h_x;
  c4_i_x = muDoubleScalarCos(c4_i_x);
  c4_b_a = c4_i_x;
  c4_j_x = c4_phi;
  c4_b_b = c4_j_x;
  c4_k_x = c4_b_b;
  c4_l_x = c4_k_x;
  c4_l_x = muDoubleScalarSin(c4_l_x);
  c4_b_b = c4_l_x;
  c4_b_y = c4_b_a * c4_b_b;
  c4_m_x = c4_theta;
  c4_n_x = c4_m_x;
  c4_o_x = c4_n_x;
  c4_p_x = c4_o_x;
  c4_p_x = muDoubleScalarSin(c4_p_x);
  c4_n_x = c4_p_x;
  for (c4_i9 = 0; c4_i9 < 3; c4_i9 = c4_i9 + 1) {
    c4_c_a[c4_i9] = c4_omega[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10 = c4_i10 + 1) {
    c4_c_b[c4_i10] = c4_v[c4_i10];
  }

  c4_d_a = c4_c_a[2];
  c4_d_b = c4_c_b[1];
  c4_c_y = c4_d_a * c4_d_b;
  c4_e_a = c4_c_a[1];
  c4_e_b = c4_c_b[2];
  c4_d_y = c4_e_a * c4_e_b;
  c4_c1 = c4_d_y - c4_c_y;
  c4_f_a = c4_c_a[0];
  c4_f_b = c4_c_b[2];
  c4_e_y = c4_f_a * c4_f_b;
  c4_g_a = c4_c_a[2];
  c4_g_b = c4_c_b[0];
  c4_f_y = c4_g_a * c4_g_b;
  c4_c2 = c4_f_y - c4_e_y;
  c4_h_a = c4_c_a[1];
  c4_h_b = c4_c_b[0];
  c4_g_y = c4_h_a * c4_h_b;
  c4_i_a = c4_c_a[0];
  c4_i_b = c4_c_b[1];
  c4_h_y = c4_i_a * c4_i_b;
  c4_c3 = c4_h_y - c4_g_y;
  c4_c[0] = c4_c1;
  c4_c[1] = c4_c2;
  c4_c[2] = c4_c3;
  for (c4_i11 = 0; c4_i11 < 3; c4_i11 = c4_i11 + 1) {
    c4_A[c4_i11] = c4_v_dot[c4_i11] + c4_c[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 3; c4_i12 = c4_i12 + 1) {
    c4_q_x[c4_i12] = c4_A[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13 = c4_i13 + 1) {
    c4_r_x[c4_i13] = c4_q_x[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14 = c4_i14 + 1) {
    c4_s_x[c4_i14] = c4_r_x[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15 = c4_i15 + 1) {
    c4_i_y[c4_i15] = c4_s_x[c4_i15] / 32.174;
  }

  c4_t_x[0] = -c4_n_x;
  c4_t_x[1] = c4_b_y;
  c4_t_x[2] = c4_y;
  for (c4_i16 = 0; c4_i16 < 3; c4_i16 = c4_i16 + 1) {
    c4_n_body[c4_i16] = c4_i_y[c4_i16] - c4_t_x[c4_i16];
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c4_i17 = 0; c4_i17 < 3; c4_i17 = c4_i17 + 1) {
    (*c4_b_n_body)[c4_i17] = c4_n_body[c4_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_auxvars_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i18;
  real_T c4_b_u[3];
  const mxArray *c4_b_y = NULL;
  SFc4_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc4_auxvars_libInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  for (c4_i18 = 0; c4_i18 < 3; c4_i18 = c4_i18 + 1) {
    c4_b_u[c4_i18] = (*((real_T (*)[3])c4_u))[c4_i18];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc4_auxvars_libInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_auxvars_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[45];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i19;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 45));
  for (c4_i19 = 0; c4_i19 < 45; c4_i19 = c4_i19 + 1) {
    c4_r0 = &c4_info[c4_i19];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i19
                    );
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i19
                    );
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[45])
{
  c4_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c4_info[0].name = "not";
  c4_info[0].dominantType = "logical";
  c4_info[0].resolved = "[B]not";
  c4_info[0].fileLength = 0U;
  c4_info[0].fileTime1 = 0U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[1].name = "eq";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved = "[B]eq";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context = "";
  c4_info[2].name = "sin";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[2].fileLength = 324U;
  c4_info[2].fileTime1 = 1203473242U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[3].name = "ge";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved = "[B]ge";
  c4_info[3].fileLength = 0U;
  c4_info[3].fileTime1 = 0U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[4].name = "eml_nonsingleton_dim";
  c4_info[4].dominantType = "logical";
  c4_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c4_info[4].fileLength = 404U;
  c4_info[4].fileTime1 = 1192492000U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[5].name = "false";
  c4_info[5].dominantType = "";
  c4_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[5].fileLength = 238U;
  c4_info[5].fileTime1 = 1192491920U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[6].name = "isequal";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[6].fileLength = 157U;
  c4_info[6].fileTime1 = 1210895846U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[7].name = "eml_scalar_sin";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c4_info[7].fileLength = 601U;
  c4_info[7].fileTime1 = 1209355992U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[8].name = "rdivide";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[8].fileLength = 620U;
  c4_info[8].fileTime1 = 1213662890U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c4_info[9].name = "le";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[B]le";
  c4_info[9].fileLength = 0U;
  c4_info[9].fileTime1 = 0U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[10].name = "eml_isequal_core";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[10].fileLength = 3543U;
  c4_info[10].fileTime1 = 1213662886U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[11].name = "strcmp";
  c4_info[11].dominantType = "char";
  c4_info[11].resolved = "[B]strcmp";
  c4_info[11].fileLength = 0U;
  c4_info[11].fileTime1 = 0U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context = "";
  c4_info[12].name = "plus";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[B]plus";
  c4_info[12].fileLength = 0U;
  c4_info[12].fileTime1 = 0U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[13].name = "assert";
  c4_info[13].dominantType = "char";
  c4_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c4_info[13].fileLength = 2684U;
  c4_info[13].fileTime1 = 1210895856U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c4_info[14].name = "ne";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved = "[B]ne";
  c4_info[14].fileLength = 0U;
  c4_info[14].fileTime1 = 0U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[15].name = "isscalar";
  c4_info[15].dominantType = "logical";
  c4_info[15].resolved = "[B]isscalar";
  c4_info[15].fileLength = 0U;
  c4_info[15].fileTime1 = 0U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context = "";
  c4_info[16].name = "mrdivide";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[16].fileLength = 755U;
  c4_info[16].fileTime1 = 1209356082U;
  c4_info[16].fileTime2 = 0U;
  c4_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[17].name = "true";
  c4_info[17].dominantType = "";
  c4_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c4_info[17].fileLength = 237U;
  c4_info[17].fileTime1 = 1192491962U;
  c4_info[17].fileTime2 = 0U;
  c4_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/isequal_scalar";
  c4_info[18].name = "isnan";
  c4_info[18].dominantType = "double";
  c4_info[18].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[18].fileLength = 472U;
  c4_info[18].fileTime1 = 1192491936U;
  c4_info[18].fileTime2 = 0U;
  c4_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[19].name = "eml_all_or_any";
  c4_info[19].dominantType = "char";
  c4_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[19].fileLength = 3423U;
  c4_info[19].fileTime1 = 1213662886U;
  c4_info[19].fileTime2 = 0U;
  c4_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[20].name = "lt";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved = "[B]lt";
  c4_info[20].fileLength = 0U;
  c4_info[20].fileTime1 = 0U;
  c4_info[20].fileTime2 = 0U;
  c4_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c4_info[21].name = "ndims";
  c4_info[21].dominantType = "double";
  c4_info[21].resolved = "[B]ndims";
  c4_info[21].fileLength = 0U;
  c4_info[21].fileTime1 = 0U;
  c4_info[21].fileTime2 = 0U;
  c4_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[22].name = "logical";
  c4_info[22].dominantType = "double";
  c4_info[22].resolved = "[B]logical";
  c4_info[22].fileLength = 0U;
  c4_info[22].fileTime1 = 0U;
  c4_info[22].fileTime2 = 0U;
  c4_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[23].name = "mtimes";
  c4_info[23].dominantType = "double";
  c4_info[23].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[23].fileLength = 2336U;
  c4_info[23].fileTime1 = 1213662890U;
  c4_info[23].fileTime2 = 0U;
  c4_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[24].name = "isa";
  c4_info[24].dominantType = "double";
  c4_info[24].resolved = "[B]isa";
  c4_info[24].fileLength = 0U;
  c4_info[24].fileTime1 = 0U;
  c4_info[24].fileTime2 = 0U;
  c4_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[25].name = "isreal";
  c4_info[25].dominantType = "double";
  c4_info[25].resolved = "[B]isreal";
  c4_info[25].fileLength = 0U;
  c4_info[25].fileTime1 = 0U;
  c4_info[25].fileTime2 = 0U;
  c4_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[26].name = "nargin";
  c4_info[26].dominantType = "";
  c4_info[26].resolved = "[B]nargin";
  c4_info[26].fileLength = 0U;
  c4_info[26].fileTime1 = 0U;
  c4_info[26].fileTime2 = 0U;
  c4_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[27].name = "minus";
  c4_info[27].dominantType = "double";
  c4_info[27].resolved = "[B]minus";
  c4_info[27].fileLength = 0U;
  c4_info[27].fileTime1 = 0U;
  c4_info[27].fileTime2 = 0U;
  c4_info[28].context = "";
  c4_info[28].name = "cos";
  c4_info[28].dominantType = "double";
  c4_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[28].fileLength = 324U;
  c4_info[28].fileTime1 = 1203473152U;
  c4_info[28].fileTime2 = 0U;
  c4_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[29].name = "eml_warning";
  c4_info[29].dominantType = "char";
  c4_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c4_info[29].fileLength = 262U;
  c4_info[29].fileTime1 = 1213662888U;
  c4_info[29].fileTime2 = 0U;
  c4_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[30].name = "eml_scalar_cos";
  c4_info[30].dominantType = "double";
  c4_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c4_info[30].fileLength = 602U;
  c4_info[30].fileTime1 = 1209355988U;
  c4_info[30].fileTime2 = 0U;
  c4_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[31].name = "ischar";
  c4_info[31].dominantType = "logical";
  c4_info[31].resolved = "[B]ischar";
  c4_info[31].fileLength = 0U;
  c4_info[31].fileTime1 = 0U;
  c4_info[31].fileTime2 = 0U;
  c4_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[32].name = "eml_set_singleton_dim";
  c4_info[32].dominantType = "double";
  c4_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c4_info[32].fileLength = 398U;
  c4_info[32].fileTime1 = 1209356038U;
  c4_info[32].fileTime2 = 0U;
  c4_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c4_info[33].name = "all";
  c4_info[33].dominantType = "logical";
  c4_info[33].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[33].fileLength = 400U;
  c4_info[33].fileTime1 = 1192492104U;
  c4_info[33].fileTime2 = 0U;
  c4_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[34].name = "isvector";
  c4_info[34].dominantType = "double";
  c4_info[34].resolved = "[B]isvector";
  c4_info[34].fileLength = 0U;
  c4_info[34].fileTime1 = 0U;
  c4_info[34].fileTime2 = 0U;
  c4_info[35].context = "";
  c4_info[35].name = "cross";
  c4_info[35].dominantType = "double";
  c4_info[35].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[35].fileLength = 2985U;
  c4_info[35].fileTime1 = 1213662890U;
  c4_info[35].fileTime2 = 0U;
  c4_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[36].name = "class";
  c4_info[36].dominantType = "double";
  c4_info[36].resolved = "[B]class";
  c4_info[36].fileLength = 0U;
  c4_info[36].fileTime1 = 0U;
  c4_info[36].fileTime2 = 0U;
  c4_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[37].name = "eml_div";
  c4_info[37].dominantType = "double";
  c4_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[37].fileLength = 4254U;
  c4_info[37].fileTime1 = 1192491972U;
  c4_info[37].fileTime2 = 0U;
  c4_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[38].name = "isinteger";
  c4_info[38].dominantType = "double";
  c4_info[38].resolved = "[B]isinteger";
  c4_info[38].fileLength = 0U;
  c4_info[38].fileTime1 = 0U;
  c4_info[38].fileTime2 = 0U;
  c4_info[39].context = "";
  c4_info[39].name = "uminus";
  c4_info[39].dominantType = "double";
  c4_info[39].resolved = "[B]uminus";
  c4_info[39].fileLength = 0U;
  c4_info[39].fileTime1 = 0U;
  c4_info[39].fileTime2 = 0U;
  c4_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[40].name = "gt";
  c4_info[40].dominantType = "double";
  c4_info[40].resolved = "[B]gt";
  c4_info[40].fileLength = 0U;
  c4_info[40].fileTime1 = 0U;
  c4_info[40].fileTime2 = 0U;
  c4_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c4_info[41].name = "isstruct";
  c4_info[41].dominantType = "double";
  c4_info[41].resolved = "[B]isstruct";
  c4_info[41].fileLength = 0U;
  c4_info[41].fileTime1 = 0U;
  c4_info[41].fileTime2 = 0U;
  c4_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[42].name = "isempty";
  c4_info[42].dominantType = "logical";
  c4_info[42].resolved = "[B]isempty";
  c4_info[42].fileLength = 0U;
  c4_info[42].fileTime1 = 0U;
  c4_info[42].fileTime2 = 0U;
  c4_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[43].name = "islogical";
  c4_info[43].dominantType = "logical";
  c4_info[43].resolved = "[B]islogical";
  c4_info[43].fileLength = 0U;
  c4_info[43].fileTime1 = 0U;
  c4_info[43].fileTime2 = 0U;
  c4_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[44].name = "size";
  c4_info[44].dominantType = "double";
  c4_info[44].resolved = "[B]size";
  c4_info[44].fileLength = 0U;
  c4_info[44].fileTime1 = 0U;
  c4_info[44].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc4_auxvars_libInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_auxvars_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(881803549U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3064173500U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(906170592U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2832008341U);
}

mxArray *sf_c4_auxvars_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4077168527U);
    pr[1] = (double)(2956225626U);
    pr[2] = (double)(2841740677U);
    pr[3] = (double)(2396244491U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc4_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc4_auxvars_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_auxvars_libMachineNumber_,
           4,
           1,
           1,
           5,
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
          init_script_number_translation(_auxvars_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_auxvars_libMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_auxvars_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"omega",0,c4_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"euler",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"n_body",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"v_dot",0,NULL);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,562);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c4_omega)[3];
          real_T (*c4_euler)[3];
          real_T (*c4_v)[3];
          real_T (*c4_n_body)[3];
          real_T (*c4_v_dot)[3];
          c4_n_body = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_omega = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c4_v_dot = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c4_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c4_v = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_omega);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_euler);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_v);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_n_body);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_v_dot);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_auxvars_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c4_auxvars_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_auxvars_libInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*)
    chartInstanceVar);
  initialize_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_auxvars_lib(void *chartInstanceVar)
{
  enable_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_auxvars_lib(void *chartInstanceVar)
{
  disable_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_auxvars_lib(void *chartInstanceVar)
{
  sf_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c4_auxvars_lib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_auxvars_lib
    ((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c4_auxvars_lib(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_auxvars_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_auxvars_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_auxvars_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_auxvars_lib((SFc4_auxvars_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_auxvars_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("auxvars_lib","gtm_design_dbg",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("auxvars_lib","gtm_design_dbg",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("auxvars_lib",
      "gtm_design_dbg",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"auxvars_lib","gtm_design_dbg",4,4);
      sf_mark_chart_reusable_outputs(S,"auxvars_lib","gtm_design_dbg",4,1);
    }

    sf_set_rtw_dwork_info(S,"auxvars_lib","gtm_design_dbg",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1896463673U));
  ssSetChecksum1(S,(1464648390U));
  ssSetChecksum2(S,(611949051U));
  ssSetChecksum3(S,(1095153445U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_auxvars_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "auxvars_lib", "gtm_design_dbg",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_auxvars_lib(SimStruct *S)
{
  SFc4_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc4_auxvars_libInstanceStruct *)malloc(sizeof
    (SFc4_auxvars_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_auxvars_lib;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_auxvars_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_auxvars_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_auxvars_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_auxvars_lib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_auxvars_lib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_auxvars_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_auxvars_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_auxvars_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_auxvars_lib;
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

void c4_auxvars_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_auxvars_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_auxvars_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_auxvars_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_auxvars_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
