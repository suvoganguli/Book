#ifndef __c3_EulerDot_lib_h__
#define __c3_EulerDot_lib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c3_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_EulerDot_lib;
  ChartInfoStruct chartInfo;
} SFc3_EulerDot_libInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c3_EulerDot_lib_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_EulerDot_lib_get_check_sum(mxArray *plhs[]);
extern void c3_EulerDot_lib_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
