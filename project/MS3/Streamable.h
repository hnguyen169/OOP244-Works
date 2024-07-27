/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/27/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H

#include <iostream>

using namespace std;

namespace seneca {
	class Streamable {
	public:
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual bool conIO(ios& io) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() = default;
	};
	ostream& operator<<(ostream& os, const Streamable& obj);
	istream& operator>>(istream& is, Streamable& obj);
}

#endif