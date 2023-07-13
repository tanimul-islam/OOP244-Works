// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {
   /*This function is used to validate the date. It checks if the year,
   month, and day values are within valid ranges. If any of these values are
   invalid, it sets an error code accordingly.
   */
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);  
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   /*his function returns the number of days in the month of the current date.*/
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 }; //Jan, Feb, March, April, May,June .....
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   /*This function returns the current system year by using the C library function time and localtime.*/
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   //: This function sets the date to the current system date. 
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   /*: This function calculates the number of days since January 1, 0001.
   It uses a formula that considers the year,
   month, and day values of the current date.*/
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   /* It is used to get the status of the date,
   indicating if there is an error or not.*/
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   std::istream& Date::read(std::istream& is) {
      errCode(NO_ERROR);

      is >> m_year;
      is.ignore();
      is >> m_mon;
      is.ignore();
      is >> m_day;

      if (is.fail()) {
         errCode(CIN_FAILED);
         is.clear();
      }
      //Flushig
      is.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
      return is;

   }
   std::ostream& Date::write(std::ostream& os)const {
      if (bad()) {
         os << dateStatus();
      }
      else {
         os << m_year << "/";
         os.width(2);
         os.fill(0);
         os << m_mon << "/";
         os.width(2);
         os.fill(0);
         os << m_day;

         os.fill(' ');
      }
      return os;
   }

   bool Date::operator==(const Date& other) const {
      return this->daysSince0001_1_1() == other.daysSince0001_1_1();
   }
   bool Date::operator!=(const Date& other) const {
      return this->daysSince0001_1_1() != other.daysSince0001_1_1();
   }
   bool Date::operator>=(const Date& other) const {
      return this->daysSince0001_1_1() >= other.daysSince0001_1_1();
   }
   bool Date::operator<=(const Date& other) const {
      return this->daysSince0001_1_1() <= other.daysSince0001_1_1();
   }
   bool Date::operator<(const Date& other) const {
      return this->daysSince0001_1_1() < other.daysSince0001_1_1();
   }
   bool Date::operator>(const Date& other) const {
      return this->daysSince0001_1_1() > other.daysSince0001_1_1();
   }

   int Date::operator-(const Date& other) {
      int days{0};
      if (this->daysSince0001_1_1() > other.daysSince0001_1_1()) {
        days = this->daysSince0001_1_1() - other.daysSince0001_1_1();
      }
      else {
         days = other.daysSince0001_1_1() - this->daysSince0001_1_1();
      }
      return days;
   }

   Date::operator bool()const {
      return !bad();
   }


   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }


}
