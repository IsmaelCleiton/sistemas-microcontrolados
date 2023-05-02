#define F_CPU 16000000UL

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(VALUE, BIT) (VALUE |= (1 << BIT))
#define CLEAR_BIT(VALUE, BIT) (VALUE &= ~(1 << BIT))
#define TOGGLE_BIT(VALUE, BIT) (VALUE ^= (1 << BIT))
#define GET_BIT(VALUE, BIT) ((VALUE >> BIT) & 1)

int main(void)
{
    CLEAR_BIT(DDRB, 0); // PB0 COMO ENTRADA
    SET_BIT(DDRB, 1);   // PB1 COMO SAIDA
    SET_BIT(PORTB, 1);

    while (1)
    {
        if (GET_BIT(PINB, 0))
        {
            SET_BIT(PORTB, 1);
        }
        else
        {
            CLEAR_BIT(PORTB, 1)
        }
    }
}