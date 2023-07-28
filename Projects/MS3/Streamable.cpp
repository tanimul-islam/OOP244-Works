#include"Streamable.h"
using namespace std;
namespace sdds {
   //empty virtual destructor
   Streamable::~Streamable() {};

   ostream& operator<<(ostream& os, const Streamable& obj) {
      if (obj) {
         obj.write(os);
      }
      return os;
   }
   istream& operator>>(istream& is, Streamable& obj) {
      return (obj.read(is));
   }
}