//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung zu Aufgabe 3.3
//
//	   Version:	1.0
// 	   Created:	25.10.2015 13:28:46
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main ( )
{
   int aFaktor = 16333;      // Vorgegebene Konstante
   int bSummand = 25887;     // Vorgegebene Konstante

   // entspricht 2^15, das eintragen der Konstante erspart das einbinden der Mathe
   // Library, sowie Rechenleistung
   int mDividend = 32768;

   int xLetzterwert = 0;     // Wird mit 0 als Startwert initalisiert

   cout << "10 Zufallszahlen:" << endl;
   for (int i = 0; i < 10; i++)
   {
      // Berechnung nach folgender Formel:
      // x [n+1] = (a * x[n] + b) MOD m
      xLetzterwert = (aFaktor * xLetzterwert + bSummand) % mDividend;

      cout << setw(6) << setfill(' ') << right << xLetzterwert << endl;
   }

   return (0);
}

