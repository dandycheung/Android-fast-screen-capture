LOCAL_PATH := $(my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := libgui
LOCAL_INSTALLED_MODULE_STEM := libgui.so
LOCAL_SDK_VERSION := 22
LOCAL_CPP_EXTENSION := .cpp
LOCAL_CPPFLAGS := -std=c++17
LOCAL_SRC_FILES := libgui.cpp
LOCAL_LDLIBS := -llog
# LOCAL_SHARED_LIBRARIES := liblog
LOCAL_MODULE_PATH := $(TARGET_OUT)/libs
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := libbinder
LOCAL_INSTALLED_MODULE_STEM := libbinder.so
LOCAL_SDK_VERSION := 22
LOCAL_CPP_EXTENSION := .cpp
LOCAL_CPPFLAGS := -std=c++17
LOCAL_SRC_FILES := libbinder.cpp
LOCAL_LDLIBS := -llog
# LOCAL_SHARED_LIBRARIES := liblog
LOCAL_MODULE_PATH := $(TARGET_OUT)/libs
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := libutils
LOCAL_INSTALLED_MODULE_STEM := libutils.so
LOCAL_SDK_VERSION := 22
LOCAL_CPP_EXTENSION := .cpp
LOCAL_CPPFLAGS := -std=c++17
LOCAL_SRC_FILES := libutils.cpp
LOCAL_LDLIBS := -llog
# LOCAL_SHARED_LIBRARIES := liblog
LOCAL_MODULE_PATH := $(TARGET_OUT)/libs
include $(BUILD_SHARED_LIBRARY)
