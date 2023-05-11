/*
Thomas Leemans: library TSL2561 + code bijeen plakken
Lauren Debie: library temperatuursensor + alle logs
Matthias Hendrickx: aantal ledjes on/off door middel van omgevingslicht
Arne Van den Broeck: Spraak
*/

#include <stdio.h>
#include "TSL2561.h"
#include <time.h>


int main(int argc, char **argv)
{
	float visibleLightData;
	float fullSpectrumData;
	float irData;
	time_t start_time, current_time;
   	double elapsed_time;

	start_time = time(NULL); // starttijd
	initTSL2561();
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
		printf("data visible light: %f\n", visibleLightData );
		printf("data infrared light: %f\n", irData);
		printf("data full spectrum: %f\n", fullSpectrumData);
		sleep(1);

		if (fullSpectrumData < 8191)
		{

		}

		else if (8192 > fullSpectrumData && fullSpectrumData <  16382)
		{
			
		}

		else if (16383 > fullSpectrumData && fullSpectrumData <  24573)
		{
			
		}

		else if (24574 > fullSpectrumData && fullSpectrumData <  32764)
		{
			
		}

		else if (32765 > fullSpectrumData && fullSpectrumData <  40955)
		{
			
		}

		else if (40956 > fullSpectrumData && fullSpectrumData <  49146)
		{
			
		}

		else if (49147 > fullSpectrumData && fullSpectrumData <  57337)
		{
			
		}

		else if (fullSpectrumData > 65528)
		{
			
		}

	}
}
