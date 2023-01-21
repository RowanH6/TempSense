#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(5);
DallasTemperature sensors(&oneWire);

float Celcius = 0;
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0,0);
}

void loop(void)
{
  sensors.requestTemperatures(); 
  Celcius = sensors.getTempCByIndex(0);

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(Celcius);
  lcd.setCursor(6,1);
  lcd.print("C");
  
  delay(1000);
}
