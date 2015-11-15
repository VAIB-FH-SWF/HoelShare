/* 
 * File:   Spielfeld.cpp
 * Author: fredde
 * 
 * Created on 15. November 2015, 00:40
 */

#include "Spielfeld.h"
#include <iostream>
#include <iomanip>

using namespace std;

Spielfeld::Spielfeld() {
}

void solve (int zeile, int spalte){
    
}

void Spielfeld::draw() {
    
    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;
    
    for (int zeile = 0; zeile < 9; zeile ++) {
        cout << "#\t";
        for (int spalte = 0; spalte < 9; spalte ++){
            
            cout << this->spielfelder[zeile][spalte] << "\t";
        }
        cout << "#" << endl;
    }
    
    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;
}


