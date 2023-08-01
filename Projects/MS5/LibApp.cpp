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
#include <iostream>
#include <fstream>
#include "LibApp.h"
#include"Utils.h"
#include "PublicationSelector.h"

using namespace std;
namespace sdds {
   
   //Constructor-initialize and set the attributes and load the publication records from database
   LibApp::LibApp(const char* fileName) :m_mainMenu("Seneca Library Application"),
      m_exitMenu("Changes have been made to the data, what would you like to do?"),
      m_publicationType("Choose the type of publication:")
   {
      if (fileName) {
         strCpy(m_fileName, fileName);
      }
      m_changed = false;
      m_NOLP = 0;

      m_mainMenu << "Add New Publication" << "Remove Publication"
         << "Checkout publication from library" << "Return publication to library";

      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
      //Adding New Publication Type
      m_publicationType << "Book" << "Publication";
      load();
   }
   LibApp::~LibApp() {
      for (int i = 0; i < m_NOLP; i++) {
         delete m_publicationPtr[i];
      }
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
      char cType{};
      int i;
      cout << "Loading Data" << endl;
      ifstream readfile(m_fileName);

      for (i = 0; readfile && i < SDDS_LIBRARY_CAPACITY; i++)
      {
         readfile >> cType;
         readfile.ignore();

         //dynamically allocationg space for PPA array
         if (readfile) {
            if (cType == 'P') {
               m_publicationPtr[i] = new Publication;
            }
            else if (cType == 'B') {
               m_publicationPtr[i] = new Book;
            }

            if (m_publicationPtr[i]) {
               readfile >> *m_publicationPtr[i];
               m_NOLP++;
               m_LLRN = m_publicationPtr[i]->getRef();// for getting the latest reference number
            }
         }
      }

   }

   void LibApp::save() {
      int i;
      cout << "Saving Data" << endl;
      ofstream writeFile(m_fileName);

      for (i = 0; i < m_NOLP; i++) {
         if (m_publicationPtr[i]->getRef() != 0) {
            writeFile << *m_publicationPtr[i] << endl;
         }
      }
      writeFile.close();

   }
   int LibApp::search(int searchType) {
      /*Search all
         Search Checkout Items Search only those publications which are on loan by library members
         Search Available Items Search only those publications which are not on loan*/
      char title[256]{};
      int i = 0, libRef = 0, selection = 0;
      char typeC;

      PublicationSelector publicationSel("Select one of the following found matches:", 15);

      selection = m_publicationType.run();
      if (selection == 1) {
         typeC = 'B';
      }
      else if (selection == 2) {
         typeC = 'P';
      }
      //getting the title to search the PPA for. (up to 256 characters)
      cin.ignore(1456, '\n');
      cout << "Publication Title: ";
      cin.getline(title, 256);

      for (i = 0; i < m_NOLP; i++) {
         if (m_publicationPtr[i]->operator==(title) && typeC == m_publicationPtr[i]->type()
            && m_publicationPtr[i]->getRef() != 0) {

            if ((searchType == 1)
               || (searchType == 2 && m_publicationPtr[i]->onLoan())
               || (searchType == 3 && !m_publicationPtr[i]->onLoan())) {

               publicationSel << m_publicationPtr[i];
            }
         }
      }
      //If matches are found, sort the result and get the user's selection
      if (publicationSel) {
         publicationSel.sort();
         libRef = publicationSel.run();

         if (libRef > 0) cout << *getPub(libRef) << endl;
         else cout << "Aborted!" << endl;
      }
      else cout << "No matches found!" << endl;

      return libRef;
   }

   void LibApp::returnPub() {
      int libRef;
      double penaltyFee;
     
      int loanDays;
      cout << "Return publication to the library" << endl;
      libRef = search(2);
      if (libRef > 0 && confirm("Return Publication?")) {
         loanDays = Date() - getPub(libRef)->checkoutDate();
         if (loanDays > 15) {
            penaltyFee = (loanDays - SDDS_MAX_LOAN_DAYS) * 0.5;
            cout << "Please pay $" << penaltyFee << "penalty for being" << (loanDays - SDDS_MAX_LOAN_DAYS) << "days late!";
         }
         getPub(libRef)->set(0);
         m_changed = true;
         cout << "Publication returned" << endl;
      }
      cout << endl;
   }
   //adding new publication
   void LibApp::newPublication() {
      bool flag = false;
      int pubType;
      Publication* pubPtr = nullptr;
      if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
         cout << "Library is at its maximum capacity!" << endl;
         flag = true;
      }
      if (!flag) {
         cout << "Adding new publication to the library" << endl;
         pubType = m_publicationType.run();
         cin.ignore(1200, '\n');

         if (pubType == 0) {
            cout << "Aborted!" << endl;
            flag = false;
         }
         else if (pubType == 1) {
            pubPtr = new Book;
            cin >> *pubPtr;
         }
         else if (pubType == 2) {
            pubPtr = new Publication;
            cin >> *pubPtr;
         }

         if (cin.fail()) {
            cin.ignore();
            cin.clear();
            cout << "Aborted!" << endl;
            exit(0);
         }
         else {
            if (!flag && confirm("Add this publication to the library?")) {
               if (*pubPtr) {
                  m_LLRN++;
                  pubPtr->setRef(m_LLRN);
                  m_publicationPtr[m_NOLP] = pubPtr;
                  m_NOLP++;
                  m_changed = true;
                  cout << "Publication added" << endl;
               }
               else {
                  cout << "Failed to add publication!" << endl;
                  delete pubPtr;
               }
            }
         }
      }
      cout << endl;
   }
   //
   void LibApp::removePublication() {
      int libRef;
      cout << "Removing publication from library" << endl;
      libRef = search(1);
      if (libRef) {
         if (confirm("Remove this publication from library?")) {
            getPub(libRef)->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
         }
     }
      cout << endl;
   }
   void LibApp::checkOutPub() {
      int libRef;
      int membershipInput;
      cout << "Checkout publication from the library" << endl;
      libRef = search(3);
      
      if (libRef > 0) {
         if (confirm("Check out publication?")) {
            cout << "Enter Membership number: ";
            do
            {  
               membershipInput = getUserInput(10000, 99999);
               if (membershipInput < 10000 && membershipInput > 99999)
                  cout << "Invalid membership number, try again: ";
            } while (membershipInput < 10000 && membershipInput > 99999);
            getPub(libRef)->set(membershipInput);
            m_changed = true;
            cout << "Publication checked out" << endl;
         }
      }
      cout << endl;
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
   Publication* LibApp::getPub(int libRef)
   {
      int i;
      Publication* result = nullptr;
      for (i = 0; i < m_NOLP; i++) {
         if (m_publicationPtr[i]->getRef() == libRef) {
            result = m_publicationPtr[i];
         }
      }
      return result;
   }
}
