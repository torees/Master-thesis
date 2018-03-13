/* Include files */

#include "Adaptive_control_CSAD_model_sfun.h"
#include "c1_Adaptive_control_CSAD_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Adaptive_control_CSAD_model_sfun_debug_macros.h"
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
static const char * c1_debug_family_names[25] = { "psi", "r", "R_T", "S_T",
  "z_1", "z1_p_tilde", "z1_psi_tilde", "delta_p_tilde", "delta_psi_tilde",
  "K1_func", "z_2", "z_1_dot", "z1_p_tilde_dot", "z1_psi_tilde_dot",
  "K1_func_dot", "nargin", "nargout", "Gamma1", "eta_t", "nu", "eta_t_dot",
  "eta_t_ddot", "eta", "alpha", "alpha_dot" };

/* Function Declarations */
static void initialize_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void initialize_params_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void enable_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void disable_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void set_sim_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_st);
static void finalize_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void sf_gateway_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void mdl_start_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void initSimStructsc1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_b_alpha_dot, const char_T *c1_identifier,
  real_T c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_d_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static real_T c1_mpower(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, real_T c1_a);
static void c1_error(SFc1_Adaptive_control_CSAD_modelInstanceStruct
                     *chartInstance);
static void c1_b_error(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance);
static real_T c1_b_mpower(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, real_T c1_a);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_b_is_active_c1_Adaptive_control_CSAD_model, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance);
static void init_simulink_io_address
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_Adaptive_control_CSAD_model(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_Adaptive_control_CSAD_model = 0U;
}

