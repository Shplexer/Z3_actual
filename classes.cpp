#include "classes.h"

ISort::ISort(){
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

std::vector<std::vector<int>> ISort::getMat() {
	return mat;
}

int ISort::getSwaps() {
	return numOfSwaps;
}

int ISort::getComps() {
	return numOfComps;
}

std::string ISort::getName() {
	return name;
}

void ISort::saveMat(std::ofstream& stream) {
	for (auto i = 0; i < mat.size(); i++) {
		for (auto j = 0; j < mat[i].size(); j++) {
			stream << mat[i][j] << " ";
		}
		stream << endl;
	}
}

void quickSort::sort() {
	//cout << "quickSort" << endl;
	for(int i = 0; i < mat.size(); i++){
	sortRecursive(mat[i], 0, static_cast<int>(mat[i].size()) - 1);
	}
}

void quickSort::sortRecursive(std::vector<int>& src, int start, int end) {
	if (start >= end) {
		return;
	}
	else{
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
			if(src[i] != src[index]){
				numOfSwaps++;
				std::swap(src[i], src[index]);
			}
			//int temp = src[i];
			//src[i] = src[index];
			//src[index] = temp;
			index++;
		}

		numOfComps++;
	}
	if (src[index] != src[end]) {
		std::swap(src[index], src[end]);
		numOfSwaps++;
	}
	return index;
}

void bubbleSort::sort() {
	//cout << "bubble" << endl;
	for (int k = 0; k < mat.size(); k++) {
		std::vector<int> temp = mat[k];
		for (auto i = 0; i < temp.size(); ++i) {
			for (auto j = 0; j < temp.size() - 1; ++j) {
				numOfComps++;
				//for (int k = 0; k < src.size(); k++) {
				//	cout << src[k] << " ";
				//}
				//cout << endl;
				//cout << src[j] << " " << src[j + 1];
				if (temp[j] > temp[j + 1]) {
					numOfSwaps++;
					std::swap(temp[j], temp[j + 1]);
					//cout << " swap ";
				}
				//cout << endl;
			}
		}
		mat[k] = temp;
	}
}

void selectionSort::sort() {
	//cout << "selectionSort" << endl;
	for (int k = 0; k < mat.size(); k++) {
		std::vector<int> temp = mat[k];
		for (auto i = 0; i < temp.size() - 1; i++) {
			int minInd = i;
			for (auto j = i + 1; j < temp.size(); j++) {
				// Select the minimum element in each loop.
				numOfComps++;
				if (temp[j] < temp[minInd])
				{
					minInd = j;
				}
			}
			// put min at the correct position
			if (temp[minInd] != temp[i]) {
				std::swap(temp[minInd], temp[i]);
				numOfSwaps++;
			}
		}
		if (mat[k] != temp) {
			mat[k] = temp;
			numOfSwaps++;
		}
	}
}

void shellSort::sort() {
	//cout << "shellSort" << endl;
	for (int k = 0; k < mat.size(); k++) {
		std::vector<int>tempVec = mat[k];
		int i = 0;
		for (int gap = static_cast<int>(tempVec.size()) / 2; gap > 0; gap /= 2) {
			for (i = gap; i < tempVec.size(); i++) {
				int temp = tempVec[i];
				int j;
				for (j = i; j >= gap && tempVec[j - gap] > temp; j -= gap) {
					tempVec[j] = tempVec[j - gap];
					numOfSwaps++;
				}
				tempVec[j] = temp;
				numOfComps++;
			}
		}
		mat[k] = tempVec;
	}
}

void insertionSort::sort() {
	//cout << "insertion sort" << endl;
	for (int k = 0; k < mat.size(); k++) {
		std::vector<int> temp = mat[k];
		for (int i = 1; i < static_cast<int>(temp.size()); i++)
		{
			int key = temp[i];
			int j = i - 1;
			while (j >= 0 && temp[j] > key)
			{
				temp[j + 1] = temp[j];
				j = j - 1;
				numOfSwaps++;
			}
			temp[j + 1] = key;
			numOfComps++;
		}
		mat[k] = temp;
	}
}