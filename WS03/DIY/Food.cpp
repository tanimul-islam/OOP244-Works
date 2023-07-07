/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 06/02/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds {


	void Food::setFoodName(const char* name) {
		strnCpy(foodName, name, 30);

		foodName[30] = '\0';
	}

	void Food::setEmpty() {
		calories = 0;
		foodName[0] = '\0';
		consumptionTime = 0;
	}

	bool Food::isValid()const {
		if ((1 <= consumptionTime) && (consumptionTime <= 4) && (foodName[0] != '\0')) {
			return true;
		}
	
		return false;
		
		
	}

	void Food::setFood(const char* name, int calorieNumber, int timeOfConsumption) {

		if (name == nullptr || timeOfConsumption < 1 || timeOfConsumption > 4) {
			setEmpty();
		}
		else {
			setFoodName(name);
			calories = calorieNumber;
			consumptionTime = timeOfConsumption;
		}
		
	}


	int Food::getCalories() const {
		return calories;
	}

	const char* Food::mealTime  (int consumptionTime)const {

		if (isValid()) {
			switch (consumptionTime) {
			case 1:
				return "Breakfast";
				break;
			case 2:
				return "Lunch";
				break;
			case 3:
				return "Dinner";
				break;
			case 4:
				return "Snack";
				break;
			case 5:
				return "0";
			
			}
		}
		return "Invalid";
	}

	void Food::display()const {


		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left, ios::adjustfield);
			cout.fill('.');
			cout.width(30);
			cout << foodName;
			cout.unsetf(ios::left);


			cout << " | ";
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.fill(' ');
			cout.width(4);
			cout <<calories ;
			cout.unsetf(ios::right);


			cout << " | ";
			cout.setf(ios::left, ios::adjustfield);
			cout.width(10);
			cout << mealTime(consumptionTime);
			cout << " |"<<endl;

		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

}
