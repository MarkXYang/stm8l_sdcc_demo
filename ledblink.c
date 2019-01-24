#include "stm8al3188.h"
#include "delay.h"

int main()
{
    CLK_DIVR = 0x00; /* Set Clock to 16MHz */

    PE_DDR = 0x80;
    PE_CR1 = 0x80;

    while(1) {
        PE_ODR ^= 0x80;
	delay_ms(500);
    }
}
