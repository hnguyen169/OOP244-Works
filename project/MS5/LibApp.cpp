/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 08/04/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace seneca {
    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?"),
        m_pubTypeMenu("Choose the type of publication:"),
        m_NOLP(0), m_LLRN(0)
    {
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";

        m_pubTypeMenu << "Book"
                      << "Publication";

        strcpy(m_filename, "LibRecs.txt");

        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu tempMenu(message);
        tempMenu << "Yes";
        bool result = tempMenu.run() == 1;
        return result;
    }

    void LibApp::load() {
        cout << "Loading Data\n";
        ifstream file(m_filename);
        char pubType{};

        while (file >> pubType) {
            file.ignore();
            Publication* pub = nullptr;

            if (pubType == 'B') {
                pub = new Book;
            }
            else if (pubType == 'P') {
                pub = new Publication;
            }

            if (pub) {
                file >> *pub;
                if (file) {
                    m_PPA[m_NOLP++] = pub;
                    m_LLRN = pub->getRef();
                }
                else {
                    delete pub;
                }
            }
        }
    }

    void LibApp::save() {
        cout << "Saving Data\n";
        ofstream file(m_filename);

        for (int i = 0; i < m_NOLP; ++i) {
            if (m_PPA[i]->getRef() != 0) {
                file << *m_PPA[i] << endl;
            }
        }
    }

    void LibApp::search(bool all, bool onLoan) {
        PublicationSelector selector("Select one of the following found matches:");
        cout << "Choose the type of publication:\n";
        int pubType = m_pubTypeMenu.run();

        if (pubType == 0) {
            cout << "Aborted!" << endl;
            return;
        }

        char title[256];
        cout << "Publication Title: ";
        cin.ignore();
        cin.getline(title, 256);

        for (int i = 0; i < m_NOLP; ++i) {
            if (m_PPA[i]->getRef() != 0) {
                if (pubType == 1 && dynamic_cast<Book*>(m_PPA[i]) != nullptr && strstr(*m_PPA[i], title)) {
                    if ((all) || (onLoan && m_PPA[i]->onLoan()) || (!onLoan && !m_PPA[i]->onLoan())) {
                        selector << m_PPA[i];
                    }
                }
                else if (pubType == 2 && dynamic_cast<Book*>(m_PPA[i]) == nullptr && strstr(*m_PPA[i], title)) {
                    if ((all) || (onLoan && m_PPA[i]->onLoan()) || (!onLoan && !m_PPA[i]->onLoan())) {
                        selector << m_PPA[i];
                    }
                }
            }
        }

        if (selector) {
            selector.sort();
            int ref = selector.run();
            if (ref != 0) {
                cout << "Publication selected!" << endl;
            }
            else {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "No matches found!" << endl;
        }
    }

    void LibApp::returnPub() {
        search(true, true);
        cout << "Returning publication\n";
        cout << "Publication returned\n\n";
        m_changed = true;
    }

    void LibApp::newPublication() {
        if (m_NOLP == SENECA_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
            return;
        }

        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added\n\n";
        }
        cout << "\n";
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed\n";
        }
        cout << "\n";
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out\n";
        }
        cout << "\n";
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            unsigned int selection = m_mainMenu.run();
            switch (selection) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    unsigned int exitSelection = m_exitMenu.run();
                    switch (exitSelection) {
                    case 1:
                        save();
                        done = true;
                        cout << "\n";
                        break;
                    case 2:
                        cout << "\n";
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;
                            cout << "\n";
                        }
                        break;
                    }
                }
                else {
                    done = true;
                    cout << "\n";
                }
                break;
            }
        }
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    Publication* LibApp::getPub(int libRef) {
        for (int i = 0; i < m_NOLP; ++i) {
            if (m_PPA[i]->getRef() == libRef) {
                return m_PPA[i];
            }
        }
        return nullptr;
    }
}