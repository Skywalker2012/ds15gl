#include "dsScence.h"
#include "dstexture.h"
#include "gl/GLAUX.H"


dsScence::dsScence(void)
{
}


dsScence::~dsScence(void)
{
	if(skyBox!=NULL){
		glIsList(skyBox);
		glDeleteLists(skyBox,1);
	}
	if(groud!=NULL){
		glIsList(groud);
		glDeleteLists(groud,1);
	}

}

void dsScence::initSkyBox(){
	int mapW,mapH,mapSize;
	dsmap.getSize(mapW,mapH);
	//��պд���ʵ�ʵ�ͼ��С
	//���ĵ������������ε�
	mapSize=(mapW>mapH?mapW:mapH);
	//����ͼƬ�ĳ���ȵ��ڸ߶�
	mapSize/=1.5;
	int height=mapSize;
	skyBox=glGenLists(1);
	glLoadIdentity();
	glNewList(skyBox,GL_COMPILE_AND_EXECUTE);
		glDisable(GL_LIGHTING);
		//glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		//glPushMatrix();
		//����
		
		glVertex3d(-mapSize,-mapSize,-2);
		glVertex3d(mapSize,-mapSize,-2);
		glVertex3d(mapSize,mapSize,-2);
		glVertex3d(-mapSize,mapSize,-2);
		//glPopMatrix();
		glEnd();
		//����
		glBindTexture(GL_TEXTURE_2D,tex[0]);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3d(mapSize,mapSize,-2);
		glTexCoord2d(0,1);glVertex3d(mapSize,mapSize,height-2);
		glTexCoord2d(1,1);glVertex3d(mapSize,-mapSize,height-2);
		glTexCoord2d(1,0);glVertex3d(mapSize,-mapSize,-2);
		glEnd();
		//����
		glBindTexture(GL_TEXTURE_2D,tex[1]);
		glBegin(GL_QUADS);
			
		glTexCoord2d(0,0);glVertex3d(-mapSize,-mapSize,-2);
		glTexCoord2d(0,1);glVertex3d(-mapSize,-mapSize,height-2);
		glTexCoord2d(1,1);glVertex3d(-mapSize,mapSize,height-2);
		glTexCoord2d(1,0);glVertex3d(-mapSize,mapSize,-2);		
		glEnd();

		//����
		glBindTexture(GL_TEXTURE_2D,tex[2]);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3d(mapSize,-mapSize,-2);
		glTexCoord2d(0,1);glVertex3d(mapSize,-mapSize,height-2);
		glTexCoord2d(1,1);glVertex3d(-mapSize,-mapSize,height-2);
		glTexCoord2d(1,0);glVertex3d(-mapSize,-mapSize,-2);		
		glEnd();
		//����
		glBindTexture(GL_TEXTURE_2D,tex[3]);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3d(-mapSize,mapSize,-2);
		glTexCoord2d(0,1);glVertex3d(-mapSize,mapSize,height-2);
		glTexCoord2d(1,1);glVertex3d(mapSize,mapSize,height-2);
		glTexCoord2d(1,0);glVertex3d(mapSize,mapSize,-2);		
		glEnd();
		//����
		glBindTexture(GL_TEXTURE_2D,tex[4]);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);glVertex3d(-mapSize,-mapSize,height-2);
		glTexCoord2d(0,1);glVertex3d(mapSize,-mapSize,height-2);
		glTexCoord2d(1,1);glVertex3d(mapSize,mapSize,height-2);
		glTexCoord2d(1,0);glVertex3d(-mapSize,mapSize,height-2);		
		glEnd();
		//glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	glEndList();
}

void dsScence::showScence(){
	glCallList(skyBox);
}

bool LoadT8(char *filename, GLuint &texture)
{	
	AUX_RGBImageRec *pImage = NULL;
	pImage = auxDIBImageLoad(filename);
	if(pImage == NULL)		return false;
	glGenTextures(1, &texture);	
	glBindTexture    (GL_TEXTURE_2D,texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D,4, pImage->sizeX, 
				  pImage->sizeY,GL_RGB, GL_UNSIGNED_BYTE,pImage->data);
	free(pImage->data);
	free(pImage);	
	return true;
}

void dsScence::initScence(){
	LoadT8("data/images/east.bmp",tex[0]);
	LoadT8("data/images/west.bmp",tex[1]);
	LoadT8("data/images/south.bmp",tex[2]);
	LoadT8("data/images/north.bmp",tex[3]);
	LoadT8("data/images/top.bmp",tex[4]);
	initSkyBox();
}

