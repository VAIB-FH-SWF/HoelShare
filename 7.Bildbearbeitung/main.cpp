//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung der Aufgaben aus Kapitel 7
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "head\Picture.h"
#include "exception\HoelShareException.h"

using namespace std;

/**
 * Gibt den Menuetext zurueck
 */
string getMenuText()
{
   stringstream menuText;
   menuText << "g\tGlaettung" << endl
            << "i\tInvertieren" << endl
            << "k\tKantenbildung" << endl
            << "s\tSchaerfen" << endl
            << "e\tENDE" << endl;
   return (menuText.str());
}

/**
 * Zeigt das Menue auf der Konsole an
 */
void showMenu (Picture* p)
{
   unsigned char eingabe;
   InputHandler consolInput(&cin);
   Picture* bearbeitet;
   do
   {
      // Liesst ein Zeichen von der Konsole ein
      eingabe = consolInput.readChar(getMenuText());
      // Entscheidet anhand der Eingabe welche Methode aufgerufen wird
      // G->Glaetten
      // I->Invertieren
      // K->Kantenbildung
      // S->Schaerfen
      // E->Ende
      // Ansonsten falsche Eingabe
      switch (eingabe)
      {
         case 'g':
         case 'G':
            bearbeitet = p->glaetten();
            bearbeitet->savePicture("Glaetten.pgm");
            cout << endl << "Bild geglaettet abgespeichert" << endl;
            // Loescht den Zeiger auf das Bearbeitete Bild
            delete bearbeitet;
         break;
         case 'i':
         case 'I':
            bearbeitet = p->invertieren();
            bearbeitet->savePicture("Invertiert.pgm");
            cout << endl << "Bild invertiert abgespeichert" << endl;
            // Loescht den Zeiger auf das Bearbeitete Bild
            delete bearbeitet;
         break;
         case 'k':
         case 'K':
            bearbeitet = p->kantenErkennung();
            bearbeitet->savePicture("Kanten.pgm");
            cout << endl << "Kanten erkanntes Bild abgespeichert" << endl;
            // Loescht den Zeiger auf das Bearbeitete Bild
            delete bearbeitet;
         break;
         case 's':
         case 'S':
            bearbeitet = p->schaerfen();
            bearbeitet->savePicture("Schaerfen.pgm");
            cout << endl << "Bild geschaerft abgespeichert" << endl;
            // Loescht den Zeiger auf das Bearbeitete Bild
            delete bearbeitet;
         break;
         case 'e':
         case 'E':
            cout << endl << "Program wird beendet" << endl;
            // NOTHING TO-DO here
            // Ansonsten wird Falsche eingabe ausgegeben
         break;
         default:
            cout << endl << "Falsche eingabe!" << endl;
         break;
      }
   } while (eingabe != 'e' && eingabe != 'E');
}

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main ( )
{
   try
   {
      cout << "Bild wird geladen..." << endl;
      // Das Bild laden
      Picture* p = Picture::loadPicture(string("dreifach.pgm"));
      // Menue anzeigen
      showMenu(p);
      // Zeiger auf das Bild loeschen
      delete p;
   }
   catch (const HoelShareException& ex) // Eigene Fehler abfangen
   {
      cout << "(Eigener)Fehler: " << ex.what();
   }
   catch (exception& ex) // Allgemeine Fehler abfangen
   {
      cout << "Fehler: " << ex.what();
   }
   return (0);
}

