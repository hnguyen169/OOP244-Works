/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"

namespace seneca {
	ostream& operator<<(ostream& os, const Streamable& str) {
		return str.write(os);
	}

	istream& operator>>(istream& is, Streamable& str) {
		return str.read(is);
	}
}