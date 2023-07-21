/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line : public LblShape {
      unsigned int m_length{};
   public:
      Line();
      Line(const char* value, unsigned int length);
      virtual ~Line() {};
      void  getSpecs(std::istream& is);
      void draw(std::ostream& os)const;
   };
}
#endif // !LINE_H
