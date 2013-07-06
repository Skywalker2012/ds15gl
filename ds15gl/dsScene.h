#pragma once
#include "dsMap.h"
#include <GL/glut.h>
#include "dsSkybox.h"
#include "dstools.h"

// �볡���йص���
// ���л�ͼ������Ӧ��ת�Ƶ������
class DSScene {
public:
	DSScene();
	~DSScene();
	void initialize();

	// ��պе���������� dsSkybox ������
	// void initSkyBox();

	void show();
	void setSize(int width,int height);
private:
	int window_width;
	int window_height;

private:
	DSMap map; // �Ժ����	
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

	DSSkybox dsSkyBox;
};

