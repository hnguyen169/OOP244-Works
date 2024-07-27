/* Citation and Sources...
Final Project Milestone 3
Module: Publication
Filename: Publication.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/27/2024
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

    Publication::Publication(const Publication& p) {
        *this = p;
    }

    Publication& Publication::operator=(const Publication& p) {
        set(p.m_membership);
        setRef(p.m_libRef);
        strcpy(m_shelfId, p.m_shelfId);
        m_date = p.m_date;
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }

        if (p.m_title != nullptr) {
            m_title = new char[strlen(p.m_title) + 1];
            strcpy(m_title, p.m_title);
        }
        else {
            m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    void Publication::set(int member_id) {
        m_membership = member_id;
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
        char t[SENECA_TITLE_WIDTH + 1] = { 0 };
        strncpy(t, m_title, SENECA_TITLE_WIDTH);
        if (conIO(os)) {
            os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << t << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            os << type();
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }
        return os;
    }

    istream& Publication::read(istream& istr) {
        char tempTitle[256]{};
        char tempShelfId[SENECA_SHELF_ID_LEN + 1]{};
        int tempLibRef = -1;
        int tempMembership = 0;
        Date tempDate;

        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
        setDefault();
        if (conIO(istr)) {
            cout << "Shelf No: ";
            istr.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1);
            if (strlen(tempShelfId) != SENECA_SHELF_ID_LEN) {
                istr.setstate(ios::failbit);
            }
            cout << "Title: ";
            istr.getline(tempTitle, 256);
            cout << "Date: ";
            istr >> tempDate;
        }
        else
        {
            istr >> tempLibRef;
            istr.ignore();
            istr.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            istr.getline(tempTitle, 256, '\t');
            istr >> tempMembership;
            istr.ignore();
            istr >> tempDate;
        }
        if (!tempDate) {
            istr.setstate(ios::failbit);
        }
        if (istr) {
            m_title = new char[strlen(tempTitle) + 1];
            strcpy(m_title, tempTitle);
            strcpy(m_shelfId, tempShelfId);
            m_membership = tempMembership;
            m_date = tempDate;
            m_libRef = tempLibRef;
        }
        return istr;
    }

    Publication::operator bool() const {
        bool ans = false;
        if (m_title != nullptr && m_shelfId[0] != '\0') {
            ans = true;
        }
        return ans;
    }

    ostream& operator<<(ostream& o, const Publication& p) {
        if (p) {
            p.write(o);
        }
        return o;
    }

    istream& operator>>(istream& i, Publication& p) {
        return (p.read(i));
    }
}