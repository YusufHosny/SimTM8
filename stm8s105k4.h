
#ifndef STM8105K4_H
#define STM8105K4_H








// MEMORY MAPPING ADDRESSES

// Important locations
#define STACKBASE 0x07FF             // base pointer of stack (bottom of stack)
#define INTERRUPVECTORSTBASE 0x8000  // base pointer of interrupt vectors (top of interrupt vector area)
#define PROGRAM_MEM_START 0x8080     // start of progra memory
#define PROGRAM_MEM_END 0xBFFF       // end of flash program memory range (16K flash mem size)


// Option Bytes
#define OPT0_ROP    0x4800    // read-out protection
#define OPT1_UBC    0x4801    // user boot code
#define NOPT1_UBC   0x4802    // user boot code NOPT
#define OPT2_AFR    0x4803    // alternate function remapping
#define NOPT2_AFR   0x4804    // alternate function remapping NOPT
#define OPT3_MISC   0x4805    // misc. option
#define NOPT3_MISC  0x4806    // misc. option NOPT
#define OPT4_CLK    0x4807    // clock option
#define NOPT4_CLK   0x4808    // clock option NOPT
#define OPT5_HSE    0x4809    // HSE clock startup
#define NOPT5_HSE   0x480A    // HSE clock startup NOPT
#define OPT6_R1     0x480B    // reserved
#define NOPT6_R1    0x480C    // reserved NOPT
#define OPT7_R2     0x480D    // reserved
#define NOPT7_R2    0x480E    // reserved NOPT
#define OPTBL       0x487E    // bootloader
#define NOPTBL      0x487F    // bootloader NOPT


// Port A at 0x5000
#define PA_ODR		 0x5000		    // Port A data output latch register
#define PA_IDR		 PA_ODR + 1		// Port A input pin value register
#define PA_DDR		 PA_IDR + 1		// Port A data direction register
#define PA_CR1		 PA_DDR + 1		// Port A control register 1
#define PA_CR2		 PA_CR2 + 1		// Port A control register 2
 
// Port B at 0x5005
#define PB_ODR		 0x5005		    // Port B data output latch register
#define PB_IDR		 PB_ODR + 1		// Port B input pin value register
#define PB_DDR		 PB_IDR + 1		// Port B data direction register
#define PB_CR1		 PB_DDR + 1		// Port B control register 1
#define PB_CR2		 PB_CR1 + 1		// Port B control register 2
 
 // Port C at 0x500a
#define PC_ODR		 0x500a		    // Port C data output latch register
#define PC_IDR		 PC_ODR + 1		// Port C input pin value register
#define PC_DDR		 PC_IDR + 1		// Port C data direction register
#define PC_CR1		 PC_DDR + 1		// Port C control register 1
#define PC_CR2		 PC_CR1 + 1		// Port C control register 2

// Port D at 0x500f
#define PD_ODR		 0x500f		    // Port D data output latch register
#define PD_IDR		 PD_ODR + 1		// Port D input pin value register
#define PD_DDR		 PD_IDR + 1		// Port D data direction register
#define PD_CR1		 PD_DDR + 1		// Port D control register 1
#define PD_CR2		 PD_CR1 + 1		// Port D control register 2

// Port E at 0x5014
#define PE_ODR		 0x5014		    // Port E data output latch register
#define PE_IDR		 PE_ODR + 1		// Port E input pin value register
#define PE_DDR		 PE_IDR + 1		// Port E data direction register
#define PE_CR1		 PE_DDR + 1		// Port E control register 1
#define PE_CR2		 PE_CR1 + 1		// Port E control register 2

// Port F at 0x5019
#define PF_ODR		 0x5019		    // Port F data output latch register
#define PF_IDR		 PF_ODR + 1		// Port F input pin value register
#define PF_DDR		 PF_IDR + 1		// Port F data direction register
#define PF_CR1		 PF_DDR + 1		// Port F control register 1
#define PF_CR2		 PF_CR1 + 1		// Port F control register 2
#define reserved1	 PF_CR2 + 1		// unused

