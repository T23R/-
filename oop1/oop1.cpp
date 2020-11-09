#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;

double In(const char* text)
{
	double res;
	cout << text;
	while (!(cin >> res) || cin.get() != '\n' || res <= 0)
	{
		cout << "Error, plese, enter normalnie values" << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
	return res;
}

class ZooStore
{
private:
	struct Animal
	{
		string kind;
		int number;
		double price;
	};
	string name;
	int arr;
	Animal* animals;
public:
	ZooStore()
	{
		name = ZooName();
		ArrSize();
		animals = new Animal[arr];
	}
	~ZooStore()
	{
		FileOut();
		delete[]animals;
	}
	void FileOut();
	string ZooName();
	int ArrSize();
	void AnimalKind(int i);
	void AnimalNumber(int i);
	void AnimalPrice(int i);
	void Cout();
	int getArrSize();
};

void ZooStore::FileOut()
{
	ofstream fout("file.txt", ios::out);
	cout << endl;
	fout << "\t";
	fout << "\n";
	fout.close();
}

string ZooStore::ZooName()
{
	cout << "Enter store name: ";
	cin >> name;
	return name;
}

int ZooStore::ArrSize()
{
	return arr = static_cast <int> (In("Enter the number of kinds: "));
}

int ZooStore::getArrSize()
{
	return arr;
}

void ZooStore::AnimalKind(int i)
{
	cout << "Enter the type of animal: ";
	cin >> animals[i].kind;
}

void ZooStore::AnimalNumber(int i)
{
	animals[i].number = static_cast <int> (In("Enter the number of animal: "));
}

void ZooStore::AnimalPrice(int i)
{
	animals[i].price = In("Enter the price of animal: ");
}

void ZooStore::Cout()
{
	cout << "\nName of store: " << name << "\n" << "\tNumber of kinds: " << arr << "\n";
	cout << "\tKinds of animals: ";
	for (int i = 0; i < arr; i++)
	{
		if (i < arr - 1)
			cout << animals[i].kind << ", ";
		else
			cout << animals[i].kind << "\n";
	}
	cout << "\tNumber of animals: ";
	for (int i = 0; i < arr; i++)
	{
		if (i < arr - 1)
			cout << animals[i].number << ", ";
		else
			cout << animals[i].number << "\n";
	}
	cout << "\tPrice of animals: ";
	for (int i = 0; i < arr; i++)
	{
		if (i < arr - 1)
			cout << animals[i].price << "$, ";
		else
			cout << animals[i].price << "$\n";
	}
}

int main()
{
	ZooStore Shop;
	for (int i = 0; i < Shop.getArrSize(); i++)
	{
		Shop.AnimalKind(i);
		Shop.AnimalNumber(i);
		Shop.AnimalPrice(i);
	}
	Shop.Cout();
	return 0;
}