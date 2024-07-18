//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/18/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H

#include <iostream>

using namespace std;

namespace seneca {
	class Shape {
	public:
		virtual void draw(ostream& os) const = 0;
		virtual void getSpecs(istream& is) = 0;
		virtual ~Shape() = default;
	};
	ostream& operator<<(ostream& os, const Shape& shape);
	istream& operator>>(istream& is, Shape& shape);
}

#endif