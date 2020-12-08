/*Разработать шаблонный класс «Квадратное уравнение», где имеется следующие поля: коэффициенты,
дискриминант, корни. Предусмотреть наличие в классе методов вывода на экран уравнения, нахождения
максимума и среднего значения элементов. Перегрузить операторы, *= (каждый коэффициент умножить на число).*/
#include <iostream>

using namespace std;

template <class Ttype>
class quadraticEquation
{
	Ttype a, b, c;
	double d, x1, x2;
public:
	quadraticEquation()
	{
		a = b = c = d = x1 = x2 = 0;
	}
	quadraticEquation(Ttype a, Ttype b, Ttype c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		d = (double)b * b - (double)4 * a * c;
		if (d < 0)
		{
			x1 = x2 = 0;
		}
		else if (d == 0)
		{
			x1 = (double)-b / 2 * a;
		}
		else
		{
			x1 = (double)(-b + sqrt(d)) / 2 * a;
			x2 = (double)(-b - sqrt(d)) / 2 * a;
		}
	}
	quadraticEquation(const quadraticEquation& other)
	{
		this->a = other.a;
		this->b = other.b;
		this->c = other.c;
		this->d = other.d;
		this->x1 = other.x1;
		this->x2 = other.x2;
	}

	void ShowAnswers()
	{
		//TODO коэффициенты равные 1 не выводить (кроме с)
		cout << a << "X^2" << ((b > 0) ? " + " : " - ")
			<< fabs(b) << "X" << ((c > 0) ? " + " : " - ")
			<< fabs(c) << " = 0" << endl;

		if (d > 0)
			cout << "D = " << d << ", X1 = " << x1 << ", X2 = " << x2 << endl << endl;
		else if (d == 0)
			cout << "D = " << d << ", X = " << x1 << endl << endl;
		else
			cout << "D = " << d << endl << endl;
	}
	void ReCalculate()
	{
		d = (double)b * b - (double)4 * a * c;
		if (d < 0)
		{
			x1 = x2 = 0;
		}
		else if (d == 0)
		{
			x1 = (double)-b / 2 * a;
		}
		else
		{
			x1 = (double)(-b + sqrt(d)) / 2 * a;
			x2 = (double)(-b - sqrt(d)) / 2 * a;
		}
	}

	quadraticEquation operator=(quadraticEquation other)
	{
		quadraticEquation obj(other.a, other.b, other.c);
		this->ReCalculate();
		return obj;
	}
	quadraticEquation operator+(quadraticEquation other)
	{
		quadraticEquation obj(other.a + this->a, other.b + this->b, other.c + this->c);
		this->ReCalculate();
		return obj;
	}
	quadraticEquation operator+=(quadraticEquation other)
	{
		this->a += other.a;
		this->b += other.b;
		this->c += other.c;
		this->ReCalculate();
		return *this;
	}
	quadraticEquation operator+=(double k)
	{
		this->a += k;
		this->b += k;
		this->c += k;
		this->ReCalculate();
		return *this;
	}
	quadraticEquation operator*=(double k)
	{
		this->a *= k;
		this->b *= k;
		this->c *= k;
		this->ReCalculate();
		return *this;
	}
};

int main()
{
	quadraticEquation <int> a(1, 8, 1);
	a.ShowAnswers();
	a *= 2;
	a.ShowAnswers();
	a += 3;
	a.ShowAnswers();
	return 0;
}