static void initialize_params_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(3, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_alpha, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_alpha_dot, 0, 0U,
    1U, 0U, 1, 3), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Adaptive_control_CSAD_model;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i0;
  real_T c1_dv1[3];
  int32_T c1_i1;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("alpha", c1_u, 0)),
                      "alpha", c1_dv0);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    (*chartInstance->c1_alpha)[c1_i0] = c1_dv0[c1_i0];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("alpha_dot", c1_u,
    1)), "alpha_dot", c1_dv1);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    (*chartInstance->c1_alpha_dot)[c1_i1] = c1_dv1[c1_i1];
  }

  chartInstance->c1_is_active_c1_Adaptive_control_CSAD_model =
    c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c1_Adaptive_control_CSAD_model", c1_u, 2)),
    "is_active_c1_Adaptive_control_CSAD_model");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Adaptive_control_CSAD_model(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_b_Gamma1[9];
  int32_T c1_i10;
  real_T c1_b_eta_t[3];
  int32_T c1_i11;
  real_T c1_b_nu[3];
  int32_T c1_i12;
  real_T c1_b_eta_t_dot[3];
  int32_T c1_i13;
  real_T c1_b_eta_t_ddot[3];
  uint32_T c1_debug_family_var_map[25];
  real_T c1_b_eta[3];
  real_T c1_psi;
  real_T c1_r;
  real_T c1_R_T[9];
  real_T c1_S_T[9];
  real_T c1_z_1[3];
  real_T c1_z1_p_tilde[2];
  real_T c1_z1_psi_tilde;
  real_T c1_delta_p_tilde;
  real_T c1_delta_psi_tilde;
  real_T c1_K1_func[9];
  real_T c1_z_2[3];
  real_T c1_z_1_dot[3];
  real_T c1_z1_p_tilde_dot[2];
  real_T c1_z1_psi_tilde_dot;
  real_T c1_K1_func_dot[9];
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 2.0;
  real_T c1_b_alpha[3];
  real_T c1_b_alpha_dot[3];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i14;
  static real_T c1_dv2[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  real_T c1_a[9];
  int32_T c1_i18;
  real_T c1_b[3];
  int32_T c1_i19;
  real_T c1_b_z_1[2];
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_b_a[2];
  real_T c1_y;
  real_T c1_b_b[2];
  int32_T c1_k;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  boolean_T c1_p;
  boolean_T c1_b_p;
  real_T c1_B;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_i25;
  int32_T c1_i26;
  real_T c1_e_y;
  int32_T c1_b_k;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  boolean_T c1_c_p;
  boolean_T c1_d_p;
  real_T c1_b_B;
  real_T c1_f_y;
  real_T c1_g_y;
  real_T c1_h_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  boolean_T c1_e_p;
  boolean_T c1_f_p;
  real_T c1_c_B;
  real_T c1_i_y;
  real_T c1_j_y;
  real_T c1_k_y;
  int32_T c1_i27;
  real_T c1_c_b[9];
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_l_y[3];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  real_T c1_m_y[3];
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_z_1_dot[2];
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  real_T c1_n_y;
  int32_T c1_c_k;
  int32_T c1_i60;
  int32_T c1_i61;
  real_T c1_o_y;
  int32_T c1_d_k;
  real_T c1_A;
  real_T c1_d_B;
  real_T c1_r_x;
  real_T c1_p_y;
  real_T c1_s_x;
  real_T c1_q_y;
  real_T c1_r_y;
  int32_T c1_i62;
  int32_T c1_i63;
  real_T c1_s_y;
  int32_T c1_e_k;
  int32_T c1_i64;
  int32_T c1_i65;
  real_T c1_t_y;
  int32_T c1_f_k;
  real_T c1_b_A;
  real_T c1_e_B;
  real_T c1_t_x;
  real_T c1_u_y;
  real_T c1_u_x;
  real_T c1_v_y;
  real_T c1_w_y;
  real_T c1_c_A;
  real_T c1_f_B;
  real_T c1_v_x;
  real_T c1_x_y;
  real_T c1_w_x;
  real_T c1_y_y;
  real_T c1_ab_y;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  real_T c1_bb_y[9];
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  real_T c1_cb_y[3];
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  real_T c1_db_y[3];
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_eta)[c1_i2], 5U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_eta_t_ddot)[c1_i3], 4U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_eta_t_dot)[c1_i4], 3U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_nu)[c1_i5], 2U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_eta_t)[c1_i6], 1U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_Gamma1)[c1_i7], 0U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i8 = 0; c1_i8 < 9; c1_i8++) {
    c1_b_Gamma1[c1_i8] = (*chartInstance->c1_Gamma1)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_b_eta_t[c1_i9] = (*chartInstance->c1_eta_t)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_b_nu[c1_i10] = (*chartInstance->c1_nu)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_b_eta_t_dot[c1_i11] = (*chartInstance->c1_eta_t_dot)[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_b_eta_t_ddot[c1_i12] = (*chartInstance->c1_eta_t_ddot)[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    c1_b_eta[c1_i13] = (*chartInstance->c1_eta)[c1_i13];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 25U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_psi, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_R_T, 2U, c1_b_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_S_T, 3U, c1_b_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_z_1, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_z1_p_tilde, 5U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_z1_psi_tilde, 6U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_delta_p_tilde, 7U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_delta_psi_tilde, 8U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_K1_func, 9U, c1_b_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_z_2, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_z_1_dot, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_z1_p_tilde_dot, 12U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_z1_psi_tilde_dot, 13U,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_K1_func_dot, 14U, c1_b_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 15U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 16U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_Gamma1, 17U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_eta_t, 18U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_nu, 19U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_eta_t_dot, 20U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_eta_t_ddot, 21U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_eta, 22U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_alpha, 23U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_alpha_dot, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_psi = c1_b_eta[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_r = c1_b_nu[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_x = c1_psi;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_psi;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_psi;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_psi;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_R_T[0] = c1_b_x;
  c1_R_T[1] = -c1_d_x;
  c1_R_T[2] = 0.0;
  c1_R_T[3] = c1_f_x;
  c1_R_T[4] = c1_h_x;
  c1_R_T[5] = 0.0;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_R_T[c1_i14 + 6] = c1_dv2[c1_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_S_T[0] = 0.0;
  c1_S_T[1] = -c1_r;
  c1_S_T[2] = 0.0;
  c1_S_T[3] = c1_r;
  c1_S_T[4] = 0.0;
  c1_S_T[5] = 0.0;
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_S_T[c1_i15 + 6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  for (c1_i16 = 0; c1_i16 < 9; c1_i16++) {
    c1_a[c1_i16] = c1_R_T[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    c1_b[c1_i17] = c1_b_eta[c1_i17] - c1_b_eta_t[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    c1_z_1[c1_i18] = 0.0;
  }

  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    c1_z_1[c1_i19] = 0.0;
    c1_i20 = 0;
    for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
      c1_z_1[c1_i19] += c1_a[c1_i20 + c1_i19] * c1_b[c1_i21];
      c1_i20 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_b_z_1[0] = c1_z_1[0];
  c1_b_z_1[1] = c1_z_1[1];
  for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
    c1_z1_p_tilde[c1_i22] = c1_b_z_1[c1_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_z1_psi_tilde = c1_z_1[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_delta_p_tilde = 0.4;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_delta_psi_tilde = 0.4;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
    c1_b_a[c1_i23] = c1_z1_p_tilde[c1_i23];
  }

  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_b_b[c1_i24] = c1_z1_p_tilde[c1_i24];
  }

  c1_y = 0.0;
  for (c1_k = 0; c1_k + 1 < 3; c1_k++) {
    c1_y += c1_b_a[c1_k] * c1_b_b[c1_k];
  }

  c1_i_x = c1_y + c1_mpower(chartInstance, 0.4);
  c1_j_x = c1_i_x;
  c1_k_x = c1_j_x;
  c1_p = (c1_k_x < 0.0);
  c1_b_p = c1_p;
  if (c1_b_p) {
    c1_b_error(chartInstance);
  }

  c1_j_x = muDoubleScalarSqrt(c1_j_x);
  c1_B = c1_j_x;
  c1_b_y = c1_B;
  c1_c_y = c1_b_y;
  c1_d_y = 1.0 / c1_c_y;
  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    c1_b_a[c1_i25] = c1_z1_p_tilde[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_b_b[c1_i26] = c1_z1_p_tilde[c1_i26];
  }

  c1_e_y = 0.0;
  for (c1_b_k = 0; c1_b_k + 1 < 3; c1_b_k++) {
    c1_e_y += c1_b_a[c1_b_k] * c1_b_b[c1_b_k];
  }

  c1_l_x = c1_e_y + c1_mpower(chartInstance, 0.4);
  c1_m_x = c1_l_x;
  c1_n_x = c1_m_x;
  c1_c_p = (c1_n_x < 0.0);
  c1_d_p = c1_c_p;
  if (c1_d_p) {
    c1_b_error(chartInstance);
  }

  c1_m_x = muDoubleScalarSqrt(c1_m_x);
  c1_b_B = c1_m_x;
  c1_f_y = c1_b_B;
  c1_g_y = c1_f_y;
  c1_h_y = 1.0 / c1_g_y;
  c1_o_x = c1_mpower(chartInstance, c1_z1_psi_tilde) + c1_mpower(chartInstance,
    0.4);
  c1_p_x = c1_o_x;
  c1_q_x = c1_p_x;
  c1_e_p = (c1_q_x < 0.0);
  c1_f_p = c1_e_p;
  if (c1_f_p) {
    c1_b_error(chartInstance);
  }

  c1_p_x = muDoubleScalarSqrt(c1_p_x);
  c1_c_B = c1_p_x;
  c1_i_y = c1_c_B;
  c1_j_y = c1_i_y;
  c1_k_y = 1.0 / c1_j_y;
  for (c1_i27 = 0; c1_i27 < 9; c1_i27++) {
    c1_a[c1_i27] = c1_b_Gamma1[c1_i27];
  }

  c1_c_b[0] = c1_d_y;
  c1_c_b[3] = 0.0;
  c1_c_b[6] = 0.0;
  c1_c_b[1] = 0.0;
  c1_c_b[4] = c1_h_y;
  c1_c_b[7] = 0.0;
  c1_c_b[2] = 0.0;
  c1_c_b[5] = 0.0;
  c1_c_b[8] = c1_k_y;
  for (c1_i28 = 0; c1_i28 < 9; c1_i28++) {
    c1_K1_func[c1_i28] = 0.0;
  }

  for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
    c1_i30 = 0;
    for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
      c1_K1_func[c1_i30 + c1_i29] = 0.0;
      c1_i34 = 0;
      for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
        c1_K1_func[c1_i30 + c1_i29] += c1_a[c1_i34 + c1_i29] * c1_c_b[c1_i35 +
          c1_i30];
        c1_i34 += 3;
      }

      c1_i30 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  for (c1_i31 = 0; c1_i31 < 9; c1_i31++) {
    c1_a[c1_i31] = c1_R_T[c1_i31];
  }

  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    c1_b[c1_i33] = c1_b_eta_t_dot[c1_i33];
  }

  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_l_y[c1_i36] = 0.0;
    c1_i38 = 0;
    for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
      c1_l_y[c1_i36] += c1_a[c1_i38 + c1_i36] * c1_b[c1_i39];
      c1_i38 += 3;
    }
  }

  for (c1_i37 = 0; c1_i37 < 9; c1_i37++) {
    c1_a[c1_i37] = c1_K1_func[c1_i37];
  }

  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    c1_b[c1_i40] = c1_z_1[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_m_y[c1_i41] = 0.0;
    c1_i43 = 0;
    for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
      c1_m_y[c1_i41] += c1_a[c1_i43 + c1_i41] * c1_b[c1_i44];
      c1_i43 += 3;
    }
  }

  for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
    c1_b_alpha[c1_i42] = c1_l_y[c1_i42] - c1_m_y[c1_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  for (c1_i45 = 0; c1_i45 < 3; c1_i45++) {
    c1_z_2[c1_i45] = c1_b_nu[c1_i45] - c1_b_alpha[c1_i45];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  for (c1_i46 = 0; c1_i46 < 9; c1_i46++) {
    c1_a[c1_i46] = c1_S_T[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    c1_b[c1_i47] = c1_z_1[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 3; c1_i48++) {
    c1_l_y[c1_i48] = 0.0;
    c1_i50 = 0;
    for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
      c1_l_y[c1_i48] += c1_a[c1_i50 + c1_i48] * c1_b[c1_i51];
      c1_i50 += 3;
    }
  }

  for (c1_i49 = 0; c1_i49 < 9; c1_i49++) {
    c1_a[c1_i49] = c1_b_Gamma1[c1_i49];
  }

  for (c1_i52 = 0; c1_i52 < 3; c1_i52++) {
    c1_b[c1_i52] = c1_z_1[c1_i52];
  }

  for (c1_i53 = 0; c1_i53 < 3; c1_i53++) {
    c1_m_y[c1_i53] = 0.0;
    c1_i55 = 0;
    for (c1_i56 = 0; c1_i56 < 3; c1_i56++) {
      c1_m_y[c1_i53] += c1_a[c1_i55 + c1_i53] * c1_b[c1_i56];
      c1_i55 += 3;
    }
  }

  for (c1_i54 = 0; c1_i54 < 3; c1_i54++) {
    c1_z_1_dot[c1_i54] = (c1_l_y[c1_i54] - c1_m_y[c1_i54]) + c1_z_2[c1_i54];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_b_z_1_dot[0] = c1_z_1_dot[0];
  c1_b_z_1_dot[1] = c1_z_1_dot[1];
  for (c1_i57 = 0; c1_i57 < 2; c1_i57++) {
    c1_z1_p_tilde_dot[c1_i57] = c1_b_z_1_dot[c1_i57];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_z1_psi_tilde_dot = c1_z_1_dot[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  for (c1_i58 = 0; c1_i58 < 2; c1_i58++) {
    c1_b_a[c1_i58] = c1_z1_p_tilde[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 2; c1_i59++) {
    c1_b_b[c1_i59] = c1_z1_p_tilde_dot[c1_i59];
  }

  c1_n_y = 0.0;
  for (c1_c_k = 0; c1_c_k + 1 < 3; c1_c_k++) {
    c1_n_y += c1_b_a[c1_c_k] * c1_b_b[c1_c_k];
  }

  for (c1_i60 = 0; c1_i60 < 2; c1_i60++) {
    c1_b_a[c1_i60] = c1_z1_p_tilde[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 2; c1_i61++) {
    c1_b_b[c1_i61] = c1_z1_p_tilde[c1_i61];
  }

  c1_o_y = 0.0;
  for (c1_d_k = 0; c1_d_k + 1 < 3; c1_d_k++) {
    c1_o_y += c1_b_a[c1_d_k] * c1_b_b[c1_d_k];
  }

  c1_A = c1_n_y;
  c1_d_B = c1_b_mpower(chartInstance, c1_o_y + c1_mpower(chartInstance, 0.4));
  c1_r_x = c1_A;
  c1_p_y = c1_d_B;
  c1_s_x = c1_r_x;
  c1_q_y = c1_p_y;
  c1_r_y = c1_s_x / c1_q_y;
  for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
    c1_b_a[c1_i62] = c1_z1_p_tilde[c1_i62];
  }

  for (c1_i63 = 0; c1_i63 < 2; c1_i63++) {
    c1_b_b[c1_i63] = c1_z1_p_tilde_dot[c1_i63];
  }

  c1_s_y = 0.0;
  for (c1_e_k = 0; c1_e_k + 1 < 3; c1_e_k++) {
    c1_s_y += c1_b_a[c1_e_k] * c1_b_b[c1_e_k];
  }

  for (c1_i64 = 0; c1_i64 < 2; c1_i64++) {
    c1_b_a[c1_i64] = c1_z1_p_tilde[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 2; c1_i65++) {
    c1_b_b[c1_i65] = c1_z1_p_tilde[c1_i65];
  }

  c1_t_y = 0.0;
  for (c1_f_k = 0; c1_f_k + 1 < 3; c1_f_k++) {
    c1_t_y += c1_b_a[c1_f_k] * c1_b_b[c1_f_k];
  }

  c1_b_A = c1_s_y;
  c1_e_B = c1_b_mpower(chartInstance, c1_t_y + c1_mpower(chartInstance, 0.4));
  c1_t_x = c1_b_A;
  c1_u_y = c1_e_B;
  c1_u_x = c1_t_x;
  c1_v_y = c1_u_y;
  c1_w_y = c1_u_x / c1_v_y;
  c1_c_A = c1_z1_psi_tilde * c1_z1_psi_tilde_dot;
  c1_f_B = c1_b_mpower(chartInstance, c1_mpower(chartInstance, c1_z1_psi_tilde)
                       + c1_mpower(chartInstance, 0.4));
  c1_v_x = c1_c_A;
  c1_x_y = c1_f_B;
  c1_w_x = c1_v_x;
  c1_y_y = c1_x_y;
  c1_ab_y = c1_w_x / c1_y_y;
  for (c1_i66 = 0; c1_i66 < 9; c1_i66++) {
    c1_a[c1_i66] = -c1_b_Gamma1[c1_i66];
  }

  c1_c_b[0] = c1_r_y;
  c1_c_b[3] = 0.0;
  c1_c_b[6] = 0.0;
  c1_c_b[1] = 0.0;
  c1_c_b[4] = c1_w_y;
  c1_c_b[7] = 0.0;
  c1_c_b[2] = 0.0;
  c1_c_b[5] = 0.0;
  c1_c_b[8] = c1_ab_y;
  for (c1_i67 = 0; c1_i67 < 9; c1_i67++) {
    c1_K1_func_dot[c1_i67] = 0.0;
  }

  for (c1_i68 = 0; c1_i68 < 3; c1_i68++) {
    c1_i69 = 0;
    for (c1_i71 = 0; c1_i71 < 3; c1_i71++) {
      c1_K1_func_dot[c1_i69 + c1_i68] = 0.0;
      c1_i73 = 0;
      for (c1_i74 = 0; c1_i74 < 3; c1_i74++) {
        c1_K1_func_dot[c1_i69 + c1_i68] += c1_a[c1_i73 + c1_i68] * c1_c_b[c1_i74
          + c1_i69];
        c1_i73 += 3;
      }

      c1_i69 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  for (c1_i70 = 0; c1_i70 < 9; c1_i70++) {
    c1_a[c1_i70] = c1_R_T[c1_i70];
  }

  for (c1_i72 = 0; c1_i72 < 3; c1_i72++) {
    c1_b[c1_i72] = c1_b_eta_t_ddot[c1_i72];
  }

  for (c1_i75 = 0; c1_i75 < 3; c1_i75++) {
    c1_l_y[c1_i75] = 0.0;
    c1_i77 = 0;
    for (c1_i78 = 0; c1_i78 < 3; c1_i78++) {
      c1_l_y[c1_i75] += c1_a[c1_i77 + c1_i75] * c1_b[c1_i78];
      c1_i77 += 3;
    }
  }

  for (c1_i76 = 0; c1_i76 < 9; c1_i76++) {
    c1_a[c1_i76] = c1_S_T[c1_i76];
  }

  for (c1_i79 = 0; c1_i79 < 9; c1_i79++) {
    c1_c_b[c1_i79] = c1_R_T[c1_i79];
  }

  for (c1_i80 = 0; c1_i80 < 3; c1_i80++) {
    c1_i82 = 0;
    for (c1_i83 = 0; c1_i83 < 3; c1_i83++) {
      c1_bb_y[c1_i82 + c1_i80] = 0.0;
      c1_i85 = 0;
      for (c1_i87 = 0; c1_i87 < 3; c1_i87++) {
        c1_bb_y[c1_i82 + c1_i80] += c1_a[c1_i85 + c1_i80] * c1_c_b[c1_i87 +
          c1_i82];
        c1_i85 += 3;
      }

      c1_i82 += 3;
    }
  }

  for (c1_i81 = 0; c1_i81 < 3; c1_i81++) {
    c1_b[c1_i81] = c1_b_eta_t_dot[c1_i81];
  }

  for (c1_i84 = 0; c1_i84 < 3; c1_i84++) {
    c1_m_y[c1_i84] = 0.0;
    c1_i88 = 0;
    for (c1_i89 = 0; c1_i89 < 3; c1_i89++) {
      c1_m_y[c1_i84] += c1_bb_y[c1_i88 + c1_i84] * c1_b[c1_i89];
      c1_i88 += 3;
    }
  }

  for (c1_i86 = 0; c1_i86 < 9; c1_i86++) {
    c1_a[c1_i86] = c1_K1_func_dot[c1_i86];
  }

  for (c1_i90 = 0; c1_i90 < 3; c1_i90++) {
    c1_b[c1_i90] = c1_z_1[c1_i90];
  }

  for (c1_i91 = 0; c1_i91 < 3; c1_i91++) {
    c1_cb_y[c1_i91] = 0.0;
    c1_i93 = 0;
    for (c1_i94 = 0; c1_i94 < 3; c1_i94++) {
      c1_cb_y[c1_i91] += c1_a[c1_i93 + c1_i91] * c1_b[c1_i94];
      c1_i93 += 3;
    }
  }

  for (c1_i92 = 0; c1_i92 < 9; c1_i92++) {
    c1_a[c1_i92] = c1_K1_func[c1_i92];
  }

  for (c1_i95 = 0; c1_i95 < 3; c1_i95++) {
    c1_b[c1_i95] = c1_z_1_dot[c1_i95];
  }

  for (c1_i96 = 0; c1_i96 < 3; c1_i96++) {
    c1_db_y[c1_i96] = 0.0;
    c1_i98 = 0;
    for (c1_i99 = 0; c1_i99 < 3; c1_i99++) {
      c1_db_y[c1_i96] += c1_a[c1_i98 + c1_i96] * c1_b[c1_i99];
      c1_i98 += 3;
    }
  }

  for (c1_i97 = 0; c1_i97 < 3; c1_i97++) {
    c1_b_alpha_dot[c1_i97] = ((c1_l_y[c1_i97] + c1_m_y[c1_i97]) - c1_cb_y[c1_i97])
      - c1_db_y[c1_i97];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -33);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i100 = 0; c1_i100 < 3; c1_i100++) {
    (*chartInstance->c1_alpha)[c1_i100] = c1_b_alpha[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 3; c1_i101++) {
    (*chartInstance->c1_alpha_dot)[c1_i101] = c1_b_alpha_dot[c1_i101];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Adaptive_control_CSAD_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i102 = 0; c1_i102 < 3; c1_i102++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_alpha)[c1_i102], 6U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i103 = 0; c1_i103 < 3; c1_i103++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_alpha_dot)[c1_i103], 7U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }
}

static void mdl_start_c1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc1_Adaptive_control_CSAD_model
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i104;
  const mxArray *c1_y = NULL;
  real_T c1_u[3];
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i104 = 0; c1_i104 < 3; c1_i104++) {
    c1_u[c1_i104] = (*(real_T (*)[3])c1_inData)[c1_i104];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_b_alpha_dot, const char_T *c1_identifier,
  real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_alpha_dot), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_alpha_dot);
}

static void c1_b_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv3[3];
  int32_T c1_i105;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i105 = 0; c1_i105 < 3; c1_i105++) {
    c1_y[c1_i105] = c1_dv3[c1_i105];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_alpha_dot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i106;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_b_alpha_dot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_alpha_dot), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_alpha_dot);
  for (c1_i106 = 0; c1_i106 < 3; c1_i106++) {
    (*(real_T (*)[3])c1_outData)[c1_i106] = c1_y[c1_i106];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i107;
  int32_T c1_i108;
  const mxArray *c1_y = NULL;
  int32_T c1_i109;
  real_T c1_u[9];
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i107 = 0;
  for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
    for (c1_i109 = 0; c1_i109 < 3; c1_i109++) {
      c1_u[c1_i109 + c1_i107] = (*(real_T (*)[9])c1_inData)[c1_i109 + c1_i107];
    }

    c1_i107 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_d_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9])
{
  real_T c1_dv4[9];
  int32_T c1_i110;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i110 = 0; c1_i110 < 9; c1_i110++) {
    c1_y[c1_i110] = c1_dv4[c1_i110];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_K1_func_dot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_K1_func_dot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_K1_func_dot), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_K1_func_dot);
  c1_i111 = 0;
  for (c1_i112 = 0; c1_i112 < 3; c1_i112++) {
    for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
      (*(real_T (*)[9])c1_outData)[c1_i113 + c1_i111] = c1_y[c1_i113 + c1_i111];
    }

    c1_i111 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i114;
  const mxArray *c1_y = NULL;
  real_T c1_u[2];
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i114 = 0; c1_i114 < 2; c1_i114++) {
    c1_u[c1_i114] = (*(real_T (*)[2])c1_inData)[c1_i114];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv5[2];
  int32_T c1_i115;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i115 = 0; c1_i115 < 2; c1_i115++) {
    c1_y[c1_i115] = c1_dv5[c1_i115];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_z1_p_tilde_dot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i116;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_z1_p_tilde_dot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_z1_p_tilde_dot), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_z1_p_tilde_dot);
  for (c1_i116 = 0; c1_i116 < 2; c1_i116++) {
    (*(real_T (*)[2])c1_outData)[c1_i116] = c1_y[c1_i116];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Adaptive_control_CSAD_model_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_mpower(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_c;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_x;
  real_T c1_d_a;
  boolean_T c1_p;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_x = c1_c_a;
  c1_d_a = c1_x;
  c1_c = c1_d_a * c1_d_a;
  c1_p = false;
  if (c1_p) {
    c1_error(chartInstance);
  }

  return c1_c;
}

static void c1_error(SFc1_Adaptive_control_CSAD_modelInstanceStruct
                     *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static void c1_b_error(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_cv2[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static real_T c1_b_mpower(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_c;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_x;
  real_T c1_d_a;
  real_T c1_e_a;
  boolean_T c1_p;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_x = c1_c_a;
  c1_d_a = c1_x;
  c1_c = muDoubleScalarPower(c1_d_a, 1.5);
  c1_e_a = c1_c_a;
  c1_p = false;
  if (c1_e_a < 0.0) {
    c1_p = true;
  }

  if (c1_p) {
    c1_error(chartInstance);
  }

  return c1_c;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i117;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i117, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i117;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_b_is_active_c1_Adaptive_control_CSAD_model, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Adaptive_control_CSAD_model), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Adaptive_control_CSAD_model);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Adaptive_control_CSAD_modelInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance)
{
  chartInstance->c1_Gamma1 = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_eta_t = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_nu = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_eta_t_dot = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_eta_t_ddot = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_alpha = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_alpha_dot = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_eta = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c1_Adaptive_control_CSAD_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2848589857U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(621265125U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3772724904U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1788357356U);
}

mxArray* sf_c1_Adaptive_control_CSAD_model_get_post_codegen_info(void);
mxArray *sf_c1_Adaptive_control_CSAD_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SS8pGwNiD9pWXsPFTwwfP");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxArray* mxPostCodegenInfo =
      sf_c1_Adaptive_control_CSAD_model_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Adaptive_control_CSAD_model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Adaptive_control_CSAD_model_jit_fallback_info(void)
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

mxArray *sf_c1_Adaptive_control_CSAD_model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Adaptive_control_CSAD_model_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Adaptive_control_CSAD_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"alpha\",},{M[1],M[22],T\"alpha_dot\",},{M[8],M[0],T\"is_active_c1_Adaptive_control_CSAD_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Adaptive_control_CSAD_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance =
      (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Adaptive_control_CSAD_modelMachineNumber_,
           1,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_Adaptive_control_CSAD_modelMachineNumber_,chartInstance->chartNumber,
           chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Adaptive_control_CSAD_modelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Adaptive_control_CSAD_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Gamma1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"eta_t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"nu");
          _SFD_SET_DATA_PROPS(3,1,1,0,"eta_t_dot");
          _SFD_SET_DATA_PROPS(4,1,1,0,"eta_t_ddot");
          _SFD_SET_DATA_PROPS(5,1,1,0,"eta");
          _SFD_SET_DATA_PROPS(6,2,0,1,"alpha");
          _SFD_SET_DATA_PROPS(7,2,0,1,"alpha_dot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1107);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Adaptive_control_CSAD_modelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance =
      (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c1_Gamma1);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c1_eta_t);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c1_nu);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c1_eta_t_dot);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c1_eta_t_ddot);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c1_alpha);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c1_alpha_dot);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c1_eta);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ss1aIvli8eP254qIZ5Rfju";
}

