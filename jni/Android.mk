#Description:makefile of Helloworld  
LOCAL_PATH := $(call my-dir)
#=======================
include $(CLEAR_VARS)

LOCAL_CFLAGS    := -Wall

LOCAL_MODULE    := libmyegl_impl

LOCAL_CPP_EXTENSION := .cpp

#local_ldlibs is used for system libs and does not need dependency
LOCAL_LDLIBS += -llog -lGLESv1_CM

LOCAL_SHARED_LIBRARIES += libcutils libutils

LOCAL_C_INCLUDES := \
		$(LOCAL_PATH)/include 
LOCAL_SRC_FILES := \
		MyRendererNative.cpp

LOCAL_CFLAGS:= -DLOG_TAG=\"MyRender\"

include $(BUILD_STATIC_LIBRARY)

#========================

include $(CLEAR_VARS)
LOCAL_CFLAGS    := -Wall

LOCAL_MODULE    := myegl_jni

LOCAL_C_INCLUDES := \
		$(LOCAL_PATH)/include 

LOCAL_CPP_EXTENSION := .cpp

LOCAL_LDLIBS += -llog -lGLESv1_CM

#LOCAL_SHARED_LIBRARIES += libmyegl_impl  
LOCAL_STATIC_LIBRARIES := libmyegl_impl

LOCAL_SRC_FILES := \
    com_example_nativeegl_MyRenderer.cpp 

include $(BUILD_SHARED_LIBRARY)

# Use the folloing include to make our test apk.
#include $(call all-makefiles-under,$(LOCAL_PATH))