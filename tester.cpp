//#include "tester.h"
//
//void launchTest() {
//	std::vector<std::vector<int>> controlVec(TESTSIZE, std::vector<int>(TESTSIZE));
//	std::vector<std::vector<int>> testVec(TESTSIZE, std::vector<int>(TESTSIZE));
//	createTestVec(controlVec, testCreation::control);
//	createTestVec(testVec, testCreation::test);
//	cout << "ADDING FUNCTION: ";
//	compareArrays(testVec, controlVec);
//	controlVec.clear();
//	testVec.clear();
//}
//
//void createTestVec(std::vector<std::vector<int>>& testVec, testCreation choice) {
//	int numRows = static_cast<int>(testVec.size());
//	int numCols = static_cast<int>(testVec[0].size());
//	switch (choice)
//	{
//	case testCreation::test:
//		for (auto i = 0; i < numRows; i++) {
//			for (auto j = 0, k = TESTSIZE*TESTSIZE; j < numCols; j++, k--) {
//				testVec[i][j] = k;
//			}
//			cout << endl;
//		}
//		break;
//	case testCreation::control:
//
//		break;
//	}
//	
//}
//
//void compareArrays(std::vector<std::vector<int>>& testVec, std::vector<std::vector<int>>& controlVec) {
//	if (controlVec.size() == testVec.size()) {
//		for (auto i = 0; i < std::max(testVec.size(), controlVec.size()); i++) {
//			std::string typeN = testVec[i].type().name();
//			if (typeN == "class carnivores") {
//				carnivores tempTest = std::any_cast<carnivores>(testVec[i]);
//				carnivores tempControl = std::any_cast<carnivores>(controlVec[i]);
//				if (tempTest.getName() == tempControl.getName() &&
//					tempTest.getNutrition() == tempControl.getNutrition() &&
//					tempTest.getEnv() == tempControl.getEnv() &&
//					tempTest.getWeight() == tempControl.getWeight() &&
//					tempTest.getAttack() == tempControl.getAttack()) {
//					if (i == controlVec.size() - 1)
//						std::cout << "\033[36m" << "GOOD" << "\033[0m" << std::endl;
//				}
//				else {
//					std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
//					std::cout << "Input array: " << std::endl;
//					printAll(testVec);
//					std::cout << "Control array: " << std::endl;
//					printAll(controlVec);
//					break;
//				}
//			}
//			else {
//				mammals tempTest = std::any_cast<mammals> (testVec[i]);
//				mammals tempControl = std::any_cast<mammals>(controlVec[i]);
//				if (tempTest.getName() == tempControl.getName() &&
//					tempTest.getNutrition() == tempControl.getNutrition() &&
//					tempTest.getEnv() == tempControl.getEnv() &&
//					tempTest.getWeight() == tempControl.getWeight()) {
//					if (i == std::max(testVec.size(), controlVec.size()) - 1)
//						std::cout << "\033[36m" << "GOOD" << "\033[0m" << std::endl;
//				}
//				else {
//					std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
//					std::cout << "Input array: " << std::endl;
//					printAll(testVec);
//					std::cout << "Control array: " << std::endl;
//					printAll(controlVec);
//					break;
//				}
//			}
//		}
//	}
//	else {
//		std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
//		std::cout << "Input array: " << std::endl;
//		printAll(testVec);
//		std::cout << "Control array: " << std::endl;
//		printAll(controlVec);
//	}
//
//}