static void sf_opaque_initialize_c1_Adaptive_control_CSAD_model(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Adaptive_control_CSAD_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
  initialize_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Adaptive_control_CSAD_model(void
  *chartInstanceVar)
{
  enable_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Adaptive_control_CSAD_model(void
  *chartInstanceVar)
{
  disable_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Adaptive_control_CSAD_model(void
  *chartInstanceVar)
{
  sf_gateway_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Adaptive_control_CSAD_model
  (SimStruct* S)
{
  return get_sim_state_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Adaptive_control_CSAD_model(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_terminate_c1_Adaptive_control_CSAD_model(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Adaptive_control_CSAD_model_optimization_info();
    }

    finalize_c1_Adaptive_control_CSAD_model
      ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Adaptive_control_CSAD_model
    ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Adaptive_control_CSAD_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Adaptive_control_CSAD_model
      ((SFc1_Adaptive_control_CSAD_modelInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_Adaptive_control_CSAD_model(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Adaptive_control_CSAD_model_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1226062598U));
  ssSetChecksum1(S,(1111087923U));
  ssSetChecksum2(S,(4073866173U));
  ssSetChecksum3(S,(581764206U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Adaptive_control_CSAD_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Adaptive_control_CSAD_model(SimStruct *S)
{
  SFc1_Adaptive_control_CSAD_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_Adaptive_control_CSAD_modelInstanceStruct *)utMalloc
    (sizeof(SFc1_Adaptive_control_CSAD_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_Adaptive_control_CSAD_modelInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Adaptive_control_CSAD_model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Adaptive_control_CSAD_model;
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
  mdl_start_c1_Adaptive_control_CSAD_model(chartInstance);
}

void c1_Adaptive_control_CSAD_model_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Adaptive_control_CSAD_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Adaptive_control_CSAD_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Adaptive_control_CSAD_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Adaptive_control_CSAD_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
