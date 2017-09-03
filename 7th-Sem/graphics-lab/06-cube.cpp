#include "GL/freeglut.h"
#include <set>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double angleCube = 0.0;
int refreshMills = 15;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set black background with white foreground
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -7.0);
	glRotated(angleCube, 1.0, 1.0, 1.0);

	// Start rendering the quadrilateral primitive
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	// Top face (y = 1.0)
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(1.0, 1.0, 1.0);

	// Bottom face (y = -1.0)
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(1.0, -1.0, -1.0);

	// Front face  (z = 1.0)
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);

	// Back face (z = -1.0)
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);

	// Left face (x = -1.0)
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, 1.0);

	// Right face (x = 1.0)
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glEnd();

	glutSwapBuffers();
	angleCube -= 0.15;
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMills, timer, 0);
}

void reshapeScene(GLsizei width, GLsizei height)
{
	// Find new aspect ratio
	if (height == 0)
		height = 1;
	GLdouble aspect = (GLdouble)width / (GLdouble)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Cube");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}
