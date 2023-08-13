#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846


GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.001f;

int triangleAmount = 100; //# of lines used to draw circle
int lineAmount = 100;
GLfloat twicePi = 2.0f * PI;
int i;
GLfloat j = 0.0f;
GLfloat l = 0.0f;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

///___________________________________________________start___________________________________________________///
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


void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}


void display()
{
    glClearColor(0.11f, 0.271f, 0.49f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)



    glBegin(GL_QUADS);

///........................................................full screen................................................................................................
    glColor3f(0.11f, 0.27f, 0.49f);
    glVertex2f(0.0f,0.0f);
    //glColor3f(0.95f, 0.99f, 0.97f);
    glColor3f(0.125f, 0.278f, 0.431f);
    glVertex2f(0.0f,1.0f);
    //glColor3f(0.0f, 0.0f, 0.0f);
        glColor3f(0.125f, 0.278f, 0.431f);
    glVertex2f(1.0f,1.0f);
    glColor3f(0.11f, 0.27f, 0.49f);
    glVertex2f(1.0f,0.0f);

///1

    glColor3f(0.125f, 0.278f, 0.431f);
    glVertex2f(0.0f,0.65f);
    glColor3f(0.0589f, 0.141f, 0.239f);
    glVertex2f(0.0f,0.60f);
    glColor3f(0.0589f, 0.141f, 0.239f);
    glVertex2f(1.0f,0.60f);
    glColor3f(0.125f, 0.278f, 0.431f);
    glVertex2f(1.0f,0.65f);
///1
    glColor3f(0.067, 0.224f, 0.4f);
    glVertex2f(0.0f,0.55f);
    glColor3f(0.0589f, 0.141f, 0.239f);
    glVertex2f(0.0f,0.60f);
    glColor3f(0.0589f, 0.141f, 0.239f);
    glVertex2f(1.0f,0.60f);
    glColor3f(0.067f, 0.234f, 0.4f);
    glVertex2f(1.0f,0.55f);

///2
    //glColor3f(0.463f, 0.627f, 0.811f);
    glColor3f(0.251f, 0.502f, 0.788f);
    glVertex2f(0.0f,0.50f);
    glColor3f(0.067f, 0.234f, 0.4f);
    glVertex2f(0.0f,0.55f);
    glColor3f(0.067f, 0.234f, 0.4f);
    glVertex2f(1.0f,0.55f);
    glColor3f(0.251f, 0.502f, 0.788f);
    //glColor3f(0.463f, 0.627f, 0.811f);
    glVertex2f(1.0f,0.50f);

///3
    glColor3f(0.302f, 0.541f, 0.82f);
    glVertex2f(0.0f,0.45f);
    glColor3f(0.251f, 0.502f, 0.788f);
    glVertex2f(0.0f,0.50f);
    glColor3f(0.251f, 0.502f, 0.788f);
    glVertex2f(1.0f,0.50f);
    glColor3f(0.302f, 0.541f, 0.82f);
    glVertex2f(1.0f,0.45f);

///4
    glColor3f(0.443f, 0.643f, 0.871f);
    glVertex2f(0.0f,0.40f);
    glColor3f(0.302f, 0.541f, 0.82f);
    glVertex2f(0.0f,0.45f);
    glColor3f(0.302f, 0.541f, 0.82f);
    glVertex2f(1.0f,0.45f);
    glColor3f(0.443f, 0.643f, 0.871f);
    glVertex2f(1.0f,0.40f);


///5
    glColor3f(0.15f, 0.30f, 0.51f);
    glVertex2f(0.0f,0.10f);
    glColor3f(0.443f, 0.643f, 0.871f);
    glVertex2f(0.0f,0.40f);
    glColor3f(0.443f, 0.643f, 0.871f);
    glVertex2f(1.0f,0.40f);
    glColor3f(0.15f, 0.30f, 0.51f);
    glVertex2f(1.0f,0.10f);
    glEnd();

///.......................MINI STARS...............................................

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    ///1
    glVertex2f(0.10f, 0.90f);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.35f, 0.99f);
    glVertex2f(0.50f, 0.80f);
    glVertex2f(0.90f, 0.90f);
    glVertex2f(0.77f, 0.77f);
    glVertex2f(0.67f, 0.95f);
    glVertex2f(0.02f, 0.75f);
    glVertex2f(0.04f, 0.90f);
    glVertex2f(0.12f, 0.77f);
    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.18f, 0.750f);
    glVertex2f(0.20f, 0.99f);
    glVertex2f(0.22f, 0.96f);
    glVertex2f(0.24f, 0.95f);
    glVertex2f(0.02f, 0.99f);
    glVertex2f(0.04f, 0.98f);
    glVertex2f(0.06f, 0.98f);
    glVertex2f(0.08f, 0.99f);
    glVertex2f(0.10f, 0.98f);
    glVertex2f(0.12f, 0.99f);
    glVertex2f(0.14f, 0.98f);
    glVertex2f(0.16f, 0.99f);
    glVertex2f(0.18f, 0.98f);
    glVertex2f(0.20f, 0.99f);
    glVertex2f(0.22f, 0.98f);
    glVertex2f(0.24f, 0.99f);
    glVertex2f(0.26f, 0.98f);
    glVertex2f(0.28f, 0.99f);
    glVertex2f(0.30f, 0.98f);
    glVertex2f(0.32f, 0.99f);
    glVertex2f(0.34f, 0.98f);
    glVertex2f(0.36f, 0.99f);
    glVertex2f(0.38f, 0.98f);
    glVertex2f(0.40f, 0.99f);
    glVertex2f(0.42f, 0.98f);
    glVertex2f(0.44f, 0.99f);
    glVertex2f(0.46f, 0.98);
    glVertex2f(0.48f, 0.99f);
    glVertex2f(0.50f, 0.98f);
    glVertex2f(0.52f, 0.99f);
    glVertex2f(0.54f, 0.98f);
    glVertex2f(0.56f, 0.99f);
    glVertex2f(0.58f, 0.98f);
    glVertex2f(0.60f, 0.99f);
    glVertex2f(0.62f, 0.98f);
    glVertex2f(0.64f, 0.99f);
    glVertex2f(0.68f, 0.98f);
    glVertex2f(0.70f, 0.99f);
    glVertex2f(0.72f, 0.98f);
    glVertex2f(0.74f, 0.99f);
    glVertex2f(0.76f, 0.98f);
    glVertex2f(0.78f, 0.99f);
    glVertex2f(0.80f, 0.98f);
    glVertex2f(0.82f, 0.99f);
    glVertex2f(0.84f, 0.98f);
    glVertex2f(0.86f, 0.99f);
    glVertex2f(0.88f, 0.98f);
    glVertex2f(0.90f, 0.99f);
    glVertex2f(0.92f, 0.98f);
    glVertex2f(0.94f, 0.99f);
    glVertex2f(0.96f, 0.98f);
    glVertex2f(0.98f, 0.99f);
    glVertex2f(1.0f, 0.98f);
    ///2
    glVertex2f(0.01f, 0.96f);
    glVertex2f(0.03f, 0.97f);
    glVertex2f(0.05f, 0.96f);
    glVertex2f(0.07f, 0.97f);
    glVertex2f(0.09f, 0.96f);
    glVertex2f(0.11f, 0.97f);
    glVertex2f(0.13f, 0.96f);
    glVertex2f(0.15f, 0.97f);
    glVertex2f(0.17f, 0.96f);
    glVertex2f(0.19f, 0.97f);
    glVertex2f(0.21f, 0.96f);
    glVertex2f(0.23f, 0.97f);
    glVertex2f(0.25f, 0.96f);
    glVertex2f(0.27f, 0.97f);
    glVertex2f(0.29f, 0.96f);
    ///3
    glVertex2f(0.01f, 0.88f);
    glVertex2f(0.03f, 0.89f);
    glVertex2f(0.05f, 0.88f);
    glVertex2f(0.07f, 0.89f);
    glVertex2f(0.09f, 0.88f);
    glVertex2f(0.11f, 0.89f);
    glVertex2f(0.13f, 0.88f);
    glVertex2f(0.15f, 0.89f);
    glVertex2f(0.17f, 0.88f);
    glVertex2f(0.19f, 0.89f);
    glVertex2f(0.21f, 0.88f);
    glVertex2f(0.23f, 0.89f);
    glVertex2f(0.25f, 0.88f);
    glVertex2f(0.27f, 0.89f);
    glVertex2f(0.29f, 0.88f);
    glVertex2f(0.31f, 0.88f);
    glVertex2f(0.33f, 0.89f);
    glVertex2f(0.35f, 0.88f);
    glVertex2f(0.37f, 0.89f);
    glVertex2f(0.39f, 0.88f);
    glVertex2f(0.41f, 0.89f);
    glVertex2f(0.43f, 0.88f);
    glVertex2f(0.45f, 0.89f);
    glVertex2f(0.47f, 0.88f);
    glVertex2f(0.49f, 0.89f);
    glVertex2f(0.51f, 0.88f);
    glVertex2f(0.53f, 0.89f);
    glVertex2f(0.55f, 0.88f);
    glVertex2f(0.57f, 0.89f);
    glVertex2f(0.59f, 0.88f);
    glVertex2f(0.61f, 0.89f);
    glVertex2f(0.63f, 0.88f);
    glVertex2f(0.65f, 0.89f);
    glVertex2f(0.67f, 0.88f);
    glVertex2f(0.69f, 0.89f);
    glVertex2f(0.71f, 0.88f);
    glVertex2f(0.73f, 0.89f);
    glVertex2f(0.75f, 0.88f);
    glVertex2f(0.77f, 0.89f);
    glVertex2f(0.79f, 0.88f);
    glVertex2f(0.81f, 0.89f);
    glVertex2f(0.83f, 0.88f);
    glVertex2f(0.85f, 0.89f);
    glVertex2f(0.87f, 0.88f);
    glVertex2f(0.89f, 0.89f);
    glVertex2f(0.91f, 0.88f);
    glVertex2f(0.93f, 0.89f);
    glVertex2f(0.95f, 0.88f);
    glVertex2f(0.97f, 0.89f);
    glVertex2f(0.99f, 0.88f);
    ///5
    glVertex2f(0.01f, 0.82f);
    glVertex2f(0.03f, 0.83f);
    glVertex2f(0.05f, 0.82f);
    glVertex2f(0.07f, 0.83f);
    glVertex2f(0.09f, 0.82f);
    glVertex2f(0.11f, 0.83f);
    glVertex2f(0.13f, 0.82f);
    glVertex2f(0.15f, 0.83f);
    glVertex2f(0.17f, 0.82f);
    glVertex2f(0.19f, 0.83f);
    glVertex2f(0.21f, 0.82f);
    glVertex2f(0.23f, 0.83f);
    glVertex2f(0.25f, 0.82f);
    glVertex2f(0.27f, 0.83f);
    glVertex2f(0.29f, 0.82f);
    glVertex2f(0.31f, 0.83f);
    glVertex2f(0.33f, 0.82f);
    glVertex2f(0.35f, 0.83f);
    glVertex2f(0.37f, 0.82f);
    glVertex2f(0.39f, 0.83f);
    glVertex2f(0.41f, 0.82f);
    glVertex2f(0.43f, 0.83f);
    glVertex2f(0.45f, 0.82f);
    glVertex2f(0.47f, 0.83f);
    glVertex2f(0.49f, 0.82f);
    glVertex2f(0.51f, 0.83f);
    glVertex2f(0.53f, 0.82f);
    glVertex2f(0.55f, 0.83f);
    glVertex2f(0.57f, 0.82f);
    glVertex2f(0.59f, 0.83f);
    glVertex2f(0.61f, 0.82f);
    glVertex2f(0.63f, 0.83f);
    glVertex2f(0.65f, 0.82f);
    glVertex2f(0.67f, 0.83f);
    glVertex2f(0.69f, 0.82f);
    glVertex2f(0.71f, 0.83f);
    glVertex2f(0.73f, 0.82f);
    glVertex2f(0.75f, 0.83f);
    glVertex2f(0.77f, 0.82f);
    glVertex2f(0.79f, 0.83f);
    glVertex2f(0.81f, 0.82f);
    glVertex2f(0.83f, 0.83f);
    glVertex2f(0.85f, 0.82f);
    glVertex2f(0.87f, 0.83f);
    glVertex2f(0.89f, 0.82f);
    glVertex2f(0.91f, 0.83f);
    glVertex2f(0.93f, 0.82f);
    glVertex2f(0.95f, 0.83f);
    glVertex2f(0.97f, 0.82f);
    glVertex2f(0.99f, 0.83f);
    ///6
    glVertex2f(0.02f, 0.79f);
    glVertex2f(0.04f, 0.78f);
    glVertex2f(0.06f, 0.79f);
    glVertex2f(0.08f, 0.78f);
    glVertex2f(0.10f, 0.79f);
    glVertex2f(0.12f, 0.78f);
    glVertex2f(0.14f, 0.79f);
    glVertex2f(0.16f, 0.78f);
    glVertex2f(0.18f, 0.79f);
    glVertex2f(0.20f, 0.78f);
    glVertex2f(0.22f, 0.79f);
    glVertex2f(0.24f, 0.78f);
    glVertex2f(0.26f, 0.79f);
    glVertex2f(0.28f, 0.78f);
    glVertex2f(0.30f, 0.79f);
    glVertex2f(0.32f, 0.78f);
    glVertex2f(0.34f, 0.79f);
    glVertex2f(0.36f, 0.78f);
    glVertex2f(0.38f, 0.79f);
    glVertex2f(0.40f, 0.78f);
    glVertex2f(0.42f, 0.79f);
    glVertex2f(0.44f, 0.78f);
    glVertex2f(0.46f, 0.79f);
    glVertex2f(0.48f, 0.78f);
    glVertex2f(0.50f, 0.79f);
    glVertex2f(0.52f, 0.78f);
    glVertex2f(0.54f, 0.79f);
    glVertex2f(0.56f, 0.78f);
    glVertex2f(0.58f, 0.79f);
    glVertex2f(0.60f, 0.78f);
    glVertex2f(0.62f, 0.79f);
    glVertex2f(0.64f, 0.78f);
    glVertex2f(0.66f, 0.79f);
    glVertex2f(0.68f, 0.78f);
    glVertex2f(0.70f, 0.79f);
    glVertex2f(0.72f, 0.78f);
    glVertex2f(0.74f, 0.79f);
    glVertex2f(0.76f, 0.78f);
    glVertex2f(0.78f, 0.79f);
    glVertex2f(0.80f, 0.78f);
    glVertex2f(0.82f, 0.79f);
    glVertex2f(0.84f, 0.78f);
    glVertex2f(0.86f, 0.79f);
    glVertex2f(0.88f, 0.78f);
    glVertex2f(0.90f, 0.79f);
    glVertex2f(0.92f, 0.78f);
    glVertex2f(0.94f, 0.79f);
    glVertex2f(0.96f, 0.78f);
    glVertex2f(0.98f, 0.79f);
    glVertex2f(1.0f, 0.78f);
    ///8
    glVertex2f(0.02f, 0.71f);
    glVertex2f(0.04f, 0.70f);
    glVertex2f(0.06f, 0.71f);
    glVertex2f(0.08f, 0.70f);
    glVertex2f(0.10f, 0.71f);
    glVertex2f(0.12f, 0.70f);
    glVertex2f(0.14f, 0.71f);
    glVertex2f(0.16f, 0.70f);
    glVertex2f(0.18f, 0.71f);
    glVertex2f(0.20f, 0.70f);
    glVertex2f(0.22f, 0.71f);
    glVertex2f(0.24f, 0.70f);
    glVertex2f(0.26f, 0.71f);
    glVertex2f(0.28f, 0.70f);
    glVertex2f(0.30f, 0.71f);
    glVertex2f(0.32f, 0.70f);
    glVertex2f(0.34f, 0.71f);
    glVertex2f(0.36f, 0.70f);
    glVertex2f(0.38f, 0.71f);
    glVertex2f(0.40f, 0.70f);
    glVertex2f(0.42f, 0.71f);
    glVertex2f(0.44f, 0.70f);
    glVertex2f(0.46f, 0.71f);
    glVertex2f(0.48f, 0.70f);
    glVertex2f(0.50f, 0.71f);
    glVertex2f(0.52f, 0.70f);
    glVertex2f(0.54f, 0.71f);
    glVertex2f(0.56f, 0.70f);
    glVertex2f(0.58f, 0.70f);
    glVertex2f(0.60f, 0.71f);
    glVertex2f(0.62f, 0.70f);
    glVertex2f(0.64f, 0.71f);
    glVertex2f(0.66f, 0.70f);
    glVertex2f(0.68f, 0.71f);
    glVertex2f(0.70f, 0.70f);
    glVertex2f(0.72f, 0.71f);
    glVertex2f(0.74f, 0.70f);
    glVertex2f(0.76f, 0.71f);
    glVertex2f(0.78f, 0.70f);
    glVertex2f(0.80f, 0.70f);
    glVertex2f(0.82f, 0.71f);
    glVertex2f(0.84f, 0.70f);
    glVertex2f(0.86f, 0.71f);
    glVertex2f(0.88f, 0.70f);
    glVertex2f(0.90f, 0.71f);
    glVertex2f(0.92f, 0.70f);
    glVertex2f(0.94f, 0.71f);
    glVertex2f(0.96f, 0.70f);
    glVertex2f(0.98f, 0.71f);
    glVertex2f(1.0f, 0.70f);

