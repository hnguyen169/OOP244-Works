//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/17/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H

#include "Shape.h"

namespace seneca {
	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape() = default;
		LblShape(const char* cstr);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(istream& is);
	};
}

#endif