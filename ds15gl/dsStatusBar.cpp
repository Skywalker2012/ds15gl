#include "dsStatusBar.h"
#include "dstools.h"

DSStatusBar::DSStatusBar(void)
{
	width=150;
}


DSStatusBar::~DSStatusBar(void)
{
}

void DSStatusBar::show(){
	
	//����ͶӰ��ʽΪ2Dƽ��ͶӰ
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0,width,0,window_height,0,1000);	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	glViewport(window_width-width,0,width,window_height);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE);
	gluLookAt(0,0,200,0,0,0,0,1,0);
	glColor3d(0,0,0);
	//fillRectange2D(0,0,width,window_height);

	//���ﻭС��ͼ��ս���������״̬��Ϣ
	//����
	glColor3f(1,0,1);	
	glutSolidTeapot(100);
	
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
	//�ص�͸��ͶӰ
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void DSStatusBar::setSize(int width,int height){
	window_height=height;
	window_width=width;
}