glEnd();
    ///7
      glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2f(0.01f, 0.75f);
    glVertex2f(0.03f, 0.74f);
    glVertex2f(0.05f, 0.75f);
    glVertex2f(0.07f, 0.74f);
    glVertex2f(0.09f, 0.75f);
    glVertex2f(0.11f, 0.74f);
    glVertex2f(0.13f, 0.75f);
    glVertex2f(0.15f, 0.74f);
    glVertex2f(0.17f, 0.75f);
    glVertex2f(0.19f, 0.74f);
    glVertex2f(0.21f, 0.75f);
    glVertex2f(0.23f, 0.74f);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.27f, 0.74f);
    glVertex2f(0.29f, 0.75f);
    glVertex2f(0.31f, 0.74f);
    glVertex2f(0.33f, 0.75f);
    glVertex2f(0.35f, 0.74f);
    glVertex2f(0.37f, 0.75f);
    glVertex2f(0.39f, 0.74f);
    glVertex2f(0.41f, 0.75f);
    glVertex2f(0.43f, 0.74f);
    glVertex2f(0.45f, 0.75f);
    glVertex2f(0.47f, 0.74f);
    glVertex2f(0.49f, 0.75f);
    glVertex2f(0.51f, 0.74f);
    glVertex2f(0.53f, 0.75f);
    glVertex2f(0.55f, 0.74f);
    glVertex2f(0.57f, 0.75f);
    glVertex2f(0.59f, 0.74f);
    glVertex2f(0.61f, 0.75f);
    glVertex2f(0.63f, 0.74f);
    glVertex2f(0.65f, 0.75f);
    glVertex2f(0.67f, 0.74f);
    glVertex2f(0.69f, 0.75f);
    glVertex2f(0.71f, 0.74f);
    glVertex2f(0.73f, 0.75f);
    glVertex2f(0.75f, 0.74f);
    glVertex2f(0.77f, 0.75f);
    glVertex2f(0.79f, 0.74f);
    glVertex2f(0.81f, 0.75f);
    glVertex2f(0.83f, 0.74f);
    glVertex2f(0.85f, 0.75f);
    glVertex2f(0.87f, 0.74f);
    glVertex2f(0.89f, 0.75f);
    glVertex2f(0.91f, 0.74f);
    glVertex2f(0.93f, 0.75f);
    glVertex2f(0.95f, 0.74f);
    glVertex2f(0.97f, 0.75f);
    glVertex2f(0.99f, 0.74f);
    glEnd();



    glPointSize(1);
    glBegin(GL_POINTS);
    ///9
    glVertex2f(0.10f, 0.90f);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.35f, 0.99f);
    glVertex2f(0.50f, 0.80f);
    glVertex2f(0.90f, 0.90f);
    glVertex2f(0.77f, 0.77f);
    glVertex2f(0.67f, 0.95f);
    glVertex2f(0.02f, 0.75f);
    glVertex2f(0.04f, 0.90f);
    glVertex2f(0.12f, 0.77f);
    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.18f, 0.750f);
    glVertex2f(0.20f, 0.99f);
    glVertex2f(0.22f, 0.96f);
    glVertex2f(0.24f, 0.95f);
