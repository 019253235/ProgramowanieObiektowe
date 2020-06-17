#include "menu.h"
#include "tablica.h"
#include <iostream>

using namespace std;

// Klasa obsługująca tablicę

bool Array::isArrayInitialized()
{
	return arrayIsInitialized;
}

bool Array::isInBounds(int x, int y)
{
	return (x >= 0 && y >=0 && x < sizeX && y < sizeY);
}

bool Array::isInBoundsX(int x)
{
	return (x < sizeX && x >= 0);
}

bool Array::isInBoundsY(int y)
{
	return (y < sizeY && y >= 0);
}

void Array::setArrayType(bool type)
{
	is_default_numeric = type;
}

int Array::setArraySize(int x, int y) // Metoda tworząca tablicę
{
	if(arrayIsInitialized == false)
	{
		if(x > 0 && y > 0)
		{
			sizeX = x;
			sizeY = y;
			arr = new Cell **[sizeX];
			for(int i = 0; i < sizeX; i++)
			{
				arr[i] = new Cell *[sizeY];
				colType = new bool[sizeY];
			}

			for (int j = 0; j < sizeY; j++)
			{
				setColType(j, is_default_numeric, false);
			}
			arrayIsInitialized = true;
		}
		else
		{
			return -10; // Kod błędu dla nieprawidłowego rozmiaru
		}
	}
	else
	{
		return -11; // Kod błędu kiedy tablica jest już zainicjalizowana
	}
}

int Array::setValue(int x, int y, double value)
{
	if(isInBounds(x,y) && arr[x][y]->isNumeric())
	{
		arr[x][y]->setValue(value);
	}
	else
	{
		return -10;
	}
}

int Array::setValue(int x, int y, string value)
{
	if(isInBounds(x,y) && (arr[x][y]->isNumeric() == false))
	{
		arr[x][y]->setValue(value);
	}
	else
	{
		return -10;
	}
}

Cell* Array::getCell(int x, int y)
{
	return arr[x][y];
}

int Array::getArraySizeX() { return sizeX; }
int Array::getArraySizeY() { return sizeY; }

int Array::setColType(int col, bool is_col_numeric, bool safeToDelete)
{
	if (isInBoundsY(col))
	{
		colType[col] = is_col_numeric;
		for (int i = 0; i < sizeX; i++)
		{
			if (safeToDelete)
			{
				delete arr[i][col];
			}
			if (is_col_numeric)
			{
				arr[i][col] = new NumericCell;
			}
			else
			{
				arr[i][col] = new TextCell;
			}
		}
		return 0;
	}
	else
	{
		return -10; // Kod błędu dla kolumny poza granicami
	}
}

bool Array::getColType(int col)
{
	return colType[col];
}

// Klasa obsługująca komórki

bool Cell::isNumeric()
{
	return is_numeric;
}

double NumericCell::getValueNum()
{
	return value;
}

string NumericCell::getValueText()
{
	return to_string(value);
}

void NumericCell::setValue(double val)
{
	value = val;
}

void NumericCell::setValue(string val)
{
	value = stod(val);
}

NumericCell::NumericCell()
{
	is_numeric = true;
	value = 0;
}

string TextCell::getValueText()
{
	return value;
}

double TextCell::getValueNum()
{
	return stod(value);
}

void TextCell::setValue(string val)
{
	value = val;
}

void TextCell::setValue(double val)
{
	value = '0' + val;
}

TextCell::TextCell()
{
	is_numeric = false;
	value = " ";
}