#include "dslight.h"

void dsSetLight() {
	// ������Դ

	glEnable(GL_LIGHT0);

	// �����⣬��������õð�һЩ��������ɰ����İ�ɫ
	GLfloat ambient[4]  = {0.1f, 0.1f, 0.1f, 1.0f};

	// �����
	GLfloat diffuse[4]  = {0.5f, 250.0f / 255 / 2, 200.0f / 255 / 2, 0.5f};

	// ����⣬��������
	// GLfloat specular[4] = {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat specular[4] = {0.5f, 250.0f / 255 / 2, 200.0f / 255 / 2, 2.0f};
	// GLfloat specular[4] = {0.0f, 0.0f, 0.0f, 1.0f};

	// ��Դλ��
	GLfloat position[4] = {5.0f, 0.0f, 5.0f, 1.0f};
	
	// �����������Դ 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	/* �۹��
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0f);
	GLfloat spot_direction[] = {- position[0], - position[1], - position[2]};
	 GLfloat spot_direction[] = {0.0, 0.0, -1};
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);*/

}

void dsSetMaterial() {
	// ������
	GLfloat ambient[4]  = {1.0f, 1.0f, 1.0f, 10.0f};

	// �����
	GLfloat diffuse[4]  = {1.0f, 1.0f, 1.0f, 10.0f};

	// ����⣬��������
	GLfloat specular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	
	GLfloat shinness = 5.0;
	
	// �������������
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinness);

}