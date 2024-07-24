//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 07/24/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__

#include "Text.h"

namespace seneca {
    class HtmlText : public Text {
        char* m_title;
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& other);
        HtmlText& operator=(const HtmlText& other);
        ~HtmlText();
        
        void write(ostream& os) const;
    };
}

#endif // !SENECA_HTMLTEXT_H__
