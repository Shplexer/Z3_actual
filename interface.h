#pragma once

#include <iostream>
#include "classes.h"

void giveGreeting();	//����� ����������

//����� ������� ��������� � ������������
void giveChart(std::shared_ptr<quickSort>, std::shared_ptr<bubbleSort>, std::shared_ptr<selectionSort>, std::shared_ptr<shellSort>, std::shared_ptr<insertionSort>);
void giveMainMenu(); //����� ����� �������� ����
void showMat(std::vector<std::vector<int> >& srcMat); //����� �������
