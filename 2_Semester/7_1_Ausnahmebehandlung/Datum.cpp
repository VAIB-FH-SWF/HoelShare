/*****************************************************************/
/*    Dateiname: Datum.cpp										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "Datum.h"

using namespace std;

/**
 * Der Konstruktor uebernimmt drei Datumsanteile
 * und prueft die Gueltigkeit der Tages- und Monatsangabe.
 * Im Fehlerfall soll zunaechst eine Textausgabe erfolgen.
 * @param tg
 * @param mnt
 * @param jhr
 */
Datum::Datum(uint tg, uint mnt, uint jhr)
{
	this->tag = tg;
	this->monat = mnt;
	this->jahr = jhr;
	if (!tagOk() || !monatOk())
	{
		// Laut aufgabenstellung Fehler ausgeben!
		cout << "Bei dem Datum (" << *this << ") handelt es sich um kein gueltiges Datum!" << endl;
	}
}

/**
 * Diese Methode gibt true zurueck, wenn die Monatsnummer zwischen 1 und 12 liegt.
 * @return
 */
bool Datum::monatOk()
{
	return monat >= 1 && monat <= 12;
}

/**
 * Berechnet die Maximale Anzahl an Tagen im Monat
 * @return
 */
int Datum::anzahlTage()
{
	int maxTage;
	if (monat == 2)
	{
		maxTage = 28;
		if (schaltjahr())
		{
			maxTage = 29;
		}
	}
	else
	{
		int geradeMonate = 30;
		int ungeradeMonate = 31;
		if (monat >= 8)
		{
			ungeradeMonate = 30;
			geradeMonate = 31;
		}

		if (monat % 2 == 0)
		{
			maxTage = geradeMonate;
		}
		else
		{
			maxTage = ungeradeMonate;
		}
	}

	return maxTage;
}

/**
 * Prueft, ob ein Schaltjahr vorliegt.
 * Schaltjahre sind alle Jahre, die ohne Rest durch 4 teilbar sind.
 * Alle Jahreszahlen, die ohne Rest durch 100 teilbar sind
 * (zum Beispiel 1800, 1900), sind keine Schaltjahre.
 * Alle Jahreszahlen, die ohne Rest durch 400 teilbar sind (zum Beispiel 1600, 2000),
 * sind jedoch wieder Schaltjahre.
 *
 * @return ob es sich um ein Schaltjahr handelt
 */
bool Datum::schaltjahr()
{
	return jahr % 4 == 0 && (!(jahr % 100 == 0) || (jahr % 400 == 0));
}

/**
 * Diese Methode gibt true zuruueck, wenn die Tagesangabe gueltig ist.
 * Hierzu wird geprueft, ob die
 * Tagesnummer zwischen 1 und dem jeweils Letzten des Monats liegt.
 * Schaltjahre sind beim Februar natürlich zu berücksichtigen.
 * Dazu wird die Methode schaltjahr verwendet.
 * @return
 */
bool Datum::tagOk()
{
	return this->tag >= 1 && this->tag <= anzahlTage();
}

ostream & operator <<(ostream & os, const Datum & obj)
{
	os << obj.getTag() << "." << obj.getMonat() << "." << obj.getJahr();

	return os;
}
