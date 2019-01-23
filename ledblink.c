#include "stm8al3188.h"

int main()
{
    int i;
    PE_DDR = 0x80;
    PE_CR1 = 0x80;

    while(1) {
        PE_ODR ^= 0x80;
        for(i=0; i<30000; i++) {}
    }
}
