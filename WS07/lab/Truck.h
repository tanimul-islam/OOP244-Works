/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 17/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include"MotorVehicle.h"
namespace sdds {
   class Truck : public MotorVehicle {
      double maxWeight{ 0.00 };
      double currentLoad{ 0.00 };
   public:
      Truck();
      Truck(const char* license, int year, double weight, const char* address = nullptr);
      ~Truck();
      bool addCargo(double cargo);
      bool unloadCargo();

      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);
   };
   std::ostream& operator<<(std::ostream& os,const Truck& source);
   std::istream& operator>>(std::istream& is, Truck& source);
}
#endif // !SDDS_TRUCK_H
