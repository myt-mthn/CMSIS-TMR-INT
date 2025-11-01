#include "stm32f1xx.h"

void GPIO_Config(void);
void TIM2_Config(void);

int main(void)
{
    GPIO_Config();     // Setup LED pin
    TIM2_Config();     // Setup Timer 2

    while (1)
    {
        // Main loop does nothing — LED toggled in interrupt
    }
}

//---------------- GPIO CONFIG ----------------
void GPIO_Config(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // Enable GPIOA clock
    GPIOA->CRL &= ~(0xF << (5 * 4));      // Clear PA5 config
    GPIOA->CRL |=  (0x2 << (5 * 4));      // PA5 output, push-pull, 2MHz
}

//---------------- TIMER2 CONFIG ----------------
void TIM2_Config(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;   // Enable Timer2 clock

    TIM2->PSC = 7999;     // Prescaler
    TIM2->ARR = 499;      // Auto reload (for 0.5s delay)
    TIM2->DIER |= 1;      // Update interrupt enable
    TIM2->CR1 |= 1;       // Enable counter

    NVIC_EnableIRQ(TIM2_IRQn);  // Enable IRQ in NVIC
}

//---------------- INTERRUPT HANDLER ----------------
void TIM2_IRQHandler(void)
{
    if (TIM2->SR & 1)     // If update flag is set
    {
        TIM2->SR &= ~1;   // Clear update flag
        GPIOA->ODR ^= (1 << 5);  // Toggle LED
    }
}
