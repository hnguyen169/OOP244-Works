/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/04/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>
#include <iomanip>

namespace seneca {
	Book::Book() : authorName(nullptr) {}

	Book::Book(const Book& b) {
		*this = b;
	}

	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			Publication::operator=(b);

			delete[] authorName;
			authorName = nullptr;

			if (b.authorName && b.authorName[0] != '\0') {
				authorName = new char[strlen(b.authorName) + 1];
				strcpy(authorName, b.authorName);
			}
			else {
				authorName = nullptr;
			}
		}		
		return *this;
	}

	Book::~Book() {
		delete[] authorName;
		authorName = nullptr;
	}

	char Book::type() const {
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		Publication::write(os);

		if (conIO(os)) {
			char tempAuthor[SENECA_AUTHOR_WIDTH + 1] = { 0 };
			strncpy(tempAuthor, authorName, SENECA_AUTHOR_WIDTH);

			os << " " << setw(SENECA_AUTHOR_WIDTH) << left << setfill(' ') << tempAuthor << " |";
		}
		else {
			os << "\t" << (authorName ? authorName : "");
		}
		return os;
	}

	istream& Book::read(istream& is) {
		char tempAuthor[256]{};

		Publication::read(is);

		delete[] authorName;
		authorName = nullptr;

		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.getline(tempAuthor, 256);
		}
		else {
			is.ignore();
			is.get(tempAuthor, 256);
		}

		if (is) {
			if (tempAuthor[0] != '\0') {
				authorName = new char[strlen(tempAuthor) + 1];
				strcpy(authorName, tempAuthor);
			}
			else {
				authorName = nullptr;
			}
		}	
		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const {
		return (authorName && authorName[0] != '\0' && Publication::operator bool());
	}
}