///10
    glVertex2f(0.02f, 0.99f);
    glVertex2f(0.04f, 0.98f);
    glVertex2f(0.06f, 0.98f);
    glVertex2f(0.08f, 0.99f);
    glVertex2f(0.10f, 0.98f);
    glVertex2f(0.12f, 0.99f);
    glVertex2f(0.14f, 0.98f);
    glVertex2f(0.16f, 0.99f);
    glVertex2f(0.18f, 0.98f);
    glVertex2f(0.20f, 0.99f);
    glVertex2f(0.22f, 0.98f);
    glVertex2f(0.24f, 0.99f);
    glVertex2f(0.26f, 0.98f);
    glVertex2f(0.28f, 0.99f);
    glVertex2f(0.30f, 0.98f);
    glVertex2f(0.32f, 0.99f);
    glVertex2f(0.34f, 0.98f);
    glVertex2f(0.36f, 0.99f);
    glVertex2f(0.38f, 0.98f);
    glVertex2f(0.40f, 0.99f);
    glVertex2f(0.42f, 0.98f);
    glVertex2f(0.44f, 0.99f);
    glVertex2f(0.46f, 0.98);
    glVertex2f(0.48f, 0.99f);
    glVertex2f(0.50f, 0.98f);
    glVertex2f(0.52f, 0.99f);
    glVertex2f(0.54f, 0.98f);
    glVertex2f(0.56f, 0.99f);
    glVertex2f(0.58f, 0.98f);
    glVertex2f(0.60f, 0.99f);
    glVertex2f(0.62f, 0.98f);
    glVertex2f(0.64f, 0.99f);
    glVertex2f(0.68f, 0.98f);
    glVertex2f(0.70f, 0.99f);
    glVertex2f(0.72f, 0.98f);
    glVertex2f(0.74f, 0.99f);
    glVertex2f(0.76f, 0.98f);
    glVertex2f(0.78f, 0.99f);
    glVertex2f(0.80f, 0.98f);
    glVertex2f(0.82f, 0.99f);
    glVertex2f(0.84f, 0.98f);
    glVertex2f(0.86f, 0.99f);
    glVertex2f(0.88f, 0.98f);
    glVertex2f(0.90f, 0.99f);
    glVertex2f(0.92f, 0.98f);
    glVertex2f(0.94f, 0.99f);
    glVertex2f(0.96f, 0.98f);
    glVertex2f(0.98f, 0.99f);
    glVertex2f(1.0f, 0.98f);
