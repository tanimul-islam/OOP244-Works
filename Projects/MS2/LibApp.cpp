/***********************************************************************
// OOP244 LibApp Module
// File	LibApp.cpp
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
#include "LibApp.h"
using namespace std;
namespace sdds {
   //Constructor-initialize and set the attributes and load the publication records from database
   LibApp::LibApp():m_mainMenu("Seneca Library Application"),
      m_exitMenu("Changes have been made to the data, what would you like to do?") {
      m_changed = false ;
      m_mainMenu << "Add New Publication" << "Remove Publication" 
         << "Checkout publication from library" << "Return publication to library";
      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
      load();
   }
   //run function Confirmation
   bool LibApp::confirm(const char* message) {
      bool flag = false;
      Menu menu(message);
      menu << "Yes";

      if (menu.run()) {
         flag = true;
      
      }
      else {
         cout << endl;
      }
      return flag;
   }
   //Simple private fuctions:
   void LibApp::load() {
      cout << "Loading Data" << endl;
   }
   void LibApp::save() {
         cout << "Saving Data" << endl;
   }
   void LibApp::search() {
      cout << "Searching for publication" << endl;
   }
   void LibApp::returnPub() {
      search();
      cout << "Returning publication" << endl;
      cout << "Publication returned" << endl << endl;;
      m_changed = true;
   }
   //adding new publication
   void LibApp::newPublication() {
      cout << "Adding new publication to library" << endl;
      if (confirm("Add this publication to library?")) {
         m_changed = true;
         cout << "Publication added" << endl << endl;;
      }
   }
   //
   void LibApp::removePublication() {
      cout << "Removing publication from library" << endl;
      search();
      if (confirm("Remove this publication from the library?")) {
         m_changed = true;
         cout << "Publication removed" << endl << endl;
      }
   }
   void LibApp::checkOutPub() {
      search();
      if (confirm("Check out publication?")) {
         m_changed = true;
         cout << "Publication checked out" << endl<<endl;
      }
   }
   void LibApp::run() {
      int userInput;
      int exitInput;

      do {
         userInput = m_mainMenu.run();

         switch (userInput) {
         case 0:
            if (m_changed == true) {
               exitInput = m_exitMenu.run();

               switch (exitInput) {
               case 1:
                  save();
                  break;
               case 2:
                  userInput = 1;
                  break;
               case 0:
                  if (confirm("This will discard all the changes are you sure?")) {
                     m_changed = false;
                  }
                  break;
               }
            }
            cout << endl;
            break;
         case 1:
            newPublication();
            break;
         case 2:
            removePublication();
            break;
         case 3:
            checkOutPub();
            break;
         case 4:
            returnPub();
            break;
         }
      } while (userInput != 0);
      cout << "-------------------------------------------" << endl;
      cout << "Thanks for using Seneca Library Application" << endl;
   }
}
