#pragma once
#include "Repository.h"
#include <string>
#include<stack>
using namespace std;
/*
*	Controller class linking with repository and ui
*/


class Controller
{
private:
	Repository repo;

public:
	//Default constructor for class Controller
	Controller();

	//Destructor for class Controller
	~Controller();


	/*
	* Description: gets the list of vehicles
	* Returns a vector of vehicles
	*/
	vector<Vehicle*> getAll();

	/*Description: adds a vehicle in the list
	* Parameters: int - id(must be positive), string - brand, int price, int year(must be lower than 2021)
	*/
	void addVehicle(int id, string make, int price, int y);

	/*Description: adds a car in the list
	* Parameters: int - id(must be positive),string - make , string - brand, int price, int year(must be lower than 2021),string - fuel , float km
	*/
	void addCar(int id, string make, int price, int y, string fuel, float km);

	/*Description: adds a motorbike in the list
	* Parameters: int - id(must be positive),string - make , string - brand, int price, int year(must be lower than 2021),string - fuel , float km
	*/
	void addMotorbike(int id, string make, int price, int y, string fuel, float km);

	/*Description: adds a trailer in the list
	* Parameters: int - id(must be positive),string - make , string - brand, int price, int year(must be lower than 2021),string - fuel , float km
	*/
	void addTrailer(int id, string make, int price, int y, string country);

	/*
	* Description: deteles a vehicle by a given id
	* Parameters: int id(positive)
	*/
	void removeVehicleById(int  id);

	/*
	* Description: prints a list of vehicles by a given year
	* Parameters: int year(<2021)
	*/
	void getByYear(int year);

	/*
	* Description: prints a list of vehicles by a given brand
	* Parameters: string brand
	*/
	void getByBrand(string brand);

	//Description: saves the list of vehicles to a file
	void saveToFile();

	void saveToCSV();

	//Description: adds some vehicles from a file to the list of vehicles
	void addFromFile();

	/*
	* Description: edits a vehicle by brand
	* Changes the the brand, the price and the year
	*/
	void editByBrand(string brand, int year, int price);

	// Description: undo the last operation
	void undo();

	//Description: redo for the last operation
	void redo();
};

