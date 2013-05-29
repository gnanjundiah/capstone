/* Include files */

#include "QPSK_Transmit_v10_sfun.h"
#include "c1_QPSK_Transmit_v10.h"
#include "c108_QPSK_Transmit_v10.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QPSK_Transmit_v10MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void QPSK_Transmit_v10_initializer(void)
{
}

void QPSK_Transmit_v10_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_QPSK_Transmit_v10_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_QPSK_Transmit_v10_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==108) {
    c108_QPSK_Transmit_v10_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_QPSK_Transmit_v10_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1108808946U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4132600642U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2530138163U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3399326437U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(238689946U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(569605708U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(24467444U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4047914236U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_QPSK_Transmit_v10_get_check_sum(mxArray *plhs[]);
          sf_c1_QPSK_Transmit_v10_get_check_sum(plhs);
          break;
        }

       case 108:
        {
          extern void sf_c108_QPSK_Transmit_v10_get_check_sum(mxArray *plhs[]);
          sf_c108_QPSK_Transmit_v10_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3107990961U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3331135704U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3275981819U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2076447021U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_QPSK_Transmit_v10_autoinheritance_info( int nlhs, mxArray *
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
     case 1:
      {
        if (strcmp(aiChksum, "iRmvylP4knQLIrxkywK4wG") == 0) {
          extern mxArray *sf_c1_QPSK_Transmit_v10_get_autoinheritance_info(void);
          plhs[0] = sf_c1_QPSK_Transmit_v10_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 108:
      {
        if (strcmp(aiChksum, "7TU25sLgkAPKDTGVcCFjZB") == 0) {
          extern mxArray *sf_c108_QPSK_Transmit_v10_get_autoinheritance_info
            (void);
          plhs[0] = sf_c108_QPSK_Transmit_v10_get_autoinheritance_info();
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

unsigned int sf_QPSK_Transmit_v10_get_eml_resolved_functions_info( int nlhs,
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
     case 1:
      {
        extern const mxArray
          *sf_c1_QPSK_Transmit_v10_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_QPSK_Transmit_v10_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 108:
      {
        extern const mxArray
          *sf_c108_QPSK_Transmit_v10_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c108_QPSK_Transmit_v10_get_eml_resolved_functions_info();
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

void QPSK_Transmit_v10_debug_initialize(void)
{
  _QPSK_Transmit_v10MachineNumber_ = sf_debug_initialize_machine(
    "QPSK_Transmit_v10","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(_QPSK_Transmit_v10MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_QPSK_Transmit_v10MachineNumber_,0);
}

void QPSK_Transmit_v10_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_QPSK_Transmit_v10_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "QPSK_Transmit_v10", "QPSK_Transmit_v10");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_QPSK_Transmit_v10_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
