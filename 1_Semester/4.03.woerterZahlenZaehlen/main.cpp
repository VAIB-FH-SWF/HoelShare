//==========================================================
//
//    Filename: main.cpp
//
// Description: Loesung zu Aufgabe 4.02, basierend auf dem Program 1.11.string
//
//     Version: 1.0
//     Created: 26.10.2015 18:31:41
//    Revision: none
//    Compiler: g++
//
//      Author: Sebastian Hoelscher, sebastian@hoelshare.de
//  Matrikelnr: 10050674
//
//==========================================================

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "ZUSTAND.h"

using namespace std;

int main ( )
{
   int maxstring = 2560;                      // Puffergroesse
   char text[maxstring];                     // Eingabepuffer
   int i, summeWoerter, summeZahlen;         // Schleifenzaehler,Buchstabezaehler
   ZUSTAND aktZustand = LEER;
   ifstream ifs;                             // erstellt ein InputFileStream Objekt
   string ifs_file_name = "daten-4-3.txt";   // input file Name

   cout << "***** Klein- und Grossbuchstaben abzaehlen *****\n";
   cout << "Geben Sie eine Textzeile ein: ";

   ifs.open(ifs_file_name.c_str());        // Oeffene den Stream
   // Konnte der Stream geoffnet werden?
   if (!ifs)
   {
      cerr << "Error: Datei " << ifs_file_name
            << " kann nicht geoeffnet werden!" << endl;
      exit(1);            // das Program mit Fehler beenden!
   }

   i = 0;
   // Einzelzeichen lesen
   //  und im Feld ablegen
   while (i < maxstring - 1 && (text[i] = ifs.get()) != EOF)
   {
      i++;     // Schleifenzaehler erhoehen
   }

   text[i] = '\0';                            // Zeichenkette abschliessen
   ifs.close();
   cout << "Der ausgewertete Text lautet: '" << text << "'\n";

   summeWoerter = summeZahlen = 0;
   for (i = 0; text[i] != '\0'; i += 1)
   {
      if (isspace(text[i]))
      {
         aktZustand = LEER;
      }
      else if (isdigit(text[i]))
      {
          // Wenn das letzte Zeichen ein Buchstabe war, wird ein Fehler ausgegeben und das Programm beendet
         if (aktZustand == WORT)
         {
            // Zahlen und Wort kombination!
            cout << "Fehler die Eingabe beinhaltet eine Wort Zahl kombination!";
            exit(1);
         }
         // Wenn der Zustand nicht
         summeZahlen += (aktZustand != ZAHL ? 1 : 0);
         aktZustand = ZAHL;
      }
      // Wenn das Zeichen weder Zahl noch Leerzeichen ist, wird es als *Buchstabe* gezaehlt
      // Der Linux Befehl wc zählt diese ebenfalls
      else if (!iscntrl(text[i]))
      {
          // Wenn das letzte Zeichen ein Buchstabe war, wird ein Fehler ausgegeben und das Programm beendet
         if (aktZustand == ZAHL)
         {
            // Zahlen und Wort kombination!
            cout << "Fehler die Eingabe beinhaltet eine Zahl Wort kombination!";
            exit(1);
         }
         // Wenn der Zustand nicht
         summeWoerter += (aktZustand != WORT ? 1 : 0);
         aktZustand = WORT;
      }
   }
   cout << setw(6) << summeWoerter << " Woerter\n";
   cout << setw(6) << summeZahlen << " Zahlen\n";

   return (0);
}     // ----------  end of function main  ----------
