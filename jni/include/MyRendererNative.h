#include <string.h>
#include <GLES/gl.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <android/log.h>

#define  LOG_TAG    "libgl_impl"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

class MyRenderer {
private:
	GLfloat rtri;  //三角形的旋转变量
	GLfloat rquad;  //四边形的旋转变量
	int testintprivate;   //non-static variable need to be initialised in constructor method

public:
	static const GLfloat PI = 3.1415f;
	static int testintpublic;

public:
	MyRenderer();
	virtual ~MyRenderer();

	void printGLString(char* name, GLenum s);
	void init();
	void resize(int width, int height);
	void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
	void renderFrame();
};
