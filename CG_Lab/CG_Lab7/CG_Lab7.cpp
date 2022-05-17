#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#include "D:/MyNTUT/ComputerGraphic/CGRes/FinalProject/FinalProject/shared/gltools.h"	// OpenGL toolkit
#include "D:/MyNTUT/ComputerGraphic/CGRes/FinalProject/FinalProject/shared/math3d.h"		//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <./gl/GL.h>

#include <GL/glut.h>
#include <GL/freeglut.h>


#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>



// Keep track of effects step
int nStep = 0;

using namespace std;
//using namespace cv;

// Lighting data
GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat lightDiffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat lightSpecular[] = { 0.9f, 0.9f, 0.9f };
GLfloat materialColor[] = { 0.8f, 0.0f, 0.0f };
GLfloat vLightPos[] = { -80.0f, 120.0f, 100.0f, 0.0f };
GLfloat ground[3][3] = { { 0.0f, -25.0f, 0.0f },
						{ 10.0f, -25.0f, 0.0f },
						{ 10.0f, -25.0f, -10.0f } };

GLuint textures[4];





// Called to draw scene
void RenderScene(void)
{
	/*
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	glPushMatrix();

	// Draw plane that the cube rests on
	glDisable(GL_LIGHTING);

	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-100.0f, -25.3f, -100.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-100.0f, -25.3f, 100.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(100.0f, -25.3f, 100.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(100.0f, -25.3f, -100.0f);
	glEnd();

	// Set drawing color to Red
	glColor3f(1.0f, 0.0f, 0.0f);


	// Move the cube slightly forward and to the left
	glTranslatef(-10.0f, 0.0f, 10.0f);

	glColor3ub(255, 255, 255);
	// glGetFloatv(GL_MODELVIEW_MATRIX, mCubeTransform);

	// Front Face (before rotation)
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25.0f, 25.0f, 25.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, 25.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-25.0f, -25.0f, 25.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 25.0f);
	glEnd();

	// Top of cube
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25.0f, 25.0f, 25.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25.0f, 25.0f, -25.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, -25.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-25.0f, 25.0f, 25.0f);
	glEnd();

	// Last two segments for effect
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(25.0f, 25.0f, -25.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, -25.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, 25.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25.0f, 25.0f, 25.0f);
	glEnd();


	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();
	*/

	
	M3DMatrix44f mCubeTransform;
	M3DVector4f pPlane;


	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	glPushMatrix();

	// Draw plane that the cube rests on
	glDisable(GL_LIGHTING);
	if (nStep == 5)
	{
		glColor3ub(255, 255, 255);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-100.0f, -25.3f, -100.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-100.0f, -25.3f, 100.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(100.0f, -25.3f, 100.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(100.0f, -25.3f, -100.0f);
		glEnd();
	}
	else
	{
		glColor3f(0.0f, 0.0f, 0.90f); // Blue
		glBegin(GL_QUADS);
		glVertex3f(-100.0f, -25.3f, -100.0f);
		glVertex3f(-100.0f, -25.3f, 100.0f);
		glVertex3f(100.0f, -25.3f, 100.0f);
		glVertex3f(100.0f, -25.3f, -100.0f);
		glEnd();
	}


	// Set drawing color to Red
	glColor3f(1.0f, 0.0f, 0.0f);

	// Enable, disable lighting
	if (nStep > 2)
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_COLOR_MATERIAL);

		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
		glMateriali(GL_FRONT, GL_SHININESS, 128);
	}

	// Move the cube slightly forward and to the left
	glTranslatef(-10.0f, 0.0f, 10.0f);

	switch (nStep)
	{
		// Just draw the wire framed cube
	
	case 0:
		glutWireCube(50.0f);
		break;

		// Same wire cube with hidden line removal simulated
	case 1:
		// Front Face (before rotation)
		glBegin(GL_LINES);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glVertex3f(25.0f, -25.0f, 25.0f);

		glVertex3f(25.0f, -25.0f, 25.0f);
		glVertex3f(-25.0f, -25.0f, 25.0f);

		glVertex3f(-25.0f, -25.0f, 25.0f);
		glVertex3f(-25.0f, 25.0f, 25.0f);

		glVertex3f(-25.0f, 25.0f, 25.0f);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glEnd();

		// Top of cube
		glBegin(GL_LINES);
		// Front Face
		glVertex3f(25.0f, 25.0f, 25.0f);
		glVertex3f(25.0f, 25.0f, -25.0f);

		glVertex3f(25.0f, 25.0f, -25.0f);
		glVertex3f(-25.0f, 25.0f, -25.0f);

		glVertex3f(-25.0f, 25.0f, -25.0f);
		glVertex3f(-25.0f, 25.0f, 25.0f);

		glVertex3f(-25.0f, 25.0f, 25.0f);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glEnd();

		// Last two segments for effect
		glBegin(GL_LINES);
		glVertex3f(25.0f, 25.0f, -25.0f);
		glVertex3f(25.0f, -25.0f, -25.0f);

		glVertex3f(25.0f, -25.0f, -25.0f);
		glVertex3f(25.0f, -25.0f, 25.0f);
		glEnd();

		break;

		// Uniform colored surface, looks 2D and goofey
	case 2:
		glutSolidCube(50.0f);
		break;

	case 3:
		glutSolidCube(50.0f);
		break;

		// Draw a shadow with some lighting
	
	case 4:
		glGetFloatv(GL_MODELVIEW_MATRIX, mCubeTransform);
		glutSolidCube(50.0f);
		glPopMatrix();

		// Disable lighting, we'll just draw the shadow as black
		glDisable(GL_LIGHTING);

		glPushMatrix();

		//m3dGetPlaneEquation(pPlane, ground[0], ground[1], ground[2]);
		//m3dMakePlanarShadowMatrix(mCubeTransform, pPlane, vLightPos);
		//MakeShadowMatrix(ground, lightpos, cubeXform);
		glMultMatrixf(mCubeTransform);

		glTranslatef(-10.0f, 0.0f, 10.0f);

		// Set drawing color to Black	
		//這段會帶到下面case5，所以要把它註解掉
		glColor3f(0.0f, 0.0f, 0.0f);

		glutSolidCube(50.0f);
		break;
	
	case 5:
		glColor3ub(255, 255, 255);
		glGetFloatv(GL_MODELVIEW_MATRIX, mCubeTransform);

		// Front Face (before rotation)
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(25.0f, -25.0f, 25.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-25.0f, -25.0f, 25.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-25.0f, 25.0f, 25.0f);
		glEnd();

		// Top of cube
		glBindTexture(GL_TEXTURE_2D, textures[2]);
		glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(25.0f, 25.0f, -25.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-25.0f, 25.0f, -25.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-25.0f, 25.0f, 25.0f);
		glEnd();

		// Last two segments for effect
		glBindTexture(GL_TEXTURE_2D, textures[3]);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(25.0f, 25.0f, -25.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(25.0f, -25.0f, -25.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(25.0f, -25.0f, 25.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(25.0f, 25.0f, 25.0f);
		glEnd();


		glPopMatrix();

		// Disable lighting, we'll just draw the shadow as black
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glPushMatrix();
		

		//m3dGetPlaneEquation(pPlane, ground[0], ground[1], ground[2]);
		//m3dMakePlanarShadowMatrix(mCubeTransform, pPlane, vLightPos);
		glMultMatrixf(mCubeTransform);

		glTranslatef(-10.0f, 0.0f, 10.0f);

		// Set drawing color to Black	搞不懂這個function在衝沙小
		/*
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidCube(50.0f);
		break;
		*/

	}

	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();
	
}

// This function does any needed initialization on the rendering
// context. 


void SetupRC()
{
	//GLbyte *pBytes;
	//GLint nWidth, nHeight, nComponents;
	//GLenum format;

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glGenTextures(4, textures);

	// Load the texture objects
	//pBytes = gltLoadTGA("floor.tga", &nWidth, &nHeight, &nComponents, &format);
	/*
	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
		format, GL_UNSIGNED_BYTE, pBytes);
	free(pBytes);

	//pBytes = gltLoadTGA("Block4.tga", &nWidth, &nHeight, &nComponents, &format);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
		format, GL_UNSIGNED_BYTE, pBytes);
	free(pBytes);

	//pBytes = gltLoadTGA("Block5.tga", &nWidth, &nHeight, &nComponents, &format);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
		format, GL_UNSIGNED_BYTE, pBytes);
	free(pBytes);

	pBytes = gltLoadTGA("Block6.tga", &nWidth, &nHeight, &nComponents, &format);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
		format, GL_UNSIGNED_BYTE, pBytes);
	free(pBytes);
	*/

	//載入圖片
	cv::Mat image0 = cv::imread("D:/MyNTUT/ComputerGraphic/block/floor.jpg");
	if (image0.empty()) {
		std::cout << "image empty" << std::endl;
	}
	else {
		cv::flip(image0, image0, 0);
		glGenTextures(1, &textures[0]);
		glBindTexture(GL_TEXTURE_2D, textures[0]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Set texture clamping method
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glTexImage2D(GL_TEXTURE_2D,     // Type of texture
			0,                 // Pyramid level (for mip-mapping) - 0 is the top level
			GL_RGB,            // Internal colour format to convert to
			image0.cols,          // Image width  i.e. 640 for Kinect in standard mode
			image0.rows,          // Image height i.e. 480 for Kinect in standard mode
			0,                 // Border width in pixels (can either be 1 or 0)
			GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
			GL_UNSIGNED_BYTE,  // Image data type
			image0.ptr());        // The actual image data itself
		//glDisable(GL_TEXTURE_2D);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	cv::Mat image1 = cv::imread("D:/MyNTUT/ComputerGraphic/block/Block4.jpg");
	if (image1.empty()) {
		std::cout << "image empty" << std::endl;
	}
	else {
		cv::flip(image1, image1, 1);
		//glGenTextures(1, &textures[1]);
		glBindTexture(GL_TEXTURE_2D, textures[1]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Set texture clamping method
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glTexImage2D(GL_TEXTURE_2D,     // Type of texture
			0,                 // Pyramid level (for mip-mapping) - 0 is the top level
			GL_RGB,            // Internal colour format to convert to
			image1.cols,          // Image width  i.e. 640 for Kinect in standard mode
			image1.rows,          // Image height i.e. 480 for Kinect in standard mode
			0,                 // Border width in pixels (can either be 1 or 0)
			GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
			GL_UNSIGNED_BYTE,  // Image data type
			image1.ptr());        // The actual image data itself
		//glDisable(GL_TEXTURE_2D);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	cv::Mat image2 = cv::imread("D:/MyNTUT/ComputerGraphic/block/Block5.jpg");
	if (image2.empty()) {
		std::cout << "image empty" << std::endl;
	}
	else {
		cv::flip(image2, image2, 2);
		//glGenTextures(1, &textures[2]);
		glBindTexture(GL_TEXTURE_2D, textures[2]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Set texture clamping method
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glTexImage2D(GL_TEXTURE_2D,     // Type of texture
			0,                 // Pyramid level (for mip-mapping) - 0 is the top level
			GL_RGB,            // Internal colour format to convert to
			image2.cols,          // Image width  i.e. 640 for Kinect in standard mode
			image2.rows,          // Image height i.e. 480 for Kinect in standard mode
			0,                 // Border width in pixels (can either be 1 or 0)
			GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
			GL_UNSIGNED_BYTE,  // Image data type
			image2.ptr());        // The actual image data itself
		//glDisable(GL_TEXTURE_2D);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	cv::Mat image3 = cv::imread("D:/MyNTUT/ComputerGraphic/block/Block6.jpg");
	if (image3.empty()) {
		std::cout << "image empty" << std::endl;
	}
	else {
		cv::flip(image3, image3, 3);
		//glGenTextures(1, &textures[3]);
		glBindTexture(GL_TEXTURE_2D, textures[3]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Set texture clamping method
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


		glTexImage2D(GL_TEXTURE_2D,     // Type of texture
			0,                 // Pyramid level (for mip-mapping) - 0 is the top level
			GL_RGB,            // Internal colour format to convert to
			image3.cols,          // Image width  i.e. 640 for Kinect in standard mode
			image3.rows,          // Image height i.e. 480 for Kinect in standard mode
			0,                 // Border width in pixels (can either be 1 or 0)
			GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
			GL_UNSIGNED_BYTE,  // Image data type
			image3.ptr());        // The actual image data itself
		//glDisable(GL_TEXTURE_2D);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}



}

void KeyPressFunc(unsigned char key, int x, int y)
{
	if (key == 32)
	{
		nStep++;

		if (nStep > 5)
			nStep = 0;
	}

	// Refresh the Window
	glutPostRedisplay();
}


void ChangeSize(int w, int h)
{
	// Calculate new clipping volume
	GLfloat windowWidth;
	GLfloat windowHeight;

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	// Keep the square square
	if (w <= h)
	{
		windowHeight = 100.0f*(GLfloat)h / (GLfloat)w;
		windowWidth = 100.0f;
	}
	else
	{
		windowWidth = 100.0f*(GLfloat)w / (GLfloat)h;
		windowHeight = 100.0f;
	}

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the clipping volume
	glOrtho(-100.0f, windowWidth, -100.0f, windowHeight, -200.0f, 200.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, vLightPos);

	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(330.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D Effects Demo");
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(KeyPressFunc);
	glutDisplayFunc(RenderScene);

	SetupRC();

	glutMainLoop();
	glDeleteTextures(4, textures);
	return 0;
}



