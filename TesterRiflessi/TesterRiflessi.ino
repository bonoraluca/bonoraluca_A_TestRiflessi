#include <LiquidCrystal.h>

int led = 7;
int ledRgb = 8;
int btn = 9;
int btn_ = 10;
int btn1 = 11;
int bzr = 6;
int value = 0;
LiquidCrystal lcd(12,13,7,8,9,10);

void setup() {
  randomSeed(millis);
  pinMode(led,OUTPUT);
  pinMode(ledRgb,OUTPUT);
  pinMode(btn,INPUT);
  pinMode(bzr,OUTPUT);

}

void loop() {
  controllaBottone(btn,value);

}

void controllaBottone(int bottone, int value){
  if (value == HIGH){
    iniziaTest(0);
  }
}

void iniziaTest(int tempo){
  lcd.clear();
  tempo = random(1,5000);
  delay(tempo);
  digitalWrite(led,HIGH);
  int ris = contatempo(btn_,0);
  digitalWrite(led,LOW);
  lcd.print(ris + "ms");
  delay(3000);
  lcd.clear();
  tempo = random(3000,5000);
  delay(tempo);
  digitalWrite(bzr,HIGH);
  int ris_ = contatempo(btn1,0);
  lcd.print(ris_ + "ms");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ris + "ms");
  lcd.setCursor(0,1);
  lcd.print(ris_ + "ms");
}


int contatempo(int value, int cont){
  while(value == LOW)
  {
    cont++;
    delay(1);
  }
  return value;
}
