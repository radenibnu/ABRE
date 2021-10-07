#include <NewPing.h>
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
//int pinRedLed = 11;
//int pinGreenLed = 8;
int buzzer = 12;
int pinSensor = A0;
int THRESHOLD =400;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
void setup() {
//pinMode(pinRedLed, OUTPUT);
//pinMode(pinGreenLed, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(pinSensor, INPUT);
Serial.begin(9600);
}
void loop() {
delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
Serial.print("Jarak: ");
Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
Serial.println("cm");
int jarak=0;
jarak=sonar.ping_cm();
Serial.print("ini jarak : ");
Serial.println(jarak);
int analogValue = analogRead(pinSensor);
Serial.println(analogValue);
//digitalWrite(pinGreenLed, HIGH);
if (analogValue >= THRESHOLD) {
//digitalWrite(pinGreenLed, LOW);
//digitalWrite(pinRedLed, HIGH);
digitalWrite(buzzer, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
delay(500);
}else if(jarak>=5 && jarak <= 6){
  digitalWrite(buzzer, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
delay(500);
}
else {
//digitalWrite(pinRedLed, LOW);
digitalWrite(buzzer, LOW);
}
delay(1000);
}
