//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung zu Aufgabe 3.2
//
//	   Version:	1.0
// 	   Created:	25.10.2015 13:19:06
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main ( )
{
   // Hilfsvariablen, fuer das arithemtische Mittel, minumum, maximum, anzahl
   double arMittel = 0.0, minimum = 0.0, maximum = 0.0;
   ifstream ifs;                          // erstellt ein InputFileStream Objekt
   // Hilfsvariable fuer den Wert der aktuellen Zeile
   double wert = 0.0;
   int anzahl  = 0;               // Hilfsvariable fuer die Anzahl der Werte
   string ifs_file_name = "daten-3-2.txt";     // input file Name

   ifs.open(ifs_file_name.c_str());        // Oeffene den Stream
   // Konnte der Stream geoffnet werden?
   if (!ifs)
   {
      cerr << "Error: Datei " << ifs_file_name
            << " kann nicht geoeffnet werden!" << endl;
      exit(1);            // das Program mit Fehler beenden!
   }

   while (ifs >> wert)
   {
      // Die Pruefung dieser Werte findet hier statt, damit nicht eine weitere
      // Schleife durchlaufen werden muss!

      // Minimumspruefung
      // falls noch kein Wert vorhanden (anzahl == 0), wird der Wert definitiv gesetzt
      if (anzahl == 0 || wert < minimum)
      {
         minimum = wert;
      }
      // Maximumspruefung, hier gilt selbiges, wie bei der mimimumspruefung
      if (anzahl == 0 || wert > maximum)
      {
         maximum = wert;
      }
      // Die Anzahl der tatsaelichen Werte erhoehen
      anzahl++;

      // Die Summe fuer das arithmetische Mittel bilden
      arMittel += wert;
   }

   ifs.close();

   // Das arithmetische Mittel, aus der Summe der Werte, bestimmen
   arMittel /= anzahl;
   cout << setprecision(15) << internal << right;
   cout << "Gelesene Werte:        " << setw(15) << anzahl << endl;
   cout << "Kleinster Wert:        " << setw(15) << minimum << endl;
   cout << "Groesster Wert:        " << setw(15) << maximum << endl;
   cout << "Arithmetisches Mittel: " << setw(15) << arMittel << endl;

   return (0);
}
