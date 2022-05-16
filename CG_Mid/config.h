#pragma once

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <algorithm>    // std::swap std::sort
#include <cmath>        // abs
#include "function.h"
#include <vector>
#include <cstdlib> // for abs
#include "coordinate.h"
#include <iostream>
#include "line.h"
//#include "objloader.h"

float getSin(float);
float getCos(float);
void int_swap(int *a, int*b);
bool compare_angle(Coordinate a, Coordinate b);


class Config {
public:
	Config() {
		gridWidth = 20.0;
		gridHeight = 20.0;
		orthoX = orthoY = orthoZ = 300;
		//Set_Grid_Amount(9);
		clickX = clickY = clickZ = 0;
		//which_to_pop = -1;
		fill_in = false;
	}

	void Set_Ortho_Width_Height(GLfloat X, GLfloat Y, GLfloat Z) {
		orthoX = X;
		orthoY = Y;
		orthoZ = Z;
	}

	void Set_Grid_Amount(int amount) {
		// ���k�W�U�O�⭿ortho
		grid_Amount = amount;
		gridWidth = 2 * orthoX / grid_Amount;
		gridHeight = 2 * orthoY / grid_Amount;
	}

	void Draw() {
		Draw_Grid();
		Draw_Target_Cube();
	}

	// �e��u
	void Draw_Grid() {
		glColor3f(1.0f, 1.0f, 1.0f); // White (RGB)

		for (float x = -orthoX; x <= orthoX; x += gridWidth)
		{
			glBegin(GL_LINES);
			glVertex3f(x, -orthoY, 0.0f);
			glVertex3f(x, orthoY, 0.0f);
			glEnd();
		}
		for (float y = -orthoY; y <= orthoY; y += gridHeight)
		{
			glBegin(GL_LINES);
			glVertex3f(-orthoX, y, 0.0f);
			glVertex3f(orthoX, y, 0.0f);
			glEnd();
		}
	}

	void Draw_Target_Cube() {

		int x, y;
		glColor3f(0.8f, 1.0f, 1.0f); // �鷺���C��
		for (unsigned int i = 0; i < coor_vec.size(); i++) {

			x = coor_vec[i].x;
			y = coor_vec[i].y;
			//x = (int)((click_vec[i].x - gridWidth / 2) / gridWidth);
			//y = (int)((click_vec[i].y - gridHeight / 2) / gridHeight);

			glPolygonMode(GL_FRONT, GL_FILL);
			glBegin(GL_POLYGON);

			//if (click_vec[i].x > gridWidth / 2)
			//  x = x + 1;
			//if (click_vec[i].y > gridHeight / 2)
			//  y = y + 1;

			glVertex3f(x*gridWidth - gridWidth / 2, y*gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth + gridWidth - gridWidth / 2, y*gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth + gridWidth - gridWidth / 2, y*gridHeight + gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth - gridWidth / 2, y*gridHeight + gridHeight - gridHeight / 2, 0.0f);

			glEnd();
			//std::cout << "grid x:" << x << " grid y:" << y << std::endl;
		}

		if (click_vec.size() >= 2) {
			Draw_Line_Target_Cube();
		}


		glColor3f(0.8f, 0.5f, 1.0f); // setting point color
		for (unsigned int i = 0; i < vertex_vec.size(); i++) {
			x = vertex_vec[i].x;
			y = vertex_vec[i].y;
			//x = (int)((click_vec[i].x - gridWidth / 2) / gridWidth);
			//y = (int)((click_vec[i].y - gridHeight / 2) / gridHeight);

			glPolygonMode(GL_FRONT, GL_FILL);
			glBegin(GL_POLYGON);

			//if (click_vec[i].x > gridWidth / 2)
			//  x = x + 1;
			//if (click_vec[i].y > gridHeight / 2)
			//  y = y + 1;

			glVertex3f(x*gridWidth - gridWidth / 2, y*gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth + gridWidth - gridWidth / 2, y*gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth + gridWidth - gridWidth / 2, y*gridHeight + gridHeight - gridHeight / 2, 0.0f);
			glVertex3f(x*gridWidth - gridWidth / 2, y*gridHeight + gridHeight - gridHeight / 2, 0.0f);

			glEnd();
		}

	}

	void Draw_Line_Target_Cube() {
		int x1, y1, x2, y2;
		int size;
		size = click_vec.size();

		glColor3f(1.0f, 0.5f, 0.5f);//�s���u�C��
		//glColor3f(0.2f, 0.3f, 0.5f);  //Some type of blue

		//�令�e�T���u
		for (int i = 0; i < size; i++) {


			x1 = vertex_vec[i].x;
			y1 = vertex_vec[i].y;

			x2 = vertex_vec[(i + 1) % size].x;
			y2 = vertex_vec[(i + 1) % size].y;
			glBegin(GL_LINES);
			glVertex3f(x1 * gridWidth, y1 * gridHeight, 0);
			glVertex3f(x2 * gridWidth, y2 * gridHeight, 0);
			glEnd();
		}
	}

