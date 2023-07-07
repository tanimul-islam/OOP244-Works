#pragma once

namespace sdds {

	class Food {
		char foodName[31];
		int calories;
		int consumptionTime;
		void setFoodName(const char* foodName);
		
	public:
		Food() {
			foodName[0] = '\0';
				calories = 0;
			consumptionTime = 0;
		}
		void setEmpty();
		bool isValid()const;
		void setFood(const char* name, int calorieNumber, int consumptionTime);
		
		int getCalories() const;
		int getConsumptionTime() const;
		const char* mealTime  (int consumptionTime)const;
		void display()const;
		
	};
	
}

