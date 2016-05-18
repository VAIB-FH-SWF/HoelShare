/*****************************************************************/
/*    Dateiname: TestClass.cpp										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 24.04.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "TestClass.h"
#include <iostream>

using namespace std;

TestClass::TestClass(int _value, string _name)
{
	cout << " ==== Konstruktor ( this = " << this << ")" << endl;

	this->value = _value;
	this->name = _name;
}

TestClass::TestClass(const TestClass &other)
{
	cout << " ==== Kopierkonstruktor ( this = " << this << " , " << &other << ")" << endl;

	this->value = other.value;
	this->name = other.name;
}

TestClass::~TestClass()
{
	cout << " ==== destruktor ( this = " << this << ")" << endl;
}

// ==================== ACCESSORS
void TestClass::print()
{
	cout << " ==== print ( this = " << this << ")" << endl;

	cout << this->name << " " << this->value << endl;
}

// ==================== MUTATORS
TestClass& TestClass::set_name(string _name)
{
	cout << " ==== set_name ( this = " << this << ")" << endl;

	this->name = _name;

	return *this;
}

TestClass& TestClass::set_value(int _value)
{
	cout << " ==== set_value ( this = " << this << ")" << endl;


	this->value = _value;

	return *this;
}

// ==================== OPERATORS
TestClass& TestClass::operator =(const TestClass &other)
{
	cout << " ==== operator= ( this = " << this << " , other = " << &other << ")" << endl;

	if (this != &other)
	{
		this->name = other.name;
		this->value = other.value;
	}

	return *this;
}

TestClass TestClass::operator +(const TestClass &other)
{
	cout << " ==== operator+ ( this = " << this << " , other = " << &other << ")" << endl;

	int addition = this->value + other.value;

	return TestClass(addition);
}
