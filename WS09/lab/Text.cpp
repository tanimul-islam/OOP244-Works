/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 22/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
  
   //one arguement constructor
   Text::Text(const char* filename)
   {
      if (filename) {
         m_filename = new char[strLen(filename) + 1];
         strCpy(m_filename, filename);
         read();
      }
   }
   //rule 0f three
   Text::Text(const Text& source)
   {
      *this = source;
   }

   Text& Text::operator=(const Text& source)
   {
      if (this != &source) {
         if (m_filename) {
            delete[] m_filename;
         }
         if (source.m_filename) {
            m_filename = new char[strLen(source.m_filename) + 1];
            strCpy(this->m_filename, source.m_filename);
            read();
         }
         else {
            m_filename = nullptr;
            m_content = nullptr;
         }
      }
      return *this;
   }

   Text::~Text()
   {
      if (m_filename) delete[] m_filename;
      if (m_content) delete[] m_content;
   }

   void Text::read()
   {
      char temp;
      int index = 0;

      ifstream readFile(m_filename);
      //delete curent content
      if (m_content) delete[] m_content;

      if (readFile.is_open()) {
         //allocates memory to the size of the file on the disk + 1
         m_content = new char[getFileLength() + 1];

         while (readFile.get(temp)) {
            m_content[index] = temp;
            index++;
         }
         m_content[index] = '\0';
         readFile.close();
      }
      else {
         m_content = nullptr;
      }
     
   }

   void Text::write(std::ostream& os) const
   {
      if (m_content != nullptr) {
         os << m_content;
      }
   }

   //operator overloading
   const char& Text::operator[](int index)const {
      if (index < getFileLength() || index >= 0) {
         return m_content[index];
      }
      else {
         //Undefined Behaviour if goes out of bounds
         return m_content[getFileLength()];
      }
   }

   ostream& operator<<(std::ostream& os, const Text& source) {
      source.write(os);
      return os;
   }
}