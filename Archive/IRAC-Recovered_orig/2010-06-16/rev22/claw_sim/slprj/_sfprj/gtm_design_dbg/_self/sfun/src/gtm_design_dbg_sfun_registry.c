#include "gtm_design_dbg_sfun.h"
#include "sfcdebug.h"
#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

unsigned int sf_process_check_sum_call( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  extern unsigned int sf_gtm_design_dbg_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_aeroutilslib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_GTM_aerolib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_JetCatP70_lib_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_T2_lib_process_check_sum_call( int nlhs, mxArray
    * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_auxvars_lib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_acparams_lib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_landinggear_lib_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_aircraft_lib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  if (sf_gtm_design_dbg_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_aeroutilslib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_GTM_aerolib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_engine_JetCatP70_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_engine_T2_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_auxvars_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_acparams_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_landinggear_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_aircraft_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

unsigned int sf_process_autoinheritence_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_gtm_design_dbg_autoinheritance_info( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  if (sf_gtm_design_dbg_autoinheritance_info(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

unsigned int sf_process_get_eml_resolved_functions_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_gtm_design_dbg_get_eml_resolved_functions_info( int
    nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_aeroutilslib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_GTM_aerolib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_JetCatP70_lib_get_eml_resolved_functions_info
    ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_T2_lib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_auxvars_lib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_acparams_lib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_landinggear_lib_get_eml_resolved_functions_info( int
    nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_aircraft_lib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  char commandName[64];
  char machineName[128];
  if (nrhs < 3) {
    return 0;
  }

  if (!mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;
  mxGetString(prhs[1], machineName,sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (strcmp(machineName, "gtm_design_dbg") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_gtm_design_dbg_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "aeroutilslib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_aeroutilslib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "GTM_aerolib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_GTM_aerolib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "engine_JetCatP70_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_engine_JetCatP70_lib_get_eml_resolved_functions_info(nlhs,plhs,2,
      newRhs);
  }

  if (strcmp(machineName, "engine_T2_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_engine_T2_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "auxvars_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_auxvars_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "acparams_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_acparams_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "landinggear_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_landinggear_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "aircraft_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_aircraft_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  return 0;
}

unsigned int sf_mex_unlock_call( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] )
{
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_mex_unlock"))
    return 0;
  while (mexIsLocked()) {
    mexUnlock();
  }

  return(1);
}

extern unsigned int sf_debug_api( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] );
static unsigned int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  if (sf_debug_api(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_mex_unlock_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_autoinheritence_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_process_get_eml_resolved_functions_info_call(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

static unsigned int sfMachineGlobalTerminatorCallable = 0;
static unsigned int sfMachineGlobalInitializerCallable = 1;
unsigned int sf_machine_global_initializer_called(void)
{
  return(!sfMachineGlobalInitializerCallable);
}

extern unsigned int sf_gtm_design_dbg_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, int_T method, void *data);
extern unsigned int sf_aeroutilslib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_GTM_aerolib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_engine_JetCatP70_lib_method_dispatcher(SimStruct *S,
  unsigned int chartFileNumber, int_T method, void *data);
extern unsigned int sf_engine_T2_lib_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, int_T method, void *data);
extern unsigned int sf_auxvars_lib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_acparams_lib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_landinggear_lib_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, int_T method, void *data);
extern unsigned int sf_aircraft_lib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
unsigned int sf_machine_global_method_dispatcher(SimStruct *simstructPtr, const
  char *machineName, unsigned int chartFileNumber, int_T method, void *data)
{
  if (!strcmp(machineName,"gtm_design_dbg")) {
    return(sf_gtm_design_dbg_method_dispatcher(simstructPtr,chartFileNumber,
            method,data));
  }

  if (!strcmp(machineName,"aeroutilslib")) {
    return(sf_aeroutilslib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"GTM_aerolib")) {
    return(sf_GTM_aerolib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"engine_JetCatP70_lib")) {
    return(sf_engine_JetCatP70_lib_method_dispatcher(simstructPtr,
            chartFileNumber,method,data));
  }

  if (!strcmp(machineName,"engine_T2_lib")) {
    return(sf_engine_T2_lib_method_dispatcher(simstructPtr,chartFileNumber,
            method,data));
  }

  if (!strcmp(machineName,"auxvars_lib")) {
    return(sf_auxvars_lib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"acparams_lib")) {
    return(sf_acparams_lib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"landinggear_lib")) {
    return(sf_landinggear_lib_method_dispatcher(simstructPtr,chartFileNumber,
            method,data));
  }

  if (!strcmp(machineName,"aircraft_lib")) {
    return(sf_aircraft_lib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  return 0;
}

extern void gtm_design_dbg_terminator(void);
extern void aeroutilslib_terminator(void);
extern void GTM_aerolib_terminator(void);
extern void engine_JetCatP70_lib_terminator(void);
extern void engine_T2_lib_terminator(void);
extern void auxvars_lib_terminator(void);
extern void acparams_lib_terminator(void);
extern void landinggear_lib_terminator(void);
extern void aircraft_lib_terminator(void);
void sf_machine_global_terminator(void)
{
  if (sfMachineGlobalTerminatorCallable) {
    sfMachineGlobalTerminatorCallable = 0;
    sfMachineGlobalInitializerCallable = 1;
    gtm_design_dbg_terminator();
    aeroutilslib_terminator();
    GTM_aerolib_terminator();
    engine_JetCatP70_lib_terminator();
    engine_T2_lib_terminator();
    auxvars_lib_terminator();
    acparams_lib_terminator();
    landinggear_lib_terminator();
    aircraft_lib_terminator();
    sf_debug_terminate();
  }

  return;
}

extern void gtm_design_dbg_initializer(void);
extern void aeroutilslib_initializer(void);
extern void GTM_aerolib_initializer(void);
extern void engine_JetCatP70_lib_initializer(void);
extern void engine_T2_lib_initializer(void);
extern void auxvars_lib_initializer(void);
extern void acparams_lib_initializer(void);
extern void landinggear_lib_initializer(void);
extern void aircraft_lib_initializer(void);
extern void gtm_design_dbg_register_exported_symbols(SimStruct* S);
extern void aeroutilslib_register_exported_symbols(SimStruct* S);
extern void GTM_aerolib_register_exported_symbols(SimStruct* S);
extern void engine_JetCatP70_lib_register_exported_symbols(SimStruct* S);
extern void engine_T2_lib_register_exported_symbols(SimStruct* S);
extern void auxvars_lib_register_exported_symbols(SimStruct* S);
extern void acparams_lib_register_exported_symbols(SimStruct* S);
extern void landinggear_lib_register_exported_symbols(SimStruct* S);
extern void aircraft_lib_register_exported_symbols(SimStruct* S);
extern void gtm_design_dbg_debug_initialize(void);
extern void aeroutilslib_debug_initialize(void);
extern void GTM_aerolib_debug_initialize(void);
extern void engine_JetCatP70_lib_debug_initialize(void);
extern void engine_T2_lib_debug_initialize(void);
extern void auxvars_lib_debug_initialize(void);
extern void acparams_lib_debug_initialize(void);
extern void landinggear_lib_debug_initialize(void);
extern void aircraft_lib_debug_initialize(void);
void sf_register_machine_exported_symbols(SimStruct* S)
{
  gtm_design_dbg_register_exported_symbols(S);
  aeroutilslib_register_exported_symbols(S);
  GTM_aerolib_register_exported_symbols(S);
  engine_JetCatP70_lib_register_exported_symbols(S);
  engine_T2_lib_register_exported_symbols(S);
  auxvars_lib_register_exported_symbols(S);
  acparams_lib_register_exported_symbols(S);
  landinggear_lib_register_exported_symbols(S);
  aircraft_lib_register_exported_symbols(S);
}

void sf_machine_global_initializer(SimStruct* S)
{
  bool simModeIsRTWGen = sim_mode_is_rtw_gen(S);
  if (sfMachineGlobalInitializerCallable) {
    sfMachineGlobalInitializerCallable = 0;
    sfMachineGlobalTerminatorCallable = 1;
    if (simModeIsRTWGen) {
      sf_register_machine_exported_symbols(S);
    }

    if (!simModeIsRTWGen) {
      gtm_design_dbg_debug_initialize();
    }

    gtm_design_dbg_initializer();
    if (!simModeIsRTWGen) {
      aeroutilslib_debug_initialize();
    }

    aeroutilslib_initializer();
    if (!simModeIsRTWGen) {
      GTM_aerolib_debug_initialize();
    }

    GTM_aerolib_initializer();
    if (!simModeIsRTWGen) {
      engine_JetCatP70_lib_debug_initialize();
    }

    engine_JetCatP70_lib_initializer();
    if (!simModeIsRTWGen) {
      engine_T2_lib_debug_initialize();
    }

    engine_T2_lib_initializer();
    if (!simModeIsRTWGen) {
      auxvars_lib_debug_initialize();
    }

    auxvars_lib_initializer();
    if (!simModeIsRTWGen) {
      acparams_lib_debug_initialize();
    }

    acparams_lib_initializer();
    if (!simModeIsRTWGen) {
      landinggear_lib_debug_initialize();
    }

    landinggear_lib_initializer();
    if (!simModeIsRTWGen) {
      aircraft_lib_debug_initialize();
    }

    aircraft_lib_initializer();
  }

  return;
}

#define PROCESS_MEX_SFUNCTION_EVERY_CALL

unsigned int ProcessMexSfunctionEveryCall(int_T nlhs, mxArray *plhs[], int_T
  nrhs, const mxArray *prhs[]);

#include "simulink.c"                  /* MEX-file interface mechanism */

static void sf_machine_load_sfunction_ptrs(SimStruct *S)
{
  ssSetmdlInitializeSampleTimes(S,__mdlInitializeSampleTimes);
  ssSetmdlInitializeConditions(S,__mdlInitializeConditions);
  ssSetmdlOutputs(S,__mdlOutputs);
  ssSetmdlTerminate(S,__mdlTerminate);
  ssSetmdlRTW(S,__mdlRTW);
  ssSetmdlSetWorkWidths(S,__mdlSetWorkWidths);

#if defined(MDL_HASSIMULATIONCONTEXTIO)

  ssSetmdlSimulationContextIO(S,__mdlSimulationContextIO);

#endif

#if defined(MDL_START)

  ssSetmdlStart(S,__mdlStart);

#endif

#if defined(RTW_GENERATED_ENABLE)

  ssSetRTWGeneratedEnable(S,__mdlEnable);

#endif

#if defined(RTW_GENERATED_DISABLE)

  ssSetRTWGeneratedDisable(S,__mdlDisable);

#endif

#if defined(MDL_ENABLE)

  ssSetmdlEnable(S,__mdlEnable);

#endif

#if defined(MDL_DISABLE)

  ssSetmdlDisable(S,__mdlDisable);

#endif

#if defined(MDL_SIM_STATUS_CHANGE)

  ssSetmdlSimStatusChange(S,__mdlSimStatusChange);

#endif

#if defined(MDL_EXT_MODE_EXEC)

  ssSetmdlExtModeExec(S,__mdlExtModeExec);

#endif

#if defined(MDL_UPDATE)

  ssSetmdlUpdate(S,__mdlUpdate);

#endif

#if defined(MDL_PROCESS_PARAMETERS)

  ssSetmdlProcessParameters(S,__mdlProcessParameters);

#endif

#if defined(MDL_ZERO_CROSSINGS)

  ssSetmdlZeroCrossings(S,__mdlZeroCrossings);

#endif

#if defined(MDL_DERIVATIVES)

  ssSetmdlDerivatives(S,__mdlDerivatives);

#endif

}

unsigned int ProcessMexSfunctionEveryCall(int_T nlhs, mxArray *plhs[], int_T
  nrhs, const mxArray *prhs[])
{
  if (nlhs < 0) {
    SimStruct *S = (SimStruct *)plhs[_LHS_SS];
    int_T flag = (int_T)(*(real_T*)mxGetPr(prhs[_RHS_FLAG]));
    if (flag == SS_CALL_MDL_SET_WORK_WIDTHS) {
      sf_machine_load_sfunction_ptrs(S);
    }
  }

  return 0;
}
