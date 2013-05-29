/* Include files */

#include "blascompat32.h"
#include "QPSK_Transmit_v8_sfun.h"
#include "c108_QPSK_Transmit_v8.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QPSK_Transmit_v8_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c108_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const mxArray *c108_eml_mx;
static const mxArray *c108_b_eml_mx;
static const mxArray *c108_c_eml_mx;

/* Function Declarations */
static void initialize_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static void initialize_params_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static void enable_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance);
static void disable_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct *
  chartInstance);
static void c108_update_debugger_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static void set_sim_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance, const mxArray *c108_st);
static void finalize_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance);
static void sf_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance);
static void c108_chartstep_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static void initSimStructsc108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c108_machineNumber, uint32_T
  c108_chartNumber);
static const mxArray *c108_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static void c108_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId,
  uint8_T c108_y[8]);
static void c108_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData);
static const mxArray *c108_b_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static const mxArray *c108_c_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static real_T c108_b_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId);
static void c108_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData);
static void c108_info_helper(c108_ResolvedFunctionInfo c108_info[43]);
static void c108_eml_error(SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance,
  int32_T c108_varargin_2);
static const mxArray *c108_d_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static int32_T c108_c_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId);
static void c108_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData);
static const mxArray *c108_e_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static const mxArray *c108_f_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData);
static void c108_d_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_y, const char_T *c108_identifier, uint8_T
  c108_b_y[8]);
static void c108_e_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId,
  uint8_T c108_y[8]);
static void c108_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData);
static uint8_T c108_f_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_b_is_active_c108_QPSK_Transmit_v8, const
  char_T *c108_identifier);
static uint8_T c108_g_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId);
static uint32_T c108__u32_minus__(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, uint32_T c108_b, uint32_T c108_c);
static uint8_T c108__u8_u32_(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, uint32_T c108_b);
static uint8_T c108__u8_d_(SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance,
  real_T c108_b);
static void init_dsm_address_info(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
  chartInstance->c108_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c108_is_active_c108_QPSK_Transmit_v8 = 0U;
  sf_mex_assign(&c108_c_eml_mx, sf_mex_call_debug("numerictype", 1U, 14U, 15,
    "SignednessBool", 3, FALSE, 15, "Signedness", 15, "Unsigned", 15,
    "WordLength", 6, 8.0, 15, "FractionLength", 6, 0.0, 15, "BinaryPoint", 6,
    0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0), TRUE);
  sf_mex_assign(&c108_b_eml_mx, sf_mex_call_debug("numerictype", 1U, 14U, 15,
    "SignednessBool", 3, FALSE, 15, "Signedness", 15, "Unsigned", 15,
    "WordLength", 6, 1.0, 15, "FractionLength", 6, 0.0, 15, "BinaryPoint", 6,
    0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0), TRUE);
  sf_mex_assign(&c108_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15,
    "RoundMode", 15, "floor", 15, "RoundingMethod", 15, "Floor", 15,
    "OverflowMode", 15, "wrap", 15, "OverflowAction", 15, "Wrap", 15,
    "ProductMode", 15, "KeepLSB", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 65535.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "KeepLSB", 15, "SumWordLength", 6,
    32.0, 15, "MaxSumWordLength", 6, 65535.0, 15, "SumFractionLength", 6, 30.0,
    15, "SumFixedExponent", 6, -30.0, 15, "SumSlope", 6, 9.3132257461547852E-10,
    15, "SumSlopeAdjustmentFactor", 6, 1.0, 15, "SumBias", 6, 0.0, 15,
    "CastBeforeSum", 3, TRUE), TRUE);
}

static void initialize_params_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
}

static void enable_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c108_update_debugger_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
  const mxArray *c108_st;
  const mxArray *c108_y = NULL;
  const mxArray *c108_b_y = NULL;
  int32_T c108_i0;
  uint8_T c108_u[8];
  const mxArray *c108_c_y = NULL;
  uint8_T c108_hoistedGlobal;
  uint8_T c108_b_u;
  const mxArray *c108_d_y = NULL;
  uint8_T (*c108_e_y)[8];
  c108_e_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c108_st = NULL;
  c108_st = NULL;
  c108_y = NULL;
  sf_mex_assign(&c108_y, sf_mex_createcellarray(2), FALSE);
  c108_b_y = NULL;
  for (c108_i0 = 0; c108_i0 < 8; c108_i0++) {
    c108_u[c108_i0] = (*c108_e_y)[c108_i0];
  }

  c108_c_y = NULL;
  sf_mex_assign(&c108_c_y, sf_mex_create("y", c108_u, 3, 0U, 1U, 0U, 1, 8),
                FALSE);
  sf_mex_assign(&c108_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c108_eml_mx), 15, "numerictype", 14, sf_mex_dup(c108_b_eml_mx),
    15, "simulinkarray", 14, c108_c_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_setcell(c108_y, 0, c108_b_y);
  c108_hoistedGlobal = chartInstance->c108_is_active_c108_QPSK_Transmit_v8;
  c108_b_u = c108_hoistedGlobal;
  c108_d_y = NULL;
  sf_mex_assign(&c108_d_y, sf_mex_create("y", &c108_b_u, 3, 0U, 0U, 0U, 0),
                FALSE);
  sf_mex_setcell(c108_y, 1, c108_d_y);
  sf_mex_assign(&c108_st, c108_y, FALSE);
  return c108_st;
}

