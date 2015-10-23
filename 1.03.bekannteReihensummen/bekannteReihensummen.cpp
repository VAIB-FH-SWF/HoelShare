//==========================================================
//
//	  Filename:	bekannteReihensummen.cpp
//
// Description: Die Datei spiegelt die Loesung der Aufgabe
//                          1.03 wider, bekannte Reihen.
//
//	   Version:	1.0
// 	   Created:	04.10.2015 16:03:19
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
   cout << "Praktikum 'Programmierung mit C++ 1' / Blatt 1 / Aufgabe 1.3\n";
   cout << "Reihensummen bekannter Funktionen\n\n";

   int n;                                   // Anzahl der Summanden
   int width = 18;                          // Ausgabebreite der Summe
   int precision = 16;                      // Nachkommastellen Summe
   double summe, vergleichssumme;           // Reihensumme (Ergebnis)
   double xValue = 1.2;                     // X-Variable der Gleichung
   double summand;
   int vz;                                  // Hilfsvariable für das Vorzeichen
   //--------------------------------------------------------
   //  Summation der Exponentialfunktion
   //--------------------------------------------------------
   summe = 1.0;
   n = 1;
   summand = 1;
   do
   {
      vergleichssumme = summe;                  // Die alte Summe zum Vergleich speichern
      summand *= (xValue / (double) n);
      summe += summand;
      n++;
   }
   while(summe != vergleichssumme);
   cout << "          Summe der Exponentialfunktion von 1..." << n << " für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << summe << endl;
   cout << "Kontrolle Summe der Exponentialfunktion            für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << exp (xValue) << endl;

   //--------------------------------------------------------
   //  Summation Cosinus hyperbolicus
   //--------------------------------------------------------
   summe = 1.0;
   n = 1;
   summand = 1;
   do
   {
      vergleichssumme = summe;                  // Die alte Summe zum Vergleich speichern
      summand *= (xValue * xValue) / (2 * n * (2 * n - 1));
      summe += summand;

      // Anzahl der Summanden hochzaehlen, jedoch nur wenn die Summen ungleich sind
      n += (summe != vergleichssumme ? 1 : 0);
   }
   while(summe != vergleichssumme);
   cout << "          Summe der Cosinus hyperbolicus von 1..." << n << " für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << summe << endl;
   cout << "Kontrolle Summe der Cosinus hyperbolicus            für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << cosh (xValue) << endl;

   //--------------------------------------------------------
   //  Summation Kosinus
   //--------------------------------------------------------
   summe = 1.0;
   n = 1;
   summand = 1;
   vz = 1;
   do
   {
      vergleichssumme = summe;                  // Die alte Summe zum Vergleich speichern
      summand *= (xValue * xValue) / (2 * n * (2 * n - 1));
      vz = -vz;
      summe += vz * summand;
      // Anzahl der Summanden hochzaehlen, jedoch nur wenn die Summen ungleich sind
      n += (summe != vergleichssumme ? 1 : 0);
   }
   while(summe != vergleichssumme);
   cout << "          Summe der Kosinusfunktion von 1..." << n << " für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << summe << endl;
   cout << "Kontrolle Summe der Kosinusfunktion            für x = ";
   cout << fixed << setw (3) << setprecision (1) << xValue << ": ";
   cout << fixed << setw (width) << setprecision (precision) << cos (xValue) << endl;

   return 0;
}
