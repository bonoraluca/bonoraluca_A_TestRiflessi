#include <LiquidCrystal.h>

int led = 4;
int ledRgbV = 7;
int ledRgbR = 1;
int btn = 2;
int btn_ = 3;
int btn1 = 5;
int bzr = 6;
int value = 0;
LiquidCrystal lcd(12,13,8,9,10,11);

void setup() {
  digitalWrite(bzr,HIGH);
  randomSeed(millis);
  pinMode(led,OUTPUT);
  pinMode(ledRgbV,OUTPUT);
  pinMode(ledRgbR,OUTPUT);
  pinMode(btn,INPUT);
  pinMode(btn_,INPUT);
  pinMode(btn1,INPUT);
  pinMode(bzr,OUTPUT);
  lcd.begin(16,2);

}

void loop() {
  controllaBottone(digitalRead(btn));
}

int controllaBottone(int value){
  if (value == HIGH){
    eseguiTest(0);
  }
}

void eseguiTest(int tempo){
  reset();
  lcd.print("Inizio Test");
  delay(1000);
  lcd.clear();
  tempo = random(1,5000);
  delay(tempo);
  digitalWrite(led,HIGH);
  int ris = contatempo(btn_,0);
  digitalWrite(led,LOW);
  String s = "ms";
  lcd.print(ris + s);
  delay(1000);
  lcd.clear();
  tempo = random(1,5000);
  delay(tempo);
  digitalWrite(bzr,LOW);
  int ris_ = contatempo(btn1,0);
  digitalWrite(bzr,HIGH);
  lcd.print(ris_ + s);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ris + s);
  lcd.setCursor(0,1);
  lcd.print(ris_ + s);
  if (ris<1 || ris_<1){
    analogWrite(ledRgbR,255);
    lcd.clear();
    lcd.print("TROPPO PRESTO");
  }else if(ris<400 && ris_<400){
    analogWrite(ledRgbV,255);
  }else{
    analogWrite(ledRgbR,255);
  }
}


int contatempo(int button, int cont){
  while(digitalRead(button) == LOW)
  {
    cont++;
    delay(1);
  }
  return cont;
}

void reset(){
  analogWrite(ledRgbV,0);
  analogWrite(ledRgbR,0);
  lcd.clear();
}
