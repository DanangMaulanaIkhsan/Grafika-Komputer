#include <GL/glut.h>

void layar() {
    glClearColor(0.0, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //gunung1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(250.0, 350.0, 0.0);
    glVertex3f(0.0, 250.0, 0.0);
    glVertex3f(450.0, 250.0, 0.0);
    glEnd();
    //gunung1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(350.0, 350.0, 0.0);
    glVertex3f(100.0, 250.0, 0.0);
    glVertex3f(500.0, 250.0, 0.0);
    glEnd();
    //tanah
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 0.0);
    glVertex3f(500.0, 250.0, 0.0);
    glVertex3f(0.0, 250.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(500.0, 0.0, 0.0);
    glEnd();
    //jalan raya
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(470.0, 250.0, 0.0);
    glVertex3f(480.0, 250.0, 0.0);
    glVertex3f(280.0, 0.0, 0.0);
    glVertex3f(180.0, 0.0, 0.0);
    glEnd();
    //atap
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.6, 0.0);
    glVertex3f(125.0, 240.0, 0.0);
    glVertex3f(180.0, 240.0, 0.0);
    glVertex3f(250.0, 175.0, 0.0);
    glVertex3f(50.0, 175.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.5, 0.0);
    glVertex3f(125.0, 240.0, 0.0);
    glVertex3f(50.0, 175.0, 0.0);
    glVertex3f(200.0, 175.0, 0.0);
    glEnd();
    // tembok
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.2, 0.4);
    glVertex3f(75.0, 175.0, 0.0);
    glVertex3f(175.0, 175.0, 0.0);
    glVertex3f(175.0, 75.0, 0.0);
    glVertex3f(75.0, 75.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.5);
    glVertex3f(175.0, 175.0, 0.0);
    glVertex3f(240.0, 175.0, 0.0);
    glVertex3f(240.0, 90.0, 0.0);
    glVertex3f(175.0, 75.0, 0.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.2, 0.9);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(120.0, 120.0, 0.0);
    glVertex3f(120.0, 75.0, 0.0);
    glVertex3f(90.0, 75.0, 0.0);
    glEnd();
    //gagang pintu
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.3, 0.7, 0.9);
    glVertex2i(100, 95);
    glEnd();
    //jendela
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 1.0);
    glVertex3f(160.0, 130.0, 0.0);
    glVertex3f(130.0, 130.0, 0.0);
    glVertex3f(130.0, 85.0, 0.0);
    glVertex3f(160.0, 85.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 1.0);
    glVertex3f(210.0, 130.0, 0.0);
    glVertex3f(180.0, 130.0, 0.0);
    glVertex3f(180.0, 90.0, 0.0);
    glVertex3f(210.0, 95.0, 0.0);
    glEnd();
    //batang
    glColor3f(0.7, 0.7, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(350.0, 150.0, 0.0);
    glVertex3f(370.0, 150.0, 0.0);
    glVertex3f(370.0, 60.0, 0.0);
    glVertex3f(350.0, 60.0, 0.0);
    glEnd();
    //daun
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(360.0, 250.0, 0.0);
    glVertex3f(310.0, 150.0, 0.0);
    glVertex3f(410.0, 150.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(360.0, 250.0, 0.0);
    glVertex3f(310.0, 130.0, 0.0);
    glVertex3f(410.0, 130.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(360.0, 250.0, 0.0);
    glVertex3f(310.0, 110.0, 0.0);
    glVertex3f(410.0, 110.0, 0.0);
    glEnd();
    //jalan rumah
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(150.0, 75.0, 0.0);
    glVertex3f(80.0, 75.0, 0.0);
    glVertex3f(215.0, 30.0, 0.0);
    glVertex3f(240.0, 50.0, 0.0);
    glEnd();
    glFlush();

}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("Tugas2_672019098");
    layar();
    glutDisplayFunc(display);
    glutMainLoop();
}

