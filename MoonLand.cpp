#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<math.h>>

# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
GLfloat s= 0.0f;
GLfloat meteorP10=0.0; GLfloat meteorP20=0.0;
GLfloat meteorS10=0.005;GLfloat meteorS20=0.003;
float objectp = 0.0f;  // Initial Y position of the object
float directionp = 1.0f; // Direction of movement (+1 for down, -1 for up)



void meteorUps(int value){

       if(meteorP10 < -1.0)
        meteorS10 = 0.5f;

        if(meteorP20 > 1.0)
        meteorS20 = 0.0f;

         meteorP10 -= meteorS10;
         meteorP20 += meteorS20;
float	glutPostRedisplay();
	glutTimerFunc(100, meteorUps, 0);

}

void updatep(int value) {
    // Update the object's Y position
    objectp += 0.005f * directionp; // Adjust the value for desired speed

    // Reverse the direction when the object reaches the top or bottom
    if (objectp >= 0.01f || objectp <= 0.0f) {
        directionp *= -1.0f;
    }

    glutPostRedisplay(); // Trigger a display update
    glutTimerFunc(16, updatep, 0); // Call the update function every 16ms (approximately 60fps)
}

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

GLfloat ya = 0.005f, xa = .001f;
GLfloat yspeed = 0.02f, xspeed = 0.01;
int yFlag = 1, xFlag = 1, AniFlag = 1;

void updates(int value)
{
    if(AniFlag == 1)
    {
        //y
        if(ya>-0.05 && yFlag == 1)
            ya = ya - yspeed;

        if(ya<=-0.05 && yFlag == 1)
            yFlag = 0;


        if(ya<0.05 && yFlag == 0)
            ya = ya + yspeed;

        if(ya>=0.05 && yFlag == 0)
            yFlag = 1;
        //x

        if(xa>-0.02 && xFlag == 1)
            xa = xa - xspeed;

        if(xa<=-0.02 && xFlag == 1)
            xFlag = 0;


        if(xa<0.02 && xFlag == 0)
            xa = xa + xspeed;

        if(xa>=0.002 && xFlag == 0)
            xFlag = 1;
    }

    glutPostRedisplay();
    glutTimerFunc(100, updates, 0);
}

GLfloat positions = 1.0f;
GLfloat speeds = 0.05f;
///for rocket
void updates1(int value)
{
    if(positions < -1.0)
        positions = 1.0f;

    positions -= speeds;

    glutPostRedisplay();
    glutTimerFunc(200, updates1, 0);
}
GLfloat positions2 = 1.0f;
GLfloat speeds2 = 0.09f;
///for stairs
void updates2(int value)
{
    if(positions2 < 1.0f)
          positions2 =0.765f;
    positions2 -= speeds2;
    glutPostRedisplay();
    glutTimerFunc(4000, updates2, 0);

}
GLfloat positions3 = 1.0f;
GLfloat speeds3 = 0.2f;
GLfloat positions4 = 1.0f;
GLfloat speeds4 = 0.2f;
GLfloat positions5 = 1.0f;
GLfloat speeds5 = 0.2f;
///for man
void updates3(int value)
{
    ///man1
    if(positions3 < 2.0)
        positions3 -= speeds;
            positions3 = 0.0f;

   ///aiun banner
   if(positions4 < 1.5)
       positions4 -= speeds;
            positions4 = 0.0f;

   ///man 2
   if(positions5 < 1.5)
       positions5 -= speeds;
            positions5 = 0.0f;

	glutPostRedisplay();
	glutTimerFunc(9000, updates3, 0);
}

void SpecialInputs(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        speeds = 0.005f;
        break;
    case GLUT_KEY_DOWN:
        speeds = 0.0f;
        break;
    case GLUT_KEY_LEFT:
        speeds2 = 0.007f;
        speeds3 = 0.007f;
        break;
    case GLUT_KEY_RIGHT:
        speeds2 = 0.0f;
        speeds3 = 0.0f;
        break;
    }
    glutPostRedisplay();
}

void drawEllipse(float centerX, float centerY, float radiusX, float radiusY, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}


