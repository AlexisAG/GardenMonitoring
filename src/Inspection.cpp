#include <Arduino.h>
#include "Inspection.h"

/*Constructor*/
Inspection::Inspection()
{

}

Inspection::Inspection(const char* name, const char* unit, InspectionType type, Data data[NB_DATA])
{
  /* Private properties */ 
  _name = name;
  _unitDisp = unit;
  _type = type;

  for (int i = 0; i < NB_DATA; i++) 
  {
    _storedData[i] = data[i];
  }
}


/* Alarm Get & Set */
Alarm Inspection::GetAlarm(int index)
{
  if (index >= MAX_ALARMS) return Alarm();
  
  return _alarms[index];
}

bool Inspection::InsertAlarm(int index, Alarm alarm)
{
  if (index >= MAX_ALARMS) return false;

  _alarms[index] = alarm;
}

/* Data Get & Set*/
Data Inspection::GetData(int index)
{
  if (index >= NB_DATA) return Data();

  return _storedData[index];
}
bool Inspection::InsertData(int index, Data data)
{
  if (index >= NB_DATA) return false;

  _storedData[index] = data;
}
