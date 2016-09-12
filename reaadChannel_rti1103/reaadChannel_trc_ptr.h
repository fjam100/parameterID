  /*********************** dSPACE target specific file *************************

   Header file reaadChannel_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Thu Sep 08 14:15:05 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_reaadChannel_trc_ptr_h_
  #define RTI_HEADER_reaadChannel_trc_ptr_h_
  /* Include the model header file. */
  #include "reaadChannel.h"
  #include "reaadChannel_private.h"

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

   #define RTI_INIT_TRC_POINTERS() \

   #endif                       /* RTI_HEADER_reaadChannel_trc_ptr_h_ */
