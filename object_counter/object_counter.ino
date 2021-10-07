#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int led_hijau = 4;
int led_merah = 5;
int buzzer = 6;
int sensor_masuk = 2;
int sensor_keluar = 3;
int objek1 = false;
int objek2 = false;
int counter;

Servo myservo;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  
  myservo.attach(9);
  myservo.write(100); 
  pinMode(led_hijau, OUTPUT);
  pinMode(led_merah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor_masuk,INPUT);
  pinMode(sensor_keluar, INPUT);
 }

 void loop() {

    int val = digitalRead(sensor_masuk);
    int val2 = digitalRead(sensor_keluar);

    if( (val == 0) && (objek1 == false) && counter > 5 ) {
      myservo.write(100); 
    }
    
    else if( (val == 0) && (objek1 == false) ){
      counter++;
      objek1 = true;

      /*tampilan ke LCD Display */
      lcd.setCursor(0,0);
      lcd.print("Jumlah Object = ");
      lcd.setCursor(6,1);
      lcd.print(counter);

      /*Coding Buzzer*/
      tone(buzzer, 500);   
      delay(300);        
      noTone(buzzer);     
      delay(300);

      /*Coding Led*/
      digitalWrite(led_hijau, HIGH);
      delay(200);
      digitalWrite(led_hijau, LOW);
      delay(200);
      digitalWrite(led_merah, LOW); 
      
      /*Coding Servo*/
      myservo.write(150);
      delay(1000);  
      myservo.write (100);
      delay(500);
      }
 
    else if( (val ==1) && (objek1 == true) ) {
      objek1 = false;
    }
         
    else if( (val2 == 0) && (objek2 == false)){
      counter--;
      objek2 = true;
      
      /*tampilan ke LCD Display */
      lcd.setCursor(0,0);
      lcd.print("Jumlah Object = ");
      Serial.println(counter);
      lcd.setCursor(6,1);
      lcd.print(counter); 

      /*Coding Servo*/
      myservo.write(150);
      delay(1000);  
      myservo.write (100);
      delay(500);

      /*Ketika tmpilan LCD lebih dari 10, set cursor */
      if (counter >= 10){
        lcd.setCursor(6,1);
        lcd.clear();  
      }
       
      if(counter == 0){
          counter = (counter - (-1));
      }
      
      digitalWrite(led_merah, LOW);  
    }
    
    else if( (val2 == 1) && (objek2 == true) ){
      objek2 = false;  
    }

    /*Kondisi Ruangan Penuh */
    else if (counter > 5){
      lcd.setCursor(0,0);
      lcd.print("Ruangan penuh !!! ");

      /*Buzzer */
      tone(buzzer, 1000);   
      delay(300);     
      noTone(buzzer);     
      delay(300);

      /*Led Merah*/
      digitalWrite(led_merah, HIGH);
    }
 }
