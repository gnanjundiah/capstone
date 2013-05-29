/* Include files */

#include "blascompat32.h"
#include "QPSK_Transmit_v12c_sfun.h"
#include "c3_QPSK_Transmit_v12c.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QPSK_Transmit_v12c_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *c3_eml_mx;
static const char * c3_debug_family_names[26] = { "fm", "OS_RATE", "f", "temp1",
  "temp2", "temp3", "temp4", "temp5", "temp6", "temp7", "temp8", "temp9",
  "temp10", "temp11", "temp12", "temp13", "temp14", "temp15", "temp16", "temp17",
  "result", "nargin", "nargout", "d_in", "d_out", "buf" };

static const mxArray *c3_b_eml_mx;
static const mxArray *c3_c_eml_mx;
static const mxArray *c3_d_eml_mx;
static const mxArray *c3_e_eml_mx;
static const mxArray *c3_f_eml_mx;
static const char * c3_b_debug_family_names[3] = { "y", "nargin", "nargout" };

static const mxArray *c3_g_eml_mx;

/* Function Declarations */
static void initialize_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void initialize_params_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void enable_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance);
static void disable_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct *
  chartInstance);
static void c3_update_debugger_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void set_sim_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance);
static void sf_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void initSimStructsc3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_b_buf, const char_T *c3_identifier, cint8_T
  c3_y[17]);
static void c3_b_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  cint8_T c3_y[17]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static cint16_T c3_c_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_d_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static cint64m_T c3_e_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static cint32_T c3_f_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[17]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[73]);
static void c3_SRRC(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance);
static void c3_eml_fi_checkforconst(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance);
static cint32_T c3_mtimes(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint8_T c3_a0);
static cint32_T c3_b_mtimes(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint8_T c3_a0, int16_T c3_b0);
static cint32_T c3_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_b_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_c_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_d_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_e_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_f_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_g_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_h_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_i_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_j_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_k_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_l_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_m_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_n_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint32_T c3_o_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static cint64m_T c3_p_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_h_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static cint16_T c3_i_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_d_out, const char_T *c3_identifier);
static cint16_T c3_j_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_k_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_QPSK_Transmit_v12c, const
  char_T *c3_identifier);
static uint8_T c3_l_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static int32_T c3_MultiWord2sLong(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u[]);
static void c3_sMultiWordShr(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u1[], int32_T c3_n1, uint32_T c3_n2,
  uint32_T c3_y[], int32_T c3_n);
static void c3_MultiWordSignedWrap(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u1[], int32_T c3_n1, uint32_T c3_n2,
  uint32_T c3_y[]);
static void c3_sLong2MultiWord(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, int32_T c3_u, uint32_T c3_y[], int32_T c3_n);
static void c3_MultiWordAdd(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  const uint32_T c3_u1[], const uint32_T c3_u2[], uint32_T c3_y[], int32_T c3_n);
static void init_dsm_address_info(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_buf_not_empty = FALSE;
  chartInstance->c3_is_active_c3_QPSK_Transmit_v12c = 0U;
  sf_mex_assign(&c3_g_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15,
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
  sf_mex_assign(&c3_f_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 14.0, 15, "FractionLength", 6, 14.0, 15, "BinaryPoint", 6,
    14.0, 15, "Slope", 6, 6.103515625E-5, 15, "FixedExponent", 6, -14.0), TRUE);
  sf_mex_assign(&c3_e_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 17.0, 15, "FractionLength", 6, 14.0, 15, "BinaryPoint", 6,
    14.0, 15, "Slope", 6, 6.103515625E-5, 15, "FixedExponent", 6, -14.0), TRUE);
  sf_mex_assign(&c3_d_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 33.0, 15, "FractionLength", 6, 14.0, 15, "BinaryPoint", 6,
    14.0, 15, "Slope", 6, 6.103515625E-5, 15, "FixedExponent", 6, -14.0), TRUE);
  sf_mex_assign(&c3_c_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 12.0, 15, "FractionLength", 6, 11.0, 15, "BinaryPoint", 6,
    11.0, 15, "Slope", 6, 0.00048828125, 15, "FixedExponent", 6, -11.0), TRUE);
  sf_mex_assign(&c3_b_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 3.0, 15, "FractionLength", 6, 0.0, 15, "BinaryPoint", 6,
    0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0), TRUE);
  sf_mex_assign(&c3_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15, "RoundMode",
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

static void initialize_params_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
}

static void enable_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  cint16_T c3_u;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i0;
  cint8_T c3_b_u[17];
  const mxArray *c3_e_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_f_y = NULL;
  cint16_T *c3_d_out;
  c3_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  c3_b_y = NULL;
  c3_u.re = c3_d_out->re;
  c3_u.im = c3_d_out->im;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_g_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_c_eml_mx), 15,
    "simulinkarray", 14, c3_c_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_d_y = NULL;
  if (!chartInstance->c3_buf_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    for (c3_i0 = 0; c3_i0 < 17; c3_i0++) {
      c3_b_u[c3_i0].re = chartInstance->c3_buf[c3_i0].re;
      c3_b_u[c3_i0].im = chartInstance->c3_buf[c3_i0].im;
    }

    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_b_u, 2, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
    sf_mex_assign(&c3_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
      sf_mex_dup(c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_b_eml_mx), 15,
      "simulinkarray", 14, c3_e_y, 15, "fimathislocal", 3, TRUE), FALSE);
  }

  sf_mex_setcell(c3_y, 1, c3_d_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_QPSK_Transmit_v12c;
  c3_c_u = c3_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  cint8_T c3_icv0[17];
  int32_T c3_i1;
  cint16_T *c3_d_out;
  c3_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_d_out = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "d_out");
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)), "buf",
                      c3_icv0);
  for (c3_i1 = 0; c3_i1 < 17; c3_i1++) {
    chartInstance->c3_buf[c3_i1] = c3_icv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_QPSK_Transmit_v12c = c3_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_QPSK_Transmit_v12c");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_QPSK_Transmit_v12c(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c3_eml_mx);
  sf_mex_destroy(&c3_b_eml_mx);
  sf_mex_destroy(&c3_c_eml_mx);
  sf_mex_destroy(&c3_d_eml_mx);
  sf_mex_destroy(&c3_e_eml_mx);
  sf_mex_destroy(&c3_f_eml_mx);
  sf_mex_destroy(&c3_g_eml_mx);
}

