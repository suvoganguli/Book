/* Include files */

#include "main_sim_claw_main_sf_sfun.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _main_sim_claw_main_sfMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void main_sim_claw_main_sf_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void main_sim_claw_main_sf_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_main_sim_claw_main_sf_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, int_T method, void *data)
{
  return 0;
}

unsigned int sf_main_sim_claw_main_sf_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3720688357U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2379033251U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3682193867U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4248433786U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1320111350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2129602331U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3510621148U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2555557675U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2095795527U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(362076406U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(670378476U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2107166022U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(269151645U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2148431686U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3048805871U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3191408831U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_main_sim_claw_main_sf_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_main_sim_claw_main_sf_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void main_sim_claw_main_sf_debug_initialize(void)
{
  _main_sim_claw_main_sfMachineNumber_ = sf_debug_initialize_machine(
    "main_sim_claw_main_sf","sfun",0,0,0,0,0);
  sf_debug_set_machine_event_thresholds(_main_sim_claw_main_sfMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_main_sim_claw_main_sfMachineNumber_,0);
}

void main_sim_claw_main_sf_register_exported_symbols(SimStruct* S)
{
}
