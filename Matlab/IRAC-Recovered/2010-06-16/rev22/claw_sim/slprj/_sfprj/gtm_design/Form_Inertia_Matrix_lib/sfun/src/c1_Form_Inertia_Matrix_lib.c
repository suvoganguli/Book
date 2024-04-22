/* Include files */

#include "Form_Inertia_Matrix_lib_sfun.h"
#include "c1_Form_Inertia_Matrix_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Form_Inertia_Matrix_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void initialize_params_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void enable_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void disable_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void update_debugger_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void set_sim_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void sf_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_mpower(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance, real_T c1_a);
static void c1_eml_warning(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[52]);
static void init_dsm_address_info(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Form_Inertia_Matrix_lib = 0U;
}

static void initialize_params_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
}

static void enable_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance, const mxArray
   *c1_st
   )
{
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
}

static void sf_c1_Form_Inertia_Matrix_lib
  (SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  uint8_T c1_previousEvent;
  real_T c1_Ixx;
  real_T c1_Iyy;
  real_T c1_Izz;
  real_T c1_Ixz;
  real_T c1_Iyz;
  real_T c1_Ixy;
  real_T c1_nargout = 2.0;
  real_T c1_nargin = 6.0;
  real_T c1_adjoint[9];
  real_T c1_det;
  real_T c1_InvI[9];
  real_T c1_I[9];
  real_T c1_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_b_b;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_c_a;
  real_T c1_d_b;
  real_T c1_b_y;
  real_T c1_d_a;
  real_T c1_e_b;
  real_T c1_c_y;
  real_T c1_e_a;
  real_T c1_f_b;
  real_T c1_d_y;
  real_T c1_f_a;
  real_T c1_g_b;
  real_T c1_g_a;
  real_T c1_h_b;
  real_T c1_e_y;
  real_T c1_h_a;
  real_T c1_i_b;
  real_T c1_f_y;
  real_T c1_i_a;
  real_T c1_j_b;
  real_T c1_g_y;
  real_T c1_j_a;
  real_T c1_k_b;
  real_T c1_h_y;
  real_T c1_k_a;
  real_T c1_l_b;
  real_T c1_i_y;
  real_T c1_l_a;
  real_T c1_m_b;
  real_T c1_j_y;
  real_T c1_m_a;
  real_T c1_n_b;
  real_T c1_k_y;
  real_T c1_n_a;
  real_T c1_o_b;
  real_T c1_l_y;
  real_T c1_o_a;
  real_T c1_p_b;
  real_T c1_m_y;
  real_T c1_p_a;
  real_T c1_q_b;
  real_T c1_n_y;
  real_T c1_q_a;
  real_T c1_r_b;
  real_T c1_o_y;
  real_T c1_r_a;
  real_T c1_s_b;
  real_T c1_p_y;
  real_T c1_s_a;
  real_T c1_t_b;
  real_T c1_q_y;
  real_T c1_t_a;
  real_T c1_u_b;
  real_T c1_r_y;
  real_T c1_u_a;
  real_T c1_v_b;
  real_T c1_s_y;
  real_T c1_v_a;
  real_T c1_w_b;
  real_T c1_t_y;
  real_T c1_u_y;
  real_T c1_v_y;
  real_T c1_w_y;
  int32_T c1_i2;
  real_T c1_A[9];
  real_T c1_B;
  int32_T c1_i3;
  real_T c1_x[9];
  real_T c1_x_y;
  int32_T c1_i4;
  real_T c1_b_x[9];
  real_T c1_y_y;
  int32_T c1_i5;
  real_T c1_c_x[9];
  real_T c1_ab_y;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T *c1_b_Ixx;
  real_T *c1_b_Iyy;
  real_T *c1_b_Izz;
  real_T *c1_b_Ixz;
  real_T *c1_b_Iyz;
  real_T *c1_b_Ixy;
  real_T (*c1_b_I)[9];
  real_T (*c1_b_InvI)[9];
  c1_b_I = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Iyz = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_InvI = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Iyy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_Ixz = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_Ixx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_Izz = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Ixy = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c1_b_Ixx, 0U);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_I)[c1_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_Iyy, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Izz, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Ixz, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Iyz, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Ixy, 6U);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1 = c1_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_InvI)[c1_i1], 7U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_Ixx = *c1_b_Ixx;
  c1_Iyy = *c1_b_Iyy;
  c1_Izz = *c1_b_Izz;
  c1_Ixz = *c1_b_Ixz;
  c1_Iyz = *c1_b_Iyz;
  c1_Ixy = *c1_b_Ixy;
  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("adjoint", &c1_adjoint, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("det", &c1_det, c1_sf_marshall);
  sf_debug_symbol_scope_add("InvI", &c1_InvI, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("I", &c1_I, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("Ixy", &c1_Ixy, c1_sf_marshall);
  sf_debug_symbol_scope_add("Iyz", &c1_Iyz, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ixz", &c1_Ixz, c1_sf_marshall);
  sf_debug_symbol_scope_add("Izz", &c1_Izz, c1_sf_marshall);
  sf_debug_symbol_scope_add("Iyy", &c1_Iyy, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ixx", &c1_Ixx, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0,5);
  c1_I[0] = c1_Ixx;
  c1_I[3] = -c1_Ixy;
  c1_I[6] = -c1_Ixz;
  c1_I[1] = -c1_Ixy;
  c1_I[4] = c1_Iyy;
  c1_I[7] = -c1_Iyz;
  c1_I[2] = -c1_Ixz;
  c1_I[5] = -c1_Iyz;
  c1_I[8] = c1_Izz;
  _SFD_EML_CALL(0,9);
  c1_a = c1_mpower(chartInstance, c1_Ixz);
  c1_b = c1_Iyy;
  c1_y = c1_a * c1_b;
  c1_b_b = c1_Ixy;
  c1_b_a = 2.0 * c1_b_b;
  c1_c_b = c1_Ixz;
  c1_c_a = c1_b_a * c1_c_b;
  c1_d_b = c1_Iyz;
  c1_b_y = c1_c_a * c1_d_b;
  c1_d_a = c1_mpower(chartInstance, c1_Ixy);
  c1_e_b = c1_Izz;
  c1_c_y = c1_d_a * c1_e_b;
  c1_e_a = c1_Ixx;
  c1_f_b = c1_mpower(chartInstance, c1_Iyz);
  c1_d_y = c1_e_a * c1_f_b;
  c1_f_a = c1_Ixx;
  c1_g_b = c1_Iyy;
  c1_g_a = c1_f_a * c1_g_b;
  c1_h_b = c1_Izz;
  c1_e_y = c1_g_a * c1_h_b;
  c1_det = (((c1_e_y - c1_d_y) - c1_c_y) - c1_b_y) - c1_y;
  _SFD_EML_CALL(0,11);
  c1_h_a = c1_Ixx;
  c1_i_b = c1_Iyy;
  c1_f_y = c1_h_a * c1_i_b;
  c1_i_a = c1_Ixy;
  c1_j_b = c1_Ixz;
  c1_g_y = c1_i_a * c1_j_b;
  c1_j_a = c1_Ixx;
  c1_k_b = c1_Iyz;
  c1_h_y = c1_j_a * c1_k_b;
  c1_k_a = c1_Ixz;
  c1_l_b = c1_Iyy;
  c1_i_y = c1_k_a * c1_l_b;
  c1_l_a = c1_Ixy;
  c1_m_b = c1_Iyz;
  c1_j_y = c1_l_a * c1_m_b;
  c1_m_a = c1_Ixy;
  c1_n_b = c1_Ixz;
  c1_k_y = c1_m_a * c1_n_b;
  c1_n_a = c1_Ixx;
  c1_o_b = c1_Iyz;
  c1_l_y = c1_n_a * c1_o_b;
  c1_o_a = c1_Ixx;
  c1_p_b = c1_Izz;
  c1_m_y = c1_o_a * c1_p_b;
  c1_p_a = c1_Ixz;
  c1_q_b = c1_Iyz;
  c1_n_y = c1_p_a * c1_q_b;
  c1_q_a = c1_Ixy;
  c1_r_b = c1_Izz;
  c1_o_y = c1_q_a * c1_r_b;
  c1_r_a = c1_Ixz;
  c1_s_b = c1_Iyy;
  c1_p_y = c1_r_a * c1_s_b;
  c1_s_a = c1_Ixy;
  c1_t_b = c1_Iyz;
  c1_q_y = c1_s_a * c1_t_b;
  c1_t_a = c1_Ixz;
  c1_u_b = c1_Iyz;
  c1_r_y = c1_t_a * c1_u_b;
  c1_u_a = c1_Ixy;
  c1_v_b = c1_Izz;
  c1_s_y = c1_u_a * c1_v_b;
  c1_v_a = c1_Iyy;
  c1_w_b = c1_Izz;
  c1_t_y = c1_v_a * c1_w_b;
  c1_u_y = c1_t_y - c1_mpower(chartInstance, c1_Iyz);
  c1_v_y = c1_m_y - c1_mpower(chartInstance, c1_Ixz);
  c1_w_y = c1_f_y - c1_mpower(chartInstance, c1_Ixy);
  c1_adjoint[0] = c1_u_y;
  c1_adjoint[3] = c1_s_y + c1_r_y;
  c1_adjoint[6] = c1_q_y + c1_p_y;
  c1_adjoint[1] = c1_o_y + c1_n_y;
  c1_adjoint[4] = c1_v_y;
  c1_adjoint[7] = c1_l_y + c1_k_y;
  c1_adjoint[2] = c1_j_y + c1_i_y;
  c1_adjoint[5] = c1_h_y + c1_g_y;
  c1_adjoint[8] = c1_w_y;
  _SFD_EML_CALL(0,16);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2 = c1_i2 + 1) {
    c1_A[c1_i2] = c1_adjoint[c1_i2];
  }

  c1_B = c1_det;
  for (c1_i3 = 0; c1_i3 < 9; c1_i3 = c1_i3 + 1) {
    c1_x[c1_i3] = c1_A[c1_i3];
  }

  c1_x_y = c1_B;
  if (c1_x_y == 0.0) {
    c1_eml_warning(chartInstance);
  }

  for (c1_i4 = 0; c1_i4 < 9; c1_i4 = c1_i4 + 1) {
    c1_b_x[c1_i4] = c1_x[c1_i4];
  }

  c1_y_y = c1_x_y;
  for (c1_i5 = 0; c1_i5 < 9; c1_i5 = c1_i5 + 1) {
    c1_c_x[c1_i5] = c1_b_x[c1_i5];
  }

  c1_ab_y = c1_y_y;
  for (c1_i6 = 0; c1_i6 < 9; c1_i6 = c1_i6 + 1) {
    c1_InvI[c1_i6] = c1_c_x[c1_i6] / c1_ab_y;
  }

  _SFD_EML_CALL(0,-16);
  sf_debug_symbol_scope_pop();
  for (c1_i7 = 0; c1_i7 < 9; c1_i7 = c1_i7 + 1) {
    (*c1_b_I)[c1_i7] = c1_I[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 9; c1_i8 = c1_i8 + 1) {
    (*c1_b_InvI)[c1_i8] = c1_InvI[c1_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_Form_Inertia_Matrix_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->
    instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_mpower(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_eml_warning(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance)
{
  int32_T c1_i9;
  static char_T c1_varargin_1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd',
    'i', 'v', 'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c1_u[19];
  const mxArray *c1_y = NULL;
  int32_T c1_i10;
  static char_T c1_varargin_2[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b',
    'y', ' ', 'z', 'e', 'r', 'o', '.' };

  char_T c1_b_u[15];
  const mxArray *c1_b_y = NULL;
  for (c1_i9 = 0; c1_i9 < 19; c1_i9 = c1_i9 + 1) {
    c1_u[c1_i9] = c1_varargin_1[c1_i9];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 19));
  for (c1_i10 = 0; c1_i10 < 15; c1_i10 = c1_i10 + 1) {
    c1_b_u[c1_i10] = c1_varargin_2[c1_i10];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_Form_Inertia_Matrix_libInstanceStruct *)
    chartInstanceVoid;
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
  int32_T c1_i11;
  int32_T c1_i12;
  real_T c1_b_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_Form_Inertia_Matrix_libInstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    for (c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
      c1_b_u[c1_i12 + 3 * c1_i11] = (*((real_T (*)[9])c1_u))[c1_i12 + 3 * c1_i11];
    }
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_Form_Inertia_Matrix_lib_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[52];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i13;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52));
  for (c1_i13 = 0; c1_i13 < 52; c1_i13 = c1_i13 + 1) {
    c1_r0 = &c1_info[c1_i13];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i13
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i13
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[52])
{
  c1_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[0].name = "eml_scalar_floor";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[0].fileLength = 260U;
  c1_info[0].fileTime1 = 1209355990U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[1].name = "ne";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]ne";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_warning";
  c1_info[2].dominantType = "char";
  c1_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[2].fileLength = 262U;
  c1_info[2].fileTime1 = 1213662888U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[3].name = "not";
  c1_info[3].dominantType = "logical";
  c1_info[3].resolved = "[B]not";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[4].name = "intmax";
  c1_info[4].dominantType = "char";
  c1_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[4].fileLength = 1535U;
  c1_info[4].fileTime1 = 1192491928U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "eq";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]eq";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "strcmp";
  c1_info[6].dominantType = "char";
  c1_info[6].resolved = "[B]strcmp";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[7].name = "isstruct";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isstruct";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "size";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]size";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[9].name = "ge";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]ge";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "isscalar";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isscalar";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[11].name = "ischar";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved = "[B]ischar";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[12].name = "eml_scalexp_size";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c1_info[12].fileLength = 1373U;
  c1_info[12].fileTime1 = 1208205260U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[13].name = "isempty";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]isempty";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c1_info[14].name = "eml_scalexp_compatible";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[14].fileLength = 502U;
  c1_info[14].fileTime1 = 1208205258U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "minus";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]minus";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "";
  c1_info[16].name = "uminus";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved = "[B]uminus";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[17].name = "class";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[B]class";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[18].name = "and";
  c1_info[18].dominantType = "logical";
  c1_info[18].resolved = "[B]and";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "mrdivide";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[19].fileLength = 755U;
  c1_info[19].fileTime1 = 1209356082U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[20].name = "lt";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]lt";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[21].name = "true";
  c1_info[21].dominantType = "";
  c1_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[21].fileLength = 237U;
  c1_info[21].fileTime1 = 1192491962U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "";
  c1_info[22].name = "mtimes";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[22].fileLength = 2336U;
  c1_info[22].fileTime1 = 1213662890U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[23].name = "eml_index_class";
  c1_info[23].dominantType = "";
  c1_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[23].fileLength = 909U;
  c1_info[23].fileTime1 = 1192491982U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "";
  c1_info[24].name = "mpower";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[24].fileLength = 3547U;
  c1_info[24].fileTime1 = 1213662888U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[25].name = "rdivide";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[25].fileLength = 620U;
  c1_info[25].fileTime1 = 1213662890U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[26].name = "eml_alloc";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[26].fileLength = 2627U;
  c1_info[26].fileTime1 = 1213662886U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[27].name = "zeros";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]zeros";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[28].name = "assert";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[28].fileLength = 2684U;
  c1_info[28].fileTime1 = 1210895856U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[29].name = "isa";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]isa";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[30].name = "isnumeric";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[B]isnumeric";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[31].name = "double";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]double";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c1_info[32].name = "cast";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[32].fileLength = 866U;
  c1_info[32].fileTime1 = 1192491844U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].name = "isinteger";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]isinteger";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[34].name = "isfinite";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[34].fileLength = 341U;
  c1_info[34].fileTime1 = 1192491934U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c1_info[35].name = "le";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]le";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[36].name = "isvector";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]isvector";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[37].name = "eml_div";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[37].fileLength = 4254U;
  c1_info[37].fileTime1 = 1192491972U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[38].name = "int32";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]int32";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[39].name = "false";
  c1_info[39].dominantType = "";
  c1_info[39].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[39].fileLength = 238U;
  c1_info[39].fileTime1 = 1192491920U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[40].name = "logical";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[B]logical";
  c1_info[40].fileLength = 0U;
  c1_info[40].fileTime1 = 0U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[41].name = "isnan";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[41].fileLength = 472U;
  c1_info[41].fileTime1 = 1192491936U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[42].name = "isreal";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[B]isreal";
  c1_info[42].fileLength = 0U;
  c1_info[42].fileTime1 = 0U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c1_info[43].name = "plus";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved = "[B]plus";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[44].name = "ndims";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved = "[B]ndims";
  c1_info[44].fileLength = 0U;
  c1_info[44].fileTime1 = 0U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[45].name = "nargin";
  c1_info[45].dominantType = "";
  c1_info[45].resolved = "[B]nargin";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[46].name = "gt";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved = "[B]gt";
  c1_info[46].fileLength = 0U;
  c1_info[46].fileTime1 = 0U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[47].name = "eml_error";
  c1_info[47].dominantType = "char";
  c1_info[47].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[47].fileLength = 315U;
  c1_info[47].fileTime1 = 1213662886U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[48].name = "power";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[48].fileLength = 5131U;
  c1_info[48].fileTime1 = 1213662890U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c1_info[49].name = "eml_assert_valid_size_arg";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[49].fileLength = 2835U;
  c1_info[49].fileTime1 = 1210895844U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[50].name = "isinf";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[50].fileLength = 472U;
  c1_info[50].fileTime1 = 1192491934U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/lang/assert.m";
  c1_info[51].name = "islogical";
  c1_info[51].dominantType = "logical";
  c1_info[51].resolved = "[B]islogical";
  c1_info[51].fileLength = 0U;
  c1_info[51].fileTime1 = 0U;
  c1_info[51].fileTime2 = 0U;
}

