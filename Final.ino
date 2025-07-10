#include <Energia.h>

#define a3f  208
#define b3f  233
#define b3   247
#define c4   261
#define c4s  277
#define e4f  311
#define f4   349
#define a4f  415
#define b4f  466
#define b4   493
#define c5   523
#define c5s  554
#define e5f  622
#define f5   698
#define f5s  740
#define a5f  831
#define rest -1

#define PIEZO 40   
#define RED_LED 39   
#define GREEN_LED 38 
#define BLUE_LED 37  
#define BUTTON_START 32 
#define BUTTON_TEMPO 33 

volatile int beatlength = 85; 
float beatseparationconstant = 0.3;

int a = 4; // part index
int b = 0; // song index
volatile bool isPlaying = false;

int song1_intro_melody[] = {c5s, e5f, e5f, f5, a5f, f5s, f5, e5f, c5s, e5f, rest, a4f, a4f};
int song1_intro_rhythmn[] = {6, 10, 6, 6, 1, 1, 1, 1, 6, 10, 4, 2, 10};

int song1_verse1_melody[] = {
  rest, c4s, c4s, c4s, c4s, e4f, rest, c4, b3f, a3f,
  rest, b3f, b3f, c4, c4s, a3f, a4f, a4f, e4f,
  rest, b3f, b3f, c4, c4s, b3f, c4s, e4f, rest, c4, b3f, b3f, a3f,
  rest, b3f, b3f, c4, c4s, a3f, a3f, e4f, e4f, e4f, f4, e4f,
  c4s, e4f, f4, c4s, e4f, e4f, e4f, f4, e4f, a3f,
  rest, b3f, c4, c4s, a3f, rest, e4f, f4, e4f
};

int song1_verse1_rhythmn[] = {
  2, 1, 1, 1, 1, 2, 1, 1, 1, 5,
  1, 1, 1, 1, 3, 1, 2, 1, 5,
  1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3,
  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4,
  5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
  2, 1, 1, 1, 3, 1, 1, 1, 3
};

int song1_chorus_melody[] = {
  b4f, b4f, a4f, a4f,
  f5, f5, e5f, b4f, b4f, a4f, a4f, e5f, e5f, c5s, c5, b4f,
  c5s, c5s, c5s, c5s,
  c5s, e5f, c5, b4f, a4f, a4f, a4f, e5f, c5s,
  b4f, b4f, a4f, a4f,
  f5, f5, e5f, b4f, b4f, a4f, a4f, a5f, c5, c5s, c5, b4f,
  c5s, c5s, c5s, c5s,
  c5s, e5f, c5, b4f, a4f, rest, a4f, e5f, c5s, rest
};

int song1_chorus_rhythmn[] = {
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8,
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8, 4
};

void setup() {
  pinMode(PIEZO, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_TEMPO, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_TEMPO), getFaster, FALLING);
  
  setLEDColor(255,255,255);                                   
}

void loop() {
  checkStartButton();
  if (isPlaying) {
    play();
  }
}

void play() {
  int notelength;
  
  if (a == 1 || a == 2) {
    notelength = beatlength * song1_intro_rhythmn[b];
    if (song1_intro_melody[b] > 0) {
      setLEDColor(0, 255, 0); 
      tone(PIEZO, song1_intro_melody[b], notelength);
    }
    b++;
    if (b >= sizeof(song1_intro_melody) / sizeof(int)) {
      a++;
      b = 0;
    }
  }
  else if (a == 3 || a == 5) { 
    notelength = beatlength * 2 * song1_verse1_rhythmn[b];
    if (song1_verse1_melody[b] > 0) {
      setLEDColor(0, 0, 255); 
      tone(PIEZO, song1_verse1_melody[b], notelength);
    }
    b++;
    if (b >= sizeof(song1_verse1_melody) / sizeof(int)) {
      a++;
      b = 0;
    }
  }
  else if (a == 4 || a == 6) { 
    notelength = beatlength * song1_chorus_rhythmn[b];
    if (song1_chorus_melody[b] > 0) {
      setLEDColor(255, 0, 0); 
      tone(PIEZO, song1_chorus_melody[b], notelength);
    }
    b++;
    if (b >= sizeof(song1_chorus_melody) / sizeof(int)) {
      a++;
      b = 0;
    }
  }
  
  delay(notelength);
  noTone(PIEZO);
  setLEDColor(255, 255, 255); 
  delay(notelength * beatseparationconstant);
  
  if (a == 7) { 
    a = 1;
  }
}

void setLEDColor(int r, int g, int b) {
  analogWrite(RED_LED, 255 - constrain(r, 0, 255));
  analogWrite(GREEN_LED, 255 - constrain(g, 0, 255));
  analogWrite(BLUE_LED, 255 - constrain(b, 0, 255));
}

void checkStartButton() {
  static bool buttonPressed = false;
  int reading = digitalRead(BUTTON_START);

  if (reading == LOW) {
    if (!buttonPressed) {
      buttonPressed = true;
      delay(20);
      
      if (isPlaying) {
        isPlaying = false; 
        setLEDColor(255, 255, 255); 
      } else {
        a = 1;
        b = 0;
        isPlaying = true;
      }
    }
  } else {
    buttonPressed = false;
  }
}

void getFaster() {
  static unsigned long lastInterrupt = 0;
  unsigned long now = millis();
  
  // Software debounce
  if (now - lastInterrupt > 200) {
    beatlength = beatlength / 2;
    if (beatlength < 20) {
      beatlength = 85;
    }
    lastInterrupt = now;
  }
}
