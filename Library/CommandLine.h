#pragma once
#include"DataGenerator.h"


bool isDigit(char* s);

void checkAlgorithmNameC(string algorithmName, int a[], int n, long long& compare);
void checkAlgorithmNameT(string algorithmName, int a[], int n, double& time);

void changeName(string& name);

void checkOutput(string output, long long compare, double time);

void checkOrder(string order, int a[], int n, string& orderName);

void cmd1(string algorithmName, string fileName, string output);
void cmd2(string algorithmName, string order, string output, int n);
void cmd3(string algorithmName, string output, int n);
void cmd4(string algo1, string algo2, string fileName);
void cmd5(string algo1, string algo2, string order, int n);