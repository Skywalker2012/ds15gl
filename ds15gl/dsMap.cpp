#include "dsMap.h"
#include <iostream>
using namespace std;

//���ļ���ʼ��һ�ŵ�ͼ
DSMap::DSMap(char* fileName)
{
	//���û�д����ļ����������һ�� 100 * 100 �ĵ�ͼ��������Ԫ�ض���0
	if (strlen(fileName) == 0) {
		width = 100;
		height = 50;
		data = new int*[height];
		
		for(int i = 0; i < height; i++) {
			data[i] = new int[width];
			for (int j = 0; j < width; j++) {
				data[i][j] = 0;
			}
		}
	}
	//printf_s("%d\n",**data);
}


DSMap::~DSMap()
{
	for(int i = 0; i < height; i++){
		delete[] data[i];
	}
	delete[] data;
}
