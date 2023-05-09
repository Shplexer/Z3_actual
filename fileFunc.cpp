#include "fileFunc.h"

std::string openFile() {
	std::ifstream fileIn;
	bool exitFlag = false;
	bool returnExit = false;
	fileNameChoice choice;
	std::error_code ec{};
	cout << "Enter the name of a source file: ";
	std::string fileName = makeLineGood();
	do {
		exitFlag = false;
		fileName = fileNameCheck(fileName);
		fileIn.open(fileName);
		if (!std::filesystem::is_regular_file(fileName, ec) || !fileIn.is_open()) {
			cout << endl << "The name of the file you have entered does not exist." << endl
				<< "1.Change the name of the file" << endl
				<< "2.Exit" << endl;
			choice = static_cast<fileNameChoice>(checkInt());
			switch (choice)
			{
			case fileNameChoice::change:
				cout << "Enter the name of a source file: ";
				fileName = fileNameCheck(makeLineGood());
				break;
			case fileNameChoice::exit:
				cout << "Exiting..." << endl;
				returnExit = false;
				exitFlag = true;
				break;
			default:
				cout << "ERR. Wrong input, try again" << endl;
				break;
			}
		}
		else {
			cout << "Your file is open!" << endl;
			//cout << fileName;
			exitFlag = true;
			returnExit = true;
		}
	} while (!exitFlag);
	fileIn.close();
	return fileName;
}

std::tuple<int, int> countMatSize(std::string fileName) {
	std::ifstream fileStream;
	fileStream.open(fileName);
	std::vector<std::string> lines;
	std::string line;
	while (std::getline(fileStream, line)){
		if (line == "//")
			break;
		lines.push_back(line);
	}
	int numRows = static_cast<int>(lines.size());
	int i = 0;
	std::istringstream iss(lines[i]);
	int numCols = 0;
	std::string x;
	while (iss >> x) {
		numCols++;
	}
	fileStream.close();
	//cout << numRows << " " << numCols << endl;
	return std::tuple(numRows, numCols);
}

void setMat(std::vector<std::vector<int>>& srcMat, std::string fileName) {
	std::ifstream setFile;
	int numRows = static_cast<int>(srcMat.size());
	int numCols = static_cast<int>(srcMat[0].size());
	setFile.open(fileName);
	//int i = 0;
	while (true) {
		int num = 0;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				setFile >> num;
				//cout << "a[" << i + 1 << "][" << j + 1 << "]: " << num << endl;
				if (setFile.fail()) {
					bool exitFlag = true;
					//cout << endl << "ERR. Wrong input data for subject " << tempName << endl;
					cout << endl << "ERR. Wrong input data for element a[" << i + 1 << "][" << j + 1 << "]" << endl;
					cout << "Would you like to change the data?" << endl;
					cout << "1. Yes" << endl << "2. No (Will put 0 as the value)" << endl;
					do
					{
						errChoice choice = static_cast<errChoice>(checkInt());
						switch (choice)
						{
						case errChoice::change:
							do {
								cout << "Enter valid data: ";
								num = checkInt();
							} while (num < 0);
							break;
						case errChoice::keep:
							num = 0;
							break;
						default:
							cout << "ERR. Wrong input" << endl;
							exitFlag = false;
							break;
						}
						setFile.ignore(INT_MAX, ' ');
						setFile.clear();
					} while (!exitFlag && !setFile.fail());
					setFile.ignore(INT_MAX, ' ');
				}
				srcMat[i][j] = num;
			}
		}
		//showMat(srcMat);
		break;
	}
	setFile.close();
}


