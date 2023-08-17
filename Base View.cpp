#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846
#include <GL/gl.h>
#include <GL/glu.h>
GLfloat position = 0.0f;
GLfloat speed1 = 0.001f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.005f;

int triangleAmount = 100;
int lineAmount = 100;

GLfloat twicePi = 2.0f * PI;
float objectY = 0.0f;  // Initial Y position of the object
float direction = 1.0f; // Direction of movement (+1 for down, -1 for up)
int i;
float carX = -0.0;  // Initial X position of the car
float cloudX = 0.0;  // Initial X position of the cloud
bool startMovingCar = false;  // Flag to control car movement
bool startMovingCloud = false;  // Flag to control cloud movement
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
///___________________________________________________Voids___________________________________________________///
void update(int value)
{
    if(position < -1.5)
            position = 1.5f;
///rocket
    if(position2 > 0.9)
            position2 = 1.0f;

    if(position3 < -2.0)
            position3 = 2.0f;

    position -= speed1;
    position2 += speed;
    position3 -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void update2(int value)
{
    if(position > 1.5)
            position = -1.5f;

    if(position2 < -0.9)
            position2 = 1.0f;

    if(position3 > 2.0)
            position3 = -2.0f;
    position += speed1;
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
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

void updatef(int value) {
    // Update the object's Y position
    objectY += 0.005f * direction; // Adjust the value for desired speed

    // Reverse the direction when the object reaches the top or bottom
    if (objectY >= 0.01f || objectY <= 0.0f) {
        direction *= -1.0f;
    }

    glutPostRedisplay(); // Trigger a display update
    glutTimerFunc(16, updatef, 0); // Call the update function every 16ms (approximately 60fps)
}

void timer(int value) {
    if (startMovingCar) {
        carX += 0.002;  // Increment X position to move the car to the right
        if (carX > 1.0) {
            carX = -1.0;  // Reset car position when it goes off-screen
        }
    }
    if (startMovingCloud) {
        cloudX -= 0.001;  // Decrement X position to move the cloud to the left
        if (cloudX < -1.90) {
            cloudX = 1.0;  // Reset cloud position when it goes off-screen
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);  // Call the timer function again after 16ms (approx. 60 FPS)
}
void keyboard(unsigned char key, int x, int y) {
    if (key == '7') {
        startMovingCar = !startMovingCar;  // Toggle car movement when '0' key is pressed
    }
     else if (key == '8') {
        startMovingCloud = !startMovingCloud;  // Toggle cloud movement when '3' key is pressed
    }
}

void display2() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
///___________________________________________________start___________________________________________________///


///_________________________________________________SKY(1)___________________________________________________///

    glBegin(GL_QUADS);
    glColor3f(0.184, 0.702, 0.945);
    glVertex2f(0.0f,1.00f);
    glColor3f(0.514, 0.792, 0.976);
    glVertex2f(0.0f,0.00f);
    glVertex2f(1.0f,0.00f);
    glColor3f(0, 0.502, 0.757);
    glVertex2f(1.0f,1.00f);
    glEnd();

///_________________________________________________SUN___________________________________________________///
    glColor3ub(243,149,0);
    GLfloat xs=0.79f; GLfloat ys=0.89f; GLfloat rs =.045f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xs, ys); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3ub(250, 235, 0.0);
            glVertex2f( xs + (rs * cos(i *  twicePi / triangleAmount)),
                        ys + (rs * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 1___________________________________________________///
    ///_________ 11 ________///
    glPushMatrix();
    glTranslatef(cloudX, 0.0, 0.0);  // Move the cloud horizontally
    GLfloat xc11=0.120f; GLfloat yc11=0.92f; GLfloat rc11 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc11, yc11);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc11 + (rc11 * cos(i*  twicePi / triangleAmount)),
                        yc11 + (rc11 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 12 ________///
    GLfloat xc12=0.140f; GLfloat yc12=0.94f; GLfloat rc12 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc12, yc12); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc12 + (rc12 * cos(i *  twicePi / triangleAmount)),
                        yc12 + (rc12 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 13 ________///
    GLfloat xc13=0.135f; GLfloat yc13=0.92f; GLfloat rc13 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc13, yc13); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc13 + (rc13 * cos(i*  twicePi / triangleAmount)),
                        yc13 + (rc13 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 16 ________///
    GLfloat xc16=0.160f; GLfloat yc16=0.94f; GLfloat rc16 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc16, yc16); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc16 + (rc16 * cos(i *  twicePi / triangleAmount)),
                        yc16 + (rc16 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 17 ________///
    GLfloat xc17=0.155f; GLfloat yc17=0.92; GLfloat rc17 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc17, yc17); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc17 + (rc17 * cos(i*  twicePi / triangleAmount)),
                        yc17 + (rc17 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 18 ________///
    GLfloat xc18=0.175f; GLfloat yc18=0.92f; GLfloat rc18 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc18, yc18); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc18 + (rc18 * cos(i *  twicePi / triangleAmount)),
                        yc18 + (rc18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 2___________________________________________________///
    ///_________ 21 ________///
    GLfloat xc21=0.210f; GLfloat yc21=0.90f; GLfloat rc21 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc21, yc21);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc21 + (rc21 * cos(i*  twicePi / triangleAmount)),
                        yc21 + (rc21 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 22 ________///
    GLfloat xc22=0.230f; GLfloat yc22=0.92f; GLfloat rc22 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc22, yc22); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc22 + (rc22 * cos(i *  twicePi / triangleAmount)),
                        yc22 + (rc22 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 23 ________///
    GLfloat xc23=0.225f; GLfloat yc23=0.90f; GLfloat rc23 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc23, yc23); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc23 + (rc23 * cos(i*  twicePi / triangleAmount)),
                        yc23 + (rc23 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 26 ________///
    GLfloat xc26=0.250f; GLfloat yc26=0.92f; GLfloat rc26 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc26, yc26); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc26 + (rc26 * cos(i *  twicePi / triangleAmount)),
                        yc26 + (rc26 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 27 ________///
    GLfloat xc27=0.245f; GLfloat yc27=0.90f; GLfloat rc27 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc27, yc27); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc27 + (rc27 * cos(i*  twicePi / triangleAmount)),
                        yc27 + (rc27 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 28 ________///
    GLfloat xc28=0.265f; GLfloat yc28=0.90f; GLfloat rc28 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc28, yc28); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc28 + (rc28 * cos(i *  twicePi / triangleAmount)),
                        yc28 + (rc28 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 3___________________________________________________///
    ///_________ 31 ________///
    GLfloat xc31=0.720f; GLfloat yc31=0.92f; GLfloat rc31 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc31, yc31);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc31 + (rc31 * cos(i*  twicePi / triangleAmount)),
                        yc31 + (rc31 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 32 ________///
    GLfloat xc32=0.740f; GLfloat yc32=0.94f; GLfloat rc32 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc32, yc32); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc32 + (rc32 * cos(i *  twicePi / triangleAmount)),
                        yc32 + (rc32 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 33 ________///
    GLfloat xc33=0.735f; GLfloat yc33=0.92f; GLfloat rc33 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc33, yc33); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc33 + (rc33 * cos(i*  twicePi / triangleAmount)),
                        yc33 + (rc33 * sin(i* twicePi / triangleAmount)) );
        }


    ///_________ 36 ________///
    GLfloat xc36=0.760f; GLfloat yc36=0.94f; GLfloat rc36 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc36, yc36); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc36 + (rc36 * cos(i *  twicePi / triangleAmount)),
                        yc36 + (rc36 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 37 ________///
    GLfloat xc37=0.755f; GLfloat yc37=0.92f; GLfloat rc37 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc37, yc37); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc37 + (rc37 * cos(i*  twicePi / triangleAmount)),
                        yc37 + (rc37 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 38 ________///
    GLfloat xc38=0.775f; GLfloat yc38=0.92f; GLfloat rc38 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc38, yc38); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc38 + (rc38 * cos(i *  twicePi / triangleAmount)),
                        yc38 + (rc38 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 4___________________________________________________///
    ///_________ 41 ________///
    GLfloat xc41=0.810f; GLfloat yc41=0.90f; GLfloat rc41 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc41, yc41);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc41 + (rc41 * cos(i*  twicePi / triangleAmount)),
                        yc41 + (rc41 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 42 ________///
    GLfloat xc42=0.830f; GLfloat yc42=0.92f; GLfloat rc42 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc42, yc42); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc42 + (rc42 * cos(i *  twicePi / triangleAmount)),
                        yc42 + (rc42 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 43 ________///
    GLfloat xc43=0.825f; GLfloat yc43=0.90f; GLfloat rc43 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc43, yc43); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc43 + (rc43 * cos(i*  twicePi / triangleAmount)),
                        yc43 + (rc43 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 46 ________///
    GLfloat xc46=0.850f; GLfloat yc46=0.92f; GLfloat rc46 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc46, yc46); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc46 + (rc46 * cos(i *  twicePi / triangleAmount)),
                        yc46 + (rc46 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 47 ________///
    GLfloat xc47=0.845f; GLfloat yc47=0.90f; GLfloat rc47 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc47, yc47); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc47 + (rc47 * cos(i*  twicePi / triangleAmount)),
                        yc47 + (rc47 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 48 ________///
    GLfloat xc48=0.865f; GLfloat yc48=0.90f; GLfloat rc48 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc48, yc48); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc48 + (rc48 * cos(i *  twicePi / triangleAmount)),
                        yc48 + (rc48 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 5___________________________________________________///
   ///_________ 111 ________///
    GLfloat xc111=1.120f; GLfloat yc111=0.92f; GLfloat rc111 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc111, yc111);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc111 + (rc111 * cos(i*  twicePi / triangleAmount)),
                        yc111 + (rc111 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 112 ________///
    GLfloat xc112=1.140f; GLfloat yc112=0.94f; GLfloat rc112 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc112, yc112); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc112 + (rc112 * cos(i *  twicePi / triangleAmount)),
                        yc112 + (rc112 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 113 ________///
    GLfloat xc113=1.135f; GLfloat yc113=0.92f; GLfloat rc113 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc113, yc113); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc113 + (rc113 * cos(i*  twicePi / triangleAmount)),
                        yc113 + (rc113 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 116 ________///
    GLfloat xc116=1.160f; GLfloat yc116=0.94f; GLfloat rc116 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc116, yc116); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc116 + (rc116 * cos(i *  twicePi / triangleAmount)),
                        yc116 + (rc116 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 117 ________///
    GLfloat xc117=1.155f; GLfloat yc117=0.92; GLfloat rc117 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc117, yc117); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc117 + (rc117 * cos(i*  twicePi / triangleAmount)),
                        yc117 + (rc117 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 118 ________///
    GLfloat xc118=1.175f; GLfloat yc118=0.92f; GLfloat rc118 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc118, yc118); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc118 + (rc118 * cos(i *  twicePi / triangleAmount)),
                        yc118 + (rc118 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 6___________________________________________________///
    ///_________ 221 ________///
    GLfloat xc221=1.210f; GLfloat yc221=0.90f; GLfloat rc221 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc221, yc221);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc221 + (rc221 * cos(i*  twicePi / triangleAmount)),
                        yc221 + (rc221 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 222 ________///
    GLfloat xc222=1.230f; GLfloat yc222=0.92f; GLfloat rc222 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc222, yc222); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc222 + (rc222 * cos(i *  twicePi / triangleAmount)),
                        yc222 + (rc222 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 223 ________///
    GLfloat xc223=1.225f; GLfloat yc223=0.90f; GLfloat rc223 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc223, yc223); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc223 + (rc223 * cos(i*  twicePi / triangleAmount)),
                        yc223 + (rc223 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 226 ________///
    GLfloat xc226=1.250f; GLfloat yc226=0.92f; GLfloat rc226 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc226, yc226); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc226 + (rc226 * cos(i *  twicePi / triangleAmount)),
                        yc226 + (rc226 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 227 ________///
    GLfloat xc227=1.245f; GLfloat yc227=0.90f; GLfloat rc227 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc227, yc227); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc227 + (rc227 * cos(i*  twicePi / triangleAmount)),
                        yc227 + (rc227 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 228 ________///
    GLfloat xc228=1.265f; GLfloat yc228=0.90f; GLfloat rc228 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc228, yc228); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc228 + (rc228 * cos(i *  twicePi / triangleAmount)),
                        yc228 + (rc228 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 7___________________________________________________///
    ///_________ 331 ________///
    GLfloat xc331=1.720f; GLfloat yc331=0.92f; GLfloat rc331 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc331, yc331);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc331 + (rc331 * cos(i*  twicePi / triangleAmount)),
                        yc331 + (rc331 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 332 ________///
    GLfloat xc332=1.740f; GLfloat yc332=0.94f; GLfloat rc332 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc332, yc332); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc332 + (rc332 * cos(i *  twicePi / triangleAmount)),
                        yc332 + (rc332 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 333 ________///
    GLfloat xc333=1.735f; GLfloat yc333=0.92f; GLfloat rc333 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc333, yc333); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc333 + (rc333 * cos(i*  twicePi / triangleAmount)),
                        yc333 + (rc333 * sin(i* twicePi / triangleAmount)) );
        }


    ///_________ 336 ________///
    GLfloat xc336=1.760f; GLfloat yc336=0.94f; GLfloat rc336 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc336, yc336); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc336 + (rc336 * cos(i *  twicePi / triangleAmount)),
                        yc336 + (rc336 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 37 ________///
    GLfloat xc337=1.755f; GLfloat yc337=0.92f; GLfloat rc337 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc337, yc337); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc337 + (rc337 * cos(i*  twicePi / triangleAmount)),
                        yc337 + (rc337 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 338 ________///
    GLfloat xc338=1.775f; GLfloat yc338=0.92f; GLfloat rc338 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc338, yc338); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc338 + (rc338 * cos(i *  twicePi / triangleAmount)),
                        yc338 + (rc338 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 8___________________________________________________///
    ///_________ 441 ________///
    GLfloat xc441=1.810f; GLfloat yc441=0.90f; GLfloat rc441 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc441, yc441);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc441 + (rc441 * cos(i*  twicePi / triangleAmount)),
                        yc441 + (rc441 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 442 ________///
    GLfloat xc442=1.830f; GLfloat yc442=0.92f; GLfloat rc442 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc442, yc442); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc442 + (rc442 * cos(i *  twicePi / triangleAmount)),
                        yc442 + (rc442 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 443 ________///
    GLfloat xc443=1.825f; GLfloat yc443=0.90f; GLfloat rc443 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc443, yc443); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc443 + (rc443 * cos(i*  twicePi / triangleAmount)),
                        yc443 + (rc443 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 46 ________///
    GLfloat xc446=1.850f; GLfloat yc446=0.92f; GLfloat rc446 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc446, yc446); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc446 + (rc446 * cos(i *  twicePi / triangleAmount)),
                        yc446 + (rc446 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 47 ________///
    GLfloat xc447=1.845f; GLfloat yc447=0.90f; GLfloat rc447 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc447, yc447); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc447 + (rc447 * cos(i*  twicePi / triangleAmount)),
                        yc447 + (rc447 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 48 ________///
    GLfloat xc448=1.865f; GLfloat yc448=0.90f; GLfloat rc448 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc448, yc448); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc448 + (rc448 * cos(i *  twicePi / triangleAmount)),
                        yc448 + (rc448 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    glPopMatrix();



///_______________________________________________C building___________________________________________________///

    ///_________C body (SILVER) ________///
    glLineWidth(1);

	GLfloat xl=-0.05f; GLfloat yl=0.41f; GLfloat rl =0.15f;
	glColor3f(0.675f, 0.663f, 0.643f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xl, yl); // center of circle
		for( i = 0; i <= triangleAmount;i++) {
			glVertex2f( xl + (rl * cos(i *  twicePi / triangleAmount)),
                        yl + (rl * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	///_________C body (Border) ________///

	GLfloat x2=-0.05f; GLfloat y2=0.41f; GLfloat r2 =0.15f;
    glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
			    x2 + (r2 * cos(i *  twicePi / lineAmount)),
			    y2 + (r2* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	///_________C body Window(1) ________///
    glBegin(GL_QUADS);
    glColor3f(0.294f, 0.525f, 0.71f);
    glVertex2f(0.00f,0.50f);
    glVertex2f(0.00f,0.48f);
    glVertex2f(0.084f,0.48f);
    glVertex2f(0.07f,0.50f);
    ///_________C body Window(2) ________///
    glVertex2f(0.00f,0.44f);
    glVertex2f(0.00f,0.42f);
    glVertex2f(0.10f,0.42f);
    glVertex2f(0.0975f,0.44f);
    ///_________C body Window(3) ________///
    glVertex2f(0.00f,0.38f);
    glVertex2f(0.00f,0.36f);
    glVertex2f(0.092f,0.36f);
    glVertex2f(0.098f,0.38f);
    glEnd();
    ///_________C body Window Lines ________///
    glBegin(GL_LINES);
    glColor3f(0.2f,0.2f,0.2f);
    ///_________ Window Line(1) ________///
    glVertex2f(0.00f,0.50f);
    glVertex2f(0.07f,0.50f);
    glVertex2f(0.00f,0.48f);
    glVertex2f(0.083f,0.48f);
    glVertex2f(0.084f,0.48f);
    glVertex2f(0.07f,0.50f);
    ///_________ Window Line(2) ________///
    glVertex2f(0.00f,0.42f);
    glVertex2f(0.10f,0.42f);
    glVertex2f(0.0975f,0.44f);
    glVertex2f(0.10f,0.42f);
    glVertex2f(0.0975f,0.44f);
    glVertex2f(0.00f,0.44f);
    ///_________ Window Line(3) ________///
    glVertex2f(0.00f,0.38f);
    glVertex2f(0.098f,0.38f);
    glVertex2f(0.00f,0.36f);
    glVertex2f(0.092f,0.36f);
    glVertex2f(0.098f,0.38f);
    glVertex2f(0.092f,0.36f);
    glEnd();

///______________________________________________Annex Tower___________________________________________________///
    ///_________ Pillar ________///
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.412, 0.412, 0.412f);
    glVertex2f(0.210f,0.60f);
    glVertex2f(0.210f,0.20f);

    glVertex2f(0.238f,0.60f);
    glVertex2f(0.238f,0.20f);

    glVertex2f(0.208f,0.60f);
    glVertex2f(0.240f,0.60f);
    ///_________ Middle Cross(1) ________///
    glVertex2f(0.212f,0.60f);
    glVertex2f(0.236f,0.4f);
    glVertex2f(0.212f,0.4f);
    glVertex2f(0.236f,0.60f);
    ///_________ Middle Cross(2) ________///
    glVertex2f(0.212f,0.4f);
    glVertex2f(0.236f,0.2f);
    glVertex2f(0.212f,0.2f);
    glVertex2f(0.236f,0.4f);
    glEnd();
    ///_________Tower Signal line L1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.412, 0.412, 0.412f);
    glVertex2f(0.188f,0.5f);
    glVertex2f(0.21f,0.5f);
    ///_________Tower Signal line R1________///
    glVertex2f(0.26f,0.56f);
    glVertex2f(0.238f,0.56f);
    ///_________Tower Signal line R2________///
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.238f,0.44f);
    glEnd();
    ///_________Tower Signal line L1________///
    ///_________ OUTSIDE L1________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xl1=0.19f; GLfloat yl1=0.505f; GLfloat rl1 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xl1, yl1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xl1 + (rl1 * cos(i *  twicePi / triangleAmount)),
                        yl1+ (rl1 * sin(i * twicePi / triangleAmount)) );
                         glColor3f(0.294f, 0.388f, 0.388f);
        }
  /*  ///_________ INSIDE L1________///
    glColor3f(1.0, 0.0, 0.0);
    GLfloat xl2=0.19f; GLfloat yl2=0.5f; GLfloat rl2 =.008f;
        glVertex2f(xl2, yl2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xl2 + (rl2 * cos(i *  twicePi / triangleAmount)),
                        yl2+ (rl2 * sin(i * twicePi / triangleAmount)) );
        }*/
    glEnd();
    ///_________Tower Signal line R1________///
    ///_________ OUTSIDE R1________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xr11=0.26f; GLfloat yr11=0.565f; GLfloat rr11 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xr11, yr11); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr11 + (rr11 * cos(i *  twicePi / triangleAmount)),
                        yr11+ (rr11 * sin(i * twicePi / triangleAmount)) );
                        glColor3f(0.294f, 0.388f, 0.388f);
        }
   /* ///_________ INSIDE R1________///
    glColor3f(1.0, 0.0, 0.0);
    GLfloat xr12=0.26f; GLfloat yr12=0.56f; GLfloat rr12 =.008f;
        glVertex2f(xr12, yr12); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr12 + (rr12 * cos(i *  twicePi / triangleAmount)),
                        yr12+ (rr12 * sin(i * twicePi / triangleAmount)) );
        }*/
        glEnd();
    ///_________Tower Signal line R2________///
    ///_________ OUTSIDE R2________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xr21=0.26f; GLfloat yr21=0.445f; GLfloat rr21 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xr21, yr21); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr21 + (rr21 * cos(i *  twicePi / triangleAmount)),
                        yr21+ (rr21 * sin(i * twicePi / triangleAmount)) );
                        glColor3f(0.294f, 0.388f, 0.388f);
        }
   /* ///_________ INSIDE R2________///
    glColor3f(1.0, 0.0, 0.0);
    GLfloat xr22=0.26f; GLfloat yr22=0.44f; GLfloat rr22 =.008f;
        glVertex2f(xr22, yr22); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr22 + (rr22 * cos(i *  twicePi / triangleAmount)),
                        yr22+ (rr22 * sin(i * twicePi / triangleAmount)) );
        }*/
