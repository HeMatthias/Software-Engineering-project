#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

// Add header file LEDs.h
#include "LEDs.h"

// Define the pins for each LED
#define LED_D1 17 
#define LED_D2 18
#define LED_D3 27
#define LED_D4 22
#define LED_D5 23
#define LED_D6 24
#define LED_D7 14
#define LED_D8 4

// LED D1: Physical pin 11, BCM GPIO17, and WiringPi pin 0.
// LED D2: Physical pin 12, BCM GPIO18, and WiringPi pin 1.
// LED D3: Physical pin 13, BCM GPIO27, and WiringPi pin 2.
// LED D4: Physical pin 15, BCM GPIO22, and WiringPi pin 3.
// LED D5: Physical pin 16, BCM GPIO23, and WiringPi pin 4.
// LED D6: Physical pin 18, BCM GPIO24, and WiringPi pin 5.
// LED D7: Physical pin 8,  BCM GPIO14, and WiringPi pin 15.
// LED D8: Physical pin 7,  BCM GPIO4,  and WiringPi pin 7.

/// @brief In this function the supplied LED (led_pin) will be initialized
/// @param led_pin 
void Led_Init(int led_pin){
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

/// @brief In this function the supplied LED (led_pin) will be turned on
/// @param led_pin 
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

/// @brief In this function the supplied LED (led_pin) will be turned off
/// @param led_pin 
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

/// @brief In this function the supplied LED (led_pin) will be unexported from the program
/// @param led_pin 
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

/// @brief This function will be an animating of a knight rider from LED1 to LED8
/// @param  
void Leds_Knight_Rider(void)
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

        Led_On(LED_D8);
        usleep(delay_time);
        Led_Off(LED_D8);

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

    Led_On(LED_D1);
    usleep(delay_time);
    Led_Off(LED_D1);
}

/// @brief In this function u can pass the amount of LEDs need to be on from 0 to 8
/// @param  
void Leds_Lvl(int level){
    switch (level) {

    case 1:
        Led_On(LED_D1);
        Led_Off(LED_D2);
        Led_Off(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;
    
    case 2:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_Off(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    case 3:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    case 4:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    case 5:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    case 6:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_On(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    case 7:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_On(LED_D6);
        Led_On(LED_D7);
        Led_Off(LED_D8);
        break;

    case 8:
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_On(LED_D6);
        Led_On(LED_D7);
        Led_On(LED_D8);
        break;

    default:
        Led_Off(LED_D1);
        Led_Off(LED_D2);
        Led_Off(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        break;

    }
}

/// @brief This function makes all LEDs from LED 1 to LED 8 flicker 3 times
/// @param  
void Leds_Alert(void){
// LEDs will flicker 3 timer
    for (int i = 0; i < 3; i++) {
        Led_On(LED_D1);
        Led_On(LED_D2);
        Led_On(LED_D3);
        Led_On(LED_D4);
        Led_On(LED_D5);
        Led_On(LED_D6);
        Led_On(LED_D7);
        Led_On(LED_D8);
        usleep(100000);

        Led_Off(LED_D1);
        Led_Off(LED_D2);
        Led_Off(LED_D3);
        Led_Off(LED_D4);
        Led_Off(LED_D5);
        Led_Off(LED_D6);
        Led_Off(LED_D7);
        Led_Off(LED_D8);
        usleep(100000);
    }
}

/// @brief This function will initialize all LEDs from LED 1 to LED 8
/// @param  
void Leds_Init(void){
// Initialize all LEDs
    Led_Init(LED_D1);
    Led_Init(LED_D2);
    Led_Init(LED_D3);
    Led_Init(LED_D4);
    Led_Init(LED_D5);
    Led_Init(LED_D6);
    Led_Init(LED_D7);
    Led_Init(LED_D8);
}

/// @brief This function will unexport/reset all LEDs from LED 1 to LED 8
/// @param
void Leds_Export(void){
// Reset all LEDs
    Led_Reset(LED_D1);
    Led_Reset(LED_D2);
    Led_Reset(LED_D3);
    Led_Reset(LED_D4);
    Led_Reset(LED_D5);
    Led_Reset(LED_D6);
    Led_Reset(LED_D7);
    Led_Reset(LED_D8);
}