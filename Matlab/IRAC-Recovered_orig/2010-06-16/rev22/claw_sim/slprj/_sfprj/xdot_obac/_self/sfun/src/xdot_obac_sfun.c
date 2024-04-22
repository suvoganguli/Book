/* Include files */

#include "xdot_obac_sfun.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _xdot_obacMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void xdot_obac_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void xdot_obac_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_xdot_obac_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, int_T method, void *data)
{
  return 0;
}

unsigned int sf_xdot_obac_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3079009919U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2370046689U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(417259550U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(926983076U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1253077057U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1997529253U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2491711715U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(176562871U);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(617980042U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1541476886U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(11559331U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2321883610U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_xdot_obac_autoinheritance_info( int nlhs, mxArray * plhs[], int
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

unsigned int sf_xdot_obac_get_eml_resolved_functions_info( int nlhs, mxArray *
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

void xdot_obac_debug_initialize(void)
{
  _xdot_obacMachineNumber_ = sf_debug_initialize_machine("xdot_obac","sfun",0,0,
    0,0,0);
  sf_debug_set_machine_event_thresholds(_xdot_obacMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_xdot_obacMachineNumber_,0);
}

void xdot_obac_register_exported_symbols(SimStruct* S)
{
}
