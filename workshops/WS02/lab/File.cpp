//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/25/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* arr) {
        if (fscanf(fptr, "%[^\n]\n", arr) == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool read(int& empNo) {
        if (fscanf(fptr, "%d,", &empNo) == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool read(double& salary) {
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}