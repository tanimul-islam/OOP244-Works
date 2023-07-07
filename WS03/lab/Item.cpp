/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 5/31/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
	

	void Item:: setName(const char* name) {
		strnCpy(m_itemName, name, 20);

		m_itemName[20] = '\0';
	}

	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		const double taxRate = 0.13;
		if (!m_taxed) {
			return 0.0;
		}
		else {
			return m_price * taxRate;
		}
	}

	bool Item::isValid()const {

		if (m_itemName[0] != '\0' && m_price >= 0.0) {
			return true;
		}
	
		return false;
		
	}


	void Item::display()const {

		if (isValid()) {
			
			cout << "| ";
			cout.setf(ios::left, ios::adjustfield);
			cout.fill('.');
			cout.width(20);
			cout << m_itemName;
			cout.unsetf(ios::left);

			cout << " | ";
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout.width(7);
			cout << m_price;
			cout.unsetf(ios::right);

			if (m_taxed == true) {
				cout << " | " << "Yes" << " |" << endl;
			}
			else {
				cout << " | " << "No " << " |" << endl;
			}

		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}





}