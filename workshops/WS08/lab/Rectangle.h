//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/18/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H

#include "LblShape.h"

namespace seneca {
	class Rectangle : public LblShape {
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* cstr, int width, int height);
		void getSpecs(istream& is);
		void draw(ostream& os) const;
	};
}

#endif