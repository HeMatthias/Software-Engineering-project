#include <stdio.h>
#include <check.h>
#include "TSL2561.h" // Je TSL2561-bibliotheek

// Externe declaratie van mockfuncties
extern void initTSL2561();
extern float getFullSpectrumLight();

// Unit testfunctie voor het uitlezen van de lichtsensor
START_TEST(test_lightsensor_reading)
{
    // Initialiseren van de mock lichtsensor
    initTSL2561();

    // Uitlezen van de lichtintensiteit via de mock
    float intensiteit = getFullSpectrumLight();

    // Check-asserties
    ck_assert_float_ge(intensiteit, 0.0); // Controleren dat de intensiteit niet-negatief is

    // Opruimen
    // (geen opruiming nodig voor de mockversie)
}
END_TEST

// Testsuite creatie
Suite* lightsensor_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("LightSensor");
    tc_core = tcase_create("Core");

    // Testcase toevoegen aan de testsuite
    tcase_add_test(tc_core, test_lightsensor_reading);
    suite_add_tcase(s, tc_core);

    return s;
}

// Mainfunctie om de tests uit te voeren
int main(void)
{
    int aantal_fouten;
    Suite *s;
    SRunner *sr;

    s = lightsensor_suite();
    sr = srunner_create(s);

    // Uitvoeren van de tests
    srunner_run_all(sr, CK_NORMAL);
    aantal_fouten = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (aantal_fouten == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}