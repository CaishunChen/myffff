LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  directive.c eval.c expand.c mbchar.c support.c system.c main_libmcpp.c
LOCAL_MODULE := mcpp
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_CFLAGS := $(GLOBAL_CFLAGS)
LOCAL_C_INCLUDES := $(GLOBAL_C_INCLUDES)
LOCAL_SHARED_LIBRARIES := gnustl_shared
LOCAL_CPP_FEATURES := rtti exceptions


include $(BUILD_STATIC_LIBRARY)