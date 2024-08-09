#include "src/Menu.h"

#define NB_MENU 3 // one for each inspection

/* ELECTRONIC PIN */
#define BUTTON_INSPECTION 7

Menu menus[NB_MENU];

/* put your setup code here, to run once:*/
void setup() 
{
 /* Init menus */
 menus[TEMPERATURE] = Menu(Inspection("Temperature", "C°", InspectionType::Temperature));
 menus[HUMIDITY] = Menu(Inspection("Humidity", "%", InspectionType::Temperature));
 menus[LUMINOSITY] = Menu(Inspection("Luminosity", "Lux", InspectionType::Temperature));

}

/*put your main code here, to run repeatedly: */
void loop() 
{

}
