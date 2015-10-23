//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Die Datei spiegelt die Loesung der Aufgabe
//                          2.03 wider, Flaeche eines Dreiecks.
//
//	   Version:	1.0
// 	   Created:	19.10.2015 17:23:01
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#include <iostream>
#include <iomanip>
#include <string>
#include "Dreieck.h"
#include "InputHandler.h"
#include "DreieckException.h"

using namespace std;

/**
 * Diese Methode ist zustaendig fuer die Ausgabe der Daten eines Dreiecks
 */
void ausgabe(Dreieck &dreieck)
{
   cout << "Das eingegebene Dreieck: " << dreieck.toString() << endl;
   try
   {  // Wenn bei der Berechnung ein Fehler auftritt, wird eine Exception geworfen
      // dies ist der Fall, wenn der Ausdruck unter der Wurzel < 0 ist
      cout << "Flaecheninhalt A nach Heron1: " << dreieck.berechneHeron1() << endl;
      cout << "Flaecheninhalt A nach Heron2: " << dreieck.berechneHeron2() << endl;
   }
   catch (DreieckException& ex)
   {
      cout << "Das Dreieck mit den angegebenen Seitenlaengen "
           << ex.getDreieck().toString() << " kann nicht erstellt werden!"
           << endl << "Zwischenergebnis: " << ex.getZwischenergebnis() << endl;
   }
}

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------
int main()
{
   Dreieck dreieck = InputHandler::leseDreieck();
   ausgabe(dreieck);
   /**
    * Die zwei Beispiel Dreiecke koennte man wie folgt erstellen.
   dreieck = Dreieck(1,1,1);
   ausgabe(dreieck);
   dreieck = Dreieck(3,4,5);
   ausgabe(dreieck);
   */
   return (0);
}


