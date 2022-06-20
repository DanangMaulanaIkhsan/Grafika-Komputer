#include <GL/glut.h>
#define RATIO 1.200

#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001
int WindowWidth;
int WindowHeight;

void InitGL() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0, 0, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glShadeModel(GL_SMOOTH);
	glViewport(0, 0, WindowWidth, WindowHeight);
}

void Display() {
	glLineWidth(4.0);
	float StartShape[14][2] = {
		{-15, -15}, {5, -15}, {10, -5}, {10, 5}, {5, 15}, {-15, 15},
		 {-15, -15}, {-12, -12}, {4, -12}, {8, -4}, {8, 4}, {4, 12}, {-12, 12}, {-12, -12}
	};
	float EndShape[14][2] = {
		{-15, -15}, {-5, -15}, {5, 5}, {5, 15}, {-15, 15}, {-15, 5},
		{-5, 5}, {-15, -15}, {-5, -15}, {5, 5}, {5, 15}, {-15, 15}, {-15, 5}, {-5, 5}
	};
	float IntermediateShape[14][2];
	float VertexColors[14][3] = {
		{1, 0, 0}, {1, 1, 0}, {1, 0, 1}, {0, 1, 0}, {0, 1, 1}, {0, 0, 1},
		{1, 0.5, 0}, {1, 0, 0.5}, {0.5, 1, 0}, {0.5, 0, 1}, {1, 0, 0.5}, {0, 1, 0.5}, {1, 0, 0}, {1, 1, 0}
	};
	static float Tween = 0.0 - deltat;
	if (Tween < 1) {
		Tween += deltat;
	}
	for (int Vtx = 0; Vtx < 14; Vtx++) {
		IntermediateShape[Vtx][0] = (1.0 - Tween) * StartShape[Vtx][0]
			+ Tween * EndShape[Vtx][0];
		IntermediateShape[Vtx][1] = (1.0 - Tween) * StartShape[Vtx][1]
			+ Tween * EndShape[Vtx][1];
	}
	glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
	glColorPointer(3, GL_FLOAT, 0, VertexColors);
	for (int i = 0; i < 100000; i++);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_LINE_LOOP, 0, 14);
	glutSwapBuffers();
	glutPostRedisplay();
	
}

void Reshape(int w, int h) {
	glutReshapeWindow(w, (int)(w / RATIO));
	WindowWidth = w;
	WindowHeight = (int)(w / RATIO);
	InitGL();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH) * .4);
	WindowHeight = (int)(WindowWidth / RATIO);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH) * .1), (glutGet((GLenum)GLUT_SCREEN_HEIGHT) / 2) - (WindowHeight / 2));
	glutCreateWindow("Danang Maulana Ikhsan-672019098");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	InitGL();
	glutMainLoop();
}