#include <LedControl.h>
int DIN = 11;
int CS =  10;
int CLK = 13;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 pinMode(2, INPUT);
 pinMode(3, OUTPUT);
 lc.shutdown(0,false);       
 lc.setIntensity(0,15);
 lc.clearDisplay(0);    
}

void loop(){ 
byte s1[8]= {0b00000000,
  0b00011000,
  0b00011000,
  0b00111000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b01111110};
byte s2[8]= {0b00000000,
  0b00111100,
  0b01100110,
  0b00000110,
  0b00001100,
  0b00110000,
  0b01100000,
  0b01111110};
byte s3[8]= {0b00000000,
  0b00111100,
  0b01100110,
  0b00000110,
  0b00011100,
  0b00000110,
  0b01100110,
  0b00111100};
byte s4[8]= {0b00000000,
  0b00001100,
  0b00011100,
  0b00101100,
  0b01001100,
  0b01111110,
  0b00001100,
  0b00001100};
byte s5[8]= {0b00000000,
  0b01111110,
  0b01100000,
  0b01111100,
  0b00000110,
  0b00000110,
  0b01100110,
  0b00111100};
byte s6[8]= {0b00000000,
  0b00111100,
  0b01100110,
  0b01100000,
  0b01111100,
  0b01100110,
  0b01100110,
  0b00111100};
byte s7[8]= {0b00000000,
  0b01111110,
  0b01100110,
  0b00001100,
  0b00001100,
  0b00011000,
  0b00011000,
  0b00011000};
byte s8[8]= {0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b00111100,
  0b01100110,
  0b01100110,
  0b00111100};
byte s9[8]= {0b00000000,
  0b00111100,
  0b01100110,
  0b01100110,
  0b00111110,
  0b00000110,
  0b01100110,
  0b00111100};
byte s0[8]= {0b11111111,
  0b11000011,
  0b10100101,
  0b10011001,
  0b10011001,
  0b10100101,
  0b11000011,
  0b11111111};
printByte(s0);
digitalWrite(3,HIGH);
if (digitalRead(2) == LOW) {
    digitalWrite(3,digitalRead(2));
    printByte(s5);
    delay(1000);
    printByte(s4);
    delay(1000);
    printByte(s3);
    delay(1000);
    printByte(s2);
    delay(1000);
    printByte(s1);
    delay(1000);
    digitalWrite(3,LOW);
    printByte(s0);
    delay(1000);
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
