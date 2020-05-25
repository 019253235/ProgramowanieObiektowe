#ifndef TABLICA_H
#define TABLICA_H

class Array
{
	public:
		bool isArrayInitialized();
		bool isInBounds(int x, int y);
		bool isInBoundsX(int x);
		bool isInBoundsY(int y);
		int setArraySize(int x, int y);
    	int setValue(int x, int y, int value);
		int getValue(int x, int y);
		int getArraySizeX();
		int getArraySizeY();
	private:
		int sizeX = 0;
		int sizeY = 0;
		bool arrayIsInitialized = false;
		int **arr;
};

#endif