#ifndef __c2_acparams_lib_h__
#define __c2_acparams_lib_h__

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
  real_T c2_aftfuel;
  real_T c2_aftfuel_pos[3];
  real_T c2_cg_pos0[3];
  real_T c2_fwdfuel;
  real_T c2_fwdfuel_pos[3];
  real_T c2_w0;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_acparams_lib;
  ChartInfoStruct chartInfo;
} SFc2_acparams_libInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c2_acparams_lib_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_acparams_lib_get_check_sum(mxArray *plhs[]);
extern void c2_acparams_lib_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
