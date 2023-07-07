#pragma once
/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 5/23/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes

	bool read(char* employyeName);
	bool read(int& employeeNumber);
	bool read(double& employeeSalary);
}
#endif // !SDDS_FILE_H_