///11
    glVertex2f(0.01f, 0.96f);
    glVertex2f(0.03f, 0.97f);
    glVertex2f(0.05f, 0.96f);
    glVertex2f(0.07f, 0.97f);
    glVertex2f(0.09f, 0.96f);
    glVertex2f(0.11f, 0.97f);
    glVertex2f(0.13f, 0.96f);
    glVertex2f(0.15f, 0.97f);
    glVertex2f(0.17f, 0.96f);
    glVertex2f(0.19f, 0.97f);
    glVertex2f(0.21f, 0.96f);
    glVertex2f(0.23f, 0.97f);
    glVertex2f(0.25f, 0.96f);
    glVertex2f(0.27f, 0.97f);
    glVertex2f(0.29f, 0.96f);
    glVertex2f(0.31f, 0.96f);
    glVertex2f(0.33f, 0.97f);
    glVertex2f(0.35f, 0.96f);
    glVertex2f(0.37f, 0.97f);
    glVertex2f(0.39f, 0.96f);
    glVertex2f(0.41f, 0.97f);
    glVertex2f(0.43f, 0.96f);
    glVertex2f(0.45f, 0.97f);
    glVertex2f(0.47f, 0.96f);
    glVertex2f(0.49f, 0.97f);
    glVertex2f(0.51f, 0.96f);
    glVertex2f(0.53f, 0.97f);
    glVertex2f(0.55f, 0.96f);
    glVertex2f(0.57f, 0.97f);
    glVertex2f(0.59f, 0.96f);
    glVertex2f(0.61f, 0.96f);
    glVertex2f(0.63f, 0.97f);
    glVertex2f(0.65f, 0.96f);
    glVertex2f(0.67f, 0.97f);
    glVertex2f(0.69f, 0.96f);
    glVertex2f(0.71f, 0.97f);
    glVertex2f(0.73f, 0.96f);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.77f, 0.96f);
    glVertex2f(0.79f, 0.97f);
    glVertex2f(0.81f, 0.96f);
    glVertex2f(0.83f, 0.97f);
    glVertex2f(0.85f, 0.96f);
    glVertex2f(0.87f, 0.97f);
    glVertex2f(0.89f, 0.96f);
    glVertex2f(0.91f, 0.96f);
    glVertex2f(0.93f, 0.97f);
    glVertex2f(0.95f, 0.96f);
    glVertex2f(0.97f, 0.97f);
    glVertex2f(0.99f, 0.96f);
///12
    glVertex2f(0.02f, 0.95f);
    glVertex2f(0.04f, 0.94f);
    glVertex2f(0.06f, 0.95f);
    glVertex2f(0.08f, 0.94f);
    glVertex2f(0.10f, 0.95f);
    glVertex2f(0.12f, 0.94f);
    glVertex2f(0.14f, 0.95f);
    glVertex2f(0.16f, 0.94f);
    glVertex2f(0.18f, 0.95f);
    glVertex2f(0.20f, 0.94f);
    glVertex2f(0.22f, 0.94f);
    glVertex2f(0.24f, 0.95f);
    glVertex2f(0.26f, 0.94f);
    glVertex2f(0.28f, 0.95f);
    glVertex2f(0.30f, 0.94f);
    glVertex2f(0.32f, 0.94f);
    glVertex2f(0.34f, 0.95f);
    glVertex2f(0.36f, 0.94f);
    glVertex2f(0.38f, 0.95f);
    glVertex2f(0.40f, 0.94f);
    glVertex2f(0.42f, 0.94f);
    glVertex2f(0.44f, 0.95f);
    glVertex2f(0.46f, 0.94f);
    glVertex2f(0.48f, 0.95f);
    glVertex2f(0.50f, 0.94f);
    glVertex2f(0.52f, 0.94f);
    glVertex2f(0.54f, 0.95f);
    glVertex2f(0.56f, 0.94f);
    glVertex2f(0.58f, 0.95f);
    glVertex2f(0.60f, 0.94f);
    glVertex2f(0.62f, 0.94f);
    glVertex2f(0.64f, 0.95f);
    glVertex2f(0.66f, 0.94f);
    glVertex2f(0.68f, 0.95f);
    glVertex2f(0.70f, 0.94f);
    glVertex2f(0.72f, 0.94f);
    glVertex2f(0.74f, 0.95f);
    glVertex2f(0.76f, 0.94f);
    glVertex2f(0.78f, 0.95f);
    glVertex2f(0.80f, 0.94f);
    glVertex2f(0.82f, 0.94f);
    glVertex2f(0.84f, 0.95f);
    glVertex2f(0.86f, 0.94f);
    glVertex2f(0.88f, 0.95f);
    glVertex2f(0.90f, 0.94f);
    glVertex2f(0.92f, 0.94f);
    glVertex2f(0.94f, 0.95f);
    glVertex2f(0.96f, 0.94f);
    glVertex2f(0.98f, 0.95f);
    glVertex2f(1.0f, 0.94f);
///13
    glVertex2f(0.01f, 0.93f);
    glVertex2f(0.03f, 0.92f);
    glVertex2f(0.05f, 0.93f);
    glVertex2f(0.07f, 0.92f);
    glVertex2f(0.09f, 0.93f);
    glVertex2f(0.11f, 0.92f);
    glVertex2f(0.13f, 0.93f);
    glVertex2f(0.15f, 0.92f);
    glVertex2f(0.17f, 0.93f);
    glVertex2f(0.19f, 0.92f);
    glVertex2f(0.21f, 0.93f);
    glVertex2f(0.23f, 0.92f);
    glVertex2f(0.25f, 0.93f);
    glVertex2f(0.27f, 0.92f);
    glVertex2f(0.29f, 0.93f);
    glVertex2f(0.31f, 0.92f);
    glVertex2f(0.33f, 0.93f);
    glVertex2f(0.35f, 0.92f);
    glVertex2f(0.37f, 0.93f);
    glVertex2f(0.39f, 0.92f);
    glVertex2f(0.41f, 0.93f);
    glVertex2f(0.43f, 0.92f);
    glVertex2f(0.45f, 0.93f);
    glVertex2f(0.47f, 0.92f);
    glVertex2f(0.49f, 0.93f);
    glVertex2f(0.51f, 0.92f);
    glVertex2f(0.53f, 0.93f);
    glVertex2f(0.55f, 0.92f);
    glVertex2f(0.57f, 0.93f);
    glVertex2f(0.59f, 0.92f);
    glVertex2f(0.61f, 0.93f);
    glVertex2f(0.63f, 0.92f);
    glVertex2f(0.65f, 0.93f);
    glVertex2f(0.67f, 0.92f);
    glVertex2f(0.69f, 0.93f);
    glVertex2f(0.71f, 0.92f);
    glVertex2f(0.73f, 0.93f);
    glVertex2f(0.75f, 0.92f);
    glVertex2f(0.77f, 0.93f);
    glVertex2f(0.79f, 0.92f);
    glVertex2f(0.81f, 0.93f);
    glVertex2f(0.83f, 0.92f);
    glVertex2f(0.85f, 0.93f);
    glVertex2f(0.87f, 0.92f);
    glVertex2f(0.89f, 0.93f);
    glVertex2f(0.91f, 0.92f);
    glVertex2f(0.93f, 0.93f);
    glVertex2f(0.95f, 0.92f);
    glVertex2f(0.97f, 0.93f);
    glVertex2f(0.99f, 0.92f);
