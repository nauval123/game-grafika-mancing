#include <windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "math.h"
#include <map>
#include <iostream>

int nilai,x,y,b,c,p,px1,px2=0;
int nyawa = 20;
int winsize[] = {1366,768};
int pasir[]={0,171,0,10};
int ortho[] = {0,171,0,96};
int koorobjek[]={56.74,74.20,70.59,79.34,0,0,};
int koorikan[]={2.85,42.42,21,30.30,0,0};
int posXikan1;
int posXikan2;
int posYikan1;
int posYikan2;
int posXkapal;
int posXkapal2;
int posYkapal;
int posYkapal2;
int posXikan3;
int posXikan4;
int posYikan3;
int posYikan4;
void *font = GLUT_BITMAP_HELVETICA_18;


///Helvetica
void tulis(int l, int m, char *string) {
    glRasterPos2f(l, m);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
        }
    }


void timer(int a){
    if(posXikan2>=posXkapal && posXikan2<=posXkapal2&& posYikan1==posYkapal && posYikan2==posYkapal2){
       b=-170;
       nilai+=1;
    }
    if(posXikan4>=posXkapal && posXikan4<=posXkapal2&& posYikan3==posYkapal && posYikan4==posYkapal2){
       c=-1200;
        nilai+=10;
    }
    b++;
    c+=100;
    glutPostRedisplay();
    glutTimerFunc(100, timer, 1);
}

//kolision kail




void kapal(){
glPushMatrix();
glTranslated(50,60,0);
//badan kapal

glBegin(GL_POLYGON);
glColor3b(117, 81, 36);
glVertex2f(6.74, 13.64);glVertex2f(7.15,13.64);
glVertex2f(7.14, 13.2361);glVertex2f(6.74, 13.23);
glEnd();

glBegin(GL_POLYGON);
glColor3b(117, 81, 36);
glVertex2f(7.15,13.64);glVertex2f(7.61,13.65);
glVertex2f(7.60, 11.91);glVertex2f(7.14, 11.91);
glEnd();

glBegin(GL_POLYGON);
glColor3b(117,81,36);
glVertex2f(7.61,13.65);glVertex2f(8.03,13.65);
glVertex2f(8.02,11.44);glVertex2f(7.61,11.45);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(117,81,36);
glVertex2f(8.03,13.65);glVertex2f(22.12,13.63);
glVertex2f(22.08,10.59);glVertex2f(8.02,10.59);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(117,81,36);
glVertex2f(24.20,16.28);glVertex2f(18.57, 13.65);
glVertex2f(22.08,10.59);
glEnd();

//kepala kapal
glBegin(GL_POLYGON);
glColor3ub(204, 139, 18);
glVertex2f(10.21, 16.29);glVertex2f(17.21,16.3);
glVertex2f(17.23, 13.64);glVertex2f(10.22, 13.62);
glEnd();
//jendela
glBegin(GL_POLYGON);
glColor3ub(222, 213, 209);
glVertex2f(10.22,15.39);glVertex2f(13.97,15.4);
glVertex2f(13.97,13.64);glVertex2f(10.22,13.62);
glEnd();

//atap
glBegin(GL_POLYGON);
glColor3ub(235, 96, 21);
glVertex2f(8.04024, 16.7297);glVertex2f(18.56248, 16.71422);
glVertex2f(18.57666, 16.30438);glVertex2f(8.03161, 16.28935);
glEnd();

//pipa

glBegin(GL_POLYGON);
glColor3ub(191,182,182);
glVertex2f(11.08, 19.34);glVertex2f(11.96, 19.34);
glVertex2f(11.96, 18.92);glVertex2f(11.08, 18.92);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(191,182,182);
glVertex2f(11.55,18.92);glVertex2f(11.96,18.92);
glVertex2f(11.96,16.71);glVertex2f(11.54,16.70);
glEnd();
glPopMatrix();
glutSwapBuffers();
}

void gerakkapal(){
    posXkapal  = koorobjek[0]+x;
    posXkapal2 = koorobjek[1]+x;
    posYkapal  = koorobjek[2]+p;
    posYkapal2 = koorobjek[3]+p;
    glPushMatrix();
    glPushMatrix();//{11.51,41.26,15,41.82};
    glBegin(GL_POLYGON);
    glColor3ub(28,28,28);
    glVertex2f(posXkapal,posYkapal);
    glVertex2f(posXkapal2,posYkapal);
    glVertex2f(posXkapal,posYkapal2);
    glVertex2f(posXkapal2,posYkapal2);
    glEnd();
    glPopMatrix();
    glTranslated(0+x,0+p,0);
    kapal();
    glPopMatrix();
    glutSwapBuffers();

}


