//mgProject 2 - Graphite Piano
//Program takes in user input from seven capacitive sensors
//Plays a corresponding frequency on the buzzer 
//for each of the seven graphite piano keys that are touched
//Karan Patel and Karen Hughes

#include <CapacitiveSensor.h>
//Seven graphite key sensors and buzzer
CapacitiveSensor sensor1 = CapacitiveSensor(A0, 9);
CapacitiveSensor sensor2 = CapacitiveSensor(A1, 8);
CapacitiveSensor sensor3 = CapacitiveSensor(A2, 7);
CapacitiveSensor sensor4 = CapacitiveSensor(A3, 6);
CapacitiveSensor sensor5 = CapacitiveSensor(A4, 5);
CapacitiveSensor sensor6 = CapacitiveSensor(A5, 4);
CapacitiveSensor sensor7 = CapacitiveSensor(12, 3);
const int buzzerPin = 2;

void setup() {
  Serial.begin(9600);
}

void PrintVals(long val1, long val2, long val3, long val4, long val5, long val6, long val7){
  Serial.print(val1);
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.print(val5);
  Serial.print(" ");
  Serial.print(val6);
  Serial.print(" ");
  Serial.print(val7);
  Serial.print("\n");
}

void loop() {
  long val1 = sensor1.capacitiveSensor(30);
  long val2 = sensor2.capacitiveSensor(30);
  long val3 = sensor3.capacitiveSensor(30);
  long val4 = sensor4.capacitiveSensor(30);
  long val5 = sensor5.capacitiveSensor(30);
  long val6 = sensor6.capacitiveSensor(30);
  long val7 = sensor7.capacitiveSensor(30);
  
  PrintVals(val1, val2, val3, val4, val5, val6, val7);

  //Plays a music note depending on which graphite key is touched
  if(val1 > 4000){
    Serial.println("sensor1");
    tone(buzzerPin, 262, 250);  //A
  }
  else if(val2 > 44000){
    Serial.println("sensor2");
    tone(buzzerPin, 294, 250);  //B
  }
  else if(val3 > 4000){
    Serial.println("sensor3");
    tone(buzzerPin, 330, 250);  //C
  }
  else if(val4 > 4000){
    Serial.println("sensor4");
    tone(buzzerPin, 349, 250);  //D
  }
  else if(val5 > 4000){
    Serial.println("sensor5");
    tone(buzzerPin, 392, 250);  //E
  }
  else if(val6 > 4000){
    Serial.println("sensor6");
    tone(buzzerPin, 440, 250);  //F
  }
  else if(val7 > 4000){
    Serial.println("sensor7");
    tone(buzzerPin, 494, 250);  //G
  }
}
