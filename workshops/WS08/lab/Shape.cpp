//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/17/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Shape.h"

namespace seneca {
	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}
}