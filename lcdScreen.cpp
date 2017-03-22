#include "lcdScreen.h"
#include <Serial_LCD_SparkFun.h>

Serial_LCD_SparkFun lcd = Serial_LCD_SparkFun();

void turnDisplayOff() {
    lcd.setBrightness(1); // off
    lcd.noDisplay();
}

void turnDisplayOn() {
    lcd.display();
    lcd.setBrightness(15); // half
}

void clearScreen() {
    lcd.clear();
}

void print(String str) {
    Serial1.print(str);
}
