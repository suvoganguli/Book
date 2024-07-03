# Copyright 1994-2005 The MathWorks, Inc.
#
# File    : ert_lcc.tmf   $Revision: 1.26.4.23 $
#
# Abstract:
#	Real-Time Workshop template makefile for building a PC-based
#	stand-alone embedded real-time version of Simulink model using
#	generated C code and 
#			LCC compiler Version 2.4
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/rtw/bin/win32.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is none. To enable 
#                          debugging specify as OPT_OPTS=-g4. 
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths 
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the 
#			   file name instead of a '\' . 
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\rtw\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of additional S-function modules.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  ADD_MDL_NAME_TO_GLOBALS - Do we add the model name to global 
#                        identifiers (1/0)?

MODEL                = claw_main_GV
MODULES              = claw_main_GV_data.c rt_nonfinite.c smn_sfunc_gam_mpass_epsposdef_wrapper.c ch_smn_wrapper.c axpy_0ir20_1r20_1r.c axpy_0ir3_1r3_1r.c better_lam_bi_0rrrrrr.c better_lam_lo_0rrr.c compute_dgamma_0r3_3r3_1r3_1r3_1rii.c compute_eta_0i20_1r20_1r20_1r.c compute_gamma_0i20_1r20_1r.c compute_u_0r3_3r20_3r3_1r3_1riir.c controlh_types.c dot_0i20_1r20_1r.c dot_0i3_1r3_1r.c get_lam_bisect_0rrrr3_3r20_3r3_1r3_1r20_1r20_1rii.c get_unlwp_03_20r3_1r20_1r20_20riir.c get_wpplusnp_03_20r3_1r20_1r20_20r3_1rii.c ins_real_matrix_self.c interp_u_gamma_020_1r20_1r20_1ri.c mach_process_0_params_gv_0.c posdeffac_020_20rir.c posdeffac_03_3rir.c posdefsol_020_20r20_1riir.c posdefsol_020_20r20_3riir.c posdefsol_03_3r3_1riir.c round_real_matrix.c semn_03_20r3_1r3_1r20_1r20_20r20_1r20_1rrii.c smn_03_20r3_1r20_1r20_1r3_1r20_1r20_20r.c spmn_03_20r3_1r20_1r20_1r3_1r20_1r20_20rrii.c 
MAKEFILE             = claw_main_GV.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R14SP3
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R14SP3
MATLAB_BIN           = C:\Program Files\MATLAB\R14SP3\bin\win32
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R14SP3\bin\win32
S_FUNCTIONS          =  table3v5.c table2v5.c table1v5.c
S_FUNCTIONS_LIB      = 
NUMST                = 1
NCSTATES             = 0
BUILDARGS            =  OPTS=" -DRT -DUSE_RTMODEL -DERT"
MULTITASKING         = 0
INTEGER_CODE         = 0
MAT_FILE             = 0
ONESTEPFCN           = 1
TERMFCN              = 1
B_ERTSFCN            = 0
MEXEXT               = mexw32
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
MULTI_INSTANCE_CODE  = 0
ADD_MDL_NAME_TO_GLOBALS = 1
MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
MEX_OPT_FILE            = -f $(MATLAB_BIN)\mexopts\lccopts.bat

#--------------------------- Model and reference models -----------------------
MODELLIB                  = claw_main_GVlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_tcpip_transport.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc\lib\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c ext_serial_win32_port.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#--------------------------- Tool Specifications -------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc
include $(MATLAB_ROOT)\rtw\c\tools\lcctools.mak

# Determine if we are generating an s-function
SFCN = 0
ifeq ($(MODELREF_TARGET_TYPE),SIM)
  SFCN = 1
endif
ifeq ($(B_ERTSFCN),1)
  SFCN = 1
endif

#------------------------------ Include Path -----------------------------------

# Additional includes 

ADD_INCLUDES = \
	-Ip:\oav-unix\flightcontrol\fast\mach\rev21\claw_sim \
	-Ip:\oav-unix\flightcontrol\fast\mach\rev21\claw_sim\claw_main_gv_ert_rtw \
	-I$(MATLAB_ROOT)\rtw\c\libsrc \
	-IP:\oav-unix\FlightControl\MACH\smn\smn_sfunc_gam_mpass_epsposdef\c_code_smn \


