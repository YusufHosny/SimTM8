
#ifndef CORE_H
#define CORE_H

#include "stm8s105k4.h"
#include "utils.h"
#include "instructions.h"
#include <stdexcept>

class stm8s105k4;
class stm8s105k4Memory;

struct ConditionCode { // Condition code register
    byte V;
    byte O;
    byte I1;
    byte H;
    byte I0;
    byte N;
    byte Z;
    byte C;

    byte operator=(byte byte) {
        V = bit_get(byte, 7);
        O = bit_get(byte, 6);
        I1 = bit_get(byte, 5);
        H = bit_get(byte, 4);
        I0 = bit_get(byte, 3);
        N = bit_get(byte, 2);
        Z = bit_get(byte, 1);
        C = bit_get(byte, 0);

        return byte;
    }

    int operator=(int byte) {
        V = bit_get(byte, 7);
        O = bit_get(byte, 6);
        I1 = bit_get(byte, 5);
        H = bit_get(byte, 4);
        I0 = bit_get(byte, 3);
        N = bit_get(byte, 2);
        Z = bit_get(byte, 1);
        C = bit_get(byte, 0);

        return byte;
    }

    operator byte() const {
        return (V << 7) + (O << 6) + (I1 << 5) + (H << 4) + (I0 << 3) + (N << 2) + (Z << 1) + C;
    }
}; 

// TODO
#define OPT0

// interrupt vectors
#define IRV_RESET          0x8000      // Reset
#define IRV_TRAP           0x8004      // Software interrupt
#define IRQ0_TLI           0x8008      // external top level interrupt
#define IRQ1_AWU           0x800C      // auto wake up from halt
#define IRQ2_CLK           0x8010      // clock controller
#define IRQ3_EXTI0         0x8014      // port A external interrupts
#define IRQ4_EXTI1         0x8018      // port B external interrupts
#define IRQ5_EXTI2         0x801C      // port C external interrupts
#define IRQ6_EXTI3         0x8020      // port D external interrupts
#define IRQ7_EXTI4         0x8024      // port E external interrupts
#define IRQ8_RESERVED1     0x8028      // reserved 
#define IRQ9_RESERVED2     0x802C      // reserved
#define IRQ10_SPI          0x8030      // SPI end of transfer
#define IRQ11_TIM1         0x8034      // TIM1 update/overflow/underflow/trigger/break
#define IRQ12_TIM1CC       0x8038      // TIM1 capture/compare
#define IRQ13_TIM2         0x803C      // TIM2 update/overflow
#define IRQ14_TIM2CC       0x8040      // TIM2 capture/compare
#define IRQ15_TIM3         0x8044      // TIM3 update/overflow
#define IRQ16_TIM3CC       0x8048      // TIM3 capture/compare
#define IRQ17_RESERVED3    0x804C      // reserved
#define IRQ18_RESERVED4    0x8050      // reserved
#define IRQ19_I2C          0x8054      // I2C interrupt
#define IRQ20_UARTTX       0x8058      // UART2 Tx complete
#define IRQ21_UARTDF       0x805C      // UART2 receive register data full
#define IRQ22_ADC          0x8060      // ADC1 end of conversion/analog watchdog interrupt
#define IRQ23_TIM4         0x8064      // TIM4 update/overflow
#define IRQ24_FLASH        0x8068      // EOP/ WR_PG_DIS

#endif 