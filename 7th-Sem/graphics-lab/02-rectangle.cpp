#include "GL/freeglut.h"
#include <set>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

auto topLeft = pair<double, double>(-5, 5);
double length = 10, breadth = 5;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set black background with white foreground
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	// Start rendering the quadrilateral primitive
	glBegin(GL_QUADS);
	glVertex2d(topLeft.first, topLeft.second);
	glVertex2d(topLeft.first + length, topLeft.second);
	glVertex2d(topLeft.first + length, topLeft.second - breadth);
	glVertex2d(topLeft.first, topLeft.second - breadth);
	glEnd();
	glutSwapBuffers();
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
	if (width >= height)
	{
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else
	{
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

int main(int argc, char** argv)
{
	cout << "Enter top left corner (x,y) [" << topLeft.first << "," << topLeft.second << "]: ";
	string input;
	getline(cin, input);
	stringstream ss(input);
	char split;
	ss >> topLeft.first >> split >> topLeft.second;
	cout << "Enter length, breadth (l,b) [" << length << "," << breadth << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> length >> split >> breadth;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Rectangle");
	glEnable(GL_DEPTH_TEST);

	topLeft.first /= 10; topLeft.second /= 10;
	length /= 10; breadth /= 10;

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glutMainLoop();

	return 0;
}
