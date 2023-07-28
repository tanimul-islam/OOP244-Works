/* Citation and Sources...
Final Project Milestone 3
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Tanimul Islam
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include "Publication.h"
#include "Utils.h"


namespace sdds {
   Publication::Publication() {
      setDefault();
   }


   Publication::Publication(const Publication& source)
   {
      *this = source;
   }

   Publication& Publication::operator=(const Publication& source)
   {
      set(source.m_membership);
      setRef(source.m_libRef);
      strCpy(this->m_shelfId, source.m_shelfId);
      this->m_date = source.m_date;

      if (m_title) {
         delete[] m_title;
      }
      dynamicStrCpy(this->m_title, source.m_title);
      return *this;
   }

   Publication::~Publication()
   {
      delete[] m_title;
   }

   void Publication::setDefault() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
      resetDate();
   }

   void Publication::set(int member_id)
   {
      if (member_id >= 10000) {
         m_membership = member_id;
      }
      else {
         m_membership = 0;
      }
   }

   void Publication::setRef(int value)
   {
      m_libRef = value;
   }

   void Publication::resetDate()
   {
      m_date = Date();
   }

   char Publication::type() const
   {
      return 'P';
   }

   bool Publication::onLoan() const
   {
      return (m_membership != 0);
   }

   Date Publication::checkoutDate() const
   {
      return m_date;
   }

   bool Publication::operator==(const char* title) const
   {
      return strStr(m_title, title) != nullptr;
   }

   Publication::operator const char* () const
   {
      return m_title;
   }

   int Publication::getRef() const
   {
      return m_libRef;
   }

   bool Publication::conIO(std::ios& io) const
   {
      return &io == &std::cin || &io == &std::cout;
   }

   std::ostream& Publication::write(std::ostream& os) const
   {

      
      if (conIO(os)) {
         //os << m_shelfId << m_title << m_membership << m_date;
         os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << m_title << " | ";
         onLoan() ? os << m_membership : os << " N/A ";
         os << " | " << m_date << " |";
      }
      else {
         os << type() << "\t";
         os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
         onLoan() ? os << m_membership : os << " N/A ";
         os << "\t" << m_date;
      }
      return os;
   }

   std::istream& Publication::read(std::istream& istr)
   {
      //TEMPORAY VARIABLES
      char tempTitle[SDDS_TITLE_WIDTH + 1]{}, tempShelfId[SDDS_SHELF_ID_LEN + 1]{};
      int tempLibRef = -1, tempMembership = 0;
      Date tempDate;

      if (m_title) {
         delete[] m_title;
      }
      setDefault();
      if (conIO(istr)) {
         std::cout << "Shelf No: ";
         istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\n');
         if (strLen(tempShelfId) != SDDS_SHELF_ID_LEN) {
            istr.setstate(std::ios::failbit);
         }
         std::cout << "Title: ";
         istr.getline(tempTitle, SDDS_TITLE_WIDTH + 1, '\n');
         std::cout << "Date: ";
         istr >> tempDate;
      }
      else {
         istr >> tempLibRef;
         istr.ignore('\t');
         istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
         istr.getline(tempTitle, SDDS_TITLE_WIDTH + 1, '\t');
         istr >> tempMembership;
         istr.ignore('\t');
         istr >> tempDate;
      }
      if (!tempDate) {
         istr.setstate(std::ios::failbit);
      }
      if (istr) {
         dynamicStrCpy(m_title, tempTitle);
         strCpy(m_shelfId, tempShelfId);
         m_membership = tempMembership;
         m_date = tempDate;
         m_libRef = tempLibRef;
      }
      return istr;
   }

   Publication::operator bool() const
   {
      bool result = false;
      if (m_title != nullptr && m_shelfId[0] != '\0') {
         result = true;
      }
      return result;
   }
}