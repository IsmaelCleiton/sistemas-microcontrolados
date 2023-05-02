#define F_CPU 16000000UL

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(VALUE, BIT) (VALUE |= (1 << BIT))
#define CLEAR_BIT(VALUE, BIT) (VALUE &= (1 << BIT))
#define TOGGLE_BIT(VALUE, BIT) (VALUE ^= (1 << BIT))
#define GET_BIT(VALUE, BIT) ((VALUE >> BIT) & 1)

ISR(PCINT0_vect)
{
    TOGGLE_BIT(PORTB, 5);
}

int main(void)
{
    SET_BIT(DDRB, 5);
    CLEAR_BIT(PORTB, 5);

    SET_BIT(PCICR, 0); /* configura o registrador PCICR para habilitar a interrupção de mudança de estado em um grupo específico de pinos de entrada/saída do microcontrolador. Nesse caso, o grupo de pinos selecionado é o PCINT0, que abrange os pinos PB0 a PB7 do microcontrolador. */

    SET_BIT(PCMSK0, 0); /* habilita a interrupção de mudança de estado em um pino específico dentro do grupo PCINT0. Nesse caso, o pino selecionado é o PB0. */

    SET_BIT(PCIFR, 0); /* limpa o flag de interrupção para o grupo PCINT0. Isso é feito para garantir que qualquer interrupção que tenha ocorrido anteriormente nesse grupo seja tratada adequadamente antes de habilitar novas interrupções.  */

    SET_BIT(SREG, 7); /* habilita as interrupções globais no microcontrolador. Isso permite que o processador interrompa a execução do programa em qualquer momento para tratar uma interrupção que tenha sido habilitada anteriormente. É importante habilitar as interrupções globais apenas após a configuração de todas as interrupções específicas que serão utilizadas no programa, para evitar que interrupções indesejadas ocorram.  */

    while (1)
    {
    }
}