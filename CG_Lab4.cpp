
#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
/*** freeglut***/
#include ".\GL\freeglut.h"

//#include <freeglut.h>
#include <iostream>

#define PI 3.13159265 

void ChangeSize(int , int );					 
void RenderScene(void);							 

//�ѼƩ�o�������ܼ�
double tx = 0, ty = 0, tz = 0;		//�y��
double thetaX = 0, thetaY = 0, thetaZ = 0;		//����
double mx = 0, my = 0;	//�ƹ��I�����y��
int openX = 0, openY = 0;
int buttonFlag = 0;


using namespace std;

GLfloat toSin(float thetaVar) {
	float degree = thetaVar;
	float result = sin(degree*PI / 180.0);
	return result;
}

GLfloat toCos(float thetaVar) {
	float degree = thetaVar;
	float result = cos(degree*PI / 180.0);
	return result;
}



void SetupRC() {
	GLfloat whiteLight[] = {0.45f,0.45f,0.45f,1.0f};
	GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
	GLfloat lightPos[] = {0.f, 25.0f, 20.0f,0.0f};

	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT0, GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
}

void ChangeSize(int w, int h) 
{ 
   glViewport(0, 0, w, h);            
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   glOrtho(-10,10,-10,10,-10,20);      
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
} 
void RenderScene(void) 
{ 
   glClearColor(1.0, 1.0, 1.0, 1.0);     
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   gluLookAt(0,0,10.0f,0,0,0,0,1,0);   

   glColor3f(1.0f, 0.0f, 0.0f); //�e����X�b
   glBegin(GL_LINES);
   glVertex3f(-8.0f, 0.0f, 0.0f);
   glVertex3f(8.0f, 0.0f, 0.0f);
   glEnd();

   glColor3f(0.0, 1.0, 0.0); //�e���Y�b
   glBegin(GL_LINES);
   glVertex3f(0.0f, -8.0f, 0.0f);
   glVertex3f(0.0f, 8.0f, 0.0f);
   glEnd();


   //Lab4

   //������ù��W���I�A�o�䪺�p�⦳�I���վ�
   openX = ((mx / 400 * 22 - 11));
   openY = ((my / 400 * 22 - 11));
   //cout << "openX and openY is : " << openX << "�B" << openY << endl;

   //���s���ɭԧ�openX�BY�]��0,0(����)
   if (mx == 0 && my == 0) {
	   openX += 11;
	   openY += 11;
   }

   //�e�X�����I�����I
   glPointSize(20);
   glBegin(GL_POINTS);
   glColor3f(1.0f, 0.0f, 1.0f);	//����
   glVertex3f(openX, openY, 0);
   glEnd();
   glFlush();

   //�e�u
   glColor3f(0.0, 1.0, 0.0); //�e���s�ƹ��I�������u
   glBegin(GL_LINES);
   glVertex3f(tx, ty, tz);
   glVertex2i(openX, openY);
   glEnd();
   

   //���XYZ�ӧO������x�}
   GLfloat rotMatrix1[16] = {1.0, 0.0, 0.0, 0.0,
                             0.0, toCos(thetaX),  toSin(thetaX), 0.0,
	                         0.0, -toSin(thetaX), toCos(thetaX), 0.0,
                             0.0, 0.0, 0.0, 1.0
   };

	   
   GLfloat rotMatrix2[16] = {toCos(thetaY), 0.0, -toSin(thetaY), 0.0,
							 0.0, 1.0, 0.0, 0.0,
							 toSin(thetaY), 0, toCos(thetaY), 0.0,
							 0, 0, 0, 1.0
   };

   GLfloat rotMatrix3[16] = {toCos(thetaZ), toSin(thetaZ), 0.0, 0.0,
							 -toSin(thetaZ), toCos(thetaZ), 0.0, 0.0,
							 0.0, 0.0, 1.0, 0.0,
							 0.0, 0.0, 0.0, 1.0
   };

   //���XYZ�������x�}
   GLfloat translateMatrix[16] = {1.0, 0.0, 0.0, 0.0,
								  0.0, 1.0, 0.0, 0.0,
								  0.0, 0.0, 1.0, 0.0,
								  tx, ty, tz, 1.0
   };


   //���scale�x�}(��j1.5��)
   /*GLfloat scaleMatrix[16] = { 1.5, 0.0, 0.0, 0.0,
								  0.0, 1.5, 0.0, 0.0,
								  0.0, 0.0, 1.5, 0.0,
								  0.0, 0.0, 0.0, 1.0
   };*/


   //��������¶�b����x�}���Ƚw�A�g���X��
   /*
   GLfloat csMatrix[] = {
	   toCos(thetaX) + ((1 - toCos(thetaX))*openX*openX),
	   (1 - toCos(thetaX)*openX*openY) + toSin(thetaX) * 0,
	   (1 - toCos(thetaX))*openX*openY - toSin(thetaX)*openY,
	   0,
	   (1 - toCos(thetaX))*openX*openY - toSin(thetaX) * 0,
	   toCos(thetaX) + (1 - toCos(thetaX)*openY*openY),
	   1 - toCos(thetaX)*openX*openY + toSin(thetaX)*openX,
	   0,
	   (1 - toCos(thetaX)*openX * 0 + toSin(thetaX)*openY),
	   (1 - toCos(thetaX)*openY * 0 - toSin(thetaX)*openX),
	   toCos(thetaX) + (1 - toCos(thetaX) * 0 * 0),
	   0,
	   0,
	   0,
	   0,
	   1
   };
   */

   //�o���XYZ�b�ӧO������ʧ@(�쪩)
   //glRotatef(thetaX, 0, -1, 0);
   //glRotatef(thetaY, -1, 0, 0);
   //glRotatef(thetaZ, 0, 0, -1);

   //�����g
   glMultMatrixf(rotMatrix1);	//X
   glMultMatrixf(rotMatrix2);	//Y
   glMultMatrixf(rotMatrix3);	//Z



   //�o��勵����h������
   //glTranslatef(tx, ty, tz);

   //������g
   glMultMatrixf(translateMatrix);

   //�o�䰵scaling
   //glMultMatrixf(scaleMatrix);

   
   //��S�w�b����
   /*
   if (buttonFlag == TRUE) {
	   glMultMatrixf(csMatrix);
   }
   */

   glColor3f(1, 1, 0);
   glutSolidCube(6);
   glutSwapBuffers();
}

