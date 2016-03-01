/* 
 * File:   Byte.h
 * Author: fredde
 *
 * Created on 14. November 2015, 23:48
 */

#ifndef BYTE_H
#define	BYTE_H

#include <string>

typedef char SmallSet;
typedef unsigned int uint;

class Byte {
public:
    Byte(SmallSet daten);
    uint set_count();
    uint set_first();
    void set_clear(uint n);
    void set_complement();
    void set_empty();
    void set_print(std::string name);
    void set_set(uint n);
    
    SmallSet getDaten () {
        return this->daten;
    }
    
    virtual ~Byte();
private:
    SmallSet daten;
};

#endif	/* BYTE_H */

