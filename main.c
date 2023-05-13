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


int main(int argc, char **argv)
{
	float visibleLightData;
	float fullSpectrumData;
	float irData;
	time_t start_time, current_time;
   	double elapsed_time;

	start_time = time(NULL); // starttijd
	initTSL2561();
	Leds_Init();
	while(1)
	{
		current_time = time(NULL); // huidige tijd
		elapsed_time = difftime(current_time, start_time); // bereken de verstreken tijd
		if(elapsed_time >= 60.0) // als er 1 minuut is verstreken, dan moet de temp uitgespoken en alle gemeten waarde opgeslagen worden in een logbestand. De data's moet op de terminal uitgeprint worden.
		{
				printf("1 minuut is verstreken!\n");
				// voer hier uw andere taak uit
				start_time = time(NULL); // reset de starttijd
		}
		visibleLightData = getVisibleLight();
		fullSpectrumData = getFullSpectrumLight();
		irData = getInfraredLight();
		/* printf("data visible light: %f\n", visibleLightData );
		printf("data infrared light: %f\n", irData); */
		printf("data full spectrum: %f\n", fullSpectrumData);

		if (fullSpectrumData >= 0 && fullSpectrumData <= 8191)
		{
			Leds_Lvl(1); 
			printf("1 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 8192 && fullSpectrumData <=  16382)
		{
			Leds_Lvl(2); 
			printf("2 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 16383 && fullSpectrumData <=  24573)
		{
			Leds_Lvl(3); 
			printf("3 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 24574 && fullSpectrumData <=  32764)
		{
			Leds_Lvl(4); 
			printf("4 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 32765 && fullSpectrumData <=  40955)
		{
			Leds_Lvl(5); 
			printf("5 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 40956 && fullSpectrumData <=  49146)
		{
			Leds_Lvl(6); 
			printf("6 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 49147 && fullSpectrumData <=  57337)
		{
			Leds_Lvl(7); 
			printf("7 led on\n");
			Leds_Unexport()
		}

		if (fullSpectrumData >= 57338)
		{
			Leds_Lvl(8); 
			printf("8 led on\n");
			Leds_Unexport()
		}
		sleep(1);
	}
}
