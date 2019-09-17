/*
Resources:
http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
http://www.arduino.cc/en/Tutorial/Tone
https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Rotary-Encoder-test-Code
*/
#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7
#include "pitches.h"
#include <LiquidCrystal.h>
const int b1 = 10; 
const int b2 = 9; 
const int b3 = 8; 
const int l1 = A3; 
const int l2 = A4; 
const int l3 = A5;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int num = 0;
int bs1 = 0;
int bs2 = 0;
int bs3 = 0;
int count = 0;
int curs = 0;
long secs = 0;
  
void setup() {
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println("Start");
  bs1=0;
  bs2=0;
  bs3=0;
  digitalWrite(l1, LOW);
  lcd.begin(16, 2);
  lcd.print("Welcome to light-it-up!");
  lcd.setCursor(0, 1);
  lcd.print("Press any button to start...");
}

void loop() {
  
  while (bs1 == LOW && bs2 == LOW && bs3 == LOW){
    delay(800);
    if (curs<11){
      lcd.scrollDisplayLeft();
      curs++;
    } else {
      lcd.clear();
      lcd.print("Welcome to light-it-up!");
      lcd.setCursor(0, 1);
      lcd.print("Press any button to start");
      curs = 0;
    }
    bs1 = digitalRead(b1);
    bs2 = digitalRead(b2);
    bs3 = digitalRead(b3);
    Serial.print(bs1);
    if (bs1==1){digitalWrite(l1, HIGH);}
    else if (bs2==1){digitalWrite(l2, HIGH);}
    else if (bs3==1){digitalWrite(l3,HIGH);}
  }
  bs1 = 0;
  bs2 = 0;
  bs3 = 0;
  delay(1000);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  lcd.clear();
  lcd.print("Set Timer");
  lcd.setCursor(0, 1);
  
  while(1){
  count = timer();
  bs1 = digitalRead(b1);
  bs2 = digitalRead(b2);
  bs3 = digitalRead(b3);
  if (bs1==1 && bs2==1){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    break;
  }
  }
  bs1=0;
  bs2=0;
  bs3=0;
  delay(1000);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  lcd.clear();
  lcd.print("Remember order");
  delay(3000);
  int order[] = {1,2,2,3,1};
  Serial.print(sizeof(order));
  for (int o=0;o<5;o++){
    Serial.print(o);
    if (order[o]==1){
      digitalWrite(l1, HIGH);
      delay(500);
      digitalWrite(l1, LOW);
    } else if (order[o]==2) {
      digitalWrite(l2, HIGH);
      delay(500);
      digitalWrite(l2, LOW);
    }else if (order[o]==3) {
      digitalWrite(l3, HIGH);
      delay(500);
      digitalWrite(l3, LOW);
    }
    delay(500);
  }
  lcd.clear();
  lcd.print("Start?");
  secs = (millis() / 1000);
  for (int o=0;o<5;o++){
    bs1=0;
    bs2=0;
    bs3=0;
    while(bs1==0 && bs2==0 && bs3==0) {    
      bs1 = digitalRead(b1);
      bs2 = digitalRead(b2);
      bs3 = digitalRead(b3);
      lcd.setCursor(0, 1);
      int time = ((millis()/ 1000)- secs);
      lcd.print(count-time);
      lcd.print("  ");
      if (count-time <=0){
        lcd.clear();
        lcd.print("Out of Time!!");
        lcd.setCursor(0, 1);
        lcd.print("Restart the game");
        melody_sad();
        exit(1);
      }
      }
    lcd.setCursor(0, 0);
    lcd.print("You can do it");
    Serial.print("now");
    Serial.print(o);
    bs1 = digitalRead(b1);
    bs2 = digitalRead(b2);
    bs3 = digitalRead(b3);
    if (bs1==1){
      if (order[o]==1){
      digitalWrite(l1, HIGH);
      delay(500);
      digitalWrite(l1, LOW);}
      else {
      lcd.clear();
      lcd.print("Wrong option");
      lcd.setCursor(0, 1);
      lcd.print("Restart the game");
      melody_sad();
      exit(1);}
      } else if (bs2==1) {
        if (order[o]==2){  
          digitalWrite(l2, HIGH);
          delay(500);
          digitalWrite(l2, LOW);}
      else {
        lcd.clear();
        lcd.print("Wrong option");
        lcd.setCursor(0, 1);
        lcd.print("Restart the game");
        melody_sad();
        exit(1);}
      }else if (bs3==1) {
        if (order[o]==3){  
          digitalWrite(l3, HIGH);
          delay(500);
          digitalWrite(l3, LOW);}
        else {
          lcd.clear();
          lcd.print("Wrong option");
          lcd.setCursor(0, 1);
          lcd.print("Restart the game");
          melody_sad();
          exit(1);}
      }
  }
  lcd.clear();
  lcd.print("Congrats!!");
  melody_fun();
  lcd.setCursor(0, 1);
  lcd.print("Reset to replay");
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  digitalWrite(l3, HIGH);
  delay(500);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  delay(500);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  digitalWrite(l3, HIGH);
  delay(500);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  
  exit(0); 
  
}


int timer(){
  static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
  static unsigned int counter = 0;
  static unsigned int prevCounter = 0;
  int tmpdata;
  tmpdata = read_encoder();
  if( tmpdata) {
    counter4x += tmpdata;
    counter = counter4x/4;
    if (prevCounter != counter){
      lcd.clear();
      Serial.print("Counter value: ");
      Serial.println(counter);
      lcd.print("Press 1 and 2");
      lcd.setCursor(0, 1);
      lcd.print(counter);
      
    }
    prevCounter = counter;
  }
  return counter;
}

int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}

int melody_fun(){
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
    int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(13, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(13);
  }
}

int melody_sad(){
  int melody[] = {
    NOTE_B3, NOTE_C4};
    int noteDurations[] = {2, 2};
  for (int thisNote = 0; thisNote < 2; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(13, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(13);
  }
}
