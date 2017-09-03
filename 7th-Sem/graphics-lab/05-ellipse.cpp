#include "GL/freeglut.h"
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

auto center = pair<double, double>(0, 0);
double minorRadius = 5.0, majorRadius = 8.0;
bool filled = false;

void drawFilledEllipse()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(center.first, center.second);
	for (double angle = 1.0; angle < 361.0; angle += 0.2)
	{
		double x = center.first + sin(angle) * minorRadius;
		double y = center.second + cos(angle) * majorRadius;
		glVertex2d(x, y);
	}
	glEnd();
}

void drawEmptyEllipse()
{
	glBegin(GL_LINE_LOOP);
	const int loops = 300;
	for (int i = 0; i <= loops; i++)
	{
		double angle = 2 * M_PI * i / loops;
		double x = minorRadius * cos(angle);
		double y = majorRadius * sin(angle);
		glVertex2d(x + center.first, y + center.second);
	}
	glEnd();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set black background with white foreground
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	filled ? drawFilledEllipse() : drawEmptyEllipse();
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
	cout << "Enter midpoint (x,y) [" << center.first << "," << center.second << "]: ";
	string input;
	getline(cin, input);
	stringstream ss(input);
	char split;
	ss >> center.first >> split >> center.second;
	cout << "Enter minor radius (along x axis) [" << minorRadius << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> minorRadius;
	cout << "Enter major radius (along y axis) [" << majorRadius << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> majorRadius;
	cout << "Fill the ellipse (y/n) [" << (filled ? "y" : "n") << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	char temp = filled ? 'y' : 'n';
	ss >> temp;
	if (tolower(temp) == 'y')
		filled = true;
	else
		filled = false;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Ellipse");
	glEnable(GL_DEPTH_TEST);

	center.first /= 10; center.second /= 10;
	minorRadius /= 10; majorRadius /= 10;

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glutMainLoop();

	return 0;
}
