/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Aufgabe 4.1 Mitarbeiter in Klasse				 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 21.03.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/
#include "Mitarbeiter.h"
#include <iostream>

using namespace std;

// Haupteinstiegspunkt
int main()
{
	// Mitarbeiter deklarieren (Alle werte auf Default)
	Mitarbeiter m;
	// Mitarbeiter mit Default-Werten ausgeben
	cout << "Mitarbeiter nach Initialisierung: " << endl;
	m.print();
	
	// Werte zuweisen 
	// Das ordnungsgemaesse Funktionieren aller Methoden ist durch 
	// einfache Verwendung im Hauptprogramm nachzuweisen
	m.set_identnummer("10004242");
	m.set_nachname("Müller");
	m.set_vorname("Manfred");
	m.set_abteilung("MS Racing Team");
	m.set_durchwahl("15");
	
	cout << "Mitarbeiter nach Wertzuweisung: " << endl;
	m.print();
	
	// Kopierkonstruktor testen
	Mitarbeiter m2(m);
	cout << "Kopierter Mitarbeiter mit Konstruktor: " << endl;
	m2.print();
	
	// Zuweisungsoperator testen
	Mitarbeiter m3;
	m3 = m2;
	cout << "Kopierter Mitarbeiter mit Zuweisung: " << endl;
	m3.print();
	
	return 0;
}
