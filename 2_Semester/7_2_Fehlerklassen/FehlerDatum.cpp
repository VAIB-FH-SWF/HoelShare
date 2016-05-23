/*****************************************************************/
/*    Dateiname: FehlerDatum.cpp										 */
/* Beschreibung: TODO  											 */
/*  															 */
/*      Version: 1.0											 */
/*     Erstellt: 22.05.2016										 */
/*        Autor: Sebastian Hoelscher							 */
/*****************************************************************/

#include "FehlerDatum.h"

FehlerDatum::FehlerDatum(std::string error)
{
	this->err_msg = error;
}

FehlerDatum::~FehlerDatum() throw()
{
}

const char* FehlerDatum::what() const throw ()
{
	return this->err_msg.c_str();
}
