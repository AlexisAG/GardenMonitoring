#ifndef Inspection_h
#define Inspection_h

#include "Alarm.h"
#include "Data.h"

#define MAX_ALARMS 3
#define NB_DATA    3

/* DATA INDEX */
#define DAILY   0
#define WEEKLY  1
#define MONTHLY 2

/* INSPECTION INDEX*/
#define TEMPERATURE 0
#define HUMIDITY    1
#define LUMINOSITY  2

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
    
  private:

    const char*    _name;
    const char*    _unitDisp;
    InspectionType _type;
    Data           _storedData[NB_DATA];  
    Alarm          _alarms[MAX_ALARMS];      

};

#endif