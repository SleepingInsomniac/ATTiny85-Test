#include <avr/io.h>
#include <util/delay.h>

// blink an led
int main() {
  DDRB = (1 << DDB1);

  for(;;) {
    PORTB ^= (1 << PB1);
    _delay_ms(1000);
  }
}
