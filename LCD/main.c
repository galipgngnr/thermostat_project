#include <global.h>



int random=0,counter=120,eleman=1,temp_counter=0,mod_counter=0,onluk=0,birlik=0,yuzluk=0,adcValue = 512,current=0,adc_map_int=0,button_counter=0,current_birlik=0,current_onluk=0,current_yuzluk=0,lock_flag=1;
float thermistorResistance=0,temperatureKelvin=0,set_heat=0,adc_result=0,adc_map=0;

char str[10];
const char digit_dizi_8[10] =
{
0x5F,                                                      // "0"
0x06,                                                      // "1"
0x6B,                                                      // "2"
0x2F,                                                      // "3"
0x36,                                                      // "4"
0x3D,                                                      // "5"
0x7D,                                                      // "6"
0x07,                                                      // "7"
0x7F,                                                      // "8"
0x37                                                      // "9"
};const char digit_dizi[10] =
{
0x5F,                                                      // "0"
0x06,                                                      // "1"
0x6B,                                                      // "2"
0x2F,                                                      // "3"
0x36,                                                      // "4"
0x3D,                                                      // "5"
0x7D,                                                      // "6"
0x07,                                                      // "7"
0x7F,                                                      // "8"
0x37                                                      // "9"
};


float map(float val, float iMin, float iMax, float oMin, float oMax) {

    return (val - iMin) * (oMax - oMin) / (iMax - iMin) + oMin;
}



int main( void )
{

    lcd_init();
    adc_init();
    gpio_config();
    TA0CCR0 = 32768 * 5 - 1; // 32768 çevrim/saniye (ACLK) kullanarak 5 saniye için Timer A CCR0 deðeri
    TA0CTL = TASSEL_1 | ID_3 | MC_1; // ACLK kullan, 64 kesirli bölmeyi kullan, Up mode
    TA0CCTL0 = CCIE; // Timer A CCR0 kesmesini etkinleþtir


    TA1CCR0 = 1000 * 5 - 1;
    TA1CTL = TASSEL_1 | ID_3 | MC_1;
    TA1CCTL0 = CCIE;

    adc_result=ADCMEM0;
    P4OUT&=~BIT0;

    counter = read_FRAM();
    __enable_interrupt();


 while(1)
 {

     birlik=counter%10;
     onluk=(counter/10)%10;
     yuzluk=counter/100;
     P1IFG&=~BIT3;
     P1IFG&=~BIT2;

     LCDM7|=0x80;
     LCDM7|=digit_dizi[birlik];
     LCDM8 |=digit_dizi[onluk];
     LCDM9 |=digit_dizi[yuzluk];
     set_heat=(float)counter/10;

     LCDM5 |=0x10;
     P1OUT|=BIT0;



     if(lock_flag==1){
         LCDM6 |=0x40;
     }
     adc_map =map(adc_result, 0,1023,0,30);
     adc_map_int=adc_map*10;

     if(adc_map<=set_heat){

         LCDM5 |=0x80;//gunes
     }
     else{

         LCDM5 &=~0x80;//gunes
     }
     current_birlik=adc_map_int%10;
     current_onluk=(adc_map_int/10)%10;
     current_yuzluk=adc_map_int/100;

     LCDM7|=0x80;
     LCDM15 |=0x80;
     switch_case_9(current_onluk);
     switch_case_8(current_yuzluk);
     switch_case_on(current_birlik);
     write_FRAM(counter); // FRAM'a veriyi yaz

     __delay_cycles(100);
 }
}
#pragma vector=PORT1_VECTOR
__interrupt void Port1_ISR(void)
{
    if(!(P1IN&BIT4)){
        while(!(P1IN&BIT4));
        if(lock_flag==1){

            lock_flag=0;
            TA0CTL |= TACLR;
            LCDM6 &=~0x40;
            P1IFG&=~BIT4;
            P4OUT|=BIT0;
        }
        else{
            lock_flag=1;
            LCDM6 |=0x40;
            P1IFG&=~BIT4;
        }
    }

    if(counter!=340){

        if(lock_flag==0){
        if(!(P1IN&BIT3)){
            TA0CTL |= TACLR;
        counter++;
    }
    else {
        counter--;
        counter++;
    }}}
    if(counter!=120)
    {
        if(lock_flag==0){
    if(!(P1IN&BIT2)){
        TA0CTL |= TACLR;
        counter--;
    }
    else {
        counter++;
        counter--;
    }}}

    P1IFG&=~BIT3;
    P1IFG&=~BIT2;
    LCDM8 &=~0xFF;
    LCDM9 &=~0xFF;
    LCDM7&=~0xFF;

}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TimerA0_ISR(void) {
    lock_flag=1;
    P4OUT&=~BIT0;

}
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0_ISR(void) {
    ADCCTL0 |= ADCENC | ADCSC;
    adc_result=ADCMEM0;
    TA1CTL |= TACLR;


}
