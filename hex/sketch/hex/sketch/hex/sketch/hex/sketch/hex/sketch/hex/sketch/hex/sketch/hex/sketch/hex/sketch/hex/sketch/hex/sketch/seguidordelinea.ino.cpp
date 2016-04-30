#include <Arduino.h>
#line 1
#line 1 "C:\\Users\\Hector\\Desktop\\seguidordelinea\\seguidordelinea.ino"
/*#define M1A 19 //Motor 1A
#define M1B 18 //Motor 1B
#define M2A 17 //Motor 2A
#define M2B 16 //Motor 2B
#define PIN_PWM 11
#define VEL 100
#define S1 0
#define S2 1
#define _UMBRAL_ 200
unsigned long timeserial;

void setup() {
  serial.begin[9600];
  timeserial=mills[];
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  stop(10000);
  analogWrite(PIN_PWM, VEL);
}

void loop() {
  byte SDER=(digitalRead(S1)>_UMBRAL_)&0:;;
  byte SIZQ=(digitalRead(S2)>_UMBRAL_)&0:;;
  if(SDER&&SIZQ)
    stop(0);
  else if (!SDER&&SIZQ)
    DER(0);
  else if (SDER&&!SIZQ)
    IZQ(0);
  else
    ADE(0);
  if(milis()-timeserial>500){
    timeserial=milis();
    serial.print("sensor1:");
    serial.print(analogRead(S1));
    serial.print("sensor2:");
    serial.print(analogRead(S2));
    }
}
  void ATR(uint8_t time){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  delay(time);
  }
  void ADE(uint8_t time){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
  delay(time);
  }
  void DER(uint8_t time){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
  delay(time);
  }
  void IZQ(uint8_t time){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  delay(time);
  }
  void STOP(uint8_t time){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,LOW);
  delay(time);
  }
*/
  #define M1A 19 //Motor 1A
  #define M1B 18 //Motor 1B
  #define M2A 17 //Motor 2A
  #define M2B 16 //Motor 2B
  #define PIN_PWM 11 //Modulacion porancho de pulso - Emular salida analogicacon salida digital
  #define VEL 100 //Velocidad
  #define S1 0 //IZQ
  #define S2 1 //DER
  #define _UMBRAL_ 200 //Umbral de lossensores
  unsigned long timeserial;
  void setup (){Serial.begin(9600);
  timeserial = millis();
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  STOP(10000);
  analogWrite(PIN_PWM, VEL);
  }
  void loop(){
    byte SDER = (analogRead(S1)> _UMBRAL_)?0:1;
    byte SIZQ = (analogRead(S2)> _UMBRAL_)?0:1;
    if(SDER && SIZQ)
    STOP(0);
    else if (!SDER && SIZQ)
    DER(0);
    else if (SDER && !SIZQ)IZQ(0);
    else ADE(0);
    if(millis() - timeserial > 500){
      timeserial = millis();
    }
    Serial.print("Sensor1: ");//
    Serial.print(SDER);
    Serial.print(analogRead(S1));
    Serial.print(" Sensor2: ");//
    Serial.println(SIZQ);
    Serial.println(analogRead(S2));
    }
    }
    void ATR(uint16_t time){
      digitalWrite(M1A, HIGH);
      digitalWrite(M1B, LOW);
      digitalWrite(M2A, HIGH);
      digitalWrite(M2B, LOW);
      delay(time);
      }
      void ADE(uint16_t time){
        digitalWrite(M1A, LOW);
        digitalWrite(M1B, HIGH);
        digitalWrite(M2A, LOW);
        digitalWrite(M2B, HIGH);
        delay(time);
        }
        void DER(uint16_t time){//Llanta Izquierda
          digitalWrite(M1A, HIGH);
          digitalWrite(M1B, LOW);//llanta Derecha
          digitalWrite(M2A, LOW);
          digitalWrite(M2B, HIGH);
          delay(time);
          }
          void IZQ(uint16_t time){//Llanta Izquierda
            digitalWrite(M1A, LOW);
            digitalWrite(M1B, HIGH);//Llanta Derecha
            digitalWrite(M2A, HIGH);
            digitalWrite(M2B, LOW);
            delay(time);
            }
            void STOP(uint16_t time){
              digitalWrite(M1A, LOW);
              digitalWrite(M1B, LOW);
              digitalWrite(M2A, LOW);
              digitalWrite(M2B, LOW);
              delay(time);
              }
              
  }


