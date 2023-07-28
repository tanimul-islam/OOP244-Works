#pragma once
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include"Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
   class Publication : public Streamable {
      char* m_title;
      char m_shelfId[SDDS_SHELF_ID_LEN];
      int m_membership;
      int m_libRef;
      Date m_date;
   public:
      Publication();
      virtual ~Publication();
      Publication(const Publication& source);
      Publication& operator=(const Publication& source);


      //Modifiers
      //sets all attributes to default
      void setDefault();
      // Sets the membership attribute to either zero or a five-digit integer.
      virtual void set(int member_id);
      // Sets the **libRef** attribute value
      void setRef(int value);
      // Sets the date to the current date of the system.
      void resetDate();

      //Querries
      //Returns the character 'P' to identify this object as a "Publication object"
      virtual char type()const;
      
      //Returns true is the publication is checkout (membership is non-zero)
      bool onLoan()const;
      
      //Returns the date attribute
      Date checkoutDate()const;
     
      //Returns true if the argument title appears anywhere in the title of the 
      //publication. Otherwise, it returns false.
      bool operator==(const char* title)const;
      
      //Returns the title attribute
      operator const char* ()const;
      
      //Returns the libRef attirbute. 
      int getRef()const;
      
      //Streamable pure virtual function implementations
      bool conIO(std::ios& io)const;
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      operator bool() const;
   };



}
#endif // !SDDS_PUBLICATION_H

