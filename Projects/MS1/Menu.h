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
namespace sdds {
   const unsigned MAX_MENU_ITEMS = 20;

   class MenuItem {
      char* menuContent{}; //holds Cstring of char dynamically
      //constructor, destructor
      MenuItem();
      MenuItem(const char* content);
      virtual ~MenuItem();
      //Copy constructor and Copy assignment are deleted
      MenuItem(const MenuItem& source) = delete;
      void operator=(const MenuItem& source) = delete;
      //type conversion overloading
      operator bool()const;
      operator const char* ()const;
      //Setting the object to empty
      void setEmpty();
      //displaying the MenuItem
      std::ostream& display(std::ostream& os = std::cout);
      friend class Menu;
   };

   class Menu {
      //attributes
      MenuItem titleOfMenu;
      MenuItem* items[MAX_MENU_ITEMS]{};
      unsigned int itemCount{ 0 };
   public:
      //Constructors
      Menu();
      Menu(const char* title);
      virtual ~Menu();
      Menu(const Menu& source) = delete;
      void operator=(const Menu& source) = delete;
      //Display the Title of Menu
      std::ostream& displayTitle(std::ostream& os);
      //Display the entire menu on ostream
      std::ostream& displayMenu(std::ostream& os = std::cout);
      //
      unsigned run();
      //Overloading operators
      unsigned operator~();
      Menu& operator<<(const char* menuitemConent);
      //overloading type conversions
      operator int();
      operator unsigned int();
      operator bool();
      //overloading the indexing operator
      const char* operator[](unsigned int index)const;
   };
   // Overloading the insertion operator
   std::ostream& operator<<(std::ostream& os, Menu& menu);
   
}
#endif // !MENU_H
