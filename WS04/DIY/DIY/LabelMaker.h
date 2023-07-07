#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

using namespace std;

namespace sdds {
	class LabelMaker {
		Label* labelArray;
		int totalLabels;

	public:
		LabelMaker(int noOfLabels);
		//creates a dynamic array of Labels to the size of noOfLabels

		void readLabels();
		//Gets the contents of the Labels as demonstrated in the Execution sample

		void printLabels();
		//Prints the Labels as demonstrated in the Execution sample

		~LabelMaker();
	};
}


#endif // !1


