#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigger 8
#define echo 9
#define trigger2 10
#define echo2 11
#define trigger3 6
#define echo3 7
#define Relay 5

long duration, duration2,duration3;
float distance, distance2,distance3;

LiquidCrystal_I2C lcd (0x27,16,2);

void setup()
{
Serial.begin(9600);

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(trigger2,OUTPUT);
 pinMode(echo2,INPUT);
 pinMode(trigger3,OUTPUT);
 pinMode(echo3,INPUT);
 pinMode(Relay,OUTPUT);

 lcd.init();
  
  // Turn on the backlight and print a message.
 
}

void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 duration=pulseIn(echo,HIGH);
 distance=(duration/2)/29.1;
} 
void measure_distance2()
{
  digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 duration2=pulseIn(echo2,HIGH);
 distance2=(duration2/2)/29.1;
}

void measure_distance3()
{
  digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger3,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 duration3=pulseIn(echo3,HIGH);
 distance3=(duration3/2)/29.1;
}

void loop()
{
 lcd.backlight();
 lcd.setCursor(4,0);
 lcd.print ("PKL 2021");

 measure_distance();
 measure_distance2();
 measure_distance3();
 Serial.print("Hasil Sensor 1 :");
 Serial.print(distance);
 Serial.println("cm      ");
 Serial.print("Hasil Sensor 2 :");
 Serial.print(distance2);
 Serial.println("cm      ");
 Serial.print("Hasil Sensor 3 :");
 Serial.print(distance3);
 Serial.println("cm      ");
 
 if(distance<8)
 {
   lcd.backlight();
   lcd.setCursor(4,1);
   lcd.print ("Gelas 1");
   delay(3000);
   lcd.setCursor(0,1);
   lcd.print ("Sedang Mengisi...");
   digitalWrite(Relay,HIGH);
   delay(6000);
   while(1){
   digitalWrite(Relay,LOW);
   lcd.setCursor(0,1);
   lcd.print("                   ");
   lcd.setCursor(2,1);
   lcd.print ("Gelas  Penuh");
   delay(5000);
    break; 
    }
   }

 else if(distance2<8)
 {
   lcd.backlight();
   lcd.setCursor(4,1);
   lcd.print ("Gelas 2");
   delay(3000);
   lcd.setCursor(0,1);
   lcd.print ("Sedang Mengisi...");
   digitalWrite(Relay,HIGH);
   delay(12000);
   while(1){
   digitalWrite(Relay,LOW);
   lcd.setCursor(0,1);
   lcd.print("                   ");
   lcd.setCursor(2,1);
   lcd.print ("Gelas  Penuh");
   delay(5000);
    break; 
    }
   }
else if (distance3<10)
 {
   lcd.backlight();
   lcd.setCursor(4,1);
   lcd.print ("Gelas 3");
   delay(3000);
   lcd.setCursor(0,1);
   lcd.print ("Sedang Mengisi...");
   digitalWrite(Relay,HIGH);
   delay(15000);
   while(1){
   digitalWrite(Relay,LOW);
   lcd.setCursor(0,1);
   lcd.print("                   ");
   lcd.setCursor(2,1);
   lcd.print ("Gelas  Penuh");
   delay(5000);
    break; 
    }
 }  }
