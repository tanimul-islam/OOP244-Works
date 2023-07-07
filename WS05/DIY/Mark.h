/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 15/6/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef MARK_SDDS_H
#define MARK_SDDS_H

#include <iostream>

namespace sdds {

	class Mark {
		int m_mark;
		/*char m_grader;
		double m_gradeScale;*/
		

	public:
		Mark();
		Mark(const int value);
		~Mark();

		//conversion overloads
		operator int()const;
		operator double()const;
		operator char()const;
		

		//operator overloads
		Mark& operator +=(const int add);
		Mark& operator=(const int value);
		

	};

	int operator +=(int& value, const Mark& add);




}

#endif // !MARK_SDDS_H

