#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;

template <class Item>
struct Status
{
	Item* ptr;
	int counter;
};
template <class Item>
class SmartPointer
{
	Status<Item>* smartPtr;
public:
	SmartPointer(Item* ptr)
	{
		if (!ptr)
		{
			smartPtr = nullptr;
		}
		else
		{
			smartPtr = new Status<Item>;
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;
		}
	}
	SmartPointer(const SmartPointer& smartPtr)
	{
		this->smartPtr = smartPtr.smartPtr;
		this->smartPtr->counter++;
	}
	~SmartPointer()
	{
		if (smartPtr)
		{
			smartPtr->counter--;
			if (smartPtr->counter <= 0)
			{
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointer& operator=(const SmartPointer& smartPtr)
	{
		if (this->smartPtr)
		{
			this->smartPtr->counter--;
			if (this->smartPtr->counter <= 0)
			{
				delete this->smartPtr->ptr;
				delete this->smartPtr;
			}
		}
		this->smartPtr = smartPtr.smartPtr;
		if (this->smartPtr)
		{
			this->smartPtr->counter++;
		}
		return *this;
	}
	Item* operator->()
	{
		if (smartPtr)
		{
			return smartPtr->ptr;
		}
		else
		{
			return NULL;
		}
	}
	int getCounter()
	{
		return smartPtr->counter;
	}
};

class Command
{
public:
	virtual bool execute() = 0;
	virtual void undo() {}
};

class History
{
public:
	int i;
	vector<SmartPointer<Command>> history;
	History()
	{
		i = 0;
	}
	void push(Command* command)
	{
		if (i != history.size())
		{
			history.erase(history.begin() + i, history.end());
		}
		if (history.size() > 10)
		{
			history.erase(history.begin());
			i--;
		}
		history.push_back(SmartPointer<Command>(command));
		i++;
	}
	void pop()
	{
		i--;
	}
};

class Manager
{
	History history;
public:
	vector<string> text;
	bool execute(Command* command);
	History* getHistory()
	{
		return &history;
	}
	friend ostream& operator<< (ostream& out, Manager manager)
	{
		for (string str : manager.text)
		{
			out << str;
		}
		return out;
	}
};

class Undo : public Command
{
	Manager* manager;
public:
	Undo(Manager* manager) : Command()
	{
		this->manager = manager;
	}
	bool execute()
	{
		History* history = manager->getHistory();
		if (!history->history.empty() && (history->i > 0))
		{
			history->history.at(--history->i)->undo();
		}
		return false;
	}
};

class Redo : public Command
{
	Manager* manager;
public:
	Redo(Manager* manager) : Command()
	{
		this->manager = manager;
	}
	bool execute()
	{
		History* history = manager->getHistory();
		if (!history->history.empty() && (history->i < history->history.size()))
		{
			history->history.at(history->i++)->execute();
		}
		return false;
	}
};

void header()
{
	cout << "Press Shift+Esc to Exit. You will Exit after finishing current input" << endl;
	cout << "--------------------------------------------------------------------" << endl;
}
class Input : public Command
{
	string input;
	vector<string> backup;
	Manager* manager;
public:
	Input(Manager* manager) : Command()
	{
		this->manager = manager;
	}
	bool execute()
	{
		if (!input.empty())
		{
			cout << input;
			return false;
		}
		this->saveBackup();
		for (int i = 0; i < 5; i++)
		{
			char temp = _getch();
			if (GetAsyncKeyState(0x5A) && GetAsyncKeyState(VK_CONTROL)) //ctrl+z
			{
				manager->text.push_back(input);
				manager->execute(new Undo(manager));
				return false;
			}
			else if (GetAsyncKeyState(0x59) && GetAsyncKeyState(VK_CONTROL)) //ctrl+y
			{
				manager->text.push_back(input);
				manager->execute(new Redo(manager));
				return false;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				cout << '\n';
				input.push_back('\n');
				break;
			}
			else
			{
				cout << temp;
				input.push_back(temp);
			}
		}
		manager->text.push_back(input);
		return true;
	}
	void undo()
	{
		manager->text = this->backup;
		system("cls");
		header();
		cout << *manager;
	}
	void saveBackup()
	{
		backup = manager->text;
	}
};

bool Manager::execute(Command* command)
{
	if (command->execute() && dynamic_cast<Input*>(command))
	{
		history.push(command);
	}
	if (GetAsyncKeyState(VK_ESCAPE) && GetAsyncKeyState(VK_SHIFT))
	{
		return false;
	}
	return true;
}


int main()
{
	Manager manager;
	string fileName;
	cout << "Enter output file name: ";
	cin >> fileName;
	fileName = fileName + ".txt";
	ofstream fout(fileName);
	while (!fout.is_open())
	{
		system("cls");
		cout << "Invalid output file name, please, try again: ";
		cin >> fileName;
		fileName = fileName + ".txt";
	}
	system("cls");
	header();
	while (manager.execute(new Input(&manager))) {}
	system("cls");
	cout << "Your text will be saved in file " << fileName << endl;
	fout << manager;
	fout.close();
}