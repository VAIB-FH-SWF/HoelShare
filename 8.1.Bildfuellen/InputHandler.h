//==========================================================
//
//	  Filename:	InputHandler.h
//
// Description: Datei zur Definition des Eingabe Handlings
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <string>

class InputHandler
{
   public:
      InputHandler (std::istream* inst) :
            is(*inst)
      {
      }
      int readInt(std::string = "");
      double readDouble(std::string = "");
      char readChar(std::string = "");
      std::string readLine(std::string = "");
      std::string readString(std::string = "");
   private:
      std::istream &is;
};



#endif /* INPUTHANDLER_H_ */
