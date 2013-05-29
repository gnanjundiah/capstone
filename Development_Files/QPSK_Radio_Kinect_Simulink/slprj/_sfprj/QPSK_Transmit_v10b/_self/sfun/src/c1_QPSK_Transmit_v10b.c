/* Include files */

#include "blascompat32.h"
#include "QPSK_Transmit_v10b_sfun.h"
#include "c1_QPSK_Transmit_v10b.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QPSK_Transmit_v10b_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *c1_eml_mx;
static const char * c1_debug_family_names[8] = { "fm", "OS_RATE", "f", "nargin",
  "nargout", "d_in", "d_out", "buf" };

static const mxArray *c1_b_eml_mx;
static const mxArray *c1_c_eml_mx;
static const mxArray *c1_d_eml_mx;
static const char * c1_b_debug_family_names[3] = { "y", "nargin", "nargout" };

static const mxArray *c1_e_eml_mx;

/* Function Declarations */
static void initialize_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static void initialize_params_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static void enable_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance);
static void disable_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static void set_sim_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance);
static void sf_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static void initSimStructsc1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_b_buf, const char_T *c1_identifier, cint8_T
  c1_y[17]);
static void c1_b_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  cint8_T c1_y[17]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static cint16_T c1_c_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_d_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[17]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[61]);
static void c1_eml_fi_checkforconst(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance);
static cint32_T c1_mtimes(SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance,
  cint8_T c1_a0[17]);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static cint16_T c1_g_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_d_out, const char_T *c1_identifier);
static cint16_T c1_h_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_QPSK_Transmit_v10b, const
  char_T *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_buf_not_empty = FALSE;
  chartInstance->c1_is_active_c1_QPSK_Transmit_v10b = 0U;
  sf_mex_assign(&c1_e_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15,
    "RoundMode", 15, "nearest", 15, "RoundingMethod", 15, "Nearest", 15,
    "OverflowMode", 15, "saturate", 15, "OverflowAction", 15, "Saturate", 15,
    "ProductMode", 15, "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 65535.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 65535.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, TRUE), TRUE);
  sf_mex_assign(&c1_d_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 14.0, 15, "FractionLength", 6, 14.0, 15, "BinaryPoint", 6,
    14.0, 15, "Slope", 6, 6.103515625E-5, 15, "FixedExponent", 6, -14.0), TRUE);
  sf_mex_assign(&c1_c_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 12.0, 15, "FractionLength", 6, 11.0, 15, "BinaryPoint", 6,
    11.0, 15, "Slope", 6, 0.00048828125, 15, "FixedExponent", 6, -11.0), TRUE);
  sf_mex_assign(&c1_b_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 3.0, 15, "FractionLength", 6, 0.0, 15, "BinaryPoint", 6,
    0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0), TRUE);
  sf_mex_assign(&c1_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15, "RoundMode",
    15, "floor", 15, "RoundingMethod", 15, "Floor", 15, "OverflowMode", 15,
    "wrap", 15, "OverflowAction", 15, "Wrap", 15, "ProductMode", 15,
    "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 128.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 128.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, TRUE), TRUE);
}

static void initialize_params_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
}

static void enable_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  cint16_T c1_u;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i0;
  cint8_T c1_b_u[17];
  const mxArray *c1_e_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_f_y = NULL;
  cint16_T *c1_d_out;
  c1_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_b_y = NULL;
  c1_u.re = c1_d_out->re;
  c1_u.im = c1_d_out->im;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c1_e_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_c_eml_mx), 15,
    "simulinkarray", 14, c1_c_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_d_y = NULL;
  if (!chartInstance->c1_buf_not_empty) {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    for (c1_i0 = 0; c1_i0 < 17; c1_i0++) {
      c1_b_u[c1_i0].re = chartInstance->c1_buf[c1_i0].re;
      c1_b_u[c1_i0].im = chartInstance->c1_buf[c1_i0].im;
    }

    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_u, 2, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
    sf_mex_assign(&c1_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
      sf_mex_dup(c1_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_b_eml_mx), 15,
      "simulinkarray", 14, c1_e_y, 15, "fimathislocal", 3, TRUE), FALSE);
  }

  sf_mex_setcell(c1_y, 1, c1_d_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_QPSK_Transmit_v10b;
  c1_c_u = c1_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  cint8_T c1_icv0[17];
  int32_T c1_i1;
  cint16_T *c1_d_out;
  c1_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_d_out = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "d_out");
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)), "buf",
                      c1_icv0);
  for (c1_i1 = 0; c1_i1 < 17; c1_i1++) {
    chartInstance->c1_buf[c1_i1] = c1_icv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_QPSK_Transmit_v10b = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_QPSK_Transmit_v10b");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_QPSK_Transmit_v10b(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c1_eml_mx);
  sf_mex_destroy(&c1_b_eml_mx);
  sf_mex_destroy(&c1_c_eml_mx);
  sf_mex_destroy(&c1_d_eml_mx);
  sf_mex_destroy(&c1_e_eml_mx);
}

