#include <Arduino.h>
#include "Menu.h"

/* CONSTRUCTOR */
Menu::Menu()
{
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
  Data data = _inspection->GetData(_indexNavigation);
  int dataResult = -1;

  // title
  snprintf(_firstRow, BUFFER_SIZE, "%s (%s)", _inspection->GetName(), _inspection->GetUnit());
  
  // data
  switch (_indexNavigation) {
  case ACTUAL:
    dataResult = data.data[0];
    break;
  default:
  int i = 0;
  int temp = 0;
    for (i = 0; i < DATA_ARRAY; i++) 
    {
      if (data.data[i] < 0)
      {
        break;
      }

      temp += data.data[i];
    }

    dataResult = (temp > 0 && i > 0) ? temp/i : -1;
  break;
  }

  snprintf(_secondRow, BUFFER_SIZE, "%s : %d%s", data.name, dataResult, _inspection->GetUnit());
}

void Menu::AddData(int data)
{
  _inspection->AddMeasurement(data);
  SetDisplay();
}

/* Change the data to display */
void Menu::ChangeData(int index)
{
  _indexNavigation = index;

  if (_indexNavigation >= NB_DATA)
  {
    _indexNavigation = 0;
  }
  else if (_indexNavigation < 0)
  {
    _indexNavigation = NB_DATA - 1;
  }

  SetDisplay();
}

void Menu::NextData()
{
  ChangeData(_indexNavigation + 1);
}


void Menu::PreviousData()
{
  ChangeData(_indexNavigation - 1);
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
