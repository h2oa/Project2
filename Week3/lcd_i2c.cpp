#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
    lcd.begin(16, 2);
    lcd.print("hello world");
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(seconds);
    delay(1000); // Wait for 500 millisecond(s)
    seconds += 1;
}
