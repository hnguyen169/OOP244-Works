//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 06/05/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H

#include <iostream>

namespace seneca {
   class Canister {
      char* m_contentName; // Points to a dynamically allocated Cstring.
      double m_diameter; // In centimeters.
      double m_height; // In centimeters.
      double m_contentVolume; // In CCs.
      bool m_usable; // Flag to identify if the Canister is usable or unusable.
      // Sets attributes to their default values.
      void setToDefault();
      // Returns true if content volume is less than 0.00001 CCs.
      bool isEmpty()const;
      // Compares the content name of this Canister with the one received from the argument C.
      bool hasSameContent(const Canister& C)const;
      // Sets the content name of the current Canister.
      void setName(const char* Cstr);
   public:
      // Sets the attributes to their default values.
      Canister();
      // Sets the attributes to their default values and name to the incoming contentName argument.
      Canister(const char* contentName);
      // Sets the attributes to their default values. Or m_height and m_diameter to incoming respective arguments, content volume to 0, and name to the incoming contentName argument.
      Canister(double height, double diameter, const char* contentName = nullptr);
      // Deallocates the dynamic memory pointed by the content name attribute.
      ~Canister();
      // Clears an unusable Canister back to an empty Canister.
      void clear();
      // Returns the capacity,
      double capacity()const;
      // Returns the content volume attribute.
      double volume()const;
      // Sets the Content name of the canister then returns the reference of the current object.
      Canister& setContent(const char* contentName);
      // Adds the quantity argument to the content volume of the Canister if it fits. Otherwise, renders the Canister unusable and returns the reference of the current object.
      Canister& pour(double quantity);
      // Pours the content of the Canister argument into the current Canister.
      Canister& pour(Canister&);
      // Prints all the number values with one digit after the decimal point.
      std::ostream& display()const;
   };
}

#endif // !SENECA_BOX_H