// Flash at 0x505a
#define FLASH_CR1		 0x505a		    // Flash control register 1
#define FLASH_CR2	FLASH_CR1 + 1		// Flash control register 2
#define FLASH_NCR2	FLASH_CR2 + 1		// Flash complementary control register 2
#define FLASH_FPR	FLASH_NCR2 + 1		// Flash protection register
#define FLASH_NFPR	FLASH_FPR + 1		// Flash complementary protection register
#define FLASH_IAPSR	FLASH_NFPR + 1		// Flash in-application programming status register
#define reserved2	FLASH_IAPS + 1		// unused
#define FLASH_PUKR	reserved2 + 2		// Flash Program memory unprotection register
#define reserved3	FLASH_PUKR + 1		// unused
#define FLASH_DUKR	reserved3 + 1		// Data EEPROM unprotection register
#define reserved4	FLASH_DUKR + 1		// unused

// External Interrupt Control Register (ITC) at 0x50a0
#define EXTI_CR1		 0x50a0		    // External interrupt control register 1
#define EXTI_CR2	EXTI_CR1 + 	 1		// External interrupt control register 2
#define reserved5	EXTI_CR2 + 1		// unused

// Reset (RST) at 0x50b3
#define RST_SR		 0x50b3		    // Reset status register 1
#define reserved6	 RST_SR + 1		// unused

// Clock Control (CLK) at 0x50c0
#define CLK_ICKR	 	 0x50c0		    // Internal clock control register
#define CLK_ECKR	 CLK_ICKR	+ 1		// External clock control register
#define reserved7	 CLK_ECKR	+ 1		// unused
#define CLK_CMSR	 reserved7	+ 1		// Clock master status register
#define CLK_SWR		 CLK_CMSR	+ 1		// Clock master switch register
#define CLK_SWCR	 CLK_SWR	+ 1		// Clock switch control register
#define CLK_CKDIVR	 CLK_SWCR	+ 1		// Clock divider register
#define CLK_PCKENR1	 CLK_CKDIVR	+ 1		// Peripheral clock gating register 1
#define CLK_CSSR	 CLK_PCKENR1 + 1	// Clock security system register
#define CLK_CCOR	 CLK_CSSR	+ 1		// Configurable clock control register
#define CLK_PCKENR2	 CLK_CCOR	+ 1		// Peripheral clock gating register 2
#define CLK_CANCCR	 CLK_PCKENR2 + 1	// CAN clock control register
#define CLK_HSITRIMR CLK_CANCCR + 1		// HSI clock calibration trimming register
#define CLK_SWIMCCR	 CLK_HSITRIMR + 1	// SWIM clock control register
#define reserved8	 CLK_SWIMCCR + 1	// unused

// Window Watchdog (WWDG) at 0x50d1
#define WWDG_CR		 0x50d1		// WWDG Control Register
#define WWDG_WR		 WWDG_CR + 1		// WWDR Window Register
#define reserved9	 WWDG_WR + 1		// unused

// Independent Watchdog (IWDG) at 0x50e0
#define IWDG_KR		 0x50e0		// IWDG Key Register
#define IWDG_PR		 IWDG_KR + 1		// IWDG Prescaler Register
#define IWDG_RLR	IWDG_PR	 +  1		// IWDG Reload Register
#define reserved10	 IWDG_RLR + 1		// unused

// Auto Wake-Up (AWU) at 0x50f0
#define AWU_CSR		 0x50f0		// AWU Control/Status Register
#define AWU_APR		 AWU_CSR + 1		// AWU asynchronous prescaler buffer register
#define AWU_TBR		 AWU_APR + 1		// AWU Timebase selection register

// Beeper (BEEP) at 0x50f3
#define BEEP_CSR		 0x50f3		    // BEEP Control/Status Register
#define reserved11	 BEEP_CSR + 1		// unused

