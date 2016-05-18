/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 24.04.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "TestClass.h"
#include <iostream>

using namespace std;

TestClass f(TestClass arg); // prototyp function f
TestClass g(TestClass *arg); // prototyp function g

int main()
{
	// Vereinbarungen
	cout  << "\n  ########## TestClass x1(11, \"x1\")     ########## \n\n";
	TestClass x1(11, "x1");
	x1.print();
	cout  << "\n  ########## TestClass x2 = x1          ########## \n\n";
	TestClass x2 = x1;
	x2.print();
	cout  << "\n  ########## TestClass x3(33, \"x\")     ########## \n\n";
	TestClass x3(33, "x3");
	x3.print();
	cout  << "\n  ########## x2.set_name(\"x2\")         ########## \n\n";
	x2.set_name("x2");
	x2.print();
	// Einfache Zuweisung
	cout  << "\n  ########## x2 = x1                   ########## \n\n";
	x2 = x1;
	x2.print();

	// Addition mit Konstante
	cout  << "\n  ########## TestClass add = x1 + 4    ########## \n\n";
	TestClass add = x1 + 4;
	add.print();

	// Addition
	cout  << "\n  ########## TestClass add2 = x1 + x3  ########## \n\n";
	TestClass add2 = x1 + x3;
	add2.print();

	cout  << "\n  ########## x3 = f(x2)                ########## \n\n";
	x3 = f(x2);
	x3.print();

	// Funktionsaufruf in einer Addition
	cout  << "\n  ########## x3 = x1 + f(x2)           ########## \n\n";
	x3 = x1 + f(x2);
	x3.print();
	cout  << "\n  ########## x3 = x1 + g(&x2)          ########## \n\n";
	x3 = x1 + g(&x2);
	x3.print();
	// Zuweisung einer int-Konstanten
	cout  << "\n  ########## x3 = 234                  ########## \n\n";
	x3 = 234;
	x3.print();

	// Verwenden der Methode set
	cout  << "\n  ########## x3.set_value(333)         ########## \n\n";
	x3.set_value(333);
	x3.print();


	return 0;
}

TestClass f(TestClass arg)
{
	return arg;
}

TestClass g(TestClass* arg)
{
	return *arg;
}

