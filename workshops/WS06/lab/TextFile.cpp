//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 07/06/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;

namespace seneca {
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }

   Line::Line() : m_value(nullptr) {}

   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setEmpty() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       delete[] m_filename;
       m_filename = nullptr;

       if (!isCopy) {
           m_filename = new char[strlen(fname) + 1];
           strcpy(m_filename, fname);
       }
       else {
           m_filename = new char[strlen(fname) + 3];
           strcpy(m_filename, "C_");
           strcat(m_filename, fname);
       }  
   }

   void TextFile::setNoOfLines() {
       ifstream file(m_filename);
       m_noOfLines = 0;
       string line;

       while (getline(file, line)){
           m_noOfLines++;
       }

       if (m_noOfLines == 0) {
           delete[] m_filename;
           m_filename = nullptr;
       }
   }

   void TextFile::loadText() {
       if (m_filename) {
           delete[] m_textLines;
           m_textLines = nullptr;

           setNoOfLines();
           m_textLines = new Line[m_noOfLines];

           ifstream file(m_filename);
           string line;
           unsigned i = 0;

           while (getline(file, line) && i < m_noOfLines) {
               m_textLines[i] = line.c_str();
               i++;
           }
           m_noOfLines = i;
       }
   }

   void TextFile::saveAs(const char* fileName) const {
       ofstream file(fileName);
       if (file) {
           for (unsigned i = 0; i < m_noOfLines; i++) {
               file << (const char*)m_textLines[i] << endl;
           }
       }       
   }

   TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {
       if (filename) {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile::TextFile(const TextFile& other) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(other.m_pageSize) {
       if (other.m_filename) {
           setFilename(other.m_filename, true);
           other.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& other) {
       if (this != &other) {
           delete[] m_textLines;
           m_textLines = nullptr;

           m_pageSize = other.m_pageSize;

           if (other.m_filename) {
               setFilename(other.m_filename, true);
               other.saveAs(m_filename);
               setNoOfLines();
               loadText();
           }
       }
       return *this;
   }

   TextFile::~TextFile() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
   }

   unsigned TextFile::lines() const {
       return m_noOfLines;
   }

   ostream& TextFile::view(ostream& ostr) const {
       if (m_filename) {
           ostr << m_filename << endl;
           
           for (unsigned i = 0; i < strlen(m_filename); i++) {
               ostr << '=';
           }

           ostr << endl;

           for (unsigned i = 0; i < m_noOfLines; i++) {
               ostr << (const char*)m_textLines[i] << endl;

               if ((i + 1) % m_pageSize == 0 && (i + 1) != m_noOfLines) {
                   ostr << "Hit ENTER to continue...";
                   ostr.flush();
                   cin.get();
               }
           }
       }
       return ostr;
   }

   istream& TextFile::getFile(istream& istr) {
       string filename;
       getline(istr, filename);
       setFilename(filename.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }

   const char* TextFile::operator[](unsigned index) const {
       if (m_noOfLines == 0) {
           return nullptr;
       }
       return m_textLines[index % m_noOfLines];
   }

   TextFile::operator bool() const {
       return m_filename != nullptr;
   }

   const char* TextFile::name() const {
       return m_filename;
   }

   ostream& operator<<(ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }

   istream& operator>>(istream& istr, TextFile& text) {
       return text.getFile(istr);
   }
}