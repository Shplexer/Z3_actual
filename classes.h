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

	//virtual void sort();
	virtual void showMat();
	int getSwaps();
	int getComps();

	void setMat(std::vector<std::vector<int>>& srcMat);
	void saveMat(std::ofstream& stream);
	
	virtual ~ISort();

protected:
	int numOfComps = 0;
	int numOfSwaps = 0;
	std::vector<std::vector<int> > mat;
};

class quickSort : public ISort {
public:
	void sort(std::vector<int>& src);
	void sortRecursive(std::vector<int>& src, int start, int end);
	int sortDivide(std::vector<int>& src, int start, int end);
private:

};

class bubbleSort : public ISort {
public:
	void sort(std::vector<int>& src);
private:

};

class selectionSort : public ISort {
public:
	void sort(std::vector<int>& src);
private:

};

class shellSort : public ISort {
public:
	void sort(std::vector<int>& src);
private:

};

class insertionSort : public ISort {
public:
	void sort(std::vector<int>& src);
private:
		
};
