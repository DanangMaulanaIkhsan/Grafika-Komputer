#include <GL/glut.h>
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
bool cek = false;
int is_depth;

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	//glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0);
}

void tampil() {
	if(cek == false || mouseDown == false){
		
		if (is_depth)
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		else
			glClear(GL_COLOR_BUFFER_BIT);
		cek = true;
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glRotatef(xrot, 1.0, 0.0, 0.0);
		glRotatef(yrot, 0.0, 1.0, 0.0);
		glPushMatrix();
		cek = false;
	}
	
	//depan
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, -10.0, 10.0);
	glVertex3f(-20.0, 40.0, 10.0);
	glVertex3f(20.0, 40.0, 10.0);
	glVertex3f(20.0, -10.0, 10.0);
	//depan1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -10.0, 10.1);
	glVertex3f(-20.0, 10.0, 10.1);
	glVertex3f(0.0, 10.0, 10.1);
	glVertex3f(0.0, -10.0, 10.1);
	//tembok dalam depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.9);
	glVertex3f(-20.0, -10.0, 9.0);
	glVertex3f(-20.0, 40.0, 9.0);
	glVertex3f(20.0, 40.0, 9.0);
	glVertex3f(20.0, -10.0, 9.0);
	glEnd();
	//pintu kiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.6, 0.0);
	glVertex3f(-15.0, -10.0, 10.2);
	glVertex3f(-15.0, 8.0, 10.2);
	glVertex3f(-5.5, 8.0, 10.2);
	glVertex3f(-5.5, -10.0, 10.2);
	//
	glVertex3f(-5.5, -10.0, 10.0);
	glVertex3f(-5.5, 8.0, 10.0);
	glVertex3f(-5.5, 8.0, 9.0);
	glVertex3f(-5.5, -10.0, 9.0);
	//
	glVertex3f(-15.0, -10.0, 10.0);
	glVertex3f(-15.0, 8.0, 10.0);
	glVertex3f(-15.0, 8.0, 9.0);
	glVertex3f(-15.0, -10.0, 9.0);
	//
	glVertex3f(-15.0, 8.0, 10.0);
	glVertex3f(-5.5, 8.0, 10.0);
	glVertex3f(-5.5, 8.0, 9.0);
	glVertex3f(-15.0, 8.0, 9.0);
	//
	glVertex3f(-15.0, -10.0, 8.9);
	glVertex3f(-15.0, 8.0, 8.9);
	glVertex3f(-5.5, 8.0, 8.9);
	glVertex3f(-5.5, -10.0, 8.9);
	glEnd();
	//pintu kanan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.0);
	glVertex3f(18.0, -10.0, 10.2);
	glVertex3f(18.0, 7.0, 10.2);
	glVertex3f(13.0, 7.0, 10.2);
	glVertex3f(13.0, -10.0, 10.2);
	//
	glVertex3f(18.0, -10.0, 8.9);
	glVertex3f(18.0, 7.0, 8.9);
	glVertex3f(13.0, 7.0, 8.9);
	glVertex3f(13.0, -10.0, 8.9);
	//
	glVertex3f(13.0, -10.0, 10.0);
	glVertex3f(13.0, 7.0, 10.0);
	glVertex3f(13.0, 7.0, 9.0);
	glVertex3f(13.0, -10.0, 9.0);
	//
	glVertex3f(18.0, -10.0, 10.0);
	glVertex3f(18.0, 7.0, 10.0);
	glVertex3f(18.0, 7.0, 9.0);
	glVertex3f(18.0, -10.0, 9.0);
	//
	glVertex3f(18.0, 7.0, 10.0);
	glVertex3f(13.0, 7.0, 10.0);
	glVertex3f(13.0, 7.0, 9.0);
	glVertex3f(18.0, 7.0, 9.0);
	glEnd();
	//jendela depan bawah
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-4.5, -8.0, 10.2);
	glVertex3f(-4.5, 8.0, 10.2);
	glVertex3f(-2.0, 8.0, 10.2);
	glVertex3f(-2.0, -8.0, 10.2);
	//
	glVertex3f(-4.5, -8.0, 8.9);
	glVertex3f(-4.5, 8.0, 8.9);
	glVertex3f(-2.0, 8.0, 8.9);
	glVertex3f(-2.0, -8.0, 8.9);
	//
	glVertex3f(-18.5, -8.0, 10.2);
	glVertex3f(-18.5, 8.0, 10.2);
	glVertex3f(-16.0, 8.0, 10.2);
	glVertex3f(-16.0, -8.0, 10.2);
	//
	glVertex3f(-18.5, -8.0, 8.9);
	glVertex3f(-18.5, 8.0, 8.9);
	glVertex3f(-16.0, 8.0, 8.9);
	glVertex3f(-16.0, -8.0, 8.9);
	//
	glVertex3f(2.5, -8.0, 10.2);
	glVertex3f(2.5, 8.0, 10.2);
	glVertex3f(7.0, 8.0, 10.2);
	glVertex3f(7.0, -8.0, 10.2);
	//
	glVertex3f(2.5, -8.0, 8.9);
	glVertex3f(2.5, 8.0, 8.9);
	glVertex3f(7.0, 8.0, 8.9);
	glVertex3f(7.0, -8.0, 8.9);
	//
	glVertex3f(8.0, -8.0, 10.2);
	glVertex3f(8.0, 8.0, 10.2);
	glVertex3f(12.5, 8.0, 10.2);
	glVertex3f(12.5, -8.0, 10.2);
	//
	glVertex3f(8.0, -8.0, 8.9);
	glVertex3f(8.0, 8.0, 8.9);
	glVertex3f(12.5, 8.0, 8.9);
	glVertex3f(12.5, -8.0, 8.9);
	glEnd();
	//jendela depan atas
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-4.5, 30.0, 10.2);
	glVertex3f(-4.5, 18.0, 10.2);
	glVertex3f(-2.0, 18.0, 10.2);
	glVertex3f(-2.0, 30.0, 10.2);
	//
	glVertex3f(-4.5, 30.0, 8.9);
	glVertex3f(-4.5, 18.0, 8.9);
	glVertex3f(-2.0, 18.0, 8.9);
	glVertex3f(-2.0, 30.0, 8.9);
	//
	glVertex3f(-16.0, 30.0, 10.2);
	glVertex3f(-16.0, 18.0, 10.2);
	glVertex3f(-10.0, 18.0, 10.2);
	glVertex3f(-10.0, 30.0, 10.2);
	//
	glVertex3f(-16.0, 30.0, 8.9);
	glVertex3f(-16.0, 18.0, 8.9);
	glVertex3f(-10.0, 18.0, 8.9);
	glVertex3f(-10.0, 30.0, 8.9);
	//
	glVertex3f(4.5, 30.0, 10.2);
	glVertex3f(4.5, 18.0, 10.2);
	glVertex3f(2.0, 18.0, 10.2);
	glVertex3f(2.0, 30.0, 10.2);
	//
	glVertex3f(4.5, 30.0, 8.9);
	glVertex3f(4.5, 18.0, 8.9);
	glVertex3f(2.0, 18.0, 8.9);
	glVertex3f(2.0, 30.0, 8.9);
	//
	glVertex3f(16.0, 30.0, 10.2);
	glVertex3f(16.0, 18.0, 10.2);
	glVertex3f(10.0, 18.0, 10.2);
	glVertex3f(10.0, 30.0, 10.2);
	//
	glVertex3f(16.0, 30.0, 8.9);
	glVertex3f(16.0, 18.0, 8.9);
	glVertex3f(10.0, 18.0, 8.9);
	glVertex3f(10.0, 30.0, 8.9);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, -10.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glVertex3f(20.0, 40.0, -50.0);
	glVertex3f(20.0, -10.0, -50.0);
	glEnd();
	//tembok dalam belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.9);
	glVertex3f(-20.0, -10.0, -49.0);
	glVertex3f(-20.0, 40.0, -49.0);
	glVertex3f(20.0, 40.0, -49.0);
	glVertex3f(20.0, -10.0, -49.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(20.0, 40.0, 11.0);
	glVertex3f(20.0, -10.0, 11.0);
	glVertex3f(20.0, -10.0, -50.0);
	glVertex3f(20.0, 40.0, -50.0);
	//
	glVertex3f(19.0, 40.0, 11.0);
	glVertex3f(19.0, -10.0, 11.0);
	glVertex3f(19.0, -10.0, 10.0);
	glVertex3f(19.0, 40.0, 10.0);
	//
	glVertex3f(19.0, -10.0, 11.0);
	glVertex3f(19.0, 40.0, 11.0);
	glVertex3f(20.0, 40.0, 11.0);
	glVertex3f(20.0, -10.0, 11.0);
	glEnd();
	//tembok dalam kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.9);
	glVertex3f(19.0, 40.0, 10.0);
	glVertex3f(19.0, -10.0, 10.0);
	glVertex3f(19.0, -10.0, -50.0);
	glVertex3f(19.0, 40.0, -50.0);
	glEnd();
	//jendela kanan bawah
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(20.1, 9.0, 8.0);
	glVertex3f(20.1, 5.0, 8.0);
	glVertex3f(20.1, 5.0, -4.0);
	glVertex3f(20.1, 9.0, -4.0);
	//
	glVertex3f(18.9, 9.0, 8.0);
	glVertex3f(18.9, 5.0, 8.0);
	glVertex3f(18.9, 5.0, -4.0);
	glVertex3f(18.9, 9.0, -4.0);
	//
	glVertex3f(20.1, 9.0, -12.0);
	glVertex3f(20.1, 5.0, -12.0);
	glVertex3f(20.1, 5.0, -24.0);
	glVertex3f(20.1, 9.0, -24.0);
	//
	glVertex3f(18.9, 9.0, -12.0);
	glVertex3f(18.9, 5.0, -12.0);
	glVertex3f(18.9, 5.0, -24.0);
	glVertex3f(18.9, 9.0, -24.0);
	//
	glVertex3f(20.1, 9.0, -28.0);
	glVertex3f(20.1, 5.0, -28.0);
	glVertex3f(20.1, 5.0, -32.0);
	glVertex3f(20.1, 9.0, -32.0);
	//
	glVertex3f(18.9, 9.0, -28.0);
	glVertex3f(18.9, 5.0, -28.0);
	glVertex3f(18.9, 5.0, -32.0);
	glVertex3f(18.9, 9.0, -32.0);
	//
	glVertex3f(20.1, 9.0, -36.0);
	glVertex3f(20.1, 5.0, -36.0);
	glVertex3f(20.1, 5.0, -38.0);
	glVertex3f(20.1, 9.0, -38.0);
	//
	glVertex3f(18.9, 9.0, -36.0);
	glVertex3f(18.9, 5.0, -36.0);
	glVertex3f(18.9, 5.0, -38.0);
	glVertex3f(18.9, 9.0, -38.0);
	//
	glVertex3f(20.1, 9.0, -40.0);
	glVertex3f(20.1, 5.0, -40.0);
	glVertex3f(20.1, 5.0, -46.0);
	glVertex3f(20.1, 9.0, -46.0);
	//
	glVertex3f(18.9, 9.0, -40.0);
	glVertex3f(18.9, 5.0, -40.0);
	glVertex3f(18.9, 5.0, -46.0);
	glVertex3f(18.9, 9.0, -46.0);
	glEnd();
	//jendela kanan atas
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(20.1, 30.0, -12.0);
	glVertex3f(20.1, 22.0, -12.0);
	glVertex3f(20.1, 22.0, -20.0);
	glVertex3f(20.1, 30.0, -20.0);
	//
	glVertex3f(18.9, 30.0, -12.0);
	glVertex3f(18.9, 22.0, -12.0);
	glVertex3f(18.9, 22.0, -20.0);
	glVertex3f(18.9, 30.0, -20.0);
	//
	glVertex3f(20.1, 32.0, -24.0);
	glVertex3f(20.1, 26.0, -24.0);
	glVertex3f(20.1, 26.0, -30.0);
	glVertex3f(20.1, 32.0, -30.0);
	//
	glVertex3f(18.9, 32.0, -24.0);
	glVertex3f(18.9, 26.0, -24.0);
	glVertex3f(18.9, 26.0, -30.0);
	glVertex3f(18.9, 32.0, -30.0);
	//
	glVertex3f(20.1, 30.0, -38.0);
	glVertex3f(20.1, 22.0, -38.0);
	glVertex3f(20.1, 22.0, -44.0);
	glVertex3f(20.1, 30.0, -44.0);
	//
	glVertex3f(18.9, 30.0, -38.0);
	glVertex3f(18.9, 22.0, -38.0);
	glVertex3f(18.9, 22.0, -44.0);
	glVertex3f(18.9, 30.0, -44.0);
	//
	glVertex3f(20.1, 30.0, 0.0);
	glVertex3f(20.1, 28.0, 2.0);
	glVertex3f(20.1, 26.0, 0.0);
	glVertex3f(20.1, 28.0, -2.0);
	//
	glVertex3f(20.1, 30.0, 5.0);
	glVertex3f(20.1, 28.0, 7.0);
	glVertex3f(20.1, 26.0, 5.0);
	glVertex3f(20.1, 28.0, 3.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-20.0, 40.0, 11.0);
	glVertex3f(-20.0, -10.0, 11.0);
	glVertex3f(-20.0, -10.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	//
	glVertex3f(-19.0, 40.0, 11.0);
	glVertex3f(-19.0, -10.0, 11.0);
	glVertex3f(-19.0, -10.0, 10.0);
	glVertex3f(-19.0, 40.0, 10.0);
	//
	glVertex3f(-19.0, -10.0, 11.0);
	glVertex3f(-19.0, 40.0, 11.0);
	glVertex3f(-20.0, 40.0, 11.0);
	glVertex3f(-20.0, -10.0, 11.0);
	glEnd();
	//tembok dalam kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.9);
	glVertex3f(-19.0, 40.0, 10.0);
	glVertex3f(-19.0, -10.0, 10.0);
	glVertex3f(-19.0, -10.0, -50.0);
	glVertex3f(-19.0, 40.0, -50.0);
	glEnd();
	//jendela kiri bawah
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-20.1, 8.0, 5.0);
	glVertex3f(-20.1, -5.0, 5.0);
	glVertex3f(-20.1, -5.0, 2.0);
	glVertex3f(-20.1, 8.0, 2.0);
	//
	glVertex3f(-18.9, 8.0, 5.0);
	glVertex3f(-18.9, -5.0, 5.0);
	glVertex3f(-18.9, -5.0, 2.0);
	glVertex3f(-18.9, 8.0, 2.0);
	//
	glVertex3f(-20.1, 8.0, -1.0);
	glVertex3f(-20.1, -5.0, -1.0);
	glVertex3f(-20.1, -5.0, -4.0);
	glVertex3f(-20.1, 8.0, -4.0);
	//
	glVertex3f(-18.9, 8.0, -1.0);
	glVertex3f(-18.9, -5.0, -1.0);
	glVertex3f(-18.9, -5.0, -4.0);
	glVertex3f(-18.9, 8.0, -4.0);
	//
	glVertex3f(-20.1, 8.0, -9.0);
	glVertex3f(-20.1, -5.0, -9.0);
	glVertex3f(-20.1, -5.0, -12.0);
	glVertex3f(-20.1, 8.0, -12.0);
	//
	glVertex3f(-18.9, 8.0, -9.0);
	glVertex3f(-18.9, -5.0, -9.0);
	glVertex3f(-18.9, -5.0, -12.0);
	glVertex3f(-18.9, 8.0, -12.0);
	//
	glVertex3f(-20.1, 8.0, -14.0);
	glVertex3f(-20.1, -5.0, -14.0);
	glVertex3f(-20.1, -5.0, -17.0);
	glVertex3f(-20.1, 8.0, -17.0);
	//
	glVertex3f(-18.9, 8.0, -14.0);
	glVertex3f(-18.9, -5.0, -14.0);
	glVertex3f(-18.9, -5.0, -17.0);
	glVertex3f(-18.9, 8.0, -17.0);
	//
	glVertex3f(-20.1, 8.0, -19.0);
	glVertex3f(-20.1, -5.0, -19.0);
	glVertex3f(-20.1, -5.0, -22.0);
	glVertex3f(-20.1, 8.0, -22.0);
	//
	glVertex3f(-18.9, 8.0, -19.0);
	glVertex3f(-18.9, -5.0, -19.0);
	glVertex3f(-18.9, -5.0, -22.0);
	glVertex3f(-18.9, 8.0, -22.0);
	glEnd();
	//jendela kiri atas
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-20.1, 30.0, -2.0);
	glVertex3f(-20.1, 18.0, -2.0);
	glVertex3f(-20.1, 18.0, 2.0);
	glVertex3f(-20.1, 30.0, 2.0);
	//
	glVertex3f(-18.9, 30.0, -2.0);
	glVertex3f(-18.9, 18.0, -2.0);
	glVertex3f(-18.9, 18.0, 2.0);
	glVertex3f(-18.9, 30.0, 2.0);
	//
	glVertex3f(-20.1, 29.0, -18.0);
	glVertex3f(-20.1, 18.0, -18.0);
	glVertex3f(-20.1, 18.0, -21.0);
	glVertex3f(-20.1, 29.0, -21.0);
	//
	glVertex3f(-18.9, 29.0, -18.0);
	glVertex3f(-18.9, 18.0, -18.0);
	glVertex3f(-18.9, 18.0, -21.0);
	glVertex3f(-18.9, 29.0, -21.0);
	//
	glVertex3f(-20.1, 29.0, -13.0);
	glVertex3f(-20.1, 18.0, -13.0);
	glVertex3f(-20.1, 18.0, -16.0);
	glVertex3f(-20.1, 29.0, -16.0);
	// 
	glVertex3f(-18.9, 29.0, -13.0);
	glVertex3f(-18.9, 18.0, -13.0);
	glVertex3f(-18.9, 18.0, -16.0);
	glVertex3f(-18.9, 29.0, -16.0);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -10.0, 10.0);
	glVertex3f(20.0, -10.0, 10.0);
	glVertex3f(20.0, -10.0, -50.0);
	glVertex3f(-20.0, -10.0, -50.0);
	glEnd();
	//detail tengah rumah
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-1.0, 40.0, 11.0);
	glVertex3f(-1.0, -10.0, 11.0);
	glVertex3f(-1.0, -10.0, 10.0);
	glVertex3f(-1.0, 40.0, 10.0);
	//
	glVertex3f(1.0, 40.0, 11.0);
	glVertex3f(1.0, -10.0, 11.0);
	glVertex3f(1.0, -10.0, 10.0);
	glVertex3f(1.0, 40.0, 10.0);
	//
	glVertex3f(-1.0, -10.0, 11.0);
	glVertex3f(-1.0, 40.0, 11.0);
	glVertex3f(1.0, 40.0, 11.0);
	glVertex3f(1.0, -10.0, 11.0);
	glEnd();
	//atap 
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 40.0, 10.0);
	glVertex3f(20.0, 40.0, 10.0);
	glVertex3f(20.0, 40.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glEnd();
	//atap1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.6, 0.0);
	glVertex3f(-20.0, 25.0 + 15.0, 11.0);
	glVertex3f(20.0, 25.0 + 15.0, 11.0);
	glVertex3f(20.0, 40.0 + 15.0, -25.0);
	glVertex3f(-20.0, 40.0 + 15.0, -25.0);
	glEnd();
	//atap2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.6, 0.0);
	glVertex3f(-5.0, 40.0 + 15.0, -25.0);
	glVertex3f(20.0, 40.0 + 15.0, -25.0);
	glVertex3f(20.0, 25.0 + 15.0, -50.0);
	glVertex3f(-5.0, 25.0 + 15.0, -50.0);
	glEnd();
	//atap 3
	glBegin(GL_QUADS);
	glColor3f(0.9, 1.0, 1.0);
	glVertex3f(-20.0, 42.0, -25.0);
	glVertex3f(0.0, 42.0, -25.0);
	glVertex3f(0.0, 40.0, -50.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glEnd();
	//tembok atas kiri belakang
	glBegin(GL_TRIANGLES);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-20.0, 40.0, -25.0);
	glVertex3f(-20.0, 42.0, -25.0);
	glVertex3f(-20.0, 40.0, -50.0);
	glEnd();
	//atap4
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(0.0, 55.0, -25.0);
	glVertex3f(0.0, 40.0, -25.0);
	glVertex3f(-20.0, 40.0, -25.0);
	glVertex3f(-20.0, 55.0, -25.0);
	glEnd();
	//tembok atas kanan
	glBegin(GL_TRIANGLES);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(20.0, 55.0, -25.0);
	glVertex3f(20.0, 40.0, 11.0);
	glVertex3f(20.0, 40.0, -50.0);
	glEnd();
	//tembok atas kiri
	glBegin(GL_TRIANGLES);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-20.0, 40.0, 11.0);
	glVertex3f(-20.0, 40.0, -25.0);
	glVertex3f(-20.0, 55.0, -25.0);
	glEnd();
	//tembok atas tengah
	glBegin(GL_TRIANGLES);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(0.0, 40.0, -25.0);
	glVertex3f(0.0, 55.0, -25.0);
	glVertex3f(0.0, 40.0, -50.0);
	glEnd();
	//talang air1 
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-22.0, 10.0, 15.0);
	glVertex3f(20.0, 10.0, 15.0);
	glVertex3f(20.0, 10.0, 10.0);
	glVertex3f(-22.0, 10.0, 10.0);
	//
	glVertex3f(-22.0, 11.0, 15.0);
	glVertex3f(20.0, 11.0, 15.0);
	glVertex3f(20.0, 11.0, 10.0);
	glVertex3f(-22.0, 11.0, 10.0);
	//
	glVertex3f(-22.0, 10.0, 15.0);
	glVertex3f(-22.0, 11.0, 15.0);
	glVertex3f(20.0, 11.0, 15.0);
	glVertex3f(20.0, 10.0, 15.0);
	//
	glVertex3f(20.0, 11.0, 10.0);
	glVertex3f(20.0, 10.0, 10.0);
	glVertex3f(20.0, 10.0, 15.0);
	glVertex3f(20.0, 11.0, 15.0);
	//
	glVertex3f(-22.0, 11.0, 15.0);
	glVertex3f(-22.0, 10.0, 15.0);
	glVertex3f(-22.0, 10.0, -25.0);
	glVertex3f(-22.0, 11.0, -25.0);
	//
	glVertex3f(-22.0, 10.0, 10.0);
	glVertex3f(-20.0, 10.0, 10.0);
	glVertex3f(-20.0, 10.0, -25.0);
	glVertex3f(-22.0, 10.0, -25.0);
	//
	glVertex3f(-22.0, 11.0, 10.0);
	glVertex3f(-20.0, 11.0, 10.0);
	glVertex3f(-20.0, 11.0, -25.0);
	glVertex3f(-22.0, 11.0, -25.0);
	//
	glVertex3f(-22.0, 11.0, -10.0);
	glVertex3f(-20.0, 10.0, -10.0);
	glVertex3f(-20.0, 10.0, -25.0);
	glVertex3f(-22.0, 11.0, -25.0);
	//
	glVertex3f(-22.0, 11.0, -25.0);
	glVertex3f(-22.0, 10.0, -25.0);
	glVertex3f(-20.0, 10.0, -25.0);
	glVertex3f(-20.0, 11.0, -25.0);
	glEnd();
	//talang air2 
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-22.0, 33.0, 15.0);
	glVertex3f(20.0, 33.0, 15.0);
	glVertex3f(20.0, 33.0, 10.0);
	glVertex3f(-22.0, 33.0, 10.0);
	//
	glVertex3f(-22.0, 32.0, 15.0);
	glVertex3f(20.0, 32.0, 15.0);
	glVertex3f(20.0, 32.0, 10.0);
	glVertex3f(-22.0, 32.0, 10.0);
	//
	glVertex3f(-22.0, 32.0, 10.0);
	glVertex3f(-20.0, 32.0, 10.0);
	glVertex3f(-20.0, 30.0, -25.0);
	glVertex3f(-22.0, 30.0, -25.0);
	//
	glVertex3f(-22.0, 33.0, 10.0);
	glVertex3f(-22.0, 33.0, 10.0);
	glVertex3f(-20.0, 31.0, -25.0);
	glVertex3f(-22.0, 31.0, -25.0);
	//
	glVertex3f(20.0, 33.0, 15.0);
	glVertex3f(20.0, 32.0, 15.0);
	glVertex3f(20.0, 32.0, 10.0);
	glVertex3f(20.0, 33.0, 10.0);
	//
	glVertex3f(-22.0, 33.0, 15.0);
	glVertex3f(-22.0, 32.0, 15.0);
	glVertex3f(20.0, 32.0, 15.0);
	glVertex3f(20.0, 33.0, 15.0);
	//
	glVertex3f(-22.0, 33.0, 15.0);
	glVertex3f(-22.0, 32.0, 15.0);
	glVertex3f(-22.0, 32.0, 10.0);
	glVertex3f(-22.0, 33.0, 10.0);
	//
	glVertex3f(-22.0, 33.0, 15.0);
	glVertex3f(-22.0, 32.0, 15.0);
	glVertex3f(-22.0, 30.0, -25.0);
	glVertex3f(-22.0, 31.0, -25.0);
	//
	glVertex3f(-22.0, 30.0, -25.0);
	glVertex3f(-22.0, 31.0, -25.0);
	glVertex3f(-20.0, 31.0, -25.0);
	glVertex3f(-20.0, 30.0, -25.0);
	glEnd();
	//detail kanan
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(21.0, 20.0, 10.0);
	glVertex3f(21.0, 15.0, 10.0);
	glVertex3f(21.0, 15.0, -50.0);
	glVertex3f(21.0, 20.0, -50.0);
	//
	glVertex3f(20.0, 15.0, 10.0);
	glVertex3f(21.0, 15.0, 10.0);
	glVertex3f(21.0, 15.0, -50.0);
	glVertex3f(20.0, 15.0, -50.0);
	//
	glVertex3f(20.0, 20.0, 10.0);
	glVertex3f(21.0, 20.0, 10.0);
	glVertex3f(21.0, 20.0, -50.0);
	glVertex3f(20.0, 20.0, -50.0);
	//
	glVertex3f(20.0, 15.0, 10.0);
	glVertex3f(20.0, 20.0, 10.0);
	glVertex3f(21.0, 20.0, 10.0);
	glVertex3f(21.0, 15.0, 10.0);
	//
	glVertex3f(20.0, 15.0, -50.0);
	glVertex3f(20.0, 20.0, -50.0);
	glVertex3f(21.0, 20.0, -50.0);
	glVertex3f(21.0, 15.0, -50.0);
	glEnd();
	//talang air3
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-20.0, 35.0, 12.5);
	glVertex3f(20.0, 35.0, 12.5);
	glVertex3f(20.0, 35.0, 10.0);
	glVertex3f(-20.0, 35.0, 10.0);
	//
	glVertex3f(-20.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 10.0);
	glVertex3f(-20.0, 38.0, 10.0);
	//
	glVertex3f(-20.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 10.0);
	glVertex3f(-20.0, 38.0, 10.0);
	//
	glVertex3f(-21.0, 38.0, 12.5);
	glVertex3f(-20.0, 38.0, 12.5);
	glVertex3f(-20.0, 38.0, 8.0);
	glVertex3f(-21.0, 38.0, 8.0);
	//
	glVertex3f(-21.0, 35.0, 12.5);
	glVertex3f(-20.0, 35.0, 12.5);
	glVertex3f(-20.0, 35.0, 8.0);
	glVertex3f(-21.0, 35.0, 8.0);
	//
	glVertex3f(21.0, 35.0, 12.5);
	glVertex3f(20.0, 35.0, 12.5);
	glVertex3f(20.0, 35.0, 8.0);
	glVertex3f(21.0, 35.0, 8.0);
	//
	glVertex3f(21.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 12.5);
	glVertex3f(20.0, 38.0, 8.0);
	glVertex3f(21.0, 38.0, 8.0);
	//
	glVertex3f(21.0, 38.0, 12.5);
	glVertex3f(21.0, 35.0, 12.5);
	glVertex3f(21.0, 35.0, 8.0);
	glVertex3f(21.0, 38.0, 8.0);
	//
	glVertex3f(-21.0, 38.0, 12.5);
	glVertex3f(-21.0, 35.0, 12.5);
	glVertex3f(-21.0, 35.0, 8.0);
	glVertex3f(-21.0, 38.0, 8.0);
	//
	glVertex3f(-21.0, 38.0, 12.5);
	glVertex3f(-21.0, 35.0, 12.5);
	glVertex3f(21.0, 35.0, 12.5);
	glVertex3f(21.0, 38.0, 12.5);
	glEnd();
	//lemari 
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.5, 0.0);
	glVertex3f(3.0, -10.0, -48.5);
	glVertex3f(3.0, 8.0, -48.5);
	glVertex3f(10.0, 8.0, -48.5);
	glVertex3f(10.0, -10.0, -48.5);
	//
	glVertex3f(3.0, -10.0, -45.0);
	glVertex3f(3.0, 8.0, -45.0);
	glVertex3f(10.0, 8.0, -45.0);
	glVertex3f(10.0, -10.0, -45.0);
	//
	glVertex3f(3.0, 8.0, -45.0);
	glVertex3f(10.0, 8.0, -45.0);
	glVertex3f(10.0, 8.0, -48.5);
	glVertex3f(3.0, 8.0, -48.5);
	//
	glVertex3f(3.0, 8.0, -45.0);
	glVertex3f(3.0, -10.0, -45.0);
	glVertex3f(3.0, -10.0, -48.5);
	glVertex3f(3.0, 8.0, -48.5);
	//
	glVertex3f(10.0, 8.0, -45.0);
	glVertex3f(10.0, -10.0, -45.0);
	glVertex3f(10.0, -10.0, -48.5);
	glVertex3f(10.0, 8.0, -48.5);
	glEnd();
	//meja
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(5.0, -2.0, -15.0);
	glVertex3f(17.0, -2.0, -15.0);
	glVertex3f(17.0, -2.0, -30.0);
	glVertex3f(5.0, -2.0, -30.0);
	//
	glVertex3f(5.0, -3.0, -15.0);
	glVertex3f(17.0, -3.0, -15.0);
	glVertex3f(17.0, -3.0, -30.0);
	glVertex3f(5.0, -3.0, -30.0);
	//
	glVertex3f(17.0, -2.0, -15.0);
	glVertex3f(17.0, -3.0, -15.0);
	glVertex3f(17.0, -3.0, -30.0);
	glVertex3f(17.0, -2.0, -30.0);
	//
	glVertex3f(5.0, -2.0, -15.0);
	glVertex3f(5.0, -3.0, -15.0);
	glVertex3f(5.0, -3.0, -30.0);
	glVertex3f(5.0, -2.0, -30.0);
	//
	glVertex3f(5.0, -2.0, -15);
	glVertex3f(5.0, -3.0, -15);
	glVertex3f(17.0, -3.0, -15);
	glVertex3f(17.0, -2.0, -15);
	//
	glVertex3f(5.0, -10.0, -15);
	glVertex3f(5.0, -3.0, -15);
	glVertex3f(7.0, -3.0, -15);
	glVertex3f(7.0, -10.0, -15);
	//
	glVertex3f(17.0, -10.0, -15);
	glVertex3f(17.0, -3.0, -15);
	glVertex3f(15.0, -3.0, -15);
	glVertex3f(15.0, -10.0, -15);
	//
	glVertex3f(5.0, -2.0, -30);
	glVertex3f(5.0, -3.0, -30);
	glVertex3f(17.0, -3.0, -30);
	glVertex3f(17.0, -2.0, -30);
	//
	glVertex3f(17.0, -10.0, -30);
	glVertex3f(17.0, -3.0, -30);
	glVertex3f(15.0, -3.0, -30);
	glVertex3f(15.0, -10.0, -30);
	//
	glVertex3f(7.0, -10.0, -30);
	glVertex3f(7.0, -3.0, -30);
	glVertex3f(5.0, -3.0, -30);
	glVertex3f(5.0, -10.0, -30);
	//
	glVertex3f(17.0, -10.0, -28.0);
	glVertex3f(17.0, -3.0, -28.0);
	glVertex3f(17.0, -3.0, -30.0);
	glVertex3f(17.0, -10.0, -30.0);
	//
	glVertex3f(5.0, -10.0, -15.0);
	glVertex3f(5.0, -3.0, -15.0);
	glVertex3f(5.0, -3.0, -17.0);
	glVertex3f(5.0, -10.0, -17.0);
	//
	glVertex3f(17.0, -10.0, -15.0);
	glVertex3f(17.0, -3.0, -15.0);
	glVertex3f(17.0, -3.0, -17.0);
	glVertex3f(17.0, -10.0, -17.0);
	//
	glVertex3f(5.0, -10.0, -28.0);
	glVertex3f(5.0, -3.0, -28.0);
	glVertex3f(5.0, -3.0, -30.0);
	glVertex3f(5.0, -10.0, -30.0);
	glEnd();
	//kursi
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(-10.0, -10.0, -26.5);
	glVertex3f(-10.0, 4.0, -26.5);
	glVertex3f(-9.0, 4.0, -26.5);
	glVertex3f(-9.0, -10.0, -26.5);
	//
	glVertex3f(-10.0, -10.0, -20.5);
	glVertex3f(-10.0, 4.0, -20.5);
	glVertex3f(-9.0, 4.0, -20.5);
	glVertex3f(-9.0, -10.0, -20.5);
	//
	glVertex3f(-10.0, 4.0, -20.5);
	glVertex3f(-9.0, 4.0, -20.5);
	glVertex3f(-9.0, 4.0, -26.5);
	glVertex3f(-10.0, 4.0, -26.5);
	//
	glVertex3f(-10.0, 4.0, -20.5);
	glVertex3f(-10.0, -1.0, -20.5);
	glVertex3f(-10.0, -1.0, -26.5);
	glVertex3f(-10.0, 4.0, -26.5);
	//
	glVertex3f(-9.0, 4.0, -20.5);
	glVertex3f(-9.0, -1.0, -20.5);
	glVertex3f(-9.0, -1.0, -26.5);
	glVertex3f(-9.0, 4.0, -26.5);
	//
	glVertex3f(-10.0, -5.0, -20.5);
	glVertex3f(-4.0, -5.0, -20.5);
	glVertex3f(-4.0, -5.0, -26.5);
	glVertex3f(-10.0, -5.0, -26.5);
	//
	glVertex3f(-10.0, -4.0, -20.5);
	glVertex3f(-4.0, -4.0, -20.5);
	glVertex3f(-4.0, -4.0, -26.5);
	glVertex3f(-10.0, -4.0, -26.5);
	//
	glVertex3f(-10.0, -5.0, -20.5);
	glVertex3f(-9.0, -4.0, -20.5);
	glVertex3f(-9.0, -4.0, -26.5);
	glVertex3f(-10.0, -4.0, -26.5);
	//
	glVertex3f(-10.0, -4.0, -20.5);
	glVertex3f(-10.0, -5.0, -20.5);
	glVertex3f(-10.0, -5.0, -26.5);
	glVertex3f(-10.0, -4.0, -26.5);
	//
	glVertex3f(-4.0, -4.0, -20.5);
	glVertex3f(-4.0, -5.0, -20.5);
	glVertex3f(-4.0, -5.0, -26.5);
	glVertex3f(-4.0, -4.0, -26.5);
	//
	glVertex3f(-10.0, -4.0, -26.5);
	glVertex3f(-10.0, -5.0, -26.5);
	glVertex3f(-4.0, -5.0, -26.5);
	glVertex3f(-4.0, -4.0, -26.5);
	//
	glVertex3f(-9.0, -4.0, -20.5);
	glVertex3f(-9.0, -5.0, -20.5);
	glVertex3f(-4.0, -5.0, -20.5);
	glVertex3f(-4.0, -4.0, -20.5);
	//
	glVertex3f(-5.0, -10.0, -20.5);
	glVertex3f(-5.0, -5.0, -20.5);
	glVertex3f(-4.0, -5.0, -20.5);
	glVertex3f(-4.0, -10.0, -20.5);
	//
	glVertex3f(-5.0, -10.0, -26.5);
	glVertex3f(-5.0, -5.0, -26.5);
	glVertex3f(-4.0, -5.0, -26.5);
	glVertex3f(-4.0, -10.0, -26.5);
	//
	glVertex3f(-5.0, -10.0, -25.5);
	glVertex3f(-5.0, -5.0, -25.5);
	glVertex3f(-4.0, -5.0, -26.5);
	glVertex3f(-4.0, -10.0, -26.5);
	//
	glVertex3f(-5.0, -10.0, -21.5);
	glVertex3f(-5.0, -5.0, -21.5);
	glVertex3f(-4.0, -5.0, -20.5);
	glVertex3f(-4.0, -10.0, -20.5);
	//
	glVertex3f(-10.0, -5.0, -21.5);
	glVertex3f(-10.0, -10.0, -21.5);
	glVertex3f(-10.0, -10.0, -20.5);
	glVertex3f(-10.0, -5.0, -20.5);
	//
	glVertex3f(-10.0, -5.0, -25.5);
	glVertex3f(-10.0, -10.0, -25.5);
	glVertex3f(-10.0, -10.0, -26.5);
	glVertex3f(-10.0, -5.0, -26.5);
	glEnd();
	//teras rumah
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.8, 0.0);
	glVertex3f(-60.0, -10.0, 20.0);
	glVertex3f(60.0, -10.0, 20.0);
	glVertex3f(60.0, -10.0, 10.0);
	glVertex3f(-60.0, -10.0, 10.0);
	glEnd();
	//tiang 
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.0);
	glVertex3f(-20.0, -10.0, 15.0);
	glVertex3f(-20.0, 5.0, 15.0);
	glVertex3f(-19.0, 5.0, 15.0);
	glVertex3f(-19.0, -10.0, 15.0);
	//
	glVertex3f(-20.0, -10.0, 16.0);
	glVertex3f(-20.0, 5.0, 16.0);
	glVertex3f(-19.0, 5.0, 16.0);
	glVertex3f(-19.0, -10.0, 16.0);
	//
	glVertex3f(-20.0, 5.0, 16.0);
	glVertex3f(-20.0, -10.0, 16.0);
	glVertex3f(-20.0, -10.0, 15.0);
	glVertex3f(-20.0, 5.0, 15.0);
	//
	glVertex3f(-19.0, 5.0, 16.0);
	glVertex3f(-19.0, -10.0, 16.0);
	glVertex3f(-19.0, -10.0, 15.0);
	glVertex3f(-19.0, 5.0, 15.0);
	glEnd();
	//bendera
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, 5.0, 16.0);
	glVertex3f(-20.0, 2.5, 16.0);
	glVertex3f(-20.0, 2.5, 20.0);
	glVertex3f(-20.0, 5.0, 20.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 0.0, 16.0);
	glVertex3f(-20.0, 2.5, 16.0);
	glVertex3f(-20.0, 2.5, 20.0);
	glVertex3f(-20.0, 0.0, 20.0);
	glEnd();
	//jalan aspal
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-60.0, -10.0, 50.0);
	glVertex3f(60.0, -10.0, 50.0);
	glVertex3f(60.0, -10.0, 20.0);
	glVertex3f(-60.0, -10.0, 20.0);
	glEnd();
	//lahan sebelah
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.0);
	glVertex3f(-60.0, -10.0, 50.0);
	glVertex3f(60.0, -10.0, 50.0);
	glVertex3f(60.0, -10.0, 60.0);
	glVertex3f(-60.0, -10.0, 60.0);
	glEnd();
	//rumput
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.9, 0.0);
	glVertex3f(-20.0, 5.0, 55.0);
	glVertex3f(-20.0, -10.5, 55.0);
	glVertex3f(-20.0, 2.5, 58.0);
	glVertex3f(-20.0, -10.0, 58.0);
	glEnd();
	//tiang lampu1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(40.0, -10.0, 57.0);
	glVertex3f(40.0, 20.0, 57.0);
	glVertex3f(40.0, 20.0, 56.0);
	glVertex3f(40.0, -10.0, 56.0);
	//
	glVertex3f(39.0, -10.0, 57.0);
	glVertex3f(39.0, 20.0, 57.0);
	glVertex3f(39.0, 20.0, 56.0);
	glVertex3f(39.0, -10.0, 56.0);
	//
	glVertex3f(40.0, -10.0, 57.0);
	glVertex3f(40.0, 20.0, 57.0);
	glVertex3f(39.0, 20.0, 57.0);
	glVertex3f(39.0, -10.0, 57.0);
	//
	glVertex3f(40.0, -10.0, 56.0);
	glVertex3f(40.0, 20.0, 56.0);
	glVertex3f(39.0, 20.0, 56.0);
	glVertex3f(39.0, -10.0, 56.0);
	//
	glVertex3f(40.0, 18.0, 57.0);
	glVertex3f(40.0, 20.0, 57.0);
	glVertex3f(40.0, 20.0, 45.0);
	glVertex3f(40.0, 18.0, 45.0);
	//
	glVertex3f(39.0, 18.0, 57.0);
	glVertex3f(39.0, 20.0, 57.0);
	glVertex3f(39.0, 20.0, 45.0);
	glVertex3f(39.0, 18.0, 45.0);
	//
	glVertex3f(40.0, 20.0, 57.0);
	glVertex3f(39.0, 20.0, 57.0);
	glVertex3f(39.0, 20.0, 45.0);
	glVertex3f(40.0, 20.0, 45.0);
	glEnd();
	//tiang lampu2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-30.0, -10.0, 57.0);
	glVertex3f(-30.0, 20.0, 57.0);
	glVertex3f(-30.0, 20.0, 56.0);
	glVertex3f(-30.0, -10.0, 56.0);
	//
	glVertex3f(-31.0, -10.0, 57.0);
	glVertex3f(-31.0, 20.0, 57.0);
	glVertex3f(-31.0, 20.0, 56.0);
	glVertex3f(-31.0, -10.0, 56.0);
	//
	glVertex3f(-31.0, -10.0, 57.0);
	glVertex3f(-31.0, 20.0, 57.0);
	glVertex3f(-30.0, 20.0, 57.0);
	glVertex3f(-30.0, -10.0, 57.0);
	//
	glVertex3f(-31.0, -10.0, 56.0);
	glVertex3f(-31.0, 20.0, 56.0);
	glVertex3f(-30.0, 20.0, 56.0);
	glVertex3f(-30.0, -10.0, 56.0);
	//
	glVertex3f(-31.0, 18.0, 57.0);
	glVertex3f(-31.0, 20.0, 57.0);
	glVertex3f(-31.0, 20.0, 45.0);
	glVertex3f(-31.0, 18.0, 45.0);
	//
	glVertex3f(-30.0, 18.0, 57.0);
	glVertex3f(-30.0, 20.0, 57.0);
	glVertex3f(-30.0, 20.0, 45.0);
	glVertex3f(-30.0, 18.0, 45.0);
	//
	glVertex3f(-31.0, 20.0, 57.0);
	glVertex3f(-30.0, 20.0, 57.0);
	glVertex3f(-30.0, 20.0, 45.0);
	glVertex3f(-31.0, 20.0, 45.0);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth) {
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else {
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void idle() {
	if (!mouseDown) {
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y) {
	if (mouseDown) {
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi) {
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Danang Maulana Ikhsan_672019098");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}