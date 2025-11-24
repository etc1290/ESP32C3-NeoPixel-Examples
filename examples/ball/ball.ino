#include <Adafruit_NeoPixel.h>

#define LED_PIN    3
#define NUMPIXELS 25
#define BTN_PIN    4

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int ball = 1;
unsigned long speed = 50;
unsigned long long timeStamp = 0;
bool start = false;
bool isFlying = true;
bool flag = false;

void initGame(){
  speed = 50;
  start = false;
  isFlying = true;
  flag = false;
}

void renderGame(int position){
  for(int i = 0; i < 3; i++){
    pixels.setPixelColor(i, pixels.Color(0, 127, 0));
  }
  
  if(position < 3){
    pixels.setPixelColor(position, pixels.Color(127, 127, 0));
  }else{
    pixels.setPixelColor(position, pixels.Color(127, 0, 0));
  }
  pixels.show();
}

void gameOver(){
  for(int i = 0; i < 5; i++){
    pixels.fill(pixels.Color(127,0,0), 0, NUMPIXELS);
    pixels.show();
    delay(200);
    pixels.clear();
    pixels.show();
    delay(200);
  }
  initGame();
}

void win(){
  for(int i = 0; i < 5; i++){
    pixels.fill(pixels.Color(0,127,0), 0, NUMPIXELS);
    pixels.show();
    delay(200);
    pixels.clear();
    pixels.show();
    delay(200);
  }
  initGame();
}

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(BTN_PIN, INPUT_PULLUP);
  pixels.setBrightness(20);
}

void loop() {
  if(ball < 0){
    gameOver();
  }

  if(speed < 30){
    win();
  }
  
  pixels.clear();

  while(!start){
    if(!digitalRead(BTN_PIN)) start = true;
    renderGame(ball);
  }

  if(ball == NUMPIXELS){
    isFlying = false;
  }

  if(ball < 3 && !digitalRead(BTN_PIN) && flag){
    isFlying = true;
    speed -= 1;
    flag = false;
  }
  

  if(millis() - timeStamp > speed){
    if(isFlying){
      ball++;
    }else{
      ball--;
    }
    flag = true;
    timeStamp = millis();
  }

  renderGame(ball);

}

