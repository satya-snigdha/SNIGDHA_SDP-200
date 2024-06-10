#define F_CPU 16000000UL  // Define CPU frequency as 16 MHz
#include <avr/io.h>       // Include AVR input/output header
#include <util/delay.h>   // Include delay functions

void setup() {
    // Set LED_BUILTIN (PB5) as output
    DDRB |= (1 << DDB5);
}

void loop() {
    // Set pin 12 (PD6) as input
    DDRD &= ~(1 << DDD6);

    // Read the value of pin 12 (PD6)
    uint8_t switchstate = PIND & (1 << PIND6);

    // Set pin 13 (PB5) as output
    DDRB |= (1 << DDB5);

    // Turn on the LED connected to pin 13 (PB5)
    PORTB |= (1 << PORTB5);
    _delay_ms(1000);

    // Turn off the LED connected to pin 13 (PB5)
    PORTB &= ~(1 << PORTB5);
    _delay_ms(1000);
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
    return 0;
}
