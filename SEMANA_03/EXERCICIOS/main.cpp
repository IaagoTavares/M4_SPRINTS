//Link Projeto: 

#define LED 19
#define LED 21
#define LED 18
#define LED 5
#define LDR 12


int buzzer = 2;
int notasIndice  = 0;
int ledValor = 0;
int notas [30];
int botao1Estado = 1;
int botao2Estado = 1;
int tempo = 500;



void setup(){   
    pinMode(LED, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(LDR, INPUT);
    pinMode(buzzer, OUTPUT);
}

void loop(){

    atualizaLed();
    armazenaNota();
    tocaMusica();
    delay(1000);

}


void atualizaLed(){
    valorSensor = analogRead(LDR);
    if (ledValor != map(valorSensor, 32, 4063, 15, 0)){
        ledValue = map(valorSensor, 32, 4063, 15, 0);
        displayLedValue(ledValor);
        countTo(ledValor);
    }
}


void contagem(int valor ) {
    for(int i = 0; i <= valor; i++) {
        showLed(i);
        playSound(i);
        delay(timeout);
        noTone(buzzer);
    }
}

void acendeLed(int valor){
    digitalWrite(19, valor & 0b0001);
    digitalWrite(21, valor & 0b0010);
    digitalWrite(18, valor & 0b0100);
    digitalWrite(5, valor & 0b1000);
}

void tocaMusica (){
    int verificabotao2Status = digitalRead(21);
    if (verificabotao2Status != botao2Estado){
        if(verificabotao2Status == 0){
            botao2Estado = 0;
            for (int i = 0; i < notasIndice; i++){
                tocaSom(notas[i]);
                delay(tempo);
                noTone(buzzer);
            }
        } else  {
            botao2Estado = 1;
        }
    } 
}

void armazenaNota(){
    int verificabotao1Status = digitalRead(19);
    if (verificabotao1Status != botao1Estado) {
        if (verificabotao1Status == 0){
            botao1Estado = 0;
            notas[notasIndice] = ledValor;
            notasIndice++;
        } else{
            botao1Estado = 1;
        }
    }
}

void tocaSom(int valor){
    int nota = 0;
    char *nomeNota = "";
    switch(nota){
        case 0:
            nota = 37;
            nomeNota = "d1";
            break;
        case 1:
            nota = 41;
            nomeNota = "e1";
            break;
        case 2:
            nota = 44;
            nomeNota = "f1";
            break;
        case 3:
            nota = 49;
            nomeNota = "g1";
            break;
        case 4:
            nota = 55;
            nomeNota = "a1";
            break;
        case 5:
            nota = 49;
            nomeNota = "g1";
            break;
        case 6:
            nota = 55;
            nomeNota = "a1";
            break;
        case 7:
            nota = 62;
            nomeNota = "b1";
            break;
        case 8:
            nota = 33;
            nomeNota = "c1";
            break;
        case 9:
            nota = 55;
            nomeNota = "a1";
            break;
        case 10:
            nota = 49;
            nomeNota = "g1";
            break;
        case 11:
            nota = 44;
            nomeNota = "f1";
            break;
        case 12:
            nota = 41;
            nomeNota = "e1";
            break;
        case 13:
            nota = 37;
            nomeNota = "d1";
            break;
        case 14:
            nota = 33;
            nomeNota = "c1";
            break;
        case 15:
            nota = 31;
            nomeNota = "b0";
            break;
    }
    displayNote(nomeNota);
    tone(buzzer, nota);
}