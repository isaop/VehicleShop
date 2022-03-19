#include "Car.h"

Car::Car() : Vehicle()
{
	this->fuel = " ";
	this->km = 0;
}

Car::Car(int id, string brand, int price, int year, string fuel, float km) :Vehicle(id, brand, price, year)
{
	this->fuel = fuel;
	this->km = km;
}

Car::~Car()
{
	
}

void Car::setFuel(string f)
{
	this->fuel = f;
}

void Car::setKm(float km)
{
	this->km = km;
}

string Car::toString()
{
	return Vehicle::toString() + "    --> It's a Car with km: " + to_string(this->km).substr(0, to_string(this->km).find('.')+3) + " and fuel: " + this->fuel + "\n";
}