# see MATLAB_INCLUDES and COMPILER_INCLUDES from lcctool.mak

SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) \
           $(SHARED_INCLUDES)

INCLUDES += -I$(MATLAB_ROOT)\rtw\c\ert

#-------------------------------- C Flags --------------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

# Compiler options, etc:
CC_OPTS = $(OPT_OPTS) $(OPTS) $(ANSI_OPTS) $(EXT_CC_OPTS)

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMT=$(MULTITASKING) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE)\
		  -DADD_MDL_NAME_TO_GLOBALS=$(ADD_MDL_NAME_TO_GLOBALS)

ifeq ($(MODELREF_TARGET_TYPE),SIM)
CPP_REQ_DEFINES += -DMDL_REF_SIM_TGT=1
else
CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif

CFLAGS = $(CC_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES) -w -noregistrylookup 

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LDFLAGS = -s -L$(LIB)
else
LDFLAGS = -L$(LIB)
endif

#-------------------------- Additional Libraries ------------------------------

LIBS =

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
ifeq ($(INTEGER_CODE),0)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBS += $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_rtwsfcn_lcc.lib
else
LIBS += $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_ert_lcc.lib
endif
else
LIBS += $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_int_ert_lcc.lib
endif
else
LIBS += rtwlib.lib
endif


LIBS += $(EXT_LIB) $(S_FUNCTIONS_LIB)

ifeq ($(SFCN),1)
LIBFIXPT = $(MATLAB_ROOT)\extern\lib\win32\lcc\libfixedpoint.lib
LIBS += $(LIBFIXPT)
endif

#----------------------------- Source Files ------------------------------------
ADD_SRCS =

ifeq ($(SFCN),0)
  SRCS  = $(MODULES) $(ADD_SRCS) $(S_FUNCTIONS)
  SRC_DEP =
  ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).exe
    BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT) $(SYSLIBS) 
    BUILD_PRODUCT_TYPE = executable
    SRCS               += $(MODEL).c ert_main.c $(EXT_SRC)
  else
    # Model reference rtw target
    PRODUCT            = $(MODELLIB)
    BUILD_PRODUCT_TYPE = library
  endif
else
  ifeq ($(MODELREF_TARGET_TYPE), SIM)
  PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)_msf.$(MEXEXT)
  RTW_SFUN_SRC       = $(MODEL)_msf.c
  SRCS               = $(MODULES) $(ADD_SRCS)
  else
  PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)_sf.$(MEXEXT)
  RTW_SFUN_SRC       = $(MODEL)_sf.c
  SRCS               = $(MODULES) $(ADD_SRCS) $(S_FUNCTIONS)
  BIN_SETTING        = $(MATLAB_BIN)\mex.bat $(RTW_SFUN_SRC) $(MEX_OPT_FILE) $(INCLUDES) -outdir $(RELATIVE_PATH_TO_ANCHOR) 
  endif  
  BUILD_PRODUCT_TYPE = mex file
  ifeq ($(B_ERTSFCN),1)
    SRCS              += $(MODEL).c    
  endif
  SRC_DEP            = $(RTW_SFUN_SRC)
endif

USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(SRCS:.c=.obj) $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.obj) $(LOCAL_USER_OBJS)

SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))

#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS) 
	@echo ### Created $(BUILD_PRODUCT_TYPE): $@	
else
 ifeq ($(MODELREF_TARGET_TYPE),SIM)
  $(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP)
	$(LIBCMD) /out:$(MODELLIB) $(LINK_OBJS)
	@echo ### Created $(MODELLIB)
	$(MATLAB_BIN)\mex.bat -c $(RTW_SFUN_SRC) $(MEX_OPT_FILE) $(INCLUDES) 
	$(MATLAB_BIN)\mex.bat $(MEX_OPT_FILE) -outdir $(RELATIVE_PATH_TO_ANCHOR) $(MODEL)_msf.obj $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS) 
	@echo ### Created $(BUILD_PRODUCT_TYPE): $@	
 else
  $(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP)
	$(LIBCMD) /out:$(MODELLIB) $(LINK_OBJS)
	@echo ### Created $(MODELLIB)
	@echo ### Created $(BUILD_PRODUCT_TYPE): $@	
 endif
