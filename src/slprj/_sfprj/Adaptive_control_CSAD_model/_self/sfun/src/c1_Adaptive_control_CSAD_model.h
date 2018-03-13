#ifndef __c1_Adaptive_control_CSAD_model_h__
#define __c1_Adaptive_control_CSAD_model_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Adaptive_control_CSAD_modelInstanceStruct
#define typedef_SFc1_Adaptive_control_CSAD_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Adaptive_control_CSAD_model;
  real_T (*c1_Gamma1)[9];
  real_T (*c1_eta_t)[3];
  real_T (*c1_nu)[3];
  real_T (*c1_eta_t_dot)[3];
  real_T (*c1_eta_t_ddot)[3];
  real_T (*c1_alpha)[3];
  real_T (*c1_alpha_dot)[3];
  real_T (*c1_eta)[3];
} SFc1_Adaptive_control_CSAD_modelInstanceStruct;

#endif                                 /*typedef_SFc1_Adaptive_control_CSAD_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_Adaptive_control_CSAD_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Adaptive_control_CSAD_model_get_check_sum(mxArray *plhs[]);
extern void c1_Adaptive_control_CSAD_model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
