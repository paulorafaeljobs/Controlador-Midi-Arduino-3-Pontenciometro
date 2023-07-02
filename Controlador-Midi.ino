int valPot1 = 0;
int lastValPot1 = 0;

int valPot2 = 1;
int lastValPot2 = 1;

int valPot3 = 2;
int lastValPot3 = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valPot1 = analogRead(0)/8;
  valPot2 = analogRead(1)/8;
  valPot3 = analogRead(2)/8;
  if(valPot1 != lastValPot1){
    mensagemMIDI( 176,2,valPot1);
    lastValPot1 = valPot1;
  }
  if(valPot2 != lastValPot2){
    mensagemMIDI( 176,3,valPot2);
    lastValPot2 = valPot2;
  }
  if(valPot3 != lastValPot3){
    mensagemMIDI( 176,4,valPot3);
    lastValPot3 = valPot3;
  }
  delay(10);
}

void mensagemMIDI(byte comando,byte data1, byte data2){
  Serial.write(comando);
  Serial.write(data1);
  Serial.write(data2);
}