glEnd();

 ///_________Tower Signal line R1________///
    glBegin(GL_QUADS);
    glColor3f(0.275, 0.69, 0.91);
    glVertex2f(0.247f,0.585f);
    glColor3f(0.286, 0.69, 0.91);
    glVertex2f(0.269f,0.545f);
    glColor3f(0.282, 0.686, 0.906);
    glVertex2f(0.28f,0.545f);
    glColor3f(0.271, 0.682, 0.906);
    glVertex2f(0.28f,0.585f);
    glEnd();
 ///_________Tower Signal line R2________///
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.702, 0.914);
    glVertex2f(0.269f,0.425f);
    glColor3f(0.325, 0.698, 0.914);
    glVertex2f(0.247f,0.465f);
    glColor3f(0.322, 0.698, 0.91);
    glVertex2f(0.28f,0.465f);
    glColor3f(0.31, 0.694, 0.91);
    glVertex2f(0.28f,0.425f);
    glEnd();
    ///_________Tower Signal line L1________///
    glBegin(GL_QUADS);
    glColor3f(0.31, 0.71, 0.929);
    glVertex2f(0.170f,0.482f);
glColor3f(0.322, 0.714, 0.929);
    glVertex2f(0.170f,0.522f);
glColor3f(0.322, 0.714, 0.925);
    glVertex2f(0.203f,0.522f);

