/*****************************************************************/
/*    Dateiname: FehlerMonat.h										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 23.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef FEHLERMONAT_H_
#define FEHLERMONAT_H_

#include "FehlerDatum.h"
#include <string>

using namespace std;

/**
 *
 */
class FehlerMonat: public FehlerDatum
{
	public:
		FehlerMonat(int monat) : FehlerDatum("Falsche Monatsangabe: " + to_string(monat))
		{
			this->monat = monat;
		}

	protected:
		int monat;
};

#endif /* FEHLERMONAT_H_ */
