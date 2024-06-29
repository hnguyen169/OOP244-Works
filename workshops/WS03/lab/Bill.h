//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/31/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_

#include "Item.h"

namespace seneca {
   class Bill {
      char m_title[37];
      Item* m_items;
      int m_noOfItems;
      int m_itemsAdded;
      // Returns the total tax applied to the Items.
      double totalTax()const;
      // Returns the sum of prices of Items.
      double totalPrice()const;
      // Prints the title of the shopping list.
      void Title()const;
      // Prints the footer contaning total tax, price and total price after tax.
      void footer()const;
      // Sets the Bill to an emtpy state.
      void setEmpty();
      // Returns true is the Bill and all of its Items are valid.
      bool isValid()const;
   public:
      // // Initializes the Bill object with the provided title and number of items. If either argument is invalid, the Bill is set to an empty state. Otherwise, the function sets m_noOfItems to the provided value, resets m_itemsAdded to zero, copies the title into m_title, and allocates an array of Items with a length equal to m_noOfItems.
      void init(const char* title, int noOfItems);
      // If the number of added Items is less than the length of the m_items array, this function will set the next available subject to the incoming argument values. Then it will add one to the m_itemsAdded and return true;
      bool add(const char* item_name, double price, bool taxed);
      // Prints the title(), then it will loop through the m_items elements, printing every one of them, and finally prints the footer(). This function can not modify the Bill.
      void display()const;
      // Deallocates the m_items arrays and sets the pointers to null.
      void deallocate();
   };
}

#endif // !SENECA_TRANSCRIPT_H
