#include "stm8s.h"
/*#include "__assert__.h"*/

void delay(void)
{
    for (uint16_t d = 0; d < 9000; d++) {
        for (uint8_t c = 0; c < 30; c++);
    }

}


void main(void)
{
    uint32_t a;
    
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovat MCU na 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);

    UART1_Init((uint32_t)115200, 
               UART1_WORDLENGTH_8D,
               UART1_STOPBITS_1,
               UART1_PARITY_NO,
               UART1_SYNCMODE_CLOCK_DISABLE,
               UART1_MODE_TXRX_ENABLE
              );
    UART1_Cmd(ENABLE);

    while (1) {
        GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
        delay();
        GPIO_WriteLow(GPIOC, GPIO_PIN_5);
        delay();
        a = 23;
    }
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  (void)file;
  (void)line;

  /* User can add their own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