///14
    glVertex2f(0.02f, 0.91f);
    glVertex2f(0.04f, 0.90f);
    glVertex2f(0.06f, 0.91f);
    glVertex2f(0.08f, 0.90f);
    glVertex2f(0.10f, 0.91f);
    glVertex2f(0.12f, 0.90f);
    glVertex2f(0.14f, 0.91f);
    glVertex2f(0.16f, 0.90f);
    glVertex2f(0.18f, 0.91f);
    glVertex2f(0.20f, 0.90f);
    glVertex2f(0.22f, 0.91f);
    glVertex2f(0.24f, 0.90f);
    glVertex2f(0.26f, 0.91f);
    glVertex2f(0.28f, 0.90f);
    glVertex2f(0.30f, 0.91f);
    glVertex2f(0.32f, 0.90f);
    glVertex2f(0.34f, 0.91f);
    glVertex2f(0.36f, 0.90f);
    glVertex2f(0.38f, 0.91f);
    glVertex2f(0.40f, 0.90f);
    glVertex2f(0.42f, 0.91f);
    glVertex2f(0.44f, 0.90f);
    glVertex2f(0.46f, 0.91f);
    glVertex2f(0.48f, 0.90f);
    glVertex2f(0.50f, 0.91f);
    glVertex2f(0.52f, 0.90f);
    glVertex2f(0.54f, 0.91f);
    glVertex2f(0.56f, 0.90f);
    glVertex2f(0.58f, 0.90f);
    glVertex2f(0.60f, 0.91f);
    glVertex2f(0.62f, 0.90f);
    glVertex2f(0.64f, 0.91f);
    glVertex2f(0.66f, 0.90f);
    glVertex2f(0.68f, 0.91f);
    glVertex2f(0.70f, 0.90f);
    glVertex2f(0.72f, 0.91f);
    glVertex2f(0.74f, 0.90f);
    glVertex2f(0.76f, 0.91f);
    glVertex2f(0.78f, 0.90f);
    glVertex2f(0.80f, 0.90f);
    glVertex2f(0.82f, 0.91f);
    glVertex2f(0.84f, 0.90f);
    glVertex2f(0.86f, 0.91f);
    glVertex2f(0.88f, 0.90f);
    glVertex2f(0.90f, 0.91f);
    glVertex2f(0.92f, 0.90f);
    glVertex2f(0.94f, 0.91f);
    glVertex2f(0.96f, 0.90f);
    glVertex2f(0.98f, 0.91f);
    glVertex2f(1.0f, 0.90f);
        ///4
    glVertex2f(0.01f, 0.85f);
    glVertex2f(0.03f, 0.84f);
    glVertex2f(0.05f, 0.85f);
    glVertex2f(0.07f, 0.84f);
    glVertex2f(0.09f, 0.85f);
    glVertex2f(0.11f, 0.84f);
    glVertex2f(0.13f, 0.85f);
    glVertex2f(0.15f, 0.84f);
    glVertex2f(0.17f, 0.85f);
    glVertex2f(0.19f, 0.84f);
    glVertex2f(0.21f, 0.85f);
    glVertex2f(0.23f, 0.84f);
    glVertex2f(0.25f, 0.85f);
    glVertex2f(0.27f, 0.84f);
    glVertex2f(0.29f, 0.85f);
    glVertex2f(0.31f, 0.84f);
    glVertex2f(0.33f, 0.85f);
    glVertex2f(0.35f, 0.84f);
    glVertex2f(0.37f, 0.85f);
    glVertex2f(0.39f, 0.84f);
    glVertex2f(0.41f, 0.85f);
    glVertex2f(0.43f, 0.84f);
    glVertex2f(0.45f, 0.85f);
    glVertex2f(0.47f, 0.84f);
    glVertex2f(0.49f, 0.85f);
    glVertex2f(0.51f, 0.84f);
    glVertex2f(0.53f, 0.85f);
    glVertex2f(0.55f, 0.84f);
    glVertex2f(0.57f, 0.85f);
    glVertex2f(0.59f, 0.84f);
    glVertex2f(0.61f, 0.85f);
    glVertex2f(0.63f, 0.84f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.67f, 0.84f);
    glVertex2f(0.69f, 0.85f);
    glVertex2f(0.71f, 0.84f);
    glVertex2f(0.73f, 0.85f);
    glVertex2f(0.75f, 0.84f);
    glVertex2f(0.77f, 0.85f);
    glVertex2f(0.79f, 0.84f);
    glVertex2f(0.81f, 0.85f);
    glVertex2f(0.83f, 0.84f);
    glVertex2f(0.85f, 0.85f);
    glVertex2f(0.87f, 0.84f);
    glVertex2f(0.89f, 0.85f);
    glVertex2f(0.91f, 0.84f);
    glVertex2f(0.93f, 0.85f);
    glVertex2f(0.95f, 0.84f);
    glVertex2f(0.97f, 0.85f);
    glVertex2f(0.99f, 0.84f);

///15
    glVertex2f(0.02f, 0.81f);
    glVertex2f(0.04f, 0.80f);
    glVertex2f(0.06f, 0.81f);
    glVertex2f(0.08f, 0.80f);
    glVertex2f(0.10f, 0.81f);
    glVertex2f(0.12f, 0.80f);
    glVertex2f(0.14f, 0.81f);
    glVertex2f(0.16f, 0.80f);
    glVertex2f(0.18f, 0.81f);
    glVertex2f(0.20f, 0.80f);
    glVertex2f(0.22f, 0.81f);
    glVertex2f(0.24f, 0.80f);
    glVertex2f(0.26f, 0.81f);
    glVertex2f(0.28f, 0.80f);
    glVertex2f(0.30f, 0.81f);
    glVertex2f(0.32f, 0.80f);
    glVertex2f(0.34f, 0.81f);
    glVertex2f(0.36f, 0.80f);
    glVertex2f(0.38f, 0.81f);
    glVertex2f(0.40f, 0.80f);
    glVertex2f(0.42f, 0.81f);
    glVertex2f(0.44f, 0.80f);
    glVertex2f(0.46f, 0.81f);
    glVertex2f(0.48f, 0.80f);
    glVertex2f(0.50f, 0.81f);
    glVertex2f(0.52f, 0.80f);
    glVertex2f(0.54f, 0.81f);
    glVertex2f(0.56f, 0.80f);
    glVertex2f(0.58f, 0.80f);
    glVertex2f(0.60f, 0.81f);
    glVertex2f(0.62f, 0.80f);
    glVertex2f(0.64f, 0.81f);
    glVertex2f(0.66f, 0.80f);
    glVertex2f(0.68f, 0.81f);
    glVertex2f(0.70f, 0.80f);
    glVertex2f(0.72f, 0.81f);
    glVertex2f(0.74f, 0.80f);
    glVertex2f(0.76f, 0.81f);
    glVertex2f(0.78f, 0.80f);
    glVertex2f(0.80f, 0.80f);
    glVertex2f(0.82f, 0.81f);
    glVertex2f(0.84f, 0.80f);
    glVertex2f(0.86f, 0.81f);
    glVertex2f(0.88f, 0.80f);
    glVertex2f(0.90f, 0.81f);
    glVertex2f(0.92f, 0.80f);
    glVertex2f(0.94f, 0.81f);
    glVertex2f(0.96f, 0.80f);
    glVertex2f(0.98f, 0.81f);
    glVertex2f(1.0f, 0.80f);
