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
		cout<<std::endl;
		for(int j=0; j < arr->getArraySizeY(); j++)
		{
			s << arr->getValue(i, j) <<" | ";
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