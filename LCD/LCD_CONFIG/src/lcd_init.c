/*
 * lcd_init.c
 *
 *  Created on: 3 Aðu 2023
 *      Author: glpgn
 */

#include <global.h>

// Configure XT1 oscillator

void lcd_init(){
    P4SEL0 |= BIT1 | BIT2;                                     // P4.2~P4.1: crystal pins
    do
    {
        CSCTL7 &= ~(XT1OFFG | DCOFFG);                         // Clear XT1 and DCO fault flag
        SFRIFG1 &= ~OFIFG;
    }while (SFRIFG1 & OFIFG);                                  // Test oscillator fault flag
    CSCTL6 = (CSCTL6 & ~(XT1DRIVE_3)) | XT1DRIVE_2;            // Higher drive strength and current consumption for XT1 oscillator
    CSCTL6 =1<<5;
    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings

    PM5CTL0 &= ~LOCKLPM5;

    // Configure LCD pins
    SYSCFG2 |= LCDPCTL;                                        // R13/R23/R33/LCDCAP0/LCDCAP1 pins selected
    LCDCTL0 = LCDSSEL__ACLK;
    LCDPCTL0 = 0xFC0F;
    LCDPCTL1 = 0xFC0F;
    LCDCTL0 |= LCD4MUX | LCDDIV_1;                                // Turn on LCD, 4-mux selected

    // LCD Operation - Mode 3, internal 3.08v, charge pump 256Hz
    LCDVCTL = LCDCPEN | LCDREFEN | VLCD_13 | ( LCDCPFSEL0 | LCDCPFSEL1 | LCDCPFSEL2 | LCDCPFSEL3);

    LCDCSSEL0 = 0x000F;                                        // Configure COMs and SEGs
    LCDCSSEL1 = 0x0000;                                        // L0, L1, L2, L3: COM pins

    LCDM0 = 0x21;                                              // L0 = COM0, L1 = COM1
    LCDM1 = 0x84;                                              // L2 = COM2, L3 = COM3

    LCDBLKCTL |= LCDBLKPRE_4;                     // BLK_FREQ = 1Hz, Blinking mode2
    LCDBLKCTL &= ~LCDBLKMOD0; // Blink modunu devre dýþý býrak
    LCDBLKCTL &= ~LCDBLKMOD1;

    // Display "123456"



    LCDCTL0 |= LCDON;
    LCDM5&=~0xFF;
    LCDM6&=~0xFF;
    LCDM7&=~0xFF;
    LCDM8&=~0xFF;
    LCDM9&=~0xFF;
    LCDM10&=~0xFF;
    LCDM11&=~0xFF;
    LCDM12&=~0xFF;
    LCDM13&=~0xFF;
    LCDM14&=~0xFF;
    LCDM15&=~0xFF;

}
