#include <global.h>



extern int switch_case_on(int on){
    switch (on){
    case 0:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0F;
        LCDM15|=0x50;
        break;
    case 1:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x06;
        break;
    case 2:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0B;
        LCDM15|=0x60;
        break;
    case 3:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0F;
        LCDM15|=0x20;
        break;
    case 4:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x06;
        LCDM15|=0x30;
        break;
    case 5:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0D;
        LCDM15|=0x30;
        break;
    case 6:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0D;
        LCDM15|=0x70;
        break;
    case 7:
        LCDM5&=~0x0D;
        LCDM15&=~0x70;
        LCDM5|=0x07;
        break;
    case 8:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x0F;
        LCDM15|=0x70;
        break;
    case 9:
        LCDM5&=~0x0F;
        LCDM15&=~0x70;
        LCDM5|=0x07;
        LCDM15|=0x30;
        break;



    }
}
extern int switch_case_9(int dokuz){
    switch (dokuz){
    case 0:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0F;
        LCDM14|=0x50;
        break;
    case 1:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x06;
        break;
    case 2:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0B;
        LCDM14|=0x60;
        break;
    case 3:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0F;
        LCDM14|=0x20;
        break;
    case 4:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x06;
        LCDM14|=0x30;
        break;
    case 5:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0D;
        LCDM14|=0x30;
        break;
    case 6:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0D;
        LCDM14|=0x70;
        break;
    case 7:
        LCDM15&=~0x0D;
        LCDM14&=~0x70;
        LCDM15|=0x07;
        break;
    case 8:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x0F;
        LCDM14|=0x70;
        break;
    case 9:
        LCDM15&=~0x0F;
        LCDM14&=~0x70;
        LCDM15|=0x07;
        LCDM14|=0x30;
        break;



    }
}
extern int switch_case_8(int sekiz){
        switch (sekiz){
        case 0:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0F;
            LCDM13|=0x50;
            break;
        case 1:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x06;
            break;
        case 2:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0B;
            LCDM13|=0x60;
            break;
        case 3:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0F;
            LCDM13|=0x20;
            break;
        case 4:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x06;
            LCDM13|=0x30;
            break;
        case 5:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0D;
            LCDM13|=0x30;
            break;
        case 6:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0D;
            LCDM13|=0x70;
            break;
        case 7:
            LCDM14&=~0x0D;
            LCDM13&=~0x70;
            LCDM14|=0x07;
            break;
        case 8:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0F;
            LCDM13|=0x70;
            break;
        case 9:
            LCDM14&=~0x0F;
            LCDM13&=~0x70;
            LCDM14|=0x0E;
            LCDM13|=0x30;
            break;



        }




}
