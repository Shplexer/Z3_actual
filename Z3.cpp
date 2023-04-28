#include "Z3.h"

int main() {
	int numRows = 0;
	int numCols = 0;
	bool exitFlag = false;
	quickSort quickS;
	bubbleSort bubbleS;
	selectionSort selS;
	shellSort shellS;
	insertionSort insS;
	fileMenuChoice choice;
	giveGreeting();
	//giveMenu();
	//Manual
	std::string fileName{};
	do{
		cout << "===================================================================================================================" << endl;
		giveMainMenu();
		exitFlag = true;
		do {
			choice = static_cast<fileMenuChoice>(checkInt());
			switch (choice)
			{
			case fileMenuChoice::test:
				//launchTest();
				exitFlag = false;
				break;
			case fileMenuChoice::file:
				fileName = openFile();
				std::tie(numRows, numCols) = countMatSize(fileName);
				break;
			case fileMenuChoice::empty:
				cout << "Rows: ";
				numRows = checkInt();
				cout << "Columns: ";
				numCols = checkInt();
				break;
			case fileMenuChoice::random:
				cout << "Rows: ";
				numRows = checkInt();
				cout << "Columns: ";
				numCols = checkInt();
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
		//std::vector<std::vector<int> > srcMat(numRows, std::vector<int>(numCols));
		std::vector<std::vector<int> > mat(numRows, std::vector<int>(numCols));
		if (choice != fileMenuChoice::test) {
			fillMatrix(mat, static_cast<int>(choice), fileName);
		}
		cout << "Input matrix: " << endl;
		getMatrix(mat);
		sortControl<quickSort>(mat, quickS);
		sortControl<bubbleSort>(mat, bubbleS);
		sortControl<selectionSort>(mat, selS);
		sortControl<shellSort>(mat, shellS);
		sortControl<insertionSort>(mat, insS);
		giveChart(quickS, bubbleS, selS, shellS, insS);
		saveToFile(mat, quickS, bubbleS, selS, shellS, insS);
	} while (true);
	return 0;
}