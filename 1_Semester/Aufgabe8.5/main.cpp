/* 
 * File:   main.cpp
 * Author: hoelshare & fredde
 *
 * Created on 15. November 2015, 00:39
 */

#include <cstdlib>
#include <iostream>

#include "Spielfeld.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Spielfeld spielfeld;
    spielfeld.setFeld(0,0, 3);
    spielfeld.setFeld(2,0, 4);
    spielfeld.setFeld(6,0, 6);
    spielfeld.setFeld(8,0, 2);
    
    
    spielfeld.setFeld(0,1, 9);
    spielfeld.setFeld(3,1, 6);
    spielfeld.setFeld(4,1, 2);
    spielfeld.setFeld(5,1, 7);
    spielfeld.setFeld(8,1, 4);
    
    spielfeld.setFeld(0,2, 6);
    spielfeld.setFeld(3,2, 1);
    spielfeld.setFeld(5,2, 4);
    spielfeld.setFeld(8,2, 7);
    
    spielfeld.setFeld(0,3, 2);
    spielfeld.setFeld(1,3, 4);
    spielfeld.setFeld(2,3, 9);
    spielfeld.setFeld(6,3, 7);
    spielfeld.setFeld(7,3, 3);
    spielfeld.setFeld(8,3, 1);
    
    spielfeld.setFeld(0,4, 1);
    spielfeld.setFeld(1,4, 6);
    spielfeld.setFeld(7,4, 8);
    spielfeld.setFeld(8,4, 5);

    spielfeld.setFeld(1,5, 8);
    spielfeld.setFeld(2,5, 3);
    spielfeld.setFeld(6,5, 4);
    spielfeld.setFeld(7,5, 6);
    
    spielfeld.setFeld(0,6, 7);
    spielfeld.setFeld(3,6, 8);
    spielfeld.setFeld(5,6, 5);
    spielfeld.setFeld(8,6, 3);
    
    spielfeld.setFeld(3, 7, 2);
    spielfeld.setFeld(4, 7, 6);
    spielfeld.setFeld(5, 7, 3);
    
    spielfeld.setFeld(0, 8, 8);
    spielfeld.setFeld(2, 8, 5);
    spielfeld.setFeld(6, 8, 9);
    spielfeld.setFeld(8, 8, 6);

    Spielfeld *spfertig = spielfeld.solve();
    spfertig->draw();
    delete spfertig;
    return 0;
}

