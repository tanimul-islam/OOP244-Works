/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 17/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Truck.h"


using namespace std;

namespace sdds {
   Truck::Truck() {};
   Truck::Truck(const char* license, int year, double weight, const char* address)
      : MotorVehicle(license, year) {
      if (weight > 0) {
         maxWeight = weight;
      }
      else if (address) {
         this->moveTo(address);
      }
   }
   Truck::~Truck() {};
   bool Truck::addCargo(double cargo) {
      bool flag = false;

      if (cargo > 0 && (currentLoad != maxWeight)) {
         currentLoad += cargo;
         flag = true;
         if (currentLoad > maxWeight) {
            currentLoad = maxWeight;
         }
      }
      return flag;
   }
   bool Truck::unloadCargo() {
      bool flag = false;
      if (currentLoad > 0) {
         currentLoad = 0.00;
         flag = true;
      }
      return flag;
   }
   ostream& Truck::write(ostream& os)const {
      MotorVehicle::write(os);
      os << " | " << currentLoad << "/" << maxWeight;
      return os;
   }
   istream& Truck::read(istream& in) {
      MotorVehicle::read(in);
      cout << "Capacity: ";
      in >> maxWeight;
      cout << "Cargo: ";
      in >> currentLoad;

      return in;
   }
   std::ostream& operator<<(std::ostream& os, const Truck& source) {
      return source.write(os);
   }
   std::istream& operator>>(std::istream& is, Truck& source) {
      return source.read(is);
   }
}