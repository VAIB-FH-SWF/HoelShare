/* 
 * File:   Spielfeld.cpp
 * Author: fredde
 * 
 * Created on 15. November 2015, 00:40
 */

#include "Spielfeld.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

Spielfeld::Spielfeld() {
    for (int zeile = 0; zeile < 9; zeile++) {
        for (int spalte = 0; spalte < 9; spalte++) {
            this->spielfelder[zeile][spalte] = 0;
        }
    }
}

void Spielfeld::setFeld(int spalte, int zeile, Feld wert) {

    this->spielfelder[zeile][spalte] = wert;
}

void Spielfeld::draw() {
    system("clear");
    
    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;

    for (int zeile = 0; zeile < 9; zeile++) {
        cout << "#\t";
        for (int spalte = 0; spalte < 9; spalte++) {

            if (!this->spielfelder[zeile][spalte]) {
                cout << "\t";
                continue;
            }

            cout << (int) this->spielfelder[zeile][spalte] << "\t";
        }
        cout << "#" << endl;
    }

    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;
}

Spielfeld* Spielfeld::solve() {
    draw();
    // Wenn die Anzahl der leeren Felder 0 ist, dann ist das Raetsel geloest
    if(getAnzahlOffen() == 0)
    {
        return this;
    }
    for (int zeile = 0; zeile < 9; zeile++) {
        for (int spalte = 0; spalte < 9; spalte++) {
            if (!this->spielfelder[zeile][spalte]) {
                bool loesbar = false;

                for (int possibeValue = 1; possibeValue <= 9; possibeValue++) {
                    
                    if (this->checkFeldValue(zeile, spalte, possibeValue)) {
                        this->spielfelder[zeile][spalte] = possibeValue;
                    }
                    
                /*    //cout << zaehler++ << " " <<  zeile << "\t" << spalte << possibeValue << endl;
                    
                    if (this->checkFeldValue(zeile, spalte, possibeValue)) {
                        loesbar = true;
                        Spielfeld*  spneu = new Spielfeld(*this);
                        spneu->setFeld(spalte, zeile, possibeValue);
                        if(spneu->solve() == nullptr)
                        {
                            return this;
                        }
                        if(spneu->getAnzahlOffen() == 0)
                        {
                            return spneu;
                        }
                        //this->spielfelder[zeile][spalte] = possibeValue;
                    }
                }
*/
               // if (!loesbar) {
               //     
               //     return nullptr;
               // }
                }
            }
        }
    }
    
    return this;
}

bool Spielfeld::checkFeldValue(int zeile, int spalte, Feld wert) {

    //spalte pruefen
    for (int spalteIterator = 0; spalteIterator < 9; spalteIterator++) {

        if (this->spielfelder[zeile][spalteIterator] == wert) {
            return false;
        }
    }
    // zeile pruefen
    for (int zeileIterator = 0; zeileIterator < 9; zeileIterator++) {

        if (this->spielfelder[zeileIterator][spalte] == wert) {
            return false;
        }
    }
    for (int zeileIterator = zeile / 3 * 3; zeileIterator / 3 * 3 < zeile / 3 * 3 + 3; zeileIterator++) {
        for (int spaltenIterator = spalte / 3 * 3; spaltenIterator / 3 * 3 < spalte / 3 * 3 + 3; spaltenIterator++) {
            if (this->spielfelder[zeileIterator][spaltenIterator] == wert) {
                return false;
            }
        }
    }
    return true;
}

uint Spielfeld::getAnzahlOffen() {
    uint anzahl = 0;
    for (int zeile = 0; zeile < 9; zeile++) {
        for (int spalte = 0; spalte < 9; spalte++) {
            if (!this->spielfelder[zeile][spalte]) {
                anzahl++;
            }
        }
    }
    return anzahl;
}
