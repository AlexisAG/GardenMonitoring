#ifndef Menu_h
#define Menu_h

#include "Inspection.h"

#define BUFFER_SIZE 32

class Menu 
{
  public:
    Menu();
    Menu(Inspection* insp);

    void ChangeData(int index);
    void NextData();
    void PreviousData();
    void ConfigureAlarm();
    char* GetTitle();
    char* GetDesc();
  private:
    int         _indexNavigation;
    int         _indexAlarm;
    bool        _isInAlarmModeConfiguration;
    char       _firstRow[BUFFER_SIZE];     
    char       _secondRow[BUFFER_SIZE];     
    Inspection* _inspection;
    void SetDisplay();


};

#endif