/* Include files */

#include "models_sfun.h"
#include "c2_models.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "models_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void initialize_params_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void enable_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void disable_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void update_debugger_state_c2_models(SFc2_modelsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_models(SFc2_modelsInstanceStruct
  *chartInstance);
static void set_sim_state_c2_models(SFc2_modelsInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void sf_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void c2_c2_models(SFc2_modelsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_warning(SFc2_modelsInstanceStruct *chartInstance);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31]);
static void init_dsm_address_info(SFc2_modelsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_models = 0U;
}

static void initialize_params_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
}

static void enable_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c2_models(SFc2_modelsInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_models(SFc2_modelsInstanceStruct
  *chartInstance)
{
  return NULL;
}

static void set_sim_state_c2_models(SFc2_modelsInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
}

static void sf_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  uint8_T c2_previousEvent;
  real_T *c2_alpha;
  real_T *c2_omega;
  real_T *c2_beta;
  real_T *c2_tas;
  real_T *c2_B;
  real_T *c2_Cbar;
  real_T (*c2_pqr_osc)[3];
  real_T (*c2_pqr)[3];
  c2_tas = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_pqr_osc = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Cbar = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c2_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_alpha, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_omega, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_beta, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_tas, 3U);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_pqr)[c2_i0], 4U);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_pqr_osc)[c2_i1], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_B, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_Cbar, 7U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_models(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_modelsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_c2_models(SFc2_modelsInstanceStruct *chartInstance)
{
  real_T c2_alpha;
  real_T c2_beta;
  real_T c2_tas;
  int32_T c2_i2;
  real_T c2_pqr[3];
  real_T c2_B;
  real_T c2_Cbar;
  real_T c2_nargout = 2.0;
  real_T c2_nargin = 6.0;
  real_T c2_c2vt;
  real_T c2_b2vt;
  real_T c2_p_osc;
  real_T c2_r_osc;
  real_T c2_whichcase;
  real_T c2_rb;
  real_T c2_qb;
  real_T c2_pb;
  real_T c2_knots2ft;
  real_T c2_dtr;
  real_T c2_pqr_osc[3];
  real_T c2_omega;
  int32_T c2_i3;
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_x;
  real_T c2_c_a;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_y;
  real_T c2_A;
  real_T c2_g_x;
  real_T c2_d_a;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_b_b;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_b_B;
  real_T c2_m_x;
  real_T c2_b_y;
  real_T c2_n_x;
  real_T c2_c_y;
  real_T c2_o_x;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_p_x;
  real_T c2_c_b;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_f_a;
  real_T c2_s_x;
  real_T c2_d_b;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_e_y;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_g_a;
  real_T c2_e_b;
  real_T c2_j_y;
  real_T c2_ab_x;
  real_T c2_h_a;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_f_b;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_k_y;
  real_T c2_b_A;
  real_T c2_gb_x;
  real_T c2_i_a;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_g_b;
  real_T c2_kb_x;
  real_T c2_lb_x;
  real_T c2_c_B;
  real_T c2_mb_x;
  real_T c2_l_y;
  real_T c2_nb_x;
  real_T c2_m_y;
  real_T c2_ob_x;
  real_T c2_n_y;
  real_T c2_j_a;
  real_T c2_pb_x;
  real_T c2_h_b;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_k_a;
  real_T c2_sb_x;
  real_T c2_i_b;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_o_y;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_p_y;
  real_T c2_q_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_r_y;
  real_T c2_s_y;
  real_T c2_l_a;
  real_T c2_j_b;
  real_T c2_t_y;
  real_T c2_c_A;
  real_T c2_ac_x;
  real_T c2_m_a;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_k_b;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_d_B;
  real_T c2_gc_x;
  real_T c2_u_y;
  real_T c2_hc_x;
  real_T c2_v_y;
  real_T c2_ic_x;
  real_T c2_w_y;
  real_T c2_n_a;
  real_T c2_jc_x;
  real_T c2_l_b;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_x_y;
  real_T c2_o_a;
  real_T c2_mc_x;
  real_T c2_m_b;
  real_T c2_nc_x;
  real_T c2_oc_x;
  real_T c2_p_a;
  real_T c2_pc_x;
  real_T c2_n_b;
  real_T c2_qc_x;
  real_T c2_rc_x;
  real_T c2_y_y;
  real_T c2_d_A;
  real_T c2_sc_x;
  real_T c2_q_a;
  real_T c2_tc_x;
  real_T c2_uc_x;
  real_T c2_vc_x;
  real_T c2_o_b;
  real_T c2_wc_x;
  real_T c2_xc_x;
  real_T c2_e_B;
  real_T c2_yc_x;
  real_T c2_ab_y;
  real_T c2_ad_x;
  real_T c2_bb_y;
  real_T c2_bd_x;
  real_T c2_cb_y;
  real_T c2_r_a;
  real_T c2_cd_x;
  real_T c2_p_b;
  real_T c2_dd_x;
  real_T c2_ed_x;
  real_T c2_s_a;
  real_T c2_fd_x;
  real_T c2_q_b;
  real_T c2_gd_x;
  real_T c2_hd_x;
  real_T c2_db_y;
  real_T c2_t_a;
  real_T c2_id_x;
  real_T c2_r_b;
  real_T c2_jd_x;
  real_T c2_kd_x;
  real_T c2_eb_y;
  real_T c2_e_A;
  real_T c2_s_b;
  real_T c2_u_a;
  real_T c2_f_B;
  real_T c2_ld_x;
  real_T c2_fb_y;
  real_T c2_md_x;
  real_T c2_gb_y;
  real_T c2_nd_x;
  real_T c2_hb_y;
  real_T c2_f_A;
  real_T c2_t_b;
  real_T c2_v_a;
  real_T c2_g_B;
  real_T c2_od_x;
  real_T c2_ib_y;
  real_T c2_pd_x;
  real_T c2_jb_y;
  real_T c2_qd_x;
  real_T c2_kb_y;
  real_T c2_w_a;
  real_T c2_u_b;
  real_T c2_b_b2vt[3];
  int32_T c2_i4;
  int32_T c2_i5;
  real_T *c2_b_alpha;
  real_T *c2_b_beta;
  real_T *c2_b_tas;
  real_T *c2_h_B;
  real_T *c2_b_Cbar;
  real_T *c2_b_omega;
  real_T (*c2_b_pqr_osc)[3];
  real_T (*c2_b_pqr)[3];
  c2_b_tas = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_h_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_pqr_osc = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_Cbar = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_alpha = *c2_b_alpha;
  c2_beta = *c2_b_beta;
  c2_tas = *c2_b_tas;
  for (c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    c2_pqr[c2_i2] = (*c2_b_pqr)[c2_i2];
  }

  c2_B = *c2_h_B;
  c2_Cbar = *c2_b_Cbar;
  sf_debug_symbol_scope_push(20U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("c2vt", &c2_c2vt, c2_sf_marshall);
  sf_debug_symbol_scope_add("b2vt", &c2_b2vt, c2_sf_marshall);
  sf_debug_symbol_scope_add("p_osc", &c2_p_osc, c2_sf_marshall);
  sf_debug_symbol_scope_add("r_osc", &c2_r_osc, c2_sf_marshall);
  sf_debug_symbol_scope_add("whichcase", &c2_whichcase, c2_sf_marshall);
  sf_debug_symbol_scope_add("rb", &c2_rb, c2_sf_marshall);
  sf_debug_symbol_scope_add("qb", &c2_qb, c2_sf_marshall);
  sf_debug_symbol_scope_add("pb", &c2_pb, c2_sf_marshall);
  sf_debug_symbol_scope_add("knots2ft", &c2_knots2ft, c2_sf_marshall);
  sf_debug_symbol_scope_add("dtr", &c2_dtr, c2_sf_marshall);
  sf_debug_symbol_scope_add("pqr_osc", &c2_pqr_osc, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("omega", &c2_omega, c2_sf_marshall);
  sf_debug_symbol_scope_add("Cbar", &c2_Cbar, c2_sf_marshall);
  sf_debug_symbol_scope_add("B", &c2_B, c2_sf_marshall);
  sf_debug_symbol_scope_add("pqr", &c2_pqr, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("tas", &c2_tas, c2_sf_marshall);
  sf_debug_symbol_scope_add("beta", &c2_beta, c2_sf_marshall);
  sf_debug_symbol_scope_add("alpha", &c2_alpha, c2_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  Hybrid Kalviste blending method for use in embedded block in Simulink. */
  /*  */
  /*  Austin Murch */
  /*  Austin.M.Murch@nasa.gov */
  /*  Dimension vector outputs. */
  _SFD_EML_CALL(0,8);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3 = c2_i3 + 1) {
    c2_pqr_osc[c2_i3] = 0.0;
  }

  /*  Constants */
  _SFD_EML_CALL(0,12);
  c2_dtr = 1.7453292519943295E-002;
  _SFD_EML_CALL(0,13);
  c2_knots2ft = 1.689;

  /*  Setup variables */
  _SFD_EML_CALL(0,16);
  c2_pb = c2_pqr[0];
  _SFD_EML_CALL(0,17);
  c2_qb = c2_pqr[1];
  _SFD_EML_CALL(0,18);
  c2_rb = c2_pqr[2];
  _SFD_EML_CALL(0,20);
  c2_a = c2_alpha;
  c2_alpha = c2_a * 1.7453292519943295E-002;
  _SFD_EML_CALL(0,21);
  c2_b_a = c2_beta;
  c2_beta = c2_b_a * 1.7453292519943295E-002;
  _SFD_EML_CALL(0,22);
  c2_omega = 0.0;

  /* ----Hybrid Kalviste Method----% */
  _SFD_EML_CALL(0,25);
  c2_whichcase = 0.0;

  /* Test for case 1: p_osc = 0 */
  _SFD_EML_CALL(0,28);
  c2_x = c2_alpha;
  c2_c_a = c2_x;
  c2_b_x = c2_c_a;
  c2_c_x = c2_b_x;
  c2_c_x = muDoubleScalarCos(c2_c_x);
  c2_c_a = c2_c_x;
  c2_d_x = c2_beta;
  c2_b = c2_d_x;
  c2_e_x = c2_b;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarCos(c2_f_x);
  c2_b = c2_f_x;
  c2_y = c2_c_a * c2_b;
  if (CV_EML_IF(0, 0, c2_y == 0.0)) {
  } else {
    _SFD_EML_CALL(0,29);
    if (CV_EML_IF(0, 1, c2_pb == 0.0)) {
    } else {
      _SFD_EML_CALL(0,31);
      c2_A = c2_pb;
      c2_g_x = c2_alpha;
      c2_d_a = c2_g_x;
      c2_h_x = c2_d_a;
      c2_i_x = c2_h_x;
      c2_i_x = muDoubleScalarCos(c2_i_x);
      c2_d_a = c2_i_x;
      c2_j_x = c2_beta;
      c2_b_b = c2_j_x;
      c2_k_x = c2_b_b;
      c2_l_x = c2_k_x;
      c2_l_x = muDoubleScalarCos(c2_l_x);
      c2_b_b = c2_l_x;
      c2_b_B = c2_d_a * c2_b_b;
      c2_m_x = c2_A;
      c2_b_y = c2_b_B;
      if (c2_b_y == 0.0) {
        c2_eml_warning(chartInstance);
      }

      c2_n_x = c2_m_x;
      c2_c_y = c2_b_y;
      c2_o_x = c2_n_x;
      c2_d_y = c2_c_y;
      c2_omega = c2_o_x / c2_d_y;
      _SFD_EML_CALL(0,32);
      c2_e_a = c2_omega;
      c2_p_x = c2_alpha;
      c2_c_b = c2_p_x;
      c2_q_x = c2_c_b;
      c2_r_x = c2_q_x;
      c2_r_x = muDoubleScalarSin(c2_r_x);
      c2_c_b = c2_r_x;
      c2_f_a = c2_e_a * c2_c_b;
      c2_s_x = c2_beta;
      c2_d_b = c2_s_x;
      c2_t_x = c2_d_b;
      c2_u_x = c2_t_x;
      c2_u_x = muDoubleScalarCos(c2_u_x);
      c2_d_b = c2_u_x;
      c2_e_y = c2_f_a * c2_d_b;
      c2_r_osc = c2_rb - c2_e_y;
      _SFD_EML_CALL(0,33);
      c2_v_x = c2_rb;
      c2_w_x = c2_v_x;
      c2_f_y = muDoubleScalarAbs(c2_w_x);
      c2_g_y = c2_f_y;
      c2_x_x = c2_r_osc;
      c2_y_x = c2_x_x;
      c2_h_y = muDoubleScalarAbs(c2_y_x);
      c2_i_y = c2_h_y;
      if (CV_EML_IF(0, 2, c2_i_y > c2_g_y)) {
      } else {
        _SFD_EML_CALL(0,34);
        c2_g_a = c2_r_osc;
        c2_e_b = c2_rb;
        c2_j_y = c2_g_a * c2_e_b;
        if (CV_EML_IF(0, 3, c2_j_y < 0.0)) {
        } else {
          _SFD_EML_CALL(0,36);
          c2_whichcase = 1.0;
        }
      }
    }
  }

  /* Test for case 2: r_osc = 0 */
  _SFD_EML_CALL(0,41);
  c2_ab_x = c2_alpha;
  c2_h_a = c2_ab_x;
  c2_bb_x = c2_h_a;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_h_a = c2_cb_x;
  c2_db_x = c2_beta;
  c2_f_b = c2_db_x;
  c2_eb_x = c2_f_b;
  c2_fb_x = c2_eb_x;
  c2_fb_x = muDoubleScalarCos(c2_fb_x);
  c2_f_b = c2_fb_x;
  c2_k_y = c2_h_a * c2_f_b;
  if (CV_EML_IF(0, 4, c2_k_y == 0.0)) {
  } else {
    _SFD_EML_CALL(0,42);
    if (CV_EML_IF(0, 5, c2_rb == 0.0)) {
    } else {
      _SFD_EML_CALL(0,44);
      c2_b_A = c2_rb;
      c2_gb_x = c2_alpha;
      c2_i_a = c2_gb_x;
      c2_hb_x = c2_i_a;
      c2_ib_x = c2_hb_x;
      c2_ib_x = muDoubleScalarSin(c2_ib_x);
      c2_i_a = c2_ib_x;
      c2_jb_x = c2_beta;
      c2_g_b = c2_jb_x;
      c2_kb_x = c2_g_b;
      c2_lb_x = c2_kb_x;
      c2_lb_x = muDoubleScalarCos(c2_lb_x);
      c2_g_b = c2_lb_x;
      c2_c_B = c2_i_a * c2_g_b;
      c2_mb_x = c2_b_A;
      c2_l_y = c2_c_B;
      if (c2_l_y == 0.0) {
        c2_eml_warning(chartInstance);
      }

      c2_nb_x = c2_mb_x;
      c2_m_y = c2_l_y;
      c2_ob_x = c2_nb_x;
      c2_n_y = c2_m_y;
      c2_omega = c2_ob_x / c2_n_y;
      _SFD_EML_CALL(0,45);
      c2_j_a = c2_omega;
      c2_pb_x = c2_alpha;
      c2_h_b = c2_pb_x;
      c2_qb_x = c2_h_b;
      c2_rb_x = c2_qb_x;
      c2_rb_x = muDoubleScalarCos(c2_rb_x);
      c2_h_b = c2_rb_x;
      c2_k_a = c2_j_a * c2_h_b;
      c2_sb_x = c2_beta;
      c2_i_b = c2_sb_x;
      c2_tb_x = c2_i_b;
      c2_ub_x = c2_tb_x;
      c2_ub_x = muDoubleScalarCos(c2_ub_x);
      c2_i_b = c2_ub_x;
      c2_o_y = c2_k_a * c2_i_b;
      c2_p_osc = c2_pb - c2_o_y;
      _SFD_EML_CALL(0,46);
      c2_vb_x = c2_pb;
      c2_wb_x = c2_vb_x;
      c2_p_y = muDoubleScalarAbs(c2_wb_x);
      c2_q_y = c2_p_y;
      c2_xb_x = c2_p_osc;
      c2_yb_x = c2_xb_x;
      c2_r_y = muDoubleScalarAbs(c2_yb_x);
      c2_s_y = c2_r_y;
      if (CV_EML_IF(0, 6, c2_s_y > c2_q_y)) {
      } else {
        _SFD_EML_CALL(0,47);
        c2_l_a = c2_p_osc;
        c2_j_b = c2_pb;
        c2_t_y = c2_l_a * c2_j_b;
        if (CV_EML_IF(0, 7, c2_t_y < 0.0)) {
        } else {
          _SFD_EML_CALL(0,49);
          c2_whichcase = 2.0;
        }
      }
    }
  }

  /* Test for case 3: Omega = 0 */
  _SFD_EML_CALL(0,54);
  if (CV_EML_IF(0, 8, c2_whichcase == 0.0)) {
    _SFD_EML_CALL(0,55);
    c2_whichcase = 3.0;
  }

  _SFD_EML_CALL(0,60);
  switch ((int32_T)_SFD_INTEGER_CHECK("whichcase", c2_whichcase)) {
   case 1:
    CV_EML_SWITCH(0, 0, 1);
    _SFD_EML_CALL(0,62);
    c2_c_A = c2_pb;
    c2_ac_x = c2_alpha;
    c2_m_a = c2_ac_x;
    c2_bc_x = c2_m_a;
    c2_cc_x = c2_bc_x;
    c2_cc_x = muDoubleScalarCos(c2_cc_x);
    c2_m_a = c2_cc_x;
    c2_dc_x = c2_beta;
    c2_k_b = c2_dc_x;
    c2_ec_x = c2_k_b;
    c2_fc_x = c2_ec_x;
    c2_fc_x = muDoubleScalarCos(c2_fc_x);
    c2_k_b = c2_fc_x;
    c2_d_B = c2_m_a * c2_k_b;
    c2_gc_x = c2_c_A;
    c2_u_y = c2_d_B;
    if (c2_u_y == 0.0) {
      c2_eml_warning(chartInstance);
    }

    c2_hc_x = c2_gc_x;
    c2_v_y = c2_u_y;
    c2_ic_x = c2_hc_x;
    c2_w_y = c2_v_y;
    c2_omega = c2_ic_x / c2_w_y;
    _SFD_EML_CALL(0,63);
    c2_pqr_osc[0] = 0.0;
    _SFD_EML_CALL(0,64);
    c2_n_a = c2_omega;
    c2_jc_x = c2_beta;
    c2_l_b = c2_jc_x;
    c2_kc_x = c2_l_b;
    c2_lc_x = c2_kc_x;
    c2_lc_x = muDoubleScalarSin(c2_lc_x);
    c2_l_b = c2_lc_x;
    c2_x_y = c2_n_a * c2_l_b;
    c2_pqr_osc[1] = c2_qb - c2_x_y;
    _SFD_EML_CALL(0,65);
    c2_o_a = c2_omega;
    c2_mc_x = c2_alpha;
    c2_m_b = c2_mc_x;
    c2_nc_x = c2_m_b;
    c2_oc_x = c2_nc_x;
    c2_oc_x = muDoubleScalarSin(c2_oc_x);
    c2_m_b = c2_oc_x;
    c2_p_a = c2_o_a * c2_m_b;
    c2_pc_x = c2_beta;
    c2_n_b = c2_pc_x;
    c2_qc_x = c2_n_b;
    c2_rc_x = c2_qc_x;
    c2_rc_x = muDoubleScalarCos(c2_rc_x);
    c2_n_b = c2_rc_x;
    c2_y_y = c2_p_a * c2_n_b;
    c2_pqr_osc[2] = c2_rb - c2_y_y;
    break;

   case 2:
    CV_EML_SWITCH(0, 0, 2);
    _SFD_EML_CALL(0,68);
    c2_d_A = c2_rb;
    c2_sc_x = c2_alpha;
    c2_q_a = c2_sc_x;
    c2_tc_x = c2_q_a;
    c2_uc_x = c2_tc_x;
    c2_uc_x = muDoubleScalarSin(c2_uc_x);
    c2_q_a = c2_uc_x;
    c2_vc_x = c2_beta;
    c2_o_b = c2_vc_x;
    c2_wc_x = c2_o_b;
    c2_xc_x = c2_wc_x;
    c2_xc_x = muDoubleScalarCos(c2_xc_x);
    c2_o_b = c2_xc_x;
    c2_e_B = c2_q_a * c2_o_b;
    c2_yc_x = c2_d_A;
    c2_ab_y = c2_e_B;
    if (c2_ab_y == 0.0) {
      c2_eml_warning(chartInstance);
    }

    c2_ad_x = c2_yc_x;
    c2_bb_y = c2_ab_y;
    c2_bd_x = c2_ad_x;
    c2_cb_y = c2_bb_y;
    c2_omega = c2_bd_x / c2_cb_y;
    _SFD_EML_CALL(0,69);
    c2_r_a = c2_omega;
    c2_cd_x = c2_alpha;
    c2_p_b = c2_cd_x;
    c2_dd_x = c2_p_b;
    c2_ed_x = c2_dd_x;
    c2_ed_x = muDoubleScalarCos(c2_ed_x);
    c2_p_b = c2_ed_x;
    c2_s_a = c2_r_a * c2_p_b;
    c2_fd_x = c2_beta;
    c2_q_b = c2_fd_x;
    c2_gd_x = c2_q_b;
    c2_hd_x = c2_gd_x;
    c2_hd_x = muDoubleScalarCos(c2_hd_x);
    c2_q_b = c2_hd_x;
    c2_db_y = c2_s_a * c2_q_b;
    c2_pqr_osc[0] = c2_pb - c2_db_y;
    _SFD_EML_CALL(0,70);
    c2_t_a = c2_omega;
    c2_id_x = c2_beta;
    c2_r_b = c2_id_x;
    c2_jd_x = c2_r_b;
    c2_kd_x = c2_jd_x;
    c2_kd_x = muDoubleScalarSin(c2_kd_x);
    c2_r_b = c2_kd_x;
    c2_eb_y = c2_t_a * c2_r_b;
    c2_pqr_osc[1] = c2_qb - c2_eb_y;
    _SFD_EML_CALL(0,71);
    c2_pqr_osc[2] = 0.0;
    break;

   case 3:
    CV_EML_SWITCH(0, 0, 3);
    _SFD_EML_CALL(0,74);
    c2_pqr_osc[0] = c2_pb;
    _SFD_EML_CALL(0,75);
    c2_pqr_osc[1] = c2_qb;
    _SFD_EML_CALL(0,76);
    c2_pqr_osc[2] = c2_rb;
    _SFD_EML_CALL(0,77);
    c2_omega = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 0, 0);
    break;
  }

  /* -----------------------------------------------% End Hybrid Kalviste */
  /*  Scale values for table lookup */
  _SFD_EML_CALL(0,83);
  c2_e_A = c2_B;
  c2_s_b = c2_tas;
  c2_u_a = 2.0 * c2_s_b;
  c2_f_B = c2_u_a * 1.689;
  c2_ld_x = c2_e_A;
  c2_fb_y = c2_f_B;
  if (c2_fb_y == 0.0) {
    c2_eml_warning(chartInstance);
  }

  c2_md_x = c2_ld_x;
  c2_gb_y = c2_fb_y;
  c2_nd_x = c2_md_x;
  c2_hb_y = c2_gb_y;
  c2_b2vt = c2_nd_x / c2_hb_y;
  _SFD_EML_CALL(0,84);
  c2_f_A = c2_Cbar;
  c2_t_b = c2_tas;
  c2_v_a = 2.0 * c2_t_b;
  c2_g_B = c2_v_a * 1.689;
  c2_od_x = c2_f_A;
  c2_ib_y = c2_g_B;
  if (c2_ib_y == 0.0) {
    c2_eml_warning(chartInstance);
  }

  c2_pd_x = c2_od_x;
  c2_jb_y = c2_ib_y;
  c2_qd_x = c2_pd_x;
  c2_kb_y = c2_jb_y;
  c2_c2vt = c2_qd_x / c2_kb_y;
  _SFD_EML_CALL(0,85);
  c2_w_a = c2_omega;
  c2_u_b = c2_b2vt;
  c2_omega = c2_w_a * c2_u_b;
  _SFD_EML_CALL(0,86);
  c2_b_b2vt[0] = c2_b2vt;
  c2_b_b2vt[1] = c2_c2vt;
  c2_b_b2vt[2] = c2_b2vt;
  for (c2_i4 = 0; c2_i4 < 3; c2_i4 = c2_i4 + 1) {
    c2_pqr_osc[c2_i4] = c2_pqr_osc[c2_i4] * c2_b_b2vt[c2_i4];
  }

  _SFD_EML_CALL(0,-86);
  sf_debug_symbol_scope_pop();
  *c2_b_omega = c2_omega;
  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    (*c2_b_pqr_osc)[c2_i5] = c2_pqr_osc[c2_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_warning(SFc2_modelsInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  static char_T c2_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c2_u[19];
  const mxArray *c2_y = NULL;
  int32_T c2_i7;
  static char_T c2_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c2_b_u[15];
  const mxArray *c2_b_y = NULL;
  for (c2_i6 = 0; c2_i6 < 19; c2_i6 = c2_i6 + 1) {
    c2_u[c2_i6] = c2_varargin_1[c2_i6];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c2_i7 = 0; c2_i7 < 15; c2_i7 = c2_i7 + 1) {
    c2_b_u[c2_i7] = c2_varargin_2[c2_i7];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelsInstanceStruct *)chartInstanceVoid;
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
  int32_T c2_i8;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelsInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_b_u[c2_i8] = (*((real_T (*)[3])c2_u))[c2_i8];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_models_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[31];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i9;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c2_i9 = 0; c2_i9 < 31; c2_i9 = c2_i9 + 1) {
    c2_r0 = &c2_info[c2_i9];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i9);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i9);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31])
{
  c2_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c2_info[0].name = "isreal";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]isreal";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[1].name = "ischar";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]ischar";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "abs";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[2].fileLength = 538U;
  c2_info[2].fileTime1 = 1203473128U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[3].name = "gt";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]gt";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[4].name = "not";
  c2_info[4].dominantType = "logical";
  c2_info[4].resolved = "[B]not";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[5].name = "isa";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isa";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileLength = 2336U;
  c2_info[6].fileTime1 = 1213662890U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].name = "class";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]class";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[8].name = "eml_scalar_abs";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[8].fileLength = 461U;
  c2_info[8].fileTime1 = 1203473160U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "size";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]size";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[10].name = "rdivide";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].fileLength = 620U;
  c2_info[10].fileTime1 = 1213662890U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[11].name = "isscalar";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]isscalar";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "times";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]times";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "sin";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[13].fileLength = 324U;
  c2_info[13].fileTime1 = 1203473242U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[14].name = "ge";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]ge";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "";
  c2_info[15].name = "pi";
  c2_info[15].dominantType = "";
  c2_info[15].resolved = "[B]pi";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[16].name = "islogical";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]islogical";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[17].name = "isempty";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]isempty";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "";
  c2_info[18].name = "minus";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]minus";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "lt";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]lt";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[20].name = "strcmp";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved = "[B]strcmp";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[21].name = "eml_warning";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[21].fileLength = 262U;
  c2_info[21].fileTime1 = 1213662888U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[22].name = "eml_scalar_sin";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[22].fileLength = 601U;
  c2_info[22].fileTime1 = 1209355992U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[23].name = "eq";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]eq";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[24].name = "eml_scalar_cos";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[24].fileLength = 602U;
  c2_info[24].fileTime1 = 1209355988U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "";
  c2_info[25].name = "mrdivide";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[25].fileLength = 755U;
  c2_info[25].fileTime1 = 1209356082U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[26].name = "nargin";
  c2_info[26].dominantType = "";
  c2_info[26].resolved = "[B]nargin";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "";
  c2_info[27].name = "zeros";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]zeros";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[28].name = "eml_div";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[28].fileLength = 4254U;
  c2_info[28].fileTime1 = 1192491972U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "";
  c2_info[29].name = "cos";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[29].fileLength = 324U;
  c2_info[29].fileTime1 = 1203473152U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[30].name = "isinteger";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved = "[B]isinteger";
  c2_info[30].fileLength = 0U;
  c2_info[30].fileTime1 = 0U;
  c2_info[30].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc2_modelsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_models_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3995141329U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4084651321U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2475378554U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(840539676U);
}

