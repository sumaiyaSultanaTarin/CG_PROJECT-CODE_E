#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<math.h>>
# define PI           3.14159265358979323846
int triangleAmount = 100;
int lineAmount = 100;
GLfloat twicePi = 2.0f * PI;


int i;
GLfloat A = 0.0f;
GLfloat P = 0.0f;
GLfloat Aspeed = 0.0;
GLfloat Pspeed = 0.0;
GLfloat Ospeed = 0.0;
GLfloat APosition = 0.0;
GLfloat PPosition = 0.0;
GLfloat OPosition = 0.0;


GLfloat meteorP3=0.0; GLfloat meteorP4=0.0;
GLfloat meteorS3=0.05;GLfloat meteorS4=0.03;

void meteorUpp(int value){

       if(meteorP3 < -1.0)
        meteorS3 = 0.5f;

        if(meteorP4 > 1.0)
        meteorS4 = 0.0f;

         meteorP3 -= meteorS3;
         meteorP4 += meteorS4;

	glutPostRedisplay();
	glutTimerFunc(100, meteorUpp, 0);

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
void drawEllipse1(float centerX, float centerY, float radiusX, float radiusY, int numSegments) {
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();



}
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}

void Idle()
{
    glutPostRedisplay();
}

void display4() {
    glClearColor(0.016f, 0.016f, 0.016f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

///FULL SCREEN
    glBegin(GL_QUADS);
    glColor3f(0.082f, 0.133f, 0.169f);
    glVertex2f(0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 1.0);
    glColor3f(0.259f, 0.333f, 0.349f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    ///.................................Stars.........................
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(0.89f, 0.867f, 0.875f);
    glVertex2f(0.04f, 0.04f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.04f, 0.55f);
    glVertex2f(0.08f, 0.018f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.5f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.06f, 0.62f);
    glVertex2f(0.5f, 0.62f);
    glVertex2f(0.5f, 0.18f);
    glVertex2f(0.4f, 0.09f);
    glVertex2f(0.3f, 0.13f);
    glVertex2f(0.22f, 0.08f);
    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.49f, 0.83f);
    glVertex2f(0.3f, 0.65f);
    glVertex2f(0.3f, 0.9f);
    glVertex2f(0.45f, 0.94f);
    glVertex2f(0.45f, 0.8f);
    glVertex2f(0.53f, 0.75f);
    glVertex2f(0.63f, 0.5f);
    glVertex2f(0.63f, 0.75f);
    glVertex2f(0.69f, 0.8f);
    glVertex2f(0.73f, 0.95f);
    glVertex2f(0.94f, 0.95f);
    glVertex2f(0.86f, 0.98f);
    glVertex2f(0.8f, 0.43f);
    glVertex2f(0.75f, 0.48f);
    glVertex2f(0.7f, 0.28f);
    glVertex2f(0.7f, 0.63f);
    glVertex2f(0.45f, 0.28f);
    glVertex2f(0.6f, 0.28f);
    glVertex2f(0.5f, 0.46f);
    glVertex2f(0.08f,0.66f);
    glVertex2f(0.2f,0.6f);
    glVertex2f(0.40f,0.52f);
    glVertex2f(0.28f,0.26f);
    glVertex2f(0.40f,0.7f);
    glVertex2f(0.56f,0.06f);
    glVertex2f(0.60f,0.9f);
    glVertex2f(0.84f,0.84f);
    glVertex2f(0.12f,0.4f);
    glVertex2f(0.32f,0.4f);
    glVertex2f(0.9f,0.83f);
    glVertex2f(0.8f,0.6f);
    glVertex2f(0.8f,0.9f);
    glVertex2f(0.95f,0.86f);
    glVertex2f(0.9f,0.66f);
    glVertex2f(0.97f,0.76f);
    glVertex2f(0.88f,0.56f);
    glVertex2f(0.98f,0.6f);
    glVertex2f(0.05f,0.8f);
    glVertex2f(0.06f,0.9f);
    glVertex2f(0.09f,0.86f);
    glVertex2f(0.16f,0.96f);
    glVertex2f(0.18f,0.83f);
    glEnd();

    ///________________________________Main____________________
    glPushMatrix();
    glTranslatef(0.0f,APosition,0.0f);
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.515f,-0.59f,0.0f);

    ///.......................................Cylinder .................
    glBegin(GL_QUADS);
    ///_______11 Right small rocket Body_____///
    glColor3f(0.196, 0.51, 0.984);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_TRIANGLES);
    ///_______11 Right small rocket Head_____///
    glColor3f(0.98, 0.549, 0.11);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
     ///_______11 Right small rocket Body_____///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    ///_______11 Right small rocket Head_____///
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
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
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
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

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,PPosition,0.0f);
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.515f,-0.59f,0.0f);
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
    glEnd();
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

    ///_________ Fire main 1________///
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
    ///_____________________________________________ROCKET(END)___________________________________________________///


    ///STAR 2
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(1.60f,6.00f,0.0f);
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

    ///STAR 5
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.40f,4.f,0.0f);
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

