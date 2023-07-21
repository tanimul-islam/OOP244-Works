/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include "Line.h"
using namespace std;
namespace sdds {
   Line::Line()
   {
      m_length = 0;
   }

   Line::Line(const char* value, unsigned int length): LblShape(value)
   {
      m_length = length;
   }

   void Line::getSpecs(std::istream& is)
   {
      unsigned int length_;
      bool flag = false;
      do {
         LblShape::getSpecs(is); //read label using base class method
         is >> length_;

         if (!is) {
            is.clear();
            is.ignore(35468, '\n');
         }
         else {
            is.ignore();
            m_length = length_;
            flag = true;
         }
      } while (flag == false);
   }

   void Line::draw(std::ostream& os) const
   {
      if (m_length > 0 && LblShape::label()){
         os << LblShape::label() << endl;
         os.width(m_length);
         os.fill('=');
         os << '=';
      }
   }
}