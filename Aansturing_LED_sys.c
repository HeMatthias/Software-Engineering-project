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

// Vanaf hier een nieuwe c code gemaakt

/*
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Define the pins for each LED
#define LED_D1 17
#define LED_D2 18
#define LED_D3 27
#define LED_D4 22
#define LED_D5 23
#define LED_D6 24
#define LED_D7 14

// Function prototypes
void Init_Led(int led_pin);
void Led_On(int led_pin);
void Led_Off(int led_pin);
void Led_Reset(int led_pin);
void Knight_Rider();

int main()
{
    // Initialize all LEDs
    Init_Led(LED_D1);
    Init_Led(LED_D2);
    Init_Led(LED_D3);
    Init_Led(LED_D4);
    Init_Led(LED_D5);
    Init_Led(LED_D6);
    Init_Led(LED_D7);

    // Toggle each LED 50 ms on, 50ms off, 100 times (10 seconds)
    for (int i = 0; i < 50; i++) {
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_On(LED_D6);
        Led_On(LED_D7);
        usleep(50000);

        Led_Off(LED_D1);
        Led_Off(LED_D2);
        Led_Off(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        usleep(50000);
    }

    Knight_Rider();

    // Reset all LEDs
    Led_Reset(LED_D1);
    Led_Reset(LED_D2);
    Led_Reset(LED_D3);
    Led_Reset(LED_D4);
    Led_Reset(LED_D5);
    Led_Reset(LED_D6);
    Led_Reset(LED_D7);

    return 0;
}

void Init_Led(int led_pin){
    // Export the GPIO pin
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/export");
        exit(1);
    }

    char buffer[4];
    int len = snprintf(buffer, sizeof(buffer), "%d", led_pin);
    if (write(fd, buffer, len) != len) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }

    close(fd);

    // Set the pin to be an output by writing "out" to /sys/class/gpio/gpioXX/direction
    char path[40];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", led_pin);

    fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpioXX/direction");
        exit(1);
    }

    if (write(fd, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpioXX/direction");
        exit(1);
    }

    close(fd);
}

void Led_On(int led_pin){
    // Write "1" to /sys/class/gpio/gpioXX/value to turn on the LED
    char path[35];
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", led_pin);

    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpioXX/value");
        exit(1);
    }

    if (write(fd, "1", 1) != 1) {
        perror("Error writing to gpio value file");
        exit(1);
    }

    close(fd);
}

void Led_Off(int led_pin) {
    char path[50];
    sprintf(path, "/sys/class/gpio/gpio%d/value", led_pin);
    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Unable to open gpio value file");
        exit(1);
    }

    if (write(fd, "0", 1) != 1) {
        perror("Error writing to gpio value file");
        exit(1);
    }

    close(fd);
}

void Led_Reset(int led_pin) {
    int fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/unexport");
        exit(1);
    }

    char pin_str[4];
    sprintf(pin_str, "%d", led_pin);
    if (write(fd, pin_str, strlen(pin_str)) != strlen(pin_str)) {
        perror("Error writing to /sys/class/gpio/unexport");
        exit(1);
    }

    close(fd);
}

void Knight_Rider()
{
    int delay_time = 100000; // Delay in microseconds (100ms)

    for(int i = 0; i < 2; i++)
    {
        Led_On(LED_D1);
        usleep(delay_time);
        Led_Off(LED_D1);

        Led_On(LED_D2);
        usleep(delay_time);
        Led_Off(LED_D2);

        Led_On(LED_D3);
        usleep(delay_time);
        Led_Off(LED_D3);

        Led_On(LED_D4);
        usleep(delay_time);
        Led_Off(LED_D4);

        Led_On(LED_D5);
        usleep(delay_time);
        Led_Off(LED_D5);

        Led_On(LED_D6);
        usleep(delay_time);
        Led_Off(LED_D6);

        Led_On(LED_D7);
        usleep(delay_time);
        Led_Off(LED_D7);

        Led_On(LED_D6);
        usleep(delay_time);
        Led_Off(LED_D6);

        Led_On(LED_D5);
        usleep(delay_time);
        Led_Off(LED_D5);

        Led_On(LED_D4);
        usleep(delay_time);
        Led_Off(LED_D4);

        Led_On(LED_D3);
        usleep(delay_time);
        Led_Off(LED_D3);

        Led_On(LED_D2);
        usleep(delay_time);
        Led_Off(LED_D2);
    }
}

*/