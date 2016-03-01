//==========================================================
//
//	  Filename:	endlicheReihen.cpp
//
// Description: Die Datei spiegelt die Loesung der Aufgabe
//							1.01 wider, Endliche Reihen.
//
//	   Version:	1.0
// 	   Created:	29.09.2015 12:57:22
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>

//----------------------------------------------------------
//  Hauptprogramm
//----------------------------------------------------------
int
main ()
{
   std::cout << "Praktikum 'Programmierung mit C++ 1' / Blatt 1 / Aufgabe 1.1\n";
   std::cout << "Summenbildung bei endlichen Reihen\n\n";

   int n = 1000; 			// Anzahl der Summanden
   int width = 10; 		    // Ausgabebreite der Summe
   int precision = 5; 	    // Nachkommastellen Summe
   double summe; 			// Reihensumme (Ergebnis)
   double summand;			// Hilfsvariable
   int i, vz;				// Hilfsvariablen

   //--------------------------------------------------------
   //  Summation der harmonischen Reihe
   //--------------------------------------------------------
   summe = 0.0;
   for(i = 1; i <= n; i++)
   {
      summe = summe + 1.0 / i;
   }

   std::cout << "Summe der harmonischen Reihe von 1..." << n << ": ";
   std::cout << std::fixed << std::setw (width) << std::setprecision (precision) << summe
         << "\n";

   //--------------------------------------------------------
   //  Summation der alternierenden harmonischen Reihe
   //--------------------------------------------------------
   summe = 0.0;
   vz = 1;
   for(i = 1; i <= n; i++)
   {
      summand = vz * (1.0 / i);
      summe = summe + summand;
      vz = -vz;
   }

   std::cout << "Summe der alternierenden harmonischen Reihe von 1..." << n << ": ";
   std::cout << std::fixed << std::setw (width) << std::setprecision (precision) << summe
         << "\n";

   //--------------------------------------------------------
   //  Summation der Leibnizschen Reihe
   //--------------------------------------------------------
   summe = 0.0;
   vz = 1;
   for(i = 1; i <= n; i++)
   {
      summand = vz * (1.0 / (2 * i - 1));
      summe = summe + summand;
      vz = -vz;
   }

   std::cout << "Summe der Leibnizschen Reihe von 1..." << n << ": ";
   std::cout << std::fixed << std::setw (width) << std::setprecision (precision) << summe
         << "\n";

   //--------------------------------------------------------
   //  Summation der Geometrischen Reihe
   //--------------------------------------------------------
   summe = 0.0;
   summand = 1.0;
   for(i = 0; i <= n; i++)
   {
      summe = summe + summand;
      summand = 0.5 * summand;
   }

   std::cout << "Summe der Geometrischen Reihe von 1..." << n << ": ";
   std::cout << std::fixed << std::setw (width) << std::setprecision (precision) << summe
         << "\n";
   return 0;
}

