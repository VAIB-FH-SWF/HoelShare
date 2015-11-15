/* 
 * File:   Spielfeld.h
 * Author: fredde
 *
 * Created on 15. November 2015, 00:40
 */

#ifndef SPIELFELD_H
#define	SPIELFELD_H

typedef unsigned char Feld;
typedef unsigned int uint;

class Spielfeld {
public:
    Spielfeld();
    void draw ();
    void setFeld(int x, int y, Feld wert);
    Spielfeld* solve ();
    
private:
    Feld spielfelder[9][9];
    uint getAnzahlOffen();
    void getFirstNotFilled(int* zeile, int* spalte);
    bool checkFeldValue (int zeile, int spalte, Feld wert);
    
};

#endif	/* SPIELFELD_H */

