# =============================================================================
#  Make include file reaadChannel_rti.mk:
#
#   RTI1103 6.5 (10-May-2010)
#   Thu Sep 08 14:15:05 2016
#
#   Copyright (c) 1999-2002 dSPACE GmbH, GERMANY
# =============================================================================

# Initialize variables used in blockset makefiles -----------------------------

BLOCKSET_LIBS     :=
BLOCKSET_SRCS     :=
BLOCKSET_INCLUDES :=

# Default rules for additional blocksets --------------------------------------

blockset_init          :
blockset_clean         :
blockset_deps          :
blockset_after_linkage :

# Includes for additional blocksets -------------------------------------------



# Model-specific options ------------------------------------------------------

# Additional C source files declared by the model
MDL_CUSTOM_C_SRCS = rti_assert.c

# Additional assembler source files declared by the model
MDL_CUSTOM_ASM_SRCS =

# Additional libraries declared by the model
MDL_CUSTOM_LIBS =

# Additional objects declared by the model
MDL_CUSTOM_OBJS =

# Directories where additional C and assembler source files are stored
MDL_CUSTOM_SRCS_DIR =

# Directories where additional header files are stored
MDL_CUSTOM_INCLUDES_PATH =


# Define workingboard for download
WORKINGBOARD = ds1103

# Define build type information
BUILDTYPE = RTI

# EOF -------------------------------------------------------------------------
