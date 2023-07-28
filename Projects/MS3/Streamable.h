/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Tanimul Islam
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds {
   class Streamable {
   public:
      //Functions overriding this function will write into an ostream object.
      virtual std::ostream& write(std::ostream& os = std::cout)const = 0;

      //Functions overriding this function will read from an istream object.
      virtual std::istream& read(std::istream& is = std::cin) = 0;

      //Functions overriding this function will determine if the incoming ios object is a console IO object or not.
      virtual bool conIO(std::ios& IOobject)const = 0;

      //this method will return if the Streamable object is in a valid state or not.
      virtual operator bool()const = 0;

      //destructor
      virtual ~Streamable();

   };
   //Overloading Insertion & Insertion operator to write & read from ostream & istream object.
   std::ostream& operator<<(std::ostream& os, const Streamable& source);
   std::istream& operator>>(std::istream& is, Streamable& source);
}
#endif // !SDDS_STREAMABLE_H