static void set_sim_state_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance, const mxArray *c108_st)
{
  const mxArray *c108_u;
  uint8_T c108_uv0[8];
  int32_T c108_i1;
  uint8_T (*c108_y)[8];
  c108_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c108_doneDoubleBufferReInit = TRUE;
  c108_u = sf_mex_dup(c108_st);
  c108_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c108_u, 0)),
    "y", c108_uv0);
  for (c108_i1 = 0; c108_i1 < 8; c108_i1++) {
    (*c108_y)[c108_i1] = c108_uv0[c108_i1];
  }

  chartInstance->c108_is_active_c108_QPSK_Transmit_v8 = c108_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c108_u, 1)),
     "is_active_c108_QPSK_Transmit_v8");
  sf_mex_destroy(&c108_u);
  c108_update_debugger_state_c108_QPSK_Transmit_v8(chartInstance);
  sf_mex_destroy(&c108_st);
}

static void finalize_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c108_eml_mx);
  sf_mex_destroy(&c108_b_eml_mx);
  sf_mex_destroy(&c108_c_eml_mx);
}

static void sf_c108_QPSK_Transmit_v8(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance)
{
  int32_T c108_i2;
  uint8_T *c108_u;
  uint8_T (*c108_y)[8];
  c108_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c108_u = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c108_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c108_u, 0U);
  for (c108_i2 = 0; c108_i2 < 8; c108_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c108_y)[c108_i2], 1U);
  }

  chartInstance->c108_sfEvent = CALL_EVENT;
  c108_chartstep_c108_QPSK_Transmit_v8(chartInstance);
  sf_debug_check_for_state_inconsistency(_QPSK_Transmit_v8MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c108_chartstep_c108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
  uint8_T c108_hoistedGlobal;
  uint8_T c108_u;
  uint32_T c108_debug_family_var_map[4];
  real_T c108_nargin = 1.0;
  real_T c108_nargout = 1.0;
  uint8_T c108_y[8];
  uint8_T c108_a;
  const mxArray *c108_propVal = NULL;
  const mxArray *c108_errmsg = NULL;
  int32_T c108_i3;
  uint8_T c108_c[8];
  int32_T c108_k;
  real_T c108_b_k;
  uint8_T c108_a1;
  real_T c108_bit1;
  uint8_T c108_bit_idx;
  uint8_T c108_slice_temp;
  int32_T c108_i4;
  int32_T c108_i5;
  uint8_T *c108_b_u;
  uint8_T (*c108_b_y)[8];
  boolean_T guard1 = FALSE;
  c108_b_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c108_b_u = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c108_sfEvent);
  c108_hoistedGlobal = *c108_b_u;
  c108_u = c108_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c108_debug_family_names,
    c108_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c108_nargin, 0U,
    c108_c_sf_marshallOut, c108_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c108_nargout, 1U,
    c108_c_sf_marshallOut, c108_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c108_u, 2U, c108_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c108_y, 3U, c108_sf_marshallOut,
    c108_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c108_sfEvent, 4);
  c108_a = c108_u;
  sf_mex_destroy(&c108_propVal);
  sf_mex_destroy(&c108_errmsg);
  for (c108_i3 = 0; c108_i3 < 8; c108_i3++) {
    c108_c[c108_i3] = 0U;
  }

  for (c108_k = 0; c108_k < 8; c108_k++) {
    c108_b_k = 1.0 + (real_T)c108_k;
    c108_a1 = c108_a;
    c108_bit1 = 8.0 - (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c108_b_k), 1, 8, 1, 0) - 1);
    guard1 = FALSE;
    if (c108_bit1 >= 1.0) {
      if (c108_bit1 <= 8.0) {
        c108_bit_idx = c108__u8_u32_(chartInstance, c108__u32_minus__
          (chartInstance, (uint32_T)c108__u8_d_(chartInstance,
          muDoubleScalarRound(c108_bit1)), 1U));
        c108_slice_temp = (uint8_T)((uint8_T)((uint32_T)c108_a1 >> c108_bit_idx)
          & 1U);
        c108_c[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c108_b_k), 1, 8, 1, 0) - 1] = c108_slice_temp;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      c108_eml_error(chartInstance, 8);
      c108_c[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c108_b_k), 1, 8, 1, 0) - 1] = 0U;
    }
  }

  for (c108_i4 = 0; c108_i4 < 8; c108_i4++) {
    c108_y[c108_i4] = c108_c[c108_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c108_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c108_i5 = 0; c108_i5 < 8; c108_i5++) {
    (*c108_b_y)[c108_i5] = c108_y[c108_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c108_sfEvent);
}

static void initSimStructsc108_QPSK_Transmit_v8
  (SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c108_machineNumber, uint32_T
  c108_chartNumber)
{
}

static const mxArray *c108_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData;
  int32_T c108_i6;
  uint8_T c108_u[8];
  const mxArray *c108_y = NULL;
  int32_T c108_i7;
  uint8_T c108_b_u[8];
  const mxArray *c108_b_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_mxArrayOutData = NULL;
  for (c108_i6 = 0; c108_i6 < 8; c108_i6++) {
    c108_u[c108_i6] = (*(uint8_T (*)[8])c108_inData)[c108_i6];
  }

  c108_y = NULL;
  for (c108_i7 = 0; c108_i7 < 8; c108_i7++) {
    c108_b_u[c108_i7] = c108_u[c108_i7];
  }

  c108_b_y = NULL;
  sf_mex_assign(&c108_b_y, sf_mex_create("y", c108_b_u, 3, 0U, 1U, 0U, 1, 8),
                FALSE);
  sf_mex_assign(&c108_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c108_eml_mx), 15, "numerictype", 14, sf_mex_dup(c108_b_eml_mx), 15,
    "simulinkarray", 14, c108_b_y, 15, "fimathislocal", 3, FALSE), FALSE);
  sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  return c108_mxArrayOutData;
}

