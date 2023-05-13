#include "interface.h"

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