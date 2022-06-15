#include"DataGenerator.h"
#include"SortingAlgorithms.h"
#include"CommandLine.h"
#include<string>

int main(int argc, char* argv[]) {
	string mode = argv[1];

	if (mode == "-a") {
		if (argc == 6)
			cmd2(argv[2], argv[4], argv[5], stoi(argv[3]));
		else if (argc == 5) {
			if (!isDigit(argv[3]))
				cmd1(argv[2], argv[3], argv[4]);
			else
				cmd3(argv[2], argv[4], stoi(argv[3]));
		}

	}
	else if (mode == "-c") {
		if (argc == 5)
			cmd4(argv[2], argv[3], argv[4]);
		else if (argc == 6)
			cmd5(argv[2], argv[3], argv[5], stoi(argv[4]));
	}
	else
		cout << "Unknown mode!";



	return 0;
}