#pragma once
#include "dsMap.h"
#include <GL/glut.h>
#include "dsSkybox.h"

// �볡���йص���
// ���л�ͼ������Ӧ��ת�Ƶ������
class dsScene {
public:
	dsScene();
	~dsScene();
	void initScene();

	// ��պе���������� dsSkybox ������
	// void initSkyBox();

	void showScene();

private:
	dsMap dsmap; // �Ժ����	
	//��ʾ�б�

	// ��պе���ʾ�б��� dsSkybox ������
	// GLuint skyBox;

	GLuint groud;
	
	////��¼��ʾ�б�����������ʱʹ��
	////int listCount;
	//��պ͵�����������겻��ģ�
	//�������ʾ�б�	

	//��ͼ

	// ��պе��������� dsSkybox ������
	// GLuint tex[6]; //east,west,south,north,top

	dsSkybox dsskybox;
};

