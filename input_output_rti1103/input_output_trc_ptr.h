  /*********************** dSPACE target specific file *************************

   Header file input_output_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Mon Sep 05 14:08:31 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_input_output_trc_ptr_h_
  #define RTI_HEADER_input_output_trc_ptr_h_
  /* Include the model header file. */
  #include "input_output.h"
  #include "input_output_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_input_output_B_real_T_0;
              EXTERN_C volatile  real_T *p_input_output_B_real_T_1;
              EXTERN_C volatile  real_T *p_input_output_P_real_T_0;
              EXTERN_C volatile  real_T *p_input_output_DWork_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_input_output_B_real_T_0 = &input_output_B.DiscreteTimeIntegrator;\
              p_input_output_B_real_T_1 = &input_output_B.encGainY;\
              p_input_output_P_real_T_0 = &input_output_P.Reset_Value;\
              p_input_output_DWork_real_T_0 = &input_output_DWork.DiscreteTimeIntegrator_DSTATE;\

   #endif                       /* RTI_HEADER_input_output_trc_ptr_h_ */
