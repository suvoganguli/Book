/* Include files */

#include "gtm_design_sfun.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _gtm_designMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void gtm_design_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void gtm_design_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_gtm_design_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, int_T method, void *data)
{
  return 0;
}

unsigned int sf_gtm_design_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2674106908U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3254197382U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(408639110U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2143042737U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2508774896U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2973568442U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3222638303U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(389029931U);
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(197327120U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2950197879U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4213550391U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2745991157U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3011703865U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3103090129U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1823712442U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(981169468U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_gtm_design_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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

unsigned int sf_gtm_design_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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

void gtm_design_debug_initialize(void)
{
  _gtm_designMachineNumber_ = sf_debug_initialize_machine("gtm_design","sfun",0,
    0,0,0,0);
  sf_debug_set_machine_event_thresholds(_gtm_designMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_gtm_designMachineNumber_,0);
}

void gtm_design_register_exported_symbols(SimStruct* S)
{
}
