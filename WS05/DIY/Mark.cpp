/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 15/6/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {

	Mark::Mark() {
		m_mark = 0;
	}

	Mark::Mark(const int value) {
	
		if (value >= 0 && value <= 100) {
			m_mark = value;
		}
		else {
			m_mark = -1;
		}
	}

	Mark::~Mark() {
		m_mark = 0;
	}

	//conversion overloads
	Mark::operator int()const {
		int value = 0;

		if (m_mark >= 0 && m_mark <= 100) 
			value = m_mark;
		

		return value;
		
	}

	Mark::operator double()const {
		double value = 0;

		if (m_mark < 50 && m_mark >= 0) {
			value = 0.0;
		}
		else if(m_mark < 60 && m_mark >= 50){
			value = 1.0;
		}
		else if (m_mark < 70 && m_mark >= 60) {
			value = 2.0;
		}
		else if (m_mark < 80 && m_mark >= 70) {
			value = 3.0;
		}
		else if (m_mark <= 100 && m_mark >= 80) {
			value = 4.0;
		}
		else {
			value = 0;
		}

		return value;
	}

	Mark::operator char()const {
		char grade;


		if (m_mark < 50 && m_mark >= 0) {
			grade = 'F';
		}
		else if (m_mark < 60 && m_mark >= 50) {
			grade = 'D';
		}
		else if (m_mark < 70 && m_mark >= 60) {
			grade = 'C';
		}
		else if (m_mark < 80 && m_mark >= 70) {
			grade = 'B';
		}
		else if (m_mark <= 100 && m_mark >= 80) {
			grade = 'A';
		}
		else {
			grade = 'X';
		}

		return grade;
	}


	//operator overloads
	Mark& Mark::operator +=(const int add) {
		if (m_mark >= 0 && m_mark <= 100) 
			m_mark += add;
		

		return *this;
	}


	Mark& Mark::operator=(const int value) {

		m_mark = value;
		return *this;

	}

	int operator+=(int& value, const Mark& add)
	{
		
		int temp = int(add);

		if (temp >= 0 && temp <= 100)
			value += temp;

		return value;
	}
}