#include <SPI.h>
String in="";
void setup (void) {
   Serial.begin(9600); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin ();
   SPI.setClockDivider(SPI_CLOCK_DIV8);//divide the clock by 8
}

void loop (void) {
      in=Serial.readString();
      Serial.println(in);
      char input[in.length()-1];  
      in.toCharArray(input,in.length()-1);
      char *p=input;
      char c;
      digitalWrite(SS, LOW); // enable Slave Select
    // send test string
    for (* p; c = *p; p++) 
   {
      SPI.transfer (c);
      Serial.print(c);
   }
   digitalWrite(SS, HIGH); // disable Slave Select
   delay(2000);
}
