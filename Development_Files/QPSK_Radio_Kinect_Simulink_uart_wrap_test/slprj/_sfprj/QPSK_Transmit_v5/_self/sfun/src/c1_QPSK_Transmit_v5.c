/* Include files */

#include "blascompat32.h"
#include "QPSK_Transmit_v5_sfun.h"
#include "c1_QPSK_Transmit_v5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QPSK_Transmit_v5_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[7] = { "OS_RATE", "f", "nargin",
  "nargout", "d_in", "d_out", "buf" };

static const char * c1_b_debug_family_names[3] = { "y", "nargin", "nargout" };

/* Function Declarations */
static void initialize_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);
static void initialize_params_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance);
static void enable_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);
static void disable_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance);
static void set_sim_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);
static void sf_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);
static void initSimStructsc1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_b_buf, const char_T *c1_identifier, creal_T
  c1_y[17]);
static void c1_b_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  creal_T c1_y[17]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static creal_T c1_c_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_d_out, const char_T *c1_identifier);
static creal_T c1_d_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[17]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_h_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_QPSK_Transmit_v5, const
  char_T *c1_identifier);
static uint8_T c1_i_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_buf_not_empty = FALSE;
  chartInstance->c1_is_active_c1_QPSK_Transmit_v5 = 0U;
}

static void initialize_params_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance)
{
}

static void enable_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  creal_T c1_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i0;
  creal_T c1_b_u[17];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  creal_T *c1_d_out;
  c1_d_out = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_u.re = c1_d_out->re;
  c1_u.im = c1_d_out->im;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i0 = 0; c1_i0 < 17; c1_i0++) {
    c1_b_u[c1_i0] = chartInstance->c1_buf[c1_i0];
  }

  c1_c_y = NULL;
  if (!chartInstance->c1_buf_not_empty) {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_QPSK_Transmit_v5;
  c1_c_u = c1_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  creal_T c1_dcv0[17];
  int32_T c1_i1;
  creal_T *c1_d_out;
  c1_d_out = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_d_out = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "d_out");
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)), "buf",
                      c1_dcv0);
  for (c1_i1 = 0; c1_i1 < 17; c1_i1++) {
    chartInstance->c1_buf[c1_i1] = c1_dcv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_QPSK_Transmit_v5 = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_QPSK_Transmit_v5");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_QPSK_Transmit_v5(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
}

