#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

PORTC = 0b00000000;

unsigned int i = 0b00000000;
unsigned int j = 0b1000000;
unsigned int num = 0;
  
while(1){
num = 255 - PINA;
  
i = 0;  
if( num > 0b1111){  

}
if( num > 0b1111){
num = num - j;
i = num<<4;
i = i | j;
}
else if ( num <= 0b1111 && num >= 0b1101){
i =  0b111111;
}
else if ( num <= 0b1100 && num >= 0b1010){
i =  0b111110;

}
if ( num <= 0b1001 && num >= 0b0111){
i =  0b111100;
}


else if ( num <= 0b0110 && num >= 0b0101){
i = 0b111000;
}
if ( num <= 0b0100 && num >= 0b0011){
i = 0b110000;
}
else if ( num <= 0b0010 && num >= 0b0001){
i = 0b100000;
}
if ( num <= 0b0110 && num >= 0b0000){
i = i | 0b1000000;
}

PORTC = i ;
}

return 0;
}
