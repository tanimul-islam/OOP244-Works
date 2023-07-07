/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 06/02/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds {

    void CalorieList::emptyTitle() {
        foodItems = nullptr;
    }

    bool CalorieList::isValid()const {

        if (foodItems != nullptr) {
            for (int i = 0; i < listSize; ++i) {
                if (!foodItems[i].isValid()) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int CalorieList::totalCalories()const {
        int i = 0;
        int totalCalories = 0;

        for (i = 0; i < listSize; i++) {
            totalCalories += foodItems[i].getCalories();
        }
        return totalCalories;
    }

    void CalorieList::Title()const {

        cout << "+----------------------------------------------------+" << endl;

        if (isValid()) {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

    }

    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        

        if (isValid()) {
            cout << "|    Total Calories for today: ";
            cout.width(8);
            cout.setf(ios::right);
            cout << totalCalories();
            cout << " |            |" << endl;
          
        }
        else {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }



    void CalorieList::init(int size) {

        int i = 0;

        if (size <= 0) {
            emptyTitle();
            return;

        }
        else {
            listSize = size;
            foodAdded = 0;
            foodItems = new Food[listSize];

            for (i = 0; i < listSize; i++) {
                foodItems[i].setEmpty();
            }
        }

    }

    bool CalorieList::add(const char* foodName, double calories, int consumptionTime) {
        
        

        if (foodAdded < listSize) {
            
            foodItems[foodAdded].setFood(foodName, calories, consumptionTime);
            
            foodAdded++;
            return true;
        }
        return false;

    }

    void CalorieList::display()const {
        int i = 0;
        Title();
        for (i = 0; i < listSize; ++i) {
            foodItems[i].display();
        }
        footer();

    }

    void CalorieList::deallocate() {

        delete[] foodItems;
        foodItems = nullptr;

    }
}