#include"CommandLine.h"
#include"SortingAlgorithms.h"
#include<iomanip>

bool isDigit(char* s) {
	int i = 1;
	while (s[i] != '\0') {
		if (s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

void checkAlgorithmNameC(string algorithmName, int a[], int n, long long& compare) {
	if (algorithmName == "selection-sort")
		selectionSortC(a, n, compare);
	else if (algorithmName == "insertion-sort")
		insertionSortC(a, n, compare);
	else if (algorithmName == "bubble-sort")
		bubbleSortC(a, n, compare);
	else if (algorithmName == "shaker-sort")
		shakerSortC(a, n, compare);
	else if (algorithmName == "shell-sort")
		shellSortC(a, n, compare);
	else if (algorithmName == "heap-sort")
		heapSortC(a, n, compare);
	else if (algorithmName == "merge-sort")
		mergeSortC(a, 0, n - 1, compare);
	else if (algorithmName == "quick-sort")
		quickSortC(a, 0, n - 1, compare);
	else if (algorithmName == "counting-sort")
		countingSortC(a, n, compare);
	else if (algorithmName == "radix-sort")
		radixSortC(a, n, compare);
	else if (algorithmName == "flash-sort")
		flashSortC(a, n, compare);
	else
		cout << "Unknown sorting algorithm!";
}

void checkAlgorithmNameT(string algorithmName, int a[], int n, double& time) {
	if (algorithmName == "selection-sort") {
		selectionSort(a, n, time);
		return;
	}
	else if (algorithmName == "insertion-sort") {
		insertionSort(a, n, time);
		return;
	}
	else if (algorithmName == "bubble-sort") {
		bubbleSort(a, n, time);
		return;
	}
	else if (algorithmName == "shaker-sort") {
		shakerSort(a, n, time);
		return;
	}
	else if (algorithmName == "shell-sort") {
		shellSort(a, n, time);
		return;
	}
	else if (algorithmName == "heap-sort") {
		clock_t start, end;
		start = clock();
		
		heapSort(a, n);

		end = clock();

		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}
	else if (algorithmName == "merge-sort") {
		clock_t start, end;
		start = clock();

		mergeSort(a, 0, n - 1);

		end = clock();

		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}
	else if (algorithmName == "quick-sort") {
		clock_t start, end;
		start = clock();

		quickSort(a, 0, n - 1);

		end = clock();

		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}
	else if (algorithmName == "counting-sort") {
		countingSort(a, n, time);
		return;
	}
	else if (algorithmName == "radix-sort") {
		radixSort(a, n, time);
		return;
	}
	else if (algorithmName == "flash-sort") {
		flashSort(a, n, time);
		return;
	}
	else
		cout << "Unknown sorting algorithm!";
}

void changeName(string& name) {
	for (int i = 0; i < name.size(); i++)
		if (name[i] == '-') {
			name[i] = ' ';
			break;
		}
	name[0] = toupper(name[0]);
}

void checkOutput(string output, long long compare, double time) {
	if (output == "-time")
		cout << "Running time: " << setprecision(10) << fixed << time << "\n\n";
	else if (output == "-comp")
		cout << "Comparisions: " << compare << "\n\n";
	else if (output == "-both") {
		cout << "Running time: " << setprecision(10) << fixed << time << endl;
		cout << "Comparisions: " << compare << "\n\n";
	}
}

void checkOrder(string order, int a[], int n, string& orderName) {
	int type;
	if (order == "-rand") {
		orderName = "Randomize";
		type = 0;
	}
	else if (order == "-sorted") {
		orderName = "Sorted";
		type = 1;
	}
	else if (order == "-rev") {
		orderName = "Reversed";
		type = 2;
	}
	else if (order == "-nsorted") {
		orderName = "Nearly sorted";
		type = 3;
	}
	else
		type = 4;

	GenerateData(a, n, type);
}

void cmd1(string algorithmName, string fileName, string output) {
	long long compare = 0;
	double time = 0;
	int n;

	int* a;
	readFile(fileName, a, n);

	if (output == "-comp")
		checkAlgorithmNameC(algorithmName, a, n, compare);
	else if (output == "-time")
		checkAlgorithmNameT(algorithmName, a, n, time);
	else if (output == "-both") {
		int* b;

		copyArray(a, b, n);
		checkAlgorithmNameC(algorithmName, a, n, compare);
		checkAlgorithmNameT(algorithmName, b, n, time);

		delete[]b;
	}
	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	string fileOut = "output.txt";
	writeToFile(fileOut, a, n);


	delete[]a;

}

void cmd2(string algorithmName, string order, string output, int n) {
	long long compare = 0;
	double time = 0;
	string orderName = "";


	int* a = new int[n];
	checkOrder(order, a, n, orderName);

	string fileOut = "input.txt";
	writeToFile(fileOut, a, n);

	if (output == "-comp")
		checkAlgorithmNameC(algorithmName, a, n, compare);
	else if (output == "-time")
		checkAlgorithmNameT(algorithmName, a, n, time);
	else if (output == "-both") {
		int* b;
		copyArray(a, b, n);
		checkAlgorithmNameC(algorithmName, a, n, compare);
		checkAlgorithmNameT(algorithmName, b, n, time);

		delete[]b;
	}

	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input order: " << orderName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	fileOut = "output.txt";
	writeToFile(fileOut, a, n);

	delete[]a;
}

void cmd3(string algorithmName, string output, int n) {
	long long compare[4] = {};
	double time[4] = {};
	string orderName[4] = { "Randomize", "Sorted", "Reversed", "Nearly sorted" };
	string fileName[4] = { "input_1.txt", "input_3.txt", "input_4.txt", "input_2.txt" };

	int** a = new int* [4];
	for (int i = 0; i < 4; i++) {
		a[i] = new int[n];
		GenerateData(a[i], n, i);
	}

	for (int i = 0; i < 4; i++) {
		writeToFile(fileName[i], a[i], n);
		if (output == "-comp")
			checkAlgorithmNameC(algorithmName, a[i], n, compare[i]);
		else if (output == "-time")
			checkAlgorithmNameT(algorithmName, a[i], n, time[i]);
		else if (output == "-both") {
			int* b;

			copyArray(a[i], b, n);
			checkAlgorithmNameC(algorithmName, a[i], n, compare[i]);
			checkAlgorithmNameT(algorithmName, b, n, time[i]);

			delete[]b;
		}
	}
	changeName(algorithmName);

	cout << "Algorithm name: " << algorithmName << endl;
	cout << "Input size: " << n << "\n\n";

	for (int i = 0; i < 4; i++) {
		cout << "Input order: " << orderName[i] << endl;
		cout << "-------------------------\n";
		checkOutput(output, compare[i], time[i]);
	}

	for (int i = 1; i < 4; i++)
		delete[]a[i];
	delete[]a;

}

void cmd4(string algo1, string algo2, string fileName) {
	long long compare[2] = {};
	double time[2];

	int* a1, * a2;
	int n;
	readFile(fileName, a1, n);
	readFile(fileName, a2, n);

	int* b1, * b2;
	copyArray(a1, b1, n);
	copyArray(a2, b2, n);

	checkAlgorithmNameC(algo1, a1, n, compare[0]);
	checkAlgorithmNameC(algo2, a2, n, compare[1]);

	checkAlgorithmNameT(algo1, b1, n, time[0]);
	checkAlgorithmNameT(algo1, b2, n, time[1]);

	changeName(algo1);
	changeName(algo2);

	cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	cout << "Running time: " << time[0] << " | " << time[1] << endl;
	cout << "Comparisions: " << compare[0] << " | " << compare[1] << endl;

	delete[]a1;
	delete[]a2;
	delete[]b1;
	delete[]b2;
}

void cmd5(string algo1, string algo2, string order, int n) {
	long long compare[2] = {};
	double time[2];
	string fileName = "input.txt";

	int* a1, * a2, * b1, * b2;
	a1 = new int[n];

	checkOrder(order, a1, n, order);
	writeToFile(fileName, a1, n);
	readFile(fileName, a2, n);
	readFile(fileName, b1, n);
	readFile(fileName, b2, n);

	checkAlgorithmNameC(algo1, a1, n, compare[0]);
	checkAlgorithmNameC(algo2, a2, n, compare[1]);

	checkAlgorithmNameT(algo1, a1, n, time[0]);
	checkAlgorithmNameT(algo2, a2, n, time[1]);

	changeName(algo1);
	changeName(algo2);

	cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: " << order << endl;
	cout << "-------------------------\n";

	cout << "Running time: " << time[0] << " | " << time[1] << endl;
	cout << "Comparisions: " << compare[0] << " | " << compare[1] << endl;

	delete[]a1;
	delete[]a2;
	delete[]b1;
	delete[]b2;
}