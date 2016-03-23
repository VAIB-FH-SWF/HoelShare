/*****************************************************************/
/*    Dateiname: main.cpp										 */
/* Beschreibung: Aufgabe 3.4 Personenbeschreibung in einer Liste */
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
		mitarbeiter* next; // Zeiger auf den Naechsten Eintrag

};

/** Funktionsprototyp */
void loescheListe(mitarbeiter* next);

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

	mitarbeiter *ma = 0; // Listenanker
	mitarbeiter *cursor = 0; // Durchlaufzeiger

	mitarbeiter* maNeu = new mitarbeiter;
	ma = maNeu;
	cursor = ma;
	while (ifs >> maNeu->identnummer >> maNeu->nachname >> maNeu->vorname >> maNeu->abteilung >> maNeu->durchwahl)
	{
		// Den aktuellen Satz im Cursor speichern
		cursor = maNeu;
		// Neuen Mitarbeiter erstellen
		maNeu = new mitarbeiter;
		// Den Zeiger auf den neu erstellten Mitarbeiter verweisen lassen
		cursor->next = maNeu;
	}
	// maNeu wurde bereits erstellt, es konnten jedoch keine Daten eingelesen werden,
	// daher muss der Speicher des zuletzt erstellten Datensatzes wieder freigegeben werden
	delete maNeu;
	// und der Next Zeiger des Zuletzt erfolgreich gelesenen Mitarbeiters muss auf 0 gesetzt werden
	cursor->next = NULL;

	// Dateistream schliessen
	ifs.close();


	//cursor wieder auf anfang setzen
	cursor = ma;

	// Durchsucht die Liste nach der Durchwahl 4731
	// Es wird nichts ausgegeben, wenn die Person nicht gefunden wurde
	do
	{
		if(cursor->durchwahl == 4731)
		{
			cout << "Vorname: " << cursor->vorname << endl;
			cout << "Nachname: " << cursor->nachname << endl;
			// Die Schleife an dieser Stelle NICHT beenden,
			// da durchwahl theoretisch oeffter vorkommen kann
		}
	}while((cursor = cursor->next));

	cursor = ma;
	// alternativ Rekursive Methode zum loeschen
	// loescheListe(cursor);

	// Liste Abbauen
	while(cursor->next)
	{
		ma = cursor;
		cursor = cursor->next;
		delete ma;
	}

	return 0;
}

/**
 * Rekursiver aufruf zum leeren der Liste
 * @param next
 */
void loescheListe(mitarbeiter* next)
{
	// Wenn ein NEXT existiert, wird die Funktion fuer diesen auch aufgerufen
	if(next->next)
		loescheListe(next->next);
	// Loesche den Pointer auf die Liste
	delete next;
}
