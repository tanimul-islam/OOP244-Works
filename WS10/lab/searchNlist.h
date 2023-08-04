/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 08/03/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#include <iostream>
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "Collection.h"

using namespace std;

namespace sdds {
   /// <summary>
   /// Searches for a key value in an array of objects and adds all the matching elements found to any type of Collection.
   /// It requires the == operator to be overloaded.
   /// </summary>
   /// <typeparam name="S1">object type</typeparam>
   /// <typeparam name="S2">type of keyvalue to be searched</typeparam>
   /// <param name="myObj">a reference to a Collection of objects</param>
   /// <param name="array">a pointer to an array of object of type S1</param>
   /// <param name="noELemenets">Size of the array</param>
   /// <param name="keyValue">The key value with type S2</param>
   /// <returns></returns>
   template <typename S1, typename S2>
   bool search(Collection<S1>& myObj, S1* array, size_t noELemenets, const S2& keyValue) {
      bool matchFound = false;
      size_t i = 0;
      for (i = 0; i < noELemenets; i++) {
         if (array[i] == keyValue) {
            myObj.add(array[i]);
            matchFound = true;
         }
      }
      return matchFound;
   }

   /// <summary>
   /// Lists the elements of an array of objects of type T1.
   /// It requires the << operator to be overloaded.
   /// </summary>
   /// <typeparam name="T1">The type of objects stored in the array</typeparam>
   /// <param name="title">A pointer to a null-terminated string representing the title of the list</param>
   /// <param name="objects">A pointer to an array of objects of type T1.</param>
   /// <param name="size">The number of elements in the array.</param>
   template<typename T1>
   void listArrayElements(const char* title, const T1* objects, size_t size) {
      size_t i;
      cout << title << endl;
      for (i = 0; i < size; i++) {
         cout << (i + 1) << ": " << objects[i] << endl;
      }
   }
}
#endif // !SDDS_SEARCHNLIST_H_