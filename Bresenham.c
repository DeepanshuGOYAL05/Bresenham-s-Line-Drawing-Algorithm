#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "math.h"

int m_x = 0;
int m_y = 0;
int point_no = 0;
int X1, Y1, X2, Y2;
void *font = GLUT_BITMAP_TIMES_ROMAN_10;
void *fonts[] = {
      GLUT_BITMAP_9_BY_15,
      GLUT_BITMAP_TIMES_ROMAN_10,
      GLUT_BITMAP_TIMES_ROMAN_24
};
void plots(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();}
void show(int x, int y, char *string){
      int len, i;
      glRasterPos2f(x, y);
      len = (int) strlen(string);
      for (i = 0; i < len; i++)
            glutBitmapCharacter(font, string[i]);
}
void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void draw_line(int x1, int x2, int y1, int y2) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y;
    dx = x2-x1;
    dy = y2-y1;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;
    if (x2 < x1) incx = -1;
    incy = 1;
    if (y2 < y1) incy = -1;
    x = x1; y = y1;
    if (dx > dy) {
        draw_pixel(x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }

    } else {
        draw_pixel(x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++) {
            if (e >= 0) {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }}
void display(void){
    if (point_no == 0){
        X1 = m_x;
        Y1 = m_y;
        if(X1!=0&&Y1!=0){
            char xs_coord[10];
              sprintf(xs_coord,"X:%d",X1);
              char ys_coord[10];
              sprintf(ys_coord,"Y:%d",Y1);
            show(X1+10,Y1+10,xs_coord);
            show(X1+10,Y1+20,ys_coord);
     }
            point_no = 1;
        }
    else{
        X2 = m_x;
        Y2 = m_y;
        char xf_coord[10];
          sprintf(xf_coord,"X:%d",X2);
          char yf_coord[10];
          sprintf(yf_coord,"Y:%d",Y2);
        show(X2+10,Y2+10,xf_coord);
        show(X2+10,Y2+20,yf_coord);
        draw_line(X1, X2, Y1, Y2);
       point_no = 0;  }
        for(int i=-620;i<=620;i++)
     { plots(i,0);
       plots(0,i); }
char name1[100] = "Deepanshu Goyal";
    char sapid1[100] = "Sapid: 500052753";
      show(700, 710, name1);
      show(700,720, sapid1);
    glutSwapBuffers();
    }
void reshape(int w, int h){
      glViewport(0, 0, w, h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, w, h, 0);
      glMatrixMode(GL_MODELVIEW);
}
void mouse(int button, int state, int x, int y){
    if (button==GLUT_LEFT_BUTTON){
        if (state==GLUT_DOWN){
                m_x = x;
                m_y = y;
                display();
        }  }  }
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(glutGet (GLUT_SCREEN_WIDTH), glutGet (GLUT_SCREEN_HEIGHT));
    glutCreateWindow("BRASHENAM'S ALGORITHM");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
    glutMainLoop();
}
