#include "main_sim_noadapt_sfun.h"
#include "sfcdebug.h"
#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

unsigned int sf_process_check_sum_call( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  extern unsigned int sf_main_sim_noadapt_process_check_sum_call( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_models_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_Polyval_lib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_GTM_aerolib_process_check_sum_call( int nlhs, mxArray *
    plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_T2_lib_process_check_sum_call( int nlhs, mxArray
    * plhs[], int nrhs, const mxArray * prhs[] );
  if (sf_main_sim_noadapt_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_models_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_Polyval_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_GTM_aerolib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  if (sf_engine_T2_lib_process_check_sum_call(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

unsigned int sf_process_autoinheritence_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_main_sim_noadapt_autoinheritance_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  if (sf_main_sim_noadapt_autoinheritance_info(nlhs,plhs,nrhs,prhs))
    return 1;
  return 0;
}

unsigned int sf_process_get_eml_resolved_functions_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  extern unsigned int sf_main_sim_noadapt_get_eml_resolved_functions_info( int
    nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_models_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_Polyval_lib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_GTM_aerolib_get_eml_resolved_functions_info( int nlhs,
    mxArray * plhs[], int nrhs, const mxArray * prhs[] );
  extern unsigned int sf_engine_T2_lib_get_eml_resolved_functions_info( int nlhs,
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
  if (strcmp(machineName, "main_sim_noadapt") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_main_sim_noadapt_get_eml_resolved_functions_info(nlhs,plhs,2,
      newRhs);
  }

  if (strcmp(machineName, "models") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_models_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "Polyval_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_Polyval_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "GTM_aerolib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_GTM_aerolib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
  }

  if (strcmp(machineName, "engine_T2_lib") == 0) {
    const mxArray *newRhs[2] = { NULL, NULL };

    newRhs[0] = prhs[0];
    newRhs[1] = prhs[2];
    return sf_engine_T2_lib_get_eml_resolved_functions_info(nlhs,plhs,2,newRhs);
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

extern unsigned int sf_main_sim_noadapt_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, int_T method, void *data);
extern unsigned int sf_models_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_Polyval_lib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_GTM_aerolib_method_dispatcher(SimStruct *S, unsigned int
  chartFileNumber, int_T method, void *data);
extern unsigned int sf_engine_T2_lib_method_dispatcher(SimStruct *S, unsigned
  int chartFileNumber, int_T method, void *data);
unsigned int sf_machine_global_method_dispatcher(SimStruct *simstructPtr, const
  char *machineName, unsigned int chartFileNumber, int_T method, void *data)
{
  if (!strcmp(machineName,"main_sim_noadapt")) {
    return(sf_main_sim_noadapt_method_dispatcher(simstructPtr,chartFileNumber,
            method,data));
  }

  if (!strcmp(machineName,"models")) {
    return(sf_models_method_dispatcher(simstructPtr,chartFileNumber,method,data));
  }

  if (!strcmp(machineName,"Polyval_lib")) {
    return(sf_Polyval_lib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"GTM_aerolib")) {
    return(sf_GTM_aerolib_method_dispatcher(simstructPtr,chartFileNumber,method,
            data));
  }

  if (!strcmp(machineName,"engine_T2_lib")) {
    return(sf_engine_T2_lib_method_dispatcher(simstructPtr,chartFileNumber,
            method,data));
  }

  return 0;
}

extern void main_sim_noadapt_terminator(void);
extern void models_terminator(void);
extern void Polyval_lib_terminator(void);
extern void GTM_aerolib_terminator(void);
extern void engine_T2_lib_terminator(void);
void sf_machine_global_terminator(void)
{
  if (sfMachineGlobalTerminatorCallable) {
    sfMachineGlobalTerminatorCallable = 0;
    sfMachineGlobalInitializerCallable = 1;
    main_sim_noadapt_terminator();
    models_terminator();
    Polyval_lib_terminator();
    GTM_aerolib_terminator();
    engine_T2_lib_terminator();
    sf_debug_terminate();
  }

  return;
}

extern void main_sim_noadapt_initializer(void);
extern void models_initializer(void);
extern void Polyval_lib_initializer(void);
extern void GTM_aerolib_initializer(void);
extern void engine_T2_lib_initializer(void);
extern void main_sim_noadapt_register_exported_symbols(SimStruct* S);
extern void models_register_exported_symbols(SimStruct* S);
extern void Polyval_lib_register_exported_symbols(SimStruct* S);
extern void GTM_aerolib_register_exported_symbols(SimStruct* S);
extern void engine_T2_lib_register_exported_symbols(SimStruct* S);
extern void main_sim_noadapt_debug_initialize(void);
extern void models_debug_initialize(void);
extern void Polyval_lib_debug_initialize(void);
extern void GTM_aerolib_debug_initialize(void);
extern void engine_T2_lib_debug_initialize(void);
void sf_register_machine_exported_symbols(SimStruct* S)
{
  main_sim_noadapt_register_exported_symbols(S);
  models_register_exported_symbols(S);
  Polyval_lib_register_exported_symbols(S);
  GTM_aerolib_register_exported_symbols(S);
  engine_T2_lib_register_exported_symbols(S);
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
      main_sim_noadapt_debug_initialize();
    }

    main_sim_noadapt_initializer();
    if (!simModeIsRTWGen) {
      models_debug_initialize();
    }

    models_initializer();
    if (!simModeIsRTWGen) {
      Polyval_lib_debug_initialize();
    }

    Polyval_lib_initializer();
    if (!simModeIsRTWGen) {
      GTM_aerolib_debug_initialize();
    }

    GTM_aerolib_initializer();
    if (!simModeIsRTWGen) {
      engine_T2_lib_debug_initialize();
    }

    engine_T2_lib_initializer();
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
