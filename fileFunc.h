#pragma once

#include <fstream>
#include <filesystem>
#include "classes.h"
#include "functions.h"

enum class errChoice { change = 1, keep };
enum class fileNameChoice { change = 1, exit };
enum class saveChoice { save = 1, discard };
void saveToFile(std::vector<std::vector<int>>& srcMat, std::shared_ptr<quickSort> quickS, std::shared_ptr<bubbleSort> bubbleS, std::shared_ptr<selectionSort> selS, std::shared_ptr<shellSort> shellS, std::shared_ptr<insertionSort> insS);
std::string saveFileCheck(std::string saveFileName);
std::string fileNameCheck(std::string inputName);
std::string openFile();
void setMat(std::vector<std::vector<int>>& srcMat, std::string fileName);
std::tuple<int, int> countMatSize(std::string fileName);