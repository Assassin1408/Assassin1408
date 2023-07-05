#include <HID-Project.h>
#include <Adafruit_NeoPixel.h>
#include <Encoder.h>
#include <Bounce2.h>

#define PIN 9  // input pin Neopixel is attached to

#define NUMPIXELS 12  // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int mode = 0;
int max_mode = 3;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
const unsigned long Interval = 2000;
unsigned long previousTime = 0;

const unsigned long eventInterval = 250;
unsigned long k1p = 0;
unsigned long k2p = 0;
unsigned long k3p = 0;
unsigned long k4p = 0;
unsigned long k5p = 0;
unsigned long k6p = 0;
unsigned long k7p = 0;
unsigned long k8p = 0;
unsigned long k9p = 0;
unsigned long s1p = 0;
unsigned long s2p = 0;
unsigned long e1p = 0;
unsigned long e2p = 0;

const int COL1 = 3;
const int COL2 = 4;
const int COL3 = 5;
const int ROW1 = 6;
const int ROW2 = 7;
const int ROW3 = 8;

int SW2 = 10;
int DT2 = 16;
int CLK2 = 14;
Encoder volumeKnob2(DT2, CLK2);
Bounce encoderButton2 = Bounce(SW2, 10);
int timeLimit = 500;
long oldPosition1 = -999;
long oldPosition2 = -999;
int SW1 = 15;
int DT1 = A0;
int CLK1 = A1;
Encoder volumeKnob1(DT1, CLK1);
Bounce encoderButton1 = Bounce(SW1, 10);

int DELAYVAL = 5;  //KEY SCANNING DELAY

void setup() {
  pinMode(COL1, OUTPUT);
  pinMode(COL2, OUTPUT);
  pinMode(COL3, OUTPUT);
  pinMode(ROW1, INPUT);
  pinMode(ROW2, INPUT);
  pinMode(ROW3, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  pixels.begin();
  setColor();
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    pixels.show();
  }
}
//MODE CHANGING
void changeMode() {
  mode++;
  if (mode == max_mode) {
    mode = 0;
  }
}
//KEY LAYOUT...
void lay0()
{
    digitalWrite(COL1, LOW);
    digitalWrite(COL2, LOW);
    digitalWrite(COL3, LOW);
}

void lay1()
{
    digitalWrite(COL1, HIGH);
    digitalWrite(COL2, LOW);
    digitalWrite(COL3, LOW);
}

void lay2()
{
    digitalWrite(COL1, LOW);
    digitalWrite(COL2, HIGH);
    digitalWrite(COL3, LOW);
}

void lay3()
{
    digitalWrite(COL1, LOW);
    digitalWrite(COL2, LOW);
    digitalWrite(COL3, HIGH);
}

//KEY FUNCTIONS...
void key_1() {
  if (mode == 0) {
    Serial.println('1');  //INSTANT REPLAY
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F10);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('1');  //INSTANT REPLAY
    
  }
  if (mode == 2) {
    Serial.println('1');  //OPEN DISCORD
    
  }
}
void key_2() {
  if (mode == 0) {
    Serial.println('2');  //SAVE INSTANT REPLAY
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F10);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('2');  //SAVE INSTANT REPLAY
    
  }
  if (mode == 2) {
    Serial.println('2');  //OPEN GOOGLE
    
  }
}
void key_3() {
  if (mode == 0) {
    Serial.println('3');  //START/STOP RECORDING
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F9);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('3');  //START/STOP RECORDING
    
  }
  if (mode == 2) {
    Serial.println('3');  //OPEN WHATSAPP
    
  }
}
void key_4() {
  if (mode == 0) {
    Serial.println('4');  //VOICE CHAT
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('4');  //VOICE CHAT
    
  }
  if (mode == 2) {
    Serial.println('4');  //OPEN VISUAL STUDIO
    
  }
}
void key_5() {
  if (mode == 0) {
    Serial.println('5');  //CAMERA
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F6);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('5');  //CAMERA
    
  }
  if (mode == 2) {
    Serial.println('5');  //TAKE SCREENSHOT
    
  }
}
void key_6() {
  if (mode == 0) {
    Serial.println('6');  //DEAFEN
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_D);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('6');  //DEAFEN
    
  }
  if (mode == 2) {
    Serial.println('6');  //SHUT DOWN
    
  }
}
void key_7() {
  if (mode == 0) {
    Serial.println('7');  //GAME LAYOUT
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press("z");
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('7');  //GAME LAYOUT
    
  }
  if (mode == 2) {
    Serial.println('7');  //SOMETHING
    
  }
}
void key_8() {
  if (mode == 0) {
    Serial.println('8');  //PHOTO MODE
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F2);
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('8');  //PHOTO MODE
    
  }
  if (mode == 2) {
    Serial.println('8');  //SOMETHING
    
  }
}
void key_9() {
  if (mode == 0) {
    Serial.println('9');  //MUTE
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press("m");
    Keyboard.releaseAll();
  }
  if (mode == 1) {
    Serial.println('9');  //MUTE
    
  }
  if (mode == 2) {
    Serial.println('9');  //SOMETHING
    
  }
}

