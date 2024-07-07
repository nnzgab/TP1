#include "mbed.h"
#include "arm_book_lib.h"
#define LED_1 PB_12
#define LED_1 PB_13
#define LED_1 PB_14


#define BOTON1 PA_8
#define BOTON2 PA_9
#define BOTON3 PA_10

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    alarmLed = OFF;

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}
