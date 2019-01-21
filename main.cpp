/*
 * Attiny841_PWM_CTC.cpp
 *
 * Created: 1/21/2019 5:21:47 PM
 * Author : Aykan
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define Output_HV9110_Pin	PINB |= (1<<PINB1)


ISR(TIMER1_COMPA_vect){
	Output_HV9110_Pin;
}


void Timer_Frequency(uint8_t freq){
	TCCR1B |= (1<<CS12) | (1<<WGM12);
	TIMSK1 |= (1<<OCIE1A);
	//=F_CPU/frequency*2*N -1
	OCR1A = (F_CPU/(freq*2*256)-1);
}





int main(void)
{
	
	DDRB |= (1<<DDB1);
	
	
	Timer_Frequency(2);
	
	sei();
	while(1);
	
	
}

