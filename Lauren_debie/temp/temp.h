/*
!!! voor tinit_temp moet men de code als sudo uitvoeren
init_temp gaat de tempratuur lees proses opzetten in de achtergront opzetten en waneer men de waardt 1 meegeft  en waneer men een 0 meegeeft gaat men dit proses killen;

temp_read hier moet men een pointer van een string  meegeven waar deze funksie de waarde van de tempratuur meter in zet
*/

#ifndef TEMP_H
#define TEMP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void init_temp(int);
void temp_read(char*);
#endif