static void sf_c3_QPSK_Transmit_v12c(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_QPSK_Transmit_v12c(chartInstance);
  sf_debug_check_for_state_inconsistency(_QPSK_Transmit_v12cMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
  cint8_T c3_d_in;
  uint32_T c3_debug_family_var_map[26];
  const mxArray *c3_fm = NULL;
  real_T c3_OS_RATE;
  int16_T c3_f[17];
  cint32_T c3_temp1;
  cint32_T c3_temp2;
  cint32_T c3_temp3;
  cint32_T c3_temp4;
  cint32_T c3_temp5;
  cint32_T c3_temp6;
  cint32_T c3_temp7;
  cint32_T c3_temp8;
  cint32_T c3_temp9;
  cint32_T c3_temp10;
  cint32_T c3_temp11;
  cint32_T c3_temp12;
  cint32_T c3_temp13;
  cint32_T c3_temp14;
  cint32_T c3_temp15;
  cint32_T c3_temp16;
  cint32_T c3_temp17;
  cint64m_T c3_result;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  cint16_T c3_d_out;
  int32_T c3_i2;
  static int16_T c3_iv0[17] = { 109, -95, -194, 337, 274, -880, -332, 3211, 5518,
    3211, -332, -880, 274, 337, -194, -95, 109 };

  int32_T c3_i3;
  int32_T c3_i4;
  cint8_T c3_hoistedGlobal[17];
  int32_T c3_i5;
  cint8_T c3_varargin_1[17];
  int8_T c3_i6;
  cint8_T c3_b_d_in;
  int8_T c3_i7;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_T = NULL;
  const mxArray *c3_F = NULL;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_val = NULL;
  const mxArray *c3_isautoscaled = NULL;
  const mxArray *c3_pvpairsetdata = NULL;
  const mxArray *c3_isfimathlocal = NULL;
  int32_T c3_i8;
  cint8_T c3_ic0;
  cint8_T c3_ic1;
  cint8_T c3_ic2;
  cint8_T c3_ic3;
  cint8_T c3_ic4;
  cint8_T c3_ic5;
  cint8_T c3_ic6;
  cint8_T c3_ic7;
  cint8_T c3_ic8;
  cint8_T c3_ic9;
  cint8_T c3_ic10;
  cint8_T c3_ic11;
  cint8_T c3_ic12;
  cint8_T c3_ic13;
  cint8_T c3_ic14;
  cint8_T c3_ic15;
  cint8_T c3_ic16;
  cint32_T c3_ic17;
  cint32_T c3_ic18;
  cint32_T c3_ic19;
  cint32_T c3_ic20;
  cint32_T c3_ic21;
  cint32_T c3_ic22;
  cint32_T c3_ic23;
  cint32_T c3_ic24;
  cint32_T c3_ic25;
  cint32_T c3_ic26;
  cint32_T c3_ic27;
  cint32_T c3_ic28;
  cint32_T c3_ic29;
  cint32_T c3_ic30;
  cint32_T c3_ic31;
  cint64m_T c3_b_varargin_1;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  int64m_T c3_r0;
  int16_T c3_i9;
  cint16_T c3_c_varargin_1;
  int64m_T c3_r1;
  int16_T c3_i10;
  const mxArray *c3_b_T = NULL;
  const mxArray *c3_b_F = NULL;
  const mxArray *c3_b_ERR = NULL;
  const mxArray *c3_b_val = NULL;
  const mxArray *c3_b_isautoscaled = NULL;
  const mxArray *c3_b_pvpairsetdata = NULL;
  const mxArray *c3_b_isfimathlocal = NULL;
  cint16_T *c3_b_d_out;
  cint8_T *c3_c_d_in;
  c3_b_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_c_d_in = (cint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_d_in.re = c3_c_d_in->re;
  c3_d_in.im = c3_c_d_in->im;
  sf_debug_symbol_scope_push_eml(0U, 26U, 26U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_fm, 0U, c3_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_OS_RATE, 1U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_f, 2U, c3_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp1, 3U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp2, 4U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp3, 5U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp4, 6U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp5, 7U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp6, 8U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp7, 9U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp8, 10U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp9, 11U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp10, 12U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp11, 13U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp12, 14U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp13, 15U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp14, 16U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp15, 17U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp16, 18U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_temp17, 19U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_result, 20U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 21U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 22U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_d_in, 23U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_d_out, 24U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c3_buf, 25U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_fm = c3_eml_mx;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_OS_RATE = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_SRRC(chartInstance);
  for (c3_i2 = 0; c3_i2 < 17; c3_i2++) {
    c3_f[c3_i2] = c3_iv0[c3_i2];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_buf_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    for (c3_i3 = 0; c3_i3 < 17; c3_i3++) {
      chartInstance->c3_buf[c3_i3].re = 0;
      chartInstance->c3_buf[c3_i3].im = 0;
    }

    chartInstance->c3_buf_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i4 = 0; c3_i4 < 17; c3_i4++) {
    c3_hoistedGlobal[c3_i4] = chartInstance->c3_buf[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 16; c3_i5++) {
    c3_varargin_1[c3_i5] = c3_hoistedGlobal[c3_i5 + 1];
  }

  c3_i6 = c3_d_in.re;
  if ((int8_T)(c3_i6 & 4) != 0) {
    c3_b_d_in.re = (int8_T)(c3_i6 | -4);
  } else {
    c3_b_d_in.re = (int8_T)(c3_i6 & 3);
  }

  c3_i7 = c3_d_in.im;
  if ((int8_T)(c3_i7 & 4) != 0) {
    c3_b_d_in.im = (int8_T)(c3_i7 | -4);
  } else {
    c3_b_d_in.im = (int8_T)(c3_i7 & 3);
  }

  c3_varargin_1[16] = c3_b_d_in;
  c3_eml_fi_checkforconst(chartInstance);
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_T);
  sf_mex_destroy(&c3_F);
  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_val);
  sf_mex_destroy(&c3_isautoscaled);
  sf_mex_destroy(&c3_pvpairsetdata);
  sf_mex_destroy(&c3_isfimathlocal);
  for (c3_i8 = 0; c3_i8 < 17; c3_i8++) {
    chartInstance->c3_buf[c3_i8] = c3_varargin_1[c3_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_ic0 = chartInstance->c3_buf[0];
  c3_temp1 = c3_mtimes(chartInstance, c3_ic0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_ic1 = chartInstance->c3_buf[1];
  c3_temp2 = c3_b_mtimes(chartInstance, c3_ic1, -95);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  c3_ic2 = chartInstance->c3_buf[3];
  c3_temp3 = c3_b_mtimes(chartInstance, c3_ic2, -194);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_ic3 = chartInstance->c3_buf[3];
  c3_temp4 = c3_b_mtimes(chartInstance, c3_ic3, 337);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_ic4 = chartInstance->c3_buf[4];
  c3_temp5 = c3_b_mtimes(chartInstance, c3_ic4, 274);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_ic5 = chartInstance->c3_buf[5];
  c3_temp6 = c3_b_mtimes(chartInstance, c3_ic5, -880);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_ic6 = chartInstance->c3_buf[6];
  c3_temp7 = c3_b_mtimes(chartInstance, c3_ic6, -332);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_ic7 = chartInstance->c3_buf[7];
  c3_temp8 = c3_b_mtimes(chartInstance, c3_ic7, 3211);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_ic8 = chartInstance->c3_buf[8];
  c3_temp9 = c3_b_mtimes(chartInstance, c3_ic8, 5518);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_ic9 = chartInstance->c3_buf[9];
  c3_temp10 = c3_b_mtimes(chartInstance, c3_ic9, 3211);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_ic10 = chartInstance->c3_buf[10];
  c3_temp11 = c3_b_mtimes(chartInstance, c3_ic10, -332);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_ic11 = chartInstance->c3_buf[11];
  c3_temp12 = c3_b_mtimes(chartInstance, c3_ic11, -880);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_ic12 = chartInstance->c3_buf[12];
  c3_temp13 = c3_b_mtimes(chartInstance, c3_ic12, 274);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_ic13 = chartInstance->c3_buf[13];
  c3_temp14 = c3_b_mtimes(chartInstance, c3_ic13, 337);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_ic14 = chartInstance->c3_buf[14];
  c3_temp15 = c3_b_mtimes(chartInstance, c3_ic14, -194);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  c3_ic15 = chartInstance->c3_buf[15];
  c3_temp16 = c3_b_mtimes(chartInstance, c3_ic15, -95);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_ic16 = chartInstance->c3_buf[16];
  c3_temp17 = c3_mtimes(chartInstance, c3_ic16);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_ic17 = c3_plus(chartInstance, c3_temp1, c3_temp2);
  c3_ic18 = c3_b_plus(chartInstance, c3_ic17, c3_temp3);
  c3_ic19 = c3_c_plus(chartInstance, c3_ic18, c3_temp4);
  c3_ic20 = c3_d_plus(chartInstance, c3_ic19, c3_temp5);
  c3_ic21 = c3_e_plus(chartInstance, c3_ic20, c3_temp6);
  c3_ic22 = c3_f_plus(chartInstance, c3_ic21, c3_temp7);
  c3_ic23 = c3_g_plus(chartInstance, c3_ic22, c3_temp8);
  c3_ic24 = c3_h_plus(chartInstance, c3_ic23, c3_temp9);
  c3_ic25 = c3_i_plus(chartInstance, c3_ic24, c3_temp10);
  c3_ic26 = c3_j_plus(chartInstance, c3_ic25, c3_temp11);
  c3_ic27 = c3_k_plus(chartInstance, c3_ic26, c3_temp12);
  c3_ic28 = c3_l_plus(chartInstance, c3_ic27, c3_temp13);
  c3_ic29 = c3_m_plus(chartInstance, c3_ic28, c3_temp14);
  c3_ic30 = c3_n_plus(chartInstance, c3_ic29, c3_temp15);
  c3_ic31 = c3_o_plus(chartInstance, c3_ic30, c3_temp16);
  c3_result = c3_p_plus(chartInstance, c3_ic31, c3_temp17);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_b_varargin_1 = c3_result;
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  c3_sMultiWordShr(chartInstance, &c3_b_varargin_1.re.chunks[0U], 2, 3U,
                   &c3_r0.chunks[0U], 2);
  c3_i9 = (int16_T)c3_MultiWord2sLong(chartInstance, &c3_r0.chunks[0U]);
  if ((int16_T)(c3_i9 & 2048) != 0) {
    c3_c_varargin_1.re = (int16_T)(c3_i9 | -2048);
  } else {
    c3_c_varargin_1.re = (int16_T)(c3_i9 & 2047);
  }

  c3_sMultiWordShr(chartInstance, &c3_b_varargin_1.im.chunks[0U], 2, 3U,
                   &c3_r1.chunks[0U], 2);
  c3_i10 = (int16_T)c3_MultiWord2sLong(chartInstance, &c3_r1.chunks[0U]);
  if ((int16_T)(c3_i10 & 2048) != 0) {
    c3_c_varargin_1.im = (int16_T)(c3_i10 | -2048);
  } else {
    c3_c_varargin_1.im = (int16_T)(c3_i10 & 2047);
  }

  c3_d_out = c3_c_varargin_1;
  sf_mex_destroy(&c3_b_T);
  sf_mex_destroy(&c3_b_F);
  sf_mex_destroy(&c3_b_ERR);
  sf_mex_destroy(&c3_b_val);
  sf_mex_destroy(&c3_b_isautoscaled);
  sf_mex_destroy(&c3_b_pvpairsetdata);
  sf_mex_destroy(&c3_b_isfimathlocal);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -32);
  sf_debug_symbol_scope_pop();
  c3_b_d_out->re = c3_d_out.re;
  c3_b_d_out->im = c3_d_out.im;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_QPSK_Transmit_v12c
  (SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/SRRC.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i11;
  cint8_T c3_u[17];
  const mxArray *c3_y = NULL;
  int32_T c3_i12;
  cint8_T c3_b_u[17];
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i11 = 0; c3_i11 < 17; c3_i11++) {
    c3_u[c3_i11] = (*(cint8_T (*)[17])c3_inData)[c3_i11];
  }

  c3_y = NULL;
  if (!chartInstance->c3_buf_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    for (c3_i12 = 0; c3_i12 < 17; c3_i12++) {
      c3_b_u[c3_i12].re = c3_u[c3_i12].re;
      c3_b_u[c3_i12].im = c3_u[c3_i12].im;
    }

    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 2, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
    sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_b_eml_mx), 15,
      "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_b_buf, const char_T *c3_identifier, cint8_T
  c3_y[17])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_buf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_buf);
}

static void c3_b_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  cint8_T c3_y[17])
{
  int32_T c3_i13;
  uint32_T c3_uv0[2];
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  cint8_T c3_icv1[17];
  int32_T c3_i14;
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_uv0[c3_i13] = 1U + ((uint32_T)c3_i13 << 4);
  }

  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_buf_not_empty = FALSE;
  } else {
    chartInstance->c3_buf_not_empty = TRUE;
    sf_mex_check_fi(c3_parentId, c3_u, 1, 2U, c3_uv0, c3_eml_mx, c3_b_eml_mx);
    sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), FALSE);
    sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
                   (c3_mxFi)), FALSE);
    sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), c3_icv1, 1, 2, 1U, 1, 0U, 2,
                  1, 17);
    sf_mex_destroy(&c3_mxFi);
    sf_mex_destroy(&c3_mxInt);
    for (c3_i14 = 0; c3_i14 < 17; c3_i14++) {
      c3_y[c3_i14] = c3_icv1[c3_i14];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_buf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  cint8_T c3_y[17];
  int32_T c3_i15;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_b_buf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_buf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_buf);
  for (c3_i15 = 0; c3_i15 < 17; c3_i15++) {
    (*(cint8_T (*)[17])c3_outData)[c3_i15] = c3_y[c3_i15];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  cint16_T c3_u;
  const mxArray *c3_y = NULL;
  cint16_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(cint16_T *)c3_inData;
  c3_y = NULL;
  c3_b_u.re = c3_u.re;
  c3_b_u.im = c3_u.im;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_c_eml_mx), 15,
    "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static cint16_T c3_c_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  cint16_T c3_y;
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  cint16_T c3_ic32;
  sf_mex_check_fi(c3_parentId, c3_u, 1, 0U, 0, c3_eml_mx, c3_c_eml_mx);
  sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), FALSE);
  sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c3_mxFi)), FALSE);
  sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), &c3_ic32, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c3_mxFi);
  sf_mex_destroy(&c3_mxInt);
  c3_y = c3_ic32;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_d_out;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  cint16_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_d_out = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_out), &c3_thisId);
  sf_mex_destroy(&c3_d_out);
  *(cint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  cint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(cint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_d_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  cint64m_T c3_u;
  const mxArray *c3_y = NULL;
  cint64m_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(cint64m_T *)c3_inData;
  c3_y = NULL;
  c3_b_u.re = c3_u.re;
  c3_b_u.im = c3_u.im;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 7, 1U, 0U, 8U, 1, 2), FALSE);
  sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_d_eml_mx), 15,
    "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static cint64m_T c3_e_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  cint64m_T c3_y;
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  cint64m_T c3_rc0;
  sf_mex_check_fi(c3_parentId, c3_u, 1, 0U, 0, c3_eml_mx, c3_d_eml_mx);
  sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), FALSE);
  sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c3_mxFi)), FALSE);
  sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), &c3_rc0, 1, 7, 1U, 0, 8U, 1,
                2);
  sf_mex_destroy(&c3_mxFi);
  sf_mex_destroy(&c3_mxInt);
  c3_y = c3_rc0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_result;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  cint64m_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_result = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_result), &c3_thisId);
  sf_mex_destroy(&c3_result);
  *(cint64m_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  cint32_T c3_u;
  const mxArray *c3_y = NULL;
  cint32_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(cint32_T *)c3_inData;
  c3_y = NULL;
  c3_b_u.re = c3_u.re;
  c3_b_u.im = c3_u.im;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_e_eml_mx), 15,
    "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static cint32_T c3_f_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  cint32_T c3_y;
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  cint32_T c3_ic33;
  sf_mex_check_fi(c3_parentId, c3_u, 1, 0U, 0, c3_eml_mx, c3_e_eml_mx);
  sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), FALSE);
  sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c3_mxFi)), FALSE);
  sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), &c3_ic33, 1, 6, 1U, 0, 0U, 0);
  sf_mex_destroy(&c3_mxFi);
  sf_mex_destroy(&c3_mxInt);
  c3_y = c3_ic33;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_temp17;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  cint32_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_temp17 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_temp17), &c3_thisId);
  sf_mex_destroy(&c3_temp17);
  *(cint32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i16;
  int16_T c3_u[17];
  const mxArray *c3_y = NULL;
  int32_T c3_i17;
  int16_T c3_b_u[17];
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 17; c3_i16++) {
    c3_u[c3_i16] = (*(int16_T (*)[17])c3_inData)[c3_i16];
  }

  c3_y = NULL;
  for (c3_i17 = 0; c3_i17 < 17; c3_i17++) {
    c3_b_u[c3_i17] = c3_u[c3_i17];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 4, 0U, 1U, 0U, 1, 17), FALSE);
  sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_f_eml_mx), 15,
    "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  const mxArray *c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = sf_mex_dup(*(const mxArray **)c3_inData);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), FALSE);
  sf_mex_destroy(&c3_u);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i18;
  real_T c3_b_inData[17];
  int32_T c3_i19;
  real_T c3_u[17];
  const mxArray *c3_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i18 = 0; c3_i18 < 17; c3_i18++) {
    c3_b_inData[c3_i18] = (*(real_T (*)[17])c3_inData)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 17; c3_i19++) {
    c3_u[c3_i19] = c3_b_inData[c3_i19];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 17), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[17])
{
  real_T c3_dv0[17];
  int32_T c3_i20;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 1, 17);
  for (c3_i20 = 0; c3_i20 < 17; c3_i20++) {
    c3_y[c3_i20] = c3_dv0[c3_i20];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[17];
  int32_T c3_i21;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
  for (c3_i21 = 0; c3_i21 < 17; c3_i21++) {
    (*(real_T (*)[17])c3_outData)[c3_i21] = c3_b_y[c3_i21];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_QPSK_Transmit_v12c_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[73];
  c3_ResolvedFunctionInfo (*c3_b_info)[73];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i22;
  c3_ResolvedFunctionInfo *c3_r2;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  c3_b_info = (c3_ResolvedFunctionInfo (*)[73])c3_info;
  (*c3_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  (*c3_b_info)[64].name = "eml_fixpt_times";
  (*c3_b_info)[64].dominantType = "embedded.fi";
  (*c3_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m";
  (*c3_b_info)[64].fileTimeLo = 1289552046U;
  (*c3_b_info)[64].fileTimeHi = 0U;
  (*c3_b_info)[64].mFileTimeLo = 0U;
  (*c3_b_info)[64].mFileTimeHi = 0U;
  (*c3_b_info)[65].context = "";
  (*c3_b_info)[65].name = "plus";
  (*c3_b_info)[65].dominantType = "embedded.fi";
  (*c3_b_info)[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[65].fileTimeLo = 1330640836U;
  (*c3_b_info)[65].fileTimeHi = 0U;
  (*c3_b_info)[65].mFileTimeLo = 0U;
  (*c3_b_info)[65].mFileTimeHi = 0U;
  (*c3_b_info)[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[66].name = "eml_scalexp_compatible";
  (*c3_b_info)[66].dominantType = "embedded.fi";
  (*c3_b_info)[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c3_b_info)[66].fileTimeLo = 1286851196U;
  (*c3_b_info)[66].fileTimeHi = 0U;
  (*c3_b_info)[66].mFileTimeLo = 0U;
  (*c3_b_info)[66].mFileTimeHi = 0U;
  (*c3_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[67].name = "isfi";
  (*c3_b_info)[67].dominantType = "embedded.fi";
  (*c3_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  (*c3_b_info)[67].fileTimeLo = 1289552010U;
  (*c3_b_info)[67].fileTimeHi = 0U;
  (*c3_b_info)[67].mFileTimeLo = 0U;
  (*c3_b_info)[67].mFileTimeHi = 0U;
  (*c3_b_info)[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[68].name = "isscaledtype";
  (*c3_b_info)[68].dominantType = "embedded.fi";
  (*c3_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m";
  (*c3_b_info)[68].fileTimeLo = 1289552066U;
  (*c3_b_info)[68].fileTimeHi = 0U;
  (*c3_b_info)[68].mFileTimeLo = 0U;
  (*c3_b_info)[68].mFileTimeHi = 0U;
  (*c3_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[69].name = "eml_checkfimathforbinaryops";
  (*c3_b_info)[69].dominantType = "embedded.fi";
  (*c3_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m";
  (*c3_b_info)[69].fileTimeLo = 1340245106U;
  (*c3_b_info)[69].fileTimeHi = 0U;
  (*c3_b_info)[69].mFileTimeLo = 0U;
  (*c3_b_info)[69].mFileTimeHi = 0U;
  (*c3_b_info)[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[70].name = "get";
  (*c3_b_info)[70].dominantType = "embedded.numerictype";
  (*c3_b_info)[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  (*c3_b_info)[70].fileTimeLo = 1289551964U;
  (*c3_b_info)[70].fileTimeHi = 0U;
  (*c3_b_info)[70].mFileTimeLo = 0U;
  (*c3_b_info)[70].mFileTimeHi = 0U;
  (*c3_b_info)[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[71].name = "get";
  (*c3_b_info)[71].dominantType = "embedded.fimath";
  (*c3_b_info)[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m";
  (*c3_b_info)[71].fileTimeLo = 1289551966U;
  (*c3_b_info)[71].fileTimeHi = 0U;
  (*c3_b_info)[71].mFileTimeLo = 0U;
  (*c3_b_info)[71].mFileTimeHi = 0U;
  (*c3_b_info)[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m";
  (*c3_b_info)[72].name = "strcmpi";
  (*c3_b_info)[72].dominantType = "char";
  (*c3_b_info)[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  (*c3_b_info)[72].fileTimeLo = 1327451510U;
  (*c3_b_info)[72].fileTimeHi = 0U;
  (*c3_b_info)[72].mFileTimeLo = 0U;
  (*c3_b_info)[72].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 73), FALSE);
  for (c3_i22 = 0; c3_i22 < 73; c3_i22++) {
    c3_r2 = &c3_info[c3_i22];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r2->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r2->context)), "context", "nameCaptureInfo",
                    c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r2->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r2->name)), "name", "nameCaptureInfo", c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r2->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r2->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r2->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r2->resolved)), "resolved", "nameCaptureInfo",
                    c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r2->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r2->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r2->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i22);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r2->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i22);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[73])
{
  c3_info[0].context = "";
  c3_info[0].name = "hdlfimath";
  c3_info[0].dominantType = "";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c3_info[0].fileTimeLo = 1289552008U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c3_info[1].name = "fimath";
  c3_info[1].dominantType = "char";
  c3_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fimath.m";
  c3_info[1].fileTimeLo = 1289552004U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "SRRC";
  c3_info[2].dominantType = "";
  c3_info[2].resolved =
    "[E]C:/Users/castone/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/SRRC.m";
  c3_info[2].fileTimeLo = 1366660138U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "fi_impl";
  c3_info[3].dominantType = "";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m";
  c3_info[3].fileTimeLo = 1326760396U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[4].name = "length";
  c3_info[4].dominantType = "cell";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[4].fileTimeLo = 1303178606U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[5].name = "eml_fi_checkforconst";
  c3_info[5].dominantType = "embedded.fimath";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforconst.m";
  c3_info[5].fileTimeLo = 1326760394U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[6].name = "isfi";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[6].fileTimeLo = 1289552010U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[7].name = "isnumerictype";
  c3_info[7].dominantType = "char";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c3_info[7].fileTimeLo = 1289552012U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c3_info[8].name = "isfi";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[8].fileTimeLo = 1289552010U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[9].name = "eml_fi_checkforntype";
  c3_info[9].dominantType = "embedded.numerictype";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforntype.m";
  c3_info[9].fileTimeLo = 1289552002U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "mtimes";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].fileTimeLo = 1289552092U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[11].name = "isfi";
  c3_info[11].dominantType = "embedded.fi";
  c3_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[11].fileTimeLo = 1289552010U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[12].name = "isnumerictype";
  c3_info[12].dominantType = "embedded.numerictype";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c3_info[12].fileTimeLo = 1289552012U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[13].name = "isfloat";
  c3_info[13].dominantType = "embedded.fi";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c3_info[13].fileTimeLo = 1336554498U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c3_info[14].name = "get";
  c3_info[14].dominantType = "embedded.numerictype";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c3_info[14].fileTimeLo = 1289551964U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c3_info[15].name = "isfi";
  c3_info[15].dominantType = "embedded.fi";
  c3_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[15].fileTimeLo = 1289552010U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c3_info[16].name = "numerictype";
  c3_info[16].dominantType = "embedded.fi";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/numerictype.m";
  c3_info[16].fileTimeLo = 1289552076U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c3_info[17].name = "fimath";
  c3_info[17].dominantType = "embedded.fi";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/fimath.m";
  c3_info[17].fileTimeLo = 1289552054U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c3_info[18].name = "eml_fi_checkforntype";
  c3_info[18].dominantType = "embedded.fi";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforntype.m";
  c3_info[18].fileTimeLo = 1289552002U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "mtimes";
  c3_info[19].dominantType = "embedded.fi";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c3_info[19].fileTimeLo = 1330640836U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c3_info[20].name = "isfi";
  c3_info[20].dominantType = "embedded.fi";
  c3_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[20].fileTimeLo = 1289552010U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c3_info[21].name = "get";
  c3_info[21].dominantType = "embedded.numerictype";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c3_info[21].fileTimeLo = 1289551964U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m";
  c3_info[22].name = "times";
  c3_info[22].dominantType = "embedded.fi";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[22].fileTimeLo = 1330640836U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[23].name = "eml_scalexp_compatible";
  c3_info[23].dominantType = "embedded.fi";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[23].fileTimeLo = 1286851196U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[24].name = "isfi";
  c3_info[24].dominantType = "embedded.fi";
  c3_info[24].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c3_info[24].fileTimeLo = 1289552010U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[25].name = "isscaledtype";
  c3_info[25].dominantType = "embedded.fi";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m";
  c3_info[25].fileTimeLo = 1289552066U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m";
  c3_info[26].name = "isfixed";
  c3_info[26].dominantType = "embedded.fi";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c3_info[26].fileTimeLo = 1336554498U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c3_info[27].name = "get";
  c3_info[27].dominantType = "embedded.numerictype";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c3_info[27].fileTimeLo = 1289551964U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[28].name = "eml_checkfimathforbinaryops";
  c3_info[28].dominantType = "embedded.fi";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m";
  c3_info[28].fileTimeLo = 1340245106U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m";
  c3_info[29].name = "isFimathEqualForCodeGen";
  c3_info[29].dominantType = "embedded.fimath";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isFimathEqualForCodeGen.m";
  c3_info[29].fileTimeLo = 1340245106U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[30].name = "get";
  c3_info[30].dominantType = "embedded.numerictype";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c3_info[30].fileTimeLo = 1289551964U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[31].name = "get";
  c3_info[31].dominantType = "embedded.fimath";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m";
  c3_info[31].fileTimeLo = 1289551966U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m";
  c3_info[32].name = "strcmpi";
  c3_info[32].dominantType = "char";
  c3_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c3_info[32].fileTimeLo = 1327451510U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c3_info[33].name = "eml_assert_supported_string";
  c3_info[33].dominantType = "char";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c3_info[33].fileTimeLo = 1327451510U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c3_info[34].name = "eml_charmax";
  c3_info[34].dominantType = "";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c3_info[34].fileTimeLo = 1327451510U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c3_info[35].name = "intmax";
  c3_info[35].dominantType = "char";
  c3_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[35].fileTimeLo = 1311287716U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange";
  c3_info[36].name = "eml_charmax";
  c3_info[36].dominantType = "";
  c3_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c3_info[36].fileTimeLo = 1327451510U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c3_info[37].name = "min";
  c3_info[37].dominantType = "double";
  c3_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[37].fileTimeLo = 1311287718U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[38].name = "eml_min_or_max";
  c3_info[38].dominantType = "char";
  c3_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[38].fileTimeLo = 1334103890U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[39].name = "eml_scalar_eg";
  c3_info[39].dominantType = "double";
  c3_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[39].fileTimeLo = 1286851196U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[40].name = "eml_scalexp_alloc";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[40].fileTimeLo = 1330640834U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[41].name = "eml_index_class";
  c3_info[41].dominantType = "";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[41].fileTimeLo = 1323202978U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[42].name = "eml_scalar_eg";
  c3_info[42].dominantType = "double";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[42].fileTimeLo = 1286851196U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m";
  c3_info[43].name = "lower";
  c3_info[43].dominantType = "char";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m";
  c3_info[43].fileTimeLo = 1327451510U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m";
  c3_info[44].name = "eml_string_transform";
  c3_info[44].dominantType = "char";
  c3_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c3_info[44].fileTimeLo = 1327451510U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c3_info[45].name = "eml_assert_supported_string";
  c3_info[45].dominantType = "char";
  c3_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m";
  c3_info[45].fileTimeLo = 1327451510U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c3_info[46].name = "eml_charmax";
  c3_info[46].dominantType = "";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m";
  c3_info[46].fileTimeLo = 1327451510U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c3_info[47].name = "colon";
  c3_info[47].dominantType = "int8";
  c3_info[47].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[47].fileTimeLo = 1311287718U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[48].name = "floor";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[48].fileTimeLo = 1286851142U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[49].name = "eml_scalar_floor";
  c3_info[49].dominantType = "double";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[49].fileTimeLo = 1286851126U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c3_info[50].name = "intmin";
  c3_info[50].dominantType = "char";
  c3_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[50].fileTimeLo = 1311287718U;
  c3_info[50].fileTimeHi = 0U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c3_info[51].name = "intmax";
  c3_info[51].dominantType = "char";
  c3_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[51].fileTimeLo = 1311287716U;
  c3_info[51].fileTimeHi = 0U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c3_info[52].name = "intmin";
  c3_info[52].dominantType = "char";
  c3_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[52].fileTimeLo = 1311287718U;
  c3_info[52].fileTimeHi = 0U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c3_info[53].name = "intmax";
  c3_info[53].dominantType = "char";
  c3_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[53].fileTimeLo = 1311287716U;
  c3_info[53].fileTimeHi = 0U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
  c3_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c3_info[54].name = "eml_isa_uint";
  c3_info[54].dominantType = "int8";
  c3_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c3_info[54].fileTimeLo = 1286851184U;
  c3_info[54].fileTimeHi = 0U;
  c3_info[54].mFileTimeLo = 0U;
  c3_info[54].mFileTimeHi = 0U;
  c3_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c3_info[55].name = "eml_unsigned_class";
  c3_info[55].dominantType = "char";
  c3_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c3_info[55].fileTimeLo = 1323202980U;
  c3_info[55].fileTimeHi = 0U;
  c3_info[55].mFileTimeLo = 0U;
  c3_info[55].mFileTimeHi = 0U;
  c3_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c3_info[56].name = "eml_index_class";
  c3_info[56].dominantType = "";
  c3_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[56].fileTimeLo = 1323202978U;
  c3_info[56].fileTimeHi = 0U;
  c3_info[56].mFileTimeLo = 0U;
  c3_info[56].mFileTimeHi = 0U;
  c3_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c3_info[57].name = "intmax";
  c3_info[57].dominantType = "char";
  c3_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[57].fileTimeLo = 1311287716U;
  c3_info[57].fileTimeHi = 0U;
  c3_info[57].mFileTimeLo = 0U;
  c3_info[57].mFileTimeHi = 0U;
  c3_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c3_info[58].name = "eml_isa_uint";
  c3_info[58].dominantType = "int8";
  c3_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c3_info[58].fileTimeLo = 1286851184U;
  c3_info[58].fileTimeHi = 0U;
  c3_info[58].mFileTimeLo = 0U;
  c3_info[58].mFileTimeHi = 0U;
  c3_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c3_info[59].name = "eml_index_plus";
  c3_info[59].dominantType = "double";
  c3_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[59].fileTimeLo = 1286851178U;
  c3_info[59].fileTimeHi = 0U;
  c3_info[59].mFileTimeLo = 0U;
  c3_info[59].mFileTimeHi = 0U;
  c3_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[60].name = "eml_index_class";
  c3_info[60].dominantType = "";
  c3_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[60].fileTimeLo = 1323202978U;
  c3_info[60].fileTimeHi = 0U;
  c3_info[60].mFileTimeLo = 0U;
  c3_info[60].mFileTimeHi = 0U;
  c3_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c3_info[61].name = "eml_int_forloop_overflow_check";
  c3_info[61].dominantType = "";
  c3_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[61].fileTimeLo = 1332197472U;
  c3_info[61].fileTimeHi = 0U;
  c3_info[61].mFileTimeLo = 0U;
  c3_info[61].mFileTimeHi = 0U;
  c3_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[62].name = "intmax";
  c3_info[62].dominantType = "char";
  c3_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[62].fileTimeLo = 1311287716U;
  c3_info[62].fileTimeHi = 0U;
  c3_info[62].mFileTimeLo = 0U;
  c3_info[62].mFileTimeHi = 0U;
  c3_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m";
  c3_info[63].name = "char";
  c3_info[63].dominantType = "int8";
  c3_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c3_info[63].fileTimeLo = 1319762368U;
  c3_info[63].fileTimeHi = 0U;
  c3_info[63].mFileTimeLo = 0U;
  c3_info[63].mFileTimeHi = 0U;
}

static void c3_SRRC(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_y[17];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i23;
  static real_T c3_dv1[17] = { 0.006690562067, -0.00576859381, -0.011827354519,
    0.020586915021, 0.016726405168, -0.053692342207, -0.020253031546,
    0.196043589067, 0.33682241319, 0.196043589067, -0.020253031546,
    -0.053692342207, 0.016726405168, 0.020586915021, -0.011827354519,
    -0.00576859381, 0.006690562067 };

  sf_debug_symbol_scope_push_eml(0U, 3U, 3U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c3_y, 0U, c3_i_sf_marshallOut,
    c3_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 1U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 2U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i23 = 0; c3_i23 < 17; c3_i23++) {
    c3_y[c3_i23] = c3_dv1[c3_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -3);
  sf_debug_symbol_scope_pop();
}

static void c3_eml_fi_checkforconst(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance)
{
}

static cint32_T c3_mtimes(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint8_T c3_a0)
{
  cint32_T c3_cout;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  const mxArray *c3_j_propVal = NULL;
  const mxArray *c3_j_errmsg = NULL;
  const mxArray *c3_k_propVal = NULL;
  const mxArray *c3_k_errmsg = NULL;
  int8_T c3_ar;
  int8_T c3_ai;
  int32_T c3_i24;
  int32_T c3_cr;
  int32_T c3_i25;
  int32_T c3_ci;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tp = NULL;
  const mxArray *c3_errmsg1 = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_errmsg2 = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  sf_mex_destroy(&c3_j_propVal);
  sf_mex_destroy(&c3_j_errmsg);
  sf_mex_destroy(&c3_k_propVal);
  sf_mex_destroy(&c3_k_errmsg);
  c3_ar = c3_a0.re;
  c3_ai = c3_a0.im;
  c3_i24 = c3_ar * 109;
  if ((c3_i24 & 65536) != 0) {
    c3_cr = c3_i24 | -65536;
  } else {
    c3_cr = c3_i24 & 65535;
  }

  c3_i25 = c3_ai * 109;
  if ((c3_i25 & 65536) != 0) {
    c3_ci = c3_i25 | -65536;
  } else {
    c3_ci = c3_i25 & 65535;
  }

  c3_cout.re = c3_cr;
  c3_cout.im = c3_ci;
  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tp);
  sf_mex_destroy(&c3_errmsg1);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_errmsg2);
  return c3_cout;
}

static cint32_T c3_b_mtimes(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint8_T c3_a0, int16_T c3_b0)
{
  cint32_T c3_cout;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  int16_T c3_b_b0;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  int16_T c3_b;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  const mxArray *c3_j_propVal = NULL;
  const mxArray *c3_j_errmsg = NULL;
  const mxArray *c3_k_propVal = NULL;
  const mxArray *c3_k_errmsg = NULL;
  int16_T c3_b_b;
  int8_T c3_ar;
  int8_T c3_ai;
  int32_T c3_i26;
  int32_T c3_cr;
  int32_T c3_i27;
  int32_T c3_ci;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tp = NULL;
  const mxArray *c3_errmsg1 = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_errmsg2 = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  c3_b_b0 = c3_b0;
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  c3_b = c3_b_b0;
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  sf_mex_destroy(&c3_j_propVal);
  sf_mex_destroy(&c3_j_errmsg);
  sf_mex_destroy(&c3_k_propVal);
  sf_mex_destroy(&c3_k_errmsg);
  c3_b_b = c3_b;
  c3_ar = c3_a0.re;
  c3_ai = c3_a0.im;
  c3_i26 = c3_ar * c3_b_b;
  if ((c3_i26 & 65536) != 0) {
    c3_cr = c3_i26 | -65536;
  } else {
    c3_cr = c3_i26 & 65535;
  }

  c3_i27 = c3_ai * c3_b_b;
  if ((c3_i27 & 65536) != 0) {
    c3_ci = c3_i27 | -65536;
  } else {
    c3_ci = c3_i27 & 65535;
  }

  c3_cout.re = c3_cr;
  c3_cout.im = c3_ci;
  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tp);
  sf_mex_destroy(&c3_errmsg1);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_errmsg2);
  return c3_cout;
}

static cint32_T c3_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i28;
  cint32_T c3_b_a0;
  int32_T c3_i29;
  int32_T c3_i30;
  cint32_T c3_b_b0;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i28 = c3_a0.re;
  if ((c3_i28 & 131072) != 0) {
    c3_b_a0.re = c3_i28 | -131072;
  } else {
    c3_b_a0.re = c3_i28 & 131071;
  }

  c3_i29 = c3_a0.im;
  if ((c3_i29 & 131072) != 0) {
    c3_b_a0.im = c3_i29 | -131072;
  } else {
    c3_b_a0.im = c3_i29 & 131071;
  }

  c3_i30 = c3_b0.re;
  if ((c3_i30 & 131072) != 0) {
    c3_b_b0.re = c3_i30 | -131072;
  } else {
    c3_b_b0.re = c3_i30 & 131071;
  }

  c3_i31 = c3_b0.im;
  if ((c3_i31 & 131072) != 0) {
    c3_b_b0.im = c3_i31 | -131072;
  } else {
    c3_b_b0.im = c3_i31 & 131071;
  }

  c3_i32 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i32 & 131072) != 0) {
    c3_c.re = c3_i32 | -131072;
  } else {
    c3_c.re = c3_i32 & 131071;
  }

  c3_i33 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i33 & 131072) != 0) {
    c3_c.im = c3_i33 | -131072;
  } else {
    c3_c.im = c3_i33 & 131071;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_b_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i34;
  cint32_T c3_b_a0;
  int32_T c3_i35;
  int32_T c3_i36;
  cint32_T c3_b_b0;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i34 = c3_a0.re;
  if ((c3_i34 & 262144) != 0) {
    c3_b_a0.re = c3_i34 | -262144;
  } else {
    c3_b_a0.re = c3_i34 & 262143;
  }

  c3_i35 = c3_a0.im;
  if ((c3_i35 & 262144) != 0) {
    c3_b_a0.im = c3_i35 | -262144;
  } else {
    c3_b_a0.im = c3_i35 & 262143;
  }

  c3_i36 = c3_b0.re;
  if ((c3_i36 & 262144) != 0) {
    c3_b_b0.re = c3_i36 | -262144;
  } else {
    c3_b_b0.re = c3_i36 & 262143;
  }

  c3_i37 = c3_b0.im;
  if ((c3_i37 & 262144) != 0) {
    c3_b_b0.im = c3_i37 | -262144;
  } else {
    c3_b_b0.im = c3_i37 & 262143;
  }

  c3_i38 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i38 & 262144) != 0) {
    c3_c.re = c3_i38 | -262144;
  } else {
    c3_c.re = c3_i38 & 262143;
  }

  c3_i39 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i39 & 262144) != 0) {
    c3_c.im = c3_i39 | -262144;
  } else {
    c3_c.im = c3_i39 & 262143;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_c_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i40;
  cint32_T c3_b_a0;
  int32_T c3_i41;
  int32_T c3_i42;
  cint32_T c3_b_b0;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i40 = c3_a0.re;
  if ((c3_i40 & 524288) != 0) {
    c3_b_a0.re = c3_i40 | -524288;
  } else {
    c3_b_a0.re = c3_i40 & 524287;
  }

  c3_i41 = c3_a0.im;
  if ((c3_i41 & 524288) != 0) {
    c3_b_a0.im = c3_i41 | -524288;
  } else {
    c3_b_a0.im = c3_i41 & 524287;
  }

  c3_i42 = c3_b0.re;
  if ((c3_i42 & 524288) != 0) {
    c3_b_b0.re = c3_i42 | -524288;
  } else {
    c3_b_b0.re = c3_i42 & 524287;
  }

  c3_i43 = c3_b0.im;
  if ((c3_i43 & 524288) != 0) {
    c3_b_b0.im = c3_i43 | -524288;
  } else {
    c3_b_b0.im = c3_i43 & 524287;
  }

  c3_i44 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i44 & 524288) != 0) {
    c3_c.re = c3_i44 | -524288;
  } else {
    c3_c.re = c3_i44 & 524287;
  }

  c3_i45 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i45 & 524288) != 0) {
    c3_c.im = c3_i45 | -524288;
  } else {
    c3_c.im = c3_i45 & 524287;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_d_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i46;
  cint32_T c3_b_a0;
  int32_T c3_i47;
  int32_T c3_i48;
  cint32_T c3_b_b0;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i46 = c3_a0.re;
  if ((c3_i46 & 1048576) != 0) {
    c3_b_a0.re = c3_i46 | -1048576;
  } else {
    c3_b_a0.re = c3_i46 & 1048575;
  }

  c3_i47 = c3_a0.im;
  if ((c3_i47 & 1048576) != 0) {
    c3_b_a0.im = c3_i47 | -1048576;
  } else {
    c3_b_a0.im = c3_i47 & 1048575;
  }

  c3_i48 = c3_b0.re;
  if ((c3_i48 & 1048576) != 0) {
    c3_b_b0.re = c3_i48 | -1048576;
  } else {
    c3_b_b0.re = c3_i48 & 1048575;
  }

  c3_i49 = c3_b0.im;
  if ((c3_i49 & 1048576) != 0) {
    c3_b_b0.im = c3_i49 | -1048576;
  } else {
    c3_b_b0.im = c3_i49 & 1048575;
  }

  c3_i50 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i50 & 1048576) != 0) {
    c3_c.re = c3_i50 | -1048576;
  } else {
    c3_c.re = c3_i50 & 1048575;
  }

  c3_i51 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i51 & 1048576) != 0) {
    c3_c.im = c3_i51 | -1048576;
  } else {
    c3_c.im = c3_i51 & 1048575;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_e_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i52;
  cint32_T c3_b_a0;
  int32_T c3_i53;
  int32_T c3_i54;
  cint32_T c3_b_b0;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i52 = c3_a0.re;
  if ((c3_i52 & 2097152) != 0) {
    c3_b_a0.re = c3_i52 | -2097152;
  } else {
    c3_b_a0.re = c3_i52 & 2097151;
  }

  c3_i53 = c3_a0.im;
  if ((c3_i53 & 2097152) != 0) {
    c3_b_a0.im = c3_i53 | -2097152;
  } else {
    c3_b_a0.im = c3_i53 & 2097151;
  }

  c3_i54 = c3_b0.re;
  if ((c3_i54 & 2097152) != 0) {
    c3_b_b0.re = c3_i54 | -2097152;
  } else {
    c3_b_b0.re = c3_i54 & 2097151;
  }

  c3_i55 = c3_b0.im;
  if ((c3_i55 & 2097152) != 0) {
    c3_b_b0.im = c3_i55 | -2097152;
  } else {
    c3_b_b0.im = c3_i55 & 2097151;
  }

  c3_i56 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i56 & 2097152) != 0) {
    c3_c.re = c3_i56 | -2097152;
  } else {
    c3_c.re = c3_i56 & 2097151;
  }

  c3_i57 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i57 & 2097152) != 0) {
    c3_c.im = c3_i57 | -2097152;
  } else {
    c3_c.im = c3_i57 & 2097151;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_f_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i58;
  cint32_T c3_b_a0;
  int32_T c3_i59;
  int32_T c3_i60;
  cint32_T c3_b_b0;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i58 = c3_a0.re;
  if ((c3_i58 & 4194304) != 0) {
    c3_b_a0.re = c3_i58 | -4194304;
  } else {
    c3_b_a0.re = c3_i58 & 4194303;
  }

  c3_i59 = c3_a0.im;
  if ((c3_i59 & 4194304) != 0) {
    c3_b_a0.im = c3_i59 | -4194304;
  } else {
    c3_b_a0.im = c3_i59 & 4194303;
  }

  c3_i60 = c3_b0.re;
  if ((c3_i60 & 4194304) != 0) {
    c3_b_b0.re = c3_i60 | -4194304;
  } else {
    c3_b_b0.re = c3_i60 & 4194303;
  }

  c3_i61 = c3_b0.im;
  if ((c3_i61 & 4194304) != 0) {
    c3_b_b0.im = c3_i61 | -4194304;
  } else {
    c3_b_b0.im = c3_i61 & 4194303;
  }

  c3_i62 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i62 & 4194304) != 0) {
    c3_c.re = c3_i62 | -4194304;
  } else {
    c3_c.re = c3_i62 & 4194303;
  }

  c3_i63 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i63 & 4194304) != 0) {
    c3_c.im = c3_i63 | -4194304;
  } else {
    c3_c.im = c3_i63 & 4194303;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_g_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i64;
  cint32_T c3_b_a0;
  int32_T c3_i65;
  int32_T c3_i66;
  cint32_T c3_b_b0;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i64 = c3_a0.re;
  if ((c3_i64 & 8388608) != 0) {
    c3_b_a0.re = c3_i64 | -8388608;
  } else {
    c3_b_a0.re = c3_i64 & 8388607;
  }

  c3_i65 = c3_a0.im;
  if ((c3_i65 & 8388608) != 0) {
    c3_b_a0.im = c3_i65 | -8388608;
  } else {
    c3_b_a0.im = c3_i65 & 8388607;
  }

  c3_i66 = c3_b0.re;
  if ((c3_i66 & 8388608) != 0) {
    c3_b_b0.re = c3_i66 | -8388608;
  } else {
    c3_b_b0.re = c3_i66 & 8388607;
  }

  c3_i67 = c3_b0.im;
  if ((c3_i67 & 8388608) != 0) {
    c3_b_b0.im = c3_i67 | -8388608;
  } else {
    c3_b_b0.im = c3_i67 & 8388607;
  }

  c3_i68 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i68 & 8388608) != 0) {
    c3_c.re = c3_i68 | -8388608;
  } else {
    c3_c.re = c3_i68 & 8388607;
  }

  c3_i69 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i69 & 8388608) != 0) {
    c3_c.im = c3_i69 | -8388608;
  } else {
    c3_c.im = c3_i69 & 8388607;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_h_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i70;
  cint32_T c3_b_a0;
  int32_T c3_i71;
  int32_T c3_i72;
  cint32_T c3_b_b0;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i70 = c3_a0.re;
  if ((c3_i70 & 16777216) != 0) {
    c3_b_a0.re = c3_i70 | -16777216;
  } else {
    c3_b_a0.re = c3_i70 & 16777215;
  }

  c3_i71 = c3_a0.im;
  if ((c3_i71 & 16777216) != 0) {
    c3_b_a0.im = c3_i71 | -16777216;
  } else {
    c3_b_a0.im = c3_i71 & 16777215;
  }

  c3_i72 = c3_b0.re;
  if ((c3_i72 & 16777216) != 0) {
    c3_b_b0.re = c3_i72 | -16777216;
  } else {
    c3_b_b0.re = c3_i72 & 16777215;
  }

  c3_i73 = c3_b0.im;
  if ((c3_i73 & 16777216) != 0) {
    c3_b_b0.im = c3_i73 | -16777216;
  } else {
    c3_b_b0.im = c3_i73 & 16777215;
  }

  c3_i74 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i74 & 16777216) != 0) {
    c3_c.re = c3_i74 | -16777216;
  } else {
    c3_c.re = c3_i74 & 16777215;
  }

  c3_i75 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i75 & 16777216) != 0) {
    c3_c.im = c3_i75 | -16777216;
  } else {
    c3_c.im = c3_i75 & 16777215;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_i_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i76;
  cint32_T c3_b_a0;
  int32_T c3_i77;
  int32_T c3_i78;
  cint32_T c3_b_b0;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i76 = c3_a0.re;
  if ((c3_i76 & 33554432) != 0) {
    c3_b_a0.re = c3_i76 | -33554432;
  } else {
    c3_b_a0.re = c3_i76 & 33554431;
  }

  c3_i77 = c3_a0.im;
  if ((c3_i77 & 33554432) != 0) {
    c3_b_a0.im = c3_i77 | -33554432;
  } else {
    c3_b_a0.im = c3_i77 & 33554431;
  }

  c3_i78 = c3_b0.re;
  if ((c3_i78 & 33554432) != 0) {
    c3_b_b0.re = c3_i78 | -33554432;
  } else {
    c3_b_b0.re = c3_i78 & 33554431;
  }

  c3_i79 = c3_b0.im;
  if ((c3_i79 & 33554432) != 0) {
    c3_b_b0.im = c3_i79 | -33554432;
  } else {
    c3_b_b0.im = c3_i79 & 33554431;
  }

  c3_i80 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i80 & 33554432) != 0) {
    c3_c.re = c3_i80 | -33554432;
  } else {
    c3_c.re = c3_i80 & 33554431;
  }

  c3_i81 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i81 & 33554432) != 0) {
    c3_c.im = c3_i81 | -33554432;
  } else {
    c3_c.im = c3_i81 & 33554431;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_j_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i82;
  cint32_T c3_b_a0;
  int32_T c3_i83;
  int32_T c3_i84;
  cint32_T c3_b_b0;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i82 = c3_a0.re;
  if ((c3_i82 & 67108864) != 0) {
    c3_b_a0.re = c3_i82 | -67108864;
  } else {
    c3_b_a0.re = c3_i82 & 67108863;
  }

  c3_i83 = c3_a0.im;
  if ((c3_i83 & 67108864) != 0) {
    c3_b_a0.im = c3_i83 | -67108864;
  } else {
    c3_b_a0.im = c3_i83 & 67108863;
  }

  c3_i84 = c3_b0.re;
  if ((c3_i84 & 67108864) != 0) {
    c3_b_b0.re = c3_i84 | -67108864;
  } else {
    c3_b_b0.re = c3_i84 & 67108863;
  }

  c3_i85 = c3_b0.im;
  if ((c3_i85 & 67108864) != 0) {
    c3_b_b0.im = c3_i85 | -67108864;
  } else {
    c3_b_b0.im = c3_i85 & 67108863;
  }

  c3_i86 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i86 & 67108864) != 0) {
    c3_c.re = c3_i86 | -67108864;
  } else {
    c3_c.re = c3_i86 & 67108863;
  }

  c3_i87 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i87 & 67108864) != 0) {
    c3_c.im = c3_i87 | -67108864;
  } else {
    c3_c.im = c3_i87 & 67108863;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_k_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i88;
  cint32_T c3_b_a0;
  int32_T c3_i89;
  int32_T c3_i90;
  cint32_T c3_b_b0;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i88 = c3_a0.re;
  if ((c3_i88 & 134217728) != 0) {
    c3_b_a0.re = c3_i88 | -134217728;
  } else {
    c3_b_a0.re = c3_i88 & 134217727;
  }

  c3_i89 = c3_a0.im;
  if ((c3_i89 & 134217728) != 0) {
    c3_b_a0.im = c3_i89 | -134217728;
  } else {
    c3_b_a0.im = c3_i89 & 134217727;
  }

  c3_i90 = c3_b0.re;
  if ((c3_i90 & 134217728) != 0) {
    c3_b_b0.re = c3_i90 | -134217728;
  } else {
    c3_b_b0.re = c3_i90 & 134217727;
  }

  c3_i91 = c3_b0.im;
  if ((c3_i91 & 134217728) != 0) {
    c3_b_b0.im = c3_i91 | -134217728;
  } else {
    c3_b_b0.im = c3_i91 & 134217727;
  }

  c3_i92 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i92 & 134217728) != 0) {
    c3_c.re = c3_i92 | -134217728;
  } else {
    c3_c.re = c3_i92 & 134217727;
  }

  c3_i93 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i93 & 134217728) != 0) {
    c3_c.im = c3_i93 | -134217728;
  } else {
    c3_c.im = c3_i93 & 134217727;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_l_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i94;
  cint32_T c3_b_a0;
  int32_T c3_i95;
  int32_T c3_i96;
  cint32_T c3_b_b0;
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i94 = c3_a0.re;
  if ((c3_i94 & 268435456) != 0) {
    c3_b_a0.re = c3_i94 | -268435456;
  } else {
    c3_b_a0.re = c3_i94 & 268435455;
  }

  c3_i95 = c3_a0.im;
  if ((c3_i95 & 268435456) != 0) {
    c3_b_a0.im = c3_i95 | -268435456;
  } else {
    c3_b_a0.im = c3_i95 & 268435455;
  }

  c3_i96 = c3_b0.re;
  if ((c3_i96 & 268435456) != 0) {
    c3_b_b0.re = c3_i96 | -268435456;
  } else {
    c3_b_b0.re = c3_i96 & 268435455;
  }

  c3_i97 = c3_b0.im;
  if ((c3_i97 & 268435456) != 0) {
    c3_b_b0.im = c3_i97 | -268435456;
  } else {
    c3_b_b0.im = c3_i97 & 268435455;
  }

  c3_i98 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i98 & 268435456) != 0) {
    c3_c.re = c3_i98 | -268435456;
  } else {
    c3_c.re = c3_i98 & 268435455;
  }

  c3_i99 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i99 & 268435456) != 0) {
    c3_c.im = c3_i99 | -268435456;
  } else {
    c3_c.im = c3_i99 & 268435455;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_m_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i100;
  cint32_T c3_b_a0;
  int32_T c3_i101;
  int32_T c3_i102;
  cint32_T c3_b_b0;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i100 = c3_a0.re;
  if ((c3_i100 & 536870912) != 0) {
    c3_b_a0.re = c3_i100 | -536870912;
  } else {
    c3_b_a0.re = c3_i100 & 536870911;
  }

  c3_i101 = c3_a0.im;
  if ((c3_i101 & 536870912) != 0) {
    c3_b_a0.im = c3_i101 | -536870912;
  } else {
    c3_b_a0.im = c3_i101 & 536870911;
  }

  c3_i102 = c3_b0.re;
  if ((c3_i102 & 536870912) != 0) {
    c3_b_b0.re = c3_i102 | -536870912;
  } else {
    c3_b_b0.re = c3_i102 & 536870911;
  }

  c3_i103 = c3_b0.im;
  if ((c3_i103 & 536870912) != 0) {
    c3_b_b0.im = c3_i103 | -536870912;
  } else {
    c3_b_b0.im = c3_i103 & 536870911;
  }

  c3_i104 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i104 & 536870912) != 0) {
    c3_c.re = c3_i104 | -536870912;
  } else {
    c3_c.re = c3_i104 & 536870911;
  }

  c3_i105 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i105 & 536870912) != 0) {
    c3_c.im = c3_i105 | -536870912;
  } else {
    c3_c.im = c3_i105 & 536870911;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_n_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int32_T c3_i106;
  cint32_T c3_b_a0;
  int32_T c3_i107;
  int32_T c3_i108;
  cint32_T c3_b_b0;
  int32_T c3_i109;
  int32_T c3_i110;
  int32_T c3_i111;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_i106 = c3_a0.re;
  if ((c3_i106 & 1073741824) != 0) {
    c3_b_a0.re = c3_i106 | -1073741824;
  } else {
    c3_b_a0.re = c3_i106 & 1073741823;
  }

  c3_i107 = c3_a0.im;
  if ((c3_i107 & 1073741824) != 0) {
    c3_b_a0.im = c3_i107 | -1073741824;
  } else {
    c3_b_a0.im = c3_i107 & 1073741823;
  }

  c3_i108 = c3_b0.re;
  if ((c3_i108 & 1073741824) != 0) {
    c3_b_b0.re = c3_i108 | -1073741824;
  } else {
    c3_b_b0.re = c3_i108 & 1073741823;
  }

  c3_i109 = c3_b0.im;
  if ((c3_i109 & 1073741824) != 0) {
    c3_b_b0.im = c3_i109 | -1073741824;
  } else {
    c3_b_b0.im = c3_i109 & 1073741823;
  }

  c3_i110 = c3_b_a0.re + c3_b_b0.re;
  if ((c3_i110 & 1073741824) != 0) {
    c3_c.re = c3_i110 | -1073741824;
  } else {
    c3_c.re = c3_i110 & 1073741823;
  }

  c3_i111 = c3_b_a0.im + c3_b_b0.im;
  if ((c3_i111 & 1073741824) != 0) {
    c3_c.im = c3_i111 | -1073741824;
  } else {
    c3_c.im = c3_i111 & 1073741823;
  }

  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint32_T c3_o_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint32_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  cint32_T c3_b_a0;
  cint32_T c3_b_b0;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_b_a0.re = c3_a0.re;
  c3_b_a0.im = c3_a0.im;
  c3_b_b0.re = c3_b0.re;
  c3_b_b0.im = c3_b0.im;
  c3_c.re = c3_b_a0.re + c3_b_b0.re;
  c3_c.im = c3_b_a0.im + c3_b_b0.im;
  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static cint64m_T c3_p_plus(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  cint32_T c3_a0, cint32_T c3_b0)
{
  cint64m_T c3_c;
  const mxArray *c3_propVal = NULL;
  const mxArray *c3_errmsg = NULL;
  const mxArray *c3_b_propVal = NULL;
  const mxArray *c3_b_errmsg = NULL;
  const mxArray *c3_c_propVal = NULL;
  const mxArray *c3_c_errmsg = NULL;
  const mxArray *c3_d_propVal = NULL;
  const mxArray *c3_d_errmsg = NULL;
  const mxArray *c3_e_propVal = NULL;
  const mxArray *c3_e_errmsg = NULL;
  const mxArray *c3_f_propVal = NULL;
  const mxArray *c3_f_errmsg = NULL;
  const mxArray *c3_g_propVal = NULL;
  const mxArray *c3_g_errmsg = NULL;
  const mxArray *c3_h_propVal = NULL;
  const mxArray *c3_h_errmsg = NULL;
  const mxArray *c3_i_propVal = NULL;
  const mxArray *c3_i_errmsg = NULL;
  int64m_T c3_r3;
  cint64m_T c3_b_a0;
  cint64m_T c3_b_b0;
  int64m_T c3_r4;
  int64m_T c3_r5;
  const mxArray *c3_ERR = NULL;
  const mxArray *c3_a2SD = NULL;
  const mxArray *c3_b2SD = NULL;
  const mxArray *c3_Tsd = NULL;
  const mxArray *c3_tc = NULL;
  const mxArray *c3_j_errmsg = NULL;
  sf_mex_destroy(&c3_propVal);
  sf_mex_destroy(&c3_errmsg);
  sf_mex_destroy(&c3_b_propVal);
  sf_mex_destroy(&c3_b_errmsg);
  sf_mex_destroy(&c3_c_propVal);
  sf_mex_destroy(&c3_c_errmsg);
  sf_mex_destroy(&c3_d_propVal);
  sf_mex_destroy(&c3_d_errmsg);
  sf_mex_destroy(&c3_e_propVal);
  sf_mex_destroy(&c3_e_errmsg);
  sf_mex_destroy(&c3_f_propVal);
  sf_mex_destroy(&c3_f_errmsg);
  sf_mex_destroy(&c3_g_propVal);
  sf_mex_destroy(&c3_g_errmsg);
  sf_mex_destroy(&c3_h_propVal);
  sf_mex_destroy(&c3_h_errmsg);
  sf_mex_destroy(&c3_i_propVal);
  sf_mex_destroy(&c3_i_errmsg);
  c3_sLong2MultiWord(chartInstance, c3_a0.re, &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_b_a0.re.chunks[0U]);
  c3_sLong2MultiWord(chartInstance, c3_a0.im, &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_b_a0.im.chunks[0U]);
  c3_sLong2MultiWord(chartInstance, c3_b0.re, &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_b_b0.re.chunks[0U]);
  c3_sLong2MultiWord(chartInstance, c3_b0.im, &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_b_b0.im.chunks[0U]);
  c3_MultiWordAdd(chartInstance, &c3_b_a0.re.chunks[0U], &c3_b_b0.re.chunks[0U],
                  &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_r4.chunks[0U]);
  c3_c.re = c3_r4;
  c3_MultiWordAdd(chartInstance, &c3_b_a0.im.chunks[0U], &c3_b_b0.im.chunks[0U],
                  &c3_r3.chunks[0U], 2);
  c3_MultiWordSignedWrap(chartInstance, &c3_r3.chunks[0U], 2, 31U,
    &c3_r5.chunks[0U]);
  c3_c.im = c3_r5;
  sf_mex_destroy(&c3_ERR);
  sf_mex_destroy(&c3_a2SD);
  sf_mex_destroy(&c3_b2SD);
  sf_mex_destroy(&c3_Tsd);
  sf_mex_destroy(&c3_tc);
  sf_mex_destroy(&c3_j_errmsg);
  return c3_c;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_h_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i112;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i112, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i112;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  cint16_T c3_u;
  const mxArray *c3_y = NULL;
  cint16_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(cint16_T *)c3_inData;
  c3_y = NULL;
  c3_b_u.re = c3_u.re;
  c3_b_u.im = c3_u.im;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c3_g_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_c_eml_mx), 15,
    "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static cint16_T c3_i_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_d_out, const char_T *c3_identifier)
{
  cint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_out), &c3_thisId);
  sf_mex_destroy(&c3_d_out);
  return c3_y;
}

