#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <GLES/gl.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern "C" {
#define  LOG_TAG    "libgl_jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
static const GLfloat PI = 3.1415f;

void printGLString(char* name, GLenum s);
void init();
void resize(int width, int height);
void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
void renderFrame();

GLfloat rtri;  //三角形的旋转变量

GLfloat rquad;  //四边形的旋转变量

const GLfloat gVertices[] = {
		 	        0.0f, 1.0f, 0.0f,
		 	        -1.0f,-1.0f, 1.0f,
		 	        1.0f,-1.0f, 1.0f,

		 	        0.0f, 1.0f, 0.0f,
		 	        1.0f,-1.0f, 1.0f,
		 	        1.0f,-1.0f, -1.0f,

		 	        0.0f, 1.0f, 0.0f,
		 	        1.0f,-1.0f, -1.0f,
		 	        -1.0f,-1.0f, -1.0f,

		 	        0.0f, 1.0f, 0.0f,
		 	        -1.0f,-1.0f,-1.0f,
		 	        -1.0f,-1.0f, 1.0f
		 	};
const GLfloat gColors[] = {
			        1.0f,0.0f,0.0f, 1.0f,
			        0.0f,1.0f,0.0f, 1.0f,
			        0.0f,0.0f,1.0f, 1.0f,

			        1.0f,0.0f,0.0f, 1.0f,
			        0.0f,0.0f,1.0f, 1.0f,
			        0.0f,1.0f,0.0f, 1.0f,

			        1.0f,0.0f,0.0f, 1.0f,
			        0.0f,1.0f,0.0f, 1.0f,
			        0.0f,0.0f,1.0f, 1.0f,

			        1.0f,0.0f,0.0f, 1.0f,
			        0.0f,0.0f,1.0f, 1.0f,
			        0.0f,1.0f,0.0f, 1.0f
			};
} //end of extern "C"