static void c108_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId,
  uint8_T c108_y[8])
{
  static uint32_T c108_uv1[1] = { 8U };

  uint32_T c108_uv2[1];
  const mxArray *c108_mxFi = NULL;
  const mxArray *c108_mxInt = NULL;
  uint8_T c108_uv3[8];
  int32_T c108_i8;
  c108_uv2[0] = c108_uv1[0];
  sf_mex_check_fi(c108_parentId, c108_u, 0, 1U, c108_uv2, c108_eml_mx,
                  c108_b_eml_mx);
  sf_mex_assign(&c108_mxFi, sf_mex_dup(c108_u), FALSE);
  sf_mex_assign(&c108_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
                 (c108_mxFi)), FALSE);
  sf_mex_import(c108_parentId, sf_mex_dup(c108_mxInt), c108_uv3, 1, 3, 0U, 1, 0U,
                1, 8);
  sf_mex_destroy(&c108_mxFi);
  sf_mex_destroy(&c108_mxInt);
  for (c108_i8 = 0; c108_i8 < 8; c108_i8++) {
    c108_y[c108_i8] = c108_uv3[c108_i8];
  }

  sf_mex_destroy(&c108_u);
}

static void c108_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData)
{
  const mxArray *c108_y;
  const char_T *c108_identifier;
  emlrtMsgIdentifier c108_thisId;
  uint8_T c108_b_y[8];
  int32_T c108_i9;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_y = sf_mex_dup(c108_mxArrayInData);
  c108_identifier = c108_varName;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_emlrt_marshallIn(chartInstance, sf_mex_dup(c108_y), &c108_thisId,
                        c108_b_y);
  sf_mex_destroy(&c108_y);
  for (c108_i9 = 0; c108_i9 < 8; c108_i9++) {
    (*(uint8_T (*)[8])c108_outData)[c108_i9] = c108_b_y[c108_i9];
  }

  sf_mex_destroy(&c108_mxArrayInData);
}

static const mxArray *c108_b_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData;
  uint8_T c108_u;
  const mxArray *c108_y = NULL;
  uint8_T c108_b_u;
  const mxArray *c108_b_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c108_u = *(uint8_T *)c108_inData;
    c108_y = NULL;
    c108_b_u = c108_u;
    c108_b_y = NULL;
    sf_mex_assign(&c108_b_y, sf_mex_create("y", &c108_b_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
    sf_mex_assign(&c108_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
      sf_mex_dup(c108_eml_mx), 15, "numerictype", 14, sf_mex_dup(c108_c_eml_mx),
      15, "simulinkarray", 14, c108_b_y, 15, "fimathislocal", 3, FALSE), FALSE);
    sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  } else {
    sf_mex_assign(&c108_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), FALSE);
  }

  return c108_mxArrayOutData;
}

static const mxArray *c108_c_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData = NULL;
  real_T c108_u;
  const mxArray *c108_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_u = *(real_T *)c108_inData;
  c108_y = NULL;
  sf_mex_assign(&c108_y, sf_mex_create("y", &c108_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  return c108_mxArrayOutData;
}

static real_T c108_b_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId)
{
  real_T c108_y;
  real_T c108_d0;
  sf_mex_import(c108_parentId, sf_mex_dup(c108_u), &c108_d0, 1, 0, 0U, 0, 0U, 0);
  c108_y = c108_d0;
  sf_mex_destroy(&c108_u);
  return c108_y;
}

static void c108_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData)
{
  const mxArray *c108_nargout;
  const char_T *c108_identifier;
  emlrtMsgIdentifier c108_thisId;
  real_T c108_y;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_nargout = sf_mex_dup(c108_mxArrayInData);
  c108_identifier = c108_varName;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_y = c108_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c108_nargout),
    &c108_thisId);
  sf_mex_destroy(&c108_nargout);
  *(real_T *)c108_outData = c108_y;
  sf_mex_destroy(&c108_mxArrayInData);
}

const mxArray *sf_c108_QPSK_Transmit_v8_get_eml_resolved_functions_info(void)
{
  const mxArray *c108_nameCaptureInfo;
  c108_ResolvedFunctionInfo c108_info[43];
  const mxArray *c108_m0 = NULL;
  int32_T c108_i10;
  c108_ResolvedFunctionInfo *c108_r0;
  c108_nameCaptureInfo = NULL;
  c108_nameCaptureInfo = NULL;
  c108_info_helper(c108_info);
  sf_mex_assign(&c108_m0, sf_mex_createstruct("nameCaptureInfo", 1, 43), FALSE);
  for (c108_i10 = 0; c108_i10 < 43; c108_i10++) {
    c108_r0 = &c108_info[c108_i10];
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo", c108_r0->context,
      15, 0U, 0U, 0U, 2, 1, strlen(c108_r0->context)), "context",
                    "nameCaptureInfo", c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo", c108_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c108_r0->name)), "name", "nameCaptureInfo",
                    c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo",
      c108_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c108_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo", c108_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c108_r0->resolved)), "resolved",
                    "nameCaptureInfo", c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo",
      &c108_r0->fileTimeLo, 7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo",
                    c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo",
      &c108_r0->fileTimeHi, 7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo",
                    c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo",
      &c108_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c108_i10);
    sf_mex_addfield(c108_m0, sf_mex_create("nameCaptureInfo",
      &c108_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c108_i10);
  }

  sf_mex_assign(&c108_nameCaptureInfo, c108_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c108_nameCaptureInfo);
  return c108_nameCaptureInfo;
}

