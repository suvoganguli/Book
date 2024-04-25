/* Include files */

#include "aeroutilslib_sfun.h"
#include "c6_aeroutilslib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "aeroutilslib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance);
static void initialize_params_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance);
static void enable_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance);
static void disable_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance);
static void update_debugger_state_c6_aeroutilslib
  (SFc6_aeroutilslibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_aeroutilslib
  (SFc6_aeroutilslibInstanceStruct *chartInstance);
static void set_sim_state_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance);
static void sf_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static void c6_eml_error(SFc6_aeroutilslibInstanceStruct *chartInstance);
static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[67]);
static void init_dsm_address_info(SFc6_aeroutilslibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_aeroutilslib = 0U;
}

static void initialize_params_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance)
{
  real_T c6_dv0[3];
  int32_T c6_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'p' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c6_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3);
  for (c6_i0 = 0; c6_i0 < 3; c6_i0 = c6_i0 + 1) {
    chartInstance->c6_p[c6_i0] = c6_dv0[c6_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c6_aeroutilslib
  (SFc6_aeroutilslibInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_aeroutilslib
  (SFc6_aeroutilslibInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct
  *chartInstance)
{
}

static void sf_c6_aeroutilslib(SFc6_aeroutilslibInstanceStruct *chartInstance)
{
  int32_T c6_i1;
  uint8_T c6_previousEvent;
  real_T c6_u;
  int32_T c6_i2;
  real_T c6_b_p[3];
  real_T c6_nargout = 1.0;
  real_T c6_nargin = 2.0;
  real_T c6_y;
  real_T c6_a;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_ak;
  int32_T c6_hoistedExpr;
  real_T c6_bk;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_b_y[3];
  int32_T c6_i3;
  real_T c6_c_x[3];
  int32_T c6_i4;
  real_T c6_d_x[3];
  real_T c6_e_x;
  int32_T c6_c_k;
  int32_T c6_d_k;
  real_T c6_f_x;
  real_T c6_r;
  real_T *c6_b_u;
  real_T *c6_c_y;
  c6_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c6_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_c_y, 1U);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1 = c6_i1 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_p[c6_i1], 2U);
  }

  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c6_u = *c6_b_u;
  for (c6_i2 = 0; c6_i2 < 3; c6_i2 = c6_i2 + 1) {
    c6_b_p[c6_i2] = chartInstance->c6_p[c6_i2];
  }

  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_sf_marshall);
  sf_debug_symbol_scope_add("y", &c6_y, c6_sf_marshall);
  sf_debug_symbol_scope_add("p", &c6_b_p, c6_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c6_u, c6_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,6);
  c6_a = c6_u;
  for (c6_k = 1.0; c6_k <= 3.0; c6_k = c6_k + 1.0) {
    c6_b_k = c6_k;
    c6_ak = c6_a;
    c6_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("b", (int32_T)
      _SFD_INTEGER_CHECK("k", c6_b_k), 1, 3, 1, 0) - 1;
    c6_bk = 2.0 + -1.0 * (real_T)c6_hoistedExpr;
    if (c6_ak < 0.0) {
      c6_x = c6_bk;
      c6_b_x = c6_x;
      c6_b_x = muDoubleScalarFloor(c6_b_x);
      if (c6_b_x != c6_bk) {
        c6_eml_error(chartInstance);
        goto label_1;
      }
    }

   label_1:
    ;
    c6_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k",
      c6_b_k), 1, 3, 1, 0) - 1] = muDoubleScalarPower(c6_ak,
      c6_bk);
  }

  for (c6_i3 = 0; c6_i3 < 3; c6_i3 = c6_i3 + 1) {
    c6_c_x[c6_i3] = c6_b_p[c6_i3] * c6_b_y[c6_i3];
  }

  for (c6_i4 = 0; c6_i4 < 3; c6_i4 = c6_i4 + 1) {
    c6_d_x[c6_i4] = c6_c_x[c6_i4];
  }

  c6_e_x = c6_d_x[0];
  c6_y = c6_e_x;
  for (c6_c_k = 2; c6_c_k < 4; c6_c_k = c6_c_k + 1) {
    c6_d_k = c6_c_k;
    c6_f_x = c6_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("k",
      (real_T)c6_d_k), 1, 3, 1, 0) - 1];
    c6_r = c6_f_x;
    c6_y = c6_y + c6_r;
  }

  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  *c6_c_y = c6_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_aeroutilslibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static void c6_eml_error(SFc6_aeroutilslibInstanceStruct *chartInstance)
{
  int32_T c6_i5;
  static char_T c6_varargin_1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e',
    'r', ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[32];
  const mxArray *c6_y = NULL;
  int32_T c6_i6;
  static char_T c6_varargin_2[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e',
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

  char_T c6_b_u[102];
  const mxArray *c6_b_y = NULL;
  for (c6_i5 = 0; c6_i5 < 32; c6_i5 = c6_i5 + 1) {
    c6_u[c6_i5] = c6_varargin_1[c6_i5];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c6_i6 = 0; c6_i6 < 102; c6_i6 = c6_i6 + 1) {
    c6_b_u[c6_i6] = c6_varargin_2[c6_i6];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call("error", 0U, 2U, 14, c6_y, 14, c6_b_y);
}

static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_aeroutilslibInstanceStruct *chartInstance;
  chartInstance = (SFc6_aeroutilslibInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i7;
  real_T c6_b_u[3];
  const mxArray *c6_b_y = NULL;
  SFc6_aeroutilslibInstanceStruct *chartInstance;
  chartInstance = (SFc6_aeroutilslibInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i7 = 0; c6_i7 < 3; c6_i7 = c6_i7 + 1) {
    c6_b_u[c6_i7] = (*((real_T (*)[3])c6_u))[c6_i7];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray *sf_c6_aeroutilslib_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[67];
  c6_ResolvedFunctionInfo (*c6_b_info)[67];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i8;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  c6_b_info = (c6_ResolvedFunctionInfo (*)[67])c6_info;
  (*c6_b_info)[64].context = "";
  (*c6_b_info)[64].name = "times";
  (*c6_b_info)[64].dominantType = "double";
  (*c6_b_info)[64].resolved = "[B]times";
  (*c6_b_info)[64].fileLength = 0U;
  (*c6_b_info)[64].fileTime1 = 0U;
  (*c6_b_info)[64].fileTime2 = 0U;
  (*c6_b_info)[65].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  (*c6_b_info)[65].name = "eml_nonsingleton_dim";
  (*c6_b_info)[65].dominantType = "logical";
  (*c6_b_info)[65].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  (*c6_b_info)[65].fileLength = 404U;
  (*c6_b_info)[65].fileTime1 = 1192492000U;
  (*c6_b_info)[65].fileTime2 = 0U;
  (*c6_b_info)[66].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  (*c6_b_info)[66].name = "isinteger";
  (*c6_b_info)[66].dominantType = "double";
  (*c6_b_info)[66].resolved = "[B]isinteger";
  (*c6_b_info)[66].fileLength = 0U;
  (*c6_b_info)[66].fileTime1 = 0U;
  (*c6_b_info)[66].fileTime2 = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 67));
  for (c6_i8 = 0; c6_i8 < 67; c6_i8 = c6_i8 + 1) {
    c6_r0 = &c6_info[c6_i8];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i8);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[67])
{
  c6_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[0].name = "not";
  c6_info[0].dominantType = "logical";
  c6_info[0].resolved = "[B]not";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c6_info[1].name = "cast";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c6_info[1].fileLength = 866U;
  c6_info[1].fileTime1 = 1192491844U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[2].name = "int32";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[B]int32";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[3].name = "power";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[3].fileLength = 5131U;
  c6_info[3].fileTime1 = 1213662890U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[4].name = "isvector";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]isvector";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "";
  c6_info[5].name = "length";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[5].fileLength = 303U;
  c6_info[5].fileTime1 = 1192491938U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[6].name = "eml_scalar_floor";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[6].fileLength = 260U;
  c6_info[6].fileTime1 = 1209355990U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c6_info[7].name = "le";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]le";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[8].name = "eml_scalexp_size";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c6_info[8].fileLength = 1373U;
  c6_info[8].fileTime1 = 1208205260U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[9].name = "isscalar";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[B]isscalar";
  c6_info[9].fileLength = 0U;
  c6_info[9].fileTime1 = 0U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c6_info[10].name = "false";
  c6_info[10].dominantType = "";
  c6_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c6_info[10].fileLength = 238U;
  c6_info[10].fileTime1 = 1192491920U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[11].name = "nargin";
  c6_info[11].dominantType = "";
  c6_info[11].resolved = "[B]nargin";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c6_info[12].name = "logical";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved = "[B]logical";
  c6_info[12].fileLength = 0U;
  c6_info[12].fileTime1 = 0U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[13].name = "and";
  c6_info[13].dominantType = "logical";
  c6_info[13].resolved = "[B]and";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c6_info[14].name = "mtimes";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[14].fileLength = 2336U;
  c6_info[14].fileTime1 = 1213662890U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[15].name = "isempty";
  c6_info[15].dominantType = "logical";
  c6_info[15].resolved = "[B]isempty";
  c6_info[15].fileLength = 0U;
  c6_info[15].fileTime1 = 0U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[16].name = "nan";
  c6_info[16].dominantType = "";
  c6_info[16].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c6_info[16].fileLength = 474U;
  c6_info[16].fileTime1 = 1192491944U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context = "";
  c6_info[17].name = "sum";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c6_info[17].fileLength = 2854U;
  c6_info[17].fileTime1 = 1213662886U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[18].name = "real";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved = "[B]real";
  c6_info[18].fileLength = 0U;
  c6_info[18].fileTime1 = 0U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c6_info[19].name = "eps";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[19].fileLength = 1342U;
  c6_info[19].fileTime1 = 1210895846U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[20].name = "isinf";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[20].fileLength = 472U;
  c6_info[20].fileTime1 = 1192491934U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[21].name = "eq";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved = "[B]eq";
  c6_info[21].fileLength = 0U;
  c6_info[21].fileTime1 = 0U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[22].name = "gt";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved = "[B]gt";
  c6_info[22].fileLength = 0U;
  c6_info[22].fileTime1 = 0U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[23].name = "ge";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[B]ge";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/maxabs";
  c6_info[24].name = "abs";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[24].fileLength = 538U;
  c6_info[24].fileTime1 = 1203473128U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c6_info[25].name = "realmax";
  c6_info[25].dominantType = "char";
  c6_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c6_info[25].fileLength = 498U;
  c6_info[25].fileTime1 = 1192491950U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[26].name = "intmax";
  c6_info[26].dominantType = "char";
  c6_info[26].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[26].fileLength = 1535U;
  c6_info[26].fileTime1 = 1192491928U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[27].name = "zeros";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved = "[B]zeros";
  c6_info[27].fileLength = 0U;
  c6_info[27].fileTime1 = 0U;
  c6_info[27].fileTime2 = 0U;
  c6_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[28].name = "isnumeric";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved = "[B]isnumeric";
  c6_info[28].fileLength = 0U;
  c6_info[28].fileTime1 = 0U;
  c6_info[28].fileTime2 = 0U;
  c6_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c6_info[29].name = "eml_all_or_any";
  c6_info[29].dominantType = "char";
  c6_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[29].fileLength = 3423U;
  c6_info[29].fileTime1 = 1213662886U;
  c6_info[29].fileTime2 = 0U;
  c6_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c6_info[30].name = "floor";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[30].fileLength = 332U;
  c6_info[30].fileTime1 = 1203473224U;
  c6_info[30].fileTime2 = 0U;
  c6_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[31].name = "isa";
  c6_info[31].dominantType = "double";
  c6_info[31].resolved = "[B]isa";
  c6_info[31].fileLength = 0U;
  c6_info[31].fileTime1 = 0U;
  c6_info[31].fileTime2 = 0U;
  c6_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c6_info[32].name = "plus";
  c6_info[32].dominantType = "double";
  c6_info[32].resolved = "[B]plus";
  c6_info[32].fileLength = 0U;
  c6_info[32].fileTime1 = 0U;
  c6_info[32].fileTime2 = 0U;
  c6_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c6_info[33].name = "isstruct";
  c6_info[33].dominantType = "double";
  c6_info[33].resolved = "[B]isstruct";
  c6_info[33].fileLength = 0U;
  c6_info[33].fileTime1 = 0U;
  c6_info[33].fileTime2 = 0U;
  c6_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c6_info[34].name = "double";
  c6_info[34].dominantType = "double";
  c6_info[34].resolved = "[B]double";
  c6_info[34].fileLength = 0U;
  c6_info[34].fileTime1 = 0U;
  c6_info[34].fileTime2 = 0U;
  c6_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[35].name = "ischar";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved = "[B]ischar";
  c6_info[35].fileLength = 0U;
  c6_info[35].fileTime1 = 0U;
  c6_info[35].fileTime2 = 0U;
  c6_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c6_info[36].name = "eml_scalexp_compatible";
  c6_info[36].dominantType = "double";
  c6_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c6_info[36].fileLength = 502U;
  c6_info[36].fileTime1 = 1208205258U;
  c6_info[36].fileTime2 = 0U;
  c6_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[37].name = "assert";
  c6_info[37].dominantType = "char";
  c6_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c6_info[37].fileLength = 2684U;
  c6_info[37].fileTime1 = 1210895856U;
  c6_info[37].fileTime2 = 0U;
  c6_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[38].name = "lt";
  c6_info[38].dominantType = "double";
  c6_info[38].resolved = "[B]lt";
  c6_info[38].fileLength = 0U;
  c6_info[38].fileTime1 = 0U;
  c6_info[38].fileTime2 = 0U;
  c6_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[39].name = "mpower";
  c6_info[39].dominantType = "double";
  c6_info[39].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[39].fileLength = 3547U;
  c6_info[39].fileTime1 = 1213662888U;
  c6_info[39].fileTime2 = 0U;
  c6_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[40].name = "eml_error";
  c6_info[40].dominantType = "char";
  c6_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[40].fileLength = 315U;
  c6_info[40].fileTime1 = 1213662886U;
  c6_info[40].fileTime2 = 0U;
  c6_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[41].name = "eml_isequal_core";
  c6_info[41].dominantType = "double";
  c6_info[41].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c6_info[41].fileLength = 3543U;
  c6_info[41].fileTime1 = 1213662886U;
  c6_info[41].fileTime2 = 0U;
  c6_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c6_info[42].name = "eml_assert_valid_size_arg";
  c6_info[42].dominantType = "double";
  c6_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[42].fileLength = 2835U;
  c6_info[42].fileTime1 = 1210895844U;
  c6_info[42].fileTime2 = 0U;
  c6_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c6_info[43].name = "true";
  c6_info[43].dominantType = "";
  c6_info[43].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c6_info[43].fileLength = 237U;
  c6_info[43].fileTime1 = 1192491962U;
  c6_info[43].fileTime2 = 0U;
  c6_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c6_info[44].name = "ne";
  c6_info[44].dominantType = "double";
  c6_info[44].resolved = "[B]ne";
  c6_info[44].fileLength = 0U;
  c6_info[44].fileTime1 = 0U;
  c6_info[44].fileTime2 = 0U;
  c6_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[45].name = "class";
  c6_info[45].dominantType = "double";
  c6_info[45].resolved = "[B]class";
  c6_info[45].fileLength = 0U;
  c6_info[45].fileTime1 = 0U;
  c6_info[45].fileTime2 = 0U;
  c6_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[46].name = "ndims";
  c6_info[46].dominantType = "double";
  c6_info[46].resolved = "[B]ndims";
  c6_info[46].fileLength = 0U;
  c6_info[46].fileTime1 = 0U;
  c6_info[46].fileTime2 = 0U;
  c6_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[47].name = "strcmp";
  c6_info[47].dominantType = "char";
  c6_info[47].resolved = "[B]strcmp";
  c6_info[47].fileLength = 0U;
  c6_info[47].fileTime1 = 0U;
  c6_info[47].fileTime2 = 0U;
  c6_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[48].name = "realmin";
  c6_info[48].dominantType = "";
  c6_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[48].fileLength = 475U;
  c6_info[48].fileTime1 = 1192491952U;
  c6_info[48].fileTime2 = 0U;
  c6_info[49].context = "";
  c6_info[49].name = "uminus";
  c6_info[49].dominantType = "double";
  c6_info[49].resolved = "[B]uminus";
  c6_info[49].fileLength = 0U;
  c6_info[49].fileTime1 = 0U;
  c6_info[49].fileTime2 = 0U;
  c6_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[50].name = "isnan";
  c6_info[50].dominantType = "double";
  c6_info[50].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[50].fileLength = 472U;
  c6_info[50].fileTime1 = 1192491936U;
  c6_info[50].fileTime2 = 0U;
  c6_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c6_info[51].name = "isequal";
  c6_info[51].dominantType = "double";
  c6_info[51].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[51].fileLength = 157U;
  c6_info[51].fileTime1 = 1210895846U;
  c6_info[51].fileTime2 = 0U;
  c6_info[52].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c6_info[52].name = "isfinite";
  c6_info[52].dominantType = "double";
  c6_info[52].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[52].fileLength = 341U;
  c6_info[52].fileTime1 = 1192491934U;
  c6_info[52].fileTime2 = 0U;
  c6_info[53].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[53].name = "islogical";
  c6_info[53].dominantType = "double";
  c6_info[53].resolved = "[B]islogical";
  c6_info[53].fileLength = 0U;
  c6_info[53].fileTime1 = 0U;
  c6_info[53].fileTime2 = 0U;
  c6_info[54].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[54].name = "eml_index_class";
  c6_info[54].dominantType = "";
  c6_info[54].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[54].fileLength = 909U;
  c6_info[54].fileTime1 = 1192491982U;
  c6_info[54].fileTime2 = 0U;
  c6_info[55].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[55].name = "eml_alloc";
  c6_info[55].dominantType = "double";
  c6_info[55].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c6_info[55].fileLength = 2627U;
  c6_info[55].fileTime1 = 1213662886U;
  c6_info[55].fileTime2 = 0U;
  c6_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[56].name = "eml_set_singleton_dim";
  c6_info[56].dominantType = "double";
  c6_info[56].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c6_info[56].fileLength = 398U;
  c6_info[56].fileTime1 = 1209356038U;
  c6_info[56].fileTime2 = 0U;
  c6_info[57].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[57].name = "size";
  c6_info[57].dominantType = "double";
  c6_info[57].resolved = "[B]size";
  c6_info[57].fileLength = 0U;
  c6_info[57].fileTime1 = 0U;
  c6_info[57].fileTime2 = 0U;
  c6_info[58].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c6_info[58].name = "all";
  c6_info[58].dominantType = "logical";
  c6_info[58].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c6_info[58].fileLength = 400U;
  c6_info[58].fileTime1 = 1192492104U;
  c6_info[58].fileTime2 = 0U;
  c6_info[59].context = "";
  c6_info[59].name = "minus";
  c6_info[59].dominantType = "double";
  c6_info[59].resolved = "[B]minus";
  c6_info[59].fileLength = 0U;
  c6_info[59].fileTime1 = 0U;
  c6_info[59].fileTime2 = 0U;
  c6_info[60].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[60].name = "eml_guarded_nan";
  c6_info[60].dominantType = "";
  c6_info[60].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[60].fileLength = 485U;
  c6_info[60].fileTime1 = 1192491980U;
  c6_info[60].fileTime2 = 0U;
  c6_info[61].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[61].name = "isreal";
  c6_info[61].dominantType = "double";
  c6_info[61].resolved = "[B]isreal";
  c6_info[61].fileLength = 0U;
  c6_info[61].fileTime1 = 0U;
  c6_info[61].fileTime2 = 0U;
  c6_info[62].context = "";
  c6_info[62].name = "colon";
  c6_info[62].dominantType = "double";
  c6_info[62].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[62].fileLength = 7324U;
  c6_info[62].fileTime1 = 1197325946U;
  c6_info[62].fileTime2 = 0U;
  c6_info[63].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[63].name = "eml_scalar_abs";
  c6_info[63].dominantType = "double";
  c6_info[63].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[63].fileLength = 461U;
  c6_info[63].fileTime1 = 1203473160U;
  c6_info[63].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc6_aeroutilslibInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_aeroutilslib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3633835843U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3891520169U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3130091345U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(941849050U);
}

