LOCAL_PATH:= $(call my-dir)
LIBICONV_PATH:=$(LOCAL_PATH)
 
include $(CLEAR_VARS)
LOCAL_MODULE := iconv
LOCAL_CFLAGS := \
	-Wno-multichar \
	-D_ANDROID \
	-DLIBDIR=\"\" \
	-DBUILDING_LIBICONV \
	-DIN_LIBRARY
 
LOCAL_C_INCLUDES := \
	$(LIBICONV_PATH)/ \
	$(LIBICONV_PATH)/include \
	$(LIBICONV_PATH)/lib \
	$(LIBICONV_PATH)/libcharset/include
 
LOCAL_SRC_FILES := \
	libcharset/lib/localcharset.c \
	lib/iconv.c \
	lib/relocatable.c
include $(BUILD_STATIC_LIBRARY)