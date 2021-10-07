#include <virtuabotixRTC.h>                                                                              
int waterpump = 4;

virtuabotixRTC myRTC(6, 7, 8);

void setup()  {      
  Serial.begin(9600);
  pinMode(waterpump, OUTPUT);
  myRTC.setDS1302Time(00, 20, 17, 6, 26, 7, 2021);
}
 
void loop()  {                                                                                                 
  myRTC.updateTime();                                                                                     
                                                                   
  Serial.print("Current Date / Time: ");                                                                  
  Serial.print(myRTC.dayofmonth);                                                                         
  Serial.print("/");                                                                                      
  Serial.print(myRTC.month);                                                                              
  Serial.print("/");                                                                                      
  Serial.print(myRTC.year);                                                                               
  Serial.print("  ");                                                                                     
  Serial.print(myRTC.hours);                                                                              
  Serial.print(":");                                                                                      
  Serial.print(myRTC.minutes);                                                                            
  Serial.print(":");                                                                                      
  Serial.println(myRTC.seconds);                                                                                                                                   
  delay( 1000);                                                                                         

   if (myRTC.minutes == 21){
    digitalWrite(waterpump, HIGH);
   }else if(myRTC.minutes == 23){
    digitalWrite(waterpump, LOW);
   }
}                                                                                                        
                                                                                                        

  
