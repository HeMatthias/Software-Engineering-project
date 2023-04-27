#include <wiringPi.h>

int main(void)
{
    // LED D1: Physical pin 11, BCM GPIO17, and WiringPi pin 0.
    const int D1 = 0;

    // LED D2: Physical pin 12, BCM GPIO18, and WiringPi pin 1.
    const int D2 = 1;

    // LED D3: Physical pin 13, BCM GPIO27, and WiringPi pin 2.
    const int D3 = 2;

    // LED D4: Physical pin 15, BCM GPIO22, and WiringPi pin 3.
    const int D4 = 3;

    // LED D5: Physical pin 16, BCM GPIO23, and WiringPi pin 4.
    const int D5 = 4;

    // LED D6: Physical pin 18, BCM GPIO24, and WiringPi pin 5.
    const int D6 = 5;

    // LED D7: Physical pin 8, BCM GPIO14, and WiringPi pin 15.
    const int D7 = 15;

    // LED D8: Physical pin 7, BCM GPIO4, and WiringPi pin 7.
    const int D8 = 7;

    wiringPiSetup();

    pinMode(led, OUTPUT);

    while (1) {
        digitalWrite(D1, HIGH);
        delay(500);
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        delay(500);
        digitalWrite(D2, LOW);
        digitalWrite(D3, HIGH);
        delay(500);
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
        delay(500);
        digitalWrite(D4, LOW);
        digitalWrite(D5, HIGH);
        delay(500);
        digitalWrite(D5, LOW);
        digitalWrite(D6, HIGH);
        delay(500);
        digitalWrite(D6, LOW);
        digitalWrite(D7, HIGH);
        delay(500);
        digitalWrite(D7, LOW);
        digitalWrite(D8, HIGH);
        delay(500);
        digitalWrite(D8, LOW);
        delay(500);
    }

    return 0;
}