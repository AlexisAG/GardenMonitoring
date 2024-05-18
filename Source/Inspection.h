#ifndef Inspection_h
#define Inspection_h

#include "Alarm.h"

#define MAX_ALARMS 3


enum InspectionType
{
  Temperature = 0,
  Humidity    = 1,
  Luminosity  = 2
};

enum Data_Type
{
  Current_Day = 0,
  LastWeek    = 1,
  LastMonth   = 2
};

struct Data
{
  public:
    const char* name;
    int         data[32];
    Data_Type   type;
};


class Inspection 
{
  public:

    Inspection();
    
  private:

    const char*    name;
    const char*    unitDisp;
    InspectionType type;
    Data           storedData[3];  
    Alarm          alarms[MAX_ALARMS]        

};

#endif