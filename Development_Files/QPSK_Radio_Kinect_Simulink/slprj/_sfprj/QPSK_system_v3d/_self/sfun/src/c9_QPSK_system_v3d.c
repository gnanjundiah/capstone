/* Include files */

#include "blascompat32.h"
#include "QPSK_system_v3d_sfun.h"
#include "c9_QPSK_system_v3d.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QPSK_system_v3d_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *c9_eml_mx;
static const char * c9_debug_family_names[5] = { "fm", "nargin", "nargout",
  "d_in", "d_out" };

static const mxArray *c9_b_eml_mx;
static const mxArray *c9_c_eml_mx;
static const mxArray *c9_d_eml_mx;

/* Function Declarations */
static void initialize_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);
static void initialize_params_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance);
static void enable_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);
static void disable_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance);
static void set_sim_state_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct *
  chartInstance, const mxArray *c9_st);
static void finalize_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);
static void sf_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);
static void initSimStructsc9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static cint16_T c9_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_b_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[13]);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static cint16_T c9_d_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_d_out, const char_T *c9_identifier);
static cint16_T c9_e_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_f_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_QPSK_system_v3d, const char_T
  *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static int32_T c9_MultiWord2sLong(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const uint32_T c9_u[]);
static void init_dsm_address_info(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_QPSK_system_v3d = 0U;
  sf_mex_assign(&c9_d_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 36.0, 15, "FractionLength", 6, 11.0, 15, "BinaryPoint", 6,
    11.0, 15, "Slope", 6, 0.00048828125, 15, "FixedExponent", 6, -11.0), TRUE);
  sf_mex_assign(&c9_c_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15,
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
  sf_mex_assign(&c9_b_eml_mx, sf_mex_call_debug("numerictype", 1U, 10U, 15,
    "WordLength", 6, 12.0, 15, "FractionLength", 6, 11.0, 15, "BinaryPoint", 6,
    11.0, 15, "Slope", 6, 0.00048828125, 15, "FixedExponent", 6, -11.0), TRUE);
  sf_mex_assign(&c9_eml_mx, sf_mex_call_debug("fimath", 1U, 42U, 15, "RoundMode",
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

static void initialize_params_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance)
{
}

static void enable_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_QPSK_system_v3d
  (SFc9_QPSK_system_v3dInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  const mxArray *c9_b_y = NULL;
  cint16_T c9_u;
  const mxArray *c9_c_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_d_y = NULL;
  cint16_T *c9_d_out;
  c9_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  c9_b_y = NULL;
  c9_u.re = c9_d_out->re;
  c9_u.im = c9_d_out->im;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c9_c_eml_mx), 15, "numerictype", 14, sf_mex_dup(c9_b_eml_mx), 15,
    "simulinkarray", 14, c9_c_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_QPSK_system_v3d;
  c9_b_u = c9_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_d_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct *
  chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  cint16_T *c9_d_out;
  c9_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_d_out = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "d_out");
  chartInstance->c9_is_active_c9_QPSK_system_v3d = c9_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
     "is_active_c9_QPSK_system_v3d");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_QPSK_system_v3d(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c9_eml_mx);
  sf_mex_destroy(&c9_b_eml_mx);
  sf_mex_destroy(&c9_c_eml_mx);
  sf_mex_destroy(&c9_d_eml_mx);
}

