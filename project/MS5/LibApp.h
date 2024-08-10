/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/09/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H

#include "Menu.h"
#include "Publication.h"

namespace seneca {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char m_fileName[256];
		Publication* m_PPA[SENECA_LIBRARY_CAPACITY];
		int m_NOLP;
		int m_LLRN;
		Menu m_pubTypeMenu;
		bool confirm(const char* message);
		void load();
		void save();
		int search(int mode);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		~LibApp();
		void run();
		Publication* getPub(int libRef);	
	};
}
#endif // !SENECA_LIBAPP_H