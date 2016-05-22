/*****************************************************************/
/*    Dateiname: Datum.h										 */
/* Beschreibung: Definition der Datum-Klasse					 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef DATUM_H_
#define DATUM_H_

#include <iostream>

typedef unsigned int uint;

/**
 * 		 Class: Datum
 * Description: Handhabung von Kalenderdaten (Minimalversion)
 */
class Datum
{
	public:

		// ====================  LIFECYCLE   =======================================
		Datum()
		{
			tag = 0;
			monat = 0;
			jahr = 0;
		}

		Datum(uint tg, uint mnt, uint jhr);

		// ====================  INQUIRY     =======================================
		uint getTag() const
		{
			return tag;
		}
		uint getMonat() const
		{
			return monat;
		}
		uint getJahr() const
		{
			return jahr;
		}

	private:
		bool monatOk();
		bool tagOk();
		bool schaltjahr();
		int anzahlTage();

	private:
		uint tag;
		uint monat;
		uint jahr;
};
// ----- end of class Datum -----

std::ostream & operator <<(std::ostream & os, const Datum & obj);

#endif /* DATUM_H_ */
