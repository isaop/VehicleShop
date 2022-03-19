#pragma once
#include "Vehicle.h"
/*
*   Subclass of Vehicle
*/
class Car : public Vehicle
{
private:
	string fuel;
	float km;
public:
	/*Description: default constructor for class Car
	*/
	Car();

	//Description: constructor for class Car
	Car(int id, string brand, int price, int year, string fuel, float km);

	/*Description: destructor for class Car*/
	~Car();

	//getter for fuel
	string getFuel()const { return fuel; }

	//getter for km
	float getKm()const { return km; }

	/*Description: setter for class Car
	* Sets the fuel
	* Parameters: string f(fuel)*/
	void setFuel(string f);

	/*Description: setter for class Car
	* Sets the km
	* Parameters: float km*/
	void setKm(float km);

	// bool function that says if the vechicle is a car
	bool isCar()const { return true; }

	// bool function that says if the vechicle is a motorbike
	bool isMotorbike()const { return false; }

	// bool function that says if the vechicle is a trailer
	bool isTrailer()const { return false; }

	//Converts a car's description to string
	string toString();
};

