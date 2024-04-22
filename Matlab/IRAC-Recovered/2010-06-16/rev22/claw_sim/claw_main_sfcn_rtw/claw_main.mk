# Copyright 1994-2007 The MathWorks, Inc.
#
# File    : rtwsfcn_lcc.tmf   $Revision: 1.20.4.18 $
#
# Abstract:
#	Real-Time Workshop template makefile for building a PC-based,
#       RTW generated S-Function of Simulink model using generated C code.
#			LCC compiler version 2.4
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win32.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#
#         MEX_OPTS       - User specific mex options.
#	  OPT_OPTS       - Optimization options. Default is none. To enable 
#                          debugging specify as OPT_OPTS=-g. 
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the 
#			   file name instead of a '\' . 
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see rtwsfcn.tlc

#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win32\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rtwsfcn.tlc
COMPILER_TOOL_CHAIN = lcc

MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  MEXEXT          - extension that a mex file has. See the MATLAB mexext 
#                    command
#  BUILDARGS       - Options passed in at the command line.
#  CREATEMODEL     - 1 will cause a untitled model to be opened with the 
#                    generated s-function block inside it.
#  USERMODULES     - passed along for later code generations of models that 
#                    contain this RTW S-Function. (Used by RTW S-Function 
#                    block.)
#  USEPARAMVALUES  - 1 will cause the generated S-function block to have values
#                    instead of variable names.

MODEL           = claw_main
MODULES         = claw_main_sf_data.c rtGetInf.c rtGetNaN.c rt_atan2_snf.c rt_backsubrr_dbl.c rt_forwardsubrr_dbl.c rt_hypot_snf.c rt_lu_real.c rt_matdivrr_dbl.c rt_pow_snf.c smn_sfunc_gam_mpass_epsposdef_wrapper.c ch_smn_wrapper.c axpy_0ir20_1r20_1r.c axpy_0ir3_1r3_1r.c better_lam_bi_0rrrrrr.c better_lam_lo_0rrr.c compute_dgamma_0r3_3r3_1r3_1r3_1rii.c compute_eta_0i20_1r20_1r20_1r.c compute_gamma_0i20_1r20_1r.c compute_u_0r3_3r20_3r3_1r3_1riir.c controlh_types.c dot_0i20_1r20_1r.c dot_0i3_1r3_1r.c get_lam_bisect_0rrrr3_3r20_3r3_1r3_1r20_1r20_1rii.c get_unlwp_03_20r3_1r20_1r20_20riir.c get_wpplusnp_03_20r3_1r20_1r20_20r3_1rii.c ins_real_matrix_self.c interp_u_gamma_020_1r20_1r20_1ri.c mach_process_0_params_gv_0.c posdeffac_020_20rir.c posdeffac_03_3rir.c posdefsol_020_20r20_1riir.c posdefsol_020_20r20_3riir.c posdefsol_03_3r3_1riir.c round_real_matrix.c semn_03_20r3_1r3_1r20_1r20_20r20_1r20_1rrii.c smn_03_20r3_1r20_1r20_1r3_1r20_1r20_20r.c spmn_03_20r3_1r20_1r20_1r3_1r20_1r20_20rrii.c 
MAKEFILE        = claw_main.mk
MATLAB_ROOT     = C:/Program Files/MATLAB/R2008b
ALT_MATLAB_ROOT = C:/PROGRA~1/MATLAB/R2008b
MATLAB_BIN      = C:/Program Files/MATLAB/R2008b/bin
ALT_MATLAB_BIN  = C:/PROGRA~1/MATLAB/R2008b/bin
S_FUNCTIONS     = 
S_FUNCTIONS_LIB = 
SOLVER          = 
NUMST           = 1
TID01EQ         = 0
NCSTATES        = 0
MEM_ALLOC       = RT_STATIC
MEXEXT          = mexw32
BUILDARGS       =  GENERATE_REPORT=0 MODELLIB=claw_mainlib.lib RELATIVE_PATH_TO_ANCHOR=.. MODELREF_TARGET_TYPE=NONE
CREATEMODEL     = 1
USERMODULES     =  
USEPARAMVALUES  = 0
MEX_OPT_FILE    = -f D:/DOCUME~1/E183308/APPLIC~1/MATHWO~1/MATLAB/R2008b/mexopts.bat
OPTIMIZATION_FLAGS = 
ADDITIONAL_LDFLAGS = 

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications ------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc
include $(MATLAB_ROOT)\rtw\c\tools\lcctools.mak