static void sf_c9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
  cint64m_T c9_d_in;
  uint32_T c9_debug_family_var_map[5];
  const mxArray *c9_fm = NULL;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  cint16_T c9_d_out;
  cint64m_T c9_varargin_1;
  const mxArray *c9_propVal = NULL;
  const mxArray *c9_errmsg = NULL;
  const mxArray *c9_b_propVal = NULL;
  const mxArray *c9_b_errmsg = NULL;
  int16_T c9_i0;
  cint16_T c9_b_varargin_1;
  int16_T c9_i1;
  const mxArray *c9_T = NULL;
  const mxArray *c9_F = NULL;
  const mxArray *c9_ERR = NULL;
  const mxArray *c9_val = NULL;
  const mxArray *c9_isautoscaled = NULL;
  const mxArray *c9_pvpairsetdata = NULL;
  const mxArray *c9_isfimathlocal = NULL;
  cint16_T *c9_b_d_out;
  cint64m_T *c9_b_d_in;
  c9_b_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_d_in = (cint64m_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  c9_d_in.re = c9_b_d_in->re;
  c9_d_in.im = c9_b_d_in->im;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_fm, 0U, c9_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 1U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 2U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_d_in, 3U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_d_out, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_fm = c9_eml_mx;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_varargin_1 = c9_d_in;
  sf_mex_destroy(&c9_propVal);
  sf_mex_destroy(&c9_errmsg);
  sf_mex_destroy(&c9_b_propVal);
  sf_mex_destroy(&c9_b_errmsg);
  c9_i0 = (int16_T)c9_MultiWord2sLong(chartInstance, &c9_varargin_1.re.chunks[0U]);
  if ((int16_T)(c9_i0 & 2048) != 0) {
    c9_b_varargin_1.re = (int16_T)(c9_i0 | -2048);
  } else {
    c9_b_varargin_1.re = (int16_T)(c9_i0 & 2047);
  }

  c9_i1 = (int16_T)c9_MultiWord2sLong(chartInstance, &c9_varargin_1.im.chunks[0U]);
  if ((int16_T)(c9_i1 & 2048) != 0) {
    c9_b_varargin_1.im = (int16_T)(c9_i1 | -2048);
  } else {
    c9_b_varargin_1.im = (int16_T)(c9_i1 & 2047);
  }

  c9_d_out = c9_b_varargin_1;
  sf_mex_destroy(&c9_T);
  sf_mex_destroy(&c9_F);
  sf_mex_destroy(&c9_ERR);
  sf_mex_destroy(&c9_val);
  sf_mex_destroy(&c9_isautoscaled);
  sf_mex_destroy(&c9_pvpairsetdata);
  sf_mex_destroy(&c9_isfimathlocal);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  c9_b_d_out->re = c9_d_out.re;
  c9_b_d_out->im = c9_d_out.im;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  sf_debug_check_for_state_inconsistency(_QPSK_system_v3dMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_QPSK_system_v3d(SFc9_QPSK_system_v3dInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  cint16_T c9_u;
  const mxArray *c9_y = NULL;
  cint16_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(cint16_T *)c9_inData;
  c9_y = NULL;
  c9_b_u.re = c9_u.re;
  c9_b_u.im = c9_u.im;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c9_eml_mx), 15, "numerictype", 14, sf_mex_dup(c9_b_eml_mx), 15,
    "simulinkarray", 14, c9_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static cint16_T c9_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  cint16_T c9_y;
  const mxArray *c9_mxFi = NULL;
  const mxArray *c9_mxInt = NULL;
  cint16_T c9_ic0;
  sf_mex_check_fi(c9_parentId, c9_u, 1, 0U, 0, c9_eml_mx, c9_b_eml_mx);
  sf_mex_assign(&c9_mxFi, sf_mex_dup(c9_u), FALSE);
  sf_mex_assign(&c9_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c9_mxFi)), FALSE);
  sf_mex_import(c9_parentId, sf_mex_dup(c9_mxInt), &c9_ic0, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c9_mxFi);
  sf_mex_destroy(&c9_mxInt);
  c9_y = c9_ic0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_d_out;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  cint16_T c9_y;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_d_out = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_out), &c9_thisId);
  sf_mex_destroy(&c9_d_out);
  *(cint16_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  cint64m_T c9_u;
  const mxArray *c9_y = NULL;
  cint64m_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(cint64m_T *)c9_inData;
  c9_y = NULL;
  c9_b_u.re = c9_u.re;
  c9_b_u.im = c9_u.im;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 7, 1U, 0U, 8U, 1, 2), FALSE);
  sf_mex_assign(&c9_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c9_c_eml_mx), 15, "numerictype", 14, sf_mex_dup(c9_d_eml_mx), 15,
    "simulinkarray", 14, c9_b_y, 15, "fimathislocal", 3, FALSE), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_b_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  const mxArray *c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = sf_mex_dup(*(const mxArray **)c9_inData);
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), FALSE);
  sf_mex_destroy(&c9_u);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_QPSK_system_v3d_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[13];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i2;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c9_i2 = 0; c9_i2 < 13; c9_i2++) {
    c9_r0 = &c9_info[c9_i2];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i2);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i2);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[13])
{
  c9_info[0].context = "";
  c9_info[0].name = "hdlfimath";
  c9_info[0].dominantType = "";
  c9_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c9_info[0].fileTimeLo = 1289552008U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/hdlfimath.m";
  c9_info[1].name = "fimath";
  c9_info[1].dominantType = "char";
  c9_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fimath.m";
  c9_info[1].fileTimeLo = 1289552004U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "fi_impl";
  c9_info[2].dominantType = "";
  c9_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m";
  c9_info[2].fileTimeLo = 1326760396U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c9_info[3].name = "length";
  c9_info[3].dominantType = "cell";
  c9_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c9_info[3].fileTimeLo = 1303178606U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c9_info[4].name = "eml_fi_checkforconst";
  c9_info[4].dominantType = "embedded.fimath";
  c9_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforconst.m";
  c9_info[4].fileTimeLo = 1326760394U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c9_info[5].name = "isfi";
  c9_info[5].dominantType = "embedded.fi";
  c9_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c9_info[5].fileTimeLo = 1289552010U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c9_info[6].name = "isnumerictype";
  c9_info[6].dominantType = "embedded.numerictype";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  c9_info[6].fileTimeLo = 1289552012U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c9_info[7].name = "isfloat";
  c9_info[7].dominantType = "embedded.fi";
  c9_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c9_info[7].fileTimeLo = 1336554498U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfloat.m";
  c9_info[8].name = "get";
  c9_info[8].dominantType = "embedded.numerictype";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m";
  c9_info[8].fileTimeLo = 1289551964U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c9_info[9].name = "isfi";
  c9_info[9].dominantType = "embedded.fi";
  c9_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  c9_info[9].fileTimeLo = 1289552010U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c9_info[10].name = "numerictype";
  c9_info[10].dominantType = "embedded.fi";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/numerictype.m";
  c9_info[10].fileTimeLo = 1289552076U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!local_createConstDataFromInput";
  c9_info[11].name = "fimath";
  c9_info[11].dominantType = "embedded.fi";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/fimath.m";
  c9_info[11].fileTimeLo = 1289552054U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  c9_info[12].name = "eml_fi_checkforntype";
  c9_info[12].dominantType = "embedded.fi";
  c9_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforntype.m";
  c9_info[12].fileTimeLo = 1289552002U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i3;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i3, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i3;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  cint64m_T c9_u;
  const mxArray *c9_y = NULL;
  cint64m_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(cint64m_T *)c9_inData;
  c9_y = NULL;
  c9_b_u.re = c9_u.re;
  c9_b_u.im = c9_u.im;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 7, 1U, 0U, 8U, 1, 2), FALSE);
  sf_mex_assign(&c9_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c9_c_eml_mx), 15, "numerictype", 14, sf_mex_dup(c9_d_eml_mx), 15,
    "simulinkarray", 14, c9_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  cint16_T c9_u;
  const mxArray *c9_y = NULL;
  cint16_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(cint16_T *)c9_inData;
  c9_y = NULL;
  c9_b_u.re = c9_u.re;
  c9_b_u.im = c9_u.im;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 4, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c9_c_eml_mx), 15, "numerictype", 14, sf_mex_dup(c9_b_eml_mx), 15,
    "simulinkarray", 14, c9_b_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static cint16_T c9_d_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_d_out, const char_T *c9_identifier)
{
  cint16_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_out), &c9_thisId);
  sf_mex_destroy(&c9_d_out);
  return c9_y;
}

static cint16_T c9_e_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  cint16_T c9_y;
  const mxArray *c9_mxFi = NULL;
  const mxArray *c9_mxInt = NULL;
  cint16_T c9_ic1;
  sf_mex_check_fi(c9_parentId, c9_u, 1, 0U, 0, c9_c_eml_mx, c9_b_eml_mx);
  sf_mex_assign(&c9_mxFi, sf_mex_dup(c9_u), FALSE);
  sf_mex_assign(&c9_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c9_mxFi)), FALSE);
  sf_mex_import(c9_parentId, sf_mex_dup(c9_mxInt), &c9_ic1, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c9_mxFi);
  sf_mex_destroy(&c9_mxInt);
  c9_y = c9_ic1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_d_out;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  cint16_T c9_y;
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)chartInstanceVoid;
  c9_d_out = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_out), &c9_thisId);
  sf_mex_destroy(&c9_d_out);
  *(cint16_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_QPSK_system_v3d, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_QPSK_system_v3d), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_QPSK_system_v3d);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static int32_T c9_MultiWord2sLong(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance, const uint32_T c9_u[])
{
  return (int32_T)c9_u[0];
}

static void init_dsm_address_info(SFc9_QPSK_system_v3dInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_QPSK_system_v3d_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3014131817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4017093829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3608694141U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(601726192U);
}

mxArray *sf_c9_QPSK_system_v3d_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Eu9ijzY8VOo8N6PuMe6NIG");
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
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(36));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-11));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

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

static const mxArray *sf_get_sim_state_info_c9_QPSK_system_v3d(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"d_out\",},{M[8],M[0],T\"is_active_c9_QPSK_system_v3d\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_QPSK_system_v3d_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
    chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QPSK_system_v3dMachineNumber_,
           9,
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
          init_script_number_translation(_QPSK_system_v3dMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QPSK_system_v3dMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QPSK_system_v3dMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,86);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,0,NULL,1,1,36,0,1,-11,1,
          (MexFcnForType)c9_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,12,0,1,-11,1,
          (MexFcnForType)c9_g_sf_marshallOut,(MexInFcnForType)c9_d_sf_marshallIn);

        {
          cint64m_T *c9_d_in;
          cint16_T *c9_d_out;
          c9_d_out = (cint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_d_in = (cint64m_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_d_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_d_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QPSK_system_v3dMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "4o89Km4KKPIvfuVZzdzMkG";
}

static void sf_opaque_initialize_c9_QPSK_system_v3d(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar);
  initialize_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_QPSK_system_v3d(void *chartInstanceVar)
{
  enable_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_QPSK_system_v3d(void *chartInstanceVar)
{
  disable_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_QPSK_system_v3d(void *chartInstanceVar)
{
  sf_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_QPSK_system_v3d(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_QPSK_system_v3d
    ((SFc9_QPSK_system_v3dInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QPSK_system_v3d();/* state var info */
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

extern void sf_internal_set_sim_state_c9_QPSK_system_v3d(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QPSK_system_v3d();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_QPSK_system_v3d(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_QPSK_system_v3d(S);
}

static void sf_opaque_set_sim_state_c9_QPSK_system_v3d(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_QPSK_system_v3d(S, st);
}

static void sf_opaque_terminate_c9_QPSK_system_v3d(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_QPSK_system_v3dInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QPSK_system_v3d_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_QPSK_system_v3d(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_QPSK_system_v3d((SFc9_QPSK_system_v3dInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_QPSK_system_v3d(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QPSK_system_v3d_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1242422149U));
  ssSetChecksum1(S,(3775087199U));
  ssSetChecksum2(S,(2490479457U));
  ssSetChecksum3(S,(2190816792U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_QPSK_system_v3d(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_QPSK_system_v3d(SimStruct *S)
{
  SFc9_QPSK_system_v3dInstanceStruct *chartInstance;
  chartInstance = (SFc9_QPSK_system_v3dInstanceStruct *)malloc(sizeof
    (SFc9_QPSK_system_v3dInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_QPSK_system_v3dInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_QPSK_system_v3d;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_QPSK_system_v3d;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_QPSK_system_v3d;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_QPSK_system_v3d;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_QPSK_system_v3d;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_QPSK_system_v3d;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_QPSK_system_v3d;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_QPSK_system_v3d;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_QPSK_system_v3d;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_QPSK_system_v3d;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_QPSK_system_v3d;
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

void c9_QPSK_system_v3d_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_QPSK_system_v3d(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_QPSK_system_v3d(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_QPSK_system_v3d(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_QPSK_system_v3d_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
