#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      //type conversion operators
      operator bool() const;
      operator int() const;
      operator double() const;

      //Unary member operator
      bool operator~()const;

      //Binary member operators
      Account& operator =(const int account);
      Account& operator =(Account &transfer);
      Account& operator +=(const double deposit);
      Account& operator -=(const double withdraw);
      Account& operator <<(Account &transfer);
      Account& operator >> (Account& transfer);

      //Binary helper operators

      friend double operator+(const Account& left, const Account& right);
      friend double operator+=(double& leftValue, const Account& rightValue);


   };
   
   
}
#endif // SDDS_ACCOUNT_H_