static void init_dsm_address_info(SFc1_Form_Inertia_Matrix_libInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Form_Inertia_Matrix_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2080796222U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1951360193U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3859308849U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2868644557U);
}

mxArray *sf_c1_Form_Inertia_Matrix_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1221721501U);
    pr[1] = (double)(875778148U);
    pr[2] = (double)(1761998066U);
    pr[3] = (double)(2586191884U);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_Form_Inertia_Matrix_libInstanceStruct *)
    ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Form_Inertia_Matrix_libMachineNumber_,
           1,
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
          init_script_number_translation(_Form_Inertia_Matrix_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Form_Inertia_Matrix_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Form_Inertia_Matrix_libMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ixx",0,
                              c1_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"I",0,c1_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Iyy",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Izz",0,
                              NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ixz",0,
                              NULL);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Iyz",0,
                              NULL);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ixy",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"InvI",0,NULL);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,486);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c1_Ixx;
          real_T (*c1_I)[9];
          real_T *c1_Iyy;
          real_T *c1_Izz;
          real_T *c1_Ixz;
          real_T *c1_Iyz;
          real_T *c1_Ixy;
          real_T (*c1_InvI)[9];
          c1_I = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Iyz = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_InvI = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Iyy = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_Ixz = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_Ixx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_Izz = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_Ixy = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Ixx);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_I);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Iyy);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Izz);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_Ixz);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_Iyz);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_Ixy);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_InvI);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_Form_Inertia_Matrix_libMachineNumber_,chartInstance->chartNumber,
       chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c1_Form_Inertia_Matrix_lib(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Form_Inertia_Matrix_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Form_Inertia_Matrix_lib
    ((SFc1_Form_Inertia_Matrix_libInstanceStruct*) chartInstanceVar);
  initialize_c1_Form_Inertia_Matrix_lib
    ((SFc1_Form_Inertia_Matrix_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Form_Inertia_Matrix_lib(void *chartInstanceVar)
{
  enable_c1_Form_Inertia_Matrix_lib((SFc1_Form_Inertia_Matrix_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_Form_Inertia_Matrix_lib(void *chartInstanceVar)
{
  disable_c1_Form_Inertia_Matrix_lib((SFc1_Form_Inertia_Matrix_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Form_Inertia_Matrix_lib(void *chartInstanceVar)
{
  sf_c1_Form_Inertia_Matrix_lib((SFc1_Form_Inertia_Matrix_libInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c1_Form_Inertia_Matrix_lib(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_Form_Inertia_Matrix_lib
    ((SFc1_Form_Inertia_Matrix_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c1_Form_Inertia_Matrix_lib(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c1_Form_Inertia_Matrix_lib
    ((SFc1_Form_Inertia_Matrix_libInstanceStruct*) chartInstanceVar, sf_mex_dup
     (st));
}

static void sf_opaque_terminate_c1_Form_Inertia_Matrix_lib(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Form_Inertia_Matrix_libInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Form_Inertia_Matrix_lib
      ((SFc1_Form_Inertia_Matrix_libInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Form_Inertia_Matrix_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Form_Inertia_Matrix_lib
      ((SFc1_Form_Inertia_Matrix_libInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Form_Inertia_Matrix_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Form_Inertia_Matrix_lib","gtm_design",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("Form_Inertia_Matrix_lib","gtm_design",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Form_Inertia_Matrix_lib",
      "gtm_design",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Form_Inertia_Matrix_lib",
        "gtm_design",1,6);
      sf_mark_chart_reusable_outputs(S,"Form_Inertia_Matrix_lib","gtm_design",1,
        2);
    }

    sf_set_rtw_dwork_info(S,"Form_Inertia_Matrix_lib","gtm_design",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3198495885U));
  ssSetChecksum1(S,(1419674515U));
  ssSetChecksum2(S,(3809346727U));
  ssSetChecksum3(S,(452642119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Form_Inertia_Matrix_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Form_Inertia_Matrix_lib", "gtm_design",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Form_Inertia_Matrix_lib(SimStruct *S)
{
  SFc1_Form_Inertia_Matrix_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_Form_Inertia_Matrix_libInstanceStruct *)malloc(sizeof
    (SFc1_Form_Inertia_Matrix_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Form_Inertia_Matrix_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Form_Inertia_Matrix_lib;
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

void c1_Form_Inertia_Matrix_lib_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Form_Inertia_Matrix_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Form_Inertia_Matrix_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Form_Inertia_Matrix_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Form_Inertia_Matrix_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