endif

%.obj : %.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/ert/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/serial/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)\rtw\c\libsrc/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : P:\oav-unix\FlightControl\MACH\smn\smn_sfunc_gam_mpass_epsposdef/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : P:\oav-unix\FlightControl\MACH\smn\smn_sfunc_gam_mpass_epsposdef\c_code_smn/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

# Libraries:



MODULES_rtwlib = \
    rt_atan2.obj \
    rt_atan232.obj \
    rt_backsubcc_dbl.obj \
    rt_backsubcc_sgl.obj \
    rt_backsubrc_dbl.obj \
    rt_backsubrc_sgl.obj \
    rt_backsubrr_dbl.obj \
    rt_backsubrr_sgl.obj \
    rt_enab.obj \
    rt_forwardsubcc_dbl.obj \
    rt_forwardsubcc_sgl.obj \
    rt_forwardsubcr_dbl.obj \
    rt_forwardsubcr_sgl.obj \
    rt_forwardsubrc_dbl.obj \
    rt_forwardsubrc_sgl.obj \
    rt_forwardsubrr_dbl.obj \
    rt_forwardsubrr_sgl.obj \
    rt_hypot.obj \
    rt_hypot32.obj \
    rt_i32zcfcn.obj \
    rt_intrp1flatcd.obj \
    rt_intrp1flatcf.obj \
    rt_intrp1flatd.obj \
    rt_intrp1flatf.obj \
    rt_intrp1lincd.obj \
    rt_intrp1lincf.obj \
    rt_intrp1linxd.obj \
    rt_intrp1linxf.obj \
    rt_intrp2flatcd.obj \
    rt_intrp2flatcf.obj \
    rt_intrp2flatd.obj \
    rt_intrp2flatf.obj \
    rt_intrp2lincd.obj \
    rt_intrp2lincf.obj \
    rt_intrp2lind.obj \
    rt_intrp2linf.obj \
    rt_intrp2linxd.obj \
    rt_intrp2linxf.obj \
    rt_intrp3lind.obj \
    rt_intrp3linf.obj \
    rt_intrp4lind.obj \
    rt_intrp4linf.obj \
    rt_intrp5lind.obj \
    rt_intrp5linf.obj \
    rt_intrpnflatcd.obj \
    rt_intrpnflatcf.obj \
    rt_intrpnflatd.obj \
    rt_intrpnflatf.obj \
    rt_intrpnlincd.obj \
    rt_intrpnlincf.obj \
    rt_intrpnlind.obj \
    rt_intrpnlinf.obj \
    rt_intrpnlinxd.obj \
    rt_intrpnlinxf.obj \
    rt_intrpnspld.obj \
    rt_intrpnsplf.obj \
    rt_logging.obj \
    rt_look.obj \
    rt_look1d.obj \
    rt_look1d32.obj \
    rt_look2d32_general.obj \
    rt_look2d32_normal.obj \
    rt_look2d_general.obj \
    rt_look2d_normal.obj \
    rt_look32.obj \
    rt_lookflat1bincsd.obj \
    rt_lookflat1bincsf.obj \
    rt_lookflat1binczd.obj \
    rt_lookflat1binczf.obj \
    rt_lookflat1evncsd.obj \
    rt_lookflat1evncsf.obj \
    rt_lookflat1evnczd.obj \
    rt_lookflat1evnczf.obj \
    rt_lookflat1lincsd.obj \
    rt_lookflat1lincsf.obj \
    rt_lookflat1linczd.obj \
    rt_lookflat1linczf.obj \
    rt_lookflat2bincsd.obj \
    rt_lookflat2bincsf.obj \
    rt_lookflat2binczd.obj \
    rt_lookflat2binczf.obj \
    rt_lookflat2evncsd.obj \
    rt_lookflat2evncsf.obj \
    rt_lookflat2evnczd.obj \
    rt_lookflat2evnczf.obj \
    rt_lookflat2lincsd.obj \
    rt_lookflat2lincsf.obj \
    rt_lookflat2linczd.obj \
    rt_lookflat2linczf.obj \
    rt_lookflatnbincsd.obj \
    rt_lookflatnbincsf.obj \
    rt_lookflatnbinczd.obj \
    rt_lookflatnbinczf.obj \
    rt_lookflatnevncsd.obj \
    rt_lookflatnevncsf.obj \
    rt_lookflatnevnczd.obj \
    rt_lookflatnevnczf.obj \
    rt_lookflatnlincsd.obj \
    rt_lookflatnlincsf.obj \
    rt_lookflatnlinczd.obj \
    rt_lookflatnlinczf.obj \
    rt_looklin1bincsd.obj \
    rt_looklin1bincsf.obj \
    rt_looklin1binczd.obj \
    rt_looklin1binczf.obj \
    rt_looklin1binxsd.obj \
    rt_looklin1binxsf.obj \
    rt_looklin1binxzd.obj \
    rt_looklin1binxzf.obj \
    rt_looklin1evncsd.obj \
    rt_looklin1evncsf.obj \
    rt_looklin1evnczd.obj \
    rt_looklin1evnczf.obj \
    rt_looklin1evnxsd.obj \
    rt_looklin1evnxsf.obj \
    rt_looklin1evnxzd.obj \
    rt_looklin1evnxzf.obj \
    rt_looklin1lincsd.obj \
    rt_looklin1lincsf.obj \
    rt_looklin1linczd.obj \
    rt_looklin1linczf.obj \
    rt_looklin1linxsd.obj \
    rt_looklin1linxsf.obj \
    rt_looklin1linxzd.obj \
    rt_looklin1linxzf.obj \
    rt_looklin2bincsd.obj \
    rt_looklin2bincsf.obj \
    rt_looklin2binczd.obj \
    rt_looklin2binczf.obj \
    rt_looklin2binxsd.obj \
    rt_looklin2binxsf.obj \
    rt_looklin2binxzd.obj \
    rt_looklin2binxzf.obj \
    rt_looklin2evncsd.obj \
    rt_looklin2evncsf.obj \
    rt_looklin2evnczd.obj \
    rt_looklin2evnczf.obj \
    rt_looklin2evnxsd.obj \
    rt_looklin2evnxsf.obj \
    rt_looklin2evnxzd.obj \
    rt_looklin2evnxzf.obj \
    rt_looklin2lincsd.obj \
    rt_looklin2lincsf.obj \
    rt_looklin2linczd.obj \
    rt_looklin2linczf.obj \
    rt_looklin2linxsd.obj \
    rt_looklin2linxsf.obj \
    rt_looklin2linxzd.obj \
    rt_looklin2linxzf.obj \
    rt_looklinnbincsd.obj \
    rt_looklinnbincsf.obj \
    rt_looklinnbinczd.obj \
    rt_looklinnbinczf.obj \
    rt_looklinnbinxsd.obj \
    rt_looklinnbinxsf.obj \
    rt_looklinnbinxzd.obj \
    rt_looklinnbinxzf.obj \
    rt_looklinnevncsd.obj \
    rt_looklinnevncsf.obj \
    rt_looklinnevnczd.obj \
    rt_looklinnevnczf.obj \
    rt_looklinnevnxsd.obj \
    rt_looklinnevnxsf.obj \
    rt_looklinnevnxzd.obj \
    rt_looklinnevnxzf.obj \
    rt_looklinnlincsd.obj \
    rt_looklinnlincsf.obj \
    rt_looklinnlinczd.obj \
    rt_looklinnlinczf.obj \
    rt_looklinnlinxsd.obj \
    rt_looklinnlinxsf.obj \
    rt_looklinnlinxzd.obj \
    rt_looklinnlinxzf.obj \
    rt_looksplnbincsd.obj \
    rt_looksplnbincsf.obj \
    rt_looksplnbinczd.obj \
    rt_looksplnbinczf.obj \
    rt_looksplnbinssd.obj \
    rt_looksplnbinssf.obj \
    rt_looksplnbinszd.obj \
    rt_looksplnbinszf.obj \
    rt_looksplnbinxsd.obj \
    rt_looksplnbinxsf.obj \
    rt_looksplnbinxzd.obj \
    rt_looksplnbinxzf.obj \
    rt_looksplnevncsd.obj \
    rt_looksplnevncsf.obj \
    rt_looksplnevnczd.obj \
    rt_looksplnevnczf.obj \
    rt_looksplnevnssd.obj \
    rt_looksplnevnssf.obj \
    rt_looksplnevnszd.obj \
    rt_looksplnevnszf.obj \
    rt_looksplnevnxsd.obj \
    rt_looksplnevnxsf.obj \
    rt_looksplnevnxzd.obj \
    rt_looksplnevnxzf.obj \
    rt_looksplnlincsd.obj \
    rt_looksplnlincsf.obj \
    rt_looksplnlinczd.obj \
    rt_looksplnlinczf.obj \
    rt_looksplnlinssd.obj \
    rt_looksplnlinssf.obj \
    rt_looksplnlinszd.obj \
    rt_looksplnlinszf.obj \
    rt_looksplnlinxsd.obj \
    rt_looksplnlinxsf.obj \
    rt_looksplnlinxzd.obj \
    rt_looksplnlinxzf.obj \
    rt_lu_cplx.obj \
    rt_lu_cplx_sgl.obj \
    rt_lu_real.obj \
    rt_lu_real_sgl.obj \
    rt_matdivcc_dbl.obj \
    rt_matdivcc_sgl.obj \
    rt_matdivcr_dbl.obj \
    rt_matdivcr_sgl.obj \
    rt_matdivrc_dbl.obj \
    rt_matdivrc_sgl.obj \
    rt_matdivrr_dbl.obj \
    rt_matdivrr_sgl.obj \
    rt_matmultandinccc_dbl.obj \
    rt_matmultandinccc_sgl.obj \
    rt_matmultandinccr_dbl.obj \
    rt_matmultandinccr_sgl.obj \
    rt_matmultandincrc_dbl.obj \
    rt_matmultandincrc_sgl.obj \
    rt_matmultandincrr_dbl.obj \
    rt_matmultandincrr_sgl.obj \
    rt_matmultcc_dbl.obj \
    rt_matmultcc_sgl.obj \
    rt_matmultcr_dbl.obj \
    rt_matmultcr_sgl.obj \
    rt_matmultrc_dbl.obj \
    rt_matmultrc_sgl.obj \
    rt_matmultrr_dbl.obj \
    rt_matmultrr_sgl.obj \
    rt_matrx.obj \
    rt_nrand.obj \
    rt_plookbincd.obj \
    rt_plookbincf.obj \
    rt_plookbinkcd.obj \
    rt_plookbinkcf.obj \
    rt_plookbinxd.obj \
    rt_plookbinxf.obj \
    rt_plookevncd.obj \
    rt_plookevncf.obj \
    rt_plookevnkcd.obj \
    rt_plookevnkcf.obj \
    rt_plookevnxd.obj \
    rt_plookevnxf.obj \
    rt_plooklincd.obj \
    rt_plooklincf.obj \
    rt_plooklinkcd.obj \
    rt_plooklinkcf.obj \
    rt_plooklinxd.obj \
    rt_plooklinxf.obj \
    rt_printf.obj \
    rt_sat_div_int16.obj \
    rt_sat_div_int32.obj \
    rt_sat_div_int8.obj \
    rt_sat_div_uint16.obj \
    rt_sat_div_uint32.obj \
    rt_sat_div_uint8.obj \
    rt_sat_prod_int16.obj \
    rt_sat_prod_int32.obj \
    rt_sat_prod_int8.obj \
    rt_sat_prod_uint16.obj \
    rt_sat_prod_uint32.obj \
    rt_sat_prod_uint8.obj \
    rt_tdelay.obj \
    rt_urand.obj \
    rt_zcfcn.obj \


rtwlib.lib : $(MAKEFILE) rtw_proj.tmw $(MODULES_rtwlib)
	@echo ### Creating $@
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(MODULES_rtwlib)
	@echo ### $@ Created 



#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c  
	$(CC) -c -Fo$@ $(CFLAGS) $<

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo ### Creating $@ 
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@echo ### $@ Created  

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo ### Deleting the generated source code for $(MODEL)
	@del $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c $(MODEL).rtw \
	        $(MODEL)_private.h $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo ### Deleting the objects and $(PROGRAM)
	@del $(LINK_OBJS) ..\$(MODEL).exe

# EOF: ert_lcc.tmf
