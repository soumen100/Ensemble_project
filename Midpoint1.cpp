/*
Name:- soumen Halder.
Roll No. 702
Subject:- CC-14 Computer Graphics */

/* Program: Write a program to implement Midpoint Circle Algorithm */
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

int X1, Y1, r;

void plot_fun(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+X1, y+Y1);
	glEnd();
}


void myInit_fun (void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot_fun(x, y);
		plot_fun(x, -y);
		plot_fun(-x, y);
		plot_fun(-x, -y);
		plot_fun(y, x);
		plot_fun(-y, x);
		plot_fun(y, -x);
		plot_fun(-y, -x);
	}

}

void Display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate: "; cin >> X1;
	cout << "\nY-coordinate: "; cin >> Y1;
	cout << "\nEnter radius : "; cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Midpoint Circle Drawing Algorithms");
	myInit_fun ();
	glutDisplayFunc(Display);
	glutMainLoop();

}
