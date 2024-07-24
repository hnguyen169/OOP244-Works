/* Citation and Sources...
Final Project Milestone 3
Module: Publication
Filename: Publication.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/15/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include "Streamable.h"

namespace seneca {
	class Publication : public Streamable {
		char* m_title;
		char m_shelfId[5];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		~Publication();
		Publication(const Publication& other);
		Publication& operator=(const Publication& other);

		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();

		virtual char type() const;
		bool onLoan() const;
		Date checkoutDate() const;
		bool operator==(const char* title) const;
		operator const char* () const;
		int getRef()const;

		bool conIO(ios& io) const;
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
		operator bool() const;
	};
}

#endif