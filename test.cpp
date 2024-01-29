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

    // Condition code register
    ConditionCode CC;
    CC = 0b11010111;
    test(CC == 0b11010111);
    test(CC.V == 1);
    test(CC.O == 1);
    test(CC.I1 == 0);
    test(CC.H == 1);
    test(CC.I0 == 0);
    test(CC.N == 1);
    test(CC.Z == 1);
    test(CC.C == 1);

    // reset and load stm8 memory
    stm8s105k4 stm8;
    stm8.mem.load_interrupt(IRV_RESET, PROGRAM_MEM_START);
    test(stm8.mem.get(IRV_RESET) == 0x82);
    test(stm8.mem.get(IRV_RESET + 1) == 0x00);
    test(stm8.mem.get(IRV_RESET + 2) == 0x80);
    test(stm8.mem.get(IRV_RESET + 3) == 0x80);
    stm8.device_reset();
    test(stm8.PC == 0x008080);
    test(stm8.CC == 0x28);
    test(stm8.A == 0);
    test(stm8.SP = 0x3FF);
    test(stm8.X == stm8.Y & stm8.X == 0);    

    // NOP
    stm8.mem.set(PROGRAM_MEM_START, NOP);
    stm8.mem.set(PROGRAM_MEM_START + 1, NOP);
    stm8.mem.set(PROGRAM_MEM_START + 2, NOP);
    test(stm8.CC == 0x28);
    test(stm8.A == 0);
    test(stm8.SP = 0x3FF);
    test(stm8.X == stm8.Y & stm8.X == 0);    

    test(stm8.PC == 0x008080);
    stm8.next_cycle();
    test(stm8.CC == 0x28);
    test(stm8.A == 0);
    test(stm8.SP = 0x3FF);
    test(stm8.X == stm8.Y & stm8.X == 0);    
    test(stm8.PC == 0x008081);
    stm8.next_cycle();
    test(stm8.CC == 0x28);
    test(stm8.A == 0);
    test(stm8.SP = 0x3FF);
    test(stm8.X == stm8.Y & stm8.X == 0);    
    test(stm8.PC == 0x008082);
    stm8.next_cycle();
    test(stm8.CC == 0x28);
    test(stm8.A == 0);
    test(stm8.SP = 0x3FF);
    test(stm8.X == stm8.Y & stm8.X == 0);    
    test(stm8.PC == 0x008083);
    
    // LD

    // ADD

    // JRA

    // MOV

    // SUB

    // CP

    // check if succeeded all
    cout << "Tests Succeeded: " << success_count << " / " << test_index << "." << std::endl;
}