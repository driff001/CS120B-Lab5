/*	Author: dylan
 *  Partner(s) Name: Jo Mama
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    PORTB = 0x00;
    DDRB = 0xFF;
    int count = 0;
    unsigned char button = 0x00;
    unsigned char led = 0x01; 
    /* Insert your solution below */
    while (1) {
        button =  ~PINA & 0x01;

         if (button ){
         ++count;
	 led =  0x0C;
	 if(count > 0){
         led =  0x03; 
         }
	 }
	 else{
	 led = 0x30;
         }
         
	 
	 

	 PORTB = led;
    }
    
}
