#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insertSort(int* a,int n);
void SortTest();
void _print(int* a,int n);
void ShellSort(int* a,int gap,int n);
void adjust(int* a,int n,int parent);
void Swap(int* a,int* b);