static void c108_info_helper(c108_ResolvedFunctionInfo c108_info[43])
{
  c108_info[0].context = "";
  c108_info[0].name = "colon";
  c108_info[0].dominantType = "double";
  c108_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c108_info[0].fileTimeLo = 1311287718U;
  c108_info[0].fileTimeHi = 0U;
  c108_info[0].mFileTimeLo = 0U;
  c108_info[0].mFileTimeHi = 0U;
  c108_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c108_info[1].name = "isfinite";
  c108_info[1].dominantType = "double";
  c108_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c108_info[1].fileTimeLo = 1286851158U;
  c108_info[1].fileTimeHi = 0U;
  c108_info[1].mFileTimeLo = 0U;
  c108_info[1].mFileTimeHi = 0U;
  c108_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c108_info[2].name = "isinf";
  c108_info[2].dominantType = "double";
  c108_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c108_info[2].fileTimeLo = 1286851160U;
  c108_info[2].fileTimeHi = 0U;
  c108_info[2].mFileTimeLo = 0U;
  c108_info[2].mFileTimeHi = 0U;
  c108_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c108_info[3].name = "isnan";
  c108_info[3].dominantType = "double";
  c108_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c108_info[3].fileTimeLo = 1286851160U;
  c108_info[3].fileTimeHi = 0U;
  c108_info[3].mFileTimeLo = 0U;
  c108_info[3].mFileTimeHi = 0U;
  c108_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c108_info[4].name = "floor";
  c108_info[4].dominantType = "double";
  c108_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c108_info[4].fileTimeLo = 1286851142U;
  c108_info[4].fileTimeHi = 0U;
  c108_info[4].mFileTimeLo = 0U;
  c108_info[4].mFileTimeHi = 0U;
  c108_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c108_info[5].name = "eml_scalar_floor";
  c108_info[5].dominantType = "double";
  c108_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c108_info[5].fileTimeLo = 1286851126U;
  c108_info[5].fileTimeHi = 0U;
  c108_info[5].mFileTimeLo = 0U;
  c108_info[5].mFileTimeHi = 0U;
  c108_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c108_info[6].name = "abs";
  c108_info[6].dominantType = "double";
  c108_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c108_info[6].fileTimeLo = 1286851094U;
  c108_info[6].fileTimeHi = 0U;
  c108_info[6].mFileTimeLo = 0U;
  c108_info[6].mFileTimeHi = 0U;
  c108_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c108_info[7].name = "eml_scalar_abs";
  c108_info[7].dominantType = "double";
  c108_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c108_info[7].fileTimeLo = 1286851112U;
  c108_info[7].fileTimeHi = 0U;
  c108_info[7].mFileTimeLo = 0U;
  c108_info[7].mFileTimeHi = 0U;
  c108_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c108_info[8].name = "eps";
  c108_info[8].dominantType = "double";
  c108_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[8].fileTimeLo = 1326760396U;
  c108_info[8].fileTimeHi = 0U;
  c108_info[8].mFileTimeLo = 0U;
  c108_info[8].mFileTimeHi = 0U;
  c108_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[9].name = "eml_mantissa_nbits";
  c108_info[9].dominantType = "char";
  c108_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c108_info[9].fileTimeLo = 1307683642U;
  c108_info[9].fileTimeHi = 0U;
  c108_info[9].mFileTimeLo = 0U;
  c108_info[9].mFileTimeHi = 0U;
  c108_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c108_info[10].name = "eml_float_model";
  c108_info[10].dominantType = "char";
  c108_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c108_info[10].fileTimeLo = 1326760396U;
  c108_info[10].fileTimeHi = 0U;
  c108_info[10].mFileTimeLo = 0U;
  c108_info[10].mFileTimeHi = 0U;
  c108_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[11].name = "eml_realmin";
  c108_info[11].dominantType = "char";
  c108_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c108_info[11].fileTimeLo = 1307683644U;
  c108_info[11].fileTimeHi = 0U;
  c108_info[11].mFileTimeLo = 0U;
  c108_info[11].mFileTimeHi = 0U;
  c108_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c108_info[12].name = "eml_float_model";
  c108_info[12].dominantType = "char";
  c108_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c108_info[12].fileTimeLo = 1326760396U;
  c108_info[12].fileTimeHi = 0U;
  c108_info[12].mFileTimeLo = 0U;
  c108_info[12].mFileTimeHi = 0U;
  c108_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[13].name = "eml_realmin_denormal";
  c108_info[13].dominantType = "char";
  c108_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c108_info[13].fileTimeLo = 1326760398U;
  c108_info[13].fileTimeHi = 0U;
  c108_info[13].mFileTimeLo = 0U;
  c108_info[13].mFileTimeHi = 0U;
  c108_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c108_info[14].name = "eml_float_model";
  c108_info[14].dominantType = "char";
  c108_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c108_info[14].fileTimeLo = 1326760396U;
  c108_info[14].fileTimeHi = 0U;
  c108_info[14].mFileTimeLo = 0U;
  c108_info[14].mFileTimeHi = 0U;
  c108_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[15].name = "abs";
  c108_info[15].dominantType = "double";
  c108_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c108_info[15].fileTimeLo = 1286851094U;
  c108_info[15].fileTimeHi = 0U;
  c108_info[15].mFileTimeLo = 0U;
  c108_info[15].mFileTimeHi = 0U;
  c108_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c108_info[16].name = "isfinite";
  c108_info[16].dominantType = "double";
  c108_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c108_info[16].fileTimeLo = 1286851158U;
  c108_info[16].fileTimeHi = 0U;
  c108_info[16].mFileTimeLo = 0U;
  c108_info[16].mFileTimeHi = 0U;
  c108_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c108_info[17].name = "realmax";
  c108_info[17].dominantType = "char";
  c108_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c108_info[17].fileTimeLo = 1307683642U;
  c108_info[17].fileTimeHi = 0U;
  c108_info[17].mFileTimeLo = 0U;
  c108_info[17].mFileTimeHi = 0U;
  c108_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c108_info[18].name = "eml_realmax";
  c108_info[18].dominantType = "char";
  c108_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c108_info[18].fileTimeLo = 1326760396U;
  c108_info[18].fileTimeHi = 0U;
  c108_info[18].mFileTimeLo = 0U;
  c108_info[18].mFileTimeHi = 0U;
  c108_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c108_info[19].name = "eml_float_model";
  c108_info[19].dominantType = "char";
  c108_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c108_info[19].fileTimeLo = 1326760396U;
  c108_info[19].fileTimeHi = 0U;
  c108_info[19].mFileTimeLo = 0U;
  c108_info[19].mFileTimeHi = 0U;
  c108_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c108_info[20].name = "mtimes";
  c108_info[20].dominantType = "double";
  c108_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c108_info[20].fileTimeLo = 1289552092U;
  c108_info[20].fileTimeHi = 0U;
  c108_info[20].mFileTimeLo = 0U;
  c108_info[20].mFileTimeHi = 0U;
  c108_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c108_info[21].name = "mrdivide";
  c108_info[21].dominantType = "double";
  c108_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c108_info[21].fileTimeLo = 1342843344U;
  c108_info[21].fileTimeHi = 0U;
  c108_info[21].mFileTimeLo = 1319762366U;
  c108_info[21].mFileTimeHi = 0U;
  c108_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c108_info[22].name = "rdivide";
  c108_info[22].dominantType = "double";
  c108_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c108_info[22].fileTimeLo = 1286851244U;
  c108_info[22].fileTimeHi = 0U;
  c108_info[22].mFileTimeLo = 0U;
  c108_info[22].mFileTimeHi = 0U;
  c108_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c108_info[23].name = "eml_div";
  c108_info[23].dominantType = "double";
  c108_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c108_info[23].fileTimeLo = 1313380210U;
  c108_info[23].fileTimeHi = 0U;
  c108_info[23].mFileTimeLo = 0U;
  c108_info[23].mFileTimeHi = 0U;
  c108_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c108_info[24].name = "floor";
  c108_info[24].dominantType = "double";
  c108_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c108_info[24].fileTimeLo = 1286851142U;
  c108_info[24].fileTimeHi = 0U;
  c108_info[24].mFileTimeLo = 0U;
  c108_info[24].mFileTimeHi = 0U;
  c108_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c108_info[25].name = "eml_index_class";
  c108_info[25].dominantType = "";
  c108_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c108_info[25].fileTimeLo = 1323202978U;
  c108_info[25].fileTimeHi = 0U;
  c108_info[25].mFileTimeLo = 0U;
  c108_info[25].mFileTimeHi = 0U;
  c108_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c108_info[26].name = "intmax";
  c108_info[26].dominantType = "char";
  c108_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c108_info[26].fileTimeLo = 1311287716U;
  c108_info[26].fileTimeHi = 0U;
  c108_info[26].mFileTimeLo = 0U;
  c108_info[26].mFileTimeHi = 0U;
  c108_info[27].context = "";
  c108_info[27].name = "bitget";
  c108_info[27].dominantType = "embedded.fi";
  c108_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[27].fileTimeLo = 1289552000U;
  c108_info[27].fileTimeHi = 0U;
  c108_info[27].mFileTimeLo = 0U;
  c108_info[27].mFileTimeHi = 0U;
  c108_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[28].name = "isfi";
  c108_info[28].dominantType = "double";
  c108_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c108_info[28].fileTimeLo = 1289552010U;
  c108_info[28].fileTimeHi = 0U;
  c108_info[28].mFileTimeLo = 0U;
  c108_info[28].mFileTimeHi = 0U;
  c108_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c108_info[29].name = "isnumerictype";
  c108_info[29].dominantType = "char";
  c108_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c108_info[29].fileTimeLo = 1289552012U;
  c108_info[29].fileTimeHi = 0U;
  c108_info[29].mFileTimeLo = 0U;
  c108_info[29].mFileTimeHi = 0U;
  c108_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[30].name = "eml_scalexp_compatible";
  c108_info[30].dominantType = "embedded.fi";
  c108_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c108_info[30].fileTimeLo = 1286851196U;
  c108_info[30].fileTimeHi = 0U;
  c108_info[30].mFileTimeLo = 0U;
  c108_info[30].mFileTimeHi = 0U;
  c108_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[31].name = "all";
  c108_info[31].dominantType = "logical";
  c108_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c108_info[31].fileTimeLo = 1286851234U;
  c108_info[31].fileTimeHi = 0U;
  c108_info[31].mFileTimeLo = 0U;
  c108_info[31].mFileTimeHi = 0U;
  c108_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c108_info[32].name = "eml_all_or_any";
  c108_info[32].dominantType = "char";
  c108_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c108_info[32].fileTimeLo = 1286851094U;
  c108_info[32].fileTimeHi = 0U;
  c108_info[32].mFileTimeLo = 0U;
  c108_info[32].mFileTimeHi = 0U;
  c108_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c108_info[33].name = "isequal";
  c108_info[33].dominantType = "double";
  c108_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c108_info[33].fileTimeLo = 1286851158U;
  c108_info[33].fileTimeHi = 0U;
  c108_info[33].mFileTimeLo = 0U;
  c108_info[33].mFileTimeHi = 0U;
  c108_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c108_info[34].name = "eml_isequal_core";
  c108_info[34].dominantType = "double";
  c108_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c108_info[34].fileTimeLo = 1286851186U;
  c108_info[34].fileTimeHi = 0U;
  c108_info[34].mFileTimeLo = 0U;
  c108_info[34].mFileTimeHi = 0U;
  c108_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c108_info[35].name = "eml_const_nonsingleton_dim";
  c108_info[35].dominantType = "logical";
  c108_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c108_info[35].fileTimeLo = 1286851096U;
  c108_info[35].fileTimeHi = 0U;
  c108_info[35].mFileTimeLo = 0U;
  c108_info[35].mFileTimeHi = 0U;
  c108_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[36].name = "isfixed";
  c108_info[36].dominantType = "embedded.fi";
  c108_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c108_info[36].fileTimeLo = 1336554498U;
  c108_info[36].fileTimeHi = 0U;
  c108_info[36].mFileTimeLo = 0U;
  c108_info[36].mFileTimeHi = 0U;
  c108_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m";
  c108_info[37].name = "get";
  c108_info[37].dominantType = "embedded.numerictype";
  c108_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c108_info[37].fileTimeLo = 1289551964U;
  c108_info[37].fileTimeHi = 0U;
  c108_info[37].mFileTimeLo = 0U;
  c108_info[37].mFileTimeHi = 0U;
  c108_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[38].name = "numerictype";
  c108_info[38].dominantType = "double";
  c108_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/numerictype.m";
  c108_info[38].fileTimeLo = 1289552020U;
  c108_info[38].fileTimeHi = 0U;
  c108_info[38].mFileTimeLo = 0U;
  c108_info[38].mFileTimeHi = 0U;
  c108_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/numerictype.m";
  c108_info[39].name = "length";
  c108_info[39].dominantType = "cell";
  c108_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c108_info[39].fileTimeLo = 1303178606U;
  c108_info[39].fileTimeHi = 0U;
  c108_info[39].mFileTimeLo = 0U;
  c108_info[39].mFileTimeHi = 0U;
  c108_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[40].name = "fimath";
  c108_info[40].dominantType = "embedded.fi";
  c108_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/fimath.m";
  c108_info[40].fileTimeLo = 1289552054U;
  c108_info[40].fileTimeHi = 0U;
  c108_info[40].mFileTimeLo = 0U;
  c108_info[40].mFileTimeHi = 0U;
  c108_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitget.m";
  c108_info[41].name = "eml_error";
  c108_info[41].dominantType = "int32";
  c108_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c108_info[41].fileTimeLo = 1305350400U;
  c108_info[41].fileTimeHi = 0U;
  c108_info[41].mFileTimeLo = 0U;
  c108_info[41].mFileTimeHi = 0U;
  c108_info[42].context = "";
  c108_info[42].name = "ctranspose";
  c108_info[42].dominantType = "embedded.fi";
  c108_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ctranspose.m";
  c108_info[42].fileTimeLo = 1289552036U;
  c108_info[42].fileTimeHi = 0U;
  c108_info[42].mFileTimeLo = 0U;
  c108_info[42].mFileTimeHi = 0U;
}

