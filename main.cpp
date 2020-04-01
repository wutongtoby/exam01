#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
int main()
{
    uLCD.line(1, 40, 1, 60, WHITE);
    uLCD.line(1, 60, 20, 60, WHITE);
    uLCD.line(20, 60, 20, 40, WHITE);
    uLCD.line(20, 40, 1, 40, WHITE);
    uLCD.printf("107061220");
}