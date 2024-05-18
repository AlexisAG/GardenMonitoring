#ifndef Inspection_h
#define Inspection_h

#include "Alarm.h"
#include "Data.h"

#define MAX_ALARMS 3


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
    
  private:

    const char*    name;
    const char*    unitDisp;
    InspectionType type;
    Data           storedData[3];  
    Alarm          alarms[MAX_ALARMS]        

};

#endif