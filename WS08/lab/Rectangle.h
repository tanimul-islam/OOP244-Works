/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include"LblShape.h"
namespace sdds {
   class Rectangle :public LblShape {
      unsigned int m_width;
      unsigned int m_height;
   public:
      Rectangle();
      Rectangle(const char* label,  int height,  int width);
      virtual ~Rectangle() {};
      void  getSpecs(std::istream& is);
      void draw(std::ostream& os)const;
};
}
#endif // !SDDS_RECTANGLE_H_
