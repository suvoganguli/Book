/* Include files */

#include "claw_main_sfun.h"
#include "c2_claw_main.h"
#include "c4_claw_main.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _claw_mainMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void claw_main_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void claw_main_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_claw_main_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_claw_main_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_claw_main_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_claw_main_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(177585873U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1353858836U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1385015254U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1897550210U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1452636361U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1143674261U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3813308682U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3111757366U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_claw_main_get_check_sum(mxArray *plhs[]);
          sf_c2_claw_main_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_claw_main_get_check_sum(mxArray *plhs[]);
          sf_c4_claw_main_get_check_sum(plhs);
          break;
        }

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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1982400416U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2505687900U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2218356702U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4224921692U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_claw_main_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
     case 2:
      {
        extern mxArray *sf_c2_claw_main_get_autoinheritance_info(void);
        plhs[0] = sf_c2_claw_main_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_claw_main_get_autoinheritance_info(void);
        plhs[0] = sf_c4_claw_main_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_claw_main_get_eml_resolved_functions_info( int nlhs, mxArray *
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
     case 2:
      {
        extern const mxArray *sf_c2_claw_main_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_claw_main_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_claw_main_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_claw_main_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void claw_main_debug_initialize(void)
{
  _claw_mainMachineNumber_ = sf_debug_initialize_machine("claw_main","sfun",0,2,
    0,0,0);
  sf_debug_set_machine_event_thresholds(_claw_mainMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_claw_mainMachineNumber_,0);
}

void claw_main_register_exported_symbols(SimStruct* S)
{
}
