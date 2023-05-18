// Include guard
#ifndef LEDS_H
#define LEDS_H

// Function declaration
void Led_Init(int led_pin);
void Led_On(int led_pin);
void Led_Off(int led_pin);
void Led_Reset(int led_pin);
void Leds_Init(void);
void Leds_Export(void);
void Leds_Alert(void);
void Leds_Lvl(int level);
void Leds_Knight_Rider(void);

#endif // LEDS_H