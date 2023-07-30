/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Tanimul Islam
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include"Streamable.h"
using namespace std;
namespace sdds {
   //empty virtual destructor
   Streamable::~Streamable() {};

   ostream& operator<<(ostream& os, const Streamable& obj) {
      if (obj) {
         obj.write(os);
      }
      return os;
   }
   istream& operator>>(istream& is, Streamable& obj) {
      return (obj.read(is));
   }
}