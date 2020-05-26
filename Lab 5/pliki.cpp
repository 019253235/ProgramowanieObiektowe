#include <fstream>
#include <iostream>
#include "menu.h"
#include "tablica.h"
#include "pliki.h"

using namespace std;

int saveFile(class Array *arr) // Zapis do pliku
{
	ofstream s;
	s.open("baza.txt");
	for(int i = 0; i < arr->getArraySizeX(); i++)
	{
		cout << endl;
		for(int j=0; j < arr->getArraySizeY(); j++)
		{
			if(arr->is_numeric)
			{
				s << arr->getValueNum(i, j) << " | ";
			}
			else
			{
				s << arr->getValueText(i, j) << " | ";
			}
		}
		s << endl;
	}
	s.close();
}

int readFile(class Array *arr) // Odczyt z pliku
{
	string currentLine;
	ifstream s;
	s.open("baza.txt");
	
	if(s.good())
	{
		while(!s.eof())
		{
			getline(s,currentLine);
			cout<< currentLine << endl;
		}
	}
	else
	{ 
	cout << "Plik nie istnieje.";
	}
	s.close();
}