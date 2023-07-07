/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 6/10/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include "Label.h"
#include "cstring.h" //using strCpy, strLen

using namespace std;

namespace sdds {

	Label::Label() {
		strCpy(symbol, defSymbol);
		frameLine = nullptr;
	}

	Label::Label(const char* frameArg) {
		
		strCpy(symbol, frameArg);
		frameLine = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		int length = strLen(content);

		strCpy(symbol, frameArg);
		
		if (length <= MAX_CHARACHTERS+1) {
			frameLine = new char[length + 1];
			strCpy(frameLine, content);
		}

	}

	Label::~Label(){
		delete[] frameLine;
		frameLine = nullptr;
	}

	void Label::readLabel() {
		char content[MAX_CHARACHTERS + 1];

		if (frameLine != nullptr) {
			delete[] frameLine;
			frameLine = nullptr;
		}

		cout << "> ";
		cin.get(content, MAX_CHARACHTERS+1);
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Cleaning the Buffer

		frameLine = new char[strLen(content) + 1];
		strCpy(frameLine, content);

	}


	std::ostream& Label::printLabel()const {

		if (frameLine != nullptr) {
			int middleSpace = strLen(frameLine);

			cout << symbol[0];
			cout.fill(symbol[1]);
			cout.width(middleSpace + 3);
			cout << symbol[2] << endl;

			cout << symbol[7];
			cout.fill(' ');
			cout.width(middleSpace + 3);
			cout << symbol[3] << endl;

			cout << symbol[7];
			cout.width(middleSpace + 1);
			cout << frameLine << " ";
			cout << symbol[3] << endl;

			cout << symbol[7];
			cout.fill(' ');
			cout.width(middleSpace + 3);
			cout << symbol[3] << endl;

			cout << symbol[6];
			cout.fill(symbol[5]);
			cout.width(middleSpace + 3);
			cout << symbol[4];
		}
		return cout;
	}
}

