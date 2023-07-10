/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 06/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line()
   {
      if (m_value != nullptr) {
         delete[] m_value;
         m_value = nullptr;
      }
   }
   void TextFile::setEmpty() {
      //deletes the m_nextLine dynamic Array , when it is not nullptr
      if (m_textLines != nullptr) {
         delete[] m_textLines;
         m_textLines = nullptr;
      }
      //delete m_filename dynamic string, when it is not nullptr
      if (m_filename != nullptr) {
         delete[] m_filename;
         m_filename = nullptr;
      }
      m_noOfLines = 0;
   }
   void TextFile::setFilename(const char* fname, bool isCopy) {
      //creating a dynamic string for filename
      if (!isCopy) {
         m_filename = new char[strLen(fname) + 1];
         strCpy(m_filename, fname);
      }
      else {
         m_filename = new char[strLen("C_") + strLen(fname) + 1];
         //adding "_C" as prefix using strCpy and strCat from cstring library
         strCpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
   }

   void TextFile::setNoOfLines()
   {
      ifstream file(m_filename);
      char ch;
      if (file.is_open()) {
         while (file.get(ch)) {
            if (ch == '\n') {
               m_noOfLines++;
            }
         }
         if (file.eof() && m_noOfLines > 0) {
            m_noOfLines++;
         }
      }
   
      else {
         delete[] m_filename;
         m_filename = nullptr;
      }
   }
   void TextFile::loadText() {
      unsigned i = 0;
      string line;
      if (m_filename != nullptr) {
         if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
         }
         m_textLines = new Line[m_noOfLines];
         ifstream file(m_filename);

         if (file.is_open()) {
            while (getline(file, line)) {
               //using c_str to converts the given string to an array of characters & adding a null-terminator
               m_textLines[i].m_value = new char[strLen(line.c_str()) + 1];
               strCpy(m_textLines[i].m_value, line.c_str());
               i++;
            }
         }
         m_noOfLines = i;
      }
   }

   void TextFile::saveAs(const char* fileName)const {
      unsigned i = 0;
      ofstream outFile(fileName);
      for (i = 0; i < m_noOfLines; i++) {
         outFile << m_textLines[i] << endl;
      }
   }

   TextFile::TextFile(unsigned pageSize) {
      setEmpty();
      m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
      setEmpty();
      m_pageSize = pageSize;
      if (filename != nullptr) {
         setFilename(filename, false);
         setNoOfLines();
         loadText();
      }
   }

   TextFile::TextFile(const TextFile& source) {
      unsigned i = 0;
      setEmpty();
      this->m_pageSize = source.m_pageSize;

     
      if (this != &source) //preventing self copy
      {
         if (source.m_textLines && source.m_noOfLines > 0) {           
            setFilename(source.m_filename, true);
            this->m_noOfLines = source.m_noOfLines;
            m_textLines = new Line[m_noOfLines];
            for ( i = 0; i < m_noOfLines; i++) {
               m_textLines[i].m_value = new char[strLen(source.m_textLines[i].m_value) + 1]; //allocating memroy for each line string
               strCpy(m_textLines[i].m_value, source.m_textLines[i].m_value);
            }
            saveAs(m_filename);
         }
      }   
   }


   TextFile& TextFile::operator=(const TextFile& incomingTxt) {
      if (this != &incomingTxt) {
         if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
         }
         if (incomingTxt.m_textLines && incomingTxt.m_noOfLines > 0) {
            this->m_noOfLines = incomingTxt.m_noOfLines;
            m_textLines = new Line[m_noOfLines];

            unsigned i = 0;
            while (i < m_noOfLines) {
               m_textLines[i].m_value = new char[strLen(incomingTxt.m_textLines[i].m_value) + 1];
               strCpy(m_textLines[i].m_value, incomingTxt.m_textLines[i].m_value);
               i++;
            }

            saveAs(m_filename);
         }
      }     
      return *this;
   }

   TextFile::~TextFile() {
      if (m_filename != nullptr) {
         delete[] m_filename;
         m_filename = nullptr;
      }
      if (m_textLines != nullptr) {
         delete[] m_textLines;
         m_textLines = nullptr;
      }
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
      unsigned i = 0;
      ostr << m_filename << endl;
      ostr.fill('=');
      ostr.width(strLen(m_filename));
      ostr << '=' << endl;
      for ( i = 0; i < m_noOfLines && i < m_pageSize; i++) {
         ostr << m_textLines[i] << endl;
      }
      //checking the pageSize
      if (i < m_noOfLines) { //means more line remains. Giving prompt
         do {
            unsigned j = 0;
            char enter;
            ostr << "Hit ENTER to continue...";
            cin.get(enter);
            for ( j = 0; i < m_noOfLines && j < m_pageSize; j++) {
               ostr << m_textLines[i] << endl;
               i++;
            }
         } while (i < m_noOfLines);
      }
      return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr) {
      string fNameInput;
      istr >> fNameInput;
      m_filename = new char[strLen(fNameInput.c_str()) + 1];
      strCpy(m_filename, fNameInput.c_str());
      //clearing input buffer
      istr.ignore(35758, '\n');

      setNoOfLines();
      loadText();
      return istr;
   }

   TextFile::operator bool()const {

      bool value = false;
      if (m_textLines != nullptr) {
         value = true;
      }
      return value;
      
   }

   unsigned TextFile::lines()const {
      return m_noOfLines;
   }

   const char* TextFile::name()const {
      return m_filename;
   }

   const char* TextFile::operator[](unsigned index)const {
      if (m_filename == nullptr) {
         return NULL;
      }
      else if(m_filename != nullptr && m_filename[0] != '\0') {
         if (index >= m_noOfLines) {
            index -= m_noOfLines;
         }
         return m_textLines[index].m_value;
      }
      return nullptr;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
      text.view(ostr);
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text) {
      text.getFile(istr);
      return istr;
   }


  

}