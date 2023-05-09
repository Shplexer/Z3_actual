#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

#define SHRT 5
#define MID 10
#define LNG 15

using std::cout;
using std::cin;
using std::endl;

class ISort {
public:
	ISort();

	virtual void sort() = 0;
	std::string getName();
	void showMat();
	int getSwaps();
	int getComps();
	std::vector<std::vector<int>> getMat();
	void setMat(std::vector<std::vector<int>>& srcMat);
	void saveMat(std::ofstream& stream);
	
	virtual ~ISort() = default;

protected:
	std::string name{};
	int numOfComps = 0;
	int numOfSwaps = 0;
	std::vector<std::vector<int> > mat;
};

class quickSort : public ISort {
public:
	quickSort() {
		name = "quick sort";
	}
	void sort();
	void sortRecursive(std::vector<int>& src, int start, int end);
	int sortDivide(std::vector<int>& src, int start, int end);
private:
};

class bubbleSort : public ISort {
public:
	bubbleSort() {
		name = "bubble sort";
	}
	void sort();
private:

};

class selectionSort : public ISort {
public:
	selectionSort() {
		name = "selection sort";
	}
	void sort();

private:

};

class shellSort : public ISort {
public:
	shellSort() {
		name = "shell sort";
	}
	void sort();
private:

};

class insertionSort : public ISort {
public:
	insertionSort() {
		name = "insertion sort";
	}
	void sort();
private:

};