void rotateMatrix(float theta, GLfloat X, GLfloat Y, GLfloat Z) {
	//MatrixReset();

	//���W��
	double magnitude = sqrt(X*X + Y * Y + Z * Z);
	if (magnitude == 0) {
		throw ERROR;
	}
	X /= magnitude;
	Y /= magnitude;
	Z /= magnitude;

	//�}�l��
	GLfloat Cos = cos(theta*(2 * PI / 360));
	GLfloat Sin = sin(theta*(2 * PI / 360));
	//glMultMatrixf(csMatrix);

	//���x�}
}


void myKeyboard(unsigned char key, int x, int y) {	//change thetaX~Z
	switch (key) {
		case 'r':
			thetaX = 0, thetaY = 0, thetaZ = 0;
			tx = 0, ty = 0, tz = 0;
			//Lab4�����m�ƹ��I���ܥ�����
			mx = 0, my = 0;
			break;
		case 'a':
			thetaX += 3;
			break;
		case 'd':
			thetaX -= 3;
			break;
		case 'w':
			thetaY += 3;
			break;
		case 's':
			thetaY -= 3;
			break;
		case 'z':
			thetaZ += 3;
			break;
		case 'x':
			thetaZ -= 3;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void mySpecialKey(int key, int x, int y) {	//change tx~z
	switch (key)
	{
	case GLUT_KEY_LEFT:
		tx -= 0.2;
		break;
	case GLUT_KEY_RIGHT:
		tx += 0.2;
		break;
	case GLUT_KEY_UP:
		ty += 0.2;
		break;
	case GLUT_KEY_DOWN:
		ty -= 0.2;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void My_Mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				cout << "mouse left button down" << endl;
				cout << "x = " << x << endl;
				mx = x;
				cout << "y = " << 400 - y << endl;
				my = 400 - y;
				buttonFlag = 1;
				
			}

	}
	glutPostRedisplay();
}




int main(int argc, char** argv)
{
	//int tx = 0, ty = 0, tz = 0;
	//int thetaX = 0, thetaY = 0, thetaZ = 0;
	//

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(600, 80);
	glutCreateWindow("moving cube");
	SetupRC();

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKey);

	glutMouseFunc(My_Mouse);

	glutMainLoop();	//http://www.programmer-club.com.tw/ShowSameTitleN/opengl/2288.html
	return 0;
}