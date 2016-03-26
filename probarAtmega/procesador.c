/*===============
	lmcapacho
	2016
=================*/

#include "procesador.h"

void CPUInit(void) // funcion CPUInit que no recibe ni retorna ningun valor
{
	DDRC = DDRD = DDRE = 0xFF; // variables inicializadas en la ultima posición
	PORTC = PORTE = 0; // variables inicializadas en la primera posición
	PORTD = (1<<RD)|(1<<WR); // cambia de estado sea de lectura ó escritura
}

void CPUWrite(uint16_t dir, uint8_t data) // recibe dos parámetros uno de 16 bits y otro de 8 bits pero no retorna
{
	DDRA = 0xFF; // tiene la última posicion de los bits
	PORTE |= (1<<ALE); //
	PORTA = (uint8_t) (dir);
	PORTC = (uint8_t) (dir>>8);
	PORTE &= ~(1<<ALE);

	PORTA = data;
	PORTD &= ~(1<<WR);
	_delay_us(10);
	PORTD |= (1<<WR);
}

uint8_t CPURead(uint16_t dir)
{
	uint8_t data;

	DDRA = 0xFF;
	PORTE |= (1<<ALE);
	PORTA = (uint8_t) (dir);
	PORTC = (uint8_t) (dir>>8);
	PORTE &= ~(1<<ALE);

	DDRA = 0;
	_delay_us(10);
	PORTD &= ~(1<<RD);
	_delay_us(10);
	data = PINA;
	PORTD |= (1<<RD);
	_delay_us(10);

	return data;
}