///16
    glVertex2f(0.02f, 0.86f);
    glVertex2f(0.04f, 0.87f);
    glVertex2f(0.06f, 0.86f);
    glVertex2f(0.08f, 0.87f);
    glVertex2f(0.10f, 0.86f);
    glVertex2f(0.12f, 0.87f);
    glVertex2f(0.14f, 0.86f);
    glVertex2f(0.16f, 0.87f);
    glVertex2f(0.18f, 0.86f);
    glVertex2f(0.20f, 0.87f);
    glVertex2f(0.22f, 0.86f);
    glVertex2f(0.24f, 0.87f);
    glVertex2f(0.26f, 0.86f);
    glVertex2f(0.28f, 0.87f);
    glVertex2f(0.30f, 0.86f);
    glVertex2f(0.32f, 0.87f);
    glVertex2f(0.34f, 0.86f);
    glVertex2f(0.36f, 0.87f);
    glVertex2f(0.38f, 0.86f);
    glVertex2f(0.40f, 0.87f);
    glVertex2f(0.42f, 0.86f);
    glVertex2f(0.44f, 0.87f);
    glVertex2f(0.46f, 0.86f);
    glVertex2f(0.48f, 0.87f);
    glVertex2f(0.50f, 0.86f);
    glVertex2f(0.52f, 0.87f);
    glVertex2f(0.54f, 0.86f);
    glVertex2f(0.56f, 0.87f);
    glVertex2f(0.58f, 0.86f);
    glVertex2f(0.60f, 0.87f);
    glVertex2f(0.62f, 0.86f);
    glVertex2f(0.64f, 0.87f);
    glVertex2f(0.66f, 0.86f);
    glVertex2f(0.68f, 0.87f);
    glVertex2f(0.70f, 0.86f);
    glVertex2f(0.72f, 0.87f);
    glVertex2f(0.74f, 0.86f);
    glVertex2f(0.76f, 0.87f);
    glVertex2f(0.78f, 0.86f);
    glVertex2f(0.80f, 0.86f);
    glVertex2f(0.82f, 0.87f);
    glVertex2f(0.84f, 0.86f);
    glVertex2f(0.86f, 0.87f);
    glVertex2f(0.88f, 0.86f);
    glVertex2f(0.90f, 0.87f);
    glVertex2f(0.92f, 0.86f);
    glVertex2f(0.94f, 0.87f);
    glVertex2f(0.96f, 0.86f);
    glVertex2f(0.98f, 0.87f);
    glVertex2f(1.0f, 0.86f);
///17
    glVertex2f(0.02f, 0.73f);
    glVertex2f(0.04f, 0.72f);
    glVertex2f(0.06f, 0.73f);
    glVertex2f(0.08f, 0.72f);
    glVertex2f(0.10f, 0.73f);
    glVertex2f(0.12f, 0.72f);
    glVertex2f(0.14f, 0.73f);
    glVertex2f(0.16f, 0.72f);
    glVertex2f(0.18f, 0.73f);
    glVertex2f(0.20f, 0.72f);
    glVertex2f(0.22f, 0.73f);
    glVertex2f(0.24f, 0.72f);
    glVertex2f(0.26f, 0.73f);
    glVertex2f(0.28f, 0.72f);
    glVertex2f(0.30f, 0.73f);
    glVertex2f(0.32f, 0.72f);
    glVertex2f(0.34f, 0.73f);
    glVertex2f(0.36f, 0.72f);
    glVertex2f(0.38f, 0.73f);
    glVertex2f(0.40f, 0.72f);
    glVertex2f(0.42f, 0.73f);
    glVertex2f(0.44f, 0.72f);
    glVertex2f(0.46f, 0.73f);
    glVertex2f(0.48f, 0.72f);
    glVertex2f(0.50f, 0.73f);
    glVertex2f(0.52f, 0.72f);
    glVertex2f(0.54f, 0.73f);
    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.58f, 0.73f);
    glVertex2f(0.60f, 0.72f);
    glVertex2f(0.62f, 0.73f);
    glVertex2f(0.64f, 0.72f);
    glVertex2f(0.66f, 0.73f);
    glVertex2f(0.68f, 0.72f);
    glVertex2f(0.70f, 0.f);
    glVertex2f(0.72f, 0.72f);
    glVertex2f(0.74f, 0.76f);
    glVertex2f(0.76f, 0.72f);
    glVertex2f(0.78f, 0.73f);
    glVertex2f(0.80f, 0.65f);
    glVertex2f(0.82f, 0.73f);
    glVertex2f(0.84f, 0.72f);
    glVertex2f(0.86f, 0.69f);
    glVertex2f(0.88f, 0.72f);
    glVertex2f(0.90f, 0.66f);
    glVertex2f(0.92f, 0.72f);
    glVertex2f(0.94f, 0.67f);
    glVertex2f(0.96f, 0.72f);
    glVertex2f(0.98f, 0.68f);
    glVertex2f(1.0f, 0.72f);

///18
    glVertex2f(0.01f, 0.76f);
    glVertex2f(0.03f, 0.77f);
    glVertex2f(0.05f, 0.76f);
    glVertex2f(0.07f, 0.77f);
    glVertex2f(0.09f, 0.76f);
    glVertex2f(0.11f, 0.77f);
    glVertex2f(0.13f, 0.76f);
    glVertex2f(0.15f, 0.77f);
    glVertex2f(0.17f, 0.76f);
    glVertex2f(0.19f, 0.77f);
    glVertex2f(0.21f, 0.76f);
    glVertex2f(0.23f, 0.77f);
    glVertex2f(0.25f, 0.76f);
    glVertex2f(0.27f, 0.77f);
    glVertex2f(0.29f, 0.76f);
    glVertex2f(0.31f, 0.76f);
    glVertex2f(0.33f, 0.77f);
    glVertex2f(0.35f, 0.76f);
    glVertex2f(0.37f, 0.77f);
    glVertex2f(0.39f, 0.76f);
    glVertex2f(0.41f, 0.77f);
    glVertex2f(0.43f, 0.76f);
    glVertex2f(0.45f, 0.77f);
    glVertex2f(0.47f, 0.76f);
    glVertex2f(0.49f, 0.77f);
    glVertex2f(0.51f, 0.76f);
    glVertex2f(0.53f, 0.77f);
    glVertex2f(0.55f, 0.76f);
    glVertex2f(0.57f, 0.77f);
    glVertex2f(0.59f, 0.76f);
    glVertex2f(0.61f, 0.76f);
    glVertex2f(0.63f, 0.77f);
    glVertex2f(0.65f, 0.76f);
    glVertex2f(0.67f, 0.77f);
    glVertex2f(0.69f, 0.76f);
    glVertex2f(0.71f, 0.77f);
    glVertex2f(0.73f, 0.76f);
    glVertex2f(0.75f, 0.77f);
    glVertex2f(0.77f, 0.76f);
    glVertex2f(0.79f, 0.77f);
    glVertex2f(0.81f, 0.76f);
    glVertex2f(0.83f, 0.77f);
    glVertex2f(0.85f, 0.76f);
    glVertex2f(0.87f, 0.77f);
    glVertex2f(0.89f, 0.76f);
    glVertex2f(0.91f, 0.76f);
    glVertex2f(0.93f, 0.77f);
    glVertex2f(0.95f, 0.76f);
    glVertex2f(0.97f, 0.77f);
    glVertex2f(0.99f, 0.76f);

    glEnd();


///_____________________________________________ROCKET(START)___________________________________________________///

    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.1f,-0.3f, 0.0f);
    glTranslatef(0.0f,position3, 0.0f);

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


///_________ Fire main 0________///

    glBegin(GL_POLYGON);

    glColor3f(0.988f, 0.702f, 0.11f);

    glVertex2f(0.39f,0.17f);

    glVertex2f(0.36f,0.11f);

    glVertex2f(0.388f,0.14f);

    glVertex2f(0.4f,0.09f);

    glVertex2f(0.42f,0.15f);

    glVertex2f(0.45f,0.11f);

    glVertex2f(0.42f,0.17f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.953f, 0.906f, 0.396f);

    glVertex2f(0.392f,0.17f);

    glVertex2f(0.38f,0.138f);

    glVertex2f(0.395f,0.16f);

    glVertex2f(0.40f,0.11f);

    glVertex2f(0.41f,0.16f);

    glVertex2f(0.43f,0.14f);

    glVertex2f(0.417f,0.17f);

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
    ///..............................rocket END...........................................



