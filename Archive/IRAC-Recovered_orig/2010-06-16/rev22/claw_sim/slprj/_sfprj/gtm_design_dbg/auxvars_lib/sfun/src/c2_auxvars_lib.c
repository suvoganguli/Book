/* Include files */

#include "auxvars_lib_sfun.h"
#include "c2_auxvars_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "auxvars_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance);
static void initialize_params_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance);
static void enable_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance);
static void disable_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance);
static void update_debugger_state_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c2_auxvars_lib
  (SFc2_auxvars_libInstanceStruct *chartInstance);
static void set_sim_state_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance);
static void sf_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance);
static void c2_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_warning(SFc2_auxvars_libInstanceStruct *chartInstance);
static void c2_eml_error(SFc2_auxvars_libInstanceStruct *chartInstance);
static void c2_b_eml_error(SFc2_auxvars_libInstanceStruct *chartInstance);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[54]);
static void init_dsm_address_info(SFc2_auxvars_libInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_auxvars_lib = 0U;
}

static void initialize_params_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance)
{
}

static void enable_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *
  chartInstance)
{
}

static const mxArray *get_sim_state_c2_auxvars_lib
  (SFc2_auxvars_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct
  *chartInstance)
{
}

static void sf_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  uint8_T c2_previousEvent;
  real_T *c2_z;
  real_T *c2_dt;
  real_T (*c2_y)[6];
  c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_z, 0U);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_y)[c2_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_dt, 2U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_auxvars_lib(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_auxvars_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_c2_auxvars_lib(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  real_T c2_z;
  real_T c2_dt;
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 2.0;
  real_T c2_c1;
  real_T c2_rho1;
  real_T c2_p1;
  real_T c2_del1;
  real_T c2_t1;
  real_T c2_a1;
  real_T c2_h;
  real_T c2_conlapse;
  real_T c2_rm2ft;
  real_T c2_slpr;
  real_T c2_sldens;
  real_T c2_hsl;
  real_T c2_psl;
  real_T c2_tsl;
  real_T c2_re;
  real_T c2_g;
  real_T c2_gamma;
  real_T c2_r;
  real_T c2_y[6];
  int32_T c2_i1;
  real_T c2_b;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_b_y;
  real_T c2_b_x;
  real_T c2_c_y;
  real_T c2_c_x;
  real_T c2_d_y;
  real_T c2_b_b;
  real_T c2_e_y;
  real_T c2_b_A;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_ak;
  real_T c2_c_a;
  real_T c2_c_A;
  real_T c2_c_b;
  real_T c2_b_B;
  real_T c2_g_x;
  real_T c2_f_y;
  real_T c2_h_x;
  real_T c2_g_y;
  real_T c2_i_x;
  real_T c2_h_y;
  real_T c2_d_b;
  real_T c2_e_b;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_d_A;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_i_y;
  real_T c2_e_A;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_j_y;
  real_T c2_f_A;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  int32_T c2_i2;
  real_T *c2_b_dt;
  real_T *c2_b_z;
  real_T (*c2_k_y)[6];
  c2_k_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_z = *c2_b_z;
  c2_dt = *c2_b_dt;
  sf_debug_symbol_scope_push(23U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("c1", &c2_c1, c2_sf_marshall);
  sf_debug_symbol_scope_add("rho1", &c2_rho1, c2_sf_marshall);
  sf_debug_symbol_scope_add("p1", &c2_p1, c2_sf_marshall);
  sf_debug_symbol_scope_add("del1", &c2_del1, c2_sf_marshall);
  sf_debug_symbol_scope_add("t1", &c2_t1, c2_sf_marshall);
  sf_debug_symbol_scope_add("a1", &c2_a1, c2_sf_marshall);
  sf_debug_symbol_scope_add("h", &c2_h, c2_sf_marshall);
  sf_debug_symbol_scope_add("conlapse", &c2_conlapse, c2_sf_marshall);
  sf_debug_symbol_scope_add("rm2ft", &c2_rm2ft, c2_sf_marshall);
  sf_debug_symbol_scope_add("slpr", &c2_slpr, c2_sf_marshall);
  sf_debug_symbol_scope_add("sldens", &c2_sldens, c2_sf_marshall);
  sf_debug_symbol_scope_add("hsl", &c2_hsl, c2_sf_marshall);
  sf_debug_symbol_scope_add("psl", &c2_psl, c2_sf_marshall);
  sf_debug_symbol_scope_add("tsl", &c2_tsl, c2_sf_marshall);
  sf_debug_symbol_scope_add("re", &c2_re, c2_sf_marshall);
  sf_debug_symbol_scope_add("g", &c2_g, c2_sf_marshall);
  sf_debug_symbol_scope_add("gamma", &c2_gamma, c2_sf_marshall);
  sf_debug_symbol_scope_add("r", &c2_r, c2_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("dt", &c2_dt, c2_sf_marshall);
  sf_debug_symbol_scope_add("z", &c2_z, c2_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  Author: Kevin Cunningham          April 20, 1992     */
  /*  Modified: Dave Cox                Aug, 14, 2008 */
  _SFD_EML_CALL(0,5);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1 = c2_i1 + 1) {
    c2_y[c2_i1] = 0.0;
  }

  /* dt=0;  % Standard Temp forced. */
  /*     --- constants from 1976 std. atmosphere */
  _SFD_EML_CALL(0,10);
  c2_r = 1.7165591567080301E+003;
  _SFD_EML_CALL(0,11);
  c2_gamma = 1.4;
  _SFD_EML_CALL(0,12);
  c2_g = 32.17405;
  _SFD_EML_CALL(0,13);
  c2_re = 2.08555315E+007;
  _SFD_EML_CALL(0,14);
  c2_tsl = 5.1867E+002;
  _SFD_EML_CALL(0,15);
  c2_psl = 2.11622E+003;
  _SFD_EML_CALL(0,16);
  c2_hsl = 0.0;
  _SFD_EML_CALL(0,17);
  c2_sldens = 0.0023769;

  /*  atmospheric density at sea level */
  _SFD_EML_CALL(0,18);
  c2_slpr = 2.11622E+003;

  /*  sea level pressure, psf */
  /* --------------------------------------------------------------------- */
  /*     conversion from metric lapse rate to english lapse rate */
  /*     meters/0.3048 = ft */
  /*     Kelvin * 1.8 = Rankine */
  _SFD_EML_CALL(0,24);
  c2_rm2ft = 3.2808398950131232E+003;
  _SFD_EML_CALL(0,25);
  c2_conlapse = 5.4864000000000009E-004;

  /*   ---- convert geometric alt. to geopotential alt. */
  _SFD_EML_CALL(0,28);
  c2_b = c2_z;
  c2_A = 2.08555315E+007 * c2_b;
  c2_B = c2_re + c2_z;
  c2_x = c2_A;
  c2_b_y = c2_B;
  if (c2_b_y == 0.0) {
    c2_eml_warning(chartInstance);
  }

  c2_b_x = c2_x;
  c2_c_y = c2_b_y;
  c2_c_x = c2_b_x;
  c2_d_y = c2_c_y;
  c2_h = c2_c_x / c2_d_y;

  /*   ---- ensure we are in layer one (based on geopotential alt) */
  _SFD_EML_CALL(0,31);
  if (CV_EML_IF(0, 0, c2_h > 3.6089238845144355E+004)) {
    /*  11 km */
    /* fprintf(1,'Error, atmosphere model out of range %f, Limiting...\n',h); */
    _SFD_EML_CALL(0,33);
    c2_h = 3.6089238845144355E+004;
  }

  _SFD_EML_CALL(0,35);
  if (CV_EML_IF(0, 1, c2_h < 0.0)) {
    /* fprintf(1,'Error, atmosphere model out of range %f, Limiting...\n',h); */
    _SFD_EML_CALL(0,37);
    c2_h = 0.0;
  }

  _SFD_EML_CALL(0,40);
  c2_a1 = -3.5661600000000005E-003;
  _SFD_EML_CALL(0,41);
  c2_b_b = c2_h - c2_hsl;
  c2_e_y = -3.5661600000000005E-003 * c2_b_b;
  c2_t1 = c2_tsl + c2_e_y;
  _SFD_EML_CALL(0,42);
  c2_b_A = c2_t1;
  c2_d_x = c2_b_A;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_a = c2_f_x / 5.1867E+002;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  if (c2_ak < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_del1 = muDoubleScalarPower(c2_ak, 5.2558883759097395E+000);
  _SFD_EML_CALL(0,43);
  c2_c_a = c2_del1;
  c2_p1 = c2_c_a * 2.11622E+003;

  /*    ---- apply temperature increment from standard day$/ */
  _SFD_EML_CALL(0,46);
  c2_t1 = c2_t1 + c2_dt;

  /*    ---- calculate density from eqn. of state w/ corrected temp.$/ */
  _SFD_EML_CALL(0,49);
  c2_c_A = c2_p1;
  c2_c_b = c2_t1;
  c2_b_B = 1.7165591567080301E+003 * c2_c_b;
  c2_g_x = c2_c_A;
  c2_f_y = c2_b_B;
  if (c2_f_y == 0.0) {
    c2_eml_warning(chartInstance);
  }

  c2_h_x = c2_g_x;
  c2_g_y = c2_f_y;
  c2_i_x = c2_h_x;
  c2_h_y = c2_g_y;
  c2_rho1 = c2_i_x / c2_h_y;

  /*    ---- calculate speed of sound w/ corrected temp.$/ */
  _SFD_EML_CALL(0,52);
  c2_d_b = c2_t1;
  c2_e_b = 1.7165591567080301E+003 * c2_d_b;
  c2_j_x = 1.4 * c2_e_b;
  c2_c1 = c2_j_x;
  if (c2_c1 < 0.0) {
    c2_b_eml_error(chartInstance);
  }

  c2_k_x = c2_c1;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarSqrt(c2_l_x);
  c2_c1 = c2_l_x;

  /*  Calculate outputs */
  _SFD_EML_CALL(0,56);
  c2_y[0] = c2_rho1;
  _SFD_EML_CALL(0,57);
  c2_y[1] = c2_p1;
  _SFD_EML_CALL(0,58);
  c2_d_A = c2_t1;
  c2_m_x = c2_d_A;
  c2_n_x = c2_m_x;
  c2_o_x = c2_n_x;
  c2_i_y = c2_o_x / 1.8;
  c2_y[2] = c2_i_y;

  /*  output temperature  in Kelvin */
  _SFD_EML_CALL(0,59);
  c2_y[3] = c2_c1;
  _SFD_EML_CALL(0,60);
  c2_e_A = c2_y[1];
  c2_p_x = c2_e_A;
  c2_q_x = c2_p_x;
  c2_r_x = c2_q_x;
  c2_j_y = c2_r_x / 2.11622E+003;
  c2_y[4] = c2_j_y;

  /*  pressure ratio */
  _SFD_EML_CALL(0,61);
  c2_f_A = c2_y[0];
  c2_s_x = c2_f_A;
  c2_t_x = c2_s_x;
  c2_u_x = c2_t_x;
  c2_v_x = c2_u_x / 0.0023769;
  c2_w_x = c2_v_x;
  if (c2_w_x < 0.0) {
    c2_b_eml_error(chartInstance);
  }

  c2_x_x = c2_w_x;
  c2_y_x = c2_x_x;
  c2_y_x = muDoubleScalarSqrt(c2_y_x);
  c2_w_x = c2_y_x;
  c2_y[5] = c2_w_x;

  /*  SQUARE ROOT OF DENSITY RATIO */
  _SFD_EML_CALL(0,-61);
  sf_debug_symbol_scope_pop();
  for (c2_i2 = 0; c2_i2 < 6; c2_i2 = c2_i2 + 1) {
    (*c2_k_y)[c2_i2] = c2_y[c2_i2];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_warning(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  static char_T c2_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c2_u[19];
  const mxArray *c2_y = NULL;
  int32_T c2_i4;
  static char_T c2_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c2_b_u[15];
  const mxArray *c2_b_y = NULL;
  for (c2_i3 = 0; c2_i3 < 19; c2_i3 = c2_i3 + 1) {
    c2_u[c2_i3] = c2_varargin_1[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c2_i4 = 0; c2_i4 < 15; c2_i4 = c2_i4 + 1) {
    c2_b_u[c2_i4] = c2_varargin_2[c2_i4];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static void c2_eml_error(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  int32_T c2_i5;
  static char_T c2_varargin_1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e',
    'r', ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[32];
  const mxArray *c2_y = NULL;
  int32_T c2_i6;
  static char_T c2_varargin_2[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e',
    'r', 'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o',
    'm', 'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r',
    'e', 's', 'u', 'l',
    't', 's', ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a',
    's', 't', ' ', 'o',
    'n', 'e', ' ', 'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e',
    'x', ',', ' ', 'e',
    '.', 'g', '.', ' ', '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p',
    'l', 'e', 'x', '('
    , 'a', ')', ',', 'b', ')', '\'', '.' };

  char_T c2_b_u[102];
  const mxArray *c2_b_y = NULL;
  for (c2_i5 = 0; c2_i5 < 32; c2_i5 = c2_i5 + 1) {
    c2_u[c2_i5] = c2_varargin_1[c2_i5];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c2_i6 = 0; c2_i6 < 102; c2_i6 = c2_i6 + 1) {
    c2_b_u[c2_i6] = c2_varargin_2[c2_i6];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static void c2_b_eml_error(SFc2_auxvars_libInstanceStruct *chartInstance)
{
  int32_T c2_i7;
  static char_T c2_varargin_1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  int32_T c2_i8;
  static char_T c2_varargin_2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e',
    'r', 'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o',
    'm', 'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r',
    'e', 's', 'u', 'l',
    't', 's', ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',',
    ' ', 'u', 's', 'e',
    ' ', '\'', 's', 'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'x', ')', ')', '\''
    , '.' };

  char_T c2_b_u[77];
  const mxArray *c2_b_y = NULL;
  for (c2_i7 = 0; c2_i7 < 31; c2_i7 = c2_i7 + 1) {
    c2_u[c2_i7] = c2_varargin_1[c2_i7];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c2_i8 = 0; c2_i8 < 77; c2_i8 = c2_i8 + 1) {
    c2_b_u[c2_i8] = c2_varargin_2[c2_i8];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_auxvars_libInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i9;
  real_T c2_b_u[6];
  const mxArray *c2_b_y = NULL;
  SFc2_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_auxvars_libInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i9 = 0; c2_i9 < 6; c2_i9 = c2_i9 + 1) {
    c2_b_u[c2_i9] = (*((real_T (*)[6])c2_u))[c2_i9];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_auxvars_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[54];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i10;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 54));
  for (c2_i10 = 0; c2_i10 < 54; c2_i10 = c2_i10 + 1) {
    c2_r0 = &c2_info[c2_i10];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i10);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i10);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i10);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i10);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i10);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i10
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i10
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[54])
{
  c2_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].name = "power";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[0].fileLength = 5131U;
  c2_info[0].fileTime1 = 1213662890U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[1].name = "and";
  c2_info[1].dominantType = "logical";
  c2_info[1].resolved = "[B]and";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "minus";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]minus";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[3].name = "eml_div";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[3].fileLength = 4254U;
  c2_info[3].fileTime1 = 1192491972U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[4].name = "eml_error";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[4].fileLength = 315U;
  c2_info[4].fileTime1 = 1213662886U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[5].name = "ge";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]ge";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[6].name = "eml_index_class";
  c2_info[6].dominantType = "";
  c2_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[6].fileLength = 909U;
  c2_info[6].fileTime1 = 1192491982U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[7].name = "int32";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]int32";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "eq";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]eq";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[9].name = "double";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]double";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[10].name = "isnumeric";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isnumeric";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "strcmp";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved = "[B]strcmp";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c2_info[12].name = "isreal";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]isreal";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "mpower";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[13].fileLength = 3547U;
  c2_info[13].fileTime1 = 1213662888U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[14].name = "eml_assert_valid_size_arg";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[14].fileLength = 2835U;
  c2_info[14].fileTime1 = 1210895844U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[15].name = "logical";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]logical";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "mrdivide";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[16].fileLength = 755U;
  c2_info[16].fileTime1 = 1209356082U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[17].name = "true";
  c2_info[17].dominantType = "";
  c2_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[17].fileLength = 237U;
  c2_info[17].fileTime1 = 1192491962U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[18].name = "ndims";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]ndims";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "uminus";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]uminus";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[20].name = "isnan";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[20].fileLength = 472U;
  c2_info[20].fileTime1 = 1192491936U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "";
  c2_info[21].name = "mtimes";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[21].fileLength = 2336U;
  c2_info[21].fileTime1 = 1213662890U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[22].name = "le";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]le";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[23].name = "ne";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]ne";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[24].name = "intmax";
  c2_info[24].dominantType = "char";
  c2_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[24].fileLength = 1535U;
  c2_info[24].fileTime1 = 1192491928U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[25].name = "gt";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]gt";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[26].name = "isempty";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[B]isempty";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[27].name = "isfinite";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[27].fileLength = 341U;
  c2_info[27].fileTime1 = 1192491934U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[28].name = "eml_scalexp_size";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[28].fileLength = 1373U;
  c2_info[28].fileTime1 = 1208205260U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[29].name = "isa";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]isa";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "";
  c2_info[30].name = "lt";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved = "[B]lt";
  c2_info[30].fileLength = 0U;
  c2_info[30].fileTime1 = 0U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[31].name = "eml_alloc";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[31].fileLength = 2627U;
  c2_info[31].fileTime1 = 1213662886U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c2_info[32].name = "islogical";
  c2_info[32].dominantType = "logical";
  c2_info[32].resolved = "[B]islogical";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[33].name = "isvector";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[B]isvector";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[34].name = "cast";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[34].fileLength = 866U;
  c2_info[34].fileTime1 = 1192491844U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[35].name = "nargin";
  c2_info[35].dominantType = "";
  c2_info[35].resolved = "[B]nargin";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[36].name = "isinteger";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]isinteger";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context = "";
  c2_info[37].name = "plus";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[B]plus";
  c2_info[37].fileLength = 0U;
  c2_info[37].fileTime1 = 0U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[38].name = "eml_warning";
  c2_info[38].dominantType = "char";
  c2_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[38].fileLength = 262U;
  c2_info[38].fileTime1 = 1213662888U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[39].name = "rdivide";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[39].fileLength = 620U;
  c2_info[39].fileTime1 = 1213662890U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[40].name = "class";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[B]class";
  c2_info[40].fileLength = 0U;
  c2_info[40].fileTime1 = 0U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[41].name = "false";
  c2_info[41].dominantType = "";
  c2_info[41].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[41].fileLength = 238U;
  c2_info[41].fileTime1 = 1192491920U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[42].name = "eml_scalar_floor";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[42].fileLength = 260U;
  c2_info[42].fileTime1 = 1209355990U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context = "";
  c2_info[43].name = "zeros";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[B]zeros";
  c2_info[43].fileLength = 0U;
  c2_info[43].fileTime1 = 0U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[44].name = "ischar";
  c2_info[44].dominantType = "char";
  c2_info[44].resolved = "[B]ischar";
  c2_info[44].fileLength = 0U;
  c2_info[44].fileTime1 = 0U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[45].name = "assert";
  c2_info[45].dominantType = "char";
  c2_info[45].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c2_info[45].fileLength = 2684U;
  c2_info[45].fileTime1 = 1210895856U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[46].name = "eml_scalexp_compatible";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[46].fileLength = 502U;
  c2_info[46].fileTime1 = 1208205258U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[47].name = "size";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved = "[B]size";
  c2_info[47].fileLength = 0U;
  c2_info[47].fileTime1 = 0U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[48].name = "isscalar";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved = "[B]isscalar";
  c2_info[48].fileLength = 0U;
  c2_info[48].fileTime1 = 0U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[49].name = "isstruct";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved = "[B]isstruct";
  c2_info[49].fileLength = 0U;
  c2_info[49].fileTime1 = 0U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[50].name = "not";
  c2_info[50].dominantType = "logical";
  c2_info[50].resolved = "[B]not";
  c2_info[50].fileLength = 0U;
  c2_info[50].fileTime1 = 0U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[51].name = "isinf";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[51].fileLength = 472U;
  c2_info[51].fileTime1 = 1192491934U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context = "";
  c2_info[52].name = "sqrt";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[52].fileLength = 572U;
  c2_info[52].fileTime1 = 1203473246U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[53].name = "eml_scalar_sqrt";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[53].fileLength = 664U;
  c2_info[53].fileTime1 = 1209355994U;
  c2_info[53].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc2_auxvars_libInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_auxvars_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3049133745U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1394866876U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3522323352U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1980629082U);
}

