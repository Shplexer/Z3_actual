#include "functions.h"

template<typename T>
T checkInput() {
	T userInput{};
	while (!(cin >> userInput)) {
		cin.clear();											//discard err flag
		cin.ignore(INT_MAX, '\n');								//clear buffer for INT_MAX characters or until '\n'
		cout << "ERR. Wrong input, try again" << endl;
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}

int checkInputInt() {
	return checkInput<int>();
}

void fillMatrix(std::vector<std::vector<int> >& srcMat, int operationInt, std::string fileName) {
	int numRows = static_cast<int>(srcMat.size());
	int numCols = static_cast<int>(srcMat[0].size());
	fileMenuChoice operation = static_cast<fileMenuChoice>(operationInt);
	switch (operation)
	{
	case fileMenuChoice::file:
		setMat(srcMat, fileName);
		break;
	case fileMenuChoice::empty:
		cout << "Enter your matrix elements: " << endl;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				cout << "a[" << i + 1 << "][" << j + 1 << "]: ";
				srcMat[i][j] = checkInputInt();
			}
		}
		break;
	case fileMenuChoice::random:
		cout << "Enter lowest random number: " << endl;
		int lowest = checkInputInt();
		int highest = 0;
		do{
			cout << "Enter highest random number: " << endl;
			highest = checkInputInt();
		} while (highest < lowest);
		int range = (highest - lowest) + 1;
		srand(static_cast<unsigned int>(time(NULL)));
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				srcMat[i][j] = lowest + (rand() % range);
				//srcMat[i][j] = rand();
			}
		}
		break;
	}
}

std::string stringInput() {
	std::string input{ "==" };
	std::getline(cin >> std::ws, input);
	for (auto i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			input[i] = '_';
		}
	}
	return input;
}

std::string stringOutput(std::string input) {
	std::string temp = input;
	for (auto i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = ' ';
		}
	}
	return temp;
}
int positiveInput(){
	int input = 0;
	do {
		input = checkInputInt();
		if (input <= 0)
			cout << "ERR. Wrong input. Try again." << endl;
	} while (input <= 0);
	return input;
}
std::tuple<std::vector<std::vector<int> >, std::string> mainMenuControl(){
	std::string fileName{};
	int numRows = 0;
	int numCols = 0;
	bool exitFlag = true;
	fileMenuChoice choice;

	do {
		exitFlag = true;
		cout << "===================================================================================================================" << endl;
		giveMainMenu();
		choice = static_cast<fileMenuChoice>(checkInputInt());
		switch (choice)
		{
		case fileMenuChoice::test:
			launchTest();
			exitFlag = false;
			break;
		case fileMenuChoice::file:
			std::tie(fileName, exitFlag) = openFile();
			if (exitFlag) {
				std::tie(numRows, numCols, exitFlag) = countMatSize(fileName);
			}
			break;
		case fileMenuChoice::empty:
			cout << "Rows: ";
			numRows = positiveInput();
			cout << "Columns: ";
			numCols = positiveInput();
			break;
		case fileMenuChoice::random:
			cout << "Rows: ";
			numRows = positiveInput();
			cout << "Columns: ";
			numCols = positiveInput();
			break;
		case fileMenuChoice::exit:
			cout << "Exiting the program...";
			std::exit(0);
		default:
			cout << "ERR. Wrong input, try again" << endl;
			exitFlag = false;
			break;
		}
	} while (!exitFlag);
	std::vector<std::vector<int> > mat(numRows, std::vector<int>(numCols));
	if (choice != fileMenuChoice::test) {
		fillMatrix(mat, static_cast<int>(choice), fileName);
	}
	return std::tuple(mat, fileName);
}

void sortAll(std::vector<std::shared_ptr<ISort>> sortMethods, std::vector<std::vector<int>> mat) {
	cout << "Input matrix: " << endl;
	showMat(mat);
	for (int i = 0; i < sortMethods.size(); i++) {
		cout << "===================================================================================================================" << endl;
		sortMethods[i]->setMat(mat);
		sortMethods[i]->sort();
		cout << sortMethods[i]->getName() << endl;
		sortMethods[i]->showMat();
		cout << "Swaps: " << sortMethods[i]->getSwaps() << " Comps: " << sortMethods[i]->getComps() << endl;
	}
}