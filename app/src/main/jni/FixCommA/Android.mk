
#
# Compile with support for the Ice router facility.
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

GLOBAL_C_INCLUDES := $(LOCAL_PATH)/include $(LOCAL_PATH)/include/ICESERVER $(LOCAL_PATH)/../xerces/include


ICE_DIR			:= src



ICE_SRCS		:= \
				$(ICE_DIR)/ACO.cpp \
				$(ICE_DIR)/ACOA.cpp \
				$(ICE_DIR)/ACOImpl.cpp \
				$(ICE_DIR)/BHACO.cpp \
				$(ICE_DIR)/FixCommA.cpp \
				$(ICE_DIR)/Handler.cpp \
				$(ICE_DIR)/TDateTime.cpp \
				$(ICE_DIR)/ACOConfig.cpp\
				$(ICE_DIR)/Util.cpp
				
LOCAL_SRC_FILES :=  $(ICE_SRCS)

LOCAL_MODULE := FixCommA

GLOBAL_CFLAGS  :=  -D_REENTRANT -DNDEBUG  -DICE_IGNORE_VERSION \
		-DPAGE_SIZE=0x400 -ftemplate-depth-128 -Wall -Os -DFIXCOMMA_EXPORTS\
		-fdata-sections -ffunction-sections -isystem $(SYSROOT)/usr/include/

LOCAL_CFLAGS := $(GLOBAL_CFLAGS)
LOCAL_C_INCLUDES := $(GLOBAL_C_INCLUDES)

LOCAL_SHARED_LIBRARIES := gnustl_shared IceUtil Ice 
LOCAL_STATIC_LIBRARIES := xerces
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)
