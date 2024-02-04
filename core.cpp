#include "core.h"
#include "memory.cpp"

class stm8s105k4 {
    public:
        stm8s105k4Memory mem;
        
        // primary registers, here for ease of access instead of using pointers to memory mappings
        Address PC; // program counter
        Word X, Y, SP; // X, Y, Stack pointer
        byte A; // Accumulator
        ConditionCode CC; // Condition code register


        void next() {
            // read memory at program counter
            byte next_byte = mem.get(PC);

            // if theres a prebyte, read 1 more byte, then call the execute instruction function
            if(next_byte == PDY || next_byte == PIX || next_byte == PIY || next_byte == PWSP) {
                execute_instruction(next_byte, mem.get(PC+1));
            } else {
                // otherwise just execute instruction with no prebyte
                execute_instruction(NOPRE, next_byte);
            }
        }

        void device_reset() {
            // reset memory
            mem.reset();

            // TODO maybe use #define for the reset values?
            // reset registers
            PC = 0;
            X, Y = 0;
            SP = 0x03FF;
            CC = 0x28;
            A = 0;

            reset_interrupt();
        }

        void reset_interrupt() {

            // set PC to reset vector
            PC.e = mem.get(IRV_RESET + 1);
            PC.h = mem.get(IRV_RESET + 2);
            PC.l = mem.get(IRV_RESET + 3);

        }

        // TODO
        void load_program() {

        
        }

    private:

        void ADD(byte M) {
            byte R = A + M;
            CC.V = check_V_add(A, M, R);
            CC.H = check_H_add(A, M, R);
            CC.N = bit_get(R, 7);
            CC.Z = (R == 0);
            CC.C = check_C_add(A, M, R);

            A = R;
        }

        void SUB(byte M) {
            byte R = A - M;
            CC.V = check_V_sub(A, M, R);
            CC.N = bit_get(R, 7);
            CC.Z = (R == 0);
            CC.C = check_C_sub(A, M, R);
            
            A = R;
        }

        // get byte at shortmem byte given at memory location
        byte get_at_shortmem(byte location) {
            byte shortmem = mem.get(location);
            return mem.get(shortmem);
        }
        
        // get byte at longmem byte given at memory location
        byte get_at_longmem(byte location) {
            Word longmem;
            longmem.h = mem.get(location);
            longmem.l = mem.get(location+1);
            return mem.get(longmem);
        }

        // get byte at shortptr byte given at memory location
        Word get_at_shortptr(byte location) {
            byte shortptr = mem.get(location);
            return mem.getWord(shortptr);
        }
        
        // get byte at longptr byte given at memory location
        Word get_at_longptr(byte location) {
            Word longptr;
            longptr.h = mem.get(location);
            longptr.l = mem.get(location+1);
            return mem.getWord(longptr);
        }

        Word get_at_REGshortptr(byte location, Word reg) {
            byte shortptr = mem.get(location);
            return mem.getWord(reg + shortptr);
        }


        Word get_at_REGlongptr(byte location, Word reg) {
            Word longptr;
            longptr.h = mem.get(PC+2);
            longptr.l = mem.get(PC+3);
            return mem.getWord(reg + longptr);
        }   


