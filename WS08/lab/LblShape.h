/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {
   class LblShape : public Shape {
      char* m_label{nullptr};
   protected:
      const char* lable()const;
   public:
      LblShape() = default;
      LblShape(const char* lable);
      virtual ~LblShape();
      LblShape(const LblShape& source) = delete;
      LblShape& operator=(const LblShape& source) = delete;
      void getSpecs(std::istream& is);
   };
}
#endif // !SDDS_LBLSHAPE_H_