///something
    glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.50f,1.50f,0.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
	glScalef(.3,.3,0);
	glTranslatef(1.0f,0.50f,0.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();
    glPopMatrix();

    glPointSize(4.9);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.9f,0.9f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.91f,0.9f);
    glVertex2f(.89f,0.9f);
    glVertex2f(.90f,0.91f);
    glVertex2f(.901f,0.89f);

    glEnd();

     glPushMatrix();
    glTranslatef(meteorP4,meteorP3,0.0f);

    ///........Meteor - 1..........................................
    glPushMatrix();
    glTranslatef(OPosition,0.0f, 0.0f);
    glScalef(.2,.2,0);
	glTranslatef(1.10f,4.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
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
    GLfloat A81=0.5f; GLfloat P81=0.5f; GLfloat O81 =0.013f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A81, P81); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A81 + (O81 * cos(i *  twicePi/ triangleAmount)),
                        P81 + (O81 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A82=0.505f; GLfloat P82=0.5045f; GLfloat O82 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A82, P82); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A82 + (O82 * cos(i *  twicePi/ triangleAmount)),
                        P82 + (O82 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    ///........................................Earth.....................................................///


    glPushMatrix();
    glTranslatef(0.42f, -0.20f, 0.0f);
    glPushMatrix();
    glScalef(0.9,0.9,0);

    GLfloat A0=0.54f; GLfloat P0=0.32f; GLfloat O0 =0.27f;
    glColor3f(0.0f, 0.651f, 0.886f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0, P0); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0 + (O0 * cos(i *  twicePi/ triangleAmount)),
                        P0 + (O0 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();

    ///.........................Earth Inside Light Green-1
    ///1
    glPushMatrix();
    glScalef(7.50,7.50,0);
    glPushMatrix();
    glLoadIdentity();//Reset the current matrix
    glTranslatef(0.30,-1.20,0);
    glRotatef(A,0.0,0.0,1.0);//
    GLfloat A1=0.54f; GLfloat P1=0.5f; GLfloat O1 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1, P1); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1 + (O1 * cos(i *  twicePi / triangleAmount)),
                        P1 + (O1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A2=0.46f; GLfloat P2=0.52f; GLfloat O2 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A2, P2); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A2 + (O2 * cos(i *  twicePi / triangleAmount)),
                        P2 + (O2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A3=0.4f; GLfloat P3=0.422f; GLfloat O3 =0.0975f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A3, P3); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A3 + (O3 * cos(i *  twicePi / triangleAmount)),
                        P3 + (O3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A4=0.48f; GLfloat P4=0.4f; GLfloat O4 =0.08f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A4, P4); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A4 + (O4 * cos(i *  twicePi / triangleAmount)),
                        P4 + (O4 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-1
    ///1
    GLfloat A5=0.5f; GLfloat P5=0.5f; GLfloat O5 =0.047f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A5, P5); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A5 + (O5 * cos(i *  twicePi / triangleAmount)),
                        P5 + (O5 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A6=0.46f; GLfloat P6=0.52f; GLfloat O6 =0.056f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A6, P6); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A6 + (O6 * cos(i *  twicePi / triangleAmount)),
                        P6 + (O6 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A7=0.4f; GLfloat P7=0.465f; GLfloat O7 =0.069f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A7, P7); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A7 + (O7 * cos(i *  twicePi / triangleAmount)),
                        P7 + (O7 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A8=0.48f; GLfloat P8=0.45f; GLfloat O8 =0.045f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A8, P8); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A8 + (O8 * cos(i *  twicePi / triangleAmount)),
                        P8 + (O8 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A9=0.45f; GLfloat P9=0.43f; GLfloat O9 =0.045f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A9, P9); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A9 + (O9 * cos(i *  twicePi / triangleAmount)),
                        P9 + (O9 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///6
    GLfloat A10=0.415f; GLfloat P10=0.503f; GLfloat O10 =0.049f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A10, P10); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A10 + (O10 * cos(i *  twicePi / triangleAmount)),
                        P10 + (O10 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///7
    GLfloat A1000=0.4f; GLfloat P1000=0.5f; GLfloat O1000 =0.043f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1000, P1000); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1000 + (O1000 * cos(i *  twicePi / triangleAmount)),
                        P1000 + (O1000 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///8
    GLfloat A1001=0.43f; GLfloat P1001=0.518f; GLfloat O1001 =0.0435f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1001, P1001); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1001 + (O1001 * cos(i *  twicePi / triangleAmount)),
                        P1001 + (O1001 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///.........................Earth Inside Light Green-2
    ///1
    GLfloat A11=0.48f; GLfloat P11=0.2f; GLfloat O11 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A11, P11); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A11 + (O11 * cos(i *  twicePi / triangleAmount)),
                        P11 + (O11 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A12=0.44f; GLfloat P12=0.17f; GLfloat O12 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A12, P12); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A12 + (O12 * cos(i *  twicePi / triangleAmount)),
                        P12 + (O12 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A13=0.44f; GLfloat P13=0.22f; GLfloat O13 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A13, P13); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A13 + (O13 * cos(i *  twicePi / triangleAmount)),
                        P13 + (O13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A14=0.54f; GLfloat P14=0.15f; GLfloat O14 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A14, P14); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A14 + (O14 * cos(i *  twicePi / triangleAmount)),
                        P14 + (O14 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-2
    ///1
    GLfloat A15=0.48f; GLfloat P15=0.21f; GLfloat O15 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A15, P15); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A15 + (O15 * cos(i *  twicePi / triangleAmount)),
                        P15 + (O15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A16=0.46f; GLfloat P16=0.17f; GLfloat O16 =0.041f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A16, P16); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A16 + (O16 * cos(i *  twicePi / triangleAmount)),
                        P16 + (O16 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A17=0.435f; GLfloat P17=0.23f; GLfloat O17 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A17, P17); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A17 + (O17 * cos(i *  twicePi / triangleAmount)),
                        P17 + (O17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A18=0.41f; GLfloat P18=0.2f; GLfloat O18 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A18, P18); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A18 + (O18 * cos(i *  twicePi / triangleAmount)),
                        P18 + (O18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///.........................Earth Inside Light Green-3
    ///1
    GLfloat A19=0.76f; GLfloat P19=0.38f; GLfloat O19 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A19, P19); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A19 + (O19 * cos(i *  twicePi / triangleAmount)),
                        P19 + (O19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A20=0.74f; GLfloat P20=0.32f; GLfloat O20 =0.07f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A20, P20); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A20 + (O20 * cos(i *  twicePi / triangleAmount)),
                        P20 + (O20 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A21=0.7f; GLfloat P21=0.35f; GLfloat O21 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A21, P21); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A21 + (O21 * cos(i *  twicePi / triangleAmount)),
                        P21 + (O21 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A22=0.67f; GLfloat P22=0.29f; GLfloat O22 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A22, P22); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A22 + (O22 * cos(i *  twicePi / triangleAmount)),
                        P22 + (O22 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A23=0.72f; GLfloat P23=0.27f; GLfloat O23 =0.07f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A23, P23); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A23 + (O23 * cos(i *  twicePi / triangleAmount)),
                        P23 + (O23 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-3
    ///1
    GLfloat A24=0.76f; GLfloat P24=0.38f; GLfloat O24 =0.027f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A24, P24); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A24 + (O24 * cos(i *  twicePi / triangleAmount)),
                        P24 + (O24 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A25=0.75f; GLfloat P25=0.34f; GLfloat O25 =0.05f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A25, P25); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A25 + (O25 * cos(i *  twicePi / triangleAmount)),
                        P25 + (O25 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A26=0.7f; GLfloat P26=0.35f; GLfloat O26 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A26, P26); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A26 + (O26 * cos(i *  twicePi / triangleAmount)),
                        P26 + (O26 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A27=0.69f; GLfloat P27=0.29f; GLfloat O27 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A27, P27); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A27 + (O27 * cos(i *  twicePi / triangleAmount)),
                        P27 + (O27 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A28=0.72f; GLfloat P28=0.27f; GLfloat O28 =0.05f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A28, P28); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A28 + (O28 * cos(i *  twicePi / triangleAmount)),
                        P28 + (O28 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    A+=0.001f;
    glPopMatrix();

    /// ................EARTH'S Border........................................................///
    glLineWidth(3);
    GLfloat A29=0.54f; GLfloat P29=0.32f; GLfloat O29 =0.27f;
    glColor3f(0.259f, 0.333f, 0.349f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++)
            {
			glVertex2f(
			    A29 + (O29 * cos(i *  twicePi / lineAmount)),
			    P29 + (O29* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

	///..................................Planet...........................................///
	glPushMatrix();
	glTranslatef(0.05f,0.2f,0.0f);
	glScalef(0.6f,0.6f,0.0f);
    GLfloat A30=0.09f; GLfloat P30=0.9f; GLfloat O30 =0.13f;
    glColor3f(0.659f, 0.392f, 0.886f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A30, P30); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A30 + (O30 * cos(i *  twicePi / triangleAmount)),
                        P30 + (O30 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///Black Spot
    /// 1.
    GLfloat A33=0.07f; GLfloat P33=0.795f; GLfloat O33 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A33, P33); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A33 + (O33 * cos(i *  twicePi / triangleAmount)),
                        P33 + (O33 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 1
    GLfloat A34=0.07f; GLfloat P34=0.795f; GLfloat O34 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A34, P34); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A34 + (O34 * cos(i *  twicePi / triangleAmount)),
                        P34 + (O34 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 2.
    GLfloat A35=0.185f; GLfloat P35=0.86f; GLfloat O35 =0.025f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A35, P35); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A35 + (O35 * cos(i *  twicePi / triangleAmount)),
                        P35 + (O35 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 2
    GLfloat A36=0.18f; GLfloat P36=0.86f; GLfloat O36 =0.015f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A36, P36); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A36 + (O36 * cos(i *  twicePi / triangleAmount)),
                        P36 + (O36 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 3.
    GLfloat A37=0.13f; GLfloat P37=0.82f; GLfloat O37 =0.019f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A37, P37); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A37 + (O37 * cos(i *  twicePi / triangleAmount)),
                        P37 + (O37 * sin(i * twicePi / triangleAmount)) );

        }
        glEnd();
    /// Inside Round of Number 3
    GLfloat A38=0.125f; GLfloat P38=0.82f; GLfloat O38 =0.01f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A38, P38); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A38 + (O38 * cos(i *  twicePi / triangleAmount)),
                        P38 + (O38 * sin(i * twicePi / triangleAmount)) );

        }
        glEnd();
    /// 4.
    GLfloat A39=0.015f; GLfloat P39=0.85f; GLfloat O39 =0.03f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A39, P39); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A39 + (O39 * cos(i *  twicePi / triangleAmount)),
                        P39 + (O39 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 4
    GLfloat A40=0.015f; GLfloat P40=0.85f; GLfloat O40 =0.017f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A40, P40); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A40 + (O40 * cos(i *  twicePi / triangleAmount)),
                        P40 + (O40 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///5.
    GLfloat A41=0.09f; GLfloat P41=0.85f; GLfloat O41 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A41, P41); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A41 + (O41 * cos(i *  twicePi / triangleAmount)),
                        P41 + (O41 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 5
    GLfloat A42=0.09f; GLfloat P42=0.85f; GLfloat O42 =0.009f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A42, P42); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A42 + (O42 * cos(i *  twicePi / triangleAmount)),
                        P42 + (O42 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///6.
    GLfloat A43=0.13f; GLfloat P43=0.89f; GLfloat O43 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A43, P43); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A43 + (O43 * cos(i *  twicePi / triangleAmount)),
                        P43 + (O43 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 6
    GLfloat A44=0.13f; GLfloat P44=0.89f; GLfloat O44 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A44, P44); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A44 + (O44 * cos(i *  twicePi / triangleAmount)),
                        P44 + (O44 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///7.
    GLfloat A45=0.194f; GLfloat P45=0.93f; GLfloat O45 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A45, P45); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A45 + (O45 * cos(i *  twicePi / triangleAmount)),
                        P45 + (O45 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 7
    GLfloat A46=0.19f; GLfloat P46=0.93f; GLfloat O46 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A46, P46); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A46 + (O46 * cos(i *  twicePi / triangleAmount)),
                        P46 + (O46 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///8.
    GLfloat A47=0.15f; GLfloat P47=0.98f; GLfloat O47 =0.03f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A47, P47); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A47 + (O47 * cos(i *  twicePi / triangleAmount)),
                        P47 + (O47 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 8
    GLfloat A48=0.15f; GLfloat P48=0.985f; GLfloat O48 =0.019f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A48, P48); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A48 + (O48 * cos(i *  twicePi / triangleAmount)),
                        P48 + (O48 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///9.
    GLfloat A49=0.11f; GLfloat P49=0.94f; GLfloat O49 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A49, P49); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A49 + (O49 * cos(i *  twicePi / triangleAmount)),
                        P49 + (O49 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 9
    GLfloat A50=0.11f; GLfloat P50=0.94f; GLfloat O50 =0.01f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A50, P50); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A50 + (O50 * cos(i *  twicePi / triangleAmount)),
                        P50 + (O50 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///10.
    GLfloat A51=0.07f; GLfloat P51=0.9f; GLfloat O51 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A51, P51); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A51 + (O51 * cos(i *  twicePi / triangleAmount)),
                        P51 + (O51 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 10
    GLfloat A52=0.07f; GLfloat P52=0.9f; GLfloat O52 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A52, P52); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A52 + (O52 * cos(i *  twicePi / triangleAmount)),
                        P52 + (O52 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///12.
    GLfloat A53=0.09f; GLfloat P53=0.99f; GLfloat O53 =0.025f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A53, P53); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A53 + (O53 * cos(i *  twicePi / triangleAmount)),
                        P53 + (O53 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 12
    GLfloat A54=0.09f; GLfloat P54=0.99f; GLfloat O54 =0.015f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A54, P54); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A54 + (O54 * cos(i *  twicePi / triangleAmount)),
                        P54 + (O54 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///13.
    GLfloat A55=0.038f; GLfloat P55=0.95f; GLfloat O55 =0.02f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A55, P55); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A55 + (O55 * cos(i *  twicePi / triangleAmount)),
                        P55 + (O55 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 13
    GLfloat A56=0.038f; GLfloat P56=0.95f; GLfloat O56 =0.012f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A56, P56); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A56 + (O56 * cos(i *  twicePi / triangleAmount)),
                        P56 + (O56 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    /// Small Circle
    ///1.
    GLfloat A57=0.04f; GLfloat P57=0.995f; GLfloat O57 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A57, P57); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A57 + (O57 * cos(i *  twicePi / triangleAmount)),
                        P57 + (O57 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///2.
    GLfloat A58=0.06f; GLfloat P58=0.835f; GLfloat O58 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A58, P58); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A58 + (O58 * cos(i *  twicePi / triangleAmount)),
                        P58 + (O58 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///3.
    GLfloat A59=0.03f; GLfloat P59=0.9f; GLfloat O59 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A59, P59); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A59 + (O59 * cos(i *  twicePi / triangleAmount)),
                        P59 + (O59 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///4.
    GLfloat A60=0.075f; GLfloat P60=0.945f; GLfloat O60 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A60, P60); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A60 + (O60 * cos(i *  twicePi / triangleAmount)),
                        P60 + (O60 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///6.
    GLfloat A62=0.007f; GLfloat P62=0.97f; GLfloat O62 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A62, P62); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A62 + (O62 * cos(i *  twicePi / triangleAmount)),
                        P62 + (O62 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///7.
    GLfloat A63=0.007f; GLfloat P63=0.92f; GLfloat O63 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A63, P63); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A63 + (O63 * cos(i *  twicePi / triangleAmount)),
                        P63 + (O63 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///8.
    GLfloat A64=0.16f; GLfloat P64=0.92f; GLfloat O64 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A64, P64); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A64 + (O64 * cos(i *  twicePi / triangleAmount)),
                        P64 + (O64 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    glPopMatrix();

    ///.............................................Planet...........MARS....................................///
    GLfloat A31=0.9f; GLfloat P31=0.75f; GLfloat O31 =0.030f;
    glColor3f(0.741f, 0.275f, 0.157f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A31, P31); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glColor3f( 0.878f, 0.4f, 0.263f);
            glVertex2f( A31 + (O31 * cos(i *  twicePi/ triangleAmount)),
                        P31 + (O31 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Planet...........Venus
    GLfloat A32=0.07f; GLfloat P32=0.20f; GLfloat O32 =0.035f;
    glColor3f(0.753f, 0.62f, 0.439f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A32, P32); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
               glColor3f(0.545f, 0.439f, 0.231f);
            glVertex2f( A32 + (O32 * cos(i *  twicePi/ triangleAmount)),
                        P32 + (O32 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Circle Starts From 81

    ///..............................................Moon................................
    GLfloat A65=0.55f; GLfloat P65=0.95f; GLfloat O65 =0.13f;
    glColor3f(0.925f, 0.925f, 0.925f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A65, P65); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
                glColor3f(0.694f, 0.694f, 0.694f);
            glVertex2f( A65 + (O65 * cos(i *  twicePi / triangleAmount)),
                        P65 + (O65 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///..................................moon...................................................///
    ///moon
    glColor3f(0.686, 0.686, 0.686); // Set color to re
    drawEllipse(0.55f, 0.95f, 0.02f, 0.005f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments







///...................................satrun ...................................................///
    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.05f,0.3f,0.0f);
    glColor3f(0.824, 0.518, 0.337); // Set color to re
    drawEllipse(0.4f, 0.4f, 0.05f, 0.05f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    glColor3f(0.91, 0.765, 0.608); // Set color to red
    drawEllipse1(0.4f, 0.4f, 0.07f, 0.01f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    glBegin(GL_QUADS);
    glColor3f(0.824, 0.518, 0.337);
    glVertex2f(0.351f,0.413f);
    glVertex2f(0.351f,0.404f);
    glVertex2f(0.449f,0.404f);
    glVertex2f(0.449f,0.413f);
    glEnd();
    glPopMatrix();
    ///...................................satrun ...................................................///

    ///..............................JHAPSA PLANET...................................................///

    /// PLANET A
    GLfloat A66=0.20f; GLfloat P66=0.20f; GLfloat O66 =0.01f;
    glColor3f(0.212f, 0.341f, 0.431f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A66, P66); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A66 + (O66 * cos(i *  twicePi / triangleAmount)),
                        P66 + (O66 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///PLANET B

    GLfloat A67=0.70f; GLfloat P67=0.50f; GLfloat O67 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A67, P67); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A67 + (O67 * cos(i *  twicePi / triangleAmount)),
                        P67 + (O67 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///PLANET C
    GLfloat A68=0.50f; GLfloat P68=0.10f; GLfloat O68 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A68, P68); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A68 + (O68 * cos(i *  twicePi / triangleAmount)),
                        P68 + (O68 * sin(i * twicePi / triangleAmount)) );

        }
      glEnd();

      ///PLANET D
    GLfloat A69=0.25f; GLfloat P69=0.50f; GLfloat O69 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A69, P69); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A69 + (O69 * cos(i *  twicePi / triangleAmount)),
                        P69 + (O69 * sin(i * twicePi / triangleAmount)) );

        }
      glEnd();

      ///PLANET E
    GLfloat A70=0.15f; GLfloat P70=0.90f; GLfloat O70 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A70, P70); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A70 + (O70 * cos(i *  twicePi / triangleAmount)),
                        P70 + (O70 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();




    ///...................................Satellite...................................................///
    glPushMatrix();
    glScalef(0.5f,0.5f,0.0f);
    glTranslatef(1.8f,0.4f, 0.0f);
    glRotatef(P,0.0,0.40,1.0);
    ///body
    glBegin(GL_QUADS);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.65f);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.65f);
    ///RIGHT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.645f);
    ///LEFT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095,0.645f);
    glEnd();
///LINES
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.773f, 0.788f, 0.776f);
    ///right
    glVertex2f(0.12f,0.625f);
    glVertex2f(0.125f,0.625f);

    ///left
    glVertex2f(0.10f,0.625f);
    glVertex2f(0.095f,0.625f);
    ///upper
    glVertex2f(0.105f,0.65f);
    glVertex2f(0.105f,0.66f);
    glVertex2f(0.115f,0.65f);
    glVertex2f(0.115f,0.66f);
    ///with mini circle
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    ///MIDDLE IN RIGHT WINGS
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.125f,0.615f);
    glVertex2f(0.175f,0.615f);
    glVertex2f(0.125f,0.625f);
    glVertex2f(0.175f,0.625f);
    glVertex2f(0.125f,0.635f);
    glVertex2f(0.175f,0.635f);
    glVertex2f(0.135f,0.605f);
    glVertex2f(0.135f,0.645f);
    glVertex2f(0.145f,0.605f);
    glVertex2f(0.145f,0.645f);
    glVertex2f(0.155f,0.605f);
    glVertex2f(0.155f,0.645f);
    glVertex2f(0.165f,0.605f);
    glVertex2f(0.165f,0.645f);
    ///MIDDLE LINE IN LEFT WINGS
    glVertex2f(0.095f,0.615f);
    glVertex2f(0.045f,0.615f);
    glVertex2f(0.095f,0.625f);
    glVertex2f(0.045f,0.625f);
    glVertex2f(0.095f,0.635f);
    glVertex2f(0.045f,0.635f);
    glVertex2f(0.055f,0.605f);
    glVertex2f(0.055f,0.645f);
    glVertex2f(0.065f,0.605f);
    glVertex2f(0.065f,0.645f);
    glVertex2f(0.075f,0.605f);
    glVertex2f(0.075f,0.645f);
    glVertex2f(0.085f,0.605f);
    glVertex2f(0.085f,0.645f);
    glEnd();
    ///mini circle
    GLfloat A83=0.11f, P83=0.70f, O83=.005;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(A83, P83); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( A83 + (O83 * cos(i *  twicePi / triangleAmount)),
                    P83 + (O83 * sin(i * twicePi / triangleAmount)) );
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();
    ///HALF CIRCLE
    GLfloat A84=0.11f, P84=0.68f, O84=.025;
    twicePi= -1.0f *PI;
    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(A84, P84); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( A84 + (O84 * cos(i *  twicePi / triangleAmount)),
                    P84 + (O84 * sin(i * twicePi / triangleAmount)) );
        glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();
    P+=0.003f;
    glPopMatrix();


    glFlush(); // Render now
}

///...........Separate
void updateA(int value)
{
    if(APosition >2.0 )
        APosition = -1.0f;
    APosition += Aspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateA, 0);
}
///.........Rocket
void updateP(int value)
{
    if(PPosition >2.0 )
        PPosition = -1.0f;
    PPosition += Pspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateP, 0);
}

void handleKeypressA(unsigned char key, int x, int y)
{
    switch(key)
    {
        ///.....C
                        case 'w':
                         Aspeed=0.015f;
                         Pspeed=0.015f;
                         break;
                         case 's':
                         Aspeed=-0.02f;
                         break;
                         case 'a':
                         Pspeed=-0.02f;
                         break;
                         ///.......Rocket
                         case 'd':
                         Pspeed=0.0f;
                         Aspeed=0.0f;
                         break;

        glutPostRedisplay();
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glBlendFunc(0.5,0.5);
    glutInitWindowSize(1400, 800); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("The Project : Rocket"); // Create a window with the given title
    ///glutFullScreen();
    init();
    glutDisplayFunc(display4); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypressA);
    glutTimerFunc(100, updateA, 0);
    glutTimerFunc(100, updateP, 0);
    glutTimerFunc(3000, meteorUpp, 0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
