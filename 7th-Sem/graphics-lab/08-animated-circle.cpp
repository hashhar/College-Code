#include "GL/freeglut.h"
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

auto center = pair<double, double>(0, 0);
double radius = 2.0;
bool filled = false;
int refreshMills = 10;
double circlePos = -10.0;
double delta = 0.01;
int direction = 1;

void drawFilledCircle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(center.first + circlePos, center.second);
	for (double angle = 1.0; angle < 361.0; angle += 0.2)
	{
		double x = center.first + sin(angle) * radius;
		double y = center.second + cos(angle) * radius;
		glVertex2d(x + circlePos, y);
	}
	circlePos += direction * delta;
	glEnd();
}

void drawEmptyCircle()
{
	// Start rendering the circle
	glBegin(GL_LINE_LOOP);
	const int loops = 300;
	for (int i = 0; i <= loops; i++)
	{
		double angle = 2 * M_PI * i / loops;
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2d(x + center.first + circlePos, y + center.second);
	}
	circlePos += direction * delta;
	glEnd();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set black background with white foreground
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if (direction == 1 && circlePos > 1.0)
		direction = -1;
	else if (direction == -1 && circlePos < -1.0)
		direction = 1;

	filled ? drawFilledCircle() : drawEmptyCircle();
	glutSwapBuffers();
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
	cout << "Enter center (x,y) [" << center.first << "," << center.second << "]: ";
	string input;
	getline(cin, input);
	stringstream ss(input);
	char split;
	ss >> center.first >> split >> center.second;
	cout << "Enter radius [" << radius << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> radius;
	cout << "Fill the circle (y/n) [" << (filled ? "y" : "n") << "]: ";
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
	glutCreateWindow("Circle");
	glEnable(GL_DEPTH_TEST);

	center.first /= 10; center.second /= 10;
	radius /= 10;
	circlePos /= 10;

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}