static cint16_T c3_j_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  cint16_T c3_y;
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  cint16_T c3_ic34;
  sf_mex_check_fi(c3_parentId, c3_u, 1, 0U, 0, c3_g_eml_mx, c3_c_eml_mx);
  sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), FALSE);
  sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c3_mxFi)), FALSE);
  sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), &c3_ic34, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c3_mxFi);
  sf_mex_destroy(&c3_mxInt);
  c3_y = c3_ic34;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_d_out;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  cint16_T c3_y;
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)chartInstanceVoid;
  c3_d_out = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_out), &c3_thisId);
  sf_mex_destroy(&c3_d_out);
  *(cint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_k_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_QPSK_Transmit_v12c, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_QPSK_Transmit_v12c), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_QPSK_Transmit_v12c);
  return c3_y;
}

static uint8_T c3_l_emlrt_marshallIn(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static int32_T c3_MultiWord2sLong(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u[])
{
  return (int32_T)c3_u[0];
}

static void c3_sMultiWordShr(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u1[], int32_T c3_n1, uint32_T c3_n2,
  uint32_T c3_y[], int32_T c3_n)
{
  int32_T c3_nb;
  int32_T c3_i;
  uint32_T c3_ys;
  int32_T c3_nc;
  uint32_T c3_nr;
  uint32_T c3_nl;
  uint32_T c3_u1i;
  int32_T c3_i1;
  uint32_T c3_yi;
  c3_nb = (int32_T)c3_n2 / 32;
  c3_i = 0;
  if ((c3_u1[c3_n1 - 1] & 2147483648U) != 0U) {
    c3_ys = MAX_uint32_T;
  } else {
    c3_ys = 0U;
  }

  if (c3_nb < c3_n1) {
    c3_nc = c3_n + c3_nb;
    if (c3_nc > c3_n1) {
      c3_nc = c3_n1;
    }

    c3_nr = c3_n2 - (uint32_T)c3_nb * 32U;
    if (c3_nr > 0) {
      c3_nl = 32U - c3_nr;
      c3_u1i = c3_u1[c3_nb];
      for (c3_i1 = c3_nb + 1; c3_i1 < c3_nc; c3_i1++) {
        c3_yi = c3_u1i >> c3_nr;
        c3_u1i = c3_u1[c3_i1];
        c3_y[c3_i] = c3_yi | c3_u1i << c3_nl;
        c3_i++;
      }

      c3_yi = c3_u1i >> c3_nr;
      if (c3_nc < c3_n1) {
        c3_u1i = c3_u1[c3_nc];
      } else {
        c3_u1i = c3_ys;
      }

      c3_y[c3_i] = c3_yi | c3_u1i << c3_nl;
      c3_i++;
    } else {
      for (c3_i1 = c3_nb; c3_i1 < c3_nc; c3_i1++) {
        c3_y[c3_i] = c3_u1[c3_i1];
        c3_i++;
      }
    }
  }

  while (c3_i < c3_n) {
    c3_y[c3_i] = c3_ys;
    c3_i++;
  }
}

static void c3_MultiWordSignedWrap(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, const uint32_T c3_u1[], int32_T c3_n1, uint32_T c3_n2,
  uint32_T c3_y[])
{
  int32_T c3_n1m1;
  int32_T c3_i;
  uint32_T c3_ns;
  uint32_T c3_mask;
  uint32_T c3_ys;
  c3_n1m1 = c3_n1 - 1;
  for (c3_i = 0; c3_i < c3_n1m1; c3_i++) {
    c3_y[c3_i] = c3_u1[c3_i];
  }

  c3_ns = 31U - c3_n2;
  c3_mask = 1U << c3_ns;
  if ((c3_u1[c3_n1m1] & c3_mask) != 0U) {
    c3_ys = MAX_uint32_T;
  } else {
    c3_ys = 0U;
  }

  c3_mask = (c3_mask << 1U) - 1U;
  c3_y[c3_n1m1] = (c3_u1[c3_n1m1] & c3_mask) | (~c3_mask & c3_ys);
}

static void c3_sLong2MultiWord(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance, int32_T c3_u, uint32_T c3_y[], int32_T c3_n)
{
  uint32_T c3_yi;
  int32_T c3_i;
  c3_y[0] = (uint32_T)c3_u;
  if (c3_u < 0) {
    c3_yi = MAX_uint32_T;
  } else {
    c3_yi = 0U;
  }

  for (c3_i = 1; c3_i < c3_n; c3_i++) {
    c3_y[c3_i] = c3_yi;
  }
}

static void c3_MultiWordAdd(SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance,
  const uint32_T c3_u1[], const uint32_T c3_u2[], uint32_T c3_y[], int32_T c3_n)
{
  int32_T c3_i;
  uint32_T c3_u1i;
  uint32_T c3_carry = 0U;
  uint32_T c3_yi;
  uint32_T c3_carry1;
  uint32_T c3_carry2;
  for (c3_i = 0; c3_i < c3_n; c3_i++) {
    c3_u1i = c3_u1[c3_i];
    c3_yi = (c3_u1i + c3_u2[c3_i]) + c3_carry;
    c3_y[c3_i] = c3_yi;
    if (c3_yi <= c3_u1i) {
      c3_carry1 = 1U;
    } else {
      c3_carry1 = 0U;
    }

    if (c3_yi < c3_u1i) {
      c3_carry2 = 1U;
    } else {
      c3_carry2 = 0U;
    }

    if (c3_carry != 0U) {
      c3_carry = c3_carry1;
    } else {
      c3_carry = c3_carry2;
    }
  }
}

static void init_dsm_address_info(SFc3_QPSK_Transmit_v12cInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_QPSK_Transmit_v12c_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2699967231U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3110790392U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3104252127U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1836724370U);
}

