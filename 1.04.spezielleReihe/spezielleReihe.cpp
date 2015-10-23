//==========================================================
//
//	  Filename:	spezielleReihe.cpp
//
// Description: Die Datei spiegelt die Loesung der Aufgabe
//                          1.04 wider, spezielle Reihen.
//
//	   Version:	1.0
// 	   Created:	04.10.2015 17:41:31
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//----------------------------------------------------------
//  Hauptprogramm
//----------------------------------------------------------
int
main ()
{
   cout << "Praktikum 'Programmierung mit C++ 1' / Blatt 1 / Aufgabe 1.4\n";
   cout << "Reihensummen spezieller Funktionen\n\n";

   int n;                                   // Anzahl der Summanden
   long summe;                              // Reihensumme (Ergebnis)
   long summand;
   int vz;                                  // Hilfsvariable für das Vorzeichen
   //--------------------------------------------------------
   //  Summation der Exponentialfunktion
   //--------------------------------------------------------
   summe = 0.0;
   summand = 0;
   vz = -1;
   for(n = 1; n <= 10; n++)
   {
      summand = (2 * n - 1) * (2 * n + 1);
      vz = -vz;
      summe += vz * summand;
   }
   /*
    * Da n noch um 1 erhoeht wird, wenn die Bedingung nicht mehr erfuellt ist,
    * muss 1 abgezogen werden für die korrekte Anzahl
    */
   n -= 1;
   cout << "Summe der Speziellen Reihe von 1..." << n << ": ";
   cout << fixed << left << summe << endl;

   return 0;
}
