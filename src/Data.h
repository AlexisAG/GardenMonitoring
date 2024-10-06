#ifndef Data_h
#define Data_h

#define NB_DATA    4
#define DATA_ARRAY 32
/* DATA INDEX */
#define ACTUAL  0
#define DAILY   1 // Average last 24h
#define WEEKLY  2 // Average last 7 days
#define MONTHLY 3 // Average last 30 days

enum Data_Type
{
  Actual      = 0,
  Current_Day = 1,
  LastWeek    = 2,
  LastMonth   = 3
};

struct Data
{
  public:
    const char* name;
    int         data[DATA_ARRAY] = {-1};
    Data_Type   type;
};


#endif