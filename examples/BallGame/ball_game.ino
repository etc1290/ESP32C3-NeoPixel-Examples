#include <Adafruit_NeoPixel.h>

#define LED_PIN    3
#define NUMPIXELS 25
#define BTN_PIN    4
#define FLOOR 3

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int ball = 1;
unsigned long speed = 50;
unsigned long long timeStamp = 0;
bool start = false;
bool isFlying = true;
bool buttonReleased = false;

void initGame(){
  speed = 50;
  start = false;
  isFlying = true;
  buttonReleased = false;
}

void renderGame(int position){
  for(int i = 0; i < FLOOR; i++){
    pixels.setPixelColor(i, pixels.Color(0, 127, 0));
  }
  
  if(position < FLOOR){
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

  if(ball < FLOOR && !digitalRead(BTN_PIN) && buttonReleased){
    isFlying = true;
    speed -= 1;
    buttonReleased = false;
  }
  else if(digitalRead(BTN_PIN) && ball < FLOOR){
    buttonReleased = true;
  }

  

  if(millis() - timeStamp > speed){
    if(isFlying){
      ball++;
    }else{
      ball--;
    }
    timeStamp = millis();
  }

  renderGame(ball);

}

