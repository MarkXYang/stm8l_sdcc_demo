#include "stm8al3188.h"
#include "delay.h"

int main()
{
    CLK_DIVR = 0x00; /* Set Clock to 16MHz */

    PC_DDR = 0x80;
    PC_CR1 = 0x80;

    while(1) {
        PC_ODR ^= 0x80;
	delay_ms(500);
    }
}
