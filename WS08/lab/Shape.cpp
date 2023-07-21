/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include "Shape.h"
namespace sdds
{
   std::ostream& operator<<(std::ostream& os, const Shape& source)
   {
      source.draw(os);
      return os;
   }
   std::istream& operator>>(std::istream& is, Shape& source)
   {
      source.getSpecs(is);
      return is;
   }
}