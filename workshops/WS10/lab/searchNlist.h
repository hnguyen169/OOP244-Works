//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Completed: 08/03/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SEARCHNLIST_H
#define SEARCHNLIST_H

#include <iostream>
#include "Collection.h"

namespace seneca {

	/*
	 Function template for searching objects in an array and storing matches in a Collection.
	 
	 Template Type Requirements:
	 - T must support the equality operator (operator==) with type K.
	 - K can be any type that can be compared to type T using (operator==).
	 - Collection<T> must have resize(int) to set collection size.
	 - Collection<T> must have add(const T&) to add an element to the collection.

	 @param collection: Reference to a Collection of templated objects to store the matches.
	 @param array: Constant array of templated objects to search through.
	 @param arraySize: Number of elements in the array.
	 @param key: Key of templated type to search for in the array.
	 @return true if at least one match is found, false otherwise.
	 */
	template <typename T, typename K>
	bool search(Collection<T>& collection, const T* array, int arraySize, const K& key) {
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

	/*
	 Function template for listing elements of an array
	 
	 Template Type Requirements:
	 - T must support the insertion operator (operator<<) to be printed to an osteam.
	 
	 @param title: Constant char pointer for the title to be printed.
	 @param array: Constant array of templated objects to be listed.
	 @param arraySize: Number of elements in the array.
	 */
	template <typename T>
	void listArrayElements(const char* title, const T* array, int arraySize) {
		std::cout << title << std::endl;

		for (int i = 0; i < arraySize; ++i) {
			std::cout << (i + 1) << ": " << array[i] << std::endl;
		}
	};
}

#endif