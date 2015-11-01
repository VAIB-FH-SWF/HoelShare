//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung zu Aufgabe 3.1
//
//	   Version:	1.0
// 	   Created:	25.10.2015 13:15:18
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
#include <time.h>

using namespace std;


//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main ( )
{
   const int ARRAYSIZE = 100;       // Arraygroesse
   const int SPALTENANZ = 10;       // Spaltenanzahl fuer die Ausgabe
   double arMittel = 0.0;           // Hilfsvariable fuer das arithmetische Mittel
   double a[ARRAYSIZE];             // Array definieren, laut Aufgabenstellung
   double minimum, maximum;         // Variblen, um das maxi- bzw. minimum zu bestimmen

   // Ohne diese Zeile, werden immer dieselben "Zufallszahlen" generiert
   srand(time(NULL));
   // Das Array mit Zufallswerten fuellen
   for (int i = 0; i < ARRAYSIZE; i++)
   {
      a[i] = rand() % 51;
   }

   // Die Zahlen werden mit einer Breite von 4 ausgegeben, da diese Maximal 2
   // Stellig sind, sind diese durch 2-3 Leerzeichen getrennt
   cout << setfill(' ') << right;

   // Ausgabe der Feldwerte mit 10 Werten pro Zeile
   for (int zeile = 0; zeile < ARRAYSIZE / SPALTENANZ; zeile++)
   {
      for (int spalte = 0; spalte < SPALTENANZ; spalte++)
      {
         cout << setw(4) << a[zeile * SPALTENANZ + spalte];
      }
      // Um in die naechste Zeile zu gelangen
      cout << endl;
   }

   // das arithmetische Mittel bilden
   for (int i = 0; i < ARRAYSIZE; i++)
   {
      arMittel += a[i];
   }
   arMittel /= ARRAYSIZE;     // Da arMittel ein Double ist, muss nicht extra geparst werden

   cout << "Das arithmetische Mittel aller " << ARRAYSIZE
         << " Feldelemente ist: " << arMittel << endl;

   minimum = maximum = a[0];

   for (int i = 1; i < ARRAYSIZE; i++)
   {
      if (a[i] < minimum)
      {
         minimum = a[i];
      }
      if (a[i] > maximum)
      {
         maximum = a[i];
      }
   }

   cout << "Das minimum der " << ARRAYSIZE << " Feldelemente liegt bei: "
         << minimum << endl;
   cout << "Das maximum der " << ARRAYSIZE << " Feldelemente liegt bei: "
         << maximum << endl;

   return (0);
}
