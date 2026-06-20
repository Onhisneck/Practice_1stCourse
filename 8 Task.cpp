#include <Adafruit_NeoPixel.h>

#define LED_PIN 3       
#define NUM_LEDS 64     

Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

const byte heartFrames[2][8][8] = {
  {
    {0,0,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
  },
  {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
  }
};

unsigned long lastFrameTime = 0; 
int currentFrame = 0;            
int frameDelay = 500;            

void setup() {
  pixels.begin();
  pixels.setBrightness(100); 
  pixels.clear();
  pixels.show();
  lastFrameTime = millis(); 
}

void loop() {
  if (millis() - lastFrameTime >= frameDelay) {
    lastFrameTime = millis(); 
    
    currentFrame = !currentFrame;
    
    if (currentFrame == 0) {
      frameDelay = 500; 
    } else {
      frameDelay = 200; 
    }

    pixels.clear(); 

    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (heartFrames[currentFrame][row][col] == 1) {
          int index = row * 8 + col; 
          pixels.setPixelColor(index, pixels.Color(230, 10, 10)); 
        }
      }
    }
    
    pixels.show(); //;)
  }
}
