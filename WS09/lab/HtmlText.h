/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 22/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      //Rule of Three
      HtmlText(const HtmlText& source);
      HtmlText& operator=(const HtmlText& source);
      virtual ~HtmlText();
      //override Text::write()
      void write(std::ostream& os)const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