glColor3f(0.306, 0.706, 0.922);
    glVertex2f(0.181f,0.482f);
    glEnd();
/*///-------------------------------------------------------------------------
glPushMatrix();
glLoadIdentity();
glTranslated(0.22,0.0,0.0);
  glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///with mini circle
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);
    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);
    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();
///mini circle
    GLfloat p=0.11f, k=0.70f, ra=.005;
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
    GLfloat twicePi1= -1.0f *PI;
    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p1, k1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p1 + (ra1 * cos(i *  twicePi1 / triangleAmount)),
                    k1 + (ra1 * sin(i * twicePi1 / triangleAmount)) );
        glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();
    glPopMatrix();*/
   /* glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.265,0.556);
    glVertex2f(0.270,0.575);

    glVertex2f(0.255,0.566);
    glVertex2f(0.260,0.575);
    glEnd();*/
///-------------------------------------------------------------------------
///_________________________________________________Annex(2)___________________________________________________///

    ///_________Annex 2 Body________///
    glBegin(GL_QUADS);
    glColor3f(0.318, 0.341, 0.341);
    glVertex2f(0.135f,0.36f);
    glVertex2f(0.135f,0.20f);
    glVertex2f(0.220f,0.20f);
    glVertex2f(0.220f,0.36f);
    ///_________Annex 2 Top________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.220f,0.38f);
    glEnd();
    ///_________Annex 2 Window 1________///
    glBegin(GL_QUADS);
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.203f,0.32f);
    ///_________Annex 2 Window 2________///
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.165f,0.32f);
    glEnd();
    ///_________Annex 2 Top Border________///
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.220f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.220f,0.38f);
    ///_________Annex 2 Window(1) Border________///
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.203f,0.32f);
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.203f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.1955f,0.32f);
    glVertex2f(0.1955f,0.3f);
    ///_________Annex 2 Window(2) Border________///
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.165f,0.32f);
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.165f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.1575f,0.32f);
    glVertex2f(0.1575f,0.3f);
    glEnd();

///_________________________________________________Annex(1)___________________________________________________///

    ///_________Annex 1 Body________///

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.486, 0.412);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Top________///
    glColor3f(0.039f, 0.459f, 0.02f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    glVertex2f(0.20f,0.29f);
    ///_________Annex 1 Under Top________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.256f);
    glVertex2f(0.20f,0.256f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Window (1)________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.015f,0.24f);
    ///_________Annex 1 Window (2)________///
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.060f,0.24f);
    ///_________Annex 1 Window (3)________///
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.105f,0.24f);
    ///_________Annex 1 Window (4)________///
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.150f,0.24f);
    ///_________Annex 1 Window (5)________///
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.195f,0.24f);
    glEnd();
    ///_________Annex 1 Top Border________///
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    glVertex2f(0.20f,0.29f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.20f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    ///_________Annex 1 Body Border________///
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.20f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Window(1)Border________///
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.015f,0.24f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.24f);
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.007f,0.22f);
    glVertex2f(0.007f,0.24f);
    ///_________Annex 1 Window(2)Border________///
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.060f,0.24f);
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.060f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.0525f,0.22f);
    glVertex2f(0.0525f,0.24f);
    ///_________Annex 1 Window(3)Border________///
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.105f,0.24f);
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.105f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.0975f,0.22f);
    glVertex2f(0.0975f,0.24f);

    ///_________Annex 1 Window(4)Border________///
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.150f,0.24f);
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.150f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.1425f,0.22f);
    glVertex2f(0.1425f,0.24f);

    ///_________Annex 1 Window(5)Border________///
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.195f,0.24f);
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.195f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.1875f,0.22f);
    glVertex2f(0.1875f,0.24f);
    ///_________Annex 1 Partition Border________///
    glVertex2f(0.120f,0.26f);
    glVertex2f(0.120f,0.20f);
    glVertex2f(0.030f,0.26f);
    glVertex2f(0.030f,0.20f);
    glEnd();
