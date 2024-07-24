//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/24/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <fstream>
#include <cstring>

namespace seneca {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }
    
    const char& Text::operator[](int index) const {
        return m_content[index];
    }
    
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }
    
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        *this = other;
    }
    
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            delete[] m_filename;
            m_filename = nullptr;
            delete[] m_content;
            m_content = nullptr;
            
            if (other.m_filename) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
            }
            
            if (other.m_content) {
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
            }
        }
        return *this;
    }
    
    Text::~Text() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }
    
    void Text::read() {
        delete[] m_content;
        m_content = nullptr;
        
        int length = getFileLength();
        if (length > 0) {
            m_content = new char[length + 1];
            ifstream fin(m_filename);
            fin.read(m_content, length);
            m_content[length] = '\0';
        }
    }
    
    void Text::write(ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }
    
    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}