#include "utils.h"

void bit_set(byte *target, byte index, byte value) {
    if(value == 1) {
        *target |= (byte)1 << index;
    }
    else if(value == 0) {
        *target &= ~((byte)1 << index);
    }
}

int bit_get(byte target, byte index) {
    return (target & ((byte)1 << index)) >> index;
}

