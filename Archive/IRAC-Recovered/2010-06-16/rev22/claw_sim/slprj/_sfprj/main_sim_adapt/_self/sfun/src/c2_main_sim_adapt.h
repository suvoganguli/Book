#ifndef __c2_main_sim_adapt_h__
#define __c2_main_sim_adapt_h__

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
} c2_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_main_sim_adapt;
  ChartInfoStruct chartInfo;
} SFc2_main_sim_adaptInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c2_main_sim_adapt_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_main_sim_adapt_get_check_sum(mxArray *plhs[]);
extern void c2_main_sim_adapt_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
