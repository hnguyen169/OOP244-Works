//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/31/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Bill.h"

using namespace std;

namespace seneca {
    double Bill::totalTax() const {
        double sumTax = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            sumTax += m_items[i].tax();
        }

        return sumTax;
    }

    double Bill::totalPrice() const {
        double sumPrice = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            sumPrice += m_items[i].price();
        }

        return sumPrice;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;

        if (isValid()) {
            cout << "| ";
            cout << left << setw(36) << m_title;
            cout << " |" << endl;
        } 
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {
            cout << "|                Total Tax: ";
            cout << right << setfill(' ') << setw(10) << totalTax();
            cout << " |" << endl;
            cout << "|              Total Price: ";
            cout << right << setfill(' ') << setw(10) << setprecision(2) << totalPrice();
            cout << " |" << endl;
            cout << "|          Total After Tax: ";
            cout << right << setfill(' ') << setw(10) << setprecision(2) << totalTax() + totalPrice();
            cout << " |" << endl;
        } 
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    
    bool Bill::isValid()const {
        if (strlen(m_title) > 0 && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; i++) {
                if (!m_items[i].isValid()) {
                    return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            strncpy(m_title, title, 36);
            m_title[36] = '\0';

            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);

            m_itemsAdded++;
            return true;
        }
        else {
            return false;
        }
    }

    void Bill::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {     
        delete[] m_items;
        m_items = nullptr;
    }
}