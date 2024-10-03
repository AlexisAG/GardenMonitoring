#ifndef Menu_h
#define Menu_h

#include "Inspection.h"

class Menu 
{
  public:
    Menu();
    Menu(Inspection* insp);

    void NextDisplay();
    void ConfigureAlarm();
    char* GetTitle();
    char* GetDesc();
    void TEST();
  private:
    int         _indexNavigation;
    int         _indexAlarm;
    bool        _isInAlarmModeConfiguration;
    char*       _firstRow;     
    char*       _secondRow;     
    Inspection* _inspection;
    
    void SetDisplay();


};

#endif