/*
 * input_output.c
 *
 * Real-Time Workshop code generation for Simulink model "input_output.mdl".
 *
 * Model version              : 1.9
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Mon Sep 05 14:08:31 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "input_output_trc_ptr.h"
#include "input_output.h"
#include "input_output_private.h"

/* Block signals (auto storage) */
BlockIO_input_output input_output_B;

/* Block states (auto storage) */
D_Work_input_output input_output_DWork;

/* Real-time model */
RT_MODEL_input_output input_output_M_;
RT_MODEL_input_output *input_output_M = &input_output_M_;

/* Model output function */
static void input_output_output(int_T tid)
{
  uint32_T initialOffset;
  real_T tmp;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  input_output_B.DiscreteTimeIntegrator =
    input_output_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/index' */
  input_output_B.index = input_output_P.index_Gain *
    input_output_B.DiscreteTimeIntegrator;

  /* LookupNDDirect: '<Root>/preu'
   *
   * About '<Root>/preu':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  tmp = rt_SATURATE(input_output_B.index, 0.0, 179999.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(floor(tmp), 4.294967296E+009);
  }

  initialOffset = tmp < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp))) :
    (uint32_T)tmp;
  input_output_B.preu = input_output_P.preu_table[initialOffset];

  /* Product: '<Root>/u' incorporates:
   *  Constant: '<Root>/Reset'
   */
  input_output_B.u = input_output_P.Reset_Value * input_output_B.preu;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, input_output_B.u);

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S3>/encGainY' */
  input_output_B.encGainY = input_output_P.encGainY_Gain *
    input_output_B.SFunction1;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  input_output_B.TSamp = input_output_B.encGainY * input_output_P.TSamp_WtEt;

  /* UnitDelay: '<S5>/UD' */
  input_output_B.Uk1 = input_output_DWork.UD_DSTATE;

  /* Sum: '<S5>/Diff' */
  input_output_B.Diff = input_output_B.TSamp - input_output_B.Uk1;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function3' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function4' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function5' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function6' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function7' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* user code (Output function Trailer) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void input_output_update(int_T tid)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Reset'
   */
  input_output_DWork.DiscreteTimeIntegrator_DSTATE =
    input_output_P.DiscreteTimeIntegrator_gainval * input_output_P.Reset_Value +
    input_output_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for UnitDelay: '<S5>/UD' */
  input_output_DWork.UD_DSTATE = input_output_B.TSamp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++input_output_M->Timing.clockTick0)) {
    ++input_output_M->Timing.clockTickH0;
  }

  input_output_M->Timing.t[0] = input_output_M->Timing.clockTick0 *
    input_output_M->Timing.stepSize0 + input_output_M->Timing.clockTickH0 *
    input_output_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void input_output_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)input_output_M, 0,
                sizeof(RT_MODEL_input_output));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = input_output_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    input_output_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    input_output_M->Timing.sampleTimes =
      (&input_output_M->Timing.sampleTimesArray[0]);
    input_output_M->Timing.offsetTimes =
      (&input_output_M->Timing.offsetTimesArray[0]);

    /* task periods */
    input_output_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    input_output_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(input_output_M, &input_output_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = input_output_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    input_output_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(input_output_M, -1);
  input_output_M->Timing.stepSize0 = 0.001;
  input_output_M->solverInfoPtr = (&input_output_M->solverInfo);
  input_output_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&input_output_M->solverInfo, 0.001);
  rtsiSetSolverMode(&input_output_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  input_output_M->ModelData.blockIO = ((void *) &input_output_B);
  (void) memset(((void *) &input_output_B), 0,
                sizeof(BlockIO_input_output));

  /* parameters */
  input_output_M->ModelData.defaultParam = ((real_T *)&input_output_P);

  /* states (dwork) */
  input_output_M->Work.dwork = ((void *) &input_output_DWork);
  (void) memset((void *)&input_output_DWork, 0,
                sizeof(D_Work_input_output));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void input_output_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  input_output_output(tid);
}

void MdlUpdate(int_T tid)
{
  input_output_update(tid);
}

void MdlInitializeSizes(void)
{
  input_output_M->Sizes.numContStates = (0);/* Number of continuous states */
  input_output_M->Sizes.numY = (0);    /* Number of model outputs */
  input_output_M->Sizes.numU = (0);    /* Number of model inputs */
  input_output_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  input_output_M->Sizes.numSampTimes = (1);/* Number of sample times */
  input_output_M->Sizes.numBlocks = (20);/* Number of blocks */
  input_output_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  input_output_M->Sizes.numBlockPrms = (180007);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  input_output_DWork.DiscreteTimeIntegrator_DSTATE =
    input_output_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  input_output_DWork.UD_DSTATE = input_output_P.UD_X0;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  input_output_terminate();
}

RT_MODEL_input_output *input_output(void)
{
  input_output_initialize(1);
  return input_output_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
