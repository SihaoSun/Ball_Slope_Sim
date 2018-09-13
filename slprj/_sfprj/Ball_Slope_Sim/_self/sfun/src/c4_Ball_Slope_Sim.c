/* Include files */

#include "Ball_Slope_Sim_sfun.h"
#include "c4_Ball_Slope_Sim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Ball_Slope_Sim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[10] = { "K1", "nargin", "nargout",
  "C0", "P0", "x", "y", "l", "C1", "P1" };

/* Function Declarations */
static void initialize_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void initialize_params_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance);
static void enable_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void disable_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance);
static void set_sim_state_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void sf_gateway_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void mdl_start_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void initSimStructsc4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct *chartInstance,
  const mxArray *c4_b_P1, const char_T *c4_identifier, real_T c4_b_y[9]);
static void c4_b_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[9]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_b_C1, const char_T *c4_identifier, real_T
  c4_b_y[3]);
static void c4_d_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[3]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_g_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Ball_Slope_Sim, const char_T *
  c4_identifier);
static uint8_T c4_h_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_Ball_Slope_Sim(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_Ball_Slope_Sim = 0U;
}

static void initialize_params_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_Ball_Slope_Sim
  (SFc4_Ball_Slope_SimInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_createcellmatrix(3, 1), false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", *chartInstance->c4_C1, 0, 0U, 1U, 0U,
    1, 3), false);
  sf_mex_setcell(c4_b_y, 0, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", *chartInstance->c4_P1, 0, 0U, 1U, 0U,
    2, 3, 3), false);
  sf_mex_setcell(c4_b_y, 1, c4_d_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_Ball_Slope_Sim;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_b_y, 2, c4_e_y);
  sf_mex_assign(&c4_st, c4_b_y, false);
  return c4_st;
}

