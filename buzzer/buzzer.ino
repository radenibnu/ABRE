const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(300);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(300);        // ...for 1sec
  
}
