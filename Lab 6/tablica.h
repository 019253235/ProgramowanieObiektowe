#ifndef TABLICA_H
#define TABLICA_H

#include <string>
using namespace std;

// Klasa obsługująca komórki

class Cell {
	
	protected:
		bool is_numeric;
	public:
		bool isNumeric();
		virtual void setValue(double val) = 0;
		virtual void setValue(string val) = 0;
		virtual double getValueNum() = 0;
		virtual string getValueText() = 0;
};

class NumericCell:  public Cell
{
	private:
		double value;
	public:
		void setValue(double val);
		void setValue(string val);
		double getValueNum();
		string getValueText();
		NumericCell();
};

class TextCell : public Cell
{
	private:
		string value;
	public:
		void setValue(double val);
		void setValue(string val);
		double getValueNum();
		string getValueText();
		TextCell();
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
		// double getValueNum(int x, int y);
		// string getValueText(int x, int y);
		Cell* getCell(int x, int y);
		int getArraySizeX();
		int getArraySizeY();
		void setArrayType(bool type);
		bool is_default_numeric;
		int setColType(int col, bool is_col_numeric, bool safeToDelete = true);
		bool getColType(int col);
	private:
		int sizeX = 0;
		int sizeY = 0;
		bool arrayIsInitialized = false;
		bool *colType;
		Cell ***arr;
};

#endif