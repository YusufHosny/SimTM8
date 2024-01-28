

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// NOP instruction
#define NOP 0x9D


// LD instruction variants
#define LD_A_IMMEDIATE        0xA6
#define LD_A_shortmem         0xB6
#define LD_A_longmem          0xC6
#define LD_A_Xptr             0xF6
#define LD_A_shortoffXptr     0xE6
#define LD_A_longoffXptr      0xD6
#define LD_A_Yptr             0x90F6
#define LD_A_shortoffYptr     0x90E6
#define LD_A_longoffYptr      0x90D6
#define LD_A_shortoffSPtr     0x7B
#define LD_A_shortptr         0x92C6
#define LD_A_longptr          0x72C6
#define LD_A_shortptrX        0x92D6
#define LD_A_longptrX         0x72D6
#define LD_A_shortptrY        0x91D6
#define LD_shortmem_A         0xB7
#define LD_longmem_A         0xC7
#define LD_Xptr_A             0xF7
#define LD_shortoffXptr_A     0xE7
#define LD_longoffXptr_A      0xD7
#define LD_Yptr_A             0x90F7
#define LD_shortoffYptr_A     0x90E7
#define LD_longoffYptr_A      0x90D7
#define LD_shortoffSPtr_A     0x6B
#define LD_shortptr_A         0x92C7
#define LD_longptr_A          0x72C7
#define LD_shortptrX_A        0x92D7
#define LD_longptrX_A         0x72D7
#define LD_shortptrY_A        0x91D7
#define LD_XL_A               0x97
#define LD_A_XL               0x9F
#define LD_YL_A               0x9097
#define LD_A_YL               0x909F
#define LD_XH_A               0x95
#define LD_A_XH               0x9E
#define LD_YH_A               0x9095
#define LD_A_YH               0x909E

// MOV instruction variants
#define MOV_longmem_IMMEDIATE 0x35
#define MOV_shortmem          0x45
#define MOV_longmem           0x55

// JRA instruction
#define JRA                   0x20

// ADD instruction variants
#define ADD_IMMEDIATE        0xAB
#define ADD_shortmem         0xBB
#define ADD_longmem          0xCB
#define ADD_Xptr             0xFB
#define ADD_shortoffX        0xEB
#define ADD_longoffX         0xDB
#define ADD_Yptr             0x90FB
#define ADD_shortoffY        0x90EB
#define ADD_longoffY         0x90DB
#define ADD_shortoffSPtr     0x1B
#define ADD_shortptr         0x92CB
#define ADD_longptr          0x72CB
#define ADD_shortptrX        0x92DB
#define ADD_longptrX         0x72DB
#define ADD_shortptrY        0x91DB

// SUB instruction variants
#define SUB_IMMEDIATE        0xA0
#define SUB_shortmem         0xB0
#define SUB_longmem          0xC0
#define SUB_Xptr             0xF0
#define SUB_shortoffX        0xE0
#define SUB_longoffX         0xD0
#define SUB_Yptr             0x90F0
#define SUB_shortoffY        0x90E0
#define SUB_longoffY         0x90D0
#define SUB_shortoffSPtr     0x10
#define SUB_shortptr         0x92C0
#define SUB_longptr          0x72C0
#define SUB_shortptrX        0x92D0
#define SUB_longptrX         0x72D0
#define SUB_shortptrY        0x91D0
#define SUB_SP_IMMEDIATE     0x52

// CP instruction variants

// INT instruction
#define INT 0x82

#endif