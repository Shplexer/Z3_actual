#pragma once

#include <fstream>
#include <filesystem>
#include "classes.h"
#include "functions.h"

enum class errChoice { change = 1, keep };
enum class fileNameChoice { change = 1, exit };

void saveToFile(std::vector<std::vector<int> >& srcMat, quickSort, bubbleSort, selectionSort, shellSort, insertionSort);
std::string saveFileCheck(std::string saveFileName);
std::string fileNameCheck(std::string inputName);
std::string openFile();
void setMat(std::vector<std::vector<int>>& srcMat, std::string fileName);
std::tuple<int, int> countMatSize(std::string fileName);