static void c108_eml_error(SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance,
  int32_T c108_varargin_2)
{
  int32_T c108_i11;
  static char_T c108_varargin_1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'b', 'i', 't', 'S', 'e', 't', 'G', 'e', 't', '_',
    'B', 'I', 'T', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  char_T c108_u[36];
  const mxArray *c108_y = NULL;
  int32_T c108_b_u;
  const mxArray *c108_b_y = NULL;
  int32_T c108_i12;
  static char_T c108_varargin_3[11] = { 'e', 'm', 'b', 'e', 'd', 'd', 'e', 'd',
    '.', 'f', 'i' };

  char_T c108_c_u[11];
  const mxArray *c108_c_y = NULL;
  for (c108_i11 = 0; c108_i11 < 36; c108_i11++) {
    c108_u[c108_i11] = c108_varargin_1[c108_i11];
  }

  c108_y = NULL;
  sf_mex_assign(&c108_y, sf_mex_create("y", c108_u, 10, 0U, 1U, 0U, 2, 1, 36),
                FALSE);
  c108_b_u = c108_varargin_2;
  c108_b_y = NULL;
  sf_mex_assign(&c108_b_y, sf_mex_create("y", &c108_b_u, 6, 0U, 0U, 0U, 0),
                FALSE);
  for (c108_i12 = 0; c108_i12 < 11; c108_i12++) {
    c108_c_u[c108_i12] = c108_varargin_3[c108_i12];
  }

  c108_c_y = NULL;
  sf_mex_assign(&c108_c_y, sf_mex_create("y", c108_c_u, 10, 0U, 1U, 0U, 2, 1, 11),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 3U, 14,
    c108_y, 14, c108_b_y, 14, c108_c_y));
}

