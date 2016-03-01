//==========================================================
//
//	  Filename:	PictureFactory.h
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	07.11.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef HEAD_PICTUREFACTORY_H_
#define HEAD_PICTUREFACTORY_H_

#include "Picture.h"
#include <iostream>
#include <string>

class PictureFactory
{
   public:
      static Picture* create(std::string);
      static Picture* copyPicture (const Picture*);
};

#endif /* HEAD_PICTUREFACTORY_H_ */
