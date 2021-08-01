#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int pin = A0;
DHT11 dht11(pin);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Level & ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity");
  delay(2000);
  lcd.clear();
  lcd.print("Starting");
  delay(1000);
}
 
void loop(){
  int wl=analogRead(A1);
  int a;
  float temp, humi;

  if ((a = dht11.read(humi, temp)) == 0){
    lcd.clear();
    delay(500);
    lcd.setCursor(0, 0);
    lcd.print("Water Level");
    lcd.setCursor(0, 1);
    lcd.print("Humidity");
    lcd.setCursor(12, 0);
    lcd.print(wl);
    lcd.setCursor(9, 1);
    lcd.print(humi);
    lcd.print(" %");
    delay(3000);
  }
  else{
    lcd.println();
    lcd.print("Error");
  }
}
