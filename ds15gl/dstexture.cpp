#include "dstexture.h"

GLuint dsLoadTextureBMP2D(const char* file_name) {
	const int BMP_Header_Length = 54;

	GLint width, height, total_bytes;
	GLubyte* pixels = nullptr;
	
	// ���ļ�
	ifstream is;
	is.open(file_name, is.in | is.binary);
	if (!is) {
		return 0;
	}

	// ��ȡͼ��Ŀ�Ⱥ͸߶�
	is.seekg(0x0012, is.beg);
	is.read((char*)&width, sizeof(width));

	is.seekg(0x0016, is.beg);
	is.read((char*)&height, sizeof(height));

	is.seekg(BMP_Header_Length, is.beg);

	// ����ÿ��������ռ�ֽ����������ݴ����ݼ����������ֽ���
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
			++line_bytes;
		total_bytes = line_bytes * height;
	}

	// �����������ֽ��������ڴ�
	pixels = new GLubyte[total_bytes];
	if (pixels == nullptr){
		is.close();
		return 0;
	}
	
	// ��ȡ����ͼƬ����
	if (is.read((char*)pixels, total_bytes) <= 0) {
		delete[] pixels;
		is.close();
		return 0;
	}
	is.close();

	// ���������ǲ��������������

	// ȡ���µ�������
	GLuint texture_ID = 0;
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0) {
		delete[] pixels;
		is.close();
		return 0;
	}

	// ���µ������������������������
	
	// ����ԭ���󶨵�������
	GLuint last_texture_ID;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&last_texture_ID);

	// ���µ������Ա���в���
	glBindTexture(GL_TEXTURE_2D, texture_ID);

	// ���������ŵ�С��״�������Բ�ֵ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// ���С����ŵ�����״ʱ�������Բ�ֵ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// ������� x ���곬����Χ�����ظ���Ĭ��ֵ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	// ������� y ���곬����Χ�����ظ���Ĭ��ֵ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// ���������ɫ����ԭ������ɫ��Ĭ��ֵ
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// ��������
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
				 GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

	// �ٰѵ�ǰ����󶨻�ԭ�����Ǹ�����Ȼ�µ������Ѿ�������������
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	delete[] pixels;

	return texture_ID;
}