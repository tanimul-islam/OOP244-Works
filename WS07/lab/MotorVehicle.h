/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 17/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#define LICENSE_NUMBER_SZ 9
#define ADDRESS_SZ 64
#include <iostream>
namespace sdds {
   class MotorVehicle {
      char m_licenseNo[LICENSE_NUMBER_SZ]{};
      char m_address[ADDRESS_SZ]{};
      unsigned int m_yearBuilt{};
   public:
      MotorVehicle();
      MotorVehicle(const char* licenseNo, int year);
      virtual ~MotorVehicle();
      void moveTo(const char* address);
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);

   };
   std::ostream& operator<<(std::ostream& os, const MotorVehicle& source);
   std::istream& operator>>(std::istream& is, MotorVehicle& source);
}
#endif // !SDDS_MOTORVEHICLE_H
