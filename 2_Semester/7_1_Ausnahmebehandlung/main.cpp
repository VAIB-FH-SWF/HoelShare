/*****************************************************************/	  
/*    Dateiname: main.cpp										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/
#include "Datum.h"
#include <iostream>
#include <string>
#include <fstream>

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
	if(!dateiStream)
	{
		cerr << "Fehler Datei(" << dateiname << ") konnte nicht geoeffnet werden";
		exit(1);
	}

	int tag, monat, jahr;
	Datum* daten[1000000];
	int zaehler = 0;
	while (dateiStream >> tag >> monat >> jahr)
	{
		daten[zaehler] = new Datum(tag, monat, jahr);

		zaehler++;
	}
	cout << "Es wurden " << zaehler << " Datensaetze eingelesen";

	// Datei schliessen
	dateiStream.close();

	// Speicher wieder freigeben
	for(; zaehler >= 0; zaehler--)
	{
		delete daten[zaehler];
	}

	return 0;
}
