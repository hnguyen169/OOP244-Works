//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 07/10/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

using namespace std;

namespace seneca {
	class Truck : public MotorVehicle {
		double maxWeight;
		double currentWeight;
	public:
		Truck(const char* license, unsigned int vyear, double maxw, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const Truck& tr);
	istream& operator>>(istream& in, Truck& tr);
}

#endif