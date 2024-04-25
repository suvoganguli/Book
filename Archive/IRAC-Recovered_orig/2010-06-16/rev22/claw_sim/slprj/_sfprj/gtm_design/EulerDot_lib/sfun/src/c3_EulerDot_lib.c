/* Include files */

#include "EulerDot_lib_sfun.h"
#include "c3_EulerDot_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EulerDot_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance);
static void initialize_params_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance);
static void enable_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance);
static void disable_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance);
static void update_debugger_state_c3_EulerDot_lib
  (SFc3_EulerDot_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_EulerDot_lib
  (SFc3_EulerDot_libInstanceStruct *chartInstance);
static void set_sim_state_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance);
static void sf_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static void c3_eml_warning(SFc3_EulerDot_libInstanceStruct *chartInstance);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[24]);
static void init_dsm_address_info(SFc3_EulerDot_libInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_EulerDot_lib = 0U;
}

static void initialize_params_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance)
{
}

static void enable_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c3_EulerDot_lib
  (SFc3_EulerDot_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_EulerDot_lib
  (SFc3_EulerDot_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct
  *chartInstance)
{
}

static void sf_c3_EulerDot_lib(SFc3_EulerDot_libInstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  uint8_T c3_previousEvent;
  int32_T c3_i3;
  real_T c3_pqr[3];
  int32_T c3_i4;
  real_T c3_euler[3];
  real_T c3_nargout = 1.0;
  real_T c3_nargin = 2.0;
  real_T c3_psi_dot;
  real_T c3_theta_dot;
  real_T c3_phi_dot;
  real_T c3_s_theta;
  real_T c3_c_theta;
  real_T c3_s_phi;
  real_T c3_c_phi;
  real_T c3_psi;
  real_T c3_theta;
  real_T c3_phi;
  real_T c3_R;
  real_T c3_Q;
  real_T c3_P;
  real_T c3_deuler[3];
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_B;
  real_T c3_y;
  real_T c3_b_y;
  real_T c3_c_y;
  real_T c3_a;
  real_T c3_b_a;
  real_T c3_b;
  real_T c3_c_a;
  real_T c3_b_b;
  real_T c3_d_y;
  real_T c3_d_a;
  real_T c3_c_b;
  real_T c3_e_a;
  real_T c3_d_b;
  real_T c3_e_y;
  real_T c3_e_b;
  real_T c3_f_y;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_g_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_h_y;
  real_T c3_b_B;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_k_y;
  real_T c3_h_a;
  real_T c3_i_a;
  real_T c3_h_b;
  real_T c3_l_y;
  real_T c3_j_a;
  real_T c3_i_b;
  real_T c3_m_y;
  real_T c3_j_b;
  int32_T c3_i5;
  real_T (*c3_b_deuler)[3];
  real_T (*c3_b_euler)[3];
  real_T (*c3_b_pqr)[3];
  c3_b_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_deuler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0 = c3_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_pqr)[c3_i0], 0U);
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1 = c3_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_deuler)[c3_i1], 1U);
  }

  for (c3_i2 = 0; c3_i2 < 3; c3_i2 = c3_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_euler)[c3_i2], 2U);
  }

  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3 = c3_i3 + 1) {
    c3_pqr[c3_i3] = (*c3_b_pqr)[c3_i3];
  }

  for (c3_i4 = 0; c3_i4 < 3; c3_i4 = c3_i4 + 1) {
    c3_euler[c3_i4] = (*c3_b_euler)[c3_i4];
  }

  sf_debug_symbol_scope_push(18U, 0U);
  sf_debug_symbol_scope_add("nargout", &c3_nargout, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c3_nargin, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("psi_dot", &c3_psi_dot, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("theta_dot", &c3_theta_dot, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("phi_dot", &c3_phi_dot, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("s_theta", &c3_s_theta, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("c_theta", &c3_c_theta, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("s_phi", &c3_s_phi, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("c_phi", &c3_c_phi, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("psi", &c3_psi, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c3_theta, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("phi", &c3_phi, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("R", &c3_R, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("Q", &c3_Q, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("P", &c3_P, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("deuler", &c3_deuler, c3_sf_marshall);
  sf_debug_symbol_scope_add("euler", &c3_euler, c3_sf_marshall);
  sf_debug_symbol_scope_add("pqr", &c3_pqr, c3_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c3_P = c3_pqr[0];
  _SFD_EML_CALL(0,6);
  c3_Q = c3_pqr[1];
  _SFD_EML_CALL(0,7);
  c3_R = c3_pqr[2];
  _SFD_EML_CALL(0,9);
  c3_phi = c3_euler[0];
  _SFD_EML_CALL(0,10);
  c3_theta = c3_euler[1];
  _SFD_EML_CALL(0,11);
  c3_psi = c3_euler[2];
  _SFD_EML_CALL(0,13);
  c3_x = c3_phi;
  c3_c_phi = c3_x;
  c3_b_x = c3_c_phi;
  c3_c_x = c3_b_x;
  c3_c_x = muDoubleScalarCos(c3_c_x);
  c3_c_phi = c3_c_x;
  _SFD_EML_CALL(0,14);
  c3_d_x = c3_phi;
  c3_s_phi = c3_d_x;
  c3_e_x = c3_s_phi;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_s_phi = c3_f_x;
  _SFD_EML_CALL(0,15);
  c3_g_x = c3_theta;
  c3_c_theta = c3_g_x;
  c3_h_x = c3_c_theta;
  c3_i_x = c3_h_x;
  c3_i_x = muDoubleScalarCos(c3_i_x);
  c3_c_theta = c3_i_x;
  _SFD_EML_CALL(0,16);
  c3_j_x = c3_theta;
  c3_s_theta = c3_j_x;
  c3_k_x = c3_s_theta;
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarSin(c3_l_x);
  c3_s_theta = c3_l_x;
  _SFD_EML_CALL(0,18);
  c3_B = c3_c_theta;
  c3_y = c3_B;
  if (c3_y == 0.0) {
    c3_eml_warning(chartInstance);
  }

  c3_b_y = c3_y;
  c3_c_y = c3_b_y;
  c3_a = 1.0 / c3_c_y;
  c3_b_a = c3_c_phi;
  c3_b = c3_s_theta;
  c3_c_a = c3_b_a * c3_b;
  c3_b_b = c3_R;
  c3_d_y = c3_c_a * c3_b_b;
  c3_d_a = c3_s_phi;
  c3_c_b = c3_s_theta;
  c3_e_a = c3_d_a * c3_c_b;
  c3_d_b = c3_Q;
  c3_e_y = c3_e_a * c3_d_b;
  c3_e_b = c3_e_y + c3_d_y;
  c3_f_y = c3_a * c3_e_b;
  c3_phi_dot = c3_P + c3_f_y;
  _SFD_EML_CALL(0,19);
  c3_f_a = c3_s_phi;
  c3_f_b = c3_R;
  c3_g_y = c3_f_a * c3_f_b;
  c3_g_a = c3_c_phi;
  c3_g_b = c3_Q;
  c3_h_y = c3_g_a * c3_g_b;
  c3_theta_dot = c3_h_y - c3_g_y;
  _SFD_EML_CALL(0,20);
  c3_b_B = c3_c_theta;
  c3_i_y = c3_b_B;
  if (c3_i_y == 0.0) {
    c3_eml_warning(chartInstance);
  }

  c3_j_y = c3_i_y;
  c3_k_y = c3_j_y;
  c3_h_a = 1.0 / c3_k_y;
  c3_i_a = c3_c_phi;
  c3_h_b = c3_R;
  c3_l_y = c3_i_a * c3_h_b;
  c3_j_a = c3_s_phi;
  c3_i_b = c3_Q;
  c3_m_y = c3_j_a * c3_i_b;
  c3_j_b = c3_m_y + c3_l_y;
  c3_psi_dot = c3_h_a * c3_j_b;
  _SFD_EML_CALL(0,22);
  c3_deuler[0] = c3_phi_dot;
  c3_deuler[1] = c3_theta_dot;
  c3_deuler[2] = c3_psi_dot;
  _SFD_EML_CALL(0,-22);
  sf_debug_symbol_scope_pop();
  for (c3_i5 = 0; c3_i5 < 3; c3_i5 = c3_i5 + 1) {
    (*c3_b_deuler)[c3_i5] = c3_deuler[c3_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_EulerDot_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static void c3_eml_warning(SFc3_EulerDot_libInstanceStruct *chartInstance)
{
  int32_T c3_i6;
  static char_T c3_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c3_u[19];
  const mxArray *c3_y = NULL;
  int32_T c3_i7;
  static char_T c3_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c3_b_u[15];
  const mxArray *c3_b_y = NULL;
  for (c3_i6 = 0; c3_i6 < 19; c3_i6 = c3_i6 + 1) {
    c3_u[c3_i6] = c3_varargin_1[c3_i6];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c3_i7 = 0; c3_i7 < 15; c3_i7 = c3_i7 + 1) {
    c3_b_u[c3_i7] = c3_varargin_2[c3_i7];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c3_y, 14, c3_b_y);
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i8;
  real_T c3_b_u[3];
  const mxArray *c3_b_y = NULL;
  SFc3_EulerDot_libInstanceStruct *chartInstance;
  chartInstance = (SFc3_EulerDot_libInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i8 = 0; c3_i8 < 3; c3_i8 = c3_i8 + 1) {
    c3_b_u[c3_i8] = (*((real_T (*)[3])c3_u))[c3_i8];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_EulerDot_libInstanceStruct *chartInstance;
  chartInstance = (SFc3_EulerDot_libInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_EulerDot_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[24];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i9;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24));
  for (c3_i9 = 0; c3_i9 < 24; c3_i9 = c3_i9 + 1) {
    c3_r0 = &c3_info[c3_i9];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i9);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i9);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[24])
{
  c3_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[0].name = "gt";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[B]gt";
  c3_info[0].fileLength = 0U;
  c3_info[0].fileTime1 = 0U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[1].name = "isinteger";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved = "[B]isinteger";
  c3_info[1].fileLength = 0U;
  c3_info[1].fileTime1 = 0U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].name = "isempty";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[B]isempty";
  c3_info[2].fileLength = 0U;
  c3_info[2].fileTime1 = 0U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_div";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[3].fileLength = 4254U;
  c3_info[3].fileTime1 = 1192491972U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[4].name = "nargin";
  c3_info[4].dominantType = "";
  c3_info[4].resolved = "[B]nargin";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "cos";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[5].fileLength = 324U;
  c3_info[5].fileTime1 = 1203473152U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "";
  c3_info[6].name = "sin";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[6].fileLength = 324U;
  c3_info[6].fileTime1 = 1203473242U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[7].name = "isreal";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[B]isreal";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[8].name = "ge";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[B]ge";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[9].name = "eml_scalar_cos";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[9].fileLength = 602U;
  c3_info[9].fileTime1 = 1209355988U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[10].name = "eml_warning";
  c3_info[10].dominantType = "char";
  c3_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[10].fileLength = 262U;
  c3_info[10].fileTime1 = 1213662888U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[11].name = "strcmp";
  c3_info[11].dominantType = "char";
  c3_info[11].resolved = "[B]strcmp";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[12].name = "not";
  c3_info[12].dominantType = "logical";
  c3_info[12].resolved = "[B]not";
  c3_info[12].fileLength = 0U;
  c3_info[12].fileTime1 = 0U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[13].name = "rdivide";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[13].fileLength = 620U;
  c3_info[13].fileTime1 = 1213662890U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[14].name = "eml_scalar_sin";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[14].fileLength = 601U;
  c3_info[14].fileTime1 = 1209355992U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[15].name = "eq";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved = "[B]eq";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context = "";
  c3_info[16].name = "mtimes";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[16].fileLength = 2336U;
  c3_info[16].fileTime1 = 1213662890U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[17].name = "size";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved = "[B]size";
  c3_info[17].fileLength = 0U;
  c3_info[17].fileTime1 = 0U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[18].name = "isscalar";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved = "[B]isscalar";
  c3_info[18].fileLength = 0U;
  c3_info[18].fileTime1 = 0U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[19].name = "isa";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[B]isa";
  c3_info[19].fileLength = 0U;
  c3_info[19].fileTime1 = 0U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context = "";
  c3_info[20].name = "mrdivide";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[20].fileLength = 755U;
  c3_info[20].fileTime1 = 1209356082U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[21].name = "class";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[B]class";
  c3_info[21].fileLength = 0U;
  c3_info[21].fileTime1 = 0U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context = "";
  c3_info[22].name = "minus";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved = "[B]minus";
  c3_info[22].fileLength = 0U;
  c3_info[22].fileTime1 = 0U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context = "";
  c3_info[23].name = "plus";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved = "[B]plus";
  c3_info[23].fileLength = 0U;
  c3_info[23].fileTime1 = 0U;
  c3_info[23].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc3_EulerDot_libInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_EulerDot_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1952663009U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3926792786U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3909933067U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(643500684U);
}

mxArray *sf_c3_EulerDot_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1538448789U);
    pr[1] = (double)(3990296041U);
    pr[2] = (double)(2125000848U);
    pr[3] = (double)(2014374977U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
  SFc3_EulerDot_libInstanceStruct *chartInstance;
  chartInstance = (SFc3_EulerDot_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EulerDot_libMachineNumber_,
           3,
           1,
           1,
           3,
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
          init_script_number_translation(_EulerDot_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_EulerDot_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EulerDot_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pqr",0,c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"deuler",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"euler",0,NULL);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,465);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c3_pqr)[3];
          real_T (*c3_deuler)[3];
          real_T (*c3_euler)[3];
          c3_euler = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_deuler = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_pqr);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_deuler);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_euler);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_EulerDot_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c3_EulerDot_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_EulerDot_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*)
    chartInstanceVar);
  initialize_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_EulerDot_lib(void *chartInstanceVar)
{
  enable_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_EulerDot_lib(void *chartInstanceVar)
{
  disable_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_EulerDot_lib(void *chartInstanceVar)
{
  sf_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c3_EulerDot_lib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c3_EulerDot_lib
    ((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c3_EulerDot_lib(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c3_EulerDot_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_EulerDot_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_EulerDot_lib((SFc3_EulerDot_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_EulerDot_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("EulerDot_lib","gtm_design",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("EulerDot_lib","gtm_design",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("EulerDot_lib",
      "gtm_design",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EulerDot_lib","gtm_design",3,2);
      sf_mark_chart_reusable_outputs(S,"EulerDot_lib","gtm_design",3,1);
    }

    sf_set_rtw_dwork_info(S,"EulerDot_lib","gtm_design",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4089536476U));
  ssSetChecksum1(S,(2878429145U));
  ssSetChecksum2(S,(3472532776U));
  ssSetChecksum3(S,(2519793921U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_EulerDot_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EulerDot_lib", "gtm_design",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_EulerDot_lib(SimStruct *S)
{
  SFc3_EulerDot_libInstanceStruct *chartInstance;
  chartInstance = (SFc3_EulerDot_libInstanceStruct *)malloc(sizeof
    (SFc3_EulerDot_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_EulerDot_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_EulerDot_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_EulerDot_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_EulerDot_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_EulerDot_lib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_EulerDot_lib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_EulerDot_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_EulerDot_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_EulerDot_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_EulerDot_lib;
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

void c3_EulerDot_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_EulerDot_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_EulerDot_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_EulerDot_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_EulerDot_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
