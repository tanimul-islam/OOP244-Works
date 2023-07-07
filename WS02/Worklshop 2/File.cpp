/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 5/23/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"


namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* employeeName) {

        int result = 0;
        result = fscanf(fptr, "%[^\n]\n", employeeName);


        if (result == 1) {
            return true;
        }
        else {
            return false;
        }

    }

    bool read(int& employeeNumber) {
        int result = 0;
        result = fscanf(fptr, "%d,", &employeeNumber);


        if (result == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool read(double& employeeSalary) {
        int result = 0;
        result = fscanf(fptr, "%lf,", &employeeSalary);

        if (result == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}