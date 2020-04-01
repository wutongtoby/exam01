#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
int main()
{
    uLCD.printf("107061220");
    uLCD.line(1, 1, 1, 20, WHITE);
    uLCD.line(1, 20, 20, 20, WHITE);
    uLCD.line(20, 20, 20, 1, WHITE);
    uLCD.line(20, 1, 1, 1, WHITE);
}