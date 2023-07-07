/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 6/6/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

    const double PI = 3.14159265;
	
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    bool Canister::isEmpty()const {
        if (m_contentVolume < 0.00001) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Canister::hasSameContent(const Canister& C) const
    {
        bool result = false;
        if (this->m_contentName != nullptr && C.m_contentName != nullptr) {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)
                result = true;
        }

        return result;
    }
       



    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && Cstr[0] != '\0'  && m_usable == true) {
            delete[] m_contentName;
            m_contentName = nullptr;

            m_contentName = new char[strLen(Cstr)+1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double hieght, double diameter, const char* contentName) {
        setToDefault();

        if ((hieght <= 40.0 && hieght >= 10.0) && (diameter <= 30.0 && diameter >= 10.0)) {
            m_height = hieght;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
   }

    Canister::~Canister()
    {
        if (m_contentName) {
            delete[] m_contentName;
            m_contentName = nullptr;
        }
    }

    void Canister::clear() {
        if (!m_usable) {      
            delete[] m_contentName;
            m_contentName = nullptr;
            m_contentVolume = 0.0;
            m_usable = true;
        }
    }

    double Canister::capacity()const {
        return (PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2));
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (!hasSameContent(contentName)) {
            m_usable = false;
        }

        return *this;
    }


    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity()) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }

        return *this;
    }

    Canister& Canister::pour(Canister& C) {

        setContent(C.m_contentName);

        if (C.volume() > (this->capacity() - this->volume())) {

            C.m_contentVolume -= (this->capacity() - this->volume());
            this->m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    ostream& Canister::display() const {

        
        cout.precision(1);
        cout << fixed;
        cout << setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        

        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of " << setw(7) << volume() << "cc   " << m_contentName;
        }
        return cout;
    }

}