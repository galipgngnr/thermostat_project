#include <global.h>

#define FRAM_ADDRESS 0x1800 // FRAM belle�i i�in �rnek bir adres se�tik

void gpio_config(){
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR|=BIT0;

    P4DIR |= BIT0;
    P4OUT &=~ BIT0;
    //encoder init & adc gpio

    P1DIR&=~BIT3|~BIT2|~BIT1|~BIT4;;
    P1IES|=BIT3|BIT2|BIT4;
    P1IE|=BIT3|BIT2|BIT4;
    P1IFG&=~BIT3|~BIT2|~BIT4;
}
void write_FRAM(int data) {
    SYSCFG0 &= ~DFWP;
    int *fram_ptr = (int *)FRAM_ADDRESS; // Adresi g�stericiye d�n��t�r
    *fram_ptr = data; // Belirtilen adrese veriyi yaz
    SYSCFG0 |= DFWP;
}
void FRAM_init() {
    SYSCFG0 &= ~DFWP;

    // FRCTL0 registerini yazma moduna ge�ir ve FRPWR parolas�n� yaz
    //FRCTL0 |=NWAITS_0; // FRAM g�c�n� a�, bekleme s�resi s�f�r
    //GCCTL0|=FRPWR;
}
int read_FRAM() {
    int *fram_ptr = (int *)FRAM_ADDRESS; // Adresi g�stericiye d�n��t�r
    return *fram_ptr; // Belirtilen adresten veriyi oku ve d�nd�r
}
