#define F_CPU 16000000UL

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(VALUE, BIT) (VALUE |= (1 << BIT))
#define CLEAR_BIT(VALUE, BIT) (VALUE &= ~(1 << BIT))
#define TOGGLE_BIT(VALUE, BIT) (VALUE ^= (1 << BIT))
#define GET_BIT(VALUE, BIT) ((VALUE >> BIT) & 1)

ISR(INT1_vect)
{
    TOGGLE_BIT()
}

int main(void)
{
    SET_BIT(DDRB, 1);   // PB1 SAIDA
    CLEAR_BIT(DDRB, 0); // PB0 ENTRADA
    SET_BIT(PORTB, 1);

    SET_BIT(PCICR, 1);
    SET_BIT(PCMSK1, 1);
    SET_BIT(PCIFR, 1);

    SET_BIT(SREG, 7);

    while (1)
    {
    }
}