static void sf_c1_QPSK_Transmit_v10b(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_QPSK_Transmit_v10b(chartInstance);
  sf_debug_check_for_state_inconsistency(_QPSK_Transmit_v10bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
  cint8_T c1_d_in;
  uint32_T c1_debug_family_var_map[8];
  const mxArray *c1_fm = NULL;
  real_T c1_OS_RATE;
  int16_T c1_f[17];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  cint16_T c1_d_out;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_y[17];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i2;
  static real_T c1_dv0[17] = { 0.006690562067, -0.00576859381, -0.011827354519,
    0.020586915021, 0.016726405168, -0.053692342207, -0.020253031546,
    0.196043589067, 0.33682241319, 0.196043589067, -0.020253031546,
    -0.053692342207, 0.016726405168, 0.020586915021, -0.011827354519,
    -0.00576859381, 0.006690562067 };

  int32_T c1_i3;
  static int16_T c1_iv0[17] = { 109, -95, -194, 337, 274, -880, -332, 3211, 5518,
    3211, -332, -880, 274, 337, -194, -95, 109 };

  int32_T c1_i4;
  int32_T c1_i5;
  cint8_T c1_hoistedGlobal[17];
  int32_T c1_i6;
  cint8_T c1_varargin_1[17];
  int8_T c1_i7;
  cint8_T c1_b_d_in;
  int8_T c1_i8;
  const mxArray *c1_propVal = NULL;
  const mxArray *c1_errmsg = NULL;
  const mxArray *c1_b_propVal = NULL;
  const mxArray *c1_b_errmsg = NULL;
  const mxArray *c1_T = NULL;
  const mxArray *c1_F = NULL;
  const mxArray *c1_ERR = NULL;
  const mxArray *c1_val = NULL;
  const mxArray *c1_isautoscaled = NULL;
  const mxArray *c1_pvpairsetdata = NULL;
  const mxArray *c1_isfimathlocal = NULL;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  cint8_T c1_b_hoistedGlobal[17];
  cint32_T c1_b_varargin_1;
  const mxArray *c1_c_propVal = NULL;
  const mxArray *c1_c_errmsg = NULL;
  const mxArray *c1_d_propVal = NULL;
  const mxArray *c1_d_errmsg = NULL;
  int16_T c1_i12;
  cint16_T c1_c_varargin_1;
  int16_T c1_i13;
  const mxArray *c1_b_T = NULL;
  const mxArray *c1_b_F = NULL;
  const mxArray *c1_b_ERR = NULL;
  const mxArray *c1_b_val = NULL;
  const mxArray *c1_b_isautoscaled = NULL;
  const mxArray *c1_b_pvpairsetdata = NULL;
  const mxArray *c1_b_isfimathlocal = NULL;
  cint16_T *c1_b_d_out;
  cint8_T *c1_c_d_in;
  c1_b_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_d_in = (cint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_d_in.re = c1_c_d_in->re;
  c1_d_in.im = c1_c_d_in->im;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_fm, 0U, c1_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_OS_RATE, 1U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_f, 2U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 4U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_d_in, 5U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_d_out, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c1_buf, 7U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_fm = c1_eml_mx;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_OS_RATE = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  sf_debug_symbol_scope_push_eml(0U, 3U, 3U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 0U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 1U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 2U,
    c1_d_sf_marshallOut, c1_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i2 = 0; c1_i2 < 17; c1_i2++) {
    c1_y[c1_i2] = c1_dv0[c1_i2];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  for (c1_i3 = 0; c1_i3 < 17; c1_i3++) {
    c1_f[c1_i3] = c1_iv0[c1_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_buf_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    for (c1_i4 = 0; c1_i4 < 17; c1_i4++) {
      chartInstance->c1_buf[c1_i4].re = 0;
      chartInstance->c1_buf[c1_i4].im = 0;
    }

    chartInstance->c1_buf_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i5 = 0; c1_i5 < 17; c1_i5++) {
    c1_hoistedGlobal[c1_i5] = chartInstance->c1_buf[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 16; c1_i6++) {
    c1_varargin_1[c1_i6] = c1_hoistedGlobal[c1_i6 + 1];
  }

  c1_i7 = c1_d_in.re;
  if ((int8_T)(c1_i7 & 4) != 0) {
    c1_b_d_in.re = (int8_T)(c1_i7 | -4);
  } else {
    c1_b_d_in.re = (int8_T)(c1_i7 & 3);
  }

  c1_i8 = c1_d_in.im;
  if ((int8_T)(c1_i8 & 4) != 0) {
    c1_b_d_in.im = (int8_T)(c1_i8 | -4);
  } else {
    c1_b_d_in.im = (int8_T)(c1_i8 & 3);
  }

  c1_varargin_1[16] = c1_b_d_in;
  c1_eml_fi_checkforconst(chartInstance);
  sf_mex_destroy(&c1_propVal);
  sf_mex_destroy(&c1_errmsg);
  sf_mex_destroy(&c1_b_propVal);
  sf_mex_destroy(&c1_b_errmsg);
  sf_mex_destroy(&c1_T);
  sf_mex_destroy(&c1_F);
  sf_mex_destroy(&c1_ERR);
  sf_mex_destroy(&c1_val);
  sf_mex_destroy(&c1_isautoscaled);
  sf_mex_destroy(&c1_pvpairsetdata);
  sf_mex_destroy(&c1_isfimathlocal);
  for (c1_i9 = 0; c1_i9 < 17; c1_i9++) {
    chartInstance->c1_buf[c1_i9] = c1_varargin_1[c1_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i10 = 0; c1_i10 < 17; c1_i10++) {
    c1_hoistedGlobal[c1_i10] = chartInstance->c1_buf[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 17; c1_i11++) {
    c1_b_hoistedGlobal[c1_i11] = c1_hoistedGlobal[c1_i11];
  }

  c1_b_varargin_1 = c1_mtimes(chartInstance, c1_b_hoistedGlobal);
  sf_mex_destroy(&c1_c_propVal);
  sf_mex_destroy(&c1_c_errmsg);
  sf_mex_destroy(&c1_d_propVal);
  sf_mex_destroy(&c1_d_errmsg);
  c1_i12 = (int16_T)(c1_b_varargin_1.re >> 3);
  if ((int16_T)(c1_i12 & 2048) != 0) {
    c1_c_varargin_1.re = (int16_T)(c1_i12 | -2048);
  } else {
    c1_c_varargin_1.re = (int16_T)(c1_i12 & 2047);
  }

  c1_i13 = (int16_T)(c1_b_varargin_1.im >> 3);
  if ((int16_T)(c1_i13 & 2048) != 0) {
    c1_c_varargin_1.im = (int16_T)(c1_i13 | -2048);
  } else {
    c1_c_varargin_1.im = (int16_T)(c1_i13 & 2047);
  }

  c1_d_out = c1_c_varargin_1;
  sf_mex_destroy(&c1_b_T);
  sf_mex_destroy(&c1_b_F);
  sf_mex_destroy(&c1_b_ERR);
  sf_mex_destroy(&c1_b_val);
  sf_mex_destroy(&c1_b_isautoscaled);
  sf_mex_destroy(&c1_b_pvpairsetdata);
  sf_mex_destroy(&c1_b_isfimathlocal);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  c1_b_d_out->re = c1_d_out.re;
  c1_b_d_out->im = c1_d_out.im;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_QPSK_Transmit_v10b
  (SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 0U, sf_debug_get_script_id(
    "C:/UCSD/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/SRRC.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i14;
  cint8_T c1_u[17];
  const mxArray *c1_y = NULL;
  int32_T c1_i15;
  cint8_T c1_b_u[17];
  const mxArray *c1_b_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i14 = 0; c1_i14 < 17; c1_i14++) {
    c1_u[c1_i14] = (*(cint8_T (*)[17])c1_inData)[c1_i14];
  }

  c1_y = NULL;
  if (!chartInstance->c1_buf_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    for (c1_i15 = 0; c1_i15 < 17; c1_i15++) {
      c1_b_u[c1_i15].re = c1_u[c1_i15].re;
      c1_b_u[c1_i15].im = c1_u[c1_i15].im;
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 2, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
    sf_mex_assign(&c1_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c1_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_b_eml_mx), 15,
      "simulinkarray", 14, c1_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_b_buf, const char_T *c1_identifier, cint8_T
  c1_y[17])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_buf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_buf);
}

static void c1_b_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  cint8_T c1_y[17])
{
  int32_T c1_i16;
  uint32_T c1_uv0[2];
  const mxArray *c1_mxFi = NULL;
  const mxArray *c1_mxInt = NULL;
  cint8_T c1_icv1[17];
  int32_T c1_i17;
  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_uv0[c1_i16] = 1U + ((uint32_T)c1_i16 << 4);
  }

  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_buf_not_empty = FALSE;
  } else {
    chartInstance->c1_buf_not_empty = TRUE;
    sf_mex_check_fi(c1_parentId, c1_u, 1, 2U, c1_uv0, c1_eml_mx, c1_b_eml_mx);
    sf_mex_assign(&c1_mxFi, sf_mex_dup(c1_u), FALSE);
    sf_mex_assign(&c1_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
                   (c1_mxFi)), FALSE);
    sf_mex_import(c1_parentId, sf_mex_dup(c1_mxInt), c1_icv1, 1, 2, 1U, 1, 0U, 2,
                  1, 17);
    sf_mex_destroy(&c1_mxFi);
    sf_mex_destroy(&c1_mxInt);
    for (c1_i17 = 0; c1_i17 < 17; c1_i17++) {
      c1_y[c1_i17] = c1_icv1[c1_i17];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_buf;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  cint8_T c1_y[17];
  int32_T c1_i18;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_b_buf = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_buf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_buf);
  for (c1_i18 = 0; c1_i18 < 17; c1_i18++) {
    (*(cint8_T (*)[17])c1_outData)[c1_i18] = c1_y[c1_i18];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  cint16_T c1_u;
  const mxArray *c1_y = NULL;
  cint16_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(cint16_T *)c1_inData;
  c1_y = NULL;
  c1_b_u.re = c1_u.re;
  c1_b_u.im = c1_u.im;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c1_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_c_eml_mx), 15,
    "simulinkarray", 14, c1_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static cint16_T c1_c_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  cint16_T c1_y;
  const mxArray *c1_mxFi = NULL;
  const mxArray *c1_mxInt = NULL;
  cint16_T c1_ic0;
  sf_mex_check_fi(c1_parentId, c1_u, 1, 0U, 0, c1_eml_mx, c1_c_eml_mx);
  sf_mex_assign(&c1_mxFi, sf_mex_dup(c1_u), FALSE);
  sf_mex_assign(&c1_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c1_mxFi)), FALSE);
  sf_mex_import(c1_parentId, sf_mex_dup(c1_mxInt), &c1_ic0, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c1_mxFi);
  sf_mex_destroy(&c1_mxInt);
  c1_y = c1_ic0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d_out;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  cint16_T c1_y;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_d_out = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_out), &c1_thisId);
  sf_mex_destroy(&c1_d_out);
  *(cint16_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  cint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(cint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_d_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i19;
  int16_T c1_u[17];
  const mxArray *c1_y = NULL;
  int32_T c1_i20;
  int16_T c1_b_u[17];
  const mxArray *c1_b_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i19 = 0; c1_i19 < 17; c1_i19++) {
    c1_u[c1_i19] = (*(int16_T (*)[17])c1_inData)[c1_i19];
  }

  c1_y = NULL;
  for (c1_i20 = 0; c1_i20 < 17; c1_i20++) {
    c1_b_u[c1_i20] = c1_u[c1_i20];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 4, 0U, 1U, 0U, 1, 17), FALSE);
  sf_mex_assign(&c1_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c1_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_d_eml_mx), 15,
    "simulinkarray", 14, c1_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  const mxArray *c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = sf_mex_dup(*(const mxArray **)c1_inData);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i21;
  real_T c1_b_inData[17];
  int32_T c1_i22;
  real_T c1_u[17];
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i21 = 0; c1_i21 < 17; c1_i21++) {
    c1_b_inData[c1_i21] = (*(real_T (*)[17])c1_inData)[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 17; c1_i22++) {
    c1_u[c1_i22] = c1_b_inData[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 17), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[17])
{
  real_T c1_dv1[17];
  int32_T c1_i23;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 17);
  for (c1_i23 = 0; c1_i23 < 17; c1_i23++) {
    c1_y[c1_i23] = c1_dv1[c1_i23];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[17];
  int32_T c1_i24;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i24 = 0; c1_i24 < 17; c1_i24++) {
    (*(real_T (*)[17])c1_outData)[c1_i24] = c1_b_y[c1_i24];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_QPSK_Transmit_v10b_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[61];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i25;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 61), FALSE);
  for (c1_i25 = 0; c1_i25 < 61; c1_i25++) {
    c1_r0 = &c1_info[c1_i25];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i25);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i25);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[61])
{
  c1_info[0].context = "";
  c1_info[0].name = "hdlfimath";
  c1_info[0].dominantType = "";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c1_info[0].fileTimeLo = 1289552008U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c1_info[1].name = "fimath";
  c1_info[1].dominantType = "char";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fimath.m";
  c1_info[1].fileTimeLo = 1289552004U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "SRRC";
  c1_info[2].dominantType = "";
  c1_info[2].resolved =
    "[E]C:/UCSD/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/SRRC.m";
  c1_info[2].fileTimeLo = 1366660138U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "fi_impl";
  c1_info[3].dominantType = "";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m";
  c1_info[3].fileTimeLo = 1326760396U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[4].name = "length";
  c1_info[4].dominantType = "cell";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[4].fileTimeLo = 1303178606U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[5].name = "eml_fi_checkforconst";
  c1_info[5].dominantType = "embedded.fimath";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforconst.m";
  c1_info[5].fileTimeLo = 1326760394U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[6].name = "isfi";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[6].fileTimeLo = 1289552010U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[7].name = "isnumerictype";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c1_info[7].fileTimeLo = 1289552012U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c1_info[8].name = "isfi";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[8].fileTimeLo = 1289552010U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[9].name = "eml_fi_checkforntype";
  c1_info[9].dominantType = "embedded.numerictype";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforntype.m";
  c1_info[9].fileTimeLo = 1289552002U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "";
  c1_info[10].name = "mtimes";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].fileTimeLo = 1289552092U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[11].name = "isfi";
  c1_info[11].dominantType = "embedded.fi";
  c1_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[11].fileTimeLo = 1289552010U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[12].name = "isnumerictype";
  c1_info[12].dominantType = "embedded.numerictype";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c1_info[12].fileTimeLo = 1289552012U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[13].name = "isfloat";
  c1_info[13].dominantType = "embedded.fi";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c1_info[13].fileTimeLo = 1336554498U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c1_info[14].name = "get";
  c1_info[14].dominantType = "embedded.numerictype";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c1_info[14].fileTimeLo = 1289551964U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c1_info[15].name = "isfi";
  c1_info[15].dominantType = "embedded.fi";
  c1_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[15].fileTimeLo = 1289552010U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c1_info[16].name = "numerictype";
  c1_info[16].dominantType = "embedded.fi";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/numerictype.m";
  c1_info[16].fileTimeLo = 1289552076U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c1_info[17].name = "fimath";
  c1_info[17].dominantType = "embedded.fi";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/fimath.m";
  c1_info[17].fileTimeLo = 1289552054U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c1_info[18].name = "eml_fi_checkforntype";
  c1_info[18].dominantType = "embedded.fi";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforntype.m";
  c1_info[18].fileTimeLo = 1289552002U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "mtimes";
  c1_info[19].dominantType = "embedded.fi";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[19].fileTimeLo = 1330640836U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[20].name = "isfi";
  c1_info[20].dominantType = "embedded.fi";
  c1_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c1_info[20].fileTimeLo = 1289552010U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[21].name = "isscaledtype";
  c1_info[21].dominantType = "embedded.fi";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m";
  c1_info[21].fileTimeLo = 1289552066U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m";
  c1_info[22].name = "isfixed";
  c1_info[22].dominantType = "embedded.fi";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c1_info[22].fileTimeLo = 1336554498U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c1_info[23].name = "get";
  c1_info[23].dominantType = "embedded.numerictype";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c1_info[23].fileTimeLo = 1289551964U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[24].name = "eml_checkfimathforbinaryops";
  c1_info[24].dominantType = "embedded.fi";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m";
  c1_info[24].fileTimeLo = 1340245106U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m";
  c1_info[25].name = "isFimathEqualForCodeGen";
  c1_info[25].dominantType = "embedded.fimath";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isFimathEqualForCodeGen.m";
  c1_info[25].fileTimeLo = 1340245106U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[26].name = "get";
  c1_info[26].dominantType = "embedded.numerictype";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c1_info[26].fileTimeLo = 1289551964U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[27].name = "get";
  c1_info[27].dominantType = "embedded.fimath";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m";
  c1_info[27].fileTimeLo = 1289551966U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[28].name = "strcmpi";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c1_info[28].fileTimeLo = 1327451510U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c1_info[29].name = "eml_assert_supported_string";
  c1_info[29].dominantType = "char";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c1_info[29].fileTimeLo = 1327451510U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c1_info[30].name = "eml_charmax";
  c1_info[30].dominantType = "";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c1_info[30].fileTimeLo = 1327451510U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c1_info[31].name = "intmax";
  c1_info[31].dominantType = "char";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[31].fileTimeLo = 1311287716U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange";
  c1_info[32].name = "eml_charmax";
  c1_info[32].dominantType = "";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c1_info[32].fileTimeLo = 1327451510U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c1_info[33].name = "min";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[33].fileTimeLo = 1311287718U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[34].name = "eml_min_or_max";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[34].fileTimeLo = 1334103890U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[35].name = "eml_scalar_eg";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[35].fileTimeLo = 1286851196U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[36].name = "eml_scalexp_alloc";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[36].fileTimeLo = 1330640834U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[37].name = "eml_index_class";
  c1_info[37].dominantType = "";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[37].fileTimeLo = 1323202978U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[38].name = "eml_scalar_eg";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[38].fileTimeLo = 1286851196U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c1_info[39].name = "lower";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m";
  c1_info[39].fileTimeLo = 1327451510U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m";
  c1_info[40].name = "eml_string_transform";
  c1_info[40].dominantType = "char";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c1_info[40].fileTimeLo = 1327451510U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c1_info[41].name = "eml_assert_supported_string";
  c1_info[41].dominantType = "char";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c1_info[41].fileTimeLo = 1327451510U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c1_info[42].name = "eml_charmax";
  c1_info[42].dominantType = "";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c1_info[42].fileTimeLo = 1327451510U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c1_info[43].name = "colon";
  c1_info[43].dominantType = "int8";
  c1_info[43].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[43].fileTimeLo = 1311287718U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[44].name = "floor";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[44].fileTimeLo = 1286851142U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[45].name = "eml_scalar_floor";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[45].fileTimeLo = 1286851126U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[46].name = "intmin";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[46].fileTimeLo = 1311287718U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[47].name = "intmax";
  c1_info[47].dominantType = "char";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[47].fileTimeLo = 1311287716U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[48].name = "intmin";
  c1_info[48].dominantType = "char";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[48].fileTimeLo = 1311287718U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[49].name = "intmax";
  c1_info[49].dominantType = "char";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[49].fileTimeLo = 1311287716U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[50].name = "eml_isa_uint";
  c1_info[50].dominantType = "int8";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[50].fileTimeLo = 1286851184U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[51].name = "eml_unsigned_class";
  c1_info[51].dominantType = "char";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[51].fileTimeLo = 1323202980U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[52].name = "eml_index_class";
  c1_info[52].dominantType = "";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[52].fileTimeLo = 1323202978U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[53].name = "intmax";
  c1_info[53].dominantType = "char";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[53].fileTimeLo = 1311287716U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[54].name = "eml_isa_uint";
  c1_info[54].dominantType = "int8";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[54].fileTimeLo = 1286851184U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[55].name = "eml_index_plus";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[55].fileTimeLo = 1286851178U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[56].name = "eml_index_class";
  c1_info[56].dominantType = "";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[56].fileTimeLo = 1323202978U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c1_info[57].name = "eml_int_forloop_overflow_check";
  c1_info[57].dominantType = "";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[57].fileTimeLo = 1332197472U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[58].name = "intmax";
  c1_info[58].dominantType = "char";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[58].fileTimeLo = 1311287716U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c1_info[59].name = "char";
  c1_info[59].dominantType = "int8";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[59].fileTimeLo = 1319762368U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c1_info[60].name = "eml_fixpt_times";
  c1_info[60].dominantType = "embedded.fi";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m";
  c1_info[60].fileTimeLo = 1289552046U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
}