	void reset() {
		click_vec.clear();
		coor_vec.clear();
		vertex_vec.clear();

		fill_in = false;
	}

	void Add_New_Click(int x, int y) {

		if (fill_in)
			return;
		//���m�T����


		//if (which_to_pop != -1 && click_vec.size() == 3) {
		//    click_vec.clear();
		//    coor_vec.clear();
		//}
		Coordinate temp(x, y);
		click_vec.push_back(temp);
		if (which_to_pop == -1)
			which_to_pop = 0;

		vertex_vec.clear();
		// �ɥ� x �� y
		// �ഫ�y��
		for (unsigned int i = 0; i < click_vec.size(); i++) {

			x = (int)((click_vec[i].x - gridWidth / 2) / gridWidth);
			y = (int)((click_vec[i].y - gridHeight / 2) / gridHeight);

			if (click_vec[i].x > gridWidth / 2)
				x = x + 1;
			if (click_vec[i].y > gridHeight / 2)
				y = y + 1;

			Coordinate temp2(x, y);
			vertex_vec.push_back(temp2);
		}

		//vertex_vec = coor_vec;

		//if (vertex_vec.size() == 3)
		//    fillTriangle();
		//setLine(coor_vec[0].x, coor_vec[0].y, coor_vec[1].x, coor_vec[1].y, false);
	}

	int jordanInside(std::vector<Coordinate> *vList, int x, int y) {
		int cross = 0;
		int x0, y0, x1, y1;
		int n = vList->size();

		x0 = (*vList)[n - 1].x - x;
		y0 = (*vList)[n - 1].y - y;
		for (int i = 0; i < n; i++) {
			x1 = (*vList)[i].x - x;
			y1 = (*vList)[i].y - y;
			if (y0 > 0) {
				if (y1 <= 0) {
					if (x1*y0 > y1*x0)
						cross++;
				}
			}
			else
				if (y1 > 0)
					if (x0*y1 > y0*x1)
						cross++;
			x0 = x1;
			y0 = y1;
		}

		return cross & 1;

	}

	void fillPolygon() {
		if (fill_in)
			return;

		int centerx = 0, centery = 0, xMin, xMax, yMin, yMax;
		int size = vertex_vec.size();

		xMin = vertex_vec[0].x; //���L�̲Ĥ@���I���ƭ�
		xMax = vertex_vec[0].x;
		yMin = vertex_vec[0].y;
		yMax = vertex_vec[0].y;
		for (unsigned int i = 0; i < size; i++) {
			if (xMin > vertex_vec[i].x)   //��̤j�̤p��
				xMin = vertex_vec[i].x;
			if (xMax < vertex_vec[i].x)
				xMax = vertex_vec[i].x;
			if (yMin > vertex_vec[i].y)
				yMin = vertex_vec[i].y;
			if (yMax < vertex_vec[i].y)
				yMax = vertex_vec[i].y;

			centerx = centerx + vertex_vec[i].x;  //�p��T���Ϊ������I
			centery = centery + vertex_vec[i].y;
		}
		centerx = centerx / size;
		centery = centery / size;
		Coordinate center(centerx, centery);
		//std::cout << 
		//for (unsigned int i = 0; i < size; i++) {
		//    vertex_vec[i].angle = GetAngle(center, vertex_vec[i]);
		//    std::cout << "����:" << vertex_vec[i].angle << std::endl;
		//}
		//std::sort(vertex_vec.begin(), vertex_vec.begin() + size, compare_angle); //�f�ɰw�ƧǡA�Ψ��ױ�
		//for (unsigned int i = 0; i < size; i++) {
		//    std::cout << "�Ƨǫᨤ��:" << vertex_vec[i].angle << std::endl;
		//}
		for (int y = yMin; y <= yMax; y++) {
			for (int x = xMin; x <= xMax; x++) {
				if (jordanInside(&vertex_vec, x, y))
					Add_Coor_to_Vec(&coor_vec, x, y);
			}
		}

		fill_in = true;
	}

	void counter_clockwise_vertex() {

	}

