int sensor = 2;
int sensorvalue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue = digitalRead(sensor);
  Serial.print("Nilai sensor : ");
  Serial.println(sensorvalue);
  delay(500);
  
}
