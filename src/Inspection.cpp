#include <Arduino.h>
#include "Inspection.h"

/*Constructor*/
Inspection::Inspection()
{
    Serial.println(_unitDisp);

  /* Init default data */
  _storedData[ACTUAL].name = "Actual";
  _storedData[ACTUAL].type = Data_Type::Actual;
  _storedData[ACTUAL].data[0] = ACTUAL;

  _storedData[DAILY].name = "Daily";
  _storedData[DAILY].type = Data_Type::Current_Day;
  _storedData[DAILY].data[0] = DAILY;

  _storedData[WEEKLY].name = "Weekly";
  _storedData[WEEKLY].type = Data_Type::LastWeek;
  _storedData[WEEKLY].data[0] = WEEKLY;

  _storedData[MONTHLY].name = "Monthly";
  _storedData[MONTHLY].type = Data_Type::LastMonth;
  _storedData[MONTHLY].data[0] = WEEKLY;
}

Inspection::Inspection(const char* name, const char* unit, InspectionType type) : Inspection()
{
  Serial.println(name);
  /* Private properties */ 
  _name = name;
  _unitDisp = unit;
  _type = type;
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

char* Inspection::GetName()
{
  return (char*)_name;
}

char* Inspection::GetUnit()
{
  return (char*)_unitDisp;
}

int Inspection::GetType()
{
  return _type;
}
