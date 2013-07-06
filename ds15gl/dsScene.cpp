#include "dsScene.h"
#include "dstexture.h"


// int test;

DSScene::DSScene()
{
}


DSScene::~DSScene()
{
	// ��պе�ж�ع�����ת�� dsSkybox ��
	// ����ע��֮����ɾ
	/*if (skyBox != NULL) {
		glIsList(skyBox);
		glDeleteLists(skyBox, 1);
	}*/

	if (groud != NULL) {
		glIsList(groud);
		glDeleteLists(groud, 1);
	}

}

// ��ʼ����պеĹ�����ת�� dsSkybox �ڲ���
// ����ע��֮����ɾ
/*
void dsScene::initSkyBox() {

	int mapW, mapH, mapSize;
	dsmap.getSize(mapW, mapH);
	// ��պд���ʵ�ʵ�ͼ��С
	// ���ĵ������������ε�
	mapSize = ((mapW > mapH) ? mapW : mapH);
	
	// ����ͼƬ�ĳ���ȵ��ڸ߶�
	// mapSize /= 1.5;
	int height = 2 * mapSize;
	skyBox = glGenLists(1);
	glLoadIdentity();
	glNewList(skyBox, GL_COMPILE_AND_EXECUTE);
	{
		glDisable(GL_LIGHTING);
		// ����
		glBindTexture(GL_TEXTURE_2D, tex[5]);
		glBegin(GL_QUADS);
		{
			//glPushMatrix();
			glTexCoord2d(1, 0); glVertex3d(- mapSize, - mapSize, -2);
			glTexCoord2d(1, 1); glVertex3d(mapSize, - mapSize, -2);
			glTexCoord2d(0, 1); glVertex3d(mapSize, mapSize, -2);
			glTexCoord2d(0, 0); glVertex3d(- mapSize, mapSize, -2);
			//glPopMatrix();
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, tex[0]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(mapSize, mapSize, -2);
			glTexCoord2d(0, 1); glVertex3d(mapSize, mapSize, height - 2);
			glTexCoord2d(1, 1); glVertex3d(mapSize, - mapSize, height - 2);
			glTexCoord2d(1, 0); glVertex3d(mapSize, - mapSize, -2);
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D,tex[1]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(- mapSize, - mapSize, -2);
			glTexCoord2d(0, 1); glVertex3d(- mapSize, - mapSize, height - 2);
			glTexCoord2d(1, 1); glVertex3d(- mapSize, mapSize, height - 2);
			glTexCoord2d(1, 0); glVertex3d(- mapSize, mapSize, -2);
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D,tex[2]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(mapSize, - mapSize, -2);
			glTexCoord2d(0, 1); glVertex3d(mapSize, - mapSize, height - 2);
			glTexCoord2d(1, 1); glVertex3d(- mapSize, - mapSize, height - 2);
			glTexCoord2d(1, 0); glVertex3d(- mapSize, - mapSize, -2);		
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D,tex[3]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(- mapSize, mapSize, -2);
			glTexCoord2d(0, 1); glVertex3d(- mapSize, mapSize, height - 2);
			glTexCoord2d(1, 1); glVertex3d(mapSize, mapSize, height - 2);
			glTexCoord2d(1, 0); glVertex3d(mapSize, mapSize, -2);		
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D,tex[4]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(1, 1); glVertex3d(- mapSize, -mapSize, height - 2);
			glTexCoord2d(1, 0); glVertex3d(mapSize, -mapSize, height - 2);
			glTexCoord2d(0, 0); glVertex3d(mapSize, mapSize, height - 2);
			glTexCoord2d(0, 1); glVertex3d(- mapSize, mapSize, height - 2);
		}
		glEnd();

		//glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	}
	glEndList();
}
*/

void DSScene::show(){
	// glCallList(skyBox);
	glViewport(0, 0, window_width-200, window_height);
	dsSkyBox.show();
	dsShowAxes();
}



void DSScene::initialize() {
	// ������պ�����Ĺ�����ת�� dsSkybox ��
	// ����ע��֮����ɾ
	/*
	LoadT8("data/images/east.bmp", tex[0]);
	LoadT8("data/images/west.bmp", tex[1]);
	LoadT8("data/images/south.bmp", tex[2]);
	LoadT8("data/images/north.bmp", tex[3]);
	LoadT8("data/images/top.bmp", tex[4]);
	extern GLdouble center[3];
	center[2] = 70.0;

	initSkyBox();
	*/
	dsSkyBox.load();
}

void DSScene::setSize(int width,int height){
	window_height=height;
	window_width=width;
}