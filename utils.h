
#ifndef UTILS_H
#define UTILS_H

using byte = unsigned char;

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
        return (h << 8) + l;
    }

    int operator=(int word) {
        h = word >> 8;
        l = word - h;
    }

    // Address conversion
    operator Address() const {
        Address address;
        address.h = h;
        address.l = l;
        return address;
    }
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
        h = (extended - l) / (1 << 8);
        l = extended - l - h;
    }

    operator int() const {
        return (e << 16) + (h << 8) + l;
    }


    // Word Conversion
    Word operator=(Word word) {
        e = 0;
        h = word.h;
        l = word.l;
    }

    int operator+=(int increment) {
        *this = (int)(*this) + increment;
    }

};


void bit_set(byte *target, byte index, byte value);
int bit_get(byte target, byte index);

#endif