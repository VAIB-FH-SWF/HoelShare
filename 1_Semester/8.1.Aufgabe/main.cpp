//==========================================================
//
//	  Filename:	main.cpp
//
// Description: Loesung der Aufgaben aus Kapitel 7
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Picture.h"
#include "HoelShareException.h"
#include "PictureFactory.h"

using namespace std;

//----------------------------------------------------------
//  Haupteinstiegspunkt des Programms
//----------------------------------------------------------

int main()
{
    try
    {
        cout << "Bild wird geladen..." << endl;


        // Das Bild laden
        Picture* p = PictureFactory::create(string("kunst.pgm"));
        // Menue anzeigen
        Picture* bearbeitet = p->fill(10, 10, 127);
        bearbeitet->savePicture("Fill.pgm");
        delete bearbeitet;
        // Zeiger auf das Bild loeschen
        delete p;
    }
    catch (const HoelShareException& ex) // Eigene Fehler abfangen
    {
        cout << "(Eigener)Fehler: " << ex.what();
    }
    catch (exception& ex) // Allgemeine Fehler abfangen
    {
        cout << "Fehler: " << ex.what();
    }
    return (0);
}

