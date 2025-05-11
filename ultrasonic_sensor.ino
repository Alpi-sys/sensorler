#define trig 4
#define echo 2

long sure, mesafe;

void setup() 
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.println("mesafe sensoru baslatiliyor");
  delay(3000);
}

void loop() 
{
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  sure = pulseIn(echo, HIGH);

  mesafe = (sure/2) * 0.0343;
  Serial.print(mesafe);
  Serial.println("cm");
  delay(1000); 
}