void ikan(){
glPushMatrix();
glBegin(GL_POLYGON);//{-11,11,-18,19}
posYikan1= koorikan[2];
posYikan2= koorikan[3];
glColor3ub(28,28,28);
posXikan1 = koorikan[0]+b;
posXikan2 = koorikan[1]+b;
glVertex2f(posXikan1,koorikan[2]);
glVertex2f(posXikan2,koorikan[2]);
glVertex2f(posXikan2,koorikan[3]);
glVertex2f(posXikan1,koorikan[3]);
glEnd();
glPopMatrix();



glPushMatrix();
glTranslated(0+b,0,0);
//kepala
glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(22.46, 30.30);
glVertex2f(42.41, 30.25);
glVertex2f(42.42, 25.02);
glVertex2f(22.43, 25.05);
glEnd();
//mata
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(35.70, 27.74);
glVertex2f(37.31, 27.74);
glVertex2f(37.30, 26.20);
glVertex2f(35.67, 26.21);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(252, 252, 252);
glVertex2f(35.70, 27.74);
glVertex2f(36.29,27.74);
glVertex2f(36.27, 27.10);
glVertex2f(35.7,27.11);
glEnd();
//badan
glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(15.38, 27.00);
glVertex2f(33.42, 26.95);
glVertex2f(34.68, 21.84);
glVertex2f(22.342, 21.79);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(22.342, 21.79);
glVertex2f(29.02, 21.83);
glVertex2f(29.03, 21.07);
glVertex2f(22.34, 21.79);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(22.46,29.75);
glVertex2f(22.45,26.99);
glVertex2f(16, 27);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(5.80, 31.37);
glVertex2f(13.86, 29.54);
glVertex2f(14.44, 28.90);
glVertex2f(13.46, 27.90);
glVertex2f(3.84, 27.86);
glVertex2f(2.85, 28.54);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(15.38, 27.00);
glVertex2f(22.45,26.99);
glVertex2f(22.34, 21.79);
glVertex2f(15.15, 21.72);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(3.70, 27.88);
glVertex2f(13.46, 27.91);
glVertex2f(15.38, 27.00);
glVertex2f(15.15, 21.72);
glVertex2f(3.70, 27.88);

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(3.70, 27.88);
glVertex2f(7.03,26.09);
glVertex2f(4, 26);
glVertex2f(3.26, 26.94);

glBegin(GL_POLYGON);
glColor3ub(18, 227, 136);
glVertex2f(5.02,26.03);
glVertex2f(7.03,26.09);
glVertex2f(9.39,24.83);
glVertex2f(3.26, 26.94);

//dada

glBegin(GL_POLYGON);
glColor3ub(252,252,252);
glVertex2f(33.96,25.04);
glVertex2f(41.74,25.03);
glVertex2f(38.41,21.84);
glVertex2f(22.342, 21.79);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(252,252,252);
glVertex2f(29.03,21.84);
glVertex2f(38.41, 21.84);
glVertex2f(37.65, 21.1);
glVertex2f(29.03,21.07);
glEnd();

//sirip

glBegin(GL_POLYGON);
glColor3ub(151,252,177);
glVertex2f(27.66,25.87);
glVertex2f(33.78,25.86);
glVertex2f(34.49,22.47);
glVertex2f(27.42,22.45);
glEnd();
glPopMatrix();

}


