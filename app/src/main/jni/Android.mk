MY_PATH := $(call my-dir)

$(call import-add-path,$(MY_PATH))
$(call import-module,mcpp)
$(call import-module,bzip2)
$(call import-module,expat)
$(call import-module,ice)
$(call import-module,sdl-2.0)
$(call import-module,xerces)

$(call import-module,FixCommA)

include $(CLEAR_VARS)
LOCAL_PATH := $(MY_PATH)

LOCAL_MODULE    := FixcomTest
LOCAL_SRC_FILES := com_mimimao_eric_fixcomma_NdkJniUtils.c fixcom_bridge.cpp BHKD_utilities.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/FixCommA/include
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_SHARED_LIBRARIES := gnustl_shared  bz2 expat IceUtil Ice sdl FixCommA
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)