/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Lib.h"
#include "Book.h"
#include <cstring>
#include <iomanip>

namespace seneca {
	Book::Book() : Publication() {
		m_authorname = nullptr;
	}

	Book::Book(const Book& b) : Publication(b) {
		m_authorname = nullptr;

		if (b.m_authorname) {
			m_authorname = new char[strlen(b.m_authorname) + 1];
			strcpy(m_authorname, b.m_authorname);
		}
	}

	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			(Publication&)*this = b;

			delete[] m_authorname;
			m_authorname = nullptr;

			if (b.m_authorname) {
				m_authorname = new char[strlen(b.m_authorname) + 1];
				strcpy(m_authorname, b.m_authorname);
			}
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_authorname;
		m_authorname = nullptr;
	}

	char Book::type() const {
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		Publication::write(os);

		if (conIO(os)) {
			os << left;
			if (m_authorname) {
				os << " ";
				if (strlen(m_authorname) > SENECA_AUTHOR_WIDTH) {
					os.write(m_authorname, SENECA_AUTHOR_WIDTH);
				}
				else {
					os << setw(SENECA_AUTHOR_WIDTH) << m_authorname;
				}
				os << " |";
			}
		}
		else {
			os << m_authorname;
		}
		return os;
	}

	istream& Book::read(istream& is) {
		char tempAuthor[256]{};

		Publication::read(is);

		delete[] m_authorname;
		m_authorname = nullptr;

		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.get(tempAuthor, 256);
		}
		else {
			is.ignore();
			is.get(tempAuthor, 256);
		}

		if (is) {
			m_authorname = new char[strlen(tempAuthor) + 1];
			strcpy(m_authorname, tempAuthor);
		}
		else {
			delete[] m_authorname;
			m_authorname = nullptr;
		}
		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const {
		return m_authorname && m_authorname[0] != '\0' && Publication::operator bool();
	}
}