// Serial Peripheral Interface (SPI) at 0x5200
#define SPI_CR1		 0x5200		// SPI Control Register 1
#define SPI_CR2		 SPI_CR1 + 1		// SPI Control Register 2
#define SPI_ICR		 SPI_CR2 + 1		// SPI Interrupt Control Register
#define SPI_SR		 SPI_ICR + 1		// SPI Status Register
#define SPI_DR		 SPI_SR	 + 1		// SPI Data Register
#define SPI_CRCPR	 SPI_DR	 + 1		// SPI CRC Polynomial Register
#define SPI_RXCRCR	 SPI_CRCPR + 1		// SPI Rx CRC Register
#define SPI_TXCRCR	 SPI_RXCRCR + 1		// SPI Tx CRC Register
#define reserved12	 SPI_TXCRCR + 1		// unused

// I2C Bus Interface (I2C) at 0x5210
#define I2C_CR1		 0x5210		        // I2C control register 1
#define I2C_CR2		 I2C_CR1 + 1		// I2C control register 2
#define I2C_FREQR	 I2C_CR2 + 1		// I2C frequency register
#define I2C_OARL	 I2C_FREQR	+ 1		// I2C Own address register low
#define I2C_OARH	 I2C_OARL	+ 1		// I2C Own address register high
#define reserved13	 I2C_OARH	+ 1		// unused
#define I2C_DR		 reserved13	+ 1		// I2C data register
#define I2C_SR1		 I2C_DR		+ 1		// I2C status register 1
#define I2C_SR2		 I2C_SR1 + 1		// I2C status register 2
#define I2C_SR3		 I2C_SR2 + 1		// I2C status register 3
#define I2C_ITR		 I2C_SR3 + 1		// I2C interrupt control register
#define I2C_CCRL	 I2C_ITR + 1		// I2C Clock control register low
#define I2C_CCRH	 I2C_CCRL	+ 1		// I2C Clock control register high
#define I2C_TRISER	 I2C_CCRH	+ 1		// I2C TRISE register
#define I2C_PECR	 I2C_TRISER	+ 1		// I2C packet error checking register
#define reserved14	 I2C_PECR	+ 1		// unused
 
// LIN Universal asynch. receiver transmitter (UART2) at 0x5240
#define UART2_SR		 0x5240		        // UART2 Status Register
#define UART2_DR		 UART2_SR + 1		// UART2 Data Register
#define UART2_BRR1		 UART2_DR + 1		// UART2 Baud Rate Register 1
#define UART2_BRR2		 UART2_BRR1 + 1		// UART2 Baud Rate Register 2
#define UART2_CR1		 UART2_BRR2 + 1		// UART2 Control Register 1
#define UART2_CR2		 UART2_CR1 + 1		// UART2 Control Register 2
#define UART2_CR3		 UART2_CR2 + 1		// UART2 Control Register 3
#define UART2_CR4		 UART2_CR3 + 1		// UART2 Control Register 4
#define UART2_CR5		 UART2_CR4 + 1		// UART2 Control Register 5
#define UART2_CR6		 UART2_CR5 + 1		// UART2 Control Register 6
#define UART2_GTR		 UART2_CR6 + 1		// UART2 Guard time Register
#define UART2_PSCR		 UART2_GTR + 1		// UART2 Prescaler Register
#define reserved15	     UART2_PSCR + 1		// unused

