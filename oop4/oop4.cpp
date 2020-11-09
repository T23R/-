#include <iostream>
#include <math.h>
using namespace std;
class City;
class vehicle;
class Airplane;
class Car;
class Train;
class City
{
	friend void TheBestOption(Airplane, Car, Train, City);
	double range;
	string name;
public:
	City()
	{
		cout << "Enter name of city: ";
		cin >> name;
		cout << "Enter the range: ";
		cin >> range;
	}
};
class vehicle
{
	friend void TheBestOption(Airplane, Car, Train, City);
protected:
	string VehicleName;
	double speed;
	double Cost;
	vehicle()
	{
		cout << "Enter speed: ";
		cin >> speed;
		cout << "Enter cost: ";
		cin >> Cost;
	}
	vehicle(bool forBestOption)
	{
		speed = 0;
		Cost = 0;
	}
	void ResOut()
	{
		cout << "Vehicle: " << VehicleName << ", speed = " << speed << endl;
	}
};
class Airplane final : public vehicle
{
	string CLASS;
public:
	friend void TheBestOption(Airplane, Car, Train, City);
	Airplane() : vehicle()
	{
		VehicleName = "Airplane";
		cout << "Enter class (buisness or econom): " << endl;
		cin >> CLASS;
	}
	Airplane(string CLASS) : vehicle()
	{
		VehicleName = "Airplane";
		this->CLASS = CLASS;
	}
	void ResOut()
	{
		vehicle::ResOut();
		cout << "class: " << CLASS << endl;
	}
};
class Car final : public vehicle
{
	int SitsNumber;
public:
	friend void TheBestOption(Airplane, Car, Train, City);
	Car() : vehicle()
	{
		VehicleName = "Car";
		cout << "Enter number of sits: " << endl;
		cin >> SitsNumber;
	}
	Car(int SitsNumber) : vehicle()
	{
		VehicleName = "Car";
		this->SitsNumber = SitsNumber;
	}
	void ResOut()
	{
		vehicle::ResOut();
		cout << "Number of sits: " << SitsNumber << endl;
	}
};
class Train final : public vehicle
{

	string carriage;
public:
	friend void TheBestOption(Airplane, Car, Train, City);
	Train() : vehicle()
	{
		VehicleName = "Train";
		cout << "Enter type of carriage(sitting, compartment, reserved seat): " << endl;
		cin >> carriage;
	}
	Train(string carriage) : vehicle()
	{
		VehicleName = "Train";
		this->carriage = carriage;
	}
	void ResOut()
	{
		vehicle::ResOut();
		cout << "type of carriage: " << carriage << endl;
	}
};
void TheBestOption(Airplane airplane, Car car, Train train, City city)
{
	vehicle result(true);
	result = airplane;
	double BestMoneyPerHour = airplane.Cost / (city.range / airplane.speed);
	if (car.Cost / (city.range / car.speed) < BestMoneyPerHour)
	{
		BestMoneyPerHour = car.Cost / (city.range / car.speed);
		result = car;
	}
	else if (train.Cost / (city.range / train.speed) < BestMoneyPerHour)
	{
		BestMoneyPerHour = train.Cost / (city.range / train.speed);
		result = train;
	}
	cout << "The best option: " << endl;
	result.ResOut();
	cout << "Ride time: " << city.range / result.speed << endl;
}
int main()
{
	char* locale = setlocale(LC_ALL, "");
	City city;
	cout << "Airplane: " << endl;
	Airplane airplane;
	cout << "Car: " << endl;
	Car car;
	cout << "Train: " << endl;
	Train train;
	TheBestOption(airplane, car, train, city);
	return 0;
}