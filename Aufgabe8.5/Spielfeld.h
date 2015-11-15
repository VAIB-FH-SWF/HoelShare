/* 
 * File:   Spielfeld.h
 * Author: fredde
 *
 * Created on 15. November 2015, 00:40
 */

#ifndef SPIELFELD_H
#define	SPIELFELD_H

typedef unsigned char Feld;

class Spielfeld {
public:
    Spielfeld();
    
    
private:
    Feld spielfelder[9][9];
    
    void draw ();
    
};

#endif	/* SPIELFELD_H */

