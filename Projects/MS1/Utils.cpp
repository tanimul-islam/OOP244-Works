/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date	2023/07/12
// Author	Tanimul Islam Dihan
// Description
//Using this file to include to all extra functionality I need to complete the project.
//such as cstring lib.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"

namespace sdds {
   void strCpy(char* des, const char* src) {

      while (*src != '\0') {
         *des = *src;
         des++;
         src++;
      }
      *des = '\0';

   }

   void strnCpy(char* des, const char* src, int len) {

      int i = 0;
      while (*src != '\0' && i < len) {
         *des = *src;
         des++;
         src++;
         i++;
      }
      if (i < len) {
         *des = '\0'; // Null-terminate the destination string
      }
   }

   int strCmp(const char* s1, const char* s2) {
      while (*s1 && (*s1 == *s2)) {
         s1++;
         s2++;
      }
      return *s1 - *s2;
   }


   int strnCmp(const char* s1, const char* s2, int len) {
      int i = 0;
      while (i < len && *s1 && (*s1 == *s2)) {
         s1++;
         s2++;
         i++;
      }
      if (i == len) {
         return 0;
      }
      return *s1 - *s2;
   }

   int strLen(const char* s) {
      int length = 0;
      while (*s != '\0') {
         length++;
         s++;
      }
      return length;
   }

   const char* strStr(const char* str1, const char* str2) {
      if (*str2 == '\0') {
         return str1; //empty str2
      }

      while (*str1 != '\0') {
         const char* p1 = str1;
         const char* p2 = str2;

         while (*p1 == *p2 && *p1 != '\0') {
            p1++;
            p2++;
         }
         if (*p2 == '\0') {
            return str1;
         }

         str1++;

      }

      return nullptr;
   }

   void strCat(char* des, const char* src) {
      while (*des != '\0') {
         des++;
      }

      while (*src != '\0') {
         *des = *src;
         des++;
         src++;
      }

      *des = '\0'; // Add null-terminating character at the end
   }

   //Function for getting the user input for menu
   int getUserInput(int lowerLimit, int upperLimit) {
      int input;
      bool validInput = false;

      while (!validInput) {
         std::cout << "Enter your selection: ";
         if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Selection, try again: " << std::endl;
         }
         else if (input < lowerLimit || input > upperLimit){
            std::cout << "Invalid Selection, try again: " << std::endl;
         }
         else {
            validInput = true;
         }
      }

      return input;
   }

}