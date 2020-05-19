#include "menu.h"
#include "tablica.h"
#include <iostream>

using namespace std;

int tablica_wysw(class Array *arr)
{	
	for(int i = 0; i < arr->getArraySizeX(); i++)
	{
		for(int j = 0; j < arr->getArraySizeY(); j++)
		{
			cout << arr->getValue(i, j) <<" | ";
			cout << endl;
		}
	}
}