static void c1_eml_fi_checkforconst(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance)
{
}

static cint32_T c1_mtimes(SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance,
  cint8_T c1_a0[17])
{
  cint32_T c1_cout;
  const mxArray *c1_propVal = NULL;
  const mxArray *c1_errmsg = NULL;
  const mxArray *c1_b_propVal = NULL;
  const mxArray *c1_b_errmsg = NULL;
  const mxArray *c1_c_propVal = NULL;
  const mxArray *c1_c_errmsg = NULL;
  const mxArray *c1_d_propVal = NULL;
  const mxArray *c1_d_errmsg = NULL;
  const mxArray *c1_e_propVal = NULL;
  const mxArray *c1_e_errmsg = NULL;
  const mxArray *c1_f_propVal = NULL;
  const mxArray *c1_f_errmsg = NULL;
  const mxArray *c1_g_propVal = NULL;
  const mxArray *c1_g_errmsg = NULL;
  static cint32_T c1_ic1 = { 0, 0 };

  int32_T c1_k;
  real_T c1_b_k;
  cint8_T c1_a;
  static int16_T c1_iv1[17] = { 109, -95, -194, 337, 274, -880, -332, 3211, 5518,
    3211, -332, -880, 274, 337, -194, -95, 109 };

  int16_T c1_b;
  int8_T c1_ar;
  int8_T c1_ai;
  int32_T c1_i26;
  int32_T c1_cr;
  int32_T c1_i27;
  int32_T c1_ci;
  cint32_T c1_prodAB;
  int32_T c1_i28;
  int32_T c1_i29;
  const mxArray *c1_ERR = NULL;
  const mxArray *c1_a2SD = NULL;
  const mxArray *c1_b2SD = NULL;
  const mxArray *c1_Tsd = NULL;
  const mxArray *c1_tp = NULL;
  const mxArray *c1_errmsg1 = NULL;
  const mxArray *c1_tc = NULL;
  const mxArray *c1_errmsg2 = NULL;
  sf_mex_destroy(&c1_propVal);
  sf_mex_destroy(&c1_errmsg);
  sf_mex_destroy(&c1_b_propVal);
  sf_mex_destroy(&c1_b_errmsg);
  sf_mex_destroy(&c1_c_propVal);
  sf_mex_destroy(&c1_c_errmsg);
  sf_mex_destroy(&c1_d_propVal);
  sf_mex_destroy(&c1_d_errmsg);
  sf_mex_destroy(&c1_e_propVal);
  sf_mex_destroy(&c1_e_errmsg);
  sf_mex_destroy(&c1_f_propVal);
  sf_mex_destroy(&c1_f_errmsg);
  sf_mex_destroy(&c1_g_propVal);
  sf_mex_destroy(&c1_g_errmsg);
  c1_cout = c1_ic1;
  for (c1_k = 0; c1_k < 17; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_a = c1_a0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 17, 2, 0) - 1];
    c1_b = c1_iv1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 17, 1, 0) - 1];
    c1_ar = c1_a.re;
    c1_ai = c1_a.im;
    c1_i26 = c1_ar * c1_b;
    if ((c1_i26 & 65536) != 0) {
      c1_cr = c1_i26 | -65536;
    } else {
      c1_cr = c1_i26 & 65535;
    }

    c1_i27 = c1_ai * c1_b;
    if ((c1_i27 & 65536) != 0) {
      c1_ci = c1_i27 | -65536;
    } else {
      c1_ci = c1_i27 & 65535;
    }

    c1_prodAB.re = c1_cr;
    c1_prodAB.im = c1_ci;
    c1_i28 = c1_cout.re + c1_prodAB.re;
    if ((c1_i28 & 2097152) != 0) {
      c1_cout.re = c1_i28 | -2097152;
    } else {
      c1_cout.re = c1_i28 & 2097151;
    }

    c1_i29 = c1_cout.im + c1_prodAB.im;
    if ((c1_i29 & 2097152) != 0) {
      c1_cout.im = c1_i29 | -2097152;
    } else {
      c1_cout.im = c1_i29 & 2097151;
    }
  }

  sf_mex_destroy(&c1_ERR);
  sf_mex_destroy(&c1_a2SD);
  sf_mex_destroy(&c1_b2SD);
  sf_mex_destroy(&c1_Tsd);
  sf_mex_destroy(&c1_tp);
  sf_mex_destroy(&c1_errmsg1);
  sf_mex_destroy(&c1_tc);
  sf_mex_destroy(&c1_errmsg2);
  return c1_cout;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i30;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i30, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i30;
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
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  cint16_T c1_u;
  const mxArray *c1_y = NULL;
  cint16_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(cint16_T *)c1_inData;
  c1_y = NULL;
  c1_b_u.re = c1_u.re;
  c1_b_u.im = c1_u.im;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c1_e_eml_mx), 15, "numerictype", 14, sf_mex_dup(c1_c_eml_mx), 15,
    "simulinkarray", 14, c1_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static cint16_T c1_g_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_d_out, const char_T *c1_identifier)
{
  cint16_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_out), &c1_thisId);
  sf_mex_destroy(&c1_d_out);
  return c1_y;
}