static void set_sim_state_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i0;
  real_T c4_dv1[9];
  int32_T c4_i1;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "C1",
                        c4_dv0);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    (*chartInstance->c4_C1)[c4_i0] = c4_dv0[c4_i0];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "P1",
                      c4_dv1);
  for (c4_i1 = 0; c4_i1 < 9; c4_i1++) {
    (*chartInstance->c4_P1)[c4_i1] = c4_dv1[c4_i1];
  }

  chartInstance->c4_is_active_c4_Ball_Slope_Sim = c4_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_active_c4_Ball_Slope_Sim");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Ball_Slope_Sim(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  real_T c4_b_C0[3];
  int32_T c4_i7;
  real_T c4_b_P0[9];
  real_T c4_b_y;
  real_T c4_b_x[3];
  real_T c4_b_l;
  uint32_T c4_debug_family_var_map[10];
  real_T c4_K1[3];
  real_T c4_nargin = 5.0;
  real_T c4_nargout = 2.0;
  real_T c4_b_C1[3];
  real_T c4_b_P1[9];
  int32_T c4_i8;
  int32_T c4_i9;
  real_T c4_a[9];
  int32_T c4_i10;
  real_T c4_b[3];
  int32_T c4_i11;
  real_T c4_b_a[3];
  int32_T c4_i12;
  real_T c4_b_b[9];
  int32_T c4_i13;
  int32_T c4_i14;
  real_T c4_c_y[3];
  int32_T c4_i15;
  real_T c4_d_y;
  int32_T c4_k;
  real_T c4_B;
  int32_T c4_i16;
  real_T c4_d0;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  real_T c4_e_y;
  int32_T c4_b_k;
  int32_T c4_i21;
  real_T c4_c_b;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i30;
  int32_T c4_i31;
  real_T c4_c_a[9];
  int32_T c4_i32;
  real_T c4_d1;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_l, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_y, 3U);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_x)[c4_i2], 2U);
  }

  for (c4_i3 = 0; c4_i3 < 9; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_P0)[c4_i3], 1U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_C0)[c4_i4], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_b_C0[c4_i5] = (*chartInstance->c4_C0)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 9; c4_i6++) {
    c4_b_P0[c4_i6] = (*chartInstance->c4_P0)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    c4_b_x[c4_i7] = (*chartInstance->c4_x)[c4_i7];
  }

  c4_b_y = *chartInstance->c4_y;
  c4_b_l = *chartInstance->c4_l;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_K1, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_C0, 3U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_P0, 4U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_x, 5U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_y, 6U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_l, 7U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_C1, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_P1, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i8 = 0; c4_i8 < 9; c4_i8++) {
    c4_a[c4_i8] = c4_b_P0[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_b[c4_i9] = c4_b_x[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_b_a[c4_i10] = c4_b_x[c4_i10];
  }

  for (c4_i11 = 0; c4_i11 < 9; c4_i11++) {
    c4_b_b[c4_i11] = c4_b_P0[c4_i11];
  }

  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_c_y[c4_i13] = 0.0;
    for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
      c4_c_y[c4_i13] += c4_b_a[c4_i15] * c4_b_b[c4_i15 + c4_i12];
    }

    c4_i12 += 3;
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_b_a[c4_i14] = c4_b_x[c4_i14];
  }

  c4_d_y = 0.0;
  for (c4_k = 0; c4_k < 3; c4_k++) {
    c4_d_y += c4_c_y[c4_k] * c4_b_a[c4_k];
  }

  c4_B = c4_d_y + c4_b_l;
  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_d0 = 0.0;
    c4_i18 = 0;
    for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
      c4_d0 += c4_a[c4_i18 + c4_i16] * c4_b[c4_i19];
      c4_i18 += 3;
    }

    c4_K1[c4_i16] = c4_d0 / c4_B;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
    c4_b_a[c4_i17] = c4_b_x[c4_i17];
  }

  for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
    c4_b[c4_i20] = c4_b_C0[c4_i20];
  }

  c4_e_y = 0.0;
  for (c4_b_k = 0; c4_b_k < 3; c4_b_k++) {
    c4_e_y += c4_b_a[c4_b_k] * c4_b[c4_b_k];
  }

  for (c4_i21 = 0; c4_i21 < 3; c4_i21++) {
    c4_b_a[c4_i21] = c4_K1[c4_i21];
  }

  c4_c_b = c4_b_y - c4_e_y;
  for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
    c4_b_C1[c4_i22] = c4_b_C0[c4_i22] + c4_b_a[c4_i22] * c4_c_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i23 = 0; c4_i23 < 3; c4_i23++) {
    c4_b_a[c4_i23] = c4_K1[c4_i23];
  }

  for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
    c4_b[c4_i24] = c4_b_x[c4_i24];
  }

  for (c4_i25 = 0; c4_i25 < 9; c4_i25++) {
    c4_b_b[c4_i25] = c4_b_P0[c4_i25];
  }

  for (c4_i26 = 0; c4_i26 < 3; c4_i26++) {
    c4_i28 = 0;
    for (c4_i29 = 0; c4_i29 < 3; c4_i29++) {
      c4_c_a[c4_i28 + c4_i26] = c4_b_a[c4_i26] * c4_b[c4_i29];
      c4_i28 += 3;
    }
  }

  for (c4_i27 = 0; c4_i27 < 3; c4_i27++) {
    c4_i30 = 0;
    for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
      c4_d1 = 0.0;
      c4_i34 = 0;
      for (c4_i35 = 0; c4_i35 < 3; c4_i35++) {
        c4_d1 += c4_c_a[c4_i34 + c4_i27] * c4_b_b[c4_i35 + c4_i30];
        c4_i34 += 3;
      }

      c4_b_P1[c4_i30 + c4_i27] = c4_b_P0[c4_i30 + c4_i27] - c4_d1;
      c4_i30 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i32 = 0; c4_i32 < 3; c4_i32++) {
    (*chartInstance->c4_C1)[c4_i32] = c4_b_C1[c4_i32];
  }

  for (c4_i33 = 0; c4_i33 < 9; c4_i33++) {
    (*chartInstance->c4_P1)[c4_i33] = c4_b_P1[c4_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Ball_Slope_SimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_C1)[c4_i36], 5U);
  }

  for (c4_i37 = 0; c4_i37 < 9; c4_i37++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_P1)[c4_i37], 6U);
  }
}

static void mdl_start_c4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc4_Ball_Slope_Sim(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i38;
  int32_T c4_i39;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i40;
  real_T c4_u[9];
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_i38 = 0;
  for (c4_i39 = 0; c4_i39 < 3; c4_i39++) {
    for (c4_i40 = 0; c4_i40 < 3; c4_i40++) {
      c4_u[c4_i40 + c4_i38] = (*(real_T (*)[9])c4_inData)[c4_i40 + c4_i38];
    }

    c4_i38 += 3;
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct *chartInstance,
  const mxArray *c4_b_P1, const char_T *c4_identifier, real_T c4_b_y[9])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P1), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_b_P1);
}

static void c4_b_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[9])
{
  real_T c4_dv2[9];
  int32_T c4_i41;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i41 = 0; c4_i41 < 9; c4_i41++) {
    c4_b_y[c4_i41] = c4_dv2[c4_i41];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P1;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[9];
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_b_P1 = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P1), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_b_P1);
  c4_i42 = 0;
  for (c4_i43 = 0; c4_i43 < 3; c4_i43++) {
    for (c4_i44 = 0; c4_i44 < 3; c4_i44++) {
      (*(real_T (*)[9])c4_outData)[c4_i44 + c4_i42] = c4_b_y[c4_i44 + c4_i42];
    }

    c4_i42 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i45;
  const mxArray *c4_b_y = NULL;
  real_T c4_u[3];
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i45 = 0; c4_i45 < 3; c4_i45++) {
    c4_u[c4_i45] = (*(real_T (*)[3])c4_inData)[c4_i45];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_b_C1, const char_T *c4_identifier, real_T
  c4_b_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_C1), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_b_C1);
}

