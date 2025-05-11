#define BUTTON 4 

/*
gnd --> gnd
vcc --> 5V
sig --> d4
*/

struct touch { 
	 byte basildi = LOW; 
	 byte basiliyor = LOW; 
}; 
touch touch; 

void setup() 
{ 
	 pinMode(BUTTON, INPUT); 
	 Serial.begin(9600); 
} 
void loop() 
{ 
	 touch.basiliyor = isTouchPressed(BUTTON); 
	 if (touch.basildi != touch.basiliyor) { 
	   Serial.println("Sensore basildi "); 
	 } 
	 touch.basildi = touch.basiliyor; 
} 
bool isTouchPressed(int pin) 
{ 
	 return digitalRead(pin) == HIGH; 
} 
