#include "stm32f103x6.h"

void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm__("nop");
    }
}

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;
    GPIOC->CRH |= GPIO_CRH_MODE13_1;

    while (1)
    {
        GPIOC->ODR ^= GPIO_ODR_ODR13; // Toggle LED
        delay(500000);
    }
}