mxArray *sf_c6_aeroutilslib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2606197940U);
    pr[1] = (double)(3220315268U);
    pr[2] = (double)(4169516728U);
    pr[3] = (double)(3645010684U);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc6_aeroutilslibInstanceStruct *chartInstance;
  chartInstance = (SFc6_aeroutilslibInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_aeroutilslibMachineNumber_,
           6,
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
          init_script_number_translation(_aeroutilslibMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_aeroutilslibMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_aeroutilslibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"u",0,
                              c6_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(2,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"p",0,c6_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,144);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c6_u;
          real_T *c6_y;
          c6_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_y);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c6_p);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_aeroutilslibMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c6_aeroutilslib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_aeroutilslibInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*)
    chartInstanceVar);
  initialize_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_aeroutilslib(void *chartInstanceVar)
{
  enable_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_aeroutilslib(void *chartInstanceVar)
{
  disable_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_aeroutilslib(void *chartInstanceVar)
{
  sf_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c6_aeroutilslib(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c6_aeroutilslib
    ((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c6_aeroutilslib(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c6_aeroutilslib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_aeroutilslib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_aeroutilslib((SFc6_aeroutilslibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_aeroutilslib(SimStruct *S)
{
  /* Actual parameters from chart:
     p
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for p*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("aeroutilslib","main_sim_adapt_Gref_SP",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("aeroutilslib","main_sim_adapt_Gref_SP",6,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("aeroutilslib",
      "main_sim_adapt_Gref_SP",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"aeroutilslib",
        "main_sim_adapt_Gref_SP",6,1);
      sf_mark_chart_reusable_outputs(S,"aeroutilslib","main_sim_adapt_Gref_SP",6,
        1);
    }

    sf_set_rtw_dwork_info(S,"aeroutilslib","main_sim_adapt_Gref_SP",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3197514932U));
  ssSetChecksum1(S,(2334305348U));
  ssSetChecksum2(S,(799015008U));
  ssSetChecksum3(S,(871674743U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_aeroutilslib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "aeroutilslib", "main_sim_adapt_Gref_SP",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_aeroutilslib(SimStruct *S)
{
  SFc6_aeroutilslibInstanceStruct *chartInstance;
  chartInstance = (SFc6_aeroutilslibInstanceStruct *)malloc(sizeof
    (SFc6_aeroutilslibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_aeroutilslib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_aeroutilslib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_aeroutilslib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_aeroutilslib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_aeroutilslib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_aeroutilslib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_aeroutilslib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_aeroutilslib;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_aeroutilslib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_aeroutilslib;
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

void c6_aeroutilslib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_aeroutilslib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_aeroutilslib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_aeroutilslib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_aeroutilslib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
