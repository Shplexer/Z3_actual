#include "classes.h"
ISort::ISort(){

}

ISort::~ISort(){

}

void ISort::setMat(std::vector<std::vector<int>>& srcMat) {
	mat = srcMat;
}

void ISort::showMat() {
	for (auto i = 0; i < mat.size(); i++) {
		for (auto j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int ISort::getSwaps() {
	return numOfSwaps;
}
int ISort::getComps() {
	return numOfComps;
}

void ISort::saveMat(std::ofstream& stream) {
	for (auto i = 0; i < mat.size(); i++) {
		for (auto j = 0; j < mat[i].size(); j++) {
			stream << mat[i][j] << " ";
		}
		stream << endl;
	}
}
void quickSort::sort(std::vector<int>& src) {
	//cout << "quickSort" << endl;
	sortRecursive(src, 0, static_cast<int>(src.size()) - 1);
}

void quickSort::sortRecursive(std::vector<int>& src, int start, int end) {
	if (start < end) {
		//numOfComps++;
		int pivot = sortDivide(src, start, end);
		sortRecursive(src, start, (pivot - 1));
		sortRecursive(src, (pivot + 1), end);
	}
}

int quickSort::sortDivide(std::vector<int>& src, int start, int end) {
	int pivot = src[end];
	int index = start;
	for (int i = start; i < end; i++) {
		if (src[i] < pivot) {
			std::swap(src[i], src[index]);
			//int temp = src[i];
			//src[i] = src[index];
			//src[index] = temp;
			index++;
			numOfSwaps++;
		}
		numOfComps++;
	}
	std::swap(src[index], src[end]);
	//numOfSwaps++;
	return index;
}

void bubbleSort::sort(std::vector<int>& src) {

	for (auto i = 0; i < src.size(); ++i) {
		for (auto j = 0; j < src.size() - 1; ++j) {
			numOfComps++;
			//for (int k = 0; k < src.size(); k++) {
			//	cout << src[k] << " ";
			//}
			//cout << endl;
			//cout << src[j] << " " << src[j + 1];
			if (src[j] > src[j + 1]) {
				numOfSwaps++;
				std::swap(src[j], src[j + 1]);
				//cout << " swap ";
			}
			//cout << endl;
		}
	}
}

void selectionSort::sort(std::vector<int>& src) {
	//cout << "selectionSort" << endl;
	for (auto i = 0; i < src.size() - 1; i++) {
		int minInd = i;
		for (auto j = i + 1; j < src.size(); j++) {
			// Select the minimum element in each loop.
			numOfComps++;
			if (src[j] < src[minInd])
			{
				minInd = j;
			}
		}
		// put min at the correct position
		std::swap(src[minInd], src[i]);
		numOfSwaps++;
	}
}

void shellSort::sort(std::vector<int>& src) {
	//cout << "shellSort" << endl;
	for (int gap = static_cast<int>(src.size()) / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < src.size(); i++) {
			int temp = src[i];
			int j;
			for (j = i; j >= gap && src[j - gap] > temp; j -= gap) {
				src[j] = src[j - gap];
				numOfSwaps++;
			}
			src[j] = temp;
			numOfComps++;
		}
	}
}

void insertionSort::sort(std::vector<int>& src) {
	int i;
	int key;
	int j;
	for (i = 1; i < static_cast<int>(src.size()); i++)
	{
		key = src[i];
		j = i - 1;
		while (j >= 0 && src[j] > key)
		{
			src[j + 1] = src[j];
			j = j - 1;
			numOfSwaps++;
		}
		src[j + 1] = key;
		numOfComps++;
	}
}