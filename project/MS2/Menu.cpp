/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/15/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Menu.h"

namespace seneca {

    // MenuItem Implementation
    MenuItem::MenuItem(const char* content) {
        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            m_content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    MenuItem::operator const char* () const {
        return m_content;
    }

    void MenuItem::display(std::ostream& os) const {
        if (*this) {
            os << m_content;
        }
    }

    // Menu Implementation
    Menu::Menu() : m_title(nullptr), m_numItems(0) {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) : m_numItems(0) {
        m_title = new MenuItem(title);
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        delete m_title;
        for (unsigned int i = 0; i < m_numItems; ++i) {
            delete m_items[i];
        }
    }

    void Menu::displayTitle(std::ostream& os) const {
        if (m_title) {
            m_title->display(os);
            os << std::endl;
        }
    }

    void Menu::displayMenu(std::ostream& os) const {
        displayTitle(os);
        for (unsigned int i = 0; i < m_numItems; ++i) {
            os << std::setw(2) << std::right << (i + 1) << "- ";
            m_items[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";
    }

    unsigned int Menu::run() const {
        displayMenu(std::cout);
        unsigned int selection;
        bool valid = false;
        while (!valid) {
            std::cin >> selection;
            if (std::cin.fail() || selection > m_numItems) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid Selection, try again: ";
            }
            else {
                valid = true;
            }
        }
        return selection;
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        if (m_numItems < MAX_MENU_ITEMS) {
            m_items[m_numItems] = new MenuItem(menuitemContent);
            ++m_numItems;
        }
        return *this;
    }

    Menu::operator int() const {
        return static_cast<int>(m_numItems);
    }

    Menu::operator unsigned int() const {
        return m_numItems;
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }

    const char* Menu::operator[](int index) const {
        if (m_numItems == 0) {
            return nullptr;
        }
        return static_cast<const char*>(*m_items[index % m_numItems]);
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        if (menu.m_title) {
            menu.m_title->display(os);
        }
        return os;
    }

}