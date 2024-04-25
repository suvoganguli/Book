#ifndef __c4_models_h__
#define __c4_models_h__

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
} c4_ResolvedFunctionInfo;

typedef struct {
  real_T c4_aftfuel;
  real_T c4_aftfuel_pos[3];
  real_T c4_cg_pos0[3];
  real_T c4_fwdfuel;
  real_T c4_fwdfuel_pos[3];
  real_T c4_w0;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_models;
  ChartInfoStruct chartInfo;
} SFc4_modelsInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c4_models_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_models_get_check_sum(mxArray *plhs[]);
extern void c4_models_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
