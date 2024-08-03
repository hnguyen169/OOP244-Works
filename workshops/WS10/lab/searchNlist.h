//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 08/01/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SEARCHNLIST_H
#define SEARCHNLIST_H

#include <iostream>
#include "Collection.h"

namespace seneca {

	// Function template for searching objects in an array and storing matches in a Collection
	template <typename T>
	bool search(Collection<T>& collection, const T* array, int arraySize, const typename T::KeyType& key) {
		bool found = false;
		collection.resize(0);

		for (int i = 0; i < arraySize; ++i) {
			if (array[i] == key) {
				collection.add(array[i]);
				found = true;
			}
		}
		return found;
	};

	// Function template for listing elements of an array
	template <typename T>
	void listArrayElements(const char* title, const T* array, int arraySize) {
		std::cout << title << std::endl;

		for (int i = 0; i < arraySize; ++i) {
			std::cout << (i + 1) << ": " << array[i] << std::endl;
		}
	};
}

#endif