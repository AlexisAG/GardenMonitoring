#include <Arduino.h>
#include "Menu.h"

/* CONSTRUCTOR */
Menu::Menu()
{
    //Serial.print("WESH \n");
    _indexNavigation = -1;
    _indexAlarm;
    _isInAlarmModeConfiguration;
    _firstRow;     
    _secondRow; 
}
Menu::Menu(Inspection* insp) : Menu()
{
  _inspection = insp;
}

/* NAVIGATION */

/* Display the information */
void Menu::SetDisplay()
{
  char bufferTitle[32];
  char bufferDesc[32];
  
  sprintf(bufferTitle, "%s (%s)", _inspection->GetName(), _inspection->GetUnit());
  _firstRow = bufferTitle;

  sprintf(bufferDesc, "WIP ON DATA");
  _secondRow = bufferDesc;

}
/* Change the data or the alarm to display */
void Menu::NextDisplay()
{
  _indexNavigation++;

  if (_indexNavigation < 0 || _indexNavigation >= NB_DATA)
  {
    _indexNavigation = 0;
  }

  SetDisplay();
}

/* Handle Alarm setup */
void Menu::ConfigureAlarm()
{

}



char* Menu::GetTitle()
{
  return _firstRow;
}

char* Menu::GetDesc()
{
  return _secondRow;
}


void Menu::TEST()
{
  Serial.println(_firstRow);
  Serial.println(_secondRow);
}