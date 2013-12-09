#include "MyRendererNative.h"

MyRenderer::MyRenderer():testintprivate(0) {
}

MyRenderer::~MyRenderer() {

}

int testintpublic = 12;   //static variable initialisation.

void MyRenderer::printGLString(char* name, GLenum s) {
	char *v = (char *) glGetString(s);
	LOGI("GL %s = %s", name, v);
}

void MyRenderer::init() {
	LOGD("init the renderer");
	rtri= 0;
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f, 0.0f, 0.0f);            //set the background color to black when starts to glclear
	glClearDepthf(1.0f);                               //set clear depth buffer bit to 1 when starts to glclear
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MyRenderer::resize(int width, int height) {
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
void MyRenderer::gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar)
{
    GLfloat top = zNear * ((GLfloat) tan(fovy * PI / 360.0));
    GLfloat bottom = -top;
    GLfloat left = bottom * aspect;
    GLfloat right = top * aspect;
    glFrustumf(left, right, bottom, top, zNear, zFar);
}

static GLfloat gColors[] = {
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

static GLfloat gVertices[]= {
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

void MyRenderer::renderFrame() {
	LOGD("renderFrame the renderer");
	// starts to clear the color buffer and depth buffer with the value set in glclearcolor and glcleardepthf
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                              // 重置模型观察矩阵
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
