//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung zu Aufgabe 3.4
//
//	   Version:	1.0
// 	   Created:	25.10.2015 13:31:09
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
   int aFaktor  = 16333;     // Vorgegebene Konstante
   int bSummand = 25887;     // Vorgegebene Konstante

   // entspricht 2^15, das eintragen der Konstante erspart das einbinden der Mathe
   // Library, sowie Rechenleistung
   int mDividend = 32768;

   int xLetzterwert = 0;    // Wird mit 0 als Startwert initalisiert
   int anzahlWerte  = 0;    // Speichert die Anzahl der werte

   do     // Stellt die Periodenlaenge fest
   {
      // Berechnung nach folgender Formel:
      // x [n+1] = (a * x[n] + b) MOD m
      xLetzterwert = (aFaktor * xLetzterwert + bSummand) % mDividend;
      anzahlWerte++;
   } while (xLetzterwert != 0);

   /* Da die Anzahlwerte bei 0 beginnen, die Werte jedoch immer fuer den Wert[+1]
    * berechnet werden, muss nichts abgezogen werden um die groesse der Periodenlaenge
    * zu ermitteln */
   cout << "Die Periodenlaenge betraegt: " << anzahlWerte << endl;

   return (0);
}

