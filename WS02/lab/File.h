//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 05/25/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {
	// opens the data file for reading.
	bool openFile(const char filename[]);

	// closes the data file.
	void closeFile();

	// reads each line and returns an integer that is the number of records in the file.
	int noOfRecords();

	// reads the employee name from the file and returns true or false.
	bool read(char* arr);

	// reads the employee number from the file and returns true or false.
	bool read(int& empNo);

	// reads the employee salary from the file and returns true of false.
	bool read(double& salary);
}

#endif // !SENECA_FILE_H_