static void sf_c1_QPSK_Transmit_v5(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_d_in;
  uint32_T c1_debug_family_var_map[7];
  real_T c1_OS_RATE;
  real_T c1_f[17];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  creal_T c1_d_out;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_y[17];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i2;
  static real_T c1_b[17] = { 0.006690562067, -0.00576859381, -0.011827354519,
    0.020586915021, 0.016726405168, -0.053692342207, -0.020253031546,
    0.196043589067, 0.33682241319, 0.196043589067, -0.020253031546,
    -0.053692342207, 0.016726405168, 0.020586915021, -0.011827354519,
    -0.00576859381, 0.006690562067 };

  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  creal_T c1_dcv1[17];
  int32_T c1_i6;
  int32_T c1_i7;
  creal_T c1_b_hoistedGlobal[17];
  creal_T c1_dc0;
  int32_T c1_i8;
  creal_T c1_b_b;
  creal_T c1_c_hoistedGlobal;
  real_T *c1_b_d_in;
  creal_T *c1_b_d_out;
  c1_b_d_out = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_d_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_d_in, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_d_in;
  c1_d_in = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_OS_RATE, 0U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_f, 1U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_d_in, 4U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_d_out, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c1_buf, 6U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_OS_RATE = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  sf_debug_symbol_scope_push_eml(0U, 3U, 3U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 0U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i2 = 0; c1_i2 < 17; c1_i2++) {
    c1_y[c1_i2] = c1_b[c1_i2];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  for (c1_i3 = 0; c1_i3 < 17; c1_i3++) {
    c1_f[c1_i3] = c1_b[c1_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_buf_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
    for (c1_i4 = 0; c1_i4 < 17; c1_i4++) {
      chartInstance->c1_buf[c1_i4].re = 0.0;
      chartInstance->c1_buf[c1_i4].im = 0.0;
    }

    chartInstance->c1_buf_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  for (c1_i5 = 0; c1_i5 < 16; c1_i5++) {
    c1_dcv1[c1_i5] = chartInstance->c1_buf[c1_i5 + 1];
  }

  c1_dcv1[16].re = c1_d_in;
  c1_dcv1[16].im = 0.0;
  for (c1_i6 = 0; c1_i6 < 17; c1_i6++) {
    chartInstance->c1_buf[c1_i6] = c1_dcv1[c1_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  for (c1_i7 = 0; c1_i7 < 17; c1_i7++) {
    c1_b_hoistedGlobal[c1_i7] = chartInstance->c1_buf[c1_i7];
  }

  c1_dc0.re = 0.0;
  c1_dc0.im = 0.0;
  for (c1_i8 = 0; c1_i8 < 17; c1_i8++) {
    c1_b_b.re = c1_b[c1_i8];
    c1_b_b.im = 0.0;
    c1_c_hoistedGlobal.re = c1_b_hoistedGlobal[c1_i8].re * c1_b_b.re -
      c1_b_hoistedGlobal[c1_i8].im * c1_b_b.im;
    c1_c_hoistedGlobal.im = c1_b_hoistedGlobal[c1_i8].re * c1_b_b.im +
      c1_b_hoistedGlobal[c1_i8].im * c1_b_b.re;
    c1_dc0.re += c1_c_hoistedGlobal.re;
    c1_dc0.im += c1_c_hoistedGlobal.im;
  }

  c1_d_out = c1_dc0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  c1_b_d_out->re = c1_d_out.re;
  c1_b_d_out->im = c1_d_out.im;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_QPSK_Transmit_v5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_QPSK_Transmit_v5
  (SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance)
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
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i9;
  creal_T c1_b_inData[17];
  int32_T c1_i10;
  creal_T c1_u[17];
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i9 = 0; c1_i9 < 17; c1_i9++) {
    c1_b_inData[c1_i9] = (*(creal_T (*)[17])c1_inData)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 17; c1_i10++) {
    c1_u[c1_i10] = c1_b_inData[c1_i10];
  }

  c1_y = NULL;
  if (!chartInstance->c1_buf_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 1, 17),
                  FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_b_buf, const char_T *c1_identifier, creal_T
  c1_y[17])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_buf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_buf);
}

static void c1_b_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  creal_T c1_y[17])
{
  creal_T c1_dcv2[17];
  int32_T c1_i11;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_buf_not_empty = FALSE;
  } else {
    chartInstance->c1_buf_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dcv2, 1, 0, 1U, 1, 0U, 2, 1,
                  17);
    for (c1_i11 = 0; c1_i11 < 17; c1_i11++) {
      c1_y[c1_i11] = c1_dcv2[c1_i11];
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
  creal_T c1_y[17];
  int32_T c1_i12;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_b_buf = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_buf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_buf);
  for (c1_i12 = 0; c1_i12 < 17; c1_i12++) {
    (*(creal_T (*)[17])c1_outData)[c1_i12] = c1_y[c1_i12];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  creal_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(creal_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static creal_T c1_c_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_d_out, const char_T *c1_identifier)
{
  creal_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_out), &c1_thisId);
  sf_mex_destroy(&c1_d_out);
  return c1_y;
}

