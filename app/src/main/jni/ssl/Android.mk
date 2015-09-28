LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  lib/libssl.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_MODULE := ssl
include $(PREBUILT_SHARED_LIBRARY)