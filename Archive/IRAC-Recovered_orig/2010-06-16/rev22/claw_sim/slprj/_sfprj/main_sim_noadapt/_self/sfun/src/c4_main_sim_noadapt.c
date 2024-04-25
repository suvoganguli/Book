/* Include files */

#include "main_sim_noadapt_sfun.h"
#include "c4_main_sim_noadapt.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "main_sim_noadapt_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_main_sim_noadaptInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_main_sim_noadapt(void);
static void initialize_params_c4_main_sim_noadapt(void);
static void enable_c4_main_sim_noadapt(void);
static void disable_c4_main_sim_noadapt(void);
static void update_debugger_state_c4_main_sim_noadapt(void);
static const mxArray *get_sim_state_c4_main_sim_noadapt(void);
static void set_sim_state_c4_main_sim_noadapt(const mxArray *c4_st);
static void finalize_c4_main_sim_noadapt(void);
static void sf_c4_main_sim_noadapt(void);
static void c4_c4_main_sim_noadapt(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static void c4_qmpy(real_T c4_p[4], real_T c4_q[4], real_T c4_r[4]);
static real_T c4_norm_vec3(real_T c4_in[3]);
static real_T c4_mpower(real_T c4_a);
static void c4_eml_error(void);
static real_T c4_atan2(real_T c4_y, real_T c4_x);
static real_T c4_abs(real_T c4_x);
static void c4_mrdivide(real_T c4_A[3], real_T c4_B, real_T c4_y[3]);
static void c4_eml_warning(void);
static void c4_b_abs(real_T c4_x[3], real_T c4_y[3]);
static real_T c4_max(real_T c4_varargin_1[3]);
static real_T c4_get_ellipsoid_scaling(real_T c4_dir[3], real_T c4_ellipsoid[9]);
static real_T c4_eml_bin_extremum(boolean_T c4_domax, real_T c4_x, real_T c4_y);
static void c4_pp(real_T c4_params[6], real_T c4_att, real_T c4_rate, real_T
                  *c4_outside, real_T *c4_accel);
static void c4_b_eml_warning(void);
static real_T c4_min(real_T c4_varargin_1, real_T c4_varargin_2);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_g_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_h_sf_marshall(void *c4_chartInstance, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[88]);
static void c4_b_info_helper(c4_ResolvedFunctionInfo c4_info[88]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_main_sim_noadapt(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c4_is_active_c4_main_sim_noadapt = 0U;
}

static void initialize_params_c4_main_sim_noadapt(void)
{
}

static void enable_c4_main_sim_noadapt(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_main_sim_noadapt(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void update_debugger_state_c4_main_sim_noadapt(void)
{
}

static const mxArray *get_sim_state_c4_main_sim_noadapt(void)
{
  return NULL;
}

static void set_sim_state_c4_main_sim_noadapt(const mxArray *c4_st)
{
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_main_sim_noadapt(void)
{
}

static void sf_c4_main_sim_noadapt(void)
{
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  uint8_T c4_previousEvent;
  real_T *c4_use_bb;
  real_T *c4_timer;
  real_T *c4_enable_bb;
  real_T *c4_use_bb_old;
  real_T *c4_timer_old;
  real_T (*c4_dir_old)[3];
  real_T (*c4_cvddes_lin)[3];
  real_T (*c4_inertia)[9];
  real_T (*c4_pqr)[3];
  real_T (*c4_att_cv)[4];
  real_T (*c4_att_cvc)[4];
  real_T (*c4_dir)[3];
  real_T (*c4_cvddes)[3];
  real_T (*c4_debug_output)[12];
  real_T (*c4_bb_ellipsoid)[9];
  real_T (*c4_bb_params)[11];
  c4_att_cv = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
  c4_bb_params = (real_T (*)[11])ssGetInputPortSignal(chartInstance.S, 0);
  c4_dir = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c4_bb_ellipsoid = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S, 1);
  c4_inertia = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S, 5);
  c4_cvddes = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c4_enable_bb = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c4_dir_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 8);
  c4_use_bb = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c4_debug_output = (real_T (*)[12])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
  c4_timer_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 10);
  c4_cvddes_lin = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 7);
  c4_att_cvc = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c4_timer = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c4_use_bb_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 9);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c4_i0 = 0; c4_i0 < 11; c4_i0 = c4_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_bb_params)[c4_i0], 0U);
  }

  for (c4_i1 = 0; c4_i1 < 9; c4_i1 = c4_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_bb_ellipsoid)[c4_i1], 1U);
  }

  for (c4_i2 = 0; c4_i2 < 12; c4_i2 = c4_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_debug_output)[c4_i2], 2U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_cvddes)[c4_i3], 3U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_dir)[c4_i4], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_use_bb, 5U);
  for (c4_i5 = 0; c4_i5 < 4; c4_i5 = c4_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_att_cvc)[c4_i5], 6U);
  }

  for (c4_i6 = 0; c4_i6 < 4; c4_i6 = c4_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_att_cv)[c4_i6], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_timer, 8U);
  for (c4_i7 = 0; c4_i7 < 3; c4_i7 = c4_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_pqr)[c4_i7], 9U);
  }

  for (c4_i8 = 0; c4_i8 < 9; c4_i8 = c4_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_inertia)[c4_i8], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_enable_bb, 11U);
  for (c4_i9 = 0; c4_i9 < 3; c4_i9 = c4_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_cvddes_lin)[c4_i9], 12U);
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10 = c4_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_dir_old)[c4_i10], 13U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_use_bb_old, 14U);
  _SFD_DATA_RANGE_CHECK(*c4_timer_old, 15U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c4_c4_main_sim_noadapt();
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_main_sim_noadaptMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c4_c4_main_sim_noadapt(void)
{
  int32_T c4_i11;
  real_T c4_bb_params[11];
  int32_T c4_i12;
  real_T c4_bb_ellipsoid[9];
  int32_T c4_i13;
  real_T c4_att_cvc[4];
  int32_T c4_i14;
  real_T c4_att_cv[4];
  int32_T c4_i15;
  real_T c4_pqr[3];
  int32_T c4_i16;
  real_T c4_inertia[9];
  real_T c4_enable_bb;
  int32_T c4_i17;
  real_T c4_cvddes_lin[3];
  int32_T c4_i18;
  real_T c4_dir_old[3];
  real_T c4_use_bb_old;
  real_T c4_timer_old;
  real_T c4_nargout = 5.0;
  real_T c4_nargin = 11.0;
  real_T c4_pp_utQu;
  real_T c4_blend_bb_claw[3];
  real_T c4_blend_lin_claw[3];
  real_T c4_accel;
  real_T c4_outside;
  real_T c4_accel_min;
  real_T c4_accel_max;
  real_T c4_rate;
  real_T c4_att_old;
  real_T c4_att;
  real_T c4_trans_dir[3];
  real_T c4_trans_mag;
  real_T c4_use_dir_old;
  real_T c4_trans[4];
  real_T c4_pp_params[6];
  real_T c4_att_diff_thresh;
  real_T c4_rate_thresh;
  real_T c4_att_thresh;
  real_T c4_timer_max;
  real_T c4_dt;
  real_T c4_timer;
  real_T c4_use_bb;
  real_T c4_dir[3];
  real_T c4_cvddes[3];
  real_T c4_debug_output[12];
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  static real_T c4_dv0[4] = { 1.0, -1.0, -1.0, -1.0 };

  real_T c4_dv1[4];
  int32_T c4_i24;
  real_T c4_b_att_cvc[4];
  real_T c4_dv2[4];
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  real_T c4_b_trans_dir[3];
  real_T c4_b;
  int32_T c4_i28;
  real_T c4_a[3];
  int32_T c4_i29;
  real_T c4_b_b[3];
  int32_T c4_i30;
  real_T c4_x[3];
  int32_T c4_i31;
  real_T c4_y[3];
  int32_T c4_i32;
  real_T c4_b_x[3];
  int32_T c4_i33;
  real_T c4_b_y[3];
  int32_T c4_i34;
  real_T c4_c_x[3];
  int32_T c4_i35;
  real_T c4_c_y[3];
  int32_T c4_i36;
  real_T c4_d_x[3];
  int32_T c4_i37;
  real_T c4_d_y[3];
  int32_T c4_i38;
  real_T c4_e_x[3];
  int32_T c4_i39;
  real_T c4_e_y[3];
  real_T c4_f_y;
  int32_T c4_k;
  int32_T c4_b_k;
  real_T c4_c_b;
  real_T c4_b_a;
  real_T c4_d_b;
  real_T c4_g_y;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  real_T c4_c_trans_dir[3];
  int32_T c4_i43;
  real_T c4_d_trans_dir[3];
  real_T c4_dv3[3];
  int32_T c4_i44;
  int32_T c4_i45;
  real_T c4_b_pqr[3];
  real_T c4_dv4[3];
  int32_T c4_i46;
  real_T c4_dv5[3];
  int32_T c4_i47;
  real_T c4_c_pqr[3];
  int32_T c4_i48;
  real_T c4_d_pqr[3];
  real_T c4_dv6[3];
  int32_T c4_i49;
  int32_T c4_i50;
  real_T c4_c_a[3];
  int32_T c4_i51;
  real_T c4_e_b[3];
  int32_T c4_i52;
  real_T c4_f_x[3];
  int32_T c4_i53;
  real_T c4_h_y[3];
  int32_T c4_i54;
  real_T c4_g_x[3];
  int32_T c4_i55;
  real_T c4_i_y[3];
  int32_T c4_i56;
  real_T c4_h_x[3];
  int32_T c4_i57;
  real_T c4_j_y[3];
  int32_T c4_i58;
  real_T c4_i_x[3];
  int32_T c4_i59;
  real_T c4_k_y[3];
  int32_T c4_i60;
  real_T c4_j_x[3];
  int32_T c4_i61;
  real_T c4_l_y[3];
  real_T c4_m_y;
  int32_T c4_c_k;
  int32_T c4_d_k;
  real_T c4_f_b;
  int32_T c4_i62;
  int32_T c4_i63;
  real_T c4_d_a[3];
  int32_T c4_i64;
  real_T c4_g_b[3];
  int32_T c4_i65;
  real_T c4_k_x[3];
  int32_T c4_i66;
  real_T c4_n_y[3];
  int32_T c4_i67;
  real_T c4_l_x[3];
  int32_T c4_i68;
  real_T c4_o_y[3];
  int32_T c4_i69;
  real_T c4_m_x[3];
  int32_T c4_i70;
  real_T c4_p_y[3];
  int32_T c4_i71;
  real_T c4_n_x[3];
  int32_T c4_i72;
  real_T c4_q_y[3];
  int32_T c4_i73;
  real_T c4_o_x[3];
  int32_T c4_i74;
  real_T c4_r_y[3];
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_i75;
  real_T c4_e_a[9];
  int32_T c4_i76;
  real_T c4_h_b[3];
  int32_T c4_i77;
  real_T c4_A[9];
  int32_T c4_i78;
  real_T c4_B[3];
  int32_T c4_i79;
  real_T c4_b_A[9];
  int32_T c4_i80;
  real_T c4_b_B[3];
  int32_T c4_i81;
  real_T c4_c_A[9];
  int32_T c4_i82;
  real_T c4_c_B[3];
  int32_T c4_i83;
  real_T c4_s_y[3];
  int32_T c4_i84;
  int32_T c4_i85;
  real_T c4_t_y[3];
  int32_T c4_i86;
  real_T c4_b_bb_ellipsoid[9];
  int32_T c4_i87;
  real_T c4_b_pp_params[6];
  real_T c4_d0;
  real_T c4_d1;
  int32_T c4_i88;
  real_T c4_f_a[3];
  int32_T c4_i89;
  real_T c4_i_b[3];
  int32_T c4_i90;
  real_T c4_p_x[3];
  int32_T c4_i91;
  real_T c4_u_y[3];
  int32_T c4_i92;
  real_T c4_q_x[3];
  int32_T c4_i93;
  real_T c4_v_y[3];
  int32_T c4_i94;
  real_T c4_r_x[3];
  int32_T c4_i95;
  real_T c4_w_y[3];
  int32_T c4_i96;
  real_T c4_s_x[3];
  int32_T c4_i97;
  real_T c4_x_y[3];
  int32_T c4_i98;
  real_T c4_t_x[3];
  int32_T c4_i99;
  real_T c4_y_y[3];
  real_T c4_g_a;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i100;
  real_T c4_j_b[3];
  int32_T c4_i101;
  real_T c4_ab_y[3];
  int32_T c4_i102;
  int32_T c4_i103;
  real_T c4_h_a[3];
  int32_T c4_i104;
  real_T c4_i_a[9];
  int32_T c4_i105;
  real_T c4_k_b[3];
  int32_T c4_i106;
  real_T c4_d_A[9];
  int32_T c4_i107;
  real_T c4_d_B[3];
  int32_T c4_i108;
  real_T c4_e_A[9];
  int32_T c4_i109;
  real_T c4_e_B[3];
  int32_T c4_i110;
  real_T c4_f_A[9];
  int32_T c4_i111;
  real_T c4_f_B[3];
  int32_T c4_i112;
  real_T c4_bb_y[3];
  int32_T c4_i113;
  int32_T c4_i114;
  real_T c4_cb_y[3];
  int32_T c4_i115;
  real_T c4_c_bb_ellipsoid[9];
  real_T c4_l_b;
  int32_T c4_i116;
  real_T c4_j_a;
  int32_T c4_i117;
  real_T c4_m_b[3];
  int32_T c4_i118;
  int32_T c4_i119;
  int32_T c4_i120;
  real_T c4_k_a[9];
  int32_T c4_i121;
  real_T c4_n_b[3];
  int32_T c4_i122;
  real_T c4_g_A[9];
  int32_T c4_i123;
  real_T c4_g_B[3];
  int32_T c4_i124;
  real_T c4_h_A[9];
  int32_T c4_i125;
  real_T c4_h_B[3];
  int32_T c4_i126;
  real_T c4_i_A[9];
  int32_T c4_i127;
  real_T c4_i_B[3];
  int32_T c4_i128;
  real_T c4_db_y[3];
  int32_T c4_i129;
  int32_T c4_i130;
  real_T c4_eb_y[3];
  int32_T c4_i131;
  real_T c4_d_bb_ellipsoid[9];
  real_T c4_j_B;
  real_T c4_fb_y;
  real_T c4_gb_y;
  real_T c4_hb_y;
  int32_T c4_i132;
  int32_T c4_i133;
  int32_T c4_i134;
  int32_T c4_i135;
  int32_T c4_i136;
  real_T *c4_b_timer;
  real_T *c4_b_use_bb;
  real_T *c4_b_timer_old;
  real_T *c4_b_use_bb_old;
  real_T *c4_b_enable_bb;
  real_T (*c4_b_debug_output)[12];
  real_T (*c4_b_cvddes)[3];
  real_T (*c4_b_dir)[3];
  real_T (*c4_b_dir_old)[3];
  real_T (*c4_b_cvddes_lin)[3];
  real_T (*c4_b_inertia)[9];
  real_T (*c4_e_pqr)[3];
  real_T (*c4_b_att_cv)[4];
  real_T (*c4_c_att_cvc)[4];
  real_T (*c4_e_bb_ellipsoid)[9];
  real_T (*c4_b_bb_params)[11];
  c4_b_att_cv = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
  c4_b_bb_params = (real_T (*)[11])ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_dir = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
  c4_e_bb_ellipsoid = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S, 1);
  c4_b_inertia = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S, 5);
  c4_b_cvddes = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c4_b_enable_bb = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c4_b_dir_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 8);
  c4_b_use_bb = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c4_b_debug_output = (real_T (*)[12])ssGetOutputPortSignal(chartInstance.S, 1);
  c4_e_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
  c4_b_timer_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 10);
  c4_b_cvddes_lin = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 7);
  c4_c_att_cvc = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
  c4_b_timer = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c4_b_use_bb_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 9);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c4_i11 = 0; c4_i11 < 11; c4_i11 = c4_i11 + 1) {
    c4_bb_params[c4_i11] = (*c4_b_bb_params)[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 9; c4_i12 = c4_i12 + 1) {
    c4_bb_ellipsoid[c4_i12] = (*c4_e_bb_ellipsoid)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 4; c4_i13 = c4_i13 + 1) {
    c4_att_cvc[c4_i13] = (*c4_c_att_cvc)[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 4; c4_i14 = c4_i14 + 1) {
    c4_att_cv[c4_i14] = (*c4_b_att_cv)[c4_i14];
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15 = c4_i15 + 1) {
    c4_pqr[c4_i15] = (*c4_e_pqr)[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 9; c4_i16 = c4_i16 + 1) {
    c4_inertia[c4_i16] = (*c4_b_inertia)[c4_i16];
  }

  c4_enable_bb = *c4_b_enable_bb;
  for (c4_i17 = 0; c4_i17 < 3; c4_i17 = c4_i17 + 1) {
    c4_cvddes_lin[c4_i17] = (*c4_b_cvddes_lin)[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 3; c4_i18 = c4_i18 + 1) {
    c4_dir_old[c4_i18] = (*c4_b_dir_old)[c4_i18];
  }

  c4_use_bb_old = *c4_b_use_bb_old;
  c4_timer_old = *c4_b_timer_old;
  sf_debug_symbol_scope_push(38U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("pp_utQu", &c4_pp_utQu, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("blend_bb_claw", &c4_blend_bb_claw, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("blend_lin_claw", &c4_blend_lin_claw,
    c4_d_sf_marshall);
  sf_debug_symbol_scope_add("accel", &c4_accel, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("outside", &c4_outside, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("accel_min", &c4_accel_min, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("accel_max", &c4_accel_max, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("rate", &c4_rate, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("att_old", &c4_att_old, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("att", &c4_att, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("trans_dir", &c4_trans_dir, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("trans_mag", &c4_trans_mag, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("use_dir_old", &c4_use_dir_old, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("trans", &c4_trans, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("pp_params", &c4_pp_params, c4_g_sf_marshall);
  sf_debug_symbol_scope_add("att_diff_thresh", &c4_att_diff_thresh,
    c4_e_sf_marshall);
  sf_debug_symbol_scope_add("rate_thresh", &c4_rate_thresh, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("att_thresh", &c4_att_thresh, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("timer_max", &c4_timer_max, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("dt", &c4_dt, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("timer", &c4_timer, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("use_bb", &c4_use_bb, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("dir", &c4_dir, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("cvddes", &c4_cvddes, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("debug_output", &c4_debug_output, c4_f_sf_marshall);
  sf_debug_symbol_scope_add("timer_old", &c4_timer_old, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("use_bb_old", &c4_use_bb_old, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("dir_old", &c4_dir_old, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("cvddes_lin", &c4_cvddes_lin, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("enable_bb", &c4_enable_bb, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("inertia", &c4_inertia, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("pqr", &c4_pqr, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("att_cv", &c4_att_cv, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("att_cvc", &c4_att_cvc, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("bb_ellipsoid", &c4_bb_ellipsoid, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("bb_params", &c4_bb_params, c4_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c4_dt = c4_bb_params[0];
  _SFD_EML_CALL(0,6);
  c4_timer_max = c4_bb_params[1];
  _SFD_EML_CALL(0,7);
  c4_att_thresh = c4_bb_params[2];
  _SFD_EML_CALL(0,8);
  c4_rate_thresh = c4_bb_params[3];
  _SFD_EML_CALL(0,9);
  c4_att_diff_thresh = c4_bb_params[4];
  _SFD_EML_CALL(0,10);
  for (c4_i19 = 0; c4_i19 < 6; c4_i19 = c4_i19 + 1) {
    c4_pp_params[c4_i19] = c4_bb_params[5 + c4_i19];
  }

  _SFD_EML_CALL(0,12);
  for (c4_i20 = 0; c4_i20 < 12; c4_i20 = c4_i20 + 1) {
    c4_debug_output[c4_i20] = 0.0;
  }

  _SFD_EML_CALL(0,13);
  for (c4_i21 = 0; c4_i21 < 3; c4_i21 = c4_i21 + 1) {
    c4_cvddes[c4_i21] = c4_cvddes_lin[c4_i21];
  }

  _SFD_EML_CALL(0,14);
  c4_use_bb = 0.0;
  _SFD_EML_CALL(0,15);
  for (c4_i22 = 0; c4_i22 < 3; c4_i22 = c4_i22 + 1) {
    c4_dir[c4_i22] = 0.0;
  }

  _SFD_EML_CALL(0,16);
  c4_timer = c4_timer_old;
  _SFD_EML_CALL(0,18);
  if (CV_EML_IF(0, 0, CV_EML_MCDC(0, 0, !(CV_EML_COND(0, 0, c4_enable_bb != 0.0)
         != 0.0)))) {
  } else {
    _SFD_EML_CALL(0,22);
    for (c4_i23 = 0; c4_i23 < 4; c4_i23 = c4_i23 + 1) {
      c4_dv1[c4_i23] = c4_dv0[c4_i23] * c4_att_cv[c4_i23];
    }

    for (c4_i24 = 0; c4_i24 < 4; c4_i24 = c4_i24 + 1) {
      c4_b_att_cvc[c4_i24] = c4_att_cvc[c4_i24];
    }

    c4_qmpy(c4_dv1, c4_b_att_cvc, c4_dv2);
    for (c4_i25 = 0; c4_i25 < 4; c4_i25 = c4_i25 + 1) {
      c4_trans[c4_i25] = c4_dv2[c4_i25];
    }

    /*  default is to use dir_old if we were in bangbang last cycle, */
    /*  and the timer has not expired */
    _SFD_EML_CALL(0,26);
    c4_use_dir_old = c4_use_bb_old;
    _SFD_EML_CALL(0,27);
    if (CV_EML_IF(0, 1, c4_use_dir_old != 0.0) != 0.0) {
      _SFD_EML_CALL(0,28);
      c4_timer = c4_timer + c4_dt;
      _SFD_EML_CALL(0,29);
      if (CV_EML_IF(0, 2, c4_timer > c4_timer_max)) {
        /*  if timer expires, don't use dir_old */
        _SFD_EML_CALL(0,31);
        c4_use_dir_old = 0.0;
      }
    }

    /*  compute att using current transformation quat */
    _SFD_EML_CALL(0,36);
    c4_trans_mag = c4_trans[0];
    _SFD_EML_CALL(0,37);
    for (c4_i26 = 0; c4_i26 < 3; c4_i26 = c4_i26 + 1) {
      c4_trans_dir[c4_i26] = c4_trans[1 + c4_i26];
    }

    _SFD_EML_CALL(0,38);
    for (c4_i27 = 0; c4_i27 < 3; c4_i27 = c4_i27 + 1) {
      c4_b_trans_dir[c4_i27] = c4_trans_dir[c4_i27];
    }

    c4_b = c4_atan2(c4_norm_vec3(c4_b_trans_dir), c4_trans_mag);
    c4_att = -2.0 * c4_b;
    _SFD_EML_CALL(0,39);
    for (c4_i28 = 0; c4_i28 < 3; c4_i28 = c4_i28 + 1) {
      c4_a[c4_i28] = c4_dir_old[c4_i28];
    }

    for (c4_i29 = 0; c4_i29 < 3; c4_i29 = c4_i29 + 1) {
      c4_b_b[c4_i29] = c4_trans_dir[c4_i29];
    }

    for (c4_i30 = 0; c4_i30 < 3; c4_i30 = c4_i30 + 1) {
      c4_x[c4_i30] = c4_a[c4_i30];
    }

    for (c4_i31 = 0; c4_i31 < 3; c4_i31 = c4_i31 + 1) {
      c4_y[c4_i31] = c4_b_b[c4_i31];
    }

    for (c4_i32 = 0; c4_i32 < 3; c4_i32 = c4_i32 + 1) {
      c4_b_x[c4_i32] = c4_x[c4_i32];
    }

    for (c4_i33 = 0; c4_i33 < 3; c4_i33 = c4_i33 + 1) {
      c4_b_y[c4_i33] = c4_y[c4_i33];
    }

    for (c4_i34 = 0; c4_i34 < 3; c4_i34 = c4_i34 + 1) {
      c4_c_x[c4_i34] = c4_b_x[c4_i34];
    }

    for (c4_i35 = 0; c4_i35 < 3; c4_i35 = c4_i35 + 1) {
      c4_c_y[c4_i35] = c4_b_y[c4_i35];
    }

    for (c4_i36 = 0; c4_i36 < 3; c4_i36 = c4_i36 + 1) {
      c4_d_x[c4_i36] = c4_c_x[c4_i36];
    }

    for (c4_i37 = 0; c4_i37 < 3; c4_i37 = c4_i37 + 1) {
      c4_d_y[c4_i37] = c4_c_y[c4_i37];
    }

    for (c4_i38 = 0; c4_i38 < 3; c4_i38 = c4_i38 + 1) {
      c4_e_x[c4_i38] = c4_d_x[c4_i38];
    }

    for (c4_i39 = 0; c4_i39 < 3; c4_i39 = c4_i39 + 1) {
      c4_e_y[c4_i39] = c4_d_y[c4_i39];
    }

    c4_f_y = 0.0;
    for (c4_k = 1; c4_k < 4; c4_k = c4_k + 1) {
      c4_b_k = c4_k;
      c4_f_y = c4_f_y + c4_e_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c4_b_k), 1, 3, 1, 0) - 1] * c4_e_y[
        _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)c4_b_k),
        1, 3, 1, 0) - 1];
    }

    c4_c_b = c4_atan2(c4_f_y, c4_trans_mag);
    c4_att_old = -2.0 * c4_c_b;

    /*  choose arbitrary att (and dir) sign to be the same as that computed using */
    /*  dir_old.  This is equivalent to making dir_old'*trans_dir positive. */
    _SFD_EML_CALL(0,43);
    c4_b_a = c4_att;
    c4_d_b = c4_att_old;
    c4_g_y = c4_b_a * c4_d_b;
    if (CV_EML_IF(0, 3, c4_g_y < 0.0)) {
      _SFD_EML_CALL(0,44);
      c4_att = -c4_att;
      _SFD_EML_CALL(0,45);
      for (c4_i40 = 0; c4_i40 < 3; c4_i40 = c4_i40 + 1) {
        c4_trans_dir[c4_i40] = -c4_trans_dir[c4_i40];
      }
    }

    /*  if we intended to use dir_old, but the angle computed using */
    /*  dir_old is significantly different than that derived using the current */
    /*  transformation, we will use current dir. */
    /*  NOTE: the angle test below works only because att has been adjusted */
    /*  to have the same sign as att_old, and both result from atan2  */
    _SFD_EML_CALL(0,53);
    if (CV_EML_IF(0, 4, c4_use_dir_old != 0.0) != 0.0) {
      _SFD_EML_CALL(0,54);
      if (CV_EML_IF(0, 5, c4_abs(c4_att - c4_att_old) > c4_att_diff_thresh)) {
        _SFD_EML_CALL(0,55);
        c4_use_dir_old = 0.0;
      } else {
        _SFD_EML_CALL(0,57);
        for (c4_i41 = 0; c4_i41 < 3; c4_i41 = c4_i41 + 1) {
          c4_dir[c4_i41] = c4_dir_old[c4_i41];
        }

        _SFD_EML_CALL(0,58);
        c4_att = c4_att_old;
      }
    }

    /*  check condition to enter (or stay in) bangbang */
    _SFD_EML_CALL(0,63);
    if (CV_EML_IF(0, 6, c4_abs(c4_att) > c4_att_thresh)) {
      _SFD_EML_CALL(0,64);
      c4_use_bb = 1.0;
      _SFD_EML_CALL(0,66);
      if (CV_EML_IF(0, 7, CV_EML_MCDC(0, 1, !(CV_EML_COND(0, 1, c4_use_dir_old
              != 0.0) != 0.0)))) {
        _SFD_EML_CALL(0,67);
        for (c4_i42 = 0; c4_i42 < 3; c4_i42 = c4_i42 + 1) {
          c4_c_trans_dir[c4_i42] = c4_trans_dir[c4_i42];
        }

        for (c4_i43 = 0; c4_i43 < 3; c4_i43 = c4_i43 + 1) {
          c4_d_trans_dir[c4_i43] = c4_trans_dir[c4_i43];
        }

        c4_mrdivide(c4_d_trans_dir, c4_norm_vec3(c4_c_trans_dir), c4_dv3);
        for (c4_i44 = 0; c4_i44 < 3; c4_i44 = c4_i44 + 1) {
          c4_dir[c4_i44] = c4_dv3[c4_i44];
        }

        _SFD_EML_CALL(0,68);
        c4_timer = 0.0;
      }
    } else {
      _SFD_EML_CALL(0,71);
      for (c4_i45 = 0; c4_i45 < 3; c4_i45 = c4_i45 + 1) {
        c4_b_pqr[c4_i45] = c4_pqr[c4_i45];
      }

      c4_b_abs(c4_b_pqr, c4_dv4);
      for (c4_i46 = 0; c4_i46 < 3; c4_i46 = c4_i46 + 1) {
        c4_dv5[c4_i46] = c4_dv4[c4_i46];
      }

      if (CV_EML_IF(0, 8, c4_max(c4_dv5) > c4_rate_thresh)) {
        _SFD_EML_CALL(0,72);
        c4_use_bb = 1.0;

        /*  if small attitude error, set dir based on rates */
        _SFD_EML_CALL(0,75);
        if (CV_EML_IF(0, 9, CV_EML_MCDC(0, 2, !(CV_EML_COND(0, 2, c4_use_dir_old
                != 0.0) != 0.0)))) {
          _SFD_EML_CALL(0,76);
          for (c4_i47 = 0; c4_i47 < 3; c4_i47 = c4_i47 + 1) {
            c4_c_pqr[c4_i47] = c4_pqr[c4_i47];
          }

          for (c4_i48 = 0; c4_i48 < 3; c4_i48 = c4_i48 + 1) {
            c4_d_pqr[c4_i48] = c4_pqr[c4_i48];
          }

          c4_mrdivide(c4_d_pqr, c4_norm_vec3(c4_c_pqr), c4_dv6);
          for (c4_i49 = 0; c4_i49 < 3; c4_i49 = c4_i49 + 1) {
            c4_dir[c4_i49] = c4_dv6[c4_i49];
          }

          _SFD_EML_CALL(0,77);
          for (c4_i50 = 0; c4_i50 < 3; c4_i50 = c4_i50 + 1) {
            c4_c_a[c4_i50] = c4_dir[c4_i50];
          }

          for (c4_i51 = 0; c4_i51 < 3; c4_i51 = c4_i51 + 1) {
            c4_e_b[c4_i51] = c4_trans_dir[c4_i51];
          }

          for (c4_i52 = 0; c4_i52 < 3; c4_i52 = c4_i52 + 1) {
            c4_f_x[c4_i52] = c4_c_a[c4_i52];
          }

          for (c4_i53 = 0; c4_i53 < 3; c4_i53 = c4_i53 + 1) {
            c4_h_y[c4_i53] = c4_e_b[c4_i53];
          }

          for (c4_i54 = 0; c4_i54 < 3; c4_i54 = c4_i54 + 1) {
            c4_g_x[c4_i54] = c4_f_x[c4_i54];
          }

          for (c4_i55 = 0; c4_i55 < 3; c4_i55 = c4_i55 + 1) {
            c4_i_y[c4_i55] = c4_h_y[c4_i55];
          }

          for (c4_i56 = 0; c4_i56 < 3; c4_i56 = c4_i56 + 1) {
            c4_h_x[c4_i56] = c4_g_x[c4_i56];
          }

          for (c4_i57 = 0; c4_i57 < 3; c4_i57 = c4_i57 + 1) {
            c4_j_y[c4_i57] = c4_i_y[c4_i57];
          }

          for (c4_i58 = 0; c4_i58 < 3; c4_i58 = c4_i58 + 1) {
            c4_i_x[c4_i58] = c4_h_x[c4_i58];
          }

          for (c4_i59 = 0; c4_i59 < 3; c4_i59 = c4_i59 + 1) {
            c4_k_y[c4_i59] = c4_j_y[c4_i59];
          }

          for (c4_i60 = 0; c4_i60 < 3; c4_i60 = c4_i60 + 1) {
            c4_j_x[c4_i60] = c4_i_x[c4_i60];
          }

          for (c4_i61 = 0; c4_i61 < 3; c4_i61 = c4_i61 + 1) {
            c4_l_y[c4_i61] = c4_k_y[c4_i61];
          }

          c4_m_y = 0.0;
          for (c4_c_k = 1; c4_c_k < 4; c4_c_k = c4_c_k + 1) {
            c4_d_k = c4_c_k;
            c4_m_y = c4_m_y + c4_j_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x",
              _SFD_INTEGER_CHECK("k", (real_T)c4_d_k), 1, 3, 1, 0) - 1] *
              c4_l_y[
              _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)
              c4_d_k), 1, 3, 1, 0) - 1];
          }

          c4_f_b = c4_atan2(c4_m_y, c4_trans_mag);
          c4_att = -2.0 * c4_f_b;
          _SFD_EML_CALL(0,78);
          c4_timer = 0.0;
        }
      } else {
        /*  even though not used, pass dir_old through for in case of ~use_bb */
        _SFD_EML_CALL(0,82);
        for (c4_i62 = 0; c4_i62 < 3; c4_i62 = c4_i62 + 1) {
          c4_dir[c4_i62] = c4_dir_old[c4_i62];
        }

        _SFD_EML_CALL(0,83);
        c4_att = c4_att_old;
      }
    }

    /*  Note: cvddes has been set to a default value of cvddes_lin */
    _SFD_EML_CALL(0,88);
    if (CV_EML_IF(0, 10, c4_use_bb != 0.0) != 0.0) {
      _SFD_EML_CALL(0,89);
      for (c4_i63 = 0; c4_i63 < 3; c4_i63 = c4_i63 + 1) {
        c4_d_a[c4_i63] = c4_pqr[c4_i63];
      }

      for (c4_i64 = 0; c4_i64 < 3; c4_i64 = c4_i64 + 1) {
        c4_g_b[c4_i64] = c4_dir[c4_i64];
      }

      for (c4_i65 = 0; c4_i65 < 3; c4_i65 = c4_i65 + 1) {
        c4_k_x[c4_i65] = c4_d_a[c4_i65];
      }

      for (c4_i66 = 0; c4_i66 < 3; c4_i66 = c4_i66 + 1) {
        c4_n_y[c4_i66] = c4_g_b[c4_i66];
      }

      for (c4_i67 = 0; c4_i67 < 3; c4_i67 = c4_i67 + 1) {
        c4_l_x[c4_i67] = c4_k_x[c4_i67];
      }

      for (c4_i68 = 0; c4_i68 < 3; c4_i68 = c4_i68 + 1) {
        c4_o_y[c4_i68] = c4_n_y[c4_i68];
      }

      for (c4_i69 = 0; c4_i69 < 3; c4_i69 = c4_i69 + 1) {
        c4_m_x[c4_i69] = c4_l_x[c4_i69];
      }

      for (c4_i70 = 0; c4_i70 < 3; c4_i70 = c4_i70 + 1) {
        c4_p_y[c4_i70] = c4_o_y[c4_i70];
      }

      for (c4_i71 = 0; c4_i71 < 3; c4_i71 = c4_i71 + 1) {
        c4_n_x[c4_i71] = c4_m_x[c4_i71];
      }

      for (c4_i72 = 0; c4_i72 < 3; c4_i72 = c4_i72 + 1) {
        c4_q_y[c4_i72] = c4_p_y[c4_i72];
      }

      for (c4_i73 = 0; c4_i73 < 3; c4_i73 = c4_i73 + 1) {
        c4_o_x[c4_i73] = c4_n_x[c4_i73];
      }

      for (c4_i74 = 0; c4_i74 < 3; c4_i74 = c4_i74 + 1) {
        c4_r_y[c4_i74] = c4_q_y[c4_i74];
      }

      c4_rate = 0.0;
      for (c4_e_k = 1; c4_e_k < 4; c4_e_k = c4_e_k + 1) {
        c4_f_k = c4_e_k;
        c4_rate = c4_rate + c4_o_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x",
          _SFD_INTEGER_CHECK("k", (real_T)c4_f_k), 1, 3, 1, 0) - 1] * c4_r_y[
          _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)
          c4_f_k), 1, 3, 1, 0) - 1];
      }

      _SFD_EML_CALL(0,90);
      for (c4_i75 = 0; c4_i75 < 9; c4_i75 = c4_i75 + 1) {
        c4_e_a[c4_i75] = c4_inertia[c4_i75];
      }

      for (c4_i76 = 0; c4_i76 < 3; c4_i76 = c4_i76 + 1) {
        c4_h_b[c4_i76] = c4_dir[c4_i76];
      }

      for (c4_i77 = 0; c4_i77 < 9; c4_i77 = c4_i77 + 1) {
        c4_A[c4_i77] = c4_e_a[c4_i77];
      }

      for (c4_i78 = 0; c4_i78 < 3; c4_i78 = c4_i78 + 1) {
        c4_B[c4_i78] = c4_h_b[c4_i78];
      }

      for (c4_i79 = 0; c4_i79 < 9; c4_i79 = c4_i79 + 1) {
        c4_b_A[c4_i79] = c4_A[c4_i79];
      }

      for (c4_i80 = 0; c4_i80 < 3; c4_i80 = c4_i80 + 1) {
        c4_b_B[c4_i80] = c4_B[c4_i80];
      }

      for (c4_i81 = 0; c4_i81 < 9; c4_i81 = c4_i81 + 1) {
        c4_c_A[c4_i81] = c4_b_A[c4_i81];
      }

      for (c4_i82 = 0; c4_i82 < 3; c4_i82 = c4_i82 + 1) {
        c4_c_B[c4_i82] = c4_b_B[c4_i82];
      }

      for (c4_i83 = 0; c4_i83 < 3; c4_i83 = c4_i83 + 1) {
        c4_s_y[c4_i83] = 0.0;
        for (c4_i84 = 0; c4_i84 < 3; c4_i84 = c4_i84 + 1) {
          c4_s_y[c4_i83] = c4_s_y[c4_i83] + c4_c_A[c4_i83 + 3 * c4_i84] *
            c4_c_B[c4_i84];
        }
      }

      for (c4_i85 = 0; c4_i85 < 3; c4_i85 = c4_i85 + 1) {
        c4_t_y[c4_i85] = c4_s_y[c4_i85];
      }

      for (c4_i86 = 0; c4_i86 < 9; c4_i86 = c4_i86 + 1) {
        c4_b_bb_ellipsoid[c4_i86] = c4_bb_ellipsoid[c4_i86];
      }

      c4_accel_max = c4_get_ellipsoid_scaling(c4_t_y, c4_b_bb_ellipsoid);
      _SFD_EML_CALL(0,91);
      c4_accel_min = -c4_accel_max;
      _SFD_EML_CALL(0,92);
      c4_pp_params[0] = c4_accel_max;
      _SFD_EML_CALL(0,93);
      c4_pp_params[1] = c4_accel_min;
      _SFD_EML_CALL(0,94);
      for (c4_i87 = 0; c4_i87 < 6; c4_i87 = c4_i87 + 1) {
        c4_b_pp_params[c4_i87] = c4_pp_params[c4_i87];
      }

      c4_pp(c4_b_pp_params, c4_att, c4_rate, &c4_d1, &c4_d0);
      c4_accel = c4_d0;
      c4_outside = c4_d1;
      _SFD_EML_CALL(0,96);
      if (CV_EML_IF(0, 11, c4_outside <= 1.0)) {
        /*  use default cvddes (cvddes_lin) */
        _SFD_EML_CALL(0,98);
        c4_use_bb = 0.0;
      } else {
        /*  eliminate component of linear command in direction dir */
        _SFD_EML_CALL(0,101);
        for (c4_i88 = 0; c4_i88 < 3; c4_i88 = c4_i88 + 1) {
          c4_f_a[c4_i88] = c4_dir[c4_i88];
        }

        for (c4_i89 = 0; c4_i89 < 3; c4_i89 = c4_i89 + 1) {
          c4_i_b[c4_i89] = c4_cvddes[c4_i89];
        }

        for (c4_i90 = 0; c4_i90 < 3; c4_i90 = c4_i90 + 1) {
          c4_p_x[c4_i90] = c4_f_a[c4_i90];
        }

        for (c4_i91 = 0; c4_i91 < 3; c4_i91 = c4_i91 + 1) {
          c4_u_y[c4_i91] = c4_i_b[c4_i91];
        }

        for (c4_i92 = 0; c4_i92 < 3; c4_i92 = c4_i92 + 1) {
          c4_q_x[c4_i92] = c4_p_x[c4_i92];
        }

        for (c4_i93 = 0; c4_i93 < 3; c4_i93 = c4_i93 + 1) {
          c4_v_y[c4_i93] = c4_u_y[c4_i93];
        }

        for (c4_i94 = 0; c4_i94 < 3; c4_i94 = c4_i94 + 1) {
          c4_r_x[c4_i94] = c4_q_x[c4_i94];
        }

        for (c4_i95 = 0; c4_i95 < 3; c4_i95 = c4_i95 + 1) {
          c4_w_y[c4_i95] = c4_v_y[c4_i95];
        }

        for (c4_i96 = 0; c4_i96 < 3; c4_i96 = c4_i96 + 1) {
          c4_s_x[c4_i96] = c4_r_x[c4_i96];
        }

        for (c4_i97 = 0; c4_i97 < 3; c4_i97 = c4_i97 + 1) {
          c4_x_y[c4_i97] = c4_w_y[c4_i97];
        }

        for (c4_i98 = 0; c4_i98 < 3; c4_i98 = c4_i98 + 1) {
          c4_t_x[c4_i98] = c4_s_x[c4_i98];
        }

        for (c4_i99 = 0; c4_i99 < 3; c4_i99 = c4_i99 + 1) {
          c4_y_y[c4_i99] = c4_x_y[c4_i99];
        }

        c4_g_a = 0.0;
        for (c4_g_k = 1; c4_g_k < 4; c4_g_k = c4_g_k + 1) {
          c4_h_k = c4_g_k;
          c4_g_a = c4_g_a + c4_t_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x",
            _SFD_INTEGER_CHECK("k", (real_T)c4_h_k), 1, 3, 1, 0) - 1] * c4_y_y[
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)
            c4_h_k), 1, 3, 1, 0) - 1];
        }

        for (c4_i100 = 0; c4_i100 < 3; c4_i100 = c4_i100 + 1) {
          c4_j_b[c4_i100] = c4_dir[c4_i100];
        }

        for (c4_i101 = 0; c4_i101 < 3; c4_i101 = c4_i101 + 1) {
          c4_ab_y[c4_i101] = c4_g_a * c4_j_b[c4_i101];
        }

        for (c4_i102 = 0; c4_i102 < 3; c4_i102 = c4_i102 + 1) {
          c4_cvddes[c4_i102] = c4_cvddes[c4_i102] - c4_ab_y[c4_i102];
        }
      }
    } else {
      /*  use default cvddes (cvddes_lin) */
      _SFD_EML_CALL(0,105);
      c4_rate = 0.0;
      _SFD_EML_CALL(0,106);
      c4_outside = 0.0;
      _SFD_EML_CALL(0,107);
      c4_accel = 0.0;
    }

    /*  saturate command at ellipsoid */
    _SFD_EML_CALL(0,111);
    for (c4_i103 = 0; c4_i103 < 3; c4_i103 = c4_i103 + 1) {
      c4_h_a[c4_i103] = c4_cvddes[c4_i103];
    }

    for (c4_i104 = 0; c4_i104 < 9; c4_i104 = c4_i104 + 1) {
      c4_i_a[c4_i104] = c4_inertia[c4_i104];
    }

    for (c4_i105 = 0; c4_i105 < 3; c4_i105 = c4_i105 + 1) {
      c4_k_b[c4_i105] = c4_cvddes[c4_i105];
    }

    for (c4_i106 = 0; c4_i106 < 9; c4_i106 = c4_i106 + 1) {
      c4_d_A[c4_i106] = c4_i_a[c4_i106];
    }

    for (c4_i107 = 0; c4_i107 < 3; c4_i107 = c4_i107 + 1) {
      c4_d_B[c4_i107] = c4_k_b[c4_i107];
    }

    for (c4_i108 = 0; c4_i108 < 9; c4_i108 = c4_i108 + 1) {
      c4_e_A[c4_i108] = c4_d_A[c4_i108];
    }

    for (c4_i109 = 0; c4_i109 < 3; c4_i109 = c4_i109 + 1) {
      c4_e_B[c4_i109] = c4_d_B[c4_i109];
    }

    for (c4_i110 = 0; c4_i110 < 9; c4_i110 = c4_i110 + 1) {
      c4_f_A[c4_i110] = c4_e_A[c4_i110];
    }

    for (c4_i111 = 0; c4_i111 < 3; c4_i111 = c4_i111 + 1) {
      c4_f_B[c4_i111] = c4_e_B[c4_i111];
    }

    for (c4_i112 = 0; c4_i112 < 3; c4_i112 = c4_i112 + 1) {
      c4_bb_y[c4_i112] = 0.0;
      for (c4_i113 = 0; c4_i113 < 3; c4_i113 = c4_i113 + 1) {
        c4_bb_y[c4_i112] = c4_bb_y[c4_i112] + c4_f_A[c4_i112 + 3 * c4_i113] *
          c4_f_B[c4_i113];
      }
    }

    for (c4_i114 = 0; c4_i114 < 3; c4_i114 = c4_i114 + 1) {
      c4_cb_y[c4_i114] = c4_bb_y[c4_i114];
    }

    for (c4_i115 = 0; c4_i115 < 9; c4_i115 = c4_i115 + 1) {
      c4_c_bb_ellipsoid[c4_i115] = c4_bb_ellipsoid[c4_i115];
    }

    c4_l_b = c4_min(c4_get_ellipsoid_scaling(c4_cb_y, c4_c_bb_ellipsoid), 1.0);
    for (c4_i116 = 0; c4_i116 < 3; c4_i116 = c4_i116 + 1) {
      c4_blend_lin_claw[c4_i116] = c4_h_a[c4_i116] * c4_l_b;
    }

    /*  add component from bangbang */
    _SFD_EML_CALL(0,114);
    c4_j_a = c4_accel;
    for (c4_i117 = 0; c4_i117 < 3; c4_i117 = c4_i117 + 1) {
      c4_m_b[c4_i117] = c4_dir[c4_i117];
    }

    for (c4_i118 = 0; c4_i118 < 3; c4_i118 = c4_i118 + 1) {
      c4_blend_bb_claw[c4_i118] = c4_j_a * c4_m_b[c4_i118];
    }

    _SFD_EML_CALL(0,115);
    for (c4_i119 = 0; c4_i119 < 3; c4_i119 = c4_i119 + 1) {
      c4_cvddes[c4_i119] = c4_blend_lin_claw[c4_i119] + c4_blend_bb_claw[c4_i119];
    }

    _SFD_EML_CALL(0,117);
    for (c4_i120 = 0; c4_i120 < 9; c4_i120 = c4_i120 + 1) {
      c4_k_a[c4_i120] = c4_inertia[c4_i120];
    }

    for (c4_i121 = 0; c4_i121 < 3; c4_i121 = c4_i121 + 1) {
      c4_n_b[c4_i121] = c4_cvddes[c4_i121];
    }

    for (c4_i122 = 0; c4_i122 < 9; c4_i122 = c4_i122 + 1) {
      c4_g_A[c4_i122] = c4_k_a[c4_i122];
    }

    for (c4_i123 = 0; c4_i123 < 3; c4_i123 = c4_i123 + 1) {
      c4_g_B[c4_i123] = c4_n_b[c4_i123];
    }

    for (c4_i124 = 0; c4_i124 < 9; c4_i124 = c4_i124 + 1) {
      c4_h_A[c4_i124] = c4_g_A[c4_i124];
    }

    for (c4_i125 = 0; c4_i125 < 3; c4_i125 = c4_i125 + 1) {
      c4_h_B[c4_i125] = c4_g_B[c4_i125];
    }

    for (c4_i126 = 0; c4_i126 < 9; c4_i126 = c4_i126 + 1) {
      c4_i_A[c4_i126] = c4_h_A[c4_i126];
    }

    for (c4_i127 = 0; c4_i127 < 3; c4_i127 = c4_i127 + 1) {
      c4_i_B[c4_i127] = c4_h_B[c4_i127];
    }

    for (c4_i128 = 0; c4_i128 < 3; c4_i128 = c4_i128 + 1) {
      c4_db_y[c4_i128] = 0.0;
      for (c4_i129 = 0; c4_i129 < 3; c4_i129 = c4_i129 + 1) {
        c4_db_y[c4_i128] = c4_db_y[c4_i128] + c4_i_A[c4_i128 + 3 * c4_i129] *
          c4_i_B[c4_i129];
      }
    }

    for (c4_i130 = 0; c4_i130 < 3; c4_i130 = c4_i130 + 1) {
      c4_eb_y[c4_i130] = c4_db_y[c4_i130];
    }

    for (c4_i131 = 0; c4_i131 < 9; c4_i131 = c4_i131 + 1) {
      c4_d_bb_ellipsoid[c4_i131] = c4_bb_ellipsoid[c4_i131];
    }

    c4_j_B = c4_get_ellipsoid_scaling(c4_eb_y, c4_d_bb_ellipsoid);
    c4_fb_y = c4_j_B;
    if (c4_fb_y == 0.0) {
      c4_eml_warning();
    }

    c4_gb_y = c4_fb_y;
    c4_hb_y = c4_gb_y;
    c4_pp_utQu = 1.0 / c4_hb_y;
    _SFD_EML_CALL(0,118);
    c4_debug_output[0] = c4_att;
    c4_debug_output[1] = c4_att_old;
    c4_debug_output[2] = c4_rate;
    c4_debug_output[3] = c4_outside;
    c4_debug_output[4] = c4_accel;
    c4_debug_output[5] = c4_pp_utQu;
    for (c4_i132 = 0; c4_i132 < 3; c4_i132 = c4_i132 + 1) {
      c4_debug_output[c4_i132 + 6] = c4_blend_bb_claw[c4_i132];
    }

    for (c4_i133 = 0; c4_i133 < 3; c4_i133 = c4_i133 + 1) {
      c4_debug_output[c4_i133 + 9] = c4_blend_lin_claw[c4_i133];
    }

    _SFD_EML_CALL(0,120);
    if (CV_EML_IF(0, 12, CV_EML_MCDC(0, 3, !(CV_EML_COND(0, 3, c4_use_bb != 0.0)
           != 0.0)))) {
      /*  if not using bangbang reset the timer, and set dir to zero */
      _SFD_EML_CALL(0,123);
      c4_timer = 0.0;

      /*  dir used for cvd_des blending is now zeroed outside of this block, */
      /*  so that dir can be retained through a temporary ~use_bb condition */
      /*      dir = 0*dir ; */
    }
  }

  _SFD_EML_CALL(0,-123);
  sf_debug_symbol_scope_pop();
  for (c4_i134 = 0; c4_i134 < 12; c4_i134 = c4_i134 + 1) {
    (*c4_b_debug_output)[c4_i134] = c4_debug_output[c4_i134];
  }

  for (c4_i135 = 0; c4_i135 < 3; c4_i135 = c4_i135 + 1) {
    (*c4_b_cvddes)[c4_i135] = c4_cvddes[c4_i135];
  }

  for (c4_i136 = 0; c4_i136 < 3; c4_i136 = c4_i136 + 1) {
    (*c4_b_dir)[c4_i136] = c4_dir[c4_i136];
  }

  *c4_b_use_bb = c4_use_bb;
  *c4_b_timer = c4_timer;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static void c4_qmpy(real_T c4_p[4], real_T c4_q[4], real_T c4_r[4])
{
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 2.0;
  real_T c4_r3;
  real_T c4_r2;
  real_T c4_r1;
  real_T c4_r0;
  real_T c4_q3;
  real_T c4_q2;
  real_T c4_q1;
  real_T c4_q0;
  real_T c4_p3;
  real_T c4_p2;
  real_T c4_p1;
  real_T c4_p0;
  real_T c4_a;
  real_T c4_b;
  real_T c4_y;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_b_y;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_y;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_d_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_e_y;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_h_y;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_i_y;
  real_T c4_j_a;
  real_T c4_j_b;
  real_T c4_j_y;
  real_T c4_k_a;
  real_T c4_k_b;
  real_T c4_k_y;
  real_T c4_l_a;
  real_T c4_l_b;
  real_T c4_l_y;
  real_T c4_m_a;
  real_T c4_m_b;
  real_T c4_m_y;
  real_T c4_n_a;
  real_T c4_n_b;
  real_T c4_n_y;
  real_T c4_o_a;
  real_T c4_o_b;
  real_T c4_o_y;
  real_T c4_p_a;
  real_T c4_p_b;
  real_T c4_p_y;
  real_T c4_b_r0[4];
  int32_T c4_i137;
  sf_debug_symbol_scope_push(17U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("r3", &c4_r3, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("r2", &c4_r2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("r1", &c4_r1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("r0", &c4_r0, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("q3", &c4_q3, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("q2", &c4_q2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("q1", &c4_q1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("q0", &c4_q0, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("p3", &c4_p3, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("p2", &c4_p2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("p1", &c4_p1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("p0", &c4_p0, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("r", c4_r, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("q", c4_q, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("p", c4_p, c4_c_sf_marshall);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0,131);
  c4_p0 = c4_p[0];
  _SFD_EML_CALL(0,132);
  c4_p1 = c4_p[1];
  _SFD_EML_CALL(0,133);
  c4_p2 = c4_p[2];
  _SFD_EML_CALL(0,134);
  c4_p3 = c4_p[3];
  _SFD_EML_CALL(0,136);
  c4_q0 = c4_q[0];
  _SFD_EML_CALL(0,137);
  c4_q1 = c4_q[1];
  _SFD_EML_CALL(0,138);
  c4_q2 = c4_q[2];
  _SFD_EML_CALL(0,139);
  c4_q3 = c4_q[3];
  _SFD_EML_CALL(0,141);
  c4_a = c4_p3;
  c4_b = c4_q3;
  c4_y = c4_a * c4_b;
  c4_b_a = c4_p2;
  c4_b_b = c4_q2;
  c4_b_y = c4_b_a * c4_b_b;
  c4_c_a = c4_p1;
  c4_c_b = c4_q1;
  c4_c_y = c4_c_a * c4_c_b;
  c4_d_a = c4_p0;
  c4_d_b = c4_q0;
  c4_d_y = c4_d_a * c4_d_b;
  c4_r0 = ((c4_d_y - c4_c_y) - c4_b_y) - c4_y;
  _SFD_EML_CALL(0,142);
  c4_e_a = c4_p3;
  c4_e_b = c4_q2;
  c4_e_y = c4_e_a * c4_e_b;
  c4_f_a = c4_p2;
  c4_f_b = c4_q3;
  c4_f_y = c4_f_a * c4_f_b;
  c4_g_a = c4_p1;
  c4_g_b = c4_q0;
  c4_g_y = c4_g_a * c4_g_b;
  c4_h_a = c4_p0;
  c4_h_b = c4_q1;
  c4_h_y = c4_h_a * c4_h_b;
  c4_r1 = ((c4_h_y + c4_g_y) + c4_f_y) - c4_e_y;
  _SFD_EML_CALL(0,143);
  c4_i_a = c4_p3;
  c4_i_b = c4_q1;
  c4_i_y = c4_i_a * c4_i_b;
  c4_j_a = c4_p2;
  c4_j_b = c4_q0;
  c4_j_y = c4_j_a * c4_j_b;
  c4_k_a = c4_p1;
  c4_k_b = c4_q3;
  c4_k_y = c4_k_a * c4_k_b;
  c4_l_a = c4_p0;
  c4_l_b = c4_q2;
  c4_l_y = c4_l_a * c4_l_b;
  c4_r2 = ((c4_l_y - c4_k_y) + c4_j_y) + c4_i_y;
  _SFD_EML_CALL(0,144);
  c4_m_a = c4_p3;
  c4_m_b = c4_q0;
  c4_m_y = c4_m_a * c4_m_b;
  c4_n_a = c4_p2;
  c4_n_b = c4_q1;
  c4_n_y = c4_n_a * c4_n_b;
  c4_o_a = c4_p1;
  c4_o_b = c4_q2;
  c4_o_y = c4_o_a * c4_o_b;
  c4_p_a = c4_p0;
  c4_p_b = c4_q3;
  c4_p_y = c4_p_a * c4_p_b;
  c4_r3 = ((c4_p_y + c4_o_y) - c4_n_y) + c4_m_y;
  _SFD_EML_CALL(0,146);
  c4_b_r0[0] = c4_r0;
  c4_b_r0[1] = c4_r1;
  c4_b_r0[2] = c4_r2;
  c4_b_r0[3] = c4_r3;
  for (c4_i137 = 0; c4_i137 < 4; c4_i137 = c4_i137 + 1) {
    c4_r[c4_i137] = c4_b_r0[c4_i137];
  }

  _SFD_EML_CALL(0,-146);
  sf_debug_symbol_scope_pop();
}

static real_T c4_norm_vec3(real_T c4_in[3])
{
  real_T c4_out;
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 1.0;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("out", &c4_out, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("in", c4_in, c4_d_sf_marshall);
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0,214);
  c4_x = (c4_mpower(c4_in[0]) + c4_mpower(c4_in[1])) + c4_mpower(c4_in[2]);
  c4_out = c4_x;
  if (c4_out < 0.0) {
    c4_eml_error();
  }

  c4_b_x = c4_out;
  c4_c_x = c4_b_x;
  c4_c_x = muDoubleScalarSqrt(c4_c_x);
  c4_out = c4_c_x;
  _SFD_EML_CALL(0,-214);
  sf_debug_symbol_scope_pop();
  return c4_out;
}

static real_T c4_mpower(real_T c4_a)
{
  real_T c4_b_a;
  real_T c4_ak;
  c4_b_a = c4_a;
  c4_ak = c4_b_a;
  return muDoubleScalarPower(c4_ak, 2.0);
}

static void c4_eml_error(void)
{
  int32_T c4_i138;
  static char_T c4_varargin_1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[31];
  const mxArray *c4_y = NULL;
  int32_T c4_i139;
  static char_T c4_varargin_2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e',
    'r', 'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o',
    'm', 'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r',
    'e', 's', 'u', 'l',
    't', 's', ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',',
    ' ', 'u', 's', 'e',
    ' ', '\'', 's', 'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'x', ')', ')', '\''
    , '.' };

  char_T c4_b_u[77];
  const mxArray *c4_b_y = NULL;
  for (c4_i138 = 0; c4_i138 < 31; c4_i138 = c4_i138 + 1) {
    c4_u[c4_i138] = c4_varargin_1[c4_i138];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c4_i139 = 0; c4_i139 < 77; c4_i139 = c4_i139 + 1) {
    c4_b_u[c4_i139] = c4_varargin_2[c4_i139];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call("error", 0U, 2U, 14, c4_y, 14, c4_b_y);
}

static real_T c4_atan2(real_T c4_y, real_T c4_x)
{
  real_T c4_b_y;
  real_T c4_b_x;
  real_T c4_b_r;
  c4_b_y = c4_y;
  c4_b_x = c4_x;
  c4_b_r = muDoubleScalarAtan2(c4_b_y, c4_b_x);
  return c4_b_r;
}

static real_T c4_abs(real_T c4_x)
{
  real_T c4_b_x;
  real_T c4_b_y;
  c4_b_x = c4_x;
  c4_b_y = muDoubleScalarAbs(c4_b_x);
  return c4_b_y;
}

static void c4_mrdivide(real_T c4_A[3], real_T c4_B, real_T c4_y[3])
{
  int32_T c4_i140;
  real_T c4_x[3];
  real_T c4_b_y;
  int32_T c4_i141;
  real_T c4_b_x[3];
  real_T c4_c_y;
  int32_T c4_i142;
  real_T c4_c_x[3];
  real_T c4_d_y;
  int32_T c4_i143;
  for (c4_i140 = 0; c4_i140 < 3; c4_i140 = c4_i140 + 1) {
    c4_x[c4_i140] = c4_A[c4_i140];
  }

  c4_b_y = c4_B;
  if (c4_b_y == 0.0) {
    c4_eml_warning();
  }

  for (c4_i141 = 0; c4_i141 < 3; c4_i141 = c4_i141 + 1) {
    c4_b_x[c4_i141] = c4_x[c4_i141];
  }

  c4_c_y = c4_b_y;
  for (c4_i142 = 0; c4_i142 < 3; c4_i142 = c4_i142 + 1) {
    c4_c_x[c4_i142] = c4_b_x[c4_i142];
  }

  c4_d_y = c4_c_y;
  for (c4_i143 = 0; c4_i143 < 3; c4_i143 = c4_i143 + 1) {
    c4_y[c4_i143] = c4_c_x[c4_i143] / c4_d_y;
  }
}

static void c4_eml_warning(void)
{
  int32_T c4_i144;
  static char_T c4_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c4_u[19];
  const mxArray *c4_y = NULL;
  int32_T c4_i145;
  static char_T c4_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c4_b_u[15];
  const mxArray *c4_b_y = NULL;
  for (c4_i144 = 0; c4_i144 < 19; c4_i144 = c4_i144 + 1) {
    c4_u[c4_i144] = c4_varargin_1[c4_i144];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c4_i145 = 0; c4_i145 < 15; c4_i145 = c4_i145 + 1) {
    c4_b_u[c4_i145] = c4_varargin_2[c4_i145];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c4_y, 14, c4_b_y);
}

static void c4_b_abs(real_T c4_x[3], real_T c4_y[3])
{
  int32_T c4_i146;
  real_T c4_k;
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_b_y;
  for (c4_i146 = 0; c4_i146 < 3; c4_i146 = c4_i146 + 1) {
    c4_y[c4_i146] = 0.0;
  }

  for (c4_k = 1.0; c4_k <= 3.0; c4_k = c4_k + 1.0) {
    c4_b_k = c4_k;
    c4_b_x = c4_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK(
      "k", c4_b_k), 1, 3, 1, 0) - 1];
    c4_b_y = muDoubleScalarAbs(c4_b_x);
    c4_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k",
      c4_b_k), 1, 3, 1, 0) - 1] = c4_b_y;
  }
}

static real_T c4_max(real_T c4_varargin_1[3])
{
  int32_T c4_i147;
  real_T c4_x[3];
  int32_T c4_i148;
  real_T c4_b_x[3];
  real_T c4_mtmp;
  int32_T c4_ix;
  int32_T c4_k;
  int32_T c4_a;
  real_T c4_c_x;
  boolean_T c4_b;
  real_T c4_d_x;
  boolean_T c4_b_b;
  for (c4_i147 = 0; c4_i147 < 3; c4_i147 = c4_i147 + 1) {
    c4_x[c4_i147] = c4_varargin_1[c4_i147];
  }

  for (c4_i148 = 0; c4_i148 < 3; c4_i148 = c4_i148 + 1) {
    c4_b_x[c4_i148] = c4_x[c4_i148];
  }

  c4_mtmp = c4_b_x[0];
  c4_ix = 1;
  for (c4_k = 2; c4_k < 4; c4_k = c4_k + 1) {
    c4_a = c4_ix;
    c4_ix = c4_a + 1;
    c4_c_x = c4_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix",
      (real_T)c4_ix), 1, 3, 1, 0) - 1];
    c4_b = rtIsNaN(c4_c_x);
    if (!c4_b) {
      c4_d_x = c4_mtmp;
      c4_b_b = rtIsNaN(c4_d_x);
      if (c4_b_b) {
        goto label_1;
      } else {
        if (c4_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix",
              (real_T)c4_ix), 1, 3, 1, 0) - 1] > c4_mtmp) {
          goto label_1;
        }
      }
    }

    goto label_2;
   label_1:
    ;
    c4_mtmp = c4_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix",
      (real_T)c4_ix), 1, 3, 1, 0) - 1];
   label_2:
    ;
  }

  return c4_mtmp;
}

static real_T c4_get_ellipsoid_scaling(real_T c4_dir[3], real_T c4_ellipsoid[9])
{
  real_T c4_scale;
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 2.0;
  int32_T c4_i149;
  real_T c4_a[3];
  int32_T c4_i150;
  real_T c4_b_a[9];
  int32_T c4_i151;
  real_T c4_b[3];
  int32_T c4_i152;
  real_T c4_A[9];
  int32_T c4_i153;
  real_T c4_B[3];
  int32_T c4_i154;
  real_T c4_b_A[9];
  int32_T c4_i155;
  real_T c4_b_B[3];
  int32_T c4_i156;
  real_T c4_c_A[9];
  int32_T c4_i157;
  real_T c4_c_B[3];
  int32_T c4_i158;
  real_T c4_b_b[3];
  int32_T c4_i159;
  int32_T c4_i160;
  real_T c4_x[3];
  int32_T c4_i161;
  real_T c4_y[3];
  int32_T c4_i162;
  real_T c4_b_x[3];
  int32_T c4_i163;
  real_T c4_b_y[3];
  int32_T c4_i164;
  real_T c4_c_x[3];
  int32_T c4_i165;
  real_T c4_c_y[3];
  int32_T c4_i166;
  real_T c4_d_x[3];
  int32_T c4_i167;
  real_T c4_d_y[3];
  int32_T c4_i168;
  real_T c4_e_x[3];
  int32_T c4_i169;
  real_T c4_e_y[3];
  real_T c4_f_x;
  int32_T c4_k;
  int32_T c4_b_k;
  real_T c4_varargin_1;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_d_B;
  real_T c4_f_y;
  real_T c4_g_y;
  real_T c4_h_y;
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("scale", &c4_scale, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("ellipsoid", c4_ellipsoid, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("dir", c4_dir, c4_d_sf_marshall);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0,149);
  for (c4_i149 = 0; c4_i149 < 3; c4_i149 = c4_i149 + 1) {
    c4_a[c4_i149] = c4_dir[c4_i149];
  }

  for (c4_i150 = 0; c4_i150 < 9; c4_i150 = c4_i150 + 1) {
    c4_b_a[c4_i150] = c4_ellipsoid[c4_i150];
  }

  for (c4_i151 = 0; c4_i151 < 3; c4_i151 = c4_i151 + 1) {
    c4_b[c4_i151] = c4_dir[c4_i151];
  }

  for (c4_i152 = 0; c4_i152 < 9; c4_i152 = c4_i152 + 1) {
    c4_A[c4_i152] = c4_b_a[c4_i152];
  }

  for (c4_i153 = 0; c4_i153 < 3; c4_i153 = c4_i153 + 1) {
    c4_B[c4_i153] = c4_b[c4_i153];
  }

  for (c4_i154 = 0; c4_i154 < 9; c4_i154 = c4_i154 + 1) {
    c4_b_A[c4_i154] = c4_A[c4_i154];
  }

  for (c4_i155 = 0; c4_i155 < 3; c4_i155 = c4_i155 + 1) {
    c4_b_B[c4_i155] = c4_B[c4_i155];
  }

  for (c4_i156 = 0; c4_i156 < 9; c4_i156 = c4_i156 + 1) {
    c4_c_A[c4_i156] = c4_b_A[c4_i156];
  }

  for (c4_i157 = 0; c4_i157 < 3; c4_i157 = c4_i157 + 1) {
    c4_c_B[c4_i157] = c4_b_B[c4_i157];
  }

  for (c4_i158 = 0; c4_i158 < 3; c4_i158 = c4_i158 + 1) {
    c4_b_b[c4_i158] = 0.0;
    for (c4_i159 = 0; c4_i159 < 3; c4_i159 = c4_i159 + 1) {
      c4_b_b[c4_i158] = c4_b_b[c4_i158] + c4_c_A[c4_i158 + 3 * c4_i159] *
        c4_c_B[c4_i159];
    }
  }

  for (c4_i160 = 0; c4_i160 < 3; c4_i160 = c4_i160 + 1) {
    c4_x[c4_i160] = c4_a[c4_i160];
  }

  for (c4_i161 = 0; c4_i161 < 3; c4_i161 = c4_i161 + 1) {
    c4_y[c4_i161] = c4_b_b[c4_i161];
  }

  for (c4_i162 = 0; c4_i162 < 3; c4_i162 = c4_i162 + 1) {
    c4_b_x[c4_i162] = c4_x[c4_i162];
  }

  for (c4_i163 = 0; c4_i163 < 3; c4_i163 = c4_i163 + 1) {
    c4_b_y[c4_i163] = c4_y[c4_i163];
  }

  for (c4_i164 = 0; c4_i164 < 3; c4_i164 = c4_i164 + 1) {
    c4_c_x[c4_i164] = c4_b_x[c4_i164];
  }

  for (c4_i165 = 0; c4_i165 < 3; c4_i165 = c4_i165 + 1) {
    c4_c_y[c4_i165] = c4_b_y[c4_i165];
  }

  for (c4_i166 = 0; c4_i166 < 3; c4_i166 = c4_i166 + 1) {
    c4_d_x[c4_i166] = c4_c_x[c4_i166];
  }

  for (c4_i167 = 0; c4_i167 < 3; c4_i167 = c4_i167 + 1) {
    c4_d_y[c4_i167] = c4_c_y[c4_i167];
  }

  for (c4_i168 = 0; c4_i168 < 3; c4_i168 = c4_i168 + 1) {
    c4_e_x[c4_i168] = c4_d_x[c4_i168];
  }

  for (c4_i169 = 0; c4_i169 < 3; c4_i169 = c4_i169 + 1) {
    c4_e_y[c4_i169] = c4_d_y[c4_i169];
  }

  c4_f_x = 0.0;
  for (c4_k = 1; c4_k < 4; c4_k = c4_k + 1) {
    c4_b_k = c4_k;
    c4_f_x = c4_f_x + c4_e_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK
      ("k", (real_T)c4_b_k), 1, 3, 1, 0) - 1] * c4_e_y[
      _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k", (real_T)c4_b_k),
      1, 3, 1, 0) - 1];
  }

  c4_varargin_1 = c4_f_x;
  if (c4_varargin_1 < 0.0) {
    c4_eml_error();
  }

  c4_g_x = c4_varargin_1;
  c4_h_x = c4_g_x;
  c4_h_x = muDoubleScalarSqrt(c4_h_x);
  c4_varargin_1 = c4_h_x;
  c4_i_x = c4_varargin_1;
  c4_d_B = c4_eml_bin_extremum(true, c4_i_x, 1.0E-012);
  c4_f_y = c4_d_B;
  if (c4_f_y == 0.0) {
    c4_eml_warning();
  }

  c4_g_y = c4_f_y;
  c4_h_y = c4_g_y;
  c4_scale = 1.0 / c4_h_y;
  _SFD_EML_CALL(0,-149);
  sf_debug_symbol_scope_pop();
  return c4_scale;
}

static real_T c4_eml_bin_extremum(boolean_T c4_domax, real_T c4_x, real_T c4_y)
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

static void c4_pp(real_T c4_params[6], real_T c4_att, real_T c4_rate, real_T
                  *c4_outside, real_T *c4_accel)
{
  real_T c4_nargout = 2.0;
  real_T c4_nargin = 3.0;
  real_T c4_p2[2];
  real_T c4_p1[2];
  real_T c4_sv2;
  real_T c4_sx2;
  real_T c4_sv1;
  real_T c4_sx1;
  real_T c4_swcurve_neg;
  real_T c4_swcurve_pos;
  real_T c4_swcurve_shrink;
  real_T c4_rate_des2;
  real_T c4_rate_des1;
  real_T c4_zeta;
  real_T c4_ww;
  real_T c4_amin;
  real_T c4_amax;
  real_T c4_b;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_y;
  real_T c4_c_b;
  real_T c4_b_y;
  real_T c4_d_b;
  real_T c4_b_a;
  real_T c4_e_b;
  real_T c4_c_y;
  real_T c4_f_b;
  real_T c4_d_y;
  real_T c4_g_b;
  real_T c4_e_y;
  real_T c4_h_b;
  real_T c4_f_y;
  real_T c4_i_b;
  real_T c4_g_y;
  real_T c4_j_b;
  real_T c4_k_b;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_h_y;
  real_T c4_b_x;
  real_T c4_i_y;
  real_T c4_c_x;
  real_T c4_j_y;
  real_T c4_c_a;
  int32_T c4_i170;
  real_T c4_b_A[4];
  int32_T c4_i171;
  real_T c4_d_a;
  real_T c4_l_b;
  real_T c4_k_y;
  real_T c4_b_B[2];
  int32_T c4_i172;
  real_T c4_c_A[4];
  int32_T c4_i173;
  real_T c4_c_B[2];
  int32_T c4_i174;
  real_T c4_d_A[4];
  int32_T c4_i175;
  real_T c4_d_B[2];
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_l_y;
  real_T c4_m_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_n_y;
  real_T c4_o_y;
  real_T c4_d;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_p_y;
  real_T c4_q_y;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_r_y;
  real_T c4_s_y;
  real_T c4_b_d;
  int32_T c4_r1;
  int32_T c4_r2;
  real_T c4_n_x;
  real_T c4_t_y;
  real_T c4_o_x;
  real_T c4_u_y;
  real_T c4_a21;
  real_T c4_e_a;
  real_T c4_m_b;
  real_T c4_v_y;
  real_T c4_a22;
  real_T c4_f_a;
  real_T c4_n_b;
  real_T c4_w_y;
  real_T c4_p_x;
  real_T c4_x_y;
  real_T c4_q_x;
  real_T c4_y_y;
  real_T c4_z;
  real_T c4_r_x[2];
  real_T c4_g_a;
  real_T c4_o_b;
  real_T c4_ab_y;
  real_T c4_s_x;
  real_T c4_bb_y;
  real_T c4_t_x;
  real_T c4_cb_y;
  real_T c4_b_z;
  int32_T c4_i176;
  real_T c4_varargin_1[2];
  real_T c4_k;
  real_T c4_b_k;
  real_T c4_u_x;
  real_T c4_db_y;
  int32_T c4_i177;
  real_T c4_v_x[2];
  int32_T c4_i178;
  real_T c4_w_x[2];
  real_T c4_mtmp;
  real_T c4_x_x;
  boolean_T c4_p_b;
  real_T c4_y_x;
  boolean_T c4_q_b;
  real_T c4_r_b;
  sf_debug_symbol_scope_push(22U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("p2", &c4_p2, c4_h_sf_marshall);
  sf_debug_symbol_scope_add("p1", &c4_p1, c4_h_sf_marshall);
  sf_debug_symbol_scope_add("sv2", &c4_sv2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("sx2", &c4_sx2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("sv1", &c4_sv1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("sx1", &c4_sx1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("swcurve_neg", &c4_swcurve_neg, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("swcurve_pos", &c4_swcurve_pos, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("swcurve_shrink", &c4_swcurve_shrink,
    c4_e_sf_marshall);
  sf_debug_symbol_scope_add("rate_des2", &c4_rate_des2, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("rate_des1", &c4_rate_des1, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("zeta", &c4_zeta, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("ww", &c4_ww, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("amin", &c4_amin, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("amax", &c4_amax, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("accel", c4_accel, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("outside", c4_outside, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("rate", &c4_rate, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("att", &c4_att, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("params", c4_params, c4_g_sf_marshall);
  CV_EML_FCN(0, 3);

  /*  the linear control law is */
  /*  accel = ww^2 * ( att_cmd - att ) - 2 * zeta * ww * rate */
  _SFD_EML_CALL(0,156);
  c4_amax = c4_params[0];
  _SFD_EML_CALL(0,157);
  c4_amin = c4_params[1];
  _SFD_EML_CALL(0,158);
  c4_ww = c4_params[2];
  _SFD_EML_CALL(0,159);
  c4_zeta = c4_params[3];
  _SFD_EML_CALL(0,160);
  c4_rate_des1 = c4_params[4];
  _SFD_EML_CALL(0,161);
  c4_rate_des2 = c4_params[5];

  /*  make switch curves conservative */
  _SFD_EML_CALL(0,164);
  c4_swcurve_shrink = 1.0;
  _SFD_EML_CALL(0,166);
  c4_b = c4_amin;
  c4_a = c4_b;
  c4_b_b = c4_att;
  c4_y = c4_a * c4_b_b;
  c4_c_b = c4_mpower(c4_rate);
  c4_b_y = 0.5 * c4_c_b;
  c4_swcurve_pos = c4_b_y - c4_y;
  _SFD_EML_CALL(0,167);
  c4_d_b = c4_amax;
  c4_b_a = c4_d_b;
  c4_e_b = c4_att;
  c4_c_y = c4_b_a * c4_e_b;
  c4_f_b = c4_mpower(c4_rate);
  c4_d_y = 0.5 * c4_f_b;
  c4_swcurve_neg = c4_d_y - c4_c_y;

  /*  replace ellipse with parallelogram */
  /*  outside = ( ww^2 * att^2 + 2 * zeta * ww * att * rate + rate^2 ) / ( ( 1 - zeta^2 ) * amax^2 / ww^2 ) ; */
  _SFD_EML_CALL(0,171);
  c4_g_b = c4_mpower(c4_zeta);
  c4_e_y = 4.0 * c4_g_b;
  c4_sx1 = (1.0 + c4_zeta) + c4_e_y;
  _SFD_EML_CALL(0,172);
  c4_h_b = c4_zeta;
  c4_f_y = 2.0 * c4_h_b;
  c4_sv1 = -0.5 - c4_f_y;
  _SFD_EML_CALL(0,173);
  c4_i_b = c4_mpower(c4_zeta);
  c4_g_y = 4.0 * c4_i_b;
  c4_sx2 = 1.0 - c4_g_y;
  _SFD_EML_CALL(0,174);
  c4_j_b = c4_zeta;
  c4_sv2 = 2.0 * c4_j_b;
  _SFD_EML_CALL(0,175);
  c4_p1[0] = c4_sx1;
  c4_p1[1] = c4_sv1;
  _SFD_EML_CALL(0,176);
  c4_p2[0] = c4_sx2;
  c4_p2[1] = c4_sv2;
  _SFD_EML_CALL(0,178);
  c4_k_b = c4_ww;
  c4_A = 2.0 * c4_k_b;
  c4_B = c4_amax;
  c4_x = c4_A;
  c4_h_y = c4_B;
  if (c4_h_y == 0.0) {
    c4_eml_warning();
  }

  c4_b_x = c4_x;
  c4_i_y = c4_h_y;
  c4_c_x = c4_b_x;
  c4_j_y = c4_i_y;
  c4_c_a = c4_c_x / c4_j_y;
  for (c4_i170 = 0; c4_i170 < 2; c4_i170 = c4_i170 + 1) {
    c4_b_A[c4_i170] = c4_p2[c4_i170] + c4_p1[c4_i170];
  }

  for (c4_i171 = 0; c4_i171 < 2; c4_i171 = c4_i171 + 1) {
    c4_b_A[c4_i171 + 2] = c4_p2[c4_i171] - c4_p1[c4_i171];
  }

  c4_d_a = c4_att;
  c4_l_b = c4_ww;
  c4_k_y = c4_d_a * c4_l_b;
  c4_b_B[0] = c4_k_y;
  c4_b_B[1] = c4_rate;
  for (c4_i172 = 0; c4_i172 < 4; c4_i172 = c4_i172 + 1) {
    c4_c_A[c4_i172] = c4_b_A[c4_i172];
  }

  for (c4_i173 = 0; c4_i173 < 2; c4_i173 = c4_i173 + 1) {
    c4_c_B[c4_i173] = c4_b_B[c4_i173];
  }

  for (c4_i174 = 0; c4_i174 < 4; c4_i174 = c4_i174 + 1) {
    c4_d_A[c4_i174] = c4_c_A[c4_i174];
  }

  for (c4_i175 = 0; c4_i175 < 2; c4_i175 = c4_i175 + 1) {
    c4_d_B[c4_i175] = c4_c_B[c4_i175];
  }

  c4_d_x = c4_d_A[0];
  c4_e_x = 0.0;
  c4_f_x = c4_e_x;
  c4_l_y = muDoubleScalarAbs(c4_f_x);
  c4_m_y = c4_l_y;
  c4_g_x = c4_d_x;
  c4_h_x = c4_g_x;
  c4_n_y = muDoubleScalarAbs(c4_h_x);
  c4_o_y = c4_n_y;
  c4_d = c4_o_y + c4_m_y;
  c4_i_x = c4_d_A[1];
  c4_j_x = 0.0;
  c4_k_x = c4_j_x;
  c4_p_y = muDoubleScalarAbs(c4_k_x);
  c4_q_y = c4_p_y;
  c4_l_x = c4_i_x;
  c4_m_x = c4_l_x;
  c4_r_y = muDoubleScalarAbs(c4_m_x);
  c4_s_y = c4_r_y;
  c4_b_d = c4_s_y + c4_q_y;
  if (c4_b_d > c4_d) {
    c4_r1 = 2;
    c4_r2 = 1;
  } else {
    c4_r1 = 1;
    c4_r2 = 2;
  }

  c4_n_x = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r2",
    (real_T)c4_r2), 1, 2, 1, 0) - 1];
  c4_t_y = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) - 1];
  c4_o_x = c4_n_x;
  c4_u_y = c4_t_y;
  c4_a21 = c4_o_x / c4_u_y;
  c4_e_a = c4_a21;
  c4_m_b = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) + 1];
  c4_v_y = c4_e_a * c4_m_b;
  c4_a22 = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r2",
    (real_T)c4_r2), 1, 2, 1, 0) + 1] - c4_v_y;
  if (c4_a22 == 0.0) {
  } else if (c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r1",
               (real_T)c4_r1), 1, 2, 1, 0) - 1] == 0.0) {
  } else {
    goto label_1;
  }

  c4_b_eml_warning();
 label_1:
  ;
  c4_f_a = c4_d_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) - 1];
  c4_n_b = c4_a21;
  c4_w_y = c4_f_a * c4_n_b;
  c4_p_x = c4_d_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("r2",
    (real_T)c4_r2), 1, 2, 1, 0) - 1] - c4_w_y;
  c4_x_y = c4_a22;
  c4_q_x = c4_p_x;
  c4_y_y = c4_x_y;
  c4_z = c4_q_x / c4_y_y;
  c4_r_x[1] = c4_z;
  c4_g_a = c4_r_x[1];
  c4_o_b = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) + 1];
  c4_ab_y = c4_g_a * c4_o_b;
  c4_s_x = c4_d_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) - 1] - c4_ab_y;
  c4_bb_y = c4_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("r1",
    (real_T)c4_r1), 1, 2, 1, 0) - 1];
  c4_t_x = c4_s_x;
  c4_cb_y = c4_bb_y;
  c4_b_z = c4_t_x / c4_cb_y;
  c4_r_x[0] = c4_b_z;
  for (c4_i176 = 0; c4_i176 < 2; c4_i176 = c4_i176 + 1) {
    c4_varargin_1[c4_i176] = 0.0;
  }

  for (c4_k = 1.0; c4_k <= 2.0; c4_k = c4_k + 1.0) {
    c4_b_k = c4_k;
    c4_u_x = c4_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
      ("k", c4_b_k), 1, 2, 1, 0) - 1];
    c4_db_y = muDoubleScalarAbs(c4_u_x);
    c4_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK(
      "k", c4_b_k), 1, 2, 1, 0) - 1] = c4_db_y;
  }

  for (c4_i177 = 0; c4_i177 < 2; c4_i177 = c4_i177 + 1) {
    c4_v_x[c4_i177] = c4_varargin_1[c4_i177];
  }

  for (c4_i178 = 0; c4_i178 < 2; c4_i178 = c4_i178 + 1) {
    c4_w_x[c4_i178] = c4_v_x[c4_i178];
  }

  c4_mtmp = c4_w_x[0];
  c4_x_x = c4_w_x[1];
  c4_p_b = rtIsNaN(c4_x_x);
  if (!c4_p_b) {
    c4_y_x = c4_mtmp;
    c4_q_b = rtIsNaN(c4_y_x);
    if (c4_q_b) {
      goto label_2;
    } else {
      if (c4_w_x[1] > c4_mtmp) {
        goto label_2;
      }
    }
  }

  goto label_3;
 label_2:
  ;
  c4_mtmp = c4_w_x[1];
 label_3:
  ;
  c4_r_b = c4_mtmp;
  *c4_outside = c4_c_a * c4_r_b;
  _SFD_EML_CALL(0,179);
  *c4_accel = 0.0;
  _SFD_EML_CALL(0,181);
  if (CV_EML_IF(0, 13, *c4_outside <= 1.0)) {
  } else {
    _SFD_EML_CALL(0,185);
    if (CV_EML_IF(0, 14, c4_rate > 0.0)) {
      _SFD_EML_CALL(0,186);
      if (CV_EML_IF(0, 15, c4_swcurve_pos < 0.0)) {
        _SFD_EML_CALL(0,187);
        if (CV_EML_IF(0, 16, c4_rate < c4_rate_des1)) {
          _SFD_EML_CALL(0,188);
          *c4_accel = c4_amax;
        } else {
          _SFD_EML_CALL(0,189);
          if (CV_EML_IF(0, 17, c4_rate < c4_rate_des2)) {
            _SFD_EML_CALL(0,190);
            *c4_accel = 0.0;
          } else {
            _SFD_EML_CALL(0,192);
            *c4_accel = c4_amin;
          }
        }
      } else {
        _SFD_EML_CALL(0,195);
        *c4_accel = c4_amin;
      }
    } else {
      _SFD_EML_CALL(0,198);
      if (CV_EML_IF(0, 18, c4_swcurve_neg < 0.0)) {
        _SFD_EML_CALL(0,199);
        if (CV_EML_IF(0, 19, c4_rate > -c4_rate_des1)) {
          _SFD_EML_CALL(0,200);
          *c4_accel = c4_amin;
        } else {
          _SFD_EML_CALL(0,201);
          if (CV_EML_IF(0, 20, c4_rate > -c4_rate_des2)) {
            _SFD_EML_CALL(0,202);
            *c4_accel = 0.0;
          } else {
            _SFD_EML_CALL(0,204);
            *c4_accel = c4_amax;
          }
        }
      } else {
        _SFD_EML_CALL(0,207);
        *c4_accel = c4_amax;
      }
    }
  }

  _SFD_EML_CALL(0,-207);
  sf_debug_symbol_scope_pop();
}

static void c4_b_eml_warning(void)
{
  int32_T c4_i179;
  static char_T c4_varargin_1[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's',
    'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r',
    'i', 'x' };

  char_T c4_u[21];
  const mxArray *c4_y = NULL;
  int32_T c4_i180;
  static char_T c4_varargin_2[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ',
    't', 'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c',
    'i', 's', 'i', 'o',
    'n', '.' };

  char_T c4_b_u[40];
  const mxArray *c4_b_y = NULL;
  for (c4_i179 = 0; c4_i179 < 21; c4_i179 = c4_i179 + 1) {
    c4_u[c4_i179] = c4_varargin_1[c4_i179];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c4_i180 = 0; c4_i180 < 40; c4_i180 = c4_i180 + 1) {
    c4_b_u[c4_i180] = c4_varargin_2[c4_i180];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call("warning", 0U, 2U, 14, c4_y, 14, c4_b_y);
}

static real_T c4_min(real_T c4_varargin_1, real_T c4_varargin_2)
{
  real_T c4_x;
  real_T c4_y;
  c4_x = c4_varargin_1;
  c4_y = c4_varargin_2;
  return c4_eml_bin_extremum(false, c4_x, c4_y);
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i181;
  real_T c4_b_u[11];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i181 = 0; c4_i181 < 11; c4_i181 = c4_i181 + 1) {
    c4_b_u[c4_i181] = (*((real_T (*)[11])c4_u))[c4_i181];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 11));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i182;
  int32_T c4_i183;
  real_T c4_b_u[9];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i182 = 0; c4_i182 < 3; c4_i182 = c4_i182 + 1) {
    for (c4_i183 = 0; c4_i183 < 3; c4_i183 = c4_i183 + 1) {
      c4_b_u[c4_i183 + 3 * c4_i182] = (*((real_T (*)[9])c4_u))[c4_i183 + 3 *
        c4_i182];
    }
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i184;
  real_T c4_b_u[4];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i184 = 0; c4_i184 < 4; c4_i184 = c4_i184 + 1) {
    c4_b_u[c4_i184] = (*((real_T (*)[4])c4_u))[c4_i184];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i185;
  real_T c4_b_u[3];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i185 = 0; c4_i185 < 3; c4_i185 = c4_i185 + 1) {
    c4_b_u[c4_i185] = (*((real_T (*)[3])c4_u))[c4_i185];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i186;
  real_T c4_b_u[12];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i186 = 0; c4_i186 < 12; c4_i186 = c4_i186 + 1) {
    c4_b_u[c4_i186] = (*((real_T (*)[12])c4_u))[c4_i186];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_g_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i187;
  real_T c4_b_u[6];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i187 = 0; c4_i187 < 6; c4_i187 = c4_i187 + 1) {
    c4_b_u[c4_i187] = (*((real_T (*)[6])c4_u))[c4_i187];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_h_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i188;
  real_T c4_b_u[2];
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  for (c4_i188 = 0; c4_i188 < 2; c4_i188 = c4_i188 + 1) {
    c4_b_u[c4_i188] = (*((real_T (*)[2])c4_u))[c4_i188];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_main_sim_noadapt_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[88];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i189;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  c4_b_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 88));
  for (c4_i189 = 0; c4_i189 < 88; c4_i189 = c4_i189 + 1) {
    c4_r0 = &c4_info[c4_i189];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c4_i189);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c4_i189);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[88])
{
  c4_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c4_info[0].name = "eml_min_or_max";
  c4_info[0].dominantType = "char";
  c4_info[0].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c4_info[0].fileLength = 7562U;
  c4_info[0].fileTime1 = 1213662886U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "";
  c4_info[1].name = "minus";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved = "[B]minus";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context = "";
  c4_info[2].name = "zeros";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[B]zeros";
  c4_info[2].fileLength = 0U;
  c4_info[2].fileTime1 = 0U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[3].name = "eml_blas_xgemm";
  c4_info[3].dominantType = "int32";
  c4_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c4_info[3].fileLength = 355U;
  c4_info[3].fileTime1 = 1192492054U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[4].name = "eml_xdotu";
  c4_info[4].dominantType = "int32";
  c4_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c4_info[4].fileLength = 1453U;
  c4_info[4].fileTime1 = 1209356052U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context = "";
  c4_info[5].name = "times";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[B]times";
  c4_info[5].fileLength = 0U;
  c4_info[5].fileTime1 = 0U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[6].name = "eml_scalar_sqrt";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[6].fileLength = 664U;
  c4_info[6].fileTime1 = 1209355994U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context = "";
  c4_info[7].name = "plus";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[B]plus";
  c4_info[7].fileLength = 0U;
  c4_info[7].fileTime1 = 0U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context = "";
  c4_info[8].name = "mtimes";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[8].fileLength = 2336U;
  c4_info[8].fileTime1 = 1213662890U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c4_info[9].name = "eml_refblas_xdotx";
  c4_info[9].dominantType = "int32";
  c4_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[9].fileLength = 1786U;
  c4_info[9].fileTime1 = 1210895856U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c4_info[10].name = "ischar";
  c4_info[10].dominantType = "char";
  c4_info[10].resolved = "[B]ischar";
  c4_info[10].fileLength = 0U;
  c4_info[10].fileTime1 = 0U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve2x2";
  c4_info[11].name = "eml_xcabs1";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c4_info[11].fileLength = 419U;
  c4_info[11].fileTime1 = 1209356048U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[12].name = "ne";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[B]ne";
  c4_info[12].fileLength = 0U;
  c4_info[12].fileTime1 = 0U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[13].name = "eml_error";
  c4_info[13].dominantType = "char";
  c4_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[13].fileLength = 315U;
  c4_info[13].fileTime1 = 1213662886U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[14].name = "isfinite";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[14].fileLength = 341U;
  c4_info[14].fileTime1 = 1192491934U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[15].name = "power";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[15].fileLength = 5131U;
  c4_info[15].fileTime1 = 1213662890U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[16].name = "gt";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved = "[B]gt";
  c4_info[16].fileLength = 0U;
  c4_info[16].fileTime1 = 0U;
  c4_info[16].fileTime2 = 0U;
  c4_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[17].name = "eml_set_singleton_dim";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c4_info[17].fileLength = 398U;
  c4_info[17].fileTime1 = 1209356038U;
  c4_info[17].fileTime2 = 0U;
  c4_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[18].name = "true";
  c4_info[18].dominantType = "";
  c4_info[18].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c4_info[18].fileLength = 237U;
  c4_info[18].fileTime1 = 1192491962U;
  c4_info[18].fileTime2 = 0U;
  c4_info[19].context = "";
  c4_info[19].name = "mrdivide";
  c4_info[19].dominantType = "double";
  c4_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[19].fileLength = 755U;
  c4_info[19].fileTime1 = 1209356082U;
  c4_info[19].fileTime2 = 0U;
  c4_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[20].name = "eml_scalar_abs";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[20].fileLength = 461U;
  c4_info[20].fileTime1 = 1203473160U;
  c4_info[20].fileTime2 = 0U;
  c4_info[21].context = "";
  c4_info[21].name = "ctranspose";
  c4_info[21].dominantType = "double";
  c4_info[21].resolved = "[B]ctranspose";
  c4_info[21].fileLength = 0U;
  c4_info[21].fileTime1 = 0U;
  c4_info[21].fileTime2 = 0U;
  c4_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c4_info[22].name = "le";
  c4_info[22].dominantType = "double";
  c4_info[22].resolved = "[B]le";
  c4_info[22].fileLength = 0U;
  c4_info[22].fileTime1 = 0U;
  c4_info[22].fileTime2 = 0U;
  c4_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[23].name = "eml_alloc";
  c4_info[23].dominantType = "double";
  c4_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[23].fileLength = 2627U;
  c4_info[23].fileTime1 = 1213662886U;
  c4_info[23].fileTime2 = 0U;
  c4_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c4_info[24].name = "int32";
  c4_info[24].dominantType = "double";
  c4_info[24].resolved = "[B]int32";
  c4_info[24].fileLength = 0U;
  c4_info[24].fileTime1 = 0U;
  c4_info[24].fileTime2 = 0U;
  c4_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[25].name = "eml_all_or_any";
  c4_info[25].dominantType = "char";
  c4_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[25].fileLength = 3423U;
  c4_info[25].fileTime1 = 1213662886U;
  c4_info[25].fileTime2 = 0U;
  c4_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[26].name = "isnan";
  c4_info[26].dominantType = "double";
  c4_info[26].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[26].fileLength = 472U;
  c4_info[26].fileTime1 = 1192491936U;
  c4_info[26].fileTime2 = 0U;
  c4_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[27].name = "logical";
  c4_info[27].dominantType = "double";
  c4_info[27].resolved = "[B]logical";
  c4_info[27].fileLength = 0U;
  c4_info[27].fileTime1 = 0U;
  c4_info[27].fileTime2 = 0U;
  c4_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c4_info[28].name = "imag";
  c4_info[28].dominantType = "double";
  c4_info[28].resolved = "[B]imag";
  c4_info[28].fileLength = 0U;
  c4_info[28].fileTime1 = 0U;
  c4_info[28].fileTime2 = 0U;
  c4_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[29].name = "nargin";
  c4_info[29].dominantType = "";
  c4_info[29].resolved = "[B]nargin";
  c4_info[29].fileLength = 0U;
  c4_info[29].fileTime1 = 0U;
  c4_info[29].fileTime2 = 0U;
  c4_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[30].name = "lt";
  c4_info[30].dominantType = "double";
  c4_info[30].resolved = "[B]lt";
  c4_info[30].fileLength = 0U;
  c4_info[30].fileTime1 = 0U;
  c4_info[30].fileTime2 = 0U;
  c4_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c4_info[31].name = "islogical";
  c4_info[31].dominantType = "logical";
  c4_info[31].resolved = "[B]islogical";
  c4_info[31].fileLength = 0U;
  c4_info[31].fileTime1 = 0U;
  c4_info[31].fileTime2 = 0U;
  c4_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/binary_isequal";
  c4_info[32].name = "all";
  c4_info[32].dominantType = "logical";
  c4_info[32].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[32].fileLength = 400U;
  c4_info[32].fileTime1 = 1192492104U;
  c4_info[32].fileTime2 = 0U;
  c4_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[33].name = "eml_xgemm";
  c4_info[33].dominantType = "int32";
  c4_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[33].fileLength = 3184U;
  c4_info[33].fileTime1 = 1209356052U;
  c4_info[33].fileTime2 = 0U;
  c4_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[34].name = "strcmp";
  c4_info[34].dominantType = "char";
  c4_info[34].resolved = "[B]strcmp";
  c4_info[34].fileLength = 0U;
  c4_info[34].fileTime1 = 0U;
  c4_info[34].fileTime2 = 0U;
  c4_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[35].name = "eml_index_plus";
  c4_info[35].dominantType = "";
  c4_info[35].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c4_info[35].fileLength = 272U;
  c4_info[35].fileTime1 = 1192491986U;
  c4_info[35].fileTime2 = 0U;
  c4_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[36].name = "isinf";
  c4_info[36].dominantType = "double";
  c4_info[36].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c4_info[36].fileLength = 472U;
  c4_info[36].fileTime1 = 1192491934U;
  c4_info[36].fileTime2 = 0U;
  c4_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[37].name = "intmax";
  c4_info[37].dominantType = "char";
  c4_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c4_info[37].fileLength = 1535U;
  c4_info[37].fileTime1 = 1192491928U;
  c4_info[37].fileTime2 = 0U;
  c4_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[38].name = "eml_scalexp_size";
  c4_info[38].dominantType = "double";
  c4_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[38].fileLength = 1373U;
  c4_info[38].fileTime1 = 1208205260U;
  c4_info[38].fileTime2 = 0U;
  c4_info[39].context = "";
  c4_info[39].name = "min";
  c4_info[39].dominantType = "double";
  c4_info[39].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c4_info[39].fileLength = 308U;
  c4_info[39].fileTime1 = 1192491834U;
  c4_info[39].fileTime2 = 0U;
  c4_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c4_info[40].name = "eml_scalexp_compatible";
  c4_info[40].dominantType = "double";
  c4_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[40].fileLength = 502U;
  c4_info[40].fileTime1 = 1208205258U;
  c4_info[40].fileTime2 = 0U;
  c4_info[41].context = "";
  c4_info[41].name = "uminus";
  c4_info[41].dominantType = "double";
  c4_info[41].resolved = "[B]uminus";
  c4_info[41].fileLength = 0U;
  c4_info[41].fileTime1 = 0U;
  c4_info[41].fileTime2 = 0U;
  c4_info[42].context = "";
  c4_info[42].name = "abs";
  c4_info[42].dominantType = "double";
  c4_info[42].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[42].fileLength = 538U;
  c4_info[42].fileTime1 = 1203473128U;
  c4_info[42].fileTime2 = 0U;
  c4_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c4_info[43].name = "nargout";
  c4_info[43].dominantType = "";
  c4_info[43].resolved = "[B]nargout";
  c4_info[43].fileLength = 0U;
  c4_info[43].fileTime1 = 0U;
  c4_info[43].fileTime2 = 0U;
  c4_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c4_info[44].name = "eml_xdot";
  c4_info[44].dominantType = "int32";
  c4_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c4_info[44].fileLength = 1330U;
  c4_info[44].fileTime1 = 1209356050U;
  c4_info[44].fileTime2 = 0U;
  c4_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[45].name = "eml_scalar_atan2";
  c4_info[45].dominantType = "double";
  c4_info[45].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c4_info[45].fileLength = 964U;
  c4_info[45].fileTime1 = 1209355986U;
  c4_info[45].fileTime2 = 0U;
  c4_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c4_info[46].name = "cast";
  c4_info[46].dominantType = "double";
  c4_info[46].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c4_info[46].fileLength = 866U;
  c4_info[46].fileTime1 = 1192491844U;
  c4_info[46].fileTime2 = 0U;
  c4_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[47].name = "isreal";
  c4_info[47].dominantType = "double";
  c4_info[47].resolved = "[B]isreal";
  c4_info[47].fileLength = 0U;
  c4_info[47].fileTime1 = 0U;
  c4_info[47].fileTime2 = 0U;
  c4_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[48].name = "isequal";
  c4_info[48].dominantType = "char";
  c4_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[48].fileLength = 157U;
  c4_info[48].fileTime1 = 1210895846U;
  c4_info[48].fileTime2 = 0U;
  c4_info[49].context = "";
  c4_info[49].name = "not";
  c4_info[49].dominantType = "double";
  c4_info[49].resolved = "[B]not";
  c4_info[49].fileLength = 0U;
  c4_info[49].fileTime1 = 0U;
  c4_info[49].fileTime2 = 0U;
  c4_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c4_info[50].name = "real";
  c4_info[50].dominantType = "double";
  c4_info[50].resolved = "[B]real";
  c4_info[50].fileLength = 0U;
  c4_info[50].fileTime1 = 0U;
  c4_info[50].fileTime2 = 0U;
  c4_info[51].context = "";
  c4_info[51].name = "atan2";
  c4_info[51].dominantType = "double";
  c4_info[51].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[51].fileLength = 674U;
  c4_info[51].fileTime1 = 1203473148U;
  c4_info[51].fileTime2 = 0U;
  c4_info[52].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[52].name = "eml_nonsingleton_dim";
  c4_info[52].dominantType = "logical";
  c4_info[52].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c4_info[52].fileLength = 404U;
  c4_info[52].fileTime1 = 1192492000U;
  c4_info[52].fileTime2 = 0U;
  c4_info[53].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[53].name = "eml_scalar_floor";
  c4_info[53].dominantType = "double";
  c4_info[53].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[53].fileLength = 260U;
  c4_info[53].fileTime1 = 1209355990U;
  c4_info[53].fileTime2 = 0U;
  c4_info[54].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[54].name = "eml_index_minus";
  c4_info[54].dominantType = "";
  c4_info[54].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c4_info[54].fileLength = 277U;
  c4_info[54].fileTime1 = 1192491984U;
  c4_info[54].fileTime2 = 0U;
  c4_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[55].name = "eml_zeros";
  c4_info[55].dominantType = "double";
  c4_info[55].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_zeros.m";
  c4_info[55].fileLength = 1083U;
  c4_info[55].fileTime1 = 1213662888U;
  c4_info[55].fileTime2 = 0U;
  c4_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c4_info[56].name = "double";
  c4_info[56].dominantType = "double";
  c4_info[56].resolved = "[B]double";
  c4_info[56].fileLength = 0U;
  c4_info[56].fileTime1 = 0U;
  c4_info[56].fileTime2 = 0U;
  c4_info[57].context = "";
  c4_info[57].name = "sqrt";
  c4_info[57].dominantType = "double";
  c4_info[57].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[57].fileLength = 572U;
  c4_info[57].fileTime1 = 1203473246U;
  c4_info[57].fileTime2 = 0U;
  c4_info[58].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[58].name = "eml_assert_valid_size_arg";
  c4_info[58].dominantType = "double";
  c4_info[58].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[58].fileLength = 2835U;
  c4_info[58].fileTime1 = 1210895844U;
  c4_info[58].fileTime2 = 0U;
  c4_info[59].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c4_info[59].name = "ge";
  c4_info[59].dominantType = "double";
  c4_info[59].resolved = "[B]ge";
  c4_info[59].fileLength = 0U;
  c4_info[59].fileTime1 = 0U;
  c4_info[59].fileTime2 = 0U;
  c4_info[60].context = "";
  c4_info[60].name = "mpower";
  c4_info[60].dominantType = "double";
  c4_info[60].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[60].fileLength = 3547U;
  c4_info[60].fileTime1 = 1213662888U;
  c4_info[60].fileTime2 = 0U;
  c4_info[61].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[61].name = "ndims";
  c4_info[61].dominantType = "double";
  c4_info[61].resolved = "[B]ndims";
  c4_info[61].fileLength = 0U;
  c4_info[61].fileTime1 = 0U;
  c4_info[61].fileTime2 = 0U;
  c4_info[62].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c4_info[62].name = "eml_index_times";
  c4_info[62].dominantType = "int32";
  c4_info[62].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c4_info[62].fileLength = 280U;
  c4_info[62].fileTime1 = 1192491988U;
  c4_info[62].fileTime2 = 0U;
  c4_info[63].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c4_info[63].name = "false";
  c4_info[63].dominantType = "";
  c4_info[63].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c4_info[63].fileLength = 238U;
  c4_info[63].fileTime1 = 1192491920U;
  c4_info[63].fileTime2 = 0U;
}

