#include <virtuabotixRTC.h>                                                                              
int waterpump = 4;

// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8);

void setup()  {      
  Serial.begin(9600);
  pinMode(waterpump, OUTPUT);

// Set the current date, and time in the following format:
// seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(00, 20, 17, 6, 26, 7, 2021);
}
 
void loop()  {                                                                                           //| 
// This allows for the update of variables for time or accessing the individual elements.                //|
  myRTC.updateTime();                                                                                    //| 
                                                                                                         //| 
// Start printing elements as individuals                                                                //|   
  Serial.print("Current Date / Time: ");                                                                 //| 
  Serial.print(myRTC.dayofmonth);                                                                        //| 
  Serial.print("/");                                                                                     //| 
  Serial.print(myRTC.month);                                                                             //| 
  Serial.print("/");                                                                                     //| 
  Serial.print(myRTC.year);                                                                              //| 
  Serial.print("  ");                                                                                    //| 
  Serial.print(myRTC.hours);                                                                             //| 
  Serial.print(":");                                                                                     //| 
  Serial.print(myRTC.minutes);                                                                           //| 
  Serial.print(":");                                                                                     //| 
  Serial.println(myRTC.seconds);                                                                         //| 
                                                                                                         //| 
// Delay so the program doesn't print non-stop                                                           //| 
  delay( 1000);                                                                                         

   if (myRTC.minutes == 21){
    digitalWrite(waterpump, HIGH);
   }else if(myRTC.minutes == 23){
    digitalWrite(waterpump, LOW);
   }
}                                                                                                        
                                                                                                        

  
