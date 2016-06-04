/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Loesung der Aufgabe 7.2						 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/
#include "Datum.h"
#include <iostream>
#include <string>
#include <fstream>
#include "FehlerDatum.h"

using namespace std;

/**
 * Haupteinstiegspunkt
 * @return
 */
int main()
{
	string dateiname = "datumsliste.dat";
	// Datei oeffnen
	ifstream dateiStream(dateiname.c_str());
	if (!dateiStream)
	{
		cerr << "Fehler Datei(" << dateiname << ") konnte nicht geoeffnet werden";
		exit(1);
	}
	int anzahl = 1000000;
	int tag, monat, jahr;
	Datum* daten[anzahl];
	int zaehler = 0;
	int anzFehler = 0;
	// Datensaetze laden
	while (zaehler < anzahl && dateiStream >> tag >> monat >> jahr)
	{
		try
		{
			daten[zaehler] = new Datum(tag, monat, jahr);
			// nur die erfolgreichen Daten uebernehmen
			zaehler++;
		}
		catch (const FehlerDatum& fehler)
		{
			// Anzahl Fehler erhoehen
			anzFehler++;
			// Zeile in der der Fehler auftritt (zaehler + anzFehler)
			cout << "Satz Nr.\t" << (zaehler + anzFehler) << ":\t" << fehler.what() << endl;
		}
	}
	cout << endl << zaehler << " von " << (zaehler + anzFehler) << " Datumsangaben übernommen";

	// Datei schliessen
	dateiStream.close();

	// Speicher wieder freigeben
	for (; zaehler >= 0; zaehler--)
	{
		delete daten[zaehler];
	}

	return 0;
}
