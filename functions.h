#pragma once

#include <time.h>
#include "Z3.h"
#include "classes.h"

#define CLASSWORDLEN 6

//template <typename T>
//void sortControl(std::vector<std::vector<int>> srcMat, T& sortMethod) {
//	cout << "===========" << endl;
//	std::string methName = typeid(T).name();
//	cout << methName.erase(NULL, CLASSWORDLEN) << ":" << endl;
//	std::vector<std::vector<int>> mat = srcMat;
//	for (auto i = 0; i < mat.size(); i++) {
//		sortMethod.sort(mat[i]);
//	}
//	sortMethod.setMat(mat);
//	sortMethod.showMat();
//	//cout << "Swaps: " << sortMethod.getSwaps() << " Comps: " << sortMethod.getComps() << endl;
//}

//void giveChart(quickSort, bubbleSort, selectionSort, shellSort, insertionSort);
void giveChart(std::shared_ptr<quickSort>, std::shared_ptr<bubbleSort>, std::shared_ptr<selectionSort>, std::shared_ptr<shellSort>, std::shared_ptr<insertionSort>);
void giveGreeting();
void giveMainMenu();
void fillMatrix(std::vector<std::vector<int> >& srcMat, int operationInt, std::string fileName);
void showMat(std::vector<std::vector<int> >& srcMat);
//void saveToFile();
std::string makeLineGood();
std::string getGoodLine(std::string input);
int checkInt();
bool checkBool();


