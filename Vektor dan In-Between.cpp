#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1300.0, 0.0, 400.0);
}


class GLintPoint
{
public:
	GLint x, y;
};


class Point2
{
public:
	float x, y;
	void set(float dx, float dy)
	{
		x = dx;
		y = dy;
	}
	void set(Point2& p)
	{
		x = p.x;
		y = p.y;
	}
	Point2(float xx, float yy)
	{
		x = xx;
		y = yy;
	}
	Point2()
	{
		x = y = 0;
	}
};


GLintPoint CP;


float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}


Point2 Tween(Point2 A, Point2 B, float t)
{
	Point2 P;
	P.x = lerp(A.x, B.x, t);
	P.y = lerp(A.y, B.y, t);
	return P;
}


void moveTo(GLint x, GLint y)
{
	CP.x = x; CP.y = y;
}


void lineTo(GLint x, GLint y)
{
	glBegin(GL_LINES);
	glVertex2i(CP.x, CP.y);
	glVertex2i(x, y);
	glEnd();
	glutSwapBuffers();
	CP.x = x; CP.y = y;
}


void drawTween(Point2 A[], Point2 B[], int n, float t)
{
	for (int i = 0; i < n; i++)
	{
		Point2 P;
		P = Tween(A[i], B[i], t);
		if (i == 0) moveTo(P.x, P.y);
		else lineTo(P.x, P.y);
	}
}


void myDisplay(void)
{
	int x;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

	Point2 A[18];
	A[0].set(20, 280);
	A[1].set(80, 320);
	A[2].set(120, 380);
	A[3].set(200, 380);
	A[4].set(240, 320);
	A[5].set(320, 280);
	A[6].set(320, 260);
	A[7].set(240, 280);
	A[8].set(240, 80);
	A[9].set(260, 20);
	A[10].set(200, 20);
	A[11].set(160, 100);
	A[12].set(120, 20);
	A[13].set(60, 20);
	A[14].set(80, 80);
	A[15].set(80, 280);
	A[16].set(20, 260);
	A[17].set(20, 280);

	Point2 B[18];
	B[0].set(800, 180);
	B[1].set(870, 150);
	B[2].set(1000, 150);
	B[3].set(1000, 220);
	B[4].set(1080, 220);
	B[5].set(1160, 150);
	B[6].set(1280, 150);
	B[7].set(1280, 50);
	B[8].set(1230, 50);
	B[9].set(1210, 9);
	B[10].set(1150, 9);
	B[11].set(1120, 50);
	B[12].set(950, 50);
	B[13].set(930, 9);
	B[14].set(870, 9);
	B[15].set(850, 50);
	B[16].set(800, 50);
	B[17].set(800, 180);




	glColor3f(1, 0, 0);
	drawTween(A, B, 18, 0.0);

	glColor3f(0, 0, 1);
	for (x = 1; x <= 5; x += 1)
	{
		drawTween(A, B, 18, 0.2 * x);
	}

	glColor3f(1, 0, 0);
	drawTween(A, B, 18, 1);


	glFlush();
	glutSwapBuffers();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1400, 400);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("672019098-Transformers");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}