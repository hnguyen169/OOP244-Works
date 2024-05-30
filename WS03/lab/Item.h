//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/28/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_

namespace seneca {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      // Sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
      void setName(const char* name);
   public:
      // Sets the Item to a recognizable safe Empty State. 
      void setEmpty();
      // Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method
      // Then sets the m_price and m_taxed attributes to the corresponding arguments.
      void set(const char* name, double price, bool taxed);
      // Prints an item with formatting based on whether Item is valid/invalid.
      void display()const;
      // Returns true if the Item is not set to the empty state (As done in setEmpty function) .
      bool isValid()const;
      // Returns the m_price attribute;
      double price()const;
      // Returns the product of m_price and 0.13(define a constant double value for this tax rate).
      // Or it returns 0.0 if the m_taxed is false.
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H
