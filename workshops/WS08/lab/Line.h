//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/18/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h"

namespace seneca {
	class Line : public LblShape {
		int m_length = 0;
	public:
		Line() = default;
		Line(const char* cstr, int length);
		void getSpecs(istream& is);
		void draw(ostream& os) const;
	};
}

#endif