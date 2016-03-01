/* 
 * File:   Spielfeld.h
 * Author: HoelShare & fredde
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
    void setFeld(Feld spielfeld[9][9]);
    Spielfeld* solve ();
    Feld spielfelder[9][9];
    
private:
    void getFirstNotFilled(int* zeile, int* spalte);
    bool checkFeldValue (int zeile, int spalte, Feld wert);
    
};

#endif	/* SPIELFELD_H */

