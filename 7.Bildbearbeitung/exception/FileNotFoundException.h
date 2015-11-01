//==========================================================
//
//	  Filename:	DreieckException.h
//
// Description: Definition der FileNotFoundException
//
//	   Version:	1.0
// 	   Created:	29.10.2015
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include "HoelShareException.h"
/**
 * Exceptions die beim lesen aus Dateien aufreten
 */
class FileNotFoundException: public HoelShareException
{
   public:
                    FileNotFoundException   (const char* _filename);
      const char*   getFilename             ();


   private:
      // Speichert den Dateinamen
      const char* filename;
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
