/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Aufgabe 3.2 Rohdaten aus Datei				     */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 21.03.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
 * Haupteinstiegspunkt
 * @return immer 0
 */
int main()
{
	string identnummer; // Idenditätsnummer
	string nachname; // Nachname
	string vorname; // Vorname
	string abteilung; // Abteilungsbezeichnung
	unsigned int durchwahl; // Telefondurchwahl

	ifstream ifs;
	// Dateistream oeffnen
	ifs.open("personen.dat");
	// Oeffnen das Dateistreams erfolgreich?
	if (!ifs)
	{
		exit(-1);
	}

	// Speichert die Anzahl der Saetze
	int satz = 0;
	while (ifs >> identnummer >> nachname >> vorname >> abteilung >> durchwahl)
	{
		satz++;
		// ... Variablenwerte formatiert ausgeben
		cout << left << setw(9) << identnummer << setw(20) << nachname << setw(20) << vorname << setw(5) << abteilung << setw(4) << durchwahl
				<< endl;
	}
	// Dateistream schliessen
	ifs.close();

	return 0;
}
