#include "mbed.h"
#include "arm_book_lib.h"


#define LED_1 PB_12
#define LED_2 PB_13
#define LED_3 PB_14


#define BOTON1 PA_8
#define BOTON2 PA_9
#define BOTON3 PA_10

int main()
{
    DigitalIn tecla_1(BOTON1);
    DigitalIn tecla_2(BOTON2);
    DigitalIn tecla_3(BOTON3);

    DigitalOut ledArm(LED_1);
    DigitalOut ledReady(LED_2);
    DigitalOut ledSystem(LED_3);

    tecla_1.mode(PullDown);
    tecla_2.mode(PullDown);
    tecla_3.mode(PullDown);

    ledArm = OFF;
    ledReady = OFF;
    ledSystem = OFF;

    while (true) {
        if ( tecla_1 == ON ) {
            ledArm = ON;
        }
        else {
            ledArm = OFF;
        }
        
        if ( tecla_2 == ON ) {
            ledReady = ON;
        }
        else {
            ledReady = OFF;
        }

        if ( tecla_3 == ON ) {
            ledSystem = ON;
        }
        else {
            ledSystem = OFF;
        }
    }
}
