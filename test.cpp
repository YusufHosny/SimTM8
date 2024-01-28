#include <iostream>
#include "utils.cpp"
#include "core.cpp"
#include <string>

using std::string;
using std::cout;

int test_index = 0;
int success_count = 0;
void test(bool test) {
    success_count += test;
    cout << "Test Number " << ++test_index << ": " << (test ? "Success." : "Failed.") << std::endl;
}

int main() {
    // bit set/get functions
    test(bit_get(0b10000000, 7) == 1);
    test(bit_get(0b10000100, 2) == 1);
    test(bit_get(0b11100000, 6) == 1);
    test(bit_get(0b11100000, 5) == 1);
    test(bit_get(0b11111111, 2) == 1);
    test(bit_get(0b00000001, 0) == 1);
    test(bit_get(0b10000000, 0) == 0);
    test(bit_get(0b10000100, 3) == 0);
    test(bit_get(0b11100000, 2) == 0);
    test(bit_get(0b11100000, 4) == 0);
    test(bit_get(0b00000001, 7) == 0);


    byte test_byte = 0b00110101;
    bit_set(&test_byte, 0, 0);
    test(bit_get(test_byte, 0) == 0);
    bit_set(&test_byte, 7, 0);
    test(bit_get(test_byte, 7) == 0);
    bit_set(&test_byte, 7, 1);
    test(bit_get(test_byte, 7) == 1);
    bit_set(&test_byte, 4, 0);
    test(bit_get(test_byte, 4) == 0);

    // Address and Word structs
    Word word = 0xADAD;
    test(word == 0xADAD);
    word.h = 0xAB;
    word.l = 0xCD;
    test(word == 0xABCD);
    word = 0xDEAD;
    test(word == 0xDEAD);
    

    Address address = 0xDEADAF;
    test(address == 0xDEADAF);
    address.e = 0xAB;
    address.h = 0xCD;
    address.l = 0xEF;
    test(address == 0xABCDEF);
    address = 0xFEDCBA;
    test(address == 0xFEDCBA);
    address = 0;
    test(address == 0);
    address += 3;
    test(address == 3);

    // Condition code registers    

    // NOP and stm8 start

    // LD


    // check if succeeded all
    cout << "Tests Succeeded: " << success_count << " / " << test_index << "." << std::endl;
}