#include "tablica.h"
#include "tablica_wysw.h"
#include "tablica_funkcje.h"
#include "pliki.h"
#include "menu.h"
#include <iostream>

using namespace std;

void functions_menu(class Array *arr, bool isRow)
{
	if(arr->isArrayInitialized() == false)
	{
		system("clear");
		cout << "Najpierw musisz utworzyc tablice!" << endl;
		menu(arr);
	}
	else if(arr->is_default_numeric == false)
	{
		system("clear");
		cout << "Operacje mozna wykonac tylko na tabeli z danymi liczbowymi!" << endl;
		menu(arr);
	}
	else
	{
		int cellId = 0, choice = 0;
		cout << "Podaj numer ";
		if(isRow)
		{
			cout << "wiersza";
		}
		else
		{
			cout << "kolumny";
		}
		cout << ": ";
		cin >> cellId;

		if(!cin)
		{
			cin.clear();   
			cin.ignore(100, '\n');
		}

		if(isRow)
		{
			if(cellId > 0 && cellId - 1 < arr->getArraySizeX())
			{
				cout << "1. Zsumuj komorki" << endl;
				cout << "2. Znajdz wartosc maksymalna" << endl;
				cout << "3. Znajdz wartosc minimalna" << endl;
				cout << "4. Znajdz srednia" << endl;
				cout << "Wybierasz: ";
				cin >> choice;

				if(!cin)
				{
					cin.clear();   
					cin.ignore(100, '\n');
				}

				switch(choice)
				{
					case 1:
						cout << "Suma komorek w wierszu: " << sumRow(arr, cellId) << endl;
						menu(arr);
						break;
					case 2:
						cout << "Maksymalna wartosc w wierszu: " << findMaxInRow(arr, cellId) << endl;
						menu(arr);
						break;
					case 3:
						cout << "Minimalna wartosc w wierszu: " << findMinInRow(arr, cellId) << endl;
						menu(arr);
						break;
					case 4:
						cout << "Srednia wartosc w wierszu: " << findAvgInRow(arr, cellId) << endl;
						menu(arr);
						break;
					default:
						system("clear");
						cout << "Wybrales niewlasciwa opcje!";
						functions_menu(arr, isRow);
						break;
				}
			}
			else
			{
				system("clear");
				cout << "Podales niewlasciwy numer wiersza!" << endl;
				functions_menu(arr, isRow);
			}
		}
		else
		{
			if(cellId > 0 && cellId - 1 < arr->getArraySizeY())
			{
				cout << "1. Zsumuj komorki" << endl;
				cout << "2. Znajdz wartosc maksymalna" << endl;
				cout << "3. Znajdz wartosc minimalna" << endl;
				cout << "4. Znajdz srednia" << endl;
				cout << "Wybierasz: ";
				cin >> choice;

				if(!cin)
				{
					cin.clear();   
					cin.ignore(100, '\n');
				}

				switch(choice)
				{
					case 1:
						cout << "Suma komorek w kolumnie: " << sumCol(arr, cellId) << endl;
						menu(arr);
						break;
					case 2:
						cout << "Maksymalna wartosc w kolumnie: " << findMaxInCol(arr, cellId) << endl;
						menu(arr);
						break;
					case 3:
						cout << "Minimalna wartosc w kolumnie: " << findMinInCol(arr, cellId) << endl;
						menu(arr);
						break;
					case 4:
						cout << "Srednia wartosc w kolumnie: " << findAvgInCol(arr, cellId) << endl;
						menu(arr);
						break;
					default:
						system("clear");
						cout << "Wybrales niewlasciwa opcje!";
						functions_menu(arr, isRow);
						break;
				}
			}
			else
			{
				system("clear");
				cout << "Podales niewlasciwy numer kolumny!" << endl;
				functions_menu(arr, isRow);
			}
		}
	}
}

void setSize_menu(class Array *arr)
{
	int x, y;
	do
	{
		x = 0;
		cout << "Podaj ilosc wierszy: ";
		cin >> x;
		if(!cin){
			cin.clear();   
			cin.ignore(100, '\n');
		}
		system("clear");
		
	} while(x <= 0);

	do
	{	
		y = 0;
		cout << "Podaj ilosc kolumn: ";
		cin >> y;
		if(!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("clear");
	} while(y <= 0);

	if (arr->isArrayInitialized() == false)
	{
		short type_choice;
		system("clear");
		cout << "Wybierz domyslny typ danych w tablicy:" << endl;
		cout << "1. Liczbowe" << endl;
		cout << "2. Tekstowe" << endl;
		cout << "Wybierasz: ";
		cin >> type_choice;
		if(!cin)
		{
			cin.clear();   
			cin.ignore(100, '\n');
		}
		switch(type_choice)
		{
			case 1:
				arr->is_default_numeric = true;
				arr->setArraySize(x, y);
				break;
			case 2:
				arr->is_default_numeric = false;
				arr->setArraySize(x, y);
				break;
			default:
				system("clear");
				cout << "Wybrales nieprawidlowa opcje!" << endl;
				setSize_menu(arr);
				break;
		}
	}
}

void editCell_menu(class Array *arr)
{
	if(arr->getArraySizeX() == 0 || arr-> getArraySizeY() == 0)
	{
		system("clear");
		cout << "Najpierw musisz utworzyc tablice!" << endl;
	}
	else
	{
		int x = 0, y = 0, valueNum;
		string valueText;
		do
		{
			system("clear");
			cout << "Numer wiersza: ";
			cin >> x;
			cout << "Numer kolumny: ";
			cin >> y;
			if(arr->getCell(x, y)->is_numeric)
			{
				cout << "Liczba: ";
				cin >> valueNum;
			}
			else
			{
				cout << "Tekst: ";
				cin >> valueText;
			}
		} while(arr->setValue(x - 1, y - 1, valueNum) == -10 && arr->setValue(x - 1, y - 1, valueText) == -10);
		system("clear");
	}
}

int menu(class Array *arr)
{
	int choice = 0;
	cout << "1. Ustaw rozmiar tablicy" << endl;
	cout << "2. Edytuj tresc komorek" << endl;
	cout << "3. Wyswietl tablice" << endl;
	cout << "4. Odczyt z pliku" << endl;
	cout << "5. Zapis do pliku" << endl;
	cout << "6. Operacje na wierszu" << endl;
	cout << "7. Operacje na kolumnie" << endl;
	cout << "8. Wyjdz z programu" << endl;
	cout << "Wybierasz: ";
	
	cin >> choice;

	if(!cin)
	{
		cin.clear();   
		cin.ignore(100, '\n');
	}

	system("clear");
	switch(choice)
	{
		case 1:
			setSize_menu(arr);
			menu(arr);
			break;
		case 2:
			editCell_menu(arr);
			menu(arr);
			break;
		case 3:
			tablica_wysw(arr);
			menu(arr);
			break;
		case 4:
			readFile(arr);
			menu(arr);
			break;
		case 5:
			saveFile(arr);
			menu(arr);
			break;
		case 6:
			functions_menu(arr, true);
			break;
		case 7:
			functions_menu(arr, false);
			break;
		case 8:
			return 0;
			break;
		default:
			cout << "Wartosc ktora wprowadziles jest nieprawidlowa!" << endl;
			menu(arr);
			break;
	}
}