mxArray *sf_c2_auxvars_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1418915001U);
    pr[1] = (double)(3689050965U);
    pr[2] = (double)(2497811808U);
    pr[3] = (double)(4032893239U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
  SFc2_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_auxvars_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_auxvars_libMachineNumber_,
           2,
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
          init_script_number_translation(_auxvars_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_auxvars_libMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_auxvars_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"z",0,
                              c2_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"y",0,c2_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dt",0,
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1644);
        _SFD_CV_INIT_EML_IF(0,0,860,877,-1,977);
        _SFD_CV_INIT_EML_IF(0,1,978,986,-1,1071);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_z;
          real_T (*c2_y)[6];
          real_T *c2_dt;
          c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_dt);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_auxvars_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c2_auxvars_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_auxvars_libInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*)
    chartInstanceVar);
  initialize_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_auxvars_lib(void *chartInstanceVar)
{
  enable_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_auxvars_lib(void *chartInstanceVar)
{
  disable_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_auxvars_lib(void *chartInstanceVar)
{
  sf_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c2_auxvars_lib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_auxvars_lib
    ((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c2_auxvars_lib(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_auxvars_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_auxvars_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_auxvars_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_auxvars_lib((SFc2_auxvars_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_auxvars_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("auxvars_lib","gtm_design_dbg",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("auxvars_lib","gtm_design_dbg",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("auxvars_lib",
      "gtm_design_dbg",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"auxvars_lib","gtm_design_dbg",2,2);
      sf_mark_chart_reusable_outputs(S,"auxvars_lib","gtm_design_dbg",2,1);
    }

    sf_set_rtw_dwork_info(S,"auxvars_lib","gtm_design_dbg",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2045648096U));
  ssSetChecksum1(S,(404249820U));
  ssSetChecksum2(S,(4284453835U));
  ssSetChecksum3(S,(2843831912U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_auxvars_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "auxvars_lib", "gtm_design_dbg",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_auxvars_lib(SimStruct *S)
{
  SFc2_auxvars_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_auxvars_libInstanceStruct *)malloc(sizeof
    (SFc2_auxvars_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_auxvars_lib;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_auxvars_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_auxvars_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_auxvars_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_auxvars_lib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_auxvars_lib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_auxvars_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_auxvars_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_auxvars_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_auxvars_lib;
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

void c2_auxvars_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_auxvars_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_auxvars_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_auxvars_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_auxvars_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
