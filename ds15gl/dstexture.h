#ifndef _DSTEXTURE_H
#define _DSTEXTURE_H

#include <GL/glut.h>
#include <fstream>

using std::ifstream;

// ����һ�� 24bit BMP ͼƬΪ�������������ţ�������ɹ������� 0
// �����д����������޷�������ָ�룬Ĭ��Ϊ��ָ�룬���ǿգ��������м�¼ͼƬ�ĳߴ�
GLuint dsLoadTextureBMP2D(const char* file_name, GLuint* pheight = nullptr, GLuint* pwidth = nullptr);

#endif