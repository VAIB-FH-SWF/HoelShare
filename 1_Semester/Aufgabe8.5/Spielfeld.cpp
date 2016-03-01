/** 
 * File:   Spielfeld.cpp
 * Author: HoelShare & fredde 
 * 
 * Created on 15. November 2015, 00:40
 */

#include "Spielfeld.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Initialisiert ein leeres Spielfeld
 */
Spielfeld::Spielfeld()
{
    for (int zeile = 0; zeile < 9; zeile++)
    {
        for (int spalte = 0; spalte < 9; spalte++)
        {
            this->spielfelder[zeile][spalte] = 0;
        }
    }
}

/**
 * Setzt den Wert an der Stelle im Spielfeld
 * @param spalte
 * @param zeile
 * @param wert
 */
void Spielfeld::setFeld(int spalte, int zeile, Feld wert)
{

    this->spielfelder[zeile][spalte] = wert;
}

/**
 * Gibt das Spielfeld aus
 */
void Spielfeld::draw()
{
    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;

    for (int zeile = 0; zeile < 9; zeile++)
    {
        cout << "#\t";
        for (int spalte = 0; spalte < 9; spalte++)
        {

            if (!this->spielfelder[zeile][spalte])
            {
                cout << "\t";
                continue;
            }

            cout << (int) this->spielfelder[zeile][spalte] << "\t";
        }
        cout << "#" << endl;
    }

    cout << "#\t#\t#\t#\t#\t#\t#\t#\t#\t#\t#" << endl;
}

/**
 * Loesst das Sudoku Raetsel
 * @return das geloesste Sudoku
 */
Spielfeld* Spielfeld::solve()
{
    int zeile = -1, spalte = -1;
    // Suche das erste nicht gefuellte Feld
    getFirstNotFilled(&zeile, &spalte);
    // Sind alle Felder gefuellt
    if (-1 == spalte || -1 == zeile)
    {
        return this;
    }

    // moeglichen Felder testen
    for (int possibeValue = 1; possibeValue <= 9; possibeValue++)
    {
        // Ist die Zahl in dem Feld moeglich?
        if (this->checkFeldValue(zeile, spalte, possibeValue))
        {
            // Neues Sudoku Feld anlegen und das Feld setzen
            // Bei diesem dann Solve aufrufen
            Spielfeld* spneu = new Spielfeld(*this);
            spneu->setFeld(spalte, zeile, possibeValue);
            Spielfeld* loesung = spneu->solve();
            // Wenn die Loesung gesetzt ist, sind alle Felder gesetzt
            if (loesung != nullptr)
            {
                return loesung;
            }
            delete spneu;
            //this->spielfelder[zeile][spalte] = possibeValue;
        }
    }
    // Keine loesung gefunden
    return nullptr;
}

/**
 * Prueft ob der Wert an der Stelle im Feld gesetzt werden kann
 * @param zeile
 * @param spalte
 * @param wert
 * @return 
 */
bool Spielfeld::checkFeldValue(int zeile, int spalte, Feld wert)
{
    
    for (int i = 0; i < 9; i++)
    {
        //spalte pruefen
        if (this->spielfelder[zeile][i] == wert)
        {
            return false;
        }
        //zeile pruefen
        if (this->spielfelder[i][spalte] == wert)
        {
            return false;
        }
        
        // 3x3 Blocks pruefen
        // /3*3 bewusst als ganzzahl, damit entweder bei 0, 3, 6 angefangen wird und 3 Felder getestet werden
        // Wenn i durch 3 Teilbar ist, wird die naechste Spalte ueberprueft
        // Ansonsten wird mit i%3 die Zeile hoehergezaehlt
        if (this->spielfelder[zeile / 3 * 3 + (i%3)][spalte / 3 * 3 + (i/3)] == wert)
        {
            return false;
        }
    }
    return true;
}

/**
 * Setzt den Wert von zeile und spalte auf das erste nicht gefuellte Feld
 * @param zeile
 * @param spalte
 */
void Spielfeld::getFirstNotFilled(int* zeile, int* spalte)
{
    for (int z = 0; z < 9; z++)
    {
        for (int s = 0; s < 9; s++)
        {
            if (!this->spielfelder[z][s])
            {
                *zeile = z;
                *spalte = s;
                return;
            }
        }
    }
}


void Spielfeld::setFeld(Feld spielfeld[9][9])
{
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 9; y++)
        {
            this->spielfelder[x][y] = spielfeld[x][y];
        }
    }
}