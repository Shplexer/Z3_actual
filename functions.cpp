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

int checkInt() {
	return checkInput<int>();
}

bool checkBool() {
	return checkInput<bool>();
}

void giveGreeting() {

	cout << "===================================================================================================================" << endl;
	cout << "Welcome!" << endl << "Made by Orekhov Daniil, group 423, task #3, variant 15" << endl;
	cout << "===================================================================================================================" << endl;
	cout << "Task: Develop a program that sorts an array using bubble, selection, insertion, shell and quick sorting methods" << endl <<
		"Input an unsorted matrix consisting of N lines and M columns" << endl <<
		"Output to console unsorted and sorted matrices" << endl <<
		"Create a table that shows the effectiveness of sorting methods by comparing the number of swaps and comparisons of each method" << endl;
	cout << "===================================================================================================================" << endl;
}

void giveChart(std::shared_ptr<quickSort> quickS, std::shared_ptr<bubbleSort> bubbleS, std::shared_ptr<selectionSort> selS, std::shared_ptr<shellSort> shellS, std::shared_ptr<insertionSort> insS) {
	cout << "===================================================================================================================" << endl;
	cout << "Comparison chart" << endl;
	cout << "===================================================================================================================" << endl;
	cout
		<< std::left
		<< std::setw(LNG) << "#"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Bubble"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Selection"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Inserton"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Shell"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Quick"
		<< std::setw(SHRT) << "||"
		<< endl;
	cout << "===================================================================================================================" << endl;
	cout
		<< std::left
		<< std::setw(LNG) << "Comparisons: "
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << bubbleS->getComps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << selS->getComps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << insS->getComps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << shellS->getComps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << quickS->getComps()
		<< std::setw(SHRT) << "||"
		<< endl;
	cout
		<< std::left
		<< std::setw(LNG) << "Swaps: "
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << bubbleS->getSwaps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << selS->getSwaps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << insS->getSwaps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << shellS->getSwaps()
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << quickS->getSwaps()
		<< std::setw(SHRT) << "||"
		<< std::right << endl;
	cout << "===================================================================================================================" << endl;

}

void giveMainMenu() {
	cout
		<< "1. Test" << endl
		<< "2. Load a file" << endl
		<< "3. Manual input" << endl
		<< "4. Random input" << endl
		<< "5. Exit" << endl;
	cout << "===================================================================================================================" << endl;
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
				srcMat[i][j] = checkInt();
			}
		}
		break;
	case fileMenuChoice::random:
		cout << "Enter lowest random number: " << endl;
		int lowest = checkInt();
		int highest = 0;
		do{
			cout << "Enter highest random number: " << endl;
			highest = checkInt();
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

void showMat(std::vector<std::vector<int> >& srcMat) {
	int numRows = static_cast<int>(srcMat.size());
	int numCols = static_cast<int>(srcMat[0].size());
	for (auto i = 0; i < numRows; i++) {
		for (auto j = 0; j < numCols; j++) {
			cout << srcMat[i][j] << " ";
		}
		cout << endl;
	}
}

std::string makeLineGood() {
	std::string input{ "==" };
	std::getline(cin >> std::ws, input);
	for (auto i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			input[i] = '_';
		}
	}
	return input;
}

std::string getGoodLine(std::string input) {
	std::string temp = input;
	for (auto i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = ' ';
		}
	}
	return temp;
}