void langit() {
glBegin(GL_POLYGON);
glColor3ub(179,34,27);glVertex2f(0,91);
glColor3ub(179,34,27);glVertex2f(171,91);
glColor3ub(240,82,74);glVertex2f(171,71);
glColor3ub(240,82,74);glVertex2f(0,71);
glEnd();
glutSwapBuffers();
}
void laut(){
glBegin(GL_POLYGON);
glColor3ub(0,142,148);glVertex2f(0,71);
glColor3ub(0,142,148);glVertex2f(171,71);
glColor3ub(0,105,148);glVertex2f(171,10);
glColor3ub(0,105,148);glVertex2f(0,10);
glEnd();
glutSwapBuffers();
}
void dasar(){
glBegin(GL_POLYGON);
glColor3ub(194,194,128);
glVertex2f(pasir[0],pasir[3]);
glColor3ub(194,194,128);
glVertex2f(pasir[1],pasir[3]);
glColor3ub(194,162,128);
glVertex2f(pasir[1],pasir[2]);
glColor3ub(194,162,128);
glVertex2f(pasir[0],pasir[2]);
glEnd();
glPopMatrix();
glutSwapBuffers();
}
void ikan2(){
glPushMatrix();
glScaled(0.25,0.25,0);
glTranslated(0+c,50,0);

//kepala
glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(22.46813, 30.30694);glVertex2f(42.41996, 30.25725);
glVertex2f(42.42971, 25.02866);glVertex2f(22.43244, 25.05017);
glEnd();
//mata
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(35.70981, 27.74373);glVertex2f(37.31415, 27.7434);
glVertex2f(37.30552, 26.20069);glVertex2f(35.67487, 26.21447);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(252, 252, 252);
glVertex2f(35.70981, 27.74373);glVertex2f(36.29,27.74);
glVertex2f(36.27882, 27.10979);glVertex2f(35.7,27.11);
glEnd();
//badan
glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(15.38609, 27.00288);glVertex2f(33.4287, 26.9565);
glVertex2f(34.6834, 21.84077);glVertex2f(22.34287, 21.79285);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(22.34287, 21.79285);glVertex2f(29.02815, 21.8381);
glVertex2f(29.03, 21.07);glVertex2f(22.34287, 21.79285);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(22.46,29.75);glVertex2f(22.45,26.99);
glVertex2f(16, 27);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(5.80587, 31.37914);glVertex2f(13.86777, 29.54046);
glVertex2f(14.44362, 28.90954);glVertex2f(13.46147, 27.90233);
glVertex2f(3.8412, 27.86402);glVertex2f(2.85887, 28.54902);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(15.38609, 27.00288);glVertex2f(22.45,26.99);
glVertex2f(22.34287, 21.79285);glVertex2f(15.1574, 21.72833);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(3.7099, 27.88181);glVertex2f(13.46129, 27.9181);
glVertex2f(15.38609, 27.00288);glVertex2f(15.1574, 21.72833);
glVertex2f(3.7099, 27.88181);

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(3.7099, 27.88181);glVertex2f(7.03,26.09);
glVertex2f(4, 26);glVertex2f(3.26535, 26.94468);

glBegin(GL_POLYGON);
glColor3ub(247, 30, 30);
glVertex2f(5.02,26.03);glVertex2f(7.03,26.09);
glVertex2f(9.39,24.83);glVertex2f(3.26535, 26.94468);

//dada

glBegin(GL_POLYGON);
glColor3ub(252,252,252);
glVertex2f(33.96,25.04);glVertex2f(41.74,25.03);
glVertex2f(38.41,21.84);glVertex2f(22.34287, 21.79285);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(252,252,252);
glVertex2f(29.03,21.84);glVertex2f(38.41, 21.84);
glVertex2f(37.65363, 21.11284);glVertex2f(29.03,21.07);
glEnd();

//sirip

glBegin(GL_POLYGON);
glColor3ub(255, 120, 120);
glVertex2f(27.66506,25.87635);glVertex2f(33.783,25.86914);
glVertex2f(34.49798,22.47);glVertex2f(27.42886,22.45492);
glEnd();
glutPostRedisplay();
glPopMatrix();
glutSwapBuffers();
}
void skor(){
    glPushMatrix();
     glColor3f(0, 0, 0);
    tulis(10,85, "Score :");
    char score[100] = {"0"};
    sprintf(score, "%i", nilai); //konversi time ke label
    tulis(20,85, score);
    glutSwapBuffers();
}
void Nyawa(){
    glPushMatrix();
     glColor3f(0, 0, 0);
    tulis(140,85, "nyawa :");
    char heart[100] = {"3"};
    sprintf(heart, "%i",nyawa); //konversi time ke label
    tulis(148,85, heart);
    glutSwapBuffers();
}


void display() {
langit();
laut();
dasar();
gerakkapal();
ikan();
ikan2();
skor();
Nyawa();
glFlush();
}

void gerakin(unsigned char key, int Z, int zz) {
  glPushMatrix();
    if(key=='d'){
        x+=1;
    }
    if(key=='a'){
        x-=1;
            }
    if(key=='s'){
        p-=1;
                      }
    if(key=='w'){
          p+=3;

                    }
    glutPostRedisplay();
    glPopMatrix();
}

int main(int argc, char* argv[]) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(1368,728);//memberikan ukuran layar
glutInitWindowPosition(0,0);//memberikan posisi pertama layar terbuka
glutCreateWindow("TypeBait");//memberikan nama pada jendela windows
glClearColor(1,1,1,1);
glutKeyboardFunc(gerakin);
glutDisplayFunc(display);//memanggil fungsi display
gluOrtho2D(0,171,0,91);//untuk membentuk ortho
glutTimerFunc(50, timer, 1);
glutMainLoop();
return 0; }

