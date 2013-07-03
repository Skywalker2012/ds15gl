#ifndef _DSSKYBOX_H
#define _DSSKYBOX_H

#include <GL/glut.h>
#include "dstexture.h"

// ��պ��࣬�Ѿ��������л�����պеĲ��ֶ�д��������

class dsSkybox {
public:
	dsSkybox(): skybox(0) {}
	~dsSkybox() { del(); }

	// ������պ� ���� ������ ��ʾ�б�
	void load(GLuint index = 3);

	// ��ʾ��պ�
	void show();

	// ɾ����պ� ��ʾ�б� �� ����
	void del();

private:
	// ��ʾ�б���
	GLuint skybox;

	// ��պ�������
	GLuint texture[6];

	GLdouble width, height;
};

#endif