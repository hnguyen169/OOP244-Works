/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include "Streamable.h"
#include "Date.h"
#include "Lib.h"

namespace seneca {
    class Publication : public Streamable {
        char* m_title{};
        char m_shelfId[SENECA_SHELF_ID_LEN + 1]{};
        int m_membership = 0;
        int m_libRef = -1;
        Date m_date;
    public:
        Publication();
        Publication(const Publication& pub);
        Publication& operator=(const Publication& pub);
        ~Publication();

        // set values to default
        void setDefault();

        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        bool conIO(ios& io) const;
        virtual ostream& write(ostream& os) const;
        virtual istream& read(istream& is);
        virtual operator bool() const;        
    };
}
#endif // !SENECA_PUBLICATION_H