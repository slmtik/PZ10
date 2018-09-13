#include <iostream>
#include <string>
class bad_hmean : public std::logic_error
{

public:
	bad_hmean() : std::logic_error("hmean() argument a should not be equal to -b\n") {}};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean() : std::logic_error("gmean() arguments should be >= 0\n") {}
};

class my_bad_base : public std::logic_error
{
protected:
	double a, b;
protected:
	my_bad_base(double a = 0, double b = 0) : logic_error("bad argument(s)\n"), a(a), b(b)   {}
public:
	virtual void msg() = 0;
};

class my_bad_hmean : public my_bad_base
{
public:
	my_bad_hmean(double a, double b) : my_bad_base(a, b) {}
	void msg();
};

class my_bad_gmean : public my_bad_base
{
public:
	my_bad_gmean(double a, double b) : my_bad_base(a, b) {}
	void msg();
};

double hmean(double a, double b);
double gmean(double a, double b);
double hmean2(double a, double b);
double gmean2(double a, double b);