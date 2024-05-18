#ifndef Data_h
#define Data_h

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


#endif