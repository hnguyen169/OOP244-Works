//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/18/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H

namespace seneca {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif