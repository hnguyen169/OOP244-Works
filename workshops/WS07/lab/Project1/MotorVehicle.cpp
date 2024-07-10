//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 07/10/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>

namespace seneca {
	MotorVehicle::MotorVehicle(const char* license, unsigned int vyear) {
		strncpy(licensePlateNo, license, 9);
		licensePlateNo[9] = '\0';
		vehicleYear = vyear;
		strcpy(vehicleAddress, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strcmp(vehicleAddress, address) != 0) {
			cout << "|" 
				<< setw(8) 
				<< right
				<< licensePlateNo 
				<< "| |" 
				<< setw(20)
				<< right
				<< vehicleAddress 
				<< " ---> " 
				<< setw(20)
				<< left
				<< address 
				<< "|" 
				<< endl;
			strcpy(vehicleAddress, address);
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "| "
			<< vehicleYear
			<< " | "
			<< licensePlateNo
			<< " | "
			<< vehicleAddress;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> vehicleYear;
		in.ignore();

		cout << "License plate: ";
		in.getline(licensePlateNo, 10);

		cout << "Current location: ";
		in.getline(vehicleAddress, 64);

		return in;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& mv) {
		return mv.write(os);
	}

	istream& operator>>(istream& in, MotorVehicle& mv) {
		return mv.read(in);
	}
}