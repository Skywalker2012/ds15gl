#pragma once
#include "dsMap.h"
#include <GL/glut.h>
class dsScence
	//�볡���йص���
	//���л�ͼ������Ӧ��ת�Ƶ������
{
public:
	dsScence(void);
	~dsScence(void);
	void initScence();
public: 
	void initSkyBox();
	void showScence();
private:
	dsMap dsmap;//�Ժ����	
	//��ʾ�б�
	GLuint skyBox;
	GLuint groud;
	
	
	////��¼��ʾ�б�����������ʱʹ��
	////int listCount;
	//��պ͵�����������겻��ģ�
	//�������ʾ�б�	
	//��ͼ
	GLuint tex[5];//east,west,south,north,top
};

