
#pragma once
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

void mergeC(int a[], int first, int mid, int last, long long& compare);
void mergeSortC(int a[], int first, int last, long long& compare);

void heapRebuildC(int a[], int n, int start, long long& compare);
void heapSortC(int a[], int n, long long& compare);

void radixSortC(int a[], int n, long long& compare);

void flashSortC(int a[], int n, long long& compare);

void quickSortC(int a[], int left, int right, long long& compare);

void shakerSortC(int a[], int n, long long& compare);

void shellSortC(int a[], int n, long long& compare);

void countingSortC(int a[], int n, long long& compare);

void selectionSortC(int a[], int n, long long& comp);

void insertionSortC(int a[], int n, long long& comp);

void bubbleSortC(int a[], int n, long long& comp);

void bubbleSort(int a[], int n, double& time);

void insertionSort(int a[], int n, double& time);

void selectionSort(int a[], int n, double& time);

void merge(int a[], int first, int mid, int last);
void mergeSort(int a[], int first, int last);

void heapRebuild(int a[], int n, int start);
void heapSort(int a[], int n);

void radixSort(int a[], int n, double &time);

void flashSort(int a[], int n, double &time);

void shakerSort(int arr[], int n, double &time);

void quickSort(int a[], int left, int right);

void countingSort(int a[], int n, double& time);

void shellSort(int a[], int n, double& time);

