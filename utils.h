
#ifndef UTILS_H
#define UTILS_H

using byte = unsigned char;

// Define word and address structs
struct Word {
    byte h;
    byte l;

    // cast to int
    operator int() const {
        return (h << 8) + l;
    }

    int operator=(int word) {
        h = word >> 8;
        l = word - h;
    }
};

// memory address struct
struct Address {
    byte e; // extended byte
    byte h; // high byte
    byte l; // low byte

    // define address using an int
    int operator=(int extended) {
        e = extended / (1 << 16);
        h = (extended - l) / (1 << 8);
        l = extended - l - h;
    }

    // cast to int
    operator int() const {
        return (e << 16) + (h << 8) + l;
    }

};


void bit_set(byte *target, byte index, byte value);
int bit_get(byte target, byte index);

#endif