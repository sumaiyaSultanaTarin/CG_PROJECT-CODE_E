#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<math.h>>
# define PI           3.14159265358979323846
GLfloat k = 0.0f;
int triangleAmount = 100;
int lineAmount = 100;
GLfloat twicePi = 2.0f * PI;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.05f;
int i;
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void update(int value)
{
    if(position < -1.5)
            position = 1.5f;

    if(position2 > 1.5)
            position2 = -1.5f;

    if(position3 < -2.0)
            position3 = 2.0f;

    position -= speed;
    position2 += speed;
    position3 -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void update2(int value)
{
    if(position > 1.5)
            position = -1.5f;

    if(position2 < -1.5)
            position2 = 1.5f;

    if(position3 > 2.0)
            position3 = -2.0f;

    position += speed;
    position2 -= speed;
    position3 += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            speed = speed + 0.01;
            break;

        case GLUT_KEY_DOWN:
            speed = speed - 0.01;
            break;

        case GLUT_KEY_LEFT:
            glutTimerFunc(100, update, 0);
            break;

        case GLUT_KEY_RIGHT:
            glutTimerFunc(100, update2, 0);
            break;
    }
    glutPostRedisplay();
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

void display() {
    glClearColor(0.016f, 0.016f, 0.016f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

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
    ///_____________________________________________ROCKET(START)___________________________________________________///
    glPushMatrix();
    glTranslatef(+0.38f, -0.38f, 0.0f);
    glTranslatef(0.0f,position3, 0.0f);
    glPushMatrix();
    glScalef(0.65,0.65,0);
    //glRotatef(30.0f,1.0,0.0,1.0);

    //glTranslatef(+0.9f, -0.02f, 0.0f);
///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,position2, 0.0f);
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
    ///_________ Fire main ________///

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
    glPopMatrix();
    glPopMatrix();
    ///........................................Earth
    glPushMatrix();
    glTranslatef(+0.42f, -0.15f, 0.0f);
    GLfloat A0=0.54f; GLfloat P0=0.32f; GLfloat O0 =0.27f;
    glColor3f(0.0f, 0.651f, 0.886f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0, P0); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0 + (O0 * cos(i *  twicePi/ triangleAmount)),
                        P0 + (O0 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///.........................Earth Inside Light Green-1
    ///1
     GLfloat A1=0.5f; GLfloat P1=0.5f; GLfloat O1 =0.06f;
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
    ///Border
    glLineWidth(3);
    GLfloat A29=0.54f; GLfloat P29=0.32f; GLfloat O29 =0.27f;
    glColor3f(0.016f, 0.016f, 0.016f);
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

	///..................................Moon.....................
	glPushMatrix();
	glTranslatef(0.39f,0.04f,0.0f);
    GLfloat A30=0.09f; GLfloat P30=0.9f; GLfloat O30 =0.13f;
    glColor3f(0.953f, 0.925f, 0.922f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A30, P30); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A30 + (O30 * cos(i *  twicePi / triangleAmount)),
                        P30 + (O30 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /*///Black Spot
    /// 1.
    GLfloat A33=0.07f; GLfloat P33=0.89f; GLfloat O33 =0.08f;
    glColor3f(0.62f, 0.588f, 0.573f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A33, P33); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A33 + (O33 * cos(i *  twicePi / triangleAmount)),
                        P33 + (O33 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 2.
    GLfloat A34=0.15f; GLfloat P34=0.9f; GLfloat O34 =0.06f;
    glColor3f(0.62f, 0.588f, 0.573f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A34, P34); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A34 + (O34 * cos(i *  twicePi / triangleAmount)),
                        P34 + (O34 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 3.
    GLfloat A35=0.11f; GLfloat P35=0.98f; GLfloat O35 =0.05f;
    glColor3f(0.62f, 0.588f, 0.573f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A35, P35); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A35 + (O35 * cos(i *  twicePi / triangleAmount)),
                        P35 + (O35 * sin(i * twicePi / triangleAmount)) );

        }
        glEnd();

    /// 4.
    GLfloat A36=0.04f; GLfloat P36=0.955f; GLfloat O36 =0.05f;
    glColor3f(0.62f, 0.588f, 0.573f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A36, P36); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A36 + (O36 * cos(i *  twicePi / triangleAmount)),
                        P36 + (O36 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();*/
    glPopMatrix();

    ///Planet...........Mars
    GLfloat A31=0.9f; GLfloat P31=0.75f; GLfloat O31 =0.035f;
    glColor3f(0.882f, 0.639f, 0.451f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A31, P31); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A31 + (O31 * cos(i *  twicePi/ triangleAmount)),
                        P31 + (O31 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    ///Planet...........Venus
    GLfloat A32=0.03f; GLfloat P32=0.95f; GLfloat O32 =0.035f;
    glColor3f(0.745f, 0.698f, 0.643f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A32, P32); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A32 + (O32 * cos(i *  twicePi/ triangleAmount)),
                        P32 + (O32 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("The Project : Rocket"); // Create a window with the given title
    ///glutFullScreen();
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);
    glutSpecialFunc(SpecialInput);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
