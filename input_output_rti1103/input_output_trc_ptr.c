/***************************************************************************

   Source file input_output_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Mon Sep 05 14:08:31 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "input_output_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_input_output_B_real_T_0 = 0;
volatile real_T *p_input_output_B_real_T_1 = 0;
volatile real_T *p_input_output_P_real_T_0 = 0;
volatile real_T *p_input_output_DWork_real_T_0 = 0;
