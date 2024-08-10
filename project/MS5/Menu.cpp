/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include "Utils.h"
#include <cstring>

using namespace std;

namespace seneca {
	MenuItem::MenuItem(const char* name) {
		if (name && name[0] != '\0') {
			m_content = new char[strlen(name) + 1];
			strcpy(m_content, name);
		}
		else {
			setEmpty();
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_content;
	}

	void MenuItem::setEmpty() {
		m_content = nullptr;
	}

	bool MenuItem::isEmpty() const {
		return m_content[0] == '\0';
	}	

	MenuItem::operator bool() const {
		return (isEmpty());
	}

	MenuItem::operator const char* () const {
		return m_content;
	}

	void MenuItem::display(ostream& os) const {
		if (!isEmpty()) {
			os << m_content;
		}
	}

	void Menu::setEmpty() {
		unsigned int i;
		title = nullptr;
		for (i = 0; i < MAX_MENU_ITEMS; i++) {
			m_items[i] = nullptr;
		}
		count = 0;
	}

	Menu::Menu(const char* title) {
		setEmpty();
		if (title) {
			this->title = new MenuItem(title);
		}
	}
	
	Menu::~Menu() {
		unsigned int i;
		delete title;
		for (i = 0; i < count; i++) {
			delete m_items[i];
		}
	}

	void Menu::displayTitle(ostream& os, bool withContent) const {
		if (title) {
			os << title->m_content;
			if (withContent) {
				os << endl;
			}
		}
	}

	void Menu::display(ostream& os) const {
		displayTitle(os, true);
		unsigned int i;
		for (i = 0; i < count; i++) {
			os.width(2);
			os.setf(ios::right);
			os << i + 1 << "- ";
			m_items[i]->display(os);
			os << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
	}

	unsigned int Menu::run() const {
		display(cout);
		return foolproof(count, 0, "Invalid Selection, try again: ");
	}

	unsigned int Menu::operator~() const {
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemContent) {
		if (menuitemContent && menuitemContent[0] != '\0' && count < MAX_MENU_ITEMS) {
			m_items[count] = new MenuItem(menuitemContent);
			count++;
		}
		return *this;
	}

	Menu::operator int() const {
		return (int)count;
	}

	Menu::operator unsigned int() const {
		return count;
	}

	Menu::operator bool() const {
		if (count > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	const char* Menu::operator[](unsigned int index) const {
		if (count == 0) {
			return nullptr;
		}
		return (const char*)(*m_items[index % count]);
	}

	ostream& operator<<(ostream& os, const Menu& menu) {
		menu.displayTitle(os, false);
		return os;
	}	
}