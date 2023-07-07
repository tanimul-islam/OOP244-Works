#pragma once
#include "Food.h"


namespace sdds {
	class CalorieList {
		Food* foodItems;
		int listSize;
		int foodAdded;
		void emptyTitle();
		bool isValid()const;
		int totalCalories()const;
		void Title()const;
		void footer()const;
	public:
		void init(int size);
		bool add(const char* foodName, double calories, int consumptionTime);
		void display()const;
		void deallocate();
	};

}
