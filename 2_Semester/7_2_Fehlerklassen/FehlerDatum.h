/*****************************************************************/
/*    Dateiname: FehlerDatum.h										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#ifndef FEHLERDATUM_H_
#define FEHLERDATUM_H_

#include <string>

/**
 *
 */
class FehlerDatum: public std::exception
{
	public:
		FehlerDatum (std::string error = "");
	      virtual ~FehlerDatum () throw ();
	      virtual const char* what ( ) const throw ( );
	   protected:
	      std::string err_msg;
};

#endif /* FEHLERDATUM_H_ */
