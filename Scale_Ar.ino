#include <stdlib.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711_ADC Loadcell  (3,2);
SoftwareSerial nodemcu(7, 8); 
void setup()
{
  Serial.begin(9600);
  nodemcu.begin(9600);
  Loadcell .begin();
  Loadcell .start(2000);
  Loadcell .setCalFactor (999.0);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("do an 2 ");
  lcd.setCursor (0,1);
  lcd.print ("weight:   "); 
}

void loop()
{ 
   Loadcell .update ();
   float i = Loadcell .getData();
   lcd.setCursor(8, 1);
   nodemcu.println(i);
   lcd.print(i);
  }
