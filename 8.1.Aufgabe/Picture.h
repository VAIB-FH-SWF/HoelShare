//==========================================================
//
//	  Filename:	Picture.h
//
// Description: Definition eines Bildes
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef PICTURE_H_
#define PICTURE_H_

#include <string>
#include "FILETYPE.h"
#include "InputHandler.h"

typedef unsigned char Pixel;

class Picture
{
   public:
      static Picture* loadPicture   (std::string);
      static Picture* copyPicture   (const Picture*);

      virtual       ~Picture        ();
      virtual void  savePicture     (std::string) = 0;
      Picture*      invertieren     () const;
      Picture*      glaetten        () const ;
      Picture*      kantenErkennung () const;
      Picture*      schaerfen       () const;
      Picture*      fill            (int inz, int ins, Pixel newVal) const;
      int           getWidth        () const;
      int           getHeight       () const;
      int           getGreydepth    () const;
      std::string   getFilename     () const;
      FILETYPE      getFiletype     () const;
      Pixel         getData         (int x, int y) const;
      void          setData         (int x, int y, Pixel pixel);
   protected:
//      Picture           (const Picture*);
      virtual void      loadData() = 0;
      virtual bool      checkData() = 0;
      std::string       filename;
      FILETYPE          filetype;
      int               width;
      int               height;
      int               greydepth;
      InputHandler*     inputHandle;
      Pixel**           data;
};

#endif /* PICTURE_H_ */
