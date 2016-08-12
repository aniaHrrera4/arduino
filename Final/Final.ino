int PIEZOPIN1=5;
int PIEZOPIN2=13;
int Pin = 3;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(PIEZOPIN1, OUTPUT);
pinMode(PIEZOPIN2, OUTPUT);
}



void PIE1(){

tone(PIEZO1,500);

}
void PIE2(){  
 delay(4);
 tone(PIEZO2,500);
  
  }
void loop() {
  // put your main code here, to run repeatedly:
PIE1();
PIE2(); 




}
