#include "Complex.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	try
	{
		Complex A;
		cin >> A;
		cout << A;

		cout << "Size of class: " << sizeof(A) << endl;

		Complex B(5, -7);
		cout << B << endl;

		cout << "Sum of complex numbers" << endl;
		Complex C = A + B;
		cout << "C = " << C << endl;

		cout << "Product of complex numbers" << endl;
		Complex D = A * B;
		cout << "D = " << D << endl;

		if (A == B)
			cout << "Complex numbers are equal" << endl;
		else
			cout << "Complex numbers are not equal" << endl;

		try
		{
			A++;
		}
		catch (MyException& a)
		{
			cerr << "Exception: " << a.What() << endl;
		}
		catch (MyException* a)
		{
			cerr << "Exception: " << a->What() << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Complex N;
		cin >> N;
		cout << N;

		try
		{
			N--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
}