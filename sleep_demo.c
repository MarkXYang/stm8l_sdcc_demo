#include "stm8al3188.h"
#include "delay.h"

void GPIO_init(void)
{
    PE_DDR = 0x80;  /* Config PE port direction register PE7 output */
    PE_CR1 = 0x80;  /* Set PE7 as pull-push output */

    PC_DDR = 0;     /* Set PortC as input */
    PC_CR1 = 0x02;  /* Set PC1 as input with pull-up */
    PC_CR2 = 0x00;  /* Disable PC1 external interrupt */
}

#if 0
void EXIT_init(void)
{
    EXTI_CR1 = 0x80; /* Enable PC1 external interrupt */
}
#endif

int main()
{
    CLK_DIVR = 0x00; /* Set Clock to 16MHz */

    //asm("sim");     /* Disable interrupt */
    GPIO_init();
//    EXTI_init();
    //asm("rim");     /* Enable interrupt */


    while(1) {
//        PE_ODR ^= 0x80;
//	delay_ms(200);
        if(PC_IDR & 0x02)
            PE_ODR = 0x80;
        else
            PE_ODR = 0x00;
    }
}
