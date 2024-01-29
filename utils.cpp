#include "utils.h"
#include <stdexcept>

void bit_set(byte *target, byte index, byte value) {
    if(value == 1) {
        *target |= (byte)1 << index;
    }
    else if(value == 0) {
        *target &= ~((byte)1 << index);
    }
}

byte bit_get(byte target, byte index) {
    return (target & ((byte)1 << index)) >> index;
}

byte check_V_add(byte A, byte M, byte R) {
    return 
        ((bit_get(A, 7) & bit_get(M, 7) )| (bit_get(M, 7) & ~bit_get(R, 7)) | (~bit_get(R, 7) & bit_get(A, 7)))
        ^ 
        ((bit_get(A, 6) & bit_get(M, 6) )| (bit_get(M, 6) & ~bit_get(R, 6)) | (~bit_get(R, 6) & bit_get(A, 6)));
}

byte check_H_add(byte A, byte M, byte R) {
    return ((bit_get(A, 3) & bit_get(M, 3) )| (bit_get(M, 3) & ~bit_get(R, 3)) | (~bit_get(R, 3) & bit_get(A, 3)));
}

byte check_C_add(byte A, byte M, byte R) {
    return ((bit_get(A, 7) & bit_get(M, 7) )| (bit_get(M, 7) & ~bit_get(R, 7)) | (~bit_get(R, 7) & bit_get(A, 7)));
}
