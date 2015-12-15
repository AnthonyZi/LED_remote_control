#include <wiringPi.h>
#include <iostream>

#define HI 1
#define LO 0

#define DELAY 500

#define POWER 0xFF02FD

void sendbit(bool bit)
{
        digitalWrite(0, HIGH);
        delayMicroseconds(bit ? DELAY*3 : DELAY);
        digitalWrite(0, LOW);
        delayMicroseconds(DELAY);
}

void sendcode(unsigned int code)
{
        for(int i = 0; i < 24; i++)
        {
                sendbit(code & 0x800000);
                code = code << 1;
        }
}

void sendsignal(unsigned int code)
{
        digitalWrite(0, LO);
        delayMicroseconds(15*DELAY);
        digitalWrite(0, HI);
        delayMicroseconds(5*DELAY);
        for(int i = 0; i < 9; i++)
        {
                sendbit(0);
        }
        sendcode(code);
        digitalWrite(0, HI);
        delay(500);
}

int main()
{
        wiringPiSetup();
        pinMode(0, OUTPUT);

        sendsignal(POWER);

        return 0;
}