static void c4_d_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_b_y[3])
{
  real_T c4_dv3[3];
  int32_T c4_i46;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i46 = 0; c4_i46 < 3; c4_i46++) {
    c4_b_y[c4_i46] = c4_dv3[c4_i46];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_C1;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[3];
  int32_T c4_i47;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_b_C1 = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_C1), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_b_C1);
  for (c4_i47 = 0; c4_i47 < 3; c4_i47++) {
    (*(real_T (*)[3])c4_outData)[c4_i47] = c4_b_y[c4_i47];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i48;
  const mxArray *c4_b_y = NULL;
  real_T c4_u[3];
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i48 = 0; c4_i48 < 3; c4_i48++) {
    c4_u[c4_i48] = (*(real_T (*)[3])c4_inData)[c4_i48];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_b_y;
  real_T c4_d2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_b_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout),
    &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Ball_Slope_Sim_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_b_y = NULL;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_b_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_b_y;
  int32_T c4_i49;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i49, 1, 6, 0U, 0, 0U, 0);
  c4_b_y = c4_i49;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_b_y;
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_b_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Ball_Slope_Sim, const char_T *
  c4_identifier)
{
  uint8_T c4_b_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Ball_Slope_Sim), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Ball_Slope_Sim);
  return c4_b_y;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_b_y;
}

static void init_dsm_address_info(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_Ball_Slope_SimInstanceStruct
  *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_C0 = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_P0 = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_C1 = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_P1 = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_x = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c4_l = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_Ball_Slope_Sim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4128149099U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4109660671U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3175924401U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1409357961U);
}

mxArray* sf_c4_Ball_Slope_Sim_get_post_codegen_info(void);
mxArray *sf_c4_Ball_Slope_Sim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("B8KNnM8ua3VqSvXVJd6ULH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_Ball_Slope_Sim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_Ball_Slope_Sim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_Ball_Slope_Sim_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_Ball_Slope_Sim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_Ball_Slope_Sim_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_Ball_Slope_Sim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"C1\",},{M[1],M[10],T\"P1\",},{M[8],M[0],T\"is_active_c4_Ball_Slope_Sim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Ball_Slope_Sim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Ball_Slope_SimInstanceStruct *chartInstance =
      (SFc4_Ball_Slope_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Ball_Slope_SimMachineNumber_,
           4,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Ball_Slope_SimMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Ball_Slope_SimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Ball_Slope_SimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"C0");
          _SFD_SET_DATA_PROPS(1,1,1,0,"P0");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x");
          _SFD_SET_DATA_PROPS(3,1,1,0,"y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"l");
          _SFD_SET_DATA_PROPS(5,2,0,1,"C1");
          _SFD_SET_DATA_PROPS(6,2,0,1,"P1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,263);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Ball_Slope_SimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Ball_Slope_SimInstanceStruct *chartInstance =
      (SFc4_Ball_Slope_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_C0);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_P0);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c4_C1);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c4_P1);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_x);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_y);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c4_l);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "siUH88aDWbtwDTAkk1mnI2F";
}

static void sf_opaque_initialize_c4_Ball_Slope_Sim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_Ball_Slope_Sim(void *chartInstanceVar)
{
  enable_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Ball_Slope_Sim(void *chartInstanceVar)
{
  disable_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_Ball_Slope_Sim(void *chartInstanceVar)
{
  sf_gateway_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_Ball_Slope_Sim(SimStruct* S)
{
  return get_sim_state_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_Ball_Slope_Sim(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_Ball_Slope_Sim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Ball_Slope_SimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Ball_Slope_Sim_optimization_info();
    }

    finalize_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Ball_Slope_Sim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Ball_Slope_Sim((SFc4_Ball_Slope_SimInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_Ball_Slope_Sim(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Ball_Slope_Sim_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2067380093U));
  ssSetChecksum1(S,(2495106054U));
  ssSetChecksum2(S,(3634462323U));
  ssSetChecksum3(S,(2631043198U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Ball_Slope_Sim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Ball_Slope_Sim(SimStruct *S)
{
  SFc4_Ball_Slope_SimInstanceStruct *chartInstance;
  chartInstance = (SFc4_Ball_Slope_SimInstanceStruct *)utMalloc(sizeof
    (SFc4_Ball_Slope_SimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_Ball_Slope_SimInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Ball_Slope_Sim;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_Ball_Slope_Sim(chartInstance);
}

void c4_Ball_Slope_Sim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Ball_Slope_Sim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Ball_Slope_Sim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Ball_Slope_Sim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Ball_Slope_Sim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
