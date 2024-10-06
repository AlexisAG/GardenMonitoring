#include <LiquidCrystal.h>
#include "src/Menu.h"

#define DELAY_MS 30
#define NB_MENU  3 // one for each inspection

/* INSPECTION INDEX*/
#define TEMPERATURE 0
#define HUMIDITY    1
#define LUMINOSITY  2

/* ELECTRONIC PIN */
#define BUTTON_SELECT 7
#define AXIS_X        A0
#define AXIS_Y        A1


/* ELECTRONICS CONSTANTS */
#define LCD_COL       16
#define LCD_ROW       2
#define AXIS_DEADZONE 0.33
#define AXIS_DEFAULT  512
#define AXIS_MIN      0
#define AXIS_MAX      1024

enum Axis_State
{
  Idle  = 0,
  Left  = 1,
  Right = 2,
  Up    = 3,
  Down  = 4
};


Axis_State axisState;

LiquidCrystal lcd(12, 11, 2, 3, 4, 5); //LCD SCREEN
Menu menus[NB_MENU];

char firstRow[LCD_COL]; // LCD SCREEN
char secondRow[LCD_COL]; // LCD SCREEN

int selectButtonState;
int indexNavigation;

bool enterSettingsMode;
bool nextAlarm;

/* put your setup code here, to run once:*/
void setup() 
{
 /* Init components */
  Serial.begin(9600);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);  

  /* lcd */
  lcd.begin(LCD_COL, LCD_ROW);
  lcd.noBlink();
  lcd.noAutoscroll();
  DisplayOnLcd("LOADING", "");

/* LOAD & INIT EVERYTHINGS */

  axisState = Axis_State::Idle;
  selectButtonState = -1;

 /* Init menus */
 
  menus[TEMPERATURE] = Menu(new Inspection("Temperature", "C", InspectionType::Temperature));
  menus[HUMIDITY] = Menu(new Inspection("Humidity", "%", InspectionType::Humidity));
  menus[LUMINOSITY] = Menu(new Inspection("Luminosity", "Lux", InspectionType::Luminosity));

 /* init navigation */
  indexNavigation = 0;
  enterSettingsMode = false;
  nextAlarm = false;

  ChangeMenu();
  RefreshDisplay();
}

/*put your main code here, to run repeatedly: */
void loop() 
{
  HandleJoystickInput();

  delay(DELAY_MS);
}

void HandleJoystickInput()
{
  bool state = digitalRead(BUTTON_SELECT);
  bool needRefresh = false;
  Axis_State axis = GetAxis();

  if (axis != axisState && axis != Axis_State::Idle)
  {
    switch (axis) 
    {
      case Axis_State::Left:
        indexNavigation--;
        ChangeMenu();
        needRefresh = true;
      break;
      case Axis_State::Right:
        indexNavigation++;
        ChangeMenu();
        needRefresh = true;
      break;
      case Axis_State::Up:
        menus[indexNavigation].PreviousData();
        needRefresh = true;
      break;
      case Axis_State::Down:
        menus[indexNavigation].NextData();
        needRefresh = true;
      break;
    }

    if (needRefresh)
    {
      RefreshDisplay();
    }
  }

  if (state == LOW && state != selectButtonState)
  {
    Serial.println("ENTER SETTINGS MODE !");
  }

  selectButtonState = state;
  axisState = axis;
}

Axis_State GetAxis()
{
  int axis_x = analogRead(AXIS_X);
  int axis_y = analogRead(AXIS_Y);
  Axis_State state = Axis_State::Idle;

  if (axis_x < (AXIS_DEFAULT - (AXIS_DEFAULT * AXIS_DEADZONE)))
  {
    state = Axis_State::Left;
  }
  else if (axis_x > (AXIS_DEFAULT + (AXIS_DEFAULT * AXIS_DEADZONE)))
  {
    state = Axis_State::Right;
  }
  else if (axis_y < (AXIS_DEFAULT - (AXIS_DEFAULT * AXIS_DEADZONE)))
  {
    state = Axis_State::Up;
  }
  else if (axis_y > (AXIS_DEFAULT + (AXIS_DEFAULT * AXIS_DEADZONE)))
  {
    state = Axis_State::Down;
  }
  else 
  {
    state = Axis_State::Idle;
  }

  return state;
}

/* LCD Related */
void DisplayOnLcd(const char* title, const char* desc)
{
  lcd.clear();
  
  // set cursor on first row then print
  lcd.setCursor(0,0);
  strncpy(firstRow, title, LCD_COL);
  lcd.print(firstRow);

  // set cursor on second row then print
  lcd.setCursor(0,1);
  strncpy(secondRow, desc, LCD_COL);
  lcd.print(secondRow);
}

void ChangeMenu()
{
  if (indexNavigation >= NB_MENU)
  {
    indexNavigation = 0;
  }
  else if (indexNavigation < 0)
  {
    indexNavigation = NB_MENU - 1;
  }

  menus[indexNavigation].ChangeData(0);
}

void RefreshDisplay()
{
  char* test1 = menus[indexNavigation].GetTitle();
  char* test2 = menus[indexNavigation].GetDesc();

  DisplayOnLcd(test1, test2);
}