void display5()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    int triangleAmount= 150; //# of lines used to draw circle
    int lineAmount = 100;
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    ///Meteor - 1
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);
    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(0.10f,4.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
    //glScalef(0.5f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A63=0.5f; GLfloat P63=0.5f; GLfloat O63 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A63, P63); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A63 + (O63 * cos(i *  twicePi/ triangleAmount)),
                        P63 + (O63 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A64=0.505f; GLfloat P64=0.5045f; GLfloat O64 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A64, P64); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A64 + (O64 * cos(i *  twicePi/ triangleAmount)),
                        P64 + (O64 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();
    glPopMatrix();

    ///Meteor - 2
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);
    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(1.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
    //glScalef(0.5f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A603=0.5f; GLfloat P603=0.5f; GLfloat O603 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A603, P603); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A603 + (O603 * cos(i *  twicePi/ triangleAmount)),
                        P603 + (O603 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A604=0.505f; GLfloat P604=0.5045f; GLfloat O604 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A604, P604); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A604 + (O604 * cos(i *  twicePi/ triangleAmount)),
                        P604 + (O604 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();
    glPopMatrix();

    ///Meteor - 3
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);

    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(2.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
    //glScalef(0.5f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A630=0.5f; GLfloat P630=0.5f; GLfloat O630 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A630, P630); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A630 + (O630 * cos(i *  twicePi/ triangleAmount)),
                        P630 + (O630 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A640=0.505f; GLfloat P640=0.5045f; GLfloat O640 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A640, P640); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A640 + (O640 * cos(i *  twicePi/ triangleAmount)),
                        P640 + (O640 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();

    glPopMatrix();

    ///Meteor - 4
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);

    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(3.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
    //glScalef(0.5f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A0630=0.5f; GLfloat P0630=0.5f; GLfloat O0630 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0630, P0630); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0630 + (O0630 * cos(i *  twicePi/ triangleAmount)),
                        P0630 + (O0630 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A0640=0.505f; GLfloat P0640=0.5045f; GLfloat O0640 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0640, P0640); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0640 + (O0640 * cos(i *  twicePi/ triangleAmount)),
                        P0640 + (O0640 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();

    glPopMatrix();

    ///start
    ///.................................Stars.........................
    glPointSize(3.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.9f,0.9f);glVertex2f(0.7f,0.6f);glVertex2f(0.5f,0.5f);glVertex2f(0.4f,0.5f);glVertex2f(0.4f,0.9f);glVertex2f(0.5f,0.7f);glVertex2f(0.6f,0.4f);glVertex2f(0.8f,0.5f);
    glPointSize(4.0);
    glVertex2f(0.6f,0.9f);glVertex2f(0.6f,0.7f);glVertex2f(0.3f,0.5f);glVertex2f(0.6f,0.4f);glVertex2f(0.4f,0.9f);glVertex2f(0.9f,0.5f);glVertex2f(0.1f,0.46f);glVertex2f(0.8f,0.6f);
    glPointSize(5.0);
    glVertex2f(0.7f,0.8f);glVertex2f(0.65f,0.4f);glVertex2f(0.2f,0.7f);glVertex2f(0.15f,0.45f);glVertex2f(0.43f,0.69f);glVertex2f(0.55f,0.75f);glVertex2f(0.05f,0.56f);glVertex2f(0.86f,0.96f);
    glPointSize(3.0);
    glColor3f(0.89f, 0.867f, 0.875f);
    glVertex2f(0.04f, 0.04f);glVertex2f(0.04f, 0.3f);glVertex2f(0.04f, 0.55f);glVertex2f(0.08f, 0.018f);glVertex2f(0.08f, 0.18f);glVertex2f(0.14f, 0.2f);glVertex2f(0.14f, 0.5f);
    glVertex2f(0.25f, 0.5f);glVertex2f(0.2f, 0.35f);glVertex2f(0.06f, 0.62f);
    glPointSize(4.0);
    glVertex2f(0.5f, 0.62f);glVertex2f(0.5f, 0.18f);glVertex2f(0.4f, 0.09f);glVertex2f(0.3f, 0.13f);glVertex2f(0.22f, 0.08f);glVertex2f(0.35f, 0.8f);glVertex2f(0.49f, 0.83f);
    glVertex2f(0.3f, 0.65f);glVertex2f(0.3f, 0.9f);glVertex2f(0.45f, 0.94f);glVertex2f(0.45f, 0.8f);
    glPointSize(5.0);
    glVertex2f(0.53f, 0.75f);glVertex2f(0.63f, 0.5f);glVertex2f(0.63f, 0.75f);glVertex2f(0.69f, 0.8f);glVertex2f(0.73f, 0.95f);glVertex2f(0.94f, 0.95f);glVertex2f(0.86f, 0.98f);
    glVertex2f(0.8f, 0.43f);glVertex2f(0.75f, 0.48f);glVertex2f(0.7f, 0.28f);glVertex2f(0.7f, 0.63f);glVertex2f(0.45f, 0.28f);glVertex2f(0.6f, 0.28f);glVertex2f(0.5f, 0.46f);glVertex2f(0.08f,0.66f);
    glPointSize(6.0);
    glVertex2f(0.2f,0.6f);glVertex2f(0.40f,0.52f);glVertex2f(0.28f,0.26f);glVertex2f(0.40f,0.7f);glVertex2f(0.56f,0.06f);glVertex2f(0.60f,0.9f);glVertex2f(0.84f,0.84f);glVertex2f(0.12f,0.4f);glVertex2f(0.32f,0.4f);
    glVertex2f(0.9f,0.83f);glVertex2f(0.8f,0.6f);glVertex2f(0.8f,0.9f);glVertex2f(0.95f,0.86f);glVertex2f(0.9f,0.66f);glVertex2f(0.97f,0.76f);glVertex2f(0.88f,0.56f);glVertex2f(0.98f,0.6f);
    glEnd();

    ///STAR 3
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.50f,3.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 4
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.40f,4.6f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();




    ///STAR 6
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.30f,6.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 7
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.10f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 8
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.1f,5.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 9
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,2.50f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 10
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 11
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.15f,3.59f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 12
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(6.2f,4.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();


    ///STAR 13
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.9f,5.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();



    ///earth
    GLfloat s0=0.0f, u0=0.9f, radi0 =.27f, j = 0.0f;
    glColor3f(0.043f, 0.678f, 0.937f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s0, u0); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s0 + (radi0 * cos(i *  twicePi / triangleAmount)),
                    u0 + (radi0 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    //glPopMatrix();
    //j+=0.2f;

    ///inside Earth
    ///Light Green
    ///1
    glPushMatrix();
    //glScalef(0.9,0.9,0);
    GLfloat s6=0.0f, u6=0.84f, radi6 =.11f, q = 0.0f;;
    glPushMatrix();
    glRotatef(q,+0.42,-0.05,0.0);

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s6, u6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s6 + (radi6 * cos(i *  twicePi / triangleAmount)),
                    u6 + (radi6 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///2
    GLfloat s7=0.1f, u7=0.85f, radi7 =.09f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s7, u7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s7 + (radi7 * cos(i *  twicePi / triangleAmount)),
                    u7 + (radi7 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///3
    GLfloat s8=0.15f, u8=1.0f, radi8 =.05f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s8, u8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s8 + (radi8 * cos(i *  twicePi / triangleAmount)),
                    u8 + (radi8 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///4
    GLfloat s9=-0.08f, u9=1.05f, radi9 =.05f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s9, u9); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s9 + (radi9 * cos(i *  twicePi / triangleAmount)),
                    u9 + (radi9 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///5
    GLfloat s700=-0.15f, u700=0.95f, radi700 =.07f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s700, u700); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s700 + (radi700 * cos(i *  twicePi / triangleAmount)),
                    u700 + (radi700 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///6
    GLfloat s6000=0.0f, u6000=1.03f, radi6000 =.09f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s6000, u6000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s6000 + (radi6000 * cos(i *  twicePi / triangleAmount)),
                    u6000 + (radi6000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///green
    ///1
    GLfloat r10=-0.07f, e10=1.06f, radi010 =.02f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r10, e10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( r10 + (radi010 * cos(i *  twicePi / triangleAmount)),
                    e10 + (radi010 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///2
    GLfloat a40=-0.09f;
    GLfloat b40=1.04f;
    GLfloat radi121 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a40, b40); // center of circle
    for(int j0 = 0; j0 <= triangleAmount; j0++)
    {
        glVertex2f( a40 + (radi121 * cos(j0 *  twicePi / triangleAmount)),
                    b40 + (radi121 * sin(j0 * twicePi / triangleAmount)));
    }
    glEnd();

    ///3
    GLfloat s10=0.14f, u10=0.98f, radi10 =.02f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s10, u10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s10 + (radi10 * cos(i *  twicePi / triangleAmount)),
                    u10 + (radi10 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///4
    GLfloat a0=0.16f;
    GLfloat b0=0.99f;
    GLfloat radi11 =.018f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a0, b0); // center of circle
    for(int j0 = 0; j0 <= triangleAmount; j0++)
    {
        glVertex2f( a0 + (radi11 * cos(j0 *  twicePi / triangleAmount)),
                    b0 + (radi11 * sin(j0 * twicePi / triangleAmount)));
    }
    glEnd();
    ///5
    GLfloat a1=0.01f;
    GLfloat b1=0.81f;
    GLfloat radi1 =.04f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a1, b1); // center of circle
    for(int j1 = 0; j1 <= triangleAmount; j1++)
    {
        glVertex2f( a1 + (radi1 * cos(j1 *  twicePi / triangleAmount)),
                    b1 + (radi1 * sin(j1 * twicePi / triangleAmount)));
    }
    glEnd();

    ///6
    GLfloat a2=0.05f;
    GLfloat b2=0.8f;
    GLfloat radi2 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a2, b2); // center of circle
    for(int j2 = 0; j2 <= triangleAmount; j2++)
    {
        glVertex2f( a2 + (radi2 * cos(j2 *  twicePi / triangleAmount)),
                    b2 + (radi2 * sin(j2 * twicePi / triangleAmount)));
    }
    glEnd();

    ///7
    GLfloat a3=0.075f;
    GLfloat b3=0.85f;
    GLfloat radi3 =.05f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a3, b3); // center of circle
    for(int j3 = 0; j3 <= triangleAmount; j3++)
    {
        glVertex2f( a3 + (radi3 * cos(j3 *  twicePi / triangleAmount)),
                    b3 + (radi3 * sin(j3 * twicePi / triangleAmount)));
    }
    glEnd();

    ///8
    GLfloat a4=0.12f;
    GLfloat b4=0.86f;
    GLfloat radi4 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a4, b4); // center of circle
    for(int j4 = 0; j4 <= triangleAmount; j4++)
    {
        glVertex2f( a4 + (radi4 * cos(j4 *  twicePi / triangleAmount)),
                    b4 + (radi4 * sin(j4 * twicePi / triangleAmount)));
    }
    glEnd();

    ///9
    GLfloat a5=0.01f;
    GLfloat b5=0.92f;
    GLfloat radi5 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a5, b5); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a5 + (radi5 * cos(j5 *  twicePi / triangleAmount)),
                    b5 + (radi5 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
     ///10
    GLfloat a60=-0.04f;
    GLfloat b60=0.90f;
    GLfloat radi60 =.04f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a60, b60); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a60 + (radi60 * cos(j5 *  twicePi / triangleAmount)),
                    b60 + (radi60 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
      ///11
    GLfloat a50=-0.05f;
    GLfloat b50=0.86f;
    GLfloat radi50 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a50, b50); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a50 + (radi50 * cos(j5 *  twicePi / triangleAmount)),
                    b50 + (radi50 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
    ///12
    GLfloat a500=-0.15f;
    GLfloat b500=0.93f;
    GLfloat radi500 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a500, b500); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a500 + (radi500 * cos(j5 *  twicePi / triangleAmount)),
                    b500 + (radi500 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
    ///13
    GLfloat s100=-0.13f, u100=0.97f, radiu100 =0.04f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s100, u100); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s100 + (radiu100 * cos(i *  twicePi / triangleAmount)),
                    u100 + (radiu100 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///14
    GLfloat s7000=-0.02f, u7000=1.0f, radiu7000 =0.04f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s7000, u7000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s7000 + (radiu7000 * cos(i *  twicePi / triangleAmount)),
                    u7000 + (radiu7000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///15
    GLfloat s8000=-0.02f, u8000=1.05f, radiu8000 =0.03f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s8000, u8000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s8000 + (radiu8000 * cos(i *  twicePi / triangleAmount)),
                    u8000 + (radiu8000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
      ///16
    GLfloat s9000=0.03f, u9000=1.04f, radiu9000 =0.05f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s9000, u9000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s9000 + (radiu9000 * cos(i *  twicePi / triangleAmount)),
                    u9000 + (radiu9000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
glPopMatrix();
glPopMatrix();
q += 0.007f;
//+=0.007f;


    ///_________ Fire main 1________///
    glPushMatrix();
    glScalef(1.2,1.2,0);
    glTranslatef(+0.25f, positions, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, objectp, 0.0f); // Translate the object vertically
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    ///_________ Fire main 2________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///moon ground

    //1
    GLfloat s1=0.1f, u1=0.2f, radiu1 =0.17f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s1, u1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s1 + (radiu1 * cos(i *  twicePi / triangleAmount)),
                    u1 + (radiu1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //2
    int i2;

    GLfloat x2=0.25f, y2=0.25f, radius2 =.07f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //3
    GLfloat x3=0.45f, y3=0.08f, radius3 =.27f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //4
    GLfloat x4=0.76f, y4=0.17f, radius4 =.2f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //5
    GLfloat x5=0.97f, y5=0.27f, radius5 =.07f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x5 + (radius5 * cos(i *  twicePi / triangleAmount)),
                    y5 + (radius5 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f,0.3f);
    glVertex2f(0.765f,0.3f);
    glColor3f(0.573f, 0.596f, 0.616f);
    glVertex2f(0.765f,0.0f);
    glVertex2f(0.0f,0.0f);
    glEnd();

    ///spots on moon
    ///1
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.055f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.05f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.045f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    ///2
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.065f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.06f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.055f, 0.015f, 100);
    ///3
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.05f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.045f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.04f, 0.015f, 100);
    ///4
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.06f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.055f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.05f, 0.015f, 100);
    ///5
    glColor3f(0.647f, 0.647f, 0.647f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.057f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.052f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.047f, 0.015f, 100);
    ///6
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.037f, 0.015f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.032f, 0.01f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.027f, 0.005f, 100);
    ///7
    glColor3f(0.597f, 0.597f, 0.597f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.067f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.062f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.057f, 0.015f, 100);
     ///8
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.047f, 0.01f, 100);
    ///9
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.047f, 0.01f, 100);



    ///Man in Moon
    ///***********************Man
    GLfloat m=0.2f, a=0.28f, n =0.02f;
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions4 , 0.257f, 0.0f);
    glTranslatef(+0.4f, 0.0f, 0.0f);
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m, a); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m + (n * cos(i *  twicePi / triangleAmount)),
                       a + (n * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    ///Border
    glLineWidth(1);
    GLfloat m1=0.2f; GLfloat a12=0.28f; GLfloat n1 =0.02f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m1 + (n1 * cos(i *  twicePi / lineAmount)),
			    a12 + (n1  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.196f, 0.243f);
    ///Helmate glass
    glVertex2f(0.181f,0.288f);
    glVertex2f(0.218f,0.288f);
    glVertex2f(0.21f,0.27f);
    glVertex2f(0.182f,0.27f);
    ///Neck
    glColor3f(0.78f, 0.788f, 0.839f);
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.218f,0.265f);
    ///Right Hand with Sholder
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    ///Right Hand Rest part
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    glVertex2f(0.26f,0.276f);
    glVertex2f(0.27f,0.27f);

    ///Left Hand with Sholder
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);

    ///Left Hand Rest part
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);
    glVertex2f(0.14f,0.276f);
    glVertex2f(0.13f,0.27f);
    ///Body
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);
    ///Pant Upper Part
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);
    ///Right Leg2
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);
    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);
    ///Right Leg shoe
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);
    ///Left Leg1
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.1894f,0.117f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);
    glEnd();

    ///Right Hand
    GLfloat m13=0.27f, a13=0.278f, n13 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m13, a13); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m13 + (n13 * cos(i *  twicePi / triangleAmount)),
                       a13 + (n13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Right Border
    glLineWidth(1);
    GLfloat m14=0.27f; GLfloat a14=0.278f; GLfloat n14 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m14 + (n14 * cos(i *  twicePi / lineAmount)),
			    a14 + (n14  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	///Left Hand
    GLfloat m15=0.13f, a15=0.278f, n15 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m15, a15); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m15 + (n15 * cos(i *  twicePi / triangleAmount)),
                       a15 + (n15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Left Border
    glLineWidth(1);
    GLfloat m16=0.13f; GLfloat a16=0.278f; GLfloat n16 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m16 + (n16 * cos(i *  twicePi / lineAmount)),
			    a16 + (n16  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    ///Detailing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.008f,0.043f,0.031f);

    ///Belt
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.175f,0.2f);

    glVertex2f(0.224f,0.2f);
    glVertex2f(0.224f,0.19f);

    glVertex2f(0.175f,0.2f);
    glVertex2f(0.224f,0.2f);

    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);

    ///Middle Line
    glVertex2f(0.18f,0.19f);
    glVertex2f(0.18f,0.2f);

    glVertex2f(0.19f,0.19f);
    glVertex2f(0.19f,0.2f);

    glVertex2f(0.2f,0.19f);
    glVertex2f(0.2f,0.2f);

    glVertex2f(0.21f,0.19f);
    glVertex2f(0.21f,0.2f);

    glVertex2f(0.22f,0.19f);
    glVertex2f(0.22f,0.2f);

    ///Neck Border
    glVertex2f(0.187f,0.263f);
    glVertex2f(0.182f,0.263f);

    glVertex2f(0.215f,0.265f);
    glVertex2f(0.218f,0.265f);

    ///Right Hand with Sholder Border
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.243f,0.26f);

    glVertex2f(0.255f,0.24f);
    glVertex2f(0.224f,0.235f);
    ///Right Hand Rest part Border
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.27f,0.27f);

    glVertex2f(0.243f,0.26f);
    glVertex2f(0.26f,0.276f);

    ///Left Hand with Sholder Border
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.157f,0.26f);

    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    ///Left Hand Rest part Border
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.13f,0.27f);

    glVertex2f(0.157f,0.26f);
    glVertex2f(0.14f,0.276f);
    ///Body Border
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);

    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);

    ///Suit Design
    glVertex2f(0.2f,0.26f);
    glVertex2f(0.2f,0.19f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.185f,0.265f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.215f,0.265f);

    ///Pant Upper Part Border
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);

    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1 Border
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);

    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);

    ///Right Leg2 Border
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);

    ///Right Leg shoe Border
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);

    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);

    ///RIGHT Shoe lines
    glVertex2f(0.207f,0.13f);
    glVertex2f(0.232f,0.13f);

    glVertex2f(0.207f,0.135f);
    glVertex2f(0.23f,0.135f);
    ///Left Leg1 Border
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);

    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2 Border
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);

    glVertex2f(0.1894f,0.12f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe Border
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);

    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);

    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.159f,0.117f);

    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);

    ///LEFT Shoe lines
    glVertex2f(0.1667f,0.13f);
    glVertex2f(0.1895f,0.13f);

    glVertex2f(0.1667f,0.135f);
    glVertex2f(0.1895f,0.135f);

    glEnd();
    glPopMatrix();

    ///AIUB Banner
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(positions3 , 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.498f, 0.498f, 0.498f);
    glVertex2f(0.335f,0.33f);
    glVertex2f(0.335f,0.25f);
    glVertex2f(0.265f,0.33f);
    glVertex2f(0.265f,0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.565f, 0.588f, 0.616f);
    glVertex2f(0.34f,.385f);
    glVertex2f(0.34f,0.33f);
    glVertex2f(0.26f,0.33f);
    glVertex2f(0.26f,0.385f);
    glEnd();

    glColor3f(0.035f, 0.38f, 0.569f);
    renderBitmapString(0.28f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    glColor3f(0.047f, 0.384f, 0.224f);
    renderBitmapString(0.29f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "I");
    glColor3f(0.792f, 0.09f, 0.259f);
    renderBitmapString(0.295f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "U");
    glColor3f(0.745f, 0.455f, 0.133f);
    renderBitmapString(0.305f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "B");
    glPopMatrix();

    ///..........................................Man-2....................................////
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions5, 0.3f, 0.0f);
    glTranslatef(+0.73f, 0.0f, 0.0f);
    GLfloat m17=0.2f, a17=0.28f, n17 =0.02f;
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m17, a17); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m17 + (n17 * cos(i *  twicePi / triangleAmount)),
                       a17 + (n17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    ///Border
    glLineWidth(1);
    GLfloat m18=0.2f; GLfloat a18=0.28f; GLfloat n18 =0.02f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m18 + (n18 * cos(i *  twicePi / lineAmount)),
			    a18 + (n18 * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.196f, 0.243f);
    ///Helmate glass
    glVertex2f(0.181f,0.288f);
    glVertex2f(0.218f,0.288f);
    glVertex2f(0.21f,0.27f);
    glVertex2f(0.182f,0.27f);
    ///Neck
    glColor3f(0.78f, 0.788f, 0.839f);
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.218f,0.265f);
    ///Right Hand with Sholder
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    ///Right Hand Rest part
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    glVertex2f(0.27f,0.26f);
    glVertex2f(0.27f,0.24f);

    ///Left Hand with Sholder
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);

    ///Left Hand Rest part
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);
    glVertex2f(0.148f,0.28f);
    glVertex2f(0.135f,0.275f);
    ///Body
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);
    ///Pant Upper Part
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);
    ///Right Leg2
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);
    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);
    ///Right Leg shoe
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);
    ///Left Leg1
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.1894f,0.117f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);
    glEnd();

    ///Right Hand
    GLfloat m19=0.27f, a19=0.25f, n19 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m19, a19); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m19 + (n19 * cos(i *  twicePi / triangleAmount)),
                       a19 + (n19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Right Border
    glLineWidth(1);
    GLfloat m20=0.27f; GLfloat a20=0.25f; GLfloat n20 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m20 + (n20 * cos(i *  twicePi / lineAmount)),
			    a20 + (n20  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	///Left Hand
    GLfloat m21=0.14f, a21=0.283f, n21 =0.009f;
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m21, a21); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m21 + (n21 * cos(i *  twicePi / triangleAmount)),
                       a21 + (n21 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Left Border
    glLineWidth(1);
    GLfloat m22=0.14f; GLfloat a22=0.283f; GLfloat n22 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m22 + (n22 * cos(i *  twicePi / lineAmount)),
			    a22 + (n22  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    ///Detailing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.008f,0.043f,0.031f);

    ///Belt
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.175f,0.2f);

    glVertex2f(0.224f,0.2f);
    glVertex2f(0.224f,0.19f);

    glVertex2f(0.175f,0.2f);
    glVertex2f(0.224f,0.2f);

    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);

    ///Middle Line
    glVertex2f(0.18f,0.19f);
    glVertex2f(0.18f,0.2f);

    glVertex2f(0.19f,0.19f);
    glVertex2f(0.19f,0.2f);

    glVertex2f(0.2f,0.19f);
    glVertex2f(0.2f,0.2f);

    glVertex2f(0.21f,0.19f);
    glVertex2f(0.21f,0.2f);

    glVertex2f(0.22f,0.19f);
    glVertex2f(0.22f,0.2f);

    ///Neck Border
    glVertex2f(0.187f,0.263f);
    glVertex2f(0.182f,0.263f);

    glVertex2f(0.215f,0.265f);
    glVertex2f(0.218f,0.265f);

    ///Right Hand with Sholder Border
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.243f,0.26f);

    glVertex2f(0.255f,0.24f);
    glVertex2f(0.224f,0.235f);
    ///Right Hand Rest part Border
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.27f,0.24f);

    glVertex2f(0.243f,0.26f);
    glVertex2f(0.27f,0.26f);

    ///Left Hand with Sholder Border
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.157f,0.26f);

    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    ///Left Hand Rest part Border
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.135f,0.275f);

    glVertex2f(0.157f,0.26f);
    glVertex2f(0.148f,0.28f);
    ///Body Border
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);

    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);

    ///Suit Design
    glVertex2f(0.2f,0.26f);
    glVertex2f(0.2f,0.19f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.185f,0.265f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.215f,0.265f);

    ///Pant Upper Part Border
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);

    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1 Border
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);

    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);

    ///Right Leg2 Border
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);

    ///Right Leg shoe Border
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);

    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);

    ///RIGHT Shoe lines
    glVertex2f(0.207f,0.13f);
    glVertex2f(0.232f,0.13f);

    glVertex2f(0.207f,0.135f);
    glVertex2f(0.23f,0.135f);
    ///Left Leg1 Border
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);

    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2 Border
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);

    glVertex2f(0.1894f,0.12f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe Border
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);

    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);

    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.159f,0.117f);

    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);

    ///LEFT Shoe lines
    glVertex2f(0.1667f,0.13f);
    glVertex2f(0.1895f,0.13f);

    glVertex2f(0.1667f,0.135f);
    glVertex2f(0.1895f,0.135f);

    glEnd();
    glPopMatrix();

    ///Flag BD
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions5, 0.0f, 0.0f);
    glTranslatef(+0.5f, 0.3f, 0.0f);
    glLineWidth(5);
    glColor3f(0.62f, 0.506f, 0.278f);
    glBegin(GL_LINES);
    glVertex2f(0.5f,0.43f);
    glVertex2f(0.5f,0.15f);
    glEnd();

    GLfloat x[4], y[4], yy[4];
    GLdouble xt[300], yt[300], yyt[300], t;
    int i, c;

    x[0]=0.5;x[1]=0.55;x[2]=0.55;x[3]=0.6-xa;
    y[0]=0.41;y[1]=0.41+ya;y[2]=0.41-ya;y[3]=0.41;
    yy[0]=0.31;yy[1]=0.31+ya;yy[2]=0.31-ya;yy[3]=0.31;

    for(i=0, t=0, c=0; t<=1; i++, t=t+0.02)
    {
        xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        yt[i] = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        yyt[i] = pow(1-t,3)*yy[0]+3*t*pow(1-t,2)*yy[1]+3*pow(t,2)*(1-t)*yy[2]+pow(t,3)*yy[3];
        c++;
    }

    glPointSize(4);
    glColor3f(0.0f, 0.404f, 0.298f);
    glBegin(GL_QUAD_STRIP);
    for(i=0; i<c; i++)
    {
        glVertex2d(xt[i],yt[i]);
        glVertex2d(xt[i],yyt[i]);
    }
    glEnd();

    ///red circle
    GLfloat xc=0.55f-xa, yc=0.36f, radiusc =.03f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int ic = 0; ic <= triangleAmount; ic++)
    {
        glVertex2f( xc + (radiusc * cos(ic *  twicePi / triangleAmount)),
                    yc + (radiusc * sin(ic * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    ///Stairs
    glPushMatrix();
    glTranslatef(positions2,0.15f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.345f, 0.42f, 0.427f);
    glVertex2f(0.08f,0.02f);
    glVertex2f(0.077f,0.1f);
    glVertex2f(0.065f,0.1f);
    glVertex2f(0.065f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.06f);
    glVertex2f(0.035f,0.06f);
    glVertex2f(0.035f,0.04f);
    glVertex2f(0.02f,0.04f);
    glVertex2f(0.02f,0.02f);
    glEnd();
    glPopMatrix();

    ///Moonland Right side
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(0.76f,0.3f);
    glColor3f(0.573f, 0.596f, 0.616f);
    glVertex2f(0.76f,0.0f);
    glVertex2f(1.0f,0.0f);
    glEnd();

    ///10
    glColor3f(0.647f, 0.647f, 0.647f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.047f, 0.01f, 100);



    ///Rocket
///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glScalef(1.2,1.2,0);
    glTranslatef(+0.25f, positions, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);

    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();

    glPopMatrix();
    ///_____________________________________________ROCKET(END)___________________________________________________///



    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 750); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);// Set the window's initial position according to the monitor
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("The Project : Rocket"); // Create a window with the given title
    glutFullScreen();
    init();
    glutDisplayFunc(display5); // Register display callback handler for window re-paint
    glutTimerFunc(100, updates, 0);
    glutTimerFunc(200, updates1, 0);
    glutTimerFunc(4000, updates2, 0);
    glutTimerFunc(9000, updates3, 0);
    glutTimerFunc(4000, meteorUps, 0);
    glutTimerFunc(0, updatep, 0);
    glutSpecialFunc(SpecialInputs);
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}