static void c4_b_info_helper(c4_ResolvedFunctionInfo c4_info[88])
{
  c4_info[64].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c4_info[64].name = "and";
  c4_info[64].dominantType = "logical";
  c4_info[64].resolved = "[B]and";
  c4_info[64].fileLength = 0U;
  c4_info[64].fileTime1 = 0U;
  c4_info[64].fileTime2 = 0U;
  c4_info[65].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[65].name = "isa";
  c4_info[65].dominantType = "double";
  c4_info[65].resolved = "[B]isa";
  c4_info[65].fileLength = 0U;
  c4_info[65].fileTime1 = 0U;
  c4_info[65].fileTime2 = 0U;
  c4_info[66].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[66].name = "isvector";
  c4_info[66].dominantType = "double";
  c4_info[66].resolved = "[B]isvector";
  c4_info[66].fileLength = 0U;
  c4_info[66].fileTime1 = 0U;
  c4_info[66].fileTime2 = 0U;
  c4_info[67].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[67].name = "isempty";
  c4_info[67].dominantType = "double";
  c4_info[67].resolved = "[B]isempty";
  c4_info[67].fileLength = 0U;
  c4_info[67].fileTime1 = 0U;
  c4_info[67].fileTime2 = 0U;
  c4_info[68].context = "";
  c4_info[68].name = "mldivide";
  c4_info[68].dominantType = "double";
  c4_info[68].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c4_info[68].fileLength = 937U;
  c4_info[68].fileTime1 = 1210895856U;
  c4_info[68].fileTime2 = 0U;
  c4_info[69].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[69].name = "rdivide";
  c4_info[69].dominantType = "double";
  c4_info[69].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[69].fileLength = 620U;
  c4_info[69].fileTime1 = 1213662890U;
  c4_info[69].fileTime2 = 0U;
  c4_info[70].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[70].name = "ones";
  c4_info[70].dominantType = "char";
  c4_info[70].resolved = "[B]ones";
  c4_info[70].fileLength = 0U;
  c4_info[70].fileTime1 = 0U;
  c4_info[70].fileTime2 = 0U;
  c4_info[71].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[71].name = "eml_isequal_core";
  c4_info[71].dominantType = "char";
  c4_info[71].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[71].fileLength = 3543U;
  c4_info[71].fileTime1 = 1213662886U;
  c4_info[71].fileTime2 = 0U;
  c4_info[72].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[72].name = "isinteger";
  c4_info[72].dominantType = "double";
  c4_info[72].resolved = "[B]isinteger";
  c4_info[72].fileLength = 0U;
  c4_info[72].fileTime1 = 0U;
  c4_info[72].fileTime2 = 0U;
  c4_info[73].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c4_info[73].name = "eml_refblas_xgemm";
  c4_info[73].dominantType = "int32";
  c4_info[73].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[73].fileLength = 5746U;
  c4_info[73].fileTime1 = 1210895858U;
  c4_info[73].fileTime2 = 0U;
  c4_info[74].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[74].name = "eq";
  c4_info[74].dominantType = "double";
  c4_info[74].resolved = "[B]eq";
  c4_info[74].fileLength = 0U;
  c4_info[74].fileTime1 = 0U;
  c4_info[74].fileTime2 = 0U;
  c4_info[75].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[75].name = "eml_div";
  c4_info[75].dominantType = "double";
  c4_info[75].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[75].fileLength = 4254U;
  c4_info[75].fileTime1 = 1192491972U;
  c4_info[75].fileTime2 = 0U;
  c4_info[76].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[76].name = "assert";
  c4_info[76].dominantType = "char";
  c4_info[76].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c4_info[76].fileLength = 2684U;
  c4_info[76].fileTime1 = 1210895856U;
  c4_info[76].fileTime2 = 0U;
  c4_info[77].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[77].name = "isscalar";
  c4_info[77].dominantType = "double";
  c4_info[77].resolved = "[B]isscalar";
  c4_info[77].fileLength = 0U;
  c4_info[77].fileTime1 = 0U;
  c4_info[77].fileTime2 = 0U;
  c4_info[78].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c4_info[78].name = "isstruct";
  c4_info[78].dominantType = "double";
  c4_info[78].resolved = "[B]isstruct";
  c4_info[78].fileLength = 0U;
  c4_info[78].fileTime1 = 0U;
  c4_info[78].fileTime2 = 0U;
  c4_info[79].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c4_info[79].name = "eml_lusolve";
  c4_info[79].dominantType = "double";
  c4_info[79].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c4_info[79].fileLength = 4058U;
  c4_info[79].fileTime1 = 1210895846U;
  c4_info[79].fileTime2 = 0U;
  c4_info[80].context = "";
  c4_info[80].name = "max";
  c4_info[80].dominantType = "double";
  c4_info[80].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c4_info[80].fileLength = 308U;
  c4_info[80].fileTime1 = 1192491830U;
  c4_info[80].fileTime2 = 0U;
  c4_info[81].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[81].name = "class";
  c4_info[81].dominantType = "double";
  c4_info[81].resolved = "[B]class";
  c4_info[81].fileLength = 0U;
  c4_info[81].fileTime1 = 0U;
  c4_info[81].fileTime2 = 0U;
  c4_info[82].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c4_info[82].name = "eml_refblas_xdot";
  c4_info[82].dominantType = "int32";
  c4_info[82].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c4_info[82].fileLength = 343U;
  c4_info[82].fileTime1 = 1210895856U;
  c4_info[82].fileTime2 = 0U;
  c4_info[83].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[83].name = "isnumeric";
  c4_info[83].dominantType = "double";
  c4_info[83].resolved = "[B]isnumeric";
  c4_info[83].fileLength = 0U;
  c4_info[83].fileTime1 = 0U;
  c4_info[83].fileTime2 = 0U;
  c4_info[84].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[84].name = "size";
  c4_info[84].dominantType = "double";
  c4_info[84].resolved = "[B]size";
  c4_info[84].fileLength = 0U;
  c4_info[84].fileTime1 = 0U;
  c4_info[84].fileTime2 = 0U;
  c4_info[85].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c4_info[85].name = "eml_blas_xdot";
  c4_info[85].dominantType = "int32";
  c4_info[85].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c4_info[85].fileLength = 238U;
  c4_info[85].fileTime1 = 1192492052U;
  c4_info[85].fileTime2 = 0U;
  c4_info[86].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c4_info[86].name = "eml_index_class";
  c4_info[86].dominantType = "";
  c4_info[86].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[86].fileLength = 909U;
  c4_info[86].fileTime1 = 1192491982U;
  c4_info[86].fileTime2 = 0U;
  c4_info[87].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[87].name = "eml_warning";
  c4_info[87].dominantType = "char";
  c4_info[87].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c4_info[87].fileLength = 262U;
  c4_info[87].fileTime1 = 1213662888U;
  c4_info[87].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_main_sim_noadapt_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1248354994U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(89472009U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4120544920U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(886600354U);
}

mxArray *sf_c4_main_sim_noadapt_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4126004377U);
    pr[1] = (double)(2724276349U);
    pr[2] = (double)(2368271395U);
    pr[3] = (double)(3896265199U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(11);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
          (_main_sim_noadaptMachineNumber_,
           4,
           1,
           1,
           16,
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
          init_script_number_translation(_main_sim_noadaptMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_main_sim_noadaptMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_main_sim_noadaptMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 11;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"bb_params",0,c4_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"bb_ellipsoid",0,c4_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 12;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"debug_output",0,c4_f_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"cvddes",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"dir",0,NULL);
          }

          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"use_bb",
                              0,NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"att_cvc",0,c4_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"att_cv",0,NULL);
          }

          _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"timer",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pqr",0,c4_d_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"inertia",0,NULL);
          }

          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "enable_bb",0,c4_e_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(12,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"cvddes_lin",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(13,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"dir_old",0,NULL);
          }

          _SFD_SET_DATA_PROPS(14,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "use_bb_old",0,NULL);
          _SFD_SET_DATA_PROPS(15,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "timer_old",0,NULL);
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
        _SFD_CV_INIT_EML(0,5,21,0,0,0,4,4);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3616);
        _SFD_CV_INIT_EML_FCN(0,1,"qmpy",3616,-1,3943);
        _SFD_CV_INIT_EML_FCN(0,2,"get_ellipsoid_scaling",3943,-1,4052);
        _SFD_CV_INIT_EML_FCN(0,3,"pp",4052,-1,5373);
        _SFD_CV_INIT_EML_FCN(0,4,"norm_vec3",5373,-1,5451);
        _SFD_CV_INIT_EML_IF(0,0,535,549,741,895);
        _SFD_CV_INIT_EML_IF(0,1,741,756,-1,895);
        _SFD_CV_INIT_EML_IF(0,2,788,809,-1,891);
        _SFD_CV_INIT_EML_IF(0,3,1240,1259,-1,1311);
        _SFD_CV_INIT_EML_IF(0,4,1625,1640,-1,1784);
        _SFD_CV_INIT_EML_IF(0,5,1647,1687,1720,1780);
        _SFD_CV_INIT_EML_IF(0,6,1835,1860,1984,2355);
        _SFD_CV_INIT_EML_IF(0,7,1889,1905,-1,1982);
        _SFD_CV_INIT_EML_IF(0,8,1984,2019,2235,2355);
        _SFD_CV_INIT_EML_IF(0,9,2102,2118,-1,2234);
        _SFD_CV_INIT_EML_IF(0,10,2419,2429,2878,2973);
        _SFD_CV_INIT_EML_IF(0,11,2667,2683,2754,2877);
        _SFD_CV_INIT_EML_IF(0,12,3346,3357,-1,3614);
        _SFD_CV_INIT_EML_IF(0,13,4839,4855,4874,5370);
        _SFD_CV_INIT_EML_IF(0,14,4874,4886,5124,5370);
        _SFD_CV_INIT_EML_IF(0,15,4893,4912,5088,5123);
        _SFD_CV_INIT_EML_IF(0,16,4923,4943,4981,5083);
        _SFD_CV_INIT_EML_IF(0,17,4981,5005,5040,5083);
        _SFD_CV_INIT_EML_IF(0,18,5133,5152,5331,5366);
        _SFD_CV_INIT_EML_IF(0,19,5163,5184,5222,5326);
        _SFD_CV_INIT_EML_IF(0,20,5222,5248,5283,5326);

        {
          static int condStart[] = { 540 };

          static int condEnd[] = { 549 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,0,539,549,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1894 };

          static int condEnd[] = { 1905 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,1893,1905,1,1,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2107 };

          static int condEnd[] = { 2118 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,2,2106,2118,1,2,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3351 };

          static int condEnd[] = { 3357 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,3,3350,3357,1,3,&(condStart[0]),&(condEnd[0]),
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
          real_T (*c4_bb_params)[11];
          real_T (*c4_bb_ellipsoid)[9];
          real_T (*c4_debug_output)[12];
          real_T (*c4_cvddes)[3];
          real_T (*c4_dir)[3];
          real_T *c4_use_bb;
          real_T (*c4_att_cvc)[4];
          real_T (*c4_att_cv)[4];
          real_T *c4_timer;
          real_T (*c4_pqr)[3];
          real_T (*c4_inertia)[9];
          real_T *c4_enable_bb;
          real_T (*c4_cvddes_lin)[3];
          real_T (*c4_dir_old)[3];
          real_T *c4_use_bb_old;
          real_T *c4_timer_old;
          c4_att_cv = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
          c4_bb_params = (real_T (*)[11])ssGetInputPortSignal(chartInstance.S, 0);
          c4_dir = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 3);
          c4_bb_ellipsoid = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S,
            1);
          c4_inertia = (real_T (*)[9])ssGetInputPortSignal(chartInstance.S, 5);
          c4_cvddes = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          c4_enable_bb = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
          c4_dir_old = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 8);
          c4_use_bb = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c4_debug_output = (real_T (*)[12])ssGetOutputPortSignal
            (chartInstance.S, 1);
          c4_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 4);
          c4_timer_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 10);
          c4_cvddes_lin = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 7);
          c4_att_cvc = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 2);
          c4_timer = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
          c4_use_bb_old = (real_T *)ssGetInputPortSignal(chartInstance.S, 9);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_bb_params);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_bb_ellipsoid);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_debug_output);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_cvddes);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_dir);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_use_bb);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_att_cvc);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_att_cv);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_timer);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_pqr);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_inertia);
          _SFD_SET_DATA_VALUE_PTR(11U, c4_enable_bb);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_cvddes_lin);
          _SFD_SET_DATA_VALUE_PTR(13U, c4_dir_old);
          _SFD_SET_DATA_VALUE_PTR(14U, c4_use_bb_old);
          _SFD_SET_DATA_VALUE_PTR(15U, c4_timer_old);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_main_sim_noadaptMachineNumber_,
      chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c4_main_sim_noadapt(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_main_sim_noadapt();
  initialize_c4_main_sim_noadapt();
}

