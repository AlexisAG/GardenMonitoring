#include <Arduino.h>
#include "Inspection.h"

/*Constructor*/
Inspection::Inspection()
{
  /* Init default data */
  _storedData[DAILY].name = "Daily Average";
  _storedData[DAILY].type = Data_Type::Current_Day;
  _storedData[DAILY].name = "Weekly Average";
  _storedData[DAILY].type = Data_Type::LastWeek;
  _storedData[DAILY].name = "Monthly Average";
  _storedData[DAILY].type = Data_Type::LastMonth;
  
  _storedData[HUMIDITY].name = "Daily Average";
  _storedData[HUMIDITY].type = Data_Type::Current_Day;
  _storedData[HUMIDITY].name = "Weekly Average";
  _storedData[HUMIDITY].type = Data_Type::LastWeek;
  _storedData[HUMIDITY].name = "Monthly Average";
  _storedData[HUMIDITY].type = Data_Type::LastMonth;

  _storedData[LUMINOSITY].name = "Daily Average";
  _storedData[LUMINOSITY].type = Data_Type::Current_Day;
  _storedData[LUMINOSITY].name = "Weekly Average";
  _storedData[LUMINOSITY].type = Data_Type::LastWeek;
  _storedData[LUMINOSITY].name = "Monthly Average";
  _storedData[LUMINOSITY].type = Data_Type::LastMonth;
}

Inspection::Inspection(const char* name, const char* unit, InspectionType type) : Inspection()
{
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
