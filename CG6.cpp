#include<iostream>
#include<stdlib.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<GL/glut.h>
#endif
using namespace std;

float sunX = -0.8f;  //initial position of sun(x,y,z)
float sunY = -0.3f;
float sunZ = -1.2f;
float colR=3.0;		  //initial RGB color
float colG=1.5;
float colB=1.0;
float bgColR=0.0;    //initial background color
float bgColG=0.0;
float bgColB=0.0;

static int flag=1;

void drawsun(void){
        glColor3f(colR,colG,colB); //set sun colour
        glTranslatef(sunX,sunY,sunZ); //moving it toward the screen a bit on creation
        glutSolidSphere(0.05, 30, 30); //create sun.
}
void drawAv(void) {
        glBegin(GL_POLYGON);   //draw mountains begin
        glColor3f(0.5,0.35,0.05);      //co-ordinates of the mountain
        glVertex3f(-0.9,-0.7,-1.0);
        glVertex3f(-0.5,-0.1,-1.0);
        glVertex3f(-0.2,-1.0,-1.0);
        glVertex3f(0.5,0.0,-1.0);
        glVertex3f(0.6,-0.2,-1.0);
        glVertex3f(0.9,-0.7,-1.0);
    glEnd();
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  //clears display window
    glClearColor(bgColR,bgColG,bgColB,0.0);    //clear display-window color
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawing the SUN
    glPushMatrix(); //copies the top matrix and pushes it onto the stack
        drawsun();
    glPopMatrix(); //pops the top matrix off the stack
    //drawing the Mount Everest
    glPushMatrix();
        drawAv();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void update(int value) {
   
    if(sunX>0.9f)  //middle
    {
        sunX = -0.8f;
        sunY = -0.3f;
        flag=1;
        colR=2.0;
        colG=1.50;
        colB=1.0;
        bgColB=0.0;
    }
    if(flag)    //sunset
    {
    sunX += 0.001f;
    sunY +=0.0007f;
    colR-=0.001;
    //colG+=0.002;
    colB+=0.005;
    bgColB+=0.001;
       if(sunX>0.01)
       {
           flag=0;
       }
    }
    if (!flag)   //night
    {
        sunX += 0.001f;
        sunY -=0.0007f;
        colR+=0.001;
        colB-=0.01;
        bgColB-=0.001;
        if(sunX<-0.3)
       {
           flag=1;
       }
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Sun");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return(0);
}


