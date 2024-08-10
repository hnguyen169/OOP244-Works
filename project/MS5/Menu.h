/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>

using namespace std;

namespace seneca {
	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu;

	class MenuItem {
		friend class Menu;

		char* m_content;		

		MenuItem(const char* name);
		MenuItem(const MenuItem& copy) = delete;
		MenuItem& operator=(const MenuItem& copy) = delete;
		~MenuItem();

		void setEmpty();
		bool isEmpty() const;

		operator bool() const;
		operator const char* () const;
		void display(ostream& os) const;
	};

	class Menu {
		MenuItem* title;
		MenuItem* m_items[MAX_MENU_ITEMS];
		unsigned int count;

		Menu(const Menu& copy) = delete;
		Menu& operator=(const Menu& copy) = delete;
		void setEmpty();
	public:
		Menu(const char* title = nullptr);
		~Menu();
		void displayTitle(ostream& os, bool withContent) const;
		void display(ostream& os) const;
		unsigned int run() const;
		unsigned int operator~() const;
		Menu& operator<<(const char* menuitemContent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](unsigned int index) const;
	};
	ostream& operator<<(ostream& os, const Menu& menu);
}

#endif // !SENECA_MENU_H