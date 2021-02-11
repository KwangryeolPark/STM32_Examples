#ifndef _PRINTF_C
#define _PRINTF_C

#include "typedef.h"
#include "usart.h"

uint8_t putc(struct _USART volatile *usart, uint8_t c) {
  
  if((c == '\n') || (c == '\r')) {
    while(!(usart -> SR & (1 << TXE))); // ���� �������� ������ ��ٸ��ϴ�.
    usart -> DR = '\n';

    while(!(usart -> SR & (1 << TXE))); // ���� �������� ������ ��ٸ��ϴ�.
    usart -> DR = '\r';
  } else {
    while(!(usart -> SR & (1 << TXE))); // ���� �������� ������ ��ٸ��ϴ�.
    usart -> DR = c;    
  }

  return c;
}

uint8_t getc(struct _USART volatile *usart) {
    while(!(usart -> SR & (1 << RXNE))); // 
    
    uint8_t c = (usart -> DR);
    putc(usart, c);
    
    return c;
}
  
  

#endif