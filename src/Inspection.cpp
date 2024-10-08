#include <Arduino.h>
#include "Inspection.h"

/*Constructor*/
Inspection::Inspection()
{
  /* Init default data */
  _storedData[ACTUAL].name = "Actual";
  _storedData[ACTUAL].type = Data_Type::Actual;

  _storedData[DAILY].name = "Daily";
  _storedData[DAILY].type = Data_Type::Current_Day;

  _storedData[WEEKLY].name = "Weekly";
  _storedData[WEEKLY].type = Data_Type::LastWeek;

  _storedData[MONTHLY].name = "Monthly";
  _storedData[MONTHLY].type = Data_Type::LastMonth;

  /* init counter */
  _actualCounter =    0;
  _hourlyCounter =    0;
  _weeklyCounter =    0;
  _monthlylyCounter = 0;
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

void Inspection::AddMeasurement(int data)
{
  _storedData[ACTUAL].data[0] = data;
  _actualCounter++;

  if (_actualCounter >= HOURLY_COUNTER)
  {
    _storedData[DAILY].data[_hourlyCounter] = data;
    _actualCounter = 0;
    _hourlyCounter++;
  }

  /* WE GOT A FULL DAY */
  if (_hourlyCounter >= DAILY_COUNTER)
  {
    _hourlyCounter = 0;
    
    if (_weeklyCounter >= WEEKLY_COUNTER)
    {
      _weeklyCounter = 0;
    }
    if (_monthlylyCounter >= MONTHLY_COUNTER)
    {
      _monthlylyCounter = 0;
    }

    _storedData[WEEKLY].data[_weeklyCounter] = data;
    _storedData[MONTHLY].data[_monthlylyCounter] = data;

    _weeklyCounter++;
    _monthlylyCounter++;
  }

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
