/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include "Rectangle.h"
#include "Utils.h"

using namespace std;
namespace sdds {
   Rectangle::Rectangle()
   {
      m_height = 0;
      m_width = 0;
   }
   Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
   {
      int tempLen = strLen(LblShape::label()) + 2;

      if (height < 3 && width < tempLen) {
         // Set to an empty state
         m_height = 0;
         m_width = 0;
      }
      else {
         m_height = height;
         m_width = width;
      }
   }
   void Rectangle::getSpecs(istream& is)
   {
      int getHeight;
      int getWidth;
      char comma;
      bool flag = false;

      do {
         LblShape::getSpecs(is);

         is >> getWidth >> comma >> getHeight;
         if (!is) {
            is.clear();
            is.ignore(35747, '\n');
         }
         else {
            is.ignore();
            m_width = getWidth;
            m_height = getHeight;
            flag = true;
         }

      } while (!flag);
   }

   void Rectangle::draw(ostream& os) const
   {
      unsigned int i = 0;
      if (m_height > 0 && m_width > 0) {
         // First line
         os << '+';
         os.width(m_width - 2);
         os.fill('-');
         os << '-' << '+' << endl;

         // Second line
         os << '|';
         os.width(m_width - 2);
         os.fill(' ');
         os << left << LblShape::label() << '|' << endl;

         // Next (m_height - 3) lines
         for (i = 0; i < (m_height - 3); i++) {
            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << ' ' << '|' << endl;
         }

         // Last line
         os << '+';
         os.width(m_width - 2);
         os.fill('-');
         os << '-' << '+';
      }
   }
}