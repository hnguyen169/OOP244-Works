/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.cpp
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
#include "Publication.h"
#include <cstring>
#include <iomanip>

namespace seneca {
	Publication::Publication() {
		setDefault();
	}

	Publication::Publication(const Publication& pub) {
		m_title = nullptr;
		*this = pub;
	}

	Publication& Publication::operator=(const Publication& pub) {
		if (this != &pub) {
			delete[] m_title;
			m_title = nullptr;
		
			strcpy(m_shelfId, pub.m_shelfId);
			set(pub.m_membership);
			setRef(pub.m_libRef);
			m_date = pub.m_date;

			if (pub.m_title) {
				m_title = new char[strlen(pub.m_title) + 1];
				strcpy(m_title, pub.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}

	void Publication::setDefault() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	void Publication::set(int member_id) {
		if (member_id >= 10000 && member_id <= 99999) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	void Publication::resetDate() {
		m_date = Date();
	}

	char Publication::type() const {
		return 'P';
	}

	bool Publication::onLoan() const {
		return (m_membership != 0);
	}

	Date Publication::checkoutDate() const {
		return m_date;
	}

	bool Publication::operator==(const char* title) const {
		return strstr(m_title, title) != nullptr;
	}

	Publication::operator const char* () const {
		return m_title;
	}

	int Publication::getRef() const {
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const {
		return &io == &cin || &io == &cout;
	}

	ostream& Publication::write(ostream& os) const {
		if (conIO(os)) {
			if (*this) {
				os << "| " << setw(SENECA_SHELF_ID_LEN) << setfill(' ') << m_shelfId << " | ";
				if (strlen(m_title) > SENECA_TITLE_WIDTH) {
					os.write(m_title, SENECA_TITLE_WIDTH);
				}
				else {
					os << left << setw(SENECA_TITLE_WIDTH) << setfill('.') << (m_title ? m_title : "");
				}
				os << " | ";
				if (m_membership != 0) {
					os << setw(5) << setfill(' ') << m_membership;
				}
				else {
					os << " N/A ";
				}
				os << " | " << setfill(' ') << m_date << " |";
			}
		}
		else {
			if (*this) {
				os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
					<< (m_title ? m_title : "") << '\t' << m_membership << '\t' << m_date;
				if (type() == 'B') {
					os << '\t';
				}
			}
		}
		return os;
	}

	istream& Publication::read(istream& is) {
		delete[] m_title;
		setDefault();		
		
		char tempTitle[256]{};
		char tempShelfId[SENECA_SHELF_ID_LEN + 1]{};		
		int tempMembership = 0;
		int tempLibRef = -1;
		Date tempDate;

		if (conIO(is)) {
			cout << "Shelf No: ";
			is.ignore();
			is.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1);
			if (strlen(tempShelfId) != SENECA_SHELF_ID_LEN) {
				is.setstate(ios::failbit);
				return is;
			}
			cout << "Title: ";
			is.getline(tempTitle, 256);
			cout << "Date: ";
			is >> tempDate;
		}
		else {
			is >> tempLibRef;
			is.ignore();
			is.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1, '\t');
			is.getline(tempTitle, 256, '\t');
			is >> tempMembership;
			is.ignore();
			is >> tempDate;
		}

		if (strcmp(tempDate.dateStatus(), "No Error") != 0) {
			is.setstate(ios::failbit);
			return is;
		}

		if (is) {
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelfId);
			m_membership = tempMembership;
			m_date = tempDate;
			m_libRef = tempLibRef;
		}
		else {
			delete[] m_title;
			m_title = nullptr;
		}

		return is;
	}

	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');		
	}	
}