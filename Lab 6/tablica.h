#ifndef TABLICA_H
#define TABLICA_H

#include <string>
using namespace std;

// Klasa obsługująca komórki

class Cell {
    public:
		double getValueNum();
		string getValueText();
		void setValue(double val);
		void setValue(string val);
		bool is_numeric;
	private:
		double num_val = 0;
		string text_val = "";
};

// Klasa obsługująca tablicę

class Array
{
	public:
		bool isArrayInitialized();
		bool isInBounds(int x, int y);
		bool isInBoundsX(int x);
		bool isInBoundsY(int y);
		int setArraySize(int x, int y);
    	int setValue(int x, int y, double value);
		int setValue(int x, int y, string value);
		double getValueNum(int x, int y);
		string getValueText(int x, int y);
		int getArraySizeX();
		int getArraySizeY();
		void setArrayType(bool type);
		bool is_numeric;
	private:
		int sizeX = 0;
		int sizeY = 0;
		bool arrayIsInitialized = false;
		Cell **arr;
};

#endif