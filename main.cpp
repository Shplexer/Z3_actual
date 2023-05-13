#include "functions.h"
#include "interface.h"
#include "fileFunc.h"

int main() {
	giveGreeting();
	do {
		auto quickS = std::make_shared<quickSort>();
		auto bubbleS = std::make_shared<bubbleSort>();
		auto selS = std::make_shared<selectionSort>();
		auto shellS = std::make_shared<shellSort>();
		auto insS = std::make_shared<insertionSort>();

		std::vector<std::shared_ptr<ISort>>sortMethods{ bubbleS, quickS, selS, shellS, insS };
		std::vector<std::vector<int> > mat;
		std::string fileName{};
		std::tie(mat, fileName) = mainMenuControl();
		sortAll(sortMethods, mat);
		
		giveChart(quickS, bubbleS, selS, shellS, insS);
		saveToFile(fileName, mat, quickS, bubbleS, selS, shellS, insS);
	} while (true);
	return 0;
}