//KEY SCANNING...
void keyscan() {
  lay0();
  delay(int(DELAYVAL / 2));

  lay1();
  delay(DELAYVAL);
  if (digitalRead(ROW1) == HIGH) {
    unsigned long k1c = millis();
    if (k1c - k1p >= eventInterval) {
      key_1();
    }
    k1p = k1c;
  } else if (digitalRead(ROW2) == HIGH) {
    unsigned long k4c = millis();
    if (k4c - k4p >= eventInterval) {
      key_4();
    }
    k4p = k4c;
  } else if (digitalRead(ROW3) == HIGH) {
    unsigned long k7c = millis();
    if (k7c - k7p >= eventInterval) {
      key_7();
    }
    k7p = k7c;
  }

  lay2();
  delay(DELAYVAL);
  if (digitalRead(ROW1) == HIGH) {
    unsigned long k2c = millis();
    if (k2c - k2p >= eventInterval) {
      key_2();
    }
    k2p = k2c;
  } else if (digitalRead(ROW2) == HIGH) {
    unsigned long k5c = millis();
    if (k5c - k5p >= eventInterval) {
      key_5();
    }
    k5p = k5c;
  } else if (digitalRead(ROW3) == HIGH) {
    unsigned long k8c = millis();
    if (k8c - k8p >= eventInterval) {
      key_8();
    }
    k8p = k8c;
  }

  lay3();
  delay(DELAYVAL);
  if (digitalRead(ROW1) == HIGH) {
    unsigned long k3c = millis();
    if (k3c - k3p >= eventInterval) {
      key_3();
    }
    k3p = k3c;
  } else if (digitalRead(ROW2) == HIGH) {
    unsigned long k6c = millis();
    if (k6c - k6p >= eventInterval) {
      key_6();
    }
    k6p = k6c;
  } else if (digitalRead(ROW3) == HIGH) {
    unsigned long k9c = millis();
    if (k9c - k9p >= eventInterval) {
      key_9();
    }
    k9p = k9c;
  }
}

void encoder1SW() {
  if (digitalRead(SW1) == LOW) {
    unsigned long s1c = millis();
    if (s1c - s1p >= eventInterval) {
      Serial.println("S1");
      Keyboard.write(KEY_PAUSE);
      Keyboard.releaseAll();
    }
    s1p = s1c;
  }
}

void encoder2SW() {
  if (digitalRead(SW2) == LOW) {
    unsigned long s2c = millis();
    if (s2c - s2p >= eventInterval) {
      Serial.println("S2");
      Serial.print(mode);
      changeMode();
    }
    s2p = s2c;
  }
}

void setColor() {
  if (mode == 0) {
    redColor = random(0, 255);
    greenColor = random(0, 255);
    blueColor = random(0, 255);
  }
  if (mode == 1) {
    redColor = 50;
    greenColor = 0;
    blueColor = 0;
  }
  if (mode == 2) {
    redColor = 50;
    greenColor = 50;
    blueColor = 50;
  }
}

void loop() {
  keyscan();
  encoder1SW();
  encoder2SW();
  long newPosition1 = volumeKnob1.read();
  if (newPosition1 != oldPosition1) {
    Serial.print(newPosition1);
    unsigned long e1c = millis();
    Serial.print(e1c);
    if ((newPosition1 - oldPosition1) > 0) {
      //volumeup
      Serial.println("volume up");
      Consumer.write(MEDIA_VOLUME_UP);
    } else {
      //volumedown
      Serial.println("volume down");
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
    Keyboard.releaseAll();
    oldPosition1 = newPosition1;
  }
  //check encoder rotation
  long newPosition2 = volumeKnob2.read();
  if (newPosition2 != oldPosition2) {
    Serial.print(newPosition2);
    unsigned long e2c = millis();
    Serial.print(e2c);
    if ((newPosition2 - oldPosition2) > 0) {
      //zoomin
      Serial.println("zoom in");
      Keyboard.press(KEY_LEFT_CTRL);
      //Keyboard.press(KEY_+);
      Keyboard.releaseAll();
    } else {
      //zoomout
      Serial.println("zoom out");
      Keyboard.press(KEY_LEFT_CTRL);
      //Keyboard.press(KEY_-);
      Keyboard.releaseAll();
    }
    Keyboard.releaseAll();
    oldPosition2 = newPosition2;
  }


  unsigned long currentTime = millis();
  if (currentTime - previousTime >= Interval) {
    setColor();
    for (int i = 0; i < NUMPIXELS; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
      pixels.show();
      previousTime = currentTime;
    }
  }
}
