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

int Array::setArraySize(int x, int y) // Metoda tworząca tablicę
{
	if(arrayIsInitialized == false)
	{
		if(x > 0 && y > 0)
		{
			sizeX = x;
			sizeY = y;
			arr = new int *[sizeX];
			for(int i = 0; i < sizeX; i++)
			{
				arr[i] = new int [sizeY];		
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

int Array::setValue(int x, int y, int value)
{
	if(isInBounds(x,y))
	{
		arr[x][y] = value;
	}
	else
	{
		return -10;
	}
}

int Array::getValue(int x, int y)
{
	if(isInBounds(x,y))
	{
		return arr[x][y];
	}
	else
	{
		return -10;
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

bool Cell::isNumeric()
{
	return is_numeric;
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
}

void Cell::setValue(string val)
{
	if (num_val == 0 && text_val == "")
	{
		is_numeric = false;
	}
	if(is_numeric = false)
	{
		text_val = val;
	}
}

Cell::Cell(double val)
{
	setValue(val);
}

Cell::Cell(string val)
{
	setValue(val);
}