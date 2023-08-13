#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

# define PI           3.14159265358979323846
int triangleAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	int i;
	int lineAmount;
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;

GLfloat speed = 0.09f;
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
void display() {
	glClearColor(0.f, 0.f, 0.f, .0f); // Set background color to gray and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	////Small Star
	glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.9f,0.9f);
	glVertex2f(0.01f,0.8f);
	glVertex2f(0.1f,0.7f);
	glVertex2f(0.95f,0.15f);
	glVertex2f(0.76f,0.26f);
	glVertex2f(0.70f,0.36f);
	glEnd();

	glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POINTS);
    glVertex2f(0.14f,0.74f);
	glVertex2f(0.04f,0.34f);
	glVertex2f(0.84f,0.24f);
	glVertex2f(0.93f,0.33f);
	glEnd();


    ///circle1
	GLfloat m0=0.45f; GLfloat g0=0.45f; GLfloat h0 =.35f;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m0, g0); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( m0+ (h0 * cos(i *  twicePi / triangleAmount)),
                        g0 + (h0 * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	///circle2
	GLfloat m01=0.53f; GLfloat g01=0.53f; GLfloat h01 =.35f;
	glColor3f(.0f, .0f, .0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m01, g01); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( m01+ (h01 * cos(i *  twicePi / triangleAmount)),
                        g01 + (h01 * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	///Text
	glPushMatrix();
	glTranslatef(0.0f, -0.10f, 0.0f);
	glColor3f(0.835f, 0.902f, 0.733f);
	//glColor3f(0.996f, 0.843f, 0.4f);

    renderBitmapString(0.30f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AMERICAN INTERNATION UNIVERSITY BANGLADESH");
    renderBitmapString(0.45f, 0.85f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN");
    renderBitmapString(0.44f, 0.80f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT MOON QUEST");
    //renderBitmapString(0.30f, 0.70f, 0.0f, GLUT_BITMAP_9_BY_15, "ID:21-45744-3  NAME:AL_NAFI");
    renderBitmapString(0.30f, 0.70f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:21-45744-3  NAME:AL_NAFI");
    renderBitmapString(0.30f, 0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18 , "ID:21-45745-3  NAME:SUMAIYA SULTANA TARIN");
    renderBitmapString(0.30f, 0.60f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:21-45443-3  NAME:ZANNATUS SURIYA SUCY");
    renderBitmapString(0.30f, 0.55f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:21-45726-3  NAME:APON KUMAR DAS");
    renderBitmapString(0.30f, 0.50f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:21-45818-3  NAME:MST.UMMAY FATEMA MIM");
    glPopMatrix();
    ///Point
    glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.6f,0.4f);
	glVertex2f(0.4f,0.24f);
	glVertex2f(0.54f,0.20f);
	glVertex2f(0.70f,0.16f);
	glVertex2f(0.8f,0.8f);
	glVertex2f(0.9f,0.94f);
	glVertex2f(0.94f,0.70f);
	glVertex2f(0.7f,0.66f);
	glColor3f(1.0f,.0f,1.0f);
	glVertex2f(0.07f,1.36f);
	glEnd();

    ///STAR1
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.60f,0.6f,0.0f);
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

    ///STAR2
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.30f,0.10f,0.0f);
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
    ///STAR3
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.40f,1.20f,0.0f);
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
    ///STAR3
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.20f,0.0f,0.0f);
	glTranslatef(1.20f,0.0f,0.0f);
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
    ///STAR4
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.05f,1.70f,0.0f);
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
    ///STAR5
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.5f,.05f,0.0f);
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
    ///STAR6
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.65f,1.50f,0.0f);
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
    //STAR7
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.9f,.70f,0.0f);
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
     ///STAR9
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.07f,.80f,0.0f);
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

    ///STAR13
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.30f,1.88f,0.0f);
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


     ///Point
    glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.16f,0.94f);
	glVertex2f(0.04f,0.84f);
	glVertex2f(.54f,.980f);
	glVertex2f(0.70f,0.96f);
	glVertex2f(.79f,0.98f);
	glVertex2f(.49f,0.04f);
	glVertex2f(.54f,0.70f);
	glVertex2f(.67f,0.46f);
	glVertex2f(.67f,.06f);
	glEnd();
	     ///Point
    glPointSize(2.5);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.6f,0.04f);
	glVertex2f(0.04f,0.24f);
	glVertex2f(.54f,.28f);
	glVertex2f(0.70f,0.26f);
	glVertex2f(.39f,0.08f);
	glVertex2f(.89f,0.44f);
	glVertex2f(.94f,0.79f);
	glVertex2f(.17f,0.04f);
	glVertex2f(.07f,.26f);
	glEnd();
    ///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.50f,1.30f,0.0f);
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
    ///Fire
    ///_________ Fire main 0________///
    /*glBegin(GL_POLYGON);
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
    glEnd();*/
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


	glFlush();  // Render now
}
void update(int value)
{
    if(position < -1.5)
            position = 1.5f;

    if(position2 > 1.5)
            position2 = .01f;

    if(position3 < -2.0)
            position3 = 2.0f;

    position -= speed;
    position2 += speed;
    position3 -= speed;
	glutPostRedisplay();
	glutTimerFunc( 100,update, 0);
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
	glutTimerFunc( 100,update2, 0);
}
void SpecialInput(int key, int x, int y)
{
    switch(key)
    {

        case GLUT_KEY_LEFT:
            glutTimerFunc( 100,update, 0);
            break;

       case GLUT_KEY_RIGHT:
            glutTimerFunc( 100,update2, 0);
            break;

        case GLUT_KEY_UP:

            speed = speed - 0.01;
            break;

        case GLUT_KEY_DOWN:

            speed = speed + 0.01;
            break;
    }
    glutPostRedisplay();
}
void init(void){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(1400, 800);   // Set the window's initial width & height
	glutCreateWindow("Front Page"); // Create a window with the given title
    glutPositionWindow(0, 0);   // Change to the position of the current window.
    init();
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	glutSpecialFunc(SpecialInput);
	return 0;
}
