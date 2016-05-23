/*****************************************************************/
/*    Dateiname: FehlerTag.h										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 23.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef FEHLERTAG_H_
#define FEHLERTAG_H_

#include "FehlerDatum.h"
#include <string>

using namespace std;

/**
 *
 */
class FehlerTag: public FehlerDatum
{
	public:
		FehlerTag(int tag) : FehlerDatum("Falsche Tagesangabe: " + to_string(tag))
		{
			this->tag = tag;
		}

	protected:
		int tag;
};

#endif /* FEHLERTAG_H_ */
