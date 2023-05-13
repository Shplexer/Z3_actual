#pragma once

#include <fstream>
#include <filesystem>
#include "classes.h"
#include "functions.h"

enum class errChoice { change = 1, keep };
enum class fileNameChoice { change = 1, exit };
enum class saveChoice { save = 1, discard };

//запрос сохранения данных в файл
void saveToFile(std::string saveFileName, std::vector<std::vector<int>>& srcMat, std::shared_ptr<quickSort> quickS, std::shared_ptr<bubbleSort> bubbleS, std::shared_ptr<selectionSort> selS, std::shared_ptr<shellSort> shellS, std::shared_ptr<insertionSort> insS);
std::string saveFileCheck(std::string saveFileName);						//проверка возможности сохранения в файл
std::string fileNameCheck(std::string inputName);							//проверка корректности имени файла
std::tuple<std::string, bool> openFile();									//проверка возможности открытия файла
void setMat(std::vector<std::vector<int>>& srcMat, std::string fileName);	//заполнение матрицы из файла 
std::tuple<int, int, bool> countMatSize(std::string fileName);				//расчет размера матрицы из файла