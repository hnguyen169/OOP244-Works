/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/04/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef BOOK_H
#define BOOK_H

#include "Publication.h"

namespace seneca {
	class Book : public Publication {
		char* authorName{};
	public:
		Book();
		Book(const Book& b);
		Book& operator=(const Book& b);
		~Book();

		char type() const;
		ostream& write(ostream& os) const;
		istream& read(istream& is);
		void set(int member_id);
		operator bool() const;
	};
}

#endif