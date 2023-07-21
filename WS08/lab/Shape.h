/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds {
   class Shape
   {
   public:
      virtual void draw(std::ostream& os)const = 0;
      virtual void getSpecs(std::istream& is) = 0;
      virtual ~Shape() {};
   };
   std::ostream& operator<<(std::ostream& os, const Shape& source);
   std::istream& operator>>(std::istream& is, Shape& source);
}
#endif // !SDDS_SHAPE_H_
