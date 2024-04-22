/* Include files */

#include "engine_JetCatP70_lib_sfun.h"
#include "c1_engine_JetCatP70_lib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "engine_JetCatP70_lib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void initialize_params_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void enable_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void disable_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void update_debugger_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void set_sim_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance);
static void sf_c1_engine_JetCatP70_lib(SFc1_engine_JetCatP70_libInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void init_dsm_address_info(SFc1_engine_JetCatP70_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_engine_JetCatP70_lib = 0U;
}

static void initialize_params_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
}

static void enable_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void update_debugger_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
  return NULL;
}

static void set_sim_state_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance, const mxArray *c1_st)
{
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_engine_JetCatP70_lib
  (SFc1_engine_JetCatP70_libInstanceStruct *chartInstance)
{
}

static void sf_c1_engine_JetCatP70_lib(SFc1_engine_JetCatP70_libInstanceStruct
  *chartInstance)
{
  uint8_T c1_previousEvent;
  real_T c1_pa;
  real_T c1_dp;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 2.0;
  real_T c1_tau;
  real_T *c1_b_pa;
  real_T *c1_b_dp;
  real_T *c1_b_tau;
  c1_b_pa = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_dp = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_tau = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c1_b_pa, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_dp, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_tau, 2U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_pa = *c1_b_pa;
  c1_dp = *c1_b_dp;
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("tau", &c1_tau, c1_sf_marshall);
  sf_debug_symbol_scope_add("dp", &c1_dp, c1_sf_marshall);
  sf_debug_symbol_scope_add("pa", &c1_pa, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details. */
  _SFD_EML_CALL(0,6);
  if (CV_EML_IF(0, 0, c1_dp >= 0.0)) {
    _SFD_EML_CALL(0,7);
    if (CV_EML_IF(0, 1, c1_pa >= 50.0)) {
      _SFD_EML_CALL(0,8);
      c1_tau = 1.44;

      /*  time constant = 1.44 sec. */
    } else {
      _SFD_EML_CALL(0,10);
      c1_tau = 1.96;

      /*  time constant = 1.96 sec. */
    }
  } else {
    /*  */
    /*   Power decrease. */
    /*  */
    _SFD_EML_CALL(0,16);
    if (CV_EML_IF(0, 2, c1_pa >= 50.0)) {
      _SFD_EML_CALL(0,17);
      c1_tau = 0.85;

      /*  time constant = 0.85 sec. */
    } else {
      _SFD_EML_CALL(0,19);
      c1_tau = 1.43;

      /*  time constant = 1.43 sec. */
    }
  }

  _SFD_EML_CALL(0,-19);
  sf_debug_symbol_scope_pop();
  *c1_b_tau = c1_tau;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_engine_JetCatP70_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->
    instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_engine_JetCatP70_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_JetCatP70_libInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_engine_JetCatP70_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[1];
  c1_ResolvedFunctionInfo (*c1_b_info)[1];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[1])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "ge";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved = "[B]ge";
  (*c1_b_info)[0].fileLength = 0U;
  (*c1_b_info)[0].fileTime1 = 0U;
  (*c1_b_info)[0].fileTime2 = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c1_i0 = 0; c1_i0 < 1; c1_i0 = c1_i0 + 1) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void init_dsm_address_info(SFc1_engine_JetCatP70_libInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_engine_JetCatP70_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2467271678U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1330173738U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3389633746U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2619908236U);
}

mxArray *sf_c1_engine_JetCatP70_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3287913593U);
    pr[1] = (double)(574120619U);
    pr[2] = (double)(38598839U);
    pr[3] = (double)(2082384419U);
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
  SFc1_engine_JetCatP70_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_JetCatP70_libInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_engine_JetCatP70_libMachineNumber_,
           1,
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
          init_script_number_translation(_engine_JetCatP70_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_engine_JetCatP70_libMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_engine_JetCatP70_libMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"pa",0,
                              c1_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dp",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tau",0,
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,436);
        _SFD_CV_INIT_EML_IF(0,0,128,138,266,436);
        _SFD_CV_INIT_EML_IF(0,1,143,154,206,265);
        _SFD_CV_INIT_EML_IF(0,2,310,321,373,432);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c1_pa;
          real_T *c1_dp;
          real_T *c1_tau;
          c1_pa = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_dp = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_tau = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_pa);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_dp);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_tau);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_engine_JetCatP70_libMachineNumber_,chartInstance->chartNumber,
       chartInstance->instanceNumber);
  }
}

static void sf_opaque_initialize_c1_engine_JetCatP70_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_engine_JetCatP70_lib
    ((SFc1_engine_JetCatP70_libInstanceStruct*) chartInstanceVar);
  initialize_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_engine_JetCatP70_lib(void *chartInstanceVar)
{
  enable_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_engine_JetCatP70_lib(void *chartInstanceVar)
{
  disable_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_engine_JetCatP70_lib(void *chartInstanceVar)
{
  sf_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_opaque_get_sim_state_c1_engine_JetCatP70_lib(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_engine_JetCatP70_lib
    ((SFc1_engine_JetCatP70_libInstanceStruct*) chartInstanceVar);
  return st;
}

static void sf_opaque_set_sim_state_c1_engine_JetCatP70_lib(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
    chartInstanceVar, sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_engine_JetCatP70_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_engine_JetCatP70_libInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_engine_JetCatP70_lib((SFc1_engine_JetCatP70_libInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_engine_JetCatP70_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_engine_JetCatP70_lib
      ((SFc1_engine_JetCatP70_libInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_engine_JetCatP70_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("engine_JetCatP70_lib","gtm_design_dbg",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("engine_JetCatP70_lib","gtm_design_dbg",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("engine_JetCatP70_lib",
      "gtm_design_dbg",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"engine_JetCatP70_lib",
        "gtm_design_dbg",1,2);
      sf_mark_chart_reusable_outputs(S,"engine_JetCatP70_lib","gtm_design_dbg",1,
        1);
    }

    sf_set_rtw_dwork_info(S,"engine_JetCatP70_lib","gtm_design_dbg",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2872752271U));
  ssSetChecksum1(S,(158581632U));
  ssSetChecksum2(S,(446145791U));
  ssSetChecksum3(S,(692888425U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_engine_JetCatP70_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "engine_JetCatP70_lib", "gtm_design_dbg",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_engine_JetCatP70_lib(SimStruct *S)
{
  SFc1_engine_JetCatP70_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_engine_JetCatP70_libInstanceStruct *)malloc(sizeof
    (SFc1_engine_JetCatP70_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_engine_JetCatP70_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_engine_JetCatP70_lib;
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

void c1_engine_JetCatP70_lib_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_engine_JetCatP70_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_engine_JetCatP70_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_engine_JetCatP70_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_engine_JetCatP70_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
