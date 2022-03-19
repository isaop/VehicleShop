#include "Controller.h"
#include "Vehicle.h"
#include"Car.h"
#include"Motorbike.h"
#include"Trailer.h"
#include"InvalidIDExcept.h"
#include"InvalidYearExcept.h"
#include<iostream>
#include<fstream>
typedef Vehicle T;

using namespace std;
Controller::Controller()
{
}


Controller::~Controller()
{
}

std::vector<Vehicle*> Controller::getAll()
{
	return  this->repo.getData();
}



void Controller::addVehicle(int id, string brand, int price, int year)
{
	Vehicle* newVehicle = new Vehicle();
	if (id < 0)
		throw InvalidIDExcept();
	if (year > 2021)
		throw InvalidYearExcept();
	newVehicle->setId(id);
	newVehicle->setBrand(brand);
	newVehicle->setPrice(price);
	newVehicle->setYear(year);

	this->repo.add(newVehicle,0);

}

void Controller::addCar(int id, string make, int price, int year, string fuel, float km)
{
	Car* newCar = new Car();
	if (id < 0)
		throw InvalidIDExcept();
	if (year > 2020)
		throw InvalidYearExcept();
	newCar->setId(id);
	newCar->setBrand(make);
	newCar->setPrice(price);
	newCar->setYear(year);
	newCar->setFuel(fuel);
	newCar->setKm(km);

	this->repo.add(newCar,0);
}

void Controller::addMotorbike(int id, string make, int price, int y, string fuel, float km)
{
	if (id < 0)
		throw InvalidIDExcept();
	if (y > 2020)
		throw InvalidYearExcept();
	Motorbike* newMotorbike = new Motorbike();
	newMotorbike->setId(id);
	newMotorbike->setBrand(make);
	newMotorbike->setPrice(price);
	newMotorbike->setYear(y);
	newMotorbike->setFuel(fuel);
	newMotorbike->setKm(km);

	this->repo.add(newMotorbike,0);
}

void Controller::addTrailer(int id, string make, int price, int y, string country)
{
	if (id < 0)
		throw InvalidIDExcept();
	if (y > 2020)
		throw InvalidYearExcept();
	Trailer* newTrailer = new Trailer();
	newTrailer->setId(id);
	newTrailer->setBrand(make);
	newTrailer->setPrice(price);
	newTrailer->setYear(y);
	newTrailer->setCountry(country);

	this->repo.add(newTrailer,0);
}

void Controller::removeVehicleById(int id)
{
	this->repo.removeVehicleById(id,0);
}

void Controller::getByYear(int year)
{
	this->repo.getByYear(year);
}

void Controller::getByBrand(string brand)
{
	this->repo.getByBrand(brand);
}

void Controller::saveToFile()
{
	vector<Vehicle*> allVehicles = this->repo.getData();

	string fileName = "data.out.txt";

	ofstream out(fileName);

	for (Vehicle* veh : allVehicles) {
		string stringVehicle = veh->toString();
		out << stringVehicle;

	}cout << "Saved! " << endl;
}

void Controller::saveToCSV()
{
	std::string fileName = "dataout.csv";

	ofstream out(fileName);

	for (Vehicle* vehicle : this->repo.getData())
	{
		Vehicle* p = dynamic_cast<Vehicle*>(vehicle);
		if (p != nullptr)
		{
			out << "Vehicle" << "," << p->getId() << ", " << p->getBrand() << ", " << p->getPrice() << "," << p->getYear() << endl;
		}

		else {
			auto p = dynamic_cast<Car*>(vehicle);
			if (p != nullptr)
			{
				out << "Car" << "," << p->getId() << ", " << p->getBrand() << ", " << p->getPrice() << "," << p->getYear() << ", " << p->getFuel() << ", " << p->getKm() << endl;
			}
			else {
				auto p = dynamic_cast<Motorbike*>(vehicle);
				if (p != nullptr)
				{
					out << "Motorbike" << "," << p->getId() << ", " << p->getBrand() << ", " << p->getPrice() << "," << p->getYear() << ", " << p->getFuel() << ", " << p->getKm() << endl;
				}

				else
				{
					auto p = dynamic_cast<Trailer*>(vehicle);
					if (p != nullptr)
					{
						out << "Trailer" << "," << p->getId() << ", " << p->getBrand() << ", " << p->getPrice() << "," << p->getYear() << ", " << p->getCountry() << endl;

					}
				}
			}
		}


	}
}

void Controller::addFromFile()
{
	string fileName = "data.in.txt";
	ifstream in(fileName);
	std::string s;
	while (!in.eof())
	{
		string brandFromFile;
		int priceFromFile, yearFromFile, IDFromFile;
		in >> IDFromFile;
		in >> brandFromFile;
		in >> priceFromFile;
		in >> yearFromFile;

		Vehicle* veh = new Vehicle(IDFromFile, brandFromFile, priceFromFile, yearFromFile);
		this->repo.add(veh,0);

	}
}

void Controller::editByBrand(string brand, int price, int year)
{
	this->repo.editByBrand(brand, price, year);
}

void Controller::undo()
{
	this->repo.undo();
}

void Controller::redo()
{
	this->repo.redo();
}