mxArray *sf_c3_QPSK_Transmit_v12c_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WxQvMsTlI2eqlrCuEkpNUH");
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

static const mxArray *sf_get_sim_state_info_c3_QPSK_Transmit_v12c(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"d_out\",},{M[4],M[0],T\"buf\",S'l','i','p'{{M1x2[61 64],M[0],}}},{M[8],M[0],T\"is_active_c3_QPSK_Transmit_v12c\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_QPSK_Transmit_v12c_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
    chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QPSK_Transmit_v12cMachineNumber_,
           3,
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
          init_script_number_translation(_QPSK_Transmit_v12cMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QPSK_Transmit_v12cMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QPSK_Transmit_v12cMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,855);
        _SFD_CV_INIT_EML_IF(0,1,0,107,124,-1,207);
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
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,12,0,1,-11,1,
          (MexFcnForType)c3_k_sf_marshallOut,(MexInFcnForType)c3_h_sf_marshallIn);

        {
          cint8_T *c3_d_in;
          cint16_T *c3_d_out;
          c3_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_d_in = (cint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_d_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_d_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_QPSK_Transmit_v12cMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "du6y0WMMCWe5NDxOSl8zWG";
}

static void sf_opaque_initialize_c3_QPSK_Transmit_v12c(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
  initialize_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_QPSK_Transmit_v12c(void *chartInstanceVar)
{
  enable_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_QPSK_Transmit_v12c(void *chartInstanceVar)
{
  disable_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_QPSK_Transmit_v12c(void *chartInstanceVar)
{
  sf_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_QPSK_Transmit_v12c(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_QPSK_Transmit_v12c
    ((SFc3_QPSK_Transmit_v12cInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_QPSK_Transmit_v12c();/* state var info */
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

extern void sf_internal_set_sim_state_c3_QPSK_Transmit_v12c(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_QPSK_Transmit_v12c();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_QPSK_Transmit_v12c(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_QPSK_Transmit_v12c(S);
}

static void sf_opaque_set_sim_state_c3_QPSK_Transmit_v12c(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_QPSK_Transmit_v12c(S, st);
}

static void sf_opaque_terminate_c3_QPSK_Transmit_v12c(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_QPSK_Transmit_v12cInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QPSK_Transmit_v12c_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_QPSK_Transmit_v12c((SFc3_QPSK_Transmit_v12cInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_QPSK_Transmit_v12c(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_QPSK_Transmit_v12c
      ((SFc3_QPSK_Transmit_v12cInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_QPSK_Transmit_v12c(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QPSK_Transmit_v12c_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2351956425U));
  ssSetChecksum1(S,(3262379801U));
  ssSetChecksum2(S,(4220206776U));
  ssSetChecksum3(S,(3360520733U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_QPSK_Transmit_v12c(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_QPSK_Transmit_v12c(SimStruct *S)
{
  SFc3_QPSK_Transmit_v12cInstanceStruct *chartInstance;
  chartInstance = (SFc3_QPSK_Transmit_v12cInstanceStruct *)malloc(sizeof
    (SFc3_QPSK_Transmit_v12cInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_QPSK_Transmit_v12cInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_QPSK_Transmit_v12c;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_QPSK_Transmit_v12c;
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

void c3_QPSK_Transmit_v12c_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_QPSK_Transmit_v12c(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_QPSK_Transmit_v12c(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_QPSK_Transmit_v12c(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_QPSK_Transmit_v12c_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