        void execute_instruction(byte pre_byte, byte instruction) {
            switch ((pre_byte << 16) + instruction) {
                // NOP
                case(NOP): {
                    PC += 1;
                    break;
                }
                
                // LD
                case(LD_A_IMMEDIATE): {
                    A = mem.get(PC+1);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);
                    
                    PC += 2;
                    break;
                }
                case(LD_A_shortmem): {
                    A = mem.get(get_at_shortmem(PC+1));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_A_longmem): {
                    A = mem.get(get_at_longmem(PC+1));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_A_Xptr): {
                    A = mem.get(X);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 1;
                    break;
                }
                case(LD_A_shortoffXptr): {
                    byte shortoff = mem.get(PC+1);
                    A = mem.get(X + shortoff);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_A_longoffXptr): {
                    Word longoff;
                    longoff.h = mem.get(PC+1);
                    longoff.l = mem.get(PC+2);
                    A = mem.get(X + longoff);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_A_Yptr): {
                    A = mem.get(Y);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_A_shortoffYptr): {
                    byte shortoff = mem.get(PC+2);
                    A = mem.get(Y + shortoff);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_A_longoffYptr ): {
                    Word longoff;
                    longoff.h = mem.get(PC+2);
                    longoff.l = mem.get(PC+3);
                    A = mem.get(Y + longoff);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_A_shortoffSPtr): {
                    byte shortoff = mem.get(PC+1);
                    A = mem.get(SP + shortoff);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_A_shortptr): {
                    A = mem.get(get_at_shortptr(PC+2));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_A_longptr): {
                    A = mem.get(get_at_longptr(PC+2));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_A_shortptrX): {
                    A = mem.get(X + get_at_REGshortptr(PC+2, X));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_A_longptrX): {
                    A = mem.get(X + get_at_REGlongptr(PC+2, X));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_A_shortptrY): {
                    A = mem.get(Y + get_at_REGshortptr(PC+2, Y));
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_shortmem_A): {
                    byte shortmem = mem.get(PC+1);
                    mem.set(shortmem, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_longmem_A): {
                    Word longmem;
                    longmem.h = mem.get(PC+1);
                    longmem.l = mem.get(PC+2);
                    mem.set(longmem, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_Xptr_A): {
                    mem.set(X, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 1;
                    break;
                }
                case(LD_shortoffXptr_A): {
                    byte shortoff = mem.get(PC+1);
                    mem.set(X + shortoff, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_longoffXptr_A ): {
                    Word longoff;
                    longoff.h = mem.get(PC+1);
                    longoff.l = mem.get(PC+2);
                    mem.set(X + longoff, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_Yptr_A): {
                    mem.set(Y, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_shortoffYptr_A): {
                    byte shortoff = mem.get(PC+2);
                    mem.set(X + shortoff, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_longoffYptr_A): {
                    Word longoff;
                    longoff.h = mem.get(PC+2);
                    longoff.l = mem.get(PC+3);
                    mem.set(X + longoff, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_shortoffSPtr_A): {
                    byte shortoff = mem.get(PC+1);
                    mem.set(SP + shortoff, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 2;
                    break;
                }
                case(LD_shortptr_A): {
                    byte shortptr = mem.get(PC+2);
                    Word target = mem.getWord(shortptr);
                    mem.set(shortptr, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_longptr_A): {
                    Word longptr;
                    longptr.h = mem.get(PC+2);
                    longptr.l = mem.get(PC+3);
                    Word target = mem.getWord(longptr);
                    mem.set(target, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_shortptrX_A): {
                    byte shortptr = mem.get(PC+2);
                    Word target = mem.getWord(shortptr);
                    mem.set(X + target, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_longptrX_A): {
                    Word longptr;
                    longptr.h = mem.get(PC+2);
                    longptr.l = mem.get(PC+3);
                    Word target = mem.getWord(longptr);
                    mem.set(X + target, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 4;
                    break;
                }
                case(LD_shortptrY_A): {
                    byte shortptr = mem.get(PC+2);
                    Word target = mem.getWord(shortptr);
                    mem.set(Y + target, A);
                    CC.C = bit_get(A, 7);
                    CC.Z = (A == 0);

                    PC += 3;
                    break;
                }
                case(LD_XL_A): {
                    X.l = A;

                    PC += 1;
                    break;
                }
                case(LD_A_XL): {
                    A = X.l;
                    
                    PC += 1;
                    break;
                }
                case(LD_YL_A): {
                    Y.l = A;

                    PC += 2;
                    break;
                }
                case(LD_A_YL): {
                    A = Y.l;

                    PC += 2;
                    break;}
                case(LD_XH_A): {
                    X.h = A;
                    
                    PC += 1;
                    break;
                }
                case(LD_A_XH): {
                    A = X.h;
                    
                    PC += 1;
                    break;
                }
                case(LD_YH_A): {
                    Y.h = A;

                    PC += 2;
                    break;
                }
                case(LD_A_YH): {
                    A = Y.h;

                    PC += 2;
                    break;
                }

                // MOV
                case(MOV_longmem_IMMEDIATE): {
                    byte immediate = mem.get(PC+1);

                    Word longmem;
                    longmem.h = mem.get(PC+2);
                    longmem.l = mem.get(PC+3);

                    mem.set(longmem, immediate);

                    PC += 4;
                    break;
                }
                case(MOV_shortmem): {
                    byte dst = mem.get(PC+1);
                    byte src = mem.get(PC+2);
                    byte src_value = mem.get(src);
                    mem.set(dst, src);

                    PC += 3;
                    break;
                }
                case(MOV_longmem): {
                    Word dst;
                    dst.h = mem.get(PC+1);
                    dst.l = mem.get(PC+2);
                    Word src;
                    src.h = mem.get(PC+3);
                    src.l = mem.get(PC+4);

                    byte src_value = mem.get(src);
                    mem.set(dst, src);

                    PC += 5;
                    break;
                }

                // ADD
                case(ADD_IMMEDIATE): {
                    byte M = mem.get(PC+1);
                    ADD(M);

                    PC += 2;
                    break;
                }
                case(ADD_shortmem): {
                    byte M = get_at_shortmem(PC+1);
                    ADD(M);

                    PC += 2;
                    break;
                }
                case(ADD_longmem): {
                    byte M = get_at_longmem(PC+1);
                    ADD(M);

                    PC += 3;
                    break;
                }
                case(ADD_Xptr): {
                    byte M = mem.get(X);
                    ADD(M);

                    PC += 1;
                    break;
                }
                case(ADD_shortoffX): {
                    byte shortoff = mem.get(PC+1);
                    byte M = mem.get(X + shortoff);
                    ADD(M);

                    PC += 2;
                    break;
                }
                case(ADD_longoffX): {
                    Word longoff;
                    longoff.h = mem.get(PC+1);
                    longoff.l = mem.get(PC+2);
                    byte M = mem.get(X + longoff);
                    ADD(M);

                    PC += 3;
                    break;
                }
                case(ADD_Yptr): {
                    byte M = mem.get(Y);
                    ADD(M);

                    PC += 2;
                    break;
                }
                case(ADD_shortoffY): {
                    byte shortoff = mem.get(PC+2);
                    byte M = mem.get(Y + shortoff);
                    ADD(M);

                    PC += 3;
                    break;
                }
                case(ADD_longoffY): {
                    Word longoff;
                    longoff.h = mem.get(PC+2);
                    longoff.l = mem.get(PC+3);
                    byte M = mem.get(Y + longoff);
                    ADD(M);

                    PC += 4;
                    break;
                }
                case(ADD_shortoffSPtr): {
                    byte shortoff = mem.get(PC+1);
                    byte M = mem.get(SP + shortoff);
                    ADD(M);

                    PC += 2;
                    break;
                }
                case(ADD_shortptr): {
                    byte M = get_at_shortptr(PC+2);
                    ADD(M);

                    PC += 3;
                    break;
                }
                case(ADD_longptr): {
                    byte M = get_at_longptr(PC+2);
                    ADD(M);

                    PC += 4;
                    break;
                }
                case(ADD_shortptrX): {
                    byte M = get_at_REGshortptr(PC+2, X);
                    ADD(M);

                    PC += 3;
                    break;
                }
                case(ADD_longptrX): {
                    byte M = get_at_REGlongptr(PC+2, X);
                    ADD(M);

                    PC += 4;
                    break;
                }
                case(ADD_shortptrY): {
                    byte M = get_at_REGshortptr(PC+2, Y);
                    ADD(M);

                    PC += 3;
                    break;
                }

                // SUB
                case(SUB_IMMEDIATE): {
                    byte M = mem.get(PC+1);
                    SUB(M);

                    PC += 1;
                    break;
                }
                case(SUB_shortmem): {
                    byte M = get_at_shortmem(PC+1);
                    SUB(M);

                    PC += 1;
                    break;
                }
                case(SUB_longmem): {
                    byte M = get_at_longmem(PC+1);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_Xptr): {
                    byte M = mem.get(X);
                    SUB(M);

                    PC += 1;
                    break;
                }
                case(SUB_shortoffX): {
                    byte shortoff = mem.get(PC+1);
                    byte M = mem.get(X + shortoff);
                    SUB(M);

                    PC += 2;
                    break;
                }
                case(SUB_longoffX): {
                    Word longoff;
                    longoff.h = mem.get(PC+1);
                    longoff.l = mem.get(PC+2);
                    byte M = mem.get(X + longoff);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_Yptr): {
                    byte M = mem.get(Y);
                    SUB(M);

                    PC += 2;
                    break;
                }
                case(SUB_shortoffY): {
                    byte shortoff = mem.get(PC+2);
                    byte M = mem.get(X + shortoff);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_longoffY): {
                    Word longoff;
                    longoff.h = mem.get(PC+2);
                    longoff.l = mem.get(PC+3);
                    byte M = mem.get(Y + longoff);
                    SUB(M);

                    PC += 4;
                    break;
                }
                case(SUB_shortoffSPtr): {
                    byte shortoff = mem.get(PC+1);
                    byte M = mem.get(SP + shortoff);
                    SUB(M);

                    PC += 2;
                    break;
                }
                case(SUB_shortptr): {
                    byte M = get_at_shortptr(PC+2);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_longptr): {
                    byte M = get_at_longptr(PC+2);
                    SUB(M);

                    PC += 4;
                    break;
                }
                case(SUB_shortptrX): {
                    byte M = get_at_REGshortptr(PC+2, X);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_longptrX): {
                    byte M = get_at_REGlongptr(PC+2, X);
                    SUB(M);

                    PC += 4;
                    break;
                }
                case(SUB_shortptrY): {
                    byte M = get_at_REGshortptr(PC+2, Y);
                    SUB(M);

                    PC += 3;
                    break;
                }
                case(SUB_SP_IMMEDIATE): {
                    // TODO update after word operators
                    byte IMMEDIATE = mem.get(PC+1);
                    SP = SP - IMMEDIATE;

                    PC += 2;
                    break;
                }

                // JRA
                case(JRA): {
                    PC += mem.get(PC+1) + 2; // PC = PC + src + lgth
                    break;
                }

                // CP
                
            } 
        }


};