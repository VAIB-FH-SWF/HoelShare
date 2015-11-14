/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 14. November 2015, 23:45
 */

#include <cstdlib>

#include "Byte.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Byte byte = Byte(76);
    
    cout << byte.set_count() << endl;
    cout << byte.set_first() << endl;
    //byte.set_clear(3);
    //byte.set_complement();
    //byte.set_empty();
    byte.set_print("Menge s1 : ");
    byte.set_set(0);
    byte.set_print("Menge s1 : ");
    cout << (int)byte.getDaten() << endl;
    
    
}

