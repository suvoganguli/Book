/* Include files */

#include "main_sim_adapt_refsp_sfun.h"
#include "c2_main_sim_adapt_refsp.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "main_sim_adapt_refsp_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_main_sim_adapt_refspInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_main_sim_adapt_refsp(void);
static void initialize_params_c2_main_sim_adapt_refsp(void);
static void enable_c2_main_sim_adapt_refsp(void);
static void disable_c2_main_sim_adapt_refsp(void);
static void update_debugger_state_c2_main_sim_adapt_refsp(void);
static const mxArray *get_sim_state_c2_main_sim_adapt_refsp(void);
static void set_sim_state_c2_main_sim_adapt_refsp(const mxArray *c2_st);
static void finalize_c2_main_sim_adapt_refsp(void);
static void sf_c2_main_sim_adapt_refsp(void);
static void c2_c2_main_sim_adapt_refsp(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_norm_vec(real_T c2_in[3]);
static void c2_eml_error(void);
static void c2_eml_warning(void);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[90]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[90]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_main_sim_adapt_refsp(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_main_sim_adapt_refsp = 0U;
}

static void initialize_params_c2_main_sim_adapt_refsp(void)
{
}

static void enable_c2_main_sim_adapt_refsp(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_main_sim_adapt_refsp(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c2_main_sim_adapt_refsp(void)
{
}

static const mxArray *get_sim_state_c2_main_sim_adapt_refsp(void)
{
  return NULL;
}

static void set_sim_state_c2_main_sim_adapt_refsp(const mxArray *c2_st)
{
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_main_sim_adapt_refsp(void)
{
}

static void sf_c2_main_sim_adapt_refsp(void)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  uint8_T c2_previousEvent;
  real_T *c2_ulim;
  real_T *c2_llim;
  real_T *c2_rcs_cmd;
  real_T *c2_minerr;
  real_T *c2_scale;
  real_T *c2_err_thresh;
  real_T *c2_rcs_use_in;
  real_T (*c2_cvd_actual)[3];
  real_T (*c2_cvd_des)[3];
  real_T (*c2_wght_cv)[3];
  real_T (*c2_Bmat)[3];
  c2_minerr = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_ulim = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_rcs_cmd = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_cvd_actual = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c2_Bmat = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c2_rcs_use_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c2_cvd_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
  c2_scale = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_wght_cv = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c2_err_thresh = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c2_llim = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_Bmat)[c2_i0], 0U);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_wght_cv)[c2_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_ulim, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_llim, 3U);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_cvd_des)[c2_i2], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_rcs_cmd, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_minerr, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_scale, 7U);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_cvd_actual)[c2_i3], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_err_thresh, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_rcs_use_in, 10U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_main_sim_adapt_refsp();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_main_sim_adapt_refspMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c2_c2_main_sim_adapt_refsp(void)
{
  int32_T c2_i4;
  real_T c2_Bmat[3];
  int32_T c2_i5;
  real_T c2_wght_cv[3];
  real_T c2_ulim;
  real_T c2_llim;
  int32_T c2_i6;
  real_T c2_cvd_des[3];
  real_T c2_err_thresh;
  real_T c2_rcs_use_in;
  real_T c2_nargout = 4.0;
  real_T c2_nargin = 7.0;
  real_T c2_err;
  real_T c2_cvd_ex[3];
  real_T c2_cvd_trial[3];
  real_T c2_rcson;
  real_T c2_i;
  real_T c2_rcs_use;
  uint32_T c2_rcs_use_tmp;
  uint32_T c2_rcs_use_all;
  uint32_T c2_bulim;
  uint32_T c2_bllim;
  real_T c2_powersof2;
  real_T c2_normsq_cvd_trial;
  real_T c2_scale_trial;
  real_T c2_nrcs;
  real_T c2_rcs_quant;
  real_T c2_cvd_actual[3];
  real_T c2_scale;
  real_T c2_minerr;
  real_T c2_rcs_cmd;
  int32_T c2_i7;
  real_T c2_a[3];
  real_T c2_b;
  int32_T c2_i8;
  int32_T c2_i9;
  real_T c2_b_cvd_actual[3];
  int32_T c2_i10;
  real_T c2_v[3];
  int32_T c2_i11;
  real_T c2_b_a[9];
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_c_a;
  int32_T c2_c;
  int32_T c2_i12;
  real_T c2_b_b[3];
  int32_T c2_i13;
  real_T c2_A[9];
  int32_T c2_i14;
  real_T c2_B[3];
  int32_T c2_i15;
  real_T c2_b_A[9];
  int32_T c2_i16;
  real_T c2_b_B[3];
  int32_T c2_i17;
  real_T c2_c_A[9];
  int32_T c2_i18;
  real_T c2_c_B[3];
  int32_T c2_i19;
  real_T c2_y[3];
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  real_T c2_c_b;
  real_T c2_b_y;
  real_T c2_d0;
  real_T c2_d1;
  real_T c2_d2;
  uint32_T c2_u0;
  real_T c2_d_b;
  real_T c2_c_y;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  uint32_T c2_u1;
  uint32_T c2_e_b;
  uint32_T c2_d_a;
  uint32_T c2_f_b;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  boolean_T c2_g_b;
  boolean_T c2_b0;
  boolean_T c2_d_y;
  int32_T c2_i23;
  real_T c2_e_a[3];
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  real_T c2_b_cvd_ex[3];
  int32_T c2_i27;
  real_T c2_d_x[3];
  int32_T c2_i28;
  real_T c2_e_y[3];
  real_T c2_k;
  real_T c2_b_k;
  int32_T c2_i29;
  real_T c2_e_x[3];
  int32_T c2_i30;
  real_T c2_f_y[3];
  int32_T c2_i31;
  real_T c2_f_x[3];
  int32_T c2_i32;
  real_T c2_g_y[3];
  int32_T c2_i33;
  int32_T c2_i34;
  real_T *c2_b_scale;
  real_T *c2_b_minerr;
  real_T *c2_b_rcs_cmd;
  real_T *c2_b_rcs_use_in;
  real_T *c2_b_err_thresh;
  real_T *c2_b_llim;
  real_T *c2_b_ulim;
  real_T (*c2_c_cvd_actual)[3];
  real_T (*c2_b_cvd_des)[3];
  real_T (*c2_b_wght_cv)[3];
  real_T (*c2_b_Bmat)[3];
  c2_b_minerr = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_ulim = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_b_rcs_cmd = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_c_cvd_actual = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c2_b_Bmat = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_rcs_use_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c2_b_cvd_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
  c2_b_scale = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_b_wght_cv = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_err_thresh = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c2_b_llim = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4 = c2_i4 + 1) {
    c2_Bmat[c2_i4] = (*c2_b_Bmat)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    c2_wght_cv[c2_i5] = (*c2_b_wght_cv)[c2_i5];
  }

  c2_ulim = *c2_b_ulim;
  c2_llim = *c2_b_llim;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6 = c2_i6 + 1) {
    c2_cvd_des[c2_i6] = (*c2_b_cvd_des)[c2_i6];
  }

  c2_err_thresh = *c2_b_err_thresh;
  c2_rcs_use_in = *c2_b_rcs_use_in;
  sf_debug_symbol_scope_push(28U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("err", &c2_err, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("cvd_ex", &c2_cvd_ex, c2_sf_marshall);
  sf_debug_symbol_scope_add("cvd_trial", &c2_cvd_trial, c2_sf_marshall);
  sf_debug_symbol_scope_add("rcson", &c2_rcson, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("i", &c2_i, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("rcs_use", &c2_rcs_use, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("rcs_use_tmp", &c2_rcs_use_tmp, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("rcs_use_all", &c2_rcs_use_all, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("bulim", &c2_bulim, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("bllim", &c2_bllim, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("powersof2", &c2_powersof2, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("normsq_cvd_trial", &c2_normsq_cvd_trial,
    c2_b_sf_marshall);
  sf_debug_symbol_scope_add("scale_trial", &c2_scale_trial, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("nrcs", &c2_nrcs, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("rcs_quant", &c2_rcs_quant, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("cvd_actual", &c2_cvd_actual, c2_sf_marshall);
  sf_debug_symbol_scope_add("scale", &c2_scale, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("minerr", &c2_minerr, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("rcs_cmd", &c2_rcs_cmd, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("rcs_use_in", &c2_rcs_use_in, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("err_thresh", &c2_err_thresh, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("cvd_des", &c2_cvd_des, c2_sf_marshall);
  sf_debug_symbol_scope_add("llim", &c2_llim, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("ulim", &c2_ulim, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("wght_cv", &c2_wght_cv, c2_sf_marshall);
  sf_debug_symbol_scope_add("Bmat", &c2_Bmat, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c2_rcs_quant = 0.0;
  _SFD_EML_CALL(0,4);
  c2_scale = 1.0;
  _SFD_EML_CALL(0,6);
  c2_nrcs = 1.0;
  _SFD_EML_CALL(0,9);
  CV_EML_IF(0, 0, c2_nrcs == 6.0);
  _SFD_EML_CALL(0,26);
  c2_rcs_cmd = c2_llim;
  _SFD_EML_CALL(0,27);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7 = c2_i7 + 1) {
    c2_a[c2_i7] = c2_Bmat[c2_i7];
  }

  c2_b = c2_rcs_cmd;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_cvd_actual[c2_i8] = c2_a[c2_i8] * c2_b;
  }

  _SFD_EML_CALL(0,28);
  for (c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_b_cvd_actual[c2_i9] = (c2_cvd_actual[c2_i9] - c2_cvd_des[c2_i9]) *
      c2_wght_cv[c2_i9];
  }

  c2_minerr = c2_norm_vec(c2_b_cvd_actual);
  _SFD_EML_CALL(0,30);
  if (CV_EML_IF(0, 2, c2_minerr <= c2_err_thresh)) {
  } else {
    _SFD_EML_CALL(0,34);
    for (c2_i10 = 0; c2_i10 < 3; c2_i10 = c2_i10 + 1) {
      c2_v[c2_i10] = c2_wght_cv[c2_i10];
    }

    for (c2_i11 = 0; c2_i11 < 9; c2_i11 = c2_i11 + 1) {
      c2_b_a[c2_i11] = 0.0;
    }

    for (c2_j = 1; c2_j < 4; c2_j = c2_j + 1) {
      c2_b_j = c2_j;
      c2_c_a = c2_b_j;
      c2_c = c2_c_a;
      c2_b_a[(_SFD_EML_ARRAY_BOUNDS_CHECK("d", _SFD_INTEGER_CHECK("j", (real_T)
                c2_b_j), 1, 3, 1, 0) - 1) + 3 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("d", _SFD_INTEGER_CHECK("", (real_T)c2_c), 1,
        3, 2, 0) - 1)] = c2_v[_SFD_EML_ARRAY_BOUNDS_CHECK("v",
        _SFD_INTEGER_CHECK("j", (real_T)c2_b_j), 1, 3, 1, 0) - 1];
    }

    for (c2_i12 = 0; c2_i12 < 3; c2_i12 = c2_i12 + 1) {
      c2_b_b[c2_i12] = c2_Bmat[c2_i12];
    }

    for (c2_i13 = 0; c2_i13 < 9; c2_i13 = c2_i13 + 1) {
      c2_A[c2_i13] = c2_b_a[c2_i13];
    }

    for (c2_i14 = 0; c2_i14 < 3; c2_i14 = c2_i14 + 1) {
      c2_B[c2_i14] = c2_b_b[c2_i14];
    }

    for (c2_i15 = 0; c2_i15 < 9; c2_i15 = c2_i15 + 1) {
      c2_b_A[c2_i15] = c2_A[c2_i15];
    }

    for (c2_i16 = 0; c2_i16 < 3; c2_i16 = c2_i16 + 1) {
      c2_b_B[c2_i16] = c2_B[c2_i16];
    }

    for (c2_i17 = 0; c2_i17 < 9; c2_i17 = c2_i17 + 1) {
      c2_c_A[c2_i17] = c2_b_A[c2_i17];
    }

    for (c2_i18 = 0; c2_i18 < 3; c2_i18 = c2_i18 + 1) {
      c2_c_B[c2_i18] = c2_b_B[c2_i18];
    }

    for (c2_i19 = 0; c2_i19 < 3; c2_i19 = c2_i19 + 1) {
      c2_y[c2_i19] = 0.0;
      for (c2_i20 = 0; c2_i20 < 3; c2_i20 = c2_i20 + 1) {
        c2_y[c2_i19] = c2_y[c2_i19] + c2_c_A[c2_i19 + 3 * c2_i20] *
          c2_c_B[c2_i20];
      }
    }

    for (c2_i21 = 0; c2_i21 < 3; c2_i21 = c2_i21 + 1) {
      c2_Bmat[c2_i21] = c2_y[c2_i21];
    }

    _SFD_EML_CALL(0,35);
    for (c2_i22 = 0; c2_i22 < 3; c2_i22 = c2_i22 + 1) {
      c2_cvd_des[c2_i22] = c2_wght_cv[c2_i22] * c2_cvd_des[c2_i22];
    }

    _SFD_EML_CALL(0,37);
    c2_scale_trial = 1.0;
    _SFD_EML_CALL(0,38);
    c2_normsq_cvd_trial = 0.0;
    _SFD_EML_CALL(0,40);
    c2_powersof2 = 1.0;
    _SFD_EML_CALL(0,41);
    c2_c_b = c2_llim;
    c2_b_y = c2_c_b;
    c2_d0 = c2_b_y;
    c2_d1 = c2_d0;
    c2_d1 = c2_d1 < 0.0 ? muDoubleScalarCeil(c2_d1 - 0.5) : muDoubleScalarFloor
      (c2_d1 + 0.5);
    c2_d2 = c2_d1;
    if (c2_d2 < 4.294967296E+009) {
      if (c2_d2 >= 0.0) {
        c2_u0 = (uint32_T)c2_d2;
      } else {
        c2_u0 = 0U;
      }
    } else if (c2_d2 >= 4.294967296E+009) {
      c2_u0 = MAX_uint32_T;
    } else {
      c2_u0 = 0U;
    }

    c2_bllim = c2_u0;
    _SFD_EML_CALL(0,42);
    c2_d_b = c2_ulim;
    c2_c_y = c2_d_b;
    c2_d3 = c2_c_y;
    c2_d4 = c2_d3;
    c2_d4 = c2_d4 < 0.0 ? muDoubleScalarCeil(c2_d4 - 0.5) : muDoubleScalarFloor
      (c2_d4 + 0.5);
    c2_d5 = c2_d4;
    if (c2_d5 < 4.294967296E+009) {
      if (c2_d5 >= 0.0) {
        c2_u1 = (uint32_T)c2_d5;
      } else {
        c2_u1 = 0U;
      }
    } else if (c2_d5 >= 4.294967296E+009) {
      c2_u1 = MAX_uint32_T;
    } else {
      c2_u1 = 0U;
    }

    c2_bulim = c2_u1;
    _SFD_EML_CALL(0,43);
    c2_rcs_use_all = 1U;
    _SFD_EML_CALL(0,44);
    c2_e_b = c2_bllim;
    c2_rcs_use_tmp = c2_e_b | 1U;
    _SFD_EML_CALL(0,45);
    c2_d_a = c2_rcs_use_tmp;
    c2_f_b = c2_bulim;
    c2_rcs_use_tmp = c2_d_a & c2_f_b;
    _SFD_EML_CALL(0,46);
    c2_rcs_use = c2_rcs_use_in * (real_T)(c2_rcs_use_tmp == c2_rcs_use_all);
    _SFD_EML_CALL(0,48);
    c2_x = c2_rcs_use;
    c2_b_x = c2_x;
    if (c2_b_x == 0.0) {
    } else {
      c2_c_x = c2_b_x;
      c2_g_b = rtIsNaN(c2_c_x);
      if (c2_g_b) {
      } else {
        c2_b0 = false;
        goto label_1;
      }
    }

    c2_b0 = true;
   label_1:
    ;
    c2_d_y = !c2_b0;
    if (CV_EML_IF(0, 3, CV_EML_MCDC(0, 0, !CV_EML_COND(0, 0, c2_d_y)))) {
    } else {
      c2_i = 1.0;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,54);
      if (CV_EML_IF(0, 4, CV_EML_MCDC(0, 1, !(CV_EML_COND(0, 1, c2_rcs_use !=
              0.0) != 0.0)))) {
      } else {
        _SFD_EML_CALL(0,58);
        c2_rcson = 1.0;
        _SFD_EML_CALL(0,59);
        for (c2_i23 = 0; c2_i23 < 3; c2_i23 = c2_i23 + 1) {
          c2_e_a[c2_i23] = c2_Bmat[c2_i23];
        }

        for (c2_i24 = 0; c2_i24 < 3; c2_i24 = c2_i24 + 1) {
          c2_cvd_trial[c2_i24] = c2_e_a[c2_i24];
        }

        /*  optional scaling */
        _SFD_EML_CALL(0,62);
        CV_EML_IF(0, 5, false);
        _SFD_EML_CALL(0,77);
        for (c2_i25 = 0; c2_i25 < 3; c2_i25 = c2_i25 + 1) {
          c2_cvd_ex[c2_i25] = c2_cvd_trial[c2_i25] - c2_cvd_des[c2_i25];
        }

        _SFD_EML_CALL(0,78);
        for (c2_i26 = 0; c2_i26 < 3; c2_i26 = c2_i26 + 1) {
          c2_b_cvd_ex[c2_i26] = c2_cvd_ex[c2_i26];
        }

        c2_err = c2_norm_vec(c2_b_cvd_ex);
        _SFD_EML_CALL(0,79);
        if (CV_EML_IF(0, 8, c2_err < c2_minerr)) {
          _SFD_EML_CALL(0,80);
          c2_scale = 1.0;
          _SFD_EML_CALL(0,81);
          c2_rcs_cmd = 1.0;
          _SFD_EML_CALL(0,82);
          c2_minerr = c2_err;
          _SFD_EML_CALL(0,83);
          for (c2_i27 = 0; c2_i27 < 3; c2_i27 = c2_i27 + 1) {
            c2_d_x[c2_i27] = c2_cvd_trial[c2_i27];
          }

          for (c2_i28 = 0; c2_i28 < 3; c2_i28 = c2_i28 + 1) {
            c2_e_y[c2_i28] = c2_wght_cv[c2_i28];
          }

          c2_k = 1.0;
         label_2:
          ;
          if (c2_k <= 3.0) {
            c2_b_k = c2_k;
            if (c2_e_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
                 _SFD_INTEGER_CHECK("k", c2_b_k), 1, 3, 1, 0) - 1] == 0.0) {
              c2_eml_warning();
            } else {
              c2_k = c2_k + 1.0;
              goto label_2;
            }
          }

          for (c2_i29 = 0; c2_i29 < 3; c2_i29 = c2_i29 + 1) {
            c2_e_x[c2_i29] = c2_d_x[c2_i29];
          }

          for (c2_i30 = 0; c2_i30 < 3; c2_i30 = c2_i30 + 1) {
            c2_f_y[c2_i30] = c2_e_y[c2_i30];
          }

          for (c2_i31 = 0; c2_i31 < 3; c2_i31 = c2_i31 + 1) {
            c2_f_x[c2_i31] = c2_e_x[c2_i31];
          }

          for (c2_i32 = 0; c2_i32 < 3; c2_i32 = c2_i32 + 1) {
            c2_g_y[c2_i32] = c2_f_y[c2_i32];
          }

          for (c2_i33 = 0; c2_i33 < 3; c2_i33 = c2_i33 + 1) {
            c2_cvd_actual[c2_i33] = c2_f_x[c2_i33] / c2_g_y[c2_i33];
          }
        }
      }

      CV_EML_FOR(0, 0, 0);
    }
  }

  _SFD_EML_CALL(0,-83);
  sf_debug_symbol_scope_pop();
  *c2_b_rcs_cmd = c2_rcs_cmd;
  *c2_b_minerr = c2_minerr;
  *c2_b_scale = c2_scale;
  for (c2_i34 = 0; c2_i34 < 3; c2_i34 = c2_i34 + 1) {
    (*c2_c_cvd_actual)[c2_i34] = c2_cvd_actual[c2_i34];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_norm_vec(real_T c2_in[3])
{
  real_T c2_out;
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 1.0;
  int32_T c2_i35;
  real_T c2_a[3];
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_ak;
  real_T c2_x[3];
  int32_T c2_i36;
  real_T c2_b_x[3];
  real_T c2_c_x;
  real_T c2_d_x;
  int32_T c2_c_k;
  int32_T c2_d_k;
  real_T c2_e_x;
  real_T c2_r;
  real_T c2_f_x;
  real_T c2_g_x;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("out", &c2_out, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("in", c2_in, c2_sf_marshall);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0,89);
  for (c2_i35 = 0; c2_i35 < 3; c2_i35 = c2_i35 + 1) {
    c2_a[c2_i35] = c2_in[c2_i35];
  }

  for (c2_k = 1.0; c2_k <= 3.0; c2_k = c2_k + 1.0) {
    c2_b_k = c2_k;
    c2_ak = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK(
      "k", c2_b_k), 1, 3, 1, 0) - 1];
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k",
      c2_b_k), 1, 3, 1, 0) - 1] = muDoubleScalarPower(c2_ak, 2.0);
  }

  for (c2_i36 = 0; c2_i36 < 3; c2_i36 = c2_i36 + 1) {
    c2_b_x[c2_i36] = c2_x[c2_i36];
  }

  c2_c_x = c2_b_x[0];
  c2_d_x = c2_c_x;
  for (c2_c_k = 2; c2_c_k < 4; c2_c_k = c2_c_k + 1) {
    c2_d_k = c2_c_k;
    c2_e_x = c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("k",
      (real_T)c2_d_k), 1, 3, 1, 0) - 1];
    c2_r = c2_e_x;
    c2_d_x = c2_d_x + c2_r;
  }

  c2_out = c2_d_x;
  if (c2_out < 0.0) {
    c2_eml_error();
  }

  c2_f_x = c2_out;
  c2_g_x = c2_f_x;
  c2_g_x = muDoubleScalarSqrt(c2_g_x);
  c2_out = c2_g_x;
  _SFD_EML_CALL(0,-89);
  sf_debug_symbol_scope_pop();
  return c2_out;
}

static void c2_eml_error(void)
{
  int32_T c2_i37;
  static char_T c2_varargin_1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  int32_T c2_i38;
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
  for (c2_i37 = 0; c2_i37 < 31; c2_i37 = c2_i37 + 1) {
    c2_u[c2_i37] = c2_varargin_1[c2_i37];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c2_i38 = 0; c2_i38 < 77; c2_i38 = c2_i38 + 1) {
    c2_b_u[c2_i38] = c2_varargin_2[c2_i38];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static void c2_eml_warning(void)
{
  int32_T c2_i39;
  static char_T c2_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c2_u[19];
  const mxArray *c2_y = NULL;
  int32_T c2_i40;
  static char_T c2_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c2_b_u[15];
  const mxArray *c2_b_y = NULL;
  for (c2_i39 = 0; c2_i39 < 19; c2_i39 = c2_i39 + 1) {
    c2_u[c2_i39] = c2_varargin_1[c2_i39];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c2_i40 = 0; c2_i40 < 15; c2_i40 = c2_i40 + 1) {
    c2_b_u[c2_i40] = c2_varargin_2[c2_i40];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i41;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i41 = 0; c2_i41 < 3; c2_i41 = c2_i41 + 1) {
    c2_b_u[c2_i41] = (*((real_T (*)[3])c2_u))[c2_i41];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint32_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 7, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_main_sim_adapt_refsp_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[90];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i42;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 90));
  for (c2_i42 = 0; c2_i42 < 90; c2_i42 = c2_i42 + 1) {
    c2_r0 = &c2_info[c2_i42];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i42);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i42);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i42);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i42);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i42);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i42
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i42
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[90])
{
  c2_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[0].name = "plus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]plus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "diag";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c2_info[1].fileLength = 2369U;
  c2_info[1].fileTime1 = 1210895844U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[2].name = "strcmp";
  c2_info[2].dominantType = "char";
  c2_info[2].resolved = "[B]strcmp";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c2_info[3].name = "realmax";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[3].fileLength = 498U;
  c2_info[3].fileTime1 = 1192491950U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].name = "assert";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c2_info[4].fileLength = 2684U;
  c2_info[4].fileTime1 = 1210895856U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c2_info[5].name = "floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].fileLength = 332U;
  c2_info[5].fileTime1 = 1203473224U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "uint32";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]uint32";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c2_info[7].name = "eml_zeros";
  c2_info[7].dominantType = "int32";
  c2_info[7].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zeros.m";
  c2_info[7].fileLength = 1083U;
  c2_info[7].fileTime1 = 1213662888U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[8].name = "isfinite";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[8].fileLength = 341U;
  c2_info[8].fileTime1 = 1192491934U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "eml_div";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[9].fileLength = 4254U;
  c2_info[9].fileTime1 = 1192491972U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[10].name = "isreal";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isreal";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[11].name = "eml_guarded_nan";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[11].fileLength = 485U;
  c2_info[11].fileTime1 = 1192491980U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[12].name = "eml_index_times";
  c2_info[12].dominantType = "int32";
  c2_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[12].fileLength = 280U;
  c2_info[12].fileTime1 = 1192491988U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[13].name = "ischar";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved = "[B]ischar";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[14].name = "isequal";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[14].fileLength = 157U;
  c2_info[14].fileTime1 = 1210895846U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[15].name = "ge";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]ge";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[16].name = "int32";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]int32";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[17].name = "isnumeric";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]isnumeric";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[18].name = "isstruct";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]isstruct";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[19].name = "islogical";
  c2_info[19].dominantType = "logical";
  c2_info[19].resolved = "[B]islogical";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[20].name = "eml_scalar_abs";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[20].fileLength = 461U;
  c2_info[20].fileTime1 = 1203473160U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[21].name = "eml_all_or_any";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[21].fileLength = 3423U;
  c2_info[21].fileTime1 = 1213662886U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[22].name = "real";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]real";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "";
  c2_info[23].name = "times";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]times";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[24].name = "logical";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]logical";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[25].name = "lt";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]lt";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[26].name = "uminus";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[B]uminus";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "";
  c2_info[27].name = "minus";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]minus";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "size";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]size";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "";
  c2_info[29].name = "rdivide";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[29].fileLength = 620U;
  c2_info[29].fileTime1 = 1213662890U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m";
  c2_info[30].name = "eml_int_nbits";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c2_info[30].fileLength = 467U;
  c2_info[30].fileTime1 = 1192491988U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[31].name = "false";
  c2_info[31].dominantType = "";
  c2_info[31].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[31].fileLength = 238U;
  c2_info[31].fileTime1 = 1192491920U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "sqrt";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[32].fileLength = 572U;
  c2_info[32].fileTime1 = 1203473246U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c2_info[33].name = "ndims";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[B]ndims";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[34].name = "mpower";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[34].fileLength = 3547U;
  c2_info[34].fileTime1 = 1213662888U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "";
  c2_info[35].name = "ctranspose";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]ctranspose";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[36].name = "eml_assert_valid_size_arg";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[36].fileLength = 2835U;
  c2_info[36].fileTime1 = 1210895844U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[37].name = "eml_scalar_sqrt";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[37].fileLength = 664U;
  c2_info[37].fileTime1 = 1209355994U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[38].name = "eml_scalexp_size";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[38].fileLength = 1373U;
  c2_info[38].fileTime1 = 1208205260U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[39].name = "le";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[B]le";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/maxabs";
  c2_info[40].name = "abs";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[40].fileLength = 538U;
  c2_info[40].fileTime1 = 1203473128U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[41].name = "gt";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved = "[B]gt";
  c2_info[41].fileLength = 0U;
  c2_info[41].fileTime1 = 0U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  c2_info[42].name = "uint8";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[B]uint8";
  c2_info[42].fileLength = 0U;
  c2_info[42].fileTime1 = 0U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[43].name = "eml_isequal_core";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[43].fileLength = 3543U;
  c2_info[43].fileTime1 = 1213662886U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[44].name = "realmin";
  c2_info[44].dominantType = "";
  c2_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[44].fileLength = 475U;
  c2_info[44].fileTime1 = 1192491952U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[45].name = "eml_index_minus";
  c2_info[45].dominantType = "int32";
  c2_info[45].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[45].fileLength = 277U;
  c2_info[45].fileTime1 = 1192491984U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context = "";
  c2_info[46].name = "length";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[46].fileLength = 303U;
  c2_info[46].fileTime1 = 1192491938U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c2_info[47].name = "all";
  c2_info[47].dominantType = "logical";
  c2_info[47].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[47].fileLength = 400U;
  c2_info[47].fileTime1 = 1192492104U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[48].name = "eml_index_class";
  c2_info[48].dominantType = "";
  c2_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[48].fileLength = 909U;
  c2_info[48].fileTime1 = 1192491982U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[49].name = "isempty";
  c2_info[49].dominantType = "logical";
  c2_info[49].resolved = "[B]isempty";
  c2_info[49].fileLength = 0U;
  c2_info[49].fileTime1 = 0U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[50].name = "nan";
  c2_info[50].dominantType = "";
  c2_info[50].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c2_info[50].fileLength = 474U;
  c2_info[50].fileTime1 = 1192491944U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[51].name = "eml_nonsingleton_dim";
  c2_info[51].dominantType = "logical";
  c2_info[51].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[51].fileLength = 404U;
  c2_info[51].fileTime1 = 1192492000U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[52].name = "eml_scalar_floor";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[52].fileLength = 260U;
  c2_info[52].fileTime1 = 1209355990U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context = "";
  c2_info[53].name = "sum";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[53].fileLength = 2854U;
  c2_info[53].fileTime1 = 1213662886U;
  c2_info[53].fileTime2 = 0U;
  c2_info[54].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[54].name = "isinteger";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved = "[B]isinteger";
  c2_info[54].fileLength = 0U;
  c2_info[54].fileTime1 = 0U;
  c2_info[54].fileTime2 = 0U;
  c2_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[55].name = "isinf";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[55].fileLength = 472U;
  c2_info[55].fileTime1 = 1192491934U;
  c2_info[55].fileTime2 = 0U;
  c2_info[56].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[56].name = "isscalar";
  c2_info[56].dominantType = "double";
  c2_info[56].resolved = "[B]isscalar";
  c2_info[56].fileLength = 0U;
  c2_info[56].fileTime1 = 0U;
  c2_info[56].fileTime2 = 0U;
  c2_info[57].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[57].name = "true";
  c2_info[57].dominantType = "";
  c2_info[57].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[57].fileLength = 237U;
  c2_info[57].fileTime1 = 1192491962U;
  c2_info[57].fileTime2 = 0U;
  c2_info[58].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[58].name = "eml_warning";
  c2_info[58].dominantType = "char";
  c2_info[58].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[58].fileLength = 262U;
  c2_info[58].fileTime1 = 1213662888U;
  c2_info[58].fileTime2 = 0U;
  c2_info[59].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[59].name = "eml_xgemm";
  c2_info[59].dominantType = "int32";
  c2_info[59].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[59].fileLength = 3184U;
  c2_info[59].fileTime1 = 1209356052U;
  c2_info[59].fileTime2 = 0U;
  c2_info[60].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c2_info[60].name = "ne";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved = "[B]ne";
  c2_info[60].fileLength = 0U;
  c2_info[60].fileTime1 = 0U;
  c2_info[60].fileTime2 = 0U;
  c2_info[61].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c2_info[61].name = "eml_refblas_xgemm";
  c2_info[61].dominantType = "int32";
  c2_info[61].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[61].fileLength = 5746U;
  c2_info[61].fileTime1 = 1210895858U;
  c2_info[61].fileTime2 = 0U;
  c2_info[62].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[62].name = "cast";
  c2_info[62].dominantType = "double";
  c2_info[62].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[62].fileLength = 866U;
  c2_info[62].fileTime1 = 1192491844U;
  c2_info[62].fileTime2 = 0U;
  c2_info[63].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[63].name = "intmax";
  c2_info[63].dominantType = "char";
  c2_info[63].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[63].fileLength = 1535U;
  c2_info[63].fileTime1 = 1192491928U;
  c2_info[63].fileTime2 = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[90])
{
  c2_info[64].context = "";
  c2_info[64].name = "bitor";
  c2_info[64].dominantType = "uint32";
  c2_info[64].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m";
  c2_info[64].fileLength = 1043U;
  c2_info[64].fileTime1 = 1209356078U;
  c2_info[64].fileTime2 = 0U;
  c2_info[65].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[65].name = "eml_scalexp_compatible";
  c2_info[65].dominantType = "double";
  c2_info[65].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[65].fileLength = 502U;
  c2_info[65].fileTime1 = 1208205258U;
  c2_info[65].fileTime2 = 0U;
  c2_info[66].context = "";
  c2_info[66].name = "bitget";
  c2_info[66].dominantType = "uint32";
  c2_info[66].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m";
  c2_info[66].fileLength = 1216U;
  c2_info[66].fileTime1 = 1213662888U;
  c2_info[66].fileTime2 = 0U;
  c2_info[67].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[67].name = "not";
  c2_info[67].dominantType = "logical";
  c2_info[67].resolved = "[B]not";
  c2_info[67].fileLength = 0U;
  c2_info[67].fileTime1 = 0U;
  c2_info[67].fileTime2 = 0U;
  c2_info[68].context = "";
  c2_info[68].name = "any";
  c2_info[68].dominantType = "double";
  c2_info[68].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c2_info[68].fileLength = 400U;
  c2_info[68].fileTime1 = 1192492106U;
  c2_info[68].fileTime2 = 0U;
  c2_info[69].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[69].name = "ones";
  c2_info[69].dominantType = "char";
  c2_info[69].resolved = "[B]ones";
  c2_info[69].fileLength = 0U;
  c2_info[69].fileTime1 = 0U;
  c2_info[69].fileTime2 = 0U;
  c2_info[70].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[70].name = "zeros";
  c2_info[70].dominantType = "double";
  c2_info[70].resolved = "[B]zeros";
  c2_info[70].fileLength = 0U;
  c2_info[70].fileTime1 = 0U;
  c2_info[70].fileTime2 = 0U;
  c2_info[71].context = "";
  c2_info[71].name = "bitand";
  c2_info[71].dominantType = "uint32";
  c2_info[71].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[71].fileLength = 1046U;
  c2_info[71].fileTime1 = 1209356078U;
  c2_info[71].fileTime2 = 0U;
  c2_info[72].context = "";
  c2_info[72].name = "mtimes";
  c2_info[72].dominantType = "double";
  c2_info[72].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[72].fileLength = 2336U;
  c2_info[72].fileTime1 = 1213662890U;
  c2_info[72].fileTime2 = 0U;
  c2_info[73].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[73].name = "eml_alloc";
  c2_info[73].dominantType = "double";
  c2_info[73].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[73].fileLength = 2627U;
  c2_info[73].fileTime1 = 1213662886U;
  c2_info[73].fileTime2 = 0U;
  c2_info[74].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m";
  c2_info[74].name = "eml_isa_uint";
  c2_info[74].dominantType = "uint32";
  c2_info[74].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[74].fileLength = 239U;
  c2_info[74].fileTime1 = 1192491992U;
  c2_info[74].fileTime2 = 0U;
  c2_info[75].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[75].name = "isvector";
  c2_info[75].dominantType = "double";
  c2_info[75].resolved = "[B]isvector";
  c2_info[75].fileLength = 0U;
  c2_info[75].fileTime1 = 0U;
  c2_info[75].fileTime2 = 0U;
  c2_info[76].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[76].name = "isa";
  c2_info[76].dominantType = "double";
  c2_info[76].resolved = "[B]isa";
  c2_info[76].fileLength = 0U;
  c2_info[76].fileTime1 = 0U;
  c2_info[76].fileTime2 = 0U;
  c2_info[77].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[77].name = "class";
  c2_info[77].dominantType = "double";
  c2_info[77].resolved = "[B]class";
  c2_info[77].fileLength = 0U;
  c2_info[77].fileTime1 = 0U;
  c2_info[77].fileTime2 = 0U;
  c2_info[78].context = "";
  c2_info[78].name = "colon";
  c2_info[78].dominantType = "double";
  c2_info[78].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[78].fileLength = 7324U;
  c2_info[78].fileTime1 = 1197325946U;
  c2_info[78].fileTime2 = 0U;
  c2_info[79].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c2_info[79].name = "eml_index_plus";
  c2_info[79].dominantType = "int32";
  c2_info[79].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[79].fileLength = 272U;
  c2_info[79].fileTime1 = 1192491986U;
  c2_info[79].fileTime2 = 0U;
  c2_info[80].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[80].name = "eml_set_singleton_dim";
  c2_info[80].dominantType = "double";
  c2_info[80].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c2_info[80].fileLength = 398U;
  c2_info[80].fileTime1 = 1209356038U;
  c2_info[80].fileTime2 = 0U;
  c2_info[81].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[81].name = "and";
  c2_info[81].dominantType = "logical";
  c2_info[81].resolved = "[B]and";
  c2_info[81].fileLength = 0U;
  c2_info[81].fileTime1 = 0U;
  c2_info[81].fileTime2 = 0U;
  c2_info[82].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c2_info[82].name = "eps";
  c2_info[82].dominantType = "double";
  c2_info[82].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[82].fileLength = 1342U;
  c2_info[82].fileTime1 = 1210895846U;
  c2_info[82].fileTime2 = 0U;
  c2_info[83].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[83].name = "eml_blas_xgemm";
  c2_info[83].dominantType = "int32";
  c2_info[83].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c2_info[83].fileLength = 355U;
  c2_info[83].fileTime1 = 1192492054U;
  c2_info[83].fileTime2 = 0U;
  c2_info[84].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c2_info[84].name = "double";
  c2_info[84].dominantType = "double";
  c2_info[84].resolved = "[B]double";
  c2_info[84].fileLength = 0U;
  c2_info[84].fileTime1 = 0U;
  c2_info[84].fileTime2 = 0U;
  c2_info[85].context = "";
  c2_info[85].name = "power";
  c2_info[85].dominantType = "double";
  c2_info[85].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[85].fileLength = 5131U;
  c2_info[85].fileTime1 = 1213662890U;
  c2_info[85].fileTime2 = 0U;
  c2_info[86].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[86].name = "isnan";
  c2_info[86].dominantType = "double";
  c2_info[86].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[86].fileLength = 472U;
  c2_info[86].fileTime1 = 1192491936U;
  c2_info[86].fileTime2 = 0U;
  c2_info[87].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[87].name = "eml_error";
  c2_info[87].dominantType = "char";
  c2_info[87].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[87].fileLength = 315U;
  c2_info[87].fileTime1 = 1213662886U;
  c2_info[87].fileTime2 = 0U;
  c2_info[88].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[88].name = "nargin";
  c2_info[88].dominantType = "";
  c2_info[88].resolved = "[B]nargin";
  c2_info[88].fileLength = 0U;
  c2_info[88].fileTime1 = 0U;
  c2_info[88].fileTime2 = 0U;
  c2_info[89].context = "";
  c2_info[89].name = "eq";
  c2_info[89].dominantType = "double";
  c2_info[89].resolved = "[B]eq";
  c2_info[89].fileLength = 0U;
  c2_info[89].fileTime1 = 0U;
  c2_info[89].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_main_sim_adapt_refsp_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1154531448U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3891046024U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(355499179U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3292868905U);
}

