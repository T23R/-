/*Создать базовый класс «печатная продукция», включающий тип и
название печатной продукции, количество страниц, издательство, данные об
авторе (тип данных строка). Разработать набор дочерних классов для класса
«Печатная продукция». Реализовать класс «Отдел», включающий в себя
название отдела, тип производимых печатных изданий, массив фактически
произведенных печатных изданий. Написать программу, позволяющую
добавлять и удалять печатные издания разных видов в/из отдела.
Использовать конструктор с параметрами, конструктор без параметров,
конструктор копирования. В класс добавить необходимый набор полей и
методов (минимум два поля и два метода) на свое усмотрение.
Предусмотреть метод для записи полученных данных в файл. */

#include <functional>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Publication
{
protected:
    string NameOfProduction;
    string TypeOfProduction;
    int NumberOfPages;
    string PublishingHouse;
    string Author;
public:
    Publication()
    {
        NameOfProduction = "Unity+C#";
        TypeOfProduction = "Бумажная книга";
        NumberOfPages = 600;
        PublishingHouse = "Питер";
        Author = "Джесси Шелл";
    }
    string getName()
    {
        string NameOfProd;
        cout << "Введите название публикации: ";
        cin >> NameOfProd;
        return NameOfProd;
    }
    void setName(string NameOfProduction)
    {
        this->NameOfProduction = NameOfProduction;
    }
    string getTypeOfProduction()
    {
        string TypeOfProd;
        cout << "Введите тип продукции: ";
        cin >> TypeOfProd;
        return  TypeOfProd;
    }
    void setTypeOfProduction(string p)
    {
        this->TypeOfProduction = p;
    }
    int getNumberOfPages()
    {
        int NumberOfPage;
        cout << "Введите кол-во страниц: ";
        cin >> NumberOfPage;
        return NumberOfPage;
    }
    void setNumberOfPages(int NumberOfPage)
    {
        this->NumberOfPages = NumberOfPage;
    }
    string getPublishingHouse()
    {
        string PublishingHouse;
        cout << "Введите издательство: ";
        cin >> PublishingHouse;
        return PublishingHouse;
    }
    void setPublishingHouse(string PublishingHouse)
    {
        this->PublishingHouse = PublishingHouse;
    }
    string getAuthor()
    {
        string Author;
        cout << "Введите автора: ";
        cin >> Author;
        return Author;
    }
    void setAuthor(string Author)
    {
        this->Author = Author;
    }
    virtual void Slogan()
    {
        cout << "We are the best!!! We are better!!!" << endl;
    }
};
class Department : public Publication
{
    friend void Del(Department*, int&);
    friend void MaxPages(Department[], int count);
protected:
    string NameOfDepartment;
    string* development;
public:
    Department()
    {
        NameOfDepartment = "Жёсткий";
        int Size;
        cout << "Введите количество публикаций, которые в разработке: ";
        cin >> Size;
        if (cin.fail() || Size <= 0)
        {
            cout << "Ошибка" << endl;
            exit(0);
        }
        else
            development = new string[Size];
        for (int i = 0; i < Size; i++)
        {
            development[i] = "GOLF";
        }
    }
    string getNameOfDepart()
    {
        string NameOfDep;
        cout << "Введиите название отдела: ";
        cin >> NameOfDep;
        return  NameOfDep;
    }
    void setNameOfDepart(string NameOfDep)
    {
        this->NameOfDepartment = NameOfDep;
    }
    string getArr()
    {

        int Size = 0;
        cout << "Введите количество публикация в разработке: ";
        cin >> Size;
        while (Size != 0)
        {
            cout << "Введите публикации, которые находятся в разработке: ";
            string* arr = new string[Size];
            for (int i = 0; i < Size; i++)
            {
                cin >> arr[i];
                cout << endl;
            }
            return *arr;
        }
    }
    void setArr(string* Development)
    {
        this->development = Development;
    }
    void View(Department publication[], int count)
    {
        cout << "Название продукта: " << NameOfProduction;
        cout << endl;
        cout << "Тип продукта: " << TypeOfProduction;
        cout << endl;
        cout << "Количество страниц продукта: " << NumberOfPages;
        cout << endl;
        cout << "Издательство: " << PublishingHouse;
        cout << endl;
        cout << "Автор: " << Author;
        cout << endl;
        cout << "Название отдела: " << NameOfDepartment;
        cout << endl;
        cout << "Книги в разработке: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << *(publication[i].development) << endl;
        }
        cout << endl;

    }
    void Slogan() override
    {
        cout << "We are from FITM!!!" << endl;
    }
    void fileWrite(Department publication[], int Size, string filename)
    {
        ofstream fout;
        fout.open(filename, ios::app);
        if (!fout.is_open())
        {
            cout << "Ошибка, файл не открыт\n";
            return;
        }
        else
        {
            fout << "Название продукта: " << NameOfProduction;
            fout << endl;
            fout << "Тип продукта: " << TypeOfProduction;
            fout << endl;
            fout << "Количество страниц продукта: " << NumberOfPages;
            fout << endl;
            fout << "Издательство: " << PublishingHouse;
            fout << endl;
            fout << "Автор" << Author;
            fout << endl;
            fout << "Название отдела" << NameOfDepartment;
            fout << endl;
            fout << "Книги в разработке : " << endl;
            for (int i = 0; i < Size; i++)
            {
                cout << publication[i].development << endl;
            }
            cout << endl;
        }
        fout.close();
    }
};
void MaxPages(Department publication[], int count)
{
    int MaxPages = publication[0].NumberOfPages;
    for (int i = 0; i < count; i++)
    {

        if (publication[i].NumberOfPages > MaxPages)
        {
            MaxPages = publication[i].NumberOfPages;
        }
    }
    cout << "Максимальная количество страниц: " << MaxPages << endl;
}
void Del(Department* obj, int& NumberOfPublications)
{
    string nameForDel;
    cout << "Введите название публикации, которую хотите удалить : ";
    cin >> nameForDel;
    for (int i = 0; i < NumberOfPublications; i++)
    {
        if (obj[i].NameOfProduction == nameForDel)
        {
            for (int j = i; i < NumberOfPublications - 1; i++)
            {
                obj[j] = obj[j + 1];
            }
            NumberOfPublications--;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите имя файла" << endl;
    ifstream fin;
    string text;
    ofstream fout;
    string filename;
    cin >> filename;
    int ChooseDefaultINT;

    while (true)
    {
        ofstream file(filename, ios::trunc);
        int numberOfPublication = 0;
        cout << "Сколько печатных центров хотите проверить?" << endl;
        cout << "Количество : ";
        cin >> numberOfPublication;
        if (cin.fail() || numberOfPublication <= 0)
        {
            exit(0);
        }
        Department* publication = new Department[numberOfPublication];
        {
            bool ChooseDefault = false;
            int choice;
            while (true)
            {
                if (ChooseDefault == true)
                {
                    break;
                }
                cout << "Сделайте выбор\n" << "1 - Заполнить информацию о печатном центре\n" << "2 - Показать информацию\n" << "3 - Найти самую большую публикацию\n" << "4 - Записать публикации в файл\n" << "5 - Cчитать с файла\n" << "6 - Удаление информации о печатном центре\n" << "7 - Выкинуть слоган\n" << "Another - Exit\n\n";
                cin >> choice;
                if (cin.fail())
                {
                    cout << "Ошибка ввода" << endl;
                    exit(0);
                }
                switch (choice)
                {
                case 1:
                {
                    for (int i = 0; i < numberOfPublication; i++)
                    {
                        cout << "Печатный центр № " << i + 1 << endl;
                        string Name = publication[i].getName();
                        publication[i].setName(Name);
                        string TypeOfProduction = publication[i].getTypeOfProduction();
                        publication[i].setTypeOfProduction(TypeOfProduction);
                        int Pages = publication[i].getNumberOfPages();
                        publication[i].setNumberOfPages(Pages);
                        string PublishingHouse = publication[i].getPublishingHouse();
                        publication[i].setPublishingHouse(PublishingHouse);
                        string Author = publication[i].getAuthor();
                        publication[i].setAuthor(Author);
                        string NameOfDepartment = publication[i].getNameOfDepart();
                        publication[i].setNameOfDepart(NameOfDepartment);
                        string InDev = publication[i].getArr();
                        publication[i].setArr(&InDev);
                        cout << endl;
                    }
                    break;
                }
                case 2:
                    cout << endl;
                    for (int i = 0; i < numberOfPublication; i++)
                    {
                        cout << "Печатный центр № " << i + 1 << endl;
                        publication[i].View(publication, numberOfPublication);
                    }
                    break;
                case 3:
                    MaxPages(publication, numberOfPublication);
                    break;
                case 4:
                    cout << "Введите имя файла" << endl;
                    cin >> filename;
                    file.close();
                    for (int i = 0; i < numberOfPublication; i++)
                    {
                        publication[i].fileWrite(publication, numberOfPublication, filename);
                    }
                    break;
                case 5:
                    fout.open(filename, ios::app);
                    if (fout.is_open())
                    {
                        while (getline(fin, text))
                        {
                            cout << text << endl;
                        }
                        fin.close();
                    }
                    else
                    {
                        cout << "Файл не может быть открыт" << endl;
                    }
                    break;
                case 6:
                {
                    Del(publication, numberOfPublication);
                    break;
                }
                case 7:
                {
                    int choose;
                    cout << "Какой Лозунг вы хотите услышать?\n1 - Компании\n2 - Отдела\nAnother - Выход" << endl;
                    cin >> choose;
                    if (choose == 1)
                    {
                        Publication obj;
                        Publication* forSloganP = &obj;
                        forSloganP->Slogan();
                    }
                    else if (choose == 2)
                    {
                        Department* forSloganD = publication;
                        forSloganD->Slogan();
                    }
                    break;
                }
                default:
                    cout << "Посмотреть новые печатные центры? 1-da Another-net" << endl;
                    cin >> ChooseDefaultINT;
                    if (ChooseDefaultINT == 1)
                    {
                        ChooseDefault = true;
                        break;
                    }
                    else
                    {
                        exit(0);
                    }
                }
            }
        }
    }
}