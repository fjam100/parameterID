/*
 * reaadChannel.c
 *
 * Real-Time Workshop code generation for Simulink model "reaadChannel.mdl".
 *
 * Model version              : 1.1
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Sep 08 14:15:05 2016
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "reaadChannel_trc_ptr.h"
#include "reaadChannel.h"
#include "reaadChannel_private.h"

/* Real-time model */
RT_MODEL_reaadChannel reaadChannel_M_;
RT_MODEL_reaadChannel *reaadChannel_M = &reaadChannel_M_;

/* Model output function */
static void reaadChannel_output(int_T tid)
{
  /* S-Function (rti_commonblock): '<S1>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

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
static void reaadChannel_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++reaadChannel_M->Timing.clockTick0)) {
    ++reaadChannel_M->Timing.clockTickH0;
  }

  reaadChannel_M->Timing.t[0] = reaadChannel_M->Timing.clockTick0 *
    reaadChannel_M->Timing.stepSize0 + reaadChannel_M->Timing.clockTickH0 *
    reaadChannel_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void reaadChannel_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)reaadChannel_M, 0,
                sizeof(RT_MODEL_reaadChannel));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = reaadChannel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    reaadChannel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    reaadChannel_M->Timing.sampleTimes =
      (&reaadChannel_M->Timing.sampleTimesArray[0]);
    reaadChannel_M->Timing.offsetTimes =
      (&reaadChannel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    reaadChannel_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    reaadChannel_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(reaadChannel_M, &reaadChannel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = reaadChannel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    reaadChannel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(reaadChannel_M, -1);
  reaadChannel_M->Timing.stepSize0 = 0.001;
  reaadChannel_M->solverInfoPtr = (&reaadChannel_M->solverInfo);
  reaadChannel_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&reaadChannel_M->solverInfo, 0.001);
  rtsiSetSolverMode(&reaadChannel_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void reaadChannel_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  reaadChannel_output(tid);
}

void MdlUpdate(int_T tid)
{
  reaadChannel_update(tid);
}

void MdlInitializeSizes(void)
{
  reaadChannel_M->Sizes.numContStates = (0);/* Number of continuous states */
  reaadChannel_M->Sizes.numY = (0);    /* Number of model outputs */
  reaadChannel_M->Sizes.numU = (0);    /* Number of model inputs */
  reaadChannel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  reaadChannel_M->Sizes.numSampTimes = (1);/* Number of sample times */
  reaadChannel_M->Sizes.numBlocks = (8);/* Number of blocks */
  reaadChannel_M->Sizes.numBlockIO = (1);/* Number of block outputs */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  reaadChannel_terminate();
}

RT_MODEL_reaadChannel *reaadChannel(void)
{
  reaadChannel_initialize(1);
  return reaadChannel_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
