#include <LiquidCrystal.h>

#define sensor    A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int gasLevel = 0;
String quality = "";

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);


  lcd.begin(16, 2);
  lcd.setCursor (0,0);
  lcd.print("                  ");
  lcd.setCursor (0,1);
  lcd.print("                  ");
  lcd.setCursor(0,0);
  lcd.print("  Air Sensor  ");
  lcd.setCursor(0,1);
  lcd.print("   Warming Up   ");
  delay(2000);

  lcd.setCursor (0,0);
  lcd.print("                  ");
  
  

}

void loop() {
  if(gasLevel<175){
      quality = "GOOD!";
    }
  else if (gasLevel > 175 && gasLevel < 225){
      quality = "Slightly polluted";
    }
  else if(gasLevel > 225 && gasLevel < 300){
      quality = "POLLUTED!";
    }
  else if(gasLevel > 300){
      quality = "HIGHLY POLLUTED";
    }

lcd.setCursor(0,0);
lcd.print("Air Quality is:");
lcd.setCursor(0,1);
lcd.print(quality);
}


/*
 * 
 * The circuit:
 * LCD RS pin to digital pin 12
 * LCD enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * ""  D5 ""  "" ""      ""  4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to SV
 * SK pot:
 * ends to +SV and ground
 * wiper to LCD VO pin (pin 3)
 */
