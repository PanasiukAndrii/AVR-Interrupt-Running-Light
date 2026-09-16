#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t isRunning = 0;

int main(void) {
    DDRD |= (_BV(5) | _BV(6) | _BV(7));
    PORTD |= _BV(3);

    EICRA |=_BV(ISC10);
    EIMSK |= _BV(INT1);
    sei();

    while(1){
        if(isRunning == 1){
            PORTD |= _BV(5); _delay_ms(100); PORTD &= ~_BV(5);
            if(isRunning == 0) continue;
            PORTD |= _BV(6); _delay_ms(100); PORTD &= ~_BV(6);
            if(isRunning == 0) continue;
            PORTD |= _BV(7); _delay_ms(100); PORTD &= ~_BV(7);
        }
    }
}
ISR(INT1_vect){
    if((PIND & _BV(3)) == 0){
        isRunning = 1;
    }else{
        isRunning = 0;
        PORTD &= ~(_BV(5) | _BV(6) | _BV(7));
    }
}