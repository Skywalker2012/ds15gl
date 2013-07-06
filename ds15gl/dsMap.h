#pragma once

class DSMap {
public:
	DSMap(char* fileName = "");
	~DSMap();
public:
	const void getSize(int& width, int& height) {
		width = this->width;
		height = this->height;
	}

	const int getTile(int x, int y){
		//����Խ��
		if (x < 0 || x >= width || y < 0 || y >= height)
			return 0;

		return data[y][x];
	}
public:
	// ��ͼÿ��Ĵ�С
	static const int ElementSize = 4;
	
private:
	int width;
	int height;
	int** data;
};

