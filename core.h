
#ifndef CORE_H
#define CORE_H

class stm8s105k4;
class stm8s105k4Memory;

// pre-bytes
#define NOPRE 0xFF // Placeholder pre-byte for operations without a pre-byte
 
#define PDY 0x90   // Replaces an X based instruction using immediate, direct, indexed or
                   // inherent addressing mode by a Y one.
                   // It also provides read/modify/write instructions using Y indexed
                   // addressing mode with long offset and two bit handling instructions
                   // (BCPL and BCCM)

#define PIX 0x92   // Replaces an instruction using direct, direct bit, or direct relative
                   // addressing mode to an instruction using the corresponding indirect
                   // addressing mode.
                   // It also changes an instruction using X indexed addressing mode to
                   // an instruction using indirect X indexed addressing mode

#define PIY 0x91   // Replace an instruction using indirect X indexed addressing mode by
                   // a Y one.

#define PWSP 0x72  // Provide long addressing mode for bit handling and read/modify/write
                   // instructions.
                   // It also provides indirect addressing mode with two byte pointer for
                   // read/modify/write and register/memory instructions.
                   // Finally it provides stack pointer indexed addressing mode on
                   // register/memory instructions.

// Instructions



// Define condition code bit indices
#define V 7
#define O 6
#define I1 5
#define H 4
#define I0 3
#define N 2
#define Z 1
#define C 0

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