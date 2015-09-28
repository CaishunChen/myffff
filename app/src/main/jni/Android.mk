MY_PATH := $(call my-dir)

$(call import-add-path,$(MY_PATH))
$(call import-module,mcpp)
$(call import-module,bzip2)
$(call import-module,ssl)
$(call import-module,expat)
$(call import-module,ice)

include $(CLEAR_VARS)
LOCAL_PATH := $(MY_PATH)

LOCAL_MODULE    := Fixcom
LOCAL_SRC_FILES := ./com_example_eric_iceeandroid_NdkJniUtils.c
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_SHARED_LIBRARIES := gnustl_shared  bz2 ssl expat Ice
LOCAL_STATIC_LIBRARIES := mcpp
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)