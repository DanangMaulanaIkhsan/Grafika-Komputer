#include<GL\glut.h>      

void init() {
    glClearColor(0.7, 0.9, 0.4, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 450, 0, 450);
}
void home() {
    glClear(GL_COLOR_BUFFER_BIT);
    //atap
    glColor3f(0.7, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(125, 250);
    glVertex2i(50, 175);
    glVertex2i(200, 175);
    glEnd();
    // tembok
    glColor3f(0.5, 0.2, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(75, 175);
    glVertex2i(175, 175);
    glVertex2i(175, 75);
    glVertex2i(75, 75);
    glEnd();
    //pintu
    glColor3f(0.7, 0.2, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(90, 120);
    glVertex2i(120, 120);
    glVertex2i(120, 75);
    glVertex2i(90, 75);
    glEnd();
    //gagang pintu
    glColor3f(0.3, 0.7, 0.9);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(100, 95);
    glEnd();
    //jendela
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(160, 130);
    glVertex2i(130, 130);
    glVertex2i(130, 85);
    glVertex2i(160, 85);
    glEnd();
    //garis jendela
    glColor3f(0.5, 0.7, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(145, 130);
    glVertex2i(145, 85);
    glVertex2i(130, 105);
    glVertex2i(160, 105);
    glEnd();
    //jalan
    glColor3f(0.2, 0.2, 0.0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(120, 75);
    glVertex2i(90, 75);
    glVertex2i(40, 0);
    glVertex2i(140, 0);
    glEnd();
    //tiang
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(250, 140);
    glVertex2i(260, 140);
    glVertex2i(260, 40);
    glVertex2i(250, 40);
    glEnd();
    //bendera
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 140);
    glVertex2i(260, 140);
    glVertex2i(260, 100);
    glVertex2i(200, 100);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 120);
    glVertex2i(260, 120);
    glVertex2i(260, 100);
    glVertex2i(200, 100);
    glEnd();
    //batang 
    glColor3f(0.5, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(350, 150);
    glVertex2i(370, 150);
    glVertex2i(370, 60);
    glVertex2i(350, 60);
    glEnd();
    //daun
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(360, 250);
    glVertex2i(310, 150);
    glVertex2i(410, 150);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(360, 250);
    glVertex2i(310, 130);
    glVertex2i(410, 130);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(360, 250);
    glVertex2i(310, 110);
    glVertex2i(410, 110);
    glEnd();
    //kursi panjang
    glColor3f(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 40);
    glVertex2i(240, 40);
    glVertex2i(240, 30);
    glVertex2i(140, 30);
    glEnd();
    //kaki kursi kiri
    glColor3f(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 40);
    glVertex2i(150, 40);
    glVertex2i(150, 20);
    glVertex2i(140, 20);
    glEnd();
    //kaki kursi kanan
    glColor3f(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(230, 40);
    glVertex2i(240, 40);
    glVertex2i(240, 20);
    glVertex2i(230, 20);
    glEnd();
    //sandaran kursi belakang
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 40);
    glVertex2i(240, 40);
    glVertex2i(240, 50);
    glVertex2i(140, 50);
    glEnd();
    //batang pohon
    glColor3f(0.6, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 90);
    glVertex2i(420, 90);
    glVertex2i(420, 40);
    glVertex2i(440, 40);
    glEnd();
    glFlush();

}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tugas1_672019098");
    init();
    glutDisplayFunc(home);
    glutMainLoop();
}
