//Link Projeto: https://wokwi.com/projects/346630306404500052

#define LED 19
#define LED 21
#define LED 18
#define LED 5
#define LDR 12


int buzzer = 2;
int botaoGrava = 32;
int botaoToca = 33;

int melody[] = {
  264, 297, 330, 352, 396, 440, 495, 495, 440, 396, 352,
  330, 297, 264, 297, 330
};

int memoria[30] = {};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(115200);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botaoGrava, INPUT_PULLUP);
  pinMode(botaoToca, OUTPUT);

}




void loop() {
  

  // pintaLed();

  tocaMusica();
  gravador();
  reprodutor();

}



void reprodutor(){
    if(digitalRead(botaoGrava) == LOW){
      noTone(buzzer);
      delay(500);
      for (int thisNote = 0; thisNote < 30; thisNote++) {
        tone(buzzer, memoria[thisNote]);
      }
    }

}

void gravador(){
  if(digitalRead(botaoGrava) == LOW){
    int x = analogRead(LDR);
    memoria[-1] = melody[map(x,4063, 32, 0, 15)];

    Serial.println("Nota gravada com sucesso!");
    delay(1000);
  }
}


void pintaLed(){
  int x = analogRead(LDR);
  int n = map(x,4063, 32, 0, 15);

  digitalWrite(19, n & 0b0001);
  digitalWrite(21, n & 0b0010);
  digitalWrite(18, n & 0b0100);
  digitalWrite(5, n & 0b1000);
  Serial.println(n);
}


void tocaMusica(){
  int x = analogRead(LDR);
  int n = map(x,4063, 32, 0, 15);
  int i = 0; 
  int j = 0;

  switch(n) {
  case 0:
    i = 0;
    j = 0;
    break;
  case 1:
    i = 1;
    j = 1;
    break;
  case 2:
    i = 2;
    j = 2;
    break;
  case 3:
    i = 3;
    j = 3;
    break;
  case 4:
    i = 4;
    j = 4;
    break;
  case 5:
    i = 5;
    j = 5;
    break;
  case 6:
    i = 6;
    j = 6;
    break;
  case 7:
    i = 7;
    j = 7;
    break;
  case 8:
    i = 8;
    j = 8;
    break;
  case 9:
    i = 9;
    j = 9;
    break;
  case 10:
    i = 10;
    j = 10;
    break;
  case 11:
    i = 11;
    j = 11;
    break;
  case 12:
    i = 12;
    j = 12;
    break;
  case 13:
    i = 13;
    j = 13;
    break;
  case 14:
    i = 14;
    j = 14;
    break;
  case 15:
    i = 15;
    j = 15;
    break;
  }
  tone(buzzer, melody[i]);
  delay(50);
}

