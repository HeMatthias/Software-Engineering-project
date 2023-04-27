#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // LED D1: Physical pin 11, BCM GPIO17, and WiringPi pin 0.
    // LED D2: Physical pin 12, BCM GPIO18, and WiringPi pin 1.
    // LED D3: Physical pin 13, BCM GPIO27, and WiringPi pin 2.
    // LED D4: Physical pin 15, BCM GPIO22, and WiringPi pin 3.
    // LED D5: Physical pin 16, BCM GPIO23, and WiringPi pin 4.
    // LED D6: Physical pin 18, BCM GPIO24, and WiringPi pin 5.
    // LED D7: Physical pin 8, BCM GPIO14, and WiringPi pin 15.
    // LED D8: Physical pin 7, BCM GPIO4, and WiringPi pin 7.

    Init_Led_D1();

    // Toggle LED 50 ms on, 50ms off, 100 times (10 seconds)

    for (int i = 0; i < 100; i++) {
        Led_D1_On();
        usleep(500000);

        Led_D1_Off();
        usleep(500000);
    }

    Led_D1_Reset();

    return 0;
}

void Init_Led_D1(){
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/export");
        exit(1);
    }

    if (write(fd, "17", 2) != 2) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }

    close(fd);

    // Set the pin to be an output by writing "out" to /sys/class/gpio/gpio24/direction

    fd = open("/sys/class/gpio/gpio17/direction", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio17/direction");
        exit(1);
    }

    if (write(fd, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio17/direction");
        exit(1);
    }

    close(fd);
}

void Led_D1_On (){
    fd = open("/sys/class/gpio/gpio17/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio17/value");
        exit(1);
    }

    if (write(fd, "1", 1) != 1) {
        perror("Error writing to /sys/class/gpio/gpio17/value");
        exit(1);
    }

    close(fd);
}

void Led_D1_Off (){
    fd = open("/sys/class/gpio/gpio17/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio17/value");
        exit(1);
    }

    if (write(fd, "0", 1) != 1) {
        perror("Error writing to /sys/class/gpio/gpio17/value");
        exit(1);
    }

    close(fd);
}

void Led_D1_Reset(){
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/unexport");
        exit(1);
    }

    if (write(fd, "17", 2) != 2) {
        perror("Error writing to /sys/class/gpio/unexport");
        exit(1);
    }

    close(fd);
}