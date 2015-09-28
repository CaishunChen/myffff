LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES :=  blocksort.c huffman.c crctable.c randtable.c compress.c decompress.c bzlib.c bzip2.c bzip2recover.c
LOCAL_MODULE := bz2
LOCAL_CFLAGS := $(GLOBAL_CFLAGS)
LOCAL_C_INCLUDES := $(GLOBAL_C_INCLUDES)
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_SHARED_LIBRARIES := gnustl_shared
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)