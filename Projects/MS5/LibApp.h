/***********************************************************************
// OOP244 LibApp Module
// File	LibApp.h
// Version 1.0
// Date	2023/07/15
// Author	Tanimul Islam Dihan
// Description
//mockup application for the Seneca Library Application
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"

namespace sdds {
   class LibApp {
      char m_fileName[SDDS_FILENAME_LEN + 1];
      Publication* m_publicationPtr[SDDS_LIBRARY_CAPACITY + 1];
      int m_NOLP;
      int m_LLRN;
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;
      Menu m_publicationType;

      bool confirm(const char* message);
      void load();  
      void save();  
      int search(int searchType);  
      void returnPub();  

      void newPublication();
      void removePublication();
      void checkOutPub();
   public:
      LibApp(const char* fileName);
      virtual ~LibApp();
      void run();
      // Return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
      Publication* getPub(int libRef);
   };
}
#endif // !SDDS_LIBAPP_H



