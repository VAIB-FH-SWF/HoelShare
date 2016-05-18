/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Loesung der Aufgabe 6							 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 10.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "Vek3.h"
#include <cmath>
#include <iostream>
#include <assert.h>

using namespace std;

/**
 * Linearesgleichungssystem
 * @param s1
 * @param s2
 * @param s3
 * @param r
 * @return Lambda Vektor
 */
Vek3 lingl3(Vek3 s1, Vek3 s2, Vek3 s3, Vek3 r);

/**
 * Haupteinstiegspunkt
 * @return
 */
int main()
{
	// Werte definieren
	Vek3 p1(1, 1);
	Vek3 v1(2, 2);
	Vek3 p2(8);
	Vek3 v2(-1, 3);
	Vek3 v3(0, 0, 1);
	v2 = -v2;
	Vek3 r = p2 - p1;
	// Dauer berechnen
	Vek3 lambda = lingl3(v1, v2, v3, r);
	// Schnittpunkt berechnen
	Vek3 s = p1 + lambda.get_x() * v1;

	cout << "Schnittpunkt: " << s << endl;

	if (lambda.get_x() == lambda.get_y())
	{
		cout << "Die Schiffe treffen nach " << lambda.get_x() << "[h] ein!";
	}
	else
	{
		cout << "Das erste Schiff trifft nach " << lambda.get_x() << "[h] ein." << endl;
		cout << "Das zweite Schiff trifft nach " << lambda.get_y() << "[h] ein." << endl;
		cout << "Die Schiffe treffen sich nicht!";
	}

	return 0;
}

/**
 * Loesst das Lineare Gleichungssystem mit 3 unbekannten
 * @param s1
 * @param s2
 * @param s3
 * @param r
 * @return
 */
Vek3 lingl3(Vek3 s1, Vek3 s2, Vek3 s3, Vek3 r)
{
	double D0 = (s1 % s2) * s3;

	if (abs(D0) < 0.005)
	{
		assert(D0);
	}

	double D1 = (r % s2) * s3;
	double D2 = (s1 % r) * s3;
	double D3 = (s1 % s2) * r;

	double x1 = D1 / D0;
	double x2 = D2 / D0;
	double x3 = D3 / D0;

	return Vek3(x1, x2, x3);
}
