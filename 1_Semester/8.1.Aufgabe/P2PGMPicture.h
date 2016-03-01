//==========================================================
//
//	  Filename:	P2PGMPicture.h
//
// Description: Definition des eines Bildes im Format P2
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "PGMPicture.h"

class P2PGMPicture : public PGMPicture
{
   public:
         P2PGMPicture (InputHandler*);
         P2PGMPicture (const Picture*);
         virtual ~P2PGMPicture();
         virtual void savePicture(std::string);
   protected:
         virtual bool checkData();
         virtual void loadData();
};

