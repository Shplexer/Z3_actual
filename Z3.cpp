#include "Z3.h"

int main() {
	do {
		int numRows = 0;
		int numCols = 0;
		bool exitFlag = true;
		auto quickS = std::make_shared<quickSort>();
		auto bubbleS = std::make_shared<bubbleSort>();
		auto selS = std::make_shared<selectionSort>();
		auto shellS = std::make_shared<shellSort>();
		auto insS = std::make_shared<insertionSort>();
		fileMenuChoice choice;
		giveGreeting();
		std::vector<std::shared_ptr<ISort>>sortMethods{ bubbleS, quickS, selS, shellS, insS };
		std::string fileName{};
		//giveMenu();
		//Manual
		do {
			exitFlag = true;
			cout << "===================================================================================================================" << endl;
			giveMainMenu();
			choice = static_cast<fileMenuChoice>(checkInt());
			switch (choice)
			{
			case fileMenuChoice::test:
				launchTest();
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
		std::vector<std::vector<int> > mat(numRows, std::vector<int>(numCols));
		if (choice != fileMenuChoice::test) {
			fillMatrix(mat, static_cast<int>(choice), fileName);
		}
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
		giveChart(quickS, bubbleS, selS, shellS, insS);
		saveToFile(mat, quickS, bubbleS, selS, shellS, insS);
	} while (true);
	return 0;
}