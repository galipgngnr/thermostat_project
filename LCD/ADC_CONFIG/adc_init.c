#include <global.h>
/*
 * adc_init.c
 *
 *  Created on: 3 Aðu 2023
 *      Author: glpgn
 */
void adc_init(){
    SYSCFG2 |= ADCPCTL1;

    ADCCTL0 |= ADCSHT_2 | ADCON;                             // ADCON, S&H=16 ADC clks
    ADCCTL1 |= ADCSHP;                                       // ADCCLK = MODOSC; sampling timer
    ADCCTL2 |= ADCRES;                                       // 10-bit conversion results
    ADCMCTL0 |= ADCINCH_1;                                   // A1 ADC input select; Vref=AVCC

}