///_____________________________________________ROCKET Stand(START)___________________________________________________///
    ///_________ 1________///
    glBegin(GL_QUADS);
    ///_________ 2________///
    glColor3f(0.549, 0.639, 0.635);
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);
    glVertex2f(0.58f,0.56f);

    ///_________ 3________///
    glColor3f(0.549, 0.639, 0.635);
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    glVertex2f(0.52f,0.51f);
    ///_________ 4________///
    glColor3f(0.035, 0.506, 0.733);
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    glVertex2f(0.57f,0.54f);
    ///_________ 5________///
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    glVertex2f(0.53f,0.50f);
    ///_________ 6________///
    glColor3f(0.635, 0.733, 0.82);
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    glVertex2f(0.56f,0.25f);


    glEnd();


    ///_________ 1 border________///
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    ///_________ 2 border________///
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);
    glVertex2f(0.58f,0.56f);
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.58f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);

   ///_________ 3 border________///
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    glVertex2f(0.52f,0.51f);
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.52f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    ///_________ 4 border________///
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    glVertex2f(0.57f,0.54f);
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.57f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    ///_________ 5 border________///
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    glVertex2f(0.53f,0.50f);
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.53f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    ///_________ 6 border________///
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    glVertex2f(0.56f,0.25f);
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.56f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    ///_________ UPPER MID border________///
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.45f,0.47f);
    glVertex2f(0.46f,0.47f);
    glVertex2f(0.47f,0.50f);
    glVertex2f(0.48f,0.50f);
    glVertex2f(0.49f,0.47f);
    glVertex2f(0.50f,0.47f);
    glVertex2f(0.51f,0.50f);
    ///_________ 7 borders________///
        ///_________ 7 top________///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.52f,0.39f);
        ///_________ 7 bottom________///
    glVertex2f(0.435f,0.36f);
    glVertex2f(0.52f,0.36f);
        ///_________ 7 Mid________///
    glVertex2f(0.435f,0.375f);
    glVertex2f(0.52f,0.375f);
    ///_________ 7 left line________///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.435f,0.36f);
        ///_________ 7 cross(Top to Bottom)________///
    glVertex2f(0.438f,0.39f);
    glVertex2f(0.458f,0.36f);
    glVertex2f(0.458f,0.36f);
    glVertex2f(0.478f,0.39f);
    glVertex2f(0.478f,0.39f);
    glVertex2f(0.498f,0.36f);
    glVertex2f(0.498f,0.36f);
    glVertex2f(0.518f,0.39f);
        ///_________ 7 cross(Bottom to top)________///
    glVertex2f(0.438f,0.36f);
    glVertex2f(0.458f,0.39f);
    glVertex2f(0.458f,0.39f);
    glVertex2f(0.478f,0.36f);
    glVertex2f(0.478f,0.36f);
    glVertex2f(0.498f,0.39f);
    glVertex2f(0.498f,0.39f);
    glVertex2f(0.518f,0.36f);
        ///_________ Lift line________///
    glColor3f(0.157, 0.6, 0.835);
    glVertex2f(0.55f,0.538f);
    glVertex2f(0.55f,0.25f);
    glEnd();
///_____________________________________________ROCKET Stand(END)___________________________________________________///

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,position2, 0.0f);
    glBegin(GL_QUADS);

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


    glPushMatrix();
    glTranslatef(0.0f, objectY, 0.0f); // Translate the object vertically
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


    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
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
    glVertex2f(0.40f,0.16f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
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
    glVertex2f(0.40f,0.16f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    ///_________ 1________///
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
    ///_________ 1 Rocket stand________///
    glBegin(GL_QUADS);
    glColor3f(0.431, 0.416, 0.412);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.44f,0.23f);
    glEnd();
    ///_________ 1 rocket stand border________///
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glEnd();

    ///.......Transparent wall.....//

    glBegin(GL_QUADS);
    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.32f,0.30f);
    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.49f,0.20f);

    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);
    glVertex2f(0.32f,0.30f);

    glVertex2f(0.49f,0.20f);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.50f,0.28f);
    glVertex2f(0.50f,0.22f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.32f,0.30f);
    glVertex2f(0.49f,0.30f);


    glVertex2f(0.32f,0.20f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);
    glVertex2f(0.32f,0.30f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);

    glVertex2f(0.49f,0.20f);
    glVertex2f(0.50f,0.22f);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.50f,0.28f);
    glVertex2f(0.50f,0.22f);
    glVertex2f(0.50f,0.28f);

    glEnd();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ///_____________________________________________ROCKET(END)___________________________________________________///

