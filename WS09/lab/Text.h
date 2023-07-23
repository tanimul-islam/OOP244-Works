/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 22/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& source);
      Text& operator=(const Text& source);
      virtual ~Text();


      void read();
      virtual void write(std::ostream& os)const; 
   };
   std::ostream& operator<<(std::ostream& os, const Text& source);
}
#endif // !SDDS_PERSON_H__

