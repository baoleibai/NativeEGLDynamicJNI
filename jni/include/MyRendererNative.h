#include <string.h>
#include <GLES/gl.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


class MyRenderer {
public:
	GLfloat rtri;  //三角形的旋转变量

	GLfloat rquad;  //四边形的旋转变量

	static const GLfloat PI = 3.1415f;

public:
	MyRenderer();
	virtual ~MyRenderer();

	void printGLString(char* name, GLenum s);
	void init();
	void resize(int width, int height);
	void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
	void renderFrame();
};
