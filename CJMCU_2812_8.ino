#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define LED_COUNT   8

#define TOUCH_PIN   2
#define POT_PIN     A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int mode = 0;
bool lastTouch = LOW;

void setup() {
  strip.begin();
  strip.show();
  pinMode(TOUCH_PIN, INPUT);
}

void loop() {
  int brightness = analogRead(POT_PIN) / 4;

  // Touch sensörle mod değişimi
  bool currentTouch = digitalRead(TOUCH_PIN);
  if (currentTouch == HIGH && lastTouch == LOW) {
    mode = (mode + 1) % 3;
    delay(200);
  }
  lastTouch = currentTouch;

  if (mode == 0) setSolidColor(strip.Color(brightness, 0, 0));        
  else if (mode == 1) setSolidColor(strip.Color(0, brightness, 0));   
  else if (mode == 2) kayma(brightness, 80);                 
}

// Sabit renkli modlar
void setSolidColor(uint32_t color) {
  strip.fill(color);
  strip.show();
  delay(50);
}

void kayma(int brightness, int delayTime) {
  static int pos = 0;
  static int direction = 1;

  strip.clear();
  strip.setPixelColor(pos, Wheel((pos * 256 / LED_COUNT) & 255, brightness));
  strip.show();
  delay(delayTime);

  pos += direction;
  if (pos == LED_COUNT - 1 || pos == 0) {
    direction = -direction;
  }
}

uint32_t Wheel(byte pos, int brightness) {
  pos = 255 - pos;
  int r, g, b;

  if (pos < 85) {
    r = 255 - pos * 3;
    g = 0;
    b = pos * 3;
  } else if (pos < 170) {
    pos -= 85;
    r = 0;
    g = pos * 3;
    b = 255 - pos * 3;
  } else {
    pos -= 170;
    r = pos * 3;
    g = 255 - pos * 3;
    b = 0;
  }

  r = (r * brightness) / 255;
  g = (g * brightness) / 255;
  b = (b * brightness) / 255;

  return strip.Color(r, g, b);
}
