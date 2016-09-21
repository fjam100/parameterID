/*
 * forceConstant.c
 *
 * Real-Time Workshop code generation for Simulink model "forceConstant.mdl".
 *
 * Model version              : 1.6
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Sep 21 14:17:39 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "forceConstant_trc_ptr.h"
#include "forceConstant.h"
#include "forceConstant_private.h"

/* Block signals (auto storage) */
BlockIO_forceConstant forceConstant_B;

/* Block states (auto storage) */
D_Work_forceConstant forceConstant_DWork;

/* Real-time model */
RT_MODEL_forceConstant forceConstant_M_;
RT_MODEL_forceConstant *forceConstant_M = &forceConstant_M_;

/* Model output function */
static void forceConstant_output(int_T tid)
{
  uint32_T initialOffset;
  int32_T tmp;
  int32_T tmp_0;
  real_T tmp_1;

  /* S-Function (rti_commonblock): '<S1>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S3>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S4>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S7>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S8>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/channel5' */
  forceConstant_B.VectorConcatenate[0] = forceConstant_P.channel5_Gain *
    forceConstant_B.SFunction_p;

  /* Gain: '<Root>/channel9' */
  forceConstant_B.VectorConcatenate[1] = forceConstant_P.channel9_Gain *
    forceConstant_B.SFunction_l4;

  /* Gain: '<Root>/channel17' */
  forceConstant_B.VectorConcatenate[2] = forceConstant_P.channel17_Gain *
    forceConstant_B.SFunction;

  /* Gain: '<Root>/channel18' */
  forceConstant_B.VectorConcatenate[3] = forceConstant_P.channel18_Gain *
    forceConstant_B.SFunction_l;

  /* Gain: '<Root>/channel19' */
  forceConstant_B.VectorConcatenate[4] = forceConstant_P.channel19_Gain *
    forceConstant_B.SFunction_m;

  /* Gain: '<Root>/channel20' */
  forceConstant_B.VectorConcatenate[5] = forceConstant_P.channel20_Gain *
    forceConstant_B.SFunction_e;

  /* Product: '<Root>/Matrix Multiply' incorporates:
   *  Constant: '<Root>/Constant'
   */
  for (tmp = 0; tmp < 6; tmp++) {
    forceConstant_B.MatrixMultiply[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      forceConstant_B.MatrixMultiply[tmp] = forceConstant_P.Constant_Value[6 *
        tmp_0 + tmp] * forceConstant_B.VectorConcatenate[tmp_0] +
        forceConstant_B.MatrixMultiply[tmp];
    }
  }

  /* Gain: '<Root>/GainFx' */
  forceConstant_B.GainFx = forceConstant_P.GainFx_Gain *
    forceConstant_B.MatrixMultiply[0];

  /* Gain: '<Root>/GainFy' */
  forceConstant_B.GainFy = forceConstant_P.GainFy_Gain *
    forceConstant_B.MatrixMultiply[1];

  /* Gain: '<Root>/GainFz' */
  forceConstant_B.GainFz = forceConstant_P.GainFz_Gain *
    forceConstant_B.MatrixMultiply[2];

  /* Gain: '<Root>/GainMx' */
  forceConstant_B.GainMx = forceConstant_P.GainMx_Gain *
    forceConstant_B.MatrixMultiply[3];

  /* Gain: '<Root>/GainMy' */
  forceConstant_B.GainMy = forceConstant_P.GainMy_Gain *
    forceConstant_B.MatrixMultiply[4];

  /* Gain: '<Root>/GainMz' */
  forceConstant_B.GainMz = forceConstant_P.GainMz_Gain *
    forceConstant_B.MatrixMultiply[5];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  forceConstant_B.DiscreteTimeIntegrator =
    forceConstant_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/index' */
  forceConstant_B.index = forceConstant_P.index_Gain *
    forceConstant_B.DiscreteTimeIntegrator;

  /* LookupNDDirect: '<Root>/input'
   *
   * About '<Root>/input':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  tmp_1 = rt_SATURATE(forceConstant_B.index, 0.0, 99999.0);
  if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = fmod(floor(tmp_1), 4.294967296E+009);
  }

  initialOffset = tmp_1 < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp_1))) :
    (uint32_T)tmp_1;
  forceConstant_B.input = forceConstant_P.input_table[initialOffset];

  /* Product: '<Root>/u' incorporates:
   *  Constant: '<Root>/Reset'
   */
  forceConstant_B.u = forceConstant_P.Reset_Value * forceConstant_B.input;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, forceConstant_B.u);

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S12>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S9>/encGainY' */
  forceConstant_B.encGainY = forceConstant_P.encGainY_Gain *
    forceConstant_B.SFunction1;

  /* SampleTimeMath: '<S11>/TSamp'
   *
   * About '<S11>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  forceConstant_B.TSamp = forceConstant_B.encGainY * forceConstant_P.TSamp_WtEt;

  /* UnitDelay: '<S11>/UD' */
  forceConstant_B.Uk1 = forceConstant_DWork.UD_DSTATE;

  /* Sum: '<S11>/Diff' */
  forceConstant_B.Diff = forceConstant_B.TSamp - forceConstant_B.Uk1;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function3' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function4' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function5' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function6' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function7' */
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
static void forceConstant_update(int_T tid)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Reset'
   */
  forceConstant_DWork.DiscreteTimeIntegrator_DSTATE =
    forceConstant_P.DiscreteTimeIntegrator_gainval * forceConstant_P.Reset_Value
    + forceConstant_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for UnitDelay: '<S11>/UD' */
  forceConstant_DWork.UD_DSTATE = forceConstant_B.TSamp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++forceConstant_M->Timing.clockTick0)) {
    ++forceConstant_M->Timing.clockTickH0;
  }

  forceConstant_M->Timing.t[0] = forceConstant_M->Timing.clockTick0 *
    forceConstant_M->Timing.stepSize0 + forceConstant_M->Timing.clockTickH0 *
    forceConstant_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void forceConstant_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)forceConstant_M, 0,
                sizeof(RT_MODEL_forceConstant));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = forceConstant_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    forceConstant_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    forceConstant_M->Timing.sampleTimes =
      (&forceConstant_M->Timing.sampleTimesArray[0]);
    forceConstant_M->Timing.offsetTimes =
      (&forceConstant_M->Timing.offsetTimesArray[0]);

    /* task periods */
    forceConstant_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    forceConstant_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(forceConstant_M, &forceConstant_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = forceConstant_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    forceConstant_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(forceConstant_M, -1);
  forceConstant_M->Timing.stepSize0 = 0.001;
  forceConstant_M->solverInfoPtr = (&forceConstant_M->solverInfo);
  forceConstant_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&forceConstant_M->solverInfo, 0.001);
  rtsiSetSolverMode(&forceConstant_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  forceConstant_M->ModelData.blockIO = ((void *) &forceConstant_B);
  (void) memset(((void *) &forceConstant_B), 0,
                sizeof(BlockIO_forceConstant));

  /* parameters */
  forceConstant_M->ModelData.defaultParam = ((real_T *)&forceConstant_P);

  /* states (dwork) */
  forceConstant_M->Work.dwork = ((void *) &forceConstant_DWork);
  (void) memset((void *)&forceConstant_DWork, 0,
                sizeof(D_Work_forceConstant));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void forceConstant_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  forceConstant_output(tid);
}

void MdlUpdate(int_T tid)
{
  forceConstant_update(tid);
}

void MdlInitializeSizes(void)
{
  forceConstant_M->Sizes.numContStates = (0);/* Number of continuous states */
  forceConstant_M->Sizes.numY = (0);   /* Number of model outputs */
  forceConstant_M->Sizes.numU = (0);   /* Number of model inputs */
  forceConstant_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  forceConstant_M->Sizes.numSampTimes = (1);/* Number of sample times */
  forceConstant_M->Sizes.numBlocks = (41);/* Number of blocks */
  forceConstant_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  forceConstant_M->Sizes.numBlockPrms = (100055);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  forceConstant_DWork.DiscreteTimeIntegrator_DSTATE =
    forceConstant_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S11>/UD' */
  forceConstant_DWork.UD_DSTATE = forceConstant_P.UD_X0;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  forceConstant_terminate();
}

RT_MODEL_forceConstant *forceConstant(void)
{
  forceConstant_initialize(1);
  return forceConstant_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
