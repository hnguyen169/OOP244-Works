/* Citation and Sources...
Final Project Milestone 3
Module: Lib
Filename: Lib.h
Version 1.0
Author:	Harrison Nguyen
Email: hnguyen169@myseneca.ca
ID: 167096239
Date Completed: 07/27/2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_LIB_H
#define SENECA_LIB_H

namespace seneca {
    const int SENECA_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SENECA_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SENECA_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SENECA_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SENECA_LIBRARY_CAPACITY = 5000;
    // Maximum number of publications the library can hold.
}

#endif