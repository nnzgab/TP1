//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

//PA_2    serial2 TX
//PA_3    serial2 RX

//PB_12    led1
//PB_13    led2
//PB_14    led3

//PA_8    btn1
//PA_9    btn2
//PA_10   btn3


//=====[Defines]===============================================================

#define LED_1 PB_12
#define LED_2 PB_13
#define LED_3 PB_14


#define BOTON1 PA_8
#define BOTON2 PA_9
#define BOTON3 PA_10

#define UART_TX PA_2
#define UART_TX PA_23

//=====[Declaration and initialization of public global objects]===============
DigitalIn tecla_1(BOTON1);
DigitalIn tecla_2(BOTON2);
DigitalIn tecla_3(BOTON3);

DigitalOut ledArm(LED_1);
DigitalOut ledReady(LED_2);
DigitalOut ledSystem(LED_3);

UnbufferedSerial uartUsb(UARTTX, UARTRX, 115200);

//=====[Declaration and initialization of public global variables]=============


//=====[Declarations (prototypes) of public functions]=========================

void inputsInit();
void outputsInit();

void botonCopiaLed();

//void uartTask();
//void availableCommands();


//=====[Main function, the program entry point after power on or reset]========

int main()
{
    inputsInit();
    outputsInit();

    bool estadoTest = OFF;
    int timeout = 0;

    while (true) {
        estadoTest = ON;
        botonCopiaLed();
        //uartTask();
    }
}

//=====[Implementations of public functions]===================================

void inputsInit()
{
    tecla_1.mode(PullDown);
    tecla_2.mode(PullDown);
    tecla_3.mode(PullDown);
}

void outputsInit()
{
    ledArm = OFF;
    ledReady = OFF;
    ledSystem = OFF;;
}

void botonCopiaLed(){
    
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


/*

void uartTask()
{
    char receivedChar = '\0'; //declaramos un char inicializada con el caracter nulo
    if( uartUsb.readable() ) { //preguntaos si hay algo para leer
        uartUsb.read( &receivedChar, 1 ); //engorroso por que tengo que decir cuantos bytes quiero leer
        if ( receivedChar == '1') {
            if ( alarmState ) {
                uartUsb.write( "The alarm is activated\r\n", 24);
            } else {
                uartUsb.write( "The alarm is not activated\r\n", 28);
            }
        } else {
            availableCommands();
        }
    }
}

void availableCommands()
{
    uartUsb.write( "Available commands:\r\n", 21 );
    uartUsb.write( "Press '1' to get the alarm state\r\n\r\n", 36 );
}

*/
