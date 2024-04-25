/* Include files */

#include "acparams_lib_sfun.h"
#include "c2_acparams_lib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "acparams_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance);
static void initialize_params_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance);
static void enable_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance);
static void disable_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance);
static void update_debugger_state_c2_acparams_lib
  (SFc2_acparams_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_acparams_lib
  (SFc2_acparams_libInstanceStruct *chartInstance);
static void set_sim_state_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance);
static void sf_c2_acparams_lib(SFc2_acparams_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_eml_bin_extremum(SFc2_acparams_libInstanceStruct *chartInstance,
  boolean_T c2_domax, real_T c2_x, real_T c2_y);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[45]);
static void init_dsm_address_info(SFc2_acparams_libInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_acparams_lib = 0U;
}

static void initialize_params_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  real_T c2_dv0[3];
  int32_T c2_i0;
  real_T c2_dv1[3];
  int32_T c2_i1;
  real_T c2_d2;
  real_T c2_dv2[3];
  int32_T c2_i2;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'aftfuel' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_aftfuel = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'fwdfuel' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    3, 0), &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_fwdfuel = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'aftfuel_pos' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c2_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    chartInstance->c2_aftfuel_pos[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'fwdfuel_pos' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    4, 0), &c2_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    chartInstance->c2_fwdfuel_pos[c2_i1] = c2_dv1[c2_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'w0' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    5, 0), &c2_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_w0 = c2_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'cg_pos0' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    2, 0), &c2_dv2, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    chartInstance->c2_cg_pos0[c2_i2] = c2_dv2[c2_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c2_acparams_lib
  (SFc2_acparams_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_acparams_lib
  (SFc2_acparams_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_acparams_lib(SFc2_acparams_libInstanceStruct
  *chartInstance)
{
}

static void sf_c2_acparams_lib(SFc2_acparams_libInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  uint8_T c2_previousEvent;
  real_T c2_fuel_used;
  real_T c2_b_aftfuel;
  real_T c2_b_fwdfuel;
  int32_T c2_i7;
  real_T c2_b_aftfuel_pos[3];
  int32_T c2_i8;
  real_T c2_b_fwdfuel_pos[3];
  real_T c2_b_w0;
  int32_T c2_i9;
  real_T c2_b_cg_pos0[3];
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 7.0;
  real_T c2_y[3];
  real_T c2_varargin_2;
  real_T c2_b_y;
  real_T c2_maxval;
  real_T c2_varargin_1;
  real_T c2_b_varargin_2;
  real_T c2_x;
  real_T c2_c_y;
  real_T c2_minval;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T *c2_b_fuel_used;
  real_T (*c2_d_y)[3];
  c2_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_fuel_used = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_b_fuel_used, 0U);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_d_y)[c2_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_aftfuel, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_fwdfuel, 3U);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4 = c2_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_aftfuel_pos[c2_i4], 4U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_fwdfuel_pos[c2_i5], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_w0, 6U);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_cg_pos0[c2_i6], 7U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_fuel_used = *c2_b_fuel_used;
  c2_b_aftfuel = chartInstance->c2_aftfuel;
  c2_b_fwdfuel = chartInstance->c2_fwdfuel;
  for (c2_i7 = 0; c2_i7 < 3; c2_i7 = c2_i7 + 1) {
    c2_b_aftfuel_pos[c2_i7] = chartInstance->c2_aftfuel_pos[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_b_fwdfuel_pos[c2_i8] = chartInstance->c2_fwdfuel_pos[c2_i8];
  }

  c2_b_w0 = chartInstance->c2_w0;
  for (c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_b_cg_pos0[c2_i9] = chartInstance->c2_cg_pos0[c2_i9];
  }

  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("cg_pos0", &c2_b_cg_pos0, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("w0", &c2_b_w0, c2_sf_marshall);
  sf_debug_symbol_scope_add("fwdfuel_pos", &c2_b_fwdfuel_pos, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("aftfuel_pos", &c2_b_aftfuel_pos, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("fwdfuel", &c2_b_fwdfuel, c2_sf_marshall);
  sf_debug_symbol_scope_add("aftfuel", &c2_b_aftfuel, c2_sf_marshall);
  sf_debug_symbol_scope_add("fuel_used", &c2_fuel_used, c2_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c2_varargin_2 = c2_fuel_used - c2_b_fwdfuel;
  c2_b_y = c2_varargin_2;
  c2_maxval = c2_eml_bin_extremum(chartInstance, true, 0.0, c2_b_y);
  c2_varargin_1 = c2_b_aftfuel;
  c2_b_varargin_2 = c2_fuel_used;
  c2_x = c2_varargin_1;
  c2_c_y = c2_b_varargin_2;
  c2_minval = c2_eml_bin_extremum(chartInstance, false, c2_x, c2_c_y);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10 = c2_i10 + 1) {
    c2_y[c2_i10] = (c2_b_w0 * c2_b_cg_pos0[c2_i10] - c2_minval *
                    c2_b_aftfuel_pos[c2_i10]) - c2_maxval *
      c2_b_fwdfuel_pos[c2_i10];
  }

  _SFD_EML_CALL(0,-5);
  sf_debug_symbol_scope_pop();
  for (c2_i11 = 0; c2_i11 < 3; c2_i11 = c2_i11 + 1) {
    (*c2_d_y)[c2_i11] = c2_y[c2_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_acparams_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_eml_bin_extremum(SFc2_acparams_libInstanceStruct *chartInstance,
  boolean_T c2_domax, real_T c2_x, real_T c2_y)
{
  real_T c2_xk;
  real_T c2_yk;
  boolean_T c2_b_domax;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_rx;
  real_T c2_ry;
  real_T c2_c_x;
  boolean_T c2_b;
  real_T c2_b_extremum;
  c2_xk = c2_x;
  c2_yk = c2_y;
  c2_b_domax = c2_domax;
  c2_b_x = c2_xk;
  c2_b_y = c2_yk;
  c2_rx = c2_xk;
  c2_ry = c2_yk;
  if (c2_b_domax) {
    if (c2_rx >= c2_ry) {
      goto label_1;
    }
  }

  if (!c2_b_domax) {
    if (c2_rx <= c2_ry) {
      goto label_1;
    }
  }

  c2_c_x = c2_ry;
  c2_b = rtIsNaN(c2_c_x);
  if (c2_b) {
    goto label_2;
  } else {
    c2_b_extremum = c2_b_y;
    goto label_3;
  }

 label_1:
  ;
 label_2:
  ;
  c2_b_extremum = c2_b_x;
 label_3:
  ;
  return c2_b_extremum;
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_acparams_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_acparams_libInstanceStruct *)chartInstanceVoid;
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
  int32_T c2_i12;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_acparams_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_acparams_libInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i12 = 0; c2_i12 < 3; c2_i12 = c2_i12 + 1) {
    c2_b_u[c2_i12] = (*((real_T (*)[3])c2_u))[c2_i12];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_acparams_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[45];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i13;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 45));
  for (c2_i13 = 0; c2_i13 < 45; c2_i13 = c2_i13 + 1) {
    c2_r0 = &c2_info[c2_i13];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i13
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i13
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[45])
{
  c2_info[0].context = "";
  c2_info[0].name = "min";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[0].fileLength = 308U;
  c2_info[0].fileTime1 = 1192491834U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[1].name = "false";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[1].fileLength = 238U;
  c2_info[1].fileTime1 = 1192491920U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "times";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]times";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[3].name = "nargin";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargin";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[4].name = "isfinite";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[4].fileLength = 341U;
  c2_info[4].fileTime1 = 1192491934U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[5].name = "eml_scalexp_compatible";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[5].fileLength = 502U;
  c2_info[5].fileTime1 = 1208205258U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[6].name = "ne";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]ne";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[7].name = "intmax";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[7].fileLength = 1535U;
  c2_info[7].fileTime1 = 1192491928U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[8].name = "strcmp";
  c2_info[8].dominantType = "char";
  c2_info[8].resolved = "[B]strcmp";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "minus";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]minus";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[10].name = "isinf";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[10].fileLength = 472U;
  c2_info[10].fileTime1 = 1192491934U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[11].name = "islogical";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]islogical";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[12].name = "nargout";
  c2_info[12].dominantType = "";
  c2_info[12].resolved = "[B]nargout";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[13].name = "eq";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]eq";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "max";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[14].fileLength = 308U;
  c2_info[14].fileTime1 = 1192491830U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[15].name = "le";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]le";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[16].name = "double";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]double";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[17].name = "isstruct";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]isstruct";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[18].name = "zeros";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]zeros";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[19].name = "eml_min_or_max";
  c2_info[19].dominantType = "char";
  c2_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[19].fileLength = 7562U;
  c2_info[19].fileTime1 = 1213662886U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[20].name = "isreal";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]isreal";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[21].name = "eml_alloc";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[21].fileLength = 2627U;
  c2_info[21].fileTime1 = 1213662886U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[22].name = "eml_index_class";
  c2_info[22].dominantType = "";
  c2_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[22].fileLength = 909U;
  c2_info[22].fileTime1 = 1192491982U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[23].name = "class";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]class";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[24].name = "mtimes";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[24].fileLength = 2336U;
  c2_info[24].fileTime1 = 1213662890U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[25].name = "gt";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]gt";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[26].name = "isnan";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[26].fileLength = 472U;
  c2_info[26].fileTime1 = 1192491936U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[27].name = "eml_scalexp_size";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[27].fileLength = 1373U;
  c2_info[27].fileTime1 = 1208205260U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[28].name = "isnumeric";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]isnumeric";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[29].name = "plus";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]plus";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[30].name = "not";
  c2_info[30].dominantType = "logical";
  c2_info[30].resolved = "[B]not";
  c2_info[30].fileLength = 0U;
  c2_info[30].fileTime1 = 0U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[31].name = "ones";
  c2_info[31].dominantType = "char";
  c2_info[31].resolved = "[B]ones";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[32].name = "isa";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]isa";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[33].name = "cast";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[33].fileLength = 866U;
  c2_info[33].fileTime1 = 1192491844U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[34].name = "eml_assert_valid_size_arg";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[34].fileLength = 2835U;
  c2_info[34].fileTime1 = 1210895844U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[35].name = "int32";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]int32";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[36].name = "size";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]size";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[37].name = "true";
  c2_info[37].dominantType = "";
  c2_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[37].fileLength = 237U;
  c2_info[37].fileTime1 = 1192491962U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[38].name = "and";
  c2_info[38].dominantType = "logical";
  c2_info[38].resolved = "[B]and";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[39].name = "isscalar";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[B]isscalar";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[40].name = "isinteger";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[B]isinteger";
  c2_info[40].fileLength = 0U;
  c2_info[40].fileTime1 = 0U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[41].name = "ge";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved = "[B]ge";
  c2_info[41].fileLength = 0U;
  c2_info[41].fileTime1 = 0U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[42].name = "logical";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[B]logical";
  c2_info[42].fileLength = 0U;
  c2_info[42].fileTime1 = 0U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[43].name = "isvector";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[B]isvector";
  c2_info[43].fileLength = 0U;
  c2_info[43].fileTime1 = 0U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[44].name = "ischar";
  c2_info[44].dominantType = "char";
  c2_info[44].resolved = "[B]ischar";
  c2_info[44].fileLength = 0U;
  c2_info[44].fileTime1 = 0U;
  c2_info[44].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc2_acparams_libInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_acparams_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3944527013U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1888669154U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1785845424U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1421194341U);
}

