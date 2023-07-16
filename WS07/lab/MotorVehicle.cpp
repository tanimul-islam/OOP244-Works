/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 17/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   MotorVehicle::MotorVehicle() {};
   MotorVehicle::MotorVehicle(const char* licenseNo, int year, const char* location) {
      if (licenseNo) {
         strnCpy(m_licenseNo, licenseNo, LICENSE_NUMBER_SZ - 1);
      }
      m_yearBuilt = year;
      strnCpy(m_address, location, ADDRESS_SZ - 1);  
   }
   MotorVehicle::~MotorVehicle() {};
   void MotorVehicle::moveTo(const char* address) {
      if (strCmp(m_address, address) != 0) {
         cout << "|";
         cout.width(8);
         cout << m_licenseNo << "| |";

         cout.width(20);
         cout << m_address << " ---> ";

         cout.width(20);
         cout << left << address << "|" << right << endl;
         strCpy(m_address, address);
      }
   }

   ostream& MotorVehicle::write(ostream& os)const {
      os << "|";
      os.width(5);
      os << m_yearBuilt << " | " << m_licenseNo << " | " << m_address;

      return os;
   }
   istream& MotorVehicle::read(istream& in) {
      cout << "Built year: ";
      in >> m_yearBuilt;
      cout << "License plate: ";
      in >> m_licenseNo;
      cout << "Current location: ";
      in >> m_address;

      return in;

   }
   std::ostream& operator<<(std:: ostream& os, const MotorVehicle& source) {
      return source.write(os);
   }
   std::istream& operator>>(std::istream& is, MotorVehicle& source) {
      return source.read(is);
   }
}