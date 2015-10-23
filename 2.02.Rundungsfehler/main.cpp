//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Stellt einen Rundungsfehler nach Berechnung
//              mit einem festen Faktor nach.
//
//	   Version:	1.0
// 	   Created:	11.10.2015 13:16:30
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main ( )
{
   int         i             = 0;             // Hilfsvariable fuer den Schleifenzaehler
   const float xZahlUrsprung = 1000000.0f;    // Konstante zum Vergleich
   float       xZahl         = xZahlUrsprung; // Hilfsvariable zum rechnen
   const float kFaktor       = 0.1693;        // Faktor zum Rechnen
   // Konstante fuer die Anzahl der Nachkommastellen
   const char  kommastellen  = 8;

   // Ausgangswert ausgeben
   cout << "Ausgangswert: " << fixed << setprecision(kommastellen) << xZahl << endl;

   // die Zahl 10 mal durch den Faktor teilen
   for(i = 0; i < 10; i++)
   {
      xZahl *= kFaktor;
   }

   // die Zahl 10 mal mit dem Faktor multiplizieren
   for(i = 0; i < 10; i++)
   {
      xZahl /= kFaktor;
   }

   // Vergleich und Ausgabe
   cout << "Endwert:      " << fixed << setprecision(kommastellen) << xZahl << endl;

   if(xZahl == xZahlUrsprung)
   {
      cout << "Die Zahlen sind nach der Berechnung gleich!" << endl;
   }
   else
   {
      cout << "Durch die Berechnung ist ein Rundungsfehler aufgetreten!" << endl;
   }

   return (0);
}
