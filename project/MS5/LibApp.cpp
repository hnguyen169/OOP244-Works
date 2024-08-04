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

#include "LibApp.h"
#include <iostream>

using namespace std;

namespace seneca {
    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";

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
    }

    void LibApp::save() {
        cout << "Saving Data\n";
    }

    void LibApp::search() {
        cout << "Searching for publication\n";
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n\n";
        m_changed = true;
    }

    void LibApp::newPublication() {
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
}