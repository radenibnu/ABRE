int Speed_kiri = 11;  //speed motor a kiri
int M_A1 = 10; //motor a = + kiri
int M_A2 = 9; //motor a = - kiri
int M_B1 = 6; //motor b = - kanan
int M_B2 = 5; //motor b = + kanan
int Speed_kanan = 3;  //speed motor b kanan
int waterpump = 8;

int sensor_kanan = 13; //Sensor Kanan
int sensor_tengah = 12; //Sensor Tegah
int sensor_kiri = 2; //Sensor Kiri

void setup() 
{
  pinMode(waterpump, OUTPUT);
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT); 
  
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(Speed_kanan, OUTPUT);
  pinMode(Speed_kiri, OUTPUT);
  
  pinMode(sensor_kanan, INPUT);
  pinMode(sensor_tengah, INPUT);
  pinMode(sensor_kiri, INPUT);
  
  analogWrite(Speed_kanan, 140); 
  analogWrite(Speed_kiri, 150); 
//  delay(200);
}
void loop()
{
  /* Logic Sensor */  
if ((digitalRead(sensor_kiri) == 0)&&(digitalRead(sensor_tengah) == 1)&&(digitalRead(sensor_kanan) == 0))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);  
}

if ((digitalRead(sensor_kiri) == 1)&&(digitalRead(sensor_tengah) == 1)&&(digitalRead(sensor_kanan) == 0))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}
if ((digitalRead(sensor_kiri) == 1)&&(digitalRead(sensor_tengah) ==0)&&(digitalRead(sensor_kanan) == 0))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}

if ((digitalRead(sensor_kiri) == 0)&&(digitalRead(sensor_tengah) == 1)&&(digitalRead(sensor_kanan) == 1))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW); 
}
if ((digitalRead(sensor_kiri) == 0)&&(digitalRead(sensor_tengah) == 0)&&(digitalRead(sensor_kanan) == 1))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW); 
 }

if ((digitalRead(sensor_kiri) == 1)&&(digitalRead(sensor_tengah) == 1)&&(digitalRead(sensor_kanan) == 1))
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}
  /* Logic Waterpump */
  if ((digitalRead(sensor_kanan) == 1)){
    digitalWrite(waterpump, HIGH);
  }else if((digitalRead(sensor_tengah) == 1)){
    digitalWrite(waterpump, HIGH);
      }else if ((digitalRead(sensor_kiri) == 1)){
    digitalWrite(waterpump, HIGH);
  }else{
    digitalWrite(waterpump, LOW);
  }


}
