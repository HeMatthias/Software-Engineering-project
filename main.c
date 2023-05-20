/*
Thomas Leemans: library TSL2561 + code bijeen plakken
Lauren Debie: library temperatuursensor + alle logs
Matthias Hendrickx: aantal ledjes on/off door middel van omgevingslicht
Arne Van den Broeck: Spraak
*/

#include <stdio.h>
#include "TSL2561.h"
#include <time.h>
#include "LEDs.h"
#include "temp.h"
#include "log.c"


int main(int argc, char **argv)
{
	float visibleLightData;
	float fullSpectrumData = 0.0;
	float irData;
	time_t start_time, current_time;
   	double elapsed_time;
	float oldFullSpectrumData = 0.0;
	float check;
	start_time = time(NULL); // starttijd
	initTSL2561();
	Leds_Init();
	init_temp(1);
	sleep(1);
	char temp[20];
	char *temp2;

	void log_light_data(float lightValue) {
		
		struct log_data_styl logData;
		time_set(logData.times);

		// Converteer de lichtwaarde naar een string
		snprintf(logData.licht, sizeof(logData.licht), "%.2f", lightValue);

		// Voeg de loggegevens toe aan de logbestanden
		log_set(&logData);
	}

	void log_temp_data(float temp)
	{
		struct log_data_styl logData;
		time_set(logData.times);
		snprintf(logData.temp, sizeof(logData.temp), "%.2f", temp);
		log_set(&logData);
	}
	while(1)
	{
		current_time = time(NULL); // huidige tijd
		elapsed_time = difftime(current_time, start_time); // bereken de verstreken tijd
		if(elapsed_time >= 60.0) // als er 1 minuut is verstreken, dan moet de temp uitgespoken en alle gemeten waarde opgeslagen worden in een logbestand. De data's moet op de terminal uitgeprint worden.
		{
				printf("1 minuut is verstreken!\n");
				// voer hier uw andere taak uit
				start_time = time(NULL); // reset de starttijd
				log_light_data(fullSpectrumData);
				start_time = time(NULL); // reset de starttijd
				temp2 = temp;
				temp_read(temp2);
				printf("waarde is:%s\r\n",temp);
				log_temp_data(temp);

		}
		oldFullSpectrumData = fullSpectrumData;
		
		visibleLightData = getVisibleLight();
		fullSpectrumData = getFullSpectrumLight();
		irData = getInfraredLight();

		check = fullSpectrumData - oldFullSpectrumData;
		/* printf("data visible light: %f\n", visibleLightData );
		printf("data infrared light: %f\n", irData); */
		printf("data full spectrum: %f\n", fullSpectrumData);

		if (fullSpectrumData >= 0 && fullSpectrumData <= 8191)
		{
			Leds_Lvl(8); 
			printf("1 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 8192 && fullSpectrumData <=  16382)
		{
			Leds_Lvl(7); 
			printf("2 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 16383 && fullSpectrumData <=  24573)
		{
			Leds_Lvl(6); 
			printf("3 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 24574 && fullSpectrumData <=  32764)
		{
			Leds_Lvl(5); 
			printf("4 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 32765 && fullSpectrumData <=  40955)
		{
			Leds_Lvl(4); 
			printf("5 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 40956 && fullSpectrumData <=  49146)
		{
			Leds_Lvl(3); 
			printf("6 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 49147 && fullSpectrumData <=  57337)
		{
			Leds_Lvl(2); 
			printf("7 led on\n");
			/* Leds_UnExport(); */
		}

		if (fullSpectrumData >= 57338)
		{
			Leds_Lvl(1); 
			printf("8 led on\n");
			/* Leds_UnExport(); */
		}
		
		if(check < -16382)
		{
			Leds_Alert();
			printf("ALERT ALERT ALERT\n");
		}
		log_light_data(fullSpectrumData);
		sleep(1);
	}
}
