// Final Project Milestone 4
// Book Module
// File	Book.cpp
// Version 1.0
// Author	Tanimul Islam
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Book.h"
#include "Utils.h"

namespace sdds 
   {

   Book::Book() {
      emptyBook();
   }

   Book::Book(const Book& source) :Publication(source)
   {
      if (source.authorName) {
         delete[] authorName;
         dynamicStrCpy(this->authorName, source.authorName);
      }
      
   }

   Book& Book::operator=(const Book& source)
   {
      if (this != &source) {
         Publication::operator=(source);
         if (source.authorName) {
            delete[] authorName;
            dynamicStrCpy(this->authorName, source.authorName);
         }
      }
      return *this;
      
   }

   Book::~Book() 
   {
      if (authorName) {
         delete[] authorName;
         authorName = nullptr;
      }
   }

   void Book::emptyBook()
   {
      authorName = nullptr;
   }

   char Book::type() const
   {  
      return 'B';
   }

   void Book::set(int member_id) 
   {
      Publication::set(member_id);
      Publication::resetDate();
   }

   std::ostream& Book::write(std::ostream& os) const
   {
      Publication::write(os);
      if (conIO(os)) {
         char tempAuthorName[SDDS_AUTHOR_WIDTH + 1] = { 0 };
         strnCpy(tempAuthorName, authorName, SDDS_AUTHOR_WIDTH);
         os << " ";
         os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << tempAuthorName << " |";
      }
      else {
         os << "\t" << authorName;
      }
      return os;
   }

   std::istream& Book::read(std::istream& istr)
   {
      char tempAuthorName[256] = { 0 };
      Publication::read(istr);

      if (authorName) delete[] authorName;

      if (conIO(istr)) {
         istr.ignore();
         std::cout << "Author: ";
      }
      else {
         istr.ignore(1000,'\t');
      }
      istr.get(tempAuthorName, 256);
      if (istr) {
         dynamicStrCpy(authorName, tempAuthorName);
      }
      return istr;
   }

   Book::operator bool() const
   {
      return authorName && Publication::operator bool();
   }

}