///_________________________________________________D building(Start)___________________________________________________///
    ///_________ 1 ________///
    glBegin(GL_QUADS);
    glColor3f(0.196f,0.376f,0.51f);
    glVertex2f(0.95f,0.2f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(1.0f,0.61f);
    glVertex2f(1.0f,0.2f);
    ///_________ body 2 ________///
    glColor3f(0.765f,0.761f,0.769f);
    glVertex2f(0.74f,0.2f);
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.98f,0.58f);
    glVertex2f(0.98f,0.2f);
    ///_________ 3 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.74f,0.545f);
    glVertex2f(0.74f,0.565f);
    glVertex2f(0.98f,0.565f);
    glVertex2f(0.98f,0.545f);
    ///_________ 4 ________///
    glVertex2f(0.74f,0.530f);
    glVertex2f(0.74f,0.510f);
    glVertex2f(0.98f,0.510f);
    glVertex2f(0.98f,0.530f);
    ///_________ 5 ________///
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.98f,0.445f);
    glVertex2f(0.98f,0.495f);
    ///_________ 6 ________///
    glVertex2f(0.74f,0.430f);
    glVertex2f(0.74f,0.495f);
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.75f,0.445f);
    ///_________ 7 ________///
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.98f,0.410f);
    glVertex2f(0.98f,0.43f);
    glVertex2f(0.75f,0.43f);
    ///_________ 8 ________///
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.98f,0.340f);
    glVertex2f(0.98f,0.390f);
    ///_________ 9 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.75f,0.325f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.76f,0.390f);
    ///_________ 10 ________///
    glVertex2f(0.76f,0.325f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.98f,0.305f);
    glVertex2f(0.98f,0.325f);
    ///_________ 11 ________///
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.76f,0.270f);
    glVertex2f(0.98f,0.270f);
    glVertex2f(0.98f,0.290f);

    ///_________ 12 ________///
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.76f,0.23f);
    glVertex2f(0.98f,0.23f);
    glVertex2f(0.98f,0.255f);
    ///_________ 13 ________///
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.76f,0.2f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.98f,0.212f);
    ///_________ 14 ________///
    glColor3f(0.765f,0.761f,0.769f);
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.68f,0.2f);
    glVertex2f(0.74f,0.2f);
    glVertex2f(0.74f,0.58f);
    ///_________ 15 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.2f);
    glVertex2f(0.732f,0.560f);
    ///_________ 16 ________///
    glVertex2f(0.73f,0.400f);
    glVertex2f(0.73f,0.2f);
    glVertex2f(0.743f,0.2f);
    glVertex2f(0.743f,0.420f);
    ///_________ 17 ________///
    glVertex2f(0.73f,0.285f);
    glVertex2f(0.73f,0.2f);
    glVertex2f(0.753f,0.2f);
    glVertex2f(0.753f,0.315f);
    glEnd();
    ///_________ 18 ________///
    /*glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.671f, 0.671f, 0.671f);
    glVertex2f(0.737f,0.58f);
    glVertex2f(0.737f,0.410f);
    glEnd();*/
    ///_________ D window (1) ________///
    glBegin(GL_QUADS);
    glColor3f(0.298, 0.51, 0.671);
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    glVertex2f(0.993f,0.56f);
    ///_________ D window (2) ________///
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    glVertex2f(0.993f,0.52f);
    ///_________ D window (3) ________///
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    glVertex2f(0.993f,0.48f);
    ///_________ D window (4) ________///
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    glVertex2f(0.993f,0.44f);
    ///_________ D window (5) ________///
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    glVertex2f(0.993f,0.40f);
    ///_________ D window (6) ________///
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    glVertex2f(0.993f,0.36f);
    ///_________ D window (7) ________///
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    glVertex2f(0.993f,0.32f);
    ///_________ D window (8) ________///
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    glVertex2f(0.993f,0.28f);
    ///_________ D window (9) ________///
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    glVertex2f(0.993f,0.24f);
     glEnd();
     ///______________________________________________________D 7th & 5th tree___________________________________________________///
   ///_________D 7th tree 1________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.10,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E1 =0.062, E2 =0.070f, S1=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E1, E2); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E1 + (S1 * cos(i *  twicePi / triangleAmount)),
                        E2 + (S1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E3 =0.057, E4 =0.09f, S2=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E3, E4); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E3 + (S2 * cos(i *  twicePi / triangleAmount)),
                        E4 + (S2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E5 =0.04, E6 =0.081f, S3=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5, E6); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5 + (S3 * cos(i *  twicePi / triangleAmount)),
                        E6 + (S3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E7 =0.026, E8 =0.089f, S4=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E7, E8); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E7 + (S4 * cos(i *  twicePi / triangleAmount)),
                        E8 + (S4 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E9 =0.019, E10 =0.10f, S5=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E9, E10); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E9 + (S5 * cos(i *  twicePi / triangleAmount)),
                        E10 + (S5 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F =0.043, F1 =0.123f, S6=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F, F1); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F + (S6 * cos(i *  twicePi / triangleAmount)),
                        F1 + (S6 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F2 =0.07, F3 =0.12f, S7=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F2, F3); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F2 + (S7 * cos(i *  twicePi / triangleAmount)),
                        F3 + (S7 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F4 =0.07, F5 =0.10f, S8=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F4, F5); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F4 + (S8 * cos(i *  twicePi / triangleAmount)),
                        F5 + (S8 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F6 =0.025, F7 =0.059f, S9=0.014f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F6, F7); // center of circle
        for( i = 0; i <= triangleAmount;i++) {


            glVertex2f( F6 + (S9 * cos(i *  twicePi / triangleAmount)),
                        F7 + (S9 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
///______________________________________________________DEMO TREE 2___________________________________________________///
 ///_________D 7th tree 2________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.30,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E11 =0.062, E12 =0.070f, S11=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E11, E12); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E11 + (S11 * cos(i *  twicePi / triangleAmount)),
                        E12 + (S11 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E13 =0.057, E14 =0.09f, S12=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E13, E14); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E13 + (S12 * cos(i *  twicePi / triangleAmount)),
                        E14 + (S12 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E15 =0.04, E16 =0.081f, S13=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E15, E16); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E15 + (S13 * cos(i *  twicePi / triangleAmount)),
                        E16 + (S13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E17 =0.026, E18 =0.089f, S14=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E17, E18); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E17 + (S14 * cos(i *  twicePi / triangleAmount)),
                        E18 + (S14 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E19 =0.019, E110 =0.10f, S15=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E19, E110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E19 + (S15 * cos(i *  twicePi / triangleAmount)),
                        E110 + (S15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F01 =0.043, F11 =0.123f, S16=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F01, F11); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F01 + (S16 * cos(i *  twicePi / triangleAmount)),
                        F11 + (S16 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F12 =0.07, F13 =0.12f, S17=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F12, F13); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F12 + (S17 * cos(i *  twicePi / triangleAmount)),
                        F13 + (S17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F14 =0.07, F15 =0.10f, S18=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F14, F15); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F14 + (S18 * cos(i *  twicePi / triangleAmount)),
                        F15 + (S18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F16 =0.025, F17 =0.059f, S19=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F16, F17); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F16 + (S19 * cos(i *  twicePi / triangleAmount)),
                        F17 + (S19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
    ///______________________________________________________DEMO TREE 3___________________________________________________///
 ///_________D 7th tree 3________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.50,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E211 =0.062, E212 =0.070f, S211=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E211, E212); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E211 + (S211 * cos(i *  twicePi / triangleAmount)),
                        E212 + (S211 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E213 =0.057, E214 =0.09f, S212=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E213, E214); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E213 + (S212 * cos(i *  twicePi / triangleAmount)),
                        E214 + (S212 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E215 =0.04, E216 =0.081f, S213=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E215, E216); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E215 + (S213 * cos(i *  twicePi / triangleAmount)),
                        E216 + (S213 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E217 =0.026, E218 =0.089f, S214=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E17, E18); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E217 + (S214 * cos(i *  twicePi / triangleAmount)),
                        E218 + (S214 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E219 =0.019, E2110 =0.10f, S215=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E219, E2110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E219 + (S215 * cos(i *  twicePi / triangleAmount)),
                        E2110 + (S215 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F201 =0.043, F211 =0.123f, S216=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F201, F211); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F201 + (S216 * cos(i *  twicePi / triangleAmount)),
                        F211 + (S216 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F212 =0.07, F213 =0.12f, S217=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F212, F213); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F212 + (S217 * cos(i *  twicePi / triangleAmount)),
                        F213 + (S217 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F214 =0.07, F215 =0.10f, S218=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F214, F215); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F214 + (S218 * cos(i *  twicePi / triangleAmount)),
                        F215 + (S218 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F216 =0.025, F217 =0.059f, S219=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F216, F217); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F216 + (S219 * cos(i *  twicePi / triangleAmount)),
                        F217 + (S219 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
    ///______________________________________________________DEMO TREE 4___________________________________________________///
 ///_________D 7th tree 4________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.72,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E111 =0.062, E112 =0.070f, S111=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E111, E112); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E111 + (S111 * cos(i *  twicePi / triangleAmount)),
                        E112 + (S111 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E113 =0.057, E114 =0.09f, S112=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E113, E114); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E113 + (S112 * cos(i *  twicePi / triangleAmount)),
                        E114 + (S112 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E115 =0.04, E116 =0.081f, S113=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E115, E116); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E115 + (S113 * cos(i *  twicePi / triangleAmount)),
                        E116 + (S113 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E117 =0.026, E118 =0.089f, S114=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E117, E118); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E117 + (S114 * cos(i *  twicePi / triangleAmount)),
                        E118 + (S114 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E119 =0.019, E1110 =0.10f, S115=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E119, E1110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E119 + (S115 * cos(i *  twicePi / triangleAmount)),
                        E1110 + (S115 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F101 =0.043, F111 =0.123f, S116=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F101, F111); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F101 + (S116 * cos(i *  twicePi / triangleAmount)),
                        F111 + (S116 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F112 =0.07, F113 =0.12f, S117=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F112, F113); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F112 + (S117 * cos(i *  twicePi / triangleAmount)),
                        F113 + (S117 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F114 =0.07, F115 =0.10f, S118=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F114, F115); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F114 + (S118 * cos(i *  twicePi / triangleAmount)),
                        F115 + (S118 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F116 =0.025, F117 =0.059f, S119=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F116, F117); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F116 + (S119 * cos(i *  twicePi / triangleAmount)),
                        F117 + (S119 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
///______________________________________________________D 5th TREE ___________________________________________________///
 ///_________D 5th tree 1________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.15,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E51 =0.062, E52 =0.070f, S51=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E51, E52); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E51 + (S51 * cos(i *  twicePi / triangleAmount)),
                        E52 + (S51 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E53 =0.057, E54 =0.09f, S52=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E53, E54); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E53 + (S52 * cos(i *  twicePi / triangleAmount)),
                        E54 + (S52 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E55 =0.04, E56 =0.081f, S53=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55, E56); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55 + (S53 * cos(i *  twicePi / triangleAmount)),
                        E56 + (S53 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E57 =0.026, E58 =0.089f, S54=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E57, E58); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E57 + (S54 * cos(i *  twicePi / triangleAmount)),
                        E58 + (S54 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E59 =0.019, E510 =0.10f, S55=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E59, E510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E59 + (S55 * cos(i *  twicePi / triangleAmount)),
                        E510 + (S55 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F05 =0.043, F51 =0.123f, S56=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F05, F51); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F05 + (S56 * cos(i *  twicePi / triangleAmount)),
                        F51 + (S56 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F52 =0.07, F53 =0.12f, S57=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F52, F53); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F52 + (S57 * cos(i *  twicePi / triangleAmount)),
                        F53 + (S57 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F54 =0.07, F55 =0.10f, S58=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F54, F55); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F54 + (S58 * cos(i *  twicePi / triangleAmount)),
                        F55 + (S58 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________D 5th tree 2________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.35,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E551 =0.062, E552 =0.070f, S551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E551, E552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E551 + (S551 * cos(i *  twicePi / triangleAmount)),
                        E552 + (S551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E553 =0.057, E554 =0.09f, S552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E553, E554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E553 + (S552 * cos(i *  twicePi / triangleAmount)),
                        E554 + (S552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E555 =0.04, E556 =0.081f, S553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E555, E556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E555 + (S553 * cos(i *  twicePi / triangleAmount)),
                        E556 + (S553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E557 =0.026, E558 =0.089f, S554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E557, E558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E557 + (S554 * cos(i *  twicePi / triangleAmount)),
                        E558 + (S554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E559 =0.019, E5510 =0.10f, S555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E559, E5510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E559 + (S555 * cos(i *  twicePi / triangleAmount)),
                        E5510 + (S555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F505 =0.043, F551 =0.123f, S556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F505, F551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F505 + (S556 * cos(i *  twicePi / triangleAmount)),
                        F551 + (S556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F552 =0.07, F553 =0.12f, S557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F552, F553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F552 + (S557 * cos(i *  twicePi / triangleAmount)),
                        F553 + (S557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F554 =0.07, F555 =0.10f, S558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F554, F555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F554 + (S558 * cos(i *  twicePi / triangleAmount)),
                        F555 + (S558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();

        ///_________D 5th tree 3________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.55,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E5551 =0.062, E5552 =0.070f, S5551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E551, E552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E5551 + (S5551 * cos(i *  twicePi / triangleAmount)),
                        E5552 + (S5551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E5553 =0.057, E5554 =0.09f, S5552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5553, E5554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5553 + (S5552 * cos(i *  twicePi / triangleAmount)),
                        E5554 + (S5552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E5555 =0.04, E5556 =0.081f, S5553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5555, E5556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5555 + (S5553 * cos(i *  twicePi / triangleAmount)),
                        E5556 + (S5553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E5557 =0.026, E5558 =0.089f, S5554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5557, E5558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5557 + (S5554 * cos(i *  twicePi / triangleAmount)),
                        E5558 + (S5554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E5559 =0.019, E55510 =0.10f, S5555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5559, E55510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5559 + (S5555 * cos(i *  twicePi / triangleAmount)),
                        E55510 + (S5555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F5505 =0.043, F5551 =0.123f, S5556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5505, F5551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5505 + (S5556 * cos(i *  twicePi / triangleAmount)),
                        F5551 + (S5556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F5552 =0.07, F5553 =0.12f, S5557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5552, F5553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5552 + (S5557 * cos(i *  twicePi / triangleAmount)),
                        F5553 + (S5557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F5554 =0.07, F5555 =0.10f, S5558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5554, F5555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5554 + (S5558 * cos(i *  twicePi / triangleAmount)),
                        F5555 + (S5558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
     ///_________D 5th tree 4________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.75,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E55551 =0.062, E55552 =0.070f, S55551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5551, E5552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E55551 + (S55551 * cos(i *  twicePi / triangleAmount)),
                        E55552 + (S55551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E55553 =0.057, E55554 =0.09f, S55552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55553, E55554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55553 + (S55552 * cos(i *  twicePi / triangleAmount)),
                        E55554 + (S55552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E55555 =0.04, E55556 =0.081f, S55553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5555, E5556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55555 + (S55553 * cos(i *  twicePi / triangleAmount)),
                        E55556 + (S55553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E55557 =0.026, E55558 =0.089f, S55554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55557, E55558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55557 + (S55554 * cos(i *  twicePi / triangleAmount)),
                        E55558 + (S55554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E55559 =0.019, E555510 =0.10f, S55555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55559, E555510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55559 + (S55555 * cos(i *  twicePi / triangleAmount)),
                        E555510 + (S55555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F55505 =0.043, F55551 =0.123f, S55556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5505, F5551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55505 + (S55556 * cos(i *  twicePi / triangleAmount)),
                        F55551 + (S55556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F55552 =0.07, F55553 =0.12f, S55557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F55552, F55553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55552 + (S55557 * cos(i *  twicePi / triangleAmount)),
                        F55553 + (S55557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F55554 =0.07, F55555 =0.10f, S55558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F55554, F5555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55554 + (S55558 * cos(i *  twicePi / triangleAmount)),
                        F55555 + (S55558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();


     ///_________ D Building border ________///
     glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    ///_________ 7th floor ________///
    glVertex2f(0.98f,0.453f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.74f,0.439f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.75f,0.445f);

    glVertex2f(0.81f,0.453f);
    glVertex2f(0.81f,0.445f);
    glVertex2f(0.87f,0.453f);
    glVertex2f(0.87f,0.445f);
    glVertex2f(0.93f,0.453f);
    glVertex2f(0.93f,0.445f);
    ///_________ 5th floor ________///
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.98f,0.348f);
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.75f,0.335f);
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.76f,0.340f);

    glVertex2f(0.81f,0.348f);
    glVertex2f(0.81f,0.340f);

    glVertex2f(0.87f,0.348f);
    glVertex2f(0.87f,0.340f);

    glVertex2f(0.93f,0.348f);
    glVertex2f(0.93f,0.340f);
    ///_________ D window (1) ________///
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    glVertex2f(0.993f,0.56f);
    glVertex2f(0.993f,0.56f);
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    ///_________ D window (2) ________///
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    glVertex2f(0.993f,0.52f);
    glVertex2f(0.993f,0.52f);
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    ///_________ D window (3) ________///
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    glVertex2f(0.993f,0.48f);
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.993f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    ///_________ D window (4) ________///
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    glVertex2f(0.993f,0.44f);
    glVertex2f(0.993f,0.44f);
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    ///_________ D window (5) ________///
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    glVertex2f(0.993f,0.40f);
    glVertex2f(0.993f,0.40f);
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    ///_________ D window (6) ________///
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    glVertex2f(0.993f,0.36f);
    glVertex2f(0.993f,0.36f);
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    ///_________ D window (7) ________///
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    glVertex2f(0.993f,0.32f);
    glVertex2f(0.993f,0.32f);
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    ///_________ D window (8) ________///
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    glVertex2f(0.993f,0.28f);
    glVertex2f(0.993f,0.28f);
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    ///_________ D window (9) ________///
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    glVertex2f(0.993f,0.24f);
    glVertex2f(0.993f,0.24f);
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    ///_________ 1 ________///
    glVertex2f(0.95f,0.58f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(1.0f,0.61f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.98f,0.58f);
    ///_________ body 2 ________///
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.98f,0.58f);
    ///_________ 3 ________///
    glVertex2f(0.74f,0.545f);
    glVertex2f(0.98f,0.545f);
    glVertex2f(0.74f,0.565f);
    glVertex2f(0.98f,0.565f);
    ///_________ 4 ________///
    glVertex2f(0.74f,0.530f);
    glVertex2f(0.98f,0.530f);
    glVertex2f(0.74f,0.510f);
    glVertex2f(0.98f,0.510f);
    ///_________ 5 ________///
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.98f,0.495f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.98f,0.445f);
    ///_________ 6 ________///
    glVertex2f(0.74f,0.430f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.74f,0.495f);
    glVertex2f(0.75f,0.495f);
    ///_________ 7 ________///
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.98f,0.410f);
    glVertex2f(0.98f,0.43f);
    glVertex2f(0.75f,0.43f);
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.75f,0.43f);
    ///_________ 8 ________///
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.98f,0.390f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.98f,0.340f);
    ///_________ 9 ________///
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.75f,0.325f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.75f,0.325f);
    ///_________ 10 ________///
    glVertex2f(0.76f,0.325f);
    glVertex2f(0.98f,0.325f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.98f,0.305f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.76f,0.325f);
    ///_________ 11 ________///
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.98f,0.290f);
    glVertex2f(0.76f,0.270f);
    glVertex2f(0.98f,0.270f);
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.76f,0.270f);
    ///_________ 12 ________///
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.98f,0.255f);
    glVertex2f(0.76f,0.23f);
    glVertex2f(0.98f,0.23f);
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.76f,0.23f);
    ///_________ 13 ________///
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.98f,0.212f);
    glVertex2f(0.76f,0.2f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.76f,0.2f);
    ///_________ 14 ________///
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.68f,0.2f);
    glVertex2f(0.74f,0.43f);
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.74f,0.58f);
    ///_________ 15 ________///
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.405f);
    glVertex2f(0.732f,0.560f);
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.732f,0.560f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.2f);
    glVertex2f(0.732f,0.403f);
    glVertex2f(0.743f,0.420f);
    ///_________ 16 ________///
    glVertex2f(0.743f,0.3f);
    glVertex2f(0.743f,0.420f);
    ///_________ 17 ________///
    glVertex2f(0.7425f,0.30f);
    glVertex2f(0.753f,0.315f);

    glVertex2f(0.753f,0.2f);
    glVertex2f(0.753f,0.315f);

    glEnd();

    ///_________________________________________________FIELD(2)___________________________________________________///

    glBegin(GL_QUADS);
    glColor3f(0.69, 0.851, 0.31);
    glVertex2f(0.0f,0.16f);
    glColor3f(0.396, 0.671, 0.141);
    glVertex2f(0.0f,0.00f);
    glVertex2f(1.0f,0.00f);
    glColor3f(0.69, 0.851, 0.31);
    glVertex2f(1.0f,0.16f);
    glEnd();

///_________________________________________________ROAD(3)___________________________________________________///
    glBegin(GL_QUADS);
    glColor3f(0.004f, 0.0f, 0.004f);
    glVertex2f(0.0f,0.2f);
    glVertex2f(0.0f,0.16f);
    glVertex2f(1.0f,0.16f);
    glVertex2f(1.0f,0.2f);
    glEnd();

///_____________________________________________ROAD CROSS LINE(4)___________________________________________________///
    glBegin(GL_LINES);
    glColor3f(1.00f, 1.0f, 1.00f);
    ///_________1________///
    glVertex2f(0.10f,0.18f);
    glVertex2f(0.20f,0.18f);
    ///_________2________///
    glVertex2f(0.30f,0.18f);
    glVertex2f(0.40f,0.18f);
    ///_________3________///
    glVertex2f(0.50f,0.18f);
    glVertex2f(0.60f,0.18f);
    ///_________4________///
    glVertex2f(0.70f,0.18f);
    glVertex2f(0.80f,0.18f);
    ///_________5________///
    glVertex2f(0.90f,0.18f);
    glVertex2f(1.00f,0.18f);
    glEnd();



///_______________________________________________FIELD Trees(1-4)___________________________________________________///

    ///_________TREE 1________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.049f,0.0f);
    glVertex2f(0.049f,0.02f);
    glVertex2f(0.052f,0.02f);
    glVertex2f(0.052f,0.0f);
    ///_______Leaf 1_______///
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.075f,0.02f);
    glVertex2f(0.075f,0.04f);
    glVertex2f(0.025f,0.04f);
    glVertex2f(0.025f,0.02f);
    ///_______Leaf 2________///
    glVertex2f(0.03f,0.04f);
    glVertex2f(0.03f,0.06f);
    glVertex2f(0.07f,0.06f);
    glVertex2f(0.07f,0.04f);
    ///________Leaf 3_______///
    glVertex2f(0.035f,0.06f);
    glVertex2f(0.035f,0.08f);
    glVertex2f(0.0665f,0.08f);
    glVertex2f(0.0665f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.040f,0.08f);
    glVertex2f(0.05075f,0.12f);
    glVertex2f(0.0615f,0.08f);
    glEnd();

    ///_________TREE 2________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.109f,0.0f);
    glVertex2f(0.109f,0.02f);
    glVertex2f(0.112f,0.02f);
    glVertex2f(0.112f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.085f,0.02f);
    glVertex2f(0.085f,0.04f);
    glVertex2f(0.135f,0.04f);
    glVertex2f(0.135f,0.02f);
     ///_______Leaf 2_______///
    glVertex2f(0.09f,0.04f);
    glVertex2f(0.09f,0.06f);
    glVertex2f(0.13f,0.06f);
    glVertex2f(0.13f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.095f,0.06f);
    glVertex2f(0.095f,0.08f);
    glVertex2f(0.125f,0.08f);
    glVertex2f(0.125f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glVertex2f(0.10f,0.08f);
    glVertex2f(0.11f,0.12f);
    glVertex2f(0.12f,0.08f);
    glEnd();

    ///_________TREE 3________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.95f,0.0f);
    glVertex2f(0.95f,0.02f);
    glVertex2f(0.953f,0.02f);
    glVertex2f(0.953f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.925f,0.02f);
    glVertex2f(0.925f,0.04f);
    glVertex2f(0.975f,0.04f);
    glVertex2f(0.975f,0.02f);
    ///_______Leaf 2_______///
    glVertex2f(0.93f,0.04f);
    glVertex2f(0.93f,0.06f);
    glVertex2f(0.97f,0.06f);
    glVertex2f(0.97f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.935f,0.06f);
    glVertex2f(0.935f,0.08f);
    glVertex2f(0.965f,0.08f);
    glVertex2f(0.965f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.940f,0.08f);
    glVertex2f(0.95f,0.12f);
    glVertex2f(0.96f,0.08f);
    glEnd();

    ///_________TREE 4________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.89f,0.0f);
    glVertex2f(0.89f,0.02f);
    glVertex2f(0.893f,0.02f);
    glVertex2f(0.893f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.915f,0.02f);
    glVertex2f(0.915f,0.04f);
    glVertex2f(0.865f,0.04f);
    glVertex2f(0.865f,0.02f);
    ///_______Leaf 2_______///
    glVertex2f(0.91f,0.04f);
    glVertex2f(0.91f,0.06f);
    glVertex2f(0.87f,0.06f);
    glVertex2f(0.87f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.905f,0.06f);
    glVertex2f(0.905f,0.08f);
    glVertex2f(0.875f,0.08f);
    glVertex2f(0.875f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.900f,0.08f);
    glVertex2f(0.89f,0.12f);
    glVertex2f(0.880f,0.08f);
    glEnd();
     ///_________________________________________________transparent stand ___________________________________________________///
     ///_________ T2________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f,0.20f);
    glVertex2f(0.45f,0.27f);
    glVertex2f(0.45f,0.27f);
    glVertex2f(0.45f,0.20f);

    glVertex2f(0.44f,0.27f);
    glVertex2f(0.46f,0.27f);
    glVertex2f(0.44f,0.269f);
    glVertex2f(0.46f,0.269f);

    glVertex2f(0.36f,0.20f);
    glVertex2f(0.36f,0.27f);
    glVertex2f(0.36f,0.27f);
    glVertex2f(0.36f,0.20f);

    glVertex2f(0.35f,0.27f);
    glVertex2f(0.37f,0.27f);

    glVertex2f(0.35f,0.269f);
    glVertex2f(0.37f,0.269f);

    glEnd();
    ///_________________________________________________TOP LAMP POST ___________________________________________________///
    ///_________ T1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.075f,0.2f);
    glVertex2f(0.075f,0.28f);
    glVertex2f(0.075f,0.28f);
    glVertex2f(0.08f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.08f, 0.27f);
    glEnd();
    ///_________ T2________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.25f,0.2f);
    glVertex2f(0.25f,0.28f);
    glVertex2f(0.25f,0.28f);
    glVertex2f(0.255f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.255f, 0.27f);
    glEnd();
    ///_________ T3________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.62f,0.2f);
    glVertex2f(0.62f,0.28f);
    glVertex2f(0.62f,0.28f);
    glVertex2f(0.625f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.625f, 0.27f);
    glEnd();
    ///_________ T4________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.77f,0.2f);
    glVertex2f(0.77f,0.28f);
    glVertex2f(0.77f,0.28f);
    glVertex2f(0.775f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.775f, 0.27f);
    glEnd();
    ///_________ T5________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.94f,0.2f);
    glVertex2f(0.94f,0.28f);
    glVertex2f(0.94f,0.28f);
    glVertex2f(0.945f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.945f, 0.27f);
    glEnd();


///______________________________________________________CAR___________________________________________________///
///........................................Bus-1
   glPushMatrix();
    glTranslatef(carX, 0.0, 0.0);  // Move the car horizontally
    glBegin(GL_QUADS);
    glColor3f(0.78f,0.137f,0.204f);
    glVertex2f(0.14f,0.175f);
    glVertex2f(0.14f,0.225f);
    glVertex2f(0.27f,0.225f);
    glVertex2f(0.27f,0.175f);
    ///Front Side Extra Part
    glVertex2f(0.27f,0.175f);
    glVertex2f(0.273f,0.175f);
    glVertex2f(0.273f,0.2f);
    glVertex2f(0.27f,0.205f);
    ///Window Slide Green Part
    glColor3f(0.031f,0.125f,0.059f);
    glVertex2f(0.143f,0.205f);
    glVertex2f(0.143f,0.223f);
    glVertex2f(0.268f,0.223f);
    glVertex2f(0.268f,0.205f);
    ///Window
    ///1. (Left To Right)
    glColor3f(0.655f,0.725f,0.725f);
    glVertex2f(0.1445f,0.207f);
    glVertex2f(0.1445f,0.221f);
    glVertex2f(0.157f,0.221f);
    glVertex2f(0.157f,0.207f);
    ///2.
    glVertex2f(0.159f,0.207f);
    glVertex2f(0.159f,0.221f);
    glVertex2f(0.173f,0.221f);
    glVertex2f(0.173f,0.207f);
    ///3.
    glVertex2f(0.175f,0.207f);
    glVertex2f(0.175f,0.221f);
    glVertex2f(0.1885f,0.221f);
    glVertex2f(0.1885f,0.207f);
    ///4.
    glVertex2f(0.191f,0.207f);
    glVertex2f(0.191f,0.221f);
    glVertex2f(0.205f,0.221f);
    glVertex2f(0.205f,0.207f);
    ///5.
    glVertex2f(0.207f,0.207f);
    glVertex2f(0.207f,0.221f);
    glVertex2f(0.222f,0.221f);
    glVertex2f(0.222f,0.207f);
    ///6.
    glVertex2f(0.245f,0.207f);
    glVertex2f(0.245f,0.221f);
    glVertex2f(0.258f,0.221f);
    glVertex2f(0.258f,0.207f);
    ///7.
    glVertex2f(0.26f,0.207f);
    glVertex2f(0.26f,0.221f);
    glVertex2f(0.266f,0.221f);
    glVertex2f(0.266f,0.207f);
    ///......Door
    glVertex2f(0.225f,0.175f);
    glVertex2f(0.225f,0.217f);
    glVertex2f(0.243f,0.217f);
    glVertex2f(0.243f,0.175f);
    glEnd();
    ///....Bus Door Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.234f,0.175f);
    glVertex2f(0.234f,0.219f);
    ///.....Side Mirror Stand
    glColor3f(0.78f,0.137f,0.204f);
    glVertex2f(0.27f,0.22f);
    glVertex2f(0.277f,0.22f);
    glEnd();
    ///........Side Mirror
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.277f,0.22f);
    glVertex2f(0.277f,0.205f);
    glEnd();
    ///...........Bus Tier Right
    GLfloat A50=0.257f; GLfloat P50=0.175f; GLfloat O50 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A50, P50); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A50 + (O50 * cos(i *  twicePi/ triangleAmount)),
                        P50 + (O50 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Right
    GLfloat A51=0.257f; GLfloat P51=0.175f; GLfloat O51 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A51, P51); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A51 + (O51 * cos(i *  twicePi/ triangleAmount)),
                        P51 + (O51 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier left
    GLfloat A52=0.166f; GLfloat P52=0.175f; GLfloat O52 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A52, P52); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A52 + (O52 * cos(i *  twicePi/ triangleAmount)),
                        P52 + (O52 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Left
    GLfloat A53=0.166f; GLfloat P53=0.175f; GLfloat O53 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A53, P53); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A53 + (O53 * cos(i *  twicePi/ triangleAmount)),
                        P53 + (O53 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
///______________________________________________________CAR___________________________________________________///
///...........................................Bus-2
    glPushMatrix();
    glTranslatef(+0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.114f,0.18f,0.612f);
    glVertex2f(0.14f,0.175f);
    glVertex2f(0.14f,0.225f);
    glVertex2f(0.27f,0.225f);
    glVertex2f(0.27f,0.175f);
    ///Front Side Extra Part
    glVertex2f(0.27f,0.175f);
    glVertex2f(0.273f,0.175f);
    glVertex2f(0.273f,0.2f);
    glVertex2f(0.27f,0.205f);
    ///Window Slide Green Part
    glColor3f(0.031f,0.125f,0.059f);
    glVertex2f(0.143f,0.205f);
    glVertex2f(0.143f,0.223f);
    glVertex2f(0.268f,0.223f);
    glVertex2f(0.268f,0.205f);
    ///Window
    ///1. (Left To Right)
    glColor3f(0.655f,0.725f,0.725f);
    glVertex2f(0.1445f,0.207f);
    glVertex2f(0.1445f,0.221f);
    glVertex2f(0.157f,0.221f);
    glVertex2f(0.157f,0.207f);
    ///2.
    glVertex2f(0.159f,0.207f);
    glVertex2f(0.159f,0.221f);
    glVertex2f(0.173f,0.221f);
    glVertex2f(0.173f,0.207f);
    ///3.
    glVertex2f(0.175f,0.207f);
    glVertex2f(0.175f,0.221f);
    glVertex2f(0.1885f,0.221f);
    glVertex2f(0.1885f,0.207f);
    ///4.
    glVertex2f(0.191f,0.207f);
    glVertex2f(0.191f,0.221f);
    glVertex2f(0.205f,0.221f);
    glVertex2f(0.205f,0.207f);
    ///5.
    glVertex2f(0.207f,0.207f);
    glVertex2f(0.207f,0.221f);
    glVertex2f(0.222f,0.221f);
    glVertex2f(0.222f,0.207f);
    ///6.
    glVertex2f(0.245f,0.207f);
    glVertex2f(0.245f,0.221f);
    glVertex2f(0.258f,0.221f);
    glVertex2f(0.258f,0.207f);
    ///7.
    glVertex2f(0.26f,0.207f);
    glVertex2f(0.26f,0.221f);
    glVertex2f(0.266f,0.221f);
    glVertex2f(0.266f,0.207f);
    ///......Door
    glVertex2f(0.225f,0.175f);
    glVertex2f(0.225f,0.217f);
    glVertex2f(0.243f,0.217f);
    glVertex2f(0.243f,0.175f);
    glEnd();
    ///....Bus Door Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.234f,0.175f);
    glVertex2f(0.234f,0.219f);
    ///.....Side Mirror Stand
    glColor3f(0.114f,0.18f,0.612f);
    glVertex2f(0.27f,0.22f);
    glVertex2f(0.277f,0.22f);
    glEnd();
    ///........Side Mirror
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.277f,0.22f);
    glVertex2f(0.277f,0.205f);
    glEnd();
    ///...........Bus Tier Right
    GLfloat A54=0.257f; GLfloat P54=0.175f; GLfloat O54 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A54, P54); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A54 + (O54 * cos(i *  twicePi/ triangleAmount)),
                        P54 + (O54 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Right
    GLfloat A55=0.257f; GLfloat P55=0.175f; GLfloat O55 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A55, P55); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A55 + (O55 * cos(i *  twicePi/ triangleAmount)),
                        P55 + (O55 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier left
    GLfloat A56=0.166f; GLfloat P56=0.175f; GLfloat O56 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A56, P56); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A56 + (O56 * cos(i *  twicePi/ triangleAmount)),
                        P56 + (O56 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Left
    GLfloat A57=0.166f; GLfloat P57=0.175f; GLfloat O57 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A57, P57); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A57 + (O57 * cos(i *  twicePi/ triangleAmount)),
                        P57 + (O57 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glutPostRedisplay();

    glPopMatrix();
    glPopMatrix();



///_________________________________________________DOWN LAMP POST ___________________________________________________///
    ///_________ D1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.165f,0.16f);
    glVertex2f(0.165f,0.24f);
    glVertex2f(0.165f,0.24f);
    glVertex2f(0.17f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.17f, 0.23f);
    glEnd();
    ///_________ D2 ________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.33f,0.16f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.335f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.335f, 0.23f);
    glEnd();
    ///_________ D3________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.69f,0.16f);
    glVertex2f(0.69f,0.24f);
    glVertex2f(0.69f,0.24f);
    glVertex2f(0.695f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.695f, 0.23f);
    glEnd();
    ///_________ D4________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.85f,0.16f);
    glVertex2f(0.85f,0.24f);
    glVertex2f(0.85f,0.24f);
    glVertex2f(0.855f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.855f, 0.23f);
    glEnd();
///______________________________________________________Soil___________________________________________________///
    ///_______soil 2______///
    GLfloat sp=0.485f;GLfloat sp1=0.023f;GLfloat o1 =.05f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp, sp1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp + (o1 * cos(i *  twicePi / triangleAmount)),
                    sp1 + (o1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///_______soil 2 border______///
     glColor3f(0.0,0.0,0.0);
    GLfloat sp411=0.485f;GLfloat sp111=0.023f;GLfloat o111 =.05f;
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp411, sp111); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {glColor3f(0.0,0.0,0.0);
        glVertex2f( sp411 + (o111 * cos(i *  twicePi / lineAmount)),
                    sp111 + (o111 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();
    ///_______soil 1______///
    GLfloat sp4=0.38f;GLfloat sp5=0.021f;GLfloat o3 =.08f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp4, sp5); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp4+ (o3 * cos(i *  twicePi / triangleAmount)),
                    sp5 + (o3 * sin(i * twicePi / triangleAmount)) );
    }
     glEnd();
    ///_______soil 3______///
    GLfloat sp2 =0.60f;GLfloat sp3=0.023f;GLfloat o2 =.09f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp2, sp3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp2 + (o2 * cos(i *  twicePi / triangleAmount)),
                    sp3 + (o2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///______________________________________________________Soil border___________________________________________________///
    ///_______soil 1 border______///
    GLfloat sp114=0.38f;GLfloat sp115=0.021f;GLfloat o113 =.08f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp114, sp115); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( sp114+ (o113 * cos(i *  twicePi /lineAmount)),
                    sp115 + (o113 * sin(i * twicePi / lineAmount)) );
    }
     glEnd();
    ///_______soil 3 Border______///
    glColor3f(0.0,0.0,0.0);
    GLfloat sp112 =0.60f;GLfloat sp113=0.023f;GLfloat o112 =.09f;
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp112, sp113); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {glColor3f(0.0,0.0,0.0);
        glVertex2f( sp112 + (o112 * cos(i *  twicePi / lineAmount)),
                    sp113 + (o112 * sin(i * twicePi / lineAmount)) );

    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.898f, 0.651f, 0.502f);
    glVertex2f(0.35,0.059);
    glVertex2f(0.35,0.0);
    glVertex2f(0.67,0.0);
    glVertex2f(0.67,0.06);
    glEnd();
///______________________________________________________Pool___________________________________________________///
    ///_______pool 2 border______///
    GLfloat spp21=0.485f;GLfloat spp11=0.023f;GLfloat op11 =.04f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp21, spp11); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp21 + (op11 * cos(i *  twicePi / lineAmount)),
                    spp11 + (op11 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();

     ///_______pool 1______///
    GLfloat sp14=0.38f;GLfloat sp15=0.021f;GLfloat o13 =.07f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp14, sp15); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp14+ (o13 * cos(i *  twicePi / triangleAmount)),
                    sp15 + (o13 * sin(i * twicePi / triangleAmount)) );
    }
     glEnd();

     ///_______pool 2______///
    GLfloat sp21=0.485f;GLfloat sp11=0.023f;GLfloat o11 =.04f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp21, sp11); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp21 + (o11 * cos(i *  twicePi / triangleAmount)),
                    sp11 + (o11 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///_______pool 3______///
    GLfloat sp12 =0.60f;GLfloat sp13=0.023f;GLfloat o12 =.08f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp12, sp13); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp12 + (o12 * cos(i *  twicePi / triangleAmount)),
                    sp13 + (o12 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
///______________________________________________________Pool border___________________________________________________///

///_______pool 1______///
    GLfloat spp14=0.38f;GLfloat spp15=0.021f;GLfloat op13 =.07f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp14, spp15); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp14+ (op13 * cos(i *  twicePi / lineAmount)),
                    spp15 + (op13 * sin(i * twicePi / lineAmount)) );
    }
     glEnd();


    ///_______pool 3______///
    GLfloat spp12 =0.60f;GLfloat spp13=0.023f;GLfloat op12 =.08f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp12, spp13); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp12 + (op12 * cos(i *  twicePi / lineAmount)),
                    spp13 + (op12 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.443, 0.78, 0.898);
    glVertex2f(0.35,0.039);
    glVertex2f(0.35,0.0);
    glVertex2f(0.67,0.0);
    glVertex2f(0.67,0.039);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.443, 0.78, 0.898);
    glVertex2f(0.67,0.024);
    glVertex2f(0.679,0.024);
    glColor3f(0.898f, 0.651f, 0.502f);
    glVertex2f(0.681,0.024);
    glVertex2f(0.69,0.024);
    glEnd();


     glFlush(); // Render now
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("The Project : Rocket"); // Create a window with the given title
    glutFullScreen();
    init();
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display2); // Register display callback handler for window re-paint
    glutTimerFunc(0, timer, 0);  // Start the timer
    glutKeyboardFunc(keyboard);  // Register keyboard function
    glutTimerFunc(0, updatef, 0);
    glutIdleFunc(Idle);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
