#include <iostream>
#include <math.h>
using namespace std;
class String
{
	friend int operator>(String, String);
	friend void ResOut(String);
	friend String operator+(String, String);
	string str;
	int length = 0;
public:
	String()
	{
		str = ' ';
		length = 0;
	}
	String(string s)
	{
		str = s;
		int i = 0;
		for (i = 0; str[i] != '\0'; i++);
		length = i;
	}
	String(const String& obj)
	{
		str = obj.str;
		length = obj.length;
	}
	String& operator=(string s)
	{
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);
		this->length = i;
		this->str = s;
		return *this;
	}
	String& operator+=(string s)
	{
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);
		this->length += i;
		this->str += s;
		return *this;
	}
	~String()
	{

	}
};
String operator+(String a, String b)
{
	String res;
	res.length = a.length + b.length;
	res.str = a.str + b.str;
	return res;
}
int operator>(String a, String b)
{
	int i = 0;
	for (i = 0; a.str[i] != '\0'; i++)
	{
		if (a.str[i] > b.str[i])
		{
			return 1;
		}
		else if (a.str[i] < b.str[i])
		{
			return 0;
		}
	}
	if (b.str[i] == '\0')
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void ResOut(String obj)
{
	cout << obj.str << " длина строки: " << obj.length << endl;
	return;
}
int main()
{
	char* locale = setlocale(LC_ALL, "");
	String obj1("Sas");
	obj1 = "Sas2";
	ResOut(obj1);
	obj1 += "3";
	ResOut(obj1);
	String obj2("Sas13");
	if (obj1 > obj2 == 1)
		cout << "obj1 > obj2" << endl;
	else if (obj1 > obj2 == 0)
		cout << "obj1 < obj2" << endl;
	else
		cout << "obj1 == obj2" << endl;
	String obj3;
	obj3 = obj1 + obj2;
	ResOut(obj3);
	return 0;
}