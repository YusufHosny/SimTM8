
#ifndef UTILS_H
#define UTILS_H

using byte = unsigned char;

struct Address;

// Define word and address structs
struct Word {
    byte h;
    byte l;

    // Constructors
    Word() : Word(0) { }

    Word(int word) {
        *this = word;   
    }


    // int conversion
    operator int() const {
        return ((int)h << 8) + l;
    }

    int operator=(int word) {
        h = word >> 8;
        l = word % 0x100;
        return word;
    }

    operator Address() const;
};

// memory address struct
struct Address {
    byte e; // extended byte
    byte h; // high byte
    byte l; // low byte
    
    // Constructors
    Address() : Address(0) { }

    Address(int address) {
        *this = address;   
    }

    // int conversion
    int operator=(int extended) {
        e = extended / (1 << 16);
        h = (extended % 0x10000) / (1 << 8);
        l = extended % 0x100;

        return extended;
    }

    operator int() const {
        return ((int)e << 16) + ((int)h << 8) + l;
    }


    // Word Conversion
    Word operator=(Word word) {
        e = 0;
        h = word.h;
        l = word.l;

        return word;
    }

    int operator+=(int increment) {
        *this = (int)(*this) + increment;
        return (int)(*this);
    }

};


// word to Address conversion
Word::operator Address() const {
    Address address;
    address.h = h;
    address.l = l;
    return address;
}


void bit_set(byte *target, byte index, byte value);
byte bit_get(byte target, byte index);

// check CC flags utility functions
byte check_V_add(byte A, byte M, byte R);
byte check_H_add(byte A, byte M, byte R);
byte check_C_add(byte A, byte M, byte R);


#endif