#include "stm8s105k4.h"
#include "utils.h"
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

        // index into memory using an int instead of address struct
        byte *operator[](int address_as_int) {
            Address address;
            address = address_as_int;
            return (*this)[address];
        }

        byte get(Address address) {
            return Memory[address];
        }

        Word getWord(Address address) {
            Word word;
            word.h = Memory[address];
            word.l = Memory[address+1];
            return word;
        }

        void set(Address address, byte value) {
            Memory[address] = value;
        }

        void load_interrupt(Address target, Address ISR) { // ISR = interrupt service routine
            Memory[target] = INT;
            Memory[target+1] = ISR.e;
            Memory[target+2] = ISR.h;
            Memory[target+3] = ISR.l;
        }

        void reset() {
            // TODO register reset values

            // TODO option byte reset values

            // TODO reset all other memory to 0s (except program memory etc)

        }


    private:
        // TODO optimize by removing reserved/unused address ranges
        byte Memory[0x010000]; // declare memory array
    
        bool isReserved(Address address) {
            // if in reserved memory ranges
            // TODO: maybe use #define for these addresses
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
