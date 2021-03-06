/* Include files */

#include "QPSK_Transmit_v5_w_FIFO_w_errors_sfun.h"
#include "c108_QPSK_Transmit_v5_w_FIFO_w_errors.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QPSK_Transmit_v5_w_FIFO_w_errorsMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QPSK_Transmit_v5_w_FIFO_w_errors_initializer(void)
{
}

void QPSK_Transmit_v5_w_FIFO_w_errors_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QPSK_Transmit_v5_w_FIFO_w_errors_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==108) {
    c108_QPSK_Transmit_v5_w_FIFO_w_errors_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_QPSK_Transmit_v5_w_FIFO_w_errors_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(821103131U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4144251792U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(280647502U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2089557122U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(929410682U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3920453238U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3159021038U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3080010394U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 108:
        {
          extern void sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_check_sum
            (mxArray *plhs[]);
          sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2938571581U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2966859974U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2886210162U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1659261649U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4097019454U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1494961264U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1698924111U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1344585566U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QPSK_Transmit_v5_w_FIFO_w_errors_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 108:
      {
        if (strcmp(aiChksum, "7TU25sLgkAPKDTGVcCFjZB") == 0) {
          extern mxArray
            *sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QPSK_Transmit_v5_w_FIFO_w_errors_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 108:
      {
        extern const mxArray
          *sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c108_QPSK_Transmit_v5_w_FIFO_w_errors_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void QPSK_Transmit_v5_w_FIFO_w_errors_debug_initialize(void)
{
  _QPSK_Transmit_v5_w_FIFO_w_errorsMachineNumber_ = sf_debug_initialize_machine(
    "QPSK_Transmit_v5_w_FIFO_w_errors","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_QPSK_Transmit_v5_w_FIFO_w_errorsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_QPSK_Transmit_v5_w_FIFO_w_errorsMachineNumber_,0);
}

void QPSK_Transmit_v5_w_FIFO_w_errors_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QPSK_Transmit_v5_w_FIFO_w_errors_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "QPSK_Transmit_v5_w_FIFO_w_errors", "QPSK_Transmit_v5_w_FIFO_w_errors");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QPSK_Transmit_v5_w_FIFO_w_errors_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
