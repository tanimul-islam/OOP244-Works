/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1.0
// Date	2023/07/12
// Author	Tanimul Islam Dihan
// Description
//Using this file to include to all extra functionality I need to complete the project.
//such as cstring lib.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//	Vwersion 2		07/26/2023			function for synamic allocation
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {

	//cstring library
	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);

	//Module-Functions
	int getUserInput(int lowerLimit, int upperLimit, const char* message = "Invalid Selection, try again: "); // default message updated

	//Dynamic-Allocation helper
	void dynamicStrCpy(char*& des, const char* src);

}
#endif // SDDS_UTILS_H__
