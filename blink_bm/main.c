#include <stdint.h>

// Base addresses
#define RCC_BASE     0x40021000
#define GPIOC_BASE   0x40011000

// Registers
#define RCC_APB2ENR  (*(volatile uint32_t*)(RCC_BASE + 0x18))
#define GPIOC_CRH    (*(volatile uint32_t*)(GPIOC_BASE + 0x04))
#define GPIOC_ODR    (*(volatile uint32_t*)(GPIOC_BASE + 0x0C))

int main(void)
{
    // 1. Enable GPIOC clock
    RCC_APB2ENR |= (1 << 4);   // IOPCEN

    // 2. Configure PC13 as output (push-pull, 2 MHz)
    GPIOC_CRH &= ~(0xF << 20); // Clear CNF13[1:0] and MODE13[1:0]
    GPIOC_CRH |=  (0x2 << 20); // MODE13 = 10 (Output 2 MHz), CNF13 = 00

    while (1)
    {
        // 3. Toggle LED
        GPIOC_ODR ^= (1 << 13);

        // 4. Delay
        for (volatile int i = 0; i < 100000; i++);
    }
}