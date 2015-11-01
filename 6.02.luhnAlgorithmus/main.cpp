//==========================================================
//
//	  Filename:	main.cpp
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	27.10.2015 18:29:00
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Berechnet die Quersumme der Zahl
 */
int quersumme(int zahl)
{
    int summe = 0;
    while (zahl > 0)
    {
        summe += zahl % 10;
        zahl /= 10;
    }
    return (summe);
}

/**
 * Berechnet die Pruefsumme der Zahl
 * Beginnend bei der Einerziffer werden die Ziffern abwechselnd mit 1 bzw. 2 gewichtet
 * Von diesen gewichteten Zahlen wird die Quersumme aufaddiert und bildet damit die Prüfsumme
 */
int berechnePruefsumme (string zahl)
{
   int summe = 0;
   for (unsigned int i = 0; i < zahl.length(); i++)
   {
      summe += quersumme(
            (zahl[zahl.length() - (i + 1)] - '0') * (i % 2 == 0 ? 1 : 2));
   }
   return (summe);
}

/**
 * Der Luhn check ist erfuellt, wenn die Pruefsumme auf 0 endet
 */
bool luhn_check(string number)
{
   // Ist die Zahl glatt durch 10 Teilbar, endet diese auf 0
    return (berechnePruefsumme(number) % 10 == 0);
}

// Haupteinstiegspunkt des Programms
int main()
{
    cout << boolalpha;          // Bools als TRUE bzw. FALSE ausgeben
    cout << "Pruefe Kreditkartennummern:" << endl;
    // Die Prüfungen durchfuehren
    cout << "       446667651: " << luhn_check("446667651") << endl;
    cout << "     49927398716: " << luhn_check("49927398716") << endl;
    cout << "     49927398717: " << luhn_check("49927398717") << endl;
    cout << "1234567812345678: " << luhn_check("1234567812345678") << endl;
    cout << "1234567812345670: " << luhn_check("1234567812345670") << endl;
}

