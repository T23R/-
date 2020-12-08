#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

class Car
{
public:
	string NameOfCar;

	virtual void ToStartTheCar()
	{
		cout << "Engine is running" << endl;
	}

	virtual void SwitchGears()
	{
		cout << "The clutch is squeezed out!" << endl;
	}
};

class SuspensionBracket : private Car
{
protected:
	string NameOfSuspensition;
};

class Transmition : public Car
{
protected:
	string NameOfTransmition;
	int CountOfGears;
	int NumberOfGear = 0;
	int t;
public:
	void SwitchGears() override
	{
		cout << " 1. Shift gear up" << endl << " 2. Shift gear down" << endl << " 3. Shift into reverse" << endl;
		cin >> t;
		if (t == 1)
		{
			cout << "The transmission switched" << NumberOfGear++ << endl;
		}
		else if (t == 2)
		{
			cout << "The transmission switched" << NumberOfGear-- << endl;
		}
		else if (t == 3)
		{
			cout << "Reverse gear is engaged" << endl;
			NumberOfGear = 0;
		}
		else
		{
			cout << "Try again" << endl;
			cin >> t;
		}
		cout << "Current gear is " << NumberOfGear << endl;

	}
};

class Engine : public Car
{
protected:
	int ValueOfEngine;
	int CountOfCylinder;
	int y;
public:
	void setNameAndEngine()
	{
		cout << "Enter Name of Car: ";
		cin >> NameOfCar;
		cout << "Enter Value of Engine: ";
		while (!(cin >> ValueOfEngine) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Try again!" << endl;
		}
		cout << "Enter Count of Cylinders: ";
		while (!(cin >> CountOfCylinder) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Try again!" << endl;
		}
	}
	void getNameAndEngine()
	{
		cout << "Name of car: " << NameOfCar << endl << "Value of Engine: " << ValueOfEngine << endl << "Count of Cylinders: " << CountOfCylinder << endl;
	}

	void ToStartTheCar() override
	{
		cout << " 1. To add engine speed" << endl << " 2. Reduce the engine speed" << endl;
		cin >> y;
		if (y == 1)
		{
			cout << "Engine speed added, it's time to shift up gear" << endl;
			return;
		}
		else if (y == 2)
		{
			cout << "Engine speed was reduced, it's time to shift down gear" << endl;
			return;
		}
		else
		{
			cout << "Try again!" << endl;
			cin >> y;
		}
	}
};

class Wheel : public Transmition, public Engine
{
protected:
	int SizeOfWheel;
public:
	void setTransmitionAndWheels()
	{
		cout << "Enter name of transmition: ";
		cin >> NameOfTransmition;
		cout << "Enter count of Gears: ";
		while (!(cin >> CountOfGears) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Try again!" << endl;
		}
		cout << "Enter size of wheel: ";
		while (!(cin >> SizeOfWheel) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Try again!" << endl;
		}

	}
	void getTransmitionAndWheels()
	{
		cout << "Name of Transmition: " << NameOfTransmition << endl << "Count of Gears: " << CountOfGears << endl << "Size of Wheels: " << SizeOfWheel << endl;
	}

	void  SwitchGears() override
	{
		if (NumberOfGear >= 0 && NumberOfGear <= 3)
		{
			cout << "Step on the gas son" << endl;
		}
		else if (NumberOfGear > 3 && NumberOfGear <= 5)
		{
			cout << "You're driver!" << endl;
		}
		else if (NumberOfGear >= 6)
		{
			cout << "Don't rush brother, mothers need us" << endl;
		}

	}
};

void  menu()
{
	bool f = false;
	int k, size;
	string name;
	cout << "How many cars do you want to enter?" << endl;
	cin >> size;
	Wheel* wheel = new Wheel[size];
	Car* car = new Car[size];
	Engine* engine = new Engine[size];
	Transmition* transmition = new Transmition[size];
	do
	{
		cout << " 1. Enter cars " << endl << " 2. View cars" << endl << " 3. No Joke" << endl << " 4. Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			for (int i = 0; i < size; i++)
			{
				wheel[i].setNameAndEngine();
				wheel[i].setTransmitionAndWheels();
				cout << endl;
			}
			Sleep(300);
			system("cls");
			break;
		case 2:

			for (int i = 0; i < size; i++)
			{
				wheel[i].getNameAndEngine();
				wheel[i].getTransmitionAndWheels();
				cout << endl;
			}
			Sleep(3000);
			system("cls");
			break;
		case 3:
			car->ToStartTheCar();
			engine->ToStartTheCar();
			car->SwitchGears();
			transmition->SwitchGears();
			Sleep(5000);
			system("cls");
			break;
		case 4:
			f = true;
			delete[]wheel;
			delete[]car;
			delete[]engine;
			delete[]transmition;
			break;
		default:
			cout << "Try again!" << endl;
			break;
		}
	} while (!f);
}

int main()
{
	menu();
}