static const mxArray *c108_d_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData = NULL;
  int32_T c108_u;
  const mxArray *c108_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_u = *(int32_T *)c108_inData;
  c108_y = NULL;
  sf_mex_assign(&c108_y, sf_mex_create("y", &c108_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  return c108_mxArrayOutData;
}

static int32_T c108_c_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId)
{
  int32_T c108_y;
  int32_T c108_i13;
  sf_mex_import(c108_parentId, sf_mex_dup(c108_u), &c108_i13, 1, 6, 0U, 0, 0U, 0);
  c108_y = c108_i13;
  sf_mex_destroy(&c108_u);
  return c108_y;
}

static void c108_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData)
{
  const mxArray *c108_b_sfEvent;
  const char_T *c108_identifier;
  emlrtMsgIdentifier c108_thisId;
  int32_T c108_y;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_b_sfEvent = sf_mex_dup(c108_mxArrayInData);
  c108_identifier = c108_varName;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_y = c108_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c108_b_sfEvent),
    &c108_thisId);
  sf_mex_destroy(&c108_b_sfEvent);
  *(int32_T *)c108_outData = c108_y;
  sf_mex_destroy(&c108_mxArrayInData);
}

static const mxArray *c108_e_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData;
  uint8_T c108_u;
  const mxArray *c108_y = NULL;
  uint8_T c108_b_u;
  const mxArray *c108_b_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c108_u = *(uint8_T *)c108_inData;
    c108_y = NULL;
    c108_b_u = c108_u;
    c108_b_y = NULL;
    sf_mex_assign(&c108_b_y, sf_mex_create("y", &c108_b_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
    sf_mex_assign(&c108_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
      sf_mex_dup(c108_eml_mx), 15, "numerictype", 14, sf_mex_dup(c108_c_eml_mx),
      15, "simulinkarray", 14, c108_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
    sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  } else {
    sf_mex_assign(&c108_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), FALSE);
  }

  return c108_mxArrayOutData;
}

