  /*********************** dSPACE target specific file *************************

   Header file forceConstant_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Tue Sep 13 10:31:35 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_forceConstant_trc_ptr_h_
  #define RTI_HEADER_forceConstant_trc_ptr_h_
  /* Include the model header file. */
  #include "forceConstant.h"
  #include "forceConstant_private.h"

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
              EXTERN_C volatile  real_T *p_forceConstant_B_real_T_0;
              EXTERN_C volatile  real_T *p_forceConstant_B_real_T_1;
              EXTERN_C volatile  real_T *p_forceConstant_P_real_T_0;
              EXTERN_C volatile  real_T *p_forceConstant_DWork_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_forceConstant_B_real_T_0 = &forceConstant_B.DiscreteTimeIntegrator;\
              p_forceConstant_B_real_T_1 = &forceConstant_B.encGainY;\
              p_forceConstant_P_real_T_0 = &forceConstant_P.Reset_Value;\
              p_forceConstant_DWork_real_T_0 = &forceConstant_DWork.DiscreteTimeIntegrator_DSTATE;\

   #endif                       /* RTI_HEADER_forceConstant_trc_ptr_h_ */
