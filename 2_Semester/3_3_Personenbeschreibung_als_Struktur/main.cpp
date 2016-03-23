/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Aufgabe 3.3 Personenbeschreibung als Struktur   */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 21.03.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct mitarbeiter
{
		string identnummer; // Idenditätsnummer
		string nachname; // Nachname
		string vorname; // Vorname
		string abteilung; // Abteilungsbezeichnung
		unsigned int durchwahl; // Telefondurchwahl

};
// ##### VARIABLES - LOCAL TO THIS SOURCE FILE ####################
const unsigned int MitarbeiterMax = 1000; // max. Anzahl Mitarbeiter
mitarbeiter ma[MitarbeiterMax]; // Feld mit Mitarbeiter-Beschr.
/**
 * Haupteinstiegspunkt
 * @return immer 0
 */
int main()
{

	ifstream ifs;
	// Dateistream oeffnen
	ifs.open("personen.dat");
	// Oeffnen das Dateistreams erfolgreich?
	if (!ifs)
	{
		// Programm mit Fehler beenden
		exit(-1);
	}

	// Speichert die Anzahl der Saetze
	int satz = 0;
	while (ifs >> ma[satz].identnummer >> ma[satz].nachname >> ma[satz].vorname >> ma[satz].abteilung
			>> ma[satz].durchwahl)
	{

		// ... Variablenwerte formatiert ausgeben
		cout << left << setw(9) << ma[satz].identnummer
				<< setw(20) << ma[satz].nachname
				<< setw(20) << ma[satz].vorname
				<< setw(5) << ma[satz].abteilung
				<< setw(4) << ma[satz].durchwahl << endl;

		// Zaehler erhoehen
		satz++;
		// Da das Array ansonsten ueberlaufen wuerde, muss nach der Maximalen menge die Schleife beendet werden
		if (satz >= MitarbeiterMax)
			break;
	}
	// Dateistream schliessen
	ifs.close();

	return 0;
}