///.........................................................CLOUD 2nd layer.................................///

    ///circle 1

    GLfloat t20 =0.04f, r20=0.10f, radi20 =.045f;
    twicePi = 2.0f * PI;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t20, r20); // center of circle
    	for(int i = 0; i <= triangleAmount; i++) {
    		glVertex2f( t20 + (radi20 * cos(i *  twicePi / triangleAmount)),
                          r20 + (radi20 * sin(i * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 2

    GLfloat t21 =0.07f, r21=0.14f, radi21 =.04f;
    twicePi = 2.0f * PI;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t21, r21); // center of circle
    	for(int i1 = 0; i1 <= triangleAmount; i1++) {
    		glVertex2f( t21 + (radi21 * cos(i1 *  twicePi / triangleAmount)),
                          r21 + (radi21 * sin(i1 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 3

    GLfloat t22=0.15f, r22=0.17, radi22 =.065f;
    twicePi = 2.0f * PI;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t22, r22); // center of circle
    	for(int i2 = 0; i2 <= triangleAmount; i2++) {
    		glVertex2f( t22 + (radi22 * cos(i2 *  twicePi / triangleAmount)),
                          r22 + (radi22 * sin(i2 * twicePi / triangleAmount)) );
    	}
    glEnd();

   ///circle 4

    GLfloat t23=0.15f, r23=0.04f, radi23 =.10f;
    twicePi = 2.0f * PI;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t23, r23); // center of circle
    	for(int i3 = 0; i3 <= triangleAmount; i3++) {
    		glVertex2f( t23 + (radi23 * cos(i3 *  twicePi / triangleAmount)),
                          r23 + (radi23 * sin(i3 * twicePi / triangleAmount)) );
    	}
    glEnd();

   ///circle 5

    GLfloat t24=0.22f, r24=0.148f, radi24 =.045f;
    twicePi = 2.0f * PI;

      glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t24, r24); // center of circle
    	for(int i4 = 0; i4 <= triangleAmount; i4++) {
    		glVertex2f( t24 + (radi24 * cos(i4 *  twicePi / triangleAmount)),
                          r24 + (radi24 * sin(i4 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 6

    GLfloat t25=0.26, r25=0.09f, radi25 =.07f;
    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t25, r25); // center of circle
    	for(int i5 = 0; i5 <= triangleAmount; i5++) {
    		glVertex2f( t25 + (radi25 * cos(i5 *  twicePi / triangleAmount)),
                          r25 + (radi25 * sin(i5 * twicePi / triangleAmount)) );
    	}
    glEnd();


     ///circle 7

    GLfloat t26=0.35f, r26=0.04f, radi26 =.09f;
    glColor3f(0.573f, 0.875f, 0.953f);

    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t26, r26); // center of circle
    	for(int i6 = 0; i6 <= triangleAmount; i6++) {
    		glVertex2f( t26 + (radi26 * cos(i6 *  twicePi / triangleAmount)),
                          r26 + (radi26 * sin(i6 * twicePi / triangleAmount)) );
    	}
    glEnd();

     ///circle 8

    GLfloat t27=0.40f, r27=0.04f, radi27 =.08f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t27, r27); // center of circle
    	for(int i7 = 0; i7 <= triangleAmount; i7++) {
    		glVertex2f( t27 + (radi27 * cos(i7 *  twicePi / triangleAmount)),
                          r27 + (radi27 * sin(i7 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 9

    GLfloat t28=0.49f, r28=0.11f, radi28 =.06f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t28, r28); // center of circle
    	for(int i8 = 0; i8 <= triangleAmount; i8++) {
    		glVertex2f( t28 + (radi28 * cos(i8 *  twicePi / triangleAmount)),
                          r28 + (radi28 * sin(i8 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 10
    GLfloat t29=0.5f, r29=0.04f, radi29 =.08f;

glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t29, r29); // center of circle
    	for(int i9 = 0; i9 <= triangleAmount; i9++) {
    		glVertex2f( t29 + (radi29 * cos(i9 *  twicePi / triangleAmount)),
                          r29 + (radi29 * sin(i9 * twicePi / triangleAmount)) );
    	}
    glEnd();


   ///circle 11
    GLfloat t30=0.60f, r30=0.11f, radi30 =.07f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t30, r30); // center of circle
    	for(int i10 = 0; i10 <= triangleAmount; i10++) {
    		glVertex2f( t30 + (radi30 * cos(i10 *  twicePi / triangleAmount)),
                          r30 + (radi30 * sin(i10 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 12
      	GLfloat t31=0.65f, r31=0.14f, radi31 =.05f;

glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t31, r31); // center of circle
    	for(int i11 = 0; i11 <= triangleAmount; i11++) {
    		glVertex2f( t31 + (radi31 * cos(i11 *  twicePi / triangleAmount)),
                          r31 + (radi31 * sin(i11 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 13
      	GLfloat t32=0.70f, r32=0.16f, radi32 =.04f;

glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t32, r32); // center of circle
    	for(int i12 = 0; i12 <= triangleAmount; i12++) {
    		glVertex2f( t32 + (radi32 * cos(i12 *  twicePi / triangleAmount)),
                          r32 + (radi32 * sin(i12 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 14
      	GLfloat t33=0.75f, r33=0.18f, radi33 =.04f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t33, r33); // center of circle
    	for(int i13 = 0; i13 <= triangleAmount; i13++) {
    		glVertex2f( t33 + (radi33 * cos(i13 *  twicePi / triangleAmount)),
                          r33 + (radi33 * sin(i13 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 15
        	GLfloat t34=0.85f, r34=0.20f, radi34 =.10f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t34, r34); // center of circle
    	for(int i14 = 0; i14 <= triangleAmount; i14++) {
    		glVertex2f( t34 + (radi34 * cos(i14 *  twicePi / triangleAmount)),
                          r34 + (radi34 * sin(i14 * twicePi / triangleAmount)) );
    	}
    glEnd();

    	///circle 16
        	GLfloat t35=0.96f, r35=0.18f, radi35 =.08f;

    glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t35, r35); // center of circle
    	for(int i15 = 0; i15 <= triangleAmount; i15++) {
    		glVertex2f( t35 + (radi35 * cos(i15 *  twicePi / triangleAmount)),
                          r35 + (radi35 * sin(i15 * twicePi / triangleAmount)) );
    	}
    glEnd();

    	///circle 17
        	GLfloat t36=0.86f, r36=0.00f, radi36 =.20f;

glColor3f(0.573f, 0.875f, 0.953f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t36, r36); // center of circle
    	for(int i16 = 0; i16 <= triangleAmount; i16++) {
    		glVertex2f( t36 + (radi36 * cos(i16 *  twicePi / triangleAmount)),
                          r36 + (radi36 * sin(i16 * twicePi / triangleAmount)) );
    	}
    glEnd();

///.........................................................................initial part.......................................................

    ///circle 1

    GLfloat t =0.04f, r=0.03f, radi =.045f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t, r); // center of circle
    	for(int i = 0; i <= triangleAmount; i++) {
    		glVertex2f( t + (radi * cos(i *  twicePi / triangleAmount)),
                          r + (radi * sin(i * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 2

    GLfloat t1 =0.07f, r1=0.07f, radi1 =.04f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t1, r1); // center of circle
    	for(int i1 = 0; i1 <= triangleAmount; i1++) {
    		glVertex2f( t1 + (radi1 * cos(i1 *  twicePi / triangleAmount)),
                          r1 + (radi1 * sin(i1 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 3

    GLfloat t2=0.15f, r2=0.10, radi2 =.065f;

     glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t2, r2); // center of circle
    	for(int i2 = 0; i2 <= triangleAmount; i2++) {
    		glVertex2f( t2 + (radi2 * cos(i2 *  twicePi / triangleAmount)),
                          r2 + (radi2 * sin(i2 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 4

    GLfloat t3=0.15f, r3=0.00f, radi3 =.10f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t3, r3); // center of circle
    	for(int i3 = 0; i3 <= triangleAmount; i3++) {
    		glVertex2f( t3 + (radi3 * cos(i3 *  twicePi / triangleAmount)),
                          r3 + (radi3 * sin(i3 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 5

    GLfloat t4=0.22f, r4=0.078f, radi4 =.045f;

      glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t4, r4); // center of circle
    	for(int i4 = 0; i4 <= triangleAmount; i4++) {
    		glVertex2f( t4 + (radi4 * cos(i4 *  twicePi / triangleAmount)),
                          r4 + (radi4 * sin(i4 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 6

    GLfloat t5=0.26, r5=0.02f, radi5 =.07f;
    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t5, r5); // center of circle
    	for(int i5 = 0; i5 <= triangleAmount; i5++) {
    		glVertex2f( t5 + (radi5 * cos(i5 *  twicePi / triangleAmount)),
                          r5 + (radi5 * sin(i5 * twicePi / triangleAmount)) );
    	}
    glEnd();


      ///circle 7

    GLfloat t6=0.35f, r6=0.00f, radi6 =.09f;

    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t6, r6); // center of circle
    	for(int i6 = 0; i6 <= triangleAmount; i6++) {
    		glVertex2f( t6 + (radi6 * cos(i6 *  twicePi / triangleAmount)),
                          r6 + (radi6 * sin(i6 * twicePi / triangleAmount)) );
    	}
    glEnd();

     ///circle 8

    GLfloat t7=0.40f, r7=0.00f, radi7 =.08f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t7, r7); // center of circle
    	for(int i7 = 0; i7 <= triangleAmount; i7++) {
    		glVertex2f( t7 + (radi7 * cos(i7 *  twicePi / triangleAmount)),
                          r7 + (radi7 * sin(i7 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 9

    GLfloat t8=0.49f, r8=0.05f, radi8 =.06f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t8, r8); // center of circle
    	for(int i8 = 0; i8 <= triangleAmount; i8++) {
    		glVertex2f( t8 + (radi8 * cos(i8 *  twicePi / triangleAmount)),
                          r8 + (radi8 * sin(i8 * twicePi / triangleAmount)) );
    	}
    glEnd();


     ///circle 10
    GLfloat t9=0.5f, r9=0.00f, radi9 =.08f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t9, r9); // center of circle
    	for(int i9 = 0; i9 <= triangleAmount; i9++) {
    		glVertex2f( t9 + (radi9 * cos(i9 *  twicePi / triangleAmount)),
                          r9 + (radi9 * sin(i9 * twicePi / triangleAmount)) );
    	}
    glEnd();


    ///circle 11
    GLfloat t10=0.60f, r10=0.04f, radi10 =.07f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t10, r10); // center of circle
    	for(int i10 = 0; i10 <= triangleAmount; i10++) {
    		glVertex2f( t10 + (radi10 * cos(i10 *  twicePi / triangleAmount)),
                          r10 + (radi10 * sin(i10 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 12
      	GLfloat t11=0.65f, r11=0.07f, radi11 =.05f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t11, r11); // center of circle
    	for(int i11 = 0; i11 <= triangleAmount; i11++) {
    		glVertex2f( t11 + (radi11 * cos(i11 *  twicePi / triangleAmount)),
                          r11 + (radi11 * sin(i11 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 13
      	GLfloat t12=0.70f, r12=0.09f, radi12 =.04f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t12, r12); // center of circle
    	for(int i12 = 0; i12 <= triangleAmount; i12++) {
    		glVertex2f( t12 + (radi12 * cos(i12 *  twicePi / triangleAmount)),
                          r12 + (radi12 * sin(i12 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 14
      	GLfloat t13=0.75f, r13=0.11f, radi13 =.04f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t13, r13); // center of circle
    	for(int i13 = 0; i13 <= triangleAmount; i13++) {
    		glVertex2f( t13 + (radi13 * cos(i13 *  twicePi / triangleAmount)),
                          r13 + (radi13 * sin(i13 * twicePi / triangleAmount)) );
    	}
    glEnd();

    ///circle 15
        	GLfloat t14=0.85f, r14=0.13f, radi14 =.10f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t14, r14); // center of circle
    	for(int i14 = 0; i14 <= triangleAmount; i14++) {
    		glVertex2f( t14 + (radi14 * cos(i14 *  twicePi / triangleAmount)),
                          r14 + (radi14 * sin(i14 * twicePi / triangleAmount)) );
    	}
    glEnd();

    	///circle 16
        	GLfloat t15=0.96f, r15=0.11f, radi15 =.08f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t15, r15); // center of circle
    	for(int i15 = 0; i15 <= triangleAmount; i15++) {
    		glVertex2f( t15 + (radi15 * cos(i15 *  twicePi / triangleAmount)),
                          r15 + (radi15 * sin(i15 * twicePi / triangleAmount)) );
    	}
    glEnd();

    	///circle 17
        	GLfloat t16=0.86f, r16=0.00f, radi16 =.20f;

    glColor3f(0.859f, 0.91f, 0.969f);
    glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(t16, r16); // center of circle
    	for(int i16 = 0; i16 <= triangleAmount; i16++) {
    		glVertex2f( t16 + (radi16 * cos(i16 *  twicePi / triangleAmount)),
                          r16 + (radi16 * sin(i16 * twicePi / triangleAmount)) );
    	}
    glEnd();



///..................................SATELLITE.......................................................................................................................
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(.950,.0,0);
    glRotatef(j,0.0,0.50,1.0);//i=how many degree you want to rotate around an axis
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



   glLineWidth(3);
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
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
    GLfloat p=0.11f, k=0.70f, ra=.005;
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p, k); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p + (ra * cos(i *  twicePi / triangleAmount)),
                    k + (ra * sin(i * twicePi / triangleAmount)) );
                    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();

    ///HALF CIRCLE
    GLfloat p1=0.11f, k1=0.68f, ra1=.025;
    twicePi= -1.0f *PI;

    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p1, k1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p1 + (ra1 * cos(i *  twicePi / triangleAmount)),
                    k1 + (ra1 * sin(i * twicePi / triangleAmount)) );
                    glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();

    j+=0.009f;
    glPopMatrix();

///SATELLITE 2

glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(-1.15,.0,0);
    glRotatef(l,0.0,0.50,1.0);//i=how many degree you want to rotate around an axis
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



   glLineWidth(3);
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
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
    GLfloat p2=0.11f, k2=0.70f, ra2=.005;
//    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p2, k2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p2 + (ra2 * cos(i *  twicePi / triangleAmount)),
                    k2 + (ra2 * sin(i * twicePi / triangleAmount)) );
                    glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();

    ///HALF CIRCLE
    GLfloat p3=0.11f, k3=0.68f, ra3=.025;
    twicePi= -1.0f *PI;

    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p3, k3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p3 + (ra3 * cos(i *  twicePi / triangleAmount)),
                    k3 + (ra3 * sin(i * twicePi / triangleAmount)) );
                    glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();

    l-=0.009f;
    glPopMatrix();



    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("The Project: Rocket"); // Create a window with the given title
    //glutFullScreen();
    init();
    glutSpecialFunc(SpecialInput);
    glutIdleFunc(Idle);

    glutDisplayFunc(display); // Register display callback handler for window re-paint
    //glutDisplayFunc(drawHalfCircle);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
