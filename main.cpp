#include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

double p=0.0;
int counter=0;
double a=0.0,b=0.0,c=25.0;
int mark=1;
GLfloat	l_t=0;
GLuint texture[50];
void LoadGLTextures()
{
	AUX_RGBImageRec* TextureImage;

	glGenTextures(50,texture);

	if (TextureImage = auxDIBImageLoad("left.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("right.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("front.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("back.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("top.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("bottom.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("nightleft.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("nightright.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("earth.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
}

void earth()
{
   // glColor3f(0.0f,1.0f,0.0f);
   // GLuint textureHandle;
    //glBindTexture(GL_TEXTURE_2D, textureHandle);

    glBindTexture(GL_TEXTURE_2D, texture[8]);

	// render as a GLU sphere quadric object
	GLUquadricObj* quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);
	gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric,6.0,100,10);
}

void day()
{
   // glClearColor (0.0, 0.0, 1.0, 0.0);
    // Draw A Quad

       glBindTexture(GL_TEXTURE_2D, texture[0]);
           glBegin(GL_QUADS);


            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)
        glEnd();

       glBindTexture(GL_TEXTURE_2D, texture[1]);
           glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)

            glEnd();

             glBindTexture(GL_TEXTURE_2D, texture[4]);
             glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)
            glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[5]);
           glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)

           glEnd();

             glBindTexture(GL_TEXTURE_2D, texture[3]);
            glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture[2]);
            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom Right Of The Quad (Front)

        glEnd();
}

void night()
{
    //glClearColor (0.0, 0.0, 0.0, 0.0);
    // Draw A Quad

       glBindTexture(GL_TEXTURE_2D, texture[6]);
           glBegin(GL_QUADS);


            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)
        glEnd();

       glBindTexture(GL_TEXTURE_2D, texture[6]);
           glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)

            glEnd();

             glBindTexture(GL_TEXTURE_2D, texture[6]);
             glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)
            glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[6]);
           glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)

           glEnd();

             glBindTexture(GL_TEXTURE_2D, texture[6]);
            glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture[7]);
            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom Right Of The Quad (Front)

        glEnd();
}


void init(void)
{

   LoadGLTextures();
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix

   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(40,w/h,0.1,100);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );
   glPushMatrix();
   // glTranslatef(0.0f,0.0f,-20.0f);
   glRotatef(l_t,0.0f,1.0f,0.0f);

   glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0.0f,0.0f,3.0f);
   earth();
   glPopMatrix();
    glTranslatef(0.0f,0.0f,-3.0f);
   if(p<43.0)
   {

       p=p+0.002;
    }
    else {p=0.0;
    counter++;
    }
   if (counter%2==0) night();
   else day();
   glutPostRedisplay();
   //printf("p=%lf ",p);
   if(c==25.0 && mark==1)
    mark=0;
   if(mark==0)
    c=c-0.002;
   if(c<=4.0 && mark==0)
    mark=1;
   if(mark==1)
    c=c+0.002;
   // printf("c=%lf ",c);
   glutPostRedisplay();

   glDisable(GL_TEXTURE_2D);

    glPopMatrix();

   glFlush(); // Force execution of GL commands in finite time

}

//void my_keyboard(unsigned char key, int p, int q)
//{
//switch (key)
//{
//    case 'f':  //front view
//        a=0.0,b=0.0,c=15.0,l_t=0;
//        glutPostRedisplay();
//		break;
//    case 'l':  //left view
//        a=-100.0,b=0.0,c=4.0,l_t=0.0;
//        glutPostRedisplay();
//		break;
//    case 'r':  //right view
//        a=100.0,b=0.0,c=5.0,l_t=0.0;
//        glutPostRedisplay();
//		break;
//    case 'b':  //back view
//        a=0.0,b=0.0,c=-15.0,l_t=0.0;
//        glutPostRedisplay();
//		break;
//    case 't': //top view
//        a=0.0,b=100.0,c=4.0,l_t=0.0;
//        glutPostRedisplay();
//		break;
//
//    case 'm': //bottom view
//        a=0.0,b=-100.0,c=5.0,l_t=0.0;
//        glutPostRedisplay();
//		break;
//     default:
//        break;
//}
//}

//void spinDisplay_left(void)		//spin speed
//{
//
//    l_t =l_t+0.2;
//    glutPostRedisplay();
//}

void specialKeys(int key,int x,int y)
{
//    if(key==GLUT_KEY_RIGHT)
//    {
//        // printf (" right a=%lf",a);
//           a+=0.02;
//    }

//    else if(key==GLUT_KEY_LEFT)
//    {
//        //printf (" left a=%lf",a);
//            a-=0.02;
//    }

    if(key==GLUT_KEY_UP)
    {  c--;
        //printf ("c=%lf",c);

    }

   else if(key==GLUT_KEY_DOWN)
            c++;
    glutPostRedisplay();
}

//void mouse(int button, int state, int s, int t)
//{
//
//   switch (button)
//   {
//      case GLUT_LEFT_BUTTON:
//         if (state == GLUT_DOWN)
//            glutIdleFunc(spinDisplay_left);
//         break;
//      case GLUT_RIGHT_BUTTON:
//         if (state == GLUT_DOWN)
//            glutIdleFunc(NULL);
//         break;
//      default:
//         break;
//   }
//}

int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("3D View of a Quad");
	init();

    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
  //  glutKeyboardFunc(my_keyboard);
   // glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