static cint16_T c1_h_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  cint16_T c1_y;
  const mxArray *c1_mxFi = NULL;
  const mxArray *c1_mxInt = NULL;
  cint16_T c1_ic2;
  sf_mex_check_fi(c1_parentId, c1_u, 1, 0U, 0, c1_e_eml_mx, c1_c_eml_mx);
  sf_mex_assign(&c1_mxFi, sf_mex_dup(c1_u), FALSE);
  sf_mex_assign(&c1_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c1_mxFi)), FALSE);
  sf_mex_import(c1_parentId, sf_mex_dup(c1_mxInt), &c1_ic2, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c1_mxFi);
  sf_mex_destroy(&c1_mxInt);
  c1_y = c1_ic2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d_out;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  cint16_T c1_y;
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)chartInstanceVoid;
  c1_d_out = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_out), &c1_thisId);
  sf_mex_destroy(&c1_d_out);
  *(cint16_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_QPSK_Transmit_v10b, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_QPSK_Transmit_v10b), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_QPSK_Transmit_v10b);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_QPSK_Transmit_v10bInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_QPSK_Transmit_v10b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(75171818U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(474355336U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1322953054U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2685747272U);
}

mxArray *sf_c1_QPSK_Transmit_v10b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iRmvylP4knQLIrxkywK4wG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(12));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-11));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_QPSK_Transmit_v10b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"d_out\",},{M[4],M[0],T\"buf\",S'l','i','p'{{M1x2[62 65],M[0],}}},{M[8],M[0],T\"is_active_c1_QPSK_Transmit_v10b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_QPSK_Transmit_v10b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
    chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QPSK_Transmit_v10bMachineNumber_,
           1,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QPSK_Transmit_v10bMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QPSK_Transmit_v10bMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QPSK_Transmit_v10bMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"d_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"d_out");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,297);
        _SFD_CV_INIT_EML_IF(0,1,0,108,125,-1,212);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"SRRC",0,-1,300);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,12,0,1,-11,1,
          (MexFcnForType)c1_i_sf_marshallOut,(MexInFcnForType)c1_f_sf_marshallIn);

        {
          cint8_T *c1_d_in;
          cint16_T *c1_d_out;
          c1_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_d_in = (cint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_d_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_d_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_QPSK_Transmit_v10bMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "4P2TMU4ZdIgxUaGroXLxuH";
}

static void sf_opaque_initialize_c1_QPSK_Transmit_v10b(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
  initialize_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_QPSK_Transmit_v10b(void *chartInstanceVar)
{
  enable_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_QPSK_Transmit_v10b(void *chartInstanceVar)
{
  disable_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_QPSK_Transmit_v10b(void *chartInstanceVar)
{
  sf_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_QPSK_Transmit_v10b(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_QPSK_Transmit_v10b
    ((SFc1_QPSK_Transmit_v10bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_QPSK_Transmit_v10b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_QPSK_Transmit_v10b(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_QPSK_Transmit_v10b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_QPSK_Transmit_v10b(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_QPSK_Transmit_v10b(S);
}

static void sf_opaque_set_sim_state_c1_QPSK_Transmit_v10b(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_QPSK_Transmit_v10b(S, st);
}

static void sf_opaque_terminate_c1_QPSK_Transmit_v10b(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_QPSK_Transmit_v10bInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QPSK_Transmit_v10b_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_QPSK_Transmit_v10b((SFc1_QPSK_Transmit_v10bInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_QPSK_Transmit_v10b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_QPSK_Transmit_v10b
      ((SFc1_QPSK_Transmit_v10bInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_QPSK_Transmit_v10b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QPSK_Transmit_v10b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2712366216U));
  ssSetChecksum1(S,(2120311492U));
  ssSetChecksum2(S,(1776788335U));
  ssSetChecksum3(S,(1267617523U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_QPSK_Transmit_v10b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_QPSK_Transmit_v10b(SimStruct *S)
{
  SFc1_QPSK_Transmit_v10bInstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v10bInstanceStruct *)malloc(sizeof
    (SFc1_QPSK_Transmit_v10bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_QPSK_Transmit_v10bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_QPSK_Transmit_v10b;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_QPSK_Transmit_v10b_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_QPSK_Transmit_v10b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_QPSK_Transmit_v10b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_QPSK_Transmit_v10b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_QPSK_Transmit_v10b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
