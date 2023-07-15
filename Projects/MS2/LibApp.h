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
#include "Menu.h"
namespace sdds {
   class LibApp {
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;
      bool confirm(const char* message);
      void load();  
      void save();  
      void search();  
      void returnPub();  
      void newPublication();
      void removePublication();
      void checkOutPub();
   public:
      LibApp();
      virtual ~LibApp() {};
      void run();

   };
}
#endif // !SDDS_LIBAPP_H