MEX = $(MATLAB_BIN)\mex.bat
CC  = $(MATLAB_BIN)\mex.bat -c

#------------------------------ Include Path ----------------------------------

# see MATLAB_INCLUDES and COMPILER_INCLUDES from lcctools.mak

ADD_INCLUDES = \
	-ID:/Projects/2003-2~1/IRAC-L~1/users/suvo/TechWork/2010/2010-0~3/rev22/claw_sim/CLAW_M~1 \
	-ID:/Projects/2003-2~1/IRAC-L~1/users/suvo/TechWork/2010/2010-0~3/rev22/claw_sim \
	-IP:/oav-unix/FlightControl/MACH/smn/smn_sfunc_gam_mpass_epsposdef/c_code_smn \


INCLUDES = -I. -I.. $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES)

#------------------------ C and MEX optimization options ----------------------
MEX_OPTS  =
OPT_OPTS  = $(DEFAULT_OPT_OPTS)
ifneq ($(OPTIMIZATION_FLAGS),)
MEX_OPT_OPTS = OPTIMFLAGS="$(OPTIMIZATION_FLAGS)"    # passed to 'mex -c'
else
MEX_OPT_OPTS = $(OPT_OPTS)    # passed to 'mex -c'
endif
ifeq "$(MEX_OPTS)" "-g"
MEX_OPT_OPTS =
endif

ifneq ($(ADDITIONAL_LDFLAGS),)
MEX_LDFLAGS = LINKFLAGS="$$LINKFLAGS $(ADDITIONAL_LDFLAGS)"
else
MEX_LDFLAGS =
endif

#-------------------------------- Mex Options  --------------------------------
MEX_FLAGS = -win32 $(MEX_OPT_OPTS) $(MEX_OPTS) $(MEX_LDFLAGS) $(MEX_OPT_FILE)

#----------------------------- Source Files -----------------------------------
USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS      = $(MODEL)_sf.c $(MODULES)
OBJS      = $(SRCS:.c=.obj) $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.obj) $(LOCAL_USER_OBJS) $(ADD_LIBS)

#------------------------- Additional Libraries -------------------------------

LIBS =



LIBUT    = $(MATLAB_ROOT)\extern\lib\win32\lcc\libut.lib
LIBFIXPT = $(MATLAB_ROOT)\extern\lib\win32\lcc\libfixedpoint.lib
LIBS += $(S_FUNCTIONS_LIB) $(LIBUT) $(LIBFIXPT)

PROGRAM = ../$(MODEL)_sf.$(MEXEXT)

#--------------------------------- Rules --------------------------------------

$(PROGRAM) : $(OBJS) $(LIBS)
	@cmd /C "echo ### Linking ..."
	$(MEX) $(MEX_FLAGS) -outdir .. $(LINK_OBJS) $(LIBS)
	@cmd /C "echo ### Created MEX-file $(MODEL)_sf.$(MEXEXT)"

%.obj : %.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : ../%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : P:/oav-unix/FlightControl/MACH/smn/smn_sfunc_gam_mpass_epsposdef/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : P:/oav-unix/FlightControl/MACH/smn/smn_sfunc_gam_mpass_epsposdef/c_code_smn/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<



%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

# Libraries:





#-------------------------------- Clean ---------------------------------------

clean :
	@cmd /C "echo ### Deleting the objects and $(PROGRAM)"
	@del $(OBJS) ..\$(MODEL)_sf.$(MEXEXT) $(wildcard *.obj) $(wildcard *.lib)

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

