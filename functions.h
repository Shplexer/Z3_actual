#pragma once

#include <time.h>
#include "classes.h"
#include "tester.h"
#include "fileFunc.h"


enum class fileMenuChoice { test = 1, file, empty, random, exit };

void fillMatrix(std::vector<std::vector<int> >& srcMat, int operationInt, std::string fileName);	//заполение матрицы
std::string stringInput();							//ввод строки вручную с заменой пробелов на "_"
std::string stringOutput(std::string input);		//при выводе строк происходит проверка на "_" и замена на пробел
int checkInputInt();								//проверка корректности введенных данных типа "int"
std::tuple<std::vector<std::vector<int> >, std::string> mainMenuControl();	//управление внутри главного меню
void sortAll(std::vector<std::shared_ptr<ISort>> sortMethods, std::vector<std::vector<int>> mat);	//сортировка всеми методами

