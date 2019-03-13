int led = 7;
int ledRgb = 8;
int btn = 9;
int btn_ = 10;
int btn1 = 11;
int value = 0;

void setup() {
  randomSeed(millis);
  pinMode(led,OUTPUT);
  pinMode(ledRgb,OUTPUT);
  pinMode(btn,INPUT);

}

void loop() {
  controllaBottone(int btn, int value);

}

void controllaBottone(int bottone, int value){
  if (value == HIGH){
    iniziaTest();
  }
}

void iniziaTest(int tempo){
  tempo = random(1,5000);
  delay(tempo);
  while(btn == LOW){
  digitalWrite(led,HIGH);
  }
  int ris = cntatempo(led,0);
  lcd.print(ris + "ms");
  
}


int contatempo(int value, int cont){
  while(value == LOW)
  {
    cont++;
    delay(1);
  }
  return value;
}
