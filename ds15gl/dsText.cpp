#include "dsText.h"

static bool dsTextGenerated = false;
static GLuint texts; // ��ʾ�б�
static const GLuint MAX_CHAR = 128;

void drawString(const char* str) {
	if (!dsTextGenerated) { // ����ǵ�һ�ε��ã�ִ�г�ʼ��
		// Ϊÿһ��ASCII�ַ�����һ����ʾ�б�
		dsTextGenerated = true;

		// ����MAX_CHAR����������ʾ�б����
		texts = glGenLists(MAX_CHAR);

		// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, texts);
	}
	// ����ÿ���ַ���Ӧ����ʾ�б�������ÿ���ַ�
	for(; *str != '\0'; ++str)
		glCallList(texts + *str);
}