//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 06/29/2024
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
       char ch;

       while (file.get(ch)) {
           if (ch == '\n') {
               m_noOfLines++;
           }
           m_noOfLines++; // add 1 to noOfLines, **double check**
       }

       if (m_noOfLines == 0) {
           delete[] m_filename;
           m_filename = 0;
       }
   }

   void TextFile::loadText() {
       if (m_filename) {
           delete[] m_textLines;
           setNoOfLines();
           m_textLines = new Line[m_noOfLines];

           ifstream file(m_filename);

           // NOT DONE
       }
   }

   void TextFile::saveAs(const char* fileName) const {
       ofstream file(fileName);
       for (int i = 0; i < m_noOfLines; i++) {
           file << (const char*)m_textLines[i] << endl;
       }
   }

   TextFile::TextFile(unsigned pageSize) {

   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {

   }

   TextFile::TextFile(const TextFile&) {

   }

   TextFile& TextFile::operator=(const TextFile&) {

   }

   TextFile::~TextFile() {
       setEmpty();
   }

   unsigned TextFile::lines() const {
       return m_noOfLines;
   }

   ostream& TextFile::view(ostream& ostr) const {

   }

   istream& TextFile::getFile(istream& istr) {

   }

   const char* TextFile::operator[](unsigned index) const {

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