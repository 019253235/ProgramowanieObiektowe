#ifndef TABLICA_FUNKCJE_H
#define TABLICA_FUNKCJE_H

int sumRow(class Array *arr, int row);
int sumCol(class Array *arr, int col);
int findMaxInRow(class Array *arr, int row);
int findMaxInCol(class Array *arr, int col);
int findMinInRow(class Array *arr, int row);
int findMinInCol(class Array *arr, int col);
double findAvgInRow(class Array *arr, int row);
double findAvgInCol(class Array *arr, int col);

#endif