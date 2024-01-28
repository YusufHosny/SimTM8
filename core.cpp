
#include "core.h"
#include "utils.h"
#include "stm8s105k4.h"
#include "instructions.h"
#include <stdexcept>


class stm8s105k4Memory {
    public:
        // Index into memory map,
        // Checks if memory address is reserved/ram/program mem etc    
        byte *operator[](Address address) {
            if(isReserved(address)) {
                throw std::invalid_argument("Reserved Address Requested");
                return NULL;
            }

            else return &(Memory[address]);
        }

        // index using an int
        byte *operator[](int address_as_int) {
            Address address;
            address = address_as_int;
            return (*this)[address];
        }

        void reset() {
            // TODO register reset values

            // TODO option byte reset values

            // TODO reset all other memory to 0s (except program memory etc)

        }


    private:
        // TODO optimize by removing reserved/unused address ranges
        byte Memory[0x028000]; // declare memory array

        bool isReserved(Address address) {
            // if in reserved memory ranges
            return
                // negative or too large
                (address < 0 || address > 0x028000) ||

                // 0x00 0800 -> 0x00 39FF
                (address > 0x000800 && address < 0x0039FF) ||

                // 0x00 4400 -> 0x00 47FF
                (address > 0x004400 && address < 0x0047FF) ||

                // 0x00 4900 -> 0x00 4FFF
                (address > 0x004900 && address < 0x004FFF) ||

                // 0x00 5800 -> 0x00 5FFF
                (address > 0x005800 && address < 0x005FFF) ||

                // 0x01 0000 -> 0x02 7FFF
                (address > 0x010000 && address < 0x027FFF);
            
        }

};


// TODO timers


class STM8105k4 {
    public:

        void next_cycle() {
            // TODO

            // read memory at program counter
            byte next_byte = *mem[PC];

            // if theres a prebyte, read 1 more byte, then call the execute instruction function
            if(next_byte == PDY || next_byte == PIX || next_byte == PIY || next_byte == PWSP) {
                execute_instruction(next_byte, *mem[PC+1]);
            } else {
                // otherwise just execute instruction with no prebyte
                execute_instruction(NOPRE, next_byte);
            }
        }

        void reset() {
            // reset memory
            mem.reset();

            // reset registers
            PC = 0;
            X, Y = 0;
            SP = 0x03FF;
            CC = 0x28;

            
        }

        // TODO
        void load_program() {


            
            // set PC to reset vector
            PC = *mem[IRV_RESET];
        }

    private:
        stm8s105k4Memory mem;

        // primary registers, here for ease of access instead of using pointers to memory mappings
        Address PC; // program counter
        Word X, Y, SP; // X, Y, Stack pointer
        byte CC; // Condition code register
        
        void execute_instruction(byte pre_byte, byte instruction) {
            switch (instruction) {
                



            } 
        }


};