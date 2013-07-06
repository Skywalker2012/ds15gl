#include "dsSkybox.h"

void DSSkybox::del() {
	// ��� ��ʾ�б� �Ѵ��ڣ���ɾ��֮
	if (glIsList(skyBox)) {
		glDeleteLists(skyBox, 1);
	}

	// ���ԭ������պ� ����
	for (GLuint i = 0; i < 6; ++i) {
		if (glIsTexture(texture[i]))
			glDeleteTextures(1, texture + i);
	}
}

void DSSkybox::load(GLuint index) {

	// ԭ�������Ѿ�������պУ���Ҫ���
	del();

	GLuint texture_height, texture_width;

	// �����������������Ŵ��� texture[]
	// ���Ѽ��˼�����պ�
	switch (index) {
	case 0:
		// �������׻�԰��պ�
		texture[0] = dsLoadTextureBMP2D("data/images/skybox1/east.bmp", &texture_height, &texture_width);
		texture[1] = dsLoadTextureBMP2D("data/images/skybox1/west.bmp");
		texture[2] = dsLoadTextureBMP2D("data/images/skybox1/south.bmp");
		texture[3] = dsLoadTextureBMP2D("data/images/skybox1/north.bmp");
		texture[4] = dsLoadTextureBMP2D("data/images/skybox1/up.bmp");
		texture[5] = dsLoadTextureBMP2D("data/images/skybox1/down.bmp");
		extern GLdouble center[3];
		center[2] = 95.0;

		break;
	case 1:
		// ����׳��ɽ����պ�
		texture[0] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_east.bmp", &texture_height, &texture_width);
		texture[1] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_west.bmp");
		texture[2] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_south.bmp");
		texture[3] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_north.bmp");
		texture[4] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_up.bmp");
		texture[5] = dsLoadTextureBMP2D("data/images/skybox0/lostvalley_down.bmp");
		extern GLdouble center[3];
		center[2] = 70.0;

		break;
	case 2:
		// ˮ�콻����պ�
		texture[0] = dsLoadTextureBMP2D("data/images/skybox2/east.bmp", &texture_height, &texture_width);
		texture[1] = dsLoadTextureBMP2D("data/images/skybox2/west.bmp");
		texture[2] = dsLoadTextureBMP2D("data/images/skybox2/south.bmp");
		texture[3] = dsLoadTextureBMP2D("data/images/skybox2/north.bmp");
		texture[4] = dsLoadTextureBMP2D("data/images/skybox2/up.bmp");
		texture[5] = dsLoadTextureBMP2D("data/images/skybox2/down.bmp");
		extern GLdouble center[3];
		center[2] = 100.0;

		break;
	case 3:
		// Ϧ�����޺�ϼ��պ�
		texture[0] = dsLoadTextureBMP2D("data/images/skybox3/east.bmp", &texture_height, &texture_width);
		texture[1] = dsLoadTextureBMP2D("data/images/skybox3/west.bmp");
		texture[2] = dsLoadTextureBMP2D("data/images/skybox3/south.bmp");
		texture[3] = dsLoadTextureBMP2D("data/images/skybox3/north.bmp");
		texture[4] = dsLoadTextureBMP2D("data/images/skybox3/up.bmp");
		texture[5] = dsLoadTextureBMP2D("data/images/skybox3/down.bmp");
		extern GLdouble center[3];
		center[2] = 950.0;

		break;
	case 4:
		// ԭ������պ�
		texture[0] = dsLoadTextureBMP2D("data/images/skybox4/east.bmp", &texture_height, &texture_width);
		texture[1] = dsLoadTextureBMP2D("data/images/skybox4/west.bmp");
		texture[2] = dsLoadTextureBMP2D("data/images/skybox4/south.bmp");
		texture[3] = dsLoadTextureBMP2D("data/images/skybox4/north.bmp");
		texture[4] = dsLoadTextureBMP2D("data/images/skybox4/up.bmp");
		texture[5] = dsLoadTextureBMP2D("data/images/skybox4/down.bmp");
		extern GLdouble center[3];
		center[2] = 40.0;

		break;
	default:
		break;
	}

	// �ٴ�����ʾ�б�
	width = 2000;
	height = width / (GLdouble)texture_width * (GLdouble)texture_height;
	
	GLdouble x = width / 2;

	skyBox = glGenLists(1);

	glNewList(skyBox, GL_COMPILE_AND_EXECUTE);
	{
		glDisable(GL_LIGHTING);

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(1, 0); glVertex3d(- x, - x, - 2);
			glTexCoord2d(1, 1); glVertex3d(x, - x, - 2);
			glTexCoord2d(0, 1); glVertex3d(x, x, - 2);
			glTexCoord2d(0, 0); glVertex3d(- x, x, - 2);
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(x, x, - 2);
			glTexCoord2d(0, 1); glVertex3d(x, x, height - 2);
			glTexCoord2d(1, 1); glVertex3d(x, - x, height - 2);
			glTexCoord2d(1, 0); glVertex3d(x, - x, - 2);
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(- x, - x, -2);
			glTexCoord2d(0, 1); glVertex3d(- x, - x, height - 2);
			glTexCoord2d(1, 1); glVertex3d(- x, x, height - 2);
			glTexCoord2d(1, 0); glVertex3d(- x, x, -2);
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(x, - x, -2);
			glTexCoord2d(0, 1); glVertex3d(x, - x, height - 2);
			glTexCoord2d(1, 1); glVertex3d(- x, - x, height - 2);
			glTexCoord2d(1, 0); glVertex3d(- x, - x, -2);		
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(0, 0); glVertex3d(- x, x, -2);
			glTexCoord2d(0, 1); glVertex3d(- x, x, height - 2);
			glTexCoord2d(1, 1); glVertex3d(x, x, height - 2);
			glTexCoord2d(1, 0); glVertex3d(x, x, -2);		
		}
		glEnd();

		// ����
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glBegin(GL_QUADS);
		{
			glTexCoord2d(1, 1); glVertex3d(- x, -x, height - 2);
			glTexCoord2d(1, 0); glVertex3d(x, -x, height - 2);
			glTexCoord2d(0, 0); glVertex3d(x, x, height - 2);
			glTexCoord2d(0, 1); glVertex3d(- x, x, height - 2);
		}
		glEnd();

		glEnable(GL_LIGHTING);

	}
	glEndList();
}

void DSSkybox::show() {
	glCallList(skyBox);
}