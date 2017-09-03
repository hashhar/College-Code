#include "GL/freeglut.h"
#include <set>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

auto point1 = pair<double, double>(-10, -5);
auto point2 = pair<double, double>(5, 5);
auto point3 = pair<double, double>(-10, 5);

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set black background with white foreground
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	// Start rendering the triangle primitive
	glBegin(GL_TRIANGLES);
	glVertex2d(point1.first, point1.second);
	glVertex2d(point2.first, point2.second);
	glVertex2d(point3.first, point3.second);
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
	cout << "Enter point 1 (x,y) [" << point1.first << "," << point1.second << "]: ";
	string input;
	getline(cin, input);
	stringstream ss(input);
	char split;
	ss >> point1.first >> split >> point1.second;
	cout << "Enter point 2 (x,y) [" << point2.first << "," << point2.second << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> point2.first >> split >> point2.second;
	cout << "Enter point 3 (x,y) [" << point3.first << "," << point3.second << "]: ";
	getline(cin, input);
	ss = stringstream(input);
	ss >> point3.first >> split >> point3.second;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Triangle");
	glEnable(GL_DEPTH_TEST);

	point1.first /= 10; point1.second /= 10;
	point2.first /= 10; point2.second /= 10;
	point3.first /= 10; point3.second /= 10;

	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glutMainLoop();

	return 0;
}
