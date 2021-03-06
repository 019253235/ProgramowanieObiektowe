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
	is_numeric = type;
}

int Array::setArraySize(int x, int y) // Metoda tworząca tablicę
{
	if(arrayIsInitialized == false)
	{
		if(x > 0 && y > 0)
		{
			sizeX = x;
			sizeY = y;
			arr = new Cell *[sizeX];
			for(int i = 0; i < sizeX; i++)
			{
				arr[i] = new Cell[sizeY];
				arr[i]->is_numeric = is_numeric;
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
	if(isInBounds(x,y) && is_numeric)
	{
		arr[x][y].setValue(value);
	}
	else
	{
		return -10;
	}
}

int Array::setValue(int x, int y, string value)
{
	if(isInBounds(x,y) && (is_numeric == false))
	{
		arr[x][y].setValue(value);
	}
	else
	{
		return -10;
	}
}

double Array::getValueNum(int x, int y)
{
	if(isInBounds(x,y))
	{
		return arr[x][y].getValueNum();
	}
	else
	{
		return -10;
	}
}

string Array::getValueText(int x, int y)
{
	if(isInBounds(x,y))
	{
		return arr[x][y].getValueText();
	}
	else
	{
		return "-10";
	}
}

int Array::getArraySizeX() { return sizeX; }
int Array::getArraySizeY() { return sizeY; }


// Klasa obsługująca komórki

double Cell::getValueNum()
{
	if(is_numeric == true)
	{
		return num_val;
	}
}

string Cell::getValueText()
{
	if(is_numeric == false)
	{
		return text_val;
	}
}

void Cell::setValue(double val)
{
	if (num_val == 0 && text_val == "")
	{
		is_numeric = true;
	}

	if(is_numeric == true)
	{
		num_val = val;
	}
	else
	{
		text_val = to_string(val);
	}
}

void Cell::setValue(string val)
{
	if (num_val == 0 && text_val == "")
	{
		is_numeric = false;
	}

	if(is_numeric == false)
	{
		text_val = val;
	}
}