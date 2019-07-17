/**
 * Copyright (C) 2019  Nicolas Jeanmonod, ouilogique.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <Arduino.h>
#ifdef BOARD_M5STACK_CORE_ESP32
#include <M5Stack.h>
#endif

/**
 *
 */
void setupSerial()
{
    Serial.begin(BAUD_RATE);
    Serial.print("\n\n##########################");
    Serial.print("\nCOMPILATION DATE AND TIME:\n");
    Serial.print(__DATE__);
    Serial.print("\n");
    Serial.print(__TIME__);
    Serial.print("\n##########################\n\n");
}

#ifdef BOARD_M5STACK_CORE_ESP32
/**
 *
 */
void setupM5Stack()
{
    M5.begin(true, false, true, true);

    // Display compilation date and time on M5STACK.
    M5.Lcd.setTextSize(3);
    M5.Lcd.fillScreen(BLACK);

    M5.Lcd.setTextColor(BLUE, BLACK);
    M5.Lcd.setCursor(20, 10);
    M5.Lcd.print("COMPILATION");

    M5.Lcd.setCursor(20, 40);
    M5.Lcd.print("DATE AND TIME");

    M5.Lcd.setTextColor(WHITE, BLACK);
    M5.Lcd.setCursor(20, 100);
    M5.Lcd.print(__DATE__);

    M5.Lcd.setCursor(20, 130);
    M5.Lcd.print(__TIME__);
}
#endif