mxArray *sf_c2_models_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3015159630U);
    pr[1] = (double)(1529796674U);
    pr[2] = (double)(3082481547U);
    pr[3] = (double)(2659662496U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc2_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelsInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_modelsMachineNumber_,
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
          init_script_number_translation(_modelsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_modelsMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_modelsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"alpha",0,
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"omega",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"beta",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tas",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pqr",0,c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pqr_osc",0,NULL);
          }

          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"B",0,
                              NULL);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Cbar",0,
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
        _SFD_CV_INIT_EML(0,1,9,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1710);
        _SFD_CV_INIT_EML_IF(0,0,444,472,473,672);
        _SFD_CV_INIT_EML_IF(0,1,473,487,488,672);
        _SFD_CV_INIT_EML_IF(0,2,581,604,609,668);
        _SFD_CV_INIT_EML_IF(0,3,609,628,633,668);
        _SFD_CV_INIT_EML_IF(0,4,702,730,731,930);
        _SFD_CV_INIT_EML_IF(0,5,731,745,746,930);
        _SFD_CV_INIT_EML_IF(0,6,839,862,867,926);
        _SFD_CV_INIT_EML_IF(0,7,867,886,891,926);
        _SFD_CV_INIT_EML_IF(0,8,960,977,-1,1000);

        {
          static int caseStart[] = { -1, 1026, 1218, 1394 };

          static int caseExprEnd[] = { 8, 1032, 1224, 1400 };

          _SFD_CV_INIT_EML_SWITCH(0,0,1005,1022,1498,4,&(caseStart[0]),
            &(caseExprEnd[0]));
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
          real_T *c2_alpha;
          real_T *c2_omega;
          real_T *c2_beta;
          real_T *c2_tas;
          real_T (*c2_pqr)[3];
          real_T (*c2_pqr_osc)[3];
          real_T *c2_B;
          real_T *c2_Cbar;
          c2_tas = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_pqr_osc = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_Cbar = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_pqr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c2_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_alpha);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_omega);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_beta);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_tas);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_pqr);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_pqr_osc);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_B);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_Cbar);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_modelsMachineNumber_,
      chartInstance->chartNumber,chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c2_models(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_modelsInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
  initialize_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_models(void *chartInstanceVar)
{
  enable_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_models(void *chartInstanceVar)
{
  disable_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_models(void *chartInstanceVar)
{
  sf_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c2_models(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_models((SFc2_modelsInstanceStruct*)
    chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c2_models(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar,
    sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_models(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_modelsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_models((SFc2_modelsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_models(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_models((SFc2_modelsInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_models(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("models","vel_loop_Bmat",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("models","vel_loop_Bmat",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("models","vel_loop_Bmat",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"models","vel_loop_Bmat",2,6);
      sf_mark_chart_reusable_outputs(S,"models","vel_loop_Bmat",2,2);
    }

    sf_set_rtw_dwork_info(S,"models","vel_loop_Bmat",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2686453363U));
  ssSetChecksum1(S,(2081193936U));
  ssSetChecksum2(S,(1561858524U));
  ssSetChecksum3(S,(2273302081U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_models(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "models", "vel_loop_Bmat",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_models(SimStruct *S)
{
  SFc2_modelsInstanceStruct *chartInstance;
  chartInstance = (SFc2_modelsInstanceStruct *)malloc(sizeof
    (SFc2_modelsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_models;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_models;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_models;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_models;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_models;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_models;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_models;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_models;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_models;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_models;
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

void c2_models_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_models(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_models(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_models(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_models_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
