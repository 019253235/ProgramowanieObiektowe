#ifndef TABLICA_H
#define TABLICA_H

#include <string>
using namespace std;

// Klasa obsługująca tablicę

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

// Klasa obsługująca komórki

class Cell {
    public:
		double getValueNum();
		string getValueText();
		short getValueType();
		void setValue(double val);
		void setValue(string val);
	private:
		double num_val = 0;
		string text_val = "";
		short value_type = 0; // Typ zmiennej -> 1 = double, 2 = string
};

#endif