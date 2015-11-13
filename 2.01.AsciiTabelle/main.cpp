//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Erstellt eine ASCII-Tabelle mit 4 Spalten
//              von 0 - 127
//
//	   Version:	1.0
// 	   Created:	11.10.2015 11:49:30
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

#define FESTEBREITEAUSGABE 3

/**
 *  Gibt eine Zahl im Oktal, Dezimal, Hexadezimalsystem und als ggf. Charakter aus
 */
void ausgabeZahl (int dezZahl)
{
   // Gibt die Zahl im Oktalsystem aus
   cout << fixed << setw(FESTEBREITEAUSGABE) << oct << setfill('0') << dezZahl;
   cout << " ";
   // Gibt die Zahl im Dezimalsystem aus
   cout << fixed << setw(FESTEBREITEAUSGABE) << dec << setfill('0') << dezZahl;
   cout << " ";
   // Gibt die Zahl im Hexadezimalsystem aus
   cout << fixed << setw(FESTEBREITEAUSGABE) << hex << setfill('0') << dezZahl;
   cout << " ";
   // Den Bereich der nicht anzeigbaren Zeichen eingrenzen, fuer diese werden "..."
   // ausgegeben
   // {0 - 31, 127}
   if (std::iscntrl(dezZahl)) // dezZahl <= 31 || dezZahl == 127
   {
      cout << fixed << "...";
   }
   else
   {
      // Gibt das entsprechende ASCII Zeichen aus
      cout << fixed << setw(FESTEBREITEAUSGABE) << setfill(' ')
            << (char) dezZahl;
   }
}

/**
 * Diese Methode erstellt den Tabellen Kopf
 */
void ausgabeHeader (const unsigned char anzSpalten)
{
   for (int i = 0; i < anzSpalten; i++)
   {
      cout << "Okt Dez Hex Zch    ";
   }
   cout << endl;

   for (int i = 0; i < anzSpalten; i++)
   {
      cout << "---------------";    // Unter den Überschriften
      if(i+1 < anzSpalten)
      {
         cout << "----";            // Zwischen den Spalten
      }
   }
   cout << endl;
}

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main ( )
{
   const unsigned char anzSpalten = 4;         // Definiert die Anzahl der Spalten
   const unsigned char anzZeilen = 31;         // Definiert die Anzahl der Zeilen
   const unsigned char offset = anzZeilen + 1; // Speichert das Offset
   ausgabeHeader(anzSpalten);                  // Den Kopfausgeben
   for (int i = 0; i <= anzZeilen; i++)
   {
      for (int j = 0; j < anzSpalten; j++)
      {
         ausgabeZahl(i + j * offset);           // Gibt die Zahl aus
         cout << "    ";                        // Abstand zwischen den Spalten
      }
      cout << endl;                             // Zeile beenden
   }
   return (0);
}

