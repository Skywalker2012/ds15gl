#include "dstools.h"

const double viewMoveSpeed = 1.0;
static const GLdouble pi = 3.1415926;
GLdouble eye_sphere[3] = {20.0, pi / 6, - pi / 2};
/* 眼睛位置，用球坐标 (r, phi, theta) 表示
 * 其中，phi 表示与 z 轴的夹角
 * theta 表示在 xy 平面的投影的旋转角
 */

GLdouble up[3] = {0.0, 0.0, 1.0};

// 视线中心点，球坐标的原点
GLdouble center[3] = {0.0, 0.0, 20.0};

// 相机位置
GLdouble eye[3];

//坐标轴长度
GLfloat axeLength;

void dsSet() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*这个不要老改，reshap时该就行了*/

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//int window_height = glutGet(GLUT_WINDOW_HEIGHT);
	//int window_width = glutGet(GLUT_WINDOW_WIDTH);
	//gluPerspective(60, (double)window_width / window_height, 0.01, 20000.0);

	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	dsSphereToOrtho3dv(eye_sphere, center, eye);
	// 将球坐标转化为直角坐标

	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
	// 设置摄像头位置
}



void dsSpecialKeys(int key, int x, int y)
{
	static float rotateSpeed=0.1;
	static float scaleSpeed=0.5;
	switch (key) {
	case GLUT_KEY_UP:
		if (eye_sphere[1] > rotateSpeed) {
			eye_sphere[1] -= rotateSpeed;
		}
		break;
	case GLUT_KEY_DOWN:
		if (eye_sphere[1] < 3.1415926 - rotateSpeed) {
			eye_sphere[1] += rotateSpeed;
		}
		break;
	case GLUT_KEY_LEFT:
		eye_sphere[2] -= rotateSpeed;
		break;
	case GLUT_KEY_RIGHT:
		eye_sphere[2] += rotateSpeed;
		break;
	case GLUT_KEY_F1:
		eye_sphere[0] += scaleSpeed;
		break;
	case GLUT_KEY_F2:
		if (eye_sphere[0] > scaleSpeed) {
			eye_sphere[0] -= scaleSpeed;
		}
	break;
	}
	axeLength=eye_sphere[0]*0.2f;
}


void keyFunc(unsigned char key,int x,int y){
	//printf_s("%f,%f,%f",eye[0],eye[1],eye[2]);
	vector2f dir = vector2f(center[0] - eye[0], center[1] - eye[1]);
	dir.normalLise();
	vector2f left = dir.turnLeft();
	switch (key) {
	case 'a':
	case 'A':
		center[0] += left.x * viewMoveSpeed;
		center[1] += left.y * viewMoveSpeed;
		break;
	case 'w':
	case 'W':
		center[0] += dir.x * viewMoveSpeed;
		center[1] += dir.y * viewMoveSpeed;
		break;
	case 'd':
	case 'D':
		center[0] -= left.x * viewMoveSpeed;
		center[1] -= left.y * viewMoveSpeed;
		break;
	case 's':
	case 'S':
		center[0] -= dir.x * viewMoveSpeed;
		center[1] -= dir.y * viewMoveSpeed;
		break;
	default:
		break;
	}
}
//效果不理想
//void dsPassiveMonitionFunc(int x,int y){
//	extern int width;
//	extern int height;
//	if(x<width/20){
//		center[0]-=viewMoveSpeed;
//	}else if(x>width*19/20){
//		center[0]+=viewMoveSpeed;
//	}
//}


// 测试用的函数，画一个直角坐标系
void dsShowAxes(void) {
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(center[0],center[1],center[2]);
	glBegin(GL_LINES);
	{
		glLineWidth(1.0);
		glColor3d(1.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3f(axeLength, 0.0, 0.0);

		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3f(0.0, axeLength, 0.0);

		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, axeLength);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

void drawRectange(int x,int y,int width,int length,int height){
	glBegin(GL_QUADS);
		glVertex3d(x,y,height);
		glVertex3d(x+width,y,height);
		glVertex3d(x+width,y+length,height);
		glVertex3d(x,y+length,height);
	glEnd();
}