
#include <stdio.h> 
#include <stdlib.h>
/*** freeglut***/
#include ".\GL\freeglut.h"
 
void ChangeSize(int , int );					 
void RenderScene(void);							 

//參數放這做全域變數
double tx = 0, ty = 0, tz = 0;		//座標
double thetaX = 0, thetaY = 0, thetaZ = 0;		//角度



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
   
   
   glColor3f(1.0f, 0.0f, 0.0f); //畫紅色X軸
   glBegin(GL_LINES);
   glVertex3f(-8.0f, 0.0f, 0.0f);
   glVertex3f(8.0f, 0.0f, 0.0f);
   glEnd();

   glColor3f(0.0, 1.0, 0.0); //畫綠色Y軸
   glBegin(GL_LINES);
   glVertex3f(0.0f, -8.0f, 0.0f);
   glVertex3f(0.0f, 8.0f, 0.0f);
   glEnd();

   
   


   //這邊對XYZ軸個別做旋轉動作
   glRotatef(thetaX, 0, -1, 0);
   glRotatef(thetaY, -1, 0, 0);
   glRotatef(thetaZ, 0, 0, -1);
 

   glTranslatef(tx, 0, 0);
   glTranslatef(0, ty, 0);
   glTranslatef(0, 0, tz);



   glColor3f(1, 1, 0);
   glutSolidCube(6);
   glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y) {	//change thetaX~Z
	switch (key) {
		case 'r':
			thetaX = 0, thetaY = 0, thetaZ = 0;
			tx = 0, ty = 0, tz = 0;
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


	glutMainLoop();	//http://www.programmer-club.com.tw/ShowSameTitleN/opengl/2288.html
	return 0;
}