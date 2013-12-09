#include "com_example_nativeegl_MyRenderer.h"

extern "C" {
/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeGetHelloString
 * Signature: ()Ljava/lang/String;
 */
jstring  nativeGetHelloString(JNIEnv *env, jobject obj) {
      return env->NewStringUTF((char*)" This is calling from JNI suckers!");
  }

/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeDrawFrame
 * Signature: ()V
 */
void nativeDrawFrame(JNIEnv *env, jobject obj) {
	myRenderer->renderFrame();
}

/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeSurfaceChanged
 * Signature: (II)V
 */
void nativeSurfaceChanged(JNIEnv *env, jobject obj, jint width, jint height){
	myRenderer->resize(width, height);
}


/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeSurfaceCreated
 * Signature: ()V
 */
 void nativeSurfaceCreated(JNIEnv *env, jobject obj) {
	 myRenderer = new MyRenderer();
	 myRenderer->init();
 }

//----------------------------JNI part:Native register------------------------------------------------------
static JNINativeMethod gMethods[] = {
		//{"native method name from Java","(arguments type)return type", "(void*)local_native_name"
		{"nativeGetHelloString", "()Ljava/lang/String;", (void *)nativeGetHelloString},
		{"nativeDrawFrame", "()V", (void *)nativeDrawFrame},
		{"nativeSurfaceChanged", "(II)V", (void *)nativeSurfaceChanged},
		{"nativeSurfaceCreated", "()V", (void *)nativeSurfaceCreated},
};

static const char* className="com/example/nativeegldynamicjni/MyRenderer";

static int registerNativeMethods(JNIEnv *env) {
	jclass clazz;
	clazz = env->FindClass(className);
	if (clazz == NULL) {
		LOGD("failed to load the class %s", className);
		return JNI_FALSE;
	}
	if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(gMethods[0])) < 0) {
		return JNI_FALSE;
	}
	return JNI_TRUE;
} //end of registerNativeMethods

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = -1;
	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK)
	{
		LOGE("ERROR: GetEnv failed\n");
		goto bail;
	}

	if (registerNativeMethods(env) < 0) {
		LOGE("ERROR: jnitest native registration failed\n");
		goto bail;
	}
	result = JNI_VERSION_1_4;

	bail:
	return result;
}

} //end of extern "C"
