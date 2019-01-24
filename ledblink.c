#include "stm8al3188.h"
#include "delay.h"

int main()
{
//    int i;
    PC_DDR = 0x80;
    PC_CR1 = 0x80;

    while(1) {
        PC_ODR ^= 0x80;
	delay_ms(500);
//        for(i=0; i<30000; i++) {}
    }
}
