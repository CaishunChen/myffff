LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  lib/libexpat.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_MODULE := expat
include $(PREBUILT_SHARED_LIBRARY)