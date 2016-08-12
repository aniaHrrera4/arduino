int Pin5=0;
int Pin6 = 6;       // Led 1

int Value5 = 0;    //Value Led1
int Value6 = 0;    //Value Led2

int analog0Pin = 0;      // button to start wave
int val0 = 0;             // variable to store the value read

int threshold = 512;     // threshold for button
int timer = 100;

void setup()  
{
 
 pinMode(analog0Pin, INPUT);
 pinMode(Pin5, OUTPUT);   // sets the digital pin as output
 pinMode(Pin6, OUTPUT);   // sets the digital pin as output
 
 Serial.begin(9600);          //  setup serial

}


void loop()
{ 
 val0 = analogRead(analog0Pin);    // read the input pin for button
 Serial.println(val0);             // debug value
/**
if (val0 >= threshold){ 
 for(Value5 = 0 ; Value5 <= 255; Value5+=5) // fade in (from min to max) Led 1
 { 
   analogWrite(Pin5, Value5);           // sets the value (range from 0 to 255) 
   delay(30);                            // waits for 30 milli seconds to see the dimming effect 
 } 
 for(Value5 = 255; Value5 >=0; Value5-=5)   // fade out (from max to min) 
 { 
   analogWrite(Pin5, Value5); 
   delay(30); 
     } 
 
}**/
  if (Value6= 255)                //

{ 
 for(Value6 = 0 ; Value6 <= 255; Value6+=5) // fade in (from min to max) Led 2
 { 
   analogWrite(Pin6, Value6);           // sets the value (range from 0 to 255) 
   delay(30);                            // waits for 30 milli seconds to see the dimming effect 
 } 
 for(Value6 = 255; Value6 >=0; Value6-=5)   // fade out (from max to min) 
 { 
   analogWrite(Pin6, Value6); 
   delay(30); 
     } 
}
     
}