// 16-Bit Timer 1 (TIM1) at 0x5250
#define TIM1_CR1		 0x5250		        // TIM1 Control register 1
#define TIM1_CR2		 TIM1_CR1 + 1		// TIM1 Control register 2
#define TIM1_SMCR		 TIM1_CR2 + 1		// TIM1 Slave Mode Control register
#define TIM1_ETR		 TIM1_SMCR + 1		// TIM1 external trigger register
#define TIM1_IER		 TIM1_ETR + 1		// TIM1 Interrupt enable register
#define TIM1_SR1		 TIM1_IER + 1		// TIM1 Status register 1
#define TIM1_SR2		 TIM1_SR1 + 1		// TIM1 Status register 2
#define TIM1_EGR		 TIM1_SR2 + 1		// TIM1 Event Generation register
#define TIM1_CCMR1		 TIM1_EGR + 1		// TIM1 Capture/Compare mode register 1
#define TIM1_CCMR2		 TIM1_CCMR + 1		// TIM1 Capture/Compare mode register 2
#define TIM1_CCMR3		 TIM1_CCMR + 1		// TIM1 Capture/Compare mode register 3
#define TIM1_CCMR4		 TIM1_CCMR + 1		// TIM1 Capture/Compare mode register 4
#define TIM1_CCER1		 TIM1_CCMR + 1		// TIM1 Capture/Compare enable register 1
#define TIM1_CCER2		 TIM1_CCER + 1		// TIM1 Capture/Compare enable register 2
#define TIM1_CNTRH		 TIM1_CCER + 1		// Data bits High
#define TIM1_CNTRL		 TIM1_CNTR + 1		// Data bits Low
#define TIM1_PSCRH		 TIM1_CNTR + 1		// Data bits High
#define TIM1_PSCRL		 TIM1_PSCR + 1		// Data bits Low
#define TIM1_ARRH		 TIM1_PSCR + 1		// Data bits High
#define TIM1_ARRL		 TIM1_ARRH + 1		// Data bits Low
#define TIM1_RCR		 TIM1_ARRL + 1		// TIM1 Repetition counter register
#define TIM1_CCR1H		 TIM1_RCR + 1		// Data bits High
#define TIM1_CCR1L		 TIM1_CCR1 + 1		// Data bits Low
#define TIM1_CCR2H		 TIM1_CCR1 + 1		// Data bits High
#define TIM1_CCR2L		 TIM1_CCR2 + 1		// Data bits Low
#define TIM1_CCR3H		 TIM1_CCR2 + 1		// Data bits High
#define TIM1_CCR3L		 TIM1_CCR3 + 1		// Data bits Low
#define TIM1_CCR4H		 TIM1_CCR3 + 1		// Data bits High
#define TIM1_CCR4L		 TIM1_CCR4 + 1		// Data bits Low
#define TIM1_BKR		 TIM1_CCR4 + 1		// TIM1 Break register
#define TIM1_DTR		 TIM1_BKR + 1		// TIM1 Dead-time register
#define TIM1_OISR		 TIM1_DTR + 1		// TIM1 Output idle state register
#define reserved16	     TIM1_OISR + 1		// unused

// 16-Bit Timer 2 (TIM2) at 0x5300
#define TIM2_CR1		 0x5300		        // TIM2 Control register 1
#define TIM2_IER		 TIM2_CR1 + 1		// TIM2 Interrupt enable register
#define TIM2_SR1		 TIM2_IER + 1		// TIM2 Status register 1
#define TIM2_SR2		 TIM2_SR1 + 1		// TIM2 Status register 2
#define TIM2_EGR		 TIM2_SR2 + 1		// TIM2 Event Generation register
#define TIM2_CCMR1		 TIM2_EGR + 1		// TIM2 Capture/Compare mode register 1
#define TIM2_CCMR2		 TIM2_CCMR1 + 1		// TIM2 Capture/Compare mode register 2
#define TIM2_CCMR3		 TIM2_CCMR2 + 1		// TIM2 Capture/Compare mode register 3
#define TIM2_CCER1		 TIM2_CCMR3 + 1		// TIM2 Capture/Compare enable register 1
#define TIM2_CCER2		 TIM2_CCER1 + 1		// TIM2 Capture/Compare enable register 2
#define TIM2_CNTRH		 TIM2_CCER2 + 1		// Data bits High
#define TIM2_CNTRL		 TIM2_CNTRH + 1		// Data bits Low
#define TIM2_PSCR		 TIM2_CNTRL + 1		// TIM2 Prescaler register
#define TIM2_ARRH		 TIM2_PSCR + 1		// Data bits High
#define TIM2_ARRL		 TIM2_ARRH + 1		// Data bits Low
#define TIM2_CCR1H		 TIM2_ARRL + 1		// Data bits High
#define TIM2_CCR1L		 TIM2_CCR1H + 1		// Data bits Low
#define TIM2_CCR2H		 TIM2_CCR1L + 1		// Data bits High
#define TIM2_CCR2L		 TIM2_CCR2H + 1		// Data bits Low
#define TIM2_CCR3H		 TIM2_CCR2L + 1		// Data bits High
#define TIM2_CCR3L		 TIM2_CCR3H + 1		// Data bits Low
#define reserved17	     TIM2_CCR3L + 1		// unused

