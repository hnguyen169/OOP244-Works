//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/31/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Item.h"

using namespace std;

namespace seneca {
    void Item::setName(const char* name) {
        if (name != nullptr && strlen(name) > 0) {
            strncpy(m_itemName, name, 20);
            m_itemName[20] = '\0';
        }
        else {
            setEmpty();
        }
    }

    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = false;
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (price < 0.0 || name == nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }       
    }

    void Item::display() const {
        if (isValid()) {
            cout << "| ";
            cout << left << setfill('.') << setw(20) << m_itemName;
            cout << " | ";
            cout << right << setfill(' ') << fixed << setw(7) << setprecision(2) << m_price;
            cout << " | ";
            cout << left << setfill(' ') << setw(3) << (m_taxed ? "Yes" : "No") << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid() const {
        return m_itemName[0] != '\0';
    }

    double Item::price() const{
        return m_price;
    }

    double Item::tax() const {
        const double tax = 0.13;
        return m_taxed ? m_price * tax : 0.0;
    }
}