//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/17/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <string>
#include <cstring>

namespace seneca {
	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape(const char* cstr) {
		if (cstr) {
			m_label = new char[strlen(cstr) + 1];
			strcpy(m_label, cstr);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {
		string temp;
		getline(is, temp, ',');
		delete[] m_label;
		m_label = new char[temp.size() + 1];
		strcpy(m_label, temp.c_str());
	}
}