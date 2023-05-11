#include <unistd.h>

#include "LEDs.h"

int main(int argc, char **argv){
    
    Leds_Init();

    Leds_Alert();
    usleep(1000000);
    Leds_Lvl(8);
    usleep(500000);
    Leds_Lvl(0);
    usleep(500000);
    Leds_Lvl(1);
    usleep(500000);
    Leds_Lvl(2);
    usleep(500000);
    Leds_Lvl(3);
    usleep(500000);
    Leds_Lvl(4);
    usleep(500000);
    Leds_Lvl(5);
    usleep(500000);
    Leds_Lvl(6);
    usleep(500000);
    Leds_Lvl(7);
    usleep(500000);
    Leds_Lvl(8);
    usleep(1000000);
    Leds_Lvl(0);

    Leds_Knight_Rider();

    Leds_Export();

    return 0;
}