#include "dsScene.h"
#include "dstexture.h"
#include "dsText.h"

DSScene::DSScene() {}

DSScene::~DSScene() {
	if (groud != NULL) {
		glIsList(groud);
		glDeleteLists(groud, 1);
	}
}

void DSScene::show(){
	glViewport(0, 0, window_width - 200, window_height);
	dsSkyBox.show();

	// glDisable(GL_TEXTURE_2D);
	/*glEnable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
	{
		glNormal3d(0.0, 0.0, 1.0);
		glVertex3d(10.0, 0.0, 0.0);
		glVertex3d(0.0, 10.0, 0.0);
		glVertex3d(-10.0, 0.0, 0.0);
	}
	glEnd();*/

	dsShowLightSource();

	glDisable(GL_LIGHTING);

	// �����ǹ��������
	glRasterPos2d(2.0, 2.0);
	drawString("Hello");

	dsShowAxes();
}



void DSScene::initialize() {
	dsSkyBox.load(3);
}

void DSScene::setSize(int width, int height){
	window_height = height;
	window_width = width;
}