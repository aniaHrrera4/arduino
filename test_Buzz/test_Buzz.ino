/*
  LiquidCrystal Library - Hello World

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
library works with all LCD displays that are compatible with the
Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

This sketch prints "Hello World!" to the LCD
and shows the time. 
  cd     cs q
  The circuit:
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* LCD R/W pin to ground
* 10K resistor:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)

Library originally added 18 Apr 2008
by David A. Mellis
library modified 5 Jul 2009
by Limor Fried (http://www.ladyada.net)
example added 9 Jul 2009
by Tom Igoe
modified 22 Nov 2010
by Tom Igoe

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/


// This code demonstrates how to generate two output signals
// with variable phase shift between them using an AVR Timer 

// The output shows up on Arduino pin 9, 10

// More AVR Timer Tricks at http://josh.com 
/*
  LiquidCrystal Library - Hello World

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
library works with all LCD displays that are compatible with the
Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

This sketch prints "Hello World!" to the LCD
and shows the time.

  The circuit:
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* LCD R/W pin to ground
* 10K resistor:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)

Library originally added 18 Apr 2008
by David A. Mellis
library modified 5 Jul 2009
by Limor Fried (http://www.ladyada.net)
example added 9 Jul 2009
by Tom Igoe
modified 22 Nov 2010
by Tom Igoe

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 


// This code demonstrates how to generate two output signals
// with variable phase shift between them using an AVR Timer 

// The output shows up on Arduino pin 9, 10

// More AVR Timer Tricks at http://josh.com 
int PIEZO1=9;
int PIEZO2=10;
int LED=6;
int button=7;
int buttonState = 0;    
void setup() {
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("NOJAMM !!!!");
  Serial.begin(9600);          //  setup serial



  
  pinMode(PIEZO1, OUTPUT );    // Arduino Pin  9 = OCR1A
  pinMode(PIEZO2, OUTPUT );   // Arduino Pin 10 = OCR1B
  pinMode(LED,OUTPUT);
  // Both outputs in toggle mode  
  TCCR1A = _BV( COM1A0 ) |_BV( COM1B0 );


  // CTC Waveform Generation Mode
  // TOP=ICR1  
  // Note clock is left off for now

  TCCR1B = _BV( WGM13) | _BV( WGM12);

  PIEZO1= 0;    // First output is the base, it always toggles at 0
}
// prescaler of 1 will get us 8MHz - 488Hz
// User a higher prescaler for lower freqncies

#define PRESCALER 1
#define PRESCALER_BITS 0x01

#define CLK 16000000UL    // Default clock speed is 16MHz on Arduino Uno

// Output phase shifted wave forms on Arduino Pins 9 & 10
// freq = freqnecy in Hertz (  122 < freq <8000000 )
// shift = phase shift in degrees ( 0 <= shift < 180 )

// Do do shifts 180-360 degrees, you could invert the OCR1B by doing an extra toggle using FOC

/// Note phase shifts will be rounded down to the next neared possible value so the higher the frequency, the less phase shift resolution you get. At 8Mhz, you can only have 0 or 180 degrees because there are only 2 clock ticks per cycle.  

int setWaveforms( unsigned long freq , int shift ) {

  // This assumes prescaler = 1. For lower freqnecies, use a larger prescaler.

  unsigned long clocks_per_toggle = (CLK / freq) / 2;    // /2 becuase it takes 2 toggles to make a full wave

  ICR1 = clocks_per_toggle;

  unsigned long offset_clocks = (clocks_per_toggle * shift) / 180UL; // Do mult first to save precision

  PIEZO2= offset_clocks;

  // Turn on timer now if is was not already on
//  Clock source = clkio/1 (no prescaling)
  // Note: you could use a prescaller here for lower freqnencies
  TCCR1B |= _BV( CS10 ); 

}




// Demo by cycling through some phase shifts at 50hz  

void loop() {
// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  
  setWaveforms( 500, 180 );
  delay(1000); 
    // print the number of seconds since reset:
  lcd.print("NOW cancelling out 500 HZ");

  digitalWrite(LED,HIGH);
  delay(1500);
  digitalWrite(LED, LOW);
  delay(1500);

}
