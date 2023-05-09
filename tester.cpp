#include "tester.h"
#include "functions.h"

void launchTest() {
	auto quickS = std::make_shared<quickSort>();
	auto bubbleS = std::make_shared<bubbleSort>();
	auto selS = std::make_shared<selectionSort>();
	auto shellS = std::make_shared<shellSort>();
	auto insS = std::make_shared<insertionSort>();

	std::vector<std::vector<int>> controlVec(TESTSIZE, std::vector<int>(TESTSIZE));
	std::vector<std::vector<int>> testVec(TESTSIZE, std::vector<int>(TESTSIZE));
	createTestVec(controlVec, testCreation::control);
	createTestVec(testVec, testCreation::test);

	std::vector<std::shared_ptr<ISort>>sortMethods{ bubbleS, quickS, selS, shellS, insS };
	for (int i = 0; i < sortMethods.size(); i++) {
		sortMethods[i]->setMat(testVec);
		sortMethods[i]->sort();
		cout << sortMethods[i]->getName() <<" : ";
		compareArrays(sortMethods[i]->getMat(), controlVec);
	}
}

void createTestVec(std::vector<std::vector<int>>& testVec, testCreation choice) {
	int numRows = static_cast<int>(testVec.size());
	int numCols = static_cast<int>(testVec[0].size());
	switch (choice)
	{
	case testCreation::test:
		for (auto i = 0, k = TESTSIZE * TESTSIZE; i < numRows; i++) {
			for (auto j = 0; j < numCols; j++, k--) {
				testVec[i][j] = k;
			}
		}
		break;
	case testCreation::control:
		for (int i = numRows - 1, k = 1; i >= 0; i--) {
			for (auto j = 0; j < numCols; j++, k++) {
				testVec[i][j] = k;
			}
		}
		break;
	}
	
}

void compareArrays(std::vector<std::vector<int>> testVec, std::vector<std::vector<int>> controlVec) {
	if (controlVec.size() == testVec.size()) {
		if (testVec == controlVec) {
			cout << "\033[36m" << "GOOD" << "\033[0m" << endl;
		}
		else{
			cout << "\033[31m" << "BAD" << "\033[0m" << endl;
			cout << "INPUT MATRIX" << endl;
			showMat(testVec);
			cout << "CONTROL MATRIX" << endl;
			showMat(controlVec);
		}
	}
	else {
		cout << "\033[31m" << "BAD" << "\033[0m" << endl;
		cout << "INPUT MATRIX" << endl;
		showMat(testVec);
		cout << "CONTROL MATRIX" << endl;
		showMat(controlVec);
	}

}