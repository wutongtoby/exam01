#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
PwmOut PWM(D6);
Serial pc( USBTX, USBRX );
DigitalIn Sample(D7);
Thread thread;

int i = 0;
float ADCdata[128];


void mission_thread() {
    for (int j = 0; j < 128; j++)
        pc.printf("%1.3f\r\n", ADCdata[j]);
}

int main()
{
    // write the uLCD
    uLCD.line(1, 40, 1, 60, WHITE);
    uLCD.line(1, 60, 20, 60, WHITE);
    uLCD.line(20, 60, 20, 40, WHITE);
    uLCD.line(20, 40, 1, 40, WHITE);
    uLCD.printf("107061220");

///////////////////////////////////////////////////
    PWM.period(1.0/1000);      // 1000 Hz
    float duty_cycle = 0;
    bool positive = true;
    PWM = 1.0;

    while (1) { 
        if (duty_cycle == 1.0) {
            positive = false;
        }
        else if (duty_cycle == 0) {
            positive = true;
        }
        if (positive)
            duty_cycle += 0.1;
        else
            duty_cycle -= 0.1;

        PWM.write(duty_cycle);      // duty cycle, relative to period
        pc.printf("%1.3f\r\n",duty_cycle);

        if (i < 128) {
            ADCdata[i] = Sample;
            i++;
        }
        else if (i == 128) {
           thread.start(mission_thread);
            i++;    
        } 
        wait(0.1f);
    }
}