#include <Arduino.h>
#include "Menu.h"

/* CONSTRUCTOR */
Menu::Menu()
{
    _indexNavigation = 0;
    _indexAlarm;
    _isInAlarmModeConfiguration;
    _firstRow;     
    _secondRow; 
}
Menu::Menu(Inspection insp) : Menu()
{
  _inspection = insp;
}

/* NAVIGATION */

/* Change the data or the alarm to display */
void Menu::NextDisplay()
{

}

/* Handle Alarm setup */
void Menu::ConfigureAlarm()
{

}


/* Display the information */
void Menu::SetDisplay(char *firstRow, char *secondRow)
{

}
