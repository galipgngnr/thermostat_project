#include <global.h>

#define FRAM_ADDRESS 0x1800 // FRAM belleði için örnek bir adres seçtik

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
    int *fram_ptr = (int *)FRAM_ADDRESS; // Adresi göstericiye dönüþtür
    *fram_ptr = data; // Belirtilen adrese veriyi yaz
    SYSCFG0 |= DFWP;
}
void FRAM_init() {
    SYSCFG0 &= ~DFWP;

    // FRCTL0 registerini yazma moduna geçir ve FRPWR parolasýný yaz
    //FRCTL0 |=NWAITS_0; // FRAM gücünü aç, bekleme süresi sýfýr
    //GCCTL0|=FRPWR;
}
int read_FRAM() {
    int *fram_ptr = (int *)FRAM_ADDRESS; // Adresi göstericiye dönüþtür
    return *fram_ptr; // Belirtilen adresten veriyi oku ve döndür
}
