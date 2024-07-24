//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/24/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__

#include <iostream>

using namespace std;

namespace seneca {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength() const;
    protected:
        const char& operator[](int index) const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& other);
        Text& operator=(const Text& other);
        ~Text();
        
        void read();
        virtual void write(ostream& os) const;
        
        friend ostream& operator<<(ostream& os, const Text& text);
    };
}

#endif // !SENECA_PERSON_H__

