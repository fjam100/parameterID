/*********************** dSPACE target specific file *************************

   Include file forceConstant_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1103 6.5 (10-May-2010)
   Sun Sep 11 14:15:03 2016

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "forceConstant.h"
#include "forceConstant_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             forceConstant_B
#define RTP_STRUCTURE_NAME             forceConstant_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        1
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);
  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1103, (void *) 0,
                        VCM_TXT_RTI1103, 6, 5, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 10, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 5, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 5, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS1103 #1 Unit:ENC_SETUP */
  ds1103_inc_init(1, DS1103_INC_CH1_TTL);
  ds1103_inc_init(2, DS1103_INC_CH2_TTL);
  ds1103_inc_init(3, DS1103_INC_CH3_TTL);
  ds1103_inc_init(4, DS1103_INC_CH4_TTL);
  ds1103_inc_init(5, DS1103_INC_CH5_TTL);
  ds1103_inc_init(6, DS1103_INC_CH6_TTL|DS1103_INC_CH6_16BIT);
  ds1103_inc_init(7, DS1103_INC_CH7_VPP|DS1103_INC_CH7_38BIT);

  /* Initialization of Master ADC units */
  ds1103_adc_trigger_setup(2, DS1103_TRIGGER_DISABLE);

  /* Initialization of Master MUXADC units */
  /* Initialization of Master DAC units */
  ds1103_dac_init(DS1103_DACMODE_TRANSPARENT);
  ds1103_dac_trigger_setup(DS1103_TRIGGER_DISABLE);

  /* Initialization of Master EncSetup units  */
  ds1103_inc_trigger_setup(1,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(2,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(3,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(4,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(5,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(6,DS1103_TRIGGER_DISABLE);
  ds1103_inc_trigger_setup(7,DS1103_TRIGGER_DISABLE);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, 0);

  /* dSPACE I/O Board DS1103 #1 Unit:ENC_POS */
  ds1103_inc_position_write(3, 0, DS1103_INC_LINE_SUBDIV_4);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

/* Function rti_mdl_background() is empty */
#define rti_mdl_background()

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.001, 0.0] */
  /* dSPACE I/O Board DS1103 #1 Unit:MultiAdc */
  {
    Float64 pvalues[20];
    ds1103_adc_multi_conv_read(DS1103_ADC_CHANNEL5, pvalues);
    forceConstant_B.SFunction = pvalues[4];
  }

  /* dSPACE I/O Board DS1103 #1 Unit:ENC_POS Group:POS */
  forceConstant_B.SFunction1 = (real_T) ds1103_inc_position_read(3,
    DS1103_INC_LINE_SUBDIV_4);
}

#undef __INLINE

/****** [EOF] ****************************************************************/
