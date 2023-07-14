/* Citation and Sources...
Final Project Milestone 1
Module: Menu.h
Filename: Menu.cpp
Version 1.0
Author	Tanimul Islam
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/07  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef MENU_H
#define SDDS_DATE_H__
#include <iostream>
#include <iomanip>
#include <limits>
#include"Menu.h"
#include "Utils.h"
namespace sdds {


   //constructor, destructor
   MenuItem::MenuItem() {
      setEmpty();
   }
   MenuItem::MenuItem(const char* content) {
      if (content && content[0]) {
         menuContent = new char[strLen(content) + 1];
         strCpy(menuContent, content);
      }
      else {
         setEmpty();
      }
   }
   MenuItem::~MenuItem() {
      if (menuContent != nullptr) {
         delete menuContent;
         menuContent = nullptr;
      }
   }
   //type conversion overloading
   MenuItem::operator bool()const {
      bool isEmpty = false;
      if (menuContent != nullptr) {
         isEmpty = true;
      }
      return isEmpty;
   }
   MenuItem::operator const char* ()const {
      return menuContent;
   }
   //Setting the object to empty
   void MenuItem::setEmpty() {
      menuContent = nullptr;
   }
   //displaying the MenuItem
   std::ostream& MenuItem::display(std::ostream& os) {
      if (menuContent != nullptr) {
         os << menuContent;
      }
      return os;
   }


   //Constructors
   Menu::Menu() {
      itemCount = 0;
   }
   Menu::Menu(const char* title) : titleOfMenu(title) {};
   Menu::~Menu() {
      unsigned int i{};
      for (i = 0; i < MAX_MENU_ITEMS; i++) {
         delete items[i];
      }
      
   }
   //Display the Title of Menu
   std::ostream& Menu::displayTitle(std::ostream& os) {
      if (titleOfMenu) {
         titleOfMenu.display();
      }
      return os;
   }
   //Display the entire menu on ostream
   std::ostream& Menu::displayMenu(std::ostream& os) {
      unsigned int i{};
      if (titleOfMenu)
      {
         titleOfMenu.display();
         os << ":" << std::endl;
      }
      for (i = 0; i < itemCount; i++) {
         os.width(2);
         os.setf(std::ios::right);
         os.fill(' ');
         os << i + 1 << "- ";
         os.unsetf(std::ios::right);
         items[i]->display(os);
         os << std::endl;
      }
      os << " 0- Exit" << std::endl;
      os << "> ";
      return os;
   }
   //displays the Menu and gets the user selection
   unsigned int Menu::run() {
      unsigned int selection{};
      displayMenu();
      selection = getUserInput(0, itemCount);
      return selection;
   }
   //Overloading operators
   unsigned int Menu::operator~() {
      return run();
   }
   Menu& Menu::operator<<(const char* menuItemContent) {
      if (itemCount < MAX_MENU_ITEMS) {
         items[itemCount] = new MenuItem(menuItemContent);//dynamically create a MenuItem object 
         itemCount++;                                                //using the content received through the operator argument 
      }
      return *this;
   }
   //overloading type conversions
   Menu::operator int() {
      return itemCount;
   }
   Menu::operator unsigned int() {
      return itemCount;
   }
   Menu::operator bool() {
      if (itemCount > 0){
         return true;
      }
      return false;
   }
   //overloading the indexing operator
   const char* Menu::operator[](unsigned int index)const {
      unsigned int actualIndex{};
      if (index > itemCount) {
         actualIndex = index % itemCount;
         return items[actualIndex]->menuContent;
      }
      else {
         return items[index]->menuContent;
      }
   }
 
   // Overloading the insertion operator
   std::ostream& operator<<(std::ostream& os, Menu& menu) {
      return (menu.displayTitle(os));
   }

}
#endif // !MENU_H
