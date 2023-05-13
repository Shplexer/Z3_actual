#pragma once

#include <time.h>
#include "classes.h"
#include "tester.h"
#include "fileFunc.h"


enum class fileMenuChoice { test = 1, file, empty, random, exit };

void fillMatrix(std::vector<std::vector<int> >& srcMat, int operationInt, std::string fileName);	//��������� �������
std::string stringInput();							//���� ������ ������� � ������� �������� �� "_"
std::string stringOutput(std::string input);		//��� ������ ����� ���������� �������� �� "_" � ������ �� ������
int checkInputInt();								//�������� ������������ ��������� ������ ���� "int"
std::tuple<std::vector<std::vector<int> >, std::string> mainMenuControl();	//���������� ������ �������� ����
void sortAll(std::vector<std::shared_ptr<ISort>> sortMethods, std::vector<std::vector<int>> mat);	//���������� ����� ��������

