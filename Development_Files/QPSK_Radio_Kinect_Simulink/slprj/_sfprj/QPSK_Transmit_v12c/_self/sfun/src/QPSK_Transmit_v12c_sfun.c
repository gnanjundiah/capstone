/* Include files */

#include "QPSK_Transmit_v12c_sfun.h"
#include "c2_QPSK_Transmit_v12c.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QPSK_Transmit_v12cMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QPSK_Transmit_v12c_initializer(void)
{
}

void QPSK_Transmit_v12c_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QPSK_Transmit_v12c_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_QPSK_Transmit_v12c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_QPSK_Transmit_v12c_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3226061228U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1812261287U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1138554575U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2804265651U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4214734673U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3608515111U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4069469564U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4000591237U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_QPSK_Transmit_v12c_get_check_sum(mxArray *plhs[]);
          sf_c2_QPSK_Transmit_v12c_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2498883144U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3267089702U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1429006447U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3230300488U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QPSK_Transmit_v12c_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(aiChksum, "7TU25sLgkAPKDTGVcCFjZB") == 0) {
          extern mxArray *sf_c2_QPSK_Transmit_v12c_get_autoinheritance_info(void);
          plhs[0] = sf_c2_QPSK_Transmit_v12c_get_autoinheritance_info();
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

unsigned int sf_QPSK_Transmit_v12c_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern const mxArray
          *sf_c2_QPSK_Transmit_v12c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_QPSK_Transmit_v12c_get_eml_resolved_functions_info();
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

void QPSK_Transmit_v12c_debug_initialize(void)
{
  _QPSK_Transmit_v12cMachineNumber_ = sf_debug_initialize_machine(
    "QPSK_Transmit_v12c","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_QPSK_Transmit_v12cMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_QPSK_Transmit_v12cMachineNumber_,0);
}

void QPSK_Transmit_v12c_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QPSK_Transmit_v12c_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "QPSK_Transmit_v12c", "QPSK_Transmit_v12c");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QPSK_Transmit_v12c_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
