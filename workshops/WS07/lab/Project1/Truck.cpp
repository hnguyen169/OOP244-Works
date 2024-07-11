//Name: Harrison Nguyen
//Email: hnguyen169@myseneca.ca
//ID: 167096239
//Date Compeleted: 07/11/2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Truck.h"
#include <iomanip>

namespace seneca {
	Truck::Truck(const char* license, unsigned int vyear, double maxw, const char* address)
        : MotorVehicle(license, vyear), maxWeight(maxw), currentWeight(0) {
        moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		if (currentWeight < maxWeight) {
			if (cargo <= (maxWeight - currentWeight)) {
				currentWeight += cargo;
				return true;
			}
			else {
				currentWeight = maxWeight;
				return true;
			}
		}
		else {
			return false;
		}
	}

	bool Truck::unloadCargo() {
		if (currentWeight == 0) {
			return false;
		}
		else {
			currentWeight = 0;
			return true;
		}
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os);
		os << " | "
			<< currentWeight
			<< "/"
			<< maxWeight;
		return os;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);

		cout << "Capacity: ";
		in >> maxWeight;
		in.ignore();

		cout << "Cargo: ";
		in >> currentWeight;
		in.ignore();

		return in;
	}

	ostream& operator<<(ostream& os, const Truck& tr) {
		return tr.write(os);
	}

	istream& operator>>(istream& in, Truck& tr) {
		return tr.read(in);
	}
}