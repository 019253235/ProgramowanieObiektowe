#include "tablica.h"

int sumRow(class Array *arr, int row)
{
    int sum = 0;
    for(int i = 0; i < arr->getArraySizeY(); i++)
    {
        sum += arr->getCell(row - 1, i)->getValueNum();
    }
    return sum;
}

int sumCol(class Array *arr, int col)
{
    int sum = 0;
    for(int i = 0; i < arr->getArraySizeX(); i++)
    {
        sum += arr->getCell(col - 1, i)->getValueNum();
    }
    return sum;
}

int findMaxInRow(class Array *arr, int row)
{
    int max = 0;
    for(int i = 0; i < arr->getArraySizeY(); i++)
    {
        if (arr->getCell(row - 1, i)->getValueNum() > max)
        {
            max = arr->getCell(row - 1, i)->getValueNum();
        }
    }
    return max;
}

int findMaxInCol(class Array *arr, int col)
{
    double max = 0;
    for(int i = 0; i < arr->getArraySizeX(); i++)
    {
        if (arr->getCell(col - 1, i)->getValueNum() > max)
        {
            max = arr->getCell(col - 1, i)->getValueNum();
        }
    }
    return max;
}

int findMinInRow(class Array *arr, int row)
{
    int min;
    for(int i = 0; i < arr->getArraySizeY(); i++)
    {
        if(i == 0)
        {
            min = arr->getCell(row - 1, i)->getValueNum();
        }
        else if (arr->getCell(row - 1, i)->getValueNum() < min)
        {
            min = arr->getCell(row - 1, i)->getValueNum();
        }
    }
    return min;
}

int findMinInCol(class Array *arr, int col)
{
    int min;
    for(int i = 0; i < arr->getArraySizeX(); i++)
    {
        if(i == 0)
        {
            min = arr->getCell(col - 1, i)->getValueNum();
        }
        else if (arr->getCell(col - 1, i)->getValueNum() < min)
        {
            min = arr->getCell(col - 1, i)->getValueNum();
        }
    }
    return min;
}

double findAvgInRow(class Array *arr, int row)
{
    return sumRow(arr, row) / (arr->getArraySizeY() + 1);
}

double findAvgInCol(class Array *arr, int col)
{
    return sumCol(arr, col) / (arr->getArraySizeX() + 1);
}