void saveToFile(std::vector<std::vector<int>>& srcMat, std::shared_ptr<quickSort> quickS, std::shared_ptr<bubbleSort> bubbleS, std::shared_ptr<selectionSort> selS, std::shared_ptr<shellSort> shellS, std::shared_ptr<insertionSort> insS) {
	bool exitFlag = true;
	do {
		cout << "Would you like to save the info?" << endl << "1.Yes" << endl << "2.No" << endl;
		saveChoice saveCh = static_cast<saveChoice>(checkInt());
		std::ofstream save;
		if (saveCh == saveChoice::save) {
			std::string saveFileName;
			saveFileName = saveFileCheck(saveFileName);
			save.open(saveFileName, std::ios::out);
			int numRows = static_cast<int>(srcMat.size());
			int numCols = static_cast<int>(srcMat[0].size());
			for (auto i = 0; i < numRows; i++) {
				for (auto j = 0; j < numCols; j++) {
					save << srcMat[i][j] << " ";
				}
				save << endl;
			}
			save << "//" << endl;
			save << "===================================================================================================================" << endl;
			save << "Comparison chart" << endl;
			save << "===================================================================================================================" << endl;
			save
				<< std::left
				<< std::setw(LNG) << "#"
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << "Bubble"
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << "Selection"
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << "Inserton"
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << "Shell"
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << "Quick"
				<< std::setw(SHRT) << "||"
				<< endl;
			save << "===================================================================================================================" << endl;
			save
				<< std::left
				<< std::setw(LNG) << "Comparisons: "
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << bubbleS->getComps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << selS->getComps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << insS->getComps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << shellS->getComps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << quickS->getComps()
				<< std::setw(SHRT) << "||"
				<< endl;
			save
				<< std::left
				<< std::setw(LNG) << "Swaps: "
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << bubbleS->getSwaps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << selS->getSwaps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << insS->getSwaps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << shellS->getSwaps()
				<< std::setw(SHRT) << "||"
				<< std::setw(MID) << quickS->getSwaps()
				<< std::setw(SHRT) << "||"
				<< std::right << endl;
			save << "===================================================================================================================" << endl;
			save << "Bubble sort" << endl;
			bubbleS->saveMat(save);
			save << "Selection sort" << endl;
			selS->saveMat(save);
			save << "Inserton sort" << endl;
			insS->saveMat(save);
			save << "Shell sort" << endl;
			shellS->saveMat(save);
			save << "Quick sort" << endl;
			quickS->saveMat(save);
			save.close();
		}
		else if (saveCh != saveChoice::discard && saveCh != saveChoice::save) {
			cout << "ERR. Wrong input." << endl;
			saveCh = static_cast<saveChoice>(checkInt());
			if (saveCh == saveChoice::save || saveCh == saveChoice::discard)
				exitFlag = true;
		}
	} while (!exitFlag); ////////////////////STOPPED HERE
}

std::string saveFileCheck(std::string saveFileName) {
	std::ifstream checkStream;
	bool exitFlag;
	bool exitAllFlag;
	do {
		exitAllFlag = false;
		checkStream.open(saveFileName);
		std::error_code ec{};
		if (!checkStream.is_open()) {
			cout << "Please enter a path to the file you wish to save your project to: ";
			saveFileName = fileNameCheck(makeLineGood());
			//if (!std::filesystem::is_regular_file(saveFileName, ec)) {
			//	cout << "Invalid data." << endl;
			//	continue;
			//}
		}
		else {
			cout << "The name of an open file: " << saveFileName << endl <<
				"Whould you like to make a new one or save into this one?" << endl <<
				"1. Save to another file" << endl <<
				"2. Save here" << endl;
			do {
				exitFlag = true;
				errChoice choice = static_cast<errChoice>(checkInt());
				switch (choice)
				{
				case errChoice::change:
					cout << "Enter a path to the file: ";
					//saveFileName = makeLineGood();
					saveFileName = fileNameCheck(makeLineGood());
					break;
				case errChoice::keep:
					exitAllFlag = true;
					break;
				default:
					exitFlag = false;
					break;
				}
			} while (!exitFlag);
		}
		checkStream.close();
		checkStream.open(saveFileName);
		if (!checkStream.is_open() || exitAllFlag)
			break;
		checkStream.close();
	} while (true);
	return saveFileName;
}

std::string fileNameCheck(std::string inputName) {
	std::string temp;
	const std::string errName = "<>:\"/\\|?*";
	const std::vector<std::string> errName2{ "CON", "PRN", "AUX", "NUL",
  "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9",
  "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6", "LPT7", "LPT8", "LPT9" };
	bool exitFlag = false;
	do {
		exitFlag = true;
		for (int i = 0; i < inputName.size(); i++) {
			for (int j = 0, k = 0; j < std::max(errName.size(), errName2.size()); j++, k++) {
				//cout << inputName[i] << " == " << errName[k] << " | " << inputName << " == " << errName2[j] << endl;
				if (inputName[i] == errName[k] || inputName == errName2[j]) {
					cout << "ERR. File name contains illegal characters. Try again." << endl;
					inputName = makeLineGood();
					exitFlag = false;
					break;
				}
				if (k >= errName.size() - 1)
					k = 0;
			}
			if (!exitFlag)
				break;
		}
	} while (!exitFlag);
	for (auto i = inputName.size() - 4; i < inputName.size(); i++) {
		temp = temp + inputName[i];
	}
	if (temp != ".txt") {
		inputName = inputName + ".txt";
	}

	return inputName;
}