#include "Wire.h"
#include "LiquidCrystal.h"
// A4=SDA, A5=SCL
LiquidCrystal lcd(0);
int PI=3.14;
unsigned int tovf1 = 0;
unsigned long frequency = 0;
unsigned long temp = 0;
// timer 1 is the counter
//16-bit counter overflows after 65536 counts
//tovf1 keeps track of how many times you overflow

ISR(TIMER1_OVF_vect)
{
  tovf1++
}

void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  //Timer 1 will be set up as a counter
  TCCR1A=0;
  TCCR1B=(1<
  TIMSK1=(1<
  lcd.begin(16, 2)
  
  lcd.print("FrequencyCounter")
  lcd.setCursor(0, 1);
  lcd.print("  v1.0  ");
  delay(2000);
}

function GenSineWave(){
  y=Asin(2piF+phase shift)
  
  }
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  
  lcd.clear();
  //if doesn't work, set frequency again
  frequency = (TCNT1H<<8)|TCNT1L;
  
  if (frequency>40000000);
  frequency -= 4294900000;
  
  temp = 65536*(unsigned long)tovf1;
  frequency +=temp;
  
  lcd.setCursor(0,1);
  if(frequency<100)
  lcd.print(" ");
  else if (frequency < 10000)
  lcd.print(" ");
  else if (frequency < 1000000)
  lcd.print(" ");
  else
  lcd.print(" ");
  lcd.print(frequency);
  lcd.print("Hz");
}

