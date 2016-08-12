int Pin = 3;
int PIEZOPIN=5;
int a; 
int b; 
int c;

void setup()
{
 Serial.begin(9600);
 pinMode(Pin, INPUT);
 pinMode(PIEZOPIN, OUTPUT);
}

void loop()
{
b=b+1; //for the sine wave
a=a+mod; //for the pitch modulation
if(a>40){mod=-mod;}
if(a<1){mod=-mod;}  //these loop modulation back and forth
c=75*sin(.004*b)+1600+a*5;  //all the numbers added up.
tone(5,c);

 float something = millis()/5000.0;
 int value = 128.0 + 128 * sin( something * 2.0 * PI  );
 analogWrite(Pin,value);
}