mxArray *sf_c2_main_sim_adapt_refsp_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(144330015U);
    pr[1] = (double)(2428826257U);
    pr[2] = (double)(3970647911U);
    pr[3] = (double)(2522856817U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_main_sim_adapt_refspMachineNumber_,
           2,
           1,
           1,
           11,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_main_sim_adapt_refspMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_main_sim_adapt_refspMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_main_sim_adapt_refspMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 1;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Bmat",0,c2_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"wght_cv",0,NULL);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ulim",0,
                              c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"llim",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"cvd_des",0,NULL);
          }

          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"rcs_cmd",
                              0,NULL);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"minerr",
                              0,NULL);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"scale",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"cvd_actual",0,NULL);
          }

          _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "err_thresh",0,NULL);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "rcs_use_in",0,NULL);
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
        _SFD_CV_INIT_EML(0,2,9,0,1,0,2,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2038);
        _SFD_CV_INIT_EML_FCN(0,1,"norm_vec",2038,-1,2098);
        _SFD_CV_INIT_EML_IF(0,0,169,182,783,822);
        _SFD_CV_INIT_EML_IF(0,1,466,483,-1,545);
        _SFD_CV_INIT_EML_IF(0,2,783,807,1197,1229);
        _SFD_CV_INIT_EML_IF(0,3,1197,1214,-1,-2);
        _SFD_CV_INIT_EML_IF(0,4,1266,1281,1419,1813);
        _SFD_CV_INIT_EML_IF(0,5,1419,1424,-1,1813);
        _SFD_CV_INIT_EML_IF(0,6,1479,1498,1602,1805);
        _SFD_CV_INIT_EML_IF(0,7,1602,1637,1675,1805);
        _SFD_CV_INIT_EML_IF(0,8,1885,1901,-1,2032);
        _SFD_CV_INIT_EML_FOR(0,0,1231,1257,2036);

        {
          static int condStart[] = { 1201 };

          static int condEnd[] = { 1213 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,0,1200,1213,1,0,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1270 };

          static int condEnd[] = { 1280 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,1269,1280,1,1,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c2_Bmat)[3];
          real_T (*c2_wght_cv)[3];
          real_T *c2_ulim;
          real_T *c2_llim;
          real_T (*c2_cvd_des)[3];
          real_T *c2_rcs_cmd;
          real_T *c2_minerr;
          real_T *c2_scale;
          real_T (*c2_cvd_actual)[3];
          real_T *c2_err_thresh;
          real_T *c2_rcs_use_in;
          c2_minerr = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_ulim = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c2_rcs_cmd = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_cvd_actual = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S,
            4);
          c2_Bmat = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c2_rcs_use_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
          c2_cvd_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
          c2_scale = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c2_wght_cv = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c2_err_thresh = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c2_llim = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Bmat);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_wght_cv);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_ulim);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_llim);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_cvd_des);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_rcs_cmd);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_minerr);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_scale);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_cvd_actual);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_err_thresh);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_rcs_use_in);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_main_sim_adapt_refspMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_main_sim_adapt_refsp(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_main_sim_adapt_refsp();
  initialize_c2_main_sim_adapt_refsp();
}

