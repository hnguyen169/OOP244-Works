//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/17/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Line.h"
#include <iomanip>
#include <string>

namespace seneca {
	Line::Line(const char* cstr, int linelength) : LblShape(cstr), m_length(linelength) {}

	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		string temp;
		getline(is, temp);
	}

	void Line::draw(ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; ++i) {
				os.put('=');
			}
		}
	}
}