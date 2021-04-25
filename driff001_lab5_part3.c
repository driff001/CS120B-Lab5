/*	Author: Dylan Riffel
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
/*Demo Link:      */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
void Tick();
unsigned int count = 0;
enum S_STATES { S_Wait, S_Press1, S_Press2,S_Press3,S_Press4,S_Press5,S_Press6,S_Press7,S_Press8,S_PressWait1} S_State;

void Tick(){

   switch(S_State) //transistions
   {
    case S_Wait: //wait state 
    

        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if(  (~PINA & 0x01) == 0x01 && count == 0 ){
            S_State = S_Press1;
        }
        else if((~PINA & 0x01) == 0x01 && count == 1 ){
            S_State = S_Press2;
        }
        else if((~PINA & 0x01) && count == 2 ){
            S_State = S_Press3;
        }
        else if((~PINA & 0x01) == 0x01 && count == 3 ){
            S_State = S_Press4;
        }
        else if((~PINA & 0x01) == 0x01 && count == 4 ){
            S_State = S_Press5;
        }
        else if((~PINA & 0x01) == 0x01 && count == 5 ){
            S_State = S_Press6;
        }
	else if((~PINA & 0x01) == 0x01 && count == 6 ){
            S_State = S_Press7;
        }
	 else if((~PINA & 0x01) == 0x01 && count == 7 ){
            S_State = S_Press8;
        }

    	break;

    case S_Press1: //increment state
        if((~PINA & 0x01) == 0b00){
          S_State = S_Wait;
        }
        else if ( (~PINA & 0x01) == 0b01){
          S_State = S_PressWait1;
        }
        
        break;

    case S_Press2: //decrement state
        if((~PINA & 0x01) == 0b00){
        S_State = S_Wait;
        }
        else if ( (~PINA & 0x01) == 0b01){
          S_State = S_PressWait1;
        }
        
        break;

    case S_Press3: //increment state
        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if((~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }
        
        break;

     case S_Press4: //increment state
        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if((~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }

        break;
      case S_Press5: //increment state
        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if((~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }

        break;
      case S_Press6: //increment state
        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if( (~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }

        break;
       case S_Press7: //increment state
        if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if((~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }
	break;

        case S_Press8:
         if((~PINA & 0x01) == 0b00){
            S_State = S_Wait;
        }
        else if((~PINA & 0x01) == 0x01){
            S_State = S_PressWait1;
        }
  


        break;





    case S_PressWait1: 
        if ((~PINA & 0x01) == 0b00){
          S_State = S_Wait;
        }
      
  
       else if(  (~PINA & 0x01) == 0x01 && count == 0 ){
            S_State = S_Press1;
        }
        else if((~PINA & 0x01) == 0x01 && count == 1 ){
            S_State = S_Press2;
        }
        else if((~PINA & 0x01) && count == 2 ){
            S_State = S_Press3;
        }
        else if((~PINA & 0x01) == 0x01 && count == 3 ){
            S_State = S_Press4;
        }
        else if((~PINA & 0x01) == 0x01 && count == 4 ){
            S_State = S_Press5;
        }
        else if((~PINA & 0x01) == 0x01 && count == 5 ){
            S_State = S_Press6;
        }
        else if((~PINA & 0x01) && count == 6 ){
            S_State = S_Press7;
        }
	 else if((~PINA & 0x01) && count == 7 ){
            S_State = S_Press8;
        }

        else{
            S_State = S_PressWait1;
	}
        break;
   }

   switch(S_State) //State actions
   {
      case S_Press1:
        ++count;
        PORTB = 0b01;
        
        break;

      case S_Wait: //wait state
        break;

      case S_Press2: //incrment state
       
        ++count;
        PORTB = 0b11;
        break;
      case S_Press3: //incrment state
	++count;
        PORTB = 0b111;
        break; 
      case S_Press4:
        ++count;	
        PORTB = 0b1111;
        break;
      case S_Press5:
	++count;
        PORTB = 0b11111;
	break;
      case S_Press6:
	++count;
        PORTB = 0b111111;
        break;
      case S_Press7:
   
        PORTB = 0b1111111;
        break;
      case S_Press8:
        count = 0;
        PORTB = 0b0;
        break;

	
      case S_PressWait1:
        break;

   }
}


int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00;
    PORTB = 0x00;
    DDRC = 0xFF; 
    /* Insert your solution below */
    S_State = S_Wait;
    while (1) {
        Tick();
    }
    return 0;
}
