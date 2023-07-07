/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 15/6/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance >= 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

    Account:: operator bool() const {
       bool flag = false;

       if (m_number >= 10000 && m_number <= 99999
           && m_balance >= 0) {
           flag = true;
       }

       return flag;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }


   bool Account:: operator~() const{
       return m_number == 0;
   }

   Account& Account::operator =(const int account) {
       if (m_number == 0) {
           m_number = account;
       }
       else if(account < 0){
           setEmpty();
       }
       return *this;
   }

   Account& Account::operator =(Account& transfer) {
       if (this->m_number == 0 && transfer.m_number > 0) {
           this->m_number = transfer.m_number;
           this->m_balance = transfer.m_balance;

           transfer.m_balance = 0;
           transfer.m_number = 0;
       }
       return *this;
   }

   Account& Account::operator +=(const double deposit) {

       if (m_number > 0 && m_balance >= 0.0 && deposit > 0.0)
       {
           m_balance += deposit;
       }

       return *this;
   }

   Account& Account::operator -=(const double withdraw) {
       if (m_number > 0 && m_balance >= withdraw && withdraw >= 0.0){
           m_balance -= withdraw;
       }

       return *this;
   }

   Account& Account::operator <<(Account& transfer) {
       if (this->m_number > 0 && transfer.m_balance > 0 && this->m_number != transfer.m_number) {
           this->m_balance += transfer.m_balance;
           transfer.m_balance = 0;
       
       }
       return *this;
   }

   Account& Account::operator >> (Account& transfer) {
       if (this->m_number > 0 && transfer.m_balance > 0 && this->m_number != transfer.m_number) {
           transfer.m_balance += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }


    double operator+(const Account& left, const Account& right) {
        double sum = 0;

        if (left.m_number > 0 && right.m_number > 0) {
            sum = left.m_balance + right.m_balance;
        }
        return sum;
       
    }


    double operator+=(double& leftValue, const Account& rightValue) {

        

        if (rightValue.m_number > 0) {
            leftValue += rightValue.m_balance;
       }

        return leftValue;
     

   }
   


}