mxArray *sf_c2_acparams_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1682516804U);
    pr[1] = (double)(2236148095U);
    pr[2] = (double)(2654441848U);
    pr[3] = (double)(2531298493U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc2_acparams_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_acparams_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_acparams_libMachineNumber_,
           2,
           1,
           1,
           8,
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
          init_script_number_translation(_acparams_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_acparams_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_acparams_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "fuel_used",0,c2_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"y",0,NULL);
          }

          _SFD_SET_DATA_PROPS(2,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "aftfuel",0,NULL);
          _SFD_SET_DATA_PROPS(3,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "fwdfuel",0,NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(4,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"aftfuel_pos",0,c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(5,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"fwdfuel_pos",0,NULL);
          }

          _SFD_SET_DATA_PROPS(6,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"w0",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(7,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"cg_pos0",0,NULL);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,275);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_fuel_used;
          real_T (*c2_y)[3];
          c2_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_fuel_used = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_fuel_used);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c2_aftfuel);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_fwdfuel);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c2_aftfuel_pos);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_fwdfuel_pos);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c2_w0);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_cg_pos0);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_acparams_libMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c2_acparams_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_acparams_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_acparams_lib((SFc2_acparams_libInstanceStruct*)
    chartInstanceVar);
  initialize_c2_acparams_lib((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_acparams_lib(void *chartInstanceVar)
{
  enable_c2_acparams_lib((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_acparams_lib(void *chartInstanceVar)
{
  disable_c2_acparams_lib((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_acparams_lib(void *chartInstanceVar)
{
  sf_c2_acparams_lib((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c2_acparams_lib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_acparams_lib
    ((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c2_acparams_lib(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c2_acparams_lib((SFc2_acparams_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_acparams_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_acparams_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_acparams_lib((SFc2_acparams_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_acparams_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_acparams_lib((SFc2_acparams_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_acparams_lib(SimStruct *S)
{
  /* Actual parameters from chart:
     aftfuel aftfuel_pos cg_pos0 fwdfuel fwdfuel_pos w0
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for aftfuel*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for aftfuel_pos*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for cg_pos0*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for fwdfuel*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for fwdfuel_pos*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for w0*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("acparams_lib","gtm_design_dbg",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("acparams_lib","gtm_design_dbg",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("acparams_lib",
      "gtm_design_dbg",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"acparams_lib","gtm_design_dbg",2,1);
      sf_mark_chart_reusable_outputs(S,"acparams_lib","gtm_design_dbg",2,1);
    }

    sf_set_rtw_dwork_info(S,"acparams_lib","gtm_design_dbg",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3231938231U));
  ssSetChecksum1(S,(3266967537U));
  ssSetChecksum2(S,(1755842589U));
  ssSetChecksum3(S,(210570415U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_acparams_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "acparams_lib", "gtm_design_dbg",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_acparams_lib(SimStruct *S)
{
  SFc2_acparams_libInstanceStruct *chartInstance;
  chartInstance = (SFc2_acparams_libInstanceStruct *)malloc(sizeof
    (SFc2_acparams_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_acparams_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_acparams_lib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_acparams_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_acparams_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_acparams_lib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_acparams_lib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_acparams_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_acparams_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_acparams_lib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_acparams_lib;
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

void c2_acparams_lib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_acparams_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_acparams_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_acparams_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_acparams_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
