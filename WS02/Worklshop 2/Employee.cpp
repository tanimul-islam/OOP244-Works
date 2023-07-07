/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 5/23/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employee) {
        bool ok = false;
        char name[128];

        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
            
            employee.m_name = new char[strLen(name) + 1];

            strCpy(employee.m_name, name);
            ok = true;

        }

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 

    bool load() {
        bool ok = false;
        int i = 0;



        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            Employee* employee = new Employee[noOfEmployees];
            employees = employee;
            
            for (i = 0; i < noOfEmployees; i++) {

                if (!load(employees[i])) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                    ok = false;
                }
                else {
                    ok = true;
                }

            }
            closeFile();

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }



    // TODO: Implementation for the display functions go here
    void display(Employee& employeeDetails) {
        cout << employeeDetails.m_empNo << ": " << employeeDetails.m_name << ", " << employeeDetails.m_salary << endl;


    }

    void display() {
        int i = 0;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();
        for (i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);

        }



    }

    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory() {
        int i;

        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
            
        }
        delete[] employees;
        employees = nullptr;
        
    }

}