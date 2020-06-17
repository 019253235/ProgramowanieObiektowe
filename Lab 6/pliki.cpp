#include <fstream>
#include <iostream>
#include "menu.h"
#include "tablica.h"
#include "pliki.h"

using namespace std;

void saveFile(class Array *arr) // Zapis do pliku
{
	ofstream s;
	s.open("baza.txt");
	s << arr->getArraySizeX() << endl;
	s << arr->getArraySizeY() << endl;
	s << arr->is_default_numeric << endl;
	for (int i = 0; i < arr->getArraySizeY(); i++)
	{
		s << arr->getColType(i) << endl;
	}
	for(int i = 0; i < arr->getArraySizeX(); i++)
	{
		for(int j=0; j < arr->getArraySizeY(); j++)
		{
			if (arr->getCell(i, j)->isNumeric())
			{
				s << arr->getCell(i, j)->getValueNum() << endl;
			}
			else
			{
				s << arr->getCell(i, j)->getValueText() << endl;
			}
		}
	}
	s.close();
}

void readFile(class Array *arr) // Odczyt z pliku
{
	string currentLine;
	ifstream s;
	s.open("baza.txt");
	
	if(s.good())
	{
		if (!s.eof())
		{
			if (arr->isArrayInitialized())
			{
				delete arr;
			}
			arr = new Array;
			int sizeX, sizeY;
			bool default_type;
			s >> sizeX;
			s >> sizeY;
			s >> default_type;
			arr->setArrayType(default_type);
			arr->setArraySize(sizeX, sizeY);
			for (int i = 0; i < sizeY; i++)
			{
				bool temp;
				s >> temp;
				arr->setColType(i, temp, false);
			}
		}
		for (int i = 0; i < arr->getArraySizeX(); i++)
		{
			for (int j = 0; j < arr->getArraySizeY(); j++)
			{
				if (arr->getColType(j))
				{
					double temp;
					s >> temp;
					arr->setValue(i, j, temp);
				}
				else
				{
					string temp;
					s >> temp;
					arr->setValue(i, j, temp);
				}
			}
		}
	}
	else
	{ 
	cout << "Plik nie istnieje." << endl;
	}
	s.close();
}