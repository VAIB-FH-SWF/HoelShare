/* 
 * File:   Byte.cpp
 * Author: fredde
 * 
 * Created on 14. November 2015, 23:48
 */

#include "Byte.h"
#include <iostream>
#include <bitset>
#include <string>

Byte::Byte(SmallSet daten) {
            this->daten = daten;
}


Byte::~Byte() {
}

uint Byte::set_count() {
    
    uint anzahl = 0;
    
    for (uint loopIterator = 0; loopIterator < 8; loopIterator ++) {
        
        if (((daten >> loopIterator) & 1) == 1)
        {
            anzahl++;
        } 
    }
    return anzahl;
}

uint Byte::set_first() {
    
    // wenn kein Element vorhande ist, wird der wert 8 zurueck gegeben
    uint first = 8;
    
    for (uint loopIterator = 0; loopIterator < 8; loopIterator ++) {
        
        if (((daten >> loopIterator) & 1) == 1)
        {
            first = loopIterator;
            break;
        } 
    }
    return first;
}

void Byte::set_clear(uint n) {
    
    this->daten = ~(1 << n) & this->daten;
}

void Byte::set_complement() {
    this->daten ^=255;
}

void Byte::set_empty() {
    this->daten &= 0; // Alternativ = 0
}

void Byte::set_print(std::string name) {
    
    std::cout << name << std::bitset<8>(this->daten) << std::endl;
}

void Byte::set_set(uint n) {
    this->daten = (1 << n) | this->daten;
}


