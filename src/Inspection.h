#ifndef Inspection_h
#define Inspection_h

#include "Alarm.h"
#include "Data.h"

#define MAX_ALARMS        3
#define HOURLY_COUNTER    6*60
#define DAILY_CONTER      24

enum InspectionType
{
  Temperature = 0,
  Humidity    = 1,
  Luminosity  = 2
};

class Inspection 
{
  public:
    Inspection();
    Inspection(const char* name, const char* unit, InspectionType type);
    
    Alarm GetAlarm(int index);
    bool InsertAlarm(int index, Alarm alarm);

    Data GetData(int index);
    bool InsertData(int index, Data data);
    
    void  AddMeasurement(int data);
    char* GetName();
    char* GetUnit();
    int   GetType();

  private:

    const char*    _name;
    const char*    _unitDisp;
    int            _actualCounter;
    int            _hourlyCounter;
    int            _dailyCounter;
    InspectionType _type;
    Data           _storedData[NB_DATA];  
    Alarm          _alarms[MAX_ALARMS];      

};

#endif