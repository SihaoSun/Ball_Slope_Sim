#ifndef __c4_Ball_Slope_Sim_h__
#define __c4_Ball_Slope_Sim_h__

/* Type Definitions */
#ifndef typedef_SFc4_Ball_Slope_SimInstanceStruct
#define typedef_SFc4_Ball_Slope_SimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Ball_Slope_Sim;
  void *c4_fEmlrtCtx;
  real_T (*c4_C0)[3];
  real_T (*c4_P0)[9];
  real_T (*c4_C1)[3];
  real_T (*c4_P1)[9];
  real_T (*c4_x)[3];
  real_T *c4_y;
  real_T *c4_l;
} SFc4_Ball_Slope_SimInstanceStruct;

#endif                                 /*typedef_SFc4_Ball_Slope_SimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Ball_Slope_Sim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_Ball_Slope_Sim_get_check_sum(mxArray *plhs[]);
extern void c4_Ball_Slope_Sim_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
