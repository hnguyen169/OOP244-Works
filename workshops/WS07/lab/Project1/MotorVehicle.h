//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 07/10/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>

using namespace std;

namespace seneca {
	class Truck;

	class MotorVehicle {
		char licensePlateNo[10];
		char vehicleAddress[65];
		unsigned int vehicleYear;
	public:
		MotorVehicle(const char* license, unsigned int vyear);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in);

		friend class Truck;
	};
	ostream& operator<<(ostream& os, const MotorVehicle& mv);
	istream& operator>>(istream& in, MotorVehicle& mv);
}

#endif