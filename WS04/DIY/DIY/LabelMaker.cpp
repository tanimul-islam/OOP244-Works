/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 6/10/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include"cstring.h"
#include"LabelMaker.h"

using namespace std;

namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {

		if (noOfLabels > 0) {
			totalLabels = noOfLabels;
			labelArray = new Label[noOfLabels];
		}
		else {
			cout << "Invalid Input!Muste be greater then 0" << endl;
			noOfLabels = 0;
		}
	}

	void LabelMaker::readLabels() {
		if (totalLabels > 0) {
			cout << "Enter " << totalLabels << " labels:" << endl;

			for (int i = 0; i < totalLabels; i++) {
				cout << "Enter label number " << i + 1 << endl;
				labelArray[i].readLabel();
			}
		}
	}


	void LabelMaker::printLabels() {
		int i = 0;
		for (i = 0; i < totalLabels; i++) {
			labelArray[i].printLabel();
			cout << endl;
		}
	}


	LabelMaker::~LabelMaker() {
		delete[] labelArray;
		labelArray = nullptr;
	}
}