	// (x2 - x1) (y - y1) = (y2 - y1) (x - x1)
	void fillTriangle() {
		//int e1 = lineEq();
		if (fill_in)
			return;

		int centerx = 0, centery = 0, xMin, xMax, yMin, yMax;

		xMin = vertex_vec[0].x; //���L�̲Ĥ@���I���ƭ�
		xMax = vertex_vec[0].x;
		yMin = vertex_vec[0].y;
		yMax = vertex_vec[0].y;
		for (unsigned int i = 0; i < vertex_vec.size(); i++) {
			if (xMin > vertex_vec[i].x)   //��̤j�̤p��
				xMin = vertex_vec[i].x;
			if (xMax < vertex_vec[i].x)
				xMax = vertex_vec[i].x;
			if (yMin > vertex_vec[i].y)
				yMin = vertex_vec[i].y;
			if (yMax < vertex_vec[i].y)
				yMax = vertex_vec[i].y;

			centerx = centerx + vertex_vec[i].x;  //�p��T���Ϊ������I
			centery = centery + vertex_vec[i].y;
		}
		centerx = centerx / 3;
		centery = centery / 3;
		Coordinate center(centerx, centery);
		//std::cout << 
		for (unsigned int i = 0; i < vertex_vec.size(); i++) {
			vertex_vec[i].angle = GetAngle(center, vertex_vec[i]);
			std::cout << "����:" << vertex_vec[i].angle << std::endl;
		}
		std::sort(vertex_vec.begin(), vertex_vec.begin() + 3, compare_angle); //�f�ɰw�ƧǡA�Ψ��ױ�
		for (unsigned int i = 0; i < vertex_vec.size(); i++) {
			std::cout << "�Ƨǫᨤ��:" << vertex_vec[i].angle << std::endl;
		}

		Line L1, L2, L3;

		int e1 = lineEq(&L1, vertex_vec[0], vertex_vec[1], xMin, yMin);
		int e2 = lineEq(&L2, vertex_vec[1], vertex_vec[2], xMin, yMin);
		int e3 = lineEq(&L3, vertex_vec[2], vertex_vec[0], xMin, yMin);
		int xDim = xMax - xMin + 1;
		std::cout << "xDim: " << xDim << std::endl;
		std::cout << "L1 = " << L1.a << "x + " << L1.b << "y + " << L1.c << " e1: " << e1 << std::endl;
		std::cout << "L2 = " << L2.a << "x + " << L2.b << "y + " << L2.c << " e2: " << e2 << std::endl;
		std::cout << "L3 = " << L3.a << "x + " << L3.b << "y + " << L3.c << " e3: " << e3 << std::endl;
		std::cout << "xMin : " << xMin << " xMax : " << xMax << " yMin : " << yMin << " yMax : " << yMax << std::endl;
		for (int y = yMin; y <= yMax; y++) {
			for (int x = xMin; x <= xMax; x++) {
				if (e1 < 0 && e2 < 0 && e3 < 0) {
					Add_Coor_to_Vec(&coor_vec, x, y);
					//std::cout << "Add ( " << x << ", " << y << " ) into vector" << " e1: " << e1 << " e2: " << e2 << " e3: " << e3 << std::endl;

				}
				e1 += L1.a;
				e2 += L2.a;
				e3 += L3.a;
			}
			e1 = e1 - xDim * L1.a + L1.b;
			e2 = e2 - xDim * L2.a + L2.b;
			e3 = e3 - xDim * L3.a + L3.b;
		}
		fill_in = true;
	}

	float GetAngle(Coordinate a, Coordinate b)
	{
		// �o��ݭn�L�o����m�ۦP�����D
		if (a.x == b.x && a.y >= b.y) return 0;

		b.x -= a.x;
		b.y -= a.y;
		Coordinate c(0, -1);

		int d1 = (c.x * b.x) + (c.y * b.y);
		float d2 = c.magnitude() * b.magnitude();
		float angle = acos(d1 / d2) * (180 / M_PI);

		if (b.x < 0) angle *= -1;

		if (angle < 0)
			angle = angle + 360;
		return angle;
	}

	int lineEq(Line *l, Coordinate dot_1, Coordinate dot_2, int x, int y) {
		int a = dot_2.y - dot_1.y;
		int b = -(dot_2.x - dot_1.x);
		int c = -dot_1.x *(dot_2.y - dot_1.y) + dot_1.y*(dot_2.x - dot_1.x);
		l->a = a;
		l->b = b;
		l->c = c;
		return a * x + b * y + c;
	}

	void Add_Coor_to_Vec(std::vector<Coordinate> *vec, int x, int y) {
		Coordinate temp(x, y);
		vec->push_back(temp);
	}

	//float midX, midY, midZ;

	//float lengthX, lengthY, lengthZ;
	GLfloat orthoX;
	GLfloat orthoY;
	GLfloat orthoZ;

	float clickX, clickY, clickZ;


	int grid_Amount;
private:
	GLfloat *translateMatrix;
	GLfloat *rotMatrix_X;
	GLfloat *rotMatrix_Y;
	GLfloat *rotMatrix_Z;

	GLfloat gridWidth;
	GLfloat gridHeight;

	bool fill_in; // ���Ӭ����h��άO�_�w�g��J�@���I

	std::vector<Coordinate> click_vec;
	std::vector<Coordinate> coor_vec; // �ഫ�᪺�y��
	std::vector<Coordinate> vertex_vec; //�x�s�ഫ�᪺�I���y��
	int which_to_pop = -1;
};