static const mxArray *c108_f_sf_marshallOut(void *chartInstanceVoid, void
  *c108_inData)
{
  const mxArray *c108_mxArrayOutData;
  int32_T c108_i14;
  uint8_T c108_u[8];
  const mxArray *c108_y = NULL;
  int32_T c108_i15;
  uint8_T c108_b_u[8];
  const mxArray *c108_b_y = NULL;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_mxArrayOutData = NULL;
  c108_mxArrayOutData = NULL;
  for (c108_i14 = 0; c108_i14 < 8; c108_i14++) {
    c108_u[c108_i14] = (*(uint8_T (*)[8])c108_inData)[c108_i14];
  }

  c108_y = NULL;
  for (c108_i15 = 0; c108_i15 < 8; c108_i15++) {
    c108_b_u[c108_i15] = c108_u[c108_i15];
  }

  c108_b_y = NULL;
  sf_mex_assign(&c108_b_y, sf_mex_create("y", c108_b_u, 3, 0U, 1U, 0U, 1, 8),
                FALSE);
  sf_mex_assign(&c108_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c108_eml_mx), 15, "numerictype", 14, sf_mex_dup(c108_b_eml_mx), 15,
    "simulinkarray", 14, c108_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c108_mxArrayOutData, c108_y, FALSE);
  return c108_mxArrayOutData;
}

static void c108_d_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_y, const char_T *c108_identifier, uint8_T
  c108_b_y[8])
{
  emlrtMsgIdentifier c108_thisId;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c108_y), &c108_thisId,
    c108_b_y);
  sf_mex_destroy(&c108_y);
}

static void c108_e_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId,
  uint8_T c108_y[8])
{
  static uint32_T c108_uv4[1] = { 8U };

  uint32_T c108_uv5[1];
  const mxArray *c108_mxFi = NULL;
  const mxArray *c108_mxInt = NULL;
  uint8_T c108_uv6[8];
  int32_T c108_i16;
  c108_uv5[0] = c108_uv4[0];
  sf_mex_check_fi(c108_parentId, c108_u, 0, 1U, c108_uv5, c108_eml_mx,
                  c108_b_eml_mx);
  sf_mex_assign(&c108_mxFi, sf_mex_dup(c108_u), FALSE);
  sf_mex_assign(&c108_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
                 (c108_mxFi)), FALSE);
  sf_mex_import(c108_parentId, sf_mex_dup(c108_mxInt), c108_uv6, 1, 3, 0U, 1, 0U,
                1, 8);
  sf_mex_destroy(&c108_mxFi);
  sf_mex_destroy(&c108_mxInt);
  for (c108_i16 = 0; c108_i16 < 8; c108_i16++) {
    c108_y[c108_i16] = c108_uv6[c108_i16];
  }

  sf_mex_destroy(&c108_u);
}

static void c108_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c108_mxArrayInData, const char_T *c108_varName, void *c108_outData)
{
  const mxArray *c108_y;
  const char_T *c108_identifier;
  emlrtMsgIdentifier c108_thisId;
  uint8_T c108_b_y[8];
  int32_T c108_i17;
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)chartInstanceVoid;
  c108_y = sf_mex_dup(c108_mxArrayInData);
  c108_identifier = c108_varName;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c108_y), &c108_thisId,
    c108_b_y);
  sf_mex_destroy(&c108_y);
  for (c108_i17 = 0; c108_i17 < 8; c108_i17++) {
    (*(uint8_T (*)[8])c108_outData)[c108_i17] = c108_b_y[c108_i17];
  }

  sf_mex_destroy(&c108_mxArrayInData);
}

