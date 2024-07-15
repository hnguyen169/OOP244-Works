/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/15/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <ostream>

namespace seneca {
    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem {
        friend class Menu;

        char* m_content;

        MenuItem(const char* content = nullptr);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();

        operator bool() const;
        operator const char* () const;
    public:
        void display(std::ostream& os) const;
    };

    class Menu {
        MenuItem* m_title;
        MenuItem* m_items[MAX_MENU_ITEMS];
        unsigned int m_numItems;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        void displayTitle(std::ostream& os) const;
        void displayMenu(std::ostream& os) const;
        unsigned int run() const;
        unsigned int operator~() const;
        Menu& operator<<(const char* menuitemContent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
        const char* operator[](int index) const;  
    };
}

#endif