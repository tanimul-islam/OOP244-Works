#include<iostream>
#include "HtmlText.h"
#include"cstring.h"
namespace sdds {
   HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
      if (title) {
         m_title = new char[strLen(title) + 1];
         strCpy(m_title, title);
      }
   }

   HtmlText::HtmlText(const HtmlText& source)
   {
      *this = source;
   }

   HtmlText& HtmlText::operator=(const HtmlText& source)
   {
      if (this != &source) {
         Text::operator= (source);
         if (m_title) delete[] m_title;
         if (source.m_title) {
            m_title = new char[strLen(source.m_title) + 1];
            strCpy(this->m_title, source.m_title);
         }
         else m_title = nullptr;
      }
      return *this;
   }

   HtmlText::~HtmlText()
   {
      if (m_title) delete[] m_title;
   }

   void HtmlText::write(std::ostream& os) const {
      bool MS = false;
      char tempChar;

      os << "<html><head><title>";
      if (m_title != nullptr) {
         os << m_title;
      }
      else {
         os << "No Title";
      }
      os << "</title></head>\n<body>\n";

      if (m_title) {
         int index = 0;
         os << "<h1>" << m_title << "</h1>\n";
         while ((tempChar = Text::operator[](index)) != '\0') {
            switch (tempChar) {
            case ' ':
               if (MS) {
                  os << "&nbsp;";
               }
               else {
                  MS = true;
               }
               break;
            case '<':
               os << "&lt;";
               MS = false;
               break;
            case '>':
               os << "&gt;";
               MS = false;
               break;
            case '\n':
               os << "<br />\n";
               MS = false;
               break;
            default:
               os << tempChar;
               MS = false;
               break;
            }
            index++;
         }
      }
      os << "</body>\n</html>";
   }

}