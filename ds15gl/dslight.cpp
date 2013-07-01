#include "dslight.h"

void dsSetLight() {
	// ������Դ

	glEnable(GL_LIGHT0);

	// ������
	GLfloat ambient[4]  = {0.5f, 250.0f / 255 / 2, 200.0f / 255 / 2, 1.0f};

	// �����
	GLfloat diffuse[4]  = {0.5f, 0.5f, 0.5f, 1.0f};

	// ����⣬��������
	GLfloat specular[4] = {1.0f, 1.0f, 0.0f, 1.0f};
	
	// ��Դλ��
	GLfloat position[4] = {1.0f, 1.0f, 1.0f, 0.2f};
	
	// �����������Դ 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

}

void dsSetMaterial() {
	// ������
	GLfloat ambient[4]  = {1.0f, 1.0f, 1.0f, 1.0f};

	// �����
	GLfloat diffuse[4]  = {1.0f, 1.0f, 1.0f, 1.0f};

	// ����⣬��������
	GLfloat specular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	GLfloat shinness = 5.0;
	
	// �������������
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinness);
	//glMaterialfv(GL_FRONT, GL_POSITION, position);
}