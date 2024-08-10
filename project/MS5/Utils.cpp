/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Utils.h"
#include <iostream>
#include <cstdio>

using namespace std;

namespace seneca {
	void flushKey() {
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}

	unsigned int foolproof(unsigned max, unsigned min, const char* errMessage) {
		unsigned int num;
		while (true) {
			cin >> num;
			if (cin.fail() || num < min || num > max) {
				cin.clear();
				flushKey();
				cout << errMessage;
			}
			else {
				return num;
			}
		}
	}
}