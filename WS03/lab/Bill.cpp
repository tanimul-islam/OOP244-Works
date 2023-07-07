/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 5/31/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;

	}

    bool Bill::isValid() const {
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; ++i) {
                if (!m_items[i].isValid()) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }


    double Bill::totalTax()const {
        int i = 0;
        double total=0.0;

        for (i = 0; i < m_noOfItems; i++) {
            total += m_items[i].tax();
        }

        return total;
    }

    double Bill::totalPrice()const {
        int i = 0;
        double totalPrice=0.0;

        for (i = 0; i < m_noOfItems; i++) {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title << " |" << endl;
        }

        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.precision(2);
            cout << totalTax();
            cout << " |"<<endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: " ;
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;

        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char* title, int noOfItems) {
        int i = 0;
        
        if (title[0] == '\0' || noOfItems <= 0) {
            setEmpty();
            return;
            
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_title[36] = '\0';

            m_items = new Item[m_noOfItems];
            for ( i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
       
    }

    bool  Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }


    void Bill::display()const {
        int i = 0;
        Title();
        for (i = 0; i < m_noOfItems; ++i) {
           m_items[i].display();
        }
        footer();
        
    }

    void Bill::deallocate() {
        
        delete[] m_items;
        m_items = nullptr;
        
    }
}