#ifndef Menu_h
#define Menu_h

#include "Inspection.h"

class Menu 
{
  public:
    Menu();
    Menu(Inspection insp);

    void SetDisplay(char* firstRow, char* secondRow);
    void NextDisplay();
    void ConfigureAlarm();
  private:
    int         _indexNavigation;
    int         _indexAlarm;
    bool        _isInAlarmModeConfiguration;
    char*       _firstRow;     
    char*       _secondRow;     
    Inspection  _inspection;


};

#endif