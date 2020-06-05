#include "menu.h"
#include "tablica.h"
#include <iostream>

using namespace std;

int tablica_wysw(class Array *arr)
{	
	for(int i = 0; i < arr->getArraySizeY(); i++)
	{
		cout << (arr->getColType(i) ? "L" : "T") << " ";
	}
	cout << endl << endl;

	for(int i = 0; i < arr->getArraySizeX(); i++)
	{
		for(int j = 0; j < arr->getArraySizeY(); j++)
		{
			if(arr->getCell(i, j)->is_numeric == true)
			{
				cout << arr->getCell(i, j)->getValueNum() << " | ";
			}
			else
			{
				cout << arr->getCell(i, j)->getValueText() << " | ";
			}
		}
		cout << endl;
	}
}
