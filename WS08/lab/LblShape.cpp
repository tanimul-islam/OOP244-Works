/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include <string>
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   const char* LblShape::label()const {
      return m_label;
   }
   LblShape::LblShape(const char* label) {
      if (label && label[0] != '\0') {
         m_label = new char[strLen(label) + 1];
         strCpy(m_label, label);
      } 
   }
   LblShape::~LblShape() {
      if (m_label) {
         delete[] m_label;
      }
   }
   void  LblShape::getSpecs(istream& is) {
      string newLabel;
      getline(is, newLabel, ',');
      delete[] m_label;
      m_label = new char[strLen(newLabel.c_str()) + 1];
      strCpy(m_label, newLabel.c_str());
   }

}