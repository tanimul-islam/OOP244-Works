/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Date: 20/7/2023
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#include "Utils.h"
namespace sdds {
    void strCpy(char* des, const char* src) {

        while (*src != '\0') {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';

    }

    int strLen(const char* s) {
        int length = 0;
        while (*s != '\0') {
            length++;
            s++;
        }
        return length;
    }

    void strCat(char* des, const char* src) {
        while (*des != '\0') {
            des++;
        }

        while (*src != '\0') {
            *des = *src;
            des++;
            src++;
        }

        *des = '\0'; // Add null-terminating character at the end
    }
}