// 16-Bit Timer 3 (TIM3) at 0x5320
#define TIM3_CR1		 0x5320		        // TIM3 Control register 1
#define TIM3_IER		 TIM3_CR1 + 1		// TIM3 Interrupt enable register
#define TIM3_SR1		 TIM3_IER + 1		// TIM3 Status register 1
#define TIM3_SR2		 TIM3_SR1 + 1		// TIM3 Status register 2
#define TIM3_EGR		 TIM3_SR2 + 1		// TIM3 Event Generation register
#define TIM3_CCMR1		 TIM3_EGR + 1		// TIM3 Capture/Compare mode register 1
#define TIM3_CCMR2		 TIM3_CCMR1 + 1		// TIM3 Capture/Compare mode register 2
#define TIM3_CCER1		 TIM3_CCMR2 + 1		// TIM3 Capture/Compare enable register 1
#define TIM3_CNTRH		 TIM3_CCER1 + 1		// Data bits High
#define TIM3_CNTRL		 TIM3_CNTRH + 1		// Data bits Low
#define TIM3_PSCR		 TIM3_CNTRL + 1		// TIM3 Prescaler register
#define TIM3_ARRH		 TIM3_PSCR + 1		// Data bits High
#define TIM3_ARRL		 TIM3_ARRH + 1		// Data bits Low
#define TIM3_CCR1H		 TIM3_ARRL + 1		// Data bits High
#define TIM3_CCR1L		 TIM3_CCR1H + 1		// Data bits Low
#define TIM3_CCR2H		 TIM3_CCR1L + 1		// Data bits High
#define TIM3_CCR2L		 TIM3_CCR2H + 1		// Data bits Low
#define reserved18	     TIM3_CCR2L + 1		// unused

// 8-Bit  Timer 4 (TIM4) at 0x5340
#define TIM4_CR1		 0x5340		        // TIM4 Control register 1
#define TIM4_IER		 TIM4_CR1 + 1		// TIM4 Interrupt enable register
#define TIM4_SR		     TIM4_IER + 1		// TIM4 Status register
#define TIM4_EGR		 TIM4_SR + 1		// TIM4 Event Generation register
#define TIM4_CNTR		 TIM4_EGR + 1		// TIM4 Counter
#define TIM4_PSCR		 TIM4_CNTR + 1		// TIM4 Prescaler register
#define TIM4_ARR		 TIM4_PSCR + 1		// TIM4 Auto-reload register
#define reserved19	     TIM4_ARR + 1		// unused

