#include <avr/io.h>

#define MOSI PB0
#define SCK PB2

void spi_setup() {
  DDRB  = (1 << PB0) | (1 << PB2);     // Setting direction of PB1 and PB2 as output
  USICR = (1 << USIWM0);               // Choosing SPI aka three wire mode
}

int main() {
  spi_setup();

  for (;;) {
    USIDR = 0b01010101;                       // Writing data bytes in Data register
    while (USIOIF == 0) {                     // Checking USI data counter overflow flag to detect the end of transmission every byte
      USICR |= (1 << USICLK) | (1 << USITC);  // Enabling clock for transmission and generating clock for slave device
    }
    USISR |= (1 << USIOIF);                   // Clearing counter overflow flag
  }
}
