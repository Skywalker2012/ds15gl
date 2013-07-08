#include "dstools.h"
#include "dsFrame.h"
#include <ctime>
#include <iostream>

//Ŀǰֻ֧��WIN32��Linux
#ifdef WIN32
#define SLEEP(mm) Sleep(mm)
#else
//�������֪���в���
#include <unistd.h>
#define SLEEP(mm) usleep(mm*1000)
#endif // WIN32


int width = 800, height = 600;
//dsScene scene;
DSFrame frame;
const int mspf = 33; //ÿ֡ʱ��

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	dsSet(); // �����ӽ�

	frame.display();

	glutSwapBuffers();

	//��ӡGL����
	GLenum errCode;
	const GLubyte *errString;

	while ((errCode = glGetError()) != GL_NO_ERROR){
		errString = gluErrorString(errCode);
		std::cerr << errString << std::endl;
	}

}

void init() {
	//scene.initScene();
	dsSetMaterial();
	dsSetLight();
	frame.initialize();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	//dsSet();
	// texGround = dsLoadTextureBMP2D("ground.bmp");
}

// �����ڴ�С���޸�ʱ�Զ����ô˺���
void reshapeFunc(int w, int h) {
	width = w;
	height = h;
	frame.setSize(w,h);
//	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (width - 200) / double(height), 2, 20000);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void idle() {
	static long t = clock();
	long deltaT = clock() - t;
	if(deltaT > 0 && deltaT < mspf)
		//�������߳�
		SLEEP(mspf - deltaT);
	t = clock();

	glutPostRedisplay();
	
}

int main(int argc, char* argv[])
{
	vector2f v(1,2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800,600);
	glutCreateWindow("DS15");
	glutDisplayFunc(display);
	//glutMouseFunc(dsMouseFunc);
	//glutPassiveMotionFunc(dsPassiveMonitionFunc);
	glutSpecialFunc(dsSpecialKeys);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyFunc);
	init();
	glutMainLoop();
	return 0;
}