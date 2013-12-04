#Description:makefile of Helloworld  
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS    := -Wall

LOCAL_MODULE    := myegl_impl

LOCAL_CPP_EXTENSION := .cpp

#local_ldlibs is used for system libs and does not need dependency
LOCAL_LDLIBS += -llog -lGLESv1_CM

LOCAL_SRC_FILES := MyRenderer.cpp

LOCAL_CFLAGS:= -DLOG_TAG=\"MyRender\"

include $(BUILD_SHARED_LIBRARY)

