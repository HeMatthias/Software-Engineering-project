# Software-Engineering-project
Dit is een kort overzicht van de vereisten voor het ontwikkelen van een toestel voor het meten van temperatuur en licht. Het toestel zal zowel de temperatuur als de lichtintensiteit meten en de metingen weergeven op een terminal en een logfile. Hieronder volgen de belangrijkste specificaties:

H3 Functionaliteiten
1. Het apparaat meet de temperatuur en lichtintensiteit.
2. De metingen worden weergegeven met een tijdstempel.
3. De metingen worden getoond op de terminal en worden opgeslagen in een logfile.
4. Een meetinterval van een minuut wordt gehanteerd, tenzij er een drastische lichtverandering plaatsvindt.
5. Er worden drie aparte logfiles gebruikt, elk met een maximale grootte van 500 KB.
6. De temperatuur wordt weergegeven in Kelvin, maar de eenheid kan worden aangepast op de terminal naar Celsius of Fahrenheit.
7. De temperatuur wordt ook uitgesproken in het Engels bij het weergeven op de terminal.
8. De lichtintensiteit wordt weergegeven met behulp van leds, waarbij het aantal brandende leds varieert naarmate de lichtintensiteit daalt.

H3 Specificaties
Temperatuursensor:
Meetbereik: 263,15 K tot 323,15 K
Nauwkeurigheid: ±0,5 °C
Lichtsensor:
Meetbereik: 1 lux tot 20.000 lux

H3Foutafhandeling
Als er een fout optreedt bij een van de sensoren, zal het apparaat blijven meten, maar een foutmelding weergeven bij de betreffende meting die niet werkt.
Dit is een beknopt overzicht van de vereisten voor het temperatuur- en lichtmeetapparaat. Verdere technische details en implementatieaspecten kunnen nog worden uitgewerkt.
