/* Include files */

#include "models_sfun.h"
#include "c4_models.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "models_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void initialize_params_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void enable_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void disable_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void update_debugger_state_c4_models(SFc4_modelsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_models(SFc4_modelsInstanceStruct
  *chartInstance);
static void set_sim_state_c4_models(SFc4_modelsInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void sf_c4_models(SFc4_modelsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static real_T c4_eml_bin_extremum(SFc4_modelsInstanceStruct *chartInstance,
  boolean_T c4_domax, real_T c4_x, real_T c4_y);
static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[45]);
static void init_dsm_address_info(SFc4_modelsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_models = 0U;
}

static void initialize_params_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_dv0[3];
  int32_T c4_i0;
  real_T c4_dv1[3];
  int32_T c4_i1;
  real_T c4_d2;
  real_T c4_dv2[3];
  int32_T c4_i2;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'aftfuel' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c4_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_aftfuel = c4_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'fwdfuel' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    3, 0), &c4_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_fwdfuel = c4_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'aftfuel_pos' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c4_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    chartInstance->c4_aftfuel_pos[c4_i0] = c4_dv0[c4_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'fwdfuel_pos' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    4, 0), &c4_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1 = c4_i1 + 1) {
    chartInstance->c4_fwdfuel_pos[c4_i1] = c4_dv1[c4_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'w0' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    5, 0), &c4_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_w0 = c4_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'cg_pos0' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    2, 0), &c4_dv2, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2 = c4_i2 + 1) {
    chartInstance->c4_cg_pos0[c4_i2] = c4_dv2[c4_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c4_models(SFc4_modelsInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_models(SFc4_modelsInstanceStruct
  *chartInstance)
{
  return NULL;
}

static void set_sim_state_c4_models(SFc4_modelsInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
}

static void sf_c4_models(SFc4_modelsInstanceStruct *chartInstance)
{
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  uint8_T c4_previousEvent;
  real_T c4_fuel_used;
  real_T c4_b_aftfuel;
  real_T c4_b_fwdfuel;
  int32_T c4_i7;
  real_T c4_b_aftfuel_pos[3];
  int32_T c4_i8;
  real_T c4_b_fwdfuel_pos[3];
  real_T c4_b_w0;
  int32_T c4_i9;
  real_T c4_b_cg_pos0[3];
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 7.0;
  real_T c4_y[3];
  real_T c4_varargin_2;
  real_T c4_b_y;
  real_T c4_maxval;
  real_T c4_varargin_1;
  real_T c4_b_varargin_2;
  real_T c4_x;
  real_T c4_c_y;
  real_T c4_minval;
  int32_T c4_i10;
  int32_T c4_i11;
  real_T *c4_b_fuel_used;
  real_T (*c4_d_y)[3];
  c4_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_fuel_used = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  _SFD_DATA_RANGE_CHECK(*c4_b_fuel_used, 0U);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_d_y)[c4_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_aftfuel, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_fwdfuel, 3U);
  for (c4_i4 = 0; c4_i4 < 3; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_aftfuel_pos[c4_i4], 4U);
  }

  for (c4_i5 = 0; c4_i5 < 3; c4_i5 = c4_i5 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_fwdfuel_pos[c4_i5], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_w0, 6U);
  for (c4_i6 = 0; c4_i6 < 3; c4_i6 = c4_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_cg_pos0[c4_i6], 7U);
  }

  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c4_fuel_used = *c4_b_fuel_used;
  c4_b_aftfuel = chartInstance->c4_aftfuel;
  c4_b_fwdfuel = chartInstance->c4_fwdfuel;
  for (c4_i7 = 0; c4_i7 < 3; c4_i7 = c4_i7 + 1) {
    c4_b_aftfuel_pos[c4_i7] = chartInstance->c4_aftfuel_pos[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8 = c4_i8 + 1) {
    c4_b_fwdfuel_pos[c4_i8] = chartInstance->c4_fwdfuel_pos[c4_i8];
  }

  c4_b_w0 = chartInstance->c4_w0;
  for (c4_i9 = 0; c4_i9 < 3; c4_i9 = c4_i9 + 1) {
    c4_b_cg_pos0[c4_i9] = chartInstance->c4_cg_pos0[c4_i9];
  }

  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_sf_marshall);
  sf_debug_symbol_scope_add("y", &c4_y, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("cg_pos0", &c4_b_cg_pos0, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("w0", &c4_b_w0, c4_sf_marshall);
  sf_debug_symbol_scope_add("fwdfuel_pos", &c4_b_fwdfuel_pos, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("aftfuel_pos", &c4_b_aftfuel_pos, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("fwdfuel", &c4_b_fwdfuel, c4_sf_marshall);
  sf_debug_symbol_scope_add("aftfuel", &c4_b_aftfuel, c4_sf_marshall);
  sf_debug_symbol_scope_add("fuel_used", &c4_fuel_used, c4_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c4_varargin_2 = c4_fuel_used - c4_b_fwdfuel;
  c4_b_y = c4_varargin_2;
  c4_maxval = c4_eml_bin_extremum(chartInstance, true, 0.0, c4_b_y);
  c4_varargin_1 = c4_b_aftfuel;
  c4_b_varargin_2 = c4_fuel_used;
  c4_x = c4_varargin_1;
  c4_c_y = c4_b_varargin_2;
  c4_minval = c4_eml_bin_extremum(chartInstance, false, c4_x, c4_c_y);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10 = c4_i10 + 1) {
    c4_y[c4_i10] = (c4_b_w0 * c4_b_cg_pos0[c4_i10] - c4_minval *
                    c4_b_aftfuel_pos[c4_i10]) - c4_maxval *
      c4_b_fwdfuel_pos[c4_i10];
  }

  _SFD_EML_CALL(0,-5);
  sf_debug_symbol_scope_pop();
  for (c4_i11 = 0; c4_i11 < 3; c4_i11 = c4_i11 + 1) {
    (*c4_d_y)[c4_i11] = c4_y[c4_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_modelsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static real_T c4_eml_bin_extremum(SFc4_modelsInstanceStruct *chartInstance,
  boolean_T c4_domax, real_T c4_x, real_T c4_y)
{
  real_T c4_xk;
  real_T c4_yk;
  boolean_T c4_b_domax;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_rx;
  real_T c4_ry;
  real_T c4_c_x;
  boolean_T c4_b;
  real_T c4_b_extremum;
  c4_xk = c4_x;
  c4_yk = c4_y;
  c4_b_domax = c4_domax;
  c4_b_x = c4_xk;
  c4_b_y = c4_yk;
  c4_rx = c4_xk;
  c4_ry = c4_yk;
  if (c4_b_domax) {
    if (c4_rx >= c4_ry) {
      goto label_1;
    }
  }

  if (!c4_b_domax) {
    if (c4_rx <= c4_ry) {
      goto label_1;
    }
  }

  c4_c_x = c4_ry;
  c4_b = rtIsNaN(c4_c_x);
  if (c4_b) {
    goto label_2;
  } else {
    c4_b_extremum = c4_b_y;
    goto label_3;
  }

 label_1:
  ;
 label_2:
  ;
  c4_b_extremum = c4_b_x;
 label_3:
  ;
  return c4_b_extremum;
}

static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc4_modelsInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i12;
  real_T c4_b_u[3];
  const mxArray *c4_b_y = NULL;
  SFc4_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc4_modelsInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  for (c4_i12 = 0; c4_i12 < 3; c4_i12 = c4_i12 + 1) {
    c4_b_u[c4_i12] = (*((real_T (*)[3])c4_u))[c4_i12];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_models_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[45];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i13;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 45));
  for (c4_i13 = 0; c4_i13 < 45; c4_i13 = c4_i13 + 1) {
    c4_r0 = &c4_info[c4_i13];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i13);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i13
                    );
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i13
                    );
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[45])
{
  c4_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[0].name = "zeros";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[B]zeros";
  c4_info[0].fileLength = 0U;
  c4_info[0].fileTime1 = 0U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[1].name = "gt";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved = "[B]gt";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[2].name = "isa";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[B]isa";
  c4_info[2].fileLength = 0U;
  c4_info[2].fileTime1 = 0U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[3].name = "isinf";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c4_info[3].fileLength = 472U;
  c4_info[3].fileTime1 = 1192491934U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c4_info[4].name = "cast";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c4_info[4].fileLength = 866U;
  c4_info[4].fileTime1 = 1192491844U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[5].name = "ischar";
  c4_info[5].dominantType = "char";
  c4_info[5].resolved = "[B]ischar";
  c4_info[5].fileLength = 0U;
  c4_info[5].fileTime1 = 0U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[6].name = "ne";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[B]ne";
  c4_info[6].fileLength = 0U;
  c4_info[6].fileTime1 = 0U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c4_info[7].name = "eml_alloc";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[7].fileLength = 2627U;
  c4_info[7].fileTime1 = 1213662886U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[8].name = "size";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[B]size";
  c4_info[8].fileLength = 0U;
  c4_info[8].fileTime1 = 0U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c4_info[9].name = "islogical";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[B]islogical";
  c4_info[9].fileLength = 0U;
  c4_info[9].fileTime1 = 0U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[10].name = "eml_assert_valid_size_arg";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[10].fileLength = 2835U;
  c4_info[10].fileTime1 = 1210895844U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[11].name = "false";
  c4_info[11].dominantType = "";
  c4_info[11].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[11].fileLength = 238U;
  c4_info[11].fileTime1 = 1192491920U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[12].name = "isnumeric";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[B]isnumeric";
  c4_info[12].fileLength = 0U;
  c4_info[12].fileTime1 = 0U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[13].name = "isnan";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[13].fileLength = 472U;
  c4_info[13].fileTime1 = 1192491936U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[14].name = "eml_scalexp_compatible";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[14].fileLength = 502U;
  c4_info[14].fileTime1 = 1208205258U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context = "";
  c4_info[15].name = "max";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c4_info[15].fileLength = 308U;
  c4_info[15].fileTime1 = 1192491830U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c4_info[16].name = "int32";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved = "[B]int32";
  c4_info[16].fileLength = 0U;
  c4_info[16].fileTime1 = 0U;
  c4_info[16].fileTime2 = 0U;
  c4_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[17].name = "isvector";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved = "[B]isvector";
  c4_info[17].fileLength = 0U;
  c4_info[17].fileTime1 = 0U;
  c4_info[17].fileTime2 = 0U;
  c4_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[18].name = "isstruct";
  c4_info[18].dominantType = "double";
  c4_info[18].resolved = "[B]isstruct";
  c4_info[18].fileLength = 0U;
  c4_info[18].fileTime1 = 0U;
  c4_info[18].fileTime2 = 0U;
  c4_info[19].context = "";
  c4_info[19].name = "minus";
  c4_info[19].dominantType = "double";
  c4_info[19].resolved = "[B]minus";
  c4_info[19].fileLength = 0U;
  c4_info[19].fileTime1 = 0U;
  c4_info[19].fileTime2 = 0U;
  c4_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[20].name = "intmax";
  c4_info[20].dominantType = "char";
  c4_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c4_info[20].fileLength = 1535U;
  c4_info[20].fileTime1 = 1192491928U;
  c4_info[20].fileTime2 = 0U;
  c4_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[21].name = "class";
  c4_info[21].dominantType = "double";
  c4_info[21].resolved = "[B]class";
  c4_info[21].fileLength = 0U;
  c4_info[21].fileTime1 = 0U;
  c4_info[21].fileTime2 = 0U;
  c4_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[22].name = "eml_min_or_max";
  c4_info[22].dominantType = "char";
  c4_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[22].fileLength = 7562U;
  c4_info[22].fileTime1 = 1213662886U;
  c4_info[22].fileTime2 = 0U;
  c4_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[23].name = "eml_index_class";
  c4_info[23].dominantType = "";
  c4_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[23].fileLength = 909U;
  c4_info[23].fileTime1 = 1192491982U;
  c4_info[23].fileTime2 = 0U;
  c4_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c4_info[24].name = "ones";
  c4_info[24].dominantType = "char";
  c4_info[24].resolved = "[B]ones";
  c4_info[24].fileLength = 0U;
  c4_info[24].fileTime1 = 0U;
  c4_info[24].fileTime2 = 0U;
  c4_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[25].name = "isscalar";
  c4_info[25].dominantType = "double";
  c4_info[25].resolved = "[B]isscalar";
  c4_info[25].fileLength = 0U;
  c4_info[25].fileTime1 = 0U;
  c4_info[25].fileTime2 = 0U;
  c4_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c4_info[26].name = "ge";
  c4_info[26].dominantType = "double";
  c4_info[26].resolved = "[B]ge";
  c4_info[26].fileLength = 0U;
  c4_info[26].fileTime1 = 0U;
  c4_info[26].fileTime2 = 0U;
  c4_info[27].context = "";
  c4_info[27].name = "min";
  c4_info[27].dominantType = "double";
  c4_info[27].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[27].fileLength = 308U;
  c4_info[27].fileTime1 = 1192491834U;
  c4_info[27].fileTime2 = 0U;
  c4_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c4_info[28].name = "double";
  c4_info[28].dominantType = "double";
  c4_info[28].resolved = "[B]double";
  c4_info[28].fileLength = 0U;
  c4_info[28].fileTime1 = 0U;
  c4_info[28].fileTime2 = 0U;
  c4_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[29].name = "isfinite";
  c4_info[29].dominantType = "double";
  c4_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[29].fileLength = 341U;
  c4_info[29].fileTime1 = 1192491934U;
  c4_info[29].fileTime2 = 0U;
  c4_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[30].name = "eq";
  c4_info[30].dominantType = "double";
  c4_info[30].resolved = "[B]eq";
  c4_info[30].fileLength = 0U;
  c4_info[30].fileTime1 = 0U;
  c4_info[30].fileTime2 = 0U;
  c4_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[31].name = "true";
  c4_info[31].dominantType = "";
  c4_info[31].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c4_info[31].fileLength = 237U;
  c4_info[31].fileTime1 = 1192491962U;
  c4_info[31].fileTime2 = 0U;
  c4_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[32].name = "le";
  c4_info[32].dominantType = "double";
  c4_info[32].resolved = "[B]le";
  c4_info[32].fileLength = 0U;
  c4_info[32].fileTime1 = 0U;
  c4_info[32].fileTime2 = 0U;
  c4_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[33].name = "logical";
  c4_info[33].dominantType = "double";
  c4_info[33].resolved = "[B]logical";
  c4_info[33].fileLength = 0U;
  c4_info[33].fileTime1 = 0U;
  c4_info[33].fileTime2 = 0U;
  c4_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[34].name = "isreal";
  c4_info[34].dominantType = "double";
  c4_info[34].resolved = "[B]isreal";
  c4_info[34].fileLength = 0U;
  c4_info[34].fileTime1 = 0U;
  c4_info[34].fileTime2 = 0U;
  c4_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[35].name = "not";
  c4_info[35].dominantType = "logical";
  c4_info[35].resolved = "[B]not";
  c4_info[35].fileLength = 0U;
  c4_info[35].fileTime1 = 0U;
  c4_info[35].fileTime2 = 0U;
  c4_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[36].name = "isinteger";
  c4_info[36].dominantType = "double";
  c4_info[36].resolved = "[B]isinteger";
  c4_info[36].fileLength = 0U;
  c4_info[36].fileTime1 = 0U;
  c4_info[36].fileTime2 = 0U;
  c4_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c4_info[37].name = "mtimes";
  c4_info[37].dominantType = "double";
  c4_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[37].fileLength = 2336U;
  c4_info[37].fileTime1 = 1213662890U;
  c4_info[37].fileTime2 = 0U;
  c4_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c4_info[38].name = "plus";
  c4_info[38].dominantType = "double";
  c4_info[38].resolved = "[B]plus";
  c4_info[38].fileLength = 0U;
  c4_info[38].fileTime1 = 0U;
  c4_info[38].fileTime2 = 0U;
  c4_info[39].context = "";
  c4_info[39].name = "times";
  c4_info[39].dominantType = "double";
  c4_info[39].resolved = "[B]times";
  c4_info[39].fileLength = 0U;
  c4_info[39].fileTime1 = 0U;
  c4_info[39].fileTime2 = 0U;
  c4_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[40].name = "strcmp";
  c4_info[40].dominantType = "char";
  c4_info[40].resolved = "[B]strcmp";
  c4_info[40].fileLength = 0U;
  c4_info[40].fileTime1 = 0U;
  c4_info[40].fileTime2 = 0U;
  c4_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[41].name = "nargin";
  c4_info[41].dominantType = "";
  c4_info[41].resolved = "[B]nargin";
  c4_info[41].fileLength = 0U;
  c4_info[41].fileTime1 = 0U;
  c4_info[41].fileTime2 = 0U;
  c4_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c4_info[42].name = "eml_scalexp_size";
  c4_info[42].dominantType = "double";
  c4_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[42].fileLength = 1373U;
  c4_info[42].fileTime1 = 1208205260U;
  c4_info[42].fileTime2 = 0U;
  c4_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[43].name = "and";
  c4_info[43].dominantType = "logical";
  c4_info[43].resolved = "[B]and";
  c4_info[43].fileLength = 0U;
  c4_info[43].fileTime1 = 0U;
  c4_info[43].fileTime2 = 0U;
  c4_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[44].name = "nargout";
  c4_info[44].dominantType = "";
  c4_info[44].resolved = "[B]nargout";
  c4_info[44].fileLength = 0U;
  c4_info[44].fileTime1 = 0U;
  c4_info[44].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc4_modelsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_models_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1184487643U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3348475039U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4154186590U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(522978328U);
}

mxArray *sf_c4_models_get_autoinheritance_info(void)
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
  SFc4_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc4_modelsInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_modelsMachineNumber_,
          4,
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
          init_script_number_translation(_modelsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_modelsMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_modelsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "fuel_used",0,c4_sf_marshall);

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
                                1.0,0,"aftfuel_pos",0,c4_b_sf_marshall);
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
          real_T *c4_fuel_used;
          real_T (*c4_y)[3];
          c4_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_fuel_used = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_fuel_used);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c4_aftfuel);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c4_fwdfuel);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c4_aftfuel_pos);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c4_fwdfuel_pos);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c4_w0);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c4_cg_pos0);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_modelsMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c4_models(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_modelsInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
  initialize_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_models(void *chartInstanceVar)
{
  enable_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_models(void *chartInstanceVar)
{
  disable_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_models(void *chartInstanceVar)
{
  sf_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c4_models(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_models((SFc4_modelsInstanceStruct*)
    chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c4_models(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar,
    sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_models(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_modelsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_models((SFc4_modelsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_models(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_models((SFc4_modelsInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_models(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable("models","claw_main",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("models","claw_main",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("models","claw_main",4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"models","claw_main",4,1);
      sf_mark_chart_reusable_outputs(S,"models","claw_main",4,1);
    }

    sf_set_rtw_dwork_info(S,"models","claw_main",4);
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

static void mdlRTW_c4_models(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "models", "claw_main",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_models(SimStruct *S)
{
  SFc4_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc4_modelsInstanceStruct *)malloc(sizeof
    (SFc4_modelsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_models;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_models;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_models;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_models;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_models;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_models;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_models;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_models;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_models;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_models;
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

void c4_models_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_models(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_models(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_models(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_models_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
