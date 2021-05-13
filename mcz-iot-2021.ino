/*******************************************************************************
* RoboCore Kit Iniciante V8 para Arduino - Fazendo Barulho 1
* Pisca-pisca sonoro.
*******************************************************************************/

const int frequencia = 2500;
const int TRIG = 3;
const int ECHO = 2;
const int VIBRA_PIN = 6;
const int BUZZER_PIN = 10;
const int distancia_obstaculo = 20;

const int pinoLEDR = 11;
const int pinoLEDG = 5;
const int pinoLEDB = 1;

void setup(){
  // Distancia
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  // Buzzer
  pinMode(10, OUTPUT); // configura o pino com o buzzer como saída
  // VIBRA
  pinMode(VIBRA_PIN, OUTPUT);
  // RGB
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
}

void loop(){
  // Distancia
  int distancia = sensor_morcego(TRIG,ECHO);
    if(distancia <= distancia_obstaculo){
      Serial.print("Com obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(VIBRA_PIN, HIGH);
      tone(BUZZER_PIN, frequencia);
      delay(500);
      tone(BUZZER_PIN, frequencia);
      //
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 255);
    }
    else{
      Serial.print("Sem obstaculo: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(VIBRA_PIN, LOW);
      noTone(BUZZER_PIN);
      //
      //
      analogWrite(pinoLEDR, 255);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 255);
    }
  delay(100);
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