static void sf_opaque_enable_c4_main_sim_noadapt(void *chartInstanceVar)
{
  enable_c4_main_sim_noadapt();
}

static void sf_opaque_disable_c4_main_sim_noadapt(void *chartInstanceVar)
{
  disable_c4_main_sim_noadapt();
}

static void sf_opaque_gateway_c4_main_sim_noadapt(void *chartInstanceVar)
{
  sf_c4_main_sim_noadapt();
}

static mxArray* sf_opaque_get_sim_state_c4_main_sim_noadapt(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_main_sim_noadapt();
  return st;
}

static void sf_opaque_set_sim_state_c4_main_sim_noadapt(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c4_main_sim_noadapt(sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_main_sim_noadapt(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_main_sim_noadapt();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_main_sim_noadapt(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_main_sim_noadapt();
  }
}

static void mdlSetWorkWidths_c4_main_sim_noadapt(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("main_sim_noadapt","main_sim_noadapt",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("main_sim_noadapt","main_sim_noadapt",4,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("main_sim_noadapt",
      "main_sim_noadapt",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"main_sim_noadapt",
        "main_sim_noadapt",4,11);
      sf_mark_chart_reusable_outputs(S,"main_sim_noadapt","main_sim_noadapt",4,5);
    }

    sf_set_rtw_dwork_info(S,"main_sim_noadapt","main_sim_noadapt",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1203317002U));
  ssSetChecksum1(S,(1243089738U));
  ssSetChecksum2(S,(2897982225U));
  ssSetChecksum3(S,(777164129U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_main_sim_noadapt(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "main_sim_noadapt", "main_sim_noadapt",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_main_sim_noadapt(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_main_sim_noadapt;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_main_sim_noadapt;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_main_sim_noadapt;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c4_main_sim_noadapt;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c4_main_sim_noadapt;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_main_sim_noadapt;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_main_sim_noadapt;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_main_sim_noadapt;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_main_sim_noadapt;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_main_sim_noadapt;
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

void c4_main_sim_noadapt_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_main_sim_noadapt(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_main_sim_noadapt(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_main_sim_noadapt(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_main_sim_noadapt_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
