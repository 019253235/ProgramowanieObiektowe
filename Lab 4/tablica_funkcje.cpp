#include "tablica.h"

int sumRow(class Array *arr, int row)
{
    int sum = 0;
    for(int i = 0; i < arr->getArraySizeY(); i++)
    {
        sum += arr->getValue(row - 1, i);
    }
    return sum;
}

int sumCol(class Array *arr, int col)
{
    int sum = 0;
    for(int i = 0; i < arr->getArraySizeX(); i++)
    {
        sum += arr->getValue(col - 1, i);
    }
    return sum;
}

int findMaxInRow(class Array *arr, int row)
{
    int max = 0;
    for(int i = 0; i < arr->getArraySizeY(); i++)
    {
        if (arr->getValue(row - 1, i) > max)
        {
            max = arr->getValue(row - 1, i);
        }
    }
    return max;
}

int findMaxInCol(class Array *arr, int col)
{
    int max = 0;
    for(int i = 0; i < arr->getArraySizeX(); i++)
    {
        if (arr->getValue(col - 1, i) > max)
        {
            max = arr->getValue(col - 1, i);
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
            min = arr->getValue(row - 1, i);
        }
        else if (arr->getValue(row - 1, i) < min)
        {
            min = arr->getValue(row - 1, i);
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
            min = arr->getValue(col - 1, i);
        }
        else if (arr->getValue(col - 1, i) < min)
        {
            min = arr->getValue(col - 1, i);
        }
    }
}

double findAvgInRow(class Array *arr, int row)
{
    return sumRow(arr, row) / (arr->getArraySizeY() + 1);
}

double findAvgInCol(class Array *arr, int col)
{
    return sumCol(arr, col) / (arr->getArraySizeX() + 1);
}