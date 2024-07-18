//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/18/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Rectangle.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>

namespace seneca {
	Rectangle::Rectangle() : m_width(0), m_height(0) {}

	Rectangle::Rectangle(const char* cstr, int width, int height) : LblShape(cstr), m_width(width), m_height(height) {
        int labelWidth = strlen(label());
		if (height < 3 || width < labelWidth + 2) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		char comma;
		is >> m_width >> comma >> m_height;
        string temp;
        getline(is, temp);
	}

    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0 && label() != nullptr) {
            os << '+';
            for (int i = 0; i < m_width - 2; ++i) {
                os << '-';
            }
            os << "+\n";

            os << '|';
            os << left << setw(m_width - 2) << label();
            os << "|\n";

            for (int i = 0; i < m_height - 3; ++i) {
                os << '|';
                for (int j = 0; j < m_width - 2; ++j) {
                    os << ' ';
                }
                os << "|\n";
            }

            os << '+';
            for (int i = 0; i < m_width - 2; ++i) {
                os << '-';
            }
            os << '+';
        }
    }
}