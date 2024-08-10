/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
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
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Book.h"
#include "Utils.h"
#include <fstream>
#include <cstring>
#include <iomanip>

namespace seneca {
    bool LibApp::confirm(const char* message) {
        if (message[0] != '\0') {
            Menu menu(message);
            menu << "Yes";
            return menu.run();
        }
        return false;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;

        ifstream is(m_fileName);

        char type{};
        int highestRef = 0;
        m_NOLP = 0;
        m_LLRN = 0;

        while (is >> type) {
            is.ignore();

            if (type == 'B') {
                m_PPA[m_NOLP] = new Book;
            }
            else if (type == 'P') {
                m_PPA[m_NOLP] = new Publication;
            }

            if (m_PPA[m_NOLP]) {
                if (!(is >> *m_PPA[m_NOLP])) {
                    delete m_PPA[m_NOLP];
                    m_PPA[m_NOLP] = nullptr;
                    break;
                }
                int currentRef = m_PPA[m_NOLP]->getRef();
                if (currentRef > highestRef) {
                    highestRef = currentRef;
                }
                m_NOLP++;
            }
        }

        m_LLRN = highestRef;
        is.close();
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;

        ofstream os(m_fileName);

        for (int i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() != 0) {
                os << *m_PPA[i] << endl;
            }
        }
    }

    int LibApp::search(int mode) {
        int pubTypeSelection = m_pubTypeMenu.run();
        if (pubTypeSelection == 0) {
            cout << "Aborted!" << endl;
        }
        cin.ignore();

        char title[256];
        cout << "Publication Title: ";
        cin.getline(title, 256);

        PublicationSelector selector("Select one of the following found matches:");
        for (int i = 0; i < m_NOLP; i++) {
            if (m_PPA[i] != nullptr && m_PPA[i]->getRef() != 0) {
                bool typeMatches = (pubTypeSelection == 1 && m_PPA[i]->type() == 'B') ||
                    (pubTypeSelection == 2 && m_PPA[i]->type() == 'P');
                bool titleMatches = (m_PPA[i]->operator const char* () != nullptr) &&
                    (strstr(m_PPA[i]->operator const char* (), title) != nullptr);
                bool loanMatches = (mode == 0) || (mode == 1 && m_PPA[i]->onLoan()) || (mode == 2 && !m_PPA[i]->onLoan());

                if (typeMatches && titleMatches && loanMatches) {
                    selector << m_PPA[i];
                }
            }
        }
        if (selector) {
            selector.sort();
            int libRef = selector.run();
            if (libRef == 0) {
                cout << "Aborted!" << endl;
                return 0;
            }
            else {
                Publication* selectedPub = nullptr;
                for (int i = 0; i < m_NOLP; i++) {
                    if (m_PPA[i] != nullptr && m_PPA[i]->getRef() == libRef) {
                        selectedPub = m_PPA[i];
                        break;
                    }
                }
                if (selectedPub) {
                    selectedPub->write(cout);
                    cout << endl;
                }
                return libRef;
            }
        }
        else {
            cout << "No matches found!" << endl;
        }
        return 0;
    }    

    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;

        int libRef = search(1);
        if (libRef == 0) {
            return;
        }

        Publication* returnPub = getPub(libRef);
        if (returnPub && confirm("Return Publication?")) {
            Date today;
            int loanDays = today - returnPub->checkoutDate();
            if (loanDays > 15) {
                double penalty = (loanDays - 15) * 0.50;
                cout << "Please pay $" << fixed << setprecision(2) << penalty << " penalty for being " << loanDays - 15 << " days late!" << endl;
            }
            returnPub->set(0);
            m_changed = true;
            cout << "Publication returned" << endl;
        }
        else {
            cout << "Aborted!" << endl;
        }
    }

    void LibApp::newPublication() {
        if (m_NOLP == SENECA_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
            return;
        }

        cout << "Adding new publication to the library" << endl;

        int pubTypeChoice = m_pubTypeMenu.run();
        if (pubTypeChoice == 0) {
            cout << "Aborted!" << endl;
            return;
        }

        Publication* newPub = nullptr;
        if (pubTypeChoice == 1) {
            newPub = new Book();
        }
        else if (pubTypeChoice == 2) {
            newPub = new Publication();
        }

        cin >> *newPub;
        if (cin.fail()) {
            flushKey();
            cout << "Aborted!" << endl;
            delete newPub;
            return;
        }
        else {
            if (confirm("Add this publication to the library?")) {
                if (newPub) {
                    m_LLRN++;
                    newPub->setRef(m_LLRN);
                    m_PPA[m_NOLP++] = newPub;
                    m_changed = true;
                    cout << "Publication added\n";
                }
                else {
                    cout << "Failed to add publication!" << endl;
                    delete newPub;
                }
            }
            else {
                cout << "Aborted!" << endl;
                delete newPub;
            }
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;

        int libRef = search(0);
        if (libRef == 0) {
            return;
        }

        Publication* removePub = getPub(libRef);
        if (removePub && confirm("Remove this publication from the library?")) {
            removePub->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        else {
            cout << "Aborted!" << endl;
        }
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;

        int libRef = search(2);
        if (libRef == 0) {
            return;
        }

        Publication* checkoutPub = getPub(libRef);
        if (checkoutPub && confirm("Check out publication?")) {
            bool valid = false;
            int mem_num;

            cout << "Enter Membership number: ";
            do {
                cin >> mem_num;
                if (cin.fail() || mem_num < 10000 || mem_num > 99999) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid membership number, try again: ";
                }
                else {
                    checkoutPub->set(mem_num);
                    valid = true;
                }
            } while (!valid);

            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        else {
            cout << "Aborted!" << endl;
        }
    }

    LibApp::LibApp(const char* filename) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubTypeMenu("Choose the type of publication:") {
        if (filename) {
            strcpy(m_fileName, filename);
            m_fileName[strlen(m_fileName)] = '\0';
        }
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_pubTypeMenu << "Book" << "Publication";
        load();
    }    

    LibApp::~LibApp() {
        for (int i = 0; i < m_NOLP; i++) {
            delete m_PPA[i];
        }
    }

    void LibApp::run() {
        unsigned int s1;
        unsigned int s2;
        bool flag = false;

        while (!flag) {
            s1 = m_mainMenu.run();
            switch (s1) {
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
                    s2 = m_exitMenu.run();
                    switch (s2) {
                    case 1:
                        save();
                        flag = true;
                        break;
                    case 2:
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            flag = true;
                        }
                        break;
                    }
                }
                else {
                    flag = true;
                }
            }
            cout << endl;
        }

        if (flag) {
            cout << "-------------------------------------------\n"
                << "Thanks for using Seneca Library Application\n";
        }
    }

    Publication* LibApp::getPub(int libRef) {
        for (int i = 0; i < m_NOLP; i++) {
            if (m_PPA[i] != nullptr && m_PPA[i]->getRef() == libRef) {
                return m_PPA[i];
            }
        }
        return nullptr;
    }
}