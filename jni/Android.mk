#Description:makefile of Helloworld  
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS    := -Wall

LOCAL_MODULE    := myegl_jni

LOCAL_C_INCLUDES :=$(LOCAL_PATH)/include

LOCAL_CPP_EXTENSION := .cpp

LOCAL_LDLIBS += -llog -lGLESv1_CM

LOCAL_SHARED_LIBRARIES := \
   myegl_impl

LOCAL_SRC_FILES := \
    com_example_nativeegl_MyRenderer.cpp 

include $(BUILD_SHARED_LIBRARY)

# Use the folloing include to make our test apk.
include $(call all-makefiles-under,$(LOCAL_PATH))

