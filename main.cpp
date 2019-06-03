#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

GLint state =GLUT_DOWN;
GLint xr=0,yr=0,x1=0;
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();

    //glFlush();
}



void init(void) {
    glClearColor(255,255,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,300.0,0.0,300.0);

}


void timer(int notUsed) // Timer is for animation. This function provides us to redisplay all objects by every 100 miliseconds
 {
     glutPostRedisplay();
     glutTimerFunc(100, timer, 0);
 }

void item(){
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glBegin(GL_POLYGON);


    // glTranslatef(xr,yr,0);
    glVertex2f(40.0+x1,50.0);
    glVertex2f(60.0+x1,50.0);
    glVertex2f(60.0+x1,70.0);
    glVertex2f(40.0+x1,70.0);

    glEnd();
    glPopMatrix();
        if(x1==50){
            x1=50;
            //glTranslatef(x1,yr,0);

        }
    //glutSwapBuffers();
    //glFlush();

}
void item1(){
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glBegin(GL_POLYGON);


    // glTranslatef(xr,yr,0);
    glVertex2f(40.0+x1,50.0);
    glVertex2f(60.0+x1,50.0);
    glVertex2f(60.0+x1,70.0);
    glVertex2f(40.0+x1,70.0);

    glEnd();
    glPopMatrix();
        if(x1==50){
            x1=50;
            //glTranslatef(x1,yr,0);

        }
    glutSwapBuffers();
    //glFlush();

}

void man(){

    //for(i=0;i<100;i++){
    glPointSize(3.0f);

    /*glPushMatrix();
    glBegin(GL_LINES);              //road
    glVertex2f(0.0,50.0);
    glVertex2f(500.0,50.0);
    glEnd();
    glPopMatrix();*/

    glPushMatrix();                 //body
    glBegin(GL_LINES);
    glVertex2f(30.0+xr,60.0);
    glVertex2f(30.0+xr,90.0);
    glTranslatef(xr,yr,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);              //left hand
    glVertex2f(20.0+xr,70.0);
    glVertex2f(30.0+xr,90.0);
    glTranslatef(xr,yr,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);              //right hand
    glVertex2f(40.0+xr,70.0);
    glVertex2f(30.0+xr,90.0);
    glTranslatef(xr,yr,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);              //left leg
    glVertex2f(20.0+xr,40.0);
    glVertex2f(30.0+xr,60.0);
    glTranslatef(xr,yr,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);              //right leg
    glVertex2f(40.0+xr,40.0);
    glVertex2f(30.0+xr,60.0);
    glTranslatef(xr,yr,0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    DrawCircle(30.0+xr, 98.0, 8.0, 10);
    glTranslatef(xr,yr,0);             //head
    glPopMatrix();

    if(xr==50){
        xr=xr-5;
    }


}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,.0,0.0);
    man();
   // glColor3f(1.0,0.0,0.0);
   item();
   //item1();

//    object();
    glFlush();


    glutSwapBuffers();
  //  glutPostRedisplay();
}


GLint draw_triangle(GLint x,GLint y){

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glBegin(GL_POLYGON);


    //glTranslatef(xr,yr,0);
    glVertex2f(40.0,50.0);
    glVertex2f(60.0,50.0);
    glVertex2f(50.0,70.0);


    glEnd();
    glPopMatrix();

    glFlush();
    glutPostRedisplay();



}


 void mouse(int button, int state, int x, int y){





     if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        //glutPostRedisplay();
      // glColor3f(1.0,0.0,0.0);
        item1();
        //glutSwapBuffers();
        //glutPostRedisplay();

     }
     else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glClearColor(1.0,0.0,1.0,0.0);
       glutPostRedisplay();
     }



 }
 void keyboard(unsigned char key,int x,int y){

     if(key == 27){
        //glColor3f(1.0,0.0,0.0);
        item1();
         //glutSwapBuffers();

        //glutPostRedisplay();
        //exit(0);
     }
     if(key == 77|| key == 109){
        xr=xr+10;
        if(x1==50){
            x1=50;
        }
        x1=x1+10;

     }
     if(key == 66 || key==98){
        xr=xr-5;
     }

 }



int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);

    glutCreateWindow("ANIMATING STICKMAN");
    init();
    glutDisplayFunc(display);


   glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
     timer(100);
    glutMainLoop();
}
