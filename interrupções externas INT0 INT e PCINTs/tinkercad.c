#define F_CPU 16000000UL

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(VALUE, BIT) (VALUE |= (1 << BIT))
#define CLEAR_BIT(VALUE, BIT) (VALUE &= (1 << BIT))
#define TOGGLE_BIT(VALUE, BIT) (VALUE ^= (1 << BIT))
#define GET_BIT(VALUE, BIT) ((VALUE >> BIT) & 1)

ISR(INT1_vect)
{
    TOGGLE_BIT(PORTB, 5);
}

int main(void)
{
    SET_BIT(DDRB, 5);
    CLEAR_BIT(PORTB, 5);

    SET_BIT(EICRA, 3); /* configura o registrador EICRA para
    definir o modo de interrupção externa INT0. Neste caso,
    o bit 1 é definido como 1, o que configura a interrupção
    externa INT0 para acionar na borda de descida
    (quando o sinal muda de nível lógico alto para baixo). */

    SET_BIT(EIMSK, 1); /* configura o registrador EIMSK para
    habilitar a interrupção externa INT0. Neste caso, o bit 0
    é definido como 1, o que habilita a interrupção externa INT0. */

    SET_BIT(EIFR, 1); /* limpa o flag de interrupção externa INT0
     . Neste caso, o bit 0 é definido como 1, o que limpa o flag
     de interrupção externa INT0, caso ele tenha sido ativado
     anteriormente.  */

    SET_BIT(SREG, 7); /* habilita as interrupções globais.
    Neste caso, o bit 7 do registrador SREG é definido como 1,
    o que habilita todas as interrupções (inclusive as
    interrupções externas).	Essas configurações são neces  */

    while (1)
    {
    }
}