static void sf_opaque_enable_c2_main_sim_adapt_refsp(void *chartInstanceVar)
{
  enable_c2_main_sim_adapt_refsp();
}

static void sf_opaque_disable_c2_main_sim_adapt_refsp(void *chartInstanceVar)
{
  disable_c2_main_sim_adapt_refsp();
}

static void sf_opaque_gateway_c2_main_sim_adapt_refsp(void *chartInstanceVar)
{
  sf_c2_main_sim_adapt_refsp();
}

static mxArray* sf_opaque_get_sim_state_c2_main_sim_adapt_refsp(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_main_sim_adapt_refsp();
  return st;
}

static void sf_opaque_set_sim_state_c2_main_sim_adapt_refsp(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_main_sim_adapt_refsp(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_main_sim_adapt_refsp(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_main_sim_adapt_refsp();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_main_sim_adapt_refsp(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_main_sim_adapt_refsp();
  }
}

static void mdlSetWorkWidths_c2_main_sim_adapt_refsp(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("main_sim_adapt_refsp","main_sim_adapt_refsp",
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("main_sim_adapt_refsp",
                "main_sim_adapt_refsp",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("main_sim_adapt_refsp",
      "main_sim_adapt_refsp",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"main_sim_adapt_refsp",
        "main_sim_adapt_refsp",2,7);
      sf_mark_chart_reusable_outputs(S,"main_sim_adapt_refsp",
        "main_sim_adapt_refsp",2,4);
    }

    sf_set_rtw_dwork_info(S,"main_sim_adapt_refsp","main_sim_adapt_refsp",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2592993594U));
  ssSetChecksum1(S,(3595202699U));
  ssSetChecksum2(S,(3186592485U));
  ssSetChecksum3(S,(1215213000U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_main_sim_adapt_refsp(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "main_sim_adapt_refsp", "main_sim_adapt_refsp",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_main_sim_adapt_refsp(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_main_sim_adapt_refsp;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c2_main_sim_adapt_refsp_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_main_sim_adapt_refsp(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_main_sim_adapt_refsp(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_main_sim_adapt_refsp(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_main_sim_adapt_refsp_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