// 10-Bit A/D Converter (ADC1) at 0x53e0
#define ADC_DB0RH		 0x53e0		        // Data Buffer register 0 High
#define ADC_DB0RL		 ADC_DB0RH + 1		// Data Buffer register 0 Low
#define ADC_DB1RH		 ADC_DB0RL + 1		// Data Buffer register 1 High
#define ADC_DB1RL		 ADC_DB1RH + 1		// Data Buffer register 1 Low
#define ADC_DB2RH		 ADC_DB1RL + 1		// Data Buffer register 2 High
#define ADC_DB2RL		 ADC_DB2RH + 1		// Data Buffer register 2 Low
#define ADC_DB3RH		 ADC_DB2RL + 1		// Data Buffer register 3 High
#define ADC_DB3RL		 ADC_DB3RH + 1		// Data Buffer register 3 Low
#define ADC_DB4RH		 ADC_DB3RL + 1		// Data Buffer register 4 High
#define ADC_DB4RL		 ADC_DB4RH + 1		// Data Buffer register 4 Low
#define ADC_DB5RH		 ADC_DB4RL + 1		// Data Buffer register 5 High
#define ADC_DB5RL		 ADC_DB5RH + 1		// Data Buffer register 5 Low
#define ADC_DB6RH		 ADC_DB5RL + 1		// Data Buffer register 6 High
#define ADC_DB6RL		 ADC_DB6RH + 1		// Data Buffer register 6 Low
#define ADC_DB7RH		 ADC_DB6RL + 1		// Data Buffer register 7 High
#define ADC_DB7RL		 ADC_DB7RH + 1		// Data Buffer register 7 Low
#define ADC_DB8RH		 ADC_DB7RL + 1		// Data Buffer register 8 High
#define ADC_DB8RL		 ADC_DB8RH + 1		// Data Buffer register 8 Low
#define ADC_DB9RH		 ADC_DB8RL + 1		// Data Buffer register 9 High
#define ADC_DB9RL		 ADC_DB9RH + 1		// Data Buffer register 9 Low
#define reserved20	     ADC_DB9RL + 1		// unused
#define ADC_CSR		     reserved20 + 12	// ADC Control/Status Register
#define ADC_CR1		     ADC_CSR + 1		// ADC Configuration Register 1
#define ADC_CR2		     ADC_CR1 + 1		// ADC Configuration Register 2
#define ADC_CR3		     ADC_CR2 + 1		// ADC Configuration Register 3
#define ADC_DRH		     ADC_CR3 + 1		// Data bits High
#define ADC_DRL		     ADC_DRH + 1		// Data bits Low
#define ADC_TDRH		 ADC_DRL + 1		// Schmitt trigger disable High
#define ADC_TDRL		 ADC_TDRH + 1		// Schmitt trigger disable Low
#define ADC_HTRH		 ADC_TDRL + 1		// High Threshold Register High
#define ADC_HTRL		 ADC_HTRH + 1		// High Threshold Register Low
#define ADC_LTRH		 ADC_HTRL + 1		// Low Threshold Register High
#define ADC_LTRL		 ADC_LTRH + 1		// Low Threshold Register Low
#define ADC_AWSRH		 ADC_LTRL + 1		// Analog Watchdog Status register High
#define ADC_AWSRL		 ADC_AWSRH + 1		// Analog Watchdog Status register Low
#define ADC_AWCRH		 ADC_AWSRL + 1		// Analog Watchdog Control register High
#define ADC_AWCRL		 ADC_AWCRH + 1		// Analog Watchdog Control register Low
#define reserved21	     ADC_AWCRL + 1		// unused

//  Global configuration register (CFG) at 0x7f60
#define CFG_GCR		 0x7f60		        // CFG Global configuration register
#define reserved22	 CFG_GCR + 1		// unused

// Interrupt Software Priority Register (ITC) at 0x7f70
#define ITC_SPR1		 0x7f70		        // Interrupt Software priority register 1
#define ITC_SPR2		 ITC_SPR1 + 1		// Interrupt Software priority register 2
#define ITC_SPR3		 ITC_SPR2 + 1		// Interrupt Software priority register 3
#define ITC_SPR4		 ITC_SPR3 + 1		// Interrupt Software priority register 4
#define ITC_SPR5		 ITC_SPR4 + 1		// Interrupt Software priority register 5
#define ITC_SPR6		 ITC_SPR5 + 1		// Interrupt Software priority register 6
#define ITC_SPR7		 ITC_SPR6 + 1		// Interrupt Software priority register 7

#endif