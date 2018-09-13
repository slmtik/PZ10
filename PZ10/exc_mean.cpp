#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "exc_mean.h"

//1. throw - является оператором генерации исключений, выполнение кода будет прекращено и произойдет переход в первый блок catch.
//return -оператор окончания функции, выполнение кода тоже будет прекращено и произойдет переход к месту вызова функции
//
//2. блоки catch должны быть расположены в порядке от дочерних до родительского класса исключений, иначе будет всегда срабатывать логика родительского класса, так как под ее условия попадают все дочерние.


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	//3.
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try { // start of try block
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " <<
				y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " <<
				y
				<< " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (bad_hmean & e) // start of catch block
		{
			cout << e.what();
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean & e)
		{
			cout << e.what();
			cout << "Sorry, you don't get to play anymore.\n";
			break;
		} // end of catch block
	}

	//4.
	cout << "Let's try again" << endl;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try { // start of try block
			z = hmean2(x, y);
			cout << "Harmonic mean of " << x << " and " <<
				y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " <<
				y
				<< " is " << gmean2(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (my_bad_base & e)
		{
			e.msg();
			cout << "Sorry, you don't get to play anymore.\n";
			break;
		} // end of catch block
	}
	cout << "Bye!\n";
	// cin.get();
	// cin.get();
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean();
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean();
	return std::sqrt(a * b);
}
double hmean2(double a, double b)
{
	if (a == -b)
		throw my_bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean2(double a, double b)
{
	if (a < 0 || b < 0)
		throw my_bad_gmean(a, b);
	return std::sqrt(a * b);
}

void my_bad_hmean::msg()
{
	std::cout << my_bad_base::what();
	std::cout << "hmean() argument a(" << my_bad_hmean::a << ") should not be equal to -b(" << my_bad_hmean::b << ")\n";
};

void my_bad_gmean::msg()
{
	std::cout << my_bad_base::what();
	std::cout << "gmean() arguments should be >= 0 (";
	if (my_bad_gmean::a < 0 && my_bad_gmean::b < 0)
		std::cout << "a is " << my_bad_gmean::a << ", b is " << my_bad_gmean::b;
	else if (my_bad_gmean::a < 0)
		std::cout << "a is " << my_bad_gmean::a;
	else if (my_bad_gmean::b < 0)
		std::cout << "b is " << my_bad_gmean::b;
	std::cout << ")\n";
};