static creal_T c1_d_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  creal_T c1_y;
  creal_T c1_dc1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_dc1, 1, 0, 1U, 0, 0U, 0);
  c1_y = c1_dc1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d_out;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  creal_T c1_y;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_d_out = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_out), &c1_thisId);
  sf_mex_destroy(&c1_d_out);
  *(creal_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
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
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i13;
  real_T c1_b_inData[17];
  int32_T c1_i14;
  real_T c1_u[17];
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i13 = 0; c1_i13 < 17; c1_i13++) {
    c1_b_inData[c1_i13] = (*(real_T (*)[17])c1_inData)[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 17; c1_i14++) {
    c1_u[c1_i14] = c1_b_inData[c1_i14];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 17), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[17])
{
  real_T c1_dv0[17];
  int32_T c1_i15;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 17);
  for (c1_i15 = 0; c1_i15 < 17; c1_i15++) {
    c1_y[c1_i15] = c1_dv0[c1_i15];
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
  int32_T c1_i16;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i16 = 0; c1_i16 < 17; c1_i16++) {
    (*(real_T (*)[17])c1_outData)[c1_i16] = c1_b_y[c1_i16];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_QPSK_Transmit_v5_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[2];
  c1_ResolvedFunctionInfo (*c1_b_info)[2];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i17;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[2])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "SRRC";
  (*c1_b_info)[0].dominantType = "";
  (*c1_b_info)[0].resolved =
    "[E]C:/UCSD/Capstone/Development_Files/QPSK_Radio_Kinect_Simulink/SRRC.m";
  (*c1_b_info)[0].fileTimeLo = 1366660138U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "mtimes";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[1].fileTimeLo = 1289552092U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    c1_r0 = &c1_info[c1_i17];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i17);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i17);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i18;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i18, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i18;
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
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_QPSK_Transmit_v5, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_QPSK_Transmit_v5), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_QPSK_Transmit_v5);
  return c1_y;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_QPSK_Transmit_v5InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_QPSK_Transmit_v5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3044697069U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1452239826U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1113958707U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(778216384U);
}

mxArray *sf_c1_QPSK_Transmit_v5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("goraYtEsffT59XvMSMBY8C");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
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

static const mxArray *sf_get_sim_state_info_c1_QPSK_Transmit_v5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"d_out\",},{M[4],M[0],T\"buf\",S'l','i','p'{{M1x2[46 49],M[0],}}},{M[8],M[0],T\"is_active_c1_QPSK_Transmit_v5\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_QPSK_Transmit_v5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
    chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_QPSK_Transmit_v5MachineNumber_,
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
          init_script_number_translation(_QPSK_Transmit_v5MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_QPSK_Transmit_v5MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QPSK_Transmit_v5MachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,199);
        _SFD_CV_INIT_EML_IF(0,1,0,75,90,-1,156);
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

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          real_T *c1_d_in;
          creal_T *c1_d_out;
          c1_d_out = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_d_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_d_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_d_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QPSK_Transmit_v5MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "wVokVpqEgSAriGwqyrV7y";
}

static void sf_opaque_initialize_c1_QPSK_Transmit_v5(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar);
  initialize_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_QPSK_Transmit_v5(void *chartInstanceVar)
{
  enable_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_QPSK_Transmit_v5(void *chartInstanceVar)
{
  disable_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_QPSK_Transmit_v5(void *chartInstanceVar)
{
  sf_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_QPSK_Transmit_v5(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_QPSK_Transmit_v5
    ((SFc1_QPSK_Transmit_v5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_QPSK_Transmit_v5();/* state var info */
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

extern void sf_internal_set_sim_state_c1_QPSK_Transmit_v5(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_QPSK_Transmit_v5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_QPSK_Transmit_v5(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_QPSK_Transmit_v5(S);
}

static void sf_opaque_set_sim_state_c1_QPSK_Transmit_v5(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_QPSK_Transmit_v5(S, st);
}

static void sf_opaque_terminate_c1_QPSK_Transmit_v5(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_QPSK_Transmit_v5InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_QPSK_Transmit_v5_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_QPSK_Transmit_v5(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_QPSK_Transmit_v5((SFc1_QPSK_Transmit_v5InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_QPSK_Transmit_v5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QPSK_Transmit_v5_optimization_info();
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
  ssSetChecksum0(S,(1382727465U));
  ssSetChecksum1(S,(1826769868U));
  ssSetChecksum2(S,(2925688491U));
  ssSetChecksum3(S,(2188971603U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_QPSK_Transmit_v5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_QPSK_Transmit_v5(SimStruct *S)
{
  SFc1_QPSK_Transmit_v5InstanceStruct *chartInstance;
  chartInstance = (SFc1_QPSK_Transmit_v5InstanceStruct *)malloc(sizeof
    (SFc1_QPSK_Transmit_v5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_QPSK_Transmit_v5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_QPSK_Transmit_v5;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_QPSK_Transmit_v5;
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

void c1_QPSK_Transmit_v5_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_QPSK_Transmit_v5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_QPSK_Transmit_v5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_QPSK_Transmit_v5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_QPSK_Transmit_v5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