static uint8_T c108_f_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_b_is_active_c108_QPSK_Transmit_v8, const
  char_T *c108_identifier)
{
  uint8_T c108_y;
  emlrtMsgIdentifier c108_thisId;
  c108_thisId.fIdentifier = c108_identifier;
  c108_thisId.fParent = NULL;
  c108_y = c108_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c108_b_is_active_c108_QPSK_Transmit_v8), &c108_thisId);
  sf_mex_destroy(&c108_b_is_active_c108_QPSK_Transmit_v8);
  return c108_y;
}

static uint8_T c108_g_emlrt_marshallIn(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, const mxArray *c108_u, const emlrtMsgIdentifier *c108_parentId)
{
  uint8_T c108_y;
  uint8_T c108_u0;
  sf_mex_import(c108_parentId, sf_mex_dup(c108_u), &c108_u0, 1, 3, 0U, 0, 0U, 0);
  c108_y = c108_u0;
  sf_mex_destroy(&c108_u);
  return c108_y;
}

static uint32_T c108__u32_minus__(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, uint32_T c108_b, uint32_T c108_c)
{
  uint32_T c108_a;
  c108_a = c108_b - c108_c;
  if (c108_b < c108_c) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c108_a;
}

static uint8_T c108__u8_u32_(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance, uint32_T c108_b)
{
  uint8_T c108_a;
  c108_a = (uint8_T)c108_b;
  if (c108_a != c108_b) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c108_a;
}

static uint8_T c108__u8_d_(SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance,
  real_T c108_b)
{
  uint8_T c108_a;
  c108_a = (uint8_T)c108_b;
  if ((real_T)c108_a != (c108_b < 0.0 ? muDoubleScalarCeil(c108_b) :
                         muDoubleScalarFloor(c108_b))) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c108_a;
}

static void init_dsm_address_info(SFc108_QPSK_Transmit_v8InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c108_QPSK_Transmit_v8_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2826370952U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3435372786U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1942507647U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(112040972U);
}

mxArray *sf_c108_QPSK_Transmit_v8_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7TU25sLgkAPKDTGVcCFjZB");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(8));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(8);
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
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c108_QPSK_Transmit_v8(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c108_QPSK_Transmit_v8\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c108_QPSK_Transmit_v8_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
    chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QPSK_Transmit_v8MachineNumber_,
           108,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QPSK_Transmit_v8MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QPSK_Transmit_v8MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QPSK_Transmit_v8MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,94);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,1,0,8,0,1,0,0,
          (MexFcnForType)c108_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),1,0,1,0,1,0,
            0,(MexFcnForType)c108_f_sf_marshallOut,(MexInFcnForType)
            c108_d_sf_marshallIn);
        }

        {
          uint8_T *c108_u;
          uint8_T (*c108_y)[8];
          c108_y = (uint8_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          c108_u = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c108_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c108_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QPSK_Transmit_v8MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ktTsrVJg9YXtjzozbGyBdF";
}

static void sf_opaque_initialize_c108_QPSK_Transmit_v8(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
  initialize_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c108_QPSK_Transmit_v8(void *chartInstanceVar)
{
  enable_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c108_QPSK_Transmit_v8(void *chartInstanceVar)
{
  disable_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c108_QPSK_Transmit_v8(void *chartInstanceVar)
{
  sf_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c108_QPSK_Transmit_v8(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c108_QPSK_Transmit_v8
    ((SFc108_QPSK_Transmit_v8InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c108_QPSK_Transmit_v8();/* state var info */
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

extern void sf_internal_set_sim_state_c108_QPSK_Transmit_v8(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c108_QPSK_Transmit_v8();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c108_QPSK_Transmit_v8(SimStruct* S)
{
  return sf_internal_get_sim_state_c108_QPSK_Transmit_v8(S);
}

static void sf_opaque_set_sim_state_c108_QPSK_Transmit_v8(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c108_QPSK_Transmit_v8(S, st);
}

static void sf_opaque_terminate_c108_QPSK_Transmit_v8(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc108_QPSK_Transmit_v8InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QPSK_Transmit_v8_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc108_QPSK_Transmit_v8((SFc108_QPSK_Transmit_v8InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c108_QPSK_Transmit_v8(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c108_QPSK_Transmit_v8
      ((SFc108_QPSK_Transmit_v8InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c108_QPSK_Transmit_v8(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QPSK_Transmit_v8_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      108);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,108,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,108,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,108,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,108,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,108);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3649955841U));
  ssSetChecksum1(S,(13867300U));
  ssSetChecksum2(S,(2986429940U));
  ssSetChecksum3(S,(2120675668U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c108_QPSK_Transmit_v8(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c108_QPSK_Transmit_v8(SimStruct *S)
{
  SFc108_QPSK_Transmit_v8InstanceStruct *chartInstance;
  chartInstance = (SFc108_QPSK_Transmit_v8InstanceStruct *)malloc(sizeof
    (SFc108_QPSK_Transmit_v8InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc108_QPSK_Transmit_v8InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.mdlStart = mdlStart_c108_QPSK_Transmit_v8;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c108_QPSK_Transmit_v8;
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

void c108_QPSK_Transmit_v8_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c108_QPSK_Transmit_v8(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c108_QPSK_Transmit_v8(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c108_QPSK_Transmit_v8(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c108_QPSK_Transmit_v8_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
