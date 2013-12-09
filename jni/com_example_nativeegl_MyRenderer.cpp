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
	renderFrame();
	//myRender->renderFrame();
}

/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeSurfaceChanged
 * Signature: (II)V
 */
void nativeSurfaceChanged(JNIEnv *env, jobject obj, jint width, jint height){
	resize(width, height);
	//myRender->resize(width, height);
}


/*
 * Class:     com_example_nativeegl_MyRenderer
 * Method:    nativeSurfaceCreated
 * Signature: ()V
 */
 void nativeSurfaceCreated(JNIEnv *env, jobject obj) {
	 //myRender = new MyRender();
	 //myRender->init();
	 init();
 }

 void init() {
 	LOGD("init the renderer");
 	glShadeModel(GL_SMOOTH);
 	glClearColor(0.0f,0.0f, 0.0f, 0.0f);            //set the background color to black when starts to glclear
 	glClearDepthf(1.0f);                               //set clear depth buffer bit to 1 when starts to glclear
 	glEnable(GL_DEPTH_TEST);
 	glDepthFunc(GL_LEQUAL);
 	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 }

 void resize(int width, int height) {
 	LOGD("resize the renderer");
 	glViewport(0,0, width, height);  //window size
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();

 //	GLfloat ratio = (GLfloat)width/(GLfloat)height;
 	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
 	//glOrthof(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);

 	glMatrixMode(GL_MODELVIEW);     // 选择模型观察矩阵
 	glLoadIdentity();                         // 重置模型观察矩阵
}

 void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar)
 {
     GLfloat top = zNear * ((GLfloat) tan(fovy * PI / 360.0));
     GLfloat bottom = -top;
     GLfloat left = bottom * aspect;
     GLfloat right = top * aspect;
     glFrustumf(left, right, bottom, top, zNear, zFar);
}

 void renderFrame() {
 	LOGD("renderFrame the renderer");
 	// starts to clear the color buffer and depth buffer with the value set in glclearcolor and glcleardepthf
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glLoadIdentity();                   // 重置模型观察矩阵
 	glTranslatef(0.0f,0.0f, -6.0f);             // 移入屏幕 6.0

 	glRotatef(rtri,0.0f,1.0f,0.0f);             // 绕Y轴旋转金字塔
 	glEnableClientState(GL_VERTEX_ARRAY);
 	glEnableClientState(GL_COLOR_ARRAY);
 	glColorPointer(4, GL_FLOAT, 0, gColors);

 	glVertexPointer(3, GL_FLOAT, 0, gVertices);
 	glDrawArrays(GL_TRIANGLES, 0, 12);
 	rtri += 0.2f;                       // 增加三角形的旋转变量
 	//LOGI("xxxxx");
 	glDisableClientState(GL_VERTEX_ARRAY);
 	glDisableClientState(GL_COLOR_ARRAY);
 	glFlush();              //force the OpenGL commands set above to execute

 	//force the OpenGL commands set above to execute. It will block the thread until above commands executed and returned.
 	//glFinish();
 }

 void printGLString(char* name, GLenum s) {
 	char *v = (char *) glGetString(s);
 	LOGI("GL %s = %s", name, v);
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
