// Final Project Milestone 4
// Book Module
// File	Book.h
// Version 1.0
// Author	Tanimul Islam
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include"Publication.h"

namespace sdds {
   class Book : public Publication {
      char* authorName;
   public:
      Book();
      Book(const Book& source);
      Book& operator=(const Book& source);
      virtual ~Book();

      //Methods
      void emptyBook();
      char type()const;
      void set(int member_id);
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      operator bool() const;
   };
}


#endif // !SDDS_BOOK_H
