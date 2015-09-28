LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

XERCES_SUBDIRS := $(patsubst $(LOCAL_PATH)/%, %, $(LOCAL_PATH)/src/xercesc/dom\
$(LOCAL_PATH)/src/xercesc/dom/impl\
$(LOCAL_PATH)/src/xercesc/framework\
$(LOCAL_PATH)/src/xercesc/framework/psvi\
$(LOCAL_PATH)/src/xercesc/internal\
$(LOCAL_PATH)/src/xercesc/NLS\
$(LOCAL_PATH)/src/xercesc/NLS/EN_US\
$(LOCAL_PATH)/src/xercesc/parsers\
$(LOCAL_PATH)/src/xercesc/sax\
$(LOCAL_PATH)/src/xercesc/sax2\
$(LOCAL_PATH)/src/xercesc/util\
$(LOCAL_PATH)/src/xercesc/util/FileManagers\
$(LOCAL_PATH)/src/xercesc/util/MsgLoaders\
$(LOCAL_PATH)/src/xercesc/util/MsgLoaders/InMemory\
$(LOCAL_PATH)/src/xercesc/util/MutexManagers\
$(LOCAL_PATH)/src/xercesc/util/NetAccessors\
$(LOCAL_PATH)/src/xercesc/util/regx\
$(LOCAL_PATH)/src/xercesc/util/Transcoders\
$(LOCAL_PATH)/src/xercesc/util/Transcoders/IconvGNU\
$(LOCAL_PATH)/src/xercesc/validators\
$(LOCAL_PATH)/src/xercesc/validators/common\
$(LOCAL_PATH)/src/xercesc/validators/datatype\
$(LOCAL_PATH)/src/xercesc/validators/DTD\
$(LOCAL_PATH)/src/xercesc/validators/schema\
$(LOCAL_PATH)/src/xercesc/validators/schema/identity\
$(LOCAL_PATH)/src/xercesc/xinclude)

LOCAL_MODULE := xerces

LOCAL_C_INCLUDES := $(LOCAL_PATH) $(LOCAL_PATH)/src $(LOCAL_PATH)/include \
                    $(LOCAL_PATH)/.. $(LOCAL_PATH)/include/xercesc/util $(LOCAL_PATH)/include/xercesc/util/MsgLoaders/InMemory \
                    $(LOCAL_PATH)/include/xercesc/dom/ $(LOCAL_PATH)/include/xercesc/dom/impl \
                    $(LOCAL_PATH)/include/xercesc/validators/schema/identity $(LOCAL_PATH)/include/xercesc/util/Transcoders/IconvGNU/ \
                    $(LOCAL_PATH)/include/xercesc/sax
LOCAL_CFLAGS := -Os -DHAVE_CONFIG_H

LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES := $(addprefix src/,$(notdir $(wildcard $(LOCAL_PATH)/src/*.cpp $(LOCAL_PATH)/src/*.c)))
LOCAL_SRC_FILES += $(foreach F, $(XERCES_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*.cpp))))

LOCAL_SHARED_LIBRARIES := sdl

include $